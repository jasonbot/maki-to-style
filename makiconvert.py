import collections
import glob
import json
import os
import re
import shutil
import subprocess
import sys
import xml.etree.ElementTree
import _winreg

import arcpy

import cartocomutils

LOCAL_SCRIPT_PATH = os.path.dirname(os.path.abspath(__file__))

# Skip the production of picture or vector by setting either flag to True
SKIP_BMPS = False
SKIP_EMFS = False

# Hardcode to a path string to convert.exe if the detection routines aren't
# working for you.
IMAGEMAGICK_PATH = None

# Hardcode to a path string to inkscape.com (*not* .exe) if the detection
# routines aren't working for you.
INKSCAPE_PATH = None

def make_out_directory_structure(out_dir):
    print "Setting up directory structure..."
    dirlist = [out_dir,
               os.path.join(out_dir, 'images'),
               os.path.join(out_dir, 'styles')]
    for directory in dirlist:
        if not os.path.isdir(directory):
            print "    Creating folder {}".format(directory)
            os.mkdir(directory)

def copy_svgs(in_path, out_path):
    print "Copying SVGs..."
    copy_count = 0
    for svg_file in glob.glob(os.path.join(in_path, '*.svg')):
            destination_svg = os.path.join(out_path,
                                           os.path.basename(svg_file))
            if not os.path.isfile(destination_svg):
                base_svg = os.path.basename(svg_file)
                sys.stdout.write("    [   ] {: <65}\r".format(base_svg))
                sys.stdout.flush()
                delete_mask = os.path.splitext(destination_svg)[0] + "*"
                files_to_delete = glob.glob(delete_mask)
                for file in files_to_delete:
                    os.unlink(file)
                shutil.copyfile(svg_file, destination_svg)
                copy_count += 1
            yield destination_svg
    success_string = ("[ * ] SVGs copied ({} new file{})"
                      .format(copy_count,
                              's' if copy_count != 1 else ''))
    print "    {: <70}".format(success_string)

def make_outline_file(svg_file, out_file):
    with open(svg_file, 'rb') as in_xml, \
         open(out_file, 'wb') as out_xml:
        tree = xml.etree.ElementTree.parse(in_xml)
        paths = tree.findall(".//{http://www.w3.org/2000/svg}path")
        for path in paths:
            if 'style' in path.attrib:
                style = path.attrib['style']
                for old, new in (("fill:#444444;",
                                  "fill:none;"),
                                 ("fill-opacity:1;",
                                  "fill-opacity:0;"),
                                 ("stroke:none;",
                                  "stroke:#000000;stroke-width:1;")):
                    style = style.replace(old, new)
                path.attrib['style'] = style
        tree.write(out_xml)

def make_outlines(svg_list):
    print "Making SVG outlines..."
    for svg_file in svg_list:
        copy_file = os.path.splitext(svg_file)[0] + "-outline.svg"
        base_svg = os.path.basename(copy_file)
        if not os.path.isfile(copy_file):
            sys.stdout.write("    [   ] {: <65}\r".format(base_svg))
            sys.stdout.flush()
            make_outline_file(svg_file, copy_file)
    print "    {: <70}".format("[ * ] SVG outlines created")

def prepare_svgs(in_path, out_path):
    new_svgs = list(copy_svgs(in_path, out_path))
    make_outlines(new_svgs)

def install_keys(format_key):
    for s in ['', 'Wow6432Node\\']:
        yield (_winreg.HKEY_LOCAL_MACHINE, format_key.format(s))

def find_imagemagick():
    if IMAGEMAGICK_PATH is not None:
        return IMAGEMAGICK_PATH
    for key in install_keys("SOFTWARE\{}ImageMagick\Current"):
        handle = None
        try:
            handle = _winreg.OpenKey(*key)
            index = 0
            while True:
                key, val, _ = _winreg.EnumValue(handle, index)
                if key.lower() == "binpath":
                    exe_file = os.path.join(val, "convert.exe")
                    if os.path.isfile(exe_file):
                        return exe_file
                index += 1
        except WindowsError:
            pass
        finally:
            if handle is not None:
                _winreg.CloseKey(handle)
    raise IOError("Could not find ImageMagick installation.")

