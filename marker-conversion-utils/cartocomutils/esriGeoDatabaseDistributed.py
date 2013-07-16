'Type library'
__all__ = ['IModifiedClassInfo', 'IEnumModifiedClassInfo', 'ISchemaChangesInit', 'IXMLDocumentVersion', 'IReplicaProgress', 'IOperationProgress', 'IDataExtraction', 'IReplicaDataChanges', 'IReplicaDataChangesInit', 'IReplicaDataChangesInit2', 'IDataChanges', 'IExportDataChanges', 'IExportDataChanges2', 'IVersionDataChangesInit', 'IDeltaDataChanges', 'IDeltaDataChanges2', 'IDeltaDataChangesInit', 'IDeltaDataChangesInit2', 'IDeltaDataChangesRelease', 'IGdbXmlExport', 'IGdbXmlImport', 'IGdbXmlExportEvents', 'IGdbSchemaCreator', 'IDataChanges2', 'IDataChanges3', 'IDataChangesInfo', 'IDataChangesExt', 'IImportDataChanges', 'IImportDataChanges2', 'IImportDataChanges3', 'IReplicasExporter', 'ITableDataChangesInfo', 'ITablesDataChanges', 'IEnumTableDataChanges', 'ICheckOut', 'ICheckIn', 'ICheckIn2', 'ICheckInDataSynchronizer', 'ICheckInDataSynchronizer2', 'IReplicaValidation', 'IReplicaValidation2', 'IReplicaMessageHandler', 'IReplicaMessageHandler2', 'IGDSData', 'IGDSExportOptions', 'IGDSQueryResultPortion', 'IGeoDataServer', 'IGeoDataServerInit', 'IGeoDataServerObjects', 'IReplicationAgent', 'IReplicationAgentCancelControl', 'IGDSData2', 'IGeoDataServer2', 'IReplicationAgent2', 'IWFSServer', 'IExportSchema', 'ISchemaChanges', 'IImportSchema', 'IEnumSchemaChange', 'ISchemaChangeInfo', 'DataChangesExporter', 'DataChangesImporter', 'DataExtraction', 'DataChanges', 'CheckOutDataChanges', 'DeltaDataChanges', 'GdbExporter', 'GdbImporter', 'GdbSchemaCreator', 'VersionDataChanges', 'TableDataChangesInfo', 'TablesDataChanges', 'OperationProgress', 'ReplicaSchemaExporter', 'ReplicaSchemaImporter', 'SchemaChanges', 'SchemaChangeInfo', 'ReplicasExporter', 'CheckOut', 'CheckIn', 'CheckInDataSynchronizer', 'ReplicaValidator', 'ReplicaProgress', 'ReplicationDataChanges', 'ArchivingDataChanges', 'ReplicaMessageHandler', 'GeoDataServerConfigurationFactory', 'GeoDataServer', 'GDSData', 'GDSExportOptions', 'GDSQueryResultPortion', 'ReplicationAgent', 'GeoDataServerLP', 'GeoDataServerIP', 'GeoDataServerObjectDescription', 'WFSServer', 'IID_IModifiedClassInfo', 'IID_IEnumModifiedClassInfo', 'IID_ISchemaChangesInit', 'IID_IXMLDocumentVersion', 'IID_IReplicaProgress', 'IID_IOperationProgress', 'IID_IDataExtraction', 'IID_IReplicaDataChanges', 'IID_IReplicaDataChangesInit', 'IID_IReplicaDataChangesInit2', 'IID_IDataChanges', 'IID_IExportDataChanges', 'IID_IExportDataChanges2', 'IID_IVersionDataChangesInit', 'IID_IDeltaDataChanges', 'IID_IDeltaDataChanges2', 'IID_IDeltaDataChangesInit', 'IID_IDeltaDataChangesInit2', 'IID_IDeltaDataChangesRelease', 'IID_IGdbXmlExport', 'IID_IGdbXmlImport', 'IID_IGdbXmlExportEvents', 'IID_IGdbSchemaCreator', 'IID_IDataChanges2', 'IID_IDataChanges3', 'IID_IDataChangesInfo', 'IID_IDataChangesExt', 'IID_IImportDataChanges', 'IID_IImportDataChanges2', 'IID_IImportDataChanges3', 'IID_IReplicasExporter', 'IID_ITableDataChangesInfo', 'IID_ITablesDataChanges', 'IID_IEnumTableDataChanges', 'IID_ICheckOut', 'IID_ICheckIn', 'IID_ICheckIn2', 'IID_ICheckInDataSynchronizer', 'IID_ICheckInDataSynchronizer2', 'IID_IReplicaValidation', 'IID_IReplicaValidation2', 'IID_IReplicaMessageHandler', 'IID_IReplicaMessageHandler2', 'IID_IGDSData', 'IID_IGDSExportOptions', 'IID_IGDSQueryResultPortion', 'IID_IGeoDataServer', 'IID_IGeoDataServerInit', 'IID_IGeoDataServerObjects', 'IID_IReplicationAgent', 'IID_IReplicationAgentCancelControl', 'IID_IGDSData2', 'IID_IGeoDataServer2', 'IID_IReplicationAgent2', 'IID_IWFSServer', 'IID_IExportSchema', 'IID_ISchemaChanges', 'IID_IImportSchema', 'IID_IEnumSchemaChange', 'IID_ISchemaChangeInfo', 'CLSID_DataChangesExporter', 'CLSID_DataChangesImporter', 'CLSID_DataExtraction', 'CLSID_DataChanges', 'CLSID_CheckOutDataChanges', 'CLSID_DeltaDataChanges', 'CLSID_GdbExporter', 'CLSID_GdbImporter', 'CLSID_GdbSchemaCreator', 'CLSID_VersionDataChanges', 'CLSID_TableDataChangesInfo', 'CLSID_TablesDataChanges', 'CLSID_OperationProgress', 'CLSID_ReplicaSchemaExporter', 'CLSID_ReplicaSchemaImporter', 'CLSID_SchemaChanges', 'CLSID_SchemaChangeInfo', 'CLSID_ReplicasExporter', 'CLSID_CheckOut', 'CLSID_CheckIn', 'CLSID_CheckInDataSynchronizer', 'CLSID_ReplicaValidator', 'CLSID_ReplicaProgress', 'CLSID_ReplicationDataChanges', 'CLSID_ArchivingDataChanges', 'CLSID_ReplicaMessageHandler', 'CLSID_GeoDataServerConfigurationFactory', 'CLSID_GeoDataServer', 'CLSID_GDSData', 'CLSID_GDSExportOptions', 'CLSID_GDSQueryResultPortion', 'CLSID_ReplicationAgent', 'CLSID_GeoDataServerLP', 'CLSID_GeoDataServerIP', 'CLSID_GeoDataServerObjectDescription', 'CLSID_WFSServer', 'esriSchemaChangeType', 'esriDataChangeType', 'esriReplicaProgress', 'esriOperationProgress', 'esriReplicaMessageType', 'esriExportGenerationsOption', 'esriReExportGenerationsOption', 'esriExportDataChangesOption', 'esriCheckInSourceType', 'esriDisconnectedEditingError', 'esriGDSExportFormat', 'esriReplicaSynchronizeDirection', 'esriGDSTransportType', 'esriGDSImportFormat', 'esriGDSReplicaImportSource', 'esriReplicationAgentReconcilePolicy', 'esriGeoDataServerMessageCodeEnum', 'esriGeoDataServerErrors', 'esriWFSHttpVerb', 'esriWFSServerMessageCodeEnum']
from cartocomutils import _esriGeoDatabaseDistributed
from cartocomutils._esriGeoDatabaseDistributed import DataChangesExporter, DataChangesImporter, DataExtraction, DataChanges, CheckOutDataChanges, DeltaDataChanges, GdbExporter, GdbImporter, GdbSchemaCreator, VersionDataChanges, TableDataChangesInfo, TablesDataChanges, OperationProgress, ReplicaSchemaExporter, ReplicaSchemaImporter, SchemaChanges, SchemaChangeInfo, ReplicasExporter, CheckOut, CheckIn, CheckInDataSynchronizer, ReplicaValidator, ReplicaProgress, ReplicationDataChanges, ArchivingDataChanges, ReplicaMessageHandler, GeoDataServerConfigurationFactory, GeoDataServer, GDSData, GDSExportOptions, GDSQueryResultPortion, ReplicationAgent, GeoDataServerLP, GeoDataServerIP, GeoDataServerObjectDescription, WFSServer
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IModifiedClassInfo(_esriGeoDatabaseDistributed.IModifiedClassInfo):
    _IID = uuid.UUID('0952a2d7-fa43-4740-aea5-d6c902eb6a2c')
    def get_ChildClassName(self):
        '''Method IModifiedClassInfo.get_ChildClassName

           OUTPUT
            cClassName          : BSTR*'''
        return super(IModifiedClassInfo, self).get_ChildClassName()
    def get_ClassID(self):
        '''Method IModifiedClassInfo.get_ClassID

           OUTPUT
            ChildClassID        : long*'''
        return super(IModifiedClassInfo, self).get_ClassID()
    def get_ParentClassName(self):
        '''Method IModifiedClassInfo.get_ParentClassName

           OUTPUT
            rName               : BSTR*'''
        return super(IModifiedClassInfo, self).get_ParentClassName()
    def get_DatasetType(self):
        '''Method IModifiedClassInfo.get_DatasetType

           OUTPUT
            dType               : esriDatasetType*'''
        return super(IModifiedClassInfo, self).get_DatasetType()
    def get_ParentDatabase(self):
        '''Method IModifiedClassInfo.get_ParentDatabase

           OUTPUT
            ParentDatabase      : BSTR*'''
        return super(IModifiedClassInfo, self).get_ParentDatabase()
    def get_ParentOwner(self):
        '''Method IModifiedClassInfo.get_ParentOwner

           OUTPUT
            ParentOwner         : BSTR*'''
        return super(IModifiedClassInfo, self).get_ParentOwner()
    ChildClassName = property(get_ChildClassName, None, None)
    ClassID = property(get_ClassID, None, None)
    DatasetType = property(get_DatasetType, None, None)
    ParentClassName = property(get_ParentClassName, None, None)
    ParentDatabase = property(get_ParentDatabase, None, None)
    ParentOwner = property(get_ParentOwner, None, None)

class IEnumModifiedClassInfo(_esriGeoDatabaseDistributed.IEnumModifiedClassInfo):
    _IID = uuid.UUID('b3924a28-0d3a-47c6-9d63-71544f1634da')
    def Reset(self):
        '''Method IEnumModifiedClassInfo.Reset'''
        return super(IEnumModifiedClassInfo, self).Reset()
    def Next(self):
        '''Method IEnumModifiedClassInfo.Next

           OUTPUT
            ModifiedClassInfo   : IModifiedClassInfo**'''
        return super(IEnumModifiedClassInfo, self).Next()
    def __iter__(self):
        try:
            super(IEnumModifiedClassInfo, self).Reset()
            val = super(IEnumModifiedClassInfo, self).Next()
            while val:
                yield val
                val = super(IEnumModifiedClassInfo, self).Next()
        except:
            pass

class ISchemaChangesInit(_esriGeoDatabaseDistributed.ISchemaChangesInit):
    _IID = uuid.UUID('e94e335a-e1f0-4a55-9e8d-e6492b033333')
    def Init(self, Replica, TargetWorkspaceName):
        '''Method ISchemaChangesInit.Init

           INPUTS
            Replica             : IReplica*
            TargetWorkspaceName : IWorkspaceName*'''
        return super(ISchemaChangesInit, self).Init(Replica, TargetWorkspaceName)
    def InitFromSchemaDocument(self, xmlFile, TargetWorkspaceName):
        '''Method ISchemaChangesInit.InitFromSchemaDocument

           INPUTS
            xmlFile             : BSTR
            TargetWorkspaceName : IWorkspaceName*'''
        return super(ISchemaChangesInit, self).InitFromSchemaDocument(xmlFile, TargetWorkspaceName)
    def InitFromSchemaDifferencesDocument(self, xmlFile, TargetWorkspaceName):
        '''Method ISchemaChangesInit.InitFromSchemaDifferencesDocument

           INPUTS
            xmlFile             : BSTR
            TargetWorkspaceName : IWorkspaceName*'''
        return super(ISchemaChangesInit, self).InitFromSchemaDifferencesDocument(xmlFile, TargetWorkspaceName)

