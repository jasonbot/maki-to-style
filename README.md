Maki to Esri `.style` and `.serverstyle` converter
==================================================

I wrote this while waiting for the compiler throughout the course of one summer day, not aware that [Craig had already written one](https://github.com/williamscraigm/makiArcGISStyle).

To use it, first clone maki and this script _in the same folder_:

    C:\whatevs\> git clone https://github.com/jasonbot/maki-to-style.git
    C:\whatevs\> git clone https://github.com/mapbox/maki.git

Then you'll need to build the Python extension module included with the version of Python that ArcGIS comes with. You'll need Visual Studio 2008 installed for this part, or alternately maybe I'll include Windows installers when I tag a release. But do this until then:

    C:\whatevs\> cd maki-to-style\marker-conversion-utils
    C:\wha...ls> C:\Python27\ArcGIS10.1\python setup.py install

Then install [ImageMagick](http://sourceforge.net/projects/imagemagick/files/) and [Inkscape](http://inkscape.org/download/) for Windows from their respective sites.

Now run the script:

    C:\whatevs\> cd maki-to-style
    C:\whatevs\maki-to-style\> C:\Python27\ArcGIS10.1\python makiconvert.py

You'll have style files in `maki-to-style\out_files\styles` which you can copy into the maki repository in the `ArcGIS\` subdirectory and check in.

I'll probably contribute to Craig's C# implementation instead of this in the future, but this was fun to do.

License
-------

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

