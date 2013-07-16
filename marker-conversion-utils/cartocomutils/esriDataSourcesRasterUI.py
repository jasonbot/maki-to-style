'Type library'
__all__ = ['IRasterSdeConnection', 'IRasterSdeConnection2', 'CreateRasterDatasetDlg', 'RasterSdeLoader', 'IID_IRasterSdeConnection', 'IID_IRasterSdeConnection2', 'CLSID_CreateRasterDatasetDlg', 'CLSID_RasterSdeLoader']
from cartocomutils import _esriDataSourcesRasterUI
from cartocomutils._esriDataSourcesRasterUI import CreateRasterDatasetDlg, RasterSdeLoader
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IRasterSdeConnection(_esriDataSourcesRasterUI.IRasterSdeConnection):
    _IID = uuid.UUID('7d00f368-fddf-11d3-b2be-00c04f8edeff')

    def __init__(self, *args, **kw):
        super(IRasterSdeConnection, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ServerName(self, Name):
        '''Method IRasterSdeConnection.put_ServerName

           INPUT
            Name                : BSTR'''
        return super(IRasterSdeConnection, self).put_ServerName(Name)
    def get_ServerName(self):
        '''Method IRasterSdeConnection.get_ServerName

           OUTPUT
            Name                : BSTR*'''
        return super(IRasterSdeConnection, self).get_ServerName()
    def put_Instance(self, Name):
        '''Method IRasterSdeConnection.put_Instance

           INPUT
            Name                : BSTR'''
        return super(IRasterSdeConnection, self).put_Instance(Name)
    def get_Instance(self):
        '''Method IRasterSdeConnection.get_Instance

           OUTPUT
            Name                : BSTR*'''
        return super(IRasterSdeConnection, self).get_Instance()
    def put_Database(self, databaseName):
        '''Method IRasterSdeConnection.put_Database

           INPUT
            databaseName        : BSTR'''
        return super(IRasterSdeConnection, self).put_Database(databaseName)
    def get_Database(self):
        '''Method IRasterSdeConnection.get_Database

           OUTPUT
            databaseName        : BSTR*'''
        return super(IRasterSdeConnection, self).get_Database()
    def put_SdeRasterName(self, outputName):
        '''Method IRasterSdeConnection.put_SdeRasterName

           INPUT
            outputName          : BSTR'''
        return super(IRasterSdeConnection, self).put_SdeRasterName(outputName)
    def get_SdeRasterName(self):
        '''Method IRasterSdeConnection.get_SdeRasterName

           OUTPUT
            outputName          : BSTR*'''
        return super(IRasterSdeConnection, self).get_SdeRasterName()
    def put_UserName(self, UserName):
        '''Method IRasterSdeConnection.put_UserName

           INPUT
            UserName            : BSTR'''
        return super(IRasterSdeConnection, self).put_UserName(UserName)
    def get_UserName(self):
        '''Method IRasterSdeConnection.get_UserName

           OUTPUT
            UserName            : BSTR*'''
        return super(IRasterSdeConnection, self).get_UserName()
    def put_Password(self, Password):
        '''Method IRasterSdeConnection.put_Password

           INPUT
            Password            : BSTR'''
        return super(IRasterSdeConnection, self).put_Password(Password)
    def get_Password(self):
        '''Method IRasterSdeConnection.get_Password

           OUTPUT
            Password            : BSTR*'''
        return super(IRasterSdeConnection, self).get_Password()
    def put_InputRasterName(self, inputName):
        '''Method IRasterSdeConnection.put_InputRasterName

           INPUT
            inputName           : BSTR'''
        return super(IRasterSdeConnection, self).put_InputRasterName(inputName)
    def get_InputRasterName(self):
        '''Method IRasterSdeConnection.get_InputRasterName

           OUTPUT
            inputName           : BSTR*'''
        return super(IRasterSdeConnection, self).get_InputRasterName()
    def put_InputBitMaskName(self, bitMaskName):
        '''Method IRasterSdeConnection.put_InputBitMaskName

           INPUT
            bitMaskName         : BSTR'''
        return super(IRasterSdeConnection, self).put_InputBitMaskName(bitMaskName)
    def get_InputBitMaskName(self):
        '''Method IRasterSdeConnection.get_InputBitMaskName

           OUTPUT
            bitMaskName         : BSTR*'''
        return super(IRasterSdeConnection, self).get_InputBitMaskName()
    def put_SdeConnection(self, _arg1):
        '''Method IRasterSdeConnection.put_SdeConnection

           INPUT
            _arg1               : IGxDatabase*'''
        return super(IRasterSdeConnection, self).put_SdeConnection(_arg1)
    def put_SdeWorkspaceName(self, _arg1):
        '''Method IRasterSdeConnection.put_SdeWorkspaceName

           INPUT
            _arg1               : IWorkspaceName*'''
        return super(IRasterSdeConnection, self).put_SdeWorkspaceName(_arg1)
    Database = property(get_Database, put_Database, None)
    InputBitMaskName = property(get_InputBitMaskName, put_InputBitMaskName, None)
    InputRasterName = property(get_InputRasterName, put_InputRasterName, None)
    Instance = property(get_Instance, put_Instance, None)
    Password = property(get_Password, put_Password, None)
    SdeConnection = property(None, put_SdeConnection, None)
    SdeRasterName = property(get_SdeRasterName, put_SdeRasterName, None)
    SdeWorkspaceName = property(None, put_SdeWorkspaceName, None)
    ServerName = property(get_ServerName, put_ServerName, None)
    UserName = property(get_UserName, put_UserName, None)

class IRasterSdeConnection2(_esriDataSourcesRasterUI.IRasterSdeConnection2):
    _IID = uuid.UUID('999df174-4f53-45ec-9784-4d921dbb6a52')

    def __init__(self, *args, **kw):
        super(IRasterSdeConnection2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ServerName(self, Name):
        '''Method IRasterSdeConnection2.put_ServerName

           INPUT
            Name                : BSTR'''
        return super(IRasterSdeConnection2, self).put_ServerName(Name)
    def get_ServerName(self):
        '''Method IRasterSdeConnection2.get_ServerName

           OUTPUT
            Name                : BSTR*'''
        return super(IRasterSdeConnection2, self).get_ServerName()
    def put_Instance(self, Name):
        '''Method IRasterSdeConnection2.put_Instance

           INPUT
            Name                : BSTR'''
        return super(IRasterSdeConnection2, self).put_Instance(Name)
    def get_Instance(self):
        '''Method IRasterSdeConnection2.get_Instance

           OUTPUT
            Name                : BSTR*'''
        return super(IRasterSdeConnection2, self).get_Instance()
    def put_Database(self, databaseName):
        '''Method IRasterSdeConnection2.put_Database

           INPUT
            databaseName        : BSTR'''
        return super(IRasterSdeConnection2, self).put_Database(databaseName)
    def get_Database(self):
        '''Method IRasterSdeConnection2.get_Database

           OUTPUT
            databaseName        : BSTR*'''
        return super(IRasterSdeConnection2, self).get_Database()
    def put_SdeRasterName(self, outputName):
        '''Method IRasterSdeConnection2.put_SdeRasterName

           INPUT
            outputName          : BSTR'''
        return super(IRasterSdeConnection2, self).put_SdeRasterName(outputName)
    def get_SdeRasterName(self):
        '''Method IRasterSdeConnection2.get_SdeRasterName

           OUTPUT
            outputName          : BSTR*'''
        return super(IRasterSdeConnection2, self).get_SdeRasterName()
    def put_UserName(self, UserName):
        '''Method IRasterSdeConnection2.put_UserName

           INPUT
            UserName            : BSTR'''
        return super(IRasterSdeConnection2, self).put_UserName(UserName)
    def get_UserName(self):
        '''Method IRasterSdeConnection2.get_UserName

           OUTPUT
            UserName            : BSTR*'''
        return super(IRasterSdeConnection2, self).get_UserName()
    def put_Password(self, Password):
        '''Method IRasterSdeConnection2.put_Password

           INPUT
            Password            : BSTR'''
        return super(IRasterSdeConnection2, self).put_Password(Password)
    def get_Password(self):
        '''Method IRasterSdeConnection2.get_Password

           OUTPUT
            Password            : BSTR*'''
        return super(IRasterSdeConnection2, self).get_Password()
    def put_InputRasterName(self, inputName):
        '''Method IRasterSdeConnection2.put_InputRasterName

           INPUT
            inputName           : BSTR'''
        return super(IRasterSdeConnection2, self).put_InputRasterName(inputName)
    def get_InputRasterName(self):
        '''Method IRasterSdeConnection2.get_InputRasterName

           OUTPUT
            inputName           : BSTR*'''
        return super(IRasterSdeConnection2, self).get_InputRasterName()
    def put_InputBitMaskName(self, bitMaskName):
        '''Method IRasterSdeConnection2.put_InputBitMaskName

           INPUT
            bitMaskName         : BSTR'''
        return super(IRasterSdeConnection2, self).put_InputBitMaskName(bitMaskName)
    def get_InputBitMaskName(self):
        '''Method IRasterSdeConnection2.get_InputBitMaskName

           OUTPUT
            bitMaskName         : BSTR*'''
        return super(IRasterSdeConnection2, self).get_InputBitMaskName()
    def put_SdeConnection(self, _arg1):
        '''Method IRasterSdeConnection2.put_SdeConnection

           INPUT
            _arg1               : IGxDatabase*'''
        return super(IRasterSdeConnection2, self).put_SdeConnection(_arg1)
    def put_SdeWorkspaceName(self, _arg1):
        '''Method IRasterSdeConnection2.put_SdeWorkspaceName

           INPUT
            _arg1               : IWorkspaceName*'''
        return super(IRasterSdeConnection2, self).put_SdeWorkspaceName(_arg1)
    def get_Raster(self):
        '''Method IRasterSdeConnection2.get_Raster

           OUTPUT
            Raster              : IRaster**'''
        return super(IRasterSdeConnection2, self).get_Raster()
    def putref_Raster(self, Raster):
        '''Method IRasterSdeConnection2.putref_Raster

           INPUT
            Raster              : IRaster*'''
        return super(IRasterSdeConnection2, self).putref_Raster(Raster)
    def get_MaskRaster(self):
        '''Method IRasterSdeConnection2.get_MaskRaster

           OUTPUT
            MaskRaster          : IRaster**'''
        return super(IRasterSdeConnection2, self).get_MaskRaster()
    def putref_MaskRaster(self, MaskRaster):
        '''Method IRasterSdeConnection2.putref_MaskRaster

           INPUT
            MaskRaster          : IRaster*'''
        return super(IRasterSdeConnection2, self).putref_MaskRaster(MaskRaster)
    Database = property(get_Database, put_Database, None)
    InputBitMaskName = property(get_InputBitMaskName, put_InputBitMaskName, None)
    InputRasterName = property(get_InputRasterName, put_InputRasterName, None)
    Instance = property(get_Instance, put_Instance, None)
    MaskRaster = property(get_MaskRaster, putref_MaskRaster, None)
    Password = property(get_Password, put_Password, None)
    Raster = property(get_Raster, putref_Raster, None)
    SdeConnection = property(None, put_SdeConnection, None)
    SdeRasterName = property(get_SdeRasterName, put_SdeRasterName, None)
    SdeWorkspaceName = property(None, put_SdeWorkspaceName, None)
    ServerName = property(get_ServerName, put_ServerName, None)
    UserName = property(get_UserName, put_UserName, None)


# IIDs
IID_IRasterSdeConnection = IRasterSdeConnection._IID
IID_IRasterSdeConnection2 = IRasterSdeConnection2._IID
_IIDMap[IID_IRasterSdeConnection] = IRasterSdeConnection
_IIDMap[IID_IRasterSdeConnection2] = IRasterSdeConnection2


# CLSIDs
CLSID_CreateRasterDatasetDlg = uuid.UUID('6956b489-197d-4b3b-ae85-9b5a4aef7c62')
CLSID_RasterSdeLoader = uuid.UUID('cc17adc2-fe14-11d3-b2bf-00c04f8edeff')

