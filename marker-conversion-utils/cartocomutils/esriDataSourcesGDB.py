'Type library'
__all__ = ['IDatabaseLockInfo', 'IEnumDatabaseLockInfo', 'IDatabaseLocksInfo', 'IFileGDBLockWaiting', 'IDataServerManager', 'IDataServerManagerAdmin', 'IServiceControl', 'AccessWorkspaceFactory', 'ScratchWorkspaceFactory', 'SdeWorkspaceFactory', 'Sde4Workspace', 'Sde3Workspace', 'FgdbTableName', 'FgdbFeatureClassName', 'FileGDBWorkspaceFactory', 'FileGDBScratchWorkspaceFactory', 'DataServerManager', 'InMemoryWorkspaceFactory', 'SqlWorkspaceFactory', 'SqlWorkspace', 'IID_IDatabaseLockInfo', 'IID_IEnumDatabaseLockInfo', 'IID_IDatabaseLocksInfo', 'IID_IFileGDBLockWaiting', 'IID_IDataServerManager', 'IID_IDataServerManagerAdmin', 'IID_IServiceControl', 'CLSID_AccessWorkspaceFactory', 'CLSID_ScratchWorkspaceFactory', 'CLSID_SdeWorkspaceFactory', 'CLSID_Sde4Workspace', 'CLSID_Sde3Workspace', 'CLSID_FgdbTableName', 'CLSID_FgdbFeatureClassName', 'CLSID_FileGDBWorkspaceFactory', 'CLSID_FileGDBScratchWorkspaceFactory', 'CLSID_DataServerManager', 'CLSID_InMemoryWorkspaceFactory', 'CLSID_SqlWorkspaceFactory', 'CLSID_SqlWorkspace', 'sdeError', 'esriDataServerStatusType', 'esriDataServerType', 'esriGeodatabasePermissionsType']
from cartocomutils import _esriDataSourcesGDB
from cartocomutils._esriDataSourcesGDB import AccessWorkspaceFactory, ScratchWorkspaceFactory, SdeWorkspaceFactory, Sde4Workspace, Sde3Workspace, FgdbTableName, FgdbFeatureClassName, FileGDBWorkspaceFactory, FileGDBScratchWorkspaceFactory, DataServerManager, InMemoryWorkspaceFactory, SqlWorkspaceFactory, SqlWorkspace
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IDatabaseLockInfo(_esriDataSourcesGDB.IDatabaseLockInfo):
    _IID = uuid.UUID('58f47253-0f9d-4e59-a573-6a3267d0810c')
    def get_SessionID(self):
        '''Method IDatabaseLockInfo.get_SessionID

           OUTPUT
            SessionID           : long*'''
        return super(IDatabaseLockInfo, self).get_SessionID()
    def get_LockOwner(self):
        '''Method IDatabaseLockInfo.get_LockOwner

           OUTPUT
            owner               : BSTR*'''
        return super(IDatabaseLockInfo, self).get_LockOwner()
    def get_LockMode(self):
        '''Method IDatabaseLockInfo.get_LockMode

           OUTPUT
            mode                : esriSdeLockMode*'''
        return super(IDatabaseLockInfo, self).get_LockMode()
    def get_LockTime(self):
        '''Method IDatabaseLockInfo.get_LockTime

           OUTPUT
            time                : VARIANT*'''
        return super(IDatabaseLockInfo, self).get_LockTime()
    def get_LockType(self):
        '''Method IDatabaseLockInfo.get_LockType

           OUTPUT
            LockType            : esriSdeLockType*'''
        return super(IDatabaseLockInfo, self).get_LockType()
    def get_ObjectID(self):
        '''Method IDatabaseLockInfo.get_ObjectID

           OUTPUT
            ID                  : __int64*'''
        return super(IDatabaseLockInfo, self).get_ObjectID()
    def get_ObjectName(self):
        '''Method IDatabaseLockInfo.get_ObjectName

           OUTPUT
            name                : BSTR*'''
        return super(IDatabaseLockInfo, self).get_ObjectName()
    def get_DatasetType(self):
        '''Method IDatabaseLockInfo.get_DatasetType

           OUTPUT
            type                : esriDatasetType*'''
        return super(IDatabaseLockInfo, self).get_DatasetType()
    def get_IsOwnLock(self):
        '''Method IDatabaseLockInfo.get_IsOwnLock

           OUTPUT
            IsOwnLock           : VARIANT_BOOL*'''
        return super(IDatabaseLockInfo, self).get_IsOwnLock()
    DatasetType = property(get_DatasetType, None, None)
    IsOwnLock = property(get_IsOwnLock, None, None)
    LockMode = property(get_LockMode, None, None)
    LockOwner = property(get_LockOwner, None, None)
    LockTime = property(get_LockTime, None, None)
    LockType = property(get_LockType, None, None)
    ObjectID = property(get_ObjectID, None, None)
    ObjectName = property(get_ObjectName, None, None)
    SessionID = property(get_SessionID, None, None)

class IEnumDatabaseLockInfo(_esriDataSourcesGDB.IEnumDatabaseLockInfo):
    _IID = uuid.UUID('225e1781-17cf-468e-a3d2-a59df3bb2d62')
    def Reset(self):
        '''Method IEnumDatabaseLockInfo.Reset'''
        return super(IEnumDatabaseLockInfo, self).Reset()
    def Next(self):
        '''Method IEnumDatabaseLockInfo.Next

           OUTPUT
            lockInfo            : IDatabaseLockInfo**'''
        return super(IEnumDatabaseLockInfo, self).Next()
    def __iter__(self):
        try:
            super(IEnumDatabaseLockInfo, self).Reset()
            val = super(IEnumDatabaseLockInfo, self).Next()
            while val:
                yield val
                val = super(IEnumDatabaseLockInfo, self).Next()
        except:
            pass

class IDatabaseLocksInfo(_esriDataSourcesGDB.IDatabaseLocksInfo):
    _IID = uuid.UUID('8aee3af9-4b7c-4c88-ba9f-388a9791d907')
    def get_AllLocks(self):
        '''Method IDatabaseLocksInfo.get_AllLocks

           OUTPUT
            locks               : IEnumDatabaseLockInfo**'''
        return super(IDatabaseLocksInfo, self).get_AllLocks()
    AllLocks = property(get_AllLocks, None, None)

class IFileGDBLockWaiting(_esriDataSourcesGDB.IFileGDBLockWaiting):
    _IID = uuid.UUID('097854c7-dbcb-483e-8730-fa5f42744ecc')
    def EnableWriteLockWaiting(self, retryCount, waitTime1, waitTime2, waitTime3):
        '''Method IFileGDBLockWaiting.EnableWriteLockWaiting

           INPUTS
            retryCount          : long
            waitTime1           : long
            waitTime2           : long
            waitTime3           : long'''
        return super(IFileGDBLockWaiting, self).EnableWriteLockWaiting(retryCount, waitTime1, waitTime2, waitTime3)
    def DisableWriteLockWaiting(self):
        '''Method IFileGDBLockWaiting.DisableWriteLockWaiting'''
        return super(IFileGDBLockWaiting, self).DisableWriteLockWaiting()