class IXMLDocumentVersion(_esriGeoDatabaseDistributed.IXMLDocumentVersion):
    _IID = uuid.UUID('80effd28-c665-47d2-aa21-c4196efcc9d3')

    def __init__(self, *args, **kw):
        super(IXMLDocumentVersion, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_NamespaceToExportTo(self, _arg1):
        '''Method IXMLDocumentVersion.put_NamespaceToExportTo

           INPUT
            _arg1               : BSTR'''
        return super(IXMLDocumentVersion, self).put_NamespaceToExportTo(_arg1)
    NamespaceToExportTo = property(None, put_NamespaceToExportTo, None)

class IReplicaProgress(_esriGeoDatabaseDistributed.IReplicaProgress):
    _IID = uuid.UUID('5435d16a-5aa0-427f-bdad-24bd6aabf858')

    def __init__(self, *args, **kw):
        super(IReplicaProgress, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def Startup(self, rProgress):
        '''Method IReplicaProgress.Startup

           INPUT
            rProgress           : esriReplicaProgress'''
        return super(IReplicaProgress, self).Startup(rProgress)
    def put_CurrentReplicaOperation(self, _arg1):
        '''Method IReplicaProgress.put_CurrentReplicaOperation

           INPUT
            _arg1               : esriReplicaProgress'''
        return super(IReplicaProgress, self).put_CurrentReplicaOperation(_arg1)
    def put_ReplicaOperations(self, _arg1):
        '''Method IReplicaProgress.put_ReplicaOperations

           INPUT
            _arg1               : long'''
        return super(IReplicaProgress, self).put_ReplicaOperations(_arg1)
    def put_ReplicaObjectCount(self, _arg1):
        '''Method IReplicaProgress.put_ReplicaObjectCount

           INPUT
            _arg1               : long'''
        return super(IReplicaProgress, self).put_ReplicaObjectCount(_arg1)
    CurrentReplicaOperation = property(None, put_CurrentReplicaOperation, None)
    ReplicaObjectCount = property(None, put_ReplicaObjectCount, None)
    ReplicaOperations = property(None, put_ReplicaOperations, None)

class IOperationProgress(_esriGeoDatabaseDistributed.IOperationProgress):
    _IID = uuid.UUID('7e1f4a6f-a857-475f-82ea-a089122dbdd4')

    def __init__(self, *args, **kw):
        super(IOperationProgress, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def Startup(self, rProgress):
        '''Method IOperationProgress.Startup

           INPUT
            rProgress           : esriOperationProgress'''
        return super(IOperationProgress, self).Startup(rProgress)
    def put_CurrentOperation(self, _arg1):
        '''Method IOperationProgress.put_CurrentOperation

           INPUT
            _arg1               : esriOperationProgress'''
        return super(IOperationProgress, self).put_CurrentOperation(_arg1)
    def put_Operations(self, _arg1):
        '''Method IOperationProgress.put_Operations

           INPUT
            _arg1               : long'''
        return super(IOperationProgress, self).put_Operations(_arg1)
    def put_ObjectCount(self, _arg1):
        '''Method IOperationProgress.put_ObjectCount

           INPUT
            _arg1               : long'''
        return super(IOperationProgress, self).put_ObjectCount(_arg1)
    CurrentOperation = property(None, put_CurrentOperation, None)
    ObjectCount = property(None, put_ObjectCount, None)
    Operations = property(None, put_Operations, None)

class IDataExtraction(_esriGeoDatabaseDistributed.IDataExtraction):
    _IID = uuid.UUID('cf7e4cf0-e0c0-4302-ab42-c32899835602')
    def Extract(self, rDDescription, transferRelObjects):
        '''Method IDataExtraction.Extract

           INPUTS
            rDDescription       : IReplicaDescription*
            transferRelObjects  : VARIANT_BOOL'''
        return super(IDataExtraction, self).Extract(rDDescription, transferRelObjects)
    def ExtractSchema(self, rSDescription, outputSpatialReference):
        '''Method IDataExtraction.ExtractSchema

           INPUTS
            rSDescription       : IReplicaDescription*
            outputSpatialReference: ISpatialReference*'''
        return super(IDataExtraction, self).ExtractSchema(rSDescription, outputSpatialReference)

class IReplicaDataChanges(_esriGeoDatabaseDistributed.IReplicaDataChanges):
    _IID = uuid.UUID('8612b096-c19b-4197-80ac-86961ac9426c')
    def get_Workspace(self):
        '''Method IReplicaDataChanges.get_Workspace

           OUTPUT
            pWorkspace          : IWorkspace**'''
        return super(IReplicaDataChanges, self).get_Workspace()
    Workspace = property(get_Workspace, None, None)

class IReplicaDataChangesInit(_esriGeoDatabaseDistributed.IReplicaDataChangesInit):
    _IID = uuid.UUID('e513366a-6fe2-42d4-ac95-40dec7122f57')
    def Init(self, Replica, checkoutWorkspace):
        '''Method IReplicaDataChangesInit.Init

           INPUTS
            Replica             : IReplica*
            checkoutWorkspace   : IWorkspaceName*'''
        return super(IReplicaDataChangesInit, self).Init(Replica, checkoutWorkspace)

class IReplicaDataChangesInit2(_esriGeoDatabaseDistributed.IReplicaDataChangesInit2):
    _IID = uuid.UUID('92267ee9-0766-43ea-ba8b-7dfd5c8e8517')
    def Init2(self, Replica, checkoutWorkspace, GenOption):
        '''Method IReplicaDataChangesInit2.Init2

           INPUTS
            Replica             : IReplica*
            checkoutWorkspace   : IWorkspaceName*
            GenOption           : esriExportGenerationsOption'''
        return super(IReplicaDataChangesInit2, self).Init2(Replica, checkoutWorkspace, GenOption)
    def Init(self, Replica, checkoutWorkspace):
        '''Method IReplicaDataChangesInit.Init (from IReplicaDataChangesInit)

           INPUTS
            Replica             : IReplica*
            checkoutWorkspace   : IWorkspaceName*'''
        return super(IReplicaDataChangesInit2, self).Init(Replica, checkoutWorkspace)

class IDataChanges(_esriGeoDatabaseDistributed.IDataChanges):
    _IID = uuid.UUID('e0951743-0d52-42ff-ab5e-32d07b5b8951')
    def GetModifiedClassesInfo(self):
        '''Method IDataChanges.GetModifiedClassesInfo

           OUTPUT
            enumModifiedClasses : IEnumModifiedClassInfo**'''
        return super(IDataChanges, self).GetModifiedClassesInfo()
    def Extract(self, tableName, changeType):
        '''Method IDataChanges.Extract

           INPUTS
            tableName           : BSTR
            changeType          : esriDataChangeType

           OUTPUT
            cursor              : IDifferenceCursor**'''
        return super(IDataChanges, self).Extract(tableName, changeType)
    def get_ParentWorkspaceName(self):
        '''Method IDataChanges.get_ParentWorkspaceName

           OUTPUT
            ParentWorkspaceName : IWorkspaceName**'''
        return super(IDataChanges, self).get_ParentWorkspaceName()
    def get_ParentReplicaID(self):
        '''Method IDataChanges.get_ParentReplicaID

           OUTPUT
            ParentReplicaID     : long*'''
        return super(IDataChanges, self).get_ParentReplicaID()
    def get_ReplicaGuid(self):
        '''Method IDataChanges.get_ReplicaGuid

           OUTPUT
            ReplicaGuid         : BSTR*'''
        return super(IDataChanges, self).get_ReplicaGuid()
    ParentReplicaID = property(get_ParentReplicaID, None, None)
    ParentWorkspaceName = property(get_ParentWorkspaceName, None, None)
    ReplicaGuid = property(get_ReplicaGuid, None, None)

class IExportDataChanges(_esriGeoDatabaseDistributed.IExportDataChanges):
    _IID = uuid.UUID('e290f6a3-535f-49a9-8fd4-c60fc44bf109')
    def ExportDataChanges(self, exportFileName, exportOption, DataChanges, OverwriteIfExists):
        '''Method IExportDataChanges.ExportDataChanges

           INPUTS
            exportFileName      : BSTR
            exportOption        : esriExportDataChangesOption
            DataChanges         : IDataChanges*
            OverwriteIfExists   : VARIANT_BOOL'''
        return super(IExportDataChanges, self).ExportDataChanges(exportFileName, exportOption, DataChanges, OverwriteIfExists)

class IExportDataChanges2(_esriGeoDatabaseDistributed.IExportDataChanges2):
    _IID = uuid.UUID('8ec3471a-80e3-4552-9cc7-dfce334cc809')
    def ExportDataChanges2(self, exportFileName, exportOption, DataChanges, OverwriteIfExists, Compressed, BinaryGeometry, LastSend):
        '''Method IExportDataChanges2.ExportDataChanges2

           INPUTS
            exportFileName      : BSTR
            exportOption        : esriExportDataChangesOption
            DataChanges         : IDataChanges*
            OverwriteIfExists   : VARIANT_BOOL
            Compressed          : VARIANT_BOOL
            BinaryGeometry      : VARIANT_BOOL
            LastSend            : VARIANT_BOOL'''
        return super(IExportDataChanges2, self).ExportDataChanges2(exportFileName, exportOption, DataChanges, OverwriteIfExists, Compressed, BinaryGeometry, LastSend)
    def ReExportDataChanges(self, exportFileName, exportOption, SourceReplica, GenOption, OverwriteIfExists, Compressed, BinaryGeometry):
        '''Method IExportDataChanges2.ReExportDataChanges

           INPUTS
            exportFileName      : BSTR
            exportOption        : esriExportDataChangesOption
            SourceReplica       : IReplica2*
            GenOption           : esriReExportGenerationsOption
            OverwriteIfExists   : VARIANT_BOOL
            Compressed          : VARIANT_BOOL
            BinaryGeometry      : VARIANT_BOOL'''
        return super(IExportDataChanges2, self).ReExportDataChanges(exportFileName, exportOption, SourceReplica, GenOption, OverwriteIfExists, Compressed, BinaryGeometry)
    def ExportDataChanges(self, exportFileName, exportOption, DataChanges, OverwriteIfExists):
        '''Method IExportDataChanges.ExportDataChanges (from IExportDataChanges)

           INPUTS
            exportFileName      : BSTR
            exportOption        : esriExportDataChangesOption
            DataChanges         : IDataChanges*
            OverwriteIfExists   : VARIANT_BOOL'''
        return super(IExportDataChanges2, self).ExportDataChanges(exportFileName, exportOption, DataChanges, OverwriteIfExists)

class IVersionDataChangesInit(_esriGeoDatabaseDistributed.IVersionDataChangesInit):
    _IID = uuid.UUID('51ddd7ac-b00b-420a-adb9-30540c7e81d4')
    def Init(self, SourceVersionedWorkspace, TargetVersionedWorkspace):
        '''Method IVersionDataChangesInit.Init

           INPUTS
            SourceVersionedWorkspace: IWorkspaceName*
            TargetVersionedWorkspace: IWorkspaceName*'''
        return super(IVersionDataChangesInit, self).Init(SourceVersionedWorkspace, TargetVersionedWorkspace)

class IDeltaDataChanges(_esriGeoDatabaseDistributed.IDeltaDataChanges):
    _IID = uuid.UUID('a598405f-8302-42b8-a6a2-121cbb2b3e0a')
    def get_Container(self):
        '''Method IDeltaDataChanges.get_Container

           OUTPUT
            Container           : IUnknown**'''
        return super(IDeltaDataChanges, self).get_Container()
    Container = property(get_Container, None, None)

class IDeltaDataChanges2(_esriGeoDatabaseDistributed.IDeltaDataChanges2):
    _IID = uuid.UUID('288ac87d-ed18-460b-b720-dc4d082da610')
    def get_ReplicaMessageType(self):
        '''Method IDeltaDataChanges2.get_ReplicaMessageType

           OUTPUT
            MessageType         : esriReplicaMessageType*'''
        return super(IDeltaDataChanges2, self).get_ReplicaMessageType()
    def get_Container(self):
        '''Method IDeltaDataChanges.get_Container (from IDeltaDataChanges)

           OUTPUT
            Container           : IUnknown**'''
        return super(IDeltaDataChanges2, self).get_Container()
    Container = property(get_Container, None, None)
    ReplicaMessageType = property(get_ReplicaMessageType, None, None)

class IDeltaDataChangesInit(_esriGeoDatabaseDistributed.IDeltaDataChangesInit):
    _IID = uuid.UUID('725451c9-cd9d-4431-8020-c9ed11bb40f0')
    def Init(self, changesFileName, exportOption):
        '''Method IDeltaDataChangesInit.Init

           INPUTS
            changesFileName     : BSTR
            exportOption        : esriExportDataChangesOption'''
        return super(IDeltaDataChangesInit, self).Init(changesFileName, exportOption)

class IDeltaDataChangesInit2(_esriGeoDatabaseDistributed.IDeltaDataChangesInit2):
    _IID = uuid.UUID('4c7fd0cf-fa09-4d49-b168-4767cf945c14')
    def Init2(self, changesFileName, exportOption, RandomAccess):
        '''Method IDeltaDataChangesInit2.Init2

           INPUTS
            changesFileName     : BSTR
            exportOption        : esriExportDataChangesOption
            RandomAccess        : VARIANT_BOOL'''
        return super(IDeltaDataChangesInit2, self).Init2(changesFileName, exportOption, RandomAccess)
    def Init(self, changesFileName, exportOption):
        '''Method IDeltaDataChangesInit.Init (from IDeltaDataChangesInit)

           INPUTS
            changesFileName     : BSTR
            exportOption        : esriExportDataChangesOption'''
        return super(IDeltaDataChangesInit2, self).Init(changesFileName, exportOption)

class IDeltaDataChangesRelease(_esriGeoDatabaseDistributed.IDeltaDataChangesRelease):
    _IID = uuid.UUID('cb41732d-ec82-4e84-bfc1-a9a1135b02b5')
    def get_MajorVersion(self):
        '''Method IDeltaDataChangesRelease.get_MajorVersion

           OUTPUT
            versionNumber       : long*'''
        return super(IDeltaDataChangesRelease, self).get_MajorVersion()
    def get_MinorVersion(self):
        '''Method IDeltaDataChangesRelease.get_MinorVersion

           OUTPUT
            versionNumber       : long*'''
        return super(IDeltaDataChangesRelease, self).get_MinorVersion()
    def get_BugfixVersion(self):
        '''Method IDeltaDataChangesRelease.get_BugfixVersion

           OUTPUT
            versionNumber       : long*'''
        return super(IDeltaDataChangesRelease, self).get_BugfixVersion()
    BugfixVersion = property(get_BugfixVersion, None, None)
    MajorVersion = property(get_MajorVersion, None, None)
    MinorVersion = property(get_MinorVersion, None, None)

class IGdbXmlExport(_esriGeoDatabaseDistributed.IGdbXmlExport):
    _IID = uuid.UUID('1f88e412-18ce-4324-a1e5-d1a32d5dff4a')
    def ExportWorkspace(self, Workspace, outFile, BinaryGeometry, Compressed, retrieveMetadata):
        '''Method IGdbXmlExport.ExportWorkspace

           INPUTS
            Workspace           : IWorkspace*
            outFile             : BSTR
            BinaryGeometry      : VARIANT_BOOL
            Compressed          : VARIANT_BOOL
            retrieveMetadata    : VARIANT_BOOL'''
        return super(IGdbXmlExport, self).ExportWorkspace(Workspace, outFile, BinaryGeometry, Compressed, retrieveMetadata)
    def ExportWorkspaceSchema(self, Workspace, outFile, Compressed, retrieveMetadata):
        '''Method IGdbXmlExport.ExportWorkspaceSchema

           INPUTS
            Workspace           : IWorkspace*
            outFile             : BSTR
            Compressed          : VARIANT_BOOL
            retrieveMetadata    : VARIANT_BOOL'''
        return super(IGdbXmlExport, self).ExportWorkspaceSchema(Workspace, outFile, Compressed, retrieveMetadata)
    def ExportDatasets(self, EnumNameMapping, outFile, BinaryGeometry, Compressed, retrieveMetadata):
        '''Method IGdbXmlExport.ExportDatasets

           INPUTS
            EnumNameMapping     : IEnumNameMapping*
            outFile             : BSTR
            BinaryGeometry      : VARIANT_BOOL
            Compressed          : VARIANT_BOOL
            retrieveMetadata    : VARIANT_BOOL'''
        return super(IGdbXmlExport, self).ExportDatasets(EnumNameMapping, outFile, BinaryGeometry, Compressed, retrieveMetadata)
    def ExportDatasetsSchema(self, EnumNameMapping, outFile, Compressed, retrieveMetadata):
        '''Method IGdbXmlExport.ExportDatasetsSchema

           INPUTS
            EnumNameMapping     : IEnumNameMapping*
            outFile             : BSTR
            Compressed          : VARIANT_BOOL
            retrieveMetadata    : VARIANT_BOOL'''
        return super(IGdbXmlExport, self).ExportDatasetsSchema(EnumNameMapping, outFile, Compressed, retrieveMetadata)
    def ExportRecordSet(self, pTableName, outFile, BinaryGeometry, Compressed):
        '''Method IGdbXmlExport.ExportRecordSet

           INPUTS
            pTableName          : ITableName*
            outFile             : BSTR
            BinaryGeometry      : VARIANT_BOOL
            Compressed          : VARIANT_BOOL'''
        return super(IGdbXmlExport, self).ExportRecordSet(pTableName, outFile, BinaryGeometry, Compressed)

class IGdbXmlImport(_esriGeoDatabaseDistributed.IGdbXmlImport):
    _IID = uuid.UUID('56cb26fb-6abf-4eb7-9f39-9ec7248c0873')
    def GenerateNameMapping(self, inFile, Workspace):
        '''Method IGdbXmlImport.GenerateNameMapping

           INPUTS
            inFile              : BSTR
            Workspace           : IWorkspace*

           OUTPUTS
            EnumNameMapping     : IEnumNameMapping**
            HasConflict         : VARIANT_BOOL*'''
        return super(IGdbXmlImport, self).GenerateNameMapping(inFile, Workspace)
    def ImportWorkspace(self, inFile, EnumNameMapping, pWorkspace, schemaOnly):
        '''Method IGdbXmlImport.ImportWorkspace

           INPUTS
            inFile              : BSTR
            EnumNameMapping     : IEnumNameMapping*
            pWorkspace          : IWorkspace*
            schemaOnly          : VARIANT_BOOL'''
        return super(IGdbXmlImport, self).ImportWorkspace(inFile, EnumNameMapping, pWorkspace, schemaOnly)
    def ImportRecordSet(self, inFile, SourceFields, TargetMappedFields, pTable):
        '''Method IGdbXmlImport.ImportRecordSet

           INPUTS
            inFile              : BSTR
            SourceFields        : IFields*
            TargetMappedFields  : IFields*
            pTable              : ITable*'''
        return super(IGdbXmlImport, self).ImportRecordSet(inFile, SourceFields, TargetMappedFields, pTable)
    def GetRecordSetFields(self, inFile):
        '''Method IGdbXmlImport.GetRecordSetFields

           INPUT
            inFile              : BSTR

           OUTPUT
            Fields              : IFields**'''
        return super(IGdbXmlImport, self).GetRecordSetFields(inFile)

class IGdbXmlExportEvents(_esriGeoDatabaseDistributed.IGdbXmlExportEvents):
    _IID = uuid.UUID('17ce60d7-24f8-49cc-8fc4-94471dbaf723')
    def BeforeStartElement(self, Element, URL, Object, pXMLWriter):
        '''Method IGdbXmlExportEvents.BeforeStartElement

           INPUTS
            Element             : BSTR
            URL                 : BSTR
            Object              : IUnknown*
            pXMLWriter          : IXMLWriter*'''
        return super(IGdbXmlExportEvents, self).BeforeStartElement(Element, URL, Object, pXMLWriter)
    def AfterEndElement(self, Element, URL, Object, pXMLWriter):
        '''Method IGdbXmlExportEvents.AfterEndElement

           INPUTS
            Element             : BSTR
            URL                 : BSTR
            Object              : IUnknown*
            pXMLWriter          : IXMLWriter*'''
        return super(IGdbXmlExportEvents, self).AfterEndElement(Element, URL, Object, pXMLWriter)

class IGdbSchemaCreator(_esriGeoDatabaseDistributed.IGdbSchemaCreator):
    _IID = uuid.UUID('077f55bf-9a00-44b3-9d6f-5e1d0fc822e7')
    def GenerateNameMapping(self, pWorkspace, pDataElements, pDomains):
        '''Method IGdbSchemaCreator.GenerateNameMapping

           INPUTS
            pWorkspace          : IWorkspace*
            pDataElements       : IArray*
            pDomains            : IArray*

           OUTPUTS
            ppENM               : IEnumNameMapping**
            pHasConflict        : VARIANT_BOOL*'''
        return super(IGdbSchemaCreator, self).GenerateNameMapping(pWorkspace, pDataElements, pDomains)
    def CreateSchema(self, pWorkspace, pENM):
        '''Method IGdbSchemaCreator.CreateSchema

           INPUTS
            pWorkspace          : IWorkspace*
            pENM                : IEnumNameMapping*'''
        return super(IGdbSchemaCreator, self).CreateSchema(pWorkspace, pENM)

class IDataChanges2(_esriGeoDatabaseDistributed.IDataChanges2):
    _IID = uuid.UUID('5f8f332e-316d-4fc0-9454-b2628cb9d546')
    def get_ChangesModelType(self):
        '''Method IDataChanges2.get_ChangesModelType

           OUTPUT
            ModelType           : esriReplicaModelType*'''
        return super(IDataChanges2, self).get_ChangesModelType()
    def GetModifiedClassesInfo(self):
        '''Method IDataChanges.GetModifiedClassesInfo (from IDataChanges)

           OUTPUT
            enumModifiedClasses : IEnumModifiedClassInfo**'''
        return super(IDataChanges2, self).GetModifiedClassesInfo()
    def Extract(self, tableName, changeType):
        '''Method IDataChanges.Extract (from IDataChanges)

           INPUTS
            tableName           : BSTR
            changeType          : esriDataChangeType

           OUTPUT
            cursor              : IDifferenceCursor**'''
        return super(IDataChanges2, self).Extract(tableName, changeType)
    def get_ParentWorkspaceName(self):
        '''Method IDataChanges.get_ParentWorkspaceName (from IDataChanges)

           OUTPUT
            ParentWorkspaceName : IWorkspaceName**'''
        return super(IDataChanges2, self).get_ParentWorkspaceName()
    def get_ParentReplicaID(self):
        '''Method IDataChanges.get_ParentReplicaID (from IDataChanges)

           OUTPUT
            ParentReplicaID     : long*'''
        return super(IDataChanges2, self).get_ParentReplicaID()
    def get_ReplicaGuid(self):
        '''Method IDataChanges.get_ReplicaGuid (from IDataChanges)

           OUTPUT
            ReplicaGuid         : BSTR*'''
        return super(IDataChanges2, self).get_ReplicaGuid()
    ChangesModelType = property(get_ChangesModelType, None, None)
    ParentReplicaID = property(get_ParentReplicaID, None, None)
    ParentWorkspaceName = property(get_ParentWorkspaceName, None, None)
    ReplicaGuid = property(get_ReplicaGuid, None, None)

class IDataChanges3(_esriGeoDatabaseDistributed.IDataChanges3):
    _IID = uuid.UUID('a289bd00-e42e-4820-9af0-c9bc64f707a8')
    def get_GenerationNumbers(self):
        '''Method IDataChanges3.get_GenerationNumbers

           OUTPUTS
            sourceGenBegin      : long*
            sourceGenEnd        : long*
            targetGen           : long*'''
        return super(IDataChanges3, self).get_GenerationNumbers()
    def get_ReplicaState(self):
        '''Method IDataChanges3.get_ReplicaState

           OUTPUT
            ReplicaState        : esriReplicaState*'''
        return super(IDataChanges3, self).get_ReplicaState()
    def get_ChangesModelType(self):
        '''Method IDataChanges2.get_ChangesModelType (from IDataChanges2)

           OUTPUT
            ModelType           : esriReplicaModelType*'''
        return super(IDataChanges3, self).get_ChangesModelType()
    def GetModifiedClassesInfo(self):
        '''Method IDataChanges.GetModifiedClassesInfo (from IDataChanges)

           OUTPUT
            enumModifiedClasses : IEnumModifiedClassInfo**'''
        return super(IDataChanges3, self).GetModifiedClassesInfo()
    def Extract(self, tableName, changeType):
        '''Method IDataChanges.Extract (from IDataChanges)

           INPUTS
            tableName           : BSTR
            changeType          : esriDataChangeType

           OUTPUT
            cursor              : IDifferenceCursor**'''
        return super(IDataChanges3, self).Extract(tableName, changeType)
    def get_ParentWorkspaceName(self):
        '''Method IDataChanges.get_ParentWorkspaceName (from IDataChanges)

           OUTPUT
            ParentWorkspaceName : IWorkspaceName**'''
        return super(IDataChanges3, self).get_ParentWorkspaceName()
    def get_ParentReplicaID(self):
        '''Method IDataChanges.get_ParentReplicaID (from IDataChanges)

           OUTPUT
            ParentReplicaID     : long*'''
        return super(IDataChanges3, self).get_ParentReplicaID()
    def get_ReplicaGuid(self):
        '''Method IDataChanges.get_ReplicaGuid (from IDataChanges)

           OUTPUT
            ReplicaGuid         : BSTR*'''
        return super(IDataChanges3, self).get_ReplicaGuid()
    ChangesModelType = property(get_ChangesModelType, None, None)
    GenerationNumbers = property(get_GenerationNumbers, None, None)
    ParentReplicaID = property(get_ParentReplicaID, None, None)
    ParentWorkspaceName = property(get_ParentWorkspaceName, None, None)
    ReplicaGuid = property(get_ReplicaGuid, None, None)
    ReplicaState = property(get_ReplicaState, None, None)

class IDataChangesInfo(_esriGeoDatabaseDistributed.IDataChangesInfo):
    _IID = uuid.UUID('bf34062d-82cb-47db-be39-8c8902e8a05a')
    def get_ChangedIDs(self, className, diffType):
        '''Method IDataChangesInfo.get_ChangedIDs

           INPUTS
            className           : BSTR
            diffType            : esriDataChangeType

           OUTPUT
            ppFIDSet            : IFIDSet**'''
        return super(IDataChangesInfo, self).get_ChangedIDs(className, diffType)

class IDataChangesExt(_esriGeoDatabaseDistributed.IDataChangesExt):
    _IID = uuid.UUID('fafbfa81-b7bd-4c25-a456-0108e11ea25b')
    def ExtractOriginalRows(self, tableName, IDs):
        '''Method IDataChangesExt.ExtractOriginalRows

           INPUTS
            tableName           : BSTR
            IDs                 : IFIDSet*

           OUTPUT
            OriginalRows        : ICursor**'''
        return super(IDataChangesExt, self).ExtractOriginalRows(tableName, IDs)

class IImportDataChanges(_esriGeoDatabaseDistributed.IImportDataChanges):
    _IID = uuid.UUID('3eea0fb7-0478-400b-bf5c-122ea29c50a4')
    def ImportDataChanges(self, WorkspaceName, DeltaDataChanges, ReconcileWithParent, acceptDefaultConflictResolution):
        '''Method IImportDataChanges.ImportDataChanges

           INPUTS
            WorkspaceName       : IWorkspaceName*
            DeltaDataChanges    : IDeltaDataChanges*
            ReconcileWithParent : VARIANT_BOOL
            acceptDefaultConflictResolution: VARIANT_BOOL

           OUTPUT
            pConflictDetected   : VARIANT_BOOL*'''
        return super(IImportDataChanges, self).ImportDataChanges(WorkspaceName, DeltaDataChanges, ReconcileWithParent, acceptDefaultConflictResolution)

class IImportDataChanges2(_esriGeoDatabaseDistributed.IImportDataChanges2):
    _IID = uuid.UUID('27fa7510-e45d-49a2-8d57-7753db605d04')
    def ImportDataChanges2(self, WorkspaceName, DeltaDataChanges, ReconcileWithParent, reconcilePolicy, columnLevel, createOIDMappingTable):
        '''Method IImportDataChanges2.ImportDataChanges2

           INPUTS
            WorkspaceName       : IWorkspaceName*
            DeltaDataChanges    : IDeltaDataChanges*
            ReconcileWithParent : VARIANT_BOOL
            reconcilePolicy     : esriReplicaReconcilePolicyType
            columnLevel         : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            pConflictDetected   : VARIANT_BOOL*'''
        return super(IImportDataChanges2, self).ImportDataChanges2(WorkspaceName, DeltaDataChanges, ReconcileWithParent, reconcilePolicy, columnLevel, createOIDMappingTable)
    def ImportDataChanges(self, WorkspaceName, DeltaDataChanges, ReconcileWithParent, acceptDefaultConflictResolution):
        '''Method IImportDataChanges.ImportDataChanges (from IImportDataChanges)

           INPUTS
            WorkspaceName       : IWorkspaceName*
            DeltaDataChanges    : IDeltaDataChanges*
            ReconcileWithParent : VARIANT_BOOL
            acceptDefaultConflictResolution: VARIANT_BOOL

           OUTPUT
            pConflictDetected   : VARIANT_BOOL*'''
        return super(IImportDataChanges2, self).ImportDataChanges(WorkspaceName, DeltaDataChanges, ReconcileWithParent, acceptDefaultConflictResolution)

class IImportDataChanges3(_esriGeoDatabaseDistributed.IImportDataChanges3):
    _IID = uuid.UUID('a2f2dba2-0515-4fa3-882c-3633480bd24a')
    def ImportDataChanges3(self, WorkspaceName, DataChanges, ReconcileWithParent, reconcilePolicy, columnLevel, createOIDMappingTable, PreserveGlobalIDs):
        '''Method IImportDataChanges3.ImportDataChanges3

           INPUTS
            WorkspaceName       : IWorkspaceName*
            DataChanges         : IDataChanges*
            ReconcileWithParent : VARIANT_BOOL
            reconcilePolicy     : esriReplicaReconcilePolicyType
            columnLevel         : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL
            PreserveGlobalIDs   : VARIANT_BOOL

           OUTPUT
            pConflictDetected   : VARIANT_BOOL*'''
        return super(IImportDataChanges3, self).ImportDataChanges3(WorkspaceName, DataChanges, ReconcileWithParent, reconcilePolicy, columnLevel, createOIDMappingTable, PreserveGlobalIDs)
    def ImportDataChanges2(self, WorkspaceName, DeltaDataChanges, ReconcileWithParent, reconcilePolicy, columnLevel, createOIDMappingTable):
        '''Method IImportDataChanges2.ImportDataChanges2 (from IImportDataChanges2)

           INPUTS
            WorkspaceName       : IWorkspaceName*
            DeltaDataChanges    : IDeltaDataChanges*
            ReconcileWithParent : VARIANT_BOOL
            reconcilePolicy     : esriReplicaReconcilePolicyType
            columnLevel         : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            pConflictDetected   : VARIANT_BOOL*'''
        return super(IImportDataChanges3, self).ImportDataChanges2(WorkspaceName, DeltaDataChanges, ReconcileWithParent, reconcilePolicy, columnLevel, createOIDMappingTable)
    def ImportDataChanges(self, WorkspaceName, DeltaDataChanges, ReconcileWithParent, acceptDefaultConflictResolution):
        '''Method IImportDataChanges.ImportDataChanges (from IImportDataChanges)

           INPUTS
            WorkspaceName       : IWorkspaceName*
            DeltaDataChanges    : IDeltaDataChanges*
            ReconcileWithParent : VARIANT_BOOL
            acceptDefaultConflictResolution: VARIANT_BOOL

           OUTPUT
            pConflictDetected   : VARIANT_BOOL*'''
        return super(IImportDataChanges3, self).ImportDataChanges(WorkspaceName, DeltaDataChanges, ReconcileWithParent, acceptDefaultConflictResolution)

class IReplicasExporter(_esriGeoDatabaseDistributed.IReplicasExporter):
    _IID = uuid.UUID('28c7af79-0a93-4ed1-832b-d1e1aec0ff75')
    def ExportReplicasInfo(self, pFromWS, pDestWS, fcName, SR):
        '''Method IReplicasExporter.ExportReplicasInfo

           INPUTS
            pFromWS             : IWorkspace*
            pDestWS             : IWorkspace*
            fcName              : BSTR
            SR                  : ISpatialReference*

           OUTPUT
            ppFC                : IFeatureClass**'''
        return super(IReplicasExporter, self).ExportReplicasInfo(pFromWS, pDestWS, fcName, SR)

class ITableDataChangesInfo(_esriGeoDatabaseDistributed.ITableDataChangesInfo):
    _IID = uuid.UUID('387adb2e-328b-464d-b6d6-548d0fd4447d')
    def Init(self, TargetName, Inserts, Updates, Deletes):
        '''Method ITableDataChangesInfo.Init

           INPUTS
            TargetName          : BSTR
            Inserts             : ITable*
            Updates             : ITable*
            Deletes             : ITable*'''
        return super(ITableDataChangesInfo, self).Init(TargetName, Inserts, Updates, Deletes)
    def SetFilter(self, changeType, Filter):
        '''Method ITableDataChangesInfo.SetFilter

           INPUTS
            changeType          : esriDataChangeType
            Filter              : IQueryFilter*'''
        return super(ITableDataChangesInfo, self).SetFilter(changeType, Filter)
    def GetFilter(self, changeType):
        '''Method ITableDataChangesInfo.GetFilter

           INPUT
            changeType          : esriDataChangeType

           OUTPUT
            Filter              : IQueryFilter**'''
        return super(ITableDataChangesInfo, self).GetFilter(changeType)
    def get_TargetName(self):
        '''Method ITableDataChangesInfo.get_TargetName

           OUTPUT
            TargetName          : BSTR*'''
        return super(ITableDataChangesInfo, self).get_TargetName()
    def get_Inserts(self):
        '''Method ITableDataChangesInfo.get_Inserts

           OUTPUT
            Table               : ITable**'''
        return super(ITableDataChangesInfo, self).get_Inserts()
    def get_Updates(self):
        '''Method ITableDataChangesInfo.get_Updates

           OUTPUT
            Table               : ITable**'''
        return super(ITableDataChangesInfo, self).get_Updates()
    def get_Deletes(self):
        '''Method ITableDataChangesInfo.get_Deletes

           OUTPUT
            Deletes             : ITable**'''
        return super(ITableDataChangesInfo, self).get_Deletes()
    def SetDeletedIDs(self, DeletedIDs, DeletedGIDs):
        '''Method ITableDataChangesInfo.SetDeletedIDs

           INPUTS
            DeletedIDs          : ILongArray*
            DeletedGIDs         : IStringArray*'''
        return super(ITableDataChangesInfo, self).SetDeletedIDs(DeletedIDs, DeletedGIDs)
    def GetDeletedIDs(self):
        '''Method ITableDataChangesInfo.GetDeletedIDs

           OUTPUTS
            DeletedIDs          : ILongArray**
            DeletedGIDs         : IStringArray**'''
        return super(ITableDataChangesInfo, self).GetDeletedIDs()
    Deletes = property(get_Deletes, None, None)
    Inserts = property(get_Inserts, None, None)
    TargetName = property(get_TargetName, None, None)
    Updates = property(get_Updates, None, None)

class ITablesDataChanges(_esriGeoDatabaseDistributed.ITablesDataChanges):
    _IID = uuid.UUID('244f9cd3-873d-42af-88a9-3f740079d4f9')
    def Init(self, ModelType):
        '''Method ITablesDataChanges.Init

           INPUT
            ModelType           : esriReplicaModelType'''
        return super(ITablesDataChanges, self).Init(ModelType)
    def Add(self, TableDataChanges):
        '''Method ITablesDataChanges.Add

           INPUT
            TableDataChanges    : ITableDataChangesInfo*'''
        return super(ITablesDataChanges, self).Add(TableDataChanges)
    def Remove(self, TargetName):
        '''Method ITablesDataChanges.Remove

           INPUT
            TargetName          : BSTR'''
        return super(ITablesDataChanges, self).Remove(TargetName)
    def FindTableChangesInfo(self, TargetName):
        '''Method ITablesDataChanges.FindTableChangesInfo

           INPUT
            TargetName          : BSTR

           OUTPUT
            TableDataChanges    : ITableDataChangesInfo**'''
        return super(ITablesDataChanges, self).FindTableChangesInfo(TargetName)
    def get_Count(self):
        '''Method ITablesDataChanges.get_Count

           OUTPUT
            Count               : long*'''
        return super(ITablesDataChanges, self).get_Count()
    Count = property(get_Count, None, None)

class IEnumTableDataChanges(_esriGeoDatabaseDistributed.IEnumTableDataChanges):
    _IID = uuid.UUID('b2573e22-0229-4f28-b33e-85573f974240')
    def Next(self):
        '''Method IEnumTableDataChanges.Next

           OUTPUT
            TableDataChanges    : ITableDataChangesInfo**'''
        return super(IEnumTableDataChanges, self).Next()
    def __iter__(self):
        try:
            super(IEnumTableDataChanges, self).Reset()
            val = super(IEnumTableDataChanges, self).Next()
            while val:
                yield val
                val = super(IEnumTableDataChanges, self).Next()
        except:
            pass
    def Reset(self):
        '''Method IEnumTableDataChanges.Reset'''
        return super(IEnumTableDataChanges, self).Reset()

class ICheckOut(_esriGeoDatabaseDistributed.ICheckOut):
    _IID = uuid.UUID('d0571ebd-d55c-46ef-90a1-246c40486dca')
    def CheckOutData(self, rDDescriptions, transferRelObjects, checkoutName):
        '''Method ICheckOut.CheckOutData

           INPUTS
            rDDescriptions      : IReplicaDescription*
            transferRelObjects  : VARIANT_BOOL
            checkoutName        : BSTR'''
        return super(ICheckOut, self).CheckOutData(rDDescriptions, transferRelObjects, checkoutName)
    def CheckOutSchema(self, rDDescription, checkoutName):
        '''Method ICheckOut.CheckOutSchema

           INPUTS
            rDDescription       : IReplicaDescription*
            checkoutName        : BSTR'''
        return super(ICheckOut, self).CheckOutSchema(rDDescription, checkoutName)

class ICheckIn(_esriGeoDatabaseDistributed.ICheckIn):
    _IID = uuid.UUID('15c5f91a-a992-42c6-a64e-53b4965fca46')
    def CheckInFromGDB(self, parentDB, checkoutName, checkOutDB, reconcileCheckout, createOIDMappingTable):
        '''Method ICheckIn.CheckInFromGDB

           INPUTS
            parentDB            : IWorkspaceName*
            checkoutName        : BSTR
            checkOutDB          : IWorkspaceName*
            reconcileCheckout   : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            conflicts_detected  : VARIANT_BOOL*'''
        return super(ICheckIn, self).CheckInFromGDB(parentDB, checkoutName, checkOutDB, reconcileCheckout, createOIDMappingTable)
    def CheckInFromDeltaFile(self, parentDB, checkoutName, fileName, dcOption, reconcileCheckout, createOIDMappingTable):
        '''Method ICheckIn.CheckInFromDeltaFile

           INPUTS
            parentDB            : IWorkspaceName*
            checkoutName        : BSTR
            fileName            : BSTR
            dcOption            : esriExportDataChangesOption
            reconcileCheckout   : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            conflicts_detected  : VARIANT_BOOL*'''
        return super(ICheckIn, self).CheckInFromDeltaFile(parentDB, checkoutName, fileName, dcOption, reconcileCheckout, createOIDMappingTable)

class ICheckIn2(_esriGeoDatabaseDistributed.ICheckIn2):
    _IID = uuid.UUID('27fce3ee-891d-407d-a36f-4d37ad14b3f6')
    def CheckInFromGDB2(self, parentDB, checkoutName, checkOutDB, reconcileCheckout, childReconcilePolicy, columnLevel, createOIDMappingTable):
        '''Method ICheckIn2.CheckInFromGDB2

           INPUTS
            parentDB            : IWorkspaceName*
            checkoutName        : BSTR
            checkOutDB          : IWorkspaceName*
            reconcileCheckout   : VARIANT_BOOL
            childReconcilePolicy: esriReplicaReconcilePolicyType
            columnLevel         : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            conflicts_detected  : VARIANT_BOOL*'''
        return super(ICheckIn2, self).CheckInFromGDB2(parentDB, checkoutName, checkOutDB, reconcileCheckout, childReconcilePolicy, columnLevel, createOIDMappingTable)
    def CheckInFromDeltaFile2(self, parentDB, checkoutName, fileName, dcOption, reconcileCheckout, childReconcilePolicy, columnLevel, createOIDMappingTable):
        '''Method ICheckIn2.CheckInFromDeltaFile2

           INPUTS
            parentDB            : IWorkspaceName*
            checkoutName        : BSTR
            fileName            : BSTR
            dcOption            : esriExportDataChangesOption
            reconcileCheckout   : VARIANT_BOOL
            childReconcilePolicy: esriReplicaReconcilePolicyType
            columnLevel         : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            conflicts_detected  : VARIANT_BOOL*'''
        return super(ICheckIn2, self).CheckInFromDeltaFile2(parentDB, checkoutName, fileName, dcOption, reconcileCheckout, childReconcilePolicy, columnLevel, createOIDMappingTable)
    def CheckInFromGDB(self, parentDB, checkoutName, checkOutDB, reconcileCheckout, createOIDMappingTable):
        '''Method ICheckIn.CheckInFromGDB (from ICheckIn)

           INPUTS
            parentDB            : IWorkspaceName*
            checkoutName        : BSTR
            checkOutDB          : IWorkspaceName*
            reconcileCheckout   : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            conflicts_detected  : VARIANT_BOOL*'''
        return super(ICheckIn2, self).CheckInFromGDB(parentDB, checkoutName, checkOutDB, reconcileCheckout, createOIDMappingTable)
    def CheckInFromDeltaFile(self, parentDB, checkoutName, fileName, dcOption, reconcileCheckout, createOIDMappingTable):
        '''Method ICheckIn.CheckInFromDeltaFile (from ICheckIn)

           INPUTS
            parentDB            : IWorkspaceName*
            checkoutName        : BSTR
            fileName            : BSTR
            dcOption            : esriExportDataChangesOption
            reconcileCheckout   : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            conflicts_detected  : VARIANT_BOOL*'''
        return super(ICheckIn2, self).CheckInFromDeltaFile(parentDB, checkoutName, fileName, dcOption, reconcileCheckout, createOIDMappingTable)

class ICheckInDataSynchronizer(_esriGeoDatabaseDistributed.ICheckInDataSynchronizer):
    _IID = uuid.UUID('73987267-11c4-477b-ae52-3dfb7dc62918')
    def Synchronize(self, DataChanges, editVersionName, ParentWorkspace, reconcileCheckout, createOIDMappingTable):
        '''Method ICheckInDataSynchronizer.Synchronize

           INPUTS
            DataChanges         : IDataChanges*
            editVersionName     : BSTR
            ParentWorkspace     : IWorkspaceName*
            reconcileCheckout   : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            conflictsDetected   : VARIANT_BOOL*'''
        return super(ICheckInDataSynchronizer, self).Synchronize(DataChanges, editVersionName, ParentWorkspace, reconcileCheckout, createOIDMappingTable)

class ICheckInDataSynchronizer2(_esriGeoDatabaseDistributed.ICheckInDataSynchronizer2):
    _IID = uuid.UUID('bb18b086-729b-4990-ab3e-a457cc584548')
    def Synchronize2(self, DataChanges, editVersionName, ParentWorkspace, reconcileCheckout, reconcilePolicy, columnLevel, createOIDMappingTable):
        '''Method ICheckInDataSynchronizer2.Synchronize2

           INPUTS
            DataChanges         : IDataChanges*
            editVersionName     : BSTR
            ParentWorkspace     : IWorkspaceName*
            reconcileCheckout   : VARIANT_BOOL
            reconcilePolicy     : esriReplicaReconcilePolicyType
            columnLevel         : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            conflictsDetected   : VARIANT_BOOL*'''
        return super(ICheckInDataSynchronizer2, self).Synchronize2(DataChanges, editVersionName, ParentWorkspace, reconcileCheckout, reconcilePolicy, columnLevel, createOIDMappingTable)
    def Synchronize(self, DataChanges, editVersionName, ParentWorkspace, reconcileCheckout, createOIDMappingTable):
        '''Method ICheckInDataSynchronizer.Synchronize (from ICheckInDataSynchronizer)

           INPUTS
            DataChanges         : IDataChanges*
            editVersionName     : BSTR
            ParentWorkspace     : IWorkspaceName*
            reconcileCheckout   : VARIANT_BOOL
            createOIDMappingTable: VARIANT_BOOL

           OUTPUT
            conflictsDetected   : VARIANT_BOOL*'''
        return super(ICheckInDataSynchronizer2, self).Synchronize(DataChanges, editVersionName, ParentWorkspace, reconcileCheckout, createOIDMappingTable)

class IReplicaValidation(_esriGeoDatabaseDistributed.IReplicaValidation):
    _IID = uuid.UUID('059a0b29-8d46-475f-a4d8-77f220ec2cbb')
    def ValidateReplicaPair(self, parentDB, ReplicaName, checkOutDB):
        '''Method IReplicaValidation.ValidateReplicaPair

           INPUTS
            parentDB            : IWorkspaceName*
            ReplicaName         : BSTR
            checkOutDB          : IWorkspaceName*

           OUTPUT
            isValid             : VARIANT_BOOL*'''
        return super(IReplicaValidation, self).ValidateReplicaPair(parentDB, ReplicaName, checkOutDB)
    def ValidateDeltaFile(self, parentDB, ReplicaName, DeltaFileName, sourceType):
        '''Method IReplicaValidation.ValidateDeltaFile

           INPUTS
            parentDB            : IWorkspaceName*
            ReplicaName         : BSTR
            DeltaFileName       : BSTR
            sourceType          : esriCheckInSourceType

           OUTPUT
            isValid             : VARIANT_BOOL*'''
        return super(IReplicaValidation, self).ValidateDeltaFile(parentDB, ReplicaName, DeltaFileName, sourceType)

class IReplicaValidation2(_esriGeoDatabaseDistributed.IReplicaValidation2):
    _IID = uuid.UUID('90b7c766-754e-47e9-bc42-7c03a336c82f')
    def ValidateReplicaSchema(self, Replica):
        '''Method IReplicaValidation2.ValidateReplicaSchema

           INPUT
            Replica             : IReplica*'''
        return super(IReplicaValidation2, self).ValidateReplicaSchema(Replica)
    def ValidateReplicaPair(self, parentDB, ReplicaName, checkOutDB):
        '''Method IReplicaValidation.ValidateReplicaPair (from IReplicaValidation)

           INPUTS
            parentDB            : IWorkspaceName*
            ReplicaName         : BSTR
            checkOutDB          : IWorkspaceName*

           OUTPUT
            isValid             : VARIANT_BOOL*'''
        return super(IReplicaValidation2, self).ValidateReplicaPair(parentDB, ReplicaName, checkOutDB)
    def ValidateDeltaFile(self, parentDB, ReplicaName, DeltaFileName, sourceType):
        '''Method IReplicaValidation.ValidateDeltaFile (from IReplicaValidation)

           INPUTS
            parentDB            : IWorkspaceName*
            ReplicaName         : BSTR
            DeltaFileName       : BSTR
            sourceType          : esriCheckInSourceType

           OUTPUT
            isValid             : VARIANT_BOOL*'''
        return super(IReplicaValidation2, self).ValidateDeltaFile(parentDB, ReplicaName, DeltaFileName, sourceType)

class IReplicaMessageHandler(_esriGeoDatabaseDistributed.IReplicaMessageHandler):
    _IID = uuid.UUID('ce6fe713-7b5a-4e27-808f-97ecfa588f2b')
    def Init(self, MsgFileName, MsgExportOption):
        '''Method IReplicaMessageHandler.Init

           INPUTS
            MsgFileName         : BSTR
            MsgExportOption     : esriExportDataChangesOption'''
        return super(IReplicaMessageHandler, self).Init(MsgFileName, MsgExportOption)
    def get_ReplicaGuid(self):
        '''Method IReplicaMessageHandler.get_ReplicaGuid

           OUTPUT
            GUID                : BSTR*'''
        return super(IReplicaMessageHandler, self).get_ReplicaGuid()
    def get_MessageType(self):
        '''Method IReplicaMessageHandler.get_MessageType

           OUTPUT
            MsgType             : esriReplicaMessageType*'''
        return super(IReplicaMessageHandler, self).get_MessageType()
    def get_MyGenerationNumber(self):
        '''Method IReplicaMessageHandler.get_MyGenerationNumber

           OUTPUT
            GenerationNumber    : long*'''
        return super(IReplicaMessageHandler, self).get_MyGenerationNumber()
    def get_SibGenerationNumber(self):
        '''Method IReplicaMessageHandler.get_SibGenerationNumber

           OUTPUT
            SibGen              : long*'''
        return super(IReplicaMessageHandler, self).get_SibGenerationNumber()
    def get_DeltaDataChanges(self):
        '''Method IReplicaMessageHandler.get_DeltaDataChanges

           OUTPUT
            DeltaDC             : IDeltaDataChanges**'''
        return super(IReplicaMessageHandler, self).get_DeltaDataChanges()
    DeltaDataChanges = property(get_DeltaDataChanges, None, None)
    MessageType = property(get_MessageType, None, None)
    MyGenerationNumber = property(get_MyGenerationNumber, None, None)
    ReplicaGuid = property(get_ReplicaGuid, None, None)
    SibGenerationNumber = property(get_SibGenerationNumber, None, None)

class IReplicaMessageHandler2(_esriGeoDatabaseDistributed.IReplicaMessageHandler2):
    _IID = uuid.UUID('37d98d2a-97e0-4252-86ac-af3395581877')
    def get_MyTime(self):
        '''Method IReplicaMessageHandler2.get_MyTime

           OUTPUT
            MyTime              : VARIANT*'''
        return super(IReplicaMessageHandler2, self).get_MyTime()
    def get_SibTime(self):
        '''Method IReplicaMessageHandler2.get_SibTime

           OUTPUT
            SibTime             : VARIANT*'''
        return super(IReplicaMessageHandler2, self).get_SibTime()
    def get_SibMyTime(self):
        '''Method IReplicaMessageHandler2.get_SibMyTime

           OUTPUT
            SibMyTime           : VARIANT*'''
        return super(IReplicaMessageHandler2, self).get_SibMyTime()
    def Init(self, MsgFileName, MsgExportOption):
        '''Method IReplicaMessageHandler.Init (from IReplicaMessageHandler)

           INPUTS
            MsgFileName         : BSTR
            MsgExportOption     : esriExportDataChangesOption'''
        return super(IReplicaMessageHandler2, self).Init(MsgFileName, MsgExportOption)
    def get_ReplicaGuid(self):
        '''Method IReplicaMessageHandler.get_ReplicaGuid (from IReplicaMessageHandler)

           OUTPUT
            GUID                : BSTR*'''
        return super(IReplicaMessageHandler2, self).get_ReplicaGuid()
    def get_MessageType(self):
        '''Method IReplicaMessageHandler.get_MessageType (from IReplicaMessageHandler)

           OUTPUT
            MsgType             : esriReplicaMessageType*'''
        return super(IReplicaMessageHandler2, self).get_MessageType()
    def get_MyGenerationNumber(self):
        '''Method IReplicaMessageHandler.get_MyGenerationNumber (from IReplicaMessageHandler)

           OUTPUT
            GenerationNumber    : long*'''
        return super(IReplicaMessageHandler2, self).get_MyGenerationNumber()
    def get_SibGenerationNumber(self):
        '''Method IReplicaMessageHandler.get_SibGenerationNumber (from IReplicaMessageHandler)

           OUTPUT
            SibGen              : long*'''
        return super(IReplicaMessageHandler2, self).get_SibGenerationNumber()
    def get_DeltaDataChanges(self):
        '''Method IReplicaMessageHandler.get_DeltaDataChanges (from IReplicaMessageHandler)

           OUTPUT
            DeltaDC             : IDeltaDataChanges**'''
        return super(IReplicaMessageHandler2, self).get_DeltaDataChanges()
    DeltaDataChanges = property(get_DeltaDataChanges, None, None)
    MessageType = property(get_MessageType, None, None)
    MyGenerationNumber = property(get_MyGenerationNumber, None, None)
    MyTime = property(get_MyTime, None, None)
    ReplicaGuid = property(get_ReplicaGuid, None, None)
    SibGenerationNumber = property(get_SibGenerationNumber, None, None)
    SibMyTime = property(get_SibMyTime, None, None)
    SibTime = property(get_SibTime, None, None)

class IGDSData(_esriGeoDatabaseDistributed.IGDSData):
    _IID = uuid.UUID('bdfd716d-e902-4907-9c97-65da73f02ae9')

    def __init__(self, *args, **kw):
        super(IGDSData, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Compressed(self):
        '''Method IGDSData.get_Compressed

           OUTPUT
            comp                : VARIANT_BOOL*'''
        return super(IGDSData, self).get_Compressed()
    def put_Compressed(self, comp):
        '''Method IGDSData.put_Compressed

           INPUT
            comp                : VARIANT_BOOL'''
        return super(IGDSData, self).put_Compressed(comp)
    def get_TransportType(self):
        '''Method IGDSData.get_TransportType

           OUTPUT
            pTransport          : esriGDSTransportType*'''
        return super(IGDSData, self).get_TransportType()
    def put_TransportType(self, pTransport):
        '''Method IGDSData.put_TransportType

           INPUT
            pTransport          : esriGDSTransportType'''
        return super(IGDSData, self).put_TransportType(pTransport)
    def get_URL(self):
        '''Method IGDSData.get_URL

           OUTPUT
            URL                 : BSTR*'''
        return super(IGDSData, self).get_URL()
    def put_URL(self, URL):
        '''Method IGDSData.put_URL

           INPUT
            URL                 : BSTR'''
        return super(IGDSData, self).put_URL(URL)
    def get_EmbeddedData(self):
        '''Method IGDSData.get_EmbeddedData

           OUTPUT
            data                : SAFEARRAY**'''
        return super(IGDSData, self).get_EmbeddedData()
    def put_EmbeddedData(self, data):
        '''Method IGDSData.put_EmbeddedData

           INPUT
            data                : SAFEARRAY**'''
        return super(IGDSData, self).put_EmbeddedData(data)
    def putref_ConnectionProperties(self, connProps):
        '''Method IGDSData.putref_ConnectionProperties

           INPUT
            connProps           : IPropertySet*'''
        return super(IGDSData, self).putref_ConnectionProperties(connProps)
    def get_ConnectionProperties(self):
        '''Method IGDSData.get_ConnectionProperties

           OUTPUT
            connProps           : IPropertySet**'''
        return super(IGDSData, self).get_ConnectionProperties()
    Compressed = property(get_Compressed, put_Compressed, None)
    ConnectionProperties = property(get_ConnectionProperties, putref_ConnectionProperties, None)
    EmbeddedData = property(get_EmbeddedData, put_EmbeddedData, None)
    TransportType = property(get_TransportType, put_TransportType, None)
    URL = property(get_URL, put_URL, None)

class IGDSExportOptions(_esriGeoDatabaseDistributed.IGDSExportOptions):
    _IID = uuid.UUID('fc23fbc0-dc6a-41fc-8914-36677fba6855')

    def __init__(self, *args, **kw):
        super(IGDSExportOptions, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ExportFormat(self):
        '''Method IGDSExportOptions.get_ExportFormat

           OUTPUT
            ExportFormat        : esriGDSExportFormat*'''
        return super(IGDSExportOptions, self).get_ExportFormat()
    def put_ExportFormat(self, ExportFormat):
        '''Method IGDSExportOptions.put_ExportFormat

           INPUT
            ExportFormat        : esriGDSExportFormat'''
        return super(IGDSExportOptions, self).put_ExportFormat(ExportFormat)
    def get_Compressed(self):
        '''Method IGDSExportOptions.get_Compressed

           OUTPUT
            comp                : VARIANT_BOOL*'''
        return super(IGDSExportOptions, self).get_Compressed()
    def put_Compressed(self, comp):
        '''Method IGDSExportOptions.put_Compressed

           INPUT
            comp                : VARIANT_BOOL'''
        return super(IGDSExportOptions, self).put_Compressed(comp)
    def get_BinaryGeometry(self):
        '''Method IGDSExportOptions.get_BinaryGeometry

           OUTPUT
            BinaryGeometry      : VARIANT_BOOL*'''
        return super(IGDSExportOptions, self).get_BinaryGeometry()
    def put_BinaryGeometry(self, BinaryGeometry):
        '''Method IGDSExportOptions.put_BinaryGeometry

           INPUT
            BinaryGeometry      : VARIANT_BOOL'''
        return super(IGDSExportOptions, self).put_BinaryGeometry(BinaryGeometry)
    BinaryGeometry = property(get_BinaryGeometry, put_BinaryGeometry, None)
    Compressed = property(get_Compressed, put_Compressed, None)
    ExportFormat = property(get_ExportFormat, put_ExportFormat, None)

class IGDSQueryResultPortion(_esriGeoDatabaseDistributed.IGDSQueryResultPortion):
    _IID = uuid.UUID('6babaf1e-d1a3-487f-bde1-58a206503dbc')

    def __init__(self, *args, **kw):
        super(IGDSQueryResultPortion, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Records(self):
        '''Method IGDSQueryResultPortion.get_Records

           OUTPUT
            recordSet           : IRecordSet**'''
        return super(IGDSQueryResultPortion, self).get_Records()
    def putref_Records(self, recordSet):
        '''Method IGDSQueryResultPortion.putref_Records

           INPUT
            recordSet           : IRecordSet*'''
        return super(IGDSQueryResultPortion, self).putref_Records(recordSet)
    Records = property(get_Records, putref_Records, None)

class IGeoDataServer(_esriGeoDatabaseDistributed.IGeoDataServer):
    _IID = uuid.UUID('b59deddd-065f-4c9f-942a-af79e8ab3fbc')
    def get_MaxRecordCount(self):
        '''Method IGeoDataServer.get_MaxRecordCount

           OUTPUT
            maxCount            : long*'''
        return super(IGeoDataServer, self).get_MaxRecordCount()
    def get_DataElements(self, pBrowseOptions):
        '''Method IGeoDataServer.get_DataElements

           INPUT
            pBrowseOptions      : IDEBrowseOptions*

           OUTPUT
            DataElements        : IDataElements**'''
        return super(IGeoDataServer, self).get_DataElements(pBrowseOptions)
    def get_Versions(self):
        '''Method IGeoDataServer.get_Versions

           OUTPUT
            versionInfos        : IGPVersionInfos**'''
        return super(IGeoDataServer, self).get_Versions()
    def get_Replicas(self):
        '''Method IGeoDataServer.get_Replicas

           OUTPUT
            Replicas            : IGPReplicas**'''
        return super(IGeoDataServer, self).get_Replicas()
    def get_DefaultWorkingVersion(self):
        '''Method IGeoDataServer.get_DefaultWorkingVersion

           OUTPUT
            DefaultWorkingVersion: BSTR*'''
        return super(IGeoDataServer, self).get_DefaultWorkingVersion()
    def get_WrappedWorkspaceType(self):
        '''Method IGeoDataServer.get_WrappedWorkspaceType

           OUTPUT
            wsType              : esriWorkspaceType*'''
        return super(IGeoDataServer, self).get_WrappedWorkspaceType()
    def ExtractData(self, versionName, replicaDesc, options, TransportType):
        '''Method IGeoDataServer.ExtractData

           INPUTS
            versionName         : BSTR
            replicaDesc         : IGPReplicaDescription*
            options             : IGDSExportOptions*
            TransportType       : esriGDSTransportType

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer, self).ExtractData(versionName, replicaDesc, options, TransportType)
    def CreateReplica(self, parentVersion, ReplicaName, replicaDesc, repOptions, exportOptions, TransportType):
        '''Method IGeoDataServer.CreateReplica

           INPUTS
            parentVersion       : BSTR
            ReplicaName         : BSTR
            replicaDesc         : IGPReplicaDescription*
            repOptions          : IGPReplicaOptions*
            exportOptions       : IGDSExportOptions*
            TransportType       : esriGDSTransportType

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer, self).CreateReplica(parentVersion, ReplicaName, replicaDesc, repOptions, exportOptions, TransportType)
    def ExpandReplicaDatasets(self, repDatasets):
        '''Method IGeoDataServer.ExpandReplicaDatasets

           INPUT
            repDatasets         : IGPReplicaDatasets*

           OUTPUT
            expandedRepDatasets : IGPReplicaDatasets**'''
        return super(IGeoDataServer, self).ExpandReplicaDatasets(repDatasets)
    def ImportData(self, pData, fmt):
        '''Method IGeoDataServer.ImportData

           INPUTS
            pData               : IGDSData*
            fmt                 : esriGDSImportFormat'''
        return super(IGeoDataServer, self).ImportData(pData, fmt)
    def ExportReplicaDataChanges(self, ReplicaName, options, TransportType, generationsToExport, switchRole):
        '''Method IGeoDataServer.ExportReplicaDataChanges

           INPUTS
            ReplicaName         : BSTR
            options             : IGDSExportOptions*
            TransportType       : esriGDSTransportType
            generationsToExport : esriExportGenerationsOption
            switchRole          : VARIANT_BOOL

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer, self).ExportReplicaDataChanges(ReplicaName, options, TransportType, generationsToExport, switchRole)
    def ReExportReplicaDataChanges(self, ReplicaName, options, TransportType, gensToExport):
        '''Method IGeoDataServer.ReExportReplicaDataChanges

           INPUTS
            ReplicaName         : BSTR
            options             : IGDSExportOptions*
            TransportType       : esriGDSTransportType
            gensToExport        : esriReExportGenerationsOption

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer, self).ReExportReplicaDataChanges(ReplicaName, options, TransportType, gensToExport)
    def ImportReplicaDataChanges(self, sourceType, reconcilePolicy, columnLevel, data):
        '''Method IGeoDataServer.ImportReplicaDataChanges

           INPUTS
            sourceType          : esriGDSReplicaImportSource
            reconcilePolicy     : esriReplicaReconcilePolicyType
            columnLevel         : VARIANT_BOOL
            data                : IGDSData*

           OUTPUT
            conflictsFound      : VARIANT_BOOL*'''
        return super(IGeoDataServer, self).ImportReplicaDataChanges(sourceType, reconcilePolicy, columnLevel, data)
    def ExportAcknowledgement(self, ReplicaName, TransportType):
        '''Method IGeoDataServer.ExportAcknowledgement

           INPUTS
            ReplicaName         : BSTR
            TransportType       : esriGDSTransportType

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer, self).ExportAcknowledgement(ReplicaName, TransportType)
    def ImportAcknowledgement(self, data):
        '''Method IGeoDataServer.ImportAcknowledgement

           INPUT
            data                : IGDSData*'''
        return super(IGeoDataServer, self).ImportAcknowledgement(data)
    def UnregisterReplica(self, ReplicaName):
        '''Method IGeoDataServer.UnregisterReplica

           INPUT
            ReplicaName         : BSTR'''
        return super(IGeoDataServer, self).UnregisterReplica(ReplicaName)
    def TableSearch(self, versionName, tableName, queryFilter, queryRange):
        '''Method IGeoDataServer.TableSearch

           INPUTS
            versionName         : BSTR
            tableName           : BSTR
            queryFilter         : IQueryFilter*
            queryRange          : IResultPortionInfo*

           OUTPUT
            resultPortion       : IGDSQueryResultPortion**'''
        return super(IGeoDataServer, self).TableSearch(versionName, tableName, queryFilter, queryRange)
    def GetNextResultPortion(self, desiredRange):
        '''Method IGeoDataServer.GetNextResultPortion

           INPUT
            desiredRange        : IResultPortionInfo*

           OUTPUT
            resultPortion       : IGDSQueryResultPortion**'''
        return super(IGeoDataServer, self).GetNextResultPortion(desiredRange)
    def ExportReplicaSchema(self, ReplicaName, TransportType):
        '''Method IGeoDataServer.ExportReplicaSchema

           INPUTS
            ReplicaName         : BSTR
            TransportType       : esriGDSTransportType

           OUTPUT
            replicaSchemaDoc    : IGDSData**'''
        return super(IGeoDataServer, self).ExportReplicaSchema(ReplicaName, TransportType)
    def CompareReplicaSchema(self, relativeReplicaSchemaDoc, TransportType):
        '''Method IGeoDataServer.CompareReplicaSchema

           INPUTS
            relativeReplicaSchemaDoc: IGDSData*
            TransportType       : esriGDSTransportType

           OUTPUT
            schemaChangesDoc    : IGDSData**'''
        return super(IGeoDataServer, self).CompareReplicaSchema(relativeReplicaSchemaDoc, TransportType)
    def ImportReplicaSchemaChanges(self, schemaChangesDoc):
        '''Method IGeoDataServer.ImportReplicaSchemaChanges

           INPUT
            schemaChangesDoc    : IGDSData*'''
        return super(IGeoDataServer, self).ImportReplicaSchemaChanges(schemaChangesDoc)
    DefaultWorkingVersion = property(get_DefaultWorkingVersion, None, None)
    MaxRecordCount = property(get_MaxRecordCount, None, None)
    Replicas = property(get_Replicas, None, None)
    Versions = property(get_Versions, None, None)
    WrappedWorkspaceType = property(get_WrappedWorkspaceType, None, None)
    DataElements = IndexProperty(get_DataElements, None)

class IGeoDataServerInit(_esriGeoDatabaseDistributed.IGeoDataServerInit):
    _IID = uuid.UUID('841bdc30-fe10-46af-b67b-582252bc16b8')

    def __init__(self, *args, **kw):
        super(IGeoDataServerInit, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def InitFromMap(self, filePath):
        '''Method IGeoDataServerInit.InitFromMap

           INPUT
            filePath            : BSTR'''
        return super(IGeoDataServerInit, self).InitFromMap(filePath)
    def InitFromFile(self, file):
        '''Method IGeoDataServerInit.InitFromFile

           INPUT
            file                : BSTR'''
        return super(IGeoDataServerInit, self).InitFromFile(file)
    def InitFromConnectionString(self, connectionString):
        '''Method IGeoDataServerInit.InitFromConnectionString

           INPUT
            connectionString    : BSTR'''
        return super(IGeoDataServerInit, self).InitFromConnectionString(connectionString)
    def InitWithWorkspace(self, pWorkspace):
        '''Method IGeoDataServerInit.InitWithWorkspace

           INPUT
            pWorkspace          : IWorkspace*'''
        return super(IGeoDataServerInit, self).InitWithWorkspace(pWorkspace)
    def put_PhysicalOutputDirectory(self, dirPath):
        '''Method IGeoDataServerInit.put_PhysicalOutputDirectory

           INPUT
            dirPath             : BSTR'''
        return super(IGeoDataServerInit, self).put_PhysicalOutputDirectory(dirPath)
    def get_PhysicalOutputDirectory(self):
        '''Method IGeoDataServerInit.get_PhysicalOutputDirectory

           OUTPUT
            dirPath             : BSTR*'''
        return super(IGeoDataServerInit, self).get_PhysicalOutputDirectory()
    def put_VirtualOutputDirectory(self, dirPath):
        '''Method IGeoDataServerInit.put_VirtualOutputDirectory

           INPUT
            dirPath             : BSTR'''
        return super(IGeoDataServerInit, self).put_VirtualOutputDirectory(dirPath)
    def get_VirtualOutputDirectory(self):
        '''Method IGeoDataServerInit.get_VirtualOutputDirectory

           OUTPUT
            dirPath             : BSTR*'''
        return super(IGeoDataServerInit, self).get_VirtualOutputDirectory()
    def get_MaxRecordCount(self):
        '''Method IGeoDataServerInit.get_MaxRecordCount

           OUTPUT
            Count               : long*'''
        return super(IGeoDataServerInit, self).get_MaxRecordCount()
    def put_MaxRecordCount(self, Count):
        '''Method IGeoDataServerInit.put_MaxRecordCount

           INPUT
            Count               : long'''
        return super(IGeoDataServerInit, self).put_MaxRecordCount(Count)
    MaxRecordCount = property(get_MaxRecordCount, put_MaxRecordCount, None)
    PhysicalOutputDirectory = property(get_PhysicalOutputDirectory, put_PhysicalOutputDirectory, None)
    VirtualOutputDirectory = property(get_VirtualOutputDirectory, put_VirtualOutputDirectory, None)

class IGeoDataServerObjects(_esriGeoDatabaseDistributed.IGeoDataServerObjects):
    _IID = uuid.UUID('f3b8e8ca-fdcc-4f3b-a581-ab11258cb801')
    def get_DefaultWorkingWorkspace(self):
        '''Method IGeoDataServerObjects.get_DefaultWorkingWorkspace

           OUTPUT
            Workspace           : IWorkspace**'''
        return super(IGeoDataServerObjects, self).get_DefaultWorkingWorkspace()
    DefaultWorkingWorkspace = property(get_DefaultWorkingWorkspace, None, None)

class IReplicationAgent(_esriGeoDatabaseDistributed.IReplicationAgent):
    _IID = uuid.UUID('ab9f2c3d-9298-480b-a57c-4afcc8d7c498')
    def CreateReplica(self, versionName, srcGDS, destGDS, ReplicaName, desc, repOptions):
        '''Method IReplicationAgent.CreateReplica

           INPUTS
            versionName         : BSTR
            srcGDS              : IGeoDataServer*
            destGDS             : IGeoDataServer*
            ReplicaName         : BSTR
            desc                : IGPReplicaDescription*
            repOptions          : IGPReplicaOptions*'''
        return super(IReplicationAgent, self).CreateReplica(versionName, srcGDS, destGDS, ReplicaName, desc, repOptions)
    def SynchronizeReplica(self, gds1, gds2, rep1, rep2, pol, dir, columnLevel):
        '''Method IReplicationAgent.SynchronizeReplica

           INPUTS
            gds1                : IGeoDataServer*
            gds2                : IGeoDataServer*
            rep1                : IGPReplica*
            rep2                : IGPReplica*
            pol                 : esriReplicationAgentReconcilePolicy
            dir                 : esriReplicaSynchronizeDirection
            columnLevel         : VARIANT_BOOL

           OUTPUT
            conflictsDetected   : VARIANT_BOOL*'''
        return super(IReplicationAgent, self).SynchronizeReplica(gds1, gds2, rep1, rep2, pol, dir, columnLevel)
    def ExtractData(self, versionName, srcGDS, destGDS, desc):
        '''Method IReplicationAgent.ExtractData

           INPUTS
            versionName         : BSTR
            srcGDS              : IGeoDataServer*
            destGDS             : IGeoDataServer*
            desc                : IGPReplicaDescription*'''
        return super(IReplicationAgent, self).ExtractData(versionName, srcGDS, destGDS, desc)

class IReplicationAgentCancelControl(_esriGeoDatabaseDistributed.IReplicationAgentCancelControl):
    _IID = uuid.UUID('fe61bef1-7ae3-45c6-84de-a9d6019a4d77')

    def __init__(self, *args, **kw):
        super(IReplicationAgentCancelControl, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def putref_CancelTracker(self, _arg1):
        '''Method IReplicationAgentCancelControl.putref_CancelTracker

           INPUT
            _arg1               : ITrackCancel*'''
        return super(IReplicationAgentCancelControl, self).putref_CancelTracker(_arg1)
    CancelTracker = property(None, putref_CancelTracker, None)

class IGDSData2(_esriGeoDatabaseDistributed.IGDSData2):
    _IID = uuid.UUID('74a172d5-7d99-41e1-9840-415193b5f58c')

    def __init__(self, *args, **kw):
        super(IGDSData2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_UploadID(self):
        '''Method IGDSData2.get_UploadID

           OUTPUT
            UploadID            : BSTR*'''
        return super(IGDSData2, self).get_UploadID()
    def put_UploadID(self, UploadID):
        '''Method IGDSData2.put_UploadID

           INPUT
            UploadID            : BSTR'''
        return super(IGDSData2, self).put_UploadID(UploadID)
    def get_Compressed(self):
        '''Method IGDSData.get_Compressed (from IGDSData)

           OUTPUT
            comp                : VARIANT_BOOL*'''
        return super(IGDSData2, self).get_Compressed()
    def put_Compressed(self, comp):
        '''Method IGDSData.put_Compressed (from IGDSData)

           INPUT
            comp                : VARIANT_BOOL'''
        return super(IGDSData2, self).put_Compressed(comp)
    def get_TransportType(self):
        '''Method IGDSData.get_TransportType (from IGDSData)

           OUTPUT
            pTransport          : esriGDSTransportType*'''
        return super(IGDSData2, self).get_TransportType()
    def put_TransportType(self, pTransport):
        '''Method IGDSData.put_TransportType (from IGDSData)

           INPUT
            pTransport          : esriGDSTransportType'''
        return super(IGDSData2, self).put_TransportType(pTransport)
    def get_URL(self):
        '''Method IGDSData.get_URL (from IGDSData)

           OUTPUT
            URL                 : BSTR*'''
        return super(IGDSData2, self).get_URL()
    def put_URL(self, URL):
        '''Method IGDSData.put_URL (from IGDSData)

           INPUT
            URL                 : BSTR'''
        return super(IGDSData2, self).put_URL(URL)
    def get_EmbeddedData(self):
        '''Method IGDSData.get_EmbeddedData (from IGDSData)

           OUTPUT
            data                : SAFEARRAY**'''
        return super(IGDSData2, self).get_EmbeddedData()
    def put_EmbeddedData(self, data):
        '''Method IGDSData.put_EmbeddedData (from IGDSData)

           INPUT
            data                : SAFEARRAY**'''
        return super(IGDSData2, self).put_EmbeddedData(data)
    def putref_ConnectionProperties(self, connProps):
        '''Method IGDSData.putref_ConnectionProperties (from IGDSData)

           INPUT
            connProps           : IPropertySet*'''
        return super(IGDSData2, self).putref_ConnectionProperties(connProps)
    def get_ConnectionProperties(self):
        '''Method IGDSData.get_ConnectionProperties (from IGDSData)

           OUTPUT
            connProps           : IPropertySet**'''
        return super(IGDSData2, self).get_ConnectionProperties()
    Compressed = property(get_Compressed, put_Compressed, None)
    ConnectionProperties = property(get_ConnectionProperties, putref_ConnectionProperties, None)
    EmbeddedData = property(get_EmbeddedData, put_EmbeddedData, None)
    TransportType = property(get_TransportType, put_TransportType, None)
    URL = property(get_URL, put_URL, None)
    UploadID = property(get_UploadID, put_UploadID, None)

class IGeoDataServer2(_esriGeoDatabaseDistributed.IGeoDataServer2):
    _IID = uuid.UUID('5906a736-62ed-4fb6-b84f-191131dfab07')
    def ExpandReplicaDatasets2(self, GPReplicaDatasets, ReplicaOptions):
        '''Method IGeoDataServer2.ExpandReplicaDatasets2

           INPUTS
            GPReplicaDatasets   : IGPReplicaDatasets*
            ReplicaOptions      : IGPReplicaOptions*

           OUTPUT
            ExpandGPReplicaDatasets: IGPReplicaDatasets**'''
        return super(IGeoDataServer2, self).ExpandReplicaDatasets2(GPReplicaDatasets, ReplicaOptions)
    def get_Replica(self, ReplicaName):
        '''Method IGeoDataServer2.get_Replica

           INPUT
            ReplicaName         : BSTR

           OUTPUT
            GPReplica           : IGPReplica**'''
        return super(IGeoDataServer2, self).get_Replica(ReplicaName)
    def get_MaxRecordCount(self):
        '''Method IGeoDataServer.get_MaxRecordCount (from IGeoDataServer)

           OUTPUT
            maxCount            : long*'''
        return super(IGeoDataServer2, self).get_MaxRecordCount()
    def get_DataElements(self, pBrowseOptions):
        '''Method IGeoDataServer.get_DataElements (from IGeoDataServer)

           INPUT
            pBrowseOptions      : IDEBrowseOptions*

           OUTPUT
            DataElements        : IDataElements**'''
        return super(IGeoDataServer2, self).get_DataElements(pBrowseOptions)
    def get_Versions(self):
        '''Method IGeoDataServer.get_Versions (from IGeoDataServer)

           OUTPUT
            versionInfos        : IGPVersionInfos**'''
        return super(IGeoDataServer2, self).get_Versions()
    def get_Replicas(self):
        '''Method IGeoDataServer.get_Replicas (from IGeoDataServer)

           OUTPUT
            Replicas            : IGPReplicas**'''
        return super(IGeoDataServer2, self).get_Replicas()
    def get_DefaultWorkingVersion(self):
        '''Method IGeoDataServer.get_DefaultWorkingVersion (from IGeoDataServer)

           OUTPUT
            DefaultWorkingVersion: BSTR*'''
        return super(IGeoDataServer2, self).get_DefaultWorkingVersion()
    def get_WrappedWorkspaceType(self):
        '''Method IGeoDataServer.get_WrappedWorkspaceType (from IGeoDataServer)

           OUTPUT
            wsType              : esriWorkspaceType*'''
        return super(IGeoDataServer2, self).get_WrappedWorkspaceType()
    def ExtractData(self, versionName, replicaDesc, options, TransportType):
        '''Method IGeoDataServer.ExtractData (from IGeoDataServer)

           INPUTS
            versionName         : BSTR
            replicaDesc         : IGPReplicaDescription*
            options             : IGDSExportOptions*
            TransportType       : esriGDSTransportType

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer2, self).ExtractData(versionName, replicaDesc, options, TransportType)
    def CreateReplica(self, parentVersion, ReplicaName, replicaDesc, repOptions, exportOptions, TransportType):
        '''Method IGeoDataServer.CreateReplica (from IGeoDataServer)

           INPUTS
            parentVersion       : BSTR
            ReplicaName         : BSTR
            replicaDesc         : IGPReplicaDescription*
            repOptions          : IGPReplicaOptions*
            exportOptions       : IGDSExportOptions*
            TransportType       : esriGDSTransportType

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer2, self).CreateReplica(parentVersion, ReplicaName, replicaDesc, repOptions, exportOptions, TransportType)
    def ExpandReplicaDatasets(self, repDatasets):
        '''Method IGeoDataServer.ExpandReplicaDatasets (from IGeoDataServer)

           INPUT
            repDatasets         : IGPReplicaDatasets*

           OUTPUT
            expandedRepDatasets : IGPReplicaDatasets**'''
        return super(IGeoDataServer2, self).ExpandReplicaDatasets(repDatasets)
    def ImportData(self, pData, fmt):
        '''Method IGeoDataServer.ImportData (from IGeoDataServer)

           INPUTS
            pData               : IGDSData*
            fmt                 : esriGDSImportFormat'''
        return super(IGeoDataServer2, self).ImportData(pData, fmt)
    def ExportReplicaDataChanges(self, ReplicaName, options, TransportType, generationsToExport, switchRole):
        '''Method IGeoDataServer.ExportReplicaDataChanges (from IGeoDataServer)

           INPUTS
            ReplicaName         : BSTR
            options             : IGDSExportOptions*
            TransportType       : esriGDSTransportType
            generationsToExport : esriExportGenerationsOption
            switchRole          : VARIANT_BOOL

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer2, self).ExportReplicaDataChanges(ReplicaName, options, TransportType, generationsToExport, switchRole)
    def ReExportReplicaDataChanges(self, ReplicaName, options, TransportType, gensToExport):
        '''Method IGeoDataServer.ReExportReplicaDataChanges (from IGeoDataServer)

           INPUTS
            ReplicaName         : BSTR
            options             : IGDSExportOptions*
            TransportType       : esriGDSTransportType
            gensToExport        : esriReExportGenerationsOption

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer2, self).ReExportReplicaDataChanges(ReplicaName, options, TransportType, gensToExport)
    def ImportReplicaDataChanges(self, sourceType, reconcilePolicy, columnLevel, data):
        '''Method IGeoDataServer.ImportReplicaDataChanges (from IGeoDataServer)

           INPUTS
            sourceType          : esriGDSReplicaImportSource
            reconcilePolicy     : esriReplicaReconcilePolicyType
            columnLevel         : VARIANT_BOOL
            data                : IGDSData*

           OUTPUT
            conflictsFound      : VARIANT_BOOL*'''
        return super(IGeoDataServer2, self).ImportReplicaDataChanges(sourceType, reconcilePolicy, columnLevel, data)
    def ExportAcknowledgement(self, ReplicaName, TransportType):
        '''Method IGeoDataServer.ExportAcknowledgement (from IGeoDataServer)

           INPUTS
            ReplicaName         : BSTR
            TransportType       : esriGDSTransportType

           OUTPUT
            result              : IGDSData**'''
        return super(IGeoDataServer2, self).ExportAcknowledgement(ReplicaName, TransportType)
    def ImportAcknowledgement(self, data):
        '''Method IGeoDataServer.ImportAcknowledgement (from IGeoDataServer)

           INPUT
            data                : IGDSData*'''
        return super(IGeoDataServer2, self).ImportAcknowledgement(data)
    def UnregisterReplica(self, ReplicaName):
        '''Method IGeoDataServer.UnregisterReplica (from IGeoDataServer)

           INPUT
            ReplicaName         : BSTR'''
        return super(IGeoDataServer2, self).UnregisterReplica(ReplicaName)
    def TableSearch(self, versionName, tableName, queryFilter, queryRange):
        '''Method IGeoDataServer.TableSearch (from IGeoDataServer)

           INPUTS
            versionName         : BSTR
            tableName           : BSTR
            queryFilter         : IQueryFilter*
            queryRange          : IResultPortionInfo*

           OUTPUT
            resultPortion       : IGDSQueryResultPortion**'''
        return super(IGeoDataServer2, self).TableSearch(versionName, tableName, queryFilter, queryRange)
    def GetNextResultPortion(self, desiredRange):
        '''Method IGeoDataServer.GetNextResultPortion (from IGeoDataServer)

           INPUT
            desiredRange        : IResultPortionInfo*

           OUTPUT
            resultPortion       : IGDSQueryResultPortion**'''
        return super(IGeoDataServer2, self).GetNextResultPortion(desiredRange)
    def ExportReplicaSchema(self, ReplicaName, TransportType):
        '''Method IGeoDataServer.ExportReplicaSchema (from IGeoDataServer)

           INPUTS
            ReplicaName         : BSTR
            TransportType       : esriGDSTransportType

           OUTPUT
            replicaSchemaDoc    : IGDSData**'''
        return super(IGeoDataServer2, self).ExportReplicaSchema(ReplicaName, TransportType)
    def CompareReplicaSchema(self, relativeReplicaSchemaDoc, TransportType):
        '''Method IGeoDataServer.CompareReplicaSchema (from IGeoDataServer)

           INPUTS
            relativeReplicaSchemaDoc: IGDSData*
            TransportType       : esriGDSTransportType

           OUTPUT
            schemaChangesDoc    : IGDSData**'''
        return super(IGeoDataServer2, self).CompareReplicaSchema(relativeReplicaSchemaDoc, TransportType)
    def ImportReplicaSchemaChanges(self, schemaChangesDoc):
        '''Method IGeoDataServer.ImportReplicaSchemaChanges (from IGeoDataServer)

           INPUT
            schemaChangesDoc    : IGDSData*'''
        return super(IGeoDataServer2, self).ImportReplicaSchemaChanges(schemaChangesDoc)
    DefaultWorkingVersion = property(get_DefaultWorkingVersion, None, None)
    MaxRecordCount = property(get_MaxRecordCount, None, None)
    Replicas = property(get_Replicas, None, None)
    Versions = property(get_Versions, None, None)
    WrappedWorkspaceType = property(get_WrappedWorkspaceType, None, None)
    DataElements = IndexProperty(get_DataElements, None)
    Replica = IndexProperty(get_Replica, None)

class IReplicationAgent2(_esriGeoDatabaseDistributed.IReplicationAgent2):
    _IID = uuid.UUID('fc1d0cbb-38ee-44b7-be6e-80049e06f855')
    def CreateReplica2(self, versionName, srcGDS, destGDS, ReplicaName, desc, repOptions, layersFolder):
        '''Method IReplicationAgent2.CreateReplica2

           INPUTS
            versionName         : BSTR
            srcGDS              : IGeoDataServer*
            destGDS             : IGeoDataServer*
            ReplicaName         : BSTR
            desc                : IGPReplicaDescription*
            repOptions          : IGPReplicaOptions*
            layersFolder        : BSTR'''
        return super(IReplicationAgent2, self).CreateReplica2(versionName, srcGDS, destGDS, ReplicaName, desc, repOptions, layersFolder)
    def CreateReplica(self, versionName, srcGDS, destGDS, ReplicaName, desc, repOptions):
        '''Method IReplicationAgent.CreateReplica (from IReplicationAgent)

           INPUTS
            versionName         : BSTR
            srcGDS              : IGeoDataServer*
            destGDS             : IGeoDataServer*
            ReplicaName         : BSTR
            desc                : IGPReplicaDescription*
            repOptions          : IGPReplicaOptions*'''
        return super(IReplicationAgent2, self).CreateReplica(versionName, srcGDS, destGDS, ReplicaName, desc, repOptions)
    def SynchronizeReplica(self, gds1, gds2, rep1, rep2, pol, dir, columnLevel):
        '''Method IReplicationAgent.SynchronizeReplica (from IReplicationAgent)

           INPUTS
            gds1                : IGeoDataServer*
            gds2                : IGeoDataServer*
            rep1                : IGPReplica*
            rep2                : IGPReplica*
            pol                 : esriReplicationAgentReconcilePolicy
            dir                 : esriReplicaSynchronizeDirection
            columnLevel         : VARIANT_BOOL

           OUTPUT
            conflictsDetected   : VARIANT_BOOL*'''
        return super(IReplicationAgent2, self).SynchronizeReplica(gds1, gds2, rep1, rep2, pol, dir, columnLevel)
    def ExtractData(self, versionName, srcGDS, destGDS, desc):
        '''Method IReplicationAgent.ExtractData (from IReplicationAgent)

           INPUTS
            versionName         : BSTR
            srcGDS              : IGeoDataServer*
            destGDS             : IGeoDataServer*
            desc                : IGPReplicaDescription*'''
        return super(IReplicationAgent2, self).ExtractData(versionName, srcGDS, destGDS, desc)

class IWFSServer(_esriGeoDatabaseDistributed.IWFSServer):
    _IID = uuid.UUID('ca2b76eb-ffe1-46d7-9e13-99a7184ab450')
    def GetData(self, httpVerb, request):
        '''Method IWFSServer.GetData

           INPUTS
            httpVerb            : esriWFSHttpVerb
            request             : BSTR

           OUTPUT
            responseUrl         : BSTR*'''
        return super(IWFSServer, self).GetData(httpVerb, request)
    def SetParameter(self, Name, value):
        '''Method IWFSServer.SetParameter

           INPUTS
            Name                : BSTR
            value               : BSTR'''
        return super(IWFSServer, self).SetParameter(Name, value)

class IExportSchema(_esriGeoDatabaseDistributed.IExportSchema):
    _IID = uuid.UUID('bfd3912e-421e-477b-b324-5e66c552ac1b')
    def ExportSchema(self, exportFileName, Replica):
        '''Method IExportSchema.ExportSchema

           INPUTS
            exportFileName      : BSTR
            Replica             : IReplica*'''
        return super(IExportSchema, self).ExportSchema(exportFileName, Replica)
    def ExportSchemaDifferences(self, exportFileName, SchemaChanges):
        '''Method IExportSchema.ExportSchemaDifferences

           INPUTS
            exportFileName      : BSTR
            SchemaChanges       : ISchemaChanges*'''
        return super(IExportSchema, self).ExportSchemaDifferences(exportFileName, SchemaChanges)

class ISchemaChanges(_esriGeoDatabaseDistributed.ISchemaChanges):
    _IID = uuid.UUID('d14b724a-ac95-4cd2-9242-7235f4fb5587')
    def GetChanges(self):
        '''Method ISchemaChanges.GetChanges

           OUTPUT
            SchemaChanges       : IEnumSchemaChange**'''
        return super(ISchemaChanges, self).GetChanges()
    def get_FromReplica(self):
        '''Method ISchemaChanges.get_FromReplica

           OUTPUT
            FromReplica         : IGPReplica**'''
        return super(ISchemaChanges, self).get_FromReplica()
    def get_ToReplica(self):
        '''Method ISchemaChanges.get_ToReplica

           OUTPUT
            ToReplica           : IGPReplica**'''
        return super(ISchemaChanges, self).get_ToReplica()
    FromReplica = property(get_FromReplica, None, None)
    ToReplica = property(get_ToReplica, None, None)

class IImportSchema(_esriGeoDatabaseDistributed.IImportSchema):
    _IID = uuid.UUID('be88729b-0719-45b6-a60b-c977e4041c7b')
    def ImportSchema(self, SchemaChanges):
        '''Method IImportSchema.ImportSchema

           INPUT
            SchemaChanges       : ISchemaChanges*'''
        return super(IImportSchema, self).ImportSchema(SchemaChanges)

class IEnumSchemaChange(_esriGeoDatabaseDistributed.IEnumSchemaChange):
    _IID = uuid.UUID('52b0879b-28c4-4904-a402-91378488b867')
    def Reset(self):
        '''Method IEnumSchemaChange.Reset'''
        return super(IEnumSchemaChange, self).Reset()
    def Next(self):
        '''Method IEnumSchemaChange.Next

           OUTPUT
            SchemaChangeInfo    : ISchemaChangeInfo**'''
        return super(IEnumSchemaChange, self).Next()
    def __iter__(self):
        try:
            super(IEnumSchemaChange, self).Reset()
            val = super(IEnumSchemaChange, self).Next()
            while val:
                yield val
                val = super(IEnumSchemaChange, self).Next()
        except:
            pass
    def GetDomainChanges(self, domainName):
        '''Method IEnumSchemaChange.GetDomainChanges

           INPUT
            domainName          : BSTR

           OUTPUT
            ppInfo              : ISchemaChangeInfo**'''
        return super(IEnumSchemaChange, self).GetDomainChanges(domainName)
    def GetDatasetChanges(self, Name, dsType):
        '''Method IEnumSchemaChange.GetDatasetChanges

           INPUTS
            Name                : BSTR
            dsType              : esriDatasetType

           OUTPUT
            ppInfo              : ISchemaChangeInfo**'''
        return super(IEnumSchemaChange, self).GetDatasetChanges(Name, dsType)
    def HasChanges(self):
        '''Method IEnumSchemaChange.HasChanges

           OUTPUT
            pHasSchemaChanges   : VARIANT_BOOL*'''
        return super(IEnumSchemaChange, self).HasChanges()
    def get_ToReplica(self):
        '''Method IEnumSchemaChange.get_ToReplica

           OUTPUT
            ToReplica           : IReplica**'''
        return super(IEnumSchemaChange, self).get_ToReplica()
    ToReplica = property(get_ToReplica, None, None)

class ISchemaChangeInfo(_esriGeoDatabaseDistributed.ISchemaChangeInfo):
    _IID = uuid.UUID('b5ccf6d9-d034-4177-8827-f1493785de8f')

    def __init__(self, *args, **kw):
        super(ISchemaChangeInfo, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_SchemaChangeType(self):
        '''Method ISchemaChangeInfo.get_SchemaChangeType

           OUTPUT
            SchemaChangeType    : esriSchemaChangeType*'''
        return super(ISchemaChangeInfo, self).get_SchemaChangeType()
    def get_FromObject(self):
        '''Method ISchemaChangeInfo.get_FromObject

           OUTPUT
            ChangedObject       : IUnknown**'''
        return super(ISchemaChangeInfo, self).get_FromObject()
    def get_ToObject(self):
        '''Method ISchemaChangeInfo.get_ToObject

           OUTPUT
            TargetObject        : IUnknown**'''
        return super(ISchemaChangeInfo, self).get_ToObject()
    def get_ToParent(self):
        '''Method ISchemaChangeInfo.get_ToParent

           OUTPUT
            Parent              : IUnknown**'''
        return super(ISchemaChangeInfo, self).get_ToParent()
    def get_ApplySchemaChange(self):
        '''Method ISchemaChangeInfo.get_ApplySchemaChange

           OUTPUT
            ApplySchemaChange   : VARIANT_BOOL*'''
        return super(ISchemaChangeInfo, self).get_ApplySchemaChange()
    def put_ApplySchemaChange(self, ApplySchemaChange):
        '''Method ISchemaChangeInfo.put_ApplySchemaChange

           INPUT
            ApplySchemaChange   : VARIANT_BOOL'''
        return super(ISchemaChangeInfo, self).put_ApplySchemaChange(ApplySchemaChange)
    def GetChanges(self):
        '''Method ISchemaChangeInfo.GetChanges

           OUTPUT
            SchemaChanges       : IEnumSchemaChange**'''
        return super(ISchemaChangeInfo, self).GetChanges()
    def get_ExtendedProperties(self):
        '''Method ISchemaChangeInfo.get_ExtendedProperties

           OUTPUT
            ExtendedProperties  : IPropertySet**'''
        return super(ISchemaChangeInfo, self).get_ExtendedProperties()
    ApplySchemaChange = property(get_ApplySchemaChange, put_ApplySchemaChange, None)
    ExtendedProperties = property(get_ExtendedProperties, None, None)
    FromObject = property(get_FromObject, None, None)
    SchemaChangeType = property(get_SchemaChangeType, None, None)
    ToObject = property(get_ToObject, None, None)
    ToParent = property(get_ToParent, None, None)


# IIDs
IID_IModifiedClassInfo = IModifiedClassInfo._IID
IID_IEnumModifiedClassInfo = IEnumModifiedClassInfo._IID
IID_ISchemaChangesInit = ISchemaChangesInit._IID
IID_IXMLDocumentVersion = IXMLDocumentVersion._IID
IID_IReplicaProgress = IReplicaProgress._IID
IID_IOperationProgress = IOperationProgress._IID
IID_IDataExtraction = IDataExtraction._IID
IID_IReplicaDataChanges = IReplicaDataChanges._IID
IID_IReplicaDataChangesInit = IReplicaDataChangesInit._IID
IID_IReplicaDataChangesInit2 = IReplicaDataChangesInit2._IID
IID_IDataChanges = IDataChanges._IID
IID_IExportDataChanges = IExportDataChanges._IID
IID_IExportDataChanges2 = IExportDataChanges2._IID
IID_IVersionDataChangesInit = IVersionDataChangesInit._IID
IID_IDeltaDataChanges = IDeltaDataChanges._IID
IID_IDeltaDataChanges2 = IDeltaDataChanges2._IID
IID_IDeltaDataChangesInit = IDeltaDataChangesInit._IID
IID_IDeltaDataChangesInit2 = IDeltaDataChangesInit2._IID
IID_IDeltaDataChangesRelease = IDeltaDataChangesRelease._IID
IID_IGdbXmlExport = IGdbXmlExport._IID
IID_IGdbXmlImport = IGdbXmlImport._IID
IID_IGdbXmlExportEvents = IGdbXmlExportEvents._IID
IID_IGdbSchemaCreator = IGdbSchemaCreator._IID
IID_IDataChanges2 = IDataChanges2._IID
IID_IDataChanges3 = IDataChanges3._IID
IID_IDataChangesInfo = IDataChangesInfo._IID
IID_IDataChangesExt = IDataChangesExt._IID
IID_IImportDataChanges = IImportDataChanges._IID
IID_IImportDataChanges2 = IImportDataChanges2._IID
IID_IImportDataChanges3 = IImportDataChanges3._IID
IID_IReplicasExporter = IReplicasExporter._IID
IID_ITableDataChangesInfo = ITableDataChangesInfo._IID
IID_ITablesDataChanges = ITablesDataChanges._IID
IID_IEnumTableDataChanges = IEnumTableDataChanges._IID
IID_ICheckOut = ICheckOut._IID
IID_ICheckIn = ICheckIn._IID
IID_ICheckIn2 = ICheckIn2._IID
IID_ICheckInDataSynchronizer = ICheckInDataSynchronizer._IID
IID_ICheckInDataSynchronizer2 = ICheckInDataSynchronizer2._IID
IID_IReplicaValidation = IReplicaValidation._IID
IID_IReplicaValidation2 = IReplicaValidation2._IID
IID_IReplicaMessageHandler = IReplicaMessageHandler._IID
IID_IReplicaMessageHandler2 = IReplicaMessageHandler2._IID
IID_IGDSData = IGDSData._IID
IID_IGDSExportOptions = IGDSExportOptions._IID
IID_IGDSQueryResultPortion = IGDSQueryResultPortion._IID
IID_IGeoDataServer = IGeoDataServer._IID
IID_IGeoDataServerInit = IGeoDataServerInit._IID
IID_IGeoDataServerObjects = IGeoDataServerObjects._IID
IID_IReplicationAgent = IReplicationAgent._IID
IID_IReplicationAgentCancelControl = IReplicationAgentCancelControl._IID
IID_IGDSData2 = IGDSData2._IID
IID_IGeoDataServer2 = IGeoDataServer2._IID
IID_IReplicationAgent2 = IReplicationAgent2._IID
IID_IWFSServer = IWFSServer._IID
IID_IExportSchema = IExportSchema._IID
IID_ISchemaChanges = ISchemaChanges._IID
IID_IImportSchema = IImportSchema._IID
IID_IEnumSchemaChange = IEnumSchemaChange._IID
IID_ISchemaChangeInfo = ISchemaChangeInfo._IID
_IIDMap[IID_IModifiedClassInfo] = IModifiedClassInfo
_IIDMap[IID_IEnumModifiedClassInfo] = IEnumModifiedClassInfo
_IIDMap[IID_ISchemaChangesInit] = ISchemaChangesInit
_IIDMap[IID_IXMLDocumentVersion] = IXMLDocumentVersion
_IIDMap[IID_IReplicaProgress] = IReplicaProgress
_IIDMap[IID_IOperationProgress] = IOperationProgress
_IIDMap[IID_IDataExtraction] = IDataExtraction
_IIDMap[IID_IReplicaDataChanges] = IReplicaDataChanges
_IIDMap[IID_IReplicaDataChangesInit] = IReplicaDataChangesInit
_IIDMap[IID_IReplicaDataChangesInit2] = IReplicaDataChangesInit2
_IIDMap[IID_IDataChanges] = IDataChanges
_IIDMap[IID_IExportDataChanges] = IExportDataChanges
_IIDMap[IID_IExportDataChanges2] = IExportDataChanges2
_IIDMap[IID_IVersionDataChangesInit] = IVersionDataChangesInit
_IIDMap[IID_IDeltaDataChanges] = IDeltaDataChanges
_IIDMap[IID_IDeltaDataChanges2] = IDeltaDataChanges2
_IIDMap[IID_IDeltaDataChangesInit] = IDeltaDataChangesInit
_IIDMap[IID_IDeltaDataChangesInit2] = IDeltaDataChangesInit2
_IIDMap[IID_IDeltaDataChangesRelease] = IDeltaDataChangesRelease
_IIDMap[IID_IGdbXmlExport] = IGdbXmlExport
_IIDMap[IID_IGdbXmlImport] = IGdbXmlImport
_IIDMap[IID_IGdbXmlExportEvents] = IGdbXmlExportEvents
_IIDMap[IID_IGdbSchemaCreator] = IGdbSchemaCreator
_IIDMap[IID_IDataChanges2] = IDataChanges2
_IIDMap[IID_IDataChanges3] = IDataChanges3
_IIDMap[IID_IDataChangesInfo] = IDataChangesInfo
_IIDMap[IID_IDataChangesExt] = IDataChangesExt
_IIDMap[IID_IImportDataChanges] = IImportDataChanges
_IIDMap[IID_IImportDataChanges2] = IImportDataChanges2
_IIDMap[IID_IImportDataChanges3] = IImportDataChanges3
_IIDMap[IID_IReplicasExporter] = IReplicasExporter
_IIDMap[IID_ITableDataChangesInfo] = ITableDataChangesInfo
_IIDMap[IID_ITablesDataChanges] = ITablesDataChanges
_IIDMap[IID_IEnumTableDataChanges] = IEnumTableDataChanges
_IIDMap[IID_ICheckOut] = ICheckOut
_IIDMap[IID_ICheckIn] = ICheckIn
_IIDMap[IID_ICheckIn2] = ICheckIn2
_IIDMap[IID_ICheckInDataSynchronizer] = ICheckInDataSynchronizer
_IIDMap[IID_ICheckInDataSynchronizer2] = ICheckInDataSynchronizer2
_IIDMap[IID_IReplicaValidation] = IReplicaValidation
_IIDMap[IID_IReplicaValidation2] = IReplicaValidation2
_IIDMap[IID_IReplicaMessageHandler] = IReplicaMessageHandler
_IIDMap[IID_IReplicaMessageHandler2] = IReplicaMessageHandler2
_IIDMap[IID_IGDSData] = IGDSData
_IIDMap[IID_IGDSExportOptions] = IGDSExportOptions
_IIDMap[IID_IGDSQueryResultPortion] = IGDSQueryResultPortion
_IIDMap[IID_IGeoDataServer] = IGeoDataServer
_IIDMap[IID_IGeoDataServerInit] = IGeoDataServerInit
_IIDMap[IID_IGeoDataServerObjects] = IGeoDataServerObjects
_IIDMap[IID_IReplicationAgent] = IReplicationAgent
_IIDMap[IID_IReplicationAgentCancelControl] = IReplicationAgentCancelControl
_IIDMap[IID_IGDSData2] = IGDSData2
_IIDMap[IID_IGeoDataServer2] = IGeoDataServer2
_IIDMap[IID_IReplicationAgent2] = IReplicationAgent2
_IIDMap[IID_IWFSServer] = IWFSServer
_IIDMap[IID_IExportSchema] = IExportSchema
_IIDMap[IID_ISchemaChanges] = ISchemaChanges
_IIDMap[IID_IImportSchema] = IImportSchema
_IIDMap[IID_IEnumSchemaChange] = IEnumSchemaChange
_IIDMap[IID_ISchemaChangeInfo] = ISchemaChangeInfo


# CLSIDs
CLSID_DataChangesExporter = uuid.UUID('fe5e515a-fc19-45e8-8e2d-46ede0554e52')
CLSID_DataChangesImporter = uuid.UUID('ce014faf-2b6d-4d74-8177-00980ba739ae')
CLSID_DataExtraction = uuid.UUID('8ba238f5-aa25-423b-9c59-4ab4988e8bc6')
CLSID_DataChanges = uuid.UUID('a1cb6e77-022b-4886-a41a-7f97aa08a722')
CLSID_CheckOutDataChanges = uuid.UUID('9fe24070-7df5-4f93-a52d-eb32bcb8bf88')
CLSID_DeltaDataChanges = uuid.UUID('50ffe4dc-0e25-4d5b-9bdf-d6a2b3169ca6')
CLSID_GdbExporter = uuid.UUID('1143edd2-a736-4129-8345-e237f7bc1b19')
CLSID_GdbImporter = uuid.UUID('109ca64f-de77-46f0-9d73-720bff4111a3')
CLSID_GdbSchemaCreator = uuid.UUID('3705e682-7e35-4a8d-b4b0-02a8e768c632')
CLSID_VersionDataChanges = uuid.UUID('c20cf99c-7021-496b-a0c5-34afc905e5b8')
CLSID_TableDataChangesInfo = uuid.UUID('e7f8c959-e5d8-453d-af20-28c609ccc27d')
CLSID_TablesDataChanges = uuid.UUID('8bb5759a-ef1f-4119-8eb4-89524aca69e0')
CLSID_OperationProgress = uuid.UUID('06c8603d-2650-4888-b60b-258d09a46ca4')
CLSID_ReplicaSchemaExporter = uuid.UUID('b3c4fbd5-e496-479a-b567-5b2d3e5790ea')
CLSID_ReplicaSchemaImporter = uuid.UUID('82823fc8-f978-4e83-a84e-fff5a96ae6c5')
CLSID_SchemaChanges = uuid.UUID('ed337be8-c03c-4d0b-a29f-727565609b4e')
CLSID_SchemaChangeInfo = uuid.UUID('26c46e0a-fea6-498d-aed9-ed0a3eb53cfd')
CLSID_ReplicasExporter = uuid.UUID('6e482c9f-8bbb-4832-9576-ebde86f32ca0')
CLSID_CheckOut = uuid.UUID('de0ddadd-814d-4c8a-acfe-691e499ed8f3')
CLSID_CheckIn = uuid.UUID('db456bf9-03ac-4a72-9162-1e8fd73de22e')
CLSID_CheckInDataSynchronizer = uuid.UUID('0b998a30-b009-41c6-a086-6dc29ba71cd4')
CLSID_ReplicaValidator = uuid.UUID('fd8c8ade-6425-474e-ae33-70d3f098077a')
CLSID_ReplicaProgress = uuid.UUID('cbd8cb96-30e1-4f82-8e90-885b86aa8ec9')
CLSID_ReplicationDataChanges = uuid.UUID('0b2a0b89-dc53-43db-b14b-4df0f3f5c0de')
CLSID_ArchivingDataChanges = uuid.UUID('2638a9a0-c033-4714-a8ee-e8c9e1c2c0fd')
CLSID_ReplicaMessageHandler = uuid.UUID('bf4e20ad-2bd9-47b2-8256-364dc4548326')
CLSID_GeoDataServerConfigurationFactory = uuid.UUID('7d7ddcaa-3f9c-4290-9351-3b8ebcef9c65')
CLSID_GeoDataServer = uuid.UUID('a61f2a53-878a-4703-ab50-50fc0b8feeef')
CLSID_GDSData = uuid.UUID('8b77e69c-2a95-42e3-88e3-22a612b69752')
CLSID_GDSExportOptions = uuid.UUID('14b1aa05-52e9-4a46-8e1f-901da5a9a4f7')
CLSID_GDSQueryResultPortion = uuid.UUID('a53bea9a-142f-4aa7-82ee-f8c3f7ed9f1b')
CLSID_ReplicationAgent = uuid.UUID('f530afcd-d953-4a5c-a00d-4f6749357f00')
CLSID_GeoDataServerLP = uuid.UUID('15bcf3a2-ed45-4d22-a368-9f0123f9f8a9')
CLSID_GeoDataServerIP = uuid.UUID('74f9a30c-d127-4880-88b9-d79de091b8a6')
CLSID_GeoDataServerObjectDescription = uuid.UUID('60e1a6ae-af1b-4b41-866f-870fd2f607d9')
CLSID_WFSServer = uuid.UUID('e3743059-d297-4c6a-9a4a-30bdf5035f2d')

# Enumerations
class esriSchemaChangeType(Enumeration):
    __slots__ = ['esriSchemaChangeTypeNoChange',
                 'esriSchemaChangeTypeAny',
                 'esriSchemaChangeTypeNewFeatureDataset',
                 'esriSchemaChangeTypeUpdateFeatureDataset',
                 'esriSchemaChangeTypeDeleteFeatureDataset',
                 'esriSchemaChangeTypeNewTable',
                 'esriSchemaChangeTypeDeleteTable',
                 'esriSchemaChangeTypeUpdateTable',
                 'esriSchemaChangeTypeNewRelationshipClass',
                 'esriSchemaChangeTypeDeleteRelationshipClass',
                 'esriSchemaChangeTypeUpdateRelationshipClass',
                 'esriSchemaChangeTypeNewField',
                 'esriSchemaChangeTypeUpdateField',
                 'esriSchemaChangeTypeDeleteField',
                 'esriSchemaChangeTypeNewDomain',
                 'esriSchemaChangeTypeUpdateDomain',
                 'esriSchemaChangeTypeDeleteDomain',
                 'esriSchemaChangeTypeUpdateFields',
                 'esriSchemaChangeTypeUpdateDomains',
                 'esriSchemaChangeTypeNewGeometricNetwork',
                 'esriSchemaChangeTypeUpdateGeometricNetwork',
                 'esriSchemaChangeTypeDeleteGeometricNetwork',
                 'esriSchemaChangeTypeNewTopology',
                 'esriSchemaChangeTypeUpdateTopology',
                 'esriSchemaChangeTypeDeleteTopology']
    esriSchemaChangeTypeNoChange = 0
    esriSchemaChangeTypeAny = 1
    esriSchemaChangeTypeNewFeatureDataset = 2
    esriSchemaChangeTypeUpdateFeatureDataset = 3
    esriSchemaChangeTypeDeleteFeatureDataset = 4
    esriSchemaChangeTypeNewTable = 5
    esriSchemaChangeTypeDeleteTable = 6
    esriSchemaChangeTypeUpdateTable = 7
    esriSchemaChangeTypeNewRelationshipClass = 8
    esriSchemaChangeTypeDeleteRelationshipClass = 9
    esriSchemaChangeTypeUpdateRelationshipClass = 10
    esriSchemaChangeTypeNewField = 11
    esriSchemaChangeTypeUpdateField = 12
    esriSchemaChangeTypeDeleteField = 13
    esriSchemaChangeTypeNewDomain = 14
    esriSchemaChangeTypeUpdateDomain = 15
    esriSchemaChangeTypeDeleteDomain = 16
    esriSchemaChangeTypeUpdateFields = 17
    esriSchemaChangeTypeUpdateDomains = 18
    esriSchemaChangeTypeNewGeometricNetwork = 19
    esriSchemaChangeTypeUpdateGeometricNetwork = 20
    esriSchemaChangeTypeDeleteGeometricNetwork = 21
    esriSchemaChangeTypeNewTopology = 22
    esriSchemaChangeTypeUpdateTopology = 23
    esriSchemaChangeTypeDeleteTopology = 24

class esriDataChangeType(Enumeration):
    __slots__ = ['esriDataChangeTypeInsert',
                 'esriDataChangeTypeUpdate',
                 'esriDataChangeTypeDelete']
    esriDataChangeTypeInsert = 0
    esriDataChangeTypeUpdate = 1
    esriDataChangeTypeDelete = 2

class esriReplicaProgress(Enumeration):
    __slots__ = ['esriRPExtractSchema',
                 'esriRPExtractData',
                 'esriRPExtractSchemaAndData',
                 'esriRPFetchRelatedObjects',
                 'esriRPFetchRelatedNObjects',
                 'esriRPBuildGeometricNetworks',
                 'esriRPFetchTopologyObjects',
                 'esriRPRegisteringCheckOut',
                 'esriRPCreateCOVersions',
                 'esriRPTransferChanges',
                 'esriRPUpdateRelatedObjects',
                 'esriRPRebuildCIConnectivity',
                 'esriRPReconcileWithParent',
                 'esriRPUnregisteringCheckOut',
                 'esriRPCreatingCheckOut',
                 'esriRPSynchronizingCheckOut',
                 'esriRPSynchronizingReplica',
                 'esriRPCreatingReplica',
                 'esriRPRegisteringReplica',
                 'esriRPCreatingSchemaCheckOut',
                 'esriRPExportingToXML',
                 'esriRPSavingToXMLFile',
                 'esriRPImportingDataChanges']
    esriRPExtractSchema = 1
    esriRPExtractData = 2
    esriRPExtractSchemaAndData = 4
    esriRPFetchRelatedObjects = 8
    esriRPFetchRelatedNObjects = 16
    esriRPBuildGeometricNetworks = 32
    esriRPFetchTopologyObjects = 64
    esriRPRegisteringCheckOut = 128
    esriRPCreateCOVersions = 256
    esriRPTransferChanges = 512
    esriRPUpdateRelatedObjects = 1024
    esriRPRebuildCIConnectivity = 2048
    esriRPReconcileWithParent = 4096
    esriRPUnregisteringCheckOut = 8192
    esriRPCreatingCheckOut = 16384
    esriRPSynchronizingCheckOut = 32768
    esriRPSynchronizingReplica = 65536
    esriRPCreatingReplica = 131072
    esriRPRegisteringReplica = 262144
    esriRPCreatingSchemaCheckOut = 524288
    esriRPExportingToXML = 1048576
    esriRPSavingToXMLFile = 2097152
    esriRPImportingDataChanges = 4194304

class esriOperationProgress(Enumeration):
    __slots__ = ['esriImportXMLWorkspace',
                 'esriImportXMLWorkspaceSchema',
                 'esriExtractSchema',
                 'esriExtractData',
                 'esriBuildGeometricNetworks',
                 'esriBuildTopologies',
                 'esriExportXMLWorkspace',
                 'esriExportXMLWorkspaceSchema',
                 'esriExportXMLWorkspaceDefinition',
                 'esriExportXMLWorkspaceData',
                 'esriImportXMLWorkspaceData',
                 'esriXMLRegisterReplica']
    esriImportXMLWorkspace = 1
    esriImportXMLWorkspaceSchema = 2
    esriExtractSchema = 4
    esriExtractData = 8
    esriBuildGeometricNetworks = 16
    esriBuildTopologies = 32
    esriExportXMLWorkspace = 64
    esriExportXMLWorkspaceSchema = 128
    esriExportXMLWorkspaceDefinition = 256
    esriExportXMLWorkspaceData = 512
    esriImportXMLWorkspaceData = 1024
    esriXMLRegisterReplica = 2048

class esriReplicaMessageType(Enumeration):
    __slots__ = ['esriReplicaMessageTypeDC',
                 'esriReplicaMessageTypeAck',
                 'esriReplicaMessageTypeDCWFD']
    esriReplicaMessageTypeDC = 1
    esriReplicaMessageTypeAck = 2
    esriReplicaMessageTypeDCWFD = 3

class esriExportGenerationsOption(Enumeration):
    __slots__ = ['esriExportGenerationsUnAcknowledged',
                 'esriExportGenerationsNew',
                 'esriExportGenerationsAll',
                 'esriExportGenerationsNone']
    esriExportGenerationsUnAcknowledged = 1
    esriExportGenerationsNew = 2
    esriExportGenerationsAll = 3
    esriExportGenerationsNone = 4

class esriReExportGenerationsOption(Enumeration):
    __slots__ = ['esriReExportGenerationsAllUnAcknowledged',
                 'esriReExportGenerationsLastUnAcknowledged']
    esriReExportGenerationsAllUnAcknowledged = 1
    esriReExportGenerationsLastUnAcknowledged = 2

class esriExportDataChangesOption(Enumeration):
    __slots__ = ['esriExportToAccess',
                 'esriExportToXML',
                 'esriExportToFileGDB',
                 'esriExportToSqliteGDB']
    esriExportToAccess = 1
    esriExportToXML = 2
    esriExportToFileGDB = 3
    esriExportToSqliteGDB = 4

class esriCheckInSourceType(Enumeration):
    __slots__ = ['esriPersonalDeltaFile',
                 'esriXMLDeltaFile',
                 'esriCheckOutGDB',
                 'esriFileGDBDelta']
    esriPersonalDeltaFile = 1
    esriXMLDeltaFile = 2
    esriCheckOutGDB = 3
    esriFileGDBDelta = 4

class esriDisconnectedEditingError(Enumeration):
    __slots__ = ['S_DE_OK',
                 'E_CHECK_OUT_NON_VERSIONED_DATA',
                 'E_CHECK_IN_INVALID_GEODATABASE',
                 'E_GEODATABASE_HAS_CHECK_OUT',
                 'E_INVALID_REPLICA_DESCRIPTION',
                 'E_CHECK_OUT_NOT_SUPPORTED_IN_RELEASE',
                 'E_CHECK_IN_NOT_SUPPORTED_IN_RELEASE',
                 'E_CAN_NOT_REUSE_SCHEMA_OF_VERSIONED_DATA',
                 'E_CHECK_OUT_INVALID_DATA',
                 'E_CAN_NOT_REUSE_SCHEMA_WITH_OUTPUT_SPATIAL_REFERENCE',
                 'E_CHECK_OUT_UNREGISTER_FAILED',
                 'E_CHECK_OUT_INVALID_SOURCE_WORKSPACE',
                 'E_SYNCHRONIZE_INVALID_RELEASES',
                 'E_UPDATEGRAM_TOPOLOGY_DEFINITION_ACCESSING']
    S_DE_OK = 0
    E_CHECK_OUT_NON_VERSIONED_DATA = -2147219455
    E_CHECK_IN_INVALID_GEODATABASE = -2147219454
    E_GEODATABASE_HAS_CHECK_OUT = -2147219453
    E_INVALID_REPLICA_DESCRIPTION = -2147219452
    E_CHECK_OUT_NOT_SUPPORTED_IN_RELEASE = -2147219451
    E_CHECK_IN_NOT_SUPPORTED_IN_RELEASE = -2147219450
    E_CAN_NOT_REUSE_SCHEMA_OF_VERSIONED_DATA = -2147219449
    E_CHECK_OUT_INVALID_DATA = -2147219448
    E_CAN_NOT_REUSE_SCHEMA_WITH_OUTPUT_SPATIAL_REFERENCE = -2147219447
    E_CHECK_OUT_UNREGISTER_FAILED = -2147219446
    E_CHECK_OUT_INVALID_SOURCE_WORKSPACE = -2147219445
    E_SYNCHRONIZE_INVALID_RELEASES = -2147219444
    E_UPDATEGRAM_TOPOLOGY_DEFINITION_ACCESSING = -2147219443

class esriGDSExportFormat(Enumeration):
    __slots__ = ['esriGDSExportFormatPersonalGdb',
                 'esriGDSExportFormatXml',
                 'esriGDSExportFormatFileGDB',
                 'esriGDSExportFormatFileGDBTransport',
                 'esriGDSExportFormatSqliteGDB']
    esriGDSExportFormatPersonalGdb = 0
    esriGDSExportFormatXml = 1
    esriGDSExportFormatFileGDB = 2
    esriGDSExportFormatFileGDBTransport = 3
    esriGDSExportFormatSqliteGDB = 4

class esriReplicaSynchronizeDirection(Enumeration):
    __slots__ = ['esriReplicaSynchronizeFromReplica1ToReplica2',
                 'esriReplicaSynchronizeFromReplica2ToReplica1',
                 'esriReplicaSynchronizeBoth']
    esriReplicaSynchronizeFromReplica1ToReplica2 = 1
    esriReplicaSynchronizeFromReplica2ToReplica1 = 2
    esriReplicaSynchronizeBoth = 3

class esriGDSTransportType(Enumeration):
    __slots__ = ['esriGDSTransportTypeEmbedded',
                 'esriGDSTransportTypeUrl',
                 'esriGDSTransportTypeUpload']
    esriGDSTransportTypeEmbedded = 0
    esriGDSTransportTypeUrl = 1
    esriGDSTransportTypeUpload = 2

class esriGDSImportFormat(Enumeration):
    __slots__ = ['esriGDSImportFormatXmlWorkspace',
                 'esriGDSImportFormatFileGDB',
                 'esriGDSImportFormatPersonalGdb']
    esriGDSImportFormatXmlWorkspace = 0
    esriGDSImportFormatFileGDB = 1
    esriGDSImportFormatPersonalGdb = 2

class esriGDSReplicaImportSource(Enumeration):
    __slots__ = ['esriGDSReplicaImportSourceDeltaXmlFile',
                 'esriGDSReplicaImportSourceDeltaPersonalGDB',
                 'esriGDSReplicaImportSourceDeltaFileGDB',
                 'esriGDSReplicaImportSourceDeltaSqliteGDB']
    esriGDSReplicaImportSourceDeltaXmlFile = 0
    esriGDSReplicaImportSourceDeltaPersonalGDB = 1
    esriGDSReplicaImportSourceDeltaFileGDB = 2
    esriGDSReplicaImportSourceDeltaSqliteGDB = 3

class esriReplicationAgentReconcilePolicy(Enumeration):
    __slots__ = ['esriRADetectConflicts',
                 'esriRAResolveConflictsInFavorOfReplica1',
                 'esriRAResolveConflictsInFavorOfReplica2',
                 'esriRAResolveConflictsNone']
    esriRADetectConflicts = 0
    esriRAResolveConflictsInFavorOfReplica1 = 1
    esriRAResolveConflictsInFavorOfReplica2 = 2
    esriRAResolveConflictsNone = 3

class esriGeoDataServerMessageCodeEnum(Enumeration):
    __slots__ = ['esriGeoDataServerMessageCode_NotLicensed',
                 'esriGeoDataServerMessageCode_ConstructStart',
                 'esriGeoDataServerMessageCode_ConstructFinish',
                 'esriGeoDataServerMessageCode_ErrorInvalidConfiguration',
                 'esriGeoDataServerMessageCode_ErrorUnableToInitFromGdb',
                 'esriGeoDataServerMessageCode_ConnectedToWS',
                 'esriGeoDataServerMessageCode_RequestNotSupported',
                 'esriGeoDataServerMessageCode_CapabilityNotSupported',
                 'esriGeoDataServerMessageCode_InitFromMapStarts',
                 'esriGeoDataServerMessageCode_InitFromMapEnded',
                 'esriGeoDataServerMessageCode_ErrorInvalidOutputDir',
                 'esriGeoDataServerMessageCode_ErrorInvalidVirtualDir',
                 'esriGeoDataServerMessageCode_ErrorMessage',
                 'esriGeoDataServerMessageCode_WarningMessage',
                 'esriGeoDataServerMessageCode_InfoMessage',
                 'esriGeoDataServerMessageCode_DebugMessage']
    esriGeoDataServerMessageCode_NotLicensed = 90000
    esriGeoDataServerMessageCode_ConstructStart = 90001
    esriGeoDataServerMessageCode_ConstructFinish = 90002
    esriGeoDataServerMessageCode_ErrorInvalidConfiguration = 90003
    esriGeoDataServerMessageCode_ErrorUnableToInitFromGdb = 90004
    esriGeoDataServerMessageCode_ConnectedToWS = 90005
    esriGeoDataServerMessageCode_RequestNotSupported = 90006
    esriGeoDataServerMessageCode_CapabilityNotSupported = 90007
    esriGeoDataServerMessageCode_InitFromMapStarts = 90008
    esriGeoDataServerMessageCode_InitFromMapEnded = 90009
    esriGeoDataServerMessageCode_ErrorInvalidOutputDir = 90010
    esriGeoDataServerMessageCode_ErrorInvalidVirtualDir = 90011
    esriGeoDataServerMessageCode_ErrorMessage = 90012
    esriGeoDataServerMessageCode_WarningMessage = 90013
    esriGeoDataServerMessageCode_InfoMessage = 90014
    esriGeoDataServerMessageCode_DebugMessage = 90015

class esriGeoDataServerErrors(Enumeration):
    __slots__ = ['GDS_E_IMPORTXMLWS_CONFLICTS_FOUND',
                 'GDS_E_CANTEXPORT_TO_NONCOMPRESSED_FILEGDB',
                 'GDS_E_REQUESTEDCOUNT_TOO_LARGE',
                 'GDS_E_INVALID_FORMAT_FOR_CREATEREPLICA',
                 'GDS_E_MISSING_PARAMETER',
                 'GDS_E_CANTIMPORT_ACKMSG_AS_DATACHANGESMSG',
                 'GDS_E_INVALID_COUNT_REQUESTED',
                 'GDS_E_INVALID_START_INDEX',
                 'GDS_E_NULL_QUERYID',
                 'GDS_E_INVALID_RECONCILE_POLICY_FOR_DIRECTION',
                 'GDS_E_REPLICAS_DONT_MATCH',
                 'GDS_E_SYNCH_DIRECTION_BOTH_INVALID_FOR_CHECKOUTS',
                 'GDS_E_IMPORTDATAWS_CONFLICTS_FOUND']
    GDS_E_IMPORTXMLWS_CONFLICTS_FOUND = -2147208551
    GDS_E_CANTEXPORT_TO_NONCOMPRESSED_FILEGDB = -2147208550
    GDS_E_REQUESTEDCOUNT_TOO_LARGE = -2147208549
    GDS_E_INVALID_FORMAT_FOR_CREATEREPLICA = -2147208548
    GDS_E_MISSING_PARAMETER = -2147208547
    GDS_E_CANTIMPORT_ACKMSG_AS_DATACHANGESMSG = -2147208546
    GDS_E_INVALID_COUNT_REQUESTED = -2147208545
    GDS_E_INVALID_START_INDEX = -2147208544
    GDS_E_NULL_QUERYID = -2147208543
    GDS_E_INVALID_RECONCILE_POLICY_FOR_DIRECTION = -2147208542
    GDS_E_REPLICAS_DONT_MATCH = -2147208541
    GDS_E_SYNCH_DIRECTION_BOTH_INVALID_FOR_CHECKOUTS = -2147208540
    GDS_E_IMPORTDATAWS_CONFLICTS_FOUND = -2147208539

class esriWFSHttpVerb(Enumeration):
    __slots__ = ['esriWFSGet',
                 'esriWFSPost']
    esriWFSGet = 0
    esriWFSPost = 1

class esriWFSServerMessageCodeEnum(Enumeration):
    __slots__ = ['esriWFSServerMessageCode_SkippedDataset',
                 'esriWFSServerMessageCode_FailedToGenerateTransactionResponse',
                 'esriWFSServerMessageCode_FailedToDeleteLock',
                 'esriWFSServerMessageCode_FailedToDeleteOutstandingTransactionVersions',
                 'esriWFSServerMessageCode_NotLicensed',
                 'esriWFSServerMessageCode_GetRequest',
                 'esriWFSServerMessageCode_PostRequest',
                 'esriWFSServerMessageCode_WFSExceptionReport',
                 'esriWFSServerMessageCode_Debug',
                 'esriWFSServerMessageCode_FailedToReleaseLocks',
                 'esriWFSServerMessageCode_ConstructStart',
                 'esriWFSServerMessageCode_ErrorInvalidAppSchemaNamespace',
                 'esriWFSServerMessageCode_ErrorInvalidAppSchemaPrefix',
                 'esriWFSServerMessageCode_ErrorInvalidDefaultLockExpiration',
                 'esriWFSServerMessageCode_ErrorPublishedWorkspaceIsntVersioned',
                 'esriWFSServerMessageCode_ConstructEnded',
                 'esriWFSServerMessageCode_ErrorInvalid10AxisOrder',
                 'esriWFSServerMessageCode_ErrorInvalid11AxisOrder',
                 'esriWFSServerMessageCode_ErrorInvalidUseSRSNameFormat',
                 'esriWFSServerMessageCode_FailedToReconcileAgainstSelf',
                 'esriWFSServerMessageCode_FailedToStopEditing',
                 'esriWFSServerMessageCode_ServerTooBusyToProcessTransaction',
                 'esriWFSServerMessageCode_FailedToImportTransactionChanges',
                 'esriWFSServerMessageCode_FailedCreatingTransactionResponse',
                 'esriWFSServerMessageCode_TransactionFailedStoppingEditOperation',
                 'esriWFSServerMessageCode_FailedToStartEditing',
                 'esriWFSServerMessageCode_ConflictDetected']
    esriWFSServerMessageCode_SkippedDataset = 92000
    esriWFSServerMessageCode_FailedToGenerateTransactionResponse = 92001
    esriWFSServerMessageCode_FailedToDeleteLock = 92002
    esriWFSServerMessageCode_FailedToDeleteOutstandingTransactionVersions = 92003
    esriWFSServerMessageCode_NotLicensed = 92004
    esriWFSServerMessageCode_GetRequest = 92005
    esriWFSServerMessageCode_PostRequest = 92006
    esriWFSServerMessageCode_WFSExceptionReport = 92007
    esriWFSServerMessageCode_Debug = 92008
    esriWFSServerMessageCode_FailedToReleaseLocks = 92009
    esriWFSServerMessageCode_ConstructStart = 92010
    esriWFSServerMessageCode_ErrorInvalidAppSchemaNamespace = 92011
    esriWFSServerMessageCode_ErrorInvalidAppSchemaPrefix = 92012
    esriWFSServerMessageCode_ErrorInvalidDefaultLockExpiration = 92013
    esriWFSServerMessageCode_ErrorPublishedWorkspaceIsntVersioned = 92014
    esriWFSServerMessageCode_ConstructEnded = 92015
    esriWFSServerMessageCode_ErrorInvalid10AxisOrder = 92016
    esriWFSServerMessageCode_ErrorInvalid11AxisOrder = 92017
    esriWFSServerMessageCode_ErrorInvalidUseSRSNameFormat = 92018
    esriWFSServerMessageCode_FailedToReconcileAgainstSelf = 92019
    esriWFSServerMessageCode_FailedToStopEditing = 92020
    esriWFSServerMessageCode_ServerTooBusyToProcessTransaction = 92021
    esriWFSServerMessageCode_FailedToImportTransactionChanges = 92022
    esriWFSServerMessageCode_FailedCreatingTransactionResponse = 92023
    esriWFSServerMessageCode_TransactionFailedStoppingEditOperation = 92024
    esriWFSServerMessageCode_FailedToStartEditing = 92025
    esriWFSServerMessageCode_ConflictDetected = 92026

