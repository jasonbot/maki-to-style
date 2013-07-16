'Type library'
__all__ = ['IServerObject', 'IServerObjectFactory', 'IServerObjectHelper', 'IServerObjectHelper2', 'IServerObjectExtension', 'IServerObjectExtensionManager', 'IServerContext', 'IServerDirectory', 'IEnumServerDirectory', 'IServerObjectConfiguration', 'IEnumServerObjectConfiguration', 'IServerObjectConfigurationStatus', 'IServerObjectType', 'IEnumServerObjectType', 'IServerMachine', 'IEnumServerMachine', 'IServerObjectAdmin', 'IConfigurationFactory', 'IServerLogQuery', 'IServerLog', 'IServerObjectConfigurationInfo', 'IEnumServerObjectConfigurationInfo', 'IServerObjectTypeInfo', 'IEnumServerObjectTypeInfo', 'IServerDirectoryInfo', 'IEnumServerDirectoryInfo', 'IServerObjectManager', 'IServerObjectExtensionTypeInfo', 'IEnumServerObjectExtensionTypeInfo', 'IServerObjectManager2', 'IServerObjectManager3', 'IServiceDescription', 'IServiceDescriptionArray', 'IServiceCatalog', 'IServiceCatalog2', 'IServerObjectManager4', 'IServerObjectExtensionType', 'IEnumServerObjectExtensionType', 'IServerObjectAdmin2', 'IServerObjectAdmin3', 'IServerObjectAdmin4', 'IServerObjectAdmin5', 'IServerObjectAdmin6', 'IServerObjectAdmin7', 'ISOMController', 'IServerObjectType2', 'IServerObjectType3', 'IServerObjectType4', 'IServerObjectTypeInfo2', 'IServerObjectTypeInfo3', 'IServerObjectExtensionType2', 'IServerObjectExtensionTypeInfo2', 'IServerObjectConfiguration2', 'IServerObjectConfiguration3', 'IServerObjectConfiguration4', 'IServerObjectConfiguration5', 'IServerObjectConfigurationInfo2', 'IServerDirectory2', 'IServerDirectory3', 'IServerDirectoryInfo2', 'IServerMachine2', 'IServerMachine3', 'IServerMachineStatus', 'IServerMachineInfo', 'IServerStatistics', 'IServerStatus', 'IServerErrorReports', 'IPermissionsAdmin', 'IPermissionsAdmin2', 'IPermissionsManager', 'IServerCLRHost', 'IServerObjectExtensionType3', 'IServerMachineEnvironment', 'IServerObjectAdmin8', 'IServerLog2', 'IServerTimeRange', 'IServerObjectConfigurationManager', 'IServerObjectConfigurationManager2', 'IConfigurationFactory2', 'IConfigurationFactory3', 'IServerEnvironmentEx', 'IServerConfigurationStorage', 'IServerJobManager', 'IServerEnvironmentImpl', 'IServerEnvironmentImpl2', 'IServer', 'IServer2', 'IServerInit', 'IServerInit2', 'IGISServerConnection', 'IGISServerConnection2', 'IServiceDescription2', 'IServiceDescription3', 'IServiceCatalog3', 'IServiceCatalogAdmin', 'IServiceCatalogAdmin2', 'IServiceCatalogAdmin3', 'IIdentity', 'IServerInfo', 'IServerInfos', 'IGISServer', 'IGISServers', 'IManagerWebService', 'IWPISilentConfig', 'IServerObjectFactoryX', 'IServerEnvironmentXHelper', 'IGPServerHelper', 'IUser', 'IRole', 'IUserStore', 'IDataStoreValidator', 'IRoleStore', 'IServerHelper', 'IResponseStreamer', 'ServerObjectFactory', 'ConfigFactory', 'ServerObjectManager', 'ServerObjectAdmin', 'ServerObjectConfiguration', 'ServerLogImpl', 'ServerDirectory', 'ServerMachine', 'ServerObject', 'ServerContext', 'ServerObjectTypeInfo', 'ServerObjectExtensionTypeInfo', 'ServerObjectConfigurationInfo', 'ServerObjectConfigurationStatus', 'ServerObjectType', 'ServerObjectExtensionType', 'ServerDirectoryInfo', 'ServerStatisticsArray', 'ServerStatisticsResults', 'ServerMachineStatus', 'SOMController', 'Server', 'ServerP', 'GISServerConnection', 'ServiceCatalog', 'ServerObjectFactoryX', 'ServerEnvironmentXHelper', 'GPServerHelper', 'Role', 'User', 'ResponseStreamer', 'IID_IServerObject', 'IID_IServerObjectFactory', 'IID_IServerObjectHelper', 'IID_IServerObjectHelper2', 'IID_IServerObjectExtension', 'IID_IServerObjectExtensionManager', 'IID_IServerContext', 'IID_IServerDirectory', 'IID_IEnumServerDirectory', 'IID_IServerObjectConfiguration', 'IID_IEnumServerObjectConfiguration', 'IID_IServerObjectConfigurationStatus', 'IID_IServerObjectType', 'IID_IEnumServerObjectType', 'IID_IServerMachine', 'IID_IEnumServerMachine', 'IID_IServerObjectAdmin', 'IID_IConfigurationFactory', 'IID_IServerLogQuery', 'IID_IServerLog', 'IID_IServerObjectConfigurationInfo', 'IID_IEnumServerObjectConfigurationInfo', 'IID_IServerObjectTypeInfo', 'IID_IEnumServerObjectTypeInfo', 'IID_IServerDirectoryInfo', 'IID_IEnumServerDirectoryInfo', 'IID_IServerObjectManager', 'IID_IServerObjectExtensionTypeInfo', 'IID_IEnumServerObjectExtensionTypeInfo', 'IID_IServerObjectManager2', 'IID_IServerObjectManager3', 'IID_IServiceDescription', 'IID_IServiceDescriptionArray', 'IID_IServiceCatalog', 'IID_IServiceCatalog2', 'IID_IServerObjectManager4', 'IID_IServerObjectExtensionType', 'IID_IEnumServerObjectExtensionType', 'IID_IServerObjectAdmin2', 'IID_IServerObjectAdmin3', 'IID_IServerObjectAdmin4', 'IID_IServerObjectAdmin5', 'IID_IServerObjectAdmin6', 'IID_IServerObjectAdmin7', 'IID_ISOMController', 'IID_IServerObjectType2', 'IID_IServerObjectType3', 'IID_IServerObjectType4', 'IID_IServerObjectTypeInfo2', 'IID_IServerObjectTypeInfo3', 'IID_IServerObjectExtensionType2', 'IID_IServerObjectExtensionTypeInfo2', 'IID_IServerObjectConfiguration2', 'IID_IServerObjectConfiguration3', 'IID_IServerObjectConfiguration4', 'IID_IServerObjectConfiguration5', 'IID_IServerObjectConfigurationInfo2', 'IID_IServerDirectory2', 'IID_IServerDirectory3', 'IID_IServerDirectoryInfo2', 'IID_IServerMachine2', 'IID_IServerMachine3', 'IID_IServerMachineStatus', 'IID_IServerMachineInfo', 'IID_IServerStatistics', 'IID_IServerStatus', 'IID_IServerErrorReports', 'IID_IPermissionsAdmin', 'IID_IPermissionsAdmin2', 'IID_IPermissionsManager', 'IID_IServerCLRHost', 'IID_IServerObjectExtensionType3', 'IID_IServerMachineEnvironment', 'IID_IServerObjectAdmin8', 'IID_IServerLog2', 'IID_IServerTimeRange', 'IID_IServerObjectConfigurationManager', 'IID_IServerObjectConfigurationManager2', 'IID_IConfigurationFactory2', 'IID_IConfigurationFactory3', 'IID_IServerEnvironmentEx', 'IID_IServerConfigurationStorage', 'IID_IServerJobManager', 'IID_IServerEnvironmentImpl', 'IID_IServerEnvironmentImpl2', 'IID_IServer', 'IID_IServer2', 'IID_IServerInit', 'IID_IServerInit2', 'IID_IGISServerConnection', 'IID_IGISServerConnection2', 'IID_IServiceDescription2', 'IID_IServiceDescription3', 'IID_IServiceCatalog3', 'IID_IServiceCatalogAdmin', 'IID_IServiceCatalogAdmin2', 'IID_IServiceCatalogAdmin3', 'IID_IIdentity', 'IID_IServerInfo', 'IID_IServerInfos', 'IID_IGISServer', 'IID_IGISServers', 'IID_IManagerWebService', 'IID_IWPISilentConfig', 'IID_IServerObjectFactoryX', 'IID_IServerEnvironmentXHelper', 'IID_IGPServerHelper', 'IID_IUser', 'IID_IRole', 'IID_IUserStore', 'IID_IDataStoreValidator', 'IID_IRoleStore', 'IID_IServerHelper', 'IID_IResponseStreamer', 'CLSID_ServerObjectFactory', 'CLSID_ConfigFactory', 'CLSID_ServerObjectManager', 'CLSID_ServerObjectAdmin', 'CLSID_ServerObjectConfiguration', 'CLSID_ServerLogImpl', 'CLSID_ServerDirectory', 'CLSID_ServerMachine', 'CLSID_ServerObject', 'CLSID_ServerContext', 'CLSID_ServerObjectTypeInfo', 'CLSID_ServerObjectExtensionTypeInfo', 'CLSID_ServerObjectConfigurationInfo', 'CLSID_ServerObjectConfigurationStatus', 'CLSID_ServerObjectType', 'CLSID_ServerObjectExtensionType', 'CLSID_ServerDirectoryInfo', 'CLSID_ServerStatisticsArray', 'CLSID_ServerStatisticsResults', 'CLSID_ServerMachineStatus', 'CLSID_SOMController', 'CLSID_Server', 'CLSID_ServerP', 'CLSID_GISServerConnection', 'CLSID_ServiceCatalog', 'CLSID_ServerObjectFactoryX', 'CLSID_ServerEnvironmentXHelper', 'CLSID_GPServerHelper', 'CLSID_Role', 'CLSID_User', 'CLSID_ResponseStreamer', 'esriServerDirectoryCleaningMode', 'esriServerIsolationLevel', 'esriStartupType', 'esriConfigurationStatus', 'esriServiceCatalogMessageFormat', 'esriLoadBalancing', 'esriServerDirectoryType', 'esriAccessLevel', 'esriServerStatEvent', 'esriServerStatFunction', 'esriServerTimePeriod', 'esriServerExceptionHandlingMode', 'esriMachineStatus', 'esriServerConnectionType', 'esriServerInstallType']
from cartocomutils import _esriServer
from cartocomutils._esriServer import ServerObjectFactory, ConfigFactory, ServerObjectManager, ServerObjectAdmin, ServerObjectConfiguration, ServerLogImpl, ServerDirectory, ServerMachine, ServerObject, ServerContext, ServerObjectTypeInfo, ServerObjectExtensionTypeInfo, ServerObjectConfigurationInfo, ServerObjectConfigurationStatus, ServerObjectType, ServerObjectExtensionType, ServerDirectoryInfo, ServerStatisticsArray, ServerStatisticsResults, ServerMachineStatus, SOMController, Server, ServerP, GISServerConnection, ServiceCatalog, ServerObjectFactoryX, ServerEnvironmentXHelper, GPServerHelper, Role, User, ResponseStreamer
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IServerObject(_esriServer.IServerObject):
    _IID = uuid.UUID('0ad6ab40-9d6a-4bf8-8b86-eb89406dfc6c')
    def get_ConfigurationName(self):
        '''Method IServerObject.get_ConfigurationName

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObject, self).get_ConfigurationName()
    def get_TypeName(self):
        '''Method IServerObject.get_TypeName

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObject, self).get_TypeName()
    ConfigurationName = property(get_ConfigurationName, None, None)
    TypeName = property(get_TypeName, None, None)

class IServerObjectFactory(_esriServer.IServerObjectFactory):
    _IID = uuid.UUID('1fc365cc-e2e8-4f83-afc9-834b33148e29')
    def CreateServerObject(self, CLSID, cfgName, cfgType):
        '''Method IServerObjectFactory.CreateServerObject

           INPUTS
            CLSID               : BSTR
            cfgName             : BSTR
            cfgType             : BSTR

           OUTPUT
            ppSO                : IServerObject**'''
        return super(IServerObjectFactory, self).CreateServerObject(CLSID, cfgName, cfgType)

class IServerObjectHelper(_esriServer.IServerObjectHelper):
    _IID = uuid.UUID('f241e441-cc73-40e2-baf0-b30ebe0ef8dc')
    def get_ServerObject(self):
        '''Method IServerObjectHelper.get_ServerObject

           OUTPUT
            ppSO                : IServerObject**'''
        return super(IServerObjectHelper, self).get_ServerObject()
    ServerObject = property(get_ServerObject, None, None)

class IServerObjectHelper2(_esriServer.IServerObjectHelper2):
    _IID = uuid.UUID('6ee30361-f7c6-4635-882e-fabc7a772bc4')
    def get_ServerObjectProperty(self):
        '''Method IServerObjectHelper2.get_ServerObjectProperty

           OUTPUT
            ppProps             : IPropertySet**'''
        return super(IServerObjectHelper2, self).get_ServerObjectProperty()
    def get_ServerObject(self):
        '''Method IServerObjectHelper.get_ServerObject (from IServerObjectHelper)

           OUTPUT
            ppSO                : IServerObject**'''
        return super(IServerObjectHelper2, self).get_ServerObject()
    ServerObject = property(get_ServerObject, None, None)
    ServerObjectProperty = property(get_ServerObjectProperty, None, None)

class IServerObjectExtension(_esriServer.IServerObjectExtension):
    _IID = uuid.UUID('de9a3831-3861-43da-a35f-2e82900db74e')
    def Init(self, pSOH):
        '''Method IServerObjectExtension.Init

           INPUT
            pSOH                : IServerObjectHelper*'''
        return super(IServerObjectExtension, self).Init(pSOH)
    def Shutdown(self):
        '''Method IServerObjectExtension.Shutdown'''
        return super(IServerObjectExtension, self).Shutdown()

class IServerObjectExtensionManager(_esriServer.IServerObjectExtensionManager):
    _IID = uuid.UUID('25d8b9dd-c7e8-4da4-bf4b-08a67087ceea')
    def FindExtensionByCLSID(self, CLSID):
        '''Method IServerObjectExtensionManager.FindExtensionByCLSID

           INPUT
            CLSID               : BSTR

           OUTPUT
            ppSOE               : IServerObjectExtension**'''
        return super(IServerObjectExtensionManager, self).FindExtensionByCLSID(CLSID)
    def FindExtensionByTypeName(self, Name):
        '''Method IServerObjectExtensionManager.FindExtensionByTypeName

           INPUT
            Name                : BSTR

           OUTPUT
            ppSOE               : IServerObjectExtension**'''
        return super(IServerObjectExtensionManager, self).FindExtensionByTypeName(Name)

class IServerContext(_esriServer.IServerContext):
    _IID = uuid.UUID('a87fdd99-6112-410c-b75e-fefff5eace35')
    def get_ServerObject(self):
        '''Method IServerContext.get_ServerObject

           OUTPUT
            obj                 : IServerObject**'''
        return super(IServerContext, self).get_ServerObject()
    def CreateObject(self, CLSID):
        '''Method IServerContext.CreateObject

           INPUT
            CLSID               : BSTR

           OUTPUT
            ppObj               : IUnknown**'''
        return super(IServerContext, self).CreateObject(CLSID)
    def LoadObject(self, str):
        '''Method IServerContext.LoadObject

           INPUT
            str                 : BSTR

           OUTPUT
            obj                 : IUnknown**'''
        return super(IServerContext, self).LoadObject(str)
    def SaveObject(self, obj):
        '''Method IServerContext.SaveObject

           INPUT
            obj                 : IUnknown*

           OUTPUT
            str                 : BSTR*'''
        return super(IServerContext, self).SaveObject(obj)
    def GetObject(self, Name):
        '''Method IServerContext.GetObject

           INPUT
            Name                : BSTR

           OUTPUT
            obj                 : IUnknown**'''
        return super(IServerContext, self).GetObject(Name)
    def SetObject(self, Name, obj):
        '''Method IServerContext.SetObject

           INPUTS
            Name                : BSTR
            obj                 : IUnknown*'''
        return super(IServerContext, self).SetObject(Name, obj)
    def Remove(self, Name):
        '''Method IServerContext.Remove

           INPUT
            Name                : BSTR'''
        return super(IServerContext, self).Remove(Name)
    def RemoveAll(self):
        '''Method IServerContext.RemoveAll'''
        return super(IServerContext, self).RemoveAll()
    def ReleaseContext(self):
        '''Method IServerContext.ReleaseContext'''
        return super(IServerContext, self).ReleaseContext()
    ServerObject = property(get_ServerObject, None, None)

class IServerDirectory(_esriServer.IServerDirectory):
    _IID = uuid.UUID('e7402a4c-0962-4e2e-ba8f-e90b6dabfcb2')

    def __init__(self, *args, **kw):
        super(IServerDirectory, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Path(self):
        '''Method IServerDirectory.get_Path

           OUTPUT
            pPath               : BSTR*'''
        return super(IServerDirectory, self).get_Path()
    def put_Path(self, pPath):
        '''Method IServerDirectory.put_Path

           INPUT
            pPath               : BSTR'''
        return super(IServerDirectory, self).put_Path(pPath)
    def get_URL(self):
        '''Method IServerDirectory.get_URL

           OUTPUT
            pUrl                : BSTR*'''
        return super(IServerDirectory, self).get_URL()
    def put_URL(self, pUrl):
        '''Method IServerDirectory.put_URL

           INPUT
            pUrl                : BSTR'''
        return super(IServerDirectory, self).put_URL(pUrl)
    def get_Description(self):
        '''Method IServerDirectory.get_Description

           OUTPUT
            pText               : BSTR*'''
        return super(IServerDirectory, self).get_Description()
    def put_Description(self, pText):
        '''Method IServerDirectory.put_Description

           INPUT
            pText               : BSTR'''
        return super(IServerDirectory, self).put_Description(pText)
    def get_CleaningMode(self):
        '''Method IServerDirectory.get_CleaningMode

           OUTPUT
            pMode               : esriServerDirectoryCleaningMode*'''
        return super(IServerDirectory, self).get_CleaningMode()
    def put_CleaningMode(self, pMode):
        '''Method IServerDirectory.put_CleaningMode

           INPUT
            pMode               : esriServerDirectoryCleaningMode'''
        return super(IServerDirectory, self).put_CleaningMode(pMode)
    def get_MaxFileAge(self):
        '''Method IServerDirectory.get_MaxFileAge

           OUTPUT
            pAge                : long*'''
        return super(IServerDirectory, self).get_MaxFileAge()
    def put_MaxFileAge(self, pAge):
        '''Method IServerDirectory.put_MaxFileAge

           INPUT
            pAge                : long'''
        return super(IServerDirectory, self).put_MaxFileAge(pAge)
    CleaningMode = property(get_CleaningMode, put_CleaningMode, None)
    Description = property(get_Description, put_Description, None)
    MaxFileAge = property(get_MaxFileAge, put_MaxFileAge, None)
    Path = property(get_Path, put_Path, None)
    URL = property(get_URL, put_URL, None)

class IEnumServerDirectory(_esriServer.IEnumServerDirectory):
    _IID = uuid.UUID('4250c367-25dc-426c-ae90-817a8e892db5')
    def Next(self):
        '''Method IEnumServerDirectory.Next

           OUTPUT
            Next                : IServerDirectory**'''
        return super(IEnumServerDirectory, self).Next()
    def __iter__(self):
        try:
            super(IEnumServerDirectory, self).Reset()
            val = super(IEnumServerDirectory, self).Next()
            while val:
                yield val
                val = super(IEnumServerDirectory, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumServerDirectory.Reset'''
        return super(IEnumServerDirectory, self).Reset()
    def get_Count(self):
        '''Method IEnumServerDirectory.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IEnumServerDirectory, self).get_Count()
    Count = property(get_Count, None, None)

class IServerObjectConfiguration(_esriServer.IServerObjectConfiguration):
    _IID = uuid.UUID('832dab4c-a03d-429e-8c14-401e3f807284')

    def __init__(self, *args, **kw):
        super(IServerObjectConfiguration, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IServerObjectConfiguration.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectConfiguration, self).get_Name()
    def put_Name(self, Name):
        '''Method IServerObjectConfiguration.put_Name

           INPUT
            Name                : BSTR'''
        return super(IServerObjectConfiguration, self).put_Name(Name)
    def get_TypeName(self):
        '''Method IServerObjectConfiguration.get_TypeName

           OUTPUT
            TypeName            : BSTR*'''
        return super(IServerObjectConfiguration, self).get_TypeName()
    def put_TypeName(self, TypeName):
        '''Method IServerObjectConfiguration.put_TypeName

           INPUT
            TypeName            : BSTR'''
        return super(IServerObjectConfiguration, self).put_TypeName(TypeName)
    def get_Description(self):
        '''Method IServerObjectConfiguration.get_Description

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectConfiguration, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectConfiguration.put_Description

           INPUT
            desc                : BSTR'''
        return super(IServerObjectConfiguration, self).put_Description(desc)
    def get_Properties(self):
        '''Method IServerObjectConfiguration.get_Properties

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration, self).get_Properties()
    def putref_Properties(self, props):
        '''Method IServerObjectConfiguration.putref_Properties

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration, self).putref_Properties(props)
    def get_RecycleProperties(self):
        '''Method IServerObjectConfiguration.get_RecycleProperties

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration, self).get_RecycleProperties()
    def putref_RecycleProperties(self, props):
        '''Method IServerObjectConfiguration.putref_RecycleProperties

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration, self).putref_RecycleProperties(props)
    def get_MinInstances(self):
        '''Method IServerObjectConfiguration.get_MinInstances

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration, self).get_MinInstances()
    def put_MinInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MinInstances

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration, self).put_MinInstances(instances)
    def get_MaxInstances(self):
        '''Method IServerObjectConfiguration.get_MaxInstances

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration, self).get_MaxInstances()
    def put_MaxInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MaxInstances

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration, self).put_MaxInstances(instances)
    def get_IsPooled(self):
        '''Method IServerObjectConfiguration.get_IsPooled

           OUTPUT
            IsPooled            : VARIANT_BOOL*'''
        return super(IServerObjectConfiguration, self).get_IsPooled()
    def put_IsPooled(self, IsPooled):
        '''Method IServerObjectConfiguration.put_IsPooled

           INPUT
            IsPooled            : VARIANT_BOOL'''
        return super(IServerObjectConfiguration, self).put_IsPooled(IsPooled)
    def get_IsolationLevel(self):
        '''Method IServerObjectConfiguration.get_IsolationLevel

           OUTPUT
            isoLevel            : esriServerIsolationLevel*'''
        return super(IServerObjectConfiguration, self).get_IsolationLevel()
    def put_IsolationLevel(self, isoLevel):
        '''Method IServerObjectConfiguration.put_IsolationLevel

           INPUT
            isoLevel            : esriServerIsolationLevel'''
        return super(IServerObjectConfiguration, self).put_IsolationLevel(isoLevel)
    def get_StartupType(self):
        '''Method IServerObjectConfiguration.get_StartupType

           OUTPUT
            Type                : esriStartupType*'''
        return super(IServerObjectConfiguration, self).get_StartupType()
    def put_StartupType(self, Type):
        '''Method IServerObjectConfiguration.put_StartupType

           INPUT
            Type                : esriStartupType'''
        return super(IServerObjectConfiguration, self).put_StartupType(Type)
    def get_WaitTimeout(self):
        '''Method IServerObjectConfiguration.get_WaitTimeout

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration, self).get_WaitTimeout()
    def put_WaitTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_WaitTimeout

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration, self).put_WaitTimeout(pVal)
    def get_UsageTimeout(self):
        '''Method IServerObjectConfiguration.get_UsageTimeout

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration, self).get_UsageTimeout()
    def put_UsageTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_UsageTimeout

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration, self).put_UsageTimeout(pVal)
    Description = property(get_Description, put_Description, None)
    IsPooled = property(get_IsPooled, put_IsPooled, None)
    IsolationLevel = property(get_IsolationLevel, put_IsolationLevel, None)
    MaxInstances = property(get_MaxInstances, put_MaxInstances, None)
    MinInstances = property(get_MinInstances, put_MinInstances, None)
    Name = property(get_Name, put_Name, None)
    Properties = property(get_Properties, putref_Properties, None)
    RecycleProperties = property(get_RecycleProperties, putref_RecycleProperties, None)
    StartupType = property(get_StartupType, put_StartupType, None)
    TypeName = property(get_TypeName, put_TypeName, None)
    UsageTimeout = property(get_UsageTimeout, put_UsageTimeout, None)
    WaitTimeout = property(get_WaitTimeout, put_WaitTimeout, None)

class IEnumServerObjectConfiguration(_esriServer.IEnumServerObjectConfiguration):
    _IID = uuid.UUID('815fed35-ec76-432c-9fb0-9ead763d2f50')
    def Next(self):
        '''Method IEnumServerObjectConfiguration.Next

           OUTPUT
            nextConfig          : IServerObjectConfiguration**'''
        return super(IEnumServerObjectConfiguration, self).Next()
    def __iter__(self):
        try:
            super(IEnumServerObjectConfiguration, self).Reset()
            val = super(IEnumServerObjectConfiguration, self).Next()
            while val:
                yield val
                val = super(IEnumServerObjectConfiguration, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumServerObjectConfiguration.Reset'''
        return super(IEnumServerObjectConfiguration, self).Reset()
    def get_Count(self):
        '''Method IEnumServerObjectConfiguration.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IEnumServerObjectConfiguration, self).get_Count()
    Count = property(get_Count, None, None)

class IServerObjectConfigurationStatus(_esriServer.IServerObjectConfigurationStatus):
    _IID = uuid.UUID('096b178f-2576-4aef-9cfa-8107d529bbff')
    def get_InstanceCount(self):
        '''Method IServerObjectConfigurationStatus.get_InstanceCount

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfigurationStatus, self).get_InstanceCount()
    def get_InstanceInUseCount(self):
        '''Method IServerObjectConfigurationStatus.get_InstanceInUseCount

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfigurationStatus, self).get_InstanceInUseCount()
    def get_Status(self):
        '''Method IServerObjectConfigurationStatus.get_Status

           OUTPUT
            pStatus             : esriConfigurationStatus*'''
        return super(IServerObjectConfigurationStatus, self).get_Status()
    InstanceCount = property(get_InstanceCount, None, None)
    InstanceInUseCount = property(get_InstanceInUseCount, None, None)
    Status = property(get_Status, None, None)

class IServerObjectType(_esriServer.IServerObjectType):
    _IID = uuid.UUID('9ad7beca-fbc3-494a-bec6-790ff0e6946e')

    def __init__(self, *args, **kw):
        super(IServerObjectType, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IServerObjectType.get_Name

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServerObjectType.put_Name

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType, self).put_Name(pVal)
    def get_Description(self):
        '''Method IServerObjectType.get_Description

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectType, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectType.put_Description

           INPUT
            desc                : BSTR'''
        return super(IServerObjectType, self).put_Description(desc)
    def get_CLSID(self):
        '''Method IServerObjectType.get_CLSID

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType, self).get_CLSID()
    def put_CLSID(self, pVal):
        '''Method IServerObjectType.put_CLSID

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType, self).put_CLSID(pVal)
    CLSID = property(get_CLSID, put_CLSID, None)
    Description = property(get_Description, put_Description, None)
    Name = property(get_Name, put_Name, None)

class IEnumServerObjectType(_esriServer.IEnumServerObjectType):
    _IID = uuid.UUID('e7fe5eab-11ec-49aa-80f4-34aa200913b0')
    def Next(self):
        '''Method IEnumServerObjectType.Next

           OUTPUT
            nextType            : IServerObjectType**'''
        return super(IEnumServerObjectType, self).Next()
    def __iter__(self):
        try:
            super(IEnumServerObjectType, self).Reset()
            val = super(IEnumServerObjectType, self).Next()
            while val:
                yield val
                val = super(IEnumServerObjectType, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumServerObjectType.Reset'''
        return super(IEnumServerObjectType, self).Reset()
    def get_Count(self):
        '''Method IEnumServerObjectType.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IEnumServerObjectType, self).get_Count()
    Count = property(get_Count, None, None)

class IServerMachine(_esriServer.IServerMachine):
    _IID = uuid.UUID('2dbbd5d1-193f-4cb0-893f-98dfffdadf1f')

    def __init__(self, *args, **kw):
        super(IServerMachine, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IServerMachine.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IServerMachine, self).get_Name()
    def put_Name(self, Name):
        '''Method IServerMachine.put_Name

           INPUT
            Name                : BSTR'''
        return super(IServerMachine, self).put_Name(Name)
    def get_Description(self):
        '''Method IServerMachine.get_Description

           OUTPUT
            desc                : BSTR*'''
        return super(IServerMachine, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerMachine.put_Description

           INPUT
            desc                : BSTR'''
        return super(IServerMachine, self).put_Description(desc)
    Description = property(get_Description, put_Description, None)
    Name = property(get_Name, put_Name, None)

class IEnumServerMachine(_esriServer.IEnumServerMachine):
    _IID = uuid.UUID('0f89530a-8ba4-4ab6-9b4a-78541ee88525')
    def Next(self):
        '''Method IEnumServerMachine.Next

           OUTPUT
            nextMachine         : IServerMachine**'''
        return super(IEnumServerMachine, self).Next()
    def __iter__(self):
        try:
            super(IEnumServerMachine, self).Reset()
            val = super(IEnumServerMachine, self).Next()
            while val:
                yield val
                val = super(IEnumServerMachine, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumServerMachine.Reset'''
        return super(IEnumServerMachine, self).Reset()
    def get_Count(self):
        '''Method IEnumServerMachine.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IEnumServerMachine, self).get_Count()
    Count = property(get_Count, None, None)

class IServerObjectAdmin(_esriServer.IServerObjectAdmin):
    _IID = uuid.UUID('01f6db39-6458-4c12-bcc7-30f1021075e2')

    def __init__(self, *args, **kw):
        super(IServerObjectAdmin, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def CreateServerDirectory(self):
        '''Method IServerObjectAdmin.CreateServerDirectory

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin, self).CreateServerDirectory()
    def AddServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.AddServerDirectory

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin, self).AddServerDirectory(pSD)
    def UpdateServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.UpdateServerDirectory

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin, self).UpdateServerDirectory(pSD)
    def DeleteServerDirectory(self, Path):
        '''Method IServerObjectAdmin.DeleteServerDirectory

           INPUT
            Path                : BSTR'''
        return super(IServerObjectAdmin, self).DeleteServerDirectory(Path)
    def GetServerDirectory(self, Path):
        '''Method IServerObjectAdmin.GetServerDirectory

           INPUT
            Path                : BSTR

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin, self).GetServerDirectory(Path)
    def GetServerDirectories(self):
        '''Method IServerObjectAdmin.GetServerDirectories

           OUTPUT
            ppEnum              : IEnumServerDirectory**'''
        return super(IServerObjectAdmin, self).GetServerDirectories()
    def CreateConfiguration(self):
        '''Method IServerObjectAdmin.CreateConfiguration

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin, self).CreateConfiguration()
    def AddConfiguration(self, config):
        '''Method IServerObjectAdmin.AddConfiguration

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin, self).AddConfiguration(config)
    def GetConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfiguration

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin, self).GetConfiguration(Name, TypeName)
    def UpdateConfiguration(self, config):
        '''Method IServerObjectAdmin.UpdateConfiguration

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin, self).UpdateConfiguration(config)
    def DeleteConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.DeleteConfiguration

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin, self).DeleteConfiguration(Name, TypeName)
    def GetConfigurations(self):
        '''Method IServerObjectAdmin.GetConfigurations

           OUTPUT
            ppConfigs           : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin, self).GetConfigurations()
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfigurationStatus

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectAdmin, self).GetConfigurationStatus(Name, TypeName)
    def GetTypes(self):
        '''Method IServerObjectAdmin.GetTypes

           OUTPUT
            ppTypes             : IEnumServerObjectType**'''
        return super(IServerObjectAdmin, self).GetTypes()
    def StartConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StartConfiguration

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin, self).StartConfiguration(Name, TypeName)
    def StopConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StopConfiguration

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin, self).StopConfiguration(Name, TypeName)
    def PauseConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.PauseConfiguration

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin, self).PauseConfiguration(Name, TypeName)
    def CreateMachine(self):
        '''Method IServerObjectAdmin.CreateMachine

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin, self).CreateMachine()
    def AddMachine(self, Machine):
        '''Method IServerObjectAdmin.AddMachine

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin, self).AddMachine(Machine)
    def GetMachines(self):
        '''Method IServerObjectAdmin.GetMachines

           OUTPUT
            machines            : IEnumServerMachine**'''
        return super(IServerObjectAdmin, self).GetMachines()
    def DeleteMachine(self, MachineName):
        '''Method IServerObjectAdmin.DeleteMachine

           INPUT
            MachineName         : BSTR'''
        return super(IServerObjectAdmin, self).DeleteMachine(MachineName)
    def GetMachine(self, Name):
        '''Method IServerObjectAdmin.GetMachine

           INPUT
            Name                : BSTR

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin, self).GetMachine(Name)
    def UpdateMachine(self, Machine):
        '''Method IServerObjectAdmin.UpdateMachine

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin, self).UpdateMachine(Machine)
    def get_Properties(self):
        '''Method IServerObjectAdmin.get_Properties

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectAdmin, self).get_Properties()
    def put_Properties(self, props):
        '''Method IServerObjectAdmin.put_Properties

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectAdmin, self).put_Properties(props)
    Properties = property(get_Properties, put_Properties, None)

class IConfigurationFactory(_esriServer.IConfigurationFactory):
    _IID = uuid.UUID('94e42963-1a3b-4413-847e-afa37ee24a5a')
    def OnAdd(self, pAdmin, pProps):
        '''Method IConfigurationFactory.OnAdd

           INPUTS
            pAdmin              : IServerObjectAdmin*
            pProps              : IPropertySet*

           OUTPUT
            ppNewProps          : IPropertySet**'''
        return super(IConfigurationFactory, self).OnAdd(pAdmin, pProps)
    def OnRemove(self):
        '''Method IConfigurationFactory.OnRemove'''
        return super(IConfigurationFactory, self).OnRemove()
    def OnStart(self, pAdmin, props):
        '''Method IConfigurationFactory.OnStart

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory, self).OnStart(pAdmin, props)
    def OnStop(self, pAdmin, props):
        '''Method IConfigurationFactory.OnStop

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory, self).OnStop(pAdmin, props)

class IServerLogQuery(_esriServer.IServerLogQuery):
    _IID = uuid.UUID('97d02ac6-aabb-4030-85f1-7280f28785de')

    def __init__(self, *args, **kw):
        super(IServerLogQuery, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_StartTime(self):
        '''Method IServerLogQuery.get_StartTime

           OUTPUT
            pTime               : DATE*'''
        return super(IServerLogQuery, self).get_StartTime()
    def put_StartTime(self, pTime):
        '''Method IServerLogQuery.put_StartTime

           INPUT
            pTime               : DATE'''
        return super(IServerLogQuery, self).put_StartTime(pTime)
    def get_EndTime(self):
        '''Method IServerLogQuery.get_EndTime

           OUTPUT
            pTime               : DATE*'''
        return super(IServerLogQuery, self).get_EndTime()
    def put_EndTime(self, pTime):
        '''Method IServerLogQuery.put_EndTime

           INPUT
            pTime               : DATE'''
        return super(IServerLogQuery, self).put_EndTime(pTime)
    def get_Target(self):
        '''Method IServerLogQuery.get_Target

           OUTPUT
            pName               : BSTR*'''
        return super(IServerLogQuery, self).get_Target()
    def put_Target(self, pName):
        '''Method IServerLogQuery.put_Target

           INPUT
            pName               : BSTR'''
        return super(IServerLogQuery, self).put_Target(pName)
    def get_Machine(self):
        '''Method IServerLogQuery.get_Machine

           OUTPUT
            pMachine            : BSTR*'''
        return super(IServerLogQuery, self).get_Machine()
    def put_Machine(self, pMachine):
        '''Method IServerLogQuery.put_Machine

           INPUT
            pMachine            : BSTR'''
        return super(IServerLogQuery, self).put_Machine(pMachine)
    def get_Level(self):
        '''Method IServerLogQuery.get_Level

           OUTPUT
            pLevel              : long*'''
        return super(IServerLogQuery, self).get_Level()
    def put_Level(self, pLevel):
        '''Method IServerLogQuery.put_Level

           INPUT
            pLevel              : long'''
        return super(IServerLogQuery, self).put_Level(pLevel)
    def get_MaxRecords(self):
        '''Method IServerLogQuery.get_MaxRecords

           OUTPUT
            pVal                : long*'''
        return super(IServerLogQuery, self).get_MaxRecords()
    def put_MaxRecords(self, pVal):
        '''Method IServerLogQuery.put_MaxRecords

           INPUT
            pVal                : long'''
        return super(IServerLogQuery, self).put_MaxRecords(pVal)
    def get_StartIndex(self):
        '''Method IServerLogQuery.get_StartIndex

           OUTPUT
            pVal                : long*'''
        return super(IServerLogQuery, self).get_StartIndex()
    def put_StartIndex(self, pVal):
        '''Method IServerLogQuery.put_StartIndex

           INPUT
            pVal                : long'''
        return super(IServerLogQuery, self).put_StartIndex(pVal)
    EndTime = property(get_EndTime, put_EndTime, None)
    Level = property(get_Level, put_Level, None)
    Machine = property(get_Machine, put_Machine, None)
    MaxRecords = property(get_MaxRecords, put_MaxRecords, None)
    StartIndex = property(get_StartIndex, put_StartIndex, None)
    StartTime = property(get_StartTime, put_StartTime, None)
    Target = property(get_Target, put_Target, None)

class IServerLog(_esriServer.IServerLog):
    _IID = uuid.UUID('44dc928c-0350-4bdb-9970-4d5ca68b4117')
    def CreateQuery(self):
        '''Method IServerLog.CreateQuery

           OUTPUT
            ppQuery             : IServerLogQuery**'''
        return super(IServerLog, self).CreateQuery()
    def GetLogRecords(self, pQuery):
        '''Method IServerLog.GetLogRecords

           INPUT
            pQuery              : IServerLogQuery*

           OUTPUT
            results             : BSTR*'''
        return super(IServerLog, self).GetLogRecords(pQuery)

class IServerObjectConfigurationInfo(_esriServer.IServerObjectConfigurationInfo):
    _IID = uuid.UUID('6c7eec75-0d7d-4ec1-8b58-4d88f11fd4fa')
    def get_Name(self):
        '''Method IServerObjectConfigurationInfo.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectConfigurationInfo, self).get_Name()
    def get_TypeName(self):
        '''Method IServerObjectConfigurationInfo.get_TypeName

           OUTPUT
            TypeName            : BSTR*'''
        return super(IServerObjectConfigurationInfo, self).get_TypeName()
    def get_Description(self):
        '''Method IServerObjectConfigurationInfo.get_Description

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectConfigurationInfo, self).get_Description()
    def get_IsPooled(self):
        '''Method IServerObjectConfigurationInfo.get_IsPooled

           OUTPUT
            IsPooled            : VARIANT_BOOL*'''
        return super(IServerObjectConfigurationInfo, self).get_IsPooled()
    Description = property(get_Description, None, None)
    IsPooled = property(get_IsPooled, None, None)
    Name = property(get_Name, None, None)
    TypeName = property(get_TypeName, None, None)

class IEnumServerObjectConfigurationInfo(_esriServer.IEnumServerObjectConfigurationInfo):
    _IID = uuid.UUID('b810b79f-1777-4555-886d-dc6297fb2891')
    def Next(self):
        '''Method IEnumServerObjectConfigurationInfo.Next

           OUTPUT
            nextInfo            : IServerObjectConfigurationInfo**'''
        return super(IEnumServerObjectConfigurationInfo, self).Next()
    def __iter__(self):
        try:
            super(IEnumServerObjectConfigurationInfo, self).Reset()
            val = super(IEnumServerObjectConfigurationInfo, self).Next()
            while val:
                yield val
                val = super(IEnumServerObjectConfigurationInfo, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumServerObjectConfigurationInfo.Reset'''
        return super(IEnumServerObjectConfigurationInfo, self).Reset()
    def get_Count(self):
        '''Method IEnumServerObjectConfigurationInfo.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IEnumServerObjectConfigurationInfo, self).get_Count()
    Count = property(get_Count, None, None)

class IServerObjectTypeInfo(_esriServer.IServerObjectTypeInfo):
    _IID = uuid.UUID('1ef2395d-81eb-41fd-aa34-33e9fe2d8968')
    def get_Name(self):
        '''Method IServerObjectTypeInfo.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectTypeInfo, self).get_Name()
    def get_Description(self):
        '''Method IServerObjectTypeInfo.get_Description

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectTypeInfo, self).get_Description()
    Description = property(get_Description, None, None)
    Name = property(get_Name, None, None)

class IEnumServerObjectTypeInfo(_esriServer.IEnumServerObjectTypeInfo):
    _IID = uuid.UUID('e9407db1-0c60-47ef-a20c-7ea37ef0aec5')
    def Next(self):
        '''Method IEnumServerObjectTypeInfo.Next

           OUTPUT
            nextInfo            : IServerObjectTypeInfo**'''
        return super(IEnumServerObjectTypeInfo, self).Next()
    def __iter__(self):
        try:
            super(IEnumServerObjectTypeInfo, self).Reset()
            val = super(IEnumServerObjectTypeInfo, self).Next()
            while val:
                yield val
                val = super(IEnumServerObjectTypeInfo, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumServerObjectTypeInfo.Reset'''
        return super(IEnumServerObjectTypeInfo, self).Reset()
    def get_Count(self):
        '''Method IEnumServerObjectTypeInfo.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IEnumServerObjectTypeInfo, self).get_Count()
    Count = property(get_Count, None, None)

class IServerDirectoryInfo(_esriServer.IServerDirectoryInfo):
    _IID = uuid.UUID('cf180145-bcfe-4d6f-ac53-3b9e127af840')
    def get_Path(self):
        '''Method IServerDirectoryInfo.get_Path

           OUTPUT
            pPath               : BSTR*'''
        return super(IServerDirectoryInfo, self).get_Path()
    def get_URL(self):
        '''Method IServerDirectoryInfo.get_URL

           OUTPUT
            pUrl                : BSTR*'''
        return super(IServerDirectoryInfo, self).get_URL()
    def get_Description(self):
        '''Method IServerDirectoryInfo.get_Description

           OUTPUT
            pText               : BSTR*'''
        return super(IServerDirectoryInfo, self).get_Description()
    def get_CleaningMode(self):
        '''Method IServerDirectoryInfo.get_CleaningMode

           OUTPUT
            pMode               : esriServerDirectoryCleaningMode*'''
        return super(IServerDirectoryInfo, self).get_CleaningMode()
    def get_MaxFileAge(self):
        '''Method IServerDirectoryInfo.get_MaxFileAge

           OUTPUT
            pAge                : long*'''
        return super(IServerDirectoryInfo, self).get_MaxFileAge()
    CleaningMode = property(get_CleaningMode, None, None)
    Description = property(get_Description, None, None)
    MaxFileAge = property(get_MaxFileAge, None, None)
    Path = property(get_Path, None, None)
    URL = property(get_URL, None, None)

class IEnumServerDirectoryInfo(_esriServer.IEnumServerDirectoryInfo):
    _IID = uuid.UUID('e3a6f4a0-28ca-45b8-86b3-36888fb5466b')
    def Next(self):
        '''Method IEnumServerDirectoryInfo.Next

           OUTPUT
            nextInfo            : IServerDirectoryInfo**'''
        return super(IEnumServerDirectoryInfo, self).Next()
    def __iter__(self):
        try:
            super(IEnumServerDirectoryInfo, self).Reset()
            val = super(IEnumServerDirectoryInfo, self).Next()
            while val:
                yield val
                val = super(IEnumServerDirectoryInfo, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumServerDirectoryInfo.Reset'''
        return super(IEnumServerDirectoryInfo, self).Reset()
    def get_Count(self):
        '''Method IEnumServerDirectoryInfo.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IEnumServerDirectoryInfo, self).get_Count()
    Count = property(get_Count, None, None)

class IServerObjectManager(_esriServer.IServerObjectManager):
    _IID = uuid.UUID('cf25ea7a-b5bc-47aa-94b2-4cd598b0c428')
    def CreateServerContext(self, configName, TypeName):
        '''Method IServerObjectManager.CreateServerContext

           INPUTS
            configName          : BSTR
            TypeName            : BSTR

           OUTPUT
            context             : IServerContext**'''
        return super(IServerObjectManager, self).CreateServerContext(configName, TypeName)
    def GetConfigurationInfo(self, Name, TypeName):
        '''Method IServerObjectManager.GetConfigurationInfo

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppInfo              : IServerObjectConfigurationInfo**'''
        return super(IServerObjectManager, self).GetConfigurationInfo(Name, TypeName)
    def GetConfigurationInfos(self):
        '''Method IServerObjectManager.GetConfigurationInfos

           OUTPUT
            infos               : IEnumServerObjectConfigurationInfo**'''
        return super(IServerObjectManager, self).GetConfigurationInfos()
    def GetTypeInfos(self):
        '''Method IServerObjectManager.GetTypeInfos

           OUTPUT
            infos               : IEnumServerObjectTypeInfo**'''
        return super(IServerObjectManager, self).GetTypeInfos()
    def GetServerDirectoryInfos(self):
        '''Method IServerObjectManager.GetServerDirectoryInfos

           OUTPUT
            ppEnum              : IEnumServerDirectoryInfo**'''
        return super(IServerObjectManager, self).GetServerDirectoryInfos()

class IServerObjectExtensionTypeInfo(_esriServer.IServerObjectExtensionTypeInfo):
    _IID = uuid.UUID('b5d6fda3-b063-4174-9e70-2764d55bccb4')
    def get_Name(self):
        '''Method IServerObjectExtensionTypeInfo.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectExtensionTypeInfo, self).get_Name()
    def get_Description(self):
        '''Method IServerObjectExtensionTypeInfo.get_Description

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectExtensionTypeInfo, self).get_Description()
    Description = property(get_Description, None, None)
    Name = property(get_Name, None, None)

class IEnumServerObjectExtensionTypeInfo(_esriServer.IEnumServerObjectExtensionTypeInfo):
    _IID = uuid.UUID('975d6f9a-0849-4de7-bd0d-9615925a098d')
    def Next(self):
        '''Method IEnumServerObjectExtensionTypeInfo.Next

           OUTPUT
            nextInfo            : IServerObjectExtensionTypeInfo**'''
        return super(IEnumServerObjectExtensionTypeInfo, self).Next()
    def __iter__(self):
        try:
            super(IEnumServerObjectExtensionTypeInfo, self).Reset()
            val = super(IEnumServerObjectExtensionTypeInfo, self).Next()
            while val:
                yield val
                val = super(IEnumServerObjectExtensionTypeInfo, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumServerObjectExtensionTypeInfo.Reset'''
        return super(IEnumServerObjectExtensionTypeInfo, self).Reset()
    def get_Count(self):
        '''Method IEnumServerObjectExtensionTypeInfo.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IEnumServerObjectExtensionTypeInfo, self).get_Count()
    Count = property(get_Count, None, None)

class IServerObjectManager2(_esriServer.IServerObjectManager2):
    _IID = uuid.UUID('2e3707f3-dae3-45ba-ac15-47ef7ec69946')
    def get_SystemInfo(self):
        '''Method IServerObjectManager2.get_SystemInfo

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectManager2, self).get_SystemInfo()
    def GetExtensionTypeInfos(self, SOTypeName):
        '''Method IServerObjectManager2.GetExtensionTypeInfos

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppInfos             : IEnumServerObjectExtensionTypeInfo**'''
        return super(IServerObjectManager2, self).GetExtensionTypeInfos(SOTypeName)
    def GetConfigurationInfosEx(self, folderName):
        '''Method IServerObjectManager2.GetConfigurationInfosEx

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfigurationInfo**'''
        return super(IServerObjectManager2, self).GetConfigurationInfosEx(folderName)
    def GetFolders(self, folderName):
        '''Method IServerObjectManager2.GetFolders

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectManager2, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectManager2.get_FolderInfo

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectManager2, self).get_FolderInfo(folderName)
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectManager2.GetConfigurationStatus

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectManager2, self).GetConfigurationStatus(Name, TypeName)
    def CreateServerContext(self, configName, TypeName):
        '''Method IServerObjectManager.CreateServerContext (from IServerObjectManager)

           INPUTS
            configName          : BSTR
            TypeName            : BSTR

           OUTPUT
            context             : IServerContext**'''
        return super(IServerObjectManager2, self).CreateServerContext(configName, TypeName)
    def GetConfigurationInfo(self, Name, TypeName):
        '''Method IServerObjectManager.GetConfigurationInfo (from IServerObjectManager)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppInfo              : IServerObjectConfigurationInfo**'''
        return super(IServerObjectManager2, self).GetConfigurationInfo(Name, TypeName)
    def GetConfigurationInfos(self):
        '''Method IServerObjectManager.GetConfigurationInfos (from IServerObjectManager)

           OUTPUT
            infos               : IEnumServerObjectConfigurationInfo**'''
        return super(IServerObjectManager2, self).GetConfigurationInfos()
    def GetTypeInfos(self):
        '''Method IServerObjectManager.GetTypeInfos (from IServerObjectManager)

           OUTPUT
            infos               : IEnumServerObjectTypeInfo**'''
        return super(IServerObjectManager2, self).GetTypeInfos()
    def GetServerDirectoryInfos(self):
        '''Method IServerObjectManager.GetServerDirectoryInfos (from IServerObjectManager)

           OUTPUT
            ppEnum              : IEnumServerDirectoryInfo**'''
        return super(IServerObjectManager2, self).GetServerDirectoryInfos()
    SystemInfo = property(get_SystemInfo, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class IServerObjectManager3(_esriServer.IServerObjectManager3):
    _IID = uuid.UUID('0f25131d-5521-4e06-9a7f-bb246f25309c')
    def GetConfigurationInfosEx2(self, folderName, stat):
        '''Method IServerObjectManager3.GetConfigurationInfosEx2

           INPUTS
            folderName          : BSTR
            stat                : esriConfigurationStatus

           OUTPUT
            ppEnum              : IEnumServerObjectConfigurationInfo**'''
        return super(IServerObjectManager3, self).GetConfigurationInfosEx2(folderName, stat)
    def get_SystemInfo(self):
        '''Method IServerObjectManager2.get_SystemInfo (from IServerObjectManager2)

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectManager3, self).get_SystemInfo()
    def GetExtensionTypeInfos(self, SOTypeName):
        '''Method IServerObjectManager2.GetExtensionTypeInfos (from IServerObjectManager2)

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppInfos             : IEnumServerObjectExtensionTypeInfo**'''
        return super(IServerObjectManager3, self).GetExtensionTypeInfos(SOTypeName)
    def GetConfigurationInfosEx(self, folderName):
        '''Method IServerObjectManager2.GetConfigurationInfosEx (from IServerObjectManager2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfigurationInfo**'''
        return super(IServerObjectManager3, self).GetConfigurationInfosEx(folderName)
    def GetFolders(self, folderName):
        '''Method IServerObjectManager2.GetFolders (from IServerObjectManager2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectManager3, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectManager2.get_FolderInfo (from IServerObjectManager2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectManager3, self).get_FolderInfo(folderName)
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectManager2.GetConfigurationStatus (from IServerObjectManager2)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectManager3, self).GetConfigurationStatus(Name, TypeName)
    def CreateServerContext(self, configName, TypeName):
        '''Method IServerObjectManager.CreateServerContext (from IServerObjectManager)

           INPUTS
            configName          : BSTR
            TypeName            : BSTR

           OUTPUT
            context             : IServerContext**'''
        return super(IServerObjectManager3, self).CreateServerContext(configName, TypeName)
    def GetConfigurationInfo(self, Name, TypeName):
        '''Method IServerObjectManager.GetConfigurationInfo (from IServerObjectManager)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppInfo              : IServerObjectConfigurationInfo**'''
        return super(IServerObjectManager3, self).GetConfigurationInfo(Name, TypeName)
    def GetConfigurationInfos(self):
        '''Method IServerObjectManager.GetConfigurationInfos (from IServerObjectManager)

           OUTPUT
            infos               : IEnumServerObjectConfigurationInfo**'''
        return super(IServerObjectManager3, self).GetConfigurationInfos()
    def GetTypeInfos(self):
        '''Method IServerObjectManager.GetTypeInfos (from IServerObjectManager)

           OUTPUT
            infos               : IEnumServerObjectTypeInfo**'''
        return super(IServerObjectManager3, self).GetTypeInfos()
    def GetServerDirectoryInfos(self):
        '''Method IServerObjectManager.GetServerDirectoryInfos (from IServerObjectManager)

           OUTPUT
            ppEnum              : IEnumServerDirectoryInfo**'''
        return super(IServerObjectManager3, self).GetServerDirectoryInfos()
    SystemInfo = property(get_SystemInfo, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class IServiceDescription(_esriServer.IServiceDescription):
    _IID = uuid.UUID('99ea4f91-10a1-4901-a695-86e31090f3c1')

    def __init__(self, *args, **kw):
        super(IServiceDescription, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IServiceDescription.get_Name

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServiceDescription.put_Name

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription, self).put_Name(pVal)
    def get_Type(self):
        '''Method IServiceDescription.get_Type

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription, self).get_Type()
    def put_Type(self, pVal):
        '''Method IServiceDescription.put_Type

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription, self).put_Type(pVal)
    def get_URL(self):
        '''Method IServiceDescription.get_URL

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription, self).get_URL()
    def put_URL(self, pVal):
        '''Method IServiceDescription.put_URL

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription, self).put_URL(pVal)
    Name = property(get_Name, put_Name, None)
    Type = property(get_Type, put_Type, None)
    URL = property(get_URL, put_URL, None)

class IServiceDescriptionArray(_esriServer.IServiceDescriptionArray):
    _IID = uuid.UUID('eef9bc6f-4560-43ab-9d8c-f8eadfad5c70')

    def __init__(self, *args, **kw):
        super(IServiceDescriptionArray, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Count(self):
        '''Method IServiceDescriptionArray.get_Count

           OUTPUT
            pCount              : long*'''
        return super(IServiceDescriptionArray, self).get_Count()
    def get_Element(self, index):
        '''Method IServiceDescriptionArray.get_Element

           INPUT
            index               : long

           OUTPUT
            Element             : IServiceDescription**'''
        return super(IServiceDescriptionArray, self).get_Element(index)
    def Add(self, Element):
        '''Method IServiceDescriptionArray.Add

           INPUT
            Element             : IServiceDescription*'''
        return super(IServiceDescriptionArray, self).Add(Element)
    def Remove(self, index):
        '''Method IServiceDescriptionArray.Remove

           INPUT
            index               : long'''
        return super(IServiceDescriptionArray, self).Remove(index)
    def RemoveAll(self):
        '''Method IServiceDescriptionArray.RemoveAll'''
        return super(IServiceDescriptionArray, self).RemoveAll()
    def Insert(self, index, Element):
        '''Method IServiceDescriptionArray.Insert

           INPUTS
            index               : long
            Element             : IServiceDescription*'''
        return super(IServiceDescriptionArray, self).Insert(index, Element)
    def put_Element(self, index, Element):
        '''Method IServiceDescriptionArray.put_Element

           INPUTS
            index               : long
            Element             : IServiceDescription*'''
        return super(IServiceDescriptionArray, self).put_Element(index, Element)
    Count = property(get_Count, None, None)
    Element = property(None, put_Element, None)
    Element = IndexProperty(get_Element, None)

class IServiceCatalog(_esriServer.IServiceCatalog):
    _IID = uuid.UUID('89d60975-fdcf-4cea-b981-73fe406a2d2b')
    def get_ServiceDescriptions(self):
        '''Method IServiceCatalog.get_ServiceDescriptions

           OUTPUT
            pVal                : IServiceDescriptionArray**'''
        return super(IServiceCatalog, self).get_ServiceDescriptions()
    ServiceDescriptions = property(get_ServiceDescriptions, None, None)

class IServiceCatalog2(_esriServer.IServiceCatalog2):
    _IID = uuid.UUID('46c52546-7c26-477f-bdc1-b1c254625f81')
    def get_MessageVersion(self):
        '''Method IServiceCatalog2.get_MessageVersion

           OUTPUT
            ver                 : esriArcGISVersion*'''
        return super(IServiceCatalog2, self).get_MessageVersion()
    def get_MessageFormats(self):
        '''Method IServiceCatalog2.get_MessageFormats

           OUTPUT
            msgFormats          : esriServiceCatalogMessageFormat*'''
        return super(IServiceCatalog2, self).get_MessageFormats()
    def get_ServiceDescriptionsEx(self, folderName):
        '''Method IServiceCatalog2.get_ServiceDescriptionsEx

           INPUT
            folderName          : BSTR

           OUTPUT
            pVal                : IServiceDescriptionArray**'''
        return super(IServiceCatalog2, self).get_ServiceDescriptionsEx(folderName)
    def GetFolders(self, folderName):
        '''Method IServiceCatalog2.GetFolders

           INPUT
            folderName          : BSTR

           OUTPUT
            pVal                : IStringArray**'''
        return super(IServiceCatalog2, self).GetFolders(folderName)
    def get_ServiceDescriptions(self):
        '''Method IServiceCatalog.get_ServiceDescriptions (from IServiceCatalog)

           OUTPUT
            pVal                : IServiceDescriptionArray**'''
        return super(IServiceCatalog2, self).get_ServiceDescriptions()
    MessageFormats = property(get_MessageFormats, None, None)
    MessageVersion = property(get_MessageVersion, None, None)
    ServiceDescriptions = property(get_ServiceDescriptions, None, None)
    ServiceDescriptionsEx = IndexProperty(get_ServiceDescriptionsEx, None)

class IServerObjectManager4(_esriServer.IServerObjectManager4):
    _IID = uuid.UUID('b87e5523-e612-4d71-a37f-89be65d783fd')
    def CreateServiceCatalog(self):
        '''Method IServerObjectManager4.CreateServiceCatalog

           OUTPUT
            ppCatalog           : IServiceCatalog2**'''
        return super(IServerObjectManager4, self).CreateServiceCatalog()
    def GetConfigurationInfosEx2(self, folderName, stat):
        '''Method IServerObjectManager3.GetConfigurationInfosEx2 (from IServerObjectManager3)

           INPUTS
            folderName          : BSTR
            stat                : esriConfigurationStatus

           OUTPUT
            ppEnum              : IEnumServerObjectConfigurationInfo**'''
        return super(IServerObjectManager4, self).GetConfigurationInfosEx2(folderName, stat)
    def get_SystemInfo(self):
        '''Method IServerObjectManager2.get_SystemInfo (from IServerObjectManager2)

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectManager4, self).get_SystemInfo()
    def GetExtensionTypeInfos(self, SOTypeName):
        '''Method IServerObjectManager2.GetExtensionTypeInfos (from IServerObjectManager2)

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppInfos             : IEnumServerObjectExtensionTypeInfo**'''
        return super(IServerObjectManager4, self).GetExtensionTypeInfos(SOTypeName)
    def GetConfigurationInfosEx(self, folderName):
        '''Method IServerObjectManager2.GetConfigurationInfosEx (from IServerObjectManager2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfigurationInfo**'''
        return super(IServerObjectManager4, self).GetConfigurationInfosEx(folderName)
    def GetFolders(self, folderName):
        '''Method IServerObjectManager2.GetFolders (from IServerObjectManager2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectManager4, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectManager2.get_FolderInfo (from IServerObjectManager2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectManager4, self).get_FolderInfo(folderName)
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectManager2.GetConfigurationStatus (from IServerObjectManager2)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectManager4, self).GetConfigurationStatus(Name, TypeName)
    def CreateServerContext(self, configName, TypeName):
        '''Method IServerObjectManager.CreateServerContext (from IServerObjectManager)

           INPUTS
            configName          : BSTR
            TypeName            : BSTR

           OUTPUT
            context             : IServerContext**'''
        return super(IServerObjectManager4, self).CreateServerContext(configName, TypeName)
    def GetConfigurationInfo(self, Name, TypeName):
        '''Method IServerObjectManager.GetConfigurationInfo (from IServerObjectManager)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppInfo              : IServerObjectConfigurationInfo**'''
        return super(IServerObjectManager4, self).GetConfigurationInfo(Name, TypeName)
    def GetConfigurationInfos(self):
        '''Method IServerObjectManager.GetConfigurationInfos (from IServerObjectManager)

           OUTPUT
            infos               : IEnumServerObjectConfigurationInfo**'''
        return super(IServerObjectManager4, self).GetConfigurationInfos()
    def GetTypeInfos(self):
        '''Method IServerObjectManager.GetTypeInfos (from IServerObjectManager)

           OUTPUT
            infos               : IEnumServerObjectTypeInfo**'''
        return super(IServerObjectManager4, self).GetTypeInfos()
    def GetServerDirectoryInfos(self):
        '''Method IServerObjectManager.GetServerDirectoryInfos (from IServerObjectManager)

           OUTPUT
            ppEnum              : IEnumServerDirectoryInfo**'''
        return super(IServerObjectManager4, self).GetServerDirectoryInfos()
    SystemInfo = property(get_SystemInfo, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class IServerObjectExtensionType(_esriServer.IServerObjectExtensionType):
    _IID = uuid.UUID('47cb8511-3aa6-4da6-9095-b6f70237acee')

    def __init__(self, *args, **kw):
        super(IServerObjectExtensionType, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IServerObjectExtensionType.get_Name

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionType, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServerObjectExtensionType.put_Name

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectExtensionType, self).put_Name(pVal)
    def get_Description(self):
        '''Method IServerObjectExtensionType.get_Description

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectExtensionType, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectExtensionType.put_Description

           INPUT
            desc                : BSTR'''
        return super(IServerObjectExtensionType, self).put_Description(desc)
    def get_CLSID(self):
        '''Method IServerObjectExtensionType.get_CLSID

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionType, self).get_CLSID()
    def put_CLSID(self, pVal):
        '''Method IServerObjectExtensionType.put_CLSID

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectExtensionType, self).put_CLSID(pVal)
    CLSID = property(get_CLSID, put_CLSID, None)
    Description = property(get_Description, put_Description, None)
    Name = property(get_Name, put_Name, None)

class IEnumServerObjectExtensionType(_esriServer.IEnumServerObjectExtensionType):
    _IID = uuid.UUID('3a2ed9b4-ba20-47e8-8052-2e00a8e86869')
    def Next(self):
        '''Method IEnumServerObjectExtensionType.Next

           OUTPUT
            nextType            : IServerObjectExtensionType**'''
        return super(IEnumServerObjectExtensionType, self).Next()
    def __iter__(self):
        try:
            super(IEnumServerObjectExtensionType, self).Reset()
            val = super(IEnumServerObjectExtensionType, self).Next()
            while val:
                yield val
                val = super(IEnumServerObjectExtensionType, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumServerObjectExtensionType.Reset'''
        return super(IEnumServerObjectExtensionType, self).Reset()
    def get_Count(self):
        '''Method IEnumServerObjectExtensionType.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IEnumServerObjectExtensionType, self).get_Count()
    Count = property(get_Count, None, None)

class IServerObjectAdmin2(_esriServer.IServerObjectAdmin2):
    _IID = uuid.UUID('4bc97a90-0b03-478c-8eb8-2ba647297bf7')

    def __init__(self, *args, **kw):
        super(IServerObjectAdmin2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def GetExtensionTypes(self, SOTypeName):
        '''Method IServerObjectAdmin2.GetExtensionTypes

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppTypes             : IEnumServerObjectExtensionType**'''
        return super(IServerObjectAdmin2, self).GetExtensionTypes(SOTypeName)
    def get_ServerLog(self):
        '''Method IServerObjectAdmin2.get_ServerLog

           OUTPUT
            ppLog               : IServerLog**'''
        return super(IServerObjectAdmin2, self).get_ServerLog()
    def Enable(self):
        '''Method IServerObjectAdmin2.Enable'''
        return super(IServerObjectAdmin2, self).Enable()
    def Disable(self):
        '''Method IServerObjectAdmin2.Disable'''
        return super(IServerObjectAdmin2, self).Disable()
    def CreateExtensionType(self):
        '''Method IServerObjectAdmin2.CreateExtensionType

           OUTPUT
            ppSOEType           : IServerObjectExtensionType**'''
        return super(IServerObjectAdmin2, self).CreateExtensionType()
    def AddExtensionType(self, SOTypeName, pSOEType):
        '''Method IServerObjectAdmin2.AddExtensionType

           INPUTS
            SOTypeName          : BSTR
            pSOEType            : IServerObjectExtensionType*'''
        return super(IServerObjectAdmin2, self).AddExtensionType(SOTypeName, pSOEType)
    def DeleteExtensionType(self, SOTypeName, SOETypeName):
        '''Method IServerObjectAdmin2.DeleteExtensionType

           INPUTS
            SOTypeName          : BSTR
            SOETypeName         : BSTR'''
        return super(IServerObjectAdmin2, self).DeleteExtensionType(SOTypeName, SOETypeName)
    def CreateFolder(self, folderName):
        '''Method IServerObjectAdmin2.CreateFolder

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin2, self).CreateFolder(folderName)
    def DeleteFolder(self, folderName):
        '''Method IServerObjectAdmin2.DeleteFolder

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin2, self).DeleteFolder(folderName)
    def RenameFolder(self, folderName, newName):
        '''Method IServerObjectAdmin2.RenameFolder

           INPUTS
            folderName          : BSTR
            newName             : BSTR'''
        return super(IServerObjectAdmin2, self).RenameFolder(folderName, newName)
    def GetFolders(self, folderName):
        '''Method IServerObjectAdmin2.GetFolders

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectAdmin2, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectAdmin2.get_FolderInfo

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectAdmin2, self).get_FolderInfo(folderName)
    def put_FolderInfo(self, folderName, ppInfo):
        '''Method IServerObjectAdmin2.put_FolderInfo

           INPUTS
            folderName          : BSTR
            ppInfo              : IPropertySet*'''
        return super(IServerObjectAdmin2, self).put_FolderInfo(folderName, ppInfo)
    def GetConfigurationsEx(self, folderName):
        '''Method IServerObjectAdmin2.GetConfigurationsEx

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin2, self).GetConfigurationsEx(folderName)
    def ValidateConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin2.ValidateConfiguration

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin2, self).ValidateConfiguration(Name, TypeName)
    def CreateServerDirectory(self):
        '''Method IServerObjectAdmin.CreateServerDirectory (from IServerObjectAdmin)

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin2, self).CreateServerDirectory()
    def AddServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.AddServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin2, self).AddServerDirectory(pSD)
    def UpdateServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.UpdateServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin2, self).UpdateServerDirectory(pSD)
    def DeleteServerDirectory(self, Path):
        '''Method IServerObjectAdmin.DeleteServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR'''
        return super(IServerObjectAdmin2, self).DeleteServerDirectory(Path)
    def GetServerDirectory(self, Path):
        '''Method IServerObjectAdmin.GetServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin2, self).GetServerDirectory(Path)
    def GetServerDirectories(self):
        '''Method IServerObjectAdmin.GetServerDirectories (from IServerObjectAdmin)

           OUTPUT
            ppEnum              : IEnumServerDirectory**'''
        return super(IServerObjectAdmin2, self).GetServerDirectories()
    def CreateConfiguration(self):
        '''Method IServerObjectAdmin.CreateConfiguration (from IServerObjectAdmin)

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin2, self).CreateConfiguration()
    def AddConfiguration(self, config):
        '''Method IServerObjectAdmin.AddConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin2, self).AddConfiguration(config)
    def GetConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin2, self).GetConfiguration(Name, TypeName)
    def UpdateConfiguration(self, config):
        '''Method IServerObjectAdmin.UpdateConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin2, self).UpdateConfiguration(config)
    def DeleteConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.DeleteConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin2, self).DeleteConfiguration(Name, TypeName)
    def GetConfigurations(self):
        '''Method IServerObjectAdmin.GetConfigurations (from IServerObjectAdmin)

           OUTPUT
            ppConfigs           : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin2, self).GetConfigurations()
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfigurationStatus (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectAdmin2, self).GetConfigurationStatus(Name, TypeName)
    def GetTypes(self):
        '''Method IServerObjectAdmin.GetTypes (from IServerObjectAdmin)

           OUTPUT
            ppTypes             : IEnumServerObjectType**'''
        return super(IServerObjectAdmin2, self).GetTypes()
    def StartConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StartConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin2, self).StartConfiguration(Name, TypeName)
    def StopConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StopConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin2, self).StopConfiguration(Name, TypeName)
    def PauseConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.PauseConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin2, self).PauseConfiguration(Name, TypeName)
    def CreateMachine(self):
        '''Method IServerObjectAdmin.CreateMachine (from IServerObjectAdmin)

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin2, self).CreateMachine()
    def AddMachine(self, Machine):
        '''Method IServerObjectAdmin.AddMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin2, self).AddMachine(Machine)
    def GetMachines(self):
        '''Method IServerObjectAdmin.GetMachines (from IServerObjectAdmin)

           OUTPUT
            machines            : IEnumServerMachine**'''
        return super(IServerObjectAdmin2, self).GetMachines()
    def DeleteMachine(self, MachineName):
        '''Method IServerObjectAdmin.DeleteMachine (from IServerObjectAdmin)

           INPUT
            MachineName         : BSTR'''
        return super(IServerObjectAdmin2, self).DeleteMachine(MachineName)
    def GetMachine(self, Name):
        '''Method IServerObjectAdmin.GetMachine (from IServerObjectAdmin)

           INPUT
            Name                : BSTR

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin2, self).GetMachine(Name)
    def UpdateMachine(self, Machine):
        '''Method IServerObjectAdmin.UpdateMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin2, self).UpdateMachine(Machine)
    def get_Properties(self):
        '''Method IServerObjectAdmin.get_Properties (from IServerObjectAdmin)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectAdmin2, self).get_Properties()
    def put_Properties(self, props):
        '''Method IServerObjectAdmin.put_Properties (from IServerObjectAdmin)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectAdmin2, self).put_Properties(props)
    FolderInfo = property(None, put_FolderInfo, None)
    Properties = property(get_Properties, put_Properties, None)
    ServerLog = property(get_ServerLog, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class IServerObjectAdmin3(_esriServer.IServerObjectAdmin3):
    _IID = uuid.UUID('e5079624-e7c9-4b12-9df7-2bc1c341a2b7')

    def __init__(self, *args, **kw):
        super(IServerObjectAdmin3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def GetConfigurationsEx2(self, folderName, stat):
        '''Method IServerObjectAdmin3.GetConfigurationsEx2

           INPUTS
            folderName          : BSTR
            stat                : esriConfigurationStatus

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin3, self).GetConfigurationsEx2(folderName, stat)
    def GetExtensionTypes(self, SOTypeName):
        '''Method IServerObjectAdmin2.GetExtensionTypes (from IServerObjectAdmin2)

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppTypes             : IEnumServerObjectExtensionType**'''
        return super(IServerObjectAdmin3, self).GetExtensionTypes(SOTypeName)
    def get_ServerLog(self):
        '''Method IServerObjectAdmin2.get_ServerLog (from IServerObjectAdmin2)

           OUTPUT
            ppLog               : IServerLog**'''
        return super(IServerObjectAdmin3, self).get_ServerLog()
    def Enable(self):
        '''Method IServerObjectAdmin2.Enable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin3, self).Enable()
    def Disable(self):
        '''Method IServerObjectAdmin2.Disable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin3, self).Disable()
    def CreateExtensionType(self):
        '''Method IServerObjectAdmin2.CreateExtensionType (from IServerObjectAdmin2)

           OUTPUT
            ppSOEType           : IServerObjectExtensionType**'''
        return super(IServerObjectAdmin3, self).CreateExtensionType()
    def AddExtensionType(self, SOTypeName, pSOEType):
        '''Method IServerObjectAdmin2.AddExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            pSOEType            : IServerObjectExtensionType*'''
        return super(IServerObjectAdmin3, self).AddExtensionType(SOTypeName, pSOEType)
    def DeleteExtensionType(self, SOTypeName, SOETypeName):
        '''Method IServerObjectAdmin2.DeleteExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            SOETypeName         : BSTR'''
        return super(IServerObjectAdmin3, self).DeleteExtensionType(SOTypeName, SOETypeName)
    def CreateFolder(self, folderName):
        '''Method IServerObjectAdmin2.CreateFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin3, self).CreateFolder(folderName)
    def DeleteFolder(self, folderName):
        '''Method IServerObjectAdmin2.DeleteFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin3, self).DeleteFolder(folderName)
    def RenameFolder(self, folderName, newName):
        '''Method IServerObjectAdmin2.RenameFolder (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            newName             : BSTR'''
        return super(IServerObjectAdmin3, self).RenameFolder(folderName, newName)
    def GetFolders(self, folderName):
        '''Method IServerObjectAdmin2.GetFolders (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectAdmin3, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectAdmin2.get_FolderInfo (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectAdmin3, self).get_FolderInfo(folderName)
    def put_FolderInfo(self, folderName, ppInfo):
        '''Method IServerObjectAdmin2.put_FolderInfo (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            ppInfo              : IPropertySet*'''
        return super(IServerObjectAdmin3, self).put_FolderInfo(folderName, ppInfo)
    def GetConfigurationsEx(self, folderName):
        '''Method IServerObjectAdmin2.GetConfigurationsEx (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin3, self).GetConfigurationsEx(folderName)
    def ValidateConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin2.ValidateConfiguration (from IServerObjectAdmin2)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin3, self).ValidateConfiguration(Name, TypeName)
    def CreateServerDirectory(self):
        '''Method IServerObjectAdmin.CreateServerDirectory (from IServerObjectAdmin)

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin3, self).CreateServerDirectory()
    def AddServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.AddServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin3, self).AddServerDirectory(pSD)
    def UpdateServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.UpdateServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin3, self).UpdateServerDirectory(pSD)
    def DeleteServerDirectory(self, Path):
        '''Method IServerObjectAdmin.DeleteServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR'''
        return super(IServerObjectAdmin3, self).DeleteServerDirectory(Path)
    def GetServerDirectory(self, Path):
        '''Method IServerObjectAdmin.GetServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin3, self).GetServerDirectory(Path)
    def GetServerDirectories(self):
        '''Method IServerObjectAdmin.GetServerDirectories (from IServerObjectAdmin)

           OUTPUT
            ppEnum              : IEnumServerDirectory**'''
        return super(IServerObjectAdmin3, self).GetServerDirectories()
    def CreateConfiguration(self):
        '''Method IServerObjectAdmin.CreateConfiguration (from IServerObjectAdmin)

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin3, self).CreateConfiguration()
    def AddConfiguration(self, config):
        '''Method IServerObjectAdmin.AddConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin3, self).AddConfiguration(config)
    def GetConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin3, self).GetConfiguration(Name, TypeName)
    def UpdateConfiguration(self, config):
        '''Method IServerObjectAdmin.UpdateConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin3, self).UpdateConfiguration(config)
    def DeleteConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.DeleteConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin3, self).DeleteConfiguration(Name, TypeName)
    def GetConfigurations(self):
        '''Method IServerObjectAdmin.GetConfigurations (from IServerObjectAdmin)

           OUTPUT
            ppConfigs           : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin3, self).GetConfigurations()
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfigurationStatus (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectAdmin3, self).GetConfigurationStatus(Name, TypeName)
    def GetTypes(self):
        '''Method IServerObjectAdmin.GetTypes (from IServerObjectAdmin)

           OUTPUT
            ppTypes             : IEnumServerObjectType**'''
        return super(IServerObjectAdmin3, self).GetTypes()
    def StartConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StartConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin3, self).StartConfiguration(Name, TypeName)
    def StopConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StopConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin3, self).StopConfiguration(Name, TypeName)
    def PauseConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.PauseConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin3, self).PauseConfiguration(Name, TypeName)
    def CreateMachine(self):
        '''Method IServerObjectAdmin.CreateMachine (from IServerObjectAdmin)

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin3, self).CreateMachine()
    def AddMachine(self, Machine):
        '''Method IServerObjectAdmin.AddMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin3, self).AddMachine(Machine)
    def GetMachines(self):
        '''Method IServerObjectAdmin.GetMachines (from IServerObjectAdmin)

           OUTPUT
            machines            : IEnumServerMachine**'''
        return super(IServerObjectAdmin3, self).GetMachines()
    def DeleteMachine(self, MachineName):
        '''Method IServerObjectAdmin.DeleteMachine (from IServerObjectAdmin)

           INPUT
            MachineName         : BSTR'''
        return super(IServerObjectAdmin3, self).DeleteMachine(MachineName)
    def GetMachine(self, Name):
        '''Method IServerObjectAdmin.GetMachine (from IServerObjectAdmin)

           INPUT
            Name                : BSTR

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin3, self).GetMachine(Name)
    def UpdateMachine(self, Machine):
        '''Method IServerObjectAdmin.UpdateMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin3, self).UpdateMachine(Machine)
    def get_Properties(self):
        '''Method IServerObjectAdmin.get_Properties (from IServerObjectAdmin)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectAdmin3, self).get_Properties()
    def put_Properties(self, props):
        '''Method IServerObjectAdmin.put_Properties (from IServerObjectAdmin)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectAdmin3, self).put_Properties(props)
    FolderInfo = property(None, put_FolderInfo, None)
    Properties = property(get_Properties, put_Properties, None)
    ServerLog = property(get_ServerLog, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class IServerObjectAdmin4(_esriServer.IServerObjectAdmin4):
    _IID = uuid.UUID('6fa1268d-0dd4-46b6-b890-02e20fc6341f')

    def __init__(self, *args, **kw):
        super(IServerObjectAdmin4, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_IsSecurityEnabled(self):
        '''Method IServerObjectAdmin4.get_IsSecurityEnabled

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin4, self).get_IsSecurityEnabled()
    def put_IsSecurityEnabled(self, pVal):
        '''Method IServerObjectAdmin4.put_IsSecurityEnabled

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(IServerObjectAdmin4, self).put_IsSecurityEnabled(pVal)
    def GetConfigurationsEx2(self, folderName, stat):
        '''Method IServerObjectAdmin3.GetConfigurationsEx2 (from IServerObjectAdmin3)

           INPUTS
            folderName          : BSTR
            stat                : esriConfigurationStatus

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin4, self).GetConfigurationsEx2(folderName, stat)
    def GetExtensionTypes(self, SOTypeName):
        '''Method IServerObjectAdmin2.GetExtensionTypes (from IServerObjectAdmin2)

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppTypes             : IEnumServerObjectExtensionType**'''
        return super(IServerObjectAdmin4, self).GetExtensionTypes(SOTypeName)
    def get_ServerLog(self):
        '''Method IServerObjectAdmin2.get_ServerLog (from IServerObjectAdmin2)

           OUTPUT
            ppLog               : IServerLog**'''
        return super(IServerObjectAdmin4, self).get_ServerLog()
    def Enable(self):
        '''Method IServerObjectAdmin2.Enable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin4, self).Enable()
    def Disable(self):
        '''Method IServerObjectAdmin2.Disable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin4, self).Disable()
    def CreateExtensionType(self):
        '''Method IServerObjectAdmin2.CreateExtensionType (from IServerObjectAdmin2)

           OUTPUT
            ppSOEType           : IServerObjectExtensionType**'''
        return super(IServerObjectAdmin4, self).CreateExtensionType()
    def AddExtensionType(self, SOTypeName, pSOEType):
        '''Method IServerObjectAdmin2.AddExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            pSOEType            : IServerObjectExtensionType*'''
        return super(IServerObjectAdmin4, self).AddExtensionType(SOTypeName, pSOEType)
    def DeleteExtensionType(self, SOTypeName, SOETypeName):
        '''Method IServerObjectAdmin2.DeleteExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            SOETypeName         : BSTR'''
        return super(IServerObjectAdmin4, self).DeleteExtensionType(SOTypeName, SOETypeName)
    def CreateFolder(self, folderName):
        '''Method IServerObjectAdmin2.CreateFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin4, self).CreateFolder(folderName)
    def DeleteFolder(self, folderName):
        '''Method IServerObjectAdmin2.DeleteFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin4, self).DeleteFolder(folderName)
    def RenameFolder(self, folderName, newName):
        '''Method IServerObjectAdmin2.RenameFolder (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            newName             : BSTR'''
        return super(IServerObjectAdmin4, self).RenameFolder(folderName, newName)
    def GetFolders(self, folderName):
        '''Method IServerObjectAdmin2.GetFolders (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectAdmin4, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectAdmin2.get_FolderInfo (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectAdmin4, self).get_FolderInfo(folderName)
    def put_FolderInfo(self, folderName, ppInfo):
        '''Method IServerObjectAdmin2.put_FolderInfo (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            ppInfo              : IPropertySet*'''
        return super(IServerObjectAdmin4, self).put_FolderInfo(folderName, ppInfo)
    def GetConfigurationsEx(self, folderName):
        '''Method IServerObjectAdmin2.GetConfigurationsEx (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin4, self).GetConfigurationsEx(folderName)
    def ValidateConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin2.ValidateConfiguration (from IServerObjectAdmin2)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin4, self).ValidateConfiguration(Name, TypeName)
    def CreateServerDirectory(self):
        '''Method IServerObjectAdmin.CreateServerDirectory (from IServerObjectAdmin)

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin4, self).CreateServerDirectory()
    def AddServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.AddServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin4, self).AddServerDirectory(pSD)
    def UpdateServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.UpdateServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin4, self).UpdateServerDirectory(pSD)
    def DeleteServerDirectory(self, Path):
        '''Method IServerObjectAdmin.DeleteServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR'''
        return super(IServerObjectAdmin4, self).DeleteServerDirectory(Path)
    def GetServerDirectory(self, Path):
        '''Method IServerObjectAdmin.GetServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin4, self).GetServerDirectory(Path)
    def GetServerDirectories(self):
        '''Method IServerObjectAdmin.GetServerDirectories (from IServerObjectAdmin)

           OUTPUT
            ppEnum              : IEnumServerDirectory**'''
        return super(IServerObjectAdmin4, self).GetServerDirectories()
    def CreateConfiguration(self):
        '''Method IServerObjectAdmin.CreateConfiguration (from IServerObjectAdmin)

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin4, self).CreateConfiguration()
    def AddConfiguration(self, config):
        '''Method IServerObjectAdmin.AddConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin4, self).AddConfiguration(config)
    def GetConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin4, self).GetConfiguration(Name, TypeName)
    def UpdateConfiguration(self, config):
        '''Method IServerObjectAdmin.UpdateConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin4, self).UpdateConfiguration(config)
    def DeleteConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.DeleteConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin4, self).DeleteConfiguration(Name, TypeName)
    def GetConfigurations(self):
        '''Method IServerObjectAdmin.GetConfigurations (from IServerObjectAdmin)

           OUTPUT
            ppConfigs           : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin4, self).GetConfigurations()
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfigurationStatus (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectAdmin4, self).GetConfigurationStatus(Name, TypeName)
    def GetTypes(self):
        '''Method IServerObjectAdmin.GetTypes (from IServerObjectAdmin)

           OUTPUT
            ppTypes             : IEnumServerObjectType**'''
        return super(IServerObjectAdmin4, self).GetTypes()
    def StartConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StartConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin4, self).StartConfiguration(Name, TypeName)
    def StopConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StopConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin4, self).StopConfiguration(Name, TypeName)
    def PauseConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.PauseConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin4, self).PauseConfiguration(Name, TypeName)
    def CreateMachine(self):
        '''Method IServerObjectAdmin.CreateMachine (from IServerObjectAdmin)

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin4, self).CreateMachine()
    def AddMachine(self, Machine):
        '''Method IServerObjectAdmin.AddMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin4, self).AddMachine(Machine)
    def GetMachines(self):
        '''Method IServerObjectAdmin.GetMachines (from IServerObjectAdmin)

           OUTPUT
            machines            : IEnumServerMachine**'''
        return super(IServerObjectAdmin4, self).GetMachines()
    def DeleteMachine(self, MachineName):
        '''Method IServerObjectAdmin.DeleteMachine (from IServerObjectAdmin)

           INPUT
            MachineName         : BSTR'''
        return super(IServerObjectAdmin4, self).DeleteMachine(MachineName)
    def GetMachine(self, Name):
        '''Method IServerObjectAdmin.GetMachine (from IServerObjectAdmin)

           INPUT
            Name                : BSTR

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin4, self).GetMachine(Name)
    def UpdateMachine(self, Machine):
        '''Method IServerObjectAdmin.UpdateMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin4, self).UpdateMachine(Machine)
    def get_Properties(self):
        '''Method IServerObjectAdmin.get_Properties (from IServerObjectAdmin)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectAdmin4, self).get_Properties()
    def put_Properties(self, props):
        '''Method IServerObjectAdmin.put_Properties (from IServerObjectAdmin)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectAdmin4, self).put_Properties(props)
    FolderInfo = property(None, put_FolderInfo, None)
    IsSecurityEnabled = property(get_IsSecurityEnabled, put_IsSecurityEnabled, None)
    Properties = property(get_Properties, put_Properties, None)
    ServerLog = property(get_ServerLog, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class IServerObjectAdmin5(_esriServer.IServerObjectAdmin5):
    _IID = uuid.UUID('a7b0b4b3-1001-49ad-ad44-aa6441d7300a')

    def __init__(self, *args, **kw):
        super(IServerObjectAdmin5, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def GetConfigurationProperties(self, Name, Type):
        '''Method IServerObjectAdmin5.GetConfigurationProperties

           INPUTS
            Name                : BSTR
            Type                : BSTR

           OUTPUT
            ppProps             : IPropertySet**'''
        return super(IServerObjectAdmin5, self).GetConfigurationProperties(Name, Type)
    def UpdateConfigurationProperties(self, Name, Type, pProps):
        '''Method IServerObjectAdmin5.UpdateConfigurationProperties

           INPUTS
            Name                : BSTR
            Type                : BSTR
            pProps              : IPropertySet*'''
        return super(IServerObjectAdmin5, self).UpdateConfigurationProperties(Name, Type, pProps)
    def get_IsSecurityEnabled(self):
        '''Method IServerObjectAdmin4.get_IsSecurityEnabled (from IServerObjectAdmin4)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin5, self).get_IsSecurityEnabled()
    def put_IsSecurityEnabled(self, pVal):
        '''Method IServerObjectAdmin4.put_IsSecurityEnabled (from IServerObjectAdmin4)

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(IServerObjectAdmin5, self).put_IsSecurityEnabled(pVal)
    def GetConfigurationsEx2(self, folderName, stat):
        '''Method IServerObjectAdmin3.GetConfigurationsEx2 (from IServerObjectAdmin3)

           INPUTS
            folderName          : BSTR
            stat                : esriConfigurationStatus

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin5, self).GetConfigurationsEx2(folderName, stat)
    def GetExtensionTypes(self, SOTypeName):
        '''Method IServerObjectAdmin2.GetExtensionTypes (from IServerObjectAdmin2)

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppTypes             : IEnumServerObjectExtensionType**'''
        return super(IServerObjectAdmin5, self).GetExtensionTypes(SOTypeName)
    def get_ServerLog(self):
        '''Method IServerObjectAdmin2.get_ServerLog (from IServerObjectAdmin2)

           OUTPUT
            ppLog               : IServerLog**'''
        return super(IServerObjectAdmin5, self).get_ServerLog()
    def Enable(self):
        '''Method IServerObjectAdmin2.Enable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin5, self).Enable()
    def Disable(self):
        '''Method IServerObjectAdmin2.Disable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin5, self).Disable()
    def CreateExtensionType(self):
        '''Method IServerObjectAdmin2.CreateExtensionType (from IServerObjectAdmin2)

           OUTPUT
            ppSOEType           : IServerObjectExtensionType**'''
        return super(IServerObjectAdmin5, self).CreateExtensionType()
    def AddExtensionType(self, SOTypeName, pSOEType):
        '''Method IServerObjectAdmin2.AddExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            pSOEType            : IServerObjectExtensionType*'''
        return super(IServerObjectAdmin5, self).AddExtensionType(SOTypeName, pSOEType)
    def DeleteExtensionType(self, SOTypeName, SOETypeName):
        '''Method IServerObjectAdmin2.DeleteExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            SOETypeName         : BSTR'''
        return super(IServerObjectAdmin5, self).DeleteExtensionType(SOTypeName, SOETypeName)
    def CreateFolder(self, folderName):
        '''Method IServerObjectAdmin2.CreateFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin5, self).CreateFolder(folderName)
    def DeleteFolder(self, folderName):
        '''Method IServerObjectAdmin2.DeleteFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin5, self).DeleteFolder(folderName)
    def RenameFolder(self, folderName, newName):
        '''Method IServerObjectAdmin2.RenameFolder (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            newName             : BSTR'''
        return super(IServerObjectAdmin5, self).RenameFolder(folderName, newName)
    def GetFolders(self, folderName):
        '''Method IServerObjectAdmin2.GetFolders (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectAdmin5, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectAdmin2.get_FolderInfo (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectAdmin5, self).get_FolderInfo(folderName)
    def put_FolderInfo(self, folderName, ppInfo):
        '''Method IServerObjectAdmin2.put_FolderInfo (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            ppInfo              : IPropertySet*'''
        return super(IServerObjectAdmin5, self).put_FolderInfo(folderName, ppInfo)
    def GetConfigurationsEx(self, folderName):
        '''Method IServerObjectAdmin2.GetConfigurationsEx (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin5, self).GetConfigurationsEx(folderName)
    def ValidateConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin2.ValidateConfiguration (from IServerObjectAdmin2)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin5, self).ValidateConfiguration(Name, TypeName)
    def CreateServerDirectory(self):
        '''Method IServerObjectAdmin.CreateServerDirectory (from IServerObjectAdmin)

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin5, self).CreateServerDirectory()
    def AddServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.AddServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin5, self).AddServerDirectory(pSD)
    def UpdateServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.UpdateServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin5, self).UpdateServerDirectory(pSD)
    def DeleteServerDirectory(self, Path):
        '''Method IServerObjectAdmin.DeleteServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR'''
        return super(IServerObjectAdmin5, self).DeleteServerDirectory(Path)
    def GetServerDirectory(self, Path):
        '''Method IServerObjectAdmin.GetServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin5, self).GetServerDirectory(Path)
    def GetServerDirectories(self):
        '''Method IServerObjectAdmin.GetServerDirectories (from IServerObjectAdmin)

           OUTPUT
            ppEnum              : IEnumServerDirectory**'''
        return super(IServerObjectAdmin5, self).GetServerDirectories()
    def CreateConfiguration(self):
        '''Method IServerObjectAdmin.CreateConfiguration (from IServerObjectAdmin)

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin5, self).CreateConfiguration()
    def AddConfiguration(self, config):
        '''Method IServerObjectAdmin.AddConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin5, self).AddConfiguration(config)
    def GetConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin5, self).GetConfiguration(Name, TypeName)
    def UpdateConfiguration(self, config):
        '''Method IServerObjectAdmin.UpdateConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin5, self).UpdateConfiguration(config)
    def DeleteConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.DeleteConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin5, self).DeleteConfiguration(Name, TypeName)
    def GetConfigurations(self):
        '''Method IServerObjectAdmin.GetConfigurations (from IServerObjectAdmin)

           OUTPUT
            ppConfigs           : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin5, self).GetConfigurations()
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfigurationStatus (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectAdmin5, self).GetConfigurationStatus(Name, TypeName)
    def GetTypes(self):
        '''Method IServerObjectAdmin.GetTypes (from IServerObjectAdmin)

           OUTPUT
            ppTypes             : IEnumServerObjectType**'''
        return super(IServerObjectAdmin5, self).GetTypes()
    def StartConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StartConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin5, self).StartConfiguration(Name, TypeName)
    def StopConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StopConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin5, self).StopConfiguration(Name, TypeName)
    def PauseConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.PauseConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin5, self).PauseConfiguration(Name, TypeName)
    def CreateMachine(self):
        '''Method IServerObjectAdmin.CreateMachine (from IServerObjectAdmin)

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin5, self).CreateMachine()
    def AddMachine(self, Machine):
        '''Method IServerObjectAdmin.AddMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin5, self).AddMachine(Machine)
    def GetMachines(self):
        '''Method IServerObjectAdmin.GetMachines (from IServerObjectAdmin)

           OUTPUT
            machines            : IEnumServerMachine**'''
        return super(IServerObjectAdmin5, self).GetMachines()
    def DeleteMachine(self, MachineName):
        '''Method IServerObjectAdmin.DeleteMachine (from IServerObjectAdmin)

           INPUT
            MachineName         : BSTR'''
        return super(IServerObjectAdmin5, self).DeleteMachine(MachineName)
    def GetMachine(self, Name):
        '''Method IServerObjectAdmin.GetMachine (from IServerObjectAdmin)

           INPUT
            Name                : BSTR

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin5, self).GetMachine(Name)
    def UpdateMachine(self, Machine):
        '''Method IServerObjectAdmin.UpdateMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin5, self).UpdateMachine(Machine)
    def get_Properties(self):
        '''Method IServerObjectAdmin.get_Properties (from IServerObjectAdmin)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectAdmin5, self).get_Properties()
    def put_Properties(self, props):
        '''Method IServerObjectAdmin.put_Properties (from IServerObjectAdmin)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectAdmin5, self).put_Properties(props)
    FolderInfo = property(None, put_FolderInfo, None)
    IsSecurityEnabled = property(get_IsSecurityEnabled, put_IsSecurityEnabled, None)
    Properties = property(get_Properties, put_Properties, None)
    ServerLog = property(get_ServerLog, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class IServerObjectAdmin6(_esriServer.IServerObjectAdmin6):
    _IID = uuid.UUID('dc0e02cd-e386-4324-b31f-56b2c5d22363')

    def __init__(self, *args, **kw):
        super(IServerObjectAdmin6, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def GetInputDir(self, cfgName, cfgType):
        '''Method IServerObjectAdmin6.GetInputDir

           INPUTS
            cfgName             : BSTR
            cfgType             : BSTR

           OUTPUT
            dir                 : BSTR*'''
        return super(IServerObjectAdmin6, self).GetInputDir(cfgName, cfgType)
    def IsInputDirInUse(self):
        '''Method IServerObjectAdmin6.IsInputDirInUse

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin6, self).IsInputDirInUse()
    def UploadData(self, cfgName, cfgType, fileName, data):
        '''Method IServerObjectAdmin6.UploadData

           INPUTS
            cfgName             : BSTR
            cfgType             : BSTR
            fileName            : BSTR
            data                : SAFEARRAY**'''
        return super(IServerObjectAdmin6, self).UploadData(cfgName, cfgType, fileName, data)
    def GetConfigurationProperties(self, Name, Type):
        '''Method IServerObjectAdmin5.GetConfigurationProperties (from IServerObjectAdmin5)

           INPUTS
            Name                : BSTR
            Type                : BSTR

           OUTPUT
            ppProps             : IPropertySet**'''
        return super(IServerObjectAdmin6, self).GetConfigurationProperties(Name, Type)
    def UpdateConfigurationProperties(self, Name, Type, pProps):
        '''Method IServerObjectAdmin5.UpdateConfigurationProperties (from IServerObjectAdmin5)

           INPUTS
            Name                : BSTR
            Type                : BSTR
            pProps              : IPropertySet*'''
        return super(IServerObjectAdmin6, self).UpdateConfigurationProperties(Name, Type, pProps)
    def get_IsSecurityEnabled(self):
        '''Method IServerObjectAdmin4.get_IsSecurityEnabled (from IServerObjectAdmin4)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin6, self).get_IsSecurityEnabled()
    def put_IsSecurityEnabled(self, pVal):
        '''Method IServerObjectAdmin4.put_IsSecurityEnabled (from IServerObjectAdmin4)

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(IServerObjectAdmin6, self).put_IsSecurityEnabled(pVal)
    def GetConfigurationsEx2(self, folderName, stat):
        '''Method IServerObjectAdmin3.GetConfigurationsEx2 (from IServerObjectAdmin3)

           INPUTS
            folderName          : BSTR
            stat                : esriConfigurationStatus

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin6, self).GetConfigurationsEx2(folderName, stat)
    def GetExtensionTypes(self, SOTypeName):
        '''Method IServerObjectAdmin2.GetExtensionTypes (from IServerObjectAdmin2)

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppTypes             : IEnumServerObjectExtensionType**'''
        return super(IServerObjectAdmin6, self).GetExtensionTypes(SOTypeName)
    def get_ServerLog(self):
        '''Method IServerObjectAdmin2.get_ServerLog (from IServerObjectAdmin2)

           OUTPUT
            ppLog               : IServerLog**'''
        return super(IServerObjectAdmin6, self).get_ServerLog()
    def Enable(self):
        '''Method IServerObjectAdmin2.Enable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin6, self).Enable()
    def Disable(self):
        '''Method IServerObjectAdmin2.Disable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin6, self).Disable()
    def CreateExtensionType(self):
        '''Method IServerObjectAdmin2.CreateExtensionType (from IServerObjectAdmin2)

           OUTPUT
            ppSOEType           : IServerObjectExtensionType**'''
        return super(IServerObjectAdmin6, self).CreateExtensionType()
    def AddExtensionType(self, SOTypeName, pSOEType):
        '''Method IServerObjectAdmin2.AddExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            pSOEType            : IServerObjectExtensionType*'''
        return super(IServerObjectAdmin6, self).AddExtensionType(SOTypeName, pSOEType)
    def DeleteExtensionType(self, SOTypeName, SOETypeName):
        '''Method IServerObjectAdmin2.DeleteExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            SOETypeName         : BSTR'''
        return super(IServerObjectAdmin6, self).DeleteExtensionType(SOTypeName, SOETypeName)
    def CreateFolder(self, folderName):
        '''Method IServerObjectAdmin2.CreateFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin6, self).CreateFolder(folderName)
    def DeleteFolder(self, folderName):
        '''Method IServerObjectAdmin2.DeleteFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin6, self).DeleteFolder(folderName)
    def RenameFolder(self, folderName, newName):
        '''Method IServerObjectAdmin2.RenameFolder (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            newName             : BSTR'''
        return super(IServerObjectAdmin6, self).RenameFolder(folderName, newName)
    def GetFolders(self, folderName):
        '''Method IServerObjectAdmin2.GetFolders (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectAdmin6, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectAdmin2.get_FolderInfo (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectAdmin6, self).get_FolderInfo(folderName)
    def put_FolderInfo(self, folderName, ppInfo):
        '''Method IServerObjectAdmin2.put_FolderInfo (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            ppInfo              : IPropertySet*'''
        return super(IServerObjectAdmin6, self).put_FolderInfo(folderName, ppInfo)
    def GetConfigurationsEx(self, folderName):
        '''Method IServerObjectAdmin2.GetConfigurationsEx (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin6, self).GetConfigurationsEx(folderName)
    def ValidateConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin2.ValidateConfiguration (from IServerObjectAdmin2)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin6, self).ValidateConfiguration(Name, TypeName)
    def CreateServerDirectory(self):
        '''Method IServerObjectAdmin.CreateServerDirectory (from IServerObjectAdmin)

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin6, self).CreateServerDirectory()
    def AddServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.AddServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin6, self).AddServerDirectory(pSD)
    def UpdateServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.UpdateServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin6, self).UpdateServerDirectory(pSD)
    def DeleteServerDirectory(self, Path):
        '''Method IServerObjectAdmin.DeleteServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR'''
        return super(IServerObjectAdmin6, self).DeleteServerDirectory(Path)
    def GetServerDirectory(self, Path):
        '''Method IServerObjectAdmin.GetServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin6, self).GetServerDirectory(Path)
    def GetServerDirectories(self):
        '''Method IServerObjectAdmin.GetServerDirectories (from IServerObjectAdmin)

           OUTPUT
            ppEnum              : IEnumServerDirectory**'''
        return super(IServerObjectAdmin6, self).GetServerDirectories()
    def CreateConfiguration(self):
        '''Method IServerObjectAdmin.CreateConfiguration (from IServerObjectAdmin)

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin6, self).CreateConfiguration()
    def AddConfiguration(self, config):
        '''Method IServerObjectAdmin.AddConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin6, self).AddConfiguration(config)
    def GetConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin6, self).GetConfiguration(Name, TypeName)
    def UpdateConfiguration(self, config):
        '''Method IServerObjectAdmin.UpdateConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin6, self).UpdateConfiguration(config)
    def DeleteConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.DeleteConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin6, self).DeleteConfiguration(Name, TypeName)
    def GetConfigurations(self):
        '''Method IServerObjectAdmin.GetConfigurations (from IServerObjectAdmin)

           OUTPUT
            ppConfigs           : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin6, self).GetConfigurations()
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfigurationStatus (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectAdmin6, self).GetConfigurationStatus(Name, TypeName)
    def GetTypes(self):
        '''Method IServerObjectAdmin.GetTypes (from IServerObjectAdmin)

           OUTPUT
            ppTypes             : IEnumServerObjectType**'''
        return super(IServerObjectAdmin6, self).GetTypes()
    def StartConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StartConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin6, self).StartConfiguration(Name, TypeName)
    def StopConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StopConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin6, self).StopConfiguration(Name, TypeName)
    def PauseConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.PauseConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin6, self).PauseConfiguration(Name, TypeName)
    def CreateMachine(self):
        '''Method IServerObjectAdmin.CreateMachine (from IServerObjectAdmin)

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin6, self).CreateMachine()
    def AddMachine(self, Machine):
        '''Method IServerObjectAdmin.AddMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin6, self).AddMachine(Machine)
    def GetMachines(self):
        '''Method IServerObjectAdmin.GetMachines (from IServerObjectAdmin)

           OUTPUT
            machines            : IEnumServerMachine**'''
        return super(IServerObjectAdmin6, self).GetMachines()
    def DeleteMachine(self, MachineName):
        '''Method IServerObjectAdmin.DeleteMachine (from IServerObjectAdmin)

           INPUT
            MachineName         : BSTR'''
        return super(IServerObjectAdmin6, self).DeleteMachine(MachineName)
    def GetMachine(self, Name):
        '''Method IServerObjectAdmin.GetMachine (from IServerObjectAdmin)

           INPUT
            Name                : BSTR

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin6, self).GetMachine(Name)
    def UpdateMachine(self, Machine):
        '''Method IServerObjectAdmin.UpdateMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin6, self).UpdateMachine(Machine)
    def get_Properties(self):
        '''Method IServerObjectAdmin.get_Properties (from IServerObjectAdmin)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectAdmin6, self).get_Properties()
    def put_Properties(self, props):
        '''Method IServerObjectAdmin.put_Properties (from IServerObjectAdmin)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectAdmin6, self).put_Properties(props)
    FolderInfo = property(None, put_FolderInfo, None)
    IsSecurityEnabled = property(get_IsSecurityEnabled, put_IsSecurityEnabled, None)
    Properties = property(get_Properties, put_Properties, None)
    ServerLog = property(get_ServerLog, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class IServerObjectAdmin7(_esriServer.IServerObjectAdmin7):
    _IID = uuid.UUID('c6cfc4df-7928-4ec2-9f34-87eed2bac0a3')

    def __init__(self, *args, **kw):
        super(IServerObjectAdmin7, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def IsAdminUser(self, UserName):
        '''Method IServerObjectAdmin7.IsAdminUser

           INPUT
            UserName            : BSTR

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin7, self).IsAdminUser(UserName)
    def GetInputDir(self, cfgName, cfgType):
        '''Method IServerObjectAdmin6.GetInputDir (from IServerObjectAdmin6)

           INPUTS
            cfgName             : BSTR
            cfgType             : BSTR

           OUTPUT
            dir                 : BSTR*'''
        return super(IServerObjectAdmin7, self).GetInputDir(cfgName, cfgType)
    def IsInputDirInUse(self):
        '''Method IServerObjectAdmin6.IsInputDirInUse (from IServerObjectAdmin6)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin7, self).IsInputDirInUse()
    def UploadData(self, cfgName, cfgType, fileName, data):
        '''Method IServerObjectAdmin6.UploadData (from IServerObjectAdmin6)

           INPUTS
            cfgName             : BSTR
            cfgType             : BSTR
            fileName            : BSTR
            data                : SAFEARRAY**'''
        return super(IServerObjectAdmin7, self).UploadData(cfgName, cfgType, fileName, data)
    def GetConfigurationProperties(self, Name, Type):
        '''Method IServerObjectAdmin5.GetConfigurationProperties (from IServerObjectAdmin5)

           INPUTS
            Name                : BSTR
            Type                : BSTR

           OUTPUT
            ppProps             : IPropertySet**'''
        return super(IServerObjectAdmin7, self).GetConfigurationProperties(Name, Type)
    def UpdateConfigurationProperties(self, Name, Type, pProps):
        '''Method IServerObjectAdmin5.UpdateConfigurationProperties (from IServerObjectAdmin5)

           INPUTS
            Name                : BSTR
            Type                : BSTR
            pProps              : IPropertySet*'''
        return super(IServerObjectAdmin7, self).UpdateConfigurationProperties(Name, Type, pProps)
    def get_IsSecurityEnabled(self):
        '''Method IServerObjectAdmin4.get_IsSecurityEnabled (from IServerObjectAdmin4)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin7, self).get_IsSecurityEnabled()
    def put_IsSecurityEnabled(self, pVal):
        '''Method IServerObjectAdmin4.put_IsSecurityEnabled (from IServerObjectAdmin4)

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(IServerObjectAdmin7, self).put_IsSecurityEnabled(pVal)
    def GetConfigurationsEx2(self, folderName, stat):
        '''Method IServerObjectAdmin3.GetConfigurationsEx2 (from IServerObjectAdmin3)

           INPUTS
            folderName          : BSTR
            stat                : esriConfigurationStatus

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin7, self).GetConfigurationsEx2(folderName, stat)
    def GetExtensionTypes(self, SOTypeName):
        '''Method IServerObjectAdmin2.GetExtensionTypes (from IServerObjectAdmin2)

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppTypes             : IEnumServerObjectExtensionType**'''
        return super(IServerObjectAdmin7, self).GetExtensionTypes(SOTypeName)
    def get_ServerLog(self):
        '''Method IServerObjectAdmin2.get_ServerLog (from IServerObjectAdmin2)

           OUTPUT
            ppLog               : IServerLog**'''
        return super(IServerObjectAdmin7, self).get_ServerLog()
    def Enable(self):
        '''Method IServerObjectAdmin2.Enable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin7, self).Enable()
    def Disable(self):
        '''Method IServerObjectAdmin2.Disable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin7, self).Disable()
    def CreateExtensionType(self):
        '''Method IServerObjectAdmin2.CreateExtensionType (from IServerObjectAdmin2)

           OUTPUT
            ppSOEType           : IServerObjectExtensionType**'''
        return super(IServerObjectAdmin7, self).CreateExtensionType()
    def AddExtensionType(self, SOTypeName, pSOEType):
        '''Method IServerObjectAdmin2.AddExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            pSOEType            : IServerObjectExtensionType*'''
        return super(IServerObjectAdmin7, self).AddExtensionType(SOTypeName, pSOEType)
    def DeleteExtensionType(self, SOTypeName, SOETypeName):
        '''Method IServerObjectAdmin2.DeleteExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            SOETypeName         : BSTR'''
        return super(IServerObjectAdmin7, self).DeleteExtensionType(SOTypeName, SOETypeName)
    def CreateFolder(self, folderName):
        '''Method IServerObjectAdmin2.CreateFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin7, self).CreateFolder(folderName)
    def DeleteFolder(self, folderName):
        '''Method IServerObjectAdmin2.DeleteFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin7, self).DeleteFolder(folderName)
    def RenameFolder(self, folderName, newName):
        '''Method IServerObjectAdmin2.RenameFolder (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            newName             : BSTR'''
        return super(IServerObjectAdmin7, self).RenameFolder(folderName, newName)
    def GetFolders(self, folderName):
        '''Method IServerObjectAdmin2.GetFolders (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectAdmin7, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectAdmin2.get_FolderInfo (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectAdmin7, self).get_FolderInfo(folderName)
    def put_FolderInfo(self, folderName, ppInfo):
        '''Method IServerObjectAdmin2.put_FolderInfo (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            ppInfo              : IPropertySet*'''
        return super(IServerObjectAdmin7, self).put_FolderInfo(folderName, ppInfo)
    def GetConfigurationsEx(self, folderName):
        '''Method IServerObjectAdmin2.GetConfigurationsEx (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin7, self).GetConfigurationsEx(folderName)
    def ValidateConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin2.ValidateConfiguration (from IServerObjectAdmin2)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin7, self).ValidateConfiguration(Name, TypeName)
    def CreateServerDirectory(self):
        '''Method IServerObjectAdmin.CreateServerDirectory (from IServerObjectAdmin)

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin7, self).CreateServerDirectory()
    def AddServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.AddServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin7, self).AddServerDirectory(pSD)
    def UpdateServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.UpdateServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin7, self).UpdateServerDirectory(pSD)
    def DeleteServerDirectory(self, Path):
        '''Method IServerObjectAdmin.DeleteServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR'''
        return super(IServerObjectAdmin7, self).DeleteServerDirectory(Path)
    def GetServerDirectory(self, Path):
        '''Method IServerObjectAdmin.GetServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin7, self).GetServerDirectory(Path)
    def GetServerDirectories(self):
        '''Method IServerObjectAdmin.GetServerDirectories (from IServerObjectAdmin)

           OUTPUT
            ppEnum              : IEnumServerDirectory**'''
        return super(IServerObjectAdmin7, self).GetServerDirectories()
    def CreateConfiguration(self):
        '''Method IServerObjectAdmin.CreateConfiguration (from IServerObjectAdmin)

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin7, self).CreateConfiguration()
    def AddConfiguration(self, config):
        '''Method IServerObjectAdmin.AddConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin7, self).AddConfiguration(config)
    def GetConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin7, self).GetConfiguration(Name, TypeName)
    def UpdateConfiguration(self, config):
        '''Method IServerObjectAdmin.UpdateConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin7, self).UpdateConfiguration(config)
    def DeleteConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.DeleteConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin7, self).DeleteConfiguration(Name, TypeName)
    def GetConfigurations(self):
        '''Method IServerObjectAdmin.GetConfigurations (from IServerObjectAdmin)

           OUTPUT
            ppConfigs           : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin7, self).GetConfigurations()
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfigurationStatus (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectAdmin7, self).GetConfigurationStatus(Name, TypeName)
    def GetTypes(self):
        '''Method IServerObjectAdmin.GetTypes (from IServerObjectAdmin)

           OUTPUT
            ppTypes             : IEnumServerObjectType**'''
        return super(IServerObjectAdmin7, self).GetTypes()
    def StartConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StartConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin7, self).StartConfiguration(Name, TypeName)
    def StopConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StopConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin7, self).StopConfiguration(Name, TypeName)
    def PauseConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.PauseConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin7, self).PauseConfiguration(Name, TypeName)
    def CreateMachine(self):
        '''Method IServerObjectAdmin.CreateMachine (from IServerObjectAdmin)

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin7, self).CreateMachine()
    def AddMachine(self, Machine):
        '''Method IServerObjectAdmin.AddMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin7, self).AddMachine(Machine)
    def GetMachines(self):
        '''Method IServerObjectAdmin.GetMachines (from IServerObjectAdmin)

           OUTPUT
            machines            : IEnumServerMachine**'''
        return super(IServerObjectAdmin7, self).GetMachines()
    def DeleteMachine(self, MachineName):
        '''Method IServerObjectAdmin.DeleteMachine (from IServerObjectAdmin)

           INPUT
            MachineName         : BSTR'''
        return super(IServerObjectAdmin7, self).DeleteMachine(MachineName)
    def GetMachine(self, Name):
        '''Method IServerObjectAdmin.GetMachine (from IServerObjectAdmin)

           INPUT
            Name                : BSTR

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin7, self).GetMachine(Name)
    def UpdateMachine(self, Machine):
        '''Method IServerObjectAdmin.UpdateMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin7, self).UpdateMachine(Machine)
    def get_Properties(self):
        '''Method IServerObjectAdmin.get_Properties (from IServerObjectAdmin)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectAdmin7, self).get_Properties()
    def put_Properties(self, props):
        '''Method IServerObjectAdmin.put_Properties (from IServerObjectAdmin)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectAdmin7, self).put_Properties(props)
    FolderInfo = property(None, put_FolderInfo, None)
    IsSecurityEnabled = property(get_IsSecurityEnabled, put_IsSecurityEnabled, None)
    Properties = property(get_Properties, put_Properties, None)
    ServerLog = property(get_ServerLog, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class ISOMController(_esriServer.ISOMController):
    _IID = uuid.UUID('e869d31e-f218-4cf7-bd51-ab5424fb7fb8')
    def Start(self):
        '''Method ISOMController.Start'''
        return super(ISOMController, self).Start()
    def Stop(self):
        '''Method ISOMController.Stop'''
        return super(ISOMController, self).Stop()
    def get_Started(self):
        '''Method ISOMController.get_Started

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ISOMController, self).get_Started()
    Started = property(get_Started, None, None)

class IServerObjectType2(_esriServer.IServerObjectType2):
    _IID = uuid.UUID('42472792-5345-4b93-b132-3977c24bacb4')

    def __init__(self, *args, **kw):
        super(IServerObjectType2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_IsolationLevel(self):
        '''Method IServerObjectType2.get_IsolationLevel

           OUTPUT
            isoLevel            : esriServerIsolationLevel*'''
        return super(IServerObjectType2, self).get_IsolationLevel()
    def put_IsolationLevel(self, isoLevel):
        '''Method IServerObjectType2.put_IsolationLevel

           INPUT
            isoLevel            : esriServerIsolationLevel'''
        return super(IServerObjectType2, self).put_IsolationLevel(isoLevel)
    def get_DisplayName(self):
        '''Method IServerObjectType2.get_DisplayName

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType2, self).get_DisplayName()
    def put_DisplayName(self, pVal):
        '''Method IServerObjectType2.put_DisplayName

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType2, self).put_DisplayName(pVal)
    def get_Name(self):
        '''Method IServerObjectType.get_Name (from IServerObjectType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType2, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServerObjectType.put_Name (from IServerObjectType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType2, self).put_Name(pVal)
    def get_Description(self):
        '''Method IServerObjectType.get_Description (from IServerObjectType)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectType2, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectType.put_Description (from IServerObjectType)

           INPUT
            desc                : BSTR'''
        return super(IServerObjectType2, self).put_Description(desc)
    def get_CLSID(self):
        '''Method IServerObjectType.get_CLSID (from IServerObjectType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType2, self).get_CLSID()
    def put_CLSID(self, pVal):
        '''Method IServerObjectType.put_CLSID (from IServerObjectType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType2, self).put_CLSID(pVal)
    CLSID = property(get_CLSID, put_CLSID, None)
    Description = property(get_Description, put_Description, None)
    DisplayName = property(get_DisplayName, put_DisplayName, None)
    IsolationLevel = property(get_IsolationLevel, put_IsolationLevel, None)
    Name = property(get_Name, put_Name, None)

class IServerObjectType3(_esriServer.IServerObjectType3):
    _IID = uuid.UUID('c54dd682-295a-4f38-93e3-7da20dca88c8')

    def __init__(self, *args, **kw):
        super(IServerObjectType3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ConfigurationsLimit(self):
        '''Method IServerObjectType3.get_ConfigurationsLimit

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectType3, self).get_ConfigurationsLimit()
    def put_ConfigurationsLimit(self, pVal):
        '''Method IServerObjectType3.put_ConfigurationsLimit

           INPUT
            pVal                : long'''
        return super(IServerObjectType3, self).put_ConfigurationsLimit(pVal)
    def get_IsolationLevel(self):
        '''Method IServerObjectType2.get_IsolationLevel (from IServerObjectType2)

           OUTPUT
            isoLevel            : esriServerIsolationLevel*'''
        return super(IServerObjectType3, self).get_IsolationLevel()
    def put_IsolationLevel(self, isoLevel):
        '''Method IServerObjectType2.put_IsolationLevel (from IServerObjectType2)

           INPUT
            isoLevel            : esriServerIsolationLevel'''
        return super(IServerObjectType3, self).put_IsolationLevel(isoLevel)
    def get_DisplayName(self):
        '''Method IServerObjectType2.get_DisplayName (from IServerObjectType2)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType3, self).get_DisplayName()
    def put_DisplayName(self, pVal):
        '''Method IServerObjectType2.put_DisplayName (from IServerObjectType2)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType3, self).put_DisplayName(pVal)
    def get_Name(self):
        '''Method IServerObjectType.get_Name (from IServerObjectType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType3, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServerObjectType.put_Name (from IServerObjectType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType3, self).put_Name(pVal)
    def get_Description(self):
        '''Method IServerObjectType.get_Description (from IServerObjectType)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectType3, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectType.put_Description (from IServerObjectType)

           INPUT
            desc                : BSTR'''
        return super(IServerObjectType3, self).put_Description(desc)
    def get_CLSID(self):
        '''Method IServerObjectType.get_CLSID (from IServerObjectType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType3, self).get_CLSID()
    def put_CLSID(self, pVal):
        '''Method IServerObjectType.put_CLSID (from IServerObjectType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType3, self).put_CLSID(pVal)
    CLSID = property(get_CLSID, put_CLSID, None)
    ConfigurationsLimit = property(get_ConfigurationsLimit, put_ConfigurationsLimit, None)
    Description = property(get_Description, put_Description, None)
    DisplayName = property(get_DisplayName, put_DisplayName, None)
    IsolationLevel = property(get_IsolationLevel, put_IsolationLevel, None)
    Name = property(get_Name, put_Name, None)

class IServerObjectType4(_esriServer.IServerObjectType4):
    _IID = uuid.UUID('6640b74d-69ce-4d7f-8222-ad46936c1799')

    def __init__(self, *args, **kw):
        super(IServerObjectType4, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def putref_Info(self, props):
        '''Method IServerObjectType4.putref_Info

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectType4, self).putref_Info(props)
    def get_Info(self):
        '''Method IServerObjectType4.get_Info

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectType4, self).get_Info()
    def get_ConfigurationsLimit(self):
        '''Method IServerObjectType3.get_ConfigurationsLimit (from IServerObjectType3)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectType4, self).get_ConfigurationsLimit()
    def put_ConfigurationsLimit(self, pVal):
        '''Method IServerObjectType3.put_ConfigurationsLimit (from IServerObjectType3)

           INPUT
            pVal                : long'''
        return super(IServerObjectType4, self).put_ConfigurationsLimit(pVal)
    def get_IsolationLevel(self):
        '''Method IServerObjectType2.get_IsolationLevel (from IServerObjectType2)

           OUTPUT
            isoLevel            : esriServerIsolationLevel*'''
        return super(IServerObjectType4, self).get_IsolationLevel()
    def put_IsolationLevel(self, isoLevel):
        '''Method IServerObjectType2.put_IsolationLevel (from IServerObjectType2)

           INPUT
            isoLevel            : esriServerIsolationLevel'''
        return super(IServerObjectType4, self).put_IsolationLevel(isoLevel)
    def get_DisplayName(self):
        '''Method IServerObjectType2.get_DisplayName (from IServerObjectType2)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType4, self).get_DisplayName()
    def put_DisplayName(self, pVal):
        '''Method IServerObjectType2.put_DisplayName (from IServerObjectType2)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType4, self).put_DisplayName(pVal)
    def get_Name(self):
        '''Method IServerObjectType.get_Name (from IServerObjectType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType4, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServerObjectType.put_Name (from IServerObjectType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType4, self).put_Name(pVal)
    def get_Description(self):
        '''Method IServerObjectType.get_Description (from IServerObjectType)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectType4, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectType.put_Description (from IServerObjectType)

           INPUT
            desc                : BSTR'''
        return super(IServerObjectType4, self).put_Description(desc)
    def get_CLSID(self):
        '''Method IServerObjectType.get_CLSID (from IServerObjectType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectType4, self).get_CLSID()
    def put_CLSID(self, pVal):
        '''Method IServerObjectType.put_CLSID (from IServerObjectType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectType4, self).put_CLSID(pVal)
    CLSID = property(get_CLSID, put_CLSID, None)
    ConfigurationsLimit = property(get_ConfigurationsLimit, put_ConfigurationsLimit, None)
    Description = property(get_Description, put_Description, None)
    DisplayName = property(get_DisplayName, put_DisplayName, None)
    Info = property(get_Info, putref_Info, None)
    IsolationLevel = property(get_IsolationLevel, put_IsolationLevel, None)
    Name = property(get_Name, put_Name, None)

class IServerObjectTypeInfo2(_esriServer.IServerObjectTypeInfo2):
    _IID = uuid.UUID('9ee9aa24-dfcb-4de5-9091-fcabac13a7e1')
    def get_DisplayName(self):
        '''Method IServerObjectTypeInfo2.get_DisplayName

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectTypeInfo2, self).get_DisplayName()
    def get_Name(self):
        '''Method IServerObjectTypeInfo.get_Name (from IServerObjectTypeInfo)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectTypeInfo2, self).get_Name()
    def get_Description(self):
        '''Method IServerObjectTypeInfo.get_Description (from IServerObjectTypeInfo)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectTypeInfo2, self).get_Description()
    Description = property(get_Description, None, None)
    DisplayName = property(get_DisplayName, None, None)
    Name = property(get_Name, None, None)

class IServerObjectTypeInfo3(_esriServer.IServerObjectTypeInfo3):
    _IID = uuid.UUID('ac43c070-1627-4c6d-9532-bc80cfd82c71')
    def get_ConfigurationsLimit(self):
        '''Method IServerObjectTypeInfo3.get_ConfigurationsLimit

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectTypeInfo3, self).get_ConfigurationsLimit()
    def get_DisplayName(self):
        '''Method IServerObjectTypeInfo2.get_DisplayName (from IServerObjectTypeInfo2)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectTypeInfo3, self).get_DisplayName()
    def get_Name(self):
        '''Method IServerObjectTypeInfo.get_Name (from IServerObjectTypeInfo)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectTypeInfo3, self).get_Name()
    def get_Description(self):
        '''Method IServerObjectTypeInfo.get_Description (from IServerObjectTypeInfo)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectTypeInfo3, self).get_Description()
    ConfigurationsLimit = property(get_ConfigurationsLimit, None, None)
    Description = property(get_Description, None, None)
    DisplayName = property(get_DisplayName, None, None)
    Name = property(get_Name, None, None)

class IServerObjectExtensionType2(_esriServer.IServerObjectExtensionType2):
    _IID = uuid.UUID('552accd0-d000-49a7-beef-bf9849b22141')

    def __init__(self, *args, **kw):
        super(IServerObjectExtensionType2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_DisplayName(self):
        '''Method IServerObjectExtensionType2.get_DisplayName

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionType2, self).get_DisplayName()
    def put_DisplayName(self, pVal):
        '''Method IServerObjectExtensionType2.put_DisplayName

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectExtensionType2, self).put_DisplayName(pVal)
    def get_Name(self):
        '''Method IServerObjectExtensionType.get_Name (from IServerObjectExtensionType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionType2, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServerObjectExtensionType.put_Name (from IServerObjectExtensionType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectExtensionType2, self).put_Name(pVal)
    def get_Description(self):
        '''Method IServerObjectExtensionType.get_Description (from IServerObjectExtensionType)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectExtensionType2, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectExtensionType.put_Description (from IServerObjectExtensionType)

           INPUT
            desc                : BSTR'''
        return super(IServerObjectExtensionType2, self).put_Description(desc)
    def get_CLSID(self):
        '''Method IServerObjectExtensionType.get_CLSID (from IServerObjectExtensionType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionType2, self).get_CLSID()
    def put_CLSID(self, pVal):
        '''Method IServerObjectExtensionType.put_CLSID (from IServerObjectExtensionType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectExtensionType2, self).put_CLSID(pVal)
    CLSID = property(get_CLSID, put_CLSID, None)
    Description = property(get_Description, put_Description, None)
    DisplayName = property(get_DisplayName, put_DisplayName, None)
    Name = property(get_Name, put_Name, None)

class IServerObjectExtensionTypeInfo2(_esriServer.IServerObjectExtensionTypeInfo2):
    _IID = uuid.UUID('94d56c57-00df-4336-8707-cf4197a890ef')
    def get_DisplayName(self):
        '''Method IServerObjectExtensionTypeInfo2.get_DisplayName

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionTypeInfo2, self).get_DisplayName()
    def get_Name(self):
        '''Method IServerObjectExtensionTypeInfo.get_Name (from IServerObjectExtensionTypeInfo)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectExtensionTypeInfo2, self).get_Name()
    def get_Description(self):
        '''Method IServerObjectExtensionTypeInfo.get_Description (from IServerObjectExtensionTypeInfo)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectExtensionTypeInfo2, self).get_Description()
    Description = property(get_Description, None, None)
    DisplayName = property(get_DisplayName, None, None)
    Name = property(get_Name, None, None)

class IServerObjectConfiguration2(_esriServer.IServerObjectConfiguration2):
    _IID = uuid.UUID('2d81b707-95b1-4efa-a0fa-5ab49b051d0b')

    def __init__(self, *args, **kw):
        super(IServerObjectConfiguration2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def Serialize(self):
        '''Method IServerObjectConfiguration2.Serialize

           OUTPUT
            str                 : BSTR*'''
        return super(IServerObjectConfiguration2, self).Serialize()
    def Deserialize(self, str):
        '''Method IServerObjectConfiguration2.Deserialize

           INPUT
            str                 : BSTR'''
        return super(IServerObjectConfiguration2, self).Deserialize(str)
    def get_ExtensionProperties(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionProperties

           INPUT
            Name                : BSTR

           OUTPUT
            ppExtProperties     : IPropertySet**'''
        return super(IServerObjectConfiguration2, self).get_ExtensionProperties(Name)
    def putref_ExtensionProperties(self, Name, ppExtProperties):
        '''Method IServerObjectConfiguration2.putref_ExtensionProperties

           INPUTS
            Name                : BSTR
            ppExtProperties     : IPropertySet*'''
        return super(IServerObjectConfiguration2, self).putref_ExtensionProperties(Name, ppExtProperties)
    def get_ExtensionInfo(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionInfo

           INPUT
            Name                : BSTR

           OUTPUT
            ppExtProperties     : IPropertySet**'''
        return super(IServerObjectConfiguration2, self).get_ExtensionInfo(Name)
    def putref_ExtensionInfo(self, Name, ppExtProperties):
        '''Method IServerObjectConfiguration2.putref_ExtensionInfo

           INPUTS
            Name                : BSTR
            ppExtProperties     : IPropertySet*'''
        return super(IServerObjectConfiguration2, self).putref_ExtensionInfo(Name, ppExtProperties)
    def get_ExtensionEnabled(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionEnabled

           INPUT
            Name                : BSTR

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectConfiguration2, self).get_ExtensionEnabled(Name)
    def put_ExtensionEnabled(self, Name, pVal):
        '''Method IServerObjectConfiguration2.put_ExtensionEnabled

           INPUTS
            Name                : BSTR
            pVal                : VARIANT_BOOL'''
        return super(IServerObjectConfiguration2, self).put_ExtensionEnabled(Name, pVal)
    def get_CleanupTimeout(self):
        '''Method IServerObjectConfiguration2.get_CleanupTimeout

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration2, self).get_CleanupTimeout()
    def put_CleanupTimeout(self, pVal):
        '''Method IServerObjectConfiguration2.put_CleanupTimeout

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration2, self).put_CleanupTimeout(pVal)
    def get_StartupTimeout(self):
        '''Method IServerObjectConfiguration2.get_StartupTimeout

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration2, self).get_StartupTimeout()
    def put_StartupTimeout(self, pVal):
        '''Method IServerObjectConfiguration2.put_StartupTimeout

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration2, self).put_StartupTimeout(pVal)
    def get_Info(self):
        '''Method IServerObjectConfiguration2.get_Info

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration2, self).get_Info()
    def putref_Info(self, props):
        '''Method IServerObjectConfiguration2.putref_Info

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration2, self).putref_Info(props)
    def get_Name(self):
        '''Method IServerObjectConfiguration.get_Name (from IServerObjectConfiguration)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectConfiguration2, self).get_Name()
    def put_Name(self, Name):
        '''Method IServerObjectConfiguration.put_Name (from IServerObjectConfiguration)

           INPUT
            Name                : BSTR'''
        return super(IServerObjectConfiguration2, self).put_Name(Name)
    def get_TypeName(self):
        '''Method IServerObjectConfiguration.get_TypeName (from IServerObjectConfiguration)

           OUTPUT
            TypeName            : BSTR*'''
        return super(IServerObjectConfiguration2, self).get_TypeName()
    def put_TypeName(self, TypeName):
        '''Method IServerObjectConfiguration.put_TypeName (from IServerObjectConfiguration)

           INPUT
            TypeName            : BSTR'''
        return super(IServerObjectConfiguration2, self).put_TypeName(TypeName)
    def get_Description(self):
        '''Method IServerObjectConfiguration.get_Description (from IServerObjectConfiguration)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectConfiguration2, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectConfiguration.put_Description (from IServerObjectConfiguration)

           INPUT
            desc                : BSTR'''
        return super(IServerObjectConfiguration2, self).put_Description(desc)
    def get_Properties(self):
        '''Method IServerObjectConfiguration.get_Properties (from IServerObjectConfiguration)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration2, self).get_Properties()
    def putref_Properties(self, props):
        '''Method IServerObjectConfiguration.putref_Properties (from IServerObjectConfiguration)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration2, self).putref_Properties(props)
    def get_RecycleProperties(self):
        '''Method IServerObjectConfiguration.get_RecycleProperties (from IServerObjectConfiguration)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration2, self).get_RecycleProperties()
    def putref_RecycleProperties(self, props):
        '''Method IServerObjectConfiguration.putref_RecycleProperties (from IServerObjectConfiguration)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration2, self).putref_RecycleProperties(props)
    def get_MinInstances(self):
        '''Method IServerObjectConfiguration.get_MinInstances (from IServerObjectConfiguration)

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration2, self).get_MinInstances()
    def put_MinInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MinInstances (from IServerObjectConfiguration)

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration2, self).put_MinInstances(instances)
    def get_MaxInstances(self):
        '''Method IServerObjectConfiguration.get_MaxInstances (from IServerObjectConfiguration)

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration2, self).get_MaxInstances()
    def put_MaxInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MaxInstances (from IServerObjectConfiguration)

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration2, self).put_MaxInstances(instances)
    def get_IsPooled(self):
        '''Method IServerObjectConfiguration.get_IsPooled (from IServerObjectConfiguration)

           OUTPUT
            IsPooled            : VARIANT_BOOL*'''
        return super(IServerObjectConfiguration2, self).get_IsPooled()
    def put_IsPooled(self, IsPooled):
        '''Method IServerObjectConfiguration.put_IsPooled (from IServerObjectConfiguration)

           INPUT
            IsPooled            : VARIANT_BOOL'''
        return super(IServerObjectConfiguration2, self).put_IsPooled(IsPooled)
    def get_IsolationLevel(self):
        '''Method IServerObjectConfiguration.get_IsolationLevel (from IServerObjectConfiguration)

           OUTPUT
            isoLevel            : esriServerIsolationLevel*'''
        return super(IServerObjectConfiguration2, self).get_IsolationLevel()
    def put_IsolationLevel(self, isoLevel):
        '''Method IServerObjectConfiguration.put_IsolationLevel (from IServerObjectConfiguration)

           INPUT
            isoLevel            : esriServerIsolationLevel'''
        return super(IServerObjectConfiguration2, self).put_IsolationLevel(isoLevel)
    def get_StartupType(self):
        '''Method IServerObjectConfiguration.get_StartupType (from IServerObjectConfiguration)

           OUTPUT
            Type                : esriStartupType*'''
        return super(IServerObjectConfiguration2, self).get_StartupType()
    def put_StartupType(self, Type):
        '''Method IServerObjectConfiguration.put_StartupType (from IServerObjectConfiguration)

           INPUT
            Type                : esriStartupType'''
        return super(IServerObjectConfiguration2, self).put_StartupType(Type)
    def get_WaitTimeout(self):
        '''Method IServerObjectConfiguration.get_WaitTimeout (from IServerObjectConfiguration)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration2, self).get_WaitTimeout()
    def put_WaitTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_WaitTimeout (from IServerObjectConfiguration)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration2, self).put_WaitTimeout(pVal)
    def get_UsageTimeout(self):
        '''Method IServerObjectConfiguration.get_UsageTimeout (from IServerObjectConfiguration)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration2, self).get_UsageTimeout()
    def put_UsageTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_UsageTimeout (from IServerObjectConfiguration)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration2, self).put_UsageTimeout(pVal)
    CleanupTimeout = property(get_CleanupTimeout, put_CleanupTimeout, None)
    Description = property(get_Description, put_Description, None)
    ExtensionEnabled = property(None, put_ExtensionEnabled, None)
    ExtensionInfo = property(None, putref_ExtensionInfo, None)
    ExtensionProperties = property(None, putref_ExtensionProperties, None)
    Info = property(get_Info, putref_Info, None)
    IsPooled = property(get_IsPooled, put_IsPooled, None)
    IsolationLevel = property(get_IsolationLevel, put_IsolationLevel, None)
    MaxInstances = property(get_MaxInstances, put_MaxInstances, None)
    MinInstances = property(get_MinInstances, put_MinInstances, None)
    Name = property(get_Name, put_Name, None)
    Properties = property(get_Properties, putref_Properties, None)
    RecycleProperties = property(get_RecycleProperties, putref_RecycleProperties, None)
    StartupTimeout = property(get_StartupTimeout, put_StartupTimeout, None)
    StartupType = property(get_StartupType, put_StartupType, None)
    TypeName = property(get_TypeName, put_TypeName, None)
    UsageTimeout = property(get_UsageTimeout, put_UsageTimeout, None)
    WaitTimeout = property(get_WaitTimeout, put_WaitTimeout, None)
    ExtensionEnabled = IndexProperty(get_ExtensionEnabled, None)
    ExtensionInfo = IndexProperty(get_ExtensionInfo, None)
    ExtensionProperties = IndexProperty(get_ExtensionProperties, None)

class IServerObjectConfiguration3(_esriServer.IServerObjectConfiguration3):
    _IID = uuid.UUID('35bcf76e-686f-4cb2-b0b8-f615754e79d3')

    def __init__(self, *args, **kw):
        super(IServerObjectConfiguration3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_IdleTimeout(self):
        '''Method IServerObjectConfiguration3.get_IdleTimeout

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration3, self).get_IdleTimeout()
    def put_IdleTimeout(self, pVal):
        '''Method IServerObjectConfiguration3.put_IdleTimeout

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration3, self).put_IdleTimeout(pVal)
    def get_InstancesPerContainer(self):
        '''Method IServerObjectConfiguration3.get_InstancesPerContainer

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration3, self).get_InstancesPerContainer()
    def put_InstancesPerContainer(self, pVal):
        '''Method IServerObjectConfiguration3.put_InstancesPerContainer

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration3, self).put_InstancesPerContainer(pVal)
    def Serialize(self):
        '''Method IServerObjectConfiguration2.Serialize (from IServerObjectConfiguration2)

           OUTPUT
            str                 : BSTR*'''
        return super(IServerObjectConfiguration3, self).Serialize()
    def Deserialize(self, str):
        '''Method IServerObjectConfiguration2.Deserialize (from IServerObjectConfiguration2)

           INPUT
            str                 : BSTR'''
        return super(IServerObjectConfiguration3, self).Deserialize(str)
    def get_ExtensionProperties(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionProperties (from IServerObjectConfiguration2)

           INPUT
            Name                : BSTR

           OUTPUT
            ppExtProperties     : IPropertySet**'''
        return super(IServerObjectConfiguration3, self).get_ExtensionProperties(Name)
    def putref_ExtensionProperties(self, Name, ppExtProperties):
        '''Method IServerObjectConfiguration2.putref_ExtensionProperties (from IServerObjectConfiguration2)

           INPUTS
            Name                : BSTR
            ppExtProperties     : IPropertySet*'''
        return super(IServerObjectConfiguration3, self).putref_ExtensionProperties(Name, ppExtProperties)
    def get_ExtensionInfo(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionInfo (from IServerObjectConfiguration2)

           INPUT
            Name                : BSTR

           OUTPUT
            ppExtProperties     : IPropertySet**'''
        return super(IServerObjectConfiguration3, self).get_ExtensionInfo(Name)
    def putref_ExtensionInfo(self, Name, ppExtProperties):
        '''Method IServerObjectConfiguration2.putref_ExtensionInfo (from IServerObjectConfiguration2)

           INPUTS
            Name                : BSTR
            ppExtProperties     : IPropertySet*'''
        return super(IServerObjectConfiguration3, self).putref_ExtensionInfo(Name, ppExtProperties)
    def get_ExtensionEnabled(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionEnabled (from IServerObjectConfiguration2)

           INPUT
            Name                : BSTR

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectConfiguration3, self).get_ExtensionEnabled(Name)
    def put_ExtensionEnabled(self, Name, pVal):
        '''Method IServerObjectConfiguration2.put_ExtensionEnabled (from IServerObjectConfiguration2)

           INPUTS
            Name                : BSTR
            pVal                : VARIANT_BOOL'''
        return super(IServerObjectConfiguration3, self).put_ExtensionEnabled(Name, pVal)
    def get_CleanupTimeout(self):
        '''Method IServerObjectConfiguration2.get_CleanupTimeout (from IServerObjectConfiguration2)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration3, self).get_CleanupTimeout()
    def put_CleanupTimeout(self, pVal):
        '''Method IServerObjectConfiguration2.put_CleanupTimeout (from IServerObjectConfiguration2)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration3, self).put_CleanupTimeout(pVal)
    def get_StartupTimeout(self):
        '''Method IServerObjectConfiguration2.get_StartupTimeout (from IServerObjectConfiguration2)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration3, self).get_StartupTimeout()
    def put_StartupTimeout(self, pVal):
        '''Method IServerObjectConfiguration2.put_StartupTimeout (from IServerObjectConfiguration2)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration3, self).put_StartupTimeout(pVal)
    def get_Info(self):
        '''Method IServerObjectConfiguration2.get_Info (from IServerObjectConfiguration2)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration3, self).get_Info()
    def putref_Info(self, props):
        '''Method IServerObjectConfiguration2.putref_Info (from IServerObjectConfiguration2)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration3, self).putref_Info(props)
    def get_Name(self):
        '''Method IServerObjectConfiguration.get_Name (from IServerObjectConfiguration)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectConfiguration3, self).get_Name()
    def put_Name(self, Name):
        '''Method IServerObjectConfiguration.put_Name (from IServerObjectConfiguration)

           INPUT
            Name                : BSTR'''
        return super(IServerObjectConfiguration3, self).put_Name(Name)
    def get_TypeName(self):
        '''Method IServerObjectConfiguration.get_TypeName (from IServerObjectConfiguration)

           OUTPUT
            TypeName            : BSTR*'''
        return super(IServerObjectConfiguration3, self).get_TypeName()
    def put_TypeName(self, TypeName):
        '''Method IServerObjectConfiguration.put_TypeName (from IServerObjectConfiguration)

           INPUT
            TypeName            : BSTR'''
        return super(IServerObjectConfiguration3, self).put_TypeName(TypeName)
    def get_Description(self):
        '''Method IServerObjectConfiguration.get_Description (from IServerObjectConfiguration)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectConfiguration3, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectConfiguration.put_Description (from IServerObjectConfiguration)

           INPUT
            desc                : BSTR'''
        return super(IServerObjectConfiguration3, self).put_Description(desc)
    def get_Properties(self):
        '''Method IServerObjectConfiguration.get_Properties (from IServerObjectConfiguration)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration3, self).get_Properties()
    def putref_Properties(self, props):
        '''Method IServerObjectConfiguration.putref_Properties (from IServerObjectConfiguration)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration3, self).putref_Properties(props)
    def get_RecycleProperties(self):
        '''Method IServerObjectConfiguration.get_RecycleProperties (from IServerObjectConfiguration)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration3, self).get_RecycleProperties()
    def putref_RecycleProperties(self, props):
        '''Method IServerObjectConfiguration.putref_RecycleProperties (from IServerObjectConfiguration)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration3, self).putref_RecycleProperties(props)
    def get_MinInstances(self):
        '''Method IServerObjectConfiguration.get_MinInstances (from IServerObjectConfiguration)

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration3, self).get_MinInstances()
    def put_MinInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MinInstances (from IServerObjectConfiguration)

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration3, self).put_MinInstances(instances)
    def get_MaxInstances(self):
        '''Method IServerObjectConfiguration.get_MaxInstances (from IServerObjectConfiguration)

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration3, self).get_MaxInstances()
    def put_MaxInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MaxInstances (from IServerObjectConfiguration)

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration3, self).put_MaxInstances(instances)
    def get_IsPooled(self):
        '''Method IServerObjectConfiguration.get_IsPooled (from IServerObjectConfiguration)

           OUTPUT
            IsPooled            : VARIANT_BOOL*'''
        return super(IServerObjectConfiguration3, self).get_IsPooled()
    def put_IsPooled(self, IsPooled):
        '''Method IServerObjectConfiguration.put_IsPooled (from IServerObjectConfiguration)

           INPUT
            IsPooled            : VARIANT_BOOL'''
        return super(IServerObjectConfiguration3, self).put_IsPooled(IsPooled)
    def get_IsolationLevel(self):
        '''Method IServerObjectConfiguration.get_IsolationLevel (from IServerObjectConfiguration)

           OUTPUT
            isoLevel            : esriServerIsolationLevel*'''
        return super(IServerObjectConfiguration3, self).get_IsolationLevel()
    def put_IsolationLevel(self, isoLevel):
        '''Method IServerObjectConfiguration.put_IsolationLevel (from IServerObjectConfiguration)

           INPUT
            isoLevel            : esriServerIsolationLevel'''
        return super(IServerObjectConfiguration3, self).put_IsolationLevel(isoLevel)
    def get_StartupType(self):
        '''Method IServerObjectConfiguration.get_StartupType (from IServerObjectConfiguration)

           OUTPUT
            Type                : esriStartupType*'''
        return super(IServerObjectConfiguration3, self).get_StartupType()
    def put_StartupType(self, Type):
        '''Method IServerObjectConfiguration.put_StartupType (from IServerObjectConfiguration)

           INPUT
            Type                : esriStartupType'''
        return super(IServerObjectConfiguration3, self).put_StartupType(Type)
    def get_WaitTimeout(self):
        '''Method IServerObjectConfiguration.get_WaitTimeout (from IServerObjectConfiguration)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration3, self).get_WaitTimeout()
    def put_WaitTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_WaitTimeout (from IServerObjectConfiguration)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration3, self).put_WaitTimeout(pVal)
    def get_UsageTimeout(self):
        '''Method IServerObjectConfiguration.get_UsageTimeout (from IServerObjectConfiguration)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration3, self).get_UsageTimeout()
    def put_UsageTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_UsageTimeout (from IServerObjectConfiguration)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration3, self).put_UsageTimeout(pVal)
    CleanupTimeout = property(get_CleanupTimeout, put_CleanupTimeout, None)
    Description = property(get_Description, put_Description, None)
    ExtensionEnabled = property(None, put_ExtensionEnabled, None)
    ExtensionInfo = property(None, putref_ExtensionInfo, None)
    ExtensionProperties = property(None, putref_ExtensionProperties, None)
    IdleTimeout = property(get_IdleTimeout, put_IdleTimeout, None)
    Info = property(get_Info, putref_Info, None)
    InstancesPerContainer = property(get_InstancesPerContainer, put_InstancesPerContainer, None)
    IsPooled = property(get_IsPooled, put_IsPooled, None)
    IsolationLevel = property(get_IsolationLevel, put_IsolationLevel, None)
    MaxInstances = property(get_MaxInstances, put_MaxInstances, None)
    MinInstances = property(get_MinInstances, put_MinInstances, None)
    Name = property(get_Name, put_Name, None)
    Properties = property(get_Properties, putref_Properties, None)
    RecycleProperties = property(get_RecycleProperties, putref_RecycleProperties, None)
    StartupTimeout = property(get_StartupTimeout, put_StartupTimeout, None)
    StartupType = property(get_StartupType, put_StartupType, None)
    TypeName = property(get_TypeName, put_TypeName, None)
    UsageTimeout = property(get_UsageTimeout, put_UsageTimeout, None)
    WaitTimeout = property(get_WaitTimeout, put_WaitTimeout, None)
    ExtensionEnabled = IndexProperty(get_ExtensionEnabled, None)
    ExtensionInfo = IndexProperty(get_ExtensionInfo, None)
    ExtensionProperties = IndexProperty(get_ExtensionProperties, None)

class IServerObjectConfiguration4(_esriServer.IServerObjectConfiguration4):
    _IID = uuid.UUID('ac7687e9-a00e-4281-abaa-b889a5d7b1a6')

    def __init__(self, *args, **kw):
        super(IServerObjectConfiguration4, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ServiceKeepAliveInterval(self):
        '''Method IServerObjectConfiguration4.get_ServiceKeepAliveInterval

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration4, self).get_ServiceKeepAliveInterval()
    def put_ServiceKeepAliveInterval(self, pVal):
        '''Method IServerObjectConfiguration4.put_ServiceKeepAliveInterval

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration4, self).put_ServiceKeepAliveInterval(pVal)
    def get_IdleTimeout(self):
        '''Method IServerObjectConfiguration3.get_IdleTimeout (from IServerObjectConfiguration3)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration4, self).get_IdleTimeout()
    def put_IdleTimeout(self, pVal):
        '''Method IServerObjectConfiguration3.put_IdleTimeout (from IServerObjectConfiguration3)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration4, self).put_IdleTimeout(pVal)
    def get_InstancesPerContainer(self):
        '''Method IServerObjectConfiguration3.get_InstancesPerContainer (from IServerObjectConfiguration3)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration4, self).get_InstancesPerContainer()
    def put_InstancesPerContainer(self, pVal):
        '''Method IServerObjectConfiguration3.put_InstancesPerContainer (from IServerObjectConfiguration3)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration4, self).put_InstancesPerContainer(pVal)
    def Serialize(self):
        '''Method IServerObjectConfiguration2.Serialize (from IServerObjectConfiguration2)

           OUTPUT
            str                 : BSTR*'''
        return super(IServerObjectConfiguration4, self).Serialize()
    def Deserialize(self, str):
        '''Method IServerObjectConfiguration2.Deserialize (from IServerObjectConfiguration2)

           INPUT
            str                 : BSTR'''
        return super(IServerObjectConfiguration4, self).Deserialize(str)
    def get_ExtensionProperties(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionProperties (from IServerObjectConfiguration2)

           INPUT
            Name                : BSTR

           OUTPUT
            ppExtProperties     : IPropertySet**'''
        return super(IServerObjectConfiguration4, self).get_ExtensionProperties(Name)
    def putref_ExtensionProperties(self, Name, ppExtProperties):
        '''Method IServerObjectConfiguration2.putref_ExtensionProperties (from IServerObjectConfiguration2)

           INPUTS
            Name                : BSTR
            ppExtProperties     : IPropertySet*'''
        return super(IServerObjectConfiguration4, self).putref_ExtensionProperties(Name, ppExtProperties)
    def get_ExtensionInfo(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionInfo (from IServerObjectConfiguration2)

           INPUT
            Name                : BSTR

           OUTPUT
            ppExtProperties     : IPropertySet**'''
        return super(IServerObjectConfiguration4, self).get_ExtensionInfo(Name)
    def putref_ExtensionInfo(self, Name, ppExtProperties):
        '''Method IServerObjectConfiguration2.putref_ExtensionInfo (from IServerObjectConfiguration2)

           INPUTS
            Name                : BSTR
            ppExtProperties     : IPropertySet*'''
        return super(IServerObjectConfiguration4, self).putref_ExtensionInfo(Name, ppExtProperties)
    def get_ExtensionEnabled(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionEnabled (from IServerObjectConfiguration2)

           INPUT
            Name                : BSTR

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectConfiguration4, self).get_ExtensionEnabled(Name)
    def put_ExtensionEnabled(self, Name, pVal):
        '''Method IServerObjectConfiguration2.put_ExtensionEnabled (from IServerObjectConfiguration2)

           INPUTS
            Name                : BSTR
            pVal                : VARIANT_BOOL'''
        return super(IServerObjectConfiguration4, self).put_ExtensionEnabled(Name, pVal)
    def get_CleanupTimeout(self):
        '''Method IServerObjectConfiguration2.get_CleanupTimeout (from IServerObjectConfiguration2)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration4, self).get_CleanupTimeout()
    def put_CleanupTimeout(self, pVal):
        '''Method IServerObjectConfiguration2.put_CleanupTimeout (from IServerObjectConfiguration2)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration4, self).put_CleanupTimeout(pVal)
    def get_StartupTimeout(self):
        '''Method IServerObjectConfiguration2.get_StartupTimeout (from IServerObjectConfiguration2)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration4, self).get_StartupTimeout()
    def put_StartupTimeout(self, pVal):
        '''Method IServerObjectConfiguration2.put_StartupTimeout (from IServerObjectConfiguration2)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration4, self).put_StartupTimeout(pVal)
    def get_Info(self):
        '''Method IServerObjectConfiguration2.get_Info (from IServerObjectConfiguration2)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration4, self).get_Info()
    def putref_Info(self, props):
        '''Method IServerObjectConfiguration2.putref_Info (from IServerObjectConfiguration2)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration4, self).putref_Info(props)
    def get_Name(self):
        '''Method IServerObjectConfiguration.get_Name (from IServerObjectConfiguration)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectConfiguration4, self).get_Name()
    def put_Name(self, Name):
        '''Method IServerObjectConfiguration.put_Name (from IServerObjectConfiguration)

           INPUT
            Name                : BSTR'''
        return super(IServerObjectConfiguration4, self).put_Name(Name)
    def get_TypeName(self):
        '''Method IServerObjectConfiguration.get_TypeName (from IServerObjectConfiguration)

           OUTPUT
            TypeName            : BSTR*'''
        return super(IServerObjectConfiguration4, self).get_TypeName()
    def put_TypeName(self, TypeName):
        '''Method IServerObjectConfiguration.put_TypeName (from IServerObjectConfiguration)

           INPUT
            TypeName            : BSTR'''
        return super(IServerObjectConfiguration4, self).put_TypeName(TypeName)
    def get_Description(self):
        '''Method IServerObjectConfiguration.get_Description (from IServerObjectConfiguration)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectConfiguration4, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectConfiguration.put_Description (from IServerObjectConfiguration)

           INPUT
            desc                : BSTR'''
        return super(IServerObjectConfiguration4, self).put_Description(desc)
    def get_Properties(self):
        '''Method IServerObjectConfiguration.get_Properties (from IServerObjectConfiguration)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration4, self).get_Properties()
    def putref_Properties(self, props):
        '''Method IServerObjectConfiguration.putref_Properties (from IServerObjectConfiguration)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration4, self).putref_Properties(props)
    def get_RecycleProperties(self):
        '''Method IServerObjectConfiguration.get_RecycleProperties (from IServerObjectConfiguration)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration4, self).get_RecycleProperties()
    def putref_RecycleProperties(self, props):
        '''Method IServerObjectConfiguration.putref_RecycleProperties (from IServerObjectConfiguration)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration4, self).putref_RecycleProperties(props)
    def get_MinInstances(self):
        '''Method IServerObjectConfiguration.get_MinInstances (from IServerObjectConfiguration)

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration4, self).get_MinInstances()
    def put_MinInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MinInstances (from IServerObjectConfiguration)

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration4, self).put_MinInstances(instances)
    def get_MaxInstances(self):
        '''Method IServerObjectConfiguration.get_MaxInstances (from IServerObjectConfiguration)

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration4, self).get_MaxInstances()
    def put_MaxInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MaxInstances (from IServerObjectConfiguration)

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration4, self).put_MaxInstances(instances)
    def get_IsPooled(self):
        '''Method IServerObjectConfiguration.get_IsPooled (from IServerObjectConfiguration)

           OUTPUT
            IsPooled            : VARIANT_BOOL*'''
        return super(IServerObjectConfiguration4, self).get_IsPooled()
    def put_IsPooled(self, IsPooled):
        '''Method IServerObjectConfiguration.put_IsPooled (from IServerObjectConfiguration)

           INPUT
            IsPooled            : VARIANT_BOOL'''
        return super(IServerObjectConfiguration4, self).put_IsPooled(IsPooled)
    def get_IsolationLevel(self):
        '''Method IServerObjectConfiguration.get_IsolationLevel (from IServerObjectConfiguration)

           OUTPUT
            isoLevel            : esriServerIsolationLevel*'''
        return super(IServerObjectConfiguration4, self).get_IsolationLevel()
    def put_IsolationLevel(self, isoLevel):
        '''Method IServerObjectConfiguration.put_IsolationLevel (from IServerObjectConfiguration)

           INPUT
            isoLevel            : esriServerIsolationLevel'''
        return super(IServerObjectConfiguration4, self).put_IsolationLevel(isoLevel)
    def get_StartupType(self):
        '''Method IServerObjectConfiguration.get_StartupType (from IServerObjectConfiguration)

           OUTPUT
            Type                : esriStartupType*'''
        return super(IServerObjectConfiguration4, self).get_StartupType()
    def put_StartupType(self, Type):
        '''Method IServerObjectConfiguration.put_StartupType (from IServerObjectConfiguration)

           INPUT
            Type                : esriStartupType'''
        return super(IServerObjectConfiguration4, self).put_StartupType(Type)
    def get_WaitTimeout(self):
        '''Method IServerObjectConfiguration.get_WaitTimeout (from IServerObjectConfiguration)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration4, self).get_WaitTimeout()
    def put_WaitTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_WaitTimeout (from IServerObjectConfiguration)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration4, self).put_WaitTimeout(pVal)
    def get_UsageTimeout(self):
        '''Method IServerObjectConfiguration.get_UsageTimeout (from IServerObjectConfiguration)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration4, self).get_UsageTimeout()
    def put_UsageTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_UsageTimeout (from IServerObjectConfiguration)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration4, self).put_UsageTimeout(pVal)
    CleanupTimeout = property(get_CleanupTimeout, put_CleanupTimeout, None)
    Description = property(get_Description, put_Description, None)
    ExtensionEnabled = property(None, put_ExtensionEnabled, None)
    ExtensionInfo = property(None, putref_ExtensionInfo, None)
    ExtensionProperties = property(None, putref_ExtensionProperties, None)
    IdleTimeout = property(get_IdleTimeout, put_IdleTimeout, None)
    Info = property(get_Info, putref_Info, None)
    InstancesPerContainer = property(get_InstancesPerContainer, put_InstancesPerContainer, None)
    IsPooled = property(get_IsPooled, put_IsPooled, None)
    IsolationLevel = property(get_IsolationLevel, put_IsolationLevel, None)
    MaxInstances = property(get_MaxInstances, put_MaxInstances, None)
    MinInstances = property(get_MinInstances, put_MinInstances, None)
    Name = property(get_Name, put_Name, None)
    Properties = property(get_Properties, putref_Properties, None)
    RecycleProperties = property(get_RecycleProperties, putref_RecycleProperties, None)
    ServiceKeepAliveInterval = property(get_ServiceKeepAliveInterval, put_ServiceKeepAliveInterval, None)
    StartupTimeout = property(get_StartupTimeout, put_StartupTimeout, None)
    StartupType = property(get_StartupType, put_StartupType, None)
    TypeName = property(get_TypeName, put_TypeName, None)
    UsageTimeout = property(get_UsageTimeout, put_UsageTimeout, None)
    WaitTimeout = property(get_WaitTimeout, put_WaitTimeout, None)
    ExtensionEnabled = IndexProperty(get_ExtensionEnabled, None)
    ExtensionInfo = IndexProperty(get_ExtensionInfo, None)
    ExtensionProperties = IndexProperty(get_ExtensionProperties, None)

class IServerObjectConfiguration5(_esriServer.IServerObjectConfiguration5):
    _IID = uuid.UUID('6ca0fe13-3acf-49e5-9632-2381a96ca0ae')

    def __init__(self, *args, **kw):
        super(IServerObjectConfiguration5, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Status(self, pStatus):
        '''Method IServerObjectConfiguration5.put_Status

           INPUT
            pStatus             : esriConfigurationStatus'''
        return super(IServerObjectConfiguration5, self).put_Status(pStatus)
    def get_Status(self):
        '''Method IServerObjectConfiguration5.get_Status

           OUTPUT
            pStatus             : esriConfigurationStatus*'''
        return super(IServerObjectConfiguration5, self).get_Status()
    def get_ExtensionNames(self):
        '''Method IServerObjectConfiguration5.get_ExtensionNames

           OUTPUT
            ppExtNames          : IStringArray**'''
        return super(IServerObjectConfiguration5, self).get_ExtensionNames()
    def put_DatasetNames(self, ppDTNames):
        '''Method IServerObjectConfiguration5.put_DatasetNames

           INPUT
            ppDTNames           : IStringArray*'''
        return super(IServerObjectConfiguration5, self).put_DatasetNames(ppDTNames)
    def get_DatasetNames(self):
        '''Method IServerObjectConfiguration5.get_DatasetNames

           OUTPUT
            ppDTNames           : IStringArray**'''
        return super(IServerObjectConfiguration5, self).get_DatasetNames()
    def put_TargetCluster(self, pName):
        '''Method IServerObjectConfiguration5.put_TargetCluster

           INPUT
            pName               : BSTR'''
        return super(IServerObjectConfiguration5, self).put_TargetCluster(pName)
    def get_TargetCluster(self):
        '''Method IServerObjectConfiguration5.get_TargetCluster

           OUTPUT
            pName               : BSTR*'''
        return super(IServerObjectConfiguration5, self).get_TargetCluster()
    def put_LoadBalancing(self, pType):
        '''Method IServerObjectConfiguration5.put_LoadBalancing

           INPUT
            pType               : esriLoadBalancing'''
        return super(IServerObjectConfiguration5, self).put_LoadBalancing(pType)
    def get_LoadBalancing(self):
        '''Method IServerObjectConfiguration5.get_LoadBalancing

           OUTPUT
            pType               : esriLoadBalancing*'''
        return super(IServerObjectConfiguration5, self).get_LoadBalancing()
    def get_ServiceKeepAliveInterval(self):
        '''Method IServerObjectConfiguration4.get_ServiceKeepAliveInterval (from IServerObjectConfiguration4)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration5, self).get_ServiceKeepAliveInterval()
    def put_ServiceKeepAliveInterval(self, pVal):
        '''Method IServerObjectConfiguration4.put_ServiceKeepAliveInterval (from IServerObjectConfiguration4)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration5, self).put_ServiceKeepAliveInterval(pVal)
    def get_IdleTimeout(self):
        '''Method IServerObjectConfiguration3.get_IdleTimeout (from IServerObjectConfiguration3)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration5, self).get_IdleTimeout()
    def put_IdleTimeout(self, pVal):
        '''Method IServerObjectConfiguration3.put_IdleTimeout (from IServerObjectConfiguration3)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration5, self).put_IdleTimeout(pVal)
    def get_InstancesPerContainer(self):
        '''Method IServerObjectConfiguration3.get_InstancesPerContainer (from IServerObjectConfiguration3)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration5, self).get_InstancesPerContainer()
    def put_InstancesPerContainer(self, pVal):
        '''Method IServerObjectConfiguration3.put_InstancesPerContainer (from IServerObjectConfiguration3)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration5, self).put_InstancesPerContainer(pVal)
    def Serialize(self):
        '''Method IServerObjectConfiguration2.Serialize (from IServerObjectConfiguration2)

           OUTPUT
            str                 : BSTR*'''
        return super(IServerObjectConfiguration5, self).Serialize()
    def Deserialize(self, str):
        '''Method IServerObjectConfiguration2.Deserialize (from IServerObjectConfiguration2)

           INPUT
            str                 : BSTR'''
        return super(IServerObjectConfiguration5, self).Deserialize(str)
    def get_ExtensionProperties(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionProperties (from IServerObjectConfiguration2)

           INPUT
            Name                : BSTR

           OUTPUT
            ppExtProperties     : IPropertySet**'''
        return super(IServerObjectConfiguration5, self).get_ExtensionProperties(Name)
    def putref_ExtensionProperties(self, Name, ppExtProperties):
        '''Method IServerObjectConfiguration2.putref_ExtensionProperties (from IServerObjectConfiguration2)

           INPUTS
            Name                : BSTR
            ppExtProperties     : IPropertySet*'''
        return super(IServerObjectConfiguration5, self).putref_ExtensionProperties(Name, ppExtProperties)
    def get_ExtensionInfo(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionInfo (from IServerObjectConfiguration2)

           INPUT
            Name                : BSTR

           OUTPUT
            ppExtProperties     : IPropertySet**'''
        return super(IServerObjectConfiguration5, self).get_ExtensionInfo(Name)
    def putref_ExtensionInfo(self, Name, ppExtProperties):
        '''Method IServerObjectConfiguration2.putref_ExtensionInfo (from IServerObjectConfiguration2)

           INPUTS
            Name                : BSTR
            ppExtProperties     : IPropertySet*'''
        return super(IServerObjectConfiguration5, self).putref_ExtensionInfo(Name, ppExtProperties)
    def get_ExtensionEnabled(self, Name):
        '''Method IServerObjectConfiguration2.get_ExtensionEnabled (from IServerObjectConfiguration2)

           INPUT
            Name                : BSTR

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectConfiguration5, self).get_ExtensionEnabled(Name)
    def put_ExtensionEnabled(self, Name, pVal):
        '''Method IServerObjectConfiguration2.put_ExtensionEnabled (from IServerObjectConfiguration2)

           INPUTS
            Name                : BSTR
            pVal                : VARIANT_BOOL'''
        return super(IServerObjectConfiguration5, self).put_ExtensionEnabled(Name, pVal)
    def get_CleanupTimeout(self):
        '''Method IServerObjectConfiguration2.get_CleanupTimeout (from IServerObjectConfiguration2)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration5, self).get_CleanupTimeout()
    def put_CleanupTimeout(self, pVal):
        '''Method IServerObjectConfiguration2.put_CleanupTimeout (from IServerObjectConfiguration2)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration5, self).put_CleanupTimeout(pVal)
    def get_StartupTimeout(self):
        '''Method IServerObjectConfiguration2.get_StartupTimeout (from IServerObjectConfiguration2)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration5, self).get_StartupTimeout()
    def put_StartupTimeout(self, pVal):
        '''Method IServerObjectConfiguration2.put_StartupTimeout (from IServerObjectConfiguration2)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration5, self).put_StartupTimeout(pVal)
    def get_Info(self):
        '''Method IServerObjectConfiguration2.get_Info (from IServerObjectConfiguration2)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration5, self).get_Info()
    def putref_Info(self, props):
        '''Method IServerObjectConfiguration2.putref_Info (from IServerObjectConfiguration2)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration5, self).putref_Info(props)
    def get_Name(self):
        '''Method IServerObjectConfiguration.get_Name (from IServerObjectConfiguration)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectConfiguration5, self).get_Name()
    def put_Name(self, Name):
        '''Method IServerObjectConfiguration.put_Name (from IServerObjectConfiguration)

           INPUT
            Name                : BSTR'''
        return super(IServerObjectConfiguration5, self).put_Name(Name)
    def get_TypeName(self):
        '''Method IServerObjectConfiguration.get_TypeName (from IServerObjectConfiguration)

           OUTPUT
            TypeName            : BSTR*'''
        return super(IServerObjectConfiguration5, self).get_TypeName()
    def put_TypeName(self, TypeName):
        '''Method IServerObjectConfiguration.put_TypeName (from IServerObjectConfiguration)

           INPUT
            TypeName            : BSTR'''
        return super(IServerObjectConfiguration5, self).put_TypeName(TypeName)
    def get_Description(self):
        '''Method IServerObjectConfiguration.get_Description (from IServerObjectConfiguration)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectConfiguration5, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectConfiguration.put_Description (from IServerObjectConfiguration)

           INPUT
            desc                : BSTR'''
        return super(IServerObjectConfiguration5, self).put_Description(desc)
    def get_Properties(self):
        '''Method IServerObjectConfiguration.get_Properties (from IServerObjectConfiguration)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration5, self).get_Properties()
    def putref_Properties(self, props):
        '''Method IServerObjectConfiguration.putref_Properties (from IServerObjectConfiguration)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration5, self).putref_Properties(props)
    def get_RecycleProperties(self):
        '''Method IServerObjectConfiguration.get_RecycleProperties (from IServerObjectConfiguration)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectConfiguration5, self).get_RecycleProperties()
    def putref_RecycleProperties(self, props):
        '''Method IServerObjectConfiguration.putref_RecycleProperties (from IServerObjectConfiguration)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectConfiguration5, self).putref_RecycleProperties(props)
    def get_MinInstances(self):
        '''Method IServerObjectConfiguration.get_MinInstances (from IServerObjectConfiguration)

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration5, self).get_MinInstances()
    def put_MinInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MinInstances (from IServerObjectConfiguration)

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration5, self).put_MinInstances(instances)
    def get_MaxInstances(self):
        '''Method IServerObjectConfiguration.get_MaxInstances (from IServerObjectConfiguration)

           OUTPUT
            instances           : long*'''
        return super(IServerObjectConfiguration5, self).get_MaxInstances()
    def put_MaxInstances(self, instances):
        '''Method IServerObjectConfiguration.put_MaxInstances (from IServerObjectConfiguration)

           INPUT
            instances           : long'''
        return super(IServerObjectConfiguration5, self).put_MaxInstances(instances)
    def get_IsPooled(self):
        '''Method IServerObjectConfiguration.get_IsPooled (from IServerObjectConfiguration)

           OUTPUT
            IsPooled            : VARIANT_BOOL*'''
        return super(IServerObjectConfiguration5, self).get_IsPooled()
    def put_IsPooled(self, IsPooled):
        '''Method IServerObjectConfiguration.put_IsPooled (from IServerObjectConfiguration)

           INPUT
            IsPooled            : VARIANT_BOOL'''
        return super(IServerObjectConfiguration5, self).put_IsPooled(IsPooled)
    def get_IsolationLevel(self):
        '''Method IServerObjectConfiguration.get_IsolationLevel (from IServerObjectConfiguration)

           OUTPUT
            isoLevel            : esriServerIsolationLevel*'''
        return super(IServerObjectConfiguration5, self).get_IsolationLevel()
    def put_IsolationLevel(self, isoLevel):
        '''Method IServerObjectConfiguration.put_IsolationLevel (from IServerObjectConfiguration)

           INPUT
            isoLevel            : esriServerIsolationLevel'''
        return super(IServerObjectConfiguration5, self).put_IsolationLevel(isoLevel)
    def get_StartupType(self):
        '''Method IServerObjectConfiguration.get_StartupType (from IServerObjectConfiguration)

           OUTPUT
            Type                : esriStartupType*'''
        return super(IServerObjectConfiguration5, self).get_StartupType()
    def put_StartupType(self, Type):
        '''Method IServerObjectConfiguration.put_StartupType (from IServerObjectConfiguration)

           INPUT
            Type                : esriStartupType'''
        return super(IServerObjectConfiguration5, self).put_StartupType(Type)
    def get_WaitTimeout(self):
        '''Method IServerObjectConfiguration.get_WaitTimeout (from IServerObjectConfiguration)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration5, self).get_WaitTimeout()
    def put_WaitTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_WaitTimeout (from IServerObjectConfiguration)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration5, self).put_WaitTimeout(pVal)
    def get_UsageTimeout(self):
        '''Method IServerObjectConfiguration.get_UsageTimeout (from IServerObjectConfiguration)

           OUTPUT
            pVal                : long*'''
        return super(IServerObjectConfiguration5, self).get_UsageTimeout()
    def put_UsageTimeout(self, pVal):
        '''Method IServerObjectConfiguration.put_UsageTimeout (from IServerObjectConfiguration)

           INPUT
            pVal                : long'''
        return super(IServerObjectConfiguration5, self).put_UsageTimeout(pVal)
    CleanupTimeout = property(get_CleanupTimeout, put_CleanupTimeout, None)
    DatasetNames = property(get_DatasetNames, put_DatasetNames, None)
    Description = property(get_Description, put_Description, None)
    ExtensionEnabled = property(None, put_ExtensionEnabled, None)
    ExtensionInfo = property(None, putref_ExtensionInfo, None)
    ExtensionNames = property(get_ExtensionNames, None, None)
    ExtensionProperties = property(None, putref_ExtensionProperties, None)
    IdleTimeout = property(get_IdleTimeout, put_IdleTimeout, None)
    Info = property(get_Info, putref_Info, None)
    InstancesPerContainer = property(get_InstancesPerContainer, put_InstancesPerContainer, None)
    IsPooled = property(get_IsPooled, put_IsPooled, None)
    IsolationLevel = property(get_IsolationLevel, put_IsolationLevel, None)
    LoadBalancing = property(get_LoadBalancing, put_LoadBalancing, None)
    MaxInstances = property(get_MaxInstances, put_MaxInstances, None)
    MinInstances = property(get_MinInstances, put_MinInstances, None)
    Name = property(get_Name, put_Name, None)
    Properties = property(get_Properties, putref_Properties, None)
    RecycleProperties = property(get_RecycleProperties, putref_RecycleProperties, None)
    ServiceKeepAliveInterval = property(get_ServiceKeepAliveInterval, put_ServiceKeepAliveInterval, None)
    StartupTimeout = property(get_StartupTimeout, put_StartupTimeout, None)
    StartupType = property(get_StartupType, put_StartupType, None)
    Status = property(get_Status, put_Status, None)
    TargetCluster = property(get_TargetCluster, put_TargetCluster, None)
    TypeName = property(get_TypeName, put_TypeName, None)
    UsageTimeout = property(get_UsageTimeout, put_UsageTimeout, None)
    WaitTimeout = property(get_WaitTimeout, put_WaitTimeout, None)
    ExtensionEnabled = IndexProperty(get_ExtensionEnabled, None)
    ExtensionInfo = IndexProperty(get_ExtensionInfo, None)
    ExtensionProperties = IndexProperty(get_ExtensionProperties, None)

class IServerObjectConfigurationInfo2(_esriServer.IServerObjectConfigurationInfo2):
    _IID = uuid.UUID('765ee3db-2a65-41ed-9619-482bbc48192d')
    def get_Extensions(self):
        '''Method IServerObjectConfigurationInfo2.get_Extensions

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectConfigurationInfo2, self).get_Extensions()
    def get_Info(self):
        '''Method IServerObjectConfigurationInfo2.get_Info

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectConfigurationInfo2, self).get_Info()
    def get_ExtensionInfo(self, Name):
        '''Method IServerObjectConfigurationInfo2.get_ExtensionInfo

           INPUT
            Name                : BSTR

           OUTPUT
            ppExtProperties     : IPropertySet**'''
        return super(IServerObjectConfigurationInfo2, self).get_ExtensionInfo(Name)
    def get_Name(self):
        '''Method IServerObjectConfigurationInfo.get_Name (from IServerObjectConfigurationInfo)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerObjectConfigurationInfo2, self).get_Name()
    def get_TypeName(self):
        '''Method IServerObjectConfigurationInfo.get_TypeName (from IServerObjectConfigurationInfo)

           OUTPUT
            TypeName            : BSTR*'''
        return super(IServerObjectConfigurationInfo2, self).get_TypeName()
    def get_Description(self):
        '''Method IServerObjectConfigurationInfo.get_Description (from IServerObjectConfigurationInfo)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectConfigurationInfo2, self).get_Description()
    def get_IsPooled(self):
        '''Method IServerObjectConfigurationInfo.get_IsPooled (from IServerObjectConfigurationInfo)

           OUTPUT
            IsPooled            : VARIANT_BOOL*'''
        return super(IServerObjectConfigurationInfo2, self).get_IsPooled()
    Description = property(get_Description, None, None)
    Extensions = property(get_Extensions, None, None)
    Info = property(get_Info, None, None)
    IsPooled = property(get_IsPooled, None, None)
    Name = property(get_Name, None, None)
    TypeName = property(get_TypeName, None, None)
    ExtensionInfo = IndexProperty(get_ExtensionInfo, None)

class IServerDirectory2(_esriServer.IServerDirectory2):
    _IID = uuid.UUID('f284d482-f71b-4542-9c93-1dc4b7e79881')

    def __init__(self, *args, **kw):
        super(IServerDirectory2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Type(self):
        '''Method IServerDirectory2.get_Type

           OUTPUT
            pType               : esriServerDirectoryType*'''
        return super(IServerDirectory2, self).get_Type()
    def put_Type(self, pType):
        '''Method IServerDirectory2.put_Type

           INPUT
            pType               : esriServerDirectoryType'''
        return super(IServerDirectory2, self).put_Type(pType)
    def get_Path(self):
        '''Method IServerDirectory.get_Path (from IServerDirectory)

           OUTPUT
            pPath               : BSTR*'''
        return super(IServerDirectory2, self).get_Path()
    def put_Path(self, pPath):
        '''Method IServerDirectory.put_Path (from IServerDirectory)

           INPUT
            pPath               : BSTR'''
        return super(IServerDirectory2, self).put_Path(pPath)
    def get_URL(self):
        '''Method IServerDirectory.get_URL (from IServerDirectory)

           OUTPUT
            pUrl                : BSTR*'''
        return super(IServerDirectory2, self).get_URL()
    def put_URL(self, pUrl):
        '''Method IServerDirectory.put_URL (from IServerDirectory)

           INPUT
            pUrl                : BSTR'''
        return super(IServerDirectory2, self).put_URL(pUrl)
    def get_Description(self):
        '''Method IServerDirectory.get_Description (from IServerDirectory)

           OUTPUT
            pText               : BSTR*'''
        return super(IServerDirectory2, self).get_Description()
    def put_Description(self, pText):
        '''Method IServerDirectory.put_Description (from IServerDirectory)

           INPUT
            pText               : BSTR'''
        return super(IServerDirectory2, self).put_Description(pText)
    def get_CleaningMode(self):
        '''Method IServerDirectory.get_CleaningMode (from IServerDirectory)

           OUTPUT
            pMode               : esriServerDirectoryCleaningMode*'''
        return super(IServerDirectory2, self).get_CleaningMode()
    def put_CleaningMode(self, pMode):
        '''Method IServerDirectory.put_CleaningMode (from IServerDirectory)

           INPUT
            pMode               : esriServerDirectoryCleaningMode'''
        return super(IServerDirectory2, self).put_CleaningMode(pMode)
    def get_MaxFileAge(self):
        '''Method IServerDirectory.get_MaxFileAge (from IServerDirectory)

           OUTPUT
            pAge                : long*'''
        return super(IServerDirectory2, self).get_MaxFileAge()
    def put_MaxFileAge(self, pAge):
        '''Method IServerDirectory.put_MaxFileAge (from IServerDirectory)

           INPUT
            pAge                : long'''
        return super(IServerDirectory2, self).put_MaxFileAge(pAge)
    CleaningMode = property(get_CleaningMode, put_CleaningMode, None)
    Description = property(get_Description, put_Description, None)
    MaxFileAge = property(get_MaxFileAge, put_MaxFileAge, None)
    Path = property(get_Path, put_Path, None)
    Type = property(get_Type, put_Type, None)
    URL = property(get_URL, put_URL, None)

class IServerDirectory3(_esriServer.IServerDirectory3):
    _IID = uuid.UUID('2f2823a9-97d5-4287-bcec-0d9802a4b115')

    def __init__(self, *args, **kw):
        super(IServerDirectory3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IServerDirectory3.get_Name

           OUTPUT
            pName               : BSTR*'''
        return super(IServerDirectory3, self).get_Name()
    def put_Name(self, pName):
        '''Method IServerDirectory3.put_Name

           INPUT
            pName               : BSTR'''
        return super(IServerDirectory3, self).put_Name(pName)
    def get_IsPrivate(self):
        '''Method IServerDirectory3.get_IsPrivate

           OUTPUT
            pIsPrivate          : VARIANT_BOOL*'''
        return super(IServerDirectory3, self).get_IsPrivate()
    def get_CanAddNew(self):
        '''Method IServerDirectory3.get_CanAddNew

           OUTPUT
            pCanAddNew          : VARIANT_BOOL*'''
        return super(IServerDirectory3, self).get_CanAddNew()
    def get_CanDelete(self):
        '''Method IServerDirectory3.get_CanDelete

           OUTPUT
            pCanDelete          : VARIANT_BOOL*'''
        return super(IServerDirectory3, self).get_CanDelete()
    def get_CanEdit(self):
        '''Method IServerDirectory3.get_CanEdit

           OUTPUT
            pCanEdit            : VARIANT_BOOL*'''
        return super(IServerDirectory3, self).get_CanEdit()
    def get_Type(self):
        '''Method IServerDirectory2.get_Type (from IServerDirectory2)

           OUTPUT
            pType               : esriServerDirectoryType*'''
        return super(IServerDirectory3, self).get_Type()
    def put_Type(self, pType):
        '''Method IServerDirectory2.put_Type (from IServerDirectory2)

           INPUT
            pType               : esriServerDirectoryType'''
        return super(IServerDirectory3, self).put_Type(pType)
    def get_Path(self):
        '''Method IServerDirectory.get_Path (from IServerDirectory)

           OUTPUT
            pPath               : BSTR*'''
        return super(IServerDirectory3, self).get_Path()
    def put_Path(self, pPath):
        '''Method IServerDirectory.put_Path (from IServerDirectory)

           INPUT
            pPath               : BSTR'''
        return super(IServerDirectory3, self).put_Path(pPath)
    def get_URL(self):
        '''Method IServerDirectory.get_URL (from IServerDirectory)

           OUTPUT
            pUrl                : BSTR*'''
        return super(IServerDirectory3, self).get_URL()
    def put_URL(self, pUrl):
        '''Method IServerDirectory.put_URL (from IServerDirectory)

           INPUT
            pUrl                : BSTR'''
        return super(IServerDirectory3, self).put_URL(pUrl)
    def get_Description(self):
        '''Method IServerDirectory.get_Description (from IServerDirectory)

           OUTPUT
            pText               : BSTR*'''
        return super(IServerDirectory3, self).get_Description()
    def put_Description(self, pText):
        '''Method IServerDirectory.put_Description (from IServerDirectory)

           INPUT
            pText               : BSTR'''
        return super(IServerDirectory3, self).put_Description(pText)
    def get_CleaningMode(self):
        '''Method IServerDirectory.get_CleaningMode (from IServerDirectory)

           OUTPUT
            pMode               : esriServerDirectoryCleaningMode*'''
        return super(IServerDirectory3, self).get_CleaningMode()
    def put_CleaningMode(self, pMode):
        '''Method IServerDirectory.put_CleaningMode (from IServerDirectory)

           INPUT
            pMode               : esriServerDirectoryCleaningMode'''
        return super(IServerDirectory3, self).put_CleaningMode(pMode)
    def get_MaxFileAge(self):
        '''Method IServerDirectory.get_MaxFileAge (from IServerDirectory)

           OUTPUT
            pAge                : long*'''
        return super(IServerDirectory3, self).get_MaxFileAge()
    def put_MaxFileAge(self, pAge):
        '''Method IServerDirectory.put_MaxFileAge (from IServerDirectory)

           INPUT
            pAge                : long'''
        return super(IServerDirectory3, self).put_MaxFileAge(pAge)
    CanAddNew = property(get_CanAddNew, None, None)
    CanDelete = property(get_CanDelete, None, None)
    CanEdit = property(get_CanEdit, None, None)
    CleaningMode = property(get_CleaningMode, put_CleaningMode, None)
    Description = property(get_Description, put_Description, None)
    IsPrivate = property(get_IsPrivate, None, None)
    MaxFileAge = property(get_MaxFileAge, put_MaxFileAge, None)
    Name = property(get_Name, put_Name, None)
    Path = property(get_Path, put_Path, None)
    Type = property(get_Type, put_Type, None)
    URL = property(get_URL, put_URL, None)

class IServerDirectoryInfo2(_esriServer.IServerDirectoryInfo2):
    _IID = uuid.UUID('2b0cc34c-e861-46ef-8bf0-308ab6113ce8')
    def get_Type(self):
        '''Method IServerDirectoryInfo2.get_Type

           OUTPUT
            pType               : esriServerDirectoryType*'''
        return super(IServerDirectoryInfo2, self).get_Type()
    def get_Path(self):
        '''Method IServerDirectoryInfo.get_Path (from IServerDirectoryInfo)

           OUTPUT
            pPath               : BSTR*'''
        return super(IServerDirectoryInfo2, self).get_Path()
    def get_URL(self):
        '''Method IServerDirectoryInfo.get_URL (from IServerDirectoryInfo)

           OUTPUT
            pUrl                : BSTR*'''
        return super(IServerDirectoryInfo2, self).get_URL()
    def get_Description(self):
        '''Method IServerDirectoryInfo.get_Description (from IServerDirectoryInfo)

           OUTPUT
            pText               : BSTR*'''
        return super(IServerDirectoryInfo2, self).get_Description()
    def get_CleaningMode(self):
        '''Method IServerDirectoryInfo.get_CleaningMode (from IServerDirectoryInfo)

           OUTPUT
            pMode               : esriServerDirectoryCleaningMode*'''
        return super(IServerDirectoryInfo2, self).get_CleaningMode()
    def get_MaxFileAge(self):
        '''Method IServerDirectoryInfo.get_MaxFileAge (from IServerDirectoryInfo)

           OUTPUT
            pAge                : long*'''
        return super(IServerDirectoryInfo2, self).get_MaxFileAge()
    CleaningMode = property(get_CleaningMode, None, None)
    Description = property(get_Description, None, None)
    MaxFileAge = property(get_MaxFileAge, None, None)
    Path = property(get_Path, None, None)
    Type = property(get_Type, None, None)
    URL = property(get_URL, None, None)

class IServerMachine2(_esriServer.IServerMachine2):
    _IID = uuid.UUID('7cdddb35-6819-41f6-b2c3-8197f95f65b0')

    def __init__(self, *args, **kw):
        super(IServerMachine2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Capacity(self):
        '''Method IServerMachine2.get_Capacity

           OUTPUT
            Val                 : long*'''
        return super(IServerMachine2, self).get_Capacity()
    def put_Capacity(self, Val):
        '''Method IServerMachine2.put_Capacity

           INPUT
            Val                 : long'''
        return super(IServerMachine2, self).put_Capacity(Val)
    def get_Name(self):
        '''Method IServerMachine.get_Name (from IServerMachine)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerMachine2, self).get_Name()
    def put_Name(self, Name):
        '''Method IServerMachine.put_Name (from IServerMachine)

           INPUT
            Name                : BSTR'''
        return super(IServerMachine2, self).put_Name(Name)
    def get_Description(self):
        '''Method IServerMachine.get_Description (from IServerMachine)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerMachine2, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerMachine.put_Description (from IServerMachine)

           INPUT
            desc                : BSTR'''
        return super(IServerMachine2, self).put_Description(desc)
    Capacity = property(get_Capacity, put_Capacity, None)
    Description = property(get_Description, put_Description, None)
    Name = property(get_Name, put_Name, None)

class IServerMachine3(_esriServer.IServerMachine3):
    _IID = uuid.UUID('c0445f7e-124c-487d-a364-6506e3574865')

    def __init__(self, *args, **kw):
        super(IServerMachine3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_AdminURL(self):
        '''Method IServerMachine3.get_AdminURL

           OUTPUT
            pUrl                : BSTR*'''
        return super(IServerMachine3, self).get_AdminURL()
    def put_AdminURL(self, pUrl):
        '''Method IServerMachine3.put_AdminURL

           INPUT
            pUrl                : BSTR'''
        return super(IServerMachine3, self).put_AdminURL(pUrl)
    def get_Platform(self):
        '''Method IServerMachine3.get_Platform

           OUTPUT
            pPlatform           : BSTR*'''
        return super(IServerMachine3, self).get_Platform()
    def put_Platform(self, pPlatform):
        '''Method IServerMachine3.put_Platform

           INPUT
            pPlatform           : BSTR'''
        return super(IServerMachine3, self).put_Platform(pPlatform)
    def get_PortCount(self):
        '''Method IServerMachine3.get_PortCount

           OUTPUT
            pCount              : long*'''
        return super(IServerMachine3, self).get_PortCount()
    def get_PortNames(self):
        '''Method IServerMachine3.get_PortNames

           OUTPUT
            ppNames             : IEnumBSTR**'''
        return super(IServerMachine3, self).get_PortNames()
    def get_PortNumber(self, Name):
        '''Method IServerMachine3.get_PortNumber

           INPUT
            Name                : BSTR

           OUTPUT
            pNumber             : long*'''
        return super(IServerMachine3, self).get_PortNumber(Name)
    def get_Capacity(self):
        '''Method IServerMachine2.get_Capacity (from IServerMachine2)

           OUTPUT
            Val                 : long*'''
        return super(IServerMachine3, self).get_Capacity()
    def put_Capacity(self, Val):
        '''Method IServerMachine2.put_Capacity (from IServerMachine2)

           INPUT
            Val                 : long'''
        return super(IServerMachine3, self).put_Capacity(Val)
    def get_Name(self):
        '''Method IServerMachine.get_Name (from IServerMachine)

           OUTPUT
            Name                : BSTR*'''
        return super(IServerMachine3, self).get_Name()
    def put_Name(self, Name):
        '''Method IServerMachine.put_Name (from IServerMachine)

           INPUT
            Name                : BSTR'''
        return super(IServerMachine3, self).put_Name(Name)
    def get_Description(self):
        '''Method IServerMachine.get_Description (from IServerMachine)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerMachine3, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerMachine.put_Description (from IServerMachine)

           INPUT
            desc                : BSTR'''
        return super(IServerMachine3, self).put_Description(desc)
    AdminURL = property(get_AdminURL, put_AdminURL, None)
    Capacity = property(get_Capacity, put_Capacity, None)
    Description = property(get_Description, put_Description, None)
    Name = property(get_Name, put_Name, None)
    Platform = property(get_Platform, put_Platform, None)
    PortCount = property(get_PortCount, None, None)
    PortNames = property(get_PortNames, None, None)
    PortNumber = IndexProperty(get_PortNumber, None)

class IServerMachineStatus(_esriServer.IServerMachineStatus):
    _IID = uuid.UUID('67e836a4-01f1-450c-97be-21ab9a3f3c11')
    def get_InstanceCount(self, access):
        '''Method IServerMachineStatus.get_InstanceCount

           INPUT
            access              : esriAccessLevel

           OUTPUT
            pVal                : long*'''
        return super(IServerMachineStatus, self).get_InstanceCount(access)
    def get_InstanceInUseCount(self, access):
        '''Method IServerMachineStatus.get_InstanceInUseCount

           INPUT
            access              : esriAccessLevel

           OUTPUT
            pVal                : long*'''
        return super(IServerMachineStatus, self).get_InstanceInUseCount(access)
    def get_Enabled(self):
        '''Method IServerMachineStatus.get_Enabled

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerMachineStatus, self).get_Enabled()
    Enabled = property(get_Enabled, None, None)
    InstanceCount = IndexProperty(get_InstanceCount, None)
    InstanceInUseCount = IndexProperty(get_InstanceInUseCount, None)

class IServerMachineInfo(_esriServer.IServerMachineInfo):
    _IID = uuid.UUID('76c3bba1-aacf-40a1-bdee-b3fa28840979')
    def get_NumberOfProcessors(self):
        '''Method IServerMachineInfo.get_NumberOfProcessors

           OUTPUT
            pVal                : long*'''
        return super(IServerMachineInfo, self).get_NumberOfProcessors()
    NumberOfProcessors = property(get_NumberOfProcessors, None, None)

class IServerStatistics(_esriServer.IServerStatistics):
    _IID = uuid.UUID('a0500a17-b797-41f3-94eb-66a32fcf8d80')
    def Reset(self):
        '''Method IServerStatistics.Reset'''
        return super(IServerStatistics, self).Reset()
    def GetSpecificStatisticForTimeIntervals(self, event, function, period, index, length, Name, Type, Machine):
        '''Method IServerStatistics.GetSpecificStatisticForTimeIntervals

           INPUTS
            event               : esriServerStatEvent
            function            : esriServerStatFunction
            period              : esriServerTimePeriod
            index               : long
            length              : long
            Name                : BSTR
            Type                : BSTR
            Machine             : BSTR

           OUTPUT
            ppArray             : IDoubleArray**'''
        return super(IServerStatistics, self).GetSpecificStatisticForTimeIntervals(event, function, period, index, length, Name, Type, Machine)
    def GetAllStatisticsForTimeInterval(self, event, period, index, length, Name, Type, Machine):
        '''Method IServerStatistics.GetAllStatisticsForTimeInterval

           INPUTS
            event               : esriServerStatEvent
            period              : esriServerTimePeriod
            index               : long
            length              : long
            Name                : BSTR
            Type                : BSTR
            Machine             : BSTR

           OUTPUT
            ppResults           : IStatisticsResults**'''
        return super(IServerStatistics, self).GetAllStatisticsForTimeInterval(event, period, index, length, Name, Type, Machine)

class IServerStatus(_esriServer.IServerStatus):
    _IID = uuid.UUID('de94c160-5101-49a4-bab4-6893745f01ce')
    def get_InstanceCount(self, access):
        '''Method IServerStatus.get_InstanceCount

           INPUT
            access              : esriAccessLevel

           OUTPUT
            pVal                : long*'''
        return super(IServerStatus, self).get_InstanceCount(access)
    def get_InstanceInUseCount(self, access):
        '''Method IServerStatus.get_InstanceInUseCount

           INPUT
            access              : esriAccessLevel

           OUTPUT
            pVal                : long*'''
        return super(IServerStatus, self).get_InstanceInUseCount(access)
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerStatus.GetConfigurationStatus

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerStatus, self).GetConfigurationStatus(Name, TypeName)
    def GetMachineStatus(self, Machine):
        '''Method IServerStatus.GetMachineStatus

           INPUT
            Machine             : BSTR

           OUTPUT
            ppStatus            : IServerMachineStatus**'''
        return super(IServerStatus, self).GetMachineStatus(Machine)
    def get_StartTime(self):
        '''Method IServerStatus.get_StartTime

           OUTPUT
            pVal                : DATE*'''
        return super(IServerStatus, self).get_StartTime()
    def get_Enabled(self):
        '''Method IServerStatus.get_Enabled

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerStatus, self).get_Enabled()
    Enabled = property(get_Enabled, None, None)
    StartTime = property(get_StartTime, None, None)
    InstanceCount = IndexProperty(get_InstanceCount, None)
    InstanceInUseCount = IndexProperty(get_InstanceInUseCount, None)

class IServerErrorReports(_esriServer.IServerErrorReports):
    _IID = uuid.UUID('a0c0005d-c630-4a08-9805-5b3e4c446dbb')

    def __init__(self, *args, **kw):
        super(IServerErrorReports, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ErrorReportMode(self, pVal):
        '''Method IServerErrorReports.put_ErrorReportMode

           INPUT
            pVal                : esriServerExceptionHandlingMode'''
        return super(IServerErrorReports, self).put_ErrorReportMode(pVal)
    def get_ErrorReportMode(self):
        '''Method IServerErrorReports.get_ErrorReportMode

           OUTPUT
            pVal                : esriServerExceptionHandlingMode*'''
        return super(IServerErrorReports, self).get_ErrorReportMode()
    def put_ErrorReportModeSOM(self, pVal):
        '''Method IServerErrorReports.put_ErrorReportModeSOM

           INPUT
            pVal                : esriServerExceptionHandlingMode'''
        return super(IServerErrorReports, self).put_ErrorReportModeSOM(pVal)
    def get_ErrorReportModeSOM(self):
        '''Method IServerErrorReports.get_ErrorReportModeSOM

           OUTPUT
            pVal                : esriServerExceptionHandlingMode*'''
        return super(IServerErrorReports, self).get_ErrorReportModeSOM()
    def put_ErrorReportType(self, pVal):
        '''Method IServerErrorReports.put_ErrorReportType

           INPUT
            pVal                : unsignedlong'''
        return super(IServerErrorReports, self).put_ErrorReportType(pVal)
    def get_ErrorReportType(self):
        '''Method IServerErrorReports.get_ErrorReportType

           OUTPUT
            pVal                : unsignedlong*'''
        return super(IServerErrorReports, self).get_ErrorReportType()
    def put_ErrorReportDir(self, pVal):
        '''Method IServerErrorReports.put_ErrorReportDir

           INPUT
            pVal                : BSTR'''
        return super(IServerErrorReports, self).put_ErrorReportDir(pVal)
    def get_ErrorReportDir(self):
        '''Method IServerErrorReports.get_ErrorReportDir

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerErrorReports, self).get_ErrorReportDir()
    def put_ErrorReportCacheSize(self, pVal):
        '''Method IServerErrorReports.put_ErrorReportCacheSize

           INPUT
            pVal                : unsignedlong'''
        return super(IServerErrorReports, self).put_ErrorReportCacheSize(pVal)
    def get_ErrorReportCacheSize(self):
        '''Method IServerErrorReports.get_ErrorReportCacheSize

           OUTPUT
            pVal                : unsignedlong*'''
        return super(IServerErrorReports, self).get_ErrorReportCacheSize()
    def put_ErrorReportEnableUpload(self, pVal):
        '''Method IServerErrorReports.put_ErrorReportEnableUpload

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(IServerErrorReports, self).put_ErrorReportEnableUpload(pVal)
    def get_ErrorReportEnableUpload(self):
        '''Method IServerErrorReports.get_ErrorReportEnableUpload

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerErrorReports, self).get_ErrorReportEnableUpload()
    def put_ErrorReportEmailAddress(self, pVal):
        '''Method IServerErrorReports.put_ErrorReportEmailAddress

           INPUT
            pVal                : BSTR'''
        return super(IServerErrorReports, self).put_ErrorReportEmailAddress(pVal)
    def get_ErrorReportEmailAddress(self):
        '''Method IServerErrorReports.get_ErrorReportEmailAddress

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerErrorReports, self).get_ErrorReportEmailAddress()
    def put_ErrorReportInterval(self, pVal):
        '''Method IServerErrorReports.put_ErrorReportInterval

           INPUT
            pVal                : unsignedlong'''
        return super(IServerErrorReports, self).put_ErrorReportInterval(pVal)
    def get_ErrorReportInterval(self):
        '''Method IServerErrorReports.get_ErrorReportInterval

           OUTPUT
            pVal                : unsignedlong*'''
        return super(IServerErrorReports, self).get_ErrorReportInterval()
    def ReportErrors(self):
        '''Method IServerErrorReports.ReportErrors'''
        return super(IServerErrorReports, self).ReportErrors()
    ErrorReportCacheSize = property(get_ErrorReportCacheSize, put_ErrorReportCacheSize, None)
    ErrorReportDir = property(get_ErrorReportDir, put_ErrorReportDir, None)
    ErrorReportEmailAddress = property(get_ErrorReportEmailAddress, put_ErrorReportEmailAddress, None)
    ErrorReportEnableUpload = property(get_ErrorReportEnableUpload, put_ErrorReportEnableUpload, None)
    ErrorReportInterval = property(get_ErrorReportInterval, put_ErrorReportInterval, None)
    ErrorReportMode = property(get_ErrorReportMode, put_ErrorReportMode, None)
    ErrorReportModeSOM = property(get_ErrorReportModeSOM, put_ErrorReportModeSOM, None)
    ErrorReportType = property(get_ErrorReportType, put_ErrorReportType, None)

class IPermissionsAdmin(_esriServer.IPermissionsAdmin):
    _IID = uuid.UUID('1d869ab1-db39-4cb8-9e95-a64ac2beb029')
    def AllowPermission(self, Principal, resource, operation):
        '''Method IPermissionsAdmin.AllowPermission

           INPUTS
            Principal           : BSTR
            resource            : BSTR
            operation           : BSTR'''
        return super(IPermissionsAdmin, self).AllowPermission(Principal, resource, operation)
    def DenyPermission(self, Principal, resource, operation):
        '''Method IPermissionsAdmin.DenyPermission

           INPUTS
            Principal           : BSTR
            resource            : BSTR
            operation           : BSTR'''
        return super(IPermissionsAdmin, self).DenyPermission(Principal, resource, operation)
    def GetAllPrincipals(self):
        '''Method IPermissionsAdmin.GetAllPrincipals

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IPermissionsAdmin, self).GetAllPrincipals()

class IPermissionsAdmin2(_esriServer.IPermissionsAdmin2):
    _IID = uuid.UUID('8f6ce835-8644-420d-a2a3-2a84e2c29bfd')
    def CleanPermissions(self, Principal):
        '''Method IPermissionsAdmin2.CleanPermissions

           INPUT
            Principal           : BSTR'''
        return super(IPermissionsAdmin2, self).CleanPermissions(Principal)
    def AllowPermission(self, Principal, resource, operation):
        '''Method IPermissionsAdmin.AllowPermission (from IPermissionsAdmin)

           INPUTS
            Principal           : BSTR
            resource            : BSTR
            operation           : BSTR'''
        return super(IPermissionsAdmin2, self).AllowPermission(Principal, resource, operation)
    def DenyPermission(self, Principal, resource, operation):
        '''Method IPermissionsAdmin.DenyPermission (from IPermissionsAdmin)

           INPUTS
            Principal           : BSTR
            resource            : BSTR
            operation           : BSTR'''
        return super(IPermissionsAdmin2, self).DenyPermission(Principal, resource, operation)
    def GetAllPrincipals(self):
        '''Method IPermissionsAdmin.GetAllPrincipals (from IPermissionsAdmin)

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IPermissionsAdmin2, self).GetAllPrincipals()

class IPermissionsManager(_esriServer.IPermissionsManager):
    _IID = uuid.UUID('05d95968-651a-4c97-b63e-d26f2bb0e97b')
    def CheckPermission(self, Principal, resource, operation):
        '''Method IPermissionsManager.CheckPermission

           INPUTS
            Principal           : BSTR
            resource            : BSTR
            operation           : BSTR

           OUTPUT
            pbRes               : VARIANT_BOOL*'''
        return super(IPermissionsManager, self).CheckPermission(Principal, resource, operation)
    def GetPrincipalsWithPermissionOnResource(self, resource, operation):
        '''Method IPermissionsManager.GetPrincipalsWithPermissionOnResource

           INPUTS
            resource            : BSTR
            operation           : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IPermissionsManager, self).GetPrincipalsWithPermissionOnResource(resource, operation)
    def CheckForDescendentsWithDifferentPermissions(self, Principal, resource, operation):
        '''Method IPermissionsManager.CheckForDescendentsWithDifferentPermissions

           INPUTS
            Principal           : BSTR
            resource            : BSTR
            operation           : BSTR

           OUTPUT
            pbRes               : VARIANT_BOOL*'''
        return super(IPermissionsManager, self).CheckForDescendentsWithDifferentPermissions(Principal, resource, operation)

class IServerCLRHost(_esriServer.IServerCLRHost):
    _IID = uuid.UUID('562704ee-3a20-4c6d-a501-8468a1dbc55a')
    def Cleanup(self):
        '''Method IServerCLRHost.Cleanup'''
        return super(IServerCLRHost, self).Cleanup()

class IServerObjectExtensionType3(_esriServer.IServerObjectExtensionType3):
    _IID = uuid.UUID('bc0eecab-48dd-439e-8eca-f2c4e3f37beb')

    def __init__(self, *args, **kw):
        super(IServerObjectExtensionType3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Properties(self):
        '''Method IServerObjectExtensionType3.get_Properties

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectExtensionType3, self).get_Properties()
    def putref_Properties(self, props):
        '''Method IServerObjectExtensionType3.putref_Properties

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectExtensionType3, self).putref_Properties(props)
    def get_Info(self):
        '''Method IServerObjectExtensionType3.get_Info

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectExtensionType3, self).get_Info()
    def putref_Info(self, props):
        '''Method IServerObjectExtensionType3.putref_Info

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectExtensionType3, self).putref_Info(props)
    def get_ConfigurationFactoryCLSID(self):
        '''Method IServerObjectExtensionType3.get_ConfigurationFactoryCLSID

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionType3, self).get_ConfigurationFactoryCLSID()
    def put_ConfigurationFactoryCLSID(self, pVal):
        '''Method IServerObjectExtensionType3.put_ConfigurationFactoryCLSID

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectExtensionType3, self).put_ConfigurationFactoryCLSID(pVal)
    def get_DisplayName(self):
        '''Method IServerObjectExtensionType2.get_DisplayName (from IServerObjectExtensionType2)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionType3, self).get_DisplayName()
    def put_DisplayName(self, pVal):
        '''Method IServerObjectExtensionType2.put_DisplayName (from IServerObjectExtensionType2)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectExtensionType3, self).put_DisplayName(pVal)
    def get_Name(self):
        '''Method IServerObjectExtensionType.get_Name (from IServerObjectExtensionType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionType3, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServerObjectExtensionType.put_Name (from IServerObjectExtensionType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectExtensionType3, self).put_Name(pVal)
    def get_Description(self):
        '''Method IServerObjectExtensionType.get_Description (from IServerObjectExtensionType)

           OUTPUT
            desc                : BSTR*'''
        return super(IServerObjectExtensionType3, self).get_Description()
    def put_Description(self, desc):
        '''Method IServerObjectExtensionType.put_Description (from IServerObjectExtensionType)

           INPUT
            desc                : BSTR'''
        return super(IServerObjectExtensionType3, self).put_Description(desc)
    def get_CLSID(self):
        '''Method IServerObjectExtensionType.get_CLSID (from IServerObjectExtensionType)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerObjectExtensionType3, self).get_CLSID()
    def put_CLSID(self, pVal):
        '''Method IServerObjectExtensionType.put_CLSID (from IServerObjectExtensionType)

           INPUT
            pVal                : BSTR'''
        return super(IServerObjectExtensionType3, self).put_CLSID(pVal)
    CLSID = property(get_CLSID, put_CLSID, None)
    ConfigurationFactoryCLSID = property(get_ConfigurationFactoryCLSID, put_ConfigurationFactoryCLSID, None)
    Description = property(get_Description, put_Description, None)
    DisplayName = property(get_DisplayName, put_DisplayName, None)
    Info = property(get_Info, putref_Info, None)
    Name = property(get_Name, put_Name, None)
    Properties = property(get_Properties, putref_Properties, None)

class IServerMachineEnvironment(_esriServer.IServerMachineEnvironment):
    _IID = uuid.UUID('c1a7fbab-48d4-49da-9aac-b28d3b982a9d')
    def GetEnvVariable(self, Name):
        '''Method IServerMachineEnvironment.GetEnvVariable

           INPUT
            Name                : BSTR

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerMachineEnvironment, self).GetEnvVariable(Name)

class IServerObjectAdmin8(_esriServer.IServerObjectAdmin8):
    _IID = uuid.UUID('22930007-4a01-479f-8cb6-33c8ac33ccf4')

    def __init__(self, *args, **kw):
        super(IServerObjectAdmin8, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def AddGeodatabase(self, gdbName, Val):
        '''Method IServerObjectAdmin8.AddGeodatabase

           INPUTS
            gdbName             : BSTR
            Val                 : BSTR'''
        return super(IServerObjectAdmin8, self).AddGeodatabase(gdbName, Val)
    def DeleteGeodatabase(self, gdbName):
        '''Method IServerObjectAdmin8.DeleteGeodatabase

           INPUT
            gdbName             : BSTR'''
        return super(IServerObjectAdmin8, self).DeleteGeodatabase(gdbName)
    def get_Geodatabases(self):
        '''Method IServerObjectAdmin8.get_Geodatabases

           OUTPUT
            pList               : BSTR*'''
        return super(IServerObjectAdmin8, self).get_Geodatabases()
    def GetGeodatabase(self, gdbName):
        '''Method IServerObjectAdmin8.GetGeodatabase

           INPUT
            gdbName             : BSTR

           OUTPUTS
            pUpdateID           : BSTR*
            pVal                : BSTR*'''
        return super(IServerObjectAdmin8, self).GetGeodatabase(gdbName)
    def PutGeodatabase(self, gdbName, Val):
        '''Method IServerObjectAdmin8.PutGeodatabase

           INPUTS
            gdbName             : BSTR
            Val                 : BSTR'''
        return super(IServerObjectAdmin8, self).PutGeodatabase(gdbName, Val)
    def IsAdminUser(self, UserName):
        '''Method IServerObjectAdmin7.IsAdminUser (from IServerObjectAdmin7)

           INPUT
            UserName            : BSTR

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin8, self).IsAdminUser(UserName)
    def GetInputDir(self, cfgName, cfgType):
        '''Method IServerObjectAdmin6.GetInputDir (from IServerObjectAdmin6)

           INPUTS
            cfgName             : BSTR
            cfgType             : BSTR

           OUTPUT
            dir                 : BSTR*'''
        return super(IServerObjectAdmin8, self).GetInputDir(cfgName, cfgType)
    def IsInputDirInUse(self):
        '''Method IServerObjectAdmin6.IsInputDirInUse (from IServerObjectAdmin6)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin8, self).IsInputDirInUse()
    def UploadData(self, cfgName, cfgType, fileName, data):
        '''Method IServerObjectAdmin6.UploadData (from IServerObjectAdmin6)

           INPUTS
            cfgName             : BSTR
            cfgType             : BSTR
            fileName            : BSTR
            data                : SAFEARRAY**'''
        return super(IServerObjectAdmin8, self).UploadData(cfgName, cfgType, fileName, data)
    def GetConfigurationProperties(self, Name, Type):
        '''Method IServerObjectAdmin5.GetConfigurationProperties (from IServerObjectAdmin5)

           INPUTS
            Name                : BSTR
            Type                : BSTR

           OUTPUT
            ppProps             : IPropertySet**'''
        return super(IServerObjectAdmin8, self).GetConfigurationProperties(Name, Type)
    def UpdateConfigurationProperties(self, Name, Type, pProps):
        '''Method IServerObjectAdmin5.UpdateConfigurationProperties (from IServerObjectAdmin5)

           INPUTS
            Name                : BSTR
            Type                : BSTR
            pProps              : IPropertySet*'''
        return super(IServerObjectAdmin8, self).UpdateConfigurationProperties(Name, Type, pProps)
    def get_IsSecurityEnabled(self):
        '''Method IServerObjectAdmin4.get_IsSecurityEnabled (from IServerObjectAdmin4)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerObjectAdmin8, self).get_IsSecurityEnabled()
    def put_IsSecurityEnabled(self, pVal):
        '''Method IServerObjectAdmin4.put_IsSecurityEnabled (from IServerObjectAdmin4)

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(IServerObjectAdmin8, self).put_IsSecurityEnabled(pVal)
    def GetConfigurationsEx2(self, folderName, stat):
        '''Method IServerObjectAdmin3.GetConfigurationsEx2 (from IServerObjectAdmin3)

           INPUTS
            folderName          : BSTR
            stat                : esriConfigurationStatus

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin8, self).GetConfigurationsEx2(folderName, stat)
    def GetExtensionTypes(self, SOTypeName):
        '''Method IServerObjectAdmin2.GetExtensionTypes (from IServerObjectAdmin2)

           INPUT
            SOTypeName          : BSTR

           OUTPUT
            ppTypes             : IEnumServerObjectExtensionType**'''
        return super(IServerObjectAdmin8, self).GetExtensionTypes(SOTypeName)
    def get_ServerLog(self):
        '''Method IServerObjectAdmin2.get_ServerLog (from IServerObjectAdmin2)

           OUTPUT
            ppLog               : IServerLog**'''
        return super(IServerObjectAdmin8, self).get_ServerLog()
    def Enable(self):
        '''Method IServerObjectAdmin2.Enable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin8, self).Enable()
    def Disable(self):
        '''Method IServerObjectAdmin2.Disable (from IServerObjectAdmin2)'''
        return super(IServerObjectAdmin8, self).Disable()
    def CreateExtensionType(self):
        '''Method IServerObjectAdmin2.CreateExtensionType (from IServerObjectAdmin2)

           OUTPUT
            ppSOEType           : IServerObjectExtensionType**'''
        return super(IServerObjectAdmin8, self).CreateExtensionType()
    def AddExtensionType(self, SOTypeName, pSOEType):
        '''Method IServerObjectAdmin2.AddExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            pSOEType            : IServerObjectExtensionType*'''
        return super(IServerObjectAdmin8, self).AddExtensionType(SOTypeName, pSOEType)
    def DeleteExtensionType(self, SOTypeName, SOETypeName):
        '''Method IServerObjectAdmin2.DeleteExtensionType (from IServerObjectAdmin2)

           INPUTS
            SOTypeName          : BSTR
            SOETypeName         : BSTR'''
        return super(IServerObjectAdmin8, self).DeleteExtensionType(SOTypeName, SOETypeName)
    def CreateFolder(self, folderName):
        '''Method IServerObjectAdmin2.CreateFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin8, self).CreateFolder(folderName)
    def DeleteFolder(self, folderName):
        '''Method IServerObjectAdmin2.DeleteFolder (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR'''
        return super(IServerObjectAdmin8, self).DeleteFolder(folderName)
    def RenameFolder(self, folderName, newName):
        '''Method IServerObjectAdmin2.RenameFolder (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            newName             : BSTR'''
        return super(IServerObjectAdmin8, self).RenameFolder(folderName, newName)
    def GetFolders(self, folderName):
        '''Method IServerObjectAdmin2.GetFolders (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumBSTR**'''
        return super(IServerObjectAdmin8, self).GetFolders(folderName)
    def get_FolderInfo(self, folderName):
        '''Method IServerObjectAdmin2.get_FolderInfo (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppInfo              : IPropertySet**'''
        return super(IServerObjectAdmin8, self).get_FolderInfo(folderName)
    def put_FolderInfo(self, folderName, ppInfo):
        '''Method IServerObjectAdmin2.put_FolderInfo (from IServerObjectAdmin2)

           INPUTS
            folderName          : BSTR
            ppInfo              : IPropertySet*'''
        return super(IServerObjectAdmin8, self).put_FolderInfo(folderName, ppInfo)
    def GetConfigurationsEx(self, folderName):
        '''Method IServerObjectAdmin2.GetConfigurationsEx (from IServerObjectAdmin2)

           INPUT
            folderName          : BSTR

           OUTPUT
            ppEnum              : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin8, self).GetConfigurationsEx(folderName)
    def ValidateConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin2.ValidateConfiguration (from IServerObjectAdmin2)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin8, self).ValidateConfiguration(Name, TypeName)
    def CreateServerDirectory(self):
        '''Method IServerObjectAdmin.CreateServerDirectory (from IServerObjectAdmin)

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin8, self).CreateServerDirectory()
    def AddServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.AddServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin8, self).AddServerDirectory(pSD)
    def UpdateServerDirectory(self, pSD):
        '''Method IServerObjectAdmin.UpdateServerDirectory (from IServerObjectAdmin)

           INPUT
            pSD                 : IServerDirectory*'''
        return super(IServerObjectAdmin8, self).UpdateServerDirectory(pSD)
    def DeleteServerDirectory(self, Path):
        '''Method IServerObjectAdmin.DeleteServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR'''
        return super(IServerObjectAdmin8, self).DeleteServerDirectory(Path)
    def GetServerDirectory(self, Path):
        '''Method IServerObjectAdmin.GetServerDirectory (from IServerObjectAdmin)

           INPUT
            Path                : BSTR

           OUTPUT
            ppSD                : IServerDirectory**'''
        return super(IServerObjectAdmin8, self).GetServerDirectory(Path)
    def GetServerDirectories(self):
        '''Method IServerObjectAdmin.GetServerDirectories (from IServerObjectAdmin)

           OUTPUT
            ppEnum              : IEnumServerDirectory**'''
        return super(IServerObjectAdmin8, self).GetServerDirectories()
    def CreateConfiguration(self):
        '''Method IServerObjectAdmin.CreateConfiguration (from IServerObjectAdmin)

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin8, self).CreateConfiguration()
    def AddConfiguration(self, config):
        '''Method IServerObjectAdmin.AddConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin8, self).AddConfiguration(config)
    def GetConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            config              : IServerObjectConfiguration**'''
        return super(IServerObjectAdmin8, self).GetConfiguration(Name, TypeName)
    def UpdateConfiguration(self, config):
        '''Method IServerObjectAdmin.UpdateConfiguration (from IServerObjectAdmin)

           INPUT
            config              : IServerObjectConfiguration*'''
        return super(IServerObjectAdmin8, self).UpdateConfiguration(config)
    def DeleteConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.DeleteConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin8, self).DeleteConfiguration(Name, TypeName)
    def GetConfigurations(self):
        '''Method IServerObjectAdmin.GetConfigurations (from IServerObjectAdmin)

           OUTPUT
            ppConfigs           : IEnumServerObjectConfiguration**'''
        return super(IServerObjectAdmin8, self).GetConfigurations()
    def GetConfigurationStatus(self, Name, TypeName):
        '''Method IServerObjectAdmin.GetConfigurationStatus (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR

           OUTPUT
            ppStatus            : IServerObjectConfigurationStatus**'''
        return super(IServerObjectAdmin8, self).GetConfigurationStatus(Name, TypeName)
    def GetTypes(self):
        '''Method IServerObjectAdmin.GetTypes (from IServerObjectAdmin)

           OUTPUT
            ppTypes             : IEnumServerObjectType**'''
        return super(IServerObjectAdmin8, self).GetTypes()
    def StartConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StartConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin8, self).StartConfiguration(Name, TypeName)
    def StopConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.StopConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin8, self).StopConfiguration(Name, TypeName)
    def PauseConfiguration(self, Name, TypeName):
        '''Method IServerObjectAdmin.PauseConfiguration (from IServerObjectAdmin)

           INPUTS
            Name                : BSTR
            TypeName            : BSTR'''
        return super(IServerObjectAdmin8, self).PauseConfiguration(Name, TypeName)
    def CreateMachine(self):
        '''Method IServerObjectAdmin.CreateMachine (from IServerObjectAdmin)

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin8, self).CreateMachine()
    def AddMachine(self, Machine):
        '''Method IServerObjectAdmin.AddMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin8, self).AddMachine(Machine)
    def GetMachines(self):
        '''Method IServerObjectAdmin.GetMachines (from IServerObjectAdmin)

           OUTPUT
            machines            : IEnumServerMachine**'''
        return super(IServerObjectAdmin8, self).GetMachines()
    def DeleteMachine(self, MachineName):
        '''Method IServerObjectAdmin.DeleteMachine (from IServerObjectAdmin)

           INPUT
            MachineName         : BSTR'''
        return super(IServerObjectAdmin8, self).DeleteMachine(MachineName)
    def GetMachine(self, Name):
        '''Method IServerObjectAdmin.GetMachine (from IServerObjectAdmin)

           INPUT
            Name                : BSTR

           OUTPUT
            Machine             : IServerMachine**'''
        return super(IServerObjectAdmin8, self).GetMachine(Name)
    def UpdateMachine(self, Machine):
        '''Method IServerObjectAdmin.UpdateMachine (from IServerObjectAdmin)

           INPUT
            Machine             : IServerMachine*'''
        return super(IServerObjectAdmin8, self).UpdateMachine(Machine)
    def get_Properties(self):
        '''Method IServerObjectAdmin.get_Properties (from IServerObjectAdmin)

           OUTPUT
            props               : IPropertySet**'''
        return super(IServerObjectAdmin8, self).get_Properties()
    def put_Properties(self, props):
        '''Method IServerObjectAdmin.put_Properties (from IServerObjectAdmin)

           INPUT
            props               : IPropertySet*'''
        return super(IServerObjectAdmin8, self).put_Properties(props)
    FolderInfo = property(None, put_FolderInfo, None)
    Geodatabases = property(get_Geodatabases, None, None)
    IsSecurityEnabled = property(get_IsSecurityEnabled, put_IsSecurityEnabled, None)
    Properties = property(get_Properties, put_Properties, None)
    ServerLog = property(get_ServerLog, None, None)
    FolderInfo = IndexProperty(get_FolderInfo, None)

class IServerLog2(_esriServer.IServerLog2):
    _IID = uuid.UUID('b7729ab3-6fd1-402d-9162-ae21b9ec545e')
    def ReleaseLog(self):
        '''Method IServerLog2.ReleaseLog'''
        return super(IServerLog2, self).ReleaseLog()

class IServerTimeRange(_esriServer.IServerTimeRange):
    _IID = uuid.UUID('37786a30-fec4-4ea4-953e-dac6b69c716d')
    def get_StartTime(self):
        '''Method IServerTimeRange.get_StartTime

           OUTPUT
            pTime               : DATE*'''
        return super(IServerTimeRange, self).get_StartTime()
    def get_EndTime(self):
        '''Method IServerTimeRange.get_EndTime

           OUTPUT
            pTime               : DATE*'''
        return super(IServerTimeRange, self).get_EndTime()
    EndTime = property(get_EndTime, None, None)
    StartTime = property(get_StartTime, None, None)

class IServerObjectConfigurationManager(_esriServer.IServerObjectConfigurationManager):
    _IID = uuid.UUID('181f5a7e-25c9-4fbf-9166-75d638acc930')
    def OnAdd(self, pProps):
        '''Method IServerObjectConfigurationManager.OnAdd

           INPUT
            pProps              : IPropertySet*

           OUTPUT
            ppNewProps          : IPropertySet**'''
        return super(IServerObjectConfigurationManager, self).OnAdd(pProps)
    def OnRemove(self):
        '''Method IServerObjectConfigurationManager.OnRemove'''
        return super(IServerObjectConfigurationManager, self).OnRemove()

class IServerObjectConfigurationManager2(_esriServer.IServerObjectConfigurationManager2):
    _IID = uuid.UUID('3130f209-598d-4269-b404-df6b13804742')
    def OnStart(self, pAdmin, pProps):
        '''Method IServerObjectConfigurationManager2.OnStart

           INPUTS
            pAdmin              : IServerObjectAdmin*
            pProps              : IPropertySet*'''
        return super(IServerObjectConfigurationManager2, self).OnStart(pAdmin, pProps)
    def OnStop(self, pAdmin, pProps):
        '''Method IServerObjectConfigurationManager2.OnStop

           INPUTS
            pAdmin              : IServerObjectAdmin*
            pProps              : IPropertySet*'''
        return super(IServerObjectConfigurationManager2, self).OnStop(pAdmin, pProps)
    def OnRemoveEx(self, pAdmin, props):
        '''Method IServerObjectConfigurationManager2.OnRemoveEx

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IServerObjectConfigurationManager2, self).OnRemoveEx(pAdmin, props)
    def BeforeStart(self, pAdmin, props):
        '''Method IServerObjectConfigurationManager2.BeforeStart

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IServerObjectConfigurationManager2, self).BeforeStart(pAdmin, props)
    def BeforeStop(self, pAdmin, props):
        '''Method IServerObjectConfigurationManager2.BeforeStop

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IServerObjectConfigurationManager2, self).BeforeStop(pAdmin, props)
    def OnAdd(self, pProps):
        '''Method IServerObjectConfigurationManager.OnAdd (from IServerObjectConfigurationManager)

           INPUT
            pProps              : IPropertySet*

           OUTPUT
            ppNewProps          : IPropertySet**'''
        return super(IServerObjectConfigurationManager2, self).OnAdd(pProps)
    def OnRemove(self):
        '''Method IServerObjectConfigurationManager.OnRemove (from IServerObjectConfigurationManager)'''
        return super(IServerObjectConfigurationManager2, self).OnRemove()

class IConfigurationFactory2(_esriServer.IConfigurationFactory2):
    _IID = uuid.UUID('702ecf93-89d3-438d-b218-f1686c813f0f')
    def BeforeStart(self, pAdmin, props):
        '''Method IConfigurationFactory2.BeforeStart

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory2, self).BeforeStart(pAdmin, props)
    def BeforeStop(self, pAdmin, props):
        '''Method IConfigurationFactory2.BeforeStop

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory2, self).BeforeStop(pAdmin, props)
    def OnRemoveEx(self, pAdmin, props):
        '''Method IConfigurationFactory2.OnRemoveEx

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory2, self).OnRemoveEx(pAdmin, props)
    def OnAdd(self, pAdmin, pProps):
        '''Method IConfigurationFactory.OnAdd (from IConfigurationFactory)

           INPUTS
            pAdmin              : IServerObjectAdmin*
            pProps              : IPropertySet*

           OUTPUT
            ppNewProps          : IPropertySet**'''
        return super(IConfigurationFactory2, self).OnAdd(pAdmin, pProps)
    def OnRemove(self):
        '''Method IConfigurationFactory.OnRemove (from IConfigurationFactory)'''
        return super(IConfigurationFactory2, self).OnRemove()
    def OnStart(self, pAdmin, props):
        '''Method IConfigurationFactory.OnStart (from IConfigurationFactory)

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory2, self).OnStart(pAdmin, props)
    def OnStop(self, pAdmin, props):
        '''Method IConfigurationFactory.OnStop (from IConfigurationFactory)

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory2, self).OnStop(pAdmin, props)

class IConfigurationFactory3(_esriServer.IConfigurationFactory3):
    _IID = uuid.UUID('1edfa167-4404-4295-b5bb-cc06a062f55c')
    def OnRename(self, pAdmin, props):
        '''Method IConfigurationFactory3.OnRename

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*

           OUTPUT
            ppNewProps          : IPropertySet**'''
        return super(IConfigurationFactory3, self).OnRename(pAdmin, props)
    def BeforeStart(self, pAdmin, props):
        '''Method IConfigurationFactory2.BeforeStart (from IConfigurationFactory2)

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory3, self).BeforeStart(pAdmin, props)
    def BeforeStop(self, pAdmin, props):
        '''Method IConfigurationFactory2.BeforeStop (from IConfigurationFactory2)

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory3, self).BeforeStop(pAdmin, props)
    def OnRemoveEx(self, pAdmin, props):
        '''Method IConfigurationFactory2.OnRemoveEx (from IConfigurationFactory2)

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory3, self).OnRemoveEx(pAdmin, props)
    def OnAdd(self, pAdmin, pProps):
        '''Method IConfigurationFactory.OnAdd (from IConfigurationFactory)

           INPUTS
            pAdmin              : IServerObjectAdmin*
            pProps              : IPropertySet*

           OUTPUT
            ppNewProps          : IPropertySet**'''
        return super(IConfigurationFactory3, self).OnAdd(pAdmin, pProps)
    def OnRemove(self):
        '''Method IConfigurationFactory.OnRemove (from IConfigurationFactory)'''
        return super(IConfigurationFactory3, self).OnRemove()
    def OnStart(self, pAdmin, props):
        '''Method IConfigurationFactory.OnStart (from IConfigurationFactory)

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory3, self).OnStart(pAdmin, props)
    def OnStop(self, pAdmin, props):
        '''Method IConfigurationFactory.OnStop (from IConfigurationFactory)

           INPUTS
            pAdmin              : IServerObjectAdmin*
            props               : IPropertySet*'''
        return super(IConfigurationFactory3, self).OnStop(pAdmin, props)

class IServerEnvironmentEx(_esriServer.IServerEnvironmentEx):
    _IID = uuid.UUID('ab1ffdae-9b92-4e97-b3da-ea251258d8af')
    def GetServerDirectoryInfos(self):
        '''Method IServerEnvironmentEx.GetServerDirectoryInfos

           OUTPUT
            ppEnum              : IEnumServerDirectoryInfo**'''
        return super(IServerEnvironmentEx, self).GetServerDirectoryInfos()

class IServerConfigurationStorage(_esriServer.IServerConfigurationStorage):
    _IID = uuid.UUID('53011377-69ef-42e5-93c8-26735b801969')
    def Connect(self, connectionString):
        '''Method IServerConfigurationStorage.Connect

           INPUT
            connectionString    : BSTR'''
        return super(IServerConfigurationStorage, self).Connect(connectionString)
    def GetUpdateIDs(self):
        '''Method IServerConfigurationStorage.GetUpdateIDs

           OUTPUTS
            pServerUpdateID     : BSTR*
            pServicesUpdateID   : BSTR*
            pFoldersUpdateID    : BSTR*
            pPermissionsUpdateID: BSTR*
            pLogUpdateID        : BSTR*
            pGDBUpdateID        : BSTR*'''
        return super(IServerConfigurationStorage, self).GetUpdateIDs()
    def GetServerProperty(self, Name):
        '''Method IServerConfigurationStorage.GetServerProperty

           INPUT
            Name                : BSTR

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerConfigurationStorage, self).GetServerProperty(Name)
    def PutServerProperty(self, Name, Val):
        '''Method IServerConfigurationStorage.PutServerProperty

           INPUTS
            Name                : BSTR
            Val                 : BSTR'''
        return super(IServerConfigurationStorage, self).PutServerProperty(Name, Val)
    def get_ServerProperties(self):
        '''Method IServerConfigurationStorage.get_ServerProperties

           OUTPUT
            pList               : BSTR*'''
        return super(IServerConfigurationStorage, self).get_ServerProperties()
    def AddFolder(self, folderName, Info):
        '''Method IServerConfigurationStorage.AddFolder

           INPUTS
            folderName          : BSTR
            Info                : BSTR'''
        return super(IServerConfigurationStorage, self).AddFolder(folderName, Info)
    def DeleteFolder(self, folderName):
        '''Method IServerConfigurationStorage.DeleteFolder

           INPUT
            folderName          : BSTR'''
        return super(IServerConfigurationStorage, self).DeleteFolder(folderName)
    def RenameFolder(self, OldName, newName):
        '''Method IServerConfigurationStorage.RenameFolder

           INPUTS
            OldName             : BSTR
            newName             : BSTR'''
        return super(IServerConfigurationStorage, self).RenameFolder(OldName, newName)
    def get_Folders(self):
        '''Method IServerConfigurationStorage.get_Folders

           OUTPUT
            pList               : BSTR*'''
        return super(IServerConfigurationStorage, self).get_Folders()
    def GetFolderInfo(self, folderName):
        '''Method IServerConfigurationStorage.GetFolderInfo

           INPUT
            folderName          : BSTR

           OUTPUTS
            pUpdateID           : BSTR*
            pVal                : BSTR*'''
        return super(IServerConfigurationStorage, self).GetFolderInfo(folderName)
    def PutFolderInfo(self, folderName, Val):
        '''Method IServerConfigurationStorage.PutFolderInfo

           INPUTS
            folderName          : BSTR
            Val                 : BSTR'''
        return super(IServerConfigurationStorage, self).PutFolderInfo(folderName, Val)
    def AddService(self, ID, definition):
        '''Method IServerConfigurationStorage.AddService

           INPUTS
            ID                  : BSTR
            definition          : BSTR'''
        return super(IServerConfigurationStorage, self).AddService(ID, definition)
    def DeleteService(self, ID):
        '''Method IServerConfigurationStorage.DeleteService

           INPUT
            ID                  : BSTR'''
        return super(IServerConfigurationStorage, self).DeleteService(ID)
    def get_Services(self):
        '''Method IServerConfigurationStorage.get_Services

           OUTPUT
            pList               : BSTR*'''
        return super(IServerConfigurationStorage, self).get_Services()
    def GetServiceDefinition(self, ID):
        '''Method IServerConfigurationStorage.GetServiceDefinition

           INPUT
            ID                  : BSTR

           OUTPUTS
            pUpdateID           : BSTR*
            pVal                : BSTR*'''
        return super(IServerConfigurationStorage, self).GetServiceDefinition(ID)
    def PutServiceDefinition(self, ID, Val):
        '''Method IServerConfigurationStorage.PutServiceDefinition

           INPUTS
            ID                  : BSTR
            Val                 : BSTR'''
        return super(IServerConfigurationStorage, self).PutServiceDefinition(ID, Val)
    def GetServiceIsStarted(self, ID):
        '''Method IServerConfigurationStorage.GetServiceIsStarted

           INPUT
            ID                  : BSTR

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IServerConfigurationStorage, self).GetServiceIsStarted(ID)
    def PutServiceIsStarted(self, ID, Val):
        '''Method IServerConfigurationStorage.PutServiceIsStarted

           INPUTS
            ID                  : BSTR
            Val                 : VARIANT_BOOL'''
        return super(IServerConfigurationStorage, self).PutServiceIsStarted(ID, Val)
    def AddPermission(self, ResourceID, acl):
        '''Method IServerConfigurationStorage.AddPermission

           INPUTS
            ResourceID          : BSTR
            acl                 : BSTR'''
        return super(IServerConfigurationStorage, self).AddPermission(ResourceID, acl)
    def DeletePermission(self, ResourceID):
        '''Method IServerConfigurationStorage.DeletePermission

           INPUT
            ResourceID          : BSTR'''
        return super(IServerConfigurationStorage, self).DeletePermission(ResourceID)
    def get_Permissions(self):
        '''Method IServerConfigurationStorage.get_Permissions

           OUTPUT
            pList               : BSTR*'''
        return super(IServerConfigurationStorage, self).get_Permissions()
    def GetACL(self, ResourceID):
        '''Method IServerConfigurationStorage.GetACL

           INPUT
            ResourceID          : BSTR

           OUTPUTS
            pUpdateID           : BSTR*
            pVal                : BSTR*'''
        return super(IServerConfigurationStorage, self).GetACL(ResourceID)
    def PutACL(self, ResourceID, Val):
        '''Method IServerConfigurationStorage.PutACL

           INPUTS
            ResourceID          : BSTR
            Val                 : BSTR'''
        return super(IServerConfigurationStorage, self).PutACL(ResourceID, Val)
    def AddGeodatabase(self, gdbName, Val):
        '''Method IServerConfigurationStorage.AddGeodatabase

           INPUTS
            gdbName             : BSTR
            Val                 : BSTR'''
        return super(IServerConfigurationStorage, self).AddGeodatabase(gdbName, Val)
    def DeleteGeodatabase(self, gdbName):
        '''Method IServerConfigurationStorage.DeleteGeodatabase

           INPUT
            gdbName             : BSTR'''
        return super(IServerConfigurationStorage, self).DeleteGeodatabase(gdbName)
    def get_Geodatabases(self):
        '''Method IServerConfigurationStorage.get_Geodatabases

           OUTPUT
            pList               : BSTR*'''
        return super(IServerConfigurationStorage, self).get_Geodatabases()
    def GetGeodatabase(self, gdbName):
        '''Method IServerConfigurationStorage.GetGeodatabase

           INPUT
            gdbName             : BSTR

           OUTPUTS
            pUpdateID           : BSTR*
            pVal                : BSTR*'''
        return super(IServerConfigurationStorage, self).GetGeodatabase(gdbName)
    def PutGeodatabase(self, gdbName, Val):
        '''Method IServerConfigurationStorage.PutGeodatabase

           INPUTS
            gdbName             : BSTR
            Val                 : BSTR'''
        return super(IServerConfigurationStorage, self).PutGeodatabase(gdbName, Val)
    def get_LogFiles(self):
        '''Method IServerConfigurationStorage.get_LogFiles

           OUTPUT
            pList               : BSTR*'''
        return super(IServerConfigurationStorage, self).get_LogFiles()
    def PutLogFile(self, fileName, DateCreated, DateModified, Log):
        '''Method IServerConfigurationStorage.PutLogFile

           INPUTS
            fileName            : BSTR
            DateCreated         : DATE
            DateModified        : DATE
            Log                 : BSTR'''
        return super(IServerConfigurationStorage, self).PutLogFile(fileName, DateCreated, DateModified, Log)
    def GetLogFile(self, fileName):
        '''Method IServerConfigurationStorage.GetLogFile

           INPUT
            fileName            : BSTR

           OUTPUTS
            pDateCreated        : DATE*
            pDateModified       : DATE*
            pLog                : BSTR*'''
        return super(IServerConfigurationStorage, self).GetLogFile(fileName)
    def DeleteLogFile(self, fileName):
        '''Method IServerConfigurationStorage.DeleteLogFile

           INPUT
            fileName            : BSTR'''
        return super(IServerConfigurationStorage, self).DeleteLogFile(fileName)
    Folders = property(get_Folders, None, None)
    Geodatabases = property(get_Geodatabases, None, None)
    LogFiles = property(get_LogFiles, None, None)
    Permissions = property(get_Permissions, None, None)
    ServerProperties = property(get_ServerProperties, None, None)
    Services = property(get_Services, None, None)

class IServerJobManager(_esriServer.IServerJobManager):
    _IID = uuid.UUID('66210bab-f71d-4ecc-8823-6bf8431a5bb4')
    def ExecuteJob(self, cfgName, cfgType, jobID):
        '''Method IServerJobManager.ExecuteJob

           INPUTS
            cfgName             : BSTR
            cfgType             : BSTR
            jobID               : BSTR'''
        return super(IServerJobManager, self).ExecuteJob(cfgName, cfgType, jobID)
    def CheckJob(self, jobID):
        '''Method IServerJobManager.CheckJob

           INPUT
            jobID               : BSTR

           OUTPUT
            bRes                : VARIANT_BOOL*'''
        return super(IServerJobManager, self).CheckJob(jobID)
    def CancelJob(self, jobID):
        '''Method IServerJobManager.CancelJob

           INPUT
            jobID               : BSTR'''
        return super(IServerJobManager, self).CancelJob(jobID)

class IServerEnvironmentImpl(_esriServer.IServerEnvironmentImpl):
    _IID = uuid.UUID('73e0f44f-9e93-4309-a29b-2d6fdde36536')

    def __init__(self, *args, **kw):
        super(IServerEnvironmentImpl, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_CurrentJobID(self, _arg1):
        '''Method IServerEnvironmentImpl.put_CurrentJobID

           INPUT
            _arg1               : BSTR'''
        return super(IServerEnvironmentImpl, self).put_CurrentJobID(_arg1)
    def put_IsAdmin(self, _arg1):
        '''Method IServerEnvironmentImpl.put_IsAdmin

           INPUT
            _arg1               : VARIANT_BOOL'''
        return super(IServerEnvironmentImpl, self).put_IsAdmin(_arg1)
    def get_JobCatalog(self):
        '''Method IServerEnvironmentImpl.get_JobCatalog

           OUTPUT
            ppJC                : IJobCatalog**'''
        return super(IServerEnvironmentImpl, self).get_JobCatalog()
    def get_ServerJobManager(self):
        '''Method IServerEnvironmentImpl.get_ServerJobManager

           OUTPUT
            ppSJM               : IServerJobManager**'''
        return super(IServerEnvironmentImpl, self).get_ServerJobManager()
    def get_ServerObjectAdmin(self):
        '''Method IServerEnvironmentImpl.get_ServerObjectAdmin

           OUTPUT
            ppSOA               : IServerObjectAdmin**'''
        return super(IServerEnvironmentImpl, self).get_ServerObjectAdmin()
    def get_JobRegistry(self):
        '''Method IServerEnvironmentImpl.get_JobRegistry

           OUTPUT
            ppJR                : IJobRegistry**'''
        return super(IServerEnvironmentImpl, self).get_JobRegistry()
    def get_StorageConnectionString(self):
        '''Method IServerEnvironmentImpl.get_StorageConnectionString

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerEnvironmentImpl, self).get_StorageConnectionString()
    CurrentJobID = property(None, put_CurrentJobID, None)
    IsAdmin = property(None, put_IsAdmin, None)
    JobCatalog = property(get_JobCatalog, None, None)
    JobRegistry = property(get_JobRegistry, None, None)
    ServerJobManager = property(get_ServerJobManager, None, None)
    ServerObjectAdmin = property(get_ServerObjectAdmin, None, None)
    StorageConnectionString = property(get_StorageConnectionString, None, None)

class IServerEnvironmentImpl2(_esriServer.IServerEnvironmentImpl2):
    _IID = uuid.UUID('e027774d-ca6e-430e-97c0-6f4b1c67cc82')

    def __init__(self, *args, **kw):
        super(IServerEnvironmentImpl2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Log(self, _arg1):
        '''Method IServerEnvironmentImpl2.put_Log

           INPUT
            _arg1               : ILog*'''
        return super(IServerEnvironmentImpl2, self).put_Log(_arg1)
    def put_Properties(self, _arg1):
        '''Method IServerEnvironmentImpl2.put_Properties

           INPUT
            _arg1               : IPropertySet*'''
        return super(IServerEnvironmentImpl2, self).put_Properties(_arg1)
    def put_JobTracker(self, _arg1):
        '''Method IServerEnvironmentImpl2.put_JobTracker

           INPUT
            _arg1               : IJobTracker*'''
        return super(IServerEnvironmentImpl2, self).put_JobTracker(_arg1)
    def put_JobRegistry(self, _arg1):
        '''Method IServerEnvironmentImpl2.put_JobRegistry

           INPUT
            _arg1               : IJobRegistry*'''
        return super(IServerEnvironmentImpl2, self).put_JobRegistry(_arg1)
    def put_ServerJobManager(self, _arg1):
        '''Method IServerEnvironmentImpl2.put_ServerJobManager

           INPUT
            _arg1               : IServerJobManager*'''
        return super(IServerEnvironmentImpl2, self).put_ServerJobManager(_arg1)
    def put_ServerObjectAdmin(self, _arg1):
        '''Method IServerEnvironmentImpl2.put_ServerObjectAdmin

           INPUT
            _arg1               : IServerObjectAdmin*'''
        return super(IServerEnvironmentImpl2, self).put_ServerObjectAdmin(_arg1)
    def put_UserInfo(self, _arg1):
        '''Method IServerEnvironmentImpl2.put_UserInfo

           INPUT
            _arg1               : IServerUserInfo*'''
        return super(IServerEnvironmentImpl2, self).put_UserInfo(_arg1)
    def put_CurrentJobID(self, _arg1):
        '''Method IServerEnvironmentImpl.put_CurrentJobID (from IServerEnvironmentImpl)

           INPUT
            _arg1               : BSTR'''
        return super(IServerEnvironmentImpl2, self).put_CurrentJobID(_arg1)
    def put_IsAdmin(self, _arg1):
        '''Method IServerEnvironmentImpl.put_IsAdmin (from IServerEnvironmentImpl)

           INPUT
            _arg1               : VARIANT_BOOL'''
        return super(IServerEnvironmentImpl2, self).put_IsAdmin(_arg1)
    def get_JobCatalog(self):
        '''Method IServerEnvironmentImpl.get_JobCatalog (from IServerEnvironmentImpl)

           OUTPUT
            ppJC                : IJobCatalog**'''
        return super(IServerEnvironmentImpl2, self).get_JobCatalog()
    def get_ServerJobManager(self):
        '''Method IServerEnvironmentImpl.get_ServerJobManager (from IServerEnvironmentImpl)

           OUTPUT
            ppSJM               : IServerJobManager**'''
        return super(IServerEnvironmentImpl2, self).get_ServerJobManager()
    def get_ServerObjectAdmin(self):
        '''Method IServerEnvironmentImpl.get_ServerObjectAdmin (from IServerEnvironmentImpl)

           OUTPUT
            ppSOA               : IServerObjectAdmin**'''
        return super(IServerEnvironmentImpl2, self).get_ServerObjectAdmin()
    def get_JobRegistry(self):
        '''Method IServerEnvironmentImpl.get_JobRegistry (from IServerEnvironmentImpl)

           OUTPUT
            ppJR                : IJobRegistry**'''
        return super(IServerEnvironmentImpl2, self).get_JobRegistry()
    def get_StorageConnectionString(self):
        '''Method IServerEnvironmentImpl.get_StorageConnectionString (from IServerEnvironmentImpl)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServerEnvironmentImpl2, self).get_StorageConnectionString()
    CurrentJobID = property(None, put_CurrentJobID, None)
    IsAdmin = property(None, put_IsAdmin, None)
    JobCatalog = property(get_JobCatalog, None, None)
    JobRegistry = property(get_JobRegistry, put_JobRegistry, None)
    JobTracker = property(None, put_JobTracker, None)
    Log = property(None, put_Log, None)
    Properties = property(None, put_Properties, None)
    ServerJobManager = property(get_ServerJobManager, put_ServerJobManager, None)
    ServerObjectAdmin = property(get_ServerObjectAdmin, put_ServerObjectAdmin, None)
    StorageConnectionString = property(get_StorageConnectionString, None, None)
    UserInfo = property(None, put_UserInfo, None)

class IServer(_esriServer.IServer):
    _IID = uuid.UUID('425b0a5b-bf1b-4f0e-9e75-37324a12e5f9')
    def get_ServerObjectManager(self):
        '''Method IServer.get_ServerObjectManager

           OUTPUT
            mgr                 : IServerObjectManager**'''
        return super(IServer, self).get_ServerObjectManager()
    def get_ServerObjectAdmin(self):
        '''Method IServer.get_ServerObjectAdmin

           OUTPUT
            admin               : IServerObjectAdmin**'''
        return super(IServer, self).get_ServerObjectAdmin()
    ServerObjectAdmin = property(get_ServerObjectAdmin, None, None)
    ServerObjectManager = property(get_ServerObjectManager, None, None)

class IServer2(_esriServer.IServer2):
    _IID = uuid.UUID('0741d66c-c157-4b4d-af5e-c74c68ba8386')
    def get_ServerObjectManager2(self, UserInfo):
        '''Method IServer2.get_ServerObjectManager2

           INPUT
            UserInfo            : BSTR

           OUTPUT
            mgr                 : IServerObjectManager**'''
        return super(IServer2, self).get_ServerObjectManager2(UserInfo)
    def get_ServerObjectManager(self):
        '''Method IServer.get_ServerObjectManager (from IServer)

           OUTPUT
            mgr                 : IServerObjectManager**'''
        return super(IServer2, self).get_ServerObjectManager()
    def get_ServerObjectAdmin(self):
        '''Method IServer.get_ServerObjectAdmin (from IServer)

           OUTPUT
            admin               : IServerObjectAdmin**'''
        return super(IServer2, self).get_ServerObjectAdmin()
    ServerObjectAdmin = property(get_ServerObjectAdmin, None, None)
    ServerObjectManager = property(get_ServerObjectManager, None, None)
    ServerObjectManager2 = IndexProperty(get_ServerObjectManager2, None)

class IServerInit(_esriServer.IServerInit):
    _IID = uuid.UUID('a49dd957-aadb-4fe4-89c1-d80bb586970a')
    def InitPrivateServer(self, dir):
        '''Method IServerInit.InitPrivateServer

           INPUT
            dir                 : BSTR'''
        return super(IServerInit, self).InitPrivateServer(dir)

class IServerInit2(_esriServer.IServerInit2):
    _IID = uuid.UUID('30d53022-c566-4854-87d8-2b9022829211')
    def InitPrivateServerEx(self, serverDir, logDir):
        '''Method IServerInit2.InitPrivateServerEx

           INPUTS
            serverDir           : BSTR
            logDir              : BSTR'''
        return super(IServerInit2, self).InitPrivateServerEx(serverDir, logDir)
    def InitPrivateServer(self, dir):
        '''Method IServerInit.InitPrivateServer (from IServerInit)

           INPUT
            dir                 : BSTR'''
        return super(IServerInit2, self).InitPrivateServer(dir)

class IGISServerConnection(_esriServer.IGISServerConnection):
    _IID = uuid.UUID('e3105184-0aad-4706-9269-dcb5ff52036d')
    def Connect(self, MachineName):
        '''Method IGISServerConnection.Connect

           INPUT
            MachineName         : BSTR'''
        return super(IGISServerConnection, self).Connect(MachineName)
    def get_ServerObjectManager(self):
        '''Method IGISServerConnection.get_ServerObjectManager

           OUTPUT
            mgr                 : IServerObjectManager**'''
        return super(IGISServerConnection, self).get_ServerObjectManager()
    def get_ServerObjectAdmin(self):
        '''Method IGISServerConnection.get_ServerObjectAdmin

           OUTPUT
            admin               : IServerObjectAdmin**'''
        return super(IGISServerConnection, self).get_ServerObjectAdmin()
    ServerObjectAdmin = property(get_ServerObjectAdmin, None, None)
    ServerObjectManager = property(get_ServerObjectManager, None, None)

class IGISServerConnection2(_esriServer.IGISServerConnection2):
    _IID = uuid.UUID('f6616298-396a-41f2-9a5b-0eed59af2e40')
    def Connect2(self, UserInfo, MachineName):
        '''Method IGISServerConnection2.Connect2

           INPUTS
            UserInfo            : BSTR
            MachineName         : BSTR'''
        return super(IGISServerConnection2, self).Connect2(UserInfo, MachineName)
    def Connect(self, MachineName):
        '''Method IGISServerConnection.Connect (from IGISServerConnection)

           INPUT
            MachineName         : BSTR'''
        return super(IGISServerConnection2, self).Connect(MachineName)
    def get_ServerObjectManager(self):
        '''Method IGISServerConnection.get_ServerObjectManager (from IGISServerConnection)

           OUTPUT
            mgr                 : IServerObjectManager**'''
        return super(IGISServerConnection2, self).get_ServerObjectManager()
    def get_ServerObjectAdmin(self):
        '''Method IGISServerConnection.get_ServerObjectAdmin (from IGISServerConnection)

           OUTPUT
            admin               : IServerObjectAdmin**'''
        return super(IGISServerConnection2, self).get_ServerObjectAdmin()
    ServerObjectAdmin = property(get_ServerObjectAdmin, None, None)
    ServerObjectManager = property(get_ServerObjectManager, None, None)

class IServiceDescription2(_esriServer.IServiceDescription2):
    _IID = uuid.UUID('081c203c-3b90-4de2-af43-7c30bbfe22e9')

    def __init__(self, *args, **kw):
        super(IServiceDescription2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ParentType(self):
        '''Method IServiceDescription2.get_ParentType

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription2, self).get_ParentType()
    def put_ParentType(self, pVal):
        '''Method IServiceDescription2.put_ParentType

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription2, self).put_ParentType(pVal)
    def get_Capabilities(self):
        '''Method IServiceDescription2.get_Capabilities

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription2, self).get_Capabilities()
    def put_Capabilities(self, pVal):
        '''Method IServiceDescription2.put_Capabilities

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription2, self).put_Capabilities(pVal)
    def get_Name(self):
        '''Method IServiceDescription.get_Name (from IServiceDescription)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription2, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServiceDescription.put_Name (from IServiceDescription)

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription2, self).put_Name(pVal)
    def get_Type(self):
        '''Method IServiceDescription.get_Type (from IServiceDescription)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription2, self).get_Type()
    def put_Type(self, pVal):
        '''Method IServiceDescription.put_Type (from IServiceDescription)

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription2, self).put_Type(pVal)
    def get_URL(self):
        '''Method IServiceDescription.get_URL (from IServiceDescription)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription2, self).get_URL()
    def put_URL(self, pVal):
        '''Method IServiceDescription.put_URL (from IServiceDescription)

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription2, self).put_URL(pVal)
    Capabilities = property(get_Capabilities, put_Capabilities, None)
    Name = property(get_Name, put_Name, None)
    ParentType = property(get_ParentType, put_ParentType, None)
    Type = property(get_Type, put_Type, None)
    URL = property(get_URL, put_URL, None)

class IServiceDescription3(_esriServer.IServiceDescription3):
    _IID = uuid.UUID('e6ce2e4a-2f2b-4d2b-82b8-85fa5aecffbc')

    def __init__(self, *args, **kw):
        super(IServiceDescription3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Description(self):
        '''Method IServiceDescription3.get_Description

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription3, self).get_Description()
    def put_Description(self, pVal):
        '''Method IServiceDescription3.put_Description

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription3, self).put_Description(pVal)
    def get_ParentType(self):
        '''Method IServiceDescription2.get_ParentType (from IServiceDescription2)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription3, self).get_ParentType()
    def put_ParentType(self, pVal):
        '''Method IServiceDescription2.put_ParentType (from IServiceDescription2)

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription3, self).put_ParentType(pVal)
    def get_Capabilities(self):
        '''Method IServiceDescription2.get_Capabilities (from IServiceDescription2)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription3, self).get_Capabilities()
    def put_Capabilities(self, pVal):
        '''Method IServiceDescription2.put_Capabilities (from IServiceDescription2)

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription3, self).put_Capabilities(pVal)
    def get_Name(self):
        '''Method IServiceDescription.get_Name (from IServiceDescription)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription3, self).get_Name()
    def put_Name(self, pVal):
        '''Method IServiceDescription.put_Name (from IServiceDescription)

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription3, self).put_Name(pVal)
    def get_Type(self):
        '''Method IServiceDescription.get_Type (from IServiceDescription)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription3, self).get_Type()
    def put_Type(self, pVal):
        '''Method IServiceDescription.put_Type (from IServiceDescription)

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription3, self).put_Type(pVal)
    def get_URL(self):
        '''Method IServiceDescription.get_URL (from IServiceDescription)

           OUTPUT
            pVal                : BSTR*'''
        return super(IServiceDescription3, self).get_URL()
    def put_URL(self, pVal):
        '''Method IServiceDescription.put_URL (from IServiceDescription)

           INPUT
            pVal                : BSTR'''
        return super(IServiceDescription3, self).put_URL(pVal)
    Capabilities = property(get_Capabilities, put_Capabilities, None)
    Description = property(get_Description, put_Description, None)
    Name = property(get_Name, put_Name, None)
    ParentType = property(get_ParentType, put_ParentType, None)
    Type = property(get_Type, put_Type, None)
    URL = property(get_URL, put_URL, None)

class IServiceCatalog3(_esriServer.IServiceCatalog3):
    _IID = uuid.UUID('bb163dc2-8ec3-4536-8b0c-7ffe7b91b7b0')
    def get_RequiresTokens(self):
        '''Method IServiceCatalog3.get_RequiresTokens

           OUTPUT
            RequiresTokens      : VARIANT_BOOL*'''
        return super(IServiceCatalog3, self).get_RequiresTokens()
    def get_TokenServiceURL(self):
        '''Method IServiceCatalog3.get_TokenServiceURL

           OUTPUT
            TokenServiceURL     : BSTR*'''
        return super(IServiceCatalog3, self).get_TokenServiceURL()
    def get_MessageVersion(self):
        '''Method IServiceCatalog2.get_MessageVersion (from IServiceCatalog2)

           OUTPUT
            ver                 : esriArcGISVersion*'''
        return super(IServiceCatalog3, self).get_MessageVersion()
    def get_MessageFormats(self):
        '''Method IServiceCatalog2.get_MessageFormats (from IServiceCatalog2)

           OUTPUT
            msgFormats          : esriServiceCatalogMessageFormat*'''
        return super(IServiceCatalog3, self).get_MessageFormats()
    def get_ServiceDescriptionsEx(self, folderName):
        '''Method IServiceCatalog2.get_ServiceDescriptionsEx (from IServiceCatalog2)

           INPUT
            folderName          : BSTR

           OUTPUT
            pVal                : IServiceDescriptionArray**'''
        return super(IServiceCatalog3, self).get_ServiceDescriptionsEx(folderName)
    def GetFolders(self, folderName):
        '''Method IServiceCatalog2.GetFolders (from IServiceCatalog2)

           INPUT
            folderName          : BSTR

           OUTPUT
            pVal                : IStringArray**'''
        return super(IServiceCatalog3, self).GetFolders(folderName)
    def get_ServiceDescriptions(self):
        '''Method IServiceCatalog.get_ServiceDescriptions (from IServiceCatalog)

           OUTPUT
            pVal                : IServiceDescriptionArray**'''
        return super(IServiceCatalog3, self).get_ServiceDescriptions()
    MessageFormats = property(get_MessageFormats, None, None)
    MessageVersion = property(get_MessageVersion, None, None)
    RequiresTokens = property(get_RequiresTokens, None, None)
    ServiceDescriptions = property(get_ServiceDescriptions, None, None)
    TokenServiceURL = property(get_TokenServiceURL, None, None)
    ServiceDescriptionsEx = IndexProperty(get_ServiceDescriptionsEx, None)

class IServiceCatalogAdmin(_esriServer.IServiceCatalogAdmin):
    _IID = uuid.UUID('34013770-2aef-4a0e-93a3-6c7d1bfc0a6a')

    def __init__(self, *args, **kw):
        super(IServiceCatalogAdmin, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def CreateServiceDescription(self):
        '''Method IServiceCatalogAdmin.CreateServiceDescription

           OUTPUT
            ServiceDescription  : IServiceDescription**'''
        return super(IServiceCatalogAdmin, self).CreateServiceDescription()
    def CreateServiceDescriptionArray(self):
        '''Method IServiceCatalogAdmin.CreateServiceDescriptionArray

           OUTPUT
            array               : IServiceDescriptionArray**'''
        return super(IServiceCatalogAdmin, self).CreateServiceDescriptionArray()
    def putref_ServiceDescriptions(self, _arg1):
        '''Method IServiceCatalogAdmin.putref_ServiceDescriptions

           INPUT
            _arg1               : IServiceDescriptionArray*'''
        return super(IServiceCatalogAdmin, self).putref_ServiceDescriptions(_arg1)
    def GetDescriptionDocument(self, serviceName, serviceType, serviceURL):
        '''Method IServiceCatalogAdmin.GetDescriptionDocument

           INPUTS
            serviceName         : BSTR
            serviceType         : BSTR
            serviceURL          : BSTR

           OUTPUT
            doc                 : SAFEARRAY**'''
        return super(IServiceCatalogAdmin, self).GetDescriptionDocument(serviceName, serviceType, serviceURL)
    def GetCatalogDescriptionDocument(self, catalogName, catalogUrl):
        '''Method IServiceCatalogAdmin.GetCatalogDescriptionDocument

           INPUTS
            catalogName         : BSTR
            catalogUrl          : BSTR

           OUTPUT
            doc                 : SAFEARRAY**'''
        return super(IServiceCatalogAdmin, self).GetCatalogDescriptionDocument(catalogName, catalogUrl)
    ServiceDescriptions = property(None, putref_ServiceDescriptions, None)

class IServiceCatalogAdmin2(_esriServer.IServiceCatalogAdmin2):
    _IID = uuid.UUID('5aba2ef8-dea3-4b86-ae3b-f2f711b85196')

    def __init__(self, *args, **kw):
        super(IServiceCatalogAdmin2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_MessageFormats(self, _arg1):
        '''Method IServiceCatalogAdmin2.put_MessageFormats

           INPUT
            _arg1               : esriServiceCatalogMessageFormat'''
        return super(IServiceCatalogAdmin2, self).put_MessageFormats(_arg1)
    def put_MessageVersion(self, _arg1):
        '''Method IServiceCatalogAdmin2.put_MessageVersion

           INPUT
            _arg1               : esriArcGISVersion'''
        return super(IServiceCatalogAdmin2, self).put_MessageVersion(_arg1)
    def CreateServiceFolderArray(self):
        '''Method IServiceCatalogAdmin2.CreateServiceFolderArray

           OUTPUT
            array               : IStringArray**'''
        return super(IServiceCatalogAdmin2, self).CreateServiceFolderArray()
    def putref_ServiceFolders(self, _arg1):
        '''Method IServiceCatalogAdmin2.putref_ServiceFolders

           INPUT
            _arg1               : IStringArray*'''
        return super(IServiceCatalogAdmin2, self).putref_ServiceFolders(_arg1)
    def CreateServiceDescription(self):
        '''Method IServiceCatalogAdmin.CreateServiceDescription (from IServiceCatalogAdmin)

           OUTPUT
            ServiceDescription  : IServiceDescription**'''
        return super(IServiceCatalogAdmin2, self).CreateServiceDescription()
    def CreateServiceDescriptionArray(self):
        '''Method IServiceCatalogAdmin.CreateServiceDescriptionArray (from IServiceCatalogAdmin)

           OUTPUT
            array               : IServiceDescriptionArray**'''
        return super(IServiceCatalogAdmin2, self).CreateServiceDescriptionArray()
    def putref_ServiceDescriptions(self, _arg1):
        '''Method IServiceCatalogAdmin.putref_ServiceDescriptions (from IServiceCatalogAdmin)

           INPUT
            _arg1               : IServiceDescriptionArray*'''
        return super(IServiceCatalogAdmin2, self).putref_ServiceDescriptions(_arg1)
    def GetDescriptionDocument(self, serviceName, serviceType, serviceURL):
        '''Method IServiceCatalogAdmin.GetDescriptionDocument (from IServiceCatalogAdmin)

           INPUTS
            serviceName         : BSTR
            serviceType         : BSTR
            serviceURL          : BSTR

           OUTPUT
            doc                 : SAFEARRAY**'''
        return super(IServiceCatalogAdmin2, self).GetDescriptionDocument(serviceName, serviceType, serviceURL)
    def GetCatalogDescriptionDocument(self, catalogName, catalogUrl):
        '''Method IServiceCatalogAdmin.GetCatalogDescriptionDocument (from IServiceCatalogAdmin)

           INPUTS
            catalogName         : BSTR
            catalogUrl          : BSTR

           OUTPUT
            doc                 : SAFEARRAY**'''
        return super(IServiceCatalogAdmin2, self).GetCatalogDescriptionDocument(catalogName, catalogUrl)
    MessageFormats = property(None, put_MessageFormats, None)
    MessageVersion = property(None, put_MessageVersion, None)
    ServiceDescriptions = property(None, putref_ServiceDescriptions, None)
    ServiceFolders = property(None, putref_ServiceFolders, None)

class IServiceCatalogAdmin3(_esriServer.IServiceCatalogAdmin3):
    _IID = uuid.UUID('214df7e7-4a43-4f8f-9a13-436afc4d2a5f')

    def __init__(self, *args, **kw):
        super(IServiceCatalogAdmin3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_TokenServiceURL(self, _arg1):
        '''Method IServiceCatalogAdmin3.put_TokenServiceURL

           INPUT
            _arg1               : BSTR'''
        return super(IServiceCatalogAdmin3, self).put_TokenServiceURL(_arg1)
    def put_RequiresTokens(self, _arg1):
        '''Method IServiceCatalogAdmin3.put_RequiresTokens

           INPUT
            _arg1               : VARIANT_BOOL'''
        return super(IServiceCatalogAdmin3, self).put_RequiresTokens(_arg1)
    def put_MessageFormats(self, _arg1):
        '''Method IServiceCatalogAdmin2.put_MessageFormats (from IServiceCatalogAdmin2)

           INPUT
            _arg1               : esriServiceCatalogMessageFormat'''
        return super(IServiceCatalogAdmin3, self).put_MessageFormats(_arg1)
    def put_MessageVersion(self, _arg1):
        '''Method IServiceCatalogAdmin2.put_MessageVersion (from IServiceCatalogAdmin2)

           INPUT
            _arg1               : esriArcGISVersion'''
        return super(IServiceCatalogAdmin3, self).put_MessageVersion(_arg1)
    def CreateServiceFolderArray(self):
        '''Method IServiceCatalogAdmin2.CreateServiceFolderArray (from IServiceCatalogAdmin2)

           OUTPUT
            array               : IStringArray**'''
        return super(IServiceCatalogAdmin3, self).CreateServiceFolderArray()
    def putref_ServiceFolders(self, _arg1):
        '''Method IServiceCatalogAdmin2.putref_ServiceFolders (from IServiceCatalogAdmin2)

           INPUT
            _arg1               : IStringArray*'''
        return super(IServiceCatalogAdmin3, self).putref_ServiceFolders(_arg1)
    def CreateServiceDescription(self):
        '''Method IServiceCatalogAdmin.CreateServiceDescription (from IServiceCatalogAdmin)

           OUTPUT
            ServiceDescription  : IServiceDescription**'''
        return super(IServiceCatalogAdmin3, self).CreateServiceDescription()
    def CreateServiceDescriptionArray(self):
        '''Method IServiceCatalogAdmin.CreateServiceDescriptionArray (from IServiceCatalogAdmin)

           OUTPUT
            array               : IServiceDescriptionArray**'''
        return super(IServiceCatalogAdmin3, self).CreateServiceDescriptionArray()
    def putref_ServiceDescriptions(self, _arg1):
        '''Method IServiceCatalogAdmin.putref_ServiceDescriptions (from IServiceCatalogAdmin)

           INPUT
            _arg1               : IServiceDescriptionArray*'''
        return super(IServiceCatalogAdmin3, self).putref_ServiceDescriptions(_arg1)
    def GetDescriptionDocument(self, serviceName, serviceType, serviceURL):
        '''Method IServiceCatalogAdmin.GetDescriptionDocument (from IServiceCatalogAdmin)

           INPUTS
            serviceName         : BSTR
            serviceType         : BSTR
            serviceURL          : BSTR

           OUTPUT
            doc                 : SAFEARRAY**'''
        return super(IServiceCatalogAdmin3, self).GetDescriptionDocument(serviceName, serviceType, serviceURL)
    def GetCatalogDescriptionDocument(self, catalogName, catalogUrl):
        '''Method IServiceCatalogAdmin.GetCatalogDescriptionDocument (from IServiceCatalogAdmin)

           INPUTS
            catalogName         : BSTR
            catalogUrl          : BSTR

           OUTPUT
            doc                 : SAFEARRAY**'''
        return super(IServiceCatalogAdmin3, self).GetCatalogDescriptionDocument(catalogName, catalogUrl)
    MessageFormats = property(None, put_MessageFormats, None)
    MessageVersion = property(None, put_MessageVersion, None)
    RequiresTokens = property(None, put_RequiresTokens, None)
    ServiceDescriptions = property(None, putref_ServiceDescriptions, None)
    ServiceFolders = property(None, putref_ServiceFolders, None)
    TokenServiceURL = property(None, put_TokenServiceURL, None)

class IIdentity(_esriServer.IIdentity):
    _IID = uuid.UUID('0710484b-62ec-42c4-8a3d-3186e2d8da36')

    def __init__(self, *args, **kw):
        super(IIdentity, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_UserName(self, UserName):
        '''Method IIdentity.put_UserName

           INPUT
            UserName            : BSTR'''
        return super(IIdentity, self).put_UserName(UserName)
    def get_UserName(self):
        '''Method IIdentity.get_UserName

           OUTPUT
            UserName            : BSTR*'''
        return super(IIdentity, self).get_UserName()
    def put_DomainName(self, DomainName):
        '''Method IIdentity.put_DomainName

           INPUT
            DomainName          : BSTR'''
        return super(IIdentity, self).put_DomainName(DomainName)
    def get_DomainName(self):
        '''Method IIdentity.get_DomainName

           OUTPUT
            DomainName          : BSTR*'''
        return super(IIdentity, self).get_DomainName()
    def put_Password(self, Password):
        '''Method IIdentity.put_Password

           INPUT
            Password            : BSTR'''
        return super(IIdentity, self).put_Password(Password)
    def get_Password(self):
        '''Method IIdentity.get_Password

           OUTPUT
            Password            : BSTR*'''
        return super(IIdentity, self).get_Password()
    def put_EncodedString(self, Password):
        '''Method IIdentity.put_EncodedString

           INPUT
            Password            : BSTR'''
        return super(IIdentity, self).put_EncodedString(Password)
    def get_EncodedString(self):
        '''Method IIdentity.get_EncodedString

           OUTPUT
            Password            : BSTR*'''
        return super(IIdentity, self).get_EncodedString()
    DomainName = property(get_DomainName, put_DomainName, None)
    EncodedString = property(get_EncodedString, put_EncodedString, None)
    Password = property(get_Password, put_Password, None)
    UserName = property(get_UserName, put_UserName, None)

class IServerInfo(_esriServer.IServerInfo):
    _IID = uuid.UUID('fa70a9e1-a5fc-448e-ae33-6c78b1014966')

    def __init__(self, *args, **kw):
        super(IServerInfo, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ServerName(self, ServerName):
        '''Method IServerInfo.put_ServerName

           INPUT
            ServerName          : BSTR'''
        return super(IServerInfo, self).put_ServerName(ServerName)
    def get_ServerName(self):
        '''Method IServerInfo.get_ServerName

           OUTPUT
            ServerName          : BSTR*'''
        return super(IServerInfo, self).get_ServerName()
    def put_Identity(self, ppIdentity):
        '''Method IServerInfo.put_Identity

           INPUT
            ppIdentity          : IIdentity*'''
        return super(IServerInfo, self).put_Identity(ppIdentity)
    def get_Identity(self):
        '''Method IServerInfo.get_Identity

           OUTPUT
            ppIdentity          : IIdentity**'''
        return super(IServerInfo, self).get_Identity()
    Identity = property(get_Identity, put_Identity, None)
    ServerName = property(get_ServerName, put_ServerName, None)

class IServerInfos(_esriServer.IServerInfos):
    _IID = uuid.UUID('23c5169b-11c2-4750-836e-2ebbdc9e7008')
    def get_Count(self):
        '''Method IServerInfos.get_Count

           OUTPUT
            Count               : long*'''
        return super(IServerInfos, self).get_Count()
    def get_Element(self, index):
        '''Method IServerInfos.get_Element

           INPUT
            index               : long

           OUTPUT
            serverInfo          : IServerInfo**'''
        return super(IServerInfos, self).get_Element(index)
    def Remove(self, index):
        '''Method IServerInfos.Remove

           INPUT
            index               : long'''
        return super(IServerInfos, self).Remove(index)
    def RemoveAll(self):
        '''Method IServerInfos.RemoveAll'''
        return super(IServerInfos, self).RemoveAll()
    def Add(self, serverInfo):
        '''Method IServerInfos.Add

           INPUT
            serverInfo          : IServerInfo*'''
        return super(IServerInfos, self).Add(serverInfo)
    def Insert(self, index, serverInfo):
        '''Method IServerInfos.Insert

           INPUTS
            index               : long
            serverInfo          : IServerInfo*'''
        return super(IServerInfos, self).Insert(index, serverInfo)
    Count = property(get_Count, None, None)
    Element = IndexProperty(get_Element, None)

class IGISServer(_esriServer.IGISServer):
    _IID = uuid.UUID('d9c910b6-4c6e-475d-bae6-5eacd1c4e9c2')

    def __init__(self, *args, **kw):
        super(IGISServer, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Alias(self, Alias):
        '''Method IGISServer.put_Alias

           INPUT
            Alias               : BSTR'''
        return super(IGISServer, self).put_Alias(Alias)
    def get_Alias(self):
        '''Method IGISServer.get_Alias

           OUTPUT
            Alias               : BSTR*'''
        return super(IGISServer, self).get_Alias()
    def put_ServerInfos(self, ServerInfos):
        '''Method IGISServer.put_ServerInfos

           INPUT
            ServerInfos         : IServerInfos*'''
        return super(IGISServer, self).put_ServerInfos(ServerInfos)
    def get_ServerInfos(self):
        '''Method IGISServer.get_ServerInfos

           OUTPUT
            ServerInfos         : IServerInfos**'''
        return super(IGISServer, self).get_ServerInfos()
    def put_ConnectionType(self, ServerInfos):
        '''Method IGISServer.put_ConnectionType

           INPUT
            ServerInfos         : esriServerConnectionType'''
        return super(IGISServer, self).put_ConnectionType(ServerInfos)
    def get_ConnectionType(self):
        '''Method IGISServer.get_ConnectionType

           OUTPUT
            ServerInfos         : esriServerConnectionType*'''
        return super(IGISServer, self).get_ConnectionType()
    def put_MaxRequestLength(self, MaxRequestLength):
        '''Method IGISServer.put_MaxRequestLength

           INPUT
            MaxRequestLength    : long'''
        return super(IGISServer, self).put_MaxRequestLength(MaxRequestLength)
    def get_MaxRequestLength(self):
        '''Method IGISServer.get_MaxRequestLength

           OUTPUT
            MaxRequestLength    : long*'''
        return super(IGISServer, self).get_MaxRequestLength()
    def put_MessageFormat(self, msgFormat):
        '''Method IGISServer.put_MessageFormat

           INPUT
            msgFormat           : esriServiceCatalogMessageFormat'''
        return super(IGISServer, self).put_MessageFormat(msgFormat)
    def get_MessageFormat(self):
        '''Method IGISServer.get_MessageFormat

           OUTPUT
            msgFormat           : esriServiceCatalogMessageFormat*'''
        return super(IGISServer, self).get_MessageFormat()
    Alias = property(get_Alias, put_Alias, None)
    ConnectionType = property(get_ConnectionType, put_ConnectionType, None)
    MaxRequestLength = property(get_MaxRequestLength, put_MaxRequestLength, None)
    MessageFormat = property(get_MessageFormat, put_MessageFormat, None)
    ServerInfos = property(get_ServerInfos, put_ServerInfos, None)

class IGISServers(_esriServer.IGISServers):
    _IID = uuid.UUID('20dae966-d7da-41e9-9334-d9d8ab7ab83e')
    def get_Count(self):
        '''Method IGISServers.get_Count

           OUTPUT
            Count               : long*'''
        return super(IGISServers, self).get_Count()
    def get_Element(self, index):
        '''Method IGISServers.get_Element

           INPUT
            index               : long

           OUTPUT
            Server              : IGISServer**'''
        return super(IGISServers, self).get_Element(index)
    def Remove(self, index):
        '''Method IGISServers.Remove

           INPUT
            index               : long'''
        return super(IGISServers, self).Remove(index)
    def RemoveAll(self):
        '''Method IGISServers.RemoveAll'''
        return super(IGISServers, self).RemoveAll()
    def Add(self, Server):
        '''Method IGISServers.Add

           INPUT
            Server              : IGISServer*'''
        return super(IGISServers, self).Add(Server)
    def Insert(self, index, Server):
        '''Method IGISServers.Insert

           INPUTS
            index               : long
            Server              : IGISServer*'''
        return super(IGISServers, self).Insert(index, Server)
    Count = property(get_Count, None, None)
    Element = IndexProperty(get_Element, None)

class IManagerWebService(_esriServer.IManagerWebService):
    _IID = uuid.UUID('c260325f-c891-4dff-89c1-58aeacc7e361')
    def get_GISServers(self):
        '''Method IManagerWebService.get_GISServers

           OUTPUT
            servers             : IGISServers**'''
        return super(IManagerWebService, self).get_GISServers()
    def AddGISServer(self, Server):
        '''Method IManagerWebService.AddGISServer

           INPUT
            Server              : IGISServer*'''
        return super(IManagerWebService, self).AddGISServer(Server)
    def DeleteGISServer(self, aliasName):
        '''Method IManagerWebService.DeleteGISServer

           INPUT
            aliasName           : BSTR'''
        return super(IManagerWebService, self).DeleteGISServer(aliasName)
    def RefreshServiceInfo(self):
        '''Method IManagerWebService.RefreshServiceInfo'''
        return super(IManagerWebService, self).RefreshServiceInfo()
    GISServers = property(get_GISServers, None, None)

class IWPISilentConfig(_esriServer.IWPISilentConfig):
    _IID = uuid.UUID('89816982-dedc-4a5a-922a-d2fbbcf53877')
    def Configure(self, WebServerName, instanceName, computerName, UserName, userPass, DomainName, port):
        '''Method IWPISilentConfig.Configure

           INPUTS
            WebServerName       : BSTR
            instanceName        : BSTR
            computerName        : BSTR
            UserName            : BSTR
            userPass            : BSTR
            DomainName          : BSTR
            port                : BSTR

           OUTPUT
            success             : VARIANT_BOOL*'''
        return super(IWPISilentConfig, self).Configure(WebServerName, instanceName, computerName, UserName, userPass, DomainName, port)

class IServerObjectFactoryX(_esriServer.IServerObjectFactoryX):
    _IID = uuid.UUID('d4b031ba-ad7d-438b-811c-a362f8b2d818')
    def AddAddInFolder(self, addInFolderPath):
        '''Method IServerObjectFactoryX.AddAddInFolder

           INPUT
            addInFolderPath     : BSTR'''
        return super(IServerObjectFactoryX, self).AddAddInFolder(addInFolderPath)
    def RemoveAddInFolder(self, addInFolderPath):
        '''Method IServerObjectFactoryX.RemoveAddInFolder

           INPUT
            addInFolderPath     : BSTR'''
        return super(IServerObjectFactoryX, self).RemoveAddInFolder(addInFolderPath)
    def SetProductCode(self, productCode):
        '''Method IServerObjectFactoryX.SetProductCode

           INPUT
            productCode         : int'''
        return super(IServerObjectFactoryX, self).SetProductCode(productCode)
    def SetJobRegistryPath(self, jobRegPath):
        '''Method IServerObjectFactoryX.SetJobRegistryPath

           INPUT
            jobRegPath          : BSTR'''
        return super(IServerObjectFactoryX, self).SetJobRegistryPath(jobRegPath)
    def GetJobRegistryPath(self):
        '''Method IServerObjectFactoryX.GetJobRegistryPath

           OUTPUT
            pJobRegPath         : BSTR*'''
        return super(IServerObjectFactoryX, self).GetJobRegistryPath()
    def SetLogDirectoryPath(self, logDirPath):
        '''Method IServerObjectFactoryX.SetLogDirectoryPath

           INPUT
            logDirPath          : BSTR'''
        return super(IServerObjectFactoryX, self).SetLogDirectoryPath(logDirPath)
    def GetLogDirectoryPath(self):
        '''Method IServerObjectFactoryX.GetLogDirectoryPath

           OUTPUT
            pLogDirPath         : BSTR*'''
        return super(IServerObjectFactoryX, self).GetLogDirectoryPath()
    def SetLogLevel(self, LogLevel):
        '''Method IServerObjectFactoryX.SetLogLevel

           INPUT
            LogLevel            : BSTR'''
        return super(IServerObjectFactoryX, self).SetLogLevel(LogLevel)
    def GetLogLevel(self):
        '''Method IServerObjectFactoryX.GetLogLevel

           OUTPUT
            pLogLevel           : BSTR*'''
        return super(IServerObjectFactoryX, self).GetLogLevel()
    def SetMaxLogFileSize(self, maxLogFileSize):
        '''Method IServerObjectFactoryX.SetMaxLogFileSize

           INPUT
            maxLogFileSize      : long'''
        return super(IServerObjectFactoryX, self).SetMaxLogFileSize(maxLogFileSize)
    def GetMaxLogFileSize(self):
        '''Method IServerObjectFactoryX.GetMaxLogFileSize

           OUTPUT
            pMaxLogFileSize     : long*'''
        return super(IServerObjectFactoryX, self).GetMaxLogFileSize()
    def CreateServerObject(self, CLSID, cfgName, cfgType, ipProps):
        '''Method IServerObjectFactoryX.CreateServerObject

           INPUTS
            CLSID               : BSTR
            cfgName             : BSTR
            cfgType             : BSTR
            ipProps             : IPropertySet*

           OUTPUT
            ppSO                : IServerObject**'''
        return super(IServerObjectFactoryX, self).CreateServerObject(CLSID, cfgName, cfgType, ipProps)
    def CreateConfigurationFactory(self, cfgName, cfgType, CLSID):
        '''Method IServerObjectFactoryX.CreateConfigurationFactory

           INPUTS
            cfgName             : BSTR
            cfgType             : BSTR
            CLSID               : BSTR

           OUTPUT
            ppCF                : IConfigurationFactory**'''
        return super(IServerObjectFactoryX, self).CreateConfigurationFactory(cfgName, cfgType, CLSID)
    def CreateObject(self, CLSID):
        '''Method IServerObjectFactoryX.CreateObject

           INPUT
            CLSID               : BSTR

           OUTPUT
            ppUnk               : IUnknown**'''
        return super(IServerObjectFactoryX, self).CreateObject(CLSID)
    def Shutdown(self):
        '''Method IServerObjectFactoryX.Shutdown'''
        return super(IServerObjectFactoryX, self).Shutdown()
    def ShutdownEx(self, ipSO):
        '''Method IServerObjectFactoryX.ShutdownEx

           INPUT
            ipSO                : IServerObject*'''
        return super(IServerObjectFactoryX, self).ShutdownEx(ipSO)
    def SetProcessId(self, ProcessId):
        '''Method IServerObjectFactoryX.SetProcessId

           INPUT
            ProcessId           : unsignedlong'''
        return super(IServerObjectFactoryX, self).SetProcessId(ProcessId)

class IServerEnvironmentXHelper(_esriServer.IServerEnvironmentXHelper):
    _IID = uuid.UUID('9fc0c623-186b-4a67-a4c9-5dec2fb8377d')
    def ChangeLogLevel(self, newLogLevel):
        '''Method IServerEnvironmentXHelper.ChangeLogLevel

           INPUT
            newLogLevel         : BSTR'''
        return super(IServerEnvironmentXHelper, self).ChangeLogLevel(newLogLevel)
    def ResetJobID(self):
        '''Method IServerEnvironmentXHelper.ResetJobID'''
        return super(IServerEnvironmentXHelper, self).ResetJobID()
    def SetJobID(self, jobID):
        '''Method IServerEnvironmentXHelper.SetJobID

           INPUT
            jobID               : BSTR'''
        return super(IServerEnvironmentXHelper, self).SetJobID(jobID)
    def AddServerDirectory(self, dirPath, URL, Description, CleaningMode, MaxFileAge, Type):
        '''Method IServerEnvironmentXHelper.AddServerDirectory

           INPUTS
            dirPath             : BSTR
            URL                 : BSTR
            Description         : BSTR
            CleaningMode        : esriServerDirectoryCleaningMode
            MaxFileAge          : long
            Type                : esriServerDirectoryType'''
        return super(IServerEnvironmentXHelper, self).AddServerDirectory(dirPath, URL, Description, CleaningMode, MaxFileAge, Type)
    def RemoveServerDirectory(self, dirPath):
        '''Method IServerEnvironmentXHelper.RemoveServerDirectory

           INPUT
            dirPath             : BSTR'''
        return super(IServerEnvironmentXHelper, self).RemoveServerDirectory(dirPath)
    def SetUserInfo(self, UserInfo):
        '''Method IServerEnvironmentXHelper.SetUserInfo

           INPUT
            UserInfo            : BSTR'''
        return super(IServerEnvironmentXHelper, self).SetUserInfo(UserInfo)
    def SetEnvProperties(self, ipProps):
        '''Method IServerEnvironmentXHelper.SetEnvProperties

           INPUT
            ipProps             : IPropertySet*'''
        return super(IServerEnvironmentXHelper, self).SetEnvProperties(ipProps)
    def AddEnvProperty(self, Name, value):
        '''Method IServerEnvironmentXHelper.AddEnvProperty

           INPUTS
            Name                : BSTR
            value               : BSTR'''
        return super(IServerEnvironmentXHelper, self).AddEnvProperty(Name, value)
    def RemoveEnvProperty(self, Name):
        '''Method IServerEnvironmentXHelper.RemoveEnvProperty

           INPUT
            Name                : BSTR'''
        return super(IServerEnvironmentXHelper, self).RemoveEnvProperty(Name)
    def ChangeLogMachineName(self, newMachineName):
        '''Method IServerEnvironmentXHelper.ChangeLogMachineName

           INPUT
            newMachineName      : BSTR'''
        return super(IServerEnvironmentXHelper, self).ChangeLogMachineName(newMachineName)
    def ChangeLogDirectory(self, newLogDirectory):
        '''Method IServerEnvironmentXHelper.ChangeLogDirectory

           INPUT
            newLogDirectory     : BSTR'''
        return super(IServerEnvironmentXHelper, self).ChangeLogDirectory(newLogDirectory)
    def ChangeMaxLogFileSize(self, maxLogFileSize):
        '''Method IServerEnvironmentXHelper.ChangeMaxLogFileSize

           INPUT
            maxLogFileSize      : long'''
        return super(IServerEnvironmentXHelper, self).ChangeMaxLogFileSize(maxLogFileSize)
    def EnableCrashDumpGeneration(self, bEnable):
        '''Method IServerEnvironmentXHelper.EnableCrashDumpGeneration

           INPUT
            bEnable             : VARIANT_BOOL'''
        return super(IServerEnvironmentXHelper, self).EnableCrashDumpGeneration(bEnable)

class IGPServerHelper(_esriServer.IGPServerHelper):
    _IID = uuid.UUID('e5a9a155-937e-4025-8ce6-42690d964c42')
    def Init(self, jobRegistryPath, jobsDirectoryPath):
        '''Method IGPServerHelper.Init

           INPUTS
            jobRegistryPath     : BSTR
            jobsDirectoryPath   : BSTR'''
        return super(IGPServerHelper, self).Init(jobRegistryPath, jobsDirectoryPath)
    def WriteStringJobResult(self, jobID, serviceName, serviceType, result):
        '''Method IGPServerHelper.WriteStringJobResult

           INPUTS
            jobID               : BSTR
            serviceName         : BSTR
            serviceType         : BSTR
            result              : BSTR'''
        return super(IGPServerHelper, self).WriteStringJobResult(jobID, serviceName, serviceType, result)
    def WriteBinaryJobResult(self, jobID, serviceName, serviceType, result):
        '''Method IGPServerHelper.WriteBinaryJobResult

           INPUTS
            jobID               : BSTR
            serviceName         : BSTR
            serviceType         : BSTR
            result              : SAFEARRAY*'''
        return super(IGPServerHelper, self).WriteBinaryJobResult(jobID, serviceName, serviceType, result)
    def WriteRESTJobResult(self, jobID, serviceName, serviceType, responseProperties, result):
        '''Method IGPServerHelper.WriteRESTJobResult

           INPUTS
            jobID               : BSTR
            serviceName         : BSTR
            serviceType         : BSTR
            responseProperties  : BSTR
            result              : SAFEARRAY*'''
        return super(IGPServerHelper, self).WriteRESTJobResult(jobID, serviceName, serviceType, responseProperties, result)
    def GetStringRequestMessageType(self, request):
        '''Method IGPServerHelper.GetStringRequestMessageType

           INPUT
            request             : BSTR

           OUTPUT
            pType               : BSTR*'''
        return super(IGPServerHelper, self).GetStringRequestMessageType(request)
    def GetBinaryRequestMessageType(self, request):
        '''Method IGPServerHelper.GetBinaryRequestMessageType

           INPUT
            request             : SAFEARRAY*

           OUTPUT
            pType               : BSTR*'''
        return super(IGPServerHelper, self).GetBinaryRequestMessageType(request)
    def GetJobIDFromStringResponse(self, response):
        '''Method IGPServerHelper.GetJobIDFromStringResponse

           INPUT
            response            : BSTR

           OUTPUT
            pJobID              : BSTR*'''
        return super(IGPServerHelper, self).GetJobIDFromStringResponse(response)
    def GetJobIDFromBinaryResponse(self, response):
        '''Method IGPServerHelper.GetJobIDFromBinaryResponse

           INPUT
            response            : SAFEARRAY*

           OUTPUT
            pJobID              : BSTR*'''
        return super(IGPServerHelper, self).GetJobIDFromBinaryResponse(response)
    def GetStringJobDefinition(self, jobID, serviceName, serviceType):
        '''Method IGPServerHelper.GetStringJobDefinition

           INPUTS
            jobID               : BSTR
            serviceName         : BSTR
            serviceType         : BSTR

           OUTPUT
            pJobDefinition      : BSTR*'''
        return super(IGPServerHelper, self).GetStringJobDefinition(jobID, serviceName, serviceType)
    def GetBinaryJobDefinition(self, jobID, serviceName, serviceType):
        '''Method IGPServerHelper.GetBinaryJobDefinition

           INPUTS
            jobID               : BSTR
            serviceName         : BSTR
            serviceType         : BSTR

           OUTPUT
            ppJobDefinition     : SAFEARRAY**'''
        return super(IGPServerHelper, self).GetBinaryJobDefinition(jobID, serviceName, serviceType)
    def GetRESTJobDefinition(self, jobID, serviceName, serviceType):
        '''Method IGPServerHelper.GetRESTJobDefinition

           INPUTS
            jobID               : BSTR
            serviceName         : BSTR
            serviceType         : BSTR

           OUTPUTS
            resourceName        : BSTR*
            operationName       : BSTR*
            operationInput      : BSTR*
            outputFormat        : BSTR*
            requestProperties   : BSTR*'''
        return super(IGPServerHelper, self).GetRESTJobDefinition(jobID, serviceName, serviceType)
    def WriteJobStatusAndMessage(self, jobID, serviceName, serviceType, Status, message):
        '''Method IGPServerHelper.WriteJobStatusAndMessage

           INPUTS
            jobID               : BSTR
            serviceName         : BSTR
            serviceType         : BSTR
            Status              : esriJobStatus
            message             : BSTR'''
        return super(IGPServerHelper, self).WriteJobStatusAndMessage(jobID, serviceName, serviceType, Status, message)
    def GetJobStatus(self, jobID, serviceName, serviceType):
        '''Method IGPServerHelper.GetJobStatus

           INPUTS
            jobID               : BSTR
            serviceName         : BSTR
            serviceType         : BSTR

           OUTPUT
            pStatus             : esriJobStatus*'''
        return super(IGPServerHelper, self).GetJobStatus(jobID, serviceName, serviceType)

class IUser(_esriServer.IUser):
    _IID = uuid.UUID('2b8a2b7f-01bf-4951-8aa7-5161ad46ef35')
    def SetUsername(self, UserName):
        '''Method IUser.SetUsername

           INPUT
            UserName            : BSTR'''
        return super(IUser, self).SetUsername(UserName)
    def GetUsername(self):
        '''Method IUser.GetUsername

           OUTPUT
            UserName            : BSTR*'''
        return super(IUser, self).GetUsername()
    def SetPassword(self, Password):
        '''Method IUser.SetPassword

           INPUT
            Password            : BSTR'''
        return super(IUser, self).SetPassword(Password)
    def GetPassword(self):
        '''Method IUser.GetPassword

           OUTPUT
            Password            : BSTR*'''
        return super(IUser, self).GetPassword()
    def SetDescription(self, Description):
        '''Method IUser.SetDescription

           INPUT
            Description         : BSTR'''
        return super(IUser, self).SetDescription(Description)
    def GetDescription(self):
        '''Method IUser.GetDescription

           OUTPUT
            Description         : BSTR*'''
        return super(IUser, self).GetDescription()
    def SetEmail(self, email):
        '''Method IUser.SetEmail

           INPUT
            email               : BSTR'''
        return super(IUser, self).SetEmail(email)
    def GetEmail(self):
        '''Method IUser.GetEmail

           OUTPUT
            email               : BSTR*'''
        return super(IUser, self).GetEmail()
    def SetFullname(self, fullname):
        '''Method IUser.SetFullname

           INPUT
            fullname            : BSTR'''
        return super(IUser, self).SetFullname(fullname)
    def GetFullname(self):
        '''Method IUser.GetFullname

           OUTPUT
            fullname            : BSTR*'''
        return super(IUser, self).GetFullname()
    def SetSecretQuestion(self, secretQuestion):
        '''Method IUser.SetSecretQuestion

           INPUT
            secretQuestion      : BSTR'''
        return super(IUser, self).SetSecretQuestion(secretQuestion)
    def GetSecretQuestion(self):
        '''Method IUser.GetSecretQuestion

           OUTPUT
            secretQuestion      : BSTR*'''
        return super(IUser, self).GetSecretQuestion()
    def SetSecretAnswer(self, secretAnswer):
        '''Method IUser.SetSecretAnswer

           INPUT
            secretAnswer        : BSTR'''
        return super(IUser, self).SetSecretAnswer(secretAnswer)
    def GetSecretAnswer(self):
        '''Method IUser.GetSecretAnswer

           OUTPUT
            secretAnswer        : BSTR*'''
        return super(IUser, self).GetSecretAnswer()

class IRole(_esriServer.IRole):
    _IID = uuid.UUID('ca90af27-e384-4e25-9f75-0b33f8f6148b')
    def SetRolename(self, rolename):
        '''Method IRole.SetRolename

           INPUT
            rolename            : BSTR'''
        return super(IRole, self).SetRolename(rolename)
    def GetRolename(self):
        '''Method IRole.GetRolename

           OUTPUT
            rolename            : BSTR*'''
        return super(IRole, self).GetRolename()
    def SetDescription(self, Description):
        '''Method IRole.SetDescription

           INPUT
            Description         : BSTR'''
        return super(IRole, self).SetDescription(Description)
    def GetDescription(self):
        '''Method IRole.GetDescription

           OUTPUT
            Description         : BSTR*'''
        return super(IRole, self).GetDescription()

class IUserStore(_esriServer.IUserStore):
    _IID = uuid.UUID('85d81926-f224-480f-a0aa-576d87ee0363')
    def TestConnection(self, pProps):
        '''Method IUserStore.TestConnection

           INPUT
            pProps              : IPropertySet*'''
        return super(IUserStore, self).TestConnection(pProps)
    def Initialize(self, pProps):
        '''Method IUserStore.Initialize

           INPUT
            pProps              : IPropertySet*'''
        return super(IUserStore, self).Initialize(pProps)
    def IsReadOnly(self):
        '''Method IUserStore.IsReadOnly

           OUTPUT
            IsReadOnly          : VARIANT_BOOL*'''
        return super(IUserStore, self).IsReadOnly()
    def AddUser(self, pUser):
        '''Method IUserStore.AddUser

           INPUT
            pUser               : IUser*'''
        return super(IUserStore, self).AddUser(pUser)
    def UpdateUser(self, pUser):
        '''Method IUserStore.UpdateUser

           INPUT
            pUser               : IUser*'''
        return super(IUserStore, self).UpdateUser(pUser)
    def DeleteUser(self, UserName):
        '''Method IUserStore.DeleteUser

           INPUT
            UserName            : BSTR'''
        return super(IUserStore, self).DeleteUser(UserName)
    def GetUser(self, UserName):
        '''Method IUserStore.GetUser

           INPUT
            UserName            : BSTR

           OUTPUT
            pUser               : IUser**'''
        return super(IUserStore, self).GetUser(UserName)
    def GetTotalUsers(self):
        '''Method IUserStore.GetTotalUsers

           OUTPUT
            totalUsers          : long*'''
        return super(IUserStore, self).GetTotalUsers()
    def GetAllUsers(self, filter, maxCount):
        '''Method IUserStore.GetAllUsers

           INPUTS
            filter              : BSTR
            maxCount            : long

           OUTPUTS
            users               : SAFEARRAY**
            hasMore             : VARIANT_BOOL*'''
        return super(IUserStore, self).GetAllUsers(filter, maxCount)
    def GetAllUsersPaged(self, StartIndex, pageSize):
        '''Method IUserStore.GetAllUsersPaged

           INPUTS
            StartIndex          : long
            pageSize            : long

           OUTPUTS
            users               : SAFEARRAY**
            hasMore             : VARIANT_BOOL*'''
        return super(IUserStore, self).GetAllUsersPaged(StartIndex, pageSize)
    def ValidateUser(self, UserName, Password):
        '''Method IUserStore.ValidateUser

           INPUTS
            UserName            : BSTR
            Password            : BSTR

           OUTPUT
            isValid             : VARIANT_BOOL*'''
        return super(IUserStore, self).ValidateUser(UserName, Password)

class IDataStoreValidator(_esriServer.IDataStoreValidator):
    _IID = uuid.UUID('e7ad5e02-e595-4cb9-9b06-ec4f09122a3e')
    def ValidateAccess(self, dataStore, dataStoreType):
        '''Method IDataStoreValidator.ValidateAccess

           INPUTS
            dataStore           : BSTR
            dataStoreType       : BSTR

           OUTPUT
            isValid             : VARIANT_BOOL*'''
        return super(IDataStoreValidator, self).ValidateAccess(dataStore, dataStoreType)

class IRoleStore(_esriServer.IRoleStore):
    _IID = uuid.UUID('5ac20c1a-cf77-44c7-9eae-7bcd859e5ab8')
    def TestConnection(self, pProps):
        '''Method IRoleStore.TestConnection

           INPUT
            pProps              : IPropertySet*'''
        return super(IRoleStore, self).TestConnection(pProps)
    def Initialize(self, pProps):
        '''Method IRoleStore.Initialize

           INPUT
            pProps              : IPropertySet*'''
        return super(IRoleStore, self).Initialize(pProps)
    def IsReadOnly(self):
        '''Method IRoleStore.IsReadOnly

           OUTPUT
            IsReadOnly          : VARIANT_BOOL*'''
        return super(IRoleStore, self).IsReadOnly()
    def AddRole(self, pRole):
        '''Method IRoleStore.AddRole

           INPUT
            pRole               : IRole*'''
        return super(IRoleStore, self).AddRole(pRole)
    def UpdateRole(self, pRole):
        '''Method IRoleStore.UpdateRole

           INPUT
            pRole               : IRole*'''
        return super(IRoleStore, self).UpdateRole(pRole)
    def DeleteRole(self, rolename):
        '''Method IRoleStore.DeleteRole

           INPUT
            rolename            : BSTR'''
        return super(IRoleStore, self).DeleteRole(rolename)
    def GetRole(self, rolename):
        '''Method IRoleStore.GetRole

           INPUT
            rolename            : BSTR

           OUTPUT
            pRole               : IRole**'''
        return super(IRoleStore, self).GetRole(rolename)
    def GetTotalRoles(self):
        '''Method IRoleStore.GetTotalRoles

           OUTPUT
            totalRoles          : long*'''
        return super(IRoleStore, self).GetTotalRoles()
    def GetAllRoles(self, filter, maxCount):
        '''Method IRoleStore.GetAllRoles

           INPUTS
            filter              : BSTR
            maxCount            : long

           OUTPUTS
            roles               : SAFEARRAY**
            hasMore             : VARIANT_BOOL*'''
        return super(IRoleStore, self).GetAllRoles(filter, maxCount)
    def GetAllRolesPaged(self, StartIndex, pageSize):
        '''Method IRoleStore.GetAllRolesPaged

           INPUTS
            StartIndex          : long
            pageSize            : long

           OUTPUTS
            roles               : SAFEARRAY**
            hasMore             : VARIANT_BOOL*'''
        return super(IRoleStore, self).GetAllRolesPaged(StartIndex, pageSize)
    def AssignRoles(self, UserName, rolenames):
        '''Method IRoleStore.AssignRoles

           INPUTS
            UserName            : BSTR
            rolenames           : SAFEARRAY**'''
        return super(IRoleStore, self).AssignRoles(UserName, rolenames)
    def RemoveRoles(self, UserName, rolenames):
        '''Method IRoleStore.RemoveRoles

           INPUTS
            UserName            : BSTR
            rolenames           : SAFEARRAY**'''
        return super(IRoleStore, self).RemoveRoles(UserName, rolenames)
    def GetRolesForUser(self, UserName, filter, maxCount):
        '''Method IRoleStore.GetRolesForUser

           INPUTS
            UserName            : BSTR
            filter              : BSTR
            maxCount            : long

           OUTPUTS
            rolenames           : SAFEARRAY**
            hasMore             : VARIANT_BOOL*'''
        return super(IRoleStore, self).GetRolesForUser(UserName, filter, maxCount)
    def GetUsersWithinRole(self, rolename, filter, maxCount):
        '''Method IRoleStore.GetUsersWithinRole

           INPUTS
            rolename            : BSTR
            filter              : BSTR
            maxCount            : long

           OUTPUTS
            usernames           : SAFEARRAY**
            hasMore             : VARIANT_BOOL*'''
        return super(IRoleStore, self).GetUsersWithinRole(rolename, filter, maxCount)
    def AddUsersToRole(self, rolename, usernames):
        '''Method IRoleStore.AddUsersToRole

           INPUTS
            rolename            : BSTR
            usernames           : SAFEARRAY**'''
        return super(IRoleStore, self).AddUsersToRole(rolename, usernames)
    def RemoveUsersFromRole(self, rolename, usernames):
        '''Method IRoleStore.RemoveUsersFromRole

           INPUTS
            rolename            : BSTR
            usernames           : SAFEARRAY**'''
        return super(IRoleStore, self).RemoveUsersFromRole(rolename, usernames)

class IServerHelper(_esriServer.IServerHelper):
    _IID = uuid.UUID('7baae10c-1933-45be-a723-e71c9d6b6941')
    def GetServerObjectConfigurationStatus(self, cfgName, cfgType):
        '''Method IServerHelper.GetServerObjectConfigurationStatus

           INPUTS
            cfgName             : BSTR
            cfgType             : BSTR

           OUTPUT
            ppCfgStatus         : IServerObjectConfigurationStatus**'''
        return super(IServerHelper, self).GetServerObjectConfigurationStatus(cfgName, cfgType)

class IResponseStreamer(_esriServer.IResponseStreamer):
    _IID = uuid.UUID('e7b4f042-dd12-3ce9-a801-0f47bc498f47')
    def Init(self, contentType, contentEncoding):
        '''Method IResponseStreamer.Init

           INPUTS
            contentType         : BSTR
            contentEncoding     : BSTR'''
        return super(IResponseStreamer, self).Init(contentType, contentEncoding)
    def Write(self, bytes):
        '''Method IResponseStreamer.Write

           INPUT
            bytes               : SAFEARRAY*'''
        return super(IResponseStreamer, self).Write(bytes)
    def GetBufferSize(self):
        '''Method IResponseStreamer.GetBufferSize

           OUTPUT
            size                : long*'''
        return super(IResponseStreamer, self).GetBufferSize()
    def Close(self):
        '''Method IResponseStreamer.Close'''
        return super(IResponseStreamer, self).Close()


# IIDs
IID_IServerObject = IServerObject._IID
IID_IServerObjectFactory = IServerObjectFactory._IID
IID_IServerObjectHelper = IServerObjectHelper._IID
IID_IServerObjectHelper2 = IServerObjectHelper2._IID
IID_IServerObjectExtension = IServerObjectExtension._IID
IID_IServerObjectExtensionManager = IServerObjectExtensionManager._IID
IID_IServerContext = IServerContext._IID
IID_IServerDirectory = IServerDirectory._IID
IID_IEnumServerDirectory = IEnumServerDirectory._IID
IID_IServerObjectConfiguration = IServerObjectConfiguration._IID
IID_IEnumServerObjectConfiguration = IEnumServerObjectConfiguration._IID
IID_IServerObjectConfigurationStatus = IServerObjectConfigurationStatus._IID
IID_IServerObjectType = IServerObjectType._IID
IID_IEnumServerObjectType = IEnumServerObjectType._IID
IID_IServerMachine = IServerMachine._IID
IID_IEnumServerMachine = IEnumServerMachine._IID
IID_IServerObjectAdmin = IServerObjectAdmin._IID
IID_IConfigurationFactory = IConfigurationFactory._IID
IID_IServerLogQuery = IServerLogQuery._IID
IID_IServerLog = IServerLog._IID
IID_IServerObjectConfigurationInfo = IServerObjectConfigurationInfo._IID
IID_IEnumServerObjectConfigurationInfo = IEnumServerObjectConfigurationInfo._IID
IID_IServerObjectTypeInfo = IServerObjectTypeInfo._IID
IID_IEnumServerObjectTypeInfo = IEnumServerObjectTypeInfo._IID
IID_IServerDirectoryInfo = IServerDirectoryInfo._IID
IID_IEnumServerDirectoryInfo = IEnumServerDirectoryInfo._IID
IID_IServerObjectManager = IServerObjectManager._IID
IID_IServerObjectExtensionTypeInfo = IServerObjectExtensionTypeInfo._IID
IID_IEnumServerObjectExtensionTypeInfo = IEnumServerObjectExtensionTypeInfo._IID
IID_IServerObjectManager2 = IServerObjectManager2._IID
IID_IServerObjectManager3 = IServerObjectManager3._IID
IID_IServiceDescription = IServiceDescription._IID
IID_IServiceDescriptionArray = IServiceDescriptionArray._IID
IID_IServiceCatalog = IServiceCatalog._IID
IID_IServiceCatalog2 = IServiceCatalog2._IID
IID_IServerObjectManager4 = IServerObjectManager4._IID
IID_IServerObjectExtensionType = IServerObjectExtensionType._IID
IID_IEnumServerObjectExtensionType = IEnumServerObjectExtensionType._IID
IID_IServerObjectAdmin2 = IServerObjectAdmin2._IID
IID_IServerObjectAdmin3 = IServerObjectAdmin3._IID
IID_IServerObjectAdmin4 = IServerObjectAdmin4._IID
IID_IServerObjectAdmin5 = IServerObjectAdmin5._IID
IID_IServerObjectAdmin6 = IServerObjectAdmin6._IID
IID_IServerObjectAdmin7 = IServerObjectAdmin7._IID
IID_ISOMController = ISOMController._IID
IID_IServerObjectType2 = IServerObjectType2._IID
IID_IServerObjectType3 = IServerObjectType3._IID
IID_IServerObjectType4 = IServerObjectType4._IID
IID_IServerObjectTypeInfo2 = IServerObjectTypeInfo2._IID
IID_IServerObjectTypeInfo3 = IServerObjectTypeInfo3._IID
IID_IServerObjectExtensionType2 = IServerObjectExtensionType2._IID
IID_IServerObjectExtensionTypeInfo2 = IServerObjectExtensionTypeInfo2._IID
IID_IServerObjectConfiguration2 = IServerObjectConfiguration2._IID
IID_IServerObjectConfiguration3 = IServerObjectConfiguration3._IID
IID_IServerObjectConfiguration4 = IServerObjectConfiguration4._IID
IID_IServerObjectConfiguration5 = IServerObjectConfiguration5._IID
IID_IServerObjectConfigurationInfo2 = IServerObjectConfigurationInfo2._IID
IID_IServerDirectory2 = IServerDirectory2._IID
IID_IServerDirectory3 = IServerDirectory3._IID
IID_IServerDirectoryInfo2 = IServerDirectoryInfo2._IID
IID_IServerMachine2 = IServerMachine2._IID
IID_IServerMachine3 = IServerMachine3._IID
IID_IServerMachineStatus = IServerMachineStatus._IID
IID_IServerMachineInfo = IServerMachineInfo._IID
IID_IServerStatistics = IServerStatistics._IID
IID_IServerStatus = IServerStatus._IID
IID_IServerErrorReports = IServerErrorReports._IID
IID_IPermissionsAdmin = IPermissionsAdmin._IID
IID_IPermissionsAdmin2 = IPermissionsAdmin2._IID
IID_IPermissionsManager = IPermissionsManager._IID
IID_IServerCLRHost = IServerCLRHost._IID
IID_IServerObjectExtensionType3 = IServerObjectExtensionType3._IID
IID_IServerMachineEnvironment = IServerMachineEnvironment._IID
IID_IServerObjectAdmin8 = IServerObjectAdmin8._IID
IID_IServerLog2 = IServerLog2._IID
IID_IServerTimeRange = IServerTimeRange._IID
IID_IServerObjectConfigurationManager = IServerObjectConfigurationManager._IID
IID_IServerObjectConfigurationManager2 = IServerObjectConfigurationManager2._IID
IID_IConfigurationFactory2 = IConfigurationFactory2._IID
IID_IConfigurationFactory3 = IConfigurationFactory3._IID
IID_IServerEnvironmentEx = IServerEnvironmentEx._IID
IID_IServerConfigurationStorage = IServerConfigurationStorage._IID
IID_IServerJobManager = IServerJobManager._IID
IID_IServerEnvironmentImpl = IServerEnvironmentImpl._IID
IID_IServerEnvironmentImpl2 = IServerEnvironmentImpl2._IID
IID_IServer = IServer._IID
IID_IServer2 = IServer2._IID
IID_IServerInit = IServerInit._IID
IID_IServerInit2 = IServerInit2._IID
IID_IGISServerConnection = IGISServerConnection._IID
IID_IGISServerConnection2 = IGISServerConnection2._IID
IID_IServiceDescription2 = IServiceDescription2._IID
IID_IServiceDescription3 = IServiceDescription3._IID
IID_IServiceCatalog3 = IServiceCatalog3._IID
IID_IServiceCatalogAdmin = IServiceCatalogAdmin._IID
IID_IServiceCatalogAdmin2 = IServiceCatalogAdmin2._IID
IID_IServiceCatalogAdmin3 = IServiceCatalogAdmin3._IID
IID_IIdentity = IIdentity._IID
IID_IServerInfo = IServerInfo._IID
IID_IServerInfos = IServerInfos._IID
IID_IGISServer = IGISServer._IID
IID_IGISServers = IGISServers._IID
IID_IManagerWebService = IManagerWebService._IID
IID_IWPISilentConfig = IWPISilentConfig._IID
IID_IServerObjectFactoryX = IServerObjectFactoryX._IID
IID_IServerEnvironmentXHelper = IServerEnvironmentXHelper._IID
IID_IGPServerHelper = IGPServerHelper._IID
IID_IUser = IUser._IID
IID_IRole = IRole._IID
IID_IUserStore = IUserStore._IID
IID_IDataStoreValidator = IDataStoreValidator._IID
IID_IRoleStore = IRoleStore._IID
IID_IServerHelper = IServerHelper._IID
IID_IResponseStreamer = IResponseStreamer._IID
_IIDMap[IID_IServerObject] = IServerObject
_IIDMap[IID_IServerObjectFactory] = IServerObjectFactory
_IIDMap[IID_IServerObjectHelper] = IServerObjectHelper
_IIDMap[IID_IServerObjectHelper2] = IServerObjectHelper2
_IIDMap[IID_IServerObjectExtension] = IServerObjectExtension
_IIDMap[IID_IServerObjectExtensionManager] = IServerObjectExtensionManager
_IIDMap[IID_IServerContext] = IServerContext
_IIDMap[IID_IServerDirectory] = IServerDirectory
_IIDMap[IID_IEnumServerDirectory] = IEnumServerDirectory
_IIDMap[IID_IServerObjectConfiguration] = IServerObjectConfiguration
_IIDMap[IID_IEnumServerObjectConfiguration] = IEnumServerObjectConfiguration
_IIDMap[IID_IServerObjectConfigurationStatus] = IServerObjectConfigurationStatus
_IIDMap[IID_IServerObjectType] = IServerObjectType
_IIDMap[IID_IEnumServerObjectType] = IEnumServerObjectType
_IIDMap[IID_IServerMachine] = IServerMachine
_IIDMap[IID_IEnumServerMachine] = IEnumServerMachine
_IIDMap[IID_IServerObjectAdmin] = IServerObjectAdmin
_IIDMap[IID_IConfigurationFactory] = IConfigurationFactory
_IIDMap[IID_IServerLogQuery] = IServerLogQuery
_IIDMap[IID_IServerLog] = IServerLog
_IIDMap[IID_IServerObjectConfigurationInfo] = IServerObjectConfigurationInfo
_IIDMap[IID_IEnumServerObjectConfigurationInfo] = IEnumServerObjectConfigurationInfo
_IIDMap[IID_IServerObjectTypeInfo] = IServerObjectTypeInfo
_IIDMap[IID_IEnumServerObjectTypeInfo] = IEnumServerObjectTypeInfo
_IIDMap[IID_IServerDirectoryInfo] = IServerDirectoryInfo
_IIDMap[IID_IEnumServerDirectoryInfo] = IEnumServerDirectoryInfo
_IIDMap[IID_IServerObjectManager] = IServerObjectManager
_IIDMap[IID_IServerObjectExtensionTypeInfo] = IServerObjectExtensionTypeInfo
_IIDMap[IID_IEnumServerObjectExtensionTypeInfo] = IEnumServerObjectExtensionTypeInfo
_IIDMap[IID_IServerObjectManager2] = IServerObjectManager2
_IIDMap[IID_IServerObjectManager3] = IServerObjectManager3
_IIDMap[IID_IServiceDescription] = IServiceDescription
_IIDMap[IID_IServiceDescriptionArray] = IServiceDescriptionArray
_IIDMap[IID_IServiceCatalog] = IServiceCatalog
_IIDMap[IID_IServiceCatalog2] = IServiceCatalog2
_IIDMap[IID_IServerObjectManager4] = IServerObjectManager4
_IIDMap[IID_IServerObjectExtensionType] = IServerObjectExtensionType
_IIDMap[IID_IEnumServerObjectExtensionType] = IEnumServerObjectExtensionType
_IIDMap[IID_IServerObjectAdmin2] = IServerObjectAdmin2
_IIDMap[IID_IServerObjectAdmin3] = IServerObjectAdmin3
_IIDMap[IID_IServerObjectAdmin4] = IServerObjectAdmin4
_IIDMap[IID_IServerObjectAdmin5] = IServerObjectAdmin5
_IIDMap[IID_IServerObjectAdmin6] = IServerObjectAdmin6
_IIDMap[IID_IServerObjectAdmin7] = IServerObjectAdmin7
_IIDMap[IID_ISOMController] = ISOMController
_IIDMap[IID_IServerObjectType2] = IServerObjectType2
_IIDMap[IID_IServerObjectType3] = IServerObjectType3
_IIDMap[IID_IServerObjectType4] = IServerObjectType4
_IIDMap[IID_IServerObjectTypeInfo2] = IServerObjectTypeInfo2
_IIDMap[IID_IServerObjectTypeInfo3] = IServerObjectTypeInfo3
_IIDMap[IID_IServerObjectExtensionType2] = IServerObjectExtensionType2
_IIDMap[IID_IServerObjectExtensionTypeInfo2] = IServerObjectExtensionTypeInfo2
_IIDMap[IID_IServerObjectConfiguration2] = IServerObjectConfiguration2
_IIDMap[IID_IServerObjectConfiguration3] = IServerObjectConfiguration3
_IIDMap[IID_IServerObjectConfiguration4] = IServerObjectConfiguration4
_IIDMap[IID_IServerObjectConfiguration5] = IServerObjectConfiguration5
_IIDMap[IID_IServerObjectConfigurationInfo2] = IServerObjectConfigurationInfo2
_IIDMap[IID_IServerDirectory2] = IServerDirectory2
_IIDMap[IID_IServerDirectory3] = IServerDirectory3
_IIDMap[IID_IServerDirectoryInfo2] = IServerDirectoryInfo2
_IIDMap[IID_IServerMachine2] = IServerMachine2
_IIDMap[IID_IServerMachine3] = IServerMachine3
_IIDMap[IID_IServerMachineStatus] = IServerMachineStatus
_IIDMap[IID_IServerMachineInfo] = IServerMachineInfo
_IIDMap[IID_IServerStatistics] = IServerStatistics
_IIDMap[IID_IServerStatus] = IServerStatus
_IIDMap[IID_IServerErrorReports] = IServerErrorReports
_IIDMap[IID_IPermissionsAdmin] = IPermissionsAdmin
_IIDMap[IID_IPermissionsAdmin2] = IPermissionsAdmin2
_IIDMap[IID_IPermissionsManager] = IPermissionsManager
_IIDMap[IID_IServerCLRHost] = IServerCLRHost
_IIDMap[IID_IServerObjectExtensionType3] = IServerObjectExtensionType3
_IIDMap[IID_IServerMachineEnvironment] = IServerMachineEnvironment
_IIDMap[IID_IServerObjectAdmin8] = IServerObjectAdmin8
_IIDMap[IID_IServerLog2] = IServerLog2
_IIDMap[IID_IServerTimeRange] = IServerTimeRange
_IIDMap[IID_IServerObjectConfigurationManager] = IServerObjectConfigurationManager
_IIDMap[IID_IServerObjectConfigurationManager2] = IServerObjectConfigurationManager2
_IIDMap[IID_IConfigurationFactory2] = IConfigurationFactory2
_IIDMap[IID_IConfigurationFactory3] = IConfigurationFactory3
_IIDMap[IID_IServerEnvironmentEx] = IServerEnvironmentEx
_IIDMap[IID_IServerConfigurationStorage] = IServerConfigurationStorage
_IIDMap[IID_IServerJobManager] = IServerJobManager
_IIDMap[IID_IServerEnvironmentImpl] = IServerEnvironmentImpl
_IIDMap[IID_IServerEnvironmentImpl2] = IServerEnvironmentImpl2
_IIDMap[IID_IServer] = IServer
_IIDMap[IID_IServer2] = IServer2
_IIDMap[IID_IServerInit] = IServerInit
_IIDMap[IID_IServerInit2] = IServerInit2
_IIDMap[IID_IGISServerConnection] = IGISServerConnection
_IIDMap[IID_IGISServerConnection2] = IGISServerConnection2
_IIDMap[IID_IServiceDescription2] = IServiceDescription2
_IIDMap[IID_IServiceDescription3] = IServiceDescription3
_IIDMap[IID_IServiceCatalog3] = IServiceCatalog3
_IIDMap[IID_IServiceCatalogAdmin] = IServiceCatalogAdmin
_IIDMap[IID_IServiceCatalogAdmin2] = IServiceCatalogAdmin2
_IIDMap[IID_IServiceCatalogAdmin3] = IServiceCatalogAdmin3
_IIDMap[IID_IIdentity] = IIdentity
_IIDMap[IID_IServerInfo] = IServerInfo
_IIDMap[IID_IServerInfos] = IServerInfos
_IIDMap[IID_IGISServer] = IGISServer
_IIDMap[IID_IGISServers] = IGISServers
_IIDMap[IID_IManagerWebService] = IManagerWebService
_IIDMap[IID_IWPISilentConfig] = IWPISilentConfig
_IIDMap[IID_IServerObjectFactoryX] = IServerObjectFactoryX
_IIDMap[IID_IServerEnvironmentXHelper] = IServerEnvironmentXHelper
_IIDMap[IID_IGPServerHelper] = IGPServerHelper
_IIDMap[IID_IUser] = IUser
_IIDMap[IID_IRole] = IRole
_IIDMap[IID_IUserStore] = IUserStore
_IIDMap[IID_IDataStoreValidator] = IDataStoreValidator
_IIDMap[IID_IRoleStore] = IRoleStore
_IIDMap[IID_IServerHelper] = IServerHelper
_IIDMap[IID_IResponseStreamer] = IResponseStreamer


# CLSIDs
CLSID_ServerObjectFactory = uuid.UUID('6c20ca3d-f8c1-44ee-bf7f-5b866d86483f')
CLSID_ConfigFactory = uuid.UUID('4750135f-afbf-4da5-a128-2eb939e87bd7')
CLSID_ServerObjectManager = uuid.UUID('5c3d041c-5d21-4b0c-935c-b1d7aa10c81c')
CLSID_ServerObjectAdmin = uuid.UUID('d317cf58-eb65-4d4c-a18b-fcb477a91ac9')
CLSID_ServerObjectConfiguration = uuid.UUID('061affb5-ae19-4a72-896c-ef59e415697b')
CLSID_ServerLogImpl = uuid.UUID('3e32107f-4f36-4d50-a5d2-9ec7c0986cc0')
CLSID_ServerDirectory = uuid.UUID('a6622dc3-1817-4420-86d6-9b3cebd33778')
CLSID_ServerMachine = uuid.UUID('39f4800b-7b54-457f-bea0-7dfcdef37ff7')
CLSID_ServerObject = uuid.UUID('d43bee68-f44f-4c90-a72f-41b469be5a6b')
CLSID_ServerContext = uuid.UUID('fccb4713-2958-4284-9d99-7e25a0bbb423')
CLSID_ServerObjectTypeInfo = uuid.UUID('c28c537e-1ecf-4cef-b29a-c9b0082c5f0c')
CLSID_ServerObjectExtensionTypeInfo = uuid.UUID('91c3d839-ce1e-4750-bf23-63a4bbb4880e')
CLSID_ServerObjectConfigurationInfo = uuid.UUID('cd8d4f2f-c833-47e1-98a6-b80c3a4f4428')
CLSID_ServerObjectConfigurationStatus = uuid.UUID('da266136-e040-4d0c-9b67-ba2553fb3e16')
CLSID_ServerObjectType = uuid.UUID('3cf5c550-0d4f-4eb8-9e75-a65b274f3100')
CLSID_ServerObjectExtensionType = uuid.UUID('087e165b-17b8-40ab-9fe6-3c912e4fd7dd')
CLSID_ServerDirectoryInfo = uuid.UUID('65997efb-8adb-49ff-9481-8b90cb84a5bf')
CLSID_ServerStatisticsArray = uuid.UUID('e6af2747-73ee-43e4-a4b9-b0fe5ea33517')
CLSID_ServerStatisticsResults = uuid.UUID('893c42fd-c4b0-4b8c-b5b1-05c567867e40')
CLSID_ServerMachineStatus = uuid.UUID('98053471-7d09-49d5-a3e0-d235e682331f')
CLSID_SOMController = uuid.UUID('049fc901-5750-46f2-8674-b883c99166c4')
CLSID_Server = uuid.UUID('379376db-aea6-40d1-9491-9345e61ef6be')
CLSID_ServerP = uuid.UUID('5116fa19-c21a-4c9f-816d-a4490c246d56')
CLSID_GISServerConnection = uuid.UUID('cd57b642-1b4a-4e02-a1d0-ffdbcf0e5a41')
CLSID_ServiceCatalog = uuid.UUID('ac58db7e-196f-4206-b4c6-2ce6aefd6ed3')
CLSID_ServerObjectFactoryX = uuid.UUID('14e85554-5eee-410e-ad86-ffece038f1a3')
CLSID_ServerEnvironmentXHelper = uuid.UUID('c779a894-bbfa-4cce-8906-ed950348bebb')
CLSID_GPServerHelper = uuid.UUID('31a080fc-e398-415e-9f12-550127217487')
CLSID_Role = uuid.UUID('a6a0c990-8eae-4ee5-8a29-10a897661b8f')
CLSID_User = uuid.UUID('6b05fd91-c29d-4317-9866-e34b1ee699ed')
CLSID_ResponseStreamer = uuid.UUID('552dc8b3-b3e7-3b06-a772-72bb30c8bcc6')

# Enumerations
class esriServerDirectoryCleaningMode(Enumeration):
    __slots__ = ['esriSDCNone',
                 'esriSDCSliding',
                 'esriSDCAbsolute']
    esriSDCNone = 0
    esriSDCSliding = 1
    esriSDCAbsolute = 2

class esriServerIsolationLevel(Enumeration):
    __slots__ = ['esriServerIsolationHigh',
                 'esriServerIsolationLow',
                 'esriServerIsolationAny']
    esriServerIsolationHigh = 0
    esriServerIsolationLow = 1
    esriServerIsolationAny = 2

class esriStartupType(Enumeration):
    __slots__ = ['esriSTAutomatic',
                 'esriSTManual']
    esriSTAutomatic = 0
    esriSTManual = 1

class esriConfigurationStatus(Enumeration):
    __slots__ = ['esriCSStarted',
                 'esriCSPaused',
                 'esriCSStopped',
                 'esriCSStarting',
                 'esriCSStopping',
                 'esriCSDeleted']
    esriCSStarted = 0
    esriCSPaused = 1
    esriCSStopped = 2
    esriCSStarting = 3
    esriCSStopping = 4
    esriCSDeleted = 5

class esriServiceCatalogMessageFormat(Enumeration):
    __slots__ = ['esriServiceCatalogMessageFormatSoap',
                 'esriServiceCatalogMessageFormatBin',
                 'esriServiceCatalogMessageFormatSoapOrBin']
    esriServiceCatalogMessageFormatSoap = 1
    esriServiceCatalogMessageFormatBin = 2
    esriServiceCatalogMessageFormatSoapOrBin = 3

class esriLoadBalancing(Enumeration):
    __slots__ = ['esriLoadBalancingRoundRobin',
                 'esriLoadBalancingNone']
    esriLoadBalancingRoundRobin = 0
    esriLoadBalancingNone = 1

class esriServerDirectoryType(Enumeration):
    __slots__ = ['esriSDTypeOutput',
                 'esriSDTypeCache',
                 'esriSDTypeJobs',
                 'esriSDTypeIndex',
                 'esriSDTypeInput',
                 'esriSDTypeSystem',
                 'esriSDTypeUploads',
                 'esriSDTypeKML',
                 'esriSDTypeJobRegistry',
                 'esriSDTypeUnknown']
    esriSDTypeOutput = 0
    esriSDTypeCache = 1
    esriSDTypeJobs = 2
    esriSDTypeIndex = 3
    esriSDTypeInput = 4
    esriSDTypeSystem = 5
    esriSDTypeUploads = 6
    esriSDTypeKML = 7
    esriSDTypeJobRegistry = 8
    esriSDTypeUnknown = 9

class esriAccessLevel(Enumeration):
    __slots__ = ['esriAccessAll',
                 'esriAccessPublic',
                 'esriAccessPrivate']
    esriAccessAll = 0
    esriAccessPublic = 1
    esriAccessPrivate = 2

class esriServerStatEvent(Enumeration):
    __slots__ = ['esriSSEContextCreated',
                 'esriSSEContextCreationFailed',
                 'esriSSEContextCreationTimeout',
                 'esriSSEContextReleased',
                 'esriSSEContextUsageTimeout',
                 'esriSSEServerObjectCreated',
                 'esriSSEServerObjectCreationFailed',
                 'esriSSELogError',
                 'esriSSELogWarning']
    esriSSEContextCreated = 0
    esriSSEContextCreationFailed = 1
    esriSSEContextCreationTimeout = 2
    esriSSEContextReleased = 3
    esriSSEContextUsageTimeout = 4
    esriSSEServerObjectCreated = 5
    esriSSEServerObjectCreationFailed = 6
    esriSSELogError = 7
    esriSSELogWarning = 8

class esriServerStatFunction(Enumeration):
    __slots__ = ['esriSSFCount',
                 'esriSSFMinimum',
                 'esriSSFMaximum',
                 'esriSSFSum',
                 'esriSSFSumSquares',
                 'esriSSFMean',
                 'esriSSFStandardDeviation']
    esriSSFCount = 0
    esriSSFMinimum = 1
    esriSSFMaximum = 2
    esriSSFSum = 3
    esriSSFSumSquares = 4
    esriSSFMean = 5
    esriSSFStandardDeviation = 6

class esriServerTimePeriod(Enumeration):
    __slots__ = ['esriSTPNone',
                 'esriSTPSecond',
                 'esriSTPMinute',
                 'esriSTPHour',
                 'esriSTPDay']
    esriSTPNone = 0
    esriSTPSecond = 1
    esriSTPMinute = 2
    esriSTPHour = 3
    esriSTPDay = 4

class esriServerExceptionHandlingMode(Enumeration):
    __slots__ = ['esriServerExceptionHandlingMode_Normal',
                 'esriServerExceptionHandlingMode_ExitOnException',
                 'esriServerExceptionHandlingMode_ExitOnExceptionAndDump',
                 'esriServerExceptionHandlingMode_Dump']
    esriServerExceptionHandlingMode_Normal = 0
    esriServerExceptionHandlingMode_ExitOnException = 1
    esriServerExceptionHandlingMode_ExitOnExceptionAndDump = 2
    esriServerExceptionHandlingMode_Dump = 3

class esriMachineStatus(Enumeration):
    __slots__ = ['esriMStarted',
                 'esriMSStopped']
    esriMStarted = 0
    esriMSStopped = 1

class esriServerConnectionType(Enumeration):
    __slots__ = ['esriServerConnectionTypeRoundRobin',
                 'esriServerConnectionTypeFailOver']
    esriServerConnectionTypeRoundRobin = 1
    esriServerConnectionTypeFailOver = 2

class esriServerInstallType(Enumeration):
    __slots__ = ['esriServerInstallTypeJava',
                 'esriServerInstallTypeDotnet',
                 'esriServerInstallTypeUnknown']
    esriServerInstallTypeJava = 0
    esriServerInstallTypeDotnet = 1
    esriServerInstallTypeUnknown = 2