def make_bmps(bmp_path):
    if SKIP_BMPS:
        return
    print "Making BMP marker files..."
    imgmagick_exe = find_imagemagick()
    #print "Imagemagick executable path: {}".format(imgmagick_exe)
    for svg_file in glob.glob(os.path.join(bmp_path, "*.svg")):
        out_bmp = os.path.splitext(svg_file)[0] + ".bmp"
        if not os.path.isfile(out_bmp):
            base_bmp = os.path.basename(out_bmp)
            sys.stdout.write("    [   ] {: <65}\r".format(base_bmp))
            sys.stdout.flush()
            command = [imgmagick_exe, "+antialias", svg_file, out_bmp]
            subprocess.call(command)
    print "    {: <70}".format("[ * ] BMPs created")

def find_inkscape():
    if INKSCAPE_PATH is not None:
        return INKSCAPE_PATH
    for key in install_keys("SOFTWARE\\{}Microsoft\\Windows\\"
                            "CurrentVersion\\Uninstall\\Inkscape"):
        handle = None
        try:
            handle = _winreg.OpenKey(*key)
            index = 0
            while True:
                key, val, _ = _winreg.EnumValue(handle, index)
                if key.lower() == "uninstalldirectory":
                    exe_file = os.path.join(val, "inkscape.com")
                    if os.path.isfile(exe_file):
                        return exe_file
                index += 1
        except WindowsError:
            pass
        finally:
            if handle is not None:
                _winreg.CloseKey(handle)
    raise IOError("Could not find Inkscape installation.")

def make_emfs(emf_path):
    if SKIP_EMFS:
        return
    old_dir = os.getcwd()
    os.chdir(emf_path)
    try:
        print "Making EMF marker files..."
        inkscape_exe = find_inkscape()
        #print "Inkscape executable path: {}".format(inkscape_exe)
        cmd_string = '"{}" --export-emf="{}" {} '
        for svg_file in glob.glob(os.path.join(emf_path, "*.svg")):
            out_emf = os.path.basename(os.path.splitext(svg_file)[0] + ".emf")
            if not os.path.isfile(out_emf):
                base_emf = os.path.basename(out_emf)
                sys.stdout.write("    [   ] {: <65}\r".format(base_emf))
                sys.stdout.flush()
                command = cmd_string.format(inkscape_exe, out_emf,
                                            os.path.basename(svg_file))
                subprocess.check_output(command,
                                        stderr=subprocess.STDOUT,
                                        shell=True)
        print "    {: <70}".format("[ * ] EMFs created")
    finally:
        os.chdir(old_dir)

def prepare_images(in_path, out_path):
    prepare_svgs(in_path, out_path)
    make_bmps(out_path)
    make_emfs(out_path)

def get_maki_mapping_for_extension(out_image_dir, extension,
                                   maki_name_mapping, extra_tag):
    tag_re = re.compile("-[0-9]+.*")
    mapping = {}
    for vector_file in glob.glob(os.path.join(out_image_dir,
                                 "*.{}".format(extension))):
        base_file = os.path.splitext(os.path.basename(vector_file))[0]
        tags = [extra_tag]
        fixed_name = base_file
        for item in tag_re.findall(base_file):
            fixed_name = fixed_name.replace(item, "")
            for i, tag in enumerate(item.strip('-').split('-')):
                if tag.strip():
                    if i == 0:
                        tag += "px"
                    else:
                        tag = tag.strip().title()
                    tags.append(tag)
        if fixed_name in maki_name_mapping:
            fixed_name = maki_name_mapping[fixed_name]
        else:
            fixed_name = fixed_name.replace('-', ' ').title()
        tag_string = ", ".join(tags)
        mapping.setdefault(fixed_name, {})[tag_string] = vector_file
    return mapping