class IDataServerManager(_esriDataSourcesGDB.IDataServerManager):
    _IID = uuid.UUID('737ef71f-3646-49f3-95b9-667259a5d498')

    def __init__(self, *args, **kw):
        super(IDataServerManager, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def Connect(self):
        '''Method IDataServerManager.Connect'''
        return super(IDataServerManager, self).Connect()
    def Disconnect(self):
        '''Method IDataServerManager.Disconnect'''
        return super(IDataServerManager, self).Disconnect()
    def put_ServerName(self, ServerName):
        '''Method IDataServerManager.put_ServerName

           INPUT
            ServerName          : BSTR'''
        return super(IDataServerManager, self).put_ServerName(ServerName)
    def get_ServerName(self):
        '''Method IDataServerManager.get_ServerName

           OUTPUT
            ServerName          : BSTR*'''
        return super(IDataServerManager, self).get_ServerName()
    def InitFromFile(self, gdsFileName):
        '''Method IDataServerManager.InitFromFile

           INPUT
            gdsFileName         : BSTR'''
        return super(IDataServerManager, self).InitFromFile(gdsFileName)
    def CreateConnectionFile(self, pathName, ServerName):
        '''Method IDataServerManager.CreateConnectionFile

           INPUTS
            pathName            : BSTR
            ServerName          : BSTR

           OUTPUT
            connFileName        : BSTR*'''
        return super(IDataServerManager, self).CreateConnectionFile(pathName, ServerName)
    def get_IsConnected(self):
        '''Method IDataServerManager.get_IsConnected

           OUTPUT
            IsConnected         : VARIANT_BOOL*'''
        return super(IDataServerManager, self).get_IsConnected()
    def get_DataServerType(self):
        '''Method IDataServerManager.get_DataServerType

           OUTPUT
            type                : esriDataServerType*'''
        return super(IDataServerManager, self).get_DataServerType()
    def get_ProductName(self):
        '''Method IDataServerManager.get_ProductName

           OUTPUT
            name                : BSTR*'''
        return super(IDataServerManager, self).get_ProductName()
    def get_ProductVersion(self):
        '''Method IDataServerManager.get_ProductVersion

           OUTPUT
            version             : BSTR*'''
        return super(IDataServerManager, self).get_ProductVersion()
    def get_AvailableMemory(self):
        '''Method IDataServerManager.get_AvailableMemory

           OUTPUT
            memory              : long*'''
        return super(IDataServerManager, self).get_AvailableMemory()
    def get_DataServerClass(self):
        '''Method IDataServerManager.get_DataServerClass

           OUTPUT
            sclass              : esriGeodatabaseServerClassType*'''
        return super(IDataServerManager, self).get_DataServerClass()
    AvailableMemory = property(get_AvailableMemory, None, None)
    DataServerClass = property(get_DataServerClass, None, None)
    DataServerType = property(get_DataServerType, None, None)
    IsConnected = property(get_IsConnected, None, None)
    ProductName = property(get_ProductName, None, None)
    ProductVersion = property(get_ProductVersion, None, None)
    ServerName = property(get_ServerName, put_ServerName, None)

class IDataServerManagerAdmin(_esriDataSourcesGDB.IDataServerManagerAdmin):
    _IID = uuid.UUID('dd374473-eda4-4a24-80f5-0b8c708a453b')
    def CreateGeodatabase(self, gdbName, gdbFileName, gdbFileSize, logFileName, logFileSize):
        '''Method IDataServerManagerAdmin.CreateGeodatabase

           INPUTS
            gdbName             : BSTR
            gdbFileName         : BSTR
            gdbFileSize         : long
            logFileName         : BSTR
            logFileSize         : long'''
        return super(IDataServerManagerAdmin, self).CreateGeodatabase(gdbName, gdbFileName, gdbFileSize, logFileName, logFileSize)
    def DeleteGeodatabase(self, gdbName):
        '''Method IDataServerManagerAdmin.DeleteGeodatabase

           INPUT
            gdbName             : BSTR'''
        return super(IDataServerManagerAdmin, self).DeleteGeodatabase(gdbName)
    def CreateLogin(self, loginName, isAdministrator):
        '''Method IDataServerManagerAdmin.CreateLogin

           INPUTS
            loginName           : BSTR
            isAdministrator     : VARIANT_BOOL'''
        return super(IDataServerManagerAdmin, self).CreateLogin(loginName, isAdministrator)
    def ModifyLoginSecurity(self, loginName, isAdministrator):
        '''Method IDataServerManagerAdmin.ModifyLoginSecurity

           INPUTS
            loginName           : BSTR
            isAdministrator     : VARIANT_BOOL'''
        return super(IDataServerManagerAdmin, self).ModifyLoginSecurity(loginName, isAdministrator)
    def ModifyGeodatabaseSecurity(self, dbName, loginName, permission):
        '''Method IDataServerManagerAdmin.ModifyGeodatabaseSecurity

           INPUTS
            dbName              : BSTR
            loginName           : BSTR
            permission          : esriGeodatabasePermissionsType'''
        return super(IDataServerManagerAdmin, self).ModifyGeodatabaseSecurity(dbName, loginName, permission)
    def DeleteLogin(self, loginName):
        '''Method IDataServerManagerAdmin.DeleteLogin

           INPUT
            loginName           : BSTR'''
        return super(IDataServerManagerAdmin, self).DeleteLogin(loginName)
    def GetGeodatabaseNames(self):
        '''Method IDataServerManagerAdmin.GetGeodatabaseNames

           OUTPUT
            ppNames             : IEnumBSTR**'''
        return super(IDataServerManagerAdmin, self).GetGeodatabaseNames()
    def GetLogins(self):
        '''Method IDataServerManagerAdmin.GetLogins

           OUTPUTS
            loginNames          : IEnumBSTR**
            dbNames             : IEnumBSTR**
            loginTypes          : IEnumBSTR**
            languages           : IEnumBSTR**'''
        return super(IDataServerManagerAdmin, self).GetLogins()
    def DetachGeodatabase(self, dbName):
        '''Method IDataServerManagerAdmin.DetachGeodatabase

           INPUT
            dbName              : BSTR'''
        return super(IDataServerManagerAdmin, self).DetachGeodatabase(dbName)
    def AttachGeodatabase(self, dbName, dataFileName, logFileName):
        '''Method IDataServerManagerAdmin.AttachGeodatabase

           INPUTS
            dbName              : BSTR
            dataFileName        : BSTR
            logFileName         : BSTR'''
        return super(IDataServerManagerAdmin, self).AttachGeodatabase(dbName, dataFileName, logFileName)
    def UpgradeGeoDatabase(self, gdbName):
        '''Method IDataServerManagerAdmin.UpgradeGeoDatabase

           INPUT
            gdbName             : BSTR'''
        return super(IDataServerManagerAdmin, self).UpgradeGeoDatabase(gdbName)
    def UpgradeSDESchema(self, gdbName):
        '''Method IDataServerManagerAdmin.UpgradeSDESchema

           INPUT
            gdbName             : BSTR'''
        return super(IDataServerManagerAdmin, self).UpgradeSDESchema(gdbName)
    def GetGeodatabaseName(self, dataFileName):
        '''Method IDataServerManagerAdmin.GetGeodatabaseName

           INPUT
            dataFileName        : BSTR

           OUTPUT
            dbName              : BSTR*'''
        return super(IDataServerManagerAdmin, self).GetGeodatabaseName(dataFileName)
    def BackupGeodatabase(self, gdbName, backupFileName, backupName, description):
        '''Method IDataServerManagerAdmin.BackupGeodatabase

           INPUTS
            gdbName             : BSTR
            backupFileName      : BSTR
            backupName          : BSTR
            description         : BSTR

           OUTPUT
            IsSimpleRecoveryModel: VARIANT_BOOL*'''
        return super(IDataServerManagerAdmin, self).BackupGeodatabase(gdbName, backupFileName, backupName, description)
    def RestoreGeodatabase(self, gdbName, backupFileName, dbFilePath):
        '''Method IDataServerManagerAdmin.RestoreGeodatabase

           INPUTS
            gdbName             : BSTR
            backupFileName      : BSTR
            dbFilePath          : BSTR'''
        return super(IDataServerManagerAdmin, self).RestoreGeodatabase(gdbName, backupFileName, dbFilePath)
    def IsSimpleRecoveryModel(self, gdbName, IsSimpleRecoveryModel):
        '''Method IDataServerManagerAdmin.IsSimpleRecoveryModel

           INPUTS
            gdbName             : BSTR
            IsSimpleRecoveryModel: VARIANT_BOOL*'''
        return super(IDataServerManagerAdmin, self).IsSimpleRecoveryModel(gdbName, IsSimpleRecoveryModel)
    def SetGeodatabaseToSimpleRecoveryModel(self, gdbName):
        '''Method IDataServerManagerAdmin.SetGeodatabaseToSimpleRecoveryModel

           INPUT
            gdbName             : BSTR'''
        return super(IDataServerManagerAdmin, self).SetGeodatabaseToSimpleRecoveryModel(gdbName)
    def get_IsConnectedUserAdministrator(self):
        '''Method IDataServerManagerAdmin.get_IsConnectedUserAdministrator

           OUTPUT
            isAdministrator     : VARIANT_BOOL*'''
        return super(IDataServerManagerAdmin, self).get_IsConnectedUserAdministrator()
    def CreateWorkspaceName(self, gdbName, versionPropName, versionSpecifier):
        '''Method IDataServerManagerAdmin.CreateWorkspaceName

           INPUTS
            gdbName             : BSTR
            versionPropName     : BSTR
            versionSpecifier    : VARIANT

           OUTPUT
            workspaceName       : IWorkspaceName**'''
        return super(IDataServerManagerAdmin, self).CreateWorkspaceName(gdbName, versionPropName, versionSpecifier)
    def GetDBProperties(self, dbName):
        '''Method IDataServerManagerAdmin.GetDBProperties

           INPUT
            dbName              : BSTR

           OUTPUTS
            status              : BSTR*
            dbSize              : long*
            owner               : BSTR*
            createDate          : VARIANT*
            dbBackup            : VARIANT*'''
        return super(IDataServerManagerAdmin, self).GetDBProperties(dbName)
    def GetFileProperties(self, dbName):
        '''Method IDataServerManagerAdmin.GetFileProperties

           INPUT
            dbName              : BSTR

           OUTPUTS
            dataName            : BSTR*
            dataPhysicalName    : BSTR*
            dataFileSize        : long*
            logName             : BSTR*
            logPhysicalName     : BSTR*
            logFileSize         : long*'''
        return super(IDataServerManagerAdmin, self).GetFileProperties(dbName)
    def Analyze(self, gdbName):
        '''Method IDataServerManagerAdmin.Analyze

           INPUT
            gdbName             : BSTR'''
        return super(IDataServerManagerAdmin, self).Analyze(gdbName)
    def RebuildIndices(self, gdbName):
        '''Method IDataServerManagerAdmin.RebuildIndices

           INPUT
            gdbName             : BSTR'''
        return super(IDataServerManagerAdmin, self).RebuildIndices(gdbName)
    def ShrinkGeodatabase(self, gdbName):
        '''Method IDataServerManagerAdmin.ShrinkGeodatabase

           INPUT
            gdbName             : BSTR'''
        return super(IDataServerManagerAdmin, self).ShrinkGeodatabase(gdbName)
    def GetConnectedUsers(self, dbName):
        '''Method IDataServerManagerAdmin.GetConnectedUsers

           INPUT
            dbName              : BSTR

           OUTPUT
            nUsers              : long*'''
        return super(IDataServerManagerAdmin, self).GetConnectedUsers(dbName)
    def GetServerAdministrators(self):
        '''Method IDataServerManagerAdmin.GetServerAdministrators

           OUTPUT
            userNames           : IEnumBSTR**'''
        return super(IDataServerManagerAdmin, self).GetServerAdministrators()
    def GetUsersByPermissionType(self, dbName, permission):
        '''Method IDataServerManagerAdmin.GetUsersByPermissionType

           INPUTS
            dbName              : BSTR
            permission          : esriGeodatabasePermissionsType

           OUTPUT
            userNames           : IEnumBSTR**'''
        return super(IDataServerManagerAdmin, self).GetUsersByPermissionType(dbName, permission)
    IsConnectedUserAdministrator = property(get_IsConnectedUserAdministrator, None, None)

class IServiceControl(_esriDataSourcesGDB.IServiceControl):
    _IID = uuid.UUID('271445cb-af1b-483a-a91e-337fa7bf2c0c')
    def get_ServerStatus(self):
        '''Method IServiceControl.get_ServerStatus

           OUTPUT
            status              : esriDataServerStatusType*'''
        return super(IServiceControl, self).get_ServerStatus()
    def get_HasControlPermissions(self):
        '''Method IServiceControl.get_HasControlPermissions

           OUTPUT
            hasPermissions      : VARIANT_BOOL*'''
        return super(IServiceControl, self).get_HasControlPermissions()
    def StopServer(self):
        '''Method IServiceControl.StopServer'''
        return super(IServiceControl, self).StopServer()
    def StartServer(self):
        '''Method IServiceControl.StartServer'''
        return super(IServiceControl, self).StartServer()
    def PauseServer(self):
        '''Method IServiceControl.PauseServer'''
        return super(IServiceControl, self).PauseServer()
    def ContinueServer(self):
        '''Method IServiceControl.ContinueServer'''
        return super(IServiceControl, self).ContinueServer()
    HasControlPermissions = property(get_HasControlPermissions, None, None)
    ServerStatus = property(get_ServerStatus, None, None)


# IIDs
IID_IDatabaseLockInfo = IDatabaseLockInfo._IID
IID_IEnumDatabaseLockInfo = IEnumDatabaseLockInfo._IID
IID_IDatabaseLocksInfo = IDatabaseLocksInfo._IID
IID_IFileGDBLockWaiting = IFileGDBLockWaiting._IID
IID_IDataServerManager = IDataServerManager._IID
IID_IDataServerManagerAdmin = IDataServerManagerAdmin._IID
IID_IServiceControl = IServiceControl._IID
_IIDMap[IID_IDatabaseLockInfo] = IDatabaseLockInfo
_IIDMap[IID_IEnumDatabaseLockInfo] = IEnumDatabaseLockInfo
_IIDMap[IID_IDatabaseLocksInfo] = IDatabaseLocksInfo
_IIDMap[IID_IFileGDBLockWaiting] = IFileGDBLockWaiting
_IIDMap[IID_IDataServerManager] = IDataServerManager
_IIDMap[IID_IDataServerManagerAdmin] = IDataServerManagerAdmin
_IIDMap[IID_IServiceControl] = IServiceControl


# CLSIDs
CLSID_AccessWorkspaceFactory = uuid.UUID('dd48c96a-d92a-11d1-aa81-00c04fa33a15')
CLSID_ScratchWorkspaceFactory = uuid.UUID('06dc8e4c-951c-11d2-ae75-080009ec732a')
CLSID_SdeWorkspaceFactory = uuid.UUID('d9b4fa40-d6d9-11d1-aa81-00c04fa33a15')
CLSID_Sde4Workspace = uuid.UUID('977c9b25-9b31-11d0-9ce2-0080c79f698f')
CLSID_Sde3Workspace = uuid.UUID('156ebb05-1488-11d3-9f40-00c04f6bddd9')
CLSID_FgdbTableName = uuid.UUID('846c88c5-6cc5-49c7-a6fe-8fa03d79bd07')
CLSID_FgdbFeatureClassName = uuid.UUID('75e10086-4226-42ac-afec-cbb9b748f847')
CLSID_FileGDBWorkspaceFactory = uuid.UUID('71fe75f0-ea0c-4406-873e-b7d53748ae7e')
CLSID_FileGDBScratchWorkspaceFactory = uuid.UUID('d9652a31-6b85-480d-8637-91a7dba2fe28')
CLSID_DataServerManager = uuid.UUID('2db75dea-bded-482d-80d9-331e92449627')
CLSID_InMemoryWorkspaceFactory = uuid.UUID('7f2bc55c-b902-43d0-a566-aa47ea9fda2c')
CLSID_SqlWorkspaceFactory = uuid.UUID('5297187b-fd2b-4a5f-8991-eb3f6f1ca502')
CLSID_SqlWorkspace = uuid.UUID('1c062199-9253-4463-8e7a-e956f2998d65')

# Enumerations
class sdeError(Enumeration):
    __slots__ = ['SDE_E_SE_FAILURE',
                 'SDE_E_SE_INVALID_LAYERINFO_OBJECT',
                 'SDE_E_SE_NO_ANNOTATION',
                 'SDE_E_SE_FINISHED',
                 'SDE_E_SE_SDE_NOT_STARTED',
                 'SDE_E_SE_UNCHANGED',
                 'SDE_E_SE_TASKS_EXCEEDED',
                 'SDE_E_SE_CONNECTIONS_EXCEEDED',
                 'SDE_E_SE_LOGIN_NOT_ALLOWED',
                 'SDE_E_SE_INVALID_USER',
                 'SDE_E_SE_NET_FAILURE',
                 'SDE_E_SE_NET_TIMEOUT',
                 'SDE_E_SE_OUT_OF_SVMEM',
                 'SDE_E_SE_OUT_OF_CLMEM',
                 'SDE_E_SE_OUT_OF_CONTEXT',
                 'SDE_E_SE_NO_ACCESS',
                 'SDE_E_SE_TOO_MANY_LAYERS',
                 'SDE_E_SE_NO_LAYER_SPECIFIED',
                 'SDE_E_SE_LAYER_LOCKED',
                 'SDE_E_SE_LAYER_EXISTS',
                 'SDE_E_SE_LAYER_NOEXIST',
                 'SDE_E_SE_LAYER_INUSE',
                 'SDE_E_SE_FID_NOEXIST',
                 'SDE_E_SE_ROW_NOEXIST',
                 'SDE_E_SE_FID_EXISTS',
                 'SDE_E_SE_ROW_EXISTS',
                 'SDE_E_SE_LAYER_MISMATCH',
                 'SDE_E_SE_NO_PERMISSIONS',
                 'SDE_E_SE_INVALID_NOT_NULL',
                 'SDE_E_SE_INVALID_SHAPE',
                 'SDE_E_SE_INVALID_LAYER_NUMBER',
                 'SDE_E_SE_INVALID_ENTITY_TYPE',
                 'SDE_E_SE_INVALID_SEARCH_METHOD',
                 'SDE_E_SE_INVALID_ETYPE_MASK',
                 'SDE_E_SE_BIND_CONFLICT',
                 'SDE_E_SE_INVALID_GRIDSIZE',
                 'SDE_E_SE_INVALID_LOCK_MODE',
                 'SDE_E_SE_ETYPE_NOT_ALLOWED',
                 'SDE_E_SE_TOO_MANY_POINTS',
                 'SDE_E_SE_INVALID_NUM_OF_PTS',
                 'SDE_E_SE_TABLE_NOEXIST',
                 'SDE_E_SE_ATTR_NOEXIST',
                 'SDE_E_SE_LICENSE_FAILURE',
                 'SDE_E_SE_OUT_OF_LICENSES',
                 'SDE_E_SE_INVALID_COLUMN_VALUE',
                 'SDE_E_SE_INVALID_WHERE',
                 'SDE_E_SE_INVALID_SQL',
                 'SDE_E_SE_LOG_NOEXIST',
                 'SDE_E_SE_LOG_NOACCESS',
                 'SDE_E_SE_LOG_NOTOPEN',
                 'SDE_E_SE_LOG_IO_ERROR',
                 'SDE_E_SE_NO_SHAPES',
                 'SDE_E_SE_NO_LOCKS',
                 'SDE_E_SE_LOCK_CONFLICT',
                 'SDE_E_SE_OUT_OF_LOCKS',
                 'SDE_E_SE_DB_IO_ERROR',
                 'SDE_E_SE_STREAM_IN_PROGRESS',
                 'SDE_E_SE_INVALID_COLUMN_TYPE',
                 'SDE_E_SE_TOPO_ERROR',
                 'SDE_E_SE_ATTR_CONV_ERROR',
                 'SDE_E_SE_INVALID_COLUMN_DEF',
                 'SDE_E_SE_INVALID_SHAPE_BUF_SIZE',
                 'SDE_E_SE_INVALID_ENVELOPE',
                 'SDE_E_SE_TEMP_IO_ERROR',
                 'SDE_E_SE_GSIZE_TOO_SMALL',
                 'SDE_E_SE_LICENSE_EXPIRED',
                 'SDE_E_SE_TABLE_EXISTS',
                 'SDE_E_SE_INDEX_EXISTS',
                 'SDE_E_SE_INDEX_NOEXIST',
                 'SDE_E_SE_INVALID_POINTER',
                 'SDE_E_SE_INVALID_PARAM_VALUE',
                 'SDE_E_SE_ALL_SLIVERS',
                 'SDE_E_SE_TRANS_IN_PROGRESS',
                 'SDE_E_SE_IOMGR_NO_DBMS_CONNECT',
                 'SDE_E_SE_DUPLICATE_ARC',
                 'SDE_E_SE_INVALID_ANNO_OBJECT',
                 'SDE_E_SE_PT_NO_EXIST',
                 'SDE_E_SE_PTS_NOT_ADJACENT',
                 'SDE_E_SE_INVALID_MID_PT',
                 'SDE_E_SE_INVALID_END_PT',
                 'SDE_E_SE_INVALID_RADIUS',
                 'SDE_E_SE_LOAD_ONLY_LAYER',
                 'SDE_E_SE_LAYERS_NOT_FOUND',
                 'SDE_E_SE_FILE_IO_ERROR',
                 'SDE_E_SE_BLOB_SIZE_TOO_LARGE',
                 'SDE_E_SE_CORRIDOR_OUT_OF_BOUNDS',
                 'SDE_E_SE_SHAPE_INTEGRITY_ERROR',
                 'SDE_E_SE_NOT_IMPLEMENTED_YET',
                 'SDE_E_SE_CAD_EXISTS',
                 'SDE_E_SE_INVALID_TRANSID',
                 'SDE_E_SE_INVALID_LAYER_NAME',
                 'SDE_E_SE_INVALID_LAYER_KEYWORD',
                 'SDE_E_SE_INVALID_RELEASE',
                 'SDE_E_SE_VERSION_TBL_EXISTS',
                 'SDE_E_SE_COLUMN_NOT_BOUND',
                 'SDE_E_SE_INVALID_INDICATOR_VALUE',
                 'SDE_E_SE_INVALID_CONNECTION',
                 'SDE_E_SE_INVALID_DBA_PASSWORD',
                 'SDE_E_SE_PATH_NOT_FOUND',
                 'SDE_E_SE_SDEHOME_NOT_SET',
                 'SDE_E_SE_NOT_TABLE_OWNER',
                 'SDE_E_SE_PROCESS_NOT_FOUND',
                 'SDE_E_SE_INVALID_DBMS_LOGIN',
                 'SDE_E_SE_PASSWORD_TIMEOUT',
                 'SDE_E_SE_INVALID_SERVER',
                 'SDE_E_SE_IOMGR_NOT_AVAILABLE',
                 'SDE_E_SE_SERVICE_NOT_FOUND',
                 'SDE_E_SE_INVALID_STATS_TYPE',
                 'SDE_E_SE_INVALID_DISTINCT_TYPE',
                 'SDE_E_SE_INVALID_GRANT_REVOKE',
                 'SDE_E_SE_INVALID_SDEHOME',
                 'SDE_E_SE_INVALID_STREAM',
                 'SDE_E_SE_TOO_MANY_STREAMS',
                 'SDE_E_SE_OUT_OF_MUTEXES',
                 'SDE_E_SE_CONNECTION_LOCKED',
                 'SDE_E_SE_CONNECTION_IN_USE',
                 'SDE_E_SE_NOT_A_SELECT_STATEMENT',
                 'SDE_E_SE_FUNCTION_SEQUENCE_ERROR',
                 'SDE_E_SE_WRONG_COLUMN_TYPE',
                 'SDE_E_SE_PTABLE_LOCKED',
                 'SDE_E_SE_PTABLE_IN_USE',
                 'SDE_E_SE_STABLE_LOCKED',
                 'SDE_E_SE_STABLE_IN_USE',
                 'SDE_E_SE_INVALID_FILTER_TYPE',
                 'SDE_E_SE_NO_CAD',
                 'SDE_E_SE_INSTANCE_NOT_AVAILABLE',
                 'SDE_E_SE_INSTANCE_TOO_EARLY',
                 'SDE_E_SE_INVALID_SYSTEM_UNITS',
                 'SDE_E_SE_INVALID_UNITS',
                 'SDE_E_SE_INVALID_CAD_OBJECT',
                 'SDE_E_SE_VERSION_NOEXIST',
                 'SDE_E_SE_INVALID_SPATIAL_CONSTRAINT',
                 'SDE_E_SE_INVALID_STREAM_TYPE',
                 'SDE_E_SE_INVALID_SPATIAL_COLUMN',
                 'SDE_E_SE_NO_SPATIAL_MASKS',
                 'SDE_E_SE_IOMGR_NOT_FOUND',
                 'SDE_E_SE_SYSTEM_IS_CLIENT_ONLY',
                 'SDE_E_SE_MULTIPLE_SPATIAL_COLS',
                 'SDE_E_SE_INVALID_SHAPE_OBJECT',
                 'SDE_E_SE_INVALID_PARTNUM',
                 'SDE_E_SE_INCOMPATIBLE_SHAPES',
                 'SDE_E_SE_INVALID_PART_OFFSET',
                 'SDE_E_SE_INCOMPATIBLE_COORDREFS',
                 'SDE_E_SE_COORD_OUT_OF_BOUNDS',
                 'SDE_E_SE_LAYER_CACHE_FULL',
                 'SDE_E_SE_INVALID_COORDREF_OBJECT',
                 'SDE_E_SE_INVALID_COORDSYS_ID',
                 'SDE_E_SE_INVALID_COORDSYS_DESC',
                 'SDE_E_SE_INVALID_ROW_ID_LAYER',
                 'SDE_E_SE_PROJECTION_ERROR',
                 'SDE_E_SE_ARRAY_BYTES_EXCEEDED',
                 'SDE_E_SE_POLY_SHELLS_OVERLAP',
                 'SDE_E_SE_TOO_FEW_POINTS',
                 'SDE_E_SE_INVALID_PART_SEPARATOR',
                 'SDE_E_SE_INVALID_POLYGON_CLOSURE',
                 'SDE_E_SE_INVALID_OUTER_SHELL',
                 'SDE_E_SE_ZERO_AREA_POLYGON',
                 'SDE_E_SE_POLYGON_HAS_VERTICAL_LINE',
                 'SDE_E_SE_OUTER_SHELLS_OVERLAP',
                 'SDE_E_SE_SELF_INTERSECTING',
                 'SDE_E_SE_INVALID_EXPORT_FILE',
                 'SDE_E_SE_READ_ONLY_SHAPE',
                 'SDE_E_SE_INVALID_DATA_SOURCE',
                 'SDE_E_SE_INVALID_STREAM_SPEC',
                 'SDE_E_SE_INVALID_ALTER_OPERATION',
                 'SDE_E_SE_INVALID_SPATIAL_COL_NAME',
                 'SDE_E_SE_INVALID_DATABASE',
                 'SDE_E_SE_SPATIAL_SQL_NOT_INSTALLED',
                 'SDE_E_SE_NORM_DIM_INFO_NOT_FOUND',
                 'SDE_E_SE_NORM_DIM_TAB_VALUE_NOT_FOUND',
                 'SDE_E_SE_UNSUPPORTED_NORMALIZED_OPERATION',
                 'SDE_E_SE_INVALID_REGISTERED_LAYER_OPTION',
                 'SDE_E_SE_READ_ONLY',
                 'SDE_E_SE_NO_SDE_ROWID_COLUMN',
                 'SDE_E_SE_READ_ONLY_COLUMN',
                 'SDE_E_SE_INVALID_VERSION_NAME',
                 'SDE_E_SE_STATE_NOEXIST',
                 'SDE_E_SE_INVALID_STATEINFO_OBJECT',
                 'SDE_E_SE_VERSION_HAS_MOVED',
                 'SDE_E_SE_STATE_HAS_CHILDREN',
                 'SDE_E_SE_PARENT_NOT_CLOSED',
                 'SDE_E_SE_VERSION_EXISTS',
                 'SDE_E_SE_TABLE_NOT_MULTIVERSION',
                 'SDE_E_SE_STATE_USED_BY_VERSION',
                 'SDE_E_SE_INVALID_VERSIONINFO_OBJECT',
                 'SDE_E_SE_INVALID_STATE_ID',
                 'SDE_E_SE_SDETRACELOC_NOT_SET',
                 'SDE_E_SE_ERROR_LOADING_SSA',
                 'SDE_E_SE_TOO_MANY_STATES',
                 'SDE_E_SE_STATES_ARE_SAME',
                 'SDE_E_SE_NO_ROWID_COLUMN',
                 'SDE_E_SE_NO_STATE_SET',
                 'SDE_E_SE_SSA_FUNCTION_ERROR',
                 'SDE_E_SE_INVALID_REGINFO_OBJECT',
                 'SDE_E_SE_NO_COMMON_LINEAGE',
                 'SDE_E_SE_STATE_INUSE',
                 'SDE_E_SE_STATE_TREE_INUSE',
                 'SDE_E_SE_INVALID_RASTER_COLUMN',
                 'SDE_E_SE_RASTERCOLUMN_EXISTS',
                 'SDE_E_SE_INVALID_MVTABLE_INDEX',
                 'SDE_E_SE_INVALID_STORAGE_TYPE',
                 'SDE_E_SE_AMBIGUOUS_NIL_SHAPE',
                 'SDE_E_SE_INVALID_BYTE_ORDER',
                 'SDE_E_SE_INVALID_GEOMETRY_TYPE',
                 'SDE_E_SE_INVALID_NUM_MEASURES',
                 'SDE_E_SE_INVALID_NUM_PARTS',
                 'SDE_E_SE_BINARY_TOO_SMALL',
                 'SDE_E_SE_SHAPE_TEXT_TOO_LONG',
                 'SDE_E_SE_SHAPE_TEXT_ERROR',
                 'SDE_E_SE_TOO_MANY_PARTS',
                 'SDE_E_SE_TYPE_MISMATCH',
                 'SDE_E_SE_SQL_PARENTHESIS_MISMATCH',
                 'SDE_E_SE_NIL_SHAPE_NOT_ALLOWED',
                 'SDE_E_SE_INSTANCE_ALREADY_RUNNING',
                 'SDE_E_SE_UNSUPPORTED_OPERATION',
                 'SDE_E_SE_INVALID_EXTERNAL_LAYER_OPTION',
                 'SDE_E_SE_NORMALIZE_VALUE_NOT_FOUND',
                 'SDE_E_SE_INVALID_QUERY_TYPE',
                 'SDE_E_SE_NO_TRACE_LIBRARY',
                 'SDE_E_SE_TRACE_ON',
                 'SDE_E_SE_TRACE_OFF',
                 'SDE_E_SE_SCL_SYNTAX_ERROR',
                 'SDE_E_SE_TABLE_REGISTERED',
                 'SDE_E_SE_INVALID_REGISTRATION_ID',
                 'SDE_E_SE_TABLE_NOREGISTERED',
                 'SDE_E_SE_TOO_MANY_REGISTRATIONS',
                 'SDE_E_SE_DELETE_NOT_ALLOWED',
                 'SDE_E_SE_ROWLOCKING_ENABLED',
                 'SDE_E_SE_ROWLOCKING_NOT_ENABLED',
                 'SDE_E_SE_RASTERCOLUMN_INUSE',
                 'SDE_E_SE_RASTERCOLUMN_NOEXIST',
                 'SDE_E_SE_INVALID_RASTERCOLUMN_NUMBER',
                 'SDE_E_SE_TOO_MANY_RASTERCOLUMNS',
                 'SDE_E_SE_INVALID_RASTER_NUMBER',
                 'SDE_E_SE_NO_REQUEST_STATUS',
                 'SDE_E_SE_NO_REQUEST_RESULTS',
                 'SDE_E_SE_RASTERBAND_EXISTS',
                 'SDE_E_SE_RASTERBAND_NOEXIST',
                 'SDE_E_SE_RASTER_EXISTS',
                 'SDE_E_SE_RASTER_NOEXIST',
                 'SDE_E_SE_TOO_MANY_RASTERBANDS',
                 'SDE_E_SE_TOO_MANY_RASTERS',
                 'SDE_E_SE_VIEW_EXISTS',
                 'SDE_E_SE_VIEW_NOEXIST',
                 'SDE_E_SE_LOCK_EXISTS',
                 'SDE_E_SE_ROWLOCK_MASK_CONFLICT',
                 'SDE_E_SE_NOT_IN_RASTER',
                 'SDE_E_SE_INVALID_RASBANDINFO_OBJECT',
                 'SDE_E_SE_INVALID_RASCOLINFO_OBJECT',
                 'SDE_E_SE_INVALID_RASTERINFO_OBJECT',
                 'SDE_E_SE_INVALID_RASTERBAND_NUMBER',
                 'SDE_E_SE_MULTIPLE_RASTER_COLS',
                 'SDE_E_SE_TABLE_SCHEMA_IS_LOCKED',
                 'SDE_E_SE_INVALID_LOGINFO_OBJECT',
                 'SDE_E_SE_SQL_TOO_LONG',
                 'SDE_E_SE_UNSUPPORTED_ON_VIEW',
                 'SDE_E_SE_LOG_EXISTS',
                 'SDE_E_SE_LOG_IS_OPEN',
                 'SDE_E_SE_SPATIALREF_EXISTS',
                 'SDE_E_SE_SPATIALREF_NOEXIST',
                 'SDE_E_SE_SPATIALREF_IN_USE',
                 'SDE_E_SE_INVALID_SPATIALREFINFO_OBJECT',
                 'SDE_E_SE_SEQUENCENBR_EXISTS',
                 'SDE_E_SE_INVALID_QUERYINFO_OBJECT',
                 'SDE_E_SE_QUERYINFO_NOT_PREPARED',
                 'SDE_E_SE_INVALID_RASTILEINFO_OBJECT',
                 'SDE_E_SE_INVALID_RASCONSTRAINT_OBJECT',
                 'SDE_E_SE_INVALID_METADATA_RECORD_ID',
                 'SDE_E_SE_INVALID_METADATA_OBJECT',
                 'SDE_E_SE_INVALID_METADATA_OBJECT_TYPE',
                 'SDE_E_SE_SDEMETADATA_NOT_FOUND',
                 'SDE_E_SE_METADATA_RECORD_NOEXIST',
                 'SDE_E_SE_GEOMETRYCOL_NOEXIST',
                 'SDE_E_SE_INVALID_FILE_PATH',
                 'SDE_E_SE_INVALID_LOCATOR_OBJECT_TYPE',
                 'SDE_E_SE_INVALID_LOCATOR',
                 'SDE_E_SE_TABLE_HAS_NO_LOCATOR',
                 'SDE_E_SE_INVALID_LOCATOR_CATEGORY',
                 'SDE_E_SE_INVALID_LOCATOR_NAME',
                 'SDE_E_SE_LOCATOR_NOEXIST',
                 'SDE_E_SE_LOCATOR_EXISTS',
                 'SDE_E_SE_INVALID_LOCATOR_TYPE',
                 'SDE_E_SE_NO_COORDREF',
                 'SDE_E_SE_CANT_TRIM_RECONCILED_STATE',
                 'SDE_E_SE_FILE_OBJECT_NOEXIST',
                 'SDE_E_SE_FILE_OBJECT_EXISTS',
                 'SDE_E_SE_INVALID_FILEINFO_OBJECT',
                 'SDE_E_SE_INVALID_FILEINFO_OBJECT_TYPE',
                 'SDE_E_SE_RASTERBAND_NO_STATS',
                 'SDE_E_SE_VERSION_HAS_CHILDREN',
                 'SDE_E_SE_SQLTYPE_UNSUPPORTED_ETYPE',
                 'SDE_E_SE_NO_DBTUNE_FILE',
                 'SDE_E_SE_LOG_SYSTABLES_CREATE_FAILED',
                 'SDE_E_SE_OBJECT_RESTRICTED',
                 'SDE_E_SE_INVALID_GEOGTRAN_OBJECT',
                 'SDE_E_SE_COLUMN_EXISTS',
                 'SDE_E_SE_SQL_KEYWORD',
                 'SDE_E_SE_INVALID_OBJECTLOCKINFO_OBJECT',
                 'SDE_E_SE_RASTERBUFFER_TOO_SMALL',
                 'SDE_E_SE_INVALID_RASTER_DATA',
                 'SDE_E_SE_OPERATION_NOT_ALLOWED',
                 'SDE_E_SE_INVALID_RASTERATTR_OBJECT',
                 'SDE_E_SE_INVALID_VERSION_ID',
                 'SDE_E_SE_MVTABLE_CANT_BE_LOAD_ONLY',
                 'SDE_E_SE_INVALID_SDO_GEOM_METADATA_OBJ',
                 'SDE_E_SE_ROW_OUT_OF_SEQUENCE',
                 'SDE_E_SE_INSTANCE_IS_READ_ONLY',
                 'SDE_E_SE_MOSAIC_NOT_ALLOWED',
                 'SDE_E_SE_INVALID_RASTER_BITMAP',
                 'SDE_E_SE_SEQUENCENBR_NOEXIST',
                 'SDE_E_SE_SQLTYPE_INVALID_FEATURE_TYPE',
                 'SDE_E_SE_DBMS_OBJECTS_NOT_SUPPORTED',
                 'SDE_E_SE_BINARY_CONV_NO_COLUMNS_FOUND',
                 'SDE_E_SE_RASTERBAND_NO_COLORMAP',
                 'SDE_E_SE_INVALID_BIN_FUNCTION',
                 'SDE_E_SE_INVALID_RASTERBAND_STATS',
                 'SDE_E_SE_INVALID_RASTERBAND_COLORMAP',
                 'SDE_E_SE_INVALID_RASTER_KEYWORD',
                 'SDE_E_SE_INCOMPATIBLE_INSTANCE',
                 'SDE_E_SE_INVALID_VOLUME_INFO',
                 'SDE_E_SE_INVALID_COMPRESSION_TYPE',
                 'SDE_E_SE_INVALID_INDEX_PARAM',
                 'SDE_E_SE_INVALID_INDEX_TYPE',
                 'SDE_E_SE_SET_VALUE_CONFLICT',
                 'SDE_E_SE_ADT_DATATYPE_NOT_SUPPORTED',
                 'SDE_E_SE_NO_SPATIAL_INDEX',
                 'SDE_E_SE_INVALID_IDENTIFIER',
                 'SDE_E_SE_REGISTERED_TABLE_ROWID_EXIST',
                 'SDE_E_SE_SERVER_LIB_LOAD_ERROR',
                 'SDE_E_SE_REGISTRATION_NOT_ALLOWED',
                 'SDE_E_SE_UNSUPPORTED_ON_MVTABLE',
                 'SDE_E_SE_NO_ARCSDE_LICENSE',
                 'SDE_E_SE_UNSUPPORTED_EXPORT_FILE',
                 'SDE_E_SE_TABLE_INUSE',
                 'SDE_E_SE_INVALID_XMLINDEX_OBJECT',
                 'SDE_E_SE_XML_COLUMN_EXISTS',
                 'SDE_E_SE_XML_TAG_CONFLICT',
                 'SDE_E_SE_XML_INDEX_EXISTS',
                 'SDE_E_SE_XML_INDEX_NOEXIST',
                 'SDE_E_SE_INVALID_XML_INDEX_ALTER',
                 'SDE_E_SE_XML_TEMPLATE_IN_USE',
                 'SDE_E_SE_NOT_XML_INDEX_OWNER',
                 'SDE_E_SE_INVALID_XMLDOC_OBJECT',
                 'SDE_E_SE_XML_TAG_NOEXIST',
                 'SDE_E_SE_XML_PARSE_ERROR',
                 'SDE_E_SE_LAYERS_COLUMN_NOEXISTS',
                 'SDE_E_SE_INVALID_DATE',
                 'SDE_E_SE_XML_COLUMN_NOEXIST',
                 'SDE_E_SE_XML_COLUMN_MISMATCH',
                 'SDE_E_SE_INVALID_XPATH',
                 'SDE_E_SE_XPATH_NOT_SUPPORTED',
                 'SDE_E_SE_INVALID_COLUMNINFO_OBJECT',
                 'SDE_E_SE_INVALID_XMLTAG_OBJECT',
                 'SDE_E_SE_INVALID_XMLINDEX_TYPE',
                 'SDE_E_SE_INSTANCEDB_UNSUPPORTED_OPERATION',
                 'SDE_E_SE_XPATH_INVALID_LOCATION_ALIAS',
                 'SDE_E_SE_XPATH_PREDICATE_INVALID_TOKEN',
                 'SDE_E_SE_XPATH_PREDICATE_INVALID_OPERATOR',
                 'SDE_E_SE_XPATH_PREDICATE_INVALID_CONTAIN_SYNTAX',
                 'SDE_E_SE_XPATH_EMPTY_ELEMENT',
                 'SDE_E_SE_XPATH_INVALID_TOKEN',
                 'SDE_E_SE_SDETMP_NOT_SET',
                 'SDE_E_SE_INVALID_SERVERINFO_OBJECT',
                 'SDE_E_SE_USER_GROUP_CONFLICT',
                 'SDE_E_SE_GCDRULE_FILE_EXISTS',
                 'SDE_E_SE_GCDRULE_FILE_NOT_FOUND',
                 'SDE_E_SE_GCDRULE_NOT_FOUND',
                 'SDE_E_SE_GCDRULE_EXISTS',
                 'SDE_E_SE_INVALID_XMLCOLUMN_OBJECT',
                 'SDE_E_SE_INVALID_GROUP',
                 'SDE_E_SE_INVALID_XML_COLUMN',
                 'SDE_E_SE_INVALID_LOCATOR_PROPERTY',
                 'SDE_E_SE_LOCATOR_PROPERTY_MULTIPLE',
                 'SDE_E_SE_DB_SRCH_OUTGEOD_EXTENT',
                 'SDE_E_SE_XML_COLUMN_NOT_INDEXED',
                 'SDE_E_SE_NO_SDE_UUID_COLUMN',
                 'SDE_E_SE_INVALID_UUID_COLUMN',
                 'SDE_E_SE_64BIT_LAYER_NOT_SUPPORTED',
                 'SDE_E_SE_INVALID_INDEX_MASK',
                 'SDE_E_SE_INVALID_PRECISION',
                 'SDE_E_SE_INVALID_TRANSFORMINFO_OBJECT',
                 'SDE_E_SE_INVALID_RASTERBAND_XFORM_LIST',
                 'SDE_E_SE_RASTERBAND_NO_XFORM_LIST',
                 'SDE_E_SE_INVALID_QUERYCOLUMN_OBJECT',
                 'SDE_E_SE_MULTIPLE_SHAPESOURCE_SHAPES',
                 'SDE_E_SE_INVALID_QUERYSELECT_OBJECT',
                 'SDE_E_SE_INVALID_SHAPESOURCE_OBJECT',
                 'SDE_E_SE_INVALID_SPATIALCONSTRAINT_OBJECT',
                 'SDE_E_SE_MISSING_JOIN_CONSTRAINT',
                 'SDE_E_SE_ANSI_JOIN_CONFLICT',
                 'SDE_E_SE_MISSING_JOIN_TABLE',
                 'SDE_E_SE_INVALID_QUERYTABLE_OBJECT',
                 'SDE_E_SE_INVALID_QUERYFROM_OBJECT',
                 'SDE_E_SE_INVALID_XMLCONSTRAINT_OBJECT',
                 'SDE_E_SE_INVALID_ATTRIBUTECONSTRAINT_OBJECT',
                 'SDE_E_SE_INVALID_QUERYWHERE_OBJECT',
                 'SDE_E_SE_CPG_OPEN_ERROR',
                 'SDE_E_SE_CPG_CONVERSION_OVERFLOW',
                 'SDE_E_SE_CPG_CONVERSION_ERROR',
                 'SDE_E_SE_STATE_CLOSED',
                 'SDE_E_SE_INVALID_ON_BASE_STATE',
                 'SDE_E_SE_DC_LICENSE_SERVER_NOT_REGISTERED',
                 'SDE_E_SE_INVALID_ID_RANGE',
                 'SDE_E_SE_STATEOBJECT_HAS_NO_LINEAGE',
                 'SDE_E_SE_OGCWKB_UNSUPPORTED_EYTPE',
                 'SDE_E_SE_SET_ORIGIN_NOT_ALLOWED',
                 'SDE_E_SE_INVALID_IMAGE_ORIGIN',
                 'SDE_E_SE_RASTERBAND_NO_GDB_METADATA',
                 'SDE_E_SE_INVALID_RASTERBAND_GDB_METADATA',
                 'SDE_E_SE_COMPLEX_COL_INDX_NOT_ALLOWED',
                 'SDE_E_SE_COMPRESS_ALREADY_RUNNING',
                 'SDE_E_SE_SCHEMA_OUT_OF_DATE',
                 'SDE_E_SE_MVTABLE_HAS_DELTA_ROWS',
                 'SDE_E_SE_LOST_DBMS_CONNECTION',
                 'SDE_E_SE_INT32_OVERFLOW',
                 'SDE_E_SE_INVALID_DBTUNEPARAM_OBJECT',
                 'SDE_E_SE_INVALID_DBTUNEKEYWORD_OBJECT',
                 'SDE_E_SE_TABLE_ARCHIVING',
                 'SDE_E_SE_TABLE_NOT_ARCHIVING',
                 'SDE_E_SE_INVALID_XMLCOLUMN_ALTER',
                 'SDE_E_SE_INVALID_INSTANCEINFO_OBJECT',
                 'SDE_E_SE_SCHEMA_EXISTS',
                 'SDE_E_SE_SCHEMA_NO_CREATE_PERMISSIONS',
                 'SDE_E_SE_LAYER_REGISTERED_OUTSIDE_SCHEMA',
                 'SDE_E_SE_TABLE_REGISTERED_OUTSIDE_SCHEMA',
                 'SDE_E_SE_NOT_IN_USER_TRANS',
                 'SDE_E_SE_INVALID_DATASOURCE',
                 'SDE_E_SE_SCHEMA_NOT_MASTER_INSTANCE',
                 'SDE_E_SE_XML_COLUMN_ALTERINDEX_MODE',
                 'SDE_E_SE_XML_COLUMN_LOAD_MODE',
                 'SDE_E_SE_XML_COLUMN_NORMAL_MODE',
                 'SDE_E_SE_LOAD_ONLY_TABLE',
                 'SDE_E_SE_INVALID_ARCHIVING_REGISTRATION',
                 'SDE_E_SE_INVALID_DBTUNE_DATA',
                 'SDE_E_SE_KEYSET_TABLE_CREATE_FAILED',
                 'SDE_E_SE_KEYSET_TABLE_REMOVE_FAILED',
                 'SDE_E_SE_INVALID_HISTORY_OPERATION',
                 'SDE_E_SE_ST_GEOMETRY_TYPE_NOT_INSTALLED',
                 'SDE_E_SE_INVALID_CONNECTION_PROPERTY',
                 'SDE_E_SE_INVALID_OBJECT',
                 'SDE_E_SE_RASTER_CODEC_ERROR',
                 'SDE_E_SE_INVALID_ARCHIVE_OBJECT',
                 'SDE_E_SE_DBMS_CONSTRAINT_NOEXIST',
                 'SDE_E_SE_DBMS_CONSTRAINT_EXIST',
                 'SDE_E_SE_SDE_WARNING',
                 'SDE_E_SE_ETYPE_CHANGED',
                 'SDE_E_SE_NO_ROWS_DELETED',
                 'SDE_E_SE_TOO_MANY_DISTINCTS',
                 'SDE_E_SE_NULL_VALUE',
                 'SDE_E_SE_NO_ROWS_UPDATED',
                 'SDE_E_SE_NO_CPGCVT',
                 'SDE_E_SE_NO_CPGHOME',
                 'SDE_E_SE_DBMS_DOES_NOT_SUPPORT',
                 'SDE_E_SE_INVALID_FUNCTION_ID',
                 'SDE_E_SE_LAYERS_UPDATE_FAILED',
                 'SDE_E_SE_NO_LOCALIZED_MESSAGE',
                 'SDE_E_SE_SPATIAL_INDEX_NOT_CREATED',
                 'SDE_E_SE_FUNC_UNSUPPORTED_ON_DBMS',
                 'SDE_E_SE_SQL_NOT_CACHED',
                 'SDE_E_SE_OBJECT_NOEXIST',
                 'SDE_E_SE_SDO_VARRAY_LIMIT',
                 'SDE_E_SE_SPATIALREF_NO_CLUSTER_TOL',
                 'SDE_E_SE_NO_COMPRESS_STATUS',
                 'SDE_E_SE_INVALID_LAYERGRID_OBJECT',
                 'SDE_E_SE_QUERY_KEYSET_NOT_SET',
                 'SDE_E_SE_INVALID_RASTER_COL_NAME',
                 'SDE_E_SE_INVALID_KEYSET_OPERATION',
                 'SDE_E_SE_INVALID_GEOM_TYPE',
                 'SDE_E_SE_INVALID_GEOR_METADATA',
                 'SDE_E_SE_PDQ_BIND_MISMATCH',
                 'SDE_E_SE_TABLE_NOT_HISTORY',
                 'SDE_E_SE_DEPENDENT_OBJECTS_EXIST',
                 'SDE_E_SE_INSTANCE_RELEASE_INCOMPATIBLE',
                 'SDE_E_SE_INVALID_REVOKE_SELECT',
                 'SDE_E_SE_INSTANCE_OLD_DCDRIVER',
                 'SDE_E_SE_INSTANCE_OLD_DBRELEASE']
    SDE_E_SE_FAILURE = -2147155967
    SDE_E_SE_INVALID_LAYERINFO_OBJECT = -2147155966
    SDE_E_SE_NO_ANNOTATION = -2147155965
    SDE_E_SE_FINISHED = -2147155964
    SDE_E_SE_SDE_NOT_STARTED = -2147155963
    SDE_E_SE_UNCHANGED = -2147155962
    SDE_E_SE_TASKS_EXCEEDED = -2147155961
    SDE_E_SE_CONNECTIONS_EXCEEDED = -2147155961
    SDE_E_SE_LOGIN_NOT_ALLOWED = -2147155960
    SDE_E_SE_INVALID_USER = -2147155959
    SDE_E_SE_NET_FAILURE = -2147155958
    SDE_E_SE_NET_TIMEOUT = -2147155957
    SDE_E_SE_OUT_OF_SVMEM = -2147155956
    SDE_E_SE_OUT_OF_CLMEM = -2147155955
    SDE_E_SE_OUT_OF_CONTEXT = -2147155954
    SDE_E_SE_NO_ACCESS = -2147155953
    SDE_E_SE_TOO_MANY_LAYERS = -2147155952
    SDE_E_SE_NO_LAYER_SPECIFIED = -2147155951
    SDE_E_SE_LAYER_LOCKED = -2147155950
    SDE_E_SE_LAYER_EXISTS = -2147155949
    SDE_E_SE_LAYER_NOEXIST = -2147155948
    SDE_E_SE_LAYER_INUSE = -2147155947
    SDE_E_SE_FID_NOEXIST = -2147155946
    SDE_E_SE_ROW_NOEXIST = -2147155946
    SDE_E_SE_FID_EXISTS = -2147155945
    SDE_E_SE_ROW_EXISTS = -2147155945
    SDE_E_SE_LAYER_MISMATCH = -2147155944
    SDE_E_SE_NO_PERMISSIONS = -2147155943
    SDE_E_SE_INVALID_NOT_NULL = -2147155941
    SDE_E_SE_INVALID_SHAPE = -2147155940
    SDE_E_SE_INVALID_LAYER_NUMBER = -2147155940
    SDE_E_SE_INVALID_ENTITY_TYPE = -2147155939
    SDE_E_SE_INVALID_SEARCH_METHOD = -2147155938
    SDE_E_SE_INVALID_ETYPE_MASK = -2147155937
    SDE_E_SE_BIND_CONFLICT = -2147155936
    SDE_E_SE_INVALID_GRIDSIZE = -2147155935
    SDE_E_SE_INVALID_LOCK_MODE = -2147155934
    SDE_E_SE_ETYPE_NOT_ALLOWED = -2147155933
    SDE_E_SE_TOO_MANY_POINTS = -2147155932
    SDE_E_SE_INVALID_NUM_OF_PTS = -2147155932
    SDE_E_SE_TABLE_NOEXIST = -2147155931
    SDE_E_SE_ATTR_NOEXIST = -2147155930
    SDE_E_SE_LICENSE_FAILURE = -2147155929
    SDE_E_SE_OUT_OF_LICENSES = -2147155928
    SDE_E_SE_INVALID_COLUMN_VALUE = -2147155927
    SDE_E_SE_INVALID_WHERE = -2147155926
    SDE_E_SE_INVALID_SQL = -2147155926
    SDE_E_SE_LOG_NOEXIST = -2147155925
    SDE_E_SE_LOG_NOACCESS = -2147155924
    SDE_E_SE_LOG_NOTOPEN = -2147155923
    SDE_E_SE_LOG_IO_ERROR = -2147155922
    SDE_E_SE_NO_SHAPES = -2147155921
    SDE_E_SE_NO_LOCKS = -2147155920
    SDE_E_SE_LOCK_CONFLICT = -2147155919
    SDE_E_SE_OUT_OF_LOCKS = -2147155918
    SDE_E_SE_DB_IO_ERROR = -2147155917
    SDE_E_SE_STREAM_IN_PROGRESS = -2147155916
    SDE_E_SE_INVALID_COLUMN_TYPE = -2147155915
    SDE_E_SE_TOPO_ERROR = -2147155914
    SDE_E_SE_ATTR_CONV_ERROR = -2147155913
    SDE_E_SE_INVALID_COLUMN_DEF = -2147155912
    SDE_E_SE_INVALID_SHAPE_BUF_SIZE = -2147155911
    SDE_E_SE_INVALID_ENVELOPE = -2147155910
    SDE_E_SE_TEMP_IO_ERROR = -2147155909
    SDE_E_SE_GSIZE_TOO_SMALL = -2147155908
    SDE_E_SE_LICENSE_EXPIRED = -2147155907
    SDE_E_SE_TABLE_EXISTS = -2147155906
    SDE_E_SE_INDEX_EXISTS = -2147155905
    SDE_E_SE_INDEX_NOEXIST = -2147155904
    SDE_E_SE_INVALID_POINTER = -2147155903
    SDE_E_SE_INVALID_PARAM_VALUE = -2147155902
    SDE_E_SE_ALL_SLIVERS = -2147155901
    SDE_E_SE_TRANS_IN_PROGRESS = -2147155900
    SDE_E_SE_IOMGR_NO_DBMS_CONNECT = -2147155899
    SDE_E_SE_DUPLICATE_ARC = -2147155898
    SDE_E_SE_INVALID_ANNO_OBJECT = -2147155897
    SDE_E_SE_PT_NO_EXIST = -2147155896
    SDE_E_SE_PTS_NOT_ADJACENT = -2147155895
    SDE_E_SE_INVALID_MID_PT = -2147155894
    SDE_E_SE_INVALID_END_PT = -2147155893
    SDE_E_SE_INVALID_RADIUS = -2147155892
    SDE_E_SE_LOAD_ONLY_LAYER = -2147155891
    SDE_E_SE_LAYERS_NOT_FOUND = -2147155890
    SDE_E_SE_FILE_IO_ERROR = -2147155889
    SDE_E_SE_BLOB_SIZE_TOO_LARGE = -2147155888
    SDE_E_SE_CORRIDOR_OUT_OF_BOUNDS = -2147155887
    SDE_E_SE_SHAPE_INTEGRITY_ERROR = -2147155886
    SDE_E_SE_NOT_IMPLEMENTED_YET = -2147155885
    SDE_E_SE_CAD_EXISTS = -2147155884
    SDE_E_SE_INVALID_TRANSID = -2147155883
    SDE_E_SE_INVALID_LAYER_NAME = -2147155882
    SDE_E_SE_INVALID_LAYER_KEYWORD = -2147155881
    SDE_E_SE_INVALID_RELEASE = -2147155880
    SDE_E_SE_VERSION_TBL_EXISTS = -2147155879
    SDE_E_SE_COLUMN_NOT_BOUND = -2147155878
    SDE_E_SE_INVALID_INDICATOR_VALUE = -2147155877
    SDE_E_SE_INVALID_CONNECTION = -2147155876
    SDE_E_SE_INVALID_DBA_PASSWORD = -2147155875
    SDE_E_SE_PATH_NOT_FOUND = -2147155874
    SDE_E_SE_SDEHOME_NOT_SET = -2147155873
    SDE_E_SE_NOT_TABLE_OWNER = -2147155872
    SDE_E_SE_PROCESS_NOT_FOUND = -2147155871
    SDE_E_SE_INVALID_DBMS_LOGIN = -2147155870
    SDE_E_SE_PASSWORD_TIMEOUT = -2147155869
    SDE_E_SE_INVALID_SERVER = -2147155868
    SDE_E_SE_IOMGR_NOT_AVAILABLE = -2147155867
    SDE_E_SE_SERVICE_NOT_FOUND = -2147155866
    SDE_E_SE_INVALID_STATS_TYPE = -2147155865
    SDE_E_SE_INVALID_DISTINCT_TYPE = -2147155864
    SDE_E_SE_INVALID_GRANT_REVOKE = -2147155863
    SDE_E_SE_INVALID_SDEHOME = -2147155862
    SDE_E_SE_INVALID_STREAM = -2147155861
    SDE_E_SE_TOO_MANY_STREAMS = -2147155860
    SDE_E_SE_OUT_OF_MUTEXES = -2147155859
    SDE_E_SE_CONNECTION_LOCKED = -2147155858
    SDE_E_SE_CONNECTION_IN_USE = -2147155857
    SDE_E_SE_NOT_A_SELECT_STATEMENT = -2147155856
    SDE_E_SE_FUNCTION_SEQUENCE_ERROR = -2147155855
    SDE_E_SE_WRONG_COLUMN_TYPE = -2147155854
    SDE_E_SE_PTABLE_LOCKED = -2147155853
    SDE_E_SE_PTABLE_IN_USE = -2147155852
    SDE_E_SE_STABLE_LOCKED = -2147155851
    SDE_E_SE_STABLE_IN_USE = -2147155850
    SDE_E_SE_INVALID_FILTER_TYPE = -2147155849
    SDE_E_SE_NO_CAD = -2147155848
    SDE_E_SE_INSTANCE_NOT_AVAILABLE = -2147155847
    SDE_E_SE_INSTANCE_TOO_EARLY = -2147155846
    SDE_E_SE_INVALID_SYSTEM_UNITS = -2147155845
    SDE_E_SE_INVALID_UNITS = -2147155844
    SDE_E_SE_INVALID_CAD_OBJECT = -2147155843
    SDE_E_SE_VERSION_NOEXIST = -2147155842
    SDE_E_SE_INVALID_SPATIAL_CONSTRAINT = -2147155841
    SDE_E_SE_INVALID_STREAM_TYPE = -2147155840
    SDE_E_SE_INVALID_SPATIAL_COLUMN = -2147155839
    SDE_E_SE_NO_SPATIAL_MASKS = -2147155838
    SDE_E_SE_IOMGR_NOT_FOUND = -2147155837
    SDE_E_SE_SYSTEM_IS_CLIENT_ONLY = -2147155836
    SDE_E_SE_MULTIPLE_SPATIAL_COLS = -2147155835
    SDE_E_SE_INVALID_SHAPE_OBJECT = -2147155834
    SDE_E_SE_INVALID_PARTNUM = -2147155833
    SDE_E_SE_INCOMPATIBLE_SHAPES = -2147155832
    SDE_E_SE_INVALID_PART_OFFSET = -2147155831
    SDE_E_SE_INCOMPATIBLE_COORDREFS = -2147155830
    SDE_E_SE_COORD_OUT_OF_BOUNDS = -2147155829
    SDE_E_SE_LAYER_CACHE_FULL = -2147155828
    SDE_E_SE_INVALID_COORDREF_OBJECT = -2147155827
    SDE_E_SE_INVALID_COORDSYS_ID = -2147155826
    SDE_E_SE_INVALID_COORDSYS_DESC = -2147155825
    SDE_E_SE_INVALID_ROW_ID_LAYER = -2147155824
    SDE_E_SE_PROJECTION_ERROR = -2147155823
    SDE_E_SE_ARRAY_BYTES_EXCEEDED = -2147155822
    SDE_E_SE_POLY_SHELLS_OVERLAP = -2147155821
    SDE_E_SE_TOO_FEW_POINTS = -2147155820
    SDE_E_SE_INVALID_PART_SEPARATOR = -2147155819
    SDE_E_SE_INVALID_POLYGON_CLOSURE = -2147155818
    SDE_E_SE_INVALID_OUTER_SHELL = -2147155817
    SDE_E_SE_ZERO_AREA_POLYGON = -2147155816
    SDE_E_SE_POLYGON_HAS_VERTICAL_LINE = -2147155815
    SDE_E_SE_OUTER_SHELLS_OVERLAP = -2147155814
    SDE_E_SE_SELF_INTERSECTING = -2147155813
    SDE_E_SE_INVALID_EXPORT_FILE = -2147155812
    SDE_E_SE_READ_ONLY_SHAPE = -2147155811
    SDE_E_SE_INVALID_DATA_SOURCE = -2147155810
    SDE_E_SE_INVALID_STREAM_SPEC = -2147155809
    SDE_E_SE_INVALID_ALTER_OPERATION = -2147155808
    SDE_E_SE_INVALID_SPATIAL_COL_NAME = -2147155807
    SDE_E_SE_INVALID_DATABASE = -2147155806
    SDE_E_SE_SPATIAL_SQL_NOT_INSTALLED = -2147155805
    SDE_E_SE_NORM_DIM_INFO_NOT_FOUND = -2147155804
    SDE_E_SE_NORM_DIM_TAB_VALUE_NOT_FOUND = -2147155803
    SDE_E_SE_UNSUPPORTED_NORMALIZED_OPERATION = -2147155802
    SDE_E_SE_INVALID_REGISTERED_LAYER_OPTION = -2147155801
    SDE_E_SE_READ_ONLY = -2147155800
    SDE_E_SE_NO_SDE_ROWID_COLUMN = -2147155799
    SDE_E_SE_READ_ONLY_COLUMN = -2147155798
    SDE_E_SE_INVALID_VERSION_NAME = -2147155797
    SDE_E_SE_STATE_NOEXIST = -2147155796
    SDE_E_SE_INVALID_STATEINFO_OBJECT = -2147155795
    SDE_E_SE_VERSION_HAS_MOVED = -2147155794
    SDE_E_SE_STATE_HAS_CHILDREN = -2147155793
    SDE_E_SE_PARENT_NOT_CLOSED = -2147155792
    SDE_E_SE_VERSION_EXISTS = -2147155791
    SDE_E_SE_TABLE_NOT_MULTIVERSION = -2147155790
    SDE_E_SE_STATE_USED_BY_VERSION = -2147155789
    SDE_E_SE_INVALID_VERSIONINFO_OBJECT = -2147155788
    SDE_E_SE_INVALID_STATE_ID = -2147155787
    SDE_E_SE_SDETRACELOC_NOT_SET = -2147155786
    SDE_E_SE_ERROR_LOADING_SSA = -2147155785
    SDE_E_SE_TOO_MANY_STATES = -2147155784
    SDE_E_SE_STATES_ARE_SAME = -2147155783
    SDE_E_SE_NO_ROWID_COLUMN = -2147155782
    SDE_E_SE_NO_STATE_SET = -2147155781
    SDE_E_SE_SSA_FUNCTION_ERROR = -2147155780
    SDE_E_SE_INVALID_REGINFO_OBJECT = -2147155779
    SDE_E_SE_NO_COMMON_LINEAGE = -2147155778
    SDE_E_SE_STATE_INUSE = -2147155777
    SDE_E_SE_STATE_TREE_INUSE = -2147155776
    SDE_E_SE_INVALID_RASTER_COLUMN = -2147155775
    SDE_E_SE_RASTERCOLUMN_EXISTS = -2147155774
    SDE_E_SE_INVALID_MVTABLE_INDEX = -2147155773
    SDE_E_SE_INVALID_STORAGE_TYPE = -2147155772
    SDE_E_SE_AMBIGUOUS_NIL_SHAPE = -2147155771
    SDE_E_SE_INVALID_BYTE_ORDER = -2147155770
    SDE_E_SE_INVALID_GEOMETRY_TYPE = -2147155769
    SDE_E_SE_INVALID_NUM_MEASURES = -2147155768
    SDE_E_SE_INVALID_NUM_PARTS = -2147155767
    SDE_E_SE_BINARY_TOO_SMALL = -2147155766
    SDE_E_SE_SHAPE_TEXT_TOO_LONG = -2147155765
    SDE_E_SE_SHAPE_TEXT_ERROR = -2147155764
    SDE_E_SE_TOO_MANY_PARTS = -2147155763
    SDE_E_SE_TYPE_MISMATCH = -2147155762
    SDE_E_SE_SQL_PARENTHESIS_MISMATCH = -2147155761
    SDE_E_SE_NIL_SHAPE_NOT_ALLOWED = -2147155760
    SDE_E_SE_INSTANCE_ALREADY_RUNNING = -2147155759
    SDE_E_SE_UNSUPPORTED_OPERATION = -2147155758
    SDE_E_SE_INVALID_EXTERNAL_LAYER_OPTION = -2147155757
    SDE_E_SE_NORMALIZE_VALUE_NOT_FOUND = -2147155756
    SDE_E_SE_INVALID_QUERY_TYPE = -2147155755
    SDE_E_SE_NO_TRACE_LIBRARY = -2147155754
    SDE_E_SE_TRACE_ON = -2147155753
    SDE_E_SE_TRACE_OFF = -2147155752
    SDE_E_SE_SCL_SYNTAX_ERROR = -2147155751
    SDE_E_SE_TABLE_REGISTERED = -2147155750
    SDE_E_SE_INVALID_REGISTRATION_ID = -2147155749
    SDE_E_SE_TABLE_NOREGISTERED = -2147155748
    SDE_E_SE_TOO_MANY_REGISTRATIONS = -2147155747
    SDE_E_SE_DELETE_NOT_ALLOWED = -2147155746
    SDE_E_SE_ROWLOCKING_ENABLED = -2147155745
    SDE_E_SE_ROWLOCKING_NOT_ENABLED = -2147155744
    SDE_E_SE_RASTERCOLUMN_INUSE = -2147155743
    SDE_E_SE_RASTERCOLUMN_NOEXIST = -2147155742
    SDE_E_SE_INVALID_RASTERCOLUMN_NUMBER = -2147155741
    SDE_E_SE_TOO_MANY_RASTERCOLUMNS = -2147155740
    SDE_E_SE_INVALID_RASTER_NUMBER = -2147155739
    SDE_E_SE_NO_REQUEST_STATUS = -2147155738
    SDE_E_SE_NO_REQUEST_RESULTS = -2147155737
    SDE_E_SE_RASTERBAND_EXISTS = -2147155736
    SDE_E_SE_RASTERBAND_NOEXIST = -2147155735
    SDE_E_SE_RASTER_EXISTS = -2147155734
    SDE_E_SE_RASTER_NOEXIST = -2147155733
    SDE_E_SE_TOO_MANY_RASTERBANDS = -2147155732
    SDE_E_SE_TOO_MANY_RASTERS = -2147155731
    SDE_E_SE_VIEW_EXISTS = -2147155730
    SDE_E_SE_VIEW_NOEXIST = -2147155729
    SDE_E_SE_LOCK_EXISTS = -2147155728
    SDE_E_SE_ROWLOCK_MASK_CONFLICT = -2147155727
    SDE_E_SE_NOT_IN_RASTER = -2147155726
    SDE_E_SE_INVALID_RASBANDINFO_OBJECT = -2147155725
    SDE_E_SE_INVALID_RASCOLINFO_OBJECT = -2147155724
    SDE_E_SE_INVALID_RASTERINFO_OBJECT = -2147155723
    SDE_E_SE_INVALID_RASTERBAND_NUMBER = -2147155722
    SDE_E_SE_MULTIPLE_RASTER_COLS = -2147155721
    SDE_E_SE_TABLE_SCHEMA_IS_LOCKED = -2147155720
    SDE_E_SE_INVALID_LOGINFO_OBJECT = -2147155719
    SDE_E_SE_SQL_TOO_LONG = -2147155718
    SDE_E_SE_UNSUPPORTED_ON_VIEW = -2147155717
    SDE_E_SE_LOG_EXISTS = -2147155716
    SDE_E_SE_LOG_IS_OPEN = -2147155715
    SDE_E_SE_SPATIALREF_EXISTS = -2147155714
    SDE_E_SE_SPATIALREF_NOEXIST = -2147155713
    SDE_E_SE_SPATIALREF_IN_USE = -2147155712
    SDE_E_SE_INVALID_SPATIALREFINFO_OBJECT = -2147155711
    SDE_E_SE_SEQUENCENBR_EXISTS = -2147155710
    SDE_E_SE_INVALID_QUERYINFO_OBJECT = -2147155709
    SDE_E_SE_QUERYINFO_NOT_PREPARED = -2147155708
    SDE_E_SE_INVALID_RASTILEINFO_OBJECT = -2147155707
    SDE_E_SE_INVALID_RASCONSTRAINT_OBJECT = -2147155706
    SDE_E_SE_INVALID_METADATA_RECORD_ID = -2147155705
    SDE_E_SE_INVALID_METADATA_OBJECT = -2147155704
    SDE_E_SE_INVALID_METADATA_OBJECT_TYPE = -2147155703
    SDE_E_SE_SDEMETADATA_NOT_FOUND = -2147155702
    SDE_E_SE_METADATA_RECORD_NOEXIST = -2147155701
    SDE_E_SE_GEOMETRYCOL_NOEXIST = -2147155700
    SDE_E_SE_INVALID_FILE_PATH = -2147155699
    SDE_E_SE_INVALID_LOCATOR_OBJECT_TYPE = -2147155698
    SDE_E_SE_INVALID_LOCATOR = -2147155697
    SDE_E_SE_TABLE_HAS_NO_LOCATOR = -2147155696
    SDE_E_SE_INVALID_LOCATOR_CATEGORY = -2147155695
    SDE_E_SE_INVALID_LOCATOR_NAME = -2147155694
    SDE_E_SE_LOCATOR_NOEXIST = -2147155693
    SDE_E_SE_LOCATOR_EXISTS = -2147155692
    SDE_E_SE_INVALID_LOCATOR_TYPE = -2147155691
    SDE_E_SE_NO_COORDREF = -2147155690
    SDE_E_SE_CANT_TRIM_RECONCILED_STATE = -2147155689
    SDE_E_SE_FILE_OBJECT_NOEXIST = -2147155688
    SDE_E_SE_FILE_OBJECT_EXISTS = -2147155687
    SDE_E_SE_INVALID_FILEINFO_OBJECT = -2147155686
    SDE_E_SE_INVALID_FILEINFO_OBJECT_TYPE = -2147155685
    SDE_E_SE_RASTERBAND_NO_STATS = -2147155684
    SDE_E_SE_VERSION_HAS_CHILDREN = -2147155683
    SDE_E_SE_SQLTYPE_UNSUPPORTED_ETYPE = -2147155682
    SDE_E_SE_NO_DBTUNE_FILE = -2147155681
    SDE_E_SE_LOG_SYSTABLES_CREATE_FAILED = -2147155680
    SDE_E_SE_OBJECT_RESTRICTED = -2147155679
    SDE_E_SE_INVALID_GEOGTRAN_OBJECT = -2147155678
    SDE_E_SE_COLUMN_EXISTS = -2147155677
    SDE_E_SE_SQL_KEYWORD = -2147155676
    SDE_E_SE_INVALID_OBJECTLOCKINFO_OBJECT = -2147155675
    SDE_E_SE_RASTERBUFFER_TOO_SMALL = -2147155674
    SDE_E_SE_INVALID_RASTER_DATA = -2147155673
    SDE_E_SE_OPERATION_NOT_ALLOWED = -2147155672
    SDE_E_SE_INVALID_RASTERATTR_OBJECT = -2147155671
    SDE_E_SE_INVALID_VERSION_ID = -2147155670
    SDE_E_SE_MVTABLE_CANT_BE_LOAD_ONLY = -2147155669
    SDE_E_SE_INVALID_SDO_GEOM_METADATA_OBJ = -2147155668
    SDE_E_SE_ROW_OUT_OF_SEQUENCE = -2147155667
    SDE_E_SE_INSTANCE_IS_READ_ONLY = -2147155666
    SDE_E_SE_MOSAIC_NOT_ALLOWED = -2147155665
    SDE_E_SE_INVALID_RASTER_BITMAP = -2147155664
    SDE_E_SE_SEQUENCENBR_NOEXIST = -2147155663
    SDE_E_SE_SQLTYPE_INVALID_FEATURE_TYPE = -2147155662
    SDE_E_SE_DBMS_OBJECTS_NOT_SUPPORTED = -2147155661
    SDE_E_SE_BINARY_CONV_NO_COLUMNS_FOUND = -2147155660
    SDE_E_SE_RASTERBAND_NO_COLORMAP = -2147155659
    SDE_E_SE_INVALID_BIN_FUNCTION = -2147155658
    SDE_E_SE_INVALID_RASTERBAND_STATS = -2147155657
    SDE_E_SE_INVALID_RASTERBAND_COLORMAP = -2147155656
    SDE_E_SE_INVALID_RASTER_KEYWORD = -2147155655
    SDE_E_SE_INCOMPATIBLE_INSTANCE = -2147155654
    SDE_E_SE_INVALID_VOLUME_INFO = -2147155653
    SDE_E_SE_INVALID_COMPRESSION_TYPE = -2147155652
    SDE_E_SE_INVALID_INDEX_PARAM = -2147155651
    SDE_E_SE_INVALID_INDEX_TYPE = -2147155650
    SDE_E_SE_SET_VALUE_CONFLICT = -2147155649
    SDE_E_SE_ADT_DATATYPE_NOT_SUPPORTED = -2147155648
    SDE_E_SE_NO_SPATIAL_INDEX = -2147155647
    SDE_E_SE_INVALID_IDENTIFIER = -2147155646
    SDE_E_SE_REGISTERED_TABLE_ROWID_EXIST = -2147155645
    SDE_E_SE_SERVER_LIB_LOAD_ERROR = -2147155644
    SDE_E_SE_REGISTRATION_NOT_ALLOWED = -2147155643
    SDE_E_SE_UNSUPPORTED_ON_MVTABLE = -2147155642
    SDE_E_SE_NO_ARCSDE_LICENSE = -2147155641
    SDE_E_SE_UNSUPPORTED_EXPORT_FILE = -2147155640
    SDE_E_SE_TABLE_INUSE = -2147155639
    SDE_E_SE_INVALID_XMLINDEX_OBJECT = -2147155638
    SDE_E_SE_XML_COLUMN_EXISTS = -2147155637
    SDE_E_SE_XML_TAG_CONFLICT = -2147155636
    SDE_E_SE_XML_INDEX_EXISTS = -2147155635
    SDE_E_SE_XML_INDEX_NOEXIST = -2147155634
    SDE_E_SE_INVALID_XML_INDEX_ALTER = -2147155633
    SDE_E_SE_XML_TEMPLATE_IN_USE = -2147155632
    SDE_E_SE_NOT_XML_INDEX_OWNER = -2147155631
    SDE_E_SE_INVALID_XMLDOC_OBJECT = -2147155630
    SDE_E_SE_XML_TAG_NOEXIST = -2147155629
    SDE_E_SE_XML_PARSE_ERROR = -2147155628
    SDE_E_SE_LAYERS_COLUMN_NOEXISTS = -2147155627
    SDE_E_SE_INVALID_DATE = -2147155626
    SDE_E_SE_XML_COLUMN_NOEXIST = -2147155625
    SDE_E_SE_XML_COLUMN_MISMATCH = -2147155624
    SDE_E_SE_INVALID_XPATH = -2147155623
    SDE_E_SE_XPATH_NOT_SUPPORTED = -2147155622
    SDE_E_SE_INVALID_COLUMNINFO_OBJECT = -2147155621
    SDE_E_SE_INVALID_XMLTAG_OBJECT = -2147155620
    SDE_E_SE_INVALID_XMLINDEX_TYPE = -2147155619
    SDE_E_SE_INSTANCEDB_UNSUPPORTED_OPERATION = -2147155618
    SDE_E_SE_XPATH_INVALID_LOCATION_ALIAS = -2147155617
    SDE_E_SE_XPATH_PREDICATE_INVALID_TOKEN = -2147155616
    SDE_E_SE_XPATH_PREDICATE_INVALID_OPERATOR = -2147155615
    SDE_E_SE_XPATH_PREDICATE_INVALID_CONTAIN_SYNTAX = -2147155614
    SDE_E_SE_XPATH_EMPTY_ELEMENT = -2147155613
    SDE_E_SE_XPATH_INVALID_TOKEN = -2147155612
    SDE_E_SE_SDETMP_NOT_SET = -2147155611
    SDE_E_SE_INVALID_SERVERINFO_OBJECT = -2147155610
    SDE_E_SE_USER_GROUP_CONFLICT = -2147155609
    SDE_E_SE_GCDRULE_FILE_EXISTS = -2147155608
    SDE_E_SE_GCDRULE_FILE_NOT_FOUND = -2147155607
    SDE_E_SE_GCDRULE_NOT_FOUND = -2147155606
    SDE_E_SE_GCDRULE_EXISTS = -2147155605
    SDE_E_SE_INVALID_XMLCOLUMN_OBJECT = -2147155604
    SDE_E_SE_INVALID_GROUP = -2147155603
    SDE_E_SE_INVALID_XML_COLUMN = -2147155602
    SDE_E_SE_INVALID_LOCATOR_PROPERTY = -2147155601
    SDE_E_SE_LOCATOR_PROPERTY_MULTIPLE = -2147155600
    SDE_E_SE_DB_SRCH_OUTGEOD_EXTENT = -2147155599
    SDE_E_SE_XML_COLUMN_NOT_INDEXED = -2147155598
    SDE_E_SE_NO_SDE_UUID_COLUMN = -2147155597
    SDE_E_SE_INVALID_UUID_COLUMN = -2147155596
    SDE_E_SE_64BIT_LAYER_NOT_SUPPORTED = -2147155595
    SDE_E_SE_INVALID_INDEX_MASK = -2147155594
    SDE_E_SE_INVALID_PRECISION = -2147155593
    SDE_E_SE_INVALID_TRANSFORMINFO_OBJECT = -2147155592
    SDE_E_SE_INVALID_RASTERBAND_XFORM_LIST = -2147155591
    SDE_E_SE_RASTERBAND_NO_XFORM_LIST = -2147155590
    SDE_E_SE_INVALID_QUERYCOLUMN_OBJECT = -2147155589
    SDE_E_SE_MULTIPLE_SHAPESOURCE_SHAPES = -2147155588
    SDE_E_SE_INVALID_QUERYSELECT_OBJECT = -2147155587
    SDE_E_SE_INVALID_SHAPESOURCE_OBJECT = -2147155586
    SDE_E_SE_INVALID_SPATIALCONSTRAINT_OBJECT = -2147155585
    SDE_E_SE_MISSING_JOIN_CONSTRAINT = -2147155584
    SDE_E_SE_ANSI_JOIN_CONFLICT = -2147155583
    SDE_E_SE_MISSING_JOIN_TABLE = -2147155582
    SDE_E_SE_INVALID_QUERYTABLE_OBJECT = -2147155581
    SDE_E_SE_INVALID_QUERYFROM_OBJECT = -2147155580
    SDE_E_SE_INVALID_XMLCONSTRAINT_OBJECT = -2147155579
    SDE_E_SE_INVALID_ATTRIBUTECONSTRAINT_OBJECT = -2147155578
    SDE_E_SE_INVALID_QUERYWHERE_OBJECT = -2147155577
    SDE_E_SE_CPG_OPEN_ERROR = -2147155576
    SDE_E_SE_CPG_CONVERSION_OVERFLOW = -2147155575
    SDE_E_SE_CPG_CONVERSION_ERROR = -2147155574
    SDE_E_SE_STATE_CLOSED = -2147155573
    SDE_E_SE_INVALID_ON_BASE_STATE = -2147155572
    SDE_E_SE_DC_LICENSE_SERVER_NOT_REGISTERED = -2147155571
    SDE_E_SE_INVALID_ID_RANGE = -2147155570
    SDE_E_SE_STATEOBJECT_HAS_NO_LINEAGE = -2147155569
    SDE_E_SE_OGCWKB_UNSUPPORTED_EYTPE = -2147155568
    SDE_E_SE_SET_ORIGIN_NOT_ALLOWED = -2147155567
    SDE_E_SE_INVALID_IMAGE_ORIGIN = -2147155566
    SDE_E_SE_RASTERBAND_NO_GDB_METADATA = -2147155565
    SDE_E_SE_INVALID_RASTERBAND_GDB_METADATA = -2147155564
    SDE_E_SE_COMPLEX_COL_INDX_NOT_ALLOWED = -2147155563
    SDE_E_SE_COMPRESS_ALREADY_RUNNING = -2147155562
    SDE_E_SE_SCHEMA_OUT_OF_DATE = -2147155561
    SDE_E_SE_MVTABLE_HAS_DELTA_ROWS = -2147155560
    SDE_E_SE_LOST_DBMS_CONNECTION = -2147155559
    SDE_E_SE_INT32_OVERFLOW = -2147155558
    SDE_E_SE_INVALID_DBTUNEPARAM_OBJECT = -2147155557
    SDE_E_SE_INVALID_DBTUNEKEYWORD_OBJECT = -2147155556
    SDE_E_SE_TABLE_ARCHIVING = -2147155555
    SDE_E_SE_TABLE_NOT_ARCHIVING = -2147155554
    SDE_E_SE_INVALID_XMLCOLUMN_ALTER = -2147155553
    SDE_E_SE_INVALID_INSTANCEINFO_OBJECT = -2147155552
    SDE_E_SE_SCHEMA_EXISTS = -2147155551
    SDE_E_SE_SCHEMA_NO_CREATE_PERMISSIONS = -2147155550
    SDE_E_SE_LAYER_REGISTERED_OUTSIDE_SCHEMA = -2147155549
    SDE_E_SE_TABLE_REGISTERED_OUTSIDE_SCHEMA = -2147155548
    SDE_E_SE_NOT_IN_USER_TRANS = -2147155547
    SDE_E_SE_INVALID_DATASOURCE = -2147155546
    SDE_E_SE_SCHEMA_NOT_MASTER_INSTANCE = -2147155545
    SDE_E_SE_XML_COLUMN_ALTERINDEX_MODE = -2147155544
    SDE_E_SE_XML_COLUMN_LOAD_MODE = -2147155543
    SDE_E_SE_XML_COLUMN_NORMAL_MODE = -2147155542
    SDE_E_SE_LOAD_ONLY_TABLE = -2147155541
    SDE_E_SE_INVALID_ARCHIVING_REGISTRATION = -2147155540
    SDE_E_SE_INVALID_DBTUNE_DATA = -2147155539
    SDE_E_SE_KEYSET_TABLE_CREATE_FAILED = -2147155538
    SDE_E_SE_KEYSET_TABLE_REMOVE_FAILED = -2147155537
    SDE_E_SE_INVALID_HISTORY_OPERATION = -2147155536
    SDE_E_SE_ST_GEOMETRY_TYPE_NOT_INSTALLED = -2147155535
    SDE_E_SE_INVALID_CONNECTION_PROPERTY = -2147155534
    SDE_E_SE_INVALID_OBJECT = -2147155533
    SDE_E_SE_RASTER_CODEC_ERROR = -2147155532
    SDE_E_SE_INVALID_ARCHIVE_OBJECT = -2147155531
    SDE_E_SE_DBMS_CONSTRAINT_NOEXIST = -2147155530
    SDE_E_SE_DBMS_CONSTRAINT_EXIST = -2147155529
    SDE_E_SE_SDE_WARNING = -2147154968
    SDE_E_SE_ETYPE_CHANGED = -2147154967
    SDE_E_SE_NO_ROWS_DELETED = -2147154966
    SDE_E_SE_TOO_MANY_DISTINCTS = -2147154965
    SDE_E_SE_NULL_VALUE = -2147154964
    SDE_E_SE_NO_ROWS_UPDATED = -2147154963
    SDE_E_SE_NO_CPGCVT = -2147154962
    SDE_E_SE_NO_CPGHOME = -2147154961
    SDE_E_SE_DBMS_DOES_NOT_SUPPORT = -2147154960
    SDE_E_SE_INVALID_FUNCTION_ID = -2147154959
    SDE_E_SE_LAYERS_UPDATE_FAILED = -2147154958
    SDE_E_SE_NO_LOCALIZED_MESSAGE = -2147154957
    SDE_E_SE_SPATIAL_INDEX_NOT_CREATED = -2147154956
    SDE_E_SE_FUNC_UNSUPPORTED_ON_DBMS = -2147154955
    SDE_E_SE_SQL_NOT_CACHED = -2147154954
    SDE_E_SE_OBJECT_NOEXIST = -2147154953
    SDE_E_SE_SDO_VARRAY_LIMIT = -2147154952
    SDE_E_SE_SPATIALREF_NO_CLUSTER_TOL = -2147154951
    SDE_E_SE_NO_COMPRESS_STATUS = -2147154950
    SDE_E_SE_INVALID_LAYERGRID_OBJECT = -2147155528
    SDE_E_SE_QUERY_KEYSET_NOT_SET = -2147155526
    SDE_E_SE_INVALID_RASTER_COL_NAME = -2147155525
    SDE_E_SE_INVALID_KEYSET_OPERATION = -2147155524
    SDE_E_SE_INVALID_GEOM_TYPE = -2147155523
    SDE_E_SE_INVALID_GEOR_METADATA = -2147155522
    SDE_E_SE_PDQ_BIND_MISMATCH = -2147155521
    SDE_E_SE_TABLE_NOT_HISTORY = -2147155520
    SDE_E_SE_DEPENDENT_OBJECTS_EXIST = -2147155519
    SDE_E_SE_INSTANCE_RELEASE_INCOMPATIBLE = -2147155518
    SDE_E_SE_INVALID_REVOKE_SELECT = -2147155527
    SDE_E_SE_INSTANCE_OLD_DCDRIVER = -2147155502
    SDE_E_SE_INSTANCE_OLD_DBRELEASE = -2147155503

class esriDataServerStatusType(Enumeration):
    __slots__ = ['esriServerUnknown',
                 'esriServerStopped',
                 'esriServerStartPending',
                 'esriServerStopPending',
                 'esriServerRunning',
                 'esriServerContinuePending',
                 'esriServerPausePending',
                 'esriServerPaused']
    esriServerUnknown = 0
    esriServerStopped = 1
    esriServerStartPending = 2
    esriServerStopPending = 3
    esriServerRunning = 4
    esriServerContinuePending = 5
    esriServerPausePending = 6
    esriServerPaused = 7

class esriDataServerType(Enumeration):
    __slots__ = ['esriDSOracle8i',
                 'esriDSOracle9i',
                 'esirDSOracle10g',
                 'esriDSMsSqlServer',
                 'esriDSInformix',
                 'esriDSDB2',
                 'esriDSPostgreSQL']
    esriDSOracle8i = 1
    esriDSOracle9i = 2
    esirDSOracle10g = 3
    esriDSMsSqlServer = 4
    esriDSInformix = 5
    esriDSDB2 = 6
    esriDSPostgreSQL = 7

class esriGeodatabasePermissionsType(Enumeration):
    __slots__ = ['esriPermNone',
                 'esriPermReadData',
                 'esriPermWriteData',
                 'esriPermAdmin']
    esriPermNone = 0
    esriPermReadData = 1
    esriPermWriteData = 2
    esriPermAdmin = 3

