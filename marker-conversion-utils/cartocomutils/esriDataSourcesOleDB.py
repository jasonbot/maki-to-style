'Type library'
__all__ = ['IFDOToADOConnection', 'IOleDBFDOHelper', 'IESRIDataSourceCreate', 'OLEDBWorkspaceFactory', 'TextFileWorkspaceFactory', 'ExcelWorkspaceFactory', 'FdoAdoConnection', 'IID_IFDOToADOConnection', 'IID_IOleDBFDOHelper', 'IID_IESRIDataSourceCreate', 'CLSID_OLEDBWorkspaceFactory', 'CLSID_TextFileWorkspaceFactory', 'CLSID_ExcelWorkspaceFactory', 'CLSID_FdoAdoConnection']
from cartocomutils import _esriDataSourcesOleDB
from cartocomutils._esriDataSourcesOleDB import OLEDBWorkspaceFactory, TextFileWorkspaceFactory, ExcelWorkspaceFactory, FdoAdoConnection
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IFDOToADOConnection(_esriDataSourcesOleDB.IFDOToADOConnection):
    _IID = uuid.UUID('7461df2c-6389-11d2-aaaf-00c04fa37849')
    def Connect(self, pWorkspace, pADOConnection):
        '''Method IFDOToADOConnection.Connect

           INPUTS
            pWorkspace          : IWorkspace*
            pADOConnection      : IUnknown*'''
        return super(IFDOToADOConnection, self).Connect(pWorkspace, pADOConnection)
    def CreateADOConnection(self, pWorkspace):
        '''Method IFDOToADOConnection.CreateADOConnection

           INPUT
            pWorkspace          : IWorkspace*

           OUTPUT
            pADOConnection      : IUnknown**'''
        return super(IFDOToADOConnection, self).CreateADOConnection(pWorkspace)

class IOleDBFDOHelper(_esriDataSourcesOleDB.IOleDBFDOHelper):
    _IID = uuid.UUID('7461df2b-6389-11d2-aaaf-00c04fa37849')
    def AttachWorkspace(self, pWorkspace):
        '''Method IOleDBFDOHelper.AttachWorkspace

           INPUT
            pWorkspace          : IWorkspace*'''
        return super(IOleDBFDOHelper, self).AttachWorkspace(pWorkspace)

class IESRIDataSourceCreate(_esriDataSourcesOleDB.IESRIDataSourceCreate):
    _IID = uuid.UUID('7e82a55f-637d-11d2-aaaf-00c04fa37849')
    def CreateDataSource(self, pWorkspace):
        '''Method IESRIDataSourceCreate.CreateDataSource

           INPUT
            pWorkspace          : IWorkspace*

           OUTPUT
            pDataSource         : IUnknown**'''
        return super(IESRIDataSourceCreate, self).CreateDataSource(pWorkspace)


# IIDs
IID_IFDOToADOConnection = IFDOToADOConnection._IID
IID_IOleDBFDOHelper = IOleDBFDOHelper._IID
IID_IESRIDataSourceCreate = IESRIDataSourceCreate._IID
_IIDMap[IID_IFDOToADOConnection] = IFDOToADOConnection
_IIDMap[IID_IOleDBFDOHelper] = IOleDBFDOHelper
_IIDMap[IID_IESRIDataSourceCreate] = IESRIDataSourceCreate


# CLSIDs
CLSID_OLEDBWorkspaceFactory = uuid.UUID('59158055-3171-11d2-aa94-00c04fa37849')
CLSID_TextFileWorkspaceFactory = uuid.UUID('72ce59ec-0be8-11d4-ae03-00c04fa33a15')
CLSID_ExcelWorkspaceFactory = uuid.UUID('30f6f271-852b-4ee8-bd2d-099f51d6b238')
CLSID_FdoAdoConnection = uuid.UUID('fdde3870-638b-11d2-aaaf-00c04fa37849')