def make_style_mapping(maki_repo, out_image_dir):
    maki_json_file = os.path.join(maki_repo, 'www', 'maki.json')
    maki_json = json.load(open(maki_json_file, 'rb'))
    maki_icon_to_name_mapping = { item['icon']: item['name']
                                  for item in maki_json }
    mapping = {}
    bmpmap = get_maki_mapping_for_extension(out_image_dir, 'bmp',
                                            maki_icon_to_name_mapping,
                                            'Picture')
    emfmap = get_maki_mapping_for_extension(out_image_dir, 'emf',
                                            maki_icon_to_name_mapping,
                                            'Vector')
    # Merge dictionaries
    for item_dict in (bmpmap, emfmap):
        for item, type_dict in item_dict.items():
            mapping.setdefault(item, {}).update(type_dict)
    return mapping

def make_picture_marker(file_path, size):
    color = cartocomutils.IRgbColor(cartocomutils.CLSID_RgbColor)
    color.Red, color.Green, color.Blue = (255, 255, 255)
    extension = os.path.splitext(file_path)[1].lower()
    if extension == ".emf":
        import_type = cartocomutils.esriIPictureType.esriIPictureEMF
    else:
        import_type = cartocomutils.esriIPictureType.esriIPictureBitmap
    picturemarker = cartocomutils.IPictureMarkerSymbol(
                            cartocomutils.CLSID_PictureMarkerSymbol)
    picturemarker.CreateMarkerSymbolFromFile(import_type, file_path)
    picturemarker.BitmapTransparencyColor = color
    picturemarker.Size = size
    return picturemarker

def make_gallery_file(style_mapping, out_gallery):
    if os.path.splitext(out_gallery)[1].lower() == ".serverstyle":
        gallery_clsid = cartocomutils.CLSID_ServerStyleGallery
        item_clsid = cartocomutils.CLSID_ServerStyleGalleryItem
    else:
        gallery_clsid = cartocomutils.CLSID_StyleGallery
        item_clsid = cartocomutils.CLSID_StyleGalleryItem
    size_re = re.compile("([0-9]+)px")
    style_gallery = cartocomutils.IStyleGallery(gallery_clsid)
    style_io = cartocomutils.IStyleGalleryStorage(style_gallery)
    style_io.TargetFile = out_gallery
    for item_name, item_dict in style_mapping.iteritems():
        for item_format, item_file in item_dict.iteritems():
            print_string = "{}: {}".format(item_name,
                                           item_format)
            sys.stdout.write("    [   ] {: <65}\r".format(print_string))
            sys.stdout.flush()
            styleitem = cartocomutils.IStyleGalleryItem(item_clsid)
            item_size = 24
            for item in size_re.findall(item_format):
                item_size = int(item)
            picture_marker = make_picture_marker(item_file, item_size)
            styleitem.Category = item_format
            styleitem.Item = picture_marker
            styleitem.Name = "{} ({})".format(item_name, item_format)
            style_gallery.AddItem(styleitem)
    print "    [ * ] {: <65}\r".format(out_gallery)

def make_style_galleries(maki_repo, out_image_dir, out_style_dir):
    print "Making style gallery files..."
    style_mapping = make_style_mapping(maki_repo, out_image_dir)
    out_files = ["maki.style", "maki.ServerStyle"]
    for file in out_files:
        out_gallery = os.path.join(out_style_dir, file)
        if os.path.isfile(out_gallery):
            os.unlink(out_gallery)
        make_gallery_file(style_mapping, out_gallery)

def make_style_files(maki_repo, out_path):
    make_out_directory_structure(out_path)
    in_image_dir = os.path.join(maki_repo, 'maki-svg')
    out_image_dir = os.path.join(out_path, 'images')
    out_style_dir = os.path.join(out_path, 'styles')
    prepare_images(in_image_dir, out_image_dir)
    make_style_galleries(maki_repo, out_image_dir, out_style_dir)

if __name__ == "__main__":
    maki_repo_path = os.path.abspath(os.path.join(LOCAL_SCRIPT_PATH,
                                                  '..',
                                                  'maki'))
    out_file_path = os.path.join(LOCAL_SCRIPT_PATH, 'out_files')
    make_style_files(maki_repo_path, out_file_path)
