import os

from distutils.core import setup, Extension

import arcpy

install_dir = arcpy.GetInstallInfo()['InstallDir']
include_dir = os.path.join(install_dir, 'com')

for directory in (r"c:\Program Files (x86)\Common Files\ArcGIS\bin\\",
                  r"c:\Program Files\Common Files\ArcGIS\bin\\",
                  None):
    version_dir = directory
    if os.path.isdir(version_dir):
        break
    elif directory is None:
        raise IOError("Can't find ArcGISVersion.dll")

setup(
    name='cartocomutils',
    version='10.2',
    packages=['cartocomutils'],
    ext_package='cartocomutils',
    ext_modules=[
      Extension('_ArcGISVersion',
                ['src/ArcGISVersion.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriSystem',
                ['src/esriSystem.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriSystemUI',
                ['src/esriSystemUI.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriGeometry',
                ['src/esriGeometry.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriGraphicsCore',
                ['src/esriGraphicsCore.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriGraphicsSymbols',
                ['src/esriGraphicsSymbols.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriDisplay',
                ['src/esriDisplay.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriServer',
                ['src/esriServer.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriOutput',
                ['src/esriOutput.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriGeoDatabase',
                ['src/esriGeoDatabase.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriGeoDatabaseDistributed',
                ['src/esriGeoDatabaseDistributed.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriGeoDatabaseExtensions',
                ['src/esriGeoDatabaseExtensions.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriGeoDatabasePS',
                ['src/esriGeoDatabasePS.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriGISClient',
                ['src/esriGISClient.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriDataSourcesFile',
                ['src/esriDataSourcesFile.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriDataSourcesGDB',
                ['src/esriDataSourcesGDB.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriDataSourcesOleDB',
                ['src/esriDataSourcesOleDB.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriDataSourcesRaster',
                ['src/esriDataSourcesRaster.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriDataSourcesNetCDF',
                ['src/esriDataSourcesNetCDF.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriDataSourcesRasterUI',
                ['src/esriDataSourcesRasterUI.cpp'],
                include_dirs=[version_dir, include_dir]),
      Extension('_esriCarto',
                ['src/esriCarto.cpp'],
                include_dirs=[version_dir, include_dir]),
    ]
)