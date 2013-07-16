'Type library'
__all__ = ['IArcInfoItem', 'IArcInfoItemEdit', 'IArcInfoItems', 'IArcInfoItemsEdit', 'IArcInfoTable', 'IArcInfoTable2', 'ICoverageFeatureClass', 'ICoverageFeatureClass2', 'ICoverage', 'ICoverage2', 'IArcInfoWorkspace', 'IInfoTableOnlyWorkspaceEdit', 'ICoverageFeatureClassName', 'ICoverageName', 'IArcInfoWorkspaceUtil', 'ICadSettings', 'ICadDrawingLayers', 'ICadTransformations', 'ICadDrawingDataset', 'ICadDrawingWorkspace', 'ISdcExporter', 'ISMRouterPoint', 'ISMRouterEnvelope', 'ISMPointsCollection', 'ISMNetAttribute', 'ISMNetAttribute2', 'ISMNetAttributesCollection', 'ISMNetBarrier', 'ISMNetBarriersCollection', 'ISMRoadPreferences', 'ISMSpeedGroup', 'ISMSpeedGroup2', 'ISMSpeedGroups', 'ISMTripPlanSettings', 'ISMFlag', 'ISMFlagCreator', 'ISMFlagCreator2', 'ISMStop', 'ISMStopsCollection', 'ISMDirItem', 'ISMDirections', 'ISMBreakTracker', 'ISMNetAttributesAccess', 'ISMRouter', 'ISMRouterFactory', 'ISMRoutingMetaData', 'ISMRestriction', 'ISMRouterSetup', 'ISMRouterSetup2', 'IUsageModeOption', 'IUsageModeInfo', 'IMetaInfo', 'IDataLicenseInfo', 'IDataLicenseManager', 'IDECadDrawingDataset', 'IGPLayer', 'IDELayer', 'IDEPrjFile', 'IDETin', 'IDELasDataset', 'IDECoverage', 'IDECoverageFeatureClass', 'IDEArcInfoTable', 'IGPArcInfoItem', 'IDEArcInfoUtilities', 'ArcInfoWorkspaceFactory', 'ArcInfoItems', 'ArcInfoItem', 'CoverageFeatureClassName', 'CoverageName', 'PCCoverageWorkspaceFactory', 'StreetMapWorkspaceFactory', 'SDCWorkspaceFactory', 'SDCNetworkSource', 'SDCNetworkAttribute', 'ShapefileWorkspaceFactory', 'VpfWorkspaceFactory', 'TinWorkspaceFactory', 'GeoRSSWorkspaceFactory', 'CadWorkspaceFactory', 'CadDrawingName', 'SdcExporter', 'SMRouterPoint', 'SMRouterEnvelope', 'SMPointsCollection', 'SMNetAttribute', 'SMNetAttributesCollection', 'SMNetBarrier', 'SMNetBarriersCollection', 'SMRoadPreferences', 'SMSpeedGroup', 'SMSpeedGroups', 'SMTripPlanSettings', 'SMFlag', 'SMStop', 'SMStopsCollection', 'SMDirItem', 'SMDirections', 'SMRouter', 'SMRouterFactory', 'SMNetAttributesAccess', 'SMFlagCreator', 'SMRestriction', 'LicensedDataExtension', 'DECadDrawingDatasetType', 'DECadDrawingDataset', 'DELayerType', 'DEShapeFileType', 'DEDbaseTableType', 'DELayer', 'DEShapeFile', 'DEDbaseTable', 'DECatalogRootType', 'DEDiskConnectionType', 'DEFolderType', 'DEFileType', 'DEPrjFileType', 'DEMapDocumentType', 'DERemoteDatabaseFolderType', 'DESpatialReferencesFolderType', 'DECatalogRoot', 'DEDiskConnection', 'DEFolder', 'DEFile', 'DEMapDocument', 'DERemoteDatabaseFolder', 'DESpatialReferencesFolder', 'DEPrjFile', 'DETextFile', 'DETextFileType', 'DETinType', 'DETin', 'DELasDatasetType', 'DELasDataset', 'DECoverageType', 'DECoverageFeatureClassType', 'DEArcInfoTableType', 'GPArcInfoItemType', 'DECoverage', 'DECoverageFeatureClass', 'DEArcInfoTable', 'GPArcInfoItem', 'DEArcInfoUtilities', 'DEVPFTableType', 'DEVPFTable', 'DEVPFCoverageType', 'DEVPFCoverage', 'IID_IArcInfoItem', 'IID_IArcInfoItemEdit', 'IID_IArcInfoItems', 'IID_IArcInfoItemsEdit', 'IID_IArcInfoTable', 'IID_IArcInfoTable2', 'IID_ICoverageFeatureClass', 'IID_ICoverageFeatureClass2', 'IID_ICoverage', 'IID_ICoverage2', 'IID_IArcInfoWorkspace', 'IID_IInfoTableOnlyWorkspaceEdit', 'IID_ICoverageFeatureClassName', 'IID_ICoverageName', 'IID_IArcInfoWorkspaceUtil', 'IID_ICadSettings', 'IID_ICadDrawingLayers', 'IID_ICadTransformations', 'IID_ICadDrawingDataset', 'IID_ICadDrawingWorkspace', 'IID_ISdcExporter', 'IID_ISMRouterPoint', 'IID_ISMRouterEnvelope', 'IID_ISMPointsCollection', 'IID_ISMNetAttribute', 'IID_ISMNetAttribute2', 'IID_ISMNetAttributesCollection', 'IID_ISMNetBarrier', 'IID_ISMNetBarriersCollection', 'IID_ISMRoadPreferences', 'IID_ISMSpeedGroup', 'IID_ISMSpeedGroup2', 'IID_ISMSpeedGroups', 'IID_ISMTripPlanSettings', 'IID_ISMFlag', 'IID_ISMFlagCreator', 'IID_ISMFlagCreator2', 'IID_ISMStop', 'IID_ISMStopsCollection', 'IID_ISMDirItem', 'IID_ISMDirections', 'IID_ISMBreakTracker', 'IID_ISMNetAttributesAccess', 'IID_ISMRouter', 'IID_ISMRouterFactory', 'IID_ISMRoutingMetaData', 'IID_ISMRestriction', 'IID_ISMRouterSetup', 'IID_ISMRouterSetup2', 'IID_IUsageModeOption', 'IID_IUsageModeInfo', 'IID_IMetaInfo', 'IID_IDataLicenseInfo', 'IID_IDataLicenseManager', 'IID_IDECadDrawingDataset', 'IID_IGPLayer', 'IID_IDELayer', 'IID_IDEPrjFile', 'IID_IDETin', 'IID_IDELasDataset', 'IID_IDECoverage', 'IID_IDECoverageFeatureClass', 'IID_IDEArcInfoTable', 'IID_IGPArcInfoItem', 'IID_IDEArcInfoUtilities', 'CLSID_ArcInfoWorkspaceFactory', 'CLSID_ArcInfoItems', 'CLSID_ArcInfoItem', 'CLSID_CoverageFeatureClassName', 'CLSID_CoverageName', 'CLSID_PCCoverageWorkspaceFactory', 'CLSID_StreetMapWorkspaceFactory', 'CLSID_SDCWorkspaceFactory', 'CLSID_SDCNetworkSource', 'CLSID_SDCNetworkAttribute', 'CLSID_ShapefileWorkspaceFactory', 'CLSID_VpfWorkspaceFactory', 'CLSID_TinWorkspaceFactory', 'CLSID_GeoRSSWorkspaceFactory', 'CLSID_CadWorkspaceFactory', 'CLSID_CadDrawingName', 'CLSID_SdcExporter', 'CLSID_SMRouterPoint', 'CLSID_SMRouterEnvelope', 'CLSID_SMPointsCollection', 'CLSID_SMNetAttribute', 'CLSID_SMNetAttributesCollection', 'CLSID_SMNetBarrier', 'CLSID_SMNetBarriersCollection', 'CLSID_SMRoadPreferences', 'CLSID_SMSpeedGroup', 'CLSID_SMSpeedGroups', 'CLSID_SMTripPlanSettings', 'CLSID_SMFlag', 'CLSID_SMStop', 'CLSID_SMStopsCollection', 'CLSID_SMDirItem', 'CLSID_SMDirections', 'CLSID_SMRouter', 'CLSID_SMRouterFactory', 'CLSID_SMNetAttributesAccess', 'CLSID_SMFlagCreator', 'CLSID_SMRestriction', 'CLSID_LicensedDataExtension', 'CLSID_DECadDrawingDatasetType', 'CLSID_DECadDrawingDataset', 'CLSID_DELayerType', 'CLSID_DEShapeFileType', 'CLSID_DEDbaseTableType', 'CLSID_DELayer', 'CLSID_DEShapeFile', 'CLSID_DEDbaseTable', 'CLSID_DECatalogRootType', 'CLSID_DEDiskConnectionType', 'CLSID_DEFolderType', 'CLSID_DEFileType', 'CLSID_DEPrjFileType', 'CLSID_DEMapDocumentType', 'CLSID_DERemoteDatabaseFolderType', 'CLSID_DESpatialReferencesFolderType', 'CLSID_DECatalogRoot', 'CLSID_DEDiskConnection', 'CLSID_DEFolder', 'CLSID_DEFile', 'CLSID_DEMapDocument', 'CLSID_DERemoteDatabaseFolder', 'CLSID_DESpatialReferencesFolder', 'CLSID_DEPrjFile', 'CLSID_DETextFile', 'CLSID_DETextFileType', 'CLSID_DETinType', 'CLSID_DETin', 'CLSID_DELasDatasetType', 'CLSID_DELasDataset', 'CLSID_DECoverageType', 'CLSID_DECoverageFeatureClassType', 'CLSID_DEArcInfoTableType', 'CLSID_GPArcInfoItemType', 'CLSID_DECoverage', 'CLSID_DECoverageFeatureClass', 'CLSID_DEArcInfoTable', 'CLSID_GPArcInfoItem', 'CLSID_DEArcInfoUtilities', 'CLSID_DEVPFTableType', 'CLSID_DEVPFTable', 'CLSID_DEVPFCoverageType', 'CLSID_DEVPFCoverage', 'esriCoverageToleranceType', 'esriArcInfoItemType', 'esriCoverageType', 'esriCoverageFeatureClassType', 'esriFeatureClassTopology', 'esriCoveragePrecisionType', 'esriCadTransform', 'esriSMNetAttributeType', 'esriSMNetAttributeUsageType', 'esriSMRoadType', 'esriSMStreetSideType', 'esriSMDirItemType', 'esriSMAzimuthType', 'esriSMRestrictionType', 'esriSMBacktrackPolicy', 'esriSMDirectionsLengthUnits', 'esriDataLicenseType']
from cartocomutils import _esriDataSourcesFile
from cartocomutils._esriDataSourcesFile import ArcInfoWorkspaceFactory, ArcInfoItems, ArcInfoItem, CoverageFeatureClassName, CoverageName, PCCoverageWorkspaceFactory, StreetMapWorkspaceFactory, SDCWorkspaceFactory, SDCNetworkSource, SDCNetworkAttribute, ShapefileWorkspaceFactory, VpfWorkspaceFactory, TinWorkspaceFactory, GeoRSSWorkspaceFactory, CadWorkspaceFactory, CadDrawingName, SdcExporter, SMRouterPoint, SMRouterEnvelope, SMPointsCollection, SMNetAttribute, SMNetAttributesCollection, SMNetBarrier, SMNetBarriersCollection, SMRoadPreferences, SMSpeedGroup, SMSpeedGroups, SMTripPlanSettings, SMFlag, SMStop, SMStopsCollection, SMDirItem, SMDirections, SMRouter, SMRouterFactory, SMNetAttributesAccess, SMFlagCreator, SMRestriction, LicensedDataExtension, DECadDrawingDatasetType, DECadDrawingDataset, DELayerType, DEShapeFileType, DEDbaseTableType, DELayer, DEShapeFile, DEDbaseTable, DECatalogRootType, DEDiskConnectionType, DEFolderType, DEFileType, DEPrjFileType, DEMapDocumentType, DERemoteDatabaseFolderType, DESpatialReferencesFolderType, DECatalogRoot, DEDiskConnection, DEFolder, DEFile, DEMapDocument, DERemoteDatabaseFolder, DESpatialReferencesFolder, DEPrjFile, DETextFile, DETextFileType, DETinType, DETin, DELasDatasetType, DELasDataset, DECoverageType, DECoverageFeatureClassType, DEArcInfoTableType, GPArcInfoItemType, DECoverage, DECoverageFeatureClass, DEArcInfoTable, GPArcInfoItem, DEArcInfoUtilities, DEVPFTableType, DEVPFTable, DEVPFCoverageType, DEVPFCoverage
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IArcInfoItem(_esriDataSourcesFile.IArcInfoItem):
    _IID = uuid.UUID('b5e470d2-ceab-11d2-b0dc-0000f8780820')
    def get_StartPosition(self):
        '''Method IArcInfoItem.get_StartPosition

           OUTPUT
            StartPosition       : long*'''
        return super(IArcInfoItem, self).get_StartPosition()
    def get_Name(self):
        '''Method IArcInfoItem.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IArcInfoItem, self).get_Name()
    def get_Width(self):
        '''Method IArcInfoItem.get_Width

           OUTPUT
            Width               : long*'''
        return super(IArcInfoItem, self).get_Width()
    def get_OutputWidth(self):
        '''Method IArcInfoItem.get_OutputWidth

           OUTPUT
            OutputWidth         : long*'''
        return super(IArcInfoItem, self).get_OutputWidth()
    def get_Type(self):
        '''Method IArcInfoItem.get_Type

           OUTPUT
            Type                : esriArcInfoItemType*'''
        return super(IArcInfoItem, self).get_Type()
    def get_NumberDecimals(self):
        '''Method IArcInfoItem.get_NumberDecimals

           OUTPUT
            NumberDecimals      : long*'''
        return super(IArcInfoItem, self).get_NumberDecimals()
    def get_AlternateName(self):
        '''Method IArcInfoItem.get_AlternateName

           OUTPUT
            AlternateName       : BSTR*'''
        return super(IArcInfoItem, self).get_AlternateName()
    def get_IsRedefined(self):
        '''Method IArcInfoItem.get_IsRedefined

           OUTPUT
            IsRedefined         : VARIANT_BOOL*'''
        return super(IArcInfoItem, self).get_IsRedefined()
    def get_IsPseudo(self):
        '''Method IArcInfoItem.get_IsPseudo

           OUTPUT
            IsPseudo            : VARIANT_BOOL*'''
        return super(IArcInfoItem, self).get_IsPseudo()
    def get_IsIndexed(self):
        '''Method IArcInfoItem.get_IsIndexed

           OUTPUT
            IsIndexed           : VARIANT_BOOL*'''
        return super(IArcInfoItem, self).get_IsIndexed()
    AlternateName = property(get_AlternateName, None, None)
    IsIndexed = property(get_IsIndexed, None, None)
    IsPseudo = property(get_IsPseudo, None, None)
    IsRedefined = property(get_IsRedefined, None, None)
    Name = property(get_Name, None, None)
    NumberDecimals = property(get_NumberDecimals, None, None)
    OutputWidth = property(get_OutputWidth, None, None)
    StartPosition = property(get_StartPosition, None, None)
    Type = property(get_Type, None, None)
    Width = property(get_Width, None, None)

class IArcInfoItemEdit(_esriDataSourcesFile.IArcInfoItemEdit):
    _IID = uuid.UUID('b5e470d3-ceab-11d2-b0dc-0000f8780820')

    def __init__(self, *args, **kw):
        super(IArcInfoItemEdit, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_StartPosition(self, _arg1):
        '''Method IArcInfoItemEdit.put_StartPosition

           INPUT
            _arg1               : long'''
        return super(IArcInfoItemEdit, self).put_StartPosition(_arg1)
    def put_Name(self, _arg1):
        '''Method IArcInfoItemEdit.put_Name

           INPUT
            _arg1               : BSTR'''
        return super(IArcInfoItemEdit, self).put_Name(_arg1)
    def put_Width(self, _arg1):
        '''Method IArcInfoItemEdit.put_Width

           INPUT
            _arg1               : long'''
        return super(IArcInfoItemEdit, self).put_Width(_arg1)
    def put_OutputWidth(self, _arg1):
        '''Method IArcInfoItemEdit.put_OutputWidth

           INPUT
            _arg1               : long'''
        return super(IArcInfoItemEdit, self).put_OutputWidth(_arg1)
    def put_Type(self, _arg1):
        '''Method IArcInfoItemEdit.put_Type

           INPUT
            _arg1               : esriArcInfoItemType'''
        return super(IArcInfoItemEdit, self).put_Type(_arg1)
    def put_NumberDecimals(self, _arg1):
        '''Method IArcInfoItemEdit.put_NumberDecimals

           INPUT
            _arg1               : long'''
        return super(IArcInfoItemEdit, self).put_NumberDecimals(_arg1)
    def put_AlternateName(self, _arg1):
        '''Method IArcInfoItemEdit.put_AlternateName

           INPUT
            _arg1               : BSTR'''
        return super(IArcInfoItemEdit, self).put_AlternateName(_arg1)
    def put_IsRedefined(self, _arg1):
        '''Method IArcInfoItemEdit.put_IsRedefined

           INPUT
            _arg1               : VARIANT_BOOL'''
        return super(IArcInfoItemEdit, self).put_IsRedefined(_arg1)
    def put_IsPseudo(self, _arg1):
        '''Method IArcInfoItemEdit.put_IsPseudo

           INPUT
            _arg1               : VARIANT_BOOL'''
        return super(IArcInfoItemEdit, self).put_IsPseudo(_arg1)
    def put_IsIndexed(self, _arg1):
        '''Method IArcInfoItemEdit.put_IsIndexed

           INPUT
            _arg1               : VARIANT_BOOL'''
        return super(IArcInfoItemEdit, self).put_IsIndexed(_arg1)
    def get_StartPosition(self):
        '''Method IArcInfoItem.get_StartPosition (from IArcInfoItem)

           OUTPUT
            StartPosition       : long*'''
        return super(IArcInfoItemEdit, self).get_StartPosition()
    def get_Name(self):
        '''Method IArcInfoItem.get_Name (from IArcInfoItem)

           OUTPUT
            Name                : BSTR*'''
        return super(IArcInfoItemEdit, self).get_Name()
    def get_Width(self):
        '''Method IArcInfoItem.get_Width (from IArcInfoItem)

           OUTPUT
            Width               : long*'''
        return super(IArcInfoItemEdit, self).get_Width()
    def get_OutputWidth(self):
        '''Method IArcInfoItem.get_OutputWidth (from IArcInfoItem)

           OUTPUT
            OutputWidth         : long*'''
        return super(IArcInfoItemEdit, self).get_OutputWidth()
    def get_Type(self):
        '''Method IArcInfoItem.get_Type (from IArcInfoItem)

           OUTPUT
            Type                : esriArcInfoItemType*'''
        return super(IArcInfoItemEdit, self).get_Type()
    def get_NumberDecimals(self):
        '''Method IArcInfoItem.get_NumberDecimals (from IArcInfoItem)

           OUTPUT
            NumberDecimals      : long*'''
        return super(IArcInfoItemEdit, self).get_NumberDecimals()
    def get_AlternateName(self):
        '''Method IArcInfoItem.get_AlternateName (from IArcInfoItem)

           OUTPUT
            AlternateName       : BSTR*'''
        return super(IArcInfoItemEdit, self).get_AlternateName()
    def get_IsRedefined(self):
        '''Method IArcInfoItem.get_IsRedefined (from IArcInfoItem)

           OUTPUT
            IsRedefined         : VARIANT_BOOL*'''
        return super(IArcInfoItemEdit, self).get_IsRedefined()
    def get_IsPseudo(self):
        '''Method IArcInfoItem.get_IsPseudo (from IArcInfoItem)

           OUTPUT
            IsPseudo            : VARIANT_BOOL*'''
        return super(IArcInfoItemEdit, self).get_IsPseudo()
    def get_IsIndexed(self):
        '''Method IArcInfoItem.get_IsIndexed (from IArcInfoItem)

           OUTPUT
            IsIndexed           : VARIANT_BOOL*'''
        return super(IArcInfoItemEdit, self).get_IsIndexed()
    AlternateName = property(get_AlternateName, put_AlternateName, None)
    IsIndexed = property(get_IsIndexed, put_IsIndexed, None)
    IsPseudo = property(get_IsPseudo, put_IsPseudo, None)
    IsRedefined = property(get_IsRedefined, put_IsRedefined, None)
    Name = property(get_Name, put_Name, None)
    NumberDecimals = property(get_NumberDecimals, put_NumberDecimals, None)
    OutputWidth = property(get_OutputWidth, put_OutputWidth, None)
    StartPosition = property(get_StartPosition, put_StartPosition, None)
    Type = property(get_Type, put_Type, None)
    Width = property(get_Width, put_Width, None)

class IArcInfoItems(_esriDataSourcesFile.IArcInfoItems):
    _IID = uuid.UUID('b5e470d4-ceab-11d2-b0dc-0000f8780820')
    def get_ItemCount(self):
        '''Method IArcInfoItems.get_ItemCount

           OUTPUT
            numItems            : long*'''
        return super(IArcInfoItems, self).get_ItemCount()
    def get_Item(self, index):
        '''Method IArcInfoItems.get_Item

           INPUT
            index               : long

           OUTPUT
            Item                : IArcInfoItem**'''
        return super(IArcInfoItems, self).get_Item(index)
    def FindItem(self, Name):
        '''Method IArcInfoItems.FindItem

           INPUT
            Name                : BSTR

           OUTPUT
            index               : long*'''
        return super(IArcInfoItems, self).FindItem(Name)
    ItemCount = property(get_ItemCount, None, None)
    Item = IndexProperty(get_Item, None)

class IArcInfoItemsEdit(_esriDataSourcesFile.IArcInfoItemsEdit):
    _IID = uuid.UUID('b5e470d5-ceab-11d2-b0dc-0000f8780820')

    def __init__(self, *args, **kw):
        super(IArcInfoItemsEdit, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ItemCount(self, _arg1):
        '''Method IArcInfoItemsEdit.put_ItemCount

           INPUT
            _arg1               : long'''
        return super(IArcInfoItemsEdit, self).put_ItemCount(_arg1)
    def put_Item(self, index, _arg2):
        '''Method IArcInfoItemsEdit.put_Item

           INPUTS
            index               : long
            _arg2               : IArcInfoItem*'''
        return super(IArcInfoItemsEdit, self).put_Item(index, _arg2)
    def AddItem(self, Item):
        '''Method IArcInfoItemsEdit.AddItem

           INPUT
            Item                : IArcInfoItem*'''
        return super(IArcInfoItemsEdit, self).AddItem(Item)
    def DeleteItem(self, Item):
        '''Method IArcInfoItemsEdit.DeleteItem

           INPUT
            Item                : IArcInfoItem*'''
        return super(IArcInfoItemsEdit, self).DeleteItem(Item)
    def DeleteAllItems(self):
        '''Method IArcInfoItemsEdit.DeleteAllItems'''
        return super(IArcInfoItemsEdit, self).DeleteAllItems()
    def get_ItemCount(self):
        '''Method IArcInfoItems.get_ItemCount (from IArcInfoItems)

           OUTPUT
            numItems            : long*'''
        return super(IArcInfoItemsEdit, self).get_ItemCount()
    def get_Item(self, index):
        '''Method IArcInfoItems.get_Item (from IArcInfoItems)

           INPUT
            index               : long

           OUTPUT
            Item                : IArcInfoItem**'''
        return super(IArcInfoItemsEdit, self).get_Item(index)
    def FindItem(self, Name):
        '''Method IArcInfoItems.FindItem (from IArcInfoItems)

           INPUT
            Name                : BSTR

           OUTPUT
            index               : long*'''
        return super(IArcInfoItemsEdit, self).FindItem(Name)
    Item = property(None, put_Item, None)
    ItemCount = property(get_ItemCount, put_ItemCount, None)
    Item = IndexProperty(get_Item, None)

class IArcInfoTable(_esriDataSourcesFile.IArcInfoTable):
    _IID = uuid.UUID('d3ec3d31-cffe-11d2-b0dc-0000f8780820')
    def FindItem(self, Name):
        '''Method IArcInfoTable.FindItem

           INPUT
            Name                : BSTR

           OUTPUT
            itemIndex           : long*'''
        return super(IArcInfoTable, self).FindItem(Name)
    def get_ItemSet(self):
        '''Method IArcInfoTable.get_ItemSet

           OUTPUT
            ItemSet             : IArcInfoItems**'''
        return super(IArcInfoTable, self).get_ItemSet()
    def AddItem(self, Item, startItem):
        '''Method IArcInfoTable.AddItem

           INPUTS
            Item                : IArcInfoItem*
            startItem           : BSTR'''
        return super(IArcInfoTable, self).AddItem(Item, startItem)
    def DeleteItem(self, itemName):
        '''Method IArcInfoTable.DeleteItem

           INPUT
            itemName            : BSTR'''
        return super(IArcInfoTable, self).DeleteItem(itemName)
    def AddIndex(self, itemName):
        '''Method IArcInfoTable.AddIndex

           INPUT
            itemName            : BSTR'''
        return super(IArcInfoTable, self).AddIndex(itemName)
    def DeleteIndex(self, itemName):
        '''Method IArcInfoTable.DeleteIndex

           INPUT
            itemName            : BSTR'''
        return super(IArcInfoTable, self).DeleteIndex(itemName)
    def AlterItem(self, itemName, Item):
        '''Method IArcInfoTable.AlterItem

           INPUTS
            itemName            : BSTR
            Item                : IArcInfoItem*'''
        return super(IArcInfoTable, self).AlterItem(itemName, Item)
    ItemSet = property(get_ItemSet, None, None)

class IArcInfoTable2(_esriDataSourcesFile.IArcInfoTable2):
    _IID = uuid.UUID('99d56004-bb97-4606-a141-6bb061f87940')
    def External(self, externalname):
        '''Method IArcInfoTable2.External

           INPUT
            externalname        : BSTR'''
        return super(IArcInfoTable2, self).External(externalname)

class ICoverageFeatureClass(_esriDataSourcesFile.ICoverageFeatureClass):
    _IID = uuid.UUID('4e471bb1-06fa-11d3-9f31-00c04f79927c')
    def get_FeatureClassType(self):
        '''Method ICoverageFeatureClass.get_FeatureClassType

           OUTPUT
            FeatureClassType    : esriCoverageFeatureClassType*'''
        return super(ICoverageFeatureClass, self).get_FeatureClassType()
    def get_Topology(self):
        '''Method ICoverageFeatureClass.get_Topology

           OUTPUT
            Topology            : esriFeatureClassTopology*'''
        return super(ICoverageFeatureClass, self).get_Topology()
    def get_HasFAT(self):
        '''Method ICoverageFeatureClass.get_HasFAT

           OUTPUT
            HasFAT              : VARIANT_BOOL*'''
        return super(ICoverageFeatureClass, self).get_HasFAT()
    FeatureClassType = property(get_FeatureClassType, None, None)
    HasFAT = property(get_HasFAT, None, None)
    Topology = property(get_Topology, None, None)

class ICoverageFeatureClass2(_esriDataSourcesFile.ICoverageFeatureClass2):
    _IID = uuid.UUID('2da3b82a-b02a-11d4-9f5a-00c04f79927c')
    def Copy(self, copyName, copyFeatureDataset):
        '''Method ICoverageFeatureClass2.Copy

           INPUTS
            copyName            : BSTR
            copyFeatureDataset  : IFeatureDataset*

           OUTPUT
            copyFeatureClass    : IFeatureClass**'''
        return super(ICoverageFeatureClass2, self).Copy(copyName, copyFeatureDataset)
    def get_FeatureClassType(self):
        '''Method ICoverageFeatureClass.get_FeatureClassType (from ICoverageFeatureClass)

           OUTPUT
            FeatureClassType    : esriCoverageFeatureClassType*'''
        return super(ICoverageFeatureClass2, self).get_FeatureClassType()
    def get_Topology(self):
        '''Method ICoverageFeatureClass.get_Topology (from ICoverageFeatureClass)

           OUTPUT
            Topology            : esriFeatureClassTopology*'''
        return super(ICoverageFeatureClass2, self).get_Topology()
    def get_HasFAT(self):
        '''Method ICoverageFeatureClass.get_HasFAT (from ICoverageFeatureClass)

           OUTPUT
            HasFAT              : VARIANT_BOOL*'''
        return super(ICoverageFeatureClass2, self).get_HasFAT()
    FeatureClassType = property(get_FeatureClassType, None, None)
    HasFAT = property(get_HasFAT, None, None)
    Topology = property(get_Topology, None, None)

class ICoverage(_esriDataSourcesFile.ICoverage):
    _IID = uuid.UUID('d42131e1-d187-11d2-b0dc-0000f8780820')

    def __init__(self, *args, **kw):
        super(ICoverage, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Tolerance(self, toleranceType):
        '''Method ICoverage.get_Tolerance

           INPUT
            toleranceType       : esriCoverageToleranceType

           OUTPUT
            toleranceValue      : double*'''
        return super(ICoverage, self).get_Tolerance(toleranceType)
    def get_ToleranceStatus(self, toleranceType):
        '''Method ICoverage.get_ToleranceStatus

           INPUT
            toleranceType       : esriCoverageToleranceType

           OUTPUT
            isVerified          : VARIANT_BOOL*'''
        return super(ICoverage, self).get_ToleranceStatus(toleranceType)
    def put_Tolerance(self, toleranceType, toleranceValue):
        '''Method ICoverage.put_Tolerance

           INPUTS
            toleranceType       : esriCoverageToleranceType
            toleranceValue      : double'''
        return super(ICoverage, self).put_Tolerance(toleranceType, toleranceValue)
    def Build(self, FeatureClassType, subclassName):
        '''Method ICoverage.Build

           INPUTS
            FeatureClassType    : esriCoverageFeatureClassType
            subclassName        : BSTR'''
        return super(ICoverage, self).Build(FeatureClassType, subclassName)
    def Clean(self, dangleTolerance, fuzzyTolerance, FeatureClassType):
        '''Method ICoverage.Clean

           INPUTS
            dangleTolerance     : double
            fuzzyTolerance      : double
            FeatureClassType    : esriCoverageFeatureClassType'''
        return super(ICoverage, self).Clean(dangleTolerance, fuzzyTolerance, FeatureClassType)
    def CreateFeatureClass(self, FeatureClassType, subclassName):
        '''Method ICoverage.CreateFeatureClass

           INPUTS
            FeatureClassType    : esriCoverageFeatureClassType
            subclassName        : BSTR

           OUTPUT
            featureClass        : IFeatureClass**'''
        return super(ICoverage, self).CreateFeatureClass(FeatureClassType, subclassName)
    Tolerance = property(None, put_Tolerance, None)
    Tolerance = IndexProperty(get_Tolerance, None)
    ToleranceStatus = IndexProperty(get_ToleranceStatus, None)

class ICoverage2(_esriDataSourcesFile.ICoverage2):
    _IID = uuid.UUID('d1e706bc-6eee-11d4-9f55-00c04f79927c')

    def __init__(self, *args, **kw):
        super(ICoverage2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Extent(self, _arg1):
        '''Method ICoverage2.put_Extent

           INPUT
            _arg1               : IEnvelope*'''
        return super(ICoverage2, self).put_Extent(_arg1)
    def RefreshSpatialProperties(self):
        '''Method ICoverage2.RefreshSpatialProperties'''
        return super(ICoverage2, self).RefreshSpatialProperties()
    def get_Tolerance(self, toleranceType):
        '''Method ICoverage.get_Tolerance (from ICoverage)

           INPUT
            toleranceType       : esriCoverageToleranceType

           OUTPUT
            toleranceValue      : double*'''
        return super(ICoverage2, self).get_Tolerance(toleranceType)
    def get_ToleranceStatus(self, toleranceType):
        '''Method ICoverage.get_ToleranceStatus (from ICoverage)

           INPUT
            toleranceType       : esriCoverageToleranceType

           OUTPUT
            isVerified          : VARIANT_BOOL*'''
        return super(ICoverage2, self).get_ToleranceStatus(toleranceType)
    def put_Tolerance(self, toleranceType, toleranceValue):
        '''Method ICoverage.put_Tolerance (from ICoverage)

           INPUTS
            toleranceType       : esriCoverageToleranceType
            toleranceValue      : double'''
        return super(ICoverage2, self).put_Tolerance(toleranceType, toleranceValue)
    def Build(self, FeatureClassType, subclassName):
        '''Method ICoverage.Build (from ICoverage)

           INPUTS
            FeatureClassType    : esriCoverageFeatureClassType
            subclassName        : BSTR'''
        return super(ICoverage2, self).Build(FeatureClassType, subclassName)
    def Clean(self, dangleTolerance, fuzzyTolerance, FeatureClassType):
        '''Method ICoverage.Clean (from ICoverage)

           INPUTS
            dangleTolerance     : double
            fuzzyTolerance      : double
            FeatureClassType    : esriCoverageFeatureClassType'''
        return super(ICoverage2, self).Clean(dangleTolerance, fuzzyTolerance, FeatureClassType)
    def CreateFeatureClass(self, FeatureClassType, subclassName):
        '''Method ICoverage.CreateFeatureClass (from ICoverage)

           INPUTS
            FeatureClassType    : esriCoverageFeatureClassType
            subclassName        : BSTR

           OUTPUT
            featureClass        : IFeatureClass**'''
        return super(ICoverage2, self).CreateFeatureClass(FeatureClassType, subclassName)
    Extent = property(None, put_Extent, None)
    Tolerance = property(None, put_Tolerance, None)
    Tolerance = IndexProperty(get_Tolerance, None)
    ToleranceStatus = IndexProperty(get_ToleranceStatus, None)

class IArcInfoWorkspace(_esriDataSourcesFile.IArcInfoWorkspace):
    _IID = uuid.UUID('730e2ff7-e3b4-11d2-9f30-00c04f79927c')
    def CreateCoverage(self, Name, templateCoverage, precision):
        '''Method IArcInfoWorkspace.CreateCoverage

           INPUTS
            Name                : BSTR
            templateCoverage    : BSTR
            precision           : esriCoveragePrecisionType

           OUTPUT
            featureDataset      : IFeatureDataset**'''
        return super(IArcInfoWorkspace, self).CreateCoverage(Name, templateCoverage, precision)
    def CreateInfoTable(self, Name, ItemSet):
        '''Method IArcInfoWorkspace.CreateInfoTable

           INPUTS
            Name                : BSTR
            ItemSet             : IArcInfoItems*

           OUTPUT
            Table               : ITable**'''
        return super(IArcInfoWorkspace, self).CreateInfoTable(Name, ItemSet)

class IInfoTableOnlyWorkspaceEdit(_esriDataSourcesFile.IInfoTableOnlyWorkspaceEdit):
    _IID = uuid.UUID('215b5973-795c-499f-b3ff-798c1cd4dbe6')
    def StartEditingTablesOnly(self, withUndoRedo):
        '''Method IInfoTableOnlyWorkspaceEdit.StartEditingTablesOnly

           INPUT
            withUndoRedo        : VARIANT_BOOL'''
        return super(IInfoTableOnlyWorkspaceEdit, self).StartEditingTablesOnly(withUndoRedo)

class ICoverageFeatureClassName(_esriDataSourcesFile.ICoverageFeatureClassName):
    _IID = uuid.UUID('de61a107-0e08-11d3-9f31-00c04f79927c')

    def __init__(self, *args, **kw):
        super(ICoverageFeatureClassName, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_FeatureClassType(self):
        '''Method ICoverageFeatureClassName.get_FeatureClassType

           OUTPUT
            FeatureClassType    : esriCoverageFeatureClassType*'''
        return super(ICoverageFeatureClassName, self).get_FeatureClassType()
    def put_FeatureClassType(self, FeatureClassType):
        '''Method ICoverageFeatureClassName.put_FeatureClassType

           INPUT
            FeatureClassType    : esriCoverageFeatureClassType'''
        return super(ICoverageFeatureClassName, self).put_FeatureClassType(FeatureClassType)
    def get_Topology(self):
        '''Method ICoverageFeatureClassName.get_Topology

           OUTPUT
            Topology            : esriFeatureClassTopology*'''
        return super(ICoverageFeatureClassName, self).get_Topology()
    def put_Topology(self, Topology):
        '''Method ICoverageFeatureClassName.put_Topology

           INPUT
            Topology            : esriFeatureClassTopology'''
        return super(ICoverageFeatureClassName, self).put_Topology(Topology)
    def get_HasFAT(self):
        '''Method ICoverageFeatureClassName.get_HasFAT

           OUTPUT
            HasFAT              : VARIANT_BOOL*'''
        return super(ICoverageFeatureClassName, self).get_HasFAT()
    def put_HasFAT(self, HasFAT):
        '''Method ICoverageFeatureClassName.put_HasFAT

           INPUT
            HasFAT              : VARIANT_BOOL'''
        return super(ICoverageFeatureClassName, self).put_HasFAT(HasFAT)
    FeatureClassType = property(get_FeatureClassType, put_FeatureClassType, None)
    HasFAT = property(get_HasFAT, put_HasFAT, None)
    Topology = property(get_Topology, put_Topology, None)

class ICoverageName(_esriDataSourcesFile.ICoverageName):
    _IID = uuid.UUID('de61a108-0e08-11d3-9f31-00c04f79927c')

    def __init__(self, *args, **kw):
        super(ICoverageName, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_CoverageType(self):
        '''Method ICoverageName.get_CoverageType

           OUTPUT
            CoverageType        : esriCoverageType*'''
        return super(ICoverageName, self).get_CoverageType()
    def put_CoverageType(self, CoverageType):
        '''Method ICoverageName.put_CoverageType

           INPUT
            CoverageType        : esriCoverageType'''
        return super(ICoverageName, self).put_CoverageType(CoverageType)
    CoverageType = property(get_CoverageType, put_CoverageType, None)

class IArcInfoWorkspaceUtil(_esriDataSourcesFile.IArcInfoWorkspaceUtil):
    _IID = uuid.UUID('a476810a-0c8d-469a-8332-7b3c1cfb8923')
    def GetInfoTableName(self, prefix):
        '''Method IArcInfoWorkspaceUtil.GetInfoTableName

           INPUT
            prefix              : BSTR

           OUTPUT
            pTableName          : BSTR*'''
        return super(IArcInfoWorkspaceUtil, self).GetInfoTableName(prefix)

class ICadSettings(_esriDataSourcesFile.ICadSettings):
    _IID = uuid.UUID('628022fd-e7df-11d4-a2a8-444553547777')

    def __init__(self, *args, **kw):
        super(ICadSettings, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_EnableAllDgnFileExtensions(self):
        '''Method ICadSettings.get_EnableAllDgnFileExtensions

           OUTPUT
            pEnabled            : VARIANT_BOOL*'''
        return super(ICadSettings, self).get_EnableAllDgnFileExtensions()
    def put_EnableAllDgnFileExtensions(self, pEnabled):
        '''Method ICadSettings.put_EnableAllDgnFileExtensions

           INPUT
            pEnabled            : VARIANT_BOOL'''
        return super(ICadSettings, self).put_EnableAllDgnFileExtensions(pEnabled)
    EnableAllDgnFileExtensions = property(get_EnableAllDgnFileExtensions, put_EnableAllDgnFileExtensions, None)

class ICadDrawingLayers(_esriDataSourcesFile.ICadDrawingLayers):
    _IID = uuid.UUID('e37f71aa-bfb1-11d2-9b20-00c04fa33299')

    def __init__(self, *args, **kw):
        super(ICadDrawingLayers, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_DrawingLayerCount(self):
        '''Method ICadDrawingLayers.get_DrawingLayerCount

           OUTPUT
            Count               : long*'''
        return super(ICadDrawingLayers, self).get_DrawingLayerCount()
    def get_DrawingLayerName(self, index):
        '''Method ICadDrawingLayers.get_DrawingLayerName

           INPUT
            index               : long

           OUTPUT
            FilePath            : BSTR*'''
        return super(ICadDrawingLayers, self).get_DrawingLayerName(index)
    def get_DrawingLayerVisible(self, index):
        '''Method ICadDrawingLayers.get_DrawingLayerVisible

           INPUT
            index               : long

           OUTPUT
            visible             : VARIANT_BOOL*'''
        return super(ICadDrawingLayers, self).get_DrawingLayerVisible(index)
    def put_DrawingLayerVisible(self, index, visible):
        '''Method ICadDrawingLayers.put_DrawingLayerVisible

           INPUTS
            index               : long
            visible             : VARIANT_BOOL'''
        return super(ICadDrawingLayers, self).put_DrawingLayerVisible(index, visible)
    def get_OriginalDrawingLayerVisible(self, index):
        '''Method ICadDrawingLayers.get_OriginalDrawingLayerVisible

           INPUT
            index               : long

           OUTPUT
            visible             : VARIANT_BOOL*'''
        return super(ICadDrawingLayers, self).get_OriginalDrawingLayerVisible(index)
    DrawingLayerCount = property(get_DrawingLayerCount, None, None)
    DrawingLayerVisible = property(None, put_DrawingLayerVisible, None)
    DrawingLayerName = IndexProperty(get_DrawingLayerName, None)
    DrawingLayerVisible = IndexProperty(get_DrawingLayerVisible, None)
    OriginalDrawingLayerVisible = IndexProperty(get_OriginalDrawingLayerVisible, None)

class ICadTransformations(_esriDataSourcesFile.ICadTransformations):
    _IID = uuid.UUID('e37f71ab-bfb1-11d2-9b20-00c04fa33299')

    def __init__(self, *args, **kw):
        super(ICadTransformations, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_EnableTransformations(self):
        '''Method ICadTransformations.get_EnableTransformations

           OUTPUT
            enabled             : VARIANT_BOOL*'''
        return super(ICadTransformations, self).get_EnableTransformations()
    def put_EnableTransformations(self, enabled):
        '''Method ICadTransformations.put_EnableTransformations

           INPUT
            enabled             : VARIANT_BOOL'''
        return super(ICadTransformations, self).put_EnableTransformations(enabled)
    def get_WorldFileName(self):
        '''Method ICadTransformations.get_WorldFileName

           OUTPUT
            FilePath            : BSTR*'''
        return super(ICadTransformations, self).get_WorldFileName()
    def put_WorldFileName(self, FilePath):
        '''Method ICadTransformations.put_WorldFileName

           INPUT
            FilePath            : BSTR'''
        return super(ICadTransformations, self).put_WorldFileName(FilePath)
    def get_TransformMode(self):
        '''Method ICadTransformations.get_TransformMode

           OUTPUT
            mode                : esriCadTransform*'''
        return super(ICadTransformations, self).get_TransformMode()
    def put_TransformMode(self, mode):
        '''Method ICadTransformations.put_TransformMode

           INPUT
            mode                : esriCadTransform'''
        return super(ICadTransformations, self).put_TransformMode(mode)
    def GetFromToTransform(self):
        '''Method ICadTransformations.GetFromToTransform

           OUTPUTS
            fromPoint1          : WKSPoint*
            fromPoint2          : WKSPoint*
            toPoint1            : WKSPoint*
            toPoint2            : WKSPoint*'''
        return super(ICadTransformations, self).GetFromToTransform()
    def SetFromToTransform(self, fromPoint1, fromPoint2, toPoint1, toPoint2):
        '''Method ICadTransformations.SetFromToTransform

           INPUTS
            fromPoint1          : WKSPoint*
            fromPoint2          : WKSPoint*
            toPoint1            : WKSPoint*
            toPoint2            : WKSPoint*'''
        return super(ICadTransformations, self).SetFromToTransform(fromPoint1, fromPoint2, toPoint1, toPoint2)
    def GetTransformation(self):
        '''Method ICadTransformations.GetTransformation

           OUTPUTS
            from                : WKSPoint*
            to                  : WKSPoint*
            angle               : double*
            scale               : double*'''
        return super(ICadTransformations, self).GetTransformation()
    def SetTransformation(self, From, to, angle, scale):
        '''Method ICadTransformations.SetTransformation

           INPUTS
            from                : WKSPoint*
            to                  : WKSPoint*
            angle               : double
            scale               : double'''
        return super(ICadTransformations, self).SetTransformation(From, to, angle, scale)
    EnableTransformations = property(get_EnableTransformations, put_EnableTransformations, None)
    TransformMode = property(get_TransformMode, put_TransformMode, None)
    WorldFileName = property(get_WorldFileName, put_WorldFileName, None)

class ICadDrawingDataset(_esriDataSourcesFile.ICadDrawingDataset):
    _IID = uuid.UUID('6c1d6540-4930-11d3-9b39-00c04fa33299')
    def get_FilePath(self):
        '''Method ICadDrawingDataset.get_FilePath

           OUTPUT
            FilePath            : BSTR*'''
        return super(ICadDrawingDataset, self).get_FilePath()
    def get_Is2d(self):
        '''Method ICadDrawingDataset.get_Is2d

           OUTPUT
            Is2d                : VARIANT_BOOL*'''
        return super(ICadDrawingDataset, self).get_Is2d()
    def get_Is3d(self):
        '''Method ICadDrawingDataset.get_Is3d

           OUTPUT
            Is3d                : VARIANT_BOOL*'''
        return super(ICadDrawingDataset, self).get_Is3d()
    def get_IsAutoCad(self):
        '''Method ICadDrawingDataset.get_IsAutoCad

           OUTPUT
            IsAutoCad           : VARIANT_BOOL*'''
        return super(ICadDrawingDataset, self).get_IsAutoCad()
    def get_IsDgn(self):
        '''Method ICadDrawingDataset.get_IsDgn

           OUTPUT
            IsDgn               : VARIANT_BOOL*'''
        return super(ICadDrawingDataset, self).get_IsDgn()
    def get_Exists(self):
        '''Method ICadDrawingDataset.get_Exists

           OUTPUT
            Exists              : VARIANT_BOOL*'''
        return super(ICadDrawingDataset, self).get_Exists()
    Exists = property(get_Exists, None, None)
    FilePath = property(get_FilePath, None, None)
    Is2d = property(get_Is2d, None, None)
    Is3d = property(get_Is3d, None, None)
    IsAutoCad = property(get_IsAutoCad, None, None)
    IsDgn = property(get_IsDgn, None, None)

class ICadDrawingWorkspace(_esriDataSourcesFile.ICadDrawingWorkspace):
    _IID = uuid.UUID('76b47b11-ac32-11d4-a226-444553547777')
    def OpenCadDrawingDataset(self, Name):
        '''Method ICadDrawingWorkspace.OpenCadDrawingDataset

           INPUT
            Name                : BSTR

           OUTPUT
            dataset             : ICadDrawingDataset**'''
        return super(ICadDrawingWorkspace, self).OpenCadDrawingDataset(Name)

class ISdcExporter(_esriDataSourcesFile.ISdcExporter):
    _IID = uuid.UUID('989b9737-fecf-467d-8544-d3b3ee30e60c')
    def Export(self, cursor, outputRootname, Key, trackCancel):
        '''Method ISdcExporter.Export

           INPUTS
            cursor              : ICursor*
            outputRootname      : BSTR
            Key                 : GUID*
            trackCancel         : ITrackCancel*

           OUTPUT
            sdcDataset          : IDataset**'''
        return super(ISdcExporter, self).Export(cursor, outputRootname, Key, trackCancel)

class ISMRouterPoint(_esriDataSourcesFile.ISMRouterPoint):
    _IID = uuid.UUID('f8b65fed-5850-11d7-b321-008048db11de')

    def __init__(self, *args, **kw):
        super(ISMRouterPoint, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_X(self):
        '''Method ISMRouterPoint.get_X

           OUTPUT
            pVal                : double*'''
        return super(ISMRouterPoint, self).get_X()
    def put_X(self, pVal):
        '''Method ISMRouterPoint.put_X

           INPUT
            pVal                : double'''
        return super(ISMRouterPoint, self).put_X(pVal)
    def get_Y(self):
        '''Method ISMRouterPoint.get_Y

           OUTPUT
            pVal                : double*'''
        return super(ISMRouterPoint, self).get_Y()
    def put_Y(self, pVal):
        '''Method ISMRouterPoint.put_Y

           INPUT
            pVal                : double'''
        return super(ISMRouterPoint, self).put_Y(pVal)
    X = property(get_X, put_X, None)
    Y = property(get_Y, put_Y, None)

class ISMRouterEnvelope(_esriDataSourcesFile.ISMRouterEnvelope):
    _IID = uuid.UUID('f8b65ff0-5850-11d7-b321-008048db11de')

    def __init__(self, *args, **kw):
        super(ISMRouterEnvelope, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Top(self):
        '''Method ISMRouterEnvelope.get_Top

           OUTPUT
            pVal                : double*'''
        return super(ISMRouterEnvelope, self).get_Top()
    def put_Top(self, pVal):
        '''Method ISMRouterEnvelope.put_Top

           INPUT
            pVal                : double'''
        return super(ISMRouterEnvelope, self).put_Top(pVal)
    def get_Bottom(self):
        '''Method ISMRouterEnvelope.get_Bottom

           OUTPUT
            pVal                : double*'''
        return super(ISMRouterEnvelope, self).get_Bottom()
    def put_Bottom(self, pVal):
        '''Method ISMRouterEnvelope.put_Bottom

           INPUT
            pVal                : double'''
        return super(ISMRouterEnvelope, self).put_Bottom(pVal)
    def get_Left(self):
        '''Method ISMRouterEnvelope.get_Left

           OUTPUT
            pVal                : double*'''
        return super(ISMRouterEnvelope, self).get_Left()
    def put_Left(self, pVal):
        '''Method ISMRouterEnvelope.put_Left

           INPUT
            pVal                : double'''
        return super(ISMRouterEnvelope, self).put_Left(pVal)
    def get_Right(self):
        '''Method ISMRouterEnvelope.get_Right

           OUTPUT
            pVal                : double*'''
        return super(ISMRouterEnvelope, self).get_Right()
    def put_Right(self, pVal):
        '''Method ISMRouterEnvelope.put_Right

           INPUT
            pVal                : double'''
        return super(ISMRouterEnvelope, self).put_Right(pVal)
    Bottom = property(get_Bottom, put_Bottom, None)
    Left = property(get_Left, put_Left, None)
    Right = property(get_Right, put_Right, None)
    Top = property(get_Top, put_Top, None)

class ISMPointsCollection(_esriDataSourcesFile.ISMPointsCollection):
    _IID = uuid.UUID('f8b65ff3-5850-11d7-b321-008048db11de')
    def get_Count(self):
        '''Method ISMPointsCollection.get_Count

           OUTPUT
            pVal                : long*'''
        return super(ISMPointsCollection, self).get_Count()
    def get_Item(self, Position):
        '''Method ISMPointsCollection.get_Item

           INPUT
            Position            : long

           OUTPUT
            pVal                : ISMRouterPoint**'''
        return super(ISMPointsCollection, self).get_Item(Position)
    def Add(self, pItem):
        '''Method ISMPointsCollection.Add

           INPUT
            pItem               : ISMRouterPoint*'''
        return super(ISMPointsCollection, self).Add(pItem)
    def Insert(self, Position, pItem):
        '''Method ISMPointsCollection.Insert

           INPUTS
            Position            : long
            pItem               : ISMRouterPoint*'''
        return super(ISMPointsCollection, self).Insert(Position, pItem)
    def Remove(self, Position):
        '''Method ISMPointsCollection.Remove

           INPUT
            Position            : long'''
        return super(ISMPointsCollection, self).Remove(Position)
    def Clear(self):
        '''Method ISMPointsCollection.Clear'''
        return super(ISMPointsCollection, self).Clear()
    Count = property(get_Count, None, None)
    Item = IndexProperty(get_Item, None)

class ISMNetAttribute(_esriDataSourcesFile.ISMNetAttribute):
    _IID = uuid.UUID('f8b65ff6-5850-11d7-b321-008048db11de')
    def get_Name(self):
        '''Method ISMNetAttribute.get_Name

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMNetAttribute, self).get_Name()
    def get_Type(self):
        '''Method ISMNetAttribute.get_Type

           OUTPUT
            pVal                : esriSMNetAttributeType*'''
        return super(ISMNetAttribute, self).get_Type()
    Name = property(get_Name, None, None)
    Type = property(get_Type, None, None)

class ISMNetAttribute2(_esriDataSourcesFile.ISMNetAttribute2):
    _IID = uuid.UUID('b1a5376c-dfdf-48dd-a472-076808c0c73e')
    def get_UsageType(self):
        '''Method ISMNetAttribute2.get_UsageType

           OUTPUT
            pVal                : esriSMNetAttributeUsageType*'''
        return super(ISMNetAttribute2, self).get_UsageType()
    def get_Name(self):
        '''Method ISMNetAttribute.get_Name (from ISMNetAttribute)

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMNetAttribute2, self).get_Name()
    def get_Type(self):
        '''Method ISMNetAttribute.get_Type (from ISMNetAttribute)

           OUTPUT
            pVal                : esriSMNetAttributeType*'''
        return super(ISMNetAttribute2, self).get_Type()
    Name = property(get_Name, None, None)
    Type = property(get_Type, None, None)
    UsageType = property(get_UsageType, None, None)

class ISMNetAttributesCollection(_esriDataSourcesFile.ISMNetAttributesCollection):
    _IID = uuid.UUID('f8b65ff9-5850-11d7-b321-008048db11de')
    def get_Count(self):
        '''Method ISMNetAttributesCollection.get_Count

           OUTPUT
            pVal                : long*'''
        return super(ISMNetAttributesCollection, self).get_Count()
    def get_Item(self, Position):
        '''Method ISMNetAttributesCollection.get_Item

           INPUT
            Position            : long

           OUTPUT
            pVal                : ISMNetAttribute**'''
        return super(ISMNetAttributesCollection, self).get_Item(Position)
    Count = property(get_Count, None, None)
    Item = IndexProperty(get_Item, None)

class ISMNetBarrier(_esriDataSourcesFile.ISMNetBarrier):
    _IID = uuid.UUID('f8b65ffc-5850-11d7-b321-008048db11de')

    def __init__(self, *args, **kw):
        super(ISMNetBarrier, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_BarrierID(self):
        '''Method ISMNetBarrier.get_BarrierID

           OUTPUT
            pVal                : long*'''
        return super(ISMNetBarrier, self).get_BarrierID()
    def put_BarrierID(self, pVal):
        '''Method ISMNetBarrier.put_BarrierID

           INPUT
            pVal                : long'''
        return super(ISMNetBarrier, self).put_BarrierID(pVal)
    def get_Point(self):
        '''Method ISMNetBarrier.get_Point

           OUTPUT
            pVal                : ISMRouterPoint**'''
        return super(ISMNetBarrier, self).get_Point()
    def put_Point(self, pVal):
        '''Method ISMNetBarrier.put_Point

           INPUT
            pVal                : ISMRouterPoint*'''
        return super(ISMNetBarrier, self).put_Point(pVal)
    BarrierID = property(get_BarrierID, put_BarrierID, None)
    Point = property(get_Point, put_Point, None)

class ISMNetBarriersCollection(_esriDataSourcesFile.ISMNetBarriersCollection):
    _IID = uuid.UUID('f8b65fff-5850-11d7-b321-008048db11de')
    def Add(self, pItem):
        '''Method ISMNetBarriersCollection.Add

           INPUT
            pItem               : ISMNetBarrier*'''
        return super(ISMNetBarriersCollection, self).Add(pItem)
    def Remove(self, lID):
        '''Method ISMNetBarriersCollection.Remove

           INPUT
            lID                 : long'''
        return super(ISMNetBarriersCollection, self).Remove(lID)
    def Clear(self):
        '''Method ISMNetBarriersCollection.Clear'''
        return super(ISMNetBarriersCollection, self).Clear()

class ISMRoadPreferences(_esriDataSourcesFile.ISMRoadPreferences):
    _IID = uuid.UUID('f8b66002-5850-11d7-b321-008048db11de')

    def __init__(self, *args, **kw):
        super(ISMRoadPreferences, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Item(self, RoadType):
        '''Method ISMRoadPreferences.get_Item

           INPUT
            RoadType            : esriSMRoadType

           OUTPUT
            pVal                : short*'''
        return super(ISMRoadPreferences, self).get_Item(RoadType)
    def put_Item(self, RoadType, pVal):
        '''Method ISMRoadPreferences.put_Item

           INPUTS
            RoadType            : esriSMRoadType
            pVal                : short'''
        return super(ISMRoadPreferences, self).put_Item(RoadType, pVal)
    Item = property(None, put_Item, None)
    Item = IndexProperty(get_Item, None)

class ISMSpeedGroup(_esriDataSourcesFile.ISMSpeedGroup):
    _IID = uuid.UUID('f8b66005-5850-11d7-b321-008048db11de')

    def __init__(self, *args, **kw):
        super(ISMSpeedGroup, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Speed(self):
        '''Method ISMSpeedGroup.get_Speed

           OUTPUT
            pVal                : float*'''
        return super(ISMSpeedGroup, self).get_Speed()
    def put_Speed(self, pVal):
        '''Method ISMSpeedGroup.put_Speed

           INPUT
            pVal                : float'''
        return super(ISMSpeedGroup, self).put_Speed(pVal)
    def get_Description(self):
        '''Method ISMSpeedGroup.get_Description

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMSpeedGroup, self).get_Description()
    Description = property(get_Description, None, None)
    Speed = property(get_Speed, put_Speed, None)

class ISMSpeedGroup2(_esriDataSourcesFile.ISMSpeedGroup2):
    _IID = uuid.UUID('1e436c24-cf57-4aca-bbd3-ffddb1151fa7')

    def __init__(self, *args, **kw):
        super(ISMSpeedGroup2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_QueryString(self):
        '''Method ISMSpeedGroup2.get_QueryString

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMSpeedGroup2, self).get_QueryString()
    def get_Speed(self):
        '''Method ISMSpeedGroup.get_Speed (from ISMSpeedGroup)

           OUTPUT
            pVal                : float*'''
        return super(ISMSpeedGroup2, self).get_Speed()
    def put_Speed(self, pVal):
        '''Method ISMSpeedGroup.put_Speed (from ISMSpeedGroup)

           INPUT
            pVal                : float'''
        return super(ISMSpeedGroup2, self).put_Speed(pVal)
    def get_Description(self):
        '''Method ISMSpeedGroup.get_Description (from ISMSpeedGroup)

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMSpeedGroup2, self).get_Description()
    Description = property(get_Description, None, None)
    QueryString = property(get_QueryString, None, None)
    Speed = property(get_Speed, put_Speed, None)

class ISMSpeedGroups(_esriDataSourcesFile.ISMSpeedGroups):
    _IID = uuid.UUID('f8b66008-5850-11d7-b321-008048db11de')
    def get_Count(self):
        '''Method ISMSpeedGroups.get_Count

           OUTPUT
            pVal                : long*'''
        return super(ISMSpeedGroups, self).get_Count()
    def get_Item(self, Position):
        '''Method ISMSpeedGroups.get_Item

           INPUT
            Position            : long

           OUTPUT
            pVal                : ISMSpeedGroup**'''
        return super(ISMSpeedGroups, self).get_Item(Position)
    Count = property(get_Count, None, None)
    Item = IndexProperty(get_Item, None)

class ISMTripPlanSettings(_esriDataSourcesFile.ISMTripPlanSettings):
    _IID = uuid.UUID('f8b6600b-5850-11d7-b321-008048db11de')

    def __init__(self, *args, **kw):
        super(ISMTripPlanSettings, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TripPlanningEnable(self):
        '''Method ISMTripPlanSettings.get_TripPlanningEnable

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ISMTripPlanSettings, self).get_TripPlanningEnable()
    def put_TripPlanningEnable(self, pVal):
        '''Method ISMTripPlanSettings.put_TripPlanningEnable

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(ISMTripPlanSettings, self).put_TripPlanningEnable(pVal)
    def get_TripStart(self):
        '''Method ISMTripPlanSettings.get_TripStart

           OUTPUT
            pVal                : DATE*'''
        return super(ISMTripPlanSettings, self).get_TripStart()
    def put_TripStart(self, pVal):
        '''Method ISMTripPlanSettings.put_TripStart

           INPUT
            pVal                : DATE'''
        return super(ISMTripPlanSettings, self).put_TripStart(pVal)
    def get_DayDriveStart(self):
        '''Method ISMTripPlanSettings.get_DayDriveStart

           OUTPUT
            pVal                : DATE*'''
        return super(ISMTripPlanSettings, self).get_DayDriveStart()
    def put_DayDriveStart(self, pVal):
        '''Method ISMTripPlanSettings.put_DayDriveStart

           INPUT
            pVal                : DATE'''
        return super(ISMTripPlanSettings, self).put_DayDriveStart(pVal)
    def get_DayDriveEnd(self):
        '''Method ISMTripPlanSettings.get_DayDriveEnd

           OUTPUT
            pVal                : DATE*'''
        return super(ISMTripPlanSettings, self).get_DayDriveEnd()
    def put_DayDriveEnd(self, pVal):
        '''Method ISMTripPlanSettings.put_DayDriveEnd

           INPUT
            pVal                : DATE'''
        return super(ISMTripPlanSettings, self).put_DayDriveEnd(pVal)
    def get_DriveFlexibility(self):
        '''Method ISMTripPlanSettings.get_DriveFlexibility

           OUTPUT
            pVal                : short*'''
        return super(ISMTripPlanSettings, self).get_DriveFlexibility()
    def put_DriveFlexibility(self, pVal):
        '''Method ISMTripPlanSettings.put_DriveFlexibility

           INPUT
            pVal                : short'''
        return super(ISMTripPlanSettings, self).put_DriveFlexibility(pVal)
    def get_RestBreaksEnable(self):
        '''Method ISMTripPlanSettings.get_RestBreaksEnable

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ISMTripPlanSettings, self).get_RestBreaksEnable()
    def put_RestBreaksEnable(self, pVal):
        '''Method ISMTripPlanSettings.put_RestBreaksEnable

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(ISMTripPlanSettings, self).put_RestBreaksEnable(pVal)
    def get_RestDuration(self):
        '''Method ISMTripPlanSettings.get_RestDuration

           OUTPUT
            pVal                : short*'''
        return super(ISMTripPlanSettings, self).get_RestDuration()
    def put_RestDuration(self, pVal):
        '''Method ISMTripPlanSettings.put_RestDuration

           INPUT
            pVal                : short'''
        return super(ISMTripPlanSettings, self).put_RestDuration(pVal)
    def get_DriveBetweenRest(self):
        '''Method ISMTripPlanSettings.get_DriveBetweenRest

           OUTPUT
            pVal                : short*'''
        return super(ISMTripPlanSettings, self).get_DriveBetweenRest()
    def put_DriveBetweenRest(self, pVal):
        '''Method ISMTripPlanSettings.put_DriveBetweenRest

           INPUT
            pVal                : short'''
        return super(ISMTripPlanSettings, self).put_DriveBetweenRest(pVal)
    DayDriveEnd = property(get_DayDriveEnd, put_DayDriveEnd, None)
    DayDriveStart = property(get_DayDriveStart, put_DayDriveStart, None)
    DriveBetweenRest = property(get_DriveBetweenRest, put_DriveBetweenRest, None)
    DriveFlexibility = property(get_DriveFlexibility, put_DriveFlexibility, None)
    RestBreaksEnable = property(get_RestBreaksEnable, put_RestBreaksEnable, None)
    RestDuration = property(get_RestDuration, put_RestDuration, None)
    TripPlanningEnable = property(get_TripPlanningEnable, put_TripPlanningEnable, None)
    TripStart = property(get_TripStart, put_TripStart, None)

class ISMFlag(_esriDataSourcesFile.ISMFlag):
    _IID = uuid.UUID('f8b66011-5850-11d7-b321-008048db11de')

    def __init__(self, *args, **kw):
        super(ISMFlag, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ObjectID(self):
        '''Method ISMFlag.get_ObjectID

           OUTPUT
            pVal                : long*'''
        return super(ISMFlag, self).get_ObjectID()
    def put_ObjectID(self, pVal):
        '''Method ISMFlag.put_ObjectID

           INPUT
            pVal                : long'''
        return super(ISMFlag, self).put_ObjectID(pVal)
    def get_PercentAlong(self):
        '''Method ISMFlag.get_PercentAlong

           OUTPUT
            pVal                : float*'''
        return super(ISMFlag, self).get_PercentAlong()
    def put_PercentAlong(self, pVal):
        '''Method ISMFlag.put_PercentAlong

           INPUT
            pVal                : float'''
        return super(ISMFlag, self).put_PercentAlong(pVal)
    def get_Side(self):
        '''Method ISMFlag.get_Side

           OUTPUT
            pVal                : esriSMStreetSideType*'''
        return super(ISMFlag, self).get_Side()
    def put_Side(self, pVal):
        '''Method ISMFlag.put_Side

           INPUT
            pVal                : esriSMStreetSideType'''
        return super(ISMFlag, self).put_Side(pVal)
    def get_StreetPoint(self):
        '''Method ISMFlag.get_StreetPoint

           OUTPUT
            pVal                : ISMRouterPoint**'''
        return super(ISMFlag, self).get_StreetPoint()
    def put_StreetPoint(self, pVal):
        '''Method ISMFlag.put_StreetPoint

           INPUT
            pVal                : ISMRouterPoint*'''
        return super(ISMFlag, self).put_StreetPoint(pVal)
    ObjectID = property(get_ObjectID, put_ObjectID, None)
    PercentAlong = property(get_PercentAlong, put_PercentAlong, None)
    Side = property(get_Side, put_Side, None)
    StreetPoint = property(get_StreetPoint, put_StreetPoint, None)

class ISMFlagCreator(_esriDataSourcesFile.ISMFlagCreator):
    _IID = uuid.UUID('8a4bb863-0c3f-4897-aa09-1479a4b76a6f')
    def CreateFlag(self, pPoint):
        '''Method ISMFlagCreator.CreateFlag

           INPUT
            pPoint              : ISMRouterPoint*

           OUTPUT
            pIFlag              : ISMFlag**'''
        return super(ISMFlagCreator, self).CreateFlag(pPoint)
    def CreateFlagDirection(self, pPoint, dOrientation, dTolerance):
        '''Method ISMFlagCreator.CreateFlagDirection

           INPUTS
            pPoint              : ISMRouterPoint*
            dOrientation        : double
            dTolerance          : double

           OUTPUTS
            pdAdjustedOrientation: double*
            ppFlag              : ISMFlag**'''
        return super(ISMFlagCreator, self).CreateFlagDirection(pPoint, dOrientation, dTolerance)
    def CreateFlagDirectionAdv(self, pPoint, dOrientation, dTolerance, dSpeed, dLatency):
        '''Method ISMFlagCreator.CreateFlagDirectionAdv

           INPUTS
            pPoint              : ISMRouterPoint*
            dOrientation        : double
            dTolerance          : double
            dSpeed              : double
            dLatency            : double

           OUTPUTS
            pdAdjustedOrientation: double*
            ppFlag              : ISMFlag**'''
        return super(ISMFlagCreator, self).CreateFlagDirectionAdv(pPoint, dOrientation, dTolerance, dSpeed, dLatency)

class ISMFlagCreator2(_esriDataSourcesFile.ISMFlagCreator2):
    _IID = uuid.UUID('0e8f6257-745f-4de3-b651-6ecf14728c5c')

    def __init__(self, *args, **kw):
        super(ISMFlagCreator2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_SearchTolerance(self):
        '''Method ISMFlagCreator2.get_SearchTolerance

           OUTPUT
            pVal                : double*'''
        return super(ISMFlagCreator2, self).get_SearchTolerance()
    def put_SearchTolerance(self, pVal):
        '''Method ISMFlagCreator2.put_SearchTolerance

           INPUT
            pVal                : double'''
        return super(ISMFlagCreator2, self).put_SearchTolerance(pVal)
    def CreateFlag(self, pPoint):
        '''Method ISMFlagCreator.CreateFlag (from ISMFlagCreator)

           INPUT
            pPoint              : ISMRouterPoint*

           OUTPUT
            pIFlag              : ISMFlag**'''
        return super(ISMFlagCreator2, self).CreateFlag(pPoint)
    def CreateFlagDirection(self, pPoint, dOrientation, dTolerance):
        '''Method ISMFlagCreator.CreateFlagDirection (from ISMFlagCreator)

           INPUTS
            pPoint              : ISMRouterPoint*
            dOrientation        : double
            dTolerance          : double

           OUTPUTS
            pdAdjustedOrientation: double*
            ppFlag              : ISMFlag**'''
        return super(ISMFlagCreator2, self).CreateFlagDirection(pPoint, dOrientation, dTolerance)
    def CreateFlagDirectionAdv(self, pPoint, dOrientation, dTolerance, dSpeed, dLatency):
        '''Method ISMFlagCreator.CreateFlagDirectionAdv (from ISMFlagCreator)

           INPUTS
            pPoint              : ISMRouterPoint*
            dOrientation        : double
            dTolerance          : double
            dSpeed              : double
            dLatency            : double

           OUTPUTS
            pdAdjustedOrientation: double*
            ppFlag              : ISMFlag**'''
        return super(ISMFlagCreator2, self).CreateFlagDirectionAdv(pPoint, dOrientation, dTolerance, dSpeed, dLatency)
    SearchTolerance = property(get_SearchTolerance, put_SearchTolerance, None)

class ISMStop(_esriDataSourcesFile.ISMStop):
    _IID = uuid.UUID('f8b66014-5850-11d7-b321-008048db11de')

    def __init__(self, *args, **kw):
        super(ISMStop, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_StopID(self):
        '''Method ISMStop.get_StopID

           OUTPUT
            pVal                : long*'''
        return super(ISMStop, self).get_StopID()
    def put_StopID(self, pVal):
        '''Method ISMStop.put_StopID

           INPUT
            pVal                : long'''
        return super(ISMStop, self).put_StopID(pVal)
    def get_Description(self):
        '''Method ISMStop.get_Description

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMStop, self).get_Description()
    def put_Description(self, pVal):
        '''Method ISMStop.put_Description

           INPUT
            pVal                : BSTR'''
        return super(ISMStop, self).put_Description(pVal)
    def get_Flag(self):
        '''Method ISMStop.get_Flag

           OUTPUT
            pVal                : ISMFlag**'''
        return super(ISMStop, self).get_Flag()
    def put_Flag(self, pVal):
        '''Method ISMStop.put_Flag

           INPUT
            pVal                : ISMFlag*'''
        return super(ISMStop, self).put_Flag(pVal)
    def get_Duration(self):
        '''Method ISMStop.get_Duration

           OUTPUT
            pVal                : short*'''
        return super(ISMStop, self).get_Duration()
    def put_Duration(self, pVal):
        '''Method ISMStop.put_Duration

           INPUT
            pVal                : short'''
        return super(ISMStop, self).put_Duration(pVal)
    def get_MinDistanceToTurn(self):
        '''Method ISMStop.get_MinDistanceToTurn

           OUTPUT
            pdDist              : double*'''
        return super(ISMStop, self).get_MinDistanceToTurn()
    def put_MinDistanceToTurn(self, pdDist):
        '''Method ISMStop.put_MinDistanceToTurn

           INPUT
            pdDist              : double'''
        return super(ISMStop, self).put_MinDistanceToTurn(pdDist)
    def get_EnforceSideOfStreet(self):
        '''Method ISMStop.get_EnforceSideOfStreet

           OUTPUT
            pbESS               : VARIANT_BOOL*'''
        return super(ISMStop, self).get_EnforceSideOfStreet()
    def put_EnforceSideOfStreet(self, pbESS):
        '''Method ISMStop.put_EnforceSideOfStreet

           INPUT
            pbESS               : VARIANT_BOOL'''
        return super(ISMStop, self).put_EnforceSideOfStreet(pbESS)
    Description = property(get_Description, put_Description, None)
    Duration = property(get_Duration, put_Duration, None)
    EnforceSideOfStreet = property(get_EnforceSideOfStreet, put_EnforceSideOfStreet, None)
    Flag = property(get_Flag, put_Flag, None)
    MinDistanceToTurn = property(get_MinDistanceToTurn, put_MinDistanceToTurn, None)
    StopID = property(get_StopID, put_StopID, None)

class ISMStopsCollection(_esriDataSourcesFile.ISMStopsCollection):
    _IID = uuid.UUID('f8b66017-5850-11d7-b321-008048db11de')
    def get_Count(self):
        '''Method ISMStopsCollection.get_Count

           OUTPUT
            pVal                : long*'''
        return super(ISMStopsCollection, self).get_Count()
    def get_Item(self, Position):
        '''Method ISMStopsCollection.get_Item

           INPUT
            Position            : long

           OUTPUT
            pVal                : ISMStop**'''
        return super(ISMStopsCollection, self).get_Item(Position)
    def Add(self, pItem):
        '''Method ISMStopsCollection.Add

           INPUT
            pItem               : ISMStop*'''
        return super(ISMStopsCollection, self).Add(pItem)
    def Insert(self, Position, pItem):
        '''Method ISMStopsCollection.Insert

           INPUTS
            Position            : long
            pItem               : ISMStop*'''
        return super(ISMStopsCollection, self).Insert(Position, pItem)
    def Remove(self, Position):
        '''Method ISMStopsCollection.Remove

           INPUT
            Position            : long'''
        return super(ISMStopsCollection, self).Remove(Position)
    def Clear(self):
        '''Method ISMStopsCollection.Clear'''
        return super(ISMStopsCollection, self).Clear()
    Count = property(get_Count, None, None)
    Item = IndexProperty(get_Item, None)

class ISMDirItem(_esriDataSourcesFile.ISMDirItem):
    _IID = uuid.UUID('f8b6601a-5850-11d7-b321-008048db11de')
    def get_Text(self):
        '''Method ISMDirItem.get_Text

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMDirItem, self).get_Text()
    def get_Length(self):
        '''Method ISMDirItem.get_Length

           OUTPUT
            pVal                : double*'''
        return super(ISMDirItem, self).get_Length()
    def get_Time(self):
        '''Method ISMDirItem.get_Time

           OUTPUT
            pVal                : double*'''
        return super(ISMDirItem, self).get_Time()
    def get_DriveText(self):
        '''Method ISMDirItem.get_DriveText

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMDirItem, self).get_DriveText()
    def get_ItemType(self):
        '''Method ISMDirItem.get_ItemType

           OUTPUT
            pVal                : esriSMDirItemType*'''
        return super(ISMDirItem, self).get_ItemType()
    def get_RoutePart(self):
        '''Method ISMDirItem.get_RoutePart

           OUTPUT
            pVal                : long*'''
        return super(ISMDirItem, self).get_RoutePart()
    def get_Shape(self):
        '''Method ISMDirItem.get_Shape

           OUTPUT
            pVal                : ISMPointsCollection**'''
        return super(ISMDirItem, self).get_Shape()
    def get_BoundBox(self):
        '''Method ISMDirItem.get_BoundBox

           OUTPUT
            pVal                : ISMRouterEnvelope**'''
        return super(ISMDirItem, self).get_BoundBox()
    def get_StreetName(self):
        '''Method ISMDirItem.get_StreetName

           OUTPUT
            pbstrStreetName     : BSTR*'''
        return super(ISMDirItem, self).get_StreetName()
    def get_TurnAngle(self):
        '''Method ISMDirItem.get_TurnAngle

           OUTPUT
            pdAngle             : double*'''
        return super(ISMDirItem, self).get_TurnAngle()
    def get_Azimuth(self):
        '''Method ISMDirItem.get_Azimuth

           OUTPUT
            pAzimuth            : esriSMAzimuthType*'''
        return super(ISMDirItem, self).get_Azimuth()
    Azimuth = property(get_Azimuth, None, None)
    BoundBox = property(get_BoundBox, None, None)
    DriveText = property(get_DriveText, None, None)
    ItemType = property(get_ItemType, None, None)
    Length = property(get_Length, None, None)
    RoutePart = property(get_RoutePart, None, None)
    Shape = property(get_Shape, None, None)
    StreetName = property(get_StreetName, None, None)
    Text = property(get_Text, None, None)
    Time = property(get_Time, None, None)
    TurnAngle = property(get_TurnAngle, None, None)

class ISMDirections(_esriDataSourcesFile.ISMDirections):
    _IID = uuid.UUID('f8b6601d-5850-11d7-b321-008048db11de')
    def get_TotalLength(self):
        '''Method ISMDirections.get_TotalLength

           OUTPUT
            pVal                : double*'''
        return super(ISMDirections, self).get_TotalLength()
    def get_TotalTime(self):
        '''Method ISMDirections.get_TotalTime

           OUTPUT
            pVal                : DATE*'''
        return super(ISMDirections, self).get_TotalTime()
    def get_TotalDrivingTime(self):
        '''Method ISMDirections.get_TotalDrivingTime

           OUTPUT
            pVal                : DATE*'''
        return super(ISMDirections, self).get_TotalDrivingTime()
    def get_TotalsText(self):
        '''Method ISMDirections.get_TotalsText

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMDirections, self).get_TotalsText()
    def get_BoundBox(self):
        '''Method ISMDirections.get_BoundBox

           OUTPUT
            pVal                : ISMRouterEnvelope**'''
        return super(ISMDirections, self).get_BoundBox()
    def get_Count(self):
        '''Method ISMDirections.get_Count

           OUTPUT
            pVal                : long*'''
        return super(ISMDirections, self).get_Count()
    def get_Item(self, Position):
        '''Method ISMDirections.get_Item

           INPUT
            Position            : long

           OUTPUT
            pVal                : ISMDirItem**'''
        return super(ISMDirections, self).get_Item(Position)
    BoundBox = property(get_BoundBox, None, None)
    Count = property(get_Count, None, None)
    TotalDrivingTime = property(get_TotalDrivingTime, None, None)
    TotalLength = property(get_TotalLength, None, None)
    TotalTime = property(get_TotalTime, None, None)
    TotalsText = property(get_TotalsText, None, None)
    Item = IndexProperty(get_Item, None)

class ISMBreakTracker(_esriDataSourcesFile.ISMBreakTracker):
    _IID = uuid.UUID('122fc3ae-a421-4922-9459-dff9d3631333')
    def Continue(self):
        '''Method ISMBreakTracker.Continue

           OUTPUT
            bKeepGoing          : VARIANT_BOOL*'''
        return super(ISMBreakTracker, self).Continue()

class ISMNetAttributesAccess(_esriDataSourcesFile.ISMNetAttributesAccess):
    _IID = uuid.UUID('198dc955-519b-41ec-af33-1090d356c674')
    def GetNetAttributeValue(self, bstrAttrName, lObjectID):
        '''Method ISMNetAttributesAccess.GetNetAttributeValue

           INPUTS
            bstrAttrName        : BSTR
            lObjectID           : long

           OUTPUT
            pvtVal              : VARIANT*'''
        return super(ISMNetAttributesAccess, self).GetNetAttributeValue(bstrAttrName, lObjectID)

class ISMRouter(_esriDataSourcesFile.ISMRouter):
    _IID = uuid.UUID('f8b66020-5850-11d7-b321-008048db11de')

    def __init__(self, *args, **kw):
        super(ISMRouter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Barriers(self):
        '''Method ISMRouter.get_Barriers

           OUTPUT
            pVal                : ISMNetBarriersCollection**'''
        return super(ISMRouter, self).get_Barriers()
    def get_NetAttributes(self):
        '''Method ISMRouter.get_NetAttributes

           OUTPUT
            pVal                : ISMNetAttributesCollection**'''
        return super(ISMRouter, self).get_NetAttributes()
    def get_Preferences(self):
        '''Method ISMRouter.get_Preferences

           OUTPUT
            pVal                : ISMRoadPreferences**'''
        return super(ISMRouter, self).get_Preferences()
    def get_SpeedGroups(self):
        '''Method ISMRouter.get_SpeedGroups

           OUTPUT
            pVal                : ISMSpeedGroups**'''
        return super(ISMRouter, self).get_SpeedGroups()
    def get_TripPlanSettings(self):
        '''Method ISMRouter.get_TripPlanSettings

           OUTPUT
            pVal                : ISMTripPlanSettings**'''
        return super(ISMRouter, self).get_TripPlanSettings()
    def get_NetAttributeName(self):
        '''Method ISMRouter.get_NetAttributeName

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMRouter, self).get_NetAttributeName()
    def put_NetAttributeName(self, pVal):
        '''Method ISMRouter.put_NetAttributeName

           INPUT
            pVal                : BSTR'''
        return super(ISMRouter, self).put_NetAttributeName(pVal)
    def ReorderStops(self, pISrcStops):
        '''Method ISMRouter.ReorderStops

           INPUT
            pISrcStops          : ISMStopsCollection*

           OUTPUT
            pIResStops          : ISMStopsCollection**'''
        return super(ISMRouter, self).ReorderStops(pISrcStops)
    def Solve(self, pIStops, pITracker):
        '''Method ISMRouter.Solve

           INPUTS
            pIStops             : ISMStopsCollection*
            pITracker           : ISMBreakTracker*

           OUTPUT
            pIDirections        : ISMDirections**'''
        return super(ISMRouter, self).Solve(pIStops, pITracker)
    def get_NetAttributesAccess(self):
        '''Method ISMRouter.get_NetAttributesAccess

           OUTPUT
            ppNetAttrAccess     : ISMNetAttributesAccess**'''
        return super(ISMRouter, self).get_NetAttributesAccess()
    def get_ProjectionString(self):
        '''Method ISMRouter.get_ProjectionString

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMRouter, self).get_ProjectionString()
    def get_FlagCreator(self):
        '''Method ISMRouter.get_FlagCreator

           OUTPUT
            pVal                : ISMFlagCreator**'''
        return super(ISMRouter, self).get_FlagCreator()
    Barriers = property(get_Barriers, None, None)
    FlagCreator = property(get_FlagCreator, None, None)
    NetAttributeName = property(get_NetAttributeName, put_NetAttributeName, None)
    NetAttributes = property(get_NetAttributes, None, None)
    NetAttributesAccess = property(get_NetAttributesAccess, None, None)
    Preferences = property(get_Preferences, None, None)
    ProjectionString = property(get_ProjectionString, None, None)
    SpeedGroups = property(get_SpeedGroups, None, None)
    TripPlanSettings = property(get_TripPlanSettings, None, None)

class ISMRouterFactory(_esriDataSourcesFile.ISMRouterFactory):
    _IID = uuid.UUID('f8b66023-5850-11d7-b321-008048db11de')
    def CreateRouter(self, RoutingFilePath):
        '''Method ISMRouterFactory.CreateRouter

           INPUT
            RoutingFilePath     : BSTR

           OUTPUT
            pIRouter            : ISMRouter**'''
        return super(ISMRouterFactory, self).CreateRouter(RoutingFilePath)
    def CreateRouterCfg(self, RoutingFilePath, ConfigPath):
        '''Method ISMRouterFactory.CreateRouterCfg

           INPUTS
            RoutingFilePath     : BSTR
            ConfigPath          : BSTR

           OUTPUT
            pIRouter            : ISMRouter**'''
        return super(ISMRouterFactory, self).CreateRouterCfg(RoutingFilePath, ConfigPath)

class ISMRoutingMetaData(_esriDataSourcesFile.ISMRoutingMetaData):
    _IID = uuid.UUID('c8128b1a-23c3-4e21-93eb-50739b68f17a')
    def get_Vendor(self):
        '''Method ISMRoutingMetaData.get_Vendor

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMRoutingMetaData, self).get_Vendor()
    def get_ProductName(self):
        '''Method ISMRoutingMetaData.get_ProductName

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMRoutingMetaData, self).get_ProductName()
    def get_ProductVersion(self):
        '''Method ISMRoutingMetaData.get_ProductVersion

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMRoutingMetaData, self).get_ProductVersion()
    def get_Geography(self):
        '''Method ISMRoutingMetaData.get_Geography

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMRoutingMetaData, self).get_Geography()
    def get_Description(self):
        '''Method ISMRoutingMetaData.get_Description

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMRoutingMetaData, self).get_Description()
    def get_Time(self):
        '''Method ISMRoutingMetaData.get_Time

           OUTPUT
            pVal                : BSTR*'''
        return super(ISMRoutingMetaData, self).get_Time()
    Description = property(get_Description, None, None)
    Geography = property(get_Geography, None, None)
    ProductName = property(get_ProductName, None, None)
    ProductVersion = property(get_ProductVersion, None, None)
    Time = property(get_Time, None, None)
    Vendor = property(get_Vendor, None, None)

class ISMRestriction(_esriDataSourcesFile.ISMRestriction):
    _IID = uuid.UUID('3df8d708-18e9-4d3c-bc69-54190a3577d8')

    def __init__(self, *args, **kw):
        super(ISMRestriction, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Attribute(self):
        '''Method ISMRestriction.get_Attribute

           OUTPUT
            pAttr               : ISMNetAttribute**'''
        return super(ISMRestriction, self).get_Attribute()
    def putref_Attribute(self, pAttr):
        '''Method ISMRestriction.putref_Attribute

           INPUT
            pAttr               : ISMNetAttribute*'''
        return super(ISMRestriction, self).putref_Attribute(pAttr)
    def get_Type(self):
        '''Method ISMRestriction.get_Type

           OUTPUT
            pVal                : esriSMRestrictionType*'''
        return super(ISMRestriction, self).get_Type()
    def put_Type(self, pVal):
        '''Method ISMRestriction.put_Type

           INPUT
            pVal                : esriSMRestrictionType'''
        return super(ISMRestriction, self).put_Type(pVal)
    def get_Param(self):
        '''Method ISMRestriction.get_Param

           OUTPUT
            pvParam             : VARIANT*'''
        return super(ISMRestriction, self).get_Param()
    def put_Param(self, pvParam):
        '''Method ISMRestriction.put_Param

           INPUT
            pvParam             : VARIANT'''
        return super(ISMRestriction, self).put_Param(pvParam)
    Attribute = property(get_Attribute, putref_Attribute, None)
    Param = property(get_Param, put_Param, None)
    Type = property(get_Type, put_Type, None)

class ISMRouterSetup(_esriDataSourcesFile.ISMRouterSetup):
    _IID = uuid.UUID('a386707f-fb42-4d0e-af12-3c1feb26f771')

    def __init__(self, *args, **kw):
        super(ISMRouterSetup, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def SetRestriction(self, pRestriction):
        '''Method ISMRouterSetup.SetRestriction

           INPUT
            pRestriction        : ISMRestriction*'''
        return super(ISMRouterSetup, self).SetRestriction(pRestriction)
    def ClearAllRestrictions(self):
        '''Method ISMRouterSetup.ClearAllRestrictions'''
        return super(ISMRouterSetup, self).ClearAllRestrictions()
    def get_BacktrackPolicy(self):
        '''Method ISMRouterSetup.get_BacktrackPolicy

           OUTPUT
            pVal                : esriSMBacktrackPolicy*'''
        return super(ISMRouterSetup, self).get_BacktrackPolicy()
    def put_BacktrackPolicy(self, pVal):
        '''Method ISMRouterSetup.put_BacktrackPolicy

           INPUT
            pVal                : esriSMBacktrackPolicy'''
        return super(ISMRouterSetup, self).put_BacktrackPolicy(pVal)
    def get_DirectionsLengthUnits(self):
        '''Method ISMRouterSetup.get_DirectionsLengthUnits

           OUTPUT
            pVal                : esriSMDirectionsLengthUnits*'''
        return super(ISMRouterSetup, self).get_DirectionsLengthUnits()
    def put_DirectionsLengthUnits(self, pVal):
        '''Method ISMRouterSetup.put_DirectionsLengthUnits

           INPUT
            pVal                : esriSMDirectionsLengthUnits'''
        return super(ISMRouterSetup, self).put_DirectionsLengthUnits(pVal)
    BacktrackPolicy = property(get_BacktrackPolicy, put_BacktrackPolicy, None)
    DirectionsLengthUnits = property(get_DirectionsLengthUnits, put_DirectionsLengthUnits, None)

class ISMRouterSetup2(_esriDataSourcesFile.ISMRouterSetup2):
    _IID = uuid.UUID('06efa9d2-490c-4325-bf15-3f73f4492f34')

    def __init__(self, *args, **kw):
        super(ISMRouterSetup2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_RestrictionCount(self):
        '''Method ISMRouterSetup2.get_RestrictionCount

           OUTPUT
            pVal                : long*'''
        return super(ISMRouterSetup2, self).get_RestrictionCount()
    def get_Restriction(self, index):
        '''Method ISMRouterSetup2.get_Restriction

           INPUT
            index               : long

           OUTPUT
            pVal                : ISMRestriction**'''
        return super(ISMRouterSetup2, self).get_Restriction(index)
    def ClearRestriction(self, index):
        '''Method ISMRouterSetup2.ClearRestriction

           INPUT
            index               : long'''
        return super(ISMRouterSetup2, self).ClearRestriction(index)
    def SetRestriction(self, pRestriction):
        '''Method ISMRouterSetup.SetRestriction (from ISMRouterSetup)

           INPUT
            pRestriction        : ISMRestriction*'''
        return super(ISMRouterSetup2, self).SetRestriction(pRestriction)
    def ClearAllRestrictions(self):
        '''Method ISMRouterSetup.ClearAllRestrictions (from ISMRouterSetup)'''
        return super(ISMRouterSetup2, self).ClearAllRestrictions()
    def get_BacktrackPolicy(self):
        '''Method ISMRouterSetup.get_BacktrackPolicy (from ISMRouterSetup)

           OUTPUT
            pVal                : esriSMBacktrackPolicy*'''
        return super(ISMRouterSetup2, self).get_BacktrackPolicy()
    def put_BacktrackPolicy(self, pVal):
        '''Method ISMRouterSetup.put_BacktrackPolicy (from ISMRouterSetup)

           INPUT
            pVal                : esriSMBacktrackPolicy'''
        return super(ISMRouterSetup2, self).put_BacktrackPolicy(pVal)
    def get_DirectionsLengthUnits(self):
        '''Method ISMRouterSetup.get_DirectionsLengthUnits (from ISMRouterSetup)

           OUTPUT
            pVal                : esriSMDirectionsLengthUnits*'''
        return super(ISMRouterSetup2, self).get_DirectionsLengthUnits()
    def put_DirectionsLengthUnits(self, pVal):
        '''Method ISMRouterSetup.put_DirectionsLengthUnits (from ISMRouterSetup)

           INPUT
            pVal                : esriSMDirectionsLengthUnits'''
        return super(ISMRouterSetup2, self).put_DirectionsLengthUnits(pVal)
    BacktrackPolicy = property(get_BacktrackPolicy, put_BacktrackPolicy, None)
    DirectionsLengthUnits = property(get_DirectionsLengthUnits, put_DirectionsLengthUnits, None)
    RestrictionCount = property(get_RestrictionCount, None, None)
    Restriction = IndexProperty(get_Restriction, None)

class IUsageModeOption(_esriDataSourcesFile.IUsageModeOption):
    _IID = uuid.UUID('c1d85fc8-f132-4187-b897-623c647c9213')
    def get_Name(self):
        '''Method IUsageModeOption.get_Name

           OUTPUT
            psName              : BSTR*'''
        return super(IUsageModeOption, self).get_Name()
    def get_Value(self):
        '''Method IUsageModeOption.get_Value

           OUTPUT
            psValue             : BSTR*'''
        return super(IUsageModeOption, self).get_Value()
    Name = property(get_Name, None, None)
    Value = property(get_Value, None, None)

class IUsageModeInfo(_esriDataSourcesFile.IUsageModeInfo):
    _IID = uuid.UUID('07713846-9da7-45f8-886f-3eb2f0a30187')
    def get_Name(self):
        '''Method IUsageModeInfo.get_Name

           OUTPUT
            psName              : BSTR*'''
        return super(IUsageModeInfo, self).get_Name()
    def get_OptionCount(self):
        '''Method IUsageModeInfo.get_OptionCount

           OUTPUT
            pnCount             : long*'''
        return super(IUsageModeInfo, self).get_OptionCount()
    def get_Option(self, nIndex):
        '''Method IUsageModeInfo.get_Option

           INPUT
            nIndex              : long

           OUTPUT
            pOption             : IUsageModeOption**'''
        return super(IUsageModeInfo, self).get_Option(nIndex)
    Name = property(get_Name, None, None)
    OptionCount = property(get_OptionCount, None, None)
    Option = IndexProperty(get_Option, None)

class IMetaInfo(_esriDataSourcesFile.IMetaInfo):
    _IID = uuid.UUID('0db7a450-5fed-441b-bb3a-db6e24d6cda3')
    def get_Name(self):
        '''Method IMetaInfo.get_Name

           OUTPUT
            psName              : BSTR*'''
        return super(IMetaInfo, self).get_Name()
    def get_Value(self):
        '''Method IMetaInfo.get_Value

           OUTPUT
            psValue             : BSTR*'''
        return super(IMetaInfo, self).get_Value()
    Name = property(get_Name, None, None)
    Value = property(get_Value, None, None)

class IDataLicenseInfo(_esriDataSourcesFile.IDataLicenseInfo):
    _IID = uuid.UUID('37474491-1c04-4669-99b5-825cf67294c5')
    def get_DataProductName(self):
        '''Method IDataLicenseInfo.get_DataProductName

           OUTPUT
            pVal                : BSTR*'''
        return super(IDataLicenseInfo, self).get_DataProductName()
    def get_ApplicationsCount(self):
        '''Method IDataLicenseInfo.get_ApplicationsCount

           OUTPUT
            pVal                : long*'''
        return super(IDataLicenseInfo, self).get_ApplicationsCount()
    def get_ApplicationName(self, nIdx):
        '''Method IDataLicenseInfo.get_ApplicationName

           INPUT
            nIdx                : long

           OUTPUT
            pVal                : BSTR*'''
        return super(IDataLicenseInfo, self).get_ApplicationName(nIdx)
    def get_AttrCroupsCount(self):
        '''Method IDataLicenseInfo.get_AttrCroupsCount

           OUTPUT
            pVal                : long*'''
        return super(IDataLicenseInfo, self).get_AttrCroupsCount()
    def get_AttrGroupName(self, nIdx):
        '''Method IDataLicenseInfo.get_AttrGroupName

           INPUT
            nIdx                : long

           OUTPUT
            pVal                : BSTR*'''
        return super(IDataLicenseInfo, self).get_AttrGroupName(nIdx)
    def get_GeographiesCount(self):
        '''Method IDataLicenseInfo.get_GeographiesCount

           OUTPUT
            pVal                : long*'''
        return super(IDataLicenseInfo, self).get_GeographiesCount()
    def get_GeographyName(self, nIdx):
        '''Method IDataLicenseInfo.get_GeographyName

           INPUT
            nIdx                : long

           OUTPUT
            pVal                : BSTR*'''
        return super(IDataLicenseInfo, self).get_GeographyName(nIdx)
    def get_MetaCount(self):
        '''Method IDataLicenseInfo.get_MetaCount

           OUTPUT
            pVal                : long*'''
        return super(IDataLicenseInfo, self).get_MetaCount()
    def get_MetaInfo(self, nIdx):
        '''Method IDataLicenseInfo.get_MetaInfo

           INPUT
            nIdx                : long

           OUTPUT
            ppMeta              : IMetaInfo**'''
        return super(IDataLicenseInfo, self).get_MetaInfo(nIdx)
    def get_LayerCroupsCount(self):
        '''Method IDataLicenseInfo.get_LayerCroupsCount

           OUTPUT
            pVal                : long*'''
        return super(IDataLicenseInfo, self).get_LayerCroupsCount()
    def get_LayerGroupName(self, nIdx):
        '''Method IDataLicenseInfo.get_LayerGroupName

           INPUT
            nIdx                : long

           OUTPUT
            pVal                : BSTR*'''
        return super(IDataLicenseInfo, self).get_LayerGroupName(nIdx)
    def get_LicenseID(self):
        '''Method IDataLicenseInfo.get_LicenseID

           OUTPUT
            pVal                : GUID*'''
        return super(IDataLicenseInfo, self).get_LicenseID()
    def get_Expiration(self):
        '''Method IDataLicenseInfo.get_Expiration

           OUTPUT
            pvtDate             : VARIANT*'''
        return super(IDataLicenseInfo, self).get_Expiration()
    def get_LicenseType(self):
        '''Method IDataLicenseInfo.get_LicenseType

           OUTPUT
            pVal                : esriDataLicenseType*'''
        return super(IDataLicenseInfo, self).get_LicenseType()
    def get_MaxConnections(self):
        '''Method IDataLicenseInfo.get_MaxConnections

           OUTPUT
            pVal                : long*'''
        return super(IDataLicenseInfo, self).get_MaxConnections()
    def get_AvailableConnections(self):
        '''Method IDataLicenseInfo.get_AvailableConnections

           OUTPUT
            pVal                : long*'''
        return super(IDataLicenseInfo, self).get_AvailableConnections()
    def get_UsageModeCount(self):
        '''Method IDataLicenseInfo.get_UsageModeCount

           OUTPUT
            pnCount             : long*'''
        return super(IDataLicenseInfo, self).get_UsageModeCount()
    def get_UsageMode(self, nIndex):
        '''Method IDataLicenseInfo.get_UsageMode

           INPUT
            nIndex              : long

           OUTPUT
            pInfo               : IUsageModeInfo**'''
        return super(IDataLicenseInfo, self).get_UsageMode(nIndex)
    ApplicationsCount = property(get_ApplicationsCount, None, None)
    AttrCroupsCount = property(get_AttrCroupsCount, None, None)
    AvailableConnections = property(get_AvailableConnections, None, None)
    DataProductName = property(get_DataProductName, None, None)
    Expiration = property(get_Expiration, None, None)
    GeographiesCount = property(get_GeographiesCount, None, None)
    LayerCroupsCount = property(get_LayerCroupsCount, None, None)
    LicenseID = property(get_LicenseID, None, None)
    LicenseType = property(get_LicenseType, None, None)
    MaxConnections = property(get_MaxConnections, None, None)
    MetaCount = property(get_MetaCount, None, None)
    UsageModeCount = property(get_UsageModeCount, None, None)
    ApplicationName = IndexProperty(get_ApplicationName, None)
    AttrGroupName = IndexProperty(get_AttrGroupName, None)
    GeographyName = IndexProperty(get_GeographyName, None)
    LayerGroupName = IndexProperty(get_LayerGroupName, None)
    MetaInfo = IndexProperty(get_MetaInfo, None)
    UsageMode = IndexProperty(get_UsageMode, None)

class IDataLicenseManager(_esriDataSourcesFile.IDataLicenseManager):
    _IID = uuid.UUID('2d5b7a40-f25b-4490-b36c-edd367df33d0')
    def get_Count(self):
        '''Method IDataLicenseManager.get_Count

           OUTPUT
            pVal                : long*'''
        return super(IDataLicenseManager, self).get_Count()
    def GetLicenseInfo(self, nIdx):
        '''Method IDataLicenseManager.GetLicenseInfo

           INPUT
            nIdx                : long

           OUTPUT
            pLicInfo            : IDataLicenseInfo**'''
        return super(IDataLicenseManager, self).GetLicenseInfo(nIdx)
    def AddLicenseFromFile(self, bstrLicenseFileName):
        '''Method IDataLicenseManager.AddLicenseFromFile

           INPUT
            bstrLicenseFileName : BSTR'''
        return super(IDataLicenseManager, self).AddLicenseFromFile(bstrLicenseFileName)
    def RemoveLicense(self, nIdx):
        '''Method IDataLicenseManager.RemoveLicense

           INPUT
            nIdx                : long'''
        return super(IDataLicenseManager, self).RemoveLicense(nIdx)
    def GetLicenseInfoFromFile(self, bstrLicenseFileName):
        '''Method IDataLicenseManager.GetLicenseInfoFromFile

           INPUT
            bstrLicenseFileName : BSTR

           OUTPUT
            pLicInfo            : IDataLicenseInfo**'''
        return super(IDataLicenseManager, self).GetLicenseInfoFromFile(bstrLicenseFileName)
    Count = property(get_Count, None, None)

class IDECadDrawingDataset(_esriDataSourcesFile.IDECadDrawingDataset):
    _IID = uuid.UUID('6ec9d0c5-c3c5-4a2c-b9b3-5959209f427c')

    def __init__(self, *args, **kw):
        super(IDECadDrawingDataset, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Is2d(self):
        '''Method IDECadDrawingDataset.get_Is2d

           OUTPUT
            Is2d                : VARIANT_BOOL*'''
        return super(IDECadDrawingDataset, self).get_Is2d()
    def put_Is2d(self, Is2d):
        '''Method IDECadDrawingDataset.put_Is2d

           INPUT
            Is2d                : VARIANT_BOOL'''
        return super(IDECadDrawingDataset, self).put_Is2d(Is2d)
    def get_Is3d(self):
        '''Method IDECadDrawingDataset.get_Is3d

           OUTPUT
            Is3d                : VARIANT_BOOL*'''
        return super(IDECadDrawingDataset, self).get_Is3d()
    def put_Is3d(self, Is3d):
        '''Method IDECadDrawingDataset.put_Is3d

           INPUT
            Is3d                : VARIANT_BOOL'''
        return super(IDECadDrawingDataset, self).put_Is3d(Is3d)
    def get_IsAutoCad(self):
        '''Method IDECadDrawingDataset.get_IsAutoCad

           OUTPUT
            IsAutoCad           : VARIANT_BOOL*'''
        return super(IDECadDrawingDataset, self).get_IsAutoCad()
    def put_IsAutoCad(self, IsAutoCad):
        '''Method IDECadDrawingDataset.put_IsAutoCad

           INPUT
            IsAutoCad           : VARIANT_BOOL'''
        return super(IDECadDrawingDataset, self).put_IsAutoCad(IsAutoCad)
    def get_IsDgn(self):
        '''Method IDECadDrawingDataset.get_IsDgn

           OUTPUT
            IsDgn               : VARIANT_BOOL*'''
        return super(IDECadDrawingDataset, self).get_IsDgn()
    def put_IsDgn(self, IsDgn):
        '''Method IDECadDrawingDataset.put_IsDgn

           INPUT
            IsDgn               : VARIANT_BOOL'''
        return super(IDECadDrawingDataset, self).put_IsDgn(IsDgn)
    Is2d = property(get_Is2d, put_Is2d, None)
    Is3d = property(get_Is3d, put_Is3d, None)
    IsAutoCad = property(get_IsAutoCad, put_IsAutoCad, None)
    IsDgn = property(get_IsDgn, put_IsDgn, None)

class IGPLayer(_esriDataSourcesFile.IGPLayer):
    _IID = uuid.UUID('ea30b18d-2d75-4593-bf44-b3620f41d8db')

    def __init__(self, *args, **kw):
        super(IGPLayer, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_NameString(self):
        '''Method IGPLayer.get_NameString

           OUTPUT
            pNamestring         : BSTR*'''
        return super(IGPLayer, self).get_NameString()
    def put_NameString(self, pNamestring):
        '''Method IGPLayer.put_NameString

           INPUT
            pNamestring         : BSTR'''
        return super(IGPLayer, self).put_NameString(pNamestring)
    def get_AreaOfInterest(self):
        '''Method IGPLayer.get_AreaOfInterest

           OUTPUT
            ppExtent            : IEnvelope**'''
        return super(IGPLayer, self).get_AreaOfInterest()
    def putref_AreaOfInterest(self, ppExtent):
        '''Method IGPLayer.putref_AreaOfInterest

           INPUT
            ppExtent            : IEnvelope*'''
        return super(IGPLayer, self).putref_AreaOfInterest(ppExtent)
    def SetAOICoords(self, xMin, yMin, xMax, yMax):
        '''Method IGPLayer.SetAOICoords

           INPUTS
            xMin                : double
            yMin                : double
            xMax                : double
            yMax                : double'''
        return super(IGPLayer, self).SetAOICoords(xMin, yMin, xMax, yMax)
    def get_DataElement(self):
        '''Method IGPLayer.get_DataElement

           OUTPUT
            ppDataElement       : IDataElement**'''
        return super(IGPLayer, self).get_DataElement()
    def putref_DataElement(self, ppDataElement):
        '''Method IGPLayer.putref_DataElement

           INPUT
            ppDataElement       : IDataElement*'''
        return super(IGPLayer, self).putref_DataElement(ppDataElement)
    AreaOfInterest = property(get_AreaOfInterest, putref_AreaOfInterest, None)
    DataElement = property(get_DataElement, putref_DataElement, None)
    NameString = property(get_NameString, put_NameString, None)

class IDELayer(_esriDataSourcesFile.IDELayer):
    _IID = uuid.UUID('991993e4-7dfd-4e23-bca0-689b174e3030')

    def __init__(self, *args, **kw):
        super(IDELayer, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_GPLayer(self):
        '''Method IDELayer.get_GPLayer

           OUTPUT
            ppLayer             : IGPLayer**'''
        return super(IDELayer, self).get_GPLayer()
    def putref_GPLayer(self, ppLayer):
        '''Method IDELayer.putref_GPLayer

           INPUT
            ppLayer             : IGPLayer*'''
        return super(IDELayer, self).putref_GPLayer(ppLayer)
    GPLayer = property(get_GPLayer, putref_GPLayer, None)

class IDEPrjFile(_esriDataSourcesFile.IDEPrjFile):
    _IID = uuid.UUID('f69ca920-cfbb-11d5-933d-0080c71a3226')

    def __init__(self, *args, **kw):
        super(IDEPrjFile, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_SpatialReference(self):
        '''Method IDEPrjFile.get_SpatialReference

           OUTPUT
            ppSpatialReference  : ISpatialReference**'''
        return super(IDEPrjFile, self).get_SpatialReference()
    def putref_SpatialReference(self, ppSpatialReference):
        '''Method IDEPrjFile.putref_SpatialReference

           INPUT
            ppSpatialReference  : ISpatialReference*'''
        return super(IDEPrjFile, self).putref_SpatialReference(ppSpatialReference)
    SpatialReference = property(get_SpatialReference, putref_SpatialReference, None)

class IDETin(_esriDataSourcesFile.IDETin):
    _IID = uuid.UUID('b0b62284-0080-4ea3-9716-de5293a73f6e')

    def __init__(self, *args, **kw):
        super(IDETin, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_IsDelaunay(self):
        '''Method IDETin.get_IsDelaunay

           OUTPUT
            pbIsDelaunay        : VARIANT_BOOL*'''
        return super(IDETin, self).get_IsDelaunay()
    def put_IsDelaunay(self, pbIsDelaunay):
        '''Method IDETin.put_IsDelaunay

           INPUT
            pbIsDelaunay        : VARIANT_BOOL'''
        return super(IDETin, self).put_IsDelaunay(pbIsDelaunay)
    def get_ZFactor(self):
        '''Method IDETin.get_ZFactor

           OUTPUT
            pFactor             : double*'''
        return super(IDETin, self).get_ZFactor()
    def put_ZFactor(self, pFactor):
        '''Method IDETin.put_ZFactor

           INPUT
            pFactor             : double'''
        return super(IDETin, self).put_ZFactor(pFactor)
    def get_HasNodeTagValues(self):
        '''Method IDETin.get_HasNodeTagValues

           OUTPUT
            pbHasNodeValues     : VARIANT_BOOL*'''
        return super(IDETin, self).get_HasNodeTagValues()
    def put_HasNodeTagValues(self, pbHasNodeValues):
        '''Method IDETin.put_HasNodeTagValues

           INPUT
            pbHasNodeValues     : VARIANT_BOOL'''
        return super(IDETin, self).put_HasNodeTagValues(pbHasNodeValues)
    def get_HasEdgeTagValues(self):
        '''Method IDETin.get_HasEdgeTagValues

           OUTPUT
            pbHasEdgeValues     : VARIANT_BOOL*'''
        return super(IDETin, self).get_HasEdgeTagValues()
    def put_HasEdgeTagValues(self, pbHasEdgeValues):
        '''Method IDETin.put_HasEdgeTagValues

           INPUT
            pbHasEdgeValues     : VARIANT_BOOL'''
        return super(IDETin, self).put_HasEdgeTagValues(pbHasEdgeValues)
    def get_HasTriangleTagValues(self):
        '''Method IDETin.get_HasTriangleTagValues

           OUTPUT
            pbHasTriangleValues : VARIANT_BOOL*'''
        return super(IDETin, self).get_HasTriangleTagValues()
    def put_HasTriangleTagValues(self, pbHasTriangleValues):
        '''Method IDETin.put_HasTriangleTagValues

           INPUT
            pbHasTriangleValues : VARIANT_BOOL'''
        return super(IDETin, self).put_HasTriangleTagValues(pbHasTriangleValues)
    def get_Fields(self):
        '''Method IDETin.get_Fields

           OUTPUT
            ppFields            : IFields**'''
        return super(IDETin, self).get_Fields()
    def putref_Fields(self, ppFields):
        '''Method IDETin.putref_Fields

           INPUT
            ppFields            : IFields*'''
        return super(IDETin, self).putref_Fields(ppFields)
    Fields = property(get_Fields, putref_Fields, None)
    HasEdgeTagValues = property(get_HasEdgeTagValues, put_HasEdgeTagValues, None)
    HasNodeTagValues = property(get_HasNodeTagValues, put_HasNodeTagValues, None)
    HasTriangleTagValues = property(get_HasTriangleTagValues, put_HasTriangleTagValues, None)
    IsDelaunay = property(get_IsDelaunay, put_IsDelaunay, None)
    ZFactor = property(get_ZFactor, put_ZFactor, None)

class IDELasDataset(_esriDataSourcesFile.IDELasDataset):
    _IID = uuid.UUID('1508d058-f970-487c-afbe-31db1c3ed594')

    def __init__(self, *args, **kw):
        super(IDELasDataset, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_FileCount(self):
        '''Method IDELasDataset.get_FileCount

           OUTPUT
            pFileCount          : long*'''
        return super(IDELasDataset, self).get_FileCount()
    def put_FileCount(self, pFileCount):
        '''Method IDELasDataset.put_FileCount

           INPUT
            pFileCount          : long'''
        return super(IDELasDataset, self).put_FileCount(pFileCount)
    def get_PointCount(self):
        '''Method IDELasDataset.get_PointCount

           OUTPUT
            pPointCount         : long*'''
        return super(IDELasDataset, self).get_PointCount()
    def put_PointCount(self, pPointCount):
        '''Method IDELasDataset.put_PointCount

           INPUT
            pPointCount         : long'''
        return super(IDELasDataset, self).put_PointCount(pPointCount)
    def get_SurfaceConstraintCount(self):
        '''Method IDELasDataset.get_SurfaceConstraintCount

           OUTPUT
            pSurfaceConstraintCount: long*'''
        return super(IDELasDataset, self).get_SurfaceConstraintCount()
    def put_SurfaceConstraintCount(self, pSurfaceConstraintCount):
        '''Method IDELasDataset.put_SurfaceConstraintCount

           INPUT
            pSurfaceConstraintCount: long'''
        return super(IDELasDataset, self).put_SurfaceConstraintCount(pSurfaceConstraintCount)
    def get_HasStatistics(self):
        '''Method IDELasDataset.get_HasStatistics

           OUTPUT
            pbHasStatistics     : VARIANT_BOOL*'''
        return super(IDELasDataset, self).get_HasStatistics()
    def put_HasStatistics(self, pbHasStatistics):
        '''Method IDELasDataset.put_HasStatistics

           INPUT
            pbHasStatistics     : VARIANT_BOOL'''
        return super(IDELasDataset, self).put_HasStatistics(pbHasStatistics)
    def get_NeedsUpdateStatistics(self):
        '''Method IDELasDataset.get_NeedsUpdateStatistics

           OUTPUT
            pbNeedsUpdateStatistics: VARIANT_BOOL*'''
        return super(IDELasDataset, self).get_NeedsUpdateStatistics()
    def put_NeedsUpdateStatistics(self, pbNeedsUpdateStatistics):
        '''Method IDELasDataset.put_NeedsUpdateStatistics

           INPUT
            pbNeedsUpdateStatistics: VARIANT_BOOL'''
        return super(IDELasDataset, self).put_NeedsUpdateStatistics(pbNeedsUpdateStatistics)
    def get_UsesRelativePath(self):
        '''Method IDELasDataset.get_UsesRelativePath

           OUTPUT
            pbUsesRelativePath  : VARIANT_BOOL*'''
        return super(IDELasDataset, self).get_UsesRelativePath()
    def put_UsesRelativePath(self, pbUsesRelativePath):
        '''Method IDELasDataset.put_UsesRelativePath

           INPUT
            pbUsesRelativePath  : VARIANT_BOOL'''
        return super(IDELasDataset, self).put_UsesRelativePath(pbUsesRelativePath)
    FileCount = property(get_FileCount, put_FileCount, None)
    HasStatistics = property(get_HasStatistics, put_HasStatistics, None)
    NeedsUpdateStatistics = property(get_NeedsUpdateStatistics, put_NeedsUpdateStatistics, None)
    PointCount = property(get_PointCount, put_PointCount, None)
    SurfaceConstraintCount = property(get_SurfaceConstraintCount, put_SurfaceConstraintCount, None)
    UsesRelativePath = property(get_UsesRelativePath, put_UsesRelativePath, None)

class IDECoverage(_esriDataSourcesFile.IDECoverage):
    _IID = uuid.UUID('bde67d8b-bf5e-45ec-a3fd-09ac77efe850')

    def __init__(self, *args, **kw):
        super(IDECoverage, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Tolerances(self):
        '''Method IDECoverage.get_Tolerances

           OUTPUT
            propertySet         : IPropertySet**'''
        return super(IDECoverage, self).get_Tolerances()
    def putref_Tolerances(self, propertySet):
        '''Method IDECoverage.putref_Tolerances

           INPUT
            propertySet         : IPropertySet*'''
        return super(IDECoverage, self).putref_Tolerances(propertySet)
    Tolerances = property(get_Tolerances, putref_Tolerances, None)

class IDECoverageFeatureClass(_esriDataSourcesFile.IDECoverageFeatureClass):
    _IID = uuid.UUID('25ea15b1-7425-452b-8fb6-ca3f8d088129')

    def __init__(self, *args, **kw):
        super(IDECoverageFeatureClass, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_FeatureClassType(self):
        '''Method IDECoverageFeatureClass.get_FeatureClassType

           OUTPUT
            FeatureClassType    : esriCoverageFeatureClassType*'''
        return super(IDECoverageFeatureClass, self).get_FeatureClassType()
    def put_FeatureClassType(self, FeatureClassType):
        '''Method IDECoverageFeatureClass.put_FeatureClassType

           INPUT
            FeatureClassType    : esriCoverageFeatureClassType'''
        return super(IDECoverageFeatureClass, self).put_FeatureClassType(FeatureClassType)
    def get_HasFAT(self):
        '''Method IDECoverageFeatureClass.get_HasFAT

           OUTPUT
            HasFAT              : VARIANT_BOOL*'''
        return super(IDECoverageFeatureClass, self).get_HasFAT()
    def put_HasFAT(self, HasFAT):
        '''Method IDECoverageFeatureClass.put_HasFAT

           INPUT
            HasFAT              : VARIANT_BOOL'''
        return super(IDECoverageFeatureClass, self).put_HasFAT(HasFAT)
    def get_Topology(self):
        '''Method IDECoverageFeatureClass.get_Topology

           OUTPUT
            pTopology           : esriFeatureClassTopology*'''
        return super(IDECoverageFeatureClass, self).get_Topology()
    def put_Topology(self, pTopology):
        '''Method IDECoverageFeatureClass.put_Topology

           INPUT
            pTopology           : esriFeatureClassTopology'''
        return super(IDECoverageFeatureClass, self).put_Topology(pTopology)
    FeatureClassType = property(get_FeatureClassType, put_FeatureClassType, None)
    HasFAT = property(get_HasFAT, put_HasFAT, None)
    Topology = property(get_Topology, put_Topology, None)

class IDEArcInfoTable(_esriDataSourcesFile.IDEArcInfoTable):
    _IID = uuid.UUID('dc3b7fdb-ce0f-4aee-945c-0755f89109e4')

    def __init__(self, *args, **kw):
        super(IDEArcInfoTable, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ItemSet(self):
        '''Method IDEArcInfoTable.get_ItemSet

           OUTPUT
            ppItems             : IArray**'''
        return super(IDEArcInfoTable, self).get_ItemSet()
    def putref_ItemSet(self, ppItems):
        '''Method IDEArcInfoTable.putref_ItemSet

           INPUT
            ppItems             : IArray*'''
        return super(IDEArcInfoTable, self).putref_ItemSet(ppItems)
    ItemSet = property(get_ItemSet, putref_ItemSet, None)

class IGPArcInfoItem(_esriDataSourcesFile.IGPArcInfoItem):
    _IID = uuid.UUID('c95b22e0-a3c3-11d5-931c-0080c71a3226')

    def __init__(self, *args, **kw):
        super(IGPArcInfoItem, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IGPArcInfoItem.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IGPArcInfoItem, self).get_Name()
    def put_Name(self, Name):
        '''Method IGPArcInfoItem.put_Name

           INPUT
            Name                : BSTR'''
        return super(IGPArcInfoItem, self).put_Name(Name)
    def get_StartPosition(self):
        '''Method IGPArcInfoItem.get_StartPosition

           OUTPUT
            Position            : long*'''
        return super(IGPArcInfoItem, self).get_StartPosition()
    def put_StartPosition(self, Position):
        '''Method IGPArcInfoItem.put_StartPosition

           INPUT
            Position            : long'''
        return super(IGPArcInfoItem, self).put_StartPosition(Position)
    def get_Width(self):
        '''Method IGPArcInfoItem.get_Width

           OUTPUT
            Width               : long*'''
        return super(IGPArcInfoItem, self).get_Width()
    def put_Width(self, Width):
        '''Method IGPArcInfoItem.put_Width

           INPUT
            Width               : long'''
        return super(IGPArcInfoItem, self).put_Width(Width)
    def get_OutputWidth(self):
        '''Method IGPArcInfoItem.get_OutputWidth

           OUTPUT
            Width               : long*'''
        return super(IGPArcInfoItem, self).get_OutputWidth()
    def put_OutputWidth(self, Width):
        '''Method IGPArcInfoItem.put_OutputWidth

           INPUT
            Width               : long'''
        return super(IGPArcInfoItem, self).put_OutputWidth(Width)
    def get_Type(self):
        '''Method IGPArcInfoItem.get_Type

           OUTPUT
            Type                : esriArcInfoItemType*'''
        return super(IGPArcInfoItem, self).get_Type()
    def put_Type(self, Type):
        '''Method IGPArcInfoItem.put_Type

           INPUT
            Type                : esriArcInfoItemType'''
        return super(IGPArcInfoItem, self).put_Type(Type)
    def get_NumberDecimals(self):
        '''Method IGPArcInfoItem.get_NumberDecimals

           OUTPUT
            number              : long*'''
        return super(IGPArcInfoItem, self).get_NumberDecimals()
    def put_NumberDecimals(self, number):
        '''Method IGPArcInfoItem.put_NumberDecimals

           INPUT
            number              : long'''
        return super(IGPArcInfoItem, self).put_NumberDecimals(number)
    def get_AlternateName(self):
        '''Method IGPArcInfoItem.get_AlternateName

           OUTPUT
            AlternateName       : BSTR*'''
        return super(IGPArcInfoItem, self).get_AlternateName()
    def put_AlternateName(self, AlternateName):
        '''Method IGPArcInfoItem.put_AlternateName

           INPUT
            AlternateName       : BSTR'''
        return super(IGPArcInfoItem, self).put_AlternateName(AlternateName)
    def get_IsRedefined(self):
        '''Method IGPArcInfoItem.get_IsRedefined

           OUTPUT
            redefined           : VARIANT_BOOL*'''
        return super(IGPArcInfoItem, self).get_IsRedefined()
    def put_IsRedefined(self, redefined):
        '''Method IGPArcInfoItem.put_IsRedefined

           INPUT
            redefined           : VARIANT_BOOL'''
        return super(IGPArcInfoItem, self).put_IsRedefined(redefined)
    def get_IsIndexed(self):
        '''Method IGPArcInfoItem.get_IsIndexed

           OUTPUT
            IsIndexed           : VARIANT_BOOL*'''
        return super(IGPArcInfoItem, self).get_IsIndexed()
    def put_IsIndexed(self, IsIndexed):
        '''Method IGPArcInfoItem.put_IsIndexed

           INPUT
            IsIndexed           : VARIANT_BOOL'''
        return super(IGPArcInfoItem, self).put_IsIndexed(IsIndexed)
    def get_IsPseudo(self):
        '''Method IGPArcInfoItem.get_IsPseudo

           OUTPUT
            isPsuedo            : VARIANT_BOOL*'''
        return super(IGPArcInfoItem, self).get_IsPseudo()
    def put_IsPseudo(self, isPsuedo):
        '''Method IGPArcInfoItem.put_IsPseudo

           INPUT
            isPsuedo            : VARIANT_BOOL'''
        return super(IGPArcInfoItem, self).put_IsPseudo(isPsuedo)
    AlternateName = property(get_AlternateName, put_AlternateName, None)
    IsIndexed = property(get_IsIndexed, put_IsIndexed, None)
    IsPseudo = property(get_IsPseudo, put_IsPseudo, None)
    IsRedefined = property(get_IsRedefined, put_IsRedefined, None)
    Name = property(get_Name, put_Name, None)
    NumberDecimals = property(get_NumberDecimals, put_NumberDecimals, None)
    OutputWidth = property(get_OutputWidth, put_OutputWidth, None)
    StartPosition = property(get_StartPosition, put_StartPosition, None)
    Type = property(get_Type, put_Type, None)
    Width = property(get_Width, put_Width, None)

class IDEArcInfoUtilities(_esriDataSourcesFile.IDEArcInfoUtilities):
    _IID = uuid.UUID('1c1d3491-9e02-4283-be2f-b8177cc8f01f')
    def AssignCoverageProperties(self, pCoverage, pDataElement):
        '''Method IDEArcInfoUtilities.AssignCoverageProperties

           INPUTS
            pCoverage           : ICoverage*
            pDataElement        : IDataElement*'''
        return super(IDEArcInfoUtilities, self).AssignCoverageProperties(pCoverage, pDataElement)
    def AssignArcInfoTableProperties(self, pArcInfoTable, pDataElement):
        '''Method IDEArcInfoUtilities.AssignArcInfoTableProperties

           INPUTS
            pArcInfoTable       : IArcInfoTable*
            pDataElement        : IDataElement*'''
        return super(IDEArcInfoUtilities, self).AssignArcInfoTableProperties(pArcInfoTable, pDataElement)
    def AssignCoverageFeatureClassProperties(self, pCoverageFeatureClass, pDataElement):
        '''Method IDEArcInfoUtilities.AssignCoverageFeatureClassProperties

           INPUTS
            pCoverageFeatureClass: ICoverageFeatureClass*
            pDataElement        : IDataElement*'''
        return super(IDEArcInfoUtilities, self).AssignCoverageFeatureClassProperties(pCoverageFeatureClass, pDataElement)
    def AssignCoverageFeatureClassNameProperties(self, pCoverageFeatureClassName, pDataElement):
        '''Method IDEArcInfoUtilities.AssignCoverageFeatureClassNameProperties

           INPUTS
            pCoverageFeatureClassName: ICoverageFeatureClassName*
            pDataElement        : IDataElement*'''
        return super(IDEArcInfoUtilities, self).AssignCoverageFeatureClassNameProperties(pCoverageFeatureClassName, pDataElement)
    def MakeDETolerances(self, pCoverage):
        '''Method IDEArcInfoUtilities.MakeDETolerances

           INPUT
            pCoverage           : ICoverage*

           OUTPUT
            ppTolerances        : IPropertySet**'''
        return super(IDEArcInfoUtilities, self).MakeDETolerances(pCoverage)
    def MakeGPItems(self, pItems):
        '''Method IDEArcInfoUtilities.MakeGPItems

           INPUT
            pItems              : IArcInfoItems*

           OUTPUT
            ppGPItems           : IArray**'''
        return super(IDEArcInfoUtilities, self).MakeGPItems(pItems)
    def MakeGPItem(self, pItem):
        '''Method IDEArcInfoUtilities.MakeGPItem

           INPUT
            pItem               : IArcInfoItem*

           OUTPUT
            ppGPItem            : IGPArcInfoItem**'''
        return super(IDEArcInfoUtilities, self).MakeGPItem(pItem)
    def GetCoverageFeatureClassTypeFromString(self, desc):
        '''Method IDEArcInfoUtilities.GetCoverageFeatureClassTypeFromString

           INPUT
            desc                : BSTR

           OUTPUT
            Type                : esriCoverageFeatureClassType*'''
        return super(IDEArcInfoUtilities, self).GetCoverageFeatureClassTypeFromString(desc)
    def GetCoverageFeatureClassTypeDescription(self, Type):
        '''Method IDEArcInfoUtilities.GetCoverageFeatureClassTypeDescription

           INPUT
            Type                : esriCoverageFeatureClassType

           OUTPUT
            desc                : BSTR*'''
        return super(IDEArcInfoUtilities, self).GetCoverageFeatureClassTypeDescription(Type)
    def GetFeatureClassTopologyFromString(self, desc):
        '''Method IDEArcInfoUtilities.GetFeatureClassTopologyFromString

           INPUT
            desc                : BSTR

           OUTPUT
            Type                : esriFeatureClassTopology*'''
        return super(IDEArcInfoUtilities, self).GetFeatureClassTopologyFromString(desc)
    def GetFeatureClassTopologyDescription(self, Type):
        '''Method IDEArcInfoUtilities.GetFeatureClassTopologyDescription

           INPUT
            Type                : esriFeatureClassTopology

           OUTPUT
            desc                : BSTR*'''
        return super(IDEArcInfoUtilities, self).GetFeatureClassTopologyDescription(Type)
    def GetItemTypeFromString(self, desc):
        '''Method IDEArcInfoUtilities.GetItemTypeFromString

           INPUT
            desc                : BSTR

           OUTPUT
            Type                : esriArcInfoItemType*'''
        return super(IDEArcInfoUtilities, self).GetItemTypeFromString(desc)
    def GetItemTypeDescription(self, Type):
        '''Method IDEArcInfoUtilities.GetItemTypeDescription

           INPUT
            Type                : esriArcInfoItemType

           OUTPUT
            desc                : BSTR*'''
        return super(IDEArcInfoUtilities, self).GetItemTypeDescription(Type)
    def ItemExists(self, pDEArcInfoTable, pGPItem):
        '''Method IDEArcInfoUtilities.ItemExists

           INPUTS
            pDEArcInfoTable     : IDEArcInfoTable*
            pGPItem             : IGPArcInfoItem*

           OUTPUT
            pExists             : VARIANT_BOOL*'''
        return super(IDEArcInfoUtilities, self).ItemExists(pDEArcInfoTable, pGPItem)
    def FindItem(self, pDEArcInfoTable, Name):
        '''Method IDEArcInfoUtilities.FindItem

           INPUTS
            pDEArcInfoTable     : IDEArcInfoTable*
            Name                : BSTR

           OUTPUT
            ppGPItem            : IGPArcInfoItem**'''
        return super(IDEArcInfoUtilities, self).FindItem(pDEArcInfoTable, Name)


# IIDs
IID_IArcInfoItem = IArcInfoItem._IID
IID_IArcInfoItemEdit = IArcInfoItemEdit._IID
IID_IArcInfoItems = IArcInfoItems._IID
IID_IArcInfoItemsEdit = IArcInfoItemsEdit._IID
IID_IArcInfoTable = IArcInfoTable._IID
IID_IArcInfoTable2 = IArcInfoTable2._IID
IID_ICoverageFeatureClass = ICoverageFeatureClass._IID
IID_ICoverageFeatureClass2 = ICoverageFeatureClass2._IID
IID_ICoverage = ICoverage._IID
IID_ICoverage2 = ICoverage2._IID
IID_IArcInfoWorkspace = IArcInfoWorkspace._IID
IID_IInfoTableOnlyWorkspaceEdit = IInfoTableOnlyWorkspaceEdit._IID
IID_ICoverageFeatureClassName = ICoverageFeatureClassName._IID
IID_ICoverageName = ICoverageName._IID
IID_IArcInfoWorkspaceUtil = IArcInfoWorkspaceUtil._IID
IID_ICadSettings = ICadSettings._IID
IID_ICadDrawingLayers = ICadDrawingLayers._IID
IID_ICadTransformations = ICadTransformations._IID
IID_ICadDrawingDataset = ICadDrawingDataset._IID
IID_ICadDrawingWorkspace = ICadDrawingWorkspace._IID
IID_ISdcExporter = ISdcExporter._IID
IID_ISMRouterPoint = ISMRouterPoint._IID
IID_ISMRouterEnvelope = ISMRouterEnvelope._IID
IID_ISMPointsCollection = ISMPointsCollection._IID
IID_ISMNetAttribute = ISMNetAttribute._IID
IID_ISMNetAttribute2 = ISMNetAttribute2._IID
IID_ISMNetAttributesCollection = ISMNetAttributesCollection._IID
IID_ISMNetBarrier = ISMNetBarrier._IID
IID_ISMNetBarriersCollection = ISMNetBarriersCollection._IID
IID_ISMRoadPreferences = ISMRoadPreferences._IID
IID_ISMSpeedGroup = ISMSpeedGroup._IID
IID_ISMSpeedGroup2 = ISMSpeedGroup2._IID
IID_ISMSpeedGroups = ISMSpeedGroups._IID
IID_ISMTripPlanSettings = ISMTripPlanSettings._IID
IID_ISMFlag = ISMFlag._IID
IID_ISMFlagCreator = ISMFlagCreator._IID
IID_ISMFlagCreator2 = ISMFlagCreator2._IID
IID_ISMStop = ISMStop._IID
IID_ISMStopsCollection = ISMStopsCollection._IID
IID_ISMDirItem = ISMDirItem._IID
IID_ISMDirections = ISMDirections._IID
IID_ISMBreakTracker = ISMBreakTracker._IID
IID_ISMNetAttributesAccess = ISMNetAttributesAccess._IID
IID_ISMRouter = ISMRouter._IID
IID_ISMRouterFactory = ISMRouterFactory._IID
IID_ISMRoutingMetaData = ISMRoutingMetaData._IID
IID_ISMRestriction = ISMRestriction._IID
IID_ISMRouterSetup = ISMRouterSetup._IID
IID_ISMRouterSetup2 = ISMRouterSetup2._IID
IID_IUsageModeOption = IUsageModeOption._IID
IID_IUsageModeInfo = IUsageModeInfo._IID
IID_IMetaInfo = IMetaInfo._IID
IID_IDataLicenseInfo = IDataLicenseInfo._IID
IID_IDataLicenseManager = IDataLicenseManager._IID
IID_IDECadDrawingDataset = IDECadDrawingDataset._IID
IID_IGPLayer = IGPLayer._IID
IID_IDELayer = IDELayer._IID
IID_IDEPrjFile = IDEPrjFile._IID
IID_IDETin = IDETin._IID
IID_IDELasDataset = IDELasDataset._IID
IID_IDECoverage = IDECoverage._IID
IID_IDECoverageFeatureClass = IDECoverageFeatureClass._IID
IID_IDEArcInfoTable = IDEArcInfoTable._IID
IID_IGPArcInfoItem = IGPArcInfoItem._IID
IID_IDEArcInfoUtilities = IDEArcInfoUtilities._IID
_IIDMap[IID_IArcInfoItem] = IArcInfoItem
_IIDMap[IID_IArcInfoItemEdit] = IArcInfoItemEdit
_IIDMap[IID_IArcInfoItems] = IArcInfoItems
_IIDMap[IID_IArcInfoItemsEdit] = IArcInfoItemsEdit
_IIDMap[IID_IArcInfoTable] = IArcInfoTable
_IIDMap[IID_IArcInfoTable2] = IArcInfoTable2
_IIDMap[IID_ICoverageFeatureClass] = ICoverageFeatureClass
_IIDMap[IID_ICoverageFeatureClass2] = ICoverageFeatureClass2
_IIDMap[IID_ICoverage] = ICoverage
_IIDMap[IID_ICoverage2] = ICoverage2
_IIDMap[IID_IArcInfoWorkspace] = IArcInfoWorkspace
_IIDMap[IID_IInfoTableOnlyWorkspaceEdit] = IInfoTableOnlyWorkspaceEdit
_IIDMap[IID_ICoverageFeatureClassName] = ICoverageFeatureClassName
_IIDMap[IID_ICoverageName] = ICoverageName
_IIDMap[IID_IArcInfoWorkspaceUtil] = IArcInfoWorkspaceUtil
_IIDMap[IID_ICadSettings] = ICadSettings
_IIDMap[IID_ICadDrawingLayers] = ICadDrawingLayers
_IIDMap[IID_ICadTransformations] = ICadTransformations
_IIDMap[IID_ICadDrawingDataset] = ICadDrawingDataset
_IIDMap[IID_ICadDrawingWorkspace] = ICadDrawingWorkspace
_IIDMap[IID_ISdcExporter] = ISdcExporter
_IIDMap[IID_ISMRouterPoint] = ISMRouterPoint
_IIDMap[IID_ISMRouterEnvelope] = ISMRouterEnvelope
_IIDMap[IID_ISMPointsCollection] = ISMPointsCollection
_IIDMap[IID_ISMNetAttribute] = ISMNetAttribute
_IIDMap[IID_ISMNetAttribute2] = ISMNetAttribute2
_IIDMap[IID_ISMNetAttributesCollection] = ISMNetAttributesCollection
_IIDMap[IID_ISMNetBarrier] = ISMNetBarrier
_IIDMap[IID_ISMNetBarriersCollection] = ISMNetBarriersCollection
_IIDMap[IID_ISMRoadPreferences] = ISMRoadPreferences
_IIDMap[IID_ISMSpeedGroup] = ISMSpeedGroup
_IIDMap[IID_ISMSpeedGroup2] = ISMSpeedGroup2
_IIDMap[IID_ISMSpeedGroups] = ISMSpeedGroups
_IIDMap[IID_ISMTripPlanSettings] = ISMTripPlanSettings
_IIDMap[IID_ISMFlag] = ISMFlag
_IIDMap[IID_ISMFlagCreator] = ISMFlagCreator
_IIDMap[IID_ISMFlagCreator2] = ISMFlagCreator2
_IIDMap[IID_ISMStop] = ISMStop
_IIDMap[IID_ISMStopsCollection] = ISMStopsCollection
_IIDMap[IID_ISMDirItem] = ISMDirItem
_IIDMap[IID_ISMDirections] = ISMDirections
_IIDMap[IID_ISMBreakTracker] = ISMBreakTracker
_IIDMap[IID_ISMNetAttributesAccess] = ISMNetAttributesAccess
_IIDMap[IID_ISMRouter] = ISMRouter
_IIDMap[IID_ISMRouterFactory] = ISMRouterFactory
_IIDMap[IID_ISMRoutingMetaData] = ISMRoutingMetaData
_IIDMap[IID_ISMRestriction] = ISMRestriction
_IIDMap[IID_ISMRouterSetup] = ISMRouterSetup
_IIDMap[IID_ISMRouterSetup2] = ISMRouterSetup2
_IIDMap[IID_IUsageModeOption] = IUsageModeOption
_IIDMap[IID_IUsageModeInfo] = IUsageModeInfo
_IIDMap[IID_IMetaInfo] = IMetaInfo
_IIDMap[IID_IDataLicenseInfo] = IDataLicenseInfo
_IIDMap[IID_IDataLicenseManager] = IDataLicenseManager
_IIDMap[IID_IDECadDrawingDataset] = IDECadDrawingDataset
_IIDMap[IID_IGPLayer] = IGPLayer
_IIDMap[IID_IDELayer] = IDELayer
_IIDMap[IID_IDEPrjFile] = IDEPrjFile
_IIDMap[IID_IDETin] = IDETin
_IIDMap[IID_IDELasDataset] = IDELasDataset
_IIDMap[IID_IDECoverage] = IDECoverage
_IIDMap[IID_IDECoverageFeatureClass] = IDECoverageFeatureClass
_IIDMap[IID_IDEArcInfoTable] = IDEArcInfoTable
_IIDMap[IID_IGPArcInfoItem] = IGPArcInfoItem
_IIDMap[IID_IDEArcInfoUtilities] = IDEArcInfoUtilities


# CLSIDs
CLSID_ArcInfoWorkspaceFactory = uuid.UUID('1d887452-d9f2-11d1-aa81-00c04fa33a15')
CLSID_ArcInfoItems = uuid.UUID('5bb90fa2-d013-11d2-b0dc-0000f8780820')
CLSID_ArcInfoItem = uuid.UUID('5bb90fa1-d013-11d2-b0dc-0000f8780820')
CLSID_CoverageFeatureClassName = uuid.UUID('72f77de8-122a-11d3-9f31-00c04f79927c')
CLSID_CoverageName = uuid.UUID('1e921c72-122f-11d3-9f31-00c04f79927c')
CLSID_PCCoverageWorkspaceFactory = uuid.UUID('6de812d2-9ab6-11d2-b0d7-0000f8780820')
CLSID_StreetMapWorkspaceFactory = uuid.UUID('ae2469e8-e110-4cd6-b3f4-a756cbf921ca')
CLSID_SDCWorkspaceFactory = uuid.UUID('34dae34f-dbe2-409c-8f85-ddbb46138011')
CLSID_SDCNetworkSource = uuid.UUID('5be00c09-a03f-4a69-b678-985108a500d3')
CLSID_SDCNetworkAttribute = uuid.UUID('a2ab1fba-aa5f-485e-97fe-79d0f5ff9984')
CLSID_ShapefileWorkspaceFactory = uuid.UUID('a06adb96-d95c-11d1-aa81-00c04fa33a15')
CLSID_VpfWorkspaceFactory = uuid.UUID('397847f9-c865-11d3-9b56-00c04fa33299')
CLSID_TinWorkspaceFactory = uuid.UUID('ad4e89d9-00a5-11d2-b1ca-00c04f8edeff')
CLSID_GeoRSSWorkspaceFactory = uuid.UUID('894af6a1-157a-47ba-bdec-3cf98d4cce74')
CLSID_CadWorkspaceFactory = uuid.UUID('9e2c27ce-62c6-11d2-9aed-00c04fa33299')
CLSID_CadDrawingName = uuid.UUID('d4224309-a5cb-11d2-9b10-00c04fa33299')
CLSID_SdcExporter = uuid.UUID('3c8b1a03-64b8-4e29-86ad-d4c4cb371ec1')
CLSID_SMRouterPoint = uuid.UUID('f8b65fee-5850-11d7-b321-008048db11de')
CLSID_SMRouterEnvelope = uuid.UUID('f8b65ff1-5850-11d7-b321-008048db11de')
CLSID_SMPointsCollection = uuid.UUID('f8b65ff4-5850-11d7-b321-008048db11de')
CLSID_SMNetAttribute = uuid.UUID('f8b65ff7-5850-11d7-b321-008048db11de')
CLSID_SMNetAttributesCollection = uuid.UUID('f8b65ffa-5850-11d7-b321-008048db11de')
CLSID_SMNetBarrier = uuid.UUID('f8b65ffd-5850-11d7-b321-008048db11de')
CLSID_SMNetBarriersCollection = uuid.UUID('f8b66000-5850-11d7-b321-008048db11de')
CLSID_SMRoadPreferences = uuid.UUID('f8b66003-5850-11d7-b321-008048db11de')
CLSID_SMSpeedGroup = uuid.UUID('f8b66006-5850-11d7-b321-008048db11de')
CLSID_SMSpeedGroups = uuid.UUID('f8b66009-5850-11d7-b321-008048db11de')
CLSID_SMTripPlanSettings = uuid.UUID('f8b6600c-5850-11d7-b321-008048db11de')
CLSID_SMFlag = uuid.UUID('f8b66012-5850-11d7-b321-008048db11de')
CLSID_SMStop = uuid.UUID('f8b66015-5850-11d7-b321-008048db11de')
CLSID_SMStopsCollection = uuid.UUID('f8b66018-5850-11d7-b321-008048db11de')
CLSID_SMDirItem = uuid.UUID('f8b6601b-5850-11d7-b321-008048db11de')
CLSID_SMDirections = uuid.UUID('f8b6601e-5850-11d7-b321-008048db11de')
CLSID_SMRouter = uuid.UUID('f8b66021-5850-11d7-b321-008048db11de')
CLSID_SMRouterFactory = uuid.UUID('f8b66024-5850-11d7-b321-008048db11de')
CLSID_SMNetAttributesAccess = uuid.UUID('2041d5a1-c9b6-4c74-8954-033af25557b8')
CLSID_SMFlagCreator = uuid.UUID('38a979e8-086f-4ca8-ac30-890f22e65ebc')
CLSID_SMRestriction = uuid.UUID('71a8e2b4-5a6c-4bdd-b005-a0fb02414197')
CLSID_LicensedDataExtension = uuid.UUID('39bc41a4-b140-4f7b-b1c9-accd507ee339')
CLSID_DECadDrawingDatasetType = uuid.UUID('43a72293-aac8-4f0c-b8f8-8b2cdb298f85')
CLSID_DECadDrawingDataset = uuid.UUID('f786332d-20b2-4607-bf34-0a53e4d0b413')
CLSID_DELayerType = uuid.UUID('775700af-8577-442d-adc9-74d7a9aa3c41')
CLSID_DEShapeFileType = uuid.UUID('44a51f3f-ef06-4fd9-bc52-010e6ca0e84b')
CLSID_DEDbaseTableType = uuid.UUID('11e37cd0-a664-11d5-931d-0080c71a3226')
CLSID_DELayer = uuid.UUID('bdd71708-3463-4787-a491-b9363b937dbe')
CLSID_DEShapeFile = uuid.UUID('03e6fb47-aa38-476c-934b-1df5765c76eb')
CLSID_DEDbaseTable = uuid.UUID('69e84176-fb98-4036-a8ff-e69c8e82f013')
CLSID_DECatalogRootType = uuid.UUID('07359aea-34ba-4b5a-ab2c-0b43c7e8e9fb')
CLSID_DEDiskConnectionType = uuid.UUID('36afbb31-cdbe-41cb-bb11-58484c2acf45')
CLSID_DEFolderType = uuid.UUID('fe29b0ed-decf-4a61-8ed0-be233bfe376b')
CLSID_DEFileType = uuid.UUID('c486aa07-9027-4d78-88fc-4a7a940bb367')
CLSID_DEPrjFileType = uuid.UUID('ebfebc90-cfbf-11d5-933d-0080c71a3226')
CLSID_DEMapDocumentType = uuid.UUID('ec42ceb1-8029-4f90-a18c-5790ae1fad01')
CLSID_DERemoteDatabaseFolderType = uuid.UUID('2919c9ef-dc76-4c52-9539-f357a4f68925')
CLSID_DESpatialReferencesFolderType = uuid.UUID('9fd4b414-498a-48b8-bf2f-82302524d513')
CLSID_DECatalogRoot = uuid.UUID('01d6ebdd-de9a-4217-8bfe-327265855fa2')
CLSID_DEDiskConnection = uuid.UUID('8e5e855a-7d60-4ce1-afd0-45929c9f492c')
CLSID_DEFolder = uuid.UUID('273ccebc-1aa2-4429-bbd5-4cb7c6e20465')
CLSID_DEFile = uuid.UUID('175cf2c5-12bf-413a-8fdf-3da30cc09bee')
CLSID_DEMapDocument = uuid.UUID('c0bed5d9-13e2-469b-a7d8-22704b0c8630')
CLSID_DERemoteDatabaseFolder = uuid.UUID('db3e6fdf-d5f8-4c94-b743-47ab4de79a05')
CLSID_DESpatialReferencesFolder = uuid.UUID('3189f8fc-a9c8-4b8e-8c47-43c758a7a8bd')
CLSID_DEPrjFile = uuid.UUID('7e704bb0-cfbe-11d5-933d-0080c71a3226')
CLSID_DETextFile = uuid.UUID('e98d0766-c13e-45ca-ba78-1def8b60cab2')
CLSID_DETextFileType = uuid.UUID('9a4700e6-c10c-4ecb-aae6-90d382ae22c4')
CLSID_DETinType = uuid.UUID('f0b41a32-ee77-4b16-a5ee-16bce3d8f3cc')
CLSID_DETin = uuid.UUID('5edc32f1-c1b2-4808-88e0-2ed68e77269d')
CLSID_DELasDatasetType = uuid.UUID('160bc182-ce75-4dab-8abf-8e6dc866c73b')
CLSID_DELasDataset = uuid.UUID('ea006709-cd03-439d-80a1-9254e25412e3')
CLSID_DECoverageType = uuid.UUID('80172db6-5715-4157-b253-6150ea74203e')
CLSID_DECoverageFeatureClassType = uuid.UUID('874e63d8-b362-457b-a3c8-aa0f3f443e0b')
CLSID_DEArcInfoTableType = uuid.UUID('0e3f5cb0-2445-4abb-be9a-fcf0492e180a')
CLSID_GPArcInfoItemType = uuid.UUID('5356dadd-53e4-4e70-99c9-996cdd224e25')
CLSID_DECoverage = uuid.UUID('96b70c47-2c7f-405f-b9fd-deaa3cdc084c')
CLSID_DECoverageFeatureClass = uuid.UUID('b7ec3865-805b-41a4-804c-8b4a30aa4128')
CLSID_DEArcInfoTable = uuid.UUID('1cc786ec-5efe-493c-8a25-b546844665d7')
CLSID_GPArcInfoItem = uuid.UUID('6dddbbb2-41dc-4f12-913e-803196eb33fa')
CLSID_DEArcInfoUtilities = uuid.UUID('95d74728-cadd-41c2-af2b-7e816364d905')
CLSID_DEVPFTableType = uuid.UUID('3f3c713f-cc15-4ea7-a780-193e021d4251')
CLSID_DEVPFTable = uuid.UUID('48aab232-6f1f-4261-9dac-cba55d183649')
CLSID_DEVPFCoverageType = uuid.UUID('728bbf56-85fa-4598-9ce8-77fc8ba73127')
CLSID_DEVPFCoverage = uuid.UUID('ca4ff80d-85a9-445c-adb2-a5c7811b3c36')

# Enumerations
class esriCoverageToleranceType(Enumeration):
    __slots__ = ['esriCTTFuzzy',
                 'esriCTTGeneralize',
                 'esriCTTNodeMatch',
                 'esriCTTDangle',
                 'esriCTTTicMatch',
                 'esriCTTEdit',
                 'esriCTTNodeSnap',
                 'esriCTTWeed',
                 'esriCTTGrain',
                 'esriCTTSnap']
    esriCTTFuzzy = 1
    esriCTTGeneralize = 2
    esriCTTNodeMatch = 3
    esriCTTDangle = 4
    esriCTTTicMatch = 5
    esriCTTEdit = 6
    esriCTTNodeSnap = 7
    esriCTTWeed = 8
    esriCTTGrain = 9
    esriCTTSnap = 10

class esriArcInfoItemType(Enumeration):
    __slots__ = ['esriItemTypeDate',
                 'esriItemTypeCharacter',
                 'esriItemTypeInteger',
                 'esriItemTypeNumber',
                 'esriItemTypeBinary',
                 'esriItemTypeFloat',
                 'esriItemTypeLeadFill',
                 'esriItemTypePacked',
                 'esriItemTypeZeroFill',
                 'esriItemTypeOverpunch',
                 'esriItemTypeTrailingSign',
                 'esriItemTypeOID',
                 'esriItemTypeGeometry',
                 'esriItemTypeBlob']
    esriItemTypeDate = 1
    esriItemTypeCharacter = 2
    esriItemTypeInteger = 3
    esriItemTypeNumber = 4
    esriItemTypeBinary = 5
    esriItemTypeFloat = 6
    esriItemTypeLeadFill = 7
    esriItemTypePacked = 8
    esriItemTypeZeroFill = 9
    esriItemTypeOverpunch = 10
    esriItemTypeTrailingSign = 11
    esriItemTypeOID = 12
    esriItemTypeGeometry = 13
    esriItemTypeBlob = 14

class esriCoverageType(Enumeration):
    __slots__ = ['esriEmptyCoverage',
                 'esriAnnotationCoverage',
                 'esriPointCoverage',
                 'esriLineCoverage',
                 'esriPolygonCoverage',
                 'esriPreliminaryPolygonCoverage']
    esriEmptyCoverage = 0
    esriAnnotationCoverage = 1
    esriPointCoverage = 2
    esriLineCoverage = 3
    esriPolygonCoverage = 4
    esriPreliminaryPolygonCoverage = 5

class esriCoverageFeatureClassType(Enumeration):
    __slots__ = ['esriCFCTPoint',
                 'esriCFCTArc',
                 'esriCFCTPolygon',
                 'esriCFCTNode',
                 'esriCFCTTic',
                 'esriCFCTAnnotation',
                 'esriCFCTSection',
                 'esriCFCTRoute',
                 'esriCFCTLink',
                 'esriCFCTRegion',
                 'esriCFCTLabel',
                 'esriCFCTFile']
    esriCFCTPoint = 1
    esriCFCTArc = 2
    esriCFCTPolygon = 3
    esriCFCTNode = 4
    esriCFCTTic = 5
    esriCFCTAnnotation = 6
    esriCFCTSection = 7
    esriCFCTRoute = 8
    esriCFCTLink = 9
    esriCFCTRegion = 11
    esriCFCTLabel = 51
    esriCFCTFile = 666

class esriFeatureClassTopology(Enumeration):
    __slots__ = ['esriFCTNotApplicable',
                 'esriFCTPreliminary',
                 'esriFCTExists',
                 'esriFCTUnknown']
    esriFCTNotApplicable = 0
    esriFCTPreliminary = 1
    esriFCTExists = 2
    esriFCTUnknown = 3

class esriCoveragePrecisionType(Enumeration):
    __slots__ = ['esriCoveragePrecisionSingle',
                 'esriCoveragePrecisionDouble']
    esriCoveragePrecisionSingle = 1
    esriCoveragePrecisionDouble = 2

class esriCadTransform(Enumeration):
    __slots__ = ['esriCadTransformByWorldFile',
                 'esriCadTransformByPoints',
                 'esriCadTransformByRst']
    esriCadTransformByWorldFile = 0
    esriCadTransformByPoints = 1
    esriCadTransformByRst = 2

class esriSMNetAttributeType(Enumeration):
    __slots__ = ['esriSMNetAttrInteger',
                 'esriSMNetAttrFloat',
                 'esriSMNetAttrDouble',
                 'esriSMNetAttrBoolean',
                 'esriSMNetAttrString',
                 'esriSMNetAttrShape']
    esriSMNetAttrInteger = 1
    esriSMNetAttrFloat = 2
    esriSMNetAttrDouble = 3
    esriSMNetAttrBoolean = 4
    esriSMNetAttrString = 5
    esriSMNetAttrShape = 6

class esriSMNetAttributeUsageType(Enumeration):
    __slots__ = ['esriSMNAUTCost',
                 'esriSMNAUTDescription',
                 'esriSMNAUTRestrictionBoolean',
                 'esriSMNAUTRestrictionMinAllowed',
                 'esriSMNAUTRestrictionMaxAllowed']
    esriSMNAUTCost = 1
    esriSMNAUTDescription = 2
    esriSMNAUTRestrictionBoolean = 3
    esriSMNAUTRestrictionMinAllowed = 4
    esriSMNAUTRestrictionMaxAllowed = 5

class esriSMRoadType(Enumeration):
    __slots__ = ['esriSMRoadTypeHighways',
                 'esriSMRoadTypeFerries']
    esriSMRoadTypeHighways = 1
    esriSMRoadTypeFerries = 2

class esriSMStreetSideType(Enumeration):
    __slots__ = ['esriSMStreetSideLeft',
                 'esriSMStreetSideRight',
                 'esriSMStreetSideUndefined']
    esriSMStreetSideLeft = 1
    esriSMStreetSideRight = 2
    esriSMStreetSideUndefined = 3

class esriSMDirItemType(Enumeration):
    __slots__ = ['esriSMDirItemNewRoad',
                 'esriSMDirItemBypass',
                 'esriSMDirItemBorder',
                 'esriSMDirItemEndOfDay',
                 'esriSMDirItemDayNumber',
                 'esriSMDirItemRestBreak',
                 'esriSMDirItemDepart',
                 'esriSMDirItemArrive']
    esriSMDirItemNewRoad = 1
    esriSMDirItemBypass = 2
    esriSMDirItemBorder = 3
    esriSMDirItemEndOfDay = 4
    esriSMDirItemDayNumber = 5
    esriSMDirItemRestBreak = 6
    esriSMDirItemDepart = 7
    esriSMDirItemArrive = 8

class esriSMAzimuthType(Enumeration):
    __slots__ = ['esriSMAzimuthN',
                 'esriSMAzimuthNE',
                 'esriSMAzimuthE',
                 'esriSMAzimuthSE',
                 'esriSMAzimuthS',
                 'esriSMAzimuthSW',
                 'esriSMAzimuthW',
                 'esriSMAzimuthNW',
                 'esriSMAzimuthUnknown']
    esriSMAzimuthN = 1
    esriSMAzimuthNE = 2
    esriSMAzimuthE = 3
    esriSMAzimuthSE = 4
    esriSMAzimuthS = 5
    esriSMAzimuthSW = 6
    esriSMAzimuthW = 7
    esriSMAzimuthNW = 8
    esriSMAzimuthUnknown = 9

class esriSMRestrictionType(Enumeration):
    __slots__ = ['esriSMRTStrict',
                 'esriSMRTRelaxed']
    esriSMRTStrict = 1
    esriSMRTRelaxed = 2

class esriSMBacktrackPolicy(Enumeration):
    __slots__ = ['esriSMBTPDisable',
                 'esriSMBTPAllow',
                 'esriSMBTPDeadend']
    esriSMBTPDisable = 1
    esriSMBTPAllow = 2
    esriSMBTPDeadend = 3

class esriSMDirectionsLengthUnits(Enumeration):
    __slots__ = ['esriSMDLUMiles',
                 'esriSMDLUKilometers',
                 'esriSMDLUMeters',
                 'esriSMDLUFeet',
                 'esriSMDLUYards']
    esriSMDLUMiles = 1
    esriSMDLUKilometers = 2
    esriSMDLUMeters = 3
    esriSMDLUFeet = 4
    esriSMDLUYards = 5

class esriDataLicenseType(Enumeration):
    __slots__ = ['esriDataLicSeatType',
                 'esriDataLicFloatType']
    esriDataLicSeatType = 1
    esriDataLicFloatType = 2

