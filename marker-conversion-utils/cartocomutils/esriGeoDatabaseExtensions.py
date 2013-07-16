'Type library'
__all__ = ['IDETerrain', 'IDETerrainWindowSize', 'ITerrainDataSource', 'ITerrainPyramidLevel', 'IEnumEnvelope', 'ITerrainEdit', 'ITerrainEdit2', 'ITerrainEdit3', 'ITerrainName', 'ITerrainDataSource2', 'ITerrainEmbeddedDataSource', 'ITerrainFieldStatistics', 'ITerrainEmbeddedDataSource2', 'ITerrainBlockCursor', 'ITerrainDataImporter', 'ITerrainLasDataImporter', 'ITerrainAsciiDataImporter', 'ITerrainAsciiDataImporter2', 'ITerrainLasDataInfo', 'ITerrainBlobReader', 'ITerrainBlobWriter', 'ITerrainEditEvents', 'ITerrainLasDataInfo2', 'IGPTerrainMembership', 'ISimpleStatistics', 'ILasReturnStatistics', 'ILasClassCodeStatistics', 'ILasStatistics', 'ILasHeaderInfo', 'ILasFile', 'ILasAttributeFilter', 'ILasPointFilter', 'ILasFilter', 'ILasSurface', 'ILasDataset', 'ILasDatasetEdit', 'IEnumLasPoint', 'ILasPointInfo', 'ILasPointCloud', 'ILasDatasetWorkspace', 'ILasDataset2', 'ILasPointEdit', 'ICadastralJob', 'ICadastralFabric', 'ICadastralFabric2', 'ICadastralFabric3', 'ICadastralFabricName', 'IDECadastralFabric', 'ICadastralTransformationData', 'ICadastralAdjustmentVectors', 'ICadastralFabricLocks', 'ICadastralFabricLocks2', 'ICadastralFabricSchemaEdit', 'ICadastralFabricSchemaEdit2', 'ICadastralTableFieldEdits', 'IDECadastralFabric2', 'IDECadastralFabric3', 'IParcelConstructionData', 'IConstructionParentParcels', 'IConstructionBreakPoints', 'IConstructionBasisOfBearing', 'IConstructionJoinLinks', 'IConstructionUnbuildableLines', 'IConstructionPoints', 'IConstructionAdjustment', 'ILineResequencer', 'ICadastralFabricRegeneration', 'ICadastralUnitConversion', 'ICadastralGroundToGridTools', 'ICadastralUnitTools', 'ICadastralFabricEditControl', 'IDataMessage', 'ITemporalOperator', 'ITrackingServiceDef', '_ITemporalFeatureClassEvents', 'ITemporalFeatureClass2', 'ITemporalTable', 'IInternalTable', 'ITemporalObservationsTable', 'ITemporalObjectTable', 'ITemporalObservationsTable2', 'IExcludedEventIDs', 'ITemporalQueryFilter', 'ITemporalQueryFilter2', 'IListener', 'ITemporalFeature', 'IAMSDatasetName', 'ITemporalFeatureClassStatistics', 'ITemporalWorkspaceStatistics', 'ITemporalWorkspaceStatistics2', 'ILockedFeatureSearch', 'ITxWorkspaceEditor', 'ITemporalRecordSet', 'ITxFeatureClass', 'ITxEnumTrackId', 'ITemporalCursor', 'ITerrain', 'IDynamicSurface', 'ITerrain2', 'IDynamicSurface2', 'IDynamicSurface3', 'TerrainWorkspaceExtension', 'TerrainName', 'TerrainDataSource', 'TerrainPyramidLevelZTolerance', 'TerrainPyramidLevelWindowSize', 'DETerrain', 'TerrainLasDataImporter', 'TerrainAsciiDataImporter', 'TerrainBlobReader', 'TerrainBlobWriter', 'TerrainBlockCursor', 'TerrainFieldStatistics', 'GPTerrainMembership', 'DETerrainType', 'TerrainFeatureDatasetExtension', 'Terrain', 'DynamicSurface', 'LasDatasetWorkspaceFactory', 'LasDatasetName', 'LasDataset', 'LasFilter', 'LasPointInfo', 'LasHeaderInfo', 'LasFile', 'LasSurface', 'LasStatistics', 'LasAttributeStatistics', 'LasReturnStatistics', 'LasClassCodeStatistics', 'LasPointEnumerator', 'LasToRasterFunction', 'LasToRasterFunctionArguments', 'TerrainToRasterFunction', 'TerrainToRasterFunctionArguments', 'LasDatasetToRasterFunction', 'LasDatasetToRasterFunctionArguments', 'CadastralFabric', 'CadastralFabricName', 'CadastralWorkspaceDatasetExtension', 'DECadastralFabric', 'CadastralFabricFDExtension', 'CadastralJob', 'CadastralTransformationData', 'CadastralTableFieldEdits', 'DECadastralFabricType', 'ParcelConstructionData', 'LineResequencer', 'CadastralFabricRegenerator', 'CadastralUnitConversion', 'CadastralDataTools', 'IID_IDETerrain', 'IID_IDETerrainWindowSize', 'IID_ITerrainDataSource', 'IID_ITerrainPyramidLevel', 'IID_IEnumEnvelope', 'IID_ITerrainEdit', 'IID_ITerrainEdit2', 'IID_ITerrainEdit3', 'IID_ITerrainName', 'IID_ITerrainDataSource2', 'IID_ITerrainEmbeddedDataSource', 'IID_ITerrainFieldStatistics', 'IID_ITerrainEmbeddedDataSource2', 'IID_ITerrainBlockCursor', 'IID_ITerrainDataImporter', 'IID_ITerrainLasDataImporter', 'IID_ITerrainAsciiDataImporter', 'IID_ITerrainAsciiDataImporter2', 'IID_ITerrainLasDataInfo', 'IID_ITerrainBlobReader', 'IID_ITerrainBlobWriter', 'IID_ITerrainEditEvents', 'IID_ITerrainLasDataInfo2', 'IID_IGPTerrainMembership', 'IID_ISimpleStatistics', 'IID_ILasReturnStatistics', 'IID_ILasClassCodeStatistics', 'IID_ILasStatistics', 'IID_ILasHeaderInfo', 'IID_ILasFile', 'IID_ILasAttributeFilter', 'IID_ILasPointFilter', 'IID_ILasFilter', 'IID_ILasSurface', 'IID_ILasDataset', 'IID_ILasDatasetEdit', 'IID_IEnumLasPoint', 'IID_ILasPointInfo', 'IID_ILasPointCloud', 'IID_ILasDatasetWorkspace', 'IID_ILasDataset2', 'IID_ILasPointEdit', 'IID_ICadastralJob', 'IID_ICadastralFabric', 'IID_ICadastralFabric2', 'IID_ICadastralFabric3', 'IID_ICadastralFabricName', 'IID_IDECadastralFabric', 'IID_ICadastralTransformationData', 'IID_ICadastralAdjustmentVectors', 'IID_ICadastralFabricLocks', 'IID_ICadastralFabricLocks2', 'IID_ICadastralFabricSchemaEdit', 'IID_ICadastralFabricSchemaEdit2', 'IID_ICadastralTableFieldEdits', 'IID_IDECadastralFabric2', 'IID_IDECadastralFabric3', 'IID_IParcelConstructionData', 'IID_IConstructionParentParcels', 'IID_IConstructionBreakPoints', 'IID_IConstructionBasisOfBearing', 'IID_IConstructionJoinLinks', 'IID_IConstructionUnbuildableLines', 'IID_IConstructionPoints', 'IID_IConstructionAdjustment', 'IID_ILineResequencer', 'IID_ICadastralFabricRegeneration', 'IID_ICadastralUnitConversion', 'IID_ICadastralGroundToGridTools', 'IID_ICadastralUnitTools', 'IID_ICadastralFabricEditControl', 'IID_IDataMessage', 'IID_ITemporalOperator', 'IID_ITrackingServiceDef', 'IID__ITemporalFeatureClassEvents', 'IID_ITemporalFeatureClass2', 'IID_ITemporalTable', 'IID_IInternalTable', 'IID_ITemporalObservationsTable', 'IID_ITemporalObjectTable', 'IID_ITemporalObservationsTable2', 'IID_IExcludedEventIDs', 'IID_ITemporalQueryFilter', 'IID_ITemporalQueryFilter2', 'IID_IListener', 'IID_ITemporalFeature', 'IID_IAMSDatasetName', 'IID_ITemporalFeatureClassStatistics', 'IID_ITemporalWorkspaceStatistics', 'IID_ITemporalWorkspaceStatistics2', 'IID_ILockedFeatureSearch', 'IID_ITxWorkspaceEditor', 'IID_ITemporalRecordSet', 'IID_ITxFeatureClass', 'IID_ITxEnumTrackId', 'IID_ITemporalCursor', 'IID_ITerrain', 'IID_IDynamicSurface', 'IID_ITerrain2', 'IID_IDynamicSurface2', 'IID_IDynamicSurface3', 'CLSID_TerrainWorkspaceExtension', 'CLSID_TerrainName', 'CLSID_TerrainDataSource', 'CLSID_TerrainPyramidLevelZTolerance', 'CLSID_TerrainPyramidLevelWindowSize', 'CLSID_DETerrain', 'CLSID_TerrainLasDataImporter', 'CLSID_TerrainAsciiDataImporter', 'CLSID_TerrainBlobReader', 'CLSID_TerrainBlobWriter', 'CLSID_TerrainBlockCursor', 'CLSID_TerrainFieldStatistics', 'CLSID_GPTerrainMembership', 'CLSID_DETerrainType', 'CLSID_TerrainFeatureDatasetExtension', 'CLSID_Terrain', 'CLSID_DynamicSurface', 'CLSID_LasDatasetWorkspaceFactory', 'CLSID_LasDatasetName', 'CLSID_LasDataset', 'CLSID_LasFilter', 'CLSID_LasPointInfo', 'CLSID_LasHeaderInfo', 'CLSID_LasFile', 'CLSID_LasSurface', 'CLSID_LasStatistics', 'CLSID_LasAttributeStatistics', 'CLSID_LasReturnStatistics', 'CLSID_LasClassCodeStatistics', 'CLSID_LasPointEnumerator', 'CLSID_LasToRasterFunction', 'CLSID_LasToRasterFunctionArguments', 'CLSID_TerrainToRasterFunction', 'CLSID_TerrainToRasterFunctionArguments', 'CLSID_LasDatasetToRasterFunction', 'CLSID_LasDatasetToRasterFunctionArguments', 'CLSID_CadastralFabric', 'CLSID_CadastralFabricName', 'CLSID_CadastralWorkspaceDatasetExtension', 'CLSID_DECadastralFabric', 'CLSID_CadastralFabricFDExtension', 'CLSID_CadastralJob', 'CLSID_CadastralTransformationData', 'CLSID_CadastralTableFieldEdits', 'CLSID_DECadastralFabricType', 'CLSID_ParcelConstructionData', 'CLSID_LineResequencer', 'CLSID_CadastralFabricRegenerator', 'CLSID_CadastralUnitConversion', 'CLSID_CadastralDataTools', 'esriTerrainPyramidType', 'esriTerrainWindowSizeMethod', 'esriTerrainZThresholdStrategy', 'esriTerrainBlobDataType', 'esriTerrainLasDataPropertyType', 'esriTerrainLasReturnType', 'esriTerrainAsciiDataFormatType', 'esriTerrainDecimalSeparatorType', 'esriTerrainError', 'esriLasAttributeType', 'esriTinPointSelectionMethod', 'esriPointToRasterMethod', 'esriLasZSource', 'esriPointToRasterVoidFillMethod', 'esriLasPointStatsType', 'esriLasDatasetError', 'esriLasClassFlag', 'esriLasClassFlagEditType', 'esriCadastralJob', 'esriCadastralFabricTable', 'esriCadastralPacketSetting', 'esriCadastralLineCategory', 'esriCadastralPointCategory', 'esriCadastralLineParameters', 'esriCadastralDistanceUnits', 'esriCadastralAreaUnits', 'esriCadastralDensifiedType', 'esriCadastralFabricType', 'esriParcelAdjustmentType', 'esriCadastralPropertySetType', 'esriCadastralLinePointCategory', 'esriCadastralRegeneratorSetting', 'enumMessageType', 'enumTemporalOperatorUnits', 'enumTemporalOperatorType', 'enumObjectSource', 'enumShapeSource', 'enumPurgeRule', 'enumTemporalOrder', 'enumTemporalRelation', 'enumTemporalConversion', 'enumTemporalFeatureType', 'esriTxFeatureClassCachingMode', 'enumTemporalSource', 'enumTemporalCursorType', 'RGB32']
from cartocomutils import _esriGeoDatabaseExtensions
from cartocomutils._esriGeoDatabaseExtensions import TerrainWorkspaceExtension, TerrainName, TerrainDataSource, TerrainPyramidLevelZTolerance, TerrainPyramidLevelWindowSize, DETerrain, TerrainLasDataImporter, TerrainAsciiDataImporter, TerrainBlobReader, TerrainBlobWriter, TerrainBlockCursor, TerrainFieldStatistics, GPTerrainMembership, DETerrainType, TerrainFeatureDatasetExtension, Terrain, DynamicSurface, LasDatasetWorkspaceFactory, LasDatasetName, LasDataset, LasFilter, LasPointInfo, LasHeaderInfo, LasFile, LasSurface, LasStatistics, LasAttributeStatistics, LasReturnStatistics, LasClassCodeStatistics, LasPointEnumerator, LasToRasterFunction, LasToRasterFunctionArguments, TerrainToRasterFunction, TerrainToRasterFunctionArguments, LasDatasetToRasterFunction, LasDatasetToRasterFunctionArguments, CadastralFabric, CadastralFabricName, CadastralWorkspaceDatasetExtension, DECadastralFabric, CadastralFabricFDExtension, CadastralJob, CadastralTransformationData, CadastralTableFieldEdits, DECadastralFabricType, ParcelConstructionData, LineResequencer, CadastralFabricRegenerator, CadastralUnitConversion, CadastralDataTools
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IDETerrain(_esriGeoDatabaseExtensions.IDETerrain):
    _IID = uuid.UUID('0911f2fb-4b12-4012-ae6b-94fad2d2084d')

    def __init__(self, *args, **kw):
        super(IDETerrain, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Name(self, pName):
        '''Method IDETerrain.put_Name

           INPUT
            pName               : BSTR'''
        return super(IDETerrain, self).put_Name(pName)
    def get_Name(self):
        '''Method IDETerrain.get_Name

           OUTPUT
            pName               : BSTR*'''
        return super(IDETerrain, self).get_Name()
    def put_TileSize(self, pSize):
        '''Method IDETerrain.put_TileSize

           INPUT
            pSize               : double'''
        return super(IDETerrain, self).put_TileSize(pSize)
    def get_TileSize(self):
        '''Method IDETerrain.get_TileSize

           OUTPUT
            pSize               : double*'''
        return super(IDETerrain, self).get_TileSize()
    def put_PyramidType(self, pType):
        '''Method IDETerrain.put_PyramidType

           INPUT
            pType               : esriTerrainPyramidType'''
        return super(IDETerrain, self).put_PyramidType(pType)
    def get_PyramidType(self):
        '''Method IDETerrain.get_PyramidType

           OUTPUT
            pType               : esriTerrainPyramidType*'''
        return super(IDETerrain, self).get_PyramidType()
    def put_MaxOverviewTerrainPoints(self, pcPoints):
        '''Method IDETerrain.put_MaxOverviewTerrainPoints

           INPUT
            pcPoints            : long'''
        return super(IDETerrain, self).put_MaxOverviewTerrainPoints(pcPoints)
    def get_MaxOverviewTerrainPoints(self):
        '''Method IDETerrain.get_MaxOverviewTerrainPoints

           OUTPUT
            pcPoints            : long*'''
        return super(IDETerrain, self).get_MaxOverviewTerrainPoints()
    def put_MaxPointsPerShape(self, pcPoints):
        '''Method IDETerrain.put_MaxPointsPerShape

           INPUT
            pcPoints            : long'''
        return super(IDETerrain, self).put_MaxPointsPerShape(pcPoints)
    def get_MaxPointsPerShape(self):
        '''Method IDETerrain.get_MaxPointsPerShape

           OUTPUT
            pcPoints            : long*'''
        return super(IDETerrain, self).get_MaxPointsPerShape()
    def put_ConfigurationKeyword(self, pConfigKeyword):
        '''Method IDETerrain.put_ConfigurationKeyword

           INPUT
            pConfigKeyword      : BSTR'''
        return super(IDETerrain, self).put_ConfigurationKeyword(pConfigKeyword)
    def get_ConfigurationKeyword(self):
        '''Method IDETerrain.get_ConfigurationKeyword

           OUTPUT
            pConfigKeyword      : BSTR*'''
        return super(IDETerrain, self).get_ConfigurationKeyword()
    ConfigurationKeyword = property(get_ConfigurationKeyword, put_ConfigurationKeyword, None)
    MaxOverviewTerrainPoints = property(get_MaxOverviewTerrainPoints, put_MaxOverviewTerrainPoints, None)
    MaxPointsPerShape = property(get_MaxPointsPerShape, put_MaxPointsPerShape, None)
    Name = property(get_Name, put_Name, None)
    PyramidType = property(get_PyramidType, put_PyramidType, None)
    TileSize = property(get_TileSize, put_TileSize, None)

class IDETerrainWindowSize(_esriGeoDatabaseExtensions.IDETerrainWindowSize):
    _IID = uuid.UUID('62b845f1-6b66-406d-870d-2afd3c00dc48')

    def __init__(self, *args, **kw):
        super(IDETerrainWindowSize, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Method(self, pMethod):
        '''Method IDETerrainWindowSize.put_Method

           INPUT
            pMethod             : esriTerrainWindowSizeMethod'''
        return super(IDETerrainWindowSize, self).put_Method(pMethod)
    def get_Method(self):
        '''Method IDETerrainWindowSize.get_Method

           OUTPUT
            pMethod             : esriTerrainWindowSizeMethod*'''
        return super(IDETerrainWindowSize, self).get_Method()
    def put_ZThreshold(self, pThreshold):
        '''Method IDETerrainWindowSize.put_ZThreshold

           INPUT
            pThreshold          : double'''
        return super(IDETerrainWindowSize, self).put_ZThreshold(pThreshold)
    def get_ZThreshold(self):
        '''Method IDETerrainWindowSize.get_ZThreshold

           OUTPUT
            pThreshold          : double*'''
        return super(IDETerrainWindowSize, self).get_ZThreshold()
    def put_ZThresholdStrategy(self, pStrategy):
        '''Method IDETerrainWindowSize.put_ZThresholdStrategy

           INPUT
            pStrategy           : esriTerrainZThresholdStrategy'''
        return super(IDETerrainWindowSize, self).put_ZThresholdStrategy(pStrategy)
    def get_ZThresholdStrategy(self):
        '''Method IDETerrainWindowSize.get_ZThresholdStrategy

           OUTPUT
            pStrategy           : esriTerrainZThresholdStrategy*'''
        return super(IDETerrainWindowSize, self).get_ZThresholdStrategy()
    Method = property(get_Method, put_Method, None)
    ZThreshold = property(get_ZThreshold, put_ZThreshold, None)
    ZThresholdStrategy = property(get_ZThresholdStrategy, put_ZThresholdStrategy, None)

class ITerrainDataSource(_esriGeoDatabaseExtensions.ITerrainDataSource):
    _IID = uuid.UUID('4d228018-1ec1-4fcc-9646-9c6a67f9ef3c')

    def __init__(self, *args, **kw):
        super(ITerrainDataSource, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_FeatureClassID(self, pClassID):
        '''Method ITerrainDataSource.put_FeatureClassID

           INPUT
            pClassID            : long'''
        return super(ITerrainDataSource, self).put_FeatureClassID(pClassID)
    def get_FeatureClassID(self):
        '''Method ITerrainDataSource.get_FeatureClassID

           OUTPUT
            pClassID            : long*'''
        return super(ITerrainDataSource, self).get_FeatureClassID()
    def put_GroupID(self, pGroupID):
        '''Method ITerrainDataSource.put_GroupID

           INPUT
            pGroupID            : long'''
        return super(ITerrainDataSource, self).put_GroupID(pGroupID)
    def get_GroupID(self):
        '''Method ITerrainDataSource.get_GroupID

           OUTPUT
            pGroupID            : long*'''
        return super(ITerrainDataSource, self).get_GroupID()
    def put_HeightField(self, pFieldName):
        '''Method ITerrainDataSource.put_HeightField

           INPUT
            pFieldName          : BSTR'''
        return super(ITerrainDataSource, self).put_HeightField(pFieldName)
    def get_HeightField(self):
        '''Method ITerrainDataSource.get_HeightField

           OUTPUT
            pFieldName          : BSTR*'''
        return super(ITerrainDataSource, self).get_HeightField()
    def put_TagValueField(self, pFieldName):
        '''Method ITerrainDataSource.put_TagValueField

           INPUT
            pFieldName          : BSTR'''
        return super(ITerrainDataSource, self).put_TagValueField(pFieldName)
    def get_TagValueField(self):
        '''Method ITerrainDataSource.get_TagValueField

           OUTPUT
            pFieldName          : BSTR*'''
        return super(ITerrainDataSource, self).get_TagValueField()
    def put_SurfaceFeatureType(self, pType):
        '''Method ITerrainDataSource.put_SurfaceFeatureType

           INPUT
            pType               : esriTinSurfaceType'''
        return super(ITerrainDataSource, self).put_SurfaceFeatureType(pType)
    def get_SurfaceFeatureType(self):
        '''Method ITerrainDataSource.get_SurfaceFeatureType

           OUTPUT
            pType               : esriTinSurfaceType*'''
        return super(ITerrainDataSource, self).get_SurfaceFeatureType()
    def put_ApplyToOverviewTerrain(self, pbApply):
        '''Method ITerrainDataSource.put_ApplyToOverviewTerrain

           INPUT
            pbApply             : VARIANT_BOOL'''
        return super(ITerrainDataSource, self).put_ApplyToOverviewTerrain(pbApply)
    def get_ApplyToOverviewTerrain(self):
        '''Method ITerrainDataSource.get_ApplyToOverviewTerrain

           OUTPUT
            pbApply             : VARIANT_BOOL*'''
        return super(ITerrainDataSource, self).get_ApplyToOverviewTerrain()
    def get_Embedded(self):
        '''Method ITerrainDataSource.get_Embedded

           OUTPUT
            pbEmbedded          : VARIANT_BOOL*'''
        return super(ITerrainDataSource, self).get_Embedded()
    def SetResolutionBounds(self, lowerBound, upperBound):
        '''Method ITerrainDataSource.SetResolutionBounds

           INPUTS
            lowerBound          : double
            upperBound          : double'''
        return super(ITerrainDataSource, self).SetResolutionBounds(lowerBound, upperBound)
    def QueryResolutionBounds(self):
        '''Method ITerrainDataSource.QueryResolutionBounds

           OUTPUTS
            pLowerBound         : double*
            pUpperBound         : double*'''
        return super(ITerrainDataSource, self).QueryResolutionBounds()
    ApplyToOverviewTerrain = property(get_ApplyToOverviewTerrain, put_ApplyToOverviewTerrain, None)
    Embedded = property(get_Embedded, None, None)
    FeatureClassID = property(get_FeatureClassID, put_FeatureClassID, None)
    GroupID = property(get_GroupID, put_GroupID, None)
    HeightField = property(get_HeightField, put_HeightField, None)
    SurfaceFeatureType = property(get_SurfaceFeatureType, put_SurfaceFeatureType, None)
    TagValueField = property(get_TagValueField, put_TagValueField, None)

class ITerrainPyramidLevel(_esriGeoDatabaseExtensions.ITerrainPyramidLevel):
    _IID = uuid.UUID('9ff889cd-ee5d-4093-9bf2-8384002d01a4')

    def __init__(self, *args, **kw):
        super(ITerrainPyramidLevel, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_PyramidType(self):
        '''Method ITerrainPyramidLevel.get_PyramidType

           OUTPUT
            pType               : esriTerrainPyramidType*'''
        return super(ITerrainPyramidLevel, self).get_PyramidType()
    def put_Resolution(self, pResolution):
        '''Method ITerrainPyramidLevel.put_Resolution

           INPUT
            pResolution         : double'''
        return super(ITerrainPyramidLevel, self).put_Resolution(pResolution)
    def get_Resolution(self):
        '''Method ITerrainPyramidLevel.get_Resolution

           OUTPUT
            pResolution         : double*'''
        return super(ITerrainPyramidLevel, self).get_Resolution()
    def put_MaxScale(self, pScale):
        '''Method ITerrainPyramidLevel.put_MaxScale

           INPUT
            pScale              : long'''
        return super(ITerrainPyramidLevel, self).put_MaxScale(pScale)
    def get_MaxScale(self):
        '''Method ITerrainPyramidLevel.get_MaxScale

           OUTPUT
            pScale              : long*'''
        return super(ITerrainPyramidLevel, self).get_MaxScale()
    MaxScale = property(get_MaxScale, put_MaxScale, None)
    PyramidType = property(get_PyramidType, None, None)
    Resolution = property(get_Resolution, put_Resolution, None)

class IEnumEnvelope(_esriGeoDatabaseExtensions.IEnumEnvelope):
    _IID = uuid.UUID('dba7c9d4-ace6-4973-89aa-3313a7d5d853')
    def get_Count(self):
        '''Method IEnumEnvelope.get_Count

           OUTPUT
            pCount              : long*'''
        return super(IEnumEnvelope, self).get_Count()
    def Reset(self):
        '''Method IEnumEnvelope.Reset'''
        return super(IEnumEnvelope, self).Reset()
    def Next(self):
        '''Method IEnumEnvelope.Next

           OUTPUT
            ppEnvelope          : IEnvelope**'''
        return super(IEnumEnvelope, self).Next()
    def __iter__(self):
        try:
            super(IEnumEnvelope, self).Reset()
            val = super(IEnumEnvelope, self).Next()
            while val:
                yield val
                val = super(IEnumEnvelope, self).Next()
        except:
            pass
    def QueryNext(self, pEnvelope):
        '''Method IEnumEnvelope.QueryNext

           INPUT
            pEnvelope           : IEnvelope*'''
        return super(IEnumEnvelope, self).QueryNext(pEnvelope)
    Count = property(get_Count, None, None)

class ITerrainEdit(_esriGeoDatabaseExtensions.ITerrainEdit):
    _IID = uuid.UUID('8e9c9736-60b1-4db5-af18-ed40f41d4714')
    def AddDataSource(self, pDataSource):
        '''Method ITerrainEdit.AddDataSource

           INPUT
            pDataSource         : ITerrainDataSource*'''
        return super(ITerrainEdit, self).AddDataSource(pDataSource)
    def RemoveDataSource(self, index):
        '''Method ITerrainEdit.RemoveDataSource

           INPUT
            index               : long'''
        return super(ITerrainEdit, self).RemoveDataSource(index)
    def AddPyramidLevel(self, pPyramidLevel):
        '''Method ITerrainEdit.AddPyramidLevel

           INPUT
            pPyramidLevel       : ITerrainPyramidLevel*'''
        return super(ITerrainEdit, self).AddPyramidLevel(pPyramidLevel)
    def RemovePyramidLevel(self, index):
        '''Method ITerrainEdit.RemovePyramidLevel

           INPUT
            index               : long'''
        return super(ITerrainEdit, self).RemovePyramidLevel(index)
    def ChangeMaxScale(self, index, newScale):
        '''Method ITerrainEdit.ChangeMaxScale

           INPUTS
            index               : long
            newScale            : long'''
        return super(ITerrainEdit, self).ChangeMaxScale(index, newScale)
    def ChangeResolutionBounds(self, index, lowerBound, upperBound):
        '''Method ITerrainEdit.ChangeResolutionBounds

           INPUTS
            index               : long
            lowerBound          : double
            upperBound          : double'''
        return super(ITerrainEdit, self).ChangeResolutionBounds(index, lowerBound, upperBound)
    def DeleteDataSourceData(self, index, pAOI, pTrackCancel):
        '''Method ITerrainEdit.DeleteDataSourceData

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit, self).DeleteDataSourceData(index, pAOI, pTrackCancel)
    def AddDataSourceData(self, index, pAOI, pInFC, pTrackCancel):
        '''Method ITerrainEdit.AddDataSourceData

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            pInFC               : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit, self).AddDataSourceData(index, pAOI, pInFC, pTrackCancel)
    def ReplaceDataSourceData(self, index, pAOI, pInFC, pTrackCancel):
        '''Method ITerrainEdit.ReplaceDataSourceData

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            pInFC               : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit, self).ReplaceDataSourceData(index, pAOI, pInFC, pTrackCancel)
    def Build(self, pTrackCancel):
        '''Method ITerrainEdit.Build

           INPUT
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit, self).Build(pTrackCancel)

class ITerrainEdit2(_esriGeoDatabaseExtensions.ITerrainEdit2):
    _IID = uuid.UUID('ed9009eb-18f0-436e-9385-0f0007dd1f90')
    def UpdateExtent(self, pTrackCancel):
        '''Method ITerrainEdit2.UpdateExtent

           INPUT
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit2, self).UpdateExtent(pTrackCancel)
    def AddDataSource(self, pDataSource):
        '''Method ITerrainEdit.AddDataSource (from ITerrainEdit)

           INPUT
            pDataSource         : ITerrainDataSource*'''
        return super(ITerrainEdit2, self).AddDataSource(pDataSource)
    def RemoveDataSource(self, index):
        '''Method ITerrainEdit.RemoveDataSource (from ITerrainEdit)

           INPUT
            index               : long'''
        return super(ITerrainEdit2, self).RemoveDataSource(index)
    def AddPyramidLevel(self, pPyramidLevel):
        '''Method ITerrainEdit.AddPyramidLevel (from ITerrainEdit)

           INPUT
            pPyramidLevel       : ITerrainPyramidLevel*'''
        return super(ITerrainEdit2, self).AddPyramidLevel(pPyramidLevel)
    def RemovePyramidLevel(self, index):
        '''Method ITerrainEdit.RemovePyramidLevel (from ITerrainEdit)

           INPUT
            index               : long'''
        return super(ITerrainEdit2, self).RemovePyramidLevel(index)
    def ChangeMaxScale(self, index, newScale):
        '''Method ITerrainEdit.ChangeMaxScale (from ITerrainEdit)

           INPUTS
            index               : long
            newScale            : long'''
        return super(ITerrainEdit2, self).ChangeMaxScale(index, newScale)
    def ChangeResolutionBounds(self, index, lowerBound, upperBound):
        '''Method ITerrainEdit.ChangeResolutionBounds (from ITerrainEdit)

           INPUTS
            index               : long
            lowerBound          : double
            upperBound          : double'''
        return super(ITerrainEdit2, self).ChangeResolutionBounds(index, lowerBound, upperBound)
    def DeleteDataSourceData(self, index, pAOI, pTrackCancel):
        '''Method ITerrainEdit.DeleteDataSourceData (from ITerrainEdit)

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit2, self).DeleteDataSourceData(index, pAOI, pTrackCancel)
    def AddDataSourceData(self, index, pAOI, pInFC, pTrackCancel):
        '''Method ITerrainEdit.AddDataSourceData (from ITerrainEdit)

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            pInFC               : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit2, self).AddDataSourceData(index, pAOI, pInFC, pTrackCancel)
    def ReplaceDataSourceData(self, index, pAOI, pInFC, pTrackCancel):
        '''Method ITerrainEdit.ReplaceDataSourceData (from ITerrainEdit)

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            pInFC               : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit2, self).ReplaceDataSourceData(index, pAOI, pInFC, pTrackCancel)
    def Build(self, pTrackCancel):
        '''Method ITerrainEdit.Build (from ITerrainEdit)

           INPUT
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit2, self).Build(pTrackCancel)

class ITerrainEdit3(_esriGeoDatabaseExtensions.ITerrainEdit3):
    _IID = uuid.UUID('a7e67808-29d5-4dd9-8696-06993fa838b4')
    def ChangeUsageInOverview(self, index, bApply):
        '''Method ITerrainEdit3.ChangeUsageInOverview

           INPUTS
            index               : long
            bApply              : VARIANT_BOOL'''
        return super(ITerrainEdit3, self).ChangeUsageInOverview(index, bApply)
    def DeleteDataSourceDataByFC(self, index, pointCountFieldName, pFC, bSparseData, pTrackCancel):
        '''Method ITerrainEdit3.DeleteDataSourceDataByFC

           INPUTS
            index               : long
            pointCountFieldName : BSTR
            pFC                 : IFeatureClass*
            bSparseData         : VARIANT_BOOL
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).DeleteDataSourceDataByFC(index, pointCountFieldName, pFC, bSparseData, pTrackCancel)
    def DeleteDataSourceData2(self, index, pointCountFieldName, pAOI, pTrackCancel):
        '''Method ITerrainEdit3.DeleteDataSourceData2

           INPUTS
            index               : long
            pointCountFieldName : BSTR
            pAOI                : IGeometry*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).DeleteDataSourceData2(index, pointCountFieldName, pAOI, pTrackCancel)
    def AddDataSourceData2(self, index, pointCountFieldName, pAOI, pInFC, pTrackCancel):
        '''Method ITerrainEdit3.AddDataSourceData2

           INPUTS
            index               : long
            pointCountFieldName : BSTR
            pAOI                : IGeometry*
            pInFC               : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).AddDataSourceData2(index, pointCountFieldName, pAOI, pInFC, pTrackCancel)
    def ReplaceDataSourceData2(self, index, pointCountFieldName, pAOI, pInFC, pTrackCancel):
        '''Method ITerrainEdit3.ReplaceDataSourceData2

           INPUTS
            index               : long
            pointCountFieldName : BSTR
            pAOI                : IGeometry*
            pInFC               : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).ReplaceDataSourceData2(index, pointCountFieldName, pAOI, pInFC, pTrackCancel)
    def CalculateFieldStatistics(self, index, pFieldNames, pTrackCancel):
        '''Method ITerrainEdit3.CalculateFieldStatistics

           INPUTS
            index               : long
            pFieldNames         : IStringArray*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).CalculateFieldStatistics(index, pFieldNames, pTrackCancel)
    def UpdateExtent(self, pTrackCancel):
        '''Method ITerrainEdit2.UpdateExtent (from ITerrainEdit2)

           INPUT
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).UpdateExtent(pTrackCancel)
    def AddDataSource(self, pDataSource):
        '''Method ITerrainEdit.AddDataSource (from ITerrainEdit)

           INPUT
            pDataSource         : ITerrainDataSource*'''
        return super(ITerrainEdit3, self).AddDataSource(pDataSource)
    def RemoveDataSource(self, index):
        '''Method ITerrainEdit.RemoveDataSource (from ITerrainEdit)

           INPUT
            index               : long'''
        return super(ITerrainEdit3, self).RemoveDataSource(index)
    def AddPyramidLevel(self, pPyramidLevel):
        '''Method ITerrainEdit.AddPyramidLevel (from ITerrainEdit)

           INPUT
            pPyramidLevel       : ITerrainPyramidLevel*'''
        return super(ITerrainEdit3, self).AddPyramidLevel(pPyramidLevel)
    def RemovePyramidLevel(self, index):
        '''Method ITerrainEdit.RemovePyramidLevel (from ITerrainEdit)

           INPUT
            index               : long'''
        return super(ITerrainEdit3, self).RemovePyramidLevel(index)
    def ChangeMaxScale(self, index, newScale):
        '''Method ITerrainEdit.ChangeMaxScale (from ITerrainEdit)

           INPUTS
            index               : long
            newScale            : long'''
        return super(ITerrainEdit3, self).ChangeMaxScale(index, newScale)
    def ChangeResolutionBounds(self, index, lowerBound, upperBound):
        '''Method ITerrainEdit.ChangeResolutionBounds (from ITerrainEdit)

           INPUTS
            index               : long
            lowerBound          : double
            upperBound          : double'''
        return super(ITerrainEdit3, self).ChangeResolutionBounds(index, lowerBound, upperBound)
    def DeleteDataSourceData(self, index, pAOI, pTrackCancel):
        '''Method ITerrainEdit.DeleteDataSourceData (from ITerrainEdit)

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).DeleteDataSourceData(index, pAOI, pTrackCancel)
    def AddDataSourceData(self, index, pAOI, pInFC, pTrackCancel):
        '''Method ITerrainEdit.AddDataSourceData (from ITerrainEdit)

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            pInFC               : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).AddDataSourceData(index, pAOI, pInFC, pTrackCancel)
    def ReplaceDataSourceData(self, index, pAOI, pInFC, pTrackCancel):
        '''Method ITerrainEdit.ReplaceDataSourceData (from ITerrainEdit)

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            pInFC               : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).ReplaceDataSourceData(index, pAOI, pInFC, pTrackCancel)
    def Build(self, pTrackCancel):
        '''Method ITerrainEdit.Build (from ITerrainEdit)

           INPUT
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrainEdit3, self).Build(pTrackCancel)

class ITerrainName(_esriGeoDatabaseExtensions.ITerrainName):
    _IID = uuid.UUID('fa7b8f6e-c012-4e16-afb9-62b8ce0f9011')

    def __init__(self, *args, **kw):
        super(ITerrainName, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def putref_FeatureDatasetName(self, ppFeatureDatasetName):
        '''Method ITerrainName.putref_FeatureDatasetName

           INPUT
            ppFeatureDatasetName: IDatasetName*'''
        return super(ITerrainName, self).putref_FeatureDatasetName(ppFeatureDatasetName)
    def get_FeatureDatasetName(self):
        '''Method ITerrainName.get_FeatureDatasetName

           OUTPUT
            ppFeatureDatasetName: IDatasetName**'''
        return super(ITerrainName, self).get_FeatureDatasetName()
    FeatureDatasetName = property(get_FeatureDatasetName, putref_FeatureDatasetName, None)

class ITerrainDataSource2(_esriGeoDatabaseExtensions.ITerrainDataSource2):
    _IID = uuid.UUID('17b45aaf-fdb2-4492-87c6-9578b20001bd')

    def __init__(self, *args, **kw):
        super(ITerrainDataSource2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Anchored(self, pbAnchored):
        '''Method ITerrainDataSource2.put_Anchored

           INPUT
            pbAnchored          : VARIANT_BOOL'''
        return super(ITerrainDataSource2, self).put_Anchored(pbAnchored)
    def get_Anchored(self):
        '''Method ITerrainDataSource2.get_Anchored

           OUTPUT
            pbAnchored          : VARIANT_BOOL*'''
        return super(ITerrainDataSource2, self).get_Anchored()
    def put_FeatureClassID(self, pClassID):
        '''Method ITerrainDataSource.put_FeatureClassID (from ITerrainDataSource)

           INPUT
            pClassID            : long'''
        return super(ITerrainDataSource2, self).put_FeatureClassID(pClassID)
    def get_FeatureClassID(self):
        '''Method ITerrainDataSource.get_FeatureClassID (from ITerrainDataSource)

           OUTPUT
            pClassID            : long*'''
        return super(ITerrainDataSource2, self).get_FeatureClassID()
    def put_GroupID(self, pGroupID):
        '''Method ITerrainDataSource.put_GroupID (from ITerrainDataSource)

           INPUT
            pGroupID            : long'''
        return super(ITerrainDataSource2, self).put_GroupID(pGroupID)
    def get_GroupID(self):
        '''Method ITerrainDataSource.get_GroupID (from ITerrainDataSource)

           OUTPUT
            pGroupID            : long*'''
        return super(ITerrainDataSource2, self).get_GroupID()
    def put_HeightField(self, pFieldName):
        '''Method ITerrainDataSource.put_HeightField (from ITerrainDataSource)

           INPUT
            pFieldName          : BSTR'''
        return super(ITerrainDataSource2, self).put_HeightField(pFieldName)
    def get_HeightField(self):
        '''Method ITerrainDataSource.get_HeightField (from ITerrainDataSource)

           OUTPUT
            pFieldName          : BSTR*'''
        return super(ITerrainDataSource2, self).get_HeightField()
    def put_TagValueField(self, pFieldName):
        '''Method ITerrainDataSource.put_TagValueField (from ITerrainDataSource)

           INPUT
            pFieldName          : BSTR'''
        return super(ITerrainDataSource2, self).put_TagValueField(pFieldName)
    def get_TagValueField(self):
        '''Method ITerrainDataSource.get_TagValueField (from ITerrainDataSource)

           OUTPUT
            pFieldName          : BSTR*'''
        return super(ITerrainDataSource2, self).get_TagValueField()
    def put_SurfaceFeatureType(self, pType):
        '''Method ITerrainDataSource.put_SurfaceFeatureType (from ITerrainDataSource)

           INPUT
            pType               : esriTinSurfaceType'''
        return super(ITerrainDataSource2, self).put_SurfaceFeatureType(pType)
    def get_SurfaceFeatureType(self):
        '''Method ITerrainDataSource.get_SurfaceFeatureType (from ITerrainDataSource)

           OUTPUT
            pType               : esriTinSurfaceType*'''
        return super(ITerrainDataSource2, self).get_SurfaceFeatureType()
    def put_ApplyToOverviewTerrain(self, pbApply):
        '''Method ITerrainDataSource.put_ApplyToOverviewTerrain (from ITerrainDataSource)

           INPUT
            pbApply             : VARIANT_BOOL'''
        return super(ITerrainDataSource2, self).put_ApplyToOverviewTerrain(pbApply)
    def get_ApplyToOverviewTerrain(self):
        '''Method ITerrainDataSource.get_ApplyToOverviewTerrain (from ITerrainDataSource)

           OUTPUT
            pbApply             : VARIANT_BOOL*'''
        return super(ITerrainDataSource2, self).get_ApplyToOverviewTerrain()
    def get_Embedded(self):
        '''Method ITerrainDataSource.get_Embedded (from ITerrainDataSource)

           OUTPUT
            pbEmbedded          : VARIANT_BOOL*'''
        return super(ITerrainDataSource2, self).get_Embedded()
    def SetResolutionBounds(self, lowerBound, upperBound):
        '''Method ITerrainDataSource.SetResolutionBounds (from ITerrainDataSource)

           INPUTS
            lowerBound          : double
            upperBound          : double'''
        return super(ITerrainDataSource2, self).SetResolutionBounds(lowerBound, upperBound)
    def QueryResolutionBounds(self):
        '''Method ITerrainDataSource.QueryResolutionBounds (from ITerrainDataSource)

           OUTPUTS
            pLowerBound         : double*
            pUpperBound         : double*'''
        return super(ITerrainDataSource2, self).QueryResolutionBounds()
    Anchored = property(get_Anchored, put_Anchored, None)
    ApplyToOverviewTerrain = property(get_ApplyToOverviewTerrain, put_ApplyToOverviewTerrain, None)
    Embedded = property(get_Embedded, None, None)
    FeatureClassID = property(get_FeatureClassID, put_FeatureClassID, None)
    GroupID = property(get_GroupID, put_GroupID, None)
    HeightField = property(get_HeightField, put_HeightField, None)
    SurfaceFeatureType = property(get_SurfaceFeatureType, put_SurfaceFeatureType, None)
    TagValueField = property(get_TagValueField, put_TagValueField, None)

class ITerrainEmbeddedDataSource(_esriGeoDatabaseExtensions.ITerrainEmbeddedDataSource):
    _IID = uuid.UUID('36a1b4a5-d296-433d-ac4f-4da50d020812')

    def __init__(self, *args, **kw):
        super(ITerrainEmbeddedDataSource, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ToBeEmbedded(self, pbToBeEmbedded):
        '''Method ITerrainEmbeddedDataSource.put_ToBeEmbedded

           INPUT
            pbToBeEmbedded      : VARIANT_BOOL'''
        return super(ITerrainEmbeddedDataSource, self).put_ToBeEmbedded(pbToBeEmbedded)
    def get_ToBeEmbedded(self):
        '''Method ITerrainEmbeddedDataSource.get_ToBeEmbedded

           OUTPUT
            pbToBeEmbedded      : VARIANT_BOOL*'''
        return super(ITerrainEmbeddedDataSource, self).get_ToBeEmbedded()
    def put_Name(self, pName):
        '''Method ITerrainEmbeddedDataSource.put_Name

           INPUT
            pName               : BSTR'''
        return super(ITerrainEmbeddedDataSource, self).put_Name(pName)
    def get_Name(self):
        '''Method ITerrainEmbeddedDataSource.get_Name

           OUTPUT
            pName               : BSTR*'''
        return super(ITerrainEmbeddedDataSource, self).get_Name()
    def SetReservedFields(self, pFields):
        '''Method ITerrainEmbeddedDataSource.SetReservedFields

           INPUT
            pFields             : IStringArray*'''
        return super(ITerrainEmbeddedDataSource, self).SetReservedFields(pFields)
    def GetReservedFields(self):
        '''Method ITerrainEmbeddedDataSource.GetReservedFields

           OUTPUT
            ppFields            : IStringArray**'''
        return super(ITerrainEmbeddedDataSource, self).GetReservedFields()
    Name = property(get_Name, put_Name, None)
    ToBeEmbedded = property(get_ToBeEmbedded, put_ToBeEmbedded, None)

class ITerrainFieldStatistics(_esriGeoDatabaseExtensions.ITerrainFieldStatistics):
    _IID = uuid.UUID('3f30b349-518b-41fa-9f2e-e00d6f81af82')
    def get_IsEmpty(self):
        '''Method ITerrainFieldStatistics.get_IsEmpty

           OUTPUT
            pbIsEmpty           : VARIANT_BOOL*'''
        return super(ITerrainFieldStatistics, self).get_IsEmpty()
    def get_NeedsUpdate(self):
        '''Method ITerrainFieldStatistics.get_NeedsUpdate

           OUTPUT
            pbNeedsUpdate       : VARIANT_BOOL*'''
        return super(ITerrainFieldStatistics, self).get_NeedsUpdate()
    def get_FieldName(self):
        '''Method ITerrainFieldStatistics.get_FieldName

           OUTPUT
            pName               : BSTR*'''
        return super(ITerrainFieldStatistics, self).get_FieldName()
    def get_Count(self):
        '''Method ITerrainFieldStatistics.get_Count

           OUTPUT
            pCount              : double*'''
        return super(ITerrainFieldStatistics, self).get_Count()
    def get_Minimum(self):
        '''Method ITerrainFieldStatistics.get_Minimum

           OUTPUT
            pMinimum            : double*'''
        return super(ITerrainFieldStatistics, self).get_Minimum()
    def get_Maximum(self):
        '''Method ITerrainFieldStatistics.get_Maximum

           OUTPUT
            pMaximum            : double*'''
        return super(ITerrainFieldStatistics, self).get_Maximum()
    def get_Mean(self):
        '''Method ITerrainFieldStatistics.get_Mean

           OUTPUT
            pMean               : double*'''
        return super(ITerrainFieldStatistics, self).get_Mean()
    def get_StandardDeviation(self):
        '''Method ITerrainFieldStatistics.get_StandardDeviation

           OUTPUT
            pStandardDeviation  : double*'''
        return super(ITerrainFieldStatistics, self).get_StandardDeviation()
    def get_UniqueValueType(self):
        '''Method ITerrainFieldStatistics.get_UniqueValueType

           OUTPUT
            pType               : esriTerrainBlobDataType*'''
        return super(ITerrainFieldStatistics, self).get_UniqueValueType()
    def GetUniqueValuesAsLong(self):
        '''Method ITerrainFieldStatistics.GetUniqueValuesAsLong

           OUTPUT
            ppValues            : ILongArray**'''
        return super(ITerrainFieldStatistics, self).GetUniqueValuesAsLong()
    def GetUniqueValuesAsDouble(self):
        '''Method ITerrainFieldStatistics.GetUniqueValuesAsDouble

           OUTPUT
            ppValues            : IDoubleArray**'''
        return super(ITerrainFieldStatistics, self).GetUniqueValuesAsDouble()
    def GetUniqueValueCounts(self):
        '''Method ITerrainFieldStatistics.GetUniqueValueCounts

           OUTPUT
            ppCounts            : IDoubleArray**'''
        return super(ITerrainFieldStatistics, self).GetUniqueValueCounts()
    Count = property(get_Count, None, None)
    FieldName = property(get_FieldName, None, None)
    IsEmpty = property(get_IsEmpty, None, None)
    Maximum = property(get_Maximum, None, None)
    Mean = property(get_Mean, None, None)
    Minimum = property(get_Minimum, None, None)
    NeedsUpdate = property(get_NeedsUpdate, None, None)
    StandardDeviation = property(get_StandardDeviation, None, None)
    UniqueValueType = property(get_UniqueValueType, None, None)

class ITerrainEmbeddedDataSource2(_esriGeoDatabaseExtensions.ITerrainEmbeddedDataSource2):
    _IID = uuid.UUID('7a0bb0b6-b097-4fbf-be95-d32473b75ab1')

    def __init__(self, *args, **kw):
        super(ITerrainEmbeddedDataSource2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def GetFieldStatistics(self, FieldName):
        '''Method ITerrainEmbeddedDataSource2.GetFieldStatistics

           INPUT
            FieldName           : BSTR

           OUTPUT
            ppStatistics        : ITerrainFieldStatistics**'''
        return super(ITerrainEmbeddedDataSource2, self).GetFieldStatistics(FieldName)
    def GetReservedFieldStatistics(self):
        '''Method ITerrainEmbeddedDataSource2.GetReservedFieldStatistics

           OUTPUT
            ppStatistics        : IArray**'''
        return super(ITerrainEmbeddedDataSource2, self).GetReservedFieldStatistics()
    def put_ToBeEmbedded(self, pbToBeEmbedded):
        '''Method ITerrainEmbeddedDataSource.put_ToBeEmbedded (from ITerrainEmbeddedDataSource)

           INPUT
            pbToBeEmbedded      : VARIANT_BOOL'''
        return super(ITerrainEmbeddedDataSource2, self).put_ToBeEmbedded(pbToBeEmbedded)
    def get_ToBeEmbedded(self):
        '''Method ITerrainEmbeddedDataSource.get_ToBeEmbedded (from ITerrainEmbeddedDataSource)

           OUTPUT
            pbToBeEmbedded      : VARIANT_BOOL*'''
        return super(ITerrainEmbeddedDataSource2, self).get_ToBeEmbedded()
    def put_Name(self, pName):
        '''Method ITerrainEmbeddedDataSource.put_Name (from ITerrainEmbeddedDataSource)

           INPUT
            pName               : BSTR'''
        return super(ITerrainEmbeddedDataSource2, self).put_Name(pName)
    def get_Name(self):
        '''Method ITerrainEmbeddedDataSource.get_Name (from ITerrainEmbeddedDataSource)

           OUTPUT
            pName               : BSTR*'''
        return super(ITerrainEmbeddedDataSource2, self).get_Name()
    def SetReservedFields(self, pFields):
        '''Method ITerrainEmbeddedDataSource.SetReservedFields (from ITerrainEmbeddedDataSource)

           INPUT
            pFields             : IStringArray*'''
        return super(ITerrainEmbeddedDataSource2, self).SetReservedFields(pFields)
    def GetReservedFields(self):
        '''Method ITerrainEmbeddedDataSource.GetReservedFields (from ITerrainEmbeddedDataSource)

           OUTPUT
            ppFields            : IStringArray**'''
        return super(ITerrainEmbeddedDataSource2, self).GetReservedFields()
    Name = property(get_Name, put_Name, None)
    ToBeEmbedded = property(get_ToBeEmbedded, put_ToBeEmbedded, None)

class ITerrainBlockCursor(_esriGeoDatabaseExtensions.ITerrainBlockCursor):
    _IID = uuid.UUID('3f4fe9ad-471b-4d67-8f8f-930a23a60305')
    def get_BlockCount(self):
        '''Method ITerrainBlockCursor.get_BlockCount

           OUTPUT
            pcBlocks            : long*'''
        return super(ITerrainBlockCursor, self).get_BlockCount()
    def Next(self):
        '''Method ITerrainBlockCursor.Next

           OUTPUTS
            pRowBegin           : long*
            pRowEnd             : long*
            pColBegin           : long*
            pColEnd             : long*
            pbIsEnd             : VARIANT_BOOL*'''
        return super(ITerrainBlockCursor, self).Next()
    def __iter__(self):
        try:
            super(ITerrainBlockCursor, self).Reset()
            val = super(ITerrainBlockCursor, self).Next()
            while any(val):
                yield val
                val = super(ITerrainBlockCursor, self).Next()
        except:
            pass
    def NextAsTin(self):
        '''Method ITerrainBlockCursor.NextAsTin

           OUTPUTS
            ppTin               : ITin**
            ppExtent            : IEnvelope**'''
        return super(ITerrainBlockCursor, self).NextAsTin()
    def Reset(self):
        '''Method ITerrainBlockCursor.Reset'''
        return super(ITerrainBlockCursor, self).Reset()
    BlockCount = property(get_BlockCount, None, None)

class ITerrainDataImporter(_esriGeoDatabaseExtensions.ITerrainDataImporter):
    _IID = uuid.UUID('36b3f42a-abe0-440e-a266-8b8592c74c82')
    def SetSourceDataSpatialReference(self, pSpatialRef):
        '''Method ITerrainDataImporter.SetSourceDataSpatialReference

           INPUT
            pSpatialRef         : ISpatialReference*'''
        return super(ITerrainDataImporter, self).SetSourceDataSpatialReference(pSpatialRef)
    def SetEmpty(self):
        '''Method ITerrainDataImporter.SetEmpty'''
        return super(ITerrainDataImporter, self).SetEmpty()
    def get_MaxShapePointCount(self):
        '''Method ITerrainDataImporter.get_MaxShapePointCount

           OUTPUT
            pCount              : long*'''
        return super(ITerrainDataImporter, self).get_MaxShapePointCount()
    def OverwriteMaxShapePointCount(self, newCount):
        '''Method ITerrainDataImporter.OverwriteMaxShapePointCount

           INPUT
            newCount            : long'''
        return super(ITerrainDataImporter, self).OverwriteMaxShapePointCount(newCount)
    def AddFile(self, fileName):
        '''Method ITerrainDataImporter.AddFile

           INPUT
            fileName            : BSTR'''
        return super(ITerrainDataImporter, self).AddFile(fileName)
    def AddFolder(self, folderName, fileExtension, bRecursive):
        '''Method ITerrainDataImporter.AddFolder

           INPUTS
            folderName          : BSTR
            fileExtension       : BSTR
            bRecursive          : VARIANT_BOOL'''
        return super(ITerrainDataImporter, self).AddFolder(folderName, fileExtension, bRecursive)
    def GetDataExtent(self, pTargetSpatialReference):
        '''Method ITerrainDataImporter.GetDataExtent

           INPUT
            pTargetSpatialReference: ISpatialReference*

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ITerrainDataImporter, self).GetDataExtent(pTargetSpatialReference)
    def GetPointCount(self):
        '''Method ITerrainDataImporter.GetPointCount

           OUTPUT
            pCount              : double*'''
        return super(ITerrainDataImporter, self).GetPointCount()
    def Import(self, pOutputFeatureClass, TileSize, ZFactor, pAOI, pTrackCancel):
        '''Method ITerrainDataImporter.Import

           INPUTS
            pOutputFeatureClass : IFeatureClass*
            TileSize            : double
            ZFactor             : double
            pAOI                : IEnvelope*
            pTrackCancel        : ITrackCancel*

           OUTPUT
            pcOutsidePoints     : long*'''
        return super(ITerrainDataImporter, self).Import(pOutputFeatureClass, TileSize, ZFactor, pAOI, pTrackCancel)
    MaxShapePointCount = property(get_MaxShapePointCount, None, None)

class ITerrainLasDataImporter(_esriGeoDatabaseExtensions.ITerrainLasDataImporter):
    _IID = uuid.UUID('80e83e8c-2ec1-4090-b399-411fa593b25b')
    def AddProperty(self, property, FieldName):
        '''Method ITerrainLasDataImporter.AddProperty

           INPUTS
            property            : esriTerrainLasDataPropertyType
            FieldName           : BSTR'''
        return super(ITerrainLasDataImporter, self).AddProperty(property, FieldName)
    def AddReturnNumber(self, ReturnNumber):
        '''Method ITerrainLasDataImporter.AddReturnNumber

           INPUT
            ReturnNumber        : esriTerrainLasReturnType'''
        return super(ITerrainLasDataImporter, self).AddReturnNumber(ReturnNumber)
    def SetClassCodes(self, pCodes):
        '''Method ITerrainLasDataImporter.SetClassCodes

           INPUT
            pCodes              : ILongArray*'''
        return super(ITerrainLasDataImporter, self).SetClassCodes(pCodes)
    def SetSourceDataSpatialReference(self, pSpatialRef):
        '''Method ITerrainDataImporter.SetSourceDataSpatialReference (from ITerrainDataImporter)

           INPUT
            pSpatialRef         : ISpatialReference*'''
        return super(ITerrainLasDataImporter, self).SetSourceDataSpatialReference(pSpatialRef)
    def SetEmpty(self):
        '''Method ITerrainDataImporter.SetEmpty (from ITerrainDataImporter)'''
        return super(ITerrainLasDataImporter, self).SetEmpty()
    def get_MaxShapePointCount(self):
        '''Method ITerrainDataImporter.get_MaxShapePointCount (from ITerrainDataImporter)

           OUTPUT
            pCount              : long*'''
        return super(ITerrainLasDataImporter, self).get_MaxShapePointCount()
    def OverwriteMaxShapePointCount(self, newCount):
        '''Method ITerrainDataImporter.OverwriteMaxShapePointCount (from ITerrainDataImporter)

           INPUT
            newCount            : long'''
        return super(ITerrainLasDataImporter, self).OverwriteMaxShapePointCount(newCount)
    def AddFile(self, fileName):
        '''Method ITerrainDataImporter.AddFile (from ITerrainDataImporter)

           INPUT
            fileName            : BSTR'''
        return super(ITerrainLasDataImporter, self).AddFile(fileName)
    def AddFolder(self, folderName, fileExtension, bRecursive):
        '''Method ITerrainDataImporter.AddFolder (from ITerrainDataImporter)

           INPUTS
            folderName          : BSTR
            fileExtension       : BSTR
            bRecursive          : VARIANT_BOOL'''
        return super(ITerrainLasDataImporter, self).AddFolder(folderName, fileExtension, bRecursive)
    def GetDataExtent(self, pTargetSpatialReference):
        '''Method ITerrainDataImporter.GetDataExtent (from ITerrainDataImporter)

           INPUT
            pTargetSpatialReference: ISpatialReference*

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ITerrainLasDataImporter, self).GetDataExtent(pTargetSpatialReference)
    def GetPointCount(self):
        '''Method ITerrainDataImporter.GetPointCount (from ITerrainDataImporter)

           OUTPUT
            pCount              : double*'''
        return super(ITerrainLasDataImporter, self).GetPointCount()
    def Import(self, pOutputFeatureClass, TileSize, ZFactor, pAOI, pTrackCancel):
        '''Method ITerrainDataImporter.Import (from ITerrainDataImporter)

           INPUTS
            pOutputFeatureClass : IFeatureClass*
            TileSize            : double
            ZFactor             : double
            pAOI                : IEnvelope*
            pTrackCancel        : ITrackCancel*

           OUTPUT
            pcOutsidePoints     : long*'''
        return super(ITerrainLasDataImporter, self).Import(pOutputFeatureClass, TileSize, ZFactor, pAOI, pTrackCancel)
    MaxShapePointCount = property(get_MaxShapePointCount, None, None)

class ITerrainAsciiDataImporter(_esriGeoDatabaseExtensions.ITerrainAsciiDataImporter):
    _IID = uuid.UUID('8d2d47f1-75bb-4346-b245-4178e9eb9b38')

    def __init__(self, *args, **kw):
        super(ITerrainAsciiDataImporter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_FileFormat(self, pFormat):
        '''Method ITerrainAsciiDataImporter.put_FileFormat

           INPUT
            pFormat             : esriTerrainAsciiDataFormatType'''
        return super(ITerrainAsciiDataImporter, self).put_FileFormat(pFormat)
    def get_FileFormat(self):
        '''Method ITerrainAsciiDataImporter.get_FileFormat

           OUTPUT
            pFormat             : esriTerrainAsciiDataFormatType*'''
        return super(ITerrainAsciiDataImporter, self).get_FileFormat()
    def SetSourceDataSpatialReference(self, pSpatialRef):
        '''Method ITerrainDataImporter.SetSourceDataSpatialReference (from ITerrainDataImporter)

           INPUT
            pSpatialRef         : ISpatialReference*'''
        return super(ITerrainAsciiDataImporter, self).SetSourceDataSpatialReference(pSpatialRef)
    def SetEmpty(self):
        '''Method ITerrainDataImporter.SetEmpty (from ITerrainDataImporter)'''
        return super(ITerrainAsciiDataImporter, self).SetEmpty()
    def get_MaxShapePointCount(self):
        '''Method ITerrainDataImporter.get_MaxShapePointCount (from ITerrainDataImporter)

           OUTPUT
            pCount              : long*'''
        return super(ITerrainAsciiDataImporter, self).get_MaxShapePointCount()
    def OverwriteMaxShapePointCount(self, newCount):
        '''Method ITerrainDataImporter.OverwriteMaxShapePointCount (from ITerrainDataImporter)

           INPUT
            newCount            : long'''
        return super(ITerrainAsciiDataImporter, self).OverwriteMaxShapePointCount(newCount)
    def AddFile(self, fileName):
        '''Method ITerrainDataImporter.AddFile (from ITerrainDataImporter)

           INPUT
            fileName            : BSTR'''
        return super(ITerrainAsciiDataImporter, self).AddFile(fileName)
    def AddFolder(self, folderName, fileExtension, bRecursive):
        '''Method ITerrainDataImporter.AddFolder (from ITerrainDataImporter)

           INPUTS
            folderName          : BSTR
            fileExtension       : BSTR
            bRecursive          : VARIANT_BOOL'''
        return super(ITerrainAsciiDataImporter, self).AddFolder(folderName, fileExtension, bRecursive)
    def GetDataExtent(self, pTargetSpatialReference):
        '''Method ITerrainDataImporter.GetDataExtent (from ITerrainDataImporter)

           INPUT
            pTargetSpatialReference: ISpatialReference*

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ITerrainAsciiDataImporter, self).GetDataExtent(pTargetSpatialReference)
    def GetPointCount(self):
        '''Method ITerrainDataImporter.GetPointCount (from ITerrainDataImporter)

           OUTPUT
            pCount              : double*'''
        return super(ITerrainAsciiDataImporter, self).GetPointCount()
    def Import(self, pOutputFeatureClass, TileSize, ZFactor, pAOI, pTrackCancel):
        '''Method ITerrainDataImporter.Import (from ITerrainDataImporter)

           INPUTS
            pOutputFeatureClass : IFeatureClass*
            TileSize            : double
            ZFactor             : double
            pAOI                : IEnvelope*
            pTrackCancel        : ITrackCancel*

           OUTPUT
            pcOutsidePoints     : long*'''
        return super(ITerrainAsciiDataImporter, self).Import(pOutputFeatureClass, TileSize, ZFactor, pAOI, pTrackCancel)
    FileFormat = property(get_FileFormat, put_FileFormat, None)
    MaxShapePointCount = property(get_MaxShapePointCount, None, None)

class ITerrainAsciiDataImporter2(_esriGeoDatabaseExtensions.ITerrainAsciiDataImporter2):
    _IID = uuid.UUID('33f2e5c8-8e0e-4fc2-8b7b-d901c6e90ed8')

    def __init__(self, *args, **kw):
        super(ITerrainAsciiDataImporter2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_DecimalPointType(self, pType):
        '''Method ITerrainAsciiDataImporter2.put_DecimalPointType

           INPUT
            pType               : esriTerrainDecimalSeparatorType'''
        return super(ITerrainAsciiDataImporter2, self).put_DecimalPointType(pType)
    def get_DecimalPointType(self):
        '''Method ITerrainAsciiDataImporter2.get_DecimalPointType

           OUTPUT
            pType               : esriTerrainDecimalSeparatorType*'''
        return super(ITerrainAsciiDataImporter2, self).get_DecimalPointType()
    def put_FileFormat(self, pFormat):
        '''Method ITerrainAsciiDataImporter.put_FileFormat (from ITerrainAsciiDataImporter)

           INPUT
            pFormat             : esriTerrainAsciiDataFormatType'''
        return super(ITerrainAsciiDataImporter2, self).put_FileFormat(pFormat)
    def get_FileFormat(self):
        '''Method ITerrainAsciiDataImporter.get_FileFormat (from ITerrainAsciiDataImporter)

           OUTPUT
            pFormat             : esriTerrainAsciiDataFormatType*'''
        return super(ITerrainAsciiDataImporter2, self).get_FileFormat()
    def SetSourceDataSpatialReference(self, pSpatialRef):
        '''Method ITerrainDataImporter.SetSourceDataSpatialReference (from ITerrainDataImporter)

           INPUT
            pSpatialRef         : ISpatialReference*'''
        return super(ITerrainAsciiDataImporter2, self).SetSourceDataSpatialReference(pSpatialRef)
    def SetEmpty(self):
        '''Method ITerrainDataImporter.SetEmpty (from ITerrainDataImporter)'''
        return super(ITerrainAsciiDataImporter2, self).SetEmpty()
    def get_MaxShapePointCount(self):
        '''Method ITerrainDataImporter.get_MaxShapePointCount (from ITerrainDataImporter)

           OUTPUT
            pCount              : long*'''
        return super(ITerrainAsciiDataImporter2, self).get_MaxShapePointCount()
    def OverwriteMaxShapePointCount(self, newCount):
        '''Method ITerrainDataImporter.OverwriteMaxShapePointCount (from ITerrainDataImporter)

           INPUT
            newCount            : long'''
        return super(ITerrainAsciiDataImporter2, self).OverwriteMaxShapePointCount(newCount)
    def AddFile(self, fileName):
        '''Method ITerrainDataImporter.AddFile (from ITerrainDataImporter)

           INPUT
            fileName            : BSTR'''
        return super(ITerrainAsciiDataImporter2, self).AddFile(fileName)
    def AddFolder(self, folderName, fileExtension, bRecursive):
        '''Method ITerrainDataImporter.AddFolder (from ITerrainDataImporter)

           INPUTS
            folderName          : BSTR
            fileExtension       : BSTR
            bRecursive          : VARIANT_BOOL'''
        return super(ITerrainAsciiDataImporter2, self).AddFolder(folderName, fileExtension, bRecursive)
    def GetDataExtent(self, pTargetSpatialReference):
        '''Method ITerrainDataImporter.GetDataExtent (from ITerrainDataImporter)

           INPUT
            pTargetSpatialReference: ISpatialReference*

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ITerrainAsciiDataImporter2, self).GetDataExtent(pTargetSpatialReference)
    def GetPointCount(self):
        '''Method ITerrainDataImporter.GetPointCount (from ITerrainDataImporter)

           OUTPUT
            pCount              : double*'''
        return super(ITerrainAsciiDataImporter2, self).GetPointCount()
    def Import(self, pOutputFeatureClass, TileSize, ZFactor, pAOI, pTrackCancel):
        '''Method ITerrainDataImporter.Import (from ITerrainDataImporter)

           INPUTS
            pOutputFeatureClass : IFeatureClass*
            TileSize            : double
            ZFactor             : double
            pAOI                : IEnvelope*
            pTrackCancel        : ITrackCancel*

           OUTPUT
            pcOutsidePoints     : long*'''
        return super(ITerrainAsciiDataImporter2, self).Import(pOutputFeatureClass, TileSize, ZFactor, pAOI, pTrackCancel)
    DecimalPointType = property(get_DecimalPointType, put_DecimalPointType, None)
    FileFormat = property(get_FileFormat, put_FileFormat, None)
    MaxShapePointCount = property(get_MaxShapePointCount, None, None)

class ITerrainLasDataInfo(_esriGeoDatabaseExtensions.ITerrainLasDataInfo):
    _IID = uuid.UUID('c1b7f6d6-4f81-4f5b-9922-5f74d3eb1e94')
    def Init(self, lasFileName):
        '''Method ITerrainLasDataInfo.Init

           INPUT
            lasFileName         : BSTR'''
        return super(ITerrainLasDataInfo, self).Init(lasFileName)
    def GetVersion(self):
        '''Method ITerrainLasDataInfo.GetVersion

           OUTPUTS
            pMajor              : long*
            pMinor              : long*'''
        return super(ITerrainLasDataInfo, self).GetVersion()
    def GetSystemID(self):
        '''Method ITerrainLasDataInfo.GetSystemID

           OUTPUT
            pID                 : BSTR*'''
        return super(ITerrainLasDataInfo, self).GetSystemID()
    def GetGeneratingSoftware(self):
        '''Method ITerrainLasDataInfo.GetGeneratingSoftware

           OUTPUT
            pName               : BSTR*'''
        return super(ITerrainLasDataInfo, self).GetGeneratingSoftware()
    def GetFlightDateJulian(self):
        '''Method ITerrainLasDataInfo.GetFlightDateJulian

           OUTPUT
            pDate               : long*'''
        return super(ITerrainLasDataInfo, self).GetFlightDateJulian()
    def GetYear(self):
        '''Method ITerrainLasDataInfo.GetYear

           OUTPUT
            pYear               : long*'''
        return super(ITerrainLasDataInfo, self).GetYear()
    def GetPointDataFormat(self):
        '''Method ITerrainLasDataInfo.GetPointDataFormat

           OUTPUT
            pFormat             : long*'''
        return super(ITerrainLasDataInfo, self).GetPointDataFormat()
    def GetNumberOfPointRecords(self):
        '''Method ITerrainLasDataInfo.GetNumberOfPointRecords

           OUTPUT
            pcRecords           : long*'''
        return super(ITerrainLasDataInfo, self).GetNumberOfPointRecords()
    def GetNumberOfPointsByReturn(self, ReturnNumber):
        '''Method ITerrainLasDataInfo.GetNumberOfPointsByReturn

           INPUT
            ReturnNumber        : long

           OUTPUT
            pcPoints            : long*'''
        return super(ITerrainLasDataInfo, self).GetNumberOfPointsByReturn(ReturnNumber)
    def GetDataExtent(self):
        '''Method ITerrainLasDataInfo.GetDataExtent

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ITerrainLasDataInfo, self).GetDataExtent()
    def GetSpatialReference(self):
        '''Method ITerrainLasDataInfo.GetSpatialReference

           OUTPUT
            ppSpatialReference  : ISpatialReference**'''
        return super(ITerrainLasDataInfo, self).GetSpatialReference()

class ITerrainBlobReader(_esriGeoDatabaseExtensions.ITerrainBlobReader):
    _IID = uuid.UUID('58ce4421-8073-464b-bf90-2ef70384c82e')
    def SetEmpty(self):
        '''Method ITerrainBlobReader.SetEmpty'''
        return super(ITerrainBlobReader, self).SetEmpty()
    def IsKnownBlob(self, pBlob):
        '''Method ITerrainBlobReader.IsKnownBlob

           INPUT
            pBlob               : IMemoryBlobStream*

           OUTPUT
            pbIsKnown           : VARIANT_BOOL*'''
        return super(ITerrainBlobReader, self).IsKnownBlob(pBlob)
    def SetBlob(self, pBlob):
        '''Method ITerrainBlobReader.SetBlob

           INPUT
            pBlob               : IMemoryBlobStream*'''
        return super(ITerrainBlobReader, self).SetBlob(pBlob)
    def GetDataType(self):
        '''Method ITerrainBlobReader.GetDataType

           OUTPUT
            pType               : esriTerrainBlobDataType*'''
        return super(ITerrainBlobReader, self).GetDataType()
    def GetItemCount(self):
        '''Method ITerrainBlobReader.GetItemCount

           OUTPUT
            pcItems             : long*'''
        return super(ITerrainBlobReader, self).GetItemCount()
    def GetValue(self, index):
        '''Method ITerrainBlobReader.GetValue

           INPUT
            index               : long

           OUTPUT
            pValue              : VARIANT*'''
        return super(ITerrainBlobReader, self).GetValue(index)

class ITerrainBlobWriter(_esriGeoDatabaseExtensions.ITerrainBlobWriter):
    _IID = uuid.UUID('6ed22878-8391-4ee1-999f-a9b6be197bd9')
    def BeginAddingValue(self, Type):
        '''Method ITerrainBlobWriter.BeginAddingValue

           INPUT
            Type                : esriTerrainBlobDataType'''
        return super(ITerrainBlobWriter, self).BeginAddingValue(Type)
    def AddValue(self, Value):
        '''Method ITerrainBlobWriter.AddValue

           INPUT
            Value               : VARIANT'''
        return super(ITerrainBlobWriter, self).AddValue(Value)
    def GetItemCount(self):
        '''Method ITerrainBlobWriter.GetItemCount

           OUTPUT
            pcItems             : long*'''
        return super(ITerrainBlobWriter, self).GetItemCount()
    def EndAddingValue(self):
        '''Method ITerrainBlobWriter.EndAddingValue

           OUTPUT
            ppBlob              : IMemoryBlobStream**'''
        return super(ITerrainBlobWriter, self).EndAddingValue()

class ITerrainEditEvents(_esriGeoDatabaseExtensions.ITerrainEditEvents):
    _IID = uuid.UUID('f008ba42-5126-4daf-88ec-005af3a60083')
    def OnBuild(self, pExtent):
        '''Method ITerrainEditEvents.OnBuild

           INPUT
            pExtent             : IEnvelope*'''
        return super(ITerrainEditEvents, self).OnBuild(pExtent)
    def OnUndoBuild(self, pExtent):
        '''Method ITerrainEditEvents.OnUndoBuild

           INPUT
            pExtent             : IEnvelope*'''
        return super(ITerrainEditEvents, self).OnUndoBuild(pExtent)
    def OnRedoBuild(self, pExtent):
        '''Method ITerrainEditEvents.OnRedoBuild

           INPUT
            pExtent             : IEnvelope*'''
        return super(ITerrainEditEvents, self).OnRedoBuild(pExtent)
    def OnReconcile(self):
        '''Method ITerrainEditEvents.OnReconcile'''
        return super(ITerrainEditEvents, self).OnReconcile()
    def OnUndoReconcile(self):
        '''Method ITerrainEditEvents.OnUndoReconcile'''
        return super(ITerrainEditEvents, self).OnUndoReconcile()
    def OnRedoReconcile(self):
        '''Method ITerrainEditEvents.OnRedoReconcile'''
        return super(ITerrainEditEvents, self).OnRedoReconcile()

class ITerrainLasDataInfo2(_esriGeoDatabaseExtensions.ITerrainLasDataInfo2):
    _IID = uuid.UUID('08ac58e1-f142-45db-9847-0d28f6d7d241')
    def GetFileSourceID(self):
        '''Method ITerrainLasDataInfo2.GetFileSourceID

           OUTPUT
            pID                 : long*'''
        return super(ITerrainLasDataInfo2, self).GetFileSourceID()
    def get_IsStandardGpsTime(self):
        '''Method ITerrainLasDataInfo2.get_IsStandardGpsTime

           OUTPUT
            pbIsAStandard       : VARIANT_BOOL*'''
        return super(ITerrainLasDataInfo2, self).get_IsStandardGpsTime()
    def GetPointInfoByClassCode(self, pTrackCancel, pCodes):
        '''Method ITerrainLasDataInfo2.GetPointInfoByClassCode

           INPUTS
            pTrackCancel        : ITrackCancel*
            pCodes              : ILongArray*

           OUTPUTS
            ppCounts            : IDoubleArray**
            ppExtents           : IArray**'''
        return super(ITerrainLasDataInfo2, self).GetPointInfoByClassCode(pTrackCancel, pCodes)
    def Init(self, lasFileName):
        '''Method ITerrainLasDataInfo.Init (from ITerrainLasDataInfo)

           INPUT
            lasFileName         : BSTR'''
        return super(ITerrainLasDataInfo2, self).Init(lasFileName)
    def GetVersion(self):
        '''Method ITerrainLasDataInfo.GetVersion (from ITerrainLasDataInfo)

           OUTPUTS
            pMajor              : long*
            pMinor              : long*'''
        return super(ITerrainLasDataInfo2, self).GetVersion()
    def GetSystemID(self):
        '''Method ITerrainLasDataInfo.GetSystemID (from ITerrainLasDataInfo)

           OUTPUT
            pID                 : BSTR*'''
        return super(ITerrainLasDataInfo2, self).GetSystemID()
    def GetGeneratingSoftware(self):
        '''Method ITerrainLasDataInfo.GetGeneratingSoftware (from ITerrainLasDataInfo)

           OUTPUT
            pName               : BSTR*'''
        return super(ITerrainLasDataInfo2, self).GetGeneratingSoftware()
    def GetFlightDateJulian(self):
        '''Method ITerrainLasDataInfo.GetFlightDateJulian (from ITerrainLasDataInfo)

           OUTPUT
            pDate               : long*'''
        return super(ITerrainLasDataInfo2, self).GetFlightDateJulian()
    def GetYear(self):
        '''Method ITerrainLasDataInfo.GetYear (from ITerrainLasDataInfo)

           OUTPUT
            pYear               : long*'''
        return super(ITerrainLasDataInfo2, self).GetYear()
    def GetPointDataFormat(self):
        '''Method ITerrainLasDataInfo.GetPointDataFormat (from ITerrainLasDataInfo)

           OUTPUT
            pFormat             : long*'''
        return super(ITerrainLasDataInfo2, self).GetPointDataFormat()
    def GetNumberOfPointRecords(self):
        '''Method ITerrainLasDataInfo.GetNumberOfPointRecords (from ITerrainLasDataInfo)

           OUTPUT
            pcRecords           : long*'''
        return super(ITerrainLasDataInfo2, self).GetNumberOfPointRecords()
    def GetNumberOfPointsByReturn(self, ReturnNumber):
        '''Method ITerrainLasDataInfo.GetNumberOfPointsByReturn (from ITerrainLasDataInfo)

           INPUT
            ReturnNumber        : long

           OUTPUT
            pcPoints            : long*'''
        return super(ITerrainLasDataInfo2, self).GetNumberOfPointsByReturn(ReturnNumber)
    def GetDataExtent(self):
        '''Method ITerrainLasDataInfo.GetDataExtent (from ITerrainLasDataInfo)

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ITerrainLasDataInfo2, self).GetDataExtent()
    def GetSpatialReference(self):
        '''Method ITerrainLasDataInfo.GetSpatialReference (from ITerrainLasDataInfo)

           OUTPUT
            ppSpatialReference  : ISpatialReference**'''
        return super(ITerrainLasDataInfo2, self).GetSpatialReference()
    IsStandardGpsTime = property(get_IsStandardGpsTime, None, None)

class IGPTerrainMembership(_esriGeoDatabaseExtensions.IGPTerrainMembership):
    _IID = uuid.UUID('718ad44a-b78f-43e3-8087-ee37cb18ac80')

    def __init__(self, *args, **kw):
        super(IGPTerrainMembership, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TerrainName(self):
        '''Method IGPTerrainMembership.get_TerrainName

           OUTPUT
            Name                : BSTR*'''
        return super(IGPTerrainMembership, self).get_TerrainName()
    def put_TerrainName(self, Name):
        '''Method IGPTerrainMembership.put_TerrainName

           INPUT
            Name                : BSTR'''
        return super(IGPTerrainMembership, self).put_TerrainName(Name)
    TerrainName = property(get_TerrainName, put_TerrainName, None)

class ISimpleStatistics(_esriGeoDatabaseExtensions.ISimpleStatistics):
    _IID = uuid.UUID('cf4000ec-9418-4da3-9c2d-931ace25889c')
    def get_DataType(self):
        '''Method ISimpleStatistics.get_DataType

           OUTPUT
            pType               : VARIANT*'''
        return super(ISimpleStatistics, self).get_DataType()
    def get_Count(self):
        '''Method ISimpleStatistics.get_Count

           OUTPUT
            pCount              : double*'''
        return super(ISimpleStatistics, self).get_Count()
    def get_Minimum(self):
        '''Method ISimpleStatistics.get_Minimum

           OUTPUT
            pMinimum            : double*'''
        return super(ISimpleStatistics, self).get_Minimum()
    def get_Maximum(self):
        '''Method ISimpleStatistics.get_Maximum

           OUTPUT
            pMaximum            : double*'''
        return super(ISimpleStatistics, self).get_Maximum()
    def get_Mean(self):
        '''Method ISimpleStatistics.get_Mean

           OUTPUT
            pMean               : double*'''
        return super(ISimpleStatistics, self).get_Mean()
    def get_StandardDeviation(self):
        '''Method ISimpleStatistics.get_StandardDeviation

           OUTPUT
            pStandardDeviation  : double*'''
        return super(ISimpleStatistics, self).get_StandardDeviation()
    Count = property(get_Count, None, None)
    DataType = property(get_DataType, None, None)
    Maximum = property(get_Maximum, None, None)
    Mean = property(get_Mean, None, None)
    Minimum = property(get_Minimum, None, None)
    StandardDeviation = property(get_StandardDeviation, None, None)

class ILasReturnStatistics(_esriGeoDatabaseExtensions.ILasReturnStatistics):
    _IID = uuid.UUID('15080791-5b91-4f28-9931-1ffe7e7db33e')
    def get_ReturnType(self):
        '''Method ILasReturnStatistics.get_ReturnType

           OUTPUT
            pType               : esriTerrainLasReturnType*'''
        return super(ILasReturnStatistics, self).get_ReturnType()
    def get_PointCount(self):
        '''Method ILasReturnStatistics.get_PointCount

           OUTPUT
            pCount              : double*'''
        return super(ILasReturnStatistics, self).get_PointCount()
    def get_SyntheticPointCount(self):
        '''Method ILasReturnStatistics.get_SyntheticPointCount

           OUTPUT
            pCount              : double*'''
        return super(ILasReturnStatistics, self).get_SyntheticPointCount()
    def get_KeyPointCount(self):
        '''Method ILasReturnStatistics.get_KeyPointCount

           OUTPUT
            pCount              : double*'''
        return super(ILasReturnStatistics, self).get_KeyPointCount()
    def get_Extent(self):
        '''Method ILasReturnStatistics.get_Extent

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ILasReturnStatistics, self).get_Extent()
    Extent = property(get_Extent, None, None)
    KeyPointCount = property(get_KeyPointCount, None, None)
    PointCount = property(get_PointCount, None, None)
    ReturnType = property(get_ReturnType, None, None)
    SyntheticPointCount = property(get_SyntheticPointCount, None, None)

class ILasClassCodeStatistics(_esriGeoDatabaseExtensions.ILasClassCodeStatistics):
    _IID = uuid.UUID('89e4489f-87e2-4690-8385-5143fe6d9753')
    def get_ClassCode(self):
        '''Method ILasClassCodeStatistics.get_ClassCode

           OUTPUT
            pCode               : long*'''
        return super(ILasClassCodeStatistics, self).get_ClassCode()
    def get_PointCount(self):
        '''Method ILasClassCodeStatistics.get_PointCount

           OUTPUT
            pCount              : double*'''
        return super(ILasClassCodeStatistics, self).get_PointCount()
    def get_SyntheticPointCount(self):
        '''Method ILasClassCodeStatistics.get_SyntheticPointCount

           OUTPUT
            pCount              : double*'''
        return super(ILasClassCodeStatistics, self).get_SyntheticPointCount()
    def get_KeyPointCount(self):
        '''Method ILasClassCodeStatistics.get_KeyPointCount

           OUTPUT
            pCount              : double*'''
        return super(ILasClassCodeStatistics, self).get_KeyPointCount()
    def get_Extent(self):
        '''Method ILasClassCodeStatistics.get_Extent

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ILasClassCodeStatistics, self).get_Extent()
    def GetIntensityRange(self):
        '''Method ILasClassCodeStatistics.GetIntensityRange

           OUTPUTS
            pMin                : long*
            pMax                : long*'''
        return super(ILasClassCodeStatistics, self).GetIntensityRange()
    ClassCode = property(get_ClassCode, None, None)
    Extent = property(get_Extent, None, None)
    KeyPointCount = property(get_KeyPointCount, None, None)
    PointCount = property(get_PointCount, None, None)
    SyntheticPointCount = property(get_SyntheticPointCount, None, None)

class ILasStatistics(_esriGeoDatabaseExtensions.ILasStatistics):
    _IID = uuid.UUID('23afc48e-4efb-479f-9164-959e70e01918')
    def get_WithheldPointCount(self):
        '''Method ILasStatistics.get_WithheldPointCount

           OUTPUT
            pCount              : double*'''
        return super(ILasStatistics, self).get_WithheldPointCount()
    def get_WithheldExtent(self):
        '''Method ILasStatistics.get_WithheldExtent

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ILasStatistics, self).get_WithheldExtent()
    def GetAttributeStatistics(self, Attribute):
        '''Method ILasStatistics.GetAttributeStatistics

           INPUT
            Attribute           : esriLasAttributeType

           OUTPUT
            ppStatistics        : ISimpleStatistics**'''
        return super(ILasStatistics, self).GetAttributeStatistics(Attribute)
    def GetUniqueReturns(self):
        '''Method ILasStatistics.GetUniqueReturns

           OUTPUT
            ppReturns           : ILongArray**'''
        return super(ILasStatistics, self).GetUniqueReturns()
    def GetUniqueClassCodes(self):
        '''Method ILasStatistics.GetUniqueClassCodes

           OUTPUT
            ppCodes             : ILongArray**'''
        return super(ILasStatistics, self).GetUniqueClassCodes()
    def GetReturnStatistics(self, Type):
        '''Method ILasStatistics.GetReturnStatistics

           INPUT
            Type                : esriTerrainLasReturnType

           OUTPUT
            ppStatistics        : ILasReturnStatistics**'''
        return super(ILasStatistics, self).GetReturnStatistics(Type)
    def GetClassCodeStatistics(self, ClassCode):
        '''Method ILasStatistics.GetClassCodeStatistics

           INPUT
            ClassCode           : long

           OUTPUT
            ppStatistics        : ILasClassCodeStatistics**'''
        return super(ILasStatistics, self).GetClassCodeStatistics(ClassCode)
    WithheldExtent = property(get_WithheldExtent, None, None)
    WithheldPointCount = property(get_WithheldPointCount, None, None)

class ILasHeaderInfo(_esriGeoDatabaseExtensions.ILasHeaderInfo):
    _IID = uuid.UUID('89f48c7a-ac12-4371-92c3-194559bb354b')
    def GetVersion(self):
        '''Method ILasHeaderInfo.GetVersion

           OUTPUTS
            pMajor              : long*
            pMinor              : long*'''
        return super(ILasHeaderInfo, self).GetVersion()
    def get_PointDataFormat(self):
        '''Method ILasHeaderInfo.get_PointDataFormat

           OUTPUT
            pFormat             : long*'''
        return super(ILasHeaderInfo, self).get_PointDataFormat()
    def get_SystemID(self):
        '''Method ILasHeaderInfo.get_SystemID

           OUTPUT
            pID                 : BSTR*'''
        return super(ILasHeaderInfo, self).get_SystemID()
    def get_GeneratingSoftware(self):
        '''Method ILasHeaderInfo.get_GeneratingSoftware

           OUTPUT
            pName               : BSTR*'''
        return super(ILasHeaderInfo, self).get_GeneratingSoftware()
    def get_FlightDateJulian(self):
        '''Method ILasHeaderInfo.get_FlightDateJulian

           OUTPUT
            pDate               : long*'''
        return super(ILasHeaderInfo, self).get_FlightDateJulian()
    def get_Year(self):
        '''Method ILasHeaderInfo.get_Year

           OUTPUT
            pYear               : long*'''
        return super(ILasHeaderInfo, self).get_Year()
    def get_NumberOfPointRecords(self):
        '''Method ILasHeaderInfo.get_NumberOfPointRecords

           OUTPUT
            pcRecords           : double*'''
        return super(ILasHeaderInfo, self).get_NumberOfPointRecords()
    def GetNumberOfPointsByReturn(self, ReturnNumber):
        '''Method ILasHeaderInfo.GetNumberOfPointsByReturn

           INPUT
            ReturnNumber        : long

           OUTPUT
            pcPoints            : double*'''
        return super(ILasHeaderInfo, self).GetNumberOfPointsByReturn(ReturnNumber)
    def get_ProjectID(self):
        '''Method ILasHeaderInfo.get_ProjectID

           OUTPUT
            ppGuid              : IUID**'''
        return super(ILasHeaderInfo, self).get_ProjectID()
    def get_FileSourceID(self):
        '''Method ILasHeaderInfo.get_FileSourceID

           OUTPUT
            pID                 : long*'''
        return super(ILasHeaderInfo, self).get_FileSourceID()
    def get_HasRGB(self):
        '''Method ILasHeaderInfo.get_HasRGB

           OUTPUT
            pbHasRGB            : VARIANT_BOOL*'''
        return super(ILasHeaderInfo, self).get_HasRGB()
    def get_HasGpsTime(self):
        '''Method ILasHeaderInfo.get_HasGpsTime

           OUTPUT
            pbHasGpsTime        : VARIANT_BOOL*'''
        return super(ILasHeaderInfo, self).get_HasGpsTime()
    def get_IsStandardGpsTime(self):
        '''Method ILasHeaderInfo.get_IsStandardGpsTime

           OUTPUT
            pbIsAStandard       : VARIANT_BOOL*'''
        return super(ILasHeaderInfo, self).get_IsStandardGpsTime()
    def get_Extent(self):
        '''Method ILasHeaderInfo.get_Extent

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ILasHeaderInfo, self).get_Extent()
    def get_SpatialReference(self):
        '''Method ILasHeaderInfo.get_SpatialReference

           OUTPUT
            ppSpatialReference  : ISpatialReference**'''
        return super(ILasHeaderInfo, self).get_SpatialReference()
    def GetOffsets(self):
        '''Method ILasHeaderInfo.GetOffsets

           OUTPUTS
            pOffsetX            : double*
            pOffsetY            : double*
            pOffsetZ            : double*'''
        return super(ILasHeaderInfo, self).GetOffsets()
    def GetScaleFactors(self):
        '''Method ILasHeaderInfo.GetScaleFactors

           OUTPUTS
            pFactorX            : double*
            pFactorY            : double*
            pFactorZ            : double*'''
        return super(ILasHeaderInfo, self).GetScaleFactors()
    def get_NumberOfVariableLengthRecords(self):
        '''Method ILasHeaderInfo.get_NumberOfVariableLengthRecords

           OUTPUT
            pcRecords           : double*'''
        return super(ILasHeaderInfo, self).get_NumberOfVariableLengthRecords()
    def GetVariableLengthRecords(self):
        '''Method ILasHeaderInfo.GetVariableLengthRecords

           OUTPUTS
            ppUserIDs           : IStringArray**
            recordIDs           : ILongArray**
            ppRecordLengths     : IDoubleArray**
            ppDescriptions      : IStringArray**
            pbOverLimit         : VARIANT_BOOL*'''
        return super(ILasHeaderInfo, self).GetVariableLengthRecords()
    Extent = property(get_Extent, None, None)
    FileSourceID = property(get_FileSourceID, None, None)
    FlightDateJulian = property(get_FlightDateJulian, None, None)
    GeneratingSoftware = property(get_GeneratingSoftware, None, None)
    HasGpsTime = property(get_HasGpsTime, None, None)
    HasRGB = property(get_HasRGB, None, None)
    IsStandardGpsTime = property(get_IsStandardGpsTime, None, None)
    NumberOfPointRecords = property(get_NumberOfPointRecords, None, None)
    NumberOfVariableLengthRecords = property(get_NumberOfVariableLengthRecords, None, None)
    PointDataFormat = property(get_PointDataFormat, None, None)
    ProjectID = property(get_ProjectID, None, None)
    SpatialReference = property(get_SpatialReference, None, None)
    SystemID = property(get_SystemID, None, None)
    Year = property(get_Year, None, None)

class ILasFile(_esriGeoDatabaseExtensions.ILasFile):
    _IID = uuid.UUID('36ccbfd3-8a6c-4c11-8551-96ae8629aad9')
    def get_Name(self):
        '''Method ILasFile.get_Name

           OUTPUT
            pName               : BSTR*'''
        return super(ILasFile, self).get_Name()
    def GetVersion(self):
        '''Method ILasFile.GetVersion

           OUTPUTS
            pMajor              : long*
            pMinor              : long*'''
        return super(ILasFile, self).GetVersion()
    def get_PointDataFormat(self):
        '''Method ILasFile.get_PointDataFormat

           OUTPUT
            pFormat             : long*'''
        return super(ILasFile, self).get_PointDataFormat()
    def get_NumberOfPointRecords(self):
        '''Method ILasFile.get_NumberOfPointRecords

           OUTPUT
            pcRecords           : double*'''
        return super(ILasFile, self).get_NumberOfPointRecords()
    def GetNumberOfPointsByReturn(self, ReturnNumber):
        '''Method ILasFile.GetNumberOfPointsByReturn

           INPUT
            ReturnNumber        : long

           OUTPUT
            pcPoints            : double*'''
        return super(ILasFile, self).GetNumberOfPointsByReturn(ReturnNumber)
    def get_SizeInBytes(self):
        '''Method ILasFile.get_SizeInBytes

           OUTPUT
            pcBytes             : double*'''
        return super(ILasFile, self).get_SizeInBytes()
    def get_HasRGB(self):
        '''Method ILasFile.get_HasRGB

           OUTPUT
            pbHasRGB            : VARIANT_BOOL*'''
        return super(ILasFile, self).get_HasRGB()
    def get_HasGpsTime(self):
        '''Method ILasFile.get_HasGpsTime

           OUTPUT
            pbHasGpsTime        : VARIANT_BOOL*'''
        return super(ILasFile, self).get_HasGpsTime()
    def get_IsStandardGpsTime(self):
        '''Method ILasFile.get_IsStandardGpsTime

           OUTPUT
            pbIsAStandard       : VARIANT_BOOL*'''
        return super(ILasFile, self).get_IsStandardGpsTime()
    def get_Extent(self):
        '''Method ILasFile.get_Extent

           OUTPUT
            ppExt               : IEnvelope**'''
        return super(ILasFile, self).get_Extent()
    def get_SpatialReference(self):
        '''Method ILasFile.get_SpatialReference

           OUTPUT
            ppSpatialReference  : ISpatialReference**'''
        return super(ILasFile, self).get_SpatialReference()
    def get_NativeSpatialReference(self):
        '''Method ILasFile.get_NativeSpatialReference

           OUTPUT
            ppSpatialReference  : ISpatialReference**'''
        return super(ILasFile, self).get_NativeSpatialReference()
    def get_IsFileMissing(self):
        '''Method ILasFile.get_IsFileMissing

           OUTPUT
            pbIsMissing         : VARIANT_BOOL*'''
        return super(ILasFile, self).get_IsFileMissing()
    def get_IsFileValid(self):
        '''Method ILasFile.get_IsFileValid

           OUTPUT
            pbIsValid           : VARIANT_BOOL*'''
        return super(ILasFile, self).get_IsFileValid()
    def get_HasPrjFile(self):
        '''Method ILasFile.get_HasPrjFile

           OUTPUT
            pbHasPRJ            : VARIANT_BOOL*'''
        return super(ILasFile, self).get_HasPrjFile()
    def get_HasStatistics(self):
        '''Method ILasFile.get_HasStatistics

           OUTPUT
            pbHasStats          : VARIANT_BOOL*'''
        return super(ILasFile, self).get_HasStatistics()
    def get_NeedsUpdateStatistics(self):
        '''Method ILasFile.get_NeedsUpdateStatistics

           OUTPUT
            pbNeedsUpdate       : VARIANT_BOOL*'''
        return super(ILasFile, self).get_NeedsUpdateStatistics()
    def GetStatistics(self):
        '''Method ILasFile.GetStatistics

           OUTPUT
            ppStatistics        : ILasStatistics**'''
        return super(ILasFile, self).GetStatistics()
    def GetHeaderInfo(self):
        '''Method ILasFile.GetHeaderInfo

           OUTPUT
            ppHeaderInfo        : ILasHeaderInfo**'''
        return super(ILasFile, self).GetHeaderInfo()
    def EstimatePointSpacing(self, bUseStatistics):
        '''Method ILasFile.EstimatePointSpacing

           INPUT
            bUseStatistics      : VARIANT_BOOL

           OUTPUT
            pSpacing            : double*'''
        return super(ILasFile, self).EstimatePointSpacing(bUseStatistics)
    def EstimatePointCount(self, pAOI):
        '''Method ILasFile.EstimatePointCount

           INPUT
            pAOI                : IGeometry*

           OUTPUT
            pcPoints            : double*'''
        return super(ILasFile, self).EstimatePointCount(pAOI)
    Extent = property(get_Extent, None, None)
    HasGpsTime = property(get_HasGpsTime, None, None)
    HasPrjFile = property(get_HasPrjFile, None, None)
    HasRGB = property(get_HasRGB, None, None)
    HasStatistics = property(get_HasStatistics, None, None)
    IsFileMissing = property(get_IsFileMissing, None, None)
    IsFileValid = property(get_IsFileValid, None, None)
    IsStandardGpsTime = property(get_IsStandardGpsTime, None, None)
    Name = property(get_Name, None, None)
    NativeSpatialReference = property(get_NativeSpatialReference, None, None)
    NeedsUpdateStatistics = property(get_NeedsUpdateStatistics, None, None)
    NumberOfPointRecords = property(get_NumberOfPointRecords, None, None)
    PointDataFormat = property(get_PointDataFormat, None, None)
    SizeInBytes = property(get_SizeInBytes, None, None)
    SpatialReference = property(get_SpatialReference, None, None)

class ILasAttributeFilter(_esriGeoDatabaseExtensions.ILasAttributeFilter):
    _IID = uuid.UUID('2a37e73c-2b6d-4d82-9f32-72a2e268394d')

    def __init__(self, *args, **kw):
        super(ILasAttributeFilter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Returns(self, ppReturns):
        '''Method ILasAttributeFilter.put_Returns

           INPUT
            ppReturns           : ILongArray*'''
        return super(ILasAttributeFilter, self).put_Returns(ppReturns)
    def get_Returns(self):
        '''Method ILasAttributeFilter.get_Returns

           OUTPUT
            ppReturns           : ILongArray**'''
        return super(ILasAttributeFilter, self).get_Returns()
    def put_ClassCodes(self, ppCodes):
        '''Method ILasAttributeFilter.put_ClassCodes

           INPUT
            ppCodes             : ILongArray*'''
        return super(ILasAttributeFilter, self).put_ClassCodes(ppCodes)
    def get_ClassCodes(self):
        '''Method ILasAttributeFilter.get_ClassCodes

           OUTPUT
            ppCodes             : ILongArray**'''
        return super(ILasAttributeFilter, self).get_ClassCodes()
    def put_ClassFlags(self, pFlags):
        '''Method ILasAttributeFilter.put_ClassFlags

           INPUT
            pFlags              : long'''
        return super(ILasAttributeFilter, self).put_ClassFlags(pFlags)
    def get_ClassFlags(self):
        '''Method ILasAttributeFilter.get_ClassFlags

           OUTPUT
            pFlags              : long*'''
        return super(ILasAttributeFilter, self).get_ClassFlags()
    ClassCodes = property(get_ClassCodes, put_ClassCodes, None)
    ClassFlags = property(get_ClassFlags, put_ClassFlags, None)
    Returns = property(get_Returns, put_Returns, None)

class ILasPointFilter(_esriGeoDatabaseExtensions.ILasPointFilter):
    _IID = uuid.UUID('53bc0282-1396-450f-bca9-0c3398550895')

    def __init__(self, *args, **kw):
        super(ILasPointFilter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def putref_AreaOfInterest(self, ppAOI):
        '''Method ILasPointFilter.putref_AreaOfInterest

           INPUT
            ppAOI               : IGeometry*'''
        return super(ILasPointFilter, self).putref_AreaOfInterest(ppAOI)
    def get_AreaOfInterest(self):
        '''Method ILasPointFilter.get_AreaOfInterest

           OUTPUT
            ppAOI               : IGeometry**'''
        return super(ILasPointFilter, self).get_AreaOfInterest()
    def put_Returns(self, ppReturns):
        '''Method ILasAttributeFilter.put_Returns (from ILasAttributeFilter)

           INPUT
            ppReturns           : ILongArray*'''
        return super(ILasPointFilter, self).put_Returns(ppReturns)
    def get_Returns(self):
        '''Method ILasAttributeFilter.get_Returns (from ILasAttributeFilter)

           OUTPUT
            ppReturns           : ILongArray**'''
        return super(ILasPointFilter, self).get_Returns()
    def put_ClassCodes(self, ppCodes):
        '''Method ILasAttributeFilter.put_ClassCodes (from ILasAttributeFilter)

           INPUT
            ppCodes             : ILongArray*'''
        return super(ILasPointFilter, self).put_ClassCodes(ppCodes)
    def get_ClassCodes(self):
        '''Method ILasAttributeFilter.get_ClassCodes (from ILasAttributeFilter)

           OUTPUT
            ppCodes             : ILongArray**'''
        return super(ILasPointFilter, self).get_ClassCodes()
    def put_ClassFlags(self, pFlags):
        '''Method ILasAttributeFilter.put_ClassFlags (from ILasAttributeFilter)

           INPUT
            pFlags              : long'''
        return super(ILasPointFilter, self).put_ClassFlags(pFlags)
    def get_ClassFlags(self):
        '''Method ILasAttributeFilter.get_ClassFlags (from ILasAttributeFilter)

           OUTPUT
            pFlags              : long*'''
        return super(ILasPointFilter, self).get_ClassFlags()
    AreaOfInterest = property(get_AreaOfInterest, putref_AreaOfInterest, None)
    ClassCodes = property(get_ClassCodes, put_ClassCodes, None)
    ClassFlags = property(get_ClassFlags, put_ClassFlags, None)
    Returns = property(get_Returns, put_Returns, None)

class ILasFilter(_esriGeoDatabaseExtensions.ILasFilter):
    _IID = uuid.UUID('9ae04cb6-3c51-4322-b5b5-e891e2dcae0b')

    def __init__(self, *args, **kw):
        super(ILasFilter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_SurfaceConstraints(self, ppConstraintIDs):
        '''Method ILasFilter.put_SurfaceConstraints

           INPUT
            ppConstraintIDs     : IArray*'''
        return super(ILasFilter, self).put_SurfaceConstraints(ppConstraintIDs)
    def get_SurfaceConstraints(self):
        '''Method ILasFilter.get_SurfaceConstraints

           OUTPUT
            ppConstraintIDs     : IArray**'''
        return super(ILasFilter, self).get_SurfaceConstraints()
    def Clone(self):
        '''Method ILasFilter.Clone

           OUTPUT
            ppClone             : ILasFilter**'''
        return super(ILasFilter, self).Clone()
    def putref_AreaOfInterest(self, ppAOI):
        '''Method ILasPointFilter.putref_AreaOfInterest (from ILasPointFilter)

           INPUT
            ppAOI               : IGeometry*'''
        return super(ILasFilter, self).putref_AreaOfInterest(ppAOI)
    def get_AreaOfInterest(self):
        '''Method ILasPointFilter.get_AreaOfInterest (from ILasPointFilter)

           OUTPUT
            ppAOI               : IGeometry**'''
        return super(ILasFilter, self).get_AreaOfInterest()
    def put_Returns(self, ppReturns):
        '''Method ILasAttributeFilter.put_Returns (from ILasAttributeFilter)

           INPUT
            ppReturns           : ILongArray*'''
        return super(ILasFilter, self).put_Returns(ppReturns)
    def get_Returns(self):
        '''Method ILasAttributeFilter.get_Returns (from ILasAttributeFilter)

           OUTPUT
            ppReturns           : ILongArray**'''
        return super(ILasFilter, self).get_Returns()
    def put_ClassCodes(self, ppCodes):
        '''Method ILasAttributeFilter.put_ClassCodes (from ILasAttributeFilter)

           INPUT
            ppCodes             : ILongArray*'''
        return super(ILasFilter, self).put_ClassCodes(ppCodes)
    def get_ClassCodes(self):
        '''Method ILasAttributeFilter.get_ClassCodes (from ILasAttributeFilter)

           OUTPUT
            ppCodes             : ILongArray**'''
        return super(ILasFilter, self).get_ClassCodes()
    def put_ClassFlags(self, pFlags):
        '''Method ILasAttributeFilter.put_ClassFlags (from ILasAttributeFilter)

           INPUT
            pFlags              : long'''
        return super(ILasFilter, self).put_ClassFlags(pFlags)
    def get_ClassFlags(self):
        '''Method ILasAttributeFilter.get_ClassFlags (from ILasAttributeFilter)

           OUTPUT
            pFlags              : long*'''
        return super(ILasFilter, self).get_ClassFlags()
    AreaOfInterest = property(get_AreaOfInterest, putref_AreaOfInterest, None)
    ClassCodes = property(get_ClassCodes, put_ClassCodes, None)
    ClassFlags = property(get_ClassFlags, put_ClassFlags, None)
    Returns = property(get_Returns, put_Returns, None)
    SurfaceConstraints = property(get_SurfaceConstraints, put_SurfaceConstraints, None)

class ILasSurface(_esriGeoDatabaseExtensions.ILasSurface):
    _IID = uuid.UUID('81792712-2296-4b3f-ba19-3d37bd0b245d')
    def AsTin(self, pTrackCancel, pFilter, Resolution, Method, ZFactor):
        '''Method ILasSurface.AsTin

           INPUTS
            pTrackCancel        : ITrackCancel*
            pFilter             : ILasFilter*
            Resolution          : double
            Method              : esriTinPointSelectionMethod
            ZFactor             : double

           OUTPUT
            ppTin               : ITin**'''
        return super(ILasSurface, self).AsTin(pTrackCancel, pFilter, Resolution, Method, ZFactor)
    def AsRaster(self, pTrackCancel, pFilter, pDataset, Method, zSource, fillMethod, Type, ZFactor):
        '''Method ILasSurface.AsRaster

           INPUTS
            pTrackCancel        : ITrackCancel*
            pFilter             : ILasFilter*
            pDataset            : IRasterDataset*
            Method              : esriPointToRasterMethod
            zSource             : esriLasZSource
            fillMethod          : esriPointToRasterVoidFillMethod
            Type                : esriSurfaceInterpolationType
            ZFactor             : double'''
        return super(ILasSurface, self).AsRaster(pTrackCancel, pFilter, pDataset, Method, zSource, fillMethod, Type, ZFactor)
    def InterpolateRaster(self, pTrackCancel, pLasFilter, pDataset, Resolution, Method, Type, ZFactor):
        '''Method ILasSurface.InterpolateRaster

           INPUTS
            pTrackCancel        : ITrackCancel*
            pLasFilter          : ILasFilter*
            pDataset            : IRasterDataset*
            Resolution          : double
            Method              : esriTinPointSelectionMethod
            Type                : esriSurfaceInterpolationType
            ZFactor             : double'''
        return super(ILasSurface, self).InterpolateRaster(pTrackCancel, pLasFilter, pDataset, Resolution, Method, Type, ZFactor)
    def InterpolateFeatureClass(self, pTrackCancel, pLasFilter, Resolution, Method, Type, ZFactor, pInClass, pQueryFilter, pOutClass, pStepSize):
        '''Method ILasSurface.InterpolateFeatureClass

           INPUTS
            pTrackCancel        : ITrackCancel*
            pLasFilter          : ILasFilter*
            Resolution          : double
            Method              : esriTinPointSelectionMethod
            Type                : esriSurfaceInterpolationType
            ZFactor             : double
            pInClass            : IFeatureClass*
            pQueryFilter        : IQueryFilter*
            pOutClass           : IFeatureClass*
            pStepSize           : VARIANT*'''
        return super(ILasSurface, self).InterpolateFeatureClass(pTrackCancel, pLasFilter, Resolution, Method, Type, ZFactor, pInClass, pQueryFilter, pOutClass, pStepSize)
    def InterpolateFeatureClassVertices(self, pTrackCancel, pLasFilter, Resolution, Method, Type, ZFactor, pInClass, pQueryFilter, pOutClass):
        '''Method ILasSurface.InterpolateFeatureClassVertices

           INPUTS
            pTrackCancel        : ITrackCancel*
            pLasFilter          : ILasFilter*
            Resolution          : double
            Method              : esriTinPointSelectionMethod
            Type                : esriSurfaceInterpolationType
            ZFactor             : double
            pInClass            : IFeatureClass*
            pQueryFilter        : IQueryFilter*
            pOutClass           : IFeatureClass*'''
        return super(ILasSurface, self).InterpolateFeatureClassVertices(pTrackCancel, pLasFilter, Resolution, Method, Type, ZFactor, pInClass, pQueryFilter, pOutClass)
    def get_CanDoCurvature(self):
        '''Method ILasSurface.get_CanDoCurvature

           OUTPUT
            pbCanDo             : VARIANT_BOOL*'''
        return super(ILasSurface, self).get_CanDoCurvature()
    def GetLineOfSightFeatureClass(self, pTrackCancel, pLasFilter, Resolution, Method, ZFactor, pInputLines, pQueryFilter, pOutputLines, pObstructionPoints, bApplyCurvature, bApplyRefraction, pRefractionFactor):
        '''Method ILasSurface.GetLineOfSightFeatureClass

           INPUTS
            pTrackCancel        : ITrackCancel*
            pLasFilter          : ILasFilter*
            Resolution          : double
            Method              : esriTinPointSelectionMethod
            ZFactor             : double
            pInputLines         : IFeatureClass*
            pQueryFilter        : IQueryFilter*
            pOutputLines        : IFeatureClass*
            pObstructionPoints  : IFeatureClass*
            bApplyCurvature     : VARIANT_BOOL
            bApplyRefraction    : VARIANT_BOOL
            pRefractionFactor   : VARIANT*'''
        return super(ILasSurface, self).GetLineOfSightFeatureClass(pTrackCancel, pLasFilter, Resolution, Method, ZFactor, pInputLines, pQueryFilter, pOutputLines, pObstructionPoints, bApplyCurvature, bApplyRefraction, pRefractionFactor)
    CanDoCurvature = property(get_CanDoCurvature, None, None)

class ILasDataset(_esriGeoDatabaseExtensions.ILasDataset):
    _IID = uuid.UUID('3ac637a3-1671-4dfe-babe-d7947d57f050')
    def SetEmpty(self):
        '''Method ILasDataset.SetEmpty'''
        return super(ILasDataset, self).SetEmpty()
    def Init(self, Name):
        '''Method ILasDataset.Init

           INPUT
            Name                : BSTR'''
        return super(ILasDataset, self).Init(Name)
    def SaveAs(self, Name, bOverWrite):
        '''Method ILasDataset.SaveAs

           INPUTS
            Name                : BSTR
            bOverWrite          : VARIANT_BOOL'''
        return super(ILasDataset, self).SaveAs(Name, bOverWrite)
    def get_Name(self):
        '''Method ILasDataset.get_Name

           OUTPUT
            pName               : BSTR*'''
        return super(ILasDataset, self).get_Name()
    def get_UsesRelativePath(self):
        '''Method ILasDataset.get_UsesRelativePath

           OUTPUT
            pbUsesRelativePath  : VARIANT_BOOL*'''
        return super(ILasDataset, self).get_UsesRelativePath()
    def get_IsDirty(self):
        '''Method ILasDataset.get_IsDirty

           OUTPUT
            pbIsDirty           : VARIANT_BOOL*'''
        return super(ILasDataset, self).get_IsDirty()
    def get_SpatialReference(self):
        '''Method ILasDataset.get_SpatialReference

           OUTPUT
            ppSpatialRef        : ISpatialReference**'''
        return super(ILasDataset, self).get_SpatialReference()
    def get_Extent(self):
        '''Method ILasDataset.get_Extent

           OUTPUT
            ppExtent            : IEnvelope**'''
        return super(ILasDataset, self).get_Extent()
    def get_FileCount(self):
        '''Method ILasDataset.get_FileCount

           OUTPUT
            pcFiles             : long*'''
        return super(ILasDataset, self).get_FileCount()
    def get_File(self, index):
        '''Method ILasDataset.get_File

           INPUT
            index               : long

           OUTPUT
            ppFile              : ILasFile**'''
        return super(ILasDataset, self).get_File(index)
    def get_SurfaceConstraintCount(self):
        '''Method ILasDataset.get_SurfaceConstraintCount

           OUTPUT
            pcConstraints       : long*'''
        return super(ILasDataset, self).get_SurfaceConstraintCount()
    def GetSurfaceConstraint(self, index):
        '''Method ILasDataset.GetSurfaceConstraint

           INPUT
            index               : long

           OUTPUTS
            ppClass             : IFeatureClass**
            ppHeightField       : IField**
            ppTagField          : IField**
            pType               : esriTinSurfaceType*'''
        return super(ILasDataset, self).GetSurfaceConstraint(index)
    def GetSurfaceConstraintName(self, index):
        '''Method ILasDataset.GetSurfaceConstraintName

           INPUT
            index               : long

           OUTPUTS
            ppName              : IFeatureClassName**
            pHeightField        : BSTR*
            pTagField           : BSTR*
            pType               : esriTinSurfaceType*'''
        return super(ILasDataset, self).GetSurfaceConstraintName(index)
    def GetSurfaceConstraintID(self, index):
        '''Method ILasDataset.GetSurfaceConstraintID

           INPUT
            index               : long

           OUTPUT
            ppGuid              : IUID**'''
        return super(ILasDataset, self).GetSurfaceConstraintID(index)
    def GetSurfaceConstraintIndexFromID(self, pGuid):
        '''Method ILasDataset.GetSurfaceConstraintIndexFromID

           INPUT
            pGuid               : IUID*

           OUTPUT
            pIndex              : long*'''
        return super(ILasDataset, self).GetSurfaceConstraintIndexFromID(pGuid)
    def get_PointCount(self):
        '''Method ILasDataset.get_PointCount

           OUTPUT
            pCount              : double*'''
        return super(ILasDataset, self).get_PointCount()
    def get_SizeInBytes(self):
        '''Method ILasDataset.get_SizeInBytes

           OUTPUT
            pcBytes             : double*'''
        return super(ILasDataset, self).get_SizeInBytes()
    def get_HasStatistics(self):
        '''Method ILasDataset.get_HasStatistics

           OUTPUT
            pbHasStats          : VARIANT_BOOL*'''
        return super(ILasDataset, self).get_HasStatistics()
    def get_NeedsUpdateStatistics(self):
        '''Method ILasDataset.get_NeedsUpdateStatistics

           OUTPUT
            pbNeedsUpdate       : VARIANT_BOOL*'''
        return super(ILasDataset, self).get_NeedsUpdateStatistics()
    def GetStatistics(self):
        '''Method ILasDataset.GetStatistics

           OUTPUT
            ppStatistics        : ILasStatistics**'''
        return super(ILasDataset, self).GetStatistics()
    def CreateDynamicSurface(self):
        '''Method ILasDataset.CreateDynamicSurface

           OUTPUT
            ppSurface           : ILasSurface**'''
        return super(ILasDataset, self).CreateDynamicSurface()
    def Export(self, pTrackCancel, FileIndex, pFilter, newFileName, pNewSpatialReference, bProject, bDropVLRs):
        '''Method ILasDataset.Export

           INPUTS
            pTrackCancel        : ITrackCancel*
            FileIndex           : long
            pFilter             : ILasPointFilter*
            newFileName         : BSTR
            pNewSpatialReference: ISpatialReference*
            bProject            : VARIANT_BOOL
            bDropVLRs           : VARIANT_BOOL'''
        return super(ILasDataset, self).Export(pTrackCancel, FileIndex, pFilter, newFileName, pNewSpatialReference, bProject, bDropVLRs)
    Extent = property(get_Extent, None, None)
    FileCount = property(get_FileCount, None, None)
    HasStatistics = property(get_HasStatistics, None, None)
    IsDirty = property(get_IsDirty, None, None)
    Name = property(get_Name, None, None)
    NeedsUpdateStatistics = property(get_NeedsUpdateStatistics, None, None)
    PointCount = property(get_PointCount, None, None)
    SizeInBytes = property(get_SizeInBytes, None, None)
    SpatialReference = property(get_SpatialReference, None, None)
    SurfaceConstraintCount = property(get_SurfaceConstraintCount, None, None)
    UsesRelativePath = property(get_UsesRelativePath, None, None)
    File = IndexProperty(get_File, None)

class ILasDatasetEdit(_esriGeoDatabaseExtensions.ILasDatasetEdit):
    _IID = uuid.UUID('ca6228e2-eb8f-442f-88cb-5e40233e88e8')

    def __init__(self, *args, **kw):
        super(ILasDatasetEdit, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def Save(self):
        '''Method ILasDatasetEdit.Save'''
        return super(ILasDatasetEdit, self).Save()
    def put_UsesRelativePath(self, _arg1):
        '''Method ILasDatasetEdit.put_UsesRelativePath

           INPUT
            _arg1               : VARIANT_BOOL'''
        return super(ILasDatasetEdit, self).put_UsesRelativePath(_arg1)
    def SetSpatialReference(self, pSpatialReference):
        '''Method ILasDatasetEdit.SetSpatialReference

           INPUT
            pSpatialReference   : ISpatialReference*'''
        return super(ILasDatasetEdit, self).SetSpatialReference(pSpatialReference)
    def AddFile(self, fileName):
        '''Method ILasDatasetEdit.AddFile

           INPUT
            fileName            : BSTR'''
        return super(ILasDatasetEdit, self).AddFile(fileName)
    def AddFolder(self, folderName, fileExtension, bRecursive):
        '''Method ILasDatasetEdit.AddFolder

           INPUTS
            folderName          : BSTR
            fileExtension       : BSTR
            bRecursive          : VARIANT_BOOL

           OUTPUT
            ppBadFiles          : IStringArray**'''
        return super(ILasDatasetEdit, self).AddFolder(folderName, fileExtension, bRecursive)
    def RemoveFile(self, index):
        '''Method ILasDatasetEdit.RemoveFile

           INPUT
            index               : long'''
        return super(ILasDatasetEdit, self).RemoveFile(index)
    def RemoveFileByName(self, fileName):
        '''Method ILasDatasetEdit.RemoveFileByName

           INPUT
            fileName            : BSTR'''
        return super(ILasDatasetEdit, self).RemoveFileByName(fileName)
    def AddSurfaceConstraint(self, pFeatureClass, pHeightField, pTagField, Type):
        '''Method ILasDatasetEdit.AddSurfaceConstraint

           INPUTS
            pFeatureClass       : IFeatureClass*
            pHeightField        : IField*
            pTagField           : IField*
            Type                : esriTinSurfaceType'''
        return super(ILasDatasetEdit, self).AddSurfaceConstraint(pFeatureClass, pHeightField, pTagField, Type)
    def RemoveSurfaceConstraint(self, pFeatureClass):
        '''Method ILasDatasetEdit.RemoveSurfaceConstraint

           INPUT
            pFeatureClass       : IFeatureClass*'''
        return super(ILasDatasetEdit, self).RemoveSurfaceConstraint(pFeatureClass)
    def RemoveSurfaceConstraintByID(self, pGuid):
        '''Method ILasDatasetEdit.RemoveSurfaceConstraintByID

           INPUT
            pGuid               : IUID*'''
        return super(ILasDatasetEdit, self).RemoveSurfaceConstraintByID(pGuid)
    def CalculateStatistics(self, pTrackCancel, bForce):
        '''Method ILasDatasetEdit.CalculateStatistics

           INPUTS
            pTrackCancel        : ITrackCancel*
            bForce              : VARIANT_BOOL

           OUTPUT
            ppBadFiles          : ILongArray**'''
        return super(ILasDatasetEdit, self).CalculateStatistics(pTrackCancel, bForce)
    def CalculateFileStatistics(self, pTrackCancel, index):
        '''Method ILasDatasetEdit.CalculateFileStatistics

           INPUTS
            pTrackCancel        : ITrackCancel*
            index               : long'''
        return super(ILasDatasetEdit, self).CalculateFileStatistics(pTrackCancel, index)
    UsesRelativePath = property(None, put_UsesRelativePath, None)

class IEnumLasPoint(_esriGeoDatabaseExtensions.IEnumLasPoint):
    _IID = uuid.UUID('41a9ea2b-b551-4987-a354-7fd3fe6dfc5e')

    def __init__(self, *args, **kw):
        super(IEnumLasPoint, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Attribute(self, pAttribute):
        '''Method IEnumLasPoint.put_Attribute

           INPUT
            pAttribute          : esriLasAttributeType'''
        return super(IEnumLasPoint, self).put_Attribute(pAttribute)
    def get_Attribute(self):
        '''Method IEnumLasPoint.get_Attribute

           OUTPUT
            pAttribute          : esriLasAttributeType*'''
        return super(IEnumLasPoint, self).get_Attribute()
    def Reset(self):
        '''Method IEnumLasPoint.Reset'''
        return super(IEnumLasPoint, self).Reset()
    def Next(self, arraySize, pIntensity, pFileIndices, pPointIDs):
        '''Method IEnumLasPoint.Next

           INPUTS
            arraySize           : long
            pIntensity          : ILongArray*
            pFileIndices        : ILongArray*
            pPointIDs           : IDoubleArray*

           OUTPUTS
            pPointCount         : long*
            pPoints             : WKSPointZ*'''
        return super(IEnumLasPoint, self).Next(arraySize, pIntensity, pFileIndices, pPointIDs)
    def NextAttrLong(self, arraySize, pIntensity, pFileIndices, pPointIDs):
        '''Method IEnumLasPoint.NextAttrLong

           INPUTS
            arraySize           : long
            pIntensity          : ILongArray*
            pFileIndices        : ILongArray*
            pPointIDs           : IDoubleArray*

           OUTPUTS
            pPointCount         : long*
            pPoints             : WKSPointZ*
            pAttribute          : long*'''
        return super(IEnumLasPoint, self).NextAttrLong(arraySize, pIntensity, pFileIndices, pPointIDs)
    def NextAttrDbl(self, arraySize, pIntensity, pFileIndices, pPointIDs):
        '''Method IEnumLasPoint.NextAttrDbl

           INPUTS
            arraySize           : long
            pIntensity          : ILongArray*
            pFileIndices        : ILongArray*
            pPointIDs           : IDoubleArray*

           OUTPUTS
            pPointCount         : long*
            pPoints             : WKSPointZ*
            pAttribute          : double*'''
        return super(IEnumLasPoint, self).NextAttrDbl(arraySize, pIntensity, pFileIndices, pPointIDs)
    def NextAttrRGB32(self, arraySize, pIntensity, pFileIndices, pPointIDs):
        '''Method IEnumLasPoint.NextAttrRGB32

           INPUTS
            arraySize           : long
            pIntensity          : ILongArray*
            pFileIndices        : ILongArray*
            pPointIDs           : IDoubleArray*

           OUTPUTS
            pPointCount         : long*
            pPoints             : WKSPointZ*
            pAttribute          : RGB32*'''
        return super(IEnumLasPoint, self).NextAttrRGB32(arraySize, pIntensity, pFileIndices, pPointIDs)
    def NextLasInfo(self, pInfo):
        '''Method IEnumLasPoint.NextLasInfo

           INPUT
            pInfo               : IArray*

           OUTPUT
            pPointCount         : long*'''
        return super(IEnumLasPoint, self).NextLasInfo(pInfo)
    Attribute = property(get_Attribute, put_Attribute, None)

class ILasPointInfo(_esriGeoDatabaseExtensions.ILasPointInfo):
    _IID = uuid.UUID('c4b222f6-c575-4f6b-b7ee-28e34fea446c')

    def __init__(self, *args, **kw):
        super(ILasPointInfo, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_FileIndex(self, pIndex):
        '''Method ILasPointInfo.put_FileIndex

           INPUT
            pIndex              : long'''
        return super(ILasPointInfo, self).put_FileIndex(pIndex)
    def get_FileIndex(self):
        '''Method ILasPointInfo.get_FileIndex

           OUTPUT
            pIndex              : long*'''
        return super(ILasPointInfo, self).get_FileIndex()
    def put_PointID(self, pID):
        '''Method ILasPointInfo.put_PointID

           INPUT
            pID                 : double'''
        return super(ILasPointInfo, self).put_PointID(pID)
    def get_PointID(self):
        '''Method ILasPointInfo.get_PointID

           OUTPUT
            pID                 : double*'''
        return super(ILasPointInfo, self).get_PointID()
    def put_ReturnNumber(self, pNumber):
        '''Method ILasPointInfo.put_ReturnNumber

           INPUT
            pNumber             : unsignedchar'''
        return super(ILasPointInfo, self).put_ReturnNumber(pNumber)
    def get_ReturnNumber(self):
        '''Method ILasPointInfo.get_ReturnNumber

           OUTPUT
            pNumber             : unsignedchar*'''
        return super(ILasPointInfo, self).get_ReturnNumber()
    def put_NumberOfReturns(self, pCount):
        '''Method ILasPointInfo.put_NumberOfReturns

           INPUT
            pCount              : unsignedchar'''
        return super(ILasPointInfo, self).put_NumberOfReturns(pCount)
    def get_NumberOfReturns(self):
        '''Method ILasPointInfo.get_NumberOfReturns

           OUTPUT
            pCount              : unsignedchar*'''
        return super(ILasPointInfo, self).get_NumberOfReturns()
    def put_ScanDirectionFlag(self, pFlag):
        '''Method ILasPointInfo.put_ScanDirectionFlag

           INPUT
            pFlag               : unsignedchar'''
        return super(ILasPointInfo, self).put_ScanDirectionFlag(pFlag)
    def get_ScanDirectionFlag(self):
        '''Method ILasPointInfo.get_ScanDirectionFlag

           OUTPUT
            pFlag               : unsignedchar*'''
        return super(ILasPointInfo, self).get_ScanDirectionFlag()
    def put_EdgeOfFlightLine(self, pEdge):
        '''Method ILasPointInfo.put_EdgeOfFlightLine

           INPUT
            pEdge               : unsignedchar'''
        return super(ILasPointInfo, self).put_EdgeOfFlightLine(pEdge)
    def get_EdgeOfFlightLine(self):
        '''Method ILasPointInfo.get_EdgeOfFlightLine

           OUTPUT
            pEdge               : unsignedchar*'''
        return super(ILasPointInfo, self).get_EdgeOfFlightLine()
    def put_ClassCode(self, pCode):
        '''Method ILasPointInfo.put_ClassCode

           INPUT
            pCode               : unsignedchar'''
        return super(ILasPointInfo, self).put_ClassCode(pCode)
    def get_ClassCode(self):
        '''Method ILasPointInfo.get_ClassCode

           OUTPUT
            pCode               : unsignedchar*'''
        return super(ILasPointInfo, self).get_ClassCode()
    def put_IsWithheld(self, pbIsWithheld):
        '''Method ILasPointInfo.put_IsWithheld

           INPUT
            pbIsWithheld        : VARIANT_BOOL'''
        return super(ILasPointInfo, self).put_IsWithheld(pbIsWithheld)
    def get_IsWithheld(self):
        '''Method ILasPointInfo.get_IsWithheld

           OUTPUT
            pbIsWithheld        : VARIANT_BOOL*'''
        return super(ILasPointInfo, self).get_IsWithheld()
    def put_IsKeyPoint(self, pbIsKey):
        '''Method ILasPointInfo.put_IsKeyPoint

           INPUT
            pbIsKey             : VARIANT_BOOL'''
        return super(ILasPointInfo, self).put_IsKeyPoint(pbIsKey)
    def get_IsKeyPoint(self):
        '''Method ILasPointInfo.get_IsKeyPoint

           OUTPUT
            pbIsKey             : VARIANT_BOOL*'''
        return super(ILasPointInfo, self).get_IsKeyPoint()
    def put_IsSyntheticPoint(self, pbIsSynthetic):
        '''Method ILasPointInfo.put_IsSyntheticPoint

           INPUT
            pbIsSynthetic       : VARIANT_BOOL'''
        return super(ILasPointInfo, self).put_IsSyntheticPoint(pbIsSynthetic)
    def get_IsSyntheticPoint(self):
        '''Method ILasPointInfo.get_IsSyntheticPoint

           OUTPUT
            pbIsSynthetic       : VARIANT_BOOL*'''
        return super(ILasPointInfo, self).get_IsSyntheticPoint()
    def put_Intensity(self, pIntensity):
        '''Method ILasPointInfo.put_Intensity

           INPUT
            pIntensity          : long'''
        return super(ILasPointInfo, self).put_Intensity(pIntensity)
    def get_Intensity(self):
        '''Method ILasPointInfo.get_Intensity

           OUTPUT
            pIntensity          : long*'''
        return super(ILasPointInfo, self).get_Intensity()
    def put_ScanAngleRank(self, pAngle):
        '''Method ILasPointInfo.put_ScanAngleRank

           INPUT
            pAngle              : short'''
        return super(ILasPointInfo, self).put_ScanAngleRank(pAngle)
    def get_ScanAngleRank(self):
        '''Method ILasPointInfo.get_ScanAngleRank

           OUTPUT
            pAngle              : short*'''
        return super(ILasPointInfo, self).get_ScanAngleRank()
    def put_UserData(self, pData):
        '''Method ILasPointInfo.put_UserData

           INPUT
            pData               : short'''
        return super(ILasPointInfo, self).put_UserData(pData)
    def get_UserData(self):
        '''Method ILasPointInfo.get_UserData

           OUTPUT
            pData               : short*'''
        return super(ILasPointInfo, self).get_UserData()
    def put_PointSourceID(self, pID):
        '''Method ILasPointInfo.put_PointSourceID

           INPUT
            pID                 : long'''
        return super(ILasPointInfo, self).put_PointSourceID(pID)
    def get_PointSourceID(self):
        '''Method ILasPointInfo.get_PointSourceID

           OUTPUT
            pID                 : long*'''
        return super(ILasPointInfo, self).get_PointSourceID()
    def put_GpsTime(self, pTime):
        '''Method ILasPointInfo.put_GpsTime

           INPUT
            pTime               : double'''
        return super(ILasPointInfo, self).put_GpsTime(pTime)
    def get_GpsTime(self):
        '''Method ILasPointInfo.get_GpsTime

           OUTPUT
            pTime               : double*'''
        return super(ILasPointInfo, self).get_GpsTime()
    def SetColor(self, Red, Green, Blue):
        '''Method ILasPointInfo.SetColor

           INPUTS
            Red                 : long
            Green               : long
            Blue                : long'''
        return super(ILasPointInfo, self).SetColor(Red, Green, Blue)
    def GetColor(self):
        '''Method ILasPointInfo.GetColor

           OUTPUTS
            pRed                : long*
            pGreen              : long*
            pBlue               : long*'''
        return super(ILasPointInfo, self).GetColor()
    def put_Location(self, ppPoint):
        '''Method ILasPointInfo.put_Location

           INPUT
            ppPoint             : IPoint*'''
        return super(ILasPointInfo, self).put_Location(ppPoint)
    def get_Location(self):
        '''Method ILasPointInfo.get_Location

           OUTPUT
            ppPoint             : IPoint**'''
        return super(ILasPointInfo, self).get_Location()
    def put_WksLocation(self, pPoint):
        '''Method ILasPointInfo.put_WksLocation

           INPUT
            pPoint              : WKSPointZ*'''
        return super(ILasPointInfo, self).put_WksLocation(pPoint)
    def get_WksLocation(self):
        '''Method ILasPointInfo.get_WksLocation

           OUTPUT
            pPoint              : WKSPointZ*'''
        return super(ILasPointInfo, self).get_WksLocation()
    def QueryLocation(self, pPoint):
        '''Method ILasPointInfo.QueryLocation

           INPUT
            pPoint              : IPoint*'''
        return super(ILasPointInfo, self).QueryLocation(pPoint)
    def putref_SpatialReference(self, ppSpatialRef):
        '''Method ILasPointInfo.putref_SpatialReference

           INPUT
            ppSpatialRef        : ISpatialReference*'''
        return super(ILasPointInfo, self).putref_SpatialReference(ppSpatialRef)
    def get_SpatialReference(self):
        '''Method ILasPointInfo.get_SpatialReference

           OUTPUT
            ppSpatialRef        : ISpatialReference**'''
        return super(ILasPointInfo, self).get_SpatialReference()
    def get_AttributeValue(self, Attribute):
        '''Method ILasPointInfo.get_AttributeValue

           INPUT
            Attribute           : esriLasAttributeType

           OUTPUT
            pValue              : VARIANT*'''
        return super(ILasPointInfo, self).get_AttributeValue(Attribute)
    ClassCode = property(get_ClassCode, put_ClassCode, None)
    EdgeOfFlightLine = property(get_EdgeOfFlightLine, put_EdgeOfFlightLine, None)
    FileIndex = property(get_FileIndex, put_FileIndex, None)
    GpsTime = property(get_GpsTime, put_GpsTime, None)
    Intensity = property(get_Intensity, put_Intensity, None)
    IsKeyPoint = property(get_IsKeyPoint, put_IsKeyPoint, None)
    IsSyntheticPoint = property(get_IsSyntheticPoint, put_IsSyntheticPoint, None)
    IsWithheld = property(get_IsWithheld, put_IsWithheld, None)
    Location = property(get_Location, put_Location, None)
    NumberOfReturns = property(get_NumberOfReturns, put_NumberOfReturns, None)
    PointID = property(get_PointID, put_PointID, None)
    PointSourceID = property(get_PointSourceID, put_PointSourceID, None)
    ReturnNumber = property(get_ReturnNumber, put_ReturnNumber, None)
    ScanAngleRank = property(get_ScanAngleRank, put_ScanAngleRank, None)
    ScanDirectionFlag = property(get_ScanDirectionFlag, put_ScanDirectionFlag, None)
    SpatialReference = property(get_SpatialReference, putref_SpatialReference, None)
    UserData = property(get_UserData, put_UserData, None)
    WksLocation = property(get_WksLocation, put_WksLocation, None)
    AttributeValue = IndexProperty(get_AttributeValue, None)

class ILasPointCloud(_esriGeoDatabaseExtensions.ILasPointCloud):
    _IID = uuid.UUID('1928009d-9153-4ec0-a75c-4c24008d28d5')
    def EstimatePointCount(self, pAOI):
        '''Method ILasPointCloud.EstimatePointCount

           INPUT
            pAOI                : IGeometry*

           OUTPUT
            pcPoints            : double*'''
        return super(ILasPointCloud, self).EstimatePointCount(pAOI)
    def EstimatePointSpacing(self, pAOI):
        '''Method ILasPointCloud.EstimatePointSpacing

           INPUT
            pAOI                : IEnvelope*

           OUTPUTS
            pMinSpacing         : double*
            pMaxSpacing         : double*
            pMeanSpacing        : double*'''
        return super(ILasPointCloud, self).EstimatePointSpacing(pAOI)
    def GetLasPoints(self, pTrackCancel, pFilter, thinningFactor, ZFactor):
        '''Method ILasPointCloud.GetLasPoints

           INPUTS
            pTrackCancel        : ITrackCancel*
            pFilter             : ILasPointFilter*
            thinningFactor      : double
            ZFactor             : double

           OUTPUT
            ppPoints            : IEnumLasPoint**'''
        return super(ILasPointCloud, self).GetLasPoints(pTrackCancel, pFilter, thinningFactor, ZFactor)
    def GetLasPointsByBudget(self, pTrackCancel, pFilter, maxPointCount, ZFactor):
        '''Method ILasPointCloud.GetLasPointsByBudget

           INPUTS
            pTrackCancel        : ITrackCancel*
            pFilter             : ILasPointFilter*
            maxPointCount       : double
            ZFactor             : double

           OUTPUT
            ppPoints            : IEnumLasPoint**'''
        return super(ILasPointCloud, self).GetLasPointsByBudget(pTrackCancel, pFilter, maxPointCount, ZFactor)
    def GetLasPointInfo(self, pTrackCancel, pLocation, PointID):
        '''Method ILasPointCloud.GetLasPointInfo

           INPUTS
            pTrackCancel        : ITrackCancel*
            pLocation           : IGeometry*
            PointID             : double

           OUTPUT
            ppInfo              : IArray**'''
        return super(ILasPointCloud, self).GetLasPointInfo(pTrackCancel, pLocation, PointID)
    def QueryLasPointInfo(self, FileIndex, PointID, pInfo):
        '''Method ILasPointCloud.QueryLasPointInfo

           INPUTS
            FileIndex           : long
            PointID             : double
            pInfo               : ILasPointInfo*'''
        return super(ILasPointCloud, self).QueryLasPointInfo(FileIndex, PointID, pInfo)
    def LasPointStatsAsRaster(self, pTrackCancel, pFilter, pDataset, Type, Attribute):
        '''Method ILasPointCloud.LasPointStatsAsRaster

           INPUTS
            pTrackCancel        : ITrackCancel*
            pFilter             : ILasPointFilter*
            pDataset            : IRasterDataset*
            Type                : esriLasPointStatsType
            Attribute           : esriLasAttributeType'''
        return super(ILasPointCloud, self).LasPointStatsAsRaster(pTrackCancel, pFilter, pDataset, Type, Attribute)

class ILasDatasetWorkspace(_esriGeoDatabaseExtensions.ILasDatasetWorkspace):
    _IID = uuid.UUID('eb2e798d-8154-41e9-a70f-53128de11573')
    def get_IsLasDataset(self, Name):
        '''Method ILasDatasetWorkspace.get_IsLasDataset

           INPUT
            Name                : BSTR

           OUTPUT
            pbIsDataset         : VARIANT_BOOL*'''
        return super(ILasDatasetWorkspace, self).get_IsLasDataset(Name)
    def OpenLasDataset(self, Name):
        '''Method ILasDatasetWorkspace.OpenLasDataset

           INPUT
            Name                : BSTR

           OUTPUT
            ppLasDataset        : ILasDataset**'''
        return super(ILasDatasetWorkspace, self).OpenLasDataset(Name)
    IsLasDataset = IndexProperty(get_IsLasDataset, None)

class ILasDataset2(_esriGeoDatabaseExtensions.ILasDataset2):
    _IID = uuid.UUID('3af8a856-b6c2-41e4-8b51-8ac0e8777087')
    def Rearrange(self, pTrackCancel, FileIndex, newFileName, bOverWrite):
        '''Method ILasDataset2.Rearrange

           INPUTS
            pTrackCancel        : ITrackCancel*
            FileIndex           : long
            newFileName         : BSTR
            bOverWrite          : VARIANT_BOOL'''
        return super(ILasDataset2, self).Rearrange(pTrackCancel, FileIndex, newFileName, bOverWrite)
    def SetEmpty(self):
        '''Method ILasDataset.SetEmpty (from ILasDataset)'''
        return super(ILasDataset2, self).SetEmpty()
    def Init(self, Name):
        '''Method ILasDataset.Init (from ILasDataset)

           INPUT
            Name                : BSTR'''
        return super(ILasDataset2, self).Init(Name)
    def SaveAs(self, Name, bOverWrite):
        '''Method ILasDataset.SaveAs (from ILasDataset)

           INPUTS
            Name                : BSTR
            bOverWrite          : VARIANT_BOOL'''
        return super(ILasDataset2, self).SaveAs(Name, bOverWrite)
    def get_Name(self):
        '''Method ILasDataset.get_Name (from ILasDataset)

           OUTPUT
            pName               : BSTR*'''
        return super(ILasDataset2, self).get_Name()
    def get_UsesRelativePath(self):
        '''Method ILasDataset.get_UsesRelativePath (from ILasDataset)

           OUTPUT
            pbUsesRelativePath  : VARIANT_BOOL*'''
        return super(ILasDataset2, self).get_UsesRelativePath()
    def get_IsDirty(self):
        '''Method ILasDataset.get_IsDirty (from ILasDataset)

           OUTPUT
            pbIsDirty           : VARIANT_BOOL*'''
        return super(ILasDataset2, self).get_IsDirty()
    def get_SpatialReference(self):
        '''Method ILasDataset.get_SpatialReference (from ILasDataset)

           OUTPUT
            ppSpatialRef        : ISpatialReference**'''
        return super(ILasDataset2, self).get_SpatialReference()
    def get_Extent(self):
        '''Method ILasDataset.get_Extent (from ILasDataset)

           OUTPUT
            ppExtent            : IEnvelope**'''
        return super(ILasDataset2, self).get_Extent()
    def get_FileCount(self):
        '''Method ILasDataset.get_FileCount (from ILasDataset)

           OUTPUT
            pcFiles             : long*'''
        return super(ILasDataset2, self).get_FileCount()
    def get_File(self, index):
        '''Method ILasDataset.get_File (from ILasDataset)

           INPUT
            index               : long

           OUTPUT
            ppFile              : ILasFile**'''
        return super(ILasDataset2, self).get_File(index)
    def get_SurfaceConstraintCount(self):
        '''Method ILasDataset.get_SurfaceConstraintCount (from ILasDataset)

           OUTPUT
            pcConstraints       : long*'''
        return super(ILasDataset2, self).get_SurfaceConstraintCount()
    def GetSurfaceConstraint(self, index):
        '''Method ILasDataset.GetSurfaceConstraint (from ILasDataset)

           INPUT
            index               : long

           OUTPUTS
            ppClass             : IFeatureClass**
            ppHeightField       : IField**
            ppTagField          : IField**
            pType               : esriTinSurfaceType*'''
        return super(ILasDataset2, self).GetSurfaceConstraint(index)
    def GetSurfaceConstraintName(self, index):
        '''Method ILasDataset.GetSurfaceConstraintName (from ILasDataset)

           INPUT
            index               : long

           OUTPUTS
            ppName              : IFeatureClassName**
            pHeightField        : BSTR*
            pTagField           : BSTR*
            pType               : esriTinSurfaceType*'''
        return super(ILasDataset2, self).GetSurfaceConstraintName(index)
    def GetSurfaceConstraintID(self, index):
        '''Method ILasDataset.GetSurfaceConstraintID (from ILasDataset)

           INPUT
            index               : long

           OUTPUT
            ppGuid              : IUID**'''
        return super(ILasDataset2, self).GetSurfaceConstraintID(index)
    def GetSurfaceConstraintIndexFromID(self, pGuid):
        '''Method ILasDataset.GetSurfaceConstraintIndexFromID (from ILasDataset)

           INPUT
            pGuid               : IUID*

           OUTPUT
            pIndex              : long*'''
        return super(ILasDataset2, self).GetSurfaceConstraintIndexFromID(pGuid)
    def get_PointCount(self):
        '''Method ILasDataset.get_PointCount (from ILasDataset)

           OUTPUT
            pCount              : double*'''
        return super(ILasDataset2, self).get_PointCount()
    def get_SizeInBytes(self):
        '''Method ILasDataset.get_SizeInBytes (from ILasDataset)

           OUTPUT
            pcBytes             : double*'''
        return super(ILasDataset2, self).get_SizeInBytes()
    def get_HasStatistics(self):
        '''Method ILasDataset.get_HasStatistics (from ILasDataset)

           OUTPUT
            pbHasStats          : VARIANT_BOOL*'''
        return super(ILasDataset2, self).get_HasStatistics()
    def get_NeedsUpdateStatistics(self):
        '''Method ILasDataset.get_NeedsUpdateStatistics (from ILasDataset)

           OUTPUT
            pbNeedsUpdate       : VARIANT_BOOL*'''
        return super(ILasDataset2, self).get_NeedsUpdateStatistics()
    def GetStatistics(self):
        '''Method ILasDataset.GetStatistics (from ILasDataset)

           OUTPUT
            ppStatistics        : ILasStatistics**'''
        return super(ILasDataset2, self).GetStatistics()
    def CreateDynamicSurface(self):
        '''Method ILasDataset.CreateDynamicSurface (from ILasDataset)

           OUTPUT
            ppSurface           : ILasSurface**'''
        return super(ILasDataset2, self).CreateDynamicSurface()
    def Export(self, pTrackCancel, FileIndex, pFilter, newFileName, pNewSpatialReference, bProject, bDropVLRs):
        '''Method ILasDataset.Export (from ILasDataset)

           INPUTS
            pTrackCancel        : ITrackCancel*
            FileIndex           : long
            pFilter             : ILasPointFilter*
            newFileName         : BSTR
            pNewSpatialReference: ISpatialReference*
            bProject            : VARIANT_BOOL
            bDropVLRs           : VARIANT_BOOL'''
        return super(ILasDataset2, self).Export(pTrackCancel, FileIndex, pFilter, newFileName, pNewSpatialReference, bProject, bDropVLRs)
    Extent = property(get_Extent, None, None)
    FileCount = property(get_FileCount, None, None)
    HasStatistics = property(get_HasStatistics, None, None)
    IsDirty = property(get_IsDirty, None, None)
    Name = property(get_Name, None, None)
    NeedsUpdateStatistics = property(get_NeedsUpdateStatistics, None, None)
    PointCount = property(get_PointCount, None, None)
    SizeInBytes = property(get_SizeInBytes, None, None)
    SpatialReference = property(get_SpatialReference, None, None)
    SurfaceConstraintCount = property(get_SurfaceConstraintCount, None, None)
    UsesRelativePath = property(get_UsesRelativePath, None, None)
    File = IndexProperty(get_File, None)

class ILasPointEdit(_esriGeoDatabaseExtensions.ILasPointEdit):
    _IID = uuid.UUID('5ea400dd-3afa-4423-9bc7-4915f4292911')
    def SetClassFlag(self, pTrackCancel, FileIndex, pAOI, bufferDistance, pZRange, pFilter, newFlags, bClear, bCalculateStats):
        '''Method ILasPointEdit.SetClassFlag

           INPUTS
            pTrackCancel        : ITrackCancel*
            FileIndex           : long
            pAOI                : IUnknown*
            bufferDistance      : double
            pZRange             : IDoubleArray*
            pFilter             : ILasAttributeFilter*
            newFlags            : long
            bClear              : VARIANT_BOOL
            bCalculateStats     : VARIANT_BOOL'''
        return super(ILasPointEdit, self).SetClassFlag(pTrackCancel, FileIndex, pAOI, bufferDistance, pZRange, pFilter, newFlags, bClear, bCalculateStats)
    def SetClassCode(self, pTrackCancel, FileIndex, pAOI, bufferDistance, pZRange, pFilter, newCode, bCalculateStats):
        '''Method ILasPointEdit.SetClassCode

           INPUTS
            pTrackCancel        : ITrackCancel*
            FileIndex           : long
            pAOI                : IUnknown*
            bufferDistance      : double
            pZRange             : IDoubleArray*
            pFilter             : ILasAttributeFilter*
            newCode             : long
            bCalculateStats     : VARIANT_BOOL'''
        return super(ILasPointEdit, self).SetClassCode(pTrackCancel, FileIndex, pAOI, bufferDistance, pZRange, pFilter, newCode, bCalculateStats)
    def ChangeClassCode(self, pTrackCancel, FileIndex, pExistingCodes, pNewCodes, bCalculateStats):
        '''Method ILasPointEdit.ChangeClassCode

           INPUTS
            pTrackCancel        : ITrackCancel*
            FileIndex           : long
            pExistingCodes      : ILongArray*
            pNewCodes           : ILongArray*
            bCalculateStats     : VARIANT_BOOL'''
        return super(ILasPointEdit, self).ChangeClassCode(pTrackCancel, FileIndex, pExistingCodes, pNewCodes, bCalculateStats)
    def EditClassCodeByClass(self, FileIndex, pPointIDs, newCode, withheldFlag, keyPointFlag, syntheticFlag):
        '''Method ILasPointEdit.EditClassCodeByClass

           INPUTS
            FileIndex           : long
            pPointIDs           : IDoubleArray*
            newCode             : long
            withheldFlag        : esriLasClassFlagEditType
            keyPointFlag        : esriLasClassFlagEditType
            syntheticFlag       : esriLasClassFlagEditType

           OUTPUT
            pbHasChange         : VARIANT_BOOL*'''
        return super(ILasPointEdit, self).EditClassCodeByClass(FileIndex, pPointIDs, newCode, withheldFlag, keyPointFlag, syntheticFlag)
    def EditClassCode(self, FileIndex, pPointIDs, pCodes):
        '''Method ILasPointEdit.EditClassCode

           INPUTS
            FileIndex           : long
            pPointIDs           : IDoubleArray*
            pCodes              : ILongArray*

           OUTPUT
            pbHasChange         : VARIANT_BOOL*'''
        return super(ILasPointEdit, self).EditClassCode(FileIndex, pPointIDs, pCodes)

class ICadastralJob(_esriGeoDatabaseExtensions.ICadastralJob):
    _IID = uuid.UUID('b2ac22b9-4234-411e-9524-01d3bf296355')

    def __init__(self, *args, **kw):
        super(ICadastralJob, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ID(self):
        '''Method ICadastralJob.get_ID

           OUTPUT
            JobID               : long*'''
        return super(ICadastralJob, self).get_ID()
    def get_Description(self):
        '''Method ICadastralJob.get_Description

           OUTPUT
            Description         : BSTR*'''
        return super(ICadastralJob, self).get_Description()
    def put_Description(self, Description):
        '''Method ICadastralJob.put_Description

           INPUT
            Description         : BSTR'''
        return super(ICadastralJob, self).put_Description(Description)
    def get_Name(self):
        '''Method ICadastralJob.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(ICadastralJob, self).get_Name()
    def put_Name(self, Name):
        '''Method ICadastralJob.put_Name

           INPUT
            Name                : BSTR'''
        return super(ICadastralJob, self).put_Name(Name)
    def get_Status(self):
        '''Method ICadastralJob.get_Status

           OUTPUT
            Status              : long*'''
        return super(ICadastralJob, self).get_Status()
    def put_Status(self, Status):
        '''Method ICadastralJob.put_Status

           INPUT
            Status              : long'''
        return super(ICadastralJob, self).put_Status(Status)
    def get_Owner(self):
        '''Method ICadastralJob.get_Owner

           OUTPUT
            Owner               : BSTR*'''
        return super(ICadastralJob, self).get_Owner()
    def put_Owner(self, Owner):
        '''Method ICadastralJob.put_Owner

           INPUT
            Owner               : BSTR'''
        return super(ICadastralJob, self).put_Owner(Owner)
    def get_ExtendedAttribute(self, fieldPosition):
        '''Method ICadastralJob.get_ExtendedAttribute

           INPUT
            fieldPosition       : long

           OUTPUT
            Value               : VARIANT*'''
        return super(ICadastralJob, self).get_ExtendedAttribute(fieldPosition)
    def put_ExtendedAttribute(self, fieldPosition, Value):
        '''Method ICadastralJob.put_ExtendedAttribute

           INPUTS
            fieldPosition       : long
            Value               : VARIANT'''
        return super(ICadastralJob, self).put_ExtendedAttribute(fieldPosition, Value)
    def get_StartDate(self):
        '''Method ICadastralJob.get_StartDate

           OUTPUT
            Date                : BSTR*'''
        return super(ICadastralJob, self).get_StartDate()
    def get_ModifiedDate(self):
        '''Method ICadastralJob.get_ModifiedDate

           OUTPUT
            Date                : BSTR*'''
        return super(ICadastralJob, self).get_ModifiedDate()
    def get_CommitDate(self):
        '''Method ICadastralJob.get_CommitDate

           OUTPUT
            Date                : BSTR*'''
        return super(ICadastralJob, self).get_CommitDate()
    def get_EditParcels(self):
        '''Method ICadastralJob.get_EditParcels

           OUTPUT
            EditParcelIDs       : IFIDSet**'''
        return super(ICadastralJob, self).get_EditParcels()
    def put_EditParcels(self, EditParcelIDs):
        '''Method ICadastralJob.put_EditParcels

           INPUT
            EditParcelIDs       : IFIDSet*'''
        return super(ICadastralJob, self).put_EditParcels(EditParcelIDs)
    def get_AdjustmentAreaParcels(self):
        '''Method ICadastralJob.get_AdjustmentAreaParcels

           OUTPUT
            AdjustmentAreaParcelIDs: IFIDSet**'''
        return super(ICadastralJob, self).get_AdjustmentAreaParcels()
    def put_AdjustmentAreaParcels(self, AdjustmentAreaParcelIDs):
        '''Method ICadastralJob.put_AdjustmentAreaParcels

           INPUT
            AdjustmentAreaParcelIDs: IFIDSet*'''
        return super(ICadastralJob, self).put_AdjustmentAreaParcels(AdjustmentAreaParcelIDs)
    def get_ControlPoints(self):
        '''Method ICadastralJob.get_ControlPoints

           OUTPUT
            ControlPointslIDs   : IFIDSet**'''
        return super(ICadastralJob, self).get_ControlPoints()
    def put_ControlPoints(self, ControlPointslIDs):
        '''Method ICadastralJob.put_ControlPoints

           INPUT
            ControlPointslIDs   : IFIDSet*'''
        return super(ICadastralJob, self).put_ControlPoints(ControlPointslIDs)
    def AddEditParcel(self, ParcelID):
        '''Method ICadastralJob.AddEditParcel

           INPUT
            ParcelID            : long'''
        return super(ICadastralJob, self).AddEditParcel(ParcelID)
    def RemoveEditParcel(self, ParcelID):
        '''Method ICadastralJob.RemoveEditParcel

           INPUT
            ParcelID            : long'''
        return super(ICadastralJob, self).RemoveEditParcel(ParcelID)
    def AddControlPoint(self, PointID):
        '''Method ICadastralJob.AddControlPoint

           INPUT
            PointID             : long'''
        return super(ICadastralJob, self).AddControlPoint(PointID)
    def RemoveControlPoint(self, PointID):
        '''Method ICadastralJob.RemoveControlPoint

           INPUT
            PointID             : long'''
        return super(ICadastralJob, self).RemoveControlPoint(PointID)
    def get_JobParcels(self):
        '''Method ICadastralJob.get_JobParcels

           OUTPUT
            ppParcelIDSet       : IFIDSet**'''
        return super(ICadastralJob, self).get_JobParcels()
    AdjustmentAreaParcels = property(get_AdjustmentAreaParcels, put_AdjustmentAreaParcels, None)
    CommitDate = property(get_CommitDate, None, None)
    ControlPoints = property(get_ControlPoints, put_ControlPoints, None)
    Description = property(get_Description, put_Description, None)
    EditParcels = property(get_EditParcels, put_EditParcels, None)
    ExtendedAttribute = property(None, put_ExtendedAttribute, None)
    ID = property(get_ID, None, None)
    JobParcels = property(get_JobParcels, None, None)
    ModifiedDate = property(get_ModifiedDate, None, None)
    Name = property(get_Name, put_Name, None)
    Owner = property(get_Owner, put_Owner, None)
    StartDate = property(get_StartDate, None, None)
    Status = property(get_Status, put_Status, None)
    ExtendedAttribute = IndexProperty(get_ExtendedAttribute, None)

class ICadastralFabric(_esriGeoDatabaseExtensions.ICadastralFabric):
    _IID = uuid.UUID('f9e240b1-d806-4388-afde-b1a5d354171f')
    def CreateJob(self, Job):
        '''Method ICadastralFabric.CreateJob

           INPUT
            Job                 : ICadastralJob*

           OUTPUT
            JobID               : long*'''
        return super(ICadastralFabric, self).CreateJob(Job)
    def GetJob(self, Name):
        '''Method ICadastralFabric.GetJob

           INPUT
            Name                : BSTR

           OUTPUT
            Job                 : ICadastralJob**'''
        return super(ICadastralFabric, self).GetJob(Name)
    def UpdateJob(self, Job):
        '''Method ICadastralFabric.UpdateJob

           INPUT
            Job                 : ICadastralJob*'''
        return super(ICadastralFabric, self).UpdateJob(Job)
    def DeleteJob(self, Name):
        '''Method ICadastralFabric.DeleteJob

           INPUT
            Name                : BSTR'''
        return super(ICadastralFabric, self).DeleteJob(Name)
    def ExtractCadastralPacket(self, JobName, OutputProjectedCoordSys, TrackCancel):
        '''Method ICadastralFabric.ExtractCadastralPacket

           INPUTS
            JobName             : BSTR
            OutputProjectedCoordSys: IProjectedCoordinateSystem*
            TrackCancel         : ITrackCancel*

           OUTPUT
            XMLStream           : IXMLStream**'''
        return super(ICadastralFabric, self).ExtractCadastralPacket(JobName, OutputProjectedCoordSys, TrackCancel)
    def PostCadastralPacket(self, XMLStream, CancelTracker):
        '''Method ICadastralFabric.PostCadastralPacket

           INPUTS
            XMLStream           : IXMLStream*
            CancelTracker       : ITrackCancel*'''
        return super(ICadastralFabric, self).PostCadastralPacket(XMLStream, CancelTracker)
    def CommitJob(self, JobName):
        '''Method ICadastralFabric.CommitJob

           INPUT
            JobName             : BSTR'''
        return super(ICadastralFabric, self).CommitJob(JobName)
    def get_CadastralJobs(self, cadastralJobType):
        '''Method ICadastralFabric.get_CadastralJobs

           INPUT
            cadastralJobType    : esriCadastralJob

           OUTPUT
            CadastralJobs       : IEnumBSTR**'''
        return super(ICadastralFabric, self).get_CadastralJobs(cadastralJobType)
    def get_CadastralTable(self, TableID):
        '''Method ICadastralFabric.get_CadastralTable

           INPUT
            TableID             : esriCadastralFabricTable

           OUTPUT
            Table               : ITable**'''
        return super(ICadastralFabric, self).get_CadastralTable(TableID)
    CadastralJobs = IndexProperty(get_CadastralJobs, None)
    CadastralTable = IndexProperty(get_CadastralTable, None)

class ICadastralFabric2(_esriGeoDatabaseExtensions.ICadastralFabric2):
    _IID = uuid.UUID('b6379408-3f07-4836-89f9-67610d2f74ce')
    def CreateCadastralPacket(self, OutputProjectedCoordSys, PlanIDs, TrackCancel):
        '''Method ICadastralFabric2.CreateCadastralPacket

           INPUTS
            OutputProjectedCoordSys: IProjectedCoordinateSystem*
            PlanIDs             : IFIDSet*
            TrackCancel         : ITrackCancel*

           OUTPUT
            XMLStream           : IXMLStream**'''
        return super(ICadastralFabric2, self).CreateCadastralPacket(OutputProjectedCoordSys, PlanIDs, TrackCancel)
    def InsertCadastralPacket(self, NewCadastralJobDefinition, XMLStream, CancelTracker):
        '''Method ICadastralFabric2.InsertCadastralPacket

           INPUTS
            NewCadastralJobDefinition: ICadastralJob*
            XMLStream           : IXMLStream*
            CancelTracker       : ITrackCancel*

           OUTPUT
            InsertedParcelOIDs  : IFIDSet**'''
        return super(ICadastralFabric2, self).InsertCadastralPacket(NewCadastralJobDefinition, XMLStream, CancelTracker)
    def ExtractCadastralPacket(self, JobName, OutputProjectedCoordSys, TrackCancel, IncludeWhiteSpace):
        '''Method ICadastralFabric2.ExtractCadastralPacket

           INPUTS
            JobName             : BSTR
            OutputProjectedCoordSys: IProjectedCoordinateSystem*
            TrackCancel         : ITrackCancel*
            IncludeWhiteSpace   : VARIANT_BOOL

           OUTPUT
            XMLStream           : IXMLStream**'''
        return super(ICadastralFabric2, self).ExtractCadastralPacket(JobName, OutputProjectedCoordSys, TrackCancel, IncludeWhiteSpace)
    def PostCadastralPacket(self, XMLStream, CancelTracker):
        '''Method ICadastralFabric2.PostCadastralPacket

           INPUTS
            XMLStream           : IXMLStream*
            CancelTracker       : ITrackCancel*

           OUTPUT
            InsertedParcelOIDs  : IFIDSet**'''
        return super(ICadastralFabric2, self).PostCadastralPacket(XMLStream, CancelTracker)

class ICadastralFabric3(_esriGeoDatabaseExtensions.ICadastralFabric3):
    _IID = uuid.UUID('5afce645-3c35-4a29-97d6-36c7524ee750')
    def CreateCadastralPacket(self, OutputProjectedCoordSys, PlanIDs, TrackCancel):
        '''Method ICadastralFabric3.CreateCadastralPacket

           INPUTS
            OutputProjectedCoordSys: IProjectedCoordinateSystem*
            PlanIDs             : IFIDSet*
            TrackCancel         : ITrackCancel*

           OUTPUT
            XMLStream           : IXMLStream**'''
        return super(ICadastralFabric3, self).CreateCadastralPacket(OutputProjectedCoordSys, PlanIDs, TrackCancel)
    def InsertCadastralPacket(self, NewCadastralJobDefinition, XMLStream, CancelTracker, ePacketSetting):
        '''Method ICadastralFabric3.InsertCadastralPacket

           INPUTS
            NewCadastralJobDefinition: ICadastralJob*
            XMLStream           : IXMLStream*
            CancelTracker       : ITrackCancel*
            ePacketSetting      : esriCadastralPacketSetting

           OUTPUT
            InsertedParcelOIDs  : IFIDSet**'''
        return super(ICadastralFabric3, self).InsertCadastralPacket(NewCadastralJobDefinition, XMLStream, CancelTracker, ePacketSetting)
    def ExtractCadastralPacket(self, JobName, OutputProjectedCoordSys, TrackCancel, IncludeWhiteSpace):
        '''Method ICadastralFabric3.ExtractCadastralPacket

           INPUTS
            JobName             : BSTR
            OutputProjectedCoordSys: IProjectedCoordinateSystem*
            TrackCancel         : ITrackCancel*
            IncludeWhiteSpace   : VARIANT_BOOL

           OUTPUT
            XMLStream           : IXMLStream**'''
        return super(ICadastralFabric3, self).ExtractCadastralPacket(JobName, OutputProjectedCoordSys, TrackCancel, IncludeWhiteSpace)
    def PostCadastralPacket(self, XMLStream, CancelTracker, ePacketSetting):
        '''Method ICadastralFabric3.PostCadastralPacket

           INPUTS
            XMLStream           : IXMLStream*
            CancelTracker       : ITrackCancel*
            ePacketSetting      : esriCadastralPacketSetting

           OUTPUT
            InsertedParcelOIDs  : IFIDSet**'''
        return super(ICadastralFabric3, self).PostCadastralPacket(XMLStream, CancelTracker, ePacketSetting)

class ICadastralFabricName(_esriGeoDatabaseExtensions.ICadastralFabricName):
    _IID = uuid.UUID('f7914f56-f87a-4e96-87f8-cbe368da3c61')

    def __init__(self, *args, **kw):
        super(ICadastralFabricName, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def putref_FeatureDatasetName(self, Name):
        '''Method ICadastralFabricName.putref_FeatureDatasetName

           INPUT
            Name                : IDatasetName*'''
        return super(ICadastralFabricName, self).putref_FeatureDatasetName(Name)
    def get_FeatureDatasetName(self):
        '''Method ICadastralFabricName.get_FeatureDatasetName

           OUTPUT
            Name                : IDatasetName**'''
        return super(ICadastralFabricName, self).get_FeatureDatasetName()
    FeatureDatasetName = property(get_FeatureDatasetName, putref_FeatureDatasetName, None)

class IDECadastralFabric(_esriGeoDatabaseExtensions.IDECadastralFabric):
    _IID = uuid.UUID('06c95fa1-8cf2-4563-8038-15fb592374b4')

    def __init__(self, *args, **kw):
        super(IDECadastralFabric, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ConfigurationKeyword(self):
        '''Method IDECadastralFabric.get_ConfigurationKeyword

           OUTPUT
            configKeyword       : BSTR*'''
        return super(IDECadastralFabric, self).get_ConfigurationKeyword()
    def put_ConfigurationKeyword(self, configKeyword):
        '''Method IDECadastralFabric.put_ConfigurationKeyword

           INPUT
            configKeyword       : BSTR'''
        return super(IDECadastralFabric, self).put_ConfigurationKeyword(configKeyword)
    def get_DefaultAccuracyCategory(self):
        '''Method IDECadastralFabric.get_DefaultAccuracyCategory

           OUTPUT
            defaultAccuracy     : long*'''
        return super(IDECadastralFabric, self).get_DefaultAccuracyCategory()
    def put_DefaultAccuracyCategory(self, defaultAccuracy):
        '''Method IDECadastralFabric.put_DefaultAccuracyCategory

           INPUT
            defaultAccuracy     : long'''
        return super(IDECadastralFabric, self).put_DefaultAccuracyCategory(defaultAccuracy)
    def putref_CadastralTableFieldEdits(self, CadastralTableFieldEdits):
        '''Method IDECadastralFabric.putref_CadastralTableFieldEdits

           INPUT
            CadastralTableFieldEdits: IArray*'''
        return super(IDECadastralFabric, self).putref_CadastralTableFieldEdits(CadastralTableFieldEdits)
    def get_CadastralTableFieldEdits(self):
        '''Method IDECadastralFabric.get_CadastralTableFieldEdits

           OUTPUT
            CadastralTableFieldEdits: IArray**'''
        return super(IDECadastralFabric, self).get_CadastralTableFieldEdits()
    CadastralTableFieldEdits = property(get_CadastralTableFieldEdits, putref_CadastralTableFieldEdits, None)
    ConfigurationKeyword = property(get_ConfigurationKeyword, put_ConfigurationKeyword, None)
    DefaultAccuracyCategory = property(get_DefaultAccuracyCategory, put_DefaultAccuracyCategory, None)

class ICadastralTransformationData(_esriGeoDatabaseExtensions.ICadastralTransformationData):
    _IID = uuid.UUID('e1f5787f-b5e4-4e6c-b84f-86d621792bb8')
    def AddData(self, Name, adjustmentLevel):
        '''Method ICadastralTransformationData.AddData

           INPUTS
            Name                : IName*
            adjustmentLevel     : long'''
        return super(ICadastralTransformationData, self).AddData(Name, adjustmentLevel)
    def GetData(self, index):
        '''Method ICadastralTransformationData.GetData

           INPUT
            index               : long

           OUTPUTS
            Name                : IName**
            adjustmentLevel     : long*'''
        return super(ICadastralTransformationData, self).GetData(index)
    def get_TransDataCount(self):
        '''Method ICadastralTransformationData.get_TransDataCount

           OUTPUT
            Count               : long*'''
        return super(ICadastralTransformationData, self).get_TransDataCount()
    def Clear(self):
        '''Method ICadastralTransformationData.Clear'''
        return super(ICadastralTransformationData, self).Clear()
    TransDataCount = property(get_TransDataCount, None, None)

class ICadastralAdjustmentVectors(_esriGeoDatabaseExtensions.ICadastralAdjustmentVectors):
    _IID = uuid.UUID('889a386d-4d81-4f8c-8736-5383423df188')
    def AddVector(self, PointID, fromX, fromY, toX, toY):
        '''Method ICadastralAdjustmentVectors.AddVector

           INPUTS
            PointID             : long
            fromX               : double
            fromY               : double
            toX                 : double
            toY                 : double'''
        return super(ICadastralAdjustmentVectors, self).AddVector(PointID, fromX, fromY, toX, toY)
    def CreateNewAdjustment(self):
        '''Method ICadastralAdjustmentVectors.CreateNewAdjustment

           OUTPUT
            pNewAdjustmentLevel : long*'''
        return super(ICadastralAdjustmentVectors, self).CreateNewAdjustment()
    def ClearVectors(self):
        '''Method ICadastralAdjustmentVectors.ClearVectors'''
        return super(ICadastralAdjustmentVectors, self).ClearVectors()

class ICadastralFabricLocks(_esriGeoDatabaseExtensions.ICadastralFabricLocks):
    _IID = uuid.UUID('c8be9a26-2fd5-4d41-a70b-7e000b644c41')

    def __init__(self, *args, **kw):
        super(ICadastralFabricLocks, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_LockingJob(self, _arg1):
        '''Method ICadastralFabricLocks.put_LockingJob

           INPUT
            _arg1               : BSTR'''
        return super(ICadastralFabricLocks, self).put_LockingJob(_arg1)
    def AcquireLocks(self, pLocks, TakeSoftLocks):
        '''Method ICadastralFabricLocks.AcquireLocks

           INPUTS
            pLocks              : ILongArray*
            TakeSoftLocks       : VARIANT_BOOL

           OUTPUTS
            ppLocksInConflict   : ILongArray**
            ppSoftLocksInConflict: ILongArray**'''
        return super(ICadastralFabricLocks, self).AcquireLocks(pLocks, TakeSoftLocks)
    def UndoLastAcquiredLocks(self):
        '''Method ICadastralFabricLocks.UndoLastAcquiredLocks'''
        return super(ICadastralFabricLocks, self).UndoLastAcquiredLocks()
    def LockJob(self):
        '''Method ICadastralFabricLocks.LockJob

           OUTPUT
            Succeed             : VARIANT_BOOL*'''
        return super(ICadastralFabricLocks, self).LockJob()
    def ReleaseJobLock(self, ForceRelease):
        '''Method ICadastralFabricLocks.ReleaseJobLock

           INPUT
            ForceRelease        : VARIANT_BOOL'''
        return super(ICadastralFabricLocks, self).ReleaseJobLock(ForceRelease)
    def ValidateJobLock(self):
        '''Method ICadastralFabricLocks.ValidateJobLock

           OUTPUTS
            Locked              : VARIANT_BOOL*
            LockingMachine      : BSTR*
            LockingPID          : long*'''
        return super(ICadastralFabricLocks, self).ValidateJobLock()
    LockingJob = property(None, put_LockingJob, None)

class ICadastralFabricLocks2(_esriGeoDatabaseExtensions.ICadastralFabricLocks2):
    _IID = uuid.UUID('882005e1-945f-46eb-80c8-2b7a3b0afd4a')
    def AcquireLocks(self, pLocks, TakeSoftLocks, pLocksInConflict, pSoftLocksInConflict):
        '''Method ICadastralFabricLocks2.AcquireLocks

           INPUTS
            pLocks              : ILongArray*
            TakeSoftLocks       : VARIANT_BOOL
            pLocksInConflict    : ILongArray*
            pSoftLocksInConflict: ILongArray*'''
        return super(ICadastralFabricLocks2, self).AcquireLocks(pLocks, TakeSoftLocks, pLocksInConflict, pSoftLocksInConflict)

class ICadastralFabricSchemaEdit(_esriGeoDatabaseExtensions.ICadastralFabricSchemaEdit):
    _IID = uuid.UUID('8a932661-07b3-4d2e-b02c-ce6092a1b4af')
    def UpdateSchema(self, DataElement):
        '''Method ICadastralFabricSchemaEdit.UpdateSchema

           INPUT
            DataElement         : IDECadastralFabric*'''
        return super(ICadastralFabricSchemaEdit, self).UpdateSchema(DataElement)

class ICadastralFabricSchemaEdit2(_esriGeoDatabaseExtensions.ICadastralFabricSchemaEdit2):
    _IID = uuid.UUID('e2930c0e-dd54-4f12-8960-c44e6c08c395')
    def ReleaseReadOnlyFields(self, pTable, Table):
        '''Method ICadastralFabricSchemaEdit2.ReleaseReadOnlyFields

           INPUTS
            pTable              : ITable*
            Table               : esriCadastralFabricTable'''
        return super(ICadastralFabricSchemaEdit2, self).ReleaseReadOnlyFields(pTable, Table)
    def ResetReadOnlyFields(self, Table):
        '''Method ICadastralFabricSchemaEdit2.ResetReadOnlyFields

           INPUT
            Table               : esriCadastralFabricTable'''
        return super(ICadastralFabricSchemaEdit2, self).ResetReadOnlyFields(Table)

class ICadastralTableFieldEdits(_esriGeoDatabaseExtensions.ICadastralTableFieldEdits):
    _IID = uuid.UUID('3327d58a-2994-4fd9-a2fb-1f3a993f27ae')

    def __init__(self, *args, **kw):
        super(ICadastralTableFieldEdits, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TableName(self):
        '''Method ICadastralTableFieldEdits.get_TableName

           OUTPUT
            Name                : BSTR*'''
        return super(ICadastralTableFieldEdits, self).get_TableName()
    def put_CadastralTable(self, Table):
        '''Method ICadastralTableFieldEdits.put_CadastralTable

           INPUT
            Table               : esriCadastralFabricTable'''
        return super(ICadastralTableFieldEdits, self).put_CadastralTable(Table)
    def get_CadastralTable(self):
        '''Method ICadastralTableFieldEdits.get_CadastralTable

           OUTPUT
            Table               : esriCadastralFabricTable*'''
        return super(ICadastralTableFieldEdits, self).get_CadastralTable()
    def get_ExtendedAttributeFields(self):
        '''Method ICadastralTableFieldEdits.get_ExtendedAttributeFields

           OUTPUT
            Fields              : IFields**'''
        return super(ICadastralTableFieldEdits, self).get_ExtendedAttributeFields()
    def put_ExtendedAttributeFields(self, Fields):
        '''Method ICadastralTableFieldEdits.put_ExtendedAttributeFields

           INPUT
            Fields              : IFields*'''
        return super(ICadastralTableFieldEdits, self).put_ExtendedAttributeFields(Fields)
    CadastralTable = property(get_CadastralTable, put_CadastralTable, None)
    ExtendedAttributeFields = property(get_ExtendedAttributeFields, put_ExtendedAttributeFields, None)
    TableName = property(get_TableName, None, None)

class IDECadastralFabric2(_esriGeoDatabaseExtensions.IDECadastralFabric2):
    _IID = uuid.UUID('5ba64979-96c6-4e16-baa1-aff9e81ccbd3')

    def __init__(self, *args, **kw):
        super(IDECadastralFabric2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_CompiledAccuracyCategory(self):
        '''Method IDECadastralFabric2.get_CompiledAccuracyCategory

           OUTPUT
            defaultAccuracy     : long*'''
        return super(IDECadastralFabric2, self).get_CompiledAccuracyCategory()
    def put_CompiledAccuracyCategory(self, defaultAccuracy):
        '''Method IDECadastralFabric2.put_CompiledAccuracyCategory

           INPUT
            defaultAccuracy     : long'''
        return super(IDECadastralFabric2, self).put_CompiledAccuracyCategory(defaultAccuracy)
    def get_BufferDistanceForAdjustment(self):
        '''Method IDECadastralFabric2.get_BufferDistanceForAdjustment

           OUTPUT
            distance            : double*'''
        return super(IDECadastralFabric2, self).get_BufferDistanceForAdjustment()
    def put_BufferDistanceForAdjustment(self, distance):
        '''Method IDECadastralFabric2.put_BufferDistanceForAdjustment

           INPUT
            distance            : double'''
        return super(IDECadastralFabric2, self).put_BufferDistanceForAdjustment(distance)
    def get_Type(self):
        '''Method IDECadastralFabric2.get_Type

           OUTPUT
            Type                : esriCadastralFabricType*'''
        return super(IDECadastralFabric2, self).get_Type()
    def put_Type(self, Type):
        '''Method IDECadastralFabric2.put_Type

           INPUT
            Type                : esriCadastralFabricType'''
        return super(IDECadastralFabric2, self).put_Type(Type)
    def get_SurrogateVersion(self):
        '''Method IDECadastralFabric2.get_SurrogateVersion

           OUTPUT
            surrogate           : BSTR*'''
        return super(IDECadastralFabric2, self).get_SurrogateVersion()
    def put_SurrogateVersion(self, surrogate):
        '''Method IDECadastralFabric2.put_SurrogateVersion

           INPUT
            surrogate           : BSTR'''
        return super(IDECadastralFabric2, self).put_SurrogateVersion(surrogate)
    def get_Version(self):
        '''Method IDECadastralFabric2.get_Version

           OUTPUT
            Version             : long*'''
        return super(IDECadastralFabric2, self).get_Version()
    def get_MaximumShiftThreshold(self):
        '''Method IDECadastralFabric2.get_MaximumShiftThreshold

           OUTPUT
            Threshold           : double*'''
        return super(IDECadastralFabric2, self).get_MaximumShiftThreshold()
    def put_MaximumShiftThreshold(self, Threshold):
        '''Method IDECadastralFabric2.put_MaximumShiftThreshold

           INPUT
            Threshold           : double'''
        return super(IDECadastralFabric2, self).put_MaximumShiftThreshold(Threshold)
    def get_MultiGenerationEditing(self):
        '''Method IDECadastralFabric2.get_MultiGenerationEditing

           OUTPUT
            pAllow              : VARIANT_BOOL*'''
        return super(IDECadastralFabric2, self).get_MultiGenerationEditing()
    def put_MultiGenerationEditing(self, pAllow):
        '''Method IDECadastralFabric2.put_MultiGenerationEditing

           INPUT
            pAllow              : VARIANT_BOOL'''
        return super(IDECadastralFabric2, self).put_MultiGenerationEditing(pAllow)
    def get_MultiLevelReconcile(self):
        '''Method IDECadastralFabric2.get_MultiLevelReconcile

           OUTPUT
            pAllow              : VARIANT_BOOL*'''
        return super(IDECadastralFabric2, self).get_MultiLevelReconcile()
    def put_MultiLevelReconcile(self, pAllow):
        '''Method IDECadastralFabric2.put_MultiLevelReconcile

           INPUT
            pAllow              : VARIANT_BOOL'''
        return super(IDECadastralFabric2, self).put_MultiLevelReconcile(pAllow)
    def get_PinAdjustmentBoundary(self):
        '''Method IDECadastralFabric2.get_PinAdjustmentBoundary

           OUTPUT
            pPinBoundary        : VARIANT_BOOL*'''
        return super(IDECadastralFabric2, self).get_PinAdjustmentBoundary()
    def put_PinAdjustmentBoundary(self, pPinBoundary):
        '''Method IDECadastralFabric2.put_PinAdjustmentBoundary

           INPUT
            pPinBoundary        : VARIANT_BOOL'''
        return super(IDECadastralFabric2, self).put_PinAdjustmentBoundary(pPinBoundary)
    def get_PinAdjustmentPointsWithinBoundary(self):
        '''Method IDECadastralFabric2.get_PinAdjustmentPointsWithinBoundary

           OUTPUT
            pPinWithinBoundary  : VARIANT_BOOL*'''
        return super(IDECadastralFabric2, self).get_PinAdjustmentPointsWithinBoundary()
    def put_PinAdjustmentPointsWithinBoundary(self, pPinWithinBoundary):
        '''Method IDECadastralFabric2.put_PinAdjustmentPointsWithinBoundary

           INPUT
            pPinWithinBoundary  : VARIANT_BOOL'''
        return super(IDECadastralFabric2, self).put_PinAdjustmentPointsWithinBoundary(pPinWithinBoundary)
    def get_WriteAdjustmentVectors(self):
        '''Method IDECadastralFabric2.get_WriteAdjustmentVectors

           OUTPUT
            pWriteAdjustmentVectors: VARIANT_BOOL*'''
        return super(IDECadastralFabric2, self).get_WriteAdjustmentVectors()
    def put_WriteAdjustmentVectors(self, pWriteAdjustmentVectors):
        '''Method IDECadastralFabric2.put_WriteAdjustmentVectors

           INPUT
            pWriteAdjustmentVectors: VARIANT_BOOL'''
        return super(IDECadastralFabric2, self).put_WriteAdjustmentVectors(pWriteAdjustmentVectors)
    BufferDistanceForAdjustment = property(get_BufferDistanceForAdjustment, put_BufferDistanceForAdjustment, None)
    CompiledAccuracyCategory = property(get_CompiledAccuracyCategory, put_CompiledAccuracyCategory, None)
    MaximumShiftThreshold = property(get_MaximumShiftThreshold, put_MaximumShiftThreshold, None)
    MultiGenerationEditing = property(get_MultiGenerationEditing, put_MultiGenerationEditing, None)
    MultiLevelReconcile = property(get_MultiLevelReconcile, put_MultiLevelReconcile, None)
    PinAdjustmentBoundary = property(get_PinAdjustmentBoundary, put_PinAdjustmentBoundary, None)
    PinAdjustmentPointsWithinBoundary = property(get_PinAdjustmentPointsWithinBoundary, put_PinAdjustmentPointsWithinBoundary, None)
    SurrogateVersion = property(get_SurrogateVersion, put_SurrogateVersion, None)
    Type = property(get_Type, put_Type, None)
    Version = property(get_Version, None, None)
    WriteAdjustmentVectors = property(get_WriteAdjustmentVectors, put_WriteAdjustmentVectors, None)

class IDECadastralFabric3(_esriGeoDatabaseExtensions.IDECadastralFabric3):
    _IID = uuid.UUID('7620970c-aef2-41ea-85a9-21c3829ea070')
    def GetPropertySet(self, Type):
        '''Method IDECadastralFabric3.GetPropertySet

           INPUT
            Type                : esriCadastralPropertySetType

           OUTPUT
            propertySet         : IPropertySet**'''
        return super(IDECadastralFabric3, self).GetPropertySet(Type)
    def SetPropertySet(self, Type, propertySet):
        '''Method IDECadastralFabric3.SetPropertySet

           INPUTS
            Type                : esriCadastralPropertySetType
            propertySet         : IPropertySet*'''
        return super(IDECadastralFabric3, self).SetPropertySet(Type, propertySet)

class IParcelConstructionData(_esriGeoDatabaseExtensions.IParcelConstructionData):
    _IID = uuid.UUID('fc722d60-d2dc-4dfe-8524-3ac3369bbe68')

    def __init__(self, *args, **kw):
        super(IParcelConstructionData, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ParcelNo(self):
        '''Method IParcelConstructionData.get_ParcelNo

           OUTPUT
            ParcelNo            : long*'''
        return super(IParcelConstructionData, self).get_ParcelNo()
    def put_ParcelNo(self, ParcelNo):
        '''Method IParcelConstructionData.put_ParcelNo

           INPUT
            ParcelNo            : long'''
        return super(IParcelConstructionData, self).put_ParcelNo(ParcelNo)
    def WriteToXML(self, pXMLDoc):
        '''Method IParcelConstructionData.WriteToXML

           INPUT
            pXMLDoc             : IUnknown*'''
        return super(IParcelConstructionData, self).WriteToXML(pXMLDoc)
    def LoadConstructionDataFromXML(self, pXMLParcelNode):
        '''Method IParcelConstructionData.LoadConstructionDataFromXML

           INPUT
            pXMLParcelNode      : IUnknown*'''
        return super(IParcelConstructionData, self).LoadConstructionDataFromXML(pXMLParcelNode)
    def ExportToXMLString(self):
        '''Method IParcelConstructionData.ExportToXMLString

           OUTPUT
            XMLString           : BSTR*'''
        return super(IParcelConstructionData, self).ExportToXMLString()
    def LoadConstructionDataFromXMLString(self, XMLString):
        '''Method IParcelConstructionData.LoadConstructionDataFromXMLString

           INPUT
            XMLString           : BSTR'''
        return super(IParcelConstructionData, self).LoadConstructionDataFromXMLString(XMLString)
    ParcelNo = property(get_ParcelNo, put_ParcelNo, None)

class IConstructionParentParcels(_esriGeoDatabaseExtensions.IConstructionParentParcels):
    _IID = uuid.UUID('b6a52380-87e2-4628-9ebd-771c0bdacf23')
    def get_ParentParcelCount(self):
        '''Method IConstructionParentParcels.get_ParentParcelCount

           OUTPUT
            Count               : long*'''
        return super(IConstructionParentParcels, self).get_ParentParcelCount()
    def GetParentParcel(self, i):
        '''Method IConstructionParentParcels.GetParentParcel

           INPUT
            i                   : long

           OUTPUT
            ParcelNo            : long*'''
        return super(IConstructionParentParcels, self).GetParentParcel(i)
    def AddParentParcel(self, ParcelNo):
        '''Method IConstructionParentParcels.AddParentParcel

           INPUT
            ParcelNo            : long'''
        return super(IConstructionParentParcels, self).AddParentParcel(ParcelNo)
    def RemoveParentParcel(self, ParcelNo):
        '''Method IConstructionParentParcels.RemoveParentParcel

           INPUT
            ParcelNo            : long'''
        return super(IConstructionParentParcels, self).RemoveParentParcel(ParcelNo)
    def ClearParentParcels(self):
        '''Method IConstructionParentParcels.ClearParentParcels'''
        return super(IConstructionParentParcels, self).ClearParentParcels()
    ParentParcelCount = property(get_ParentParcelCount, None, None)

class IConstructionBreakPoints(_esriGeoDatabaseExtensions.IConstructionBreakPoints):
    _IID = uuid.UUID('1c66cb4e-8950-41b1-8896-e75c173870aa')
    def get_BreakPointCount(self):
        '''Method IConstructionBreakPoints.get_BreakPointCount

           OUTPUT
            Count               : long*'''
        return super(IConstructionBreakPoints, self).get_BreakPointCount()
    def GetBreakPoint(self, i):
        '''Method IConstructionBreakPoints.GetBreakPoint

           INPUT
            i                   : long

           OUTPUTS
            pointNo             : long*
            fromPointNo         : long*
            toPointNo           : long*
            ratio               : double*'''
        return super(IConstructionBreakPoints, self).GetBreakPoint(i)
    def FindBreakPoint(self, pointNo):
        '''Method IConstructionBreakPoints.FindBreakPoint

           INPUT
            pointNo             : long

           OUTPUTS
            fromPointNo         : long*
            toPointNo           : long*
            ratio               : double*'''
        return super(IConstructionBreakPoints, self).FindBreakPoint(pointNo)
    def AddBreakPoint(self, pointNo, fromPointNo, toPointNo, ratio):
        '''Method IConstructionBreakPoints.AddBreakPoint

           INPUTS
            pointNo             : long
            fromPointNo         : long
            toPointNo           : long
            ratio               : double'''
        return super(IConstructionBreakPoints, self).AddBreakPoint(pointNo, fromPointNo, toPointNo, ratio)
    def RemoveBreakPoint(self, pointNo):
        '''Method IConstructionBreakPoints.RemoveBreakPoint

           INPUT
            pointNo             : long'''
        return super(IConstructionBreakPoints, self).RemoveBreakPoint(pointNo)
    def ClearBreakPoints(self):
        '''Method IConstructionBreakPoints.ClearBreakPoints'''
        return super(IConstructionBreakPoints, self).ClearBreakPoints()
    BreakPointCount = property(get_BreakPointCount, None, None)

class IConstructionBasisOfBearing(_esriGeoDatabaseExtensions.IConstructionBasisOfBearing):
    _IID = uuid.UUID('2b82ac6e-aa06-43d8-ae70-7b200e07be6b')

    def __init__(self, *args, **kw):
        super(IConstructionBasisOfBearing, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_BasisOfBearingOffset(self):
        '''Method IConstructionBasisOfBearing.get_BasisOfBearingOffset

           OUTPUT
            angleOffset         : double*'''
        return super(IConstructionBasisOfBearing, self).get_BasisOfBearingOffset()
    def put_BasisOfBearingOffset(self, angleOffset):
        '''Method IConstructionBasisOfBearing.put_BasisOfBearingOffset

           INPUT
            angleOffset         : double'''
        return super(IConstructionBasisOfBearing, self).put_BasisOfBearingOffset(angleOffset)
    BasisOfBearingOffset = property(get_BasisOfBearingOffset, put_BasisOfBearingOffset, None)

class IConstructionJoinLinks(_esriGeoDatabaseExtensions.IConstructionJoinLinks):
    _IID = uuid.UUID('646fca02-4b1d-4844-a083-9911ef6cfa7b')
    def get_JoinLinkCount(self):
        '''Method IConstructionJoinLinks.get_JoinLinkCount

           OUTPUT
            Count               : long*'''
        return super(IConstructionJoinLinks, self).get_JoinLinkCount()
    def AddJoinLink(self, JoinedPointNo, UnjoinedPointNo, fromPointNo, toPointNo, ParcelNo):
        '''Method IConstructionJoinLinks.AddJoinLink

           INPUTS
            JoinedPointNo       : long
            UnjoinedPointNo     : long
            fromPointNo         : long
            toPointNo           : long
            ParcelNo            : long'''
        return super(IConstructionJoinLinks, self).AddJoinLink(JoinedPointNo, UnjoinedPointNo, fromPointNo, toPointNo, ParcelNo)
    def GetJoinLink(self, i):
        '''Method IConstructionJoinLinks.GetJoinLink

           INPUT
            i                   : long

           OUTPUTS
            JoinedPointNo       : long*
            UnjoinedPointNo     : long*
            fromPointNo         : long*
            toPointNo           : long*
            ParcelNo            : long*'''
        return super(IConstructionJoinLinks, self).GetJoinLink(i)
    def RemoveJoinLink(self, i):
        '''Method IConstructionJoinLinks.RemoveJoinLink

           INPUT
            i                   : long'''
        return super(IConstructionJoinLinks, self).RemoveJoinLink(i)
    def ClearJoinLinks(self):
        '''Method IConstructionJoinLinks.ClearJoinLinks'''
        return super(IConstructionJoinLinks, self).ClearJoinLinks()
    JoinLinkCount = property(get_JoinLinkCount, None, None)

class IConstructionUnbuildableLines(_esriGeoDatabaseExtensions.IConstructionUnbuildableLines):
    _IID = uuid.UUID('11ea4990-32f3-4aac-b285-f70ff18c956f')
    def AddUnbuildableLine(self, parentParcelNo, fromPointNo, toPointNo):
        '''Method IConstructionUnbuildableLines.AddUnbuildableLine

           INPUTS
            parentParcelNo      : long
            fromPointNo         : long
            toPointNo           : long'''
        return super(IConstructionUnbuildableLines, self).AddUnbuildableLine(parentParcelNo, fromPointNo, toPointNo)
    def RemoveUnbuildableLine(self, parentParcelNo, fromPointNo, toPointNo):
        '''Method IConstructionUnbuildableLines.RemoveUnbuildableLine

           INPUTS
            parentParcelNo      : long
            fromPointNo         : long
            toPointNo           : long'''
        return super(IConstructionUnbuildableLines, self).RemoveUnbuildableLine(parentParcelNo, fromPointNo, toPointNo)
    def SetUnbuildableLines(self, parentParcelNo, Count, fromPointNos, toPointNos):
        '''Method IConstructionUnbuildableLines.SetUnbuildableLines

           INPUTS
            parentParcelNo      : long
            Count               : long
            fromPointNos        : long*
            toPointNos          : long*'''
        return super(IConstructionUnbuildableLines, self).SetUnbuildableLines(parentParcelNo, Count, fromPointNos, toPointNos)
    def GetUnbuildableLines(self, parentParcelNo):
        '''Method IConstructionUnbuildableLines.GetUnbuildableLines

           INPUT
            parentParcelNo      : long

           OUTPUTS
            Count               : long*
            fromPointNos        : long**
            toPointNos          : long**'''
        return super(IConstructionUnbuildableLines, self).GetUnbuildableLines(parentParcelNo)
    def ClearUnbuildableLines(self, parentParcelNo):
        '''Method IConstructionUnbuildableLines.ClearUnbuildableLines

           INPUT
            parentParcelNo      : long'''
        return super(IConstructionUnbuildableLines, self).ClearUnbuildableLines(parentParcelNo)

class IConstructionPoints(_esriGeoDatabaseExtensions.IConstructionPoints):
    _IID = uuid.UUID('adc3412a-6ef7-41ac-bdc2-23e911c31280')
    def get_ConstructionPointCount(self):
        '''Method IConstructionPoints.get_ConstructionPointCount

           OUTPUT
            pCount              : long*'''
        return super(IConstructionPoints, self).get_ConstructionPointCount()
    def GetConstructionPoint(self, i):
        '''Method IConstructionPoints.GetConstructionPoint

           INPUT
            i                   : long

           OUTPUTS
            pUnjoinedPointNo    : long*
            pX                  : double*
            pY                  : double*'''
        return super(IConstructionPoints, self).GetConstructionPoint(i)
    def AddConstructionPoint(self, UnjoinedPointNo, x, y):
        '''Method IConstructionPoints.AddConstructionPoint

           INPUTS
            UnjoinedPointNo     : long
            x                   : double
            y                   : double'''
        return super(IConstructionPoints, self).AddConstructionPoint(UnjoinedPointNo, x, y)
    def FindConstructionPoint(self, UnjoinedPointNo):
        '''Method IConstructionPoints.FindConstructionPoint

           INPUT
            UnjoinedPointNo     : long

           OUTPUTS
            x                   : double*
            y                   : double*'''
        return super(IConstructionPoints, self).FindConstructionPoint(UnjoinedPointNo)
    def RemoveConstructionPoint(self, UnjoinedPointNo):
        '''Method IConstructionPoints.RemoveConstructionPoint

           INPUT
            UnjoinedPointNo     : long'''
        return super(IConstructionPoints, self).RemoveConstructionPoint(UnjoinedPointNo)
    def ClearConstructionPoints(self):
        '''Method IConstructionPoints.ClearConstructionPoints'''
        return super(IConstructionPoints, self).ClearConstructionPoints()
    ConstructionPointCount = property(get_ConstructionPointCount, None, None)

class IConstructionAdjustment(_esriGeoDatabaseExtensions.IConstructionAdjustment):
    _IID = uuid.UUID('cb760247-e82a-4666-a79e-a6f1f6bf2845')

    def __init__(self, *args, **kw):
        super(IConstructionAdjustment, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_AdjustmentMethod(self):
        '''Method IConstructionAdjustment.get_AdjustmentMethod

           OUTPUT
            Type                : esriParcelAdjustmentType*'''
        return super(IConstructionAdjustment, self).get_AdjustmentMethod()
    def put_AdjustmentMethod(self, Type):
        '''Method IConstructionAdjustment.put_AdjustmentMethod

           INPUT
            Type                : esriParcelAdjustmentType'''
        return super(IConstructionAdjustment, self).put_AdjustmentMethod(Type)
    def GetStartPoint(self):
        '''Method IConstructionAdjustment.GetStartPoint

           OUTPUTS
            UnjoinedPointNo     : long*
            x                   : double*
            y                   : double*'''
        return super(IConstructionAdjustment, self).GetStartPoint()
    def GetEndPoint(self):
        '''Method IConstructionAdjustment.GetEndPoint

           OUTPUTS
            UnjoinedPointNo     : long*
            x                   : double*
            y                   : double*'''
        return super(IConstructionAdjustment, self).GetEndPoint()
    def SetStartPoint(self, UnjoinedPointNo, x, y):
        '''Method IConstructionAdjustment.SetStartPoint

           INPUTS
            UnjoinedPointNo     : long
            x                   : double
            y                   : double'''
        return super(IConstructionAdjustment, self).SetStartPoint(UnjoinedPointNo, x, y)
    def SetEndPoint(self, UnjoinedPointNo, x, y):
        '''Method IConstructionAdjustment.SetEndPoint

           INPUTS
            UnjoinedPointNo     : long
            x                   : double
            y                   : double'''
        return super(IConstructionAdjustment, self).SetEndPoint(UnjoinedPointNo, x, y)
    AdjustmentMethod = property(get_AdjustmentMethod, put_AdjustmentMethod, None)

class ILineResequencer(_esriGeoDatabaseExtensions.ILineResequencer):
    _IID = uuid.UUID('5d89097e-23de-41aa-ad16-284f362bef9a')
    def Empty(self):
        '''Method ILineResequencer.Empty'''
        return super(ILineResequencer, self).Empty()
    def AddLine(self, pLine, lineID, eCategory):
        '''Method ILineResequencer.AddLine

           INPUTS
            pLine               : ICurve*
            lineID              : long
            eCategory           : esriCadastralLineCategory'''
        return super(ILineResequencer, self).AddLine(pLine, lineID, eCategory)
    def Sort(self, presentation):
        '''Method ILineResequencer.Sort

           INPUT
            presentation        : VARIANT_BOOL

           OUTPUTS
            ppLineOrder         : ILongArray**
            ppReverse           : ILongArray**
            ppParcel            : IGeometry**
            pFormsLoop          : VARIANT_BOOL*'''
        return super(ILineResequencer, self).Sort(presentation)

class ICadastralFabricRegeneration(_esriGeoDatabaseExtensions.ICadastralFabricRegeneration):
    _IID = uuid.UUID('98319c51-d6cf-45c9-b8e7-0cae17d55476')

    def __init__(self, *args, **kw):
        super(ICadastralFabricRegeneration, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def putref_CadastralFabric(self, ppCadastralFabric):
        '''Method ICadastralFabricRegeneration.putref_CadastralFabric

           INPUT
            ppCadastralFabric   : ICadastralFabric*'''
        return super(ICadastralFabricRegeneration, self).putref_CadastralFabric(ppCadastralFabric)
    def get_CadastralFabric(self):
        '''Method ICadastralFabricRegeneration.get_CadastralFabric

           OUTPUT
            ppCadastralFabric   : ICadastralFabric**'''
        return super(ICadastralFabricRegeneration, self).get_CadastralFabric()
    def put_RegeneratorBitmask(self, pRegeneratorBitmask):
        '''Method ICadastralFabricRegeneration.put_RegeneratorBitmask

           INPUT
            pRegeneratorBitmask : long'''
        return super(ICadastralFabricRegeneration, self).put_RegeneratorBitmask(pRegeneratorBitmask)
    def get_RegeneratorBitmask(self):
        '''Method ICadastralFabricRegeneration.get_RegeneratorBitmask

           OUTPUT
            pRegeneratorBitmask : long*'''
        return super(ICadastralFabricRegeneration, self).get_RegeneratorBitmask()
    def RegenerateParcels(self, pParcelsToRegenerate, regeneratePoints, pTrackCancel):
        '''Method ICadastralFabricRegeneration.RegenerateParcels

           INPUTS
            pParcelsToRegenerate: IFIDSet*
            regeneratePoints    : VARIANT_BOOL
            pTrackCancel        : ITrackCancel*'''
        return super(ICadastralFabricRegeneration, self).RegenerateParcels(pParcelsToRegenerate, regeneratePoints, pTrackCancel)
    def RegenerateAllParcels(self, regeneratePoints, pTrackCancel):
        '''Method ICadastralFabricRegeneration.RegenerateAllParcels

           INPUTS
            regeneratePoints    : VARIANT_BOOL
            pTrackCancel        : ITrackCancel*'''
        return super(ICadastralFabricRegeneration, self).RegenerateAllParcels(regeneratePoints, pTrackCancel)
    def RegenerateControlPoints(self, pControlPointsToRegenerate, pTrackCancel):
        '''Method ICadastralFabricRegeneration.RegenerateControlPoints

           INPUTS
            pControlPointsToRegenerate: IFIDSet*
            pTrackCancel        : ITrackCancel*'''
        return super(ICadastralFabricRegeneration, self).RegenerateControlPoints(pControlPointsToRegenerate, pTrackCancel)
    def RegenerateAllControlPoints(self, pTrackCancel):
        '''Method ICadastralFabricRegeneration.RegenerateAllControlPoints

           INPUT
            pTrackCancel        : ITrackCancel*'''
        return super(ICadastralFabricRegeneration, self).RegenerateAllControlPoints(pTrackCancel)
    def RegenerateEntireFabric(self, pTrackCancel):
        '''Method ICadastralFabricRegeneration.RegenerateEntireFabric

           INPUT
            pTrackCancel        : ITrackCancel*'''
        return super(ICadastralFabricRegeneration, self).RegenerateEntireFabric(pTrackCancel)
    def RegenerateMissingPoints(self, pTrackCancel):
        '''Method ICadastralFabricRegeneration.RegenerateMissingPoints

           INPUT
            pTrackCancel        : ITrackCancel*'''
        return super(ICadastralFabricRegeneration, self).RegenerateMissingPoints(pTrackCancel)
    CadastralFabric = property(get_CadastralFabric, putref_CadastralFabric, None)
    RegeneratorBitmask = property(get_RegeneratorBitmask, put_RegeneratorBitmask, None)

class ICadastralUnitConversion(_esriGeoDatabaseExtensions.ICadastralUnitConversion):
    _IID = uuid.UUID('f8b45123-3fd5-4f0b-bfa0-f81ae0a79df9')
    def get_DistanceUnitType(self, pLinearUnit):
        '''Method ICadastralUnitConversion.get_DistanceUnitType

           INPUT
            pLinearUnit         : ILinearUnit*

           OUTPUT
            pDistanceUnit       : esriCadastralDistanceUnits*'''
        return super(ICadastralUnitConversion, self).get_DistanceUnitType(pLinearUnit)
    def ConvertString(self, val, defaultUnit, outputUnit):
        '''Method ICadastralUnitConversion.ConvertString

           INPUTS
            val                 : BSTR
            defaultUnit         : esriCadastralDistanceUnits
            outputUnit          : esriCadastralDistanceUnits

           OUTPUT
            pVal                : double*'''
        return super(ICadastralUnitConversion, self).ConvertString(val, defaultUnit, outputUnit)
    def ConvertDouble(self, val, unit, outputUnit):
        '''Method ICadastralUnitConversion.ConvertDouble

           INPUTS
            val                 : double
            unit                : esriCadastralDistanceUnits
            outputUnit          : esriCadastralDistanceUnits

           OUTPUT
            pVal                : double*'''
        return super(ICadastralUnitConversion, self).ConvertDouble(val, unit, outputUnit)
    DistanceUnitType = IndexProperty(get_DistanceUnitType, None)

class ICadastralGroundToGridTools(_esriGeoDatabaseExtensions.ICadastralGroundToGridTools):
    _IID = uuid.UUID('69e2d388-48f1-407c-9f35-fc972034336a')
    def Inverse3D(self, pSR, argumentsInMeters, pPoint1, pPoint2):
        '''Method ICadastralGroundToGridTools.Inverse3D

           INPUTS
            pSR                 : ISpatialReference*
            argumentsInMeters   : VARIANT_BOOL
            pPoint1             : IPoint*
            pPoint2             : IPoint*

           OUTPUT
            pDistance           : double*'''
        return super(ICadastralGroundToGridTools, self).Inverse3D(pSR, argumentsInMeters, pPoint1, pPoint2)
    def Forward3D(self, pSR, argumentsInMeters, pPoint1, pPoint2Provisional, markToMarkDistance):
        '''Method ICadastralGroundToGridTools.Forward3D

           INPUTS
            pSR                 : ISpatialReference*
            argumentsInMeters   : VARIANT_BOOL
            pPoint1             : IPoint*
            pPoint2Provisional  : IPoint*
            markToMarkDistance  : double

           OUTPUT
            ppPoint             : IPoint**'''
        return super(ICadastralGroundToGridTools, self).Forward3D(pSR, argumentsInMeters, pPoint1, pPoint2Provisional, markToMarkDistance)

class ICadastralUnitTools(_esriGeoDatabaseExtensions.ICadastralUnitTools):
    _IID = uuid.UUID('0dc83354-e621-4c2d-9c2d-bad65c0727d1')
    def get_FormattedArea(self, areaSQMeters, eOutputAreaTypeDisplay, isUSFoot, decimalPlaces):
        '''Method ICadastralUnitTools.get_FormattedArea

           INPUTS
            areaSQMeters        : double
            eOutputAreaTypeDisplay: esriCadastralAreaUnits
            isUSFoot            : VARIANT_BOOL
            decimalPlaces       : long

           OUTPUT
            formatedArea        : BSTR*'''
        return super(ICadastralUnitTools, self).get_FormattedArea(areaSQMeters, eOutputAreaTypeDisplay, isUSFoot, decimalPlaces)
    def get_ConvertArea(self, areaSQMeters, eOutputAreaType):
        '''Method ICadastralUnitTools.get_ConvertArea

           INPUTS
            areaSQMeters        : double
            eOutputAreaType     : esriCadastralAreaUnits

           OUTPUT
            pArea               : double*'''
        return super(ICadastralUnitTools, self).get_ConvertArea(areaSQMeters, eOutputAreaType)
    def get_DirectionType(self, eDirType):
        '''Method ICadastralUnitTools.get_DirectionType

           INPUT
            eDirType            : esriDirectionType

           OUTPUT
            dirType             : BSTR*'''
        return super(ICadastralUnitTools, self).get_DirectionType(eDirType)
    def get_DirectionUnit(self, eDirUnit):
        '''Method ICadastralUnitTools.get_DirectionUnit

           INPUT
            eDirUnit            : esriDirectionUnits

           OUTPUT
            dirUnit             : BSTR*'''
        return super(ICadastralUnitTools, self).get_DirectionUnit(eDirUnit)
    def get_DistanceUnit(self, eDistanceType, shortNotation):
        '''Method ICadastralUnitTools.get_DistanceUnit

           INPUTS
            eDistanceType       : esriCadastralDistanceUnits
            shortNotation       : VARIANT_BOOL

           OUTPUT
            distUnit            : BSTR*'''
        return super(ICadastralUnitTools, self).get_DistanceUnit(eDistanceType, shortNotation)
    def get_AreaUnit(self, eAreaType, shortNotation):
        '''Method ICadastralUnitTools.get_AreaUnit

           INPUTS
            eAreaType           : esriCadastralAreaUnits
            shortNotation       : VARIANT_BOOL

           OUTPUT
            area                : BSTR*'''
        return super(ICadastralUnitTools, self).get_AreaUnit(eAreaType, shortNotation)
    DirectionType = IndexProperty(get_DirectionType, None)
    DirectionUnit = IndexProperty(get_DirectionUnit, None)

class ICadastralFabricEditControl(_esriGeoDatabaseExtensions.ICadastralFabricEditControl):
    _IID = uuid.UUID('a56b04a1-1748-40ab-bb7e-dfe95b34dd48')
    def SetStoreEventsRequired(self):
        '''Method ICadastralFabricEditControl.SetStoreEventsRequired'''
        return super(ICadastralFabricEditControl, self).SetStoreEventsRequired()

class IDataMessage(_esriGeoDatabaseExtensions.IDataMessage):
    _IID = uuid.UUID('cc018a04-24fb-11d4-b34c-00104ba2abcc')

    def __init__(self, *args, **kw):
        super(IDataMessage, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_CreationDate(self):
        '''Method IDataMessage.get_CreationDate

           OUTPUT
            pVal                : VARIANT*'''
        return super(IDataMessage, self).get_CreationDate()
    def get_ID(self):
        '''Method IDataMessage.get_ID

           OUTPUT
            pVal                : BSTR*'''
        return super(IDataMessage, self).get_ID()
    def get_MessageType(self):
        '''Method IDataMessage.get_MessageType

           OUTPUT
            pVal                : enumMessageType*'''
        return super(IDataMessage, self).get_MessageType()
    def get_Priority(self):
        '''Method IDataMessage.get_Priority

           OUTPUT
            pVal                : int*'''
        return super(IDataMessage, self).get_Priority()
    def put_Priority(self, pVal):
        '''Method IDataMessage.put_Priority

           INPUT
            pVal                : int'''
        return super(IDataMessage, self).put_Priority(pVal)
    def get_Destination(self):
        '''Method IDataMessage.get_Destination

           OUTPUT
            pVal                : BSTR*'''
        return super(IDataMessage, self).get_Destination()
    def put_Destination(self, pVal):
        '''Method IDataMessage.put_Destination

           INPUT
            pVal                : BSTR'''
        return super(IDataMessage, self).put_Destination(pVal)
    def get_ArgumentCount(self):
        '''Method IDataMessage.get_ArgumentCount

           OUTPUT
            pVal                : int*'''
        return super(IDataMessage, self).get_ArgumentCount()
    def setArgument(self, nIndex, pValue):
        '''Method IDataMessage.setArgument

           INPUTS
            nIndex              : int
            pValue              : VARIANT*'''
        return super(IDataMessage, self).setArgument(nIndex, pValue)
    def addArgument(self, pValue):
        '''Method IDataMessage.addArgument

           INPUT
            pValue              : VARIANT*'''
        return super(IDataMessage, self).addArgument(pValue)
    def removeArgument(self, nIndex):
        '''Method IDataMessage.removeArgument

           INPUT
            nIndex              : int'''
        return super(IDataMessage, self).removeArgument(nIndex)
    def getArgument(self, nIndex):
        '''Method IDataMessage.getArgument

           INPUT
            nIndex              : int

           OUTPUT
            pValue              : VARIANT*'''
        return super(IDataMessage, self).getArgument(nIndex)
    def get_DataDefinitionID(self):
        '''Method IDataMessage.get_DataDefinitionID

           OUTPUT
            pVal                : BSTR*'''
        return super(IDataMessage, self).get_DataDefinitionID()
    def put_DataDefinitionID(self, pVal):
        '''Method IDataMessage.put_DataDefinitionID

           INPUT
            pVal                : BSTR'''
        return super(IDataMessage, self).put_DataDefinitionID(pVal)
    def get_ColumnCount(self):
        '''Method IDataMessage.get_ColumnCount

           OUTPUT
            pVal                : int*'''
        return super(IDataMessage, self).get_ColumnCount()
    def setColumn(self, nIndex, pValue):
        '''Method IDataMessage.setColumn

           INPUTS
            nIndex              : int
            pValue              : VARIANT*'''
        return super(IDataMessage, self).setColumn(nIndex, pValue)
    def addColumn(self, pValue):
        '''Method IDataMessage.addColumn

           INPUT
            pValue              : VARIANT*'''
        return super(IDataMessage, self).addColumn(pValue)
    def removeColumn(self, nIndex):
        '''Method IDataMessage.removeColumn

           INPUT
            nIndex              : int'''
        return super(IDataMessage, self).removeColumn(nIndex)
    def getColumn(self, nIndex):
        '''Method IDataMessage.getColumn

           INPUT
            nIndex              : int

           OUTPUT
            pValue              : VARIANT*'''
        return super(IDataMessage, self).getColumn(nIndex)
    def getRawColumn(self, nIndex):
        '''Method IDataMessage.getRawColumn

           INPUT
            nIndex              : int

           OUTPUT
            pValue              : VARIANT*'''
        return super(IDataMessage, self).getRawColumn(nIndex)
    ArgumentCount = property(get_ArgumentCount, None, None)
    ColumnCount = property(get_ColumnCount, None, None)
    CreationDate = property(get_CreationDate, None, None)
    DataDefinitionID = property(get_DataDefinitionID, put_DataDefinitionID, None)
    Destination = property(get_Destination, put_Destination, None)
    ID = property(get_ID, None, None)
    MessageType = property(get_MessageType, None, None)
    Priority = property(get_Priority, put_Priority, None)

class ITemporalOperator(_esriGeoDatabaseExtensions.ITemporalOperator):
    _IID = uuid.UUID('56ae7150-7bfc-11d6-b84d-00010265adc5')
    def SetDateTime(self, lYear, lMonth, lDayOfMonth, lHour, lMinute, lSecond, lMillisecond):
        '''Method ITemporalOperator.SetDateTime

           INPUTS
            lYear               : long
            lMonth              : short
            lDayOfMonth         : short
            lHour               : short
            lMinute             : short
            lSecond             : short
            lMillisecond        : short'''
        return super(ITemporalOperator, self).SetDateTime(lYear, lMonth, lDayOfMonth, lHour, lMinute, lSecond, lMillisecond)
    def SetInterval(self, dQuantity, enumUnits):
        '''Method ITemporalOperator.SetInterval

           INPUTS
            dQuantity           : double
            enumUnits           : enumTemporalOperatorUnits'''
        return super(ITemporalOperator, self).SetInterval(dQuantity, enumUnits)
    def get_Type(self):
        '''Method ITemporalOperator.get_Type

           OUTPUT
            pVal                : enumTemporalOperatorType*'''
        return super(ITemporalOperator, self).get_Type()
    def Reset(self):
        '''Method ITemporalOperator.Reset'''
        return super(ITemporalOperator, self).Reset()
    def Add(self, piOtherOperator):
        '''Method ITemporalOperator.Add

           INPUT
            piOtherOperator     : ITemporalOperator*'''
        return super(ITemporalOperator, self).Add(piOtherOperator)
    def Subtract(self, piOtherOperator):
        '''Method ITemporalOperator.Subtract

           INPUT
            piOtherOperator     : ITemporalOperator*'''
        return super(ITemporalOperator, self).Subtract(piOtherOperator)
    def get_AsString(self, bstrFormat):
        '''Method ITemporalOperator.get_AsString

           INPUT
            bstrFormat          : BSTR

           OUTPUT
            pVal                : BSTR*'''
        return super(ITemporalOperator, self).get_AsString(bstrFormat)
    def get_AsDate(self):
        '''Method ITemporalOperator.get_AsDate

           OUTPUT
            pVal                : VARIANT*'''
        return super(ITemporalOperator, self).get_AsDate()
    def get_AsInterval(self, enumUnits):
        '''Method ITemporalOperator.get_AsInterval

           INPUT
            enumUnits           : enumTemporalOperatorUnits

           OUTPUT
            pVal                : VARIANT*'''
        return super(ITemporalOperator, self).get_AsInterval(enumUnits)
    def get_Value(self):
        '''Method ITemporalOperator.get_Value

           OUTPUT
            pVal                : VARIANT*'''
        return super(ITemporalOperator, self).get_Value()
    def get_IntervalQuantity(self):
        '''Method ITemporalOperator.get_IntervalQuantity

           OUTPUT
            pVal                : double*'''
        return super(ITemporalOperator, self).get_IntervalQuantity()
    def get_IntervalUnits(self):
        '''Method ITemporalOperator.get_IntervalUnits

           OUTPUT
            pVal                : enumTemporalOperatorUnits*'''
        return super(ITemporalOperator, self).get_IntervalUnits()
    AsDate = property(get_AsDate, None, None)
    IntervalQuantity = property(get_IntervalQuantity, None, None)
    IntervalUnits = property(get_IntervalUnits, None, None)
    Type = property(get_Type, None, None)
    Value = property(get_Value, None, None)
    AsInterval = IndexProperty(get_AsInterval, None)
    AsString = IndexProperty(get_AsString, None)

class ITrackingServiceDef(_esriGeoDatabaseExtensions.ITrackingServiceDef):
    _IID = uuid.UUID('1b9c2538-3b1d-11d5-b7e4-00010265adc5')

    def __init__(self, *args, **kw):
        super(ITrackingServiceDef, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method ITrackingServiceDef.get_Name

           OUTPUT
            pVal                : BSTR*'''
        return super(ITrackingServiceDef, self).get_Name()
    def put_Name(self, pVal):
        '''Method ITrackingServiceDef.put_Name

           INPUT
            pVal                : BSTR'''
        return super(ITrackingServiceDef, self).put_Name(pVal)
    def get_MetaData(self):
        '''Method ITrackingServiceDef.get_MetaData

           OUTPUT
            pVal                : BSTR*'''
        return super(ITrackingServiceDef, self).get_MetaData()
    def put_MetaData(self, pVal):
        '''Method ITrackingServiceDef.put_MetaData

           INPUT
            pVal                : BSTR'''
        return super(ITrackingServiceDef, self).put_MetaData(pVal)
    def get_ObjectDefinitionName(self):
        '''Method ITrackingServiceDef.get_ObjectDefinitionName

           OUTPUT
            pVal                : BSTR*'''
        return super(ITrackingServiceDef, self).get_ObjectDefinitionName()
    def put_ObjectDefinitionName(self, pVal):
        '''Method ITrackingServiceDef.put_ObjectDefinitionName

           INPUT
            pVal                : BSTR'''
        return super(ITrackingServiceDef, self).put_ObjectDefinitionName(pVal)
    def get_ObservationDefinitionName(self):
        '''Method ITrackingServiceDef.get_ObservationDefinitionName

           OUTPUT
            pVal                : BSTR*'''
        return super(ITrackingServiceDef, self).get_ObservationDefinitionName()
    def put_ObservationDefinitionName(self, pVal):
        '''Method ITrackingServiceDef.put_ObservationDefinitionName

           INPUT
            pVal                : BSTR'''
        return super(ITrackingServiceDef, self).put_ObservationDefinitionName(pVal)
    def get_ObjectSource(self):
        '''Method ITrackingServiceDef.get_ObjectSource

           OUTPUT
            pVal                : enumObjectSource*'''
        return super(ITrackingServiceDef, self).get_ObjectSource()
    def put_ObjectSource(self, pVal):
        '''Method ITrackingServiceDef.put_ObjectSource

           INPUT
            pVal                : enumObjectSource'''
        return super(ITrackingServiceDef, self).put_ObjectSource(pVal)
    def get_ObjectSourceConnectionString(self):
        '''Method ITrackingServiceDef.get_ObjectSourceConnectionString

           OUTPUT
            pVal                : BSTR*'''
        return super(ITrackingServiceDef, self).get_ObjectSourceConnectionString()
    def put_ObjectSourceConnectionString(self, pVal):
        '''Method ITrackingServiceDef.put_ObjectSourceConnectionString

           INPUT
            pVal                : BSTR'''
        return super(ITrackingServiceDef, self).put_ObjectSourceConnectionString(pVal)
    def get_SourceOfGeometry(self):
        '''Method ITrackingServiceDef.get_SourceOfGeometry

           OUTPUT
            pVal                : enumShapeSource*'''
        return super(ITrackingServiceDef, self).get_SourceOfGeometry()
    def put_SourceOfGeometry(self, pVal):
        '''Method ITrackingServiceDef.put_SourceOfGeometry

           INPUT
            pVal                : enumShapeSource'''
        return super(ITrackingServiceDef, self).put_SourceOfGeometry(pVal)
    MetaData = property(get_MetaData, put_MetaData, None)
    Name = property(get_Name, put_Name, None)
    ObjectDefinitionName = property(get_ObjectDefinitionName, put_ObjectDefinitionName, None)
    ObjectSource = property(get_ObjectSource, put_ObjectSource, None)
    ObjectSourceConnectionString = property(get_ObjectSourceConnectionString, put_ObjectSourceConnectionString, None)
    ObservationDefinitionName = property(get_ObservationDefinitionName, put_ObservationDefinitionName, None)
    SourceOfGeometry = property(get_SourceOfGeometry, put_SourceOfGeometry, None)

class _ITemporalFeatureClassEvents(_esriGeoDatabaseExtensions._ITemporalFeatureClassEvents):
    _IID = uuid.UUID('cc018a65-24fb-11d4-b34c-00104ba2abcc')
    def OnAddData(self, piEnvelope, piFeatureClass):
        '''Method _ITemporalFeatureClassEvents.OnAddData

           INPUTS
            piEnvelope          : IEnvelope*
            piFeatureClass      : IFeatureClass*'''
        return super(_ITemporalFeatureClassEvents, self).OnAddData(piEnvelope, piFeatureClass)
    def OnRemoveData(self, piEnvelope, piFeatureClass):
        '''Method _ITemporalFeatureClassEvents.OnRemoveData

           INPUTS
            piEnvelope          : IEnvelope*
            piFeatureClass      : IFeatureClass*'''
        return super(_ITemporalFeatureClassEvents, self).OnRemoveData(piEnvelope, piFeatureClass)

class ITemporalFeatureClass2(_esriGeoDatabaseExtensions.ITemporalFeatureClass2):
    _IID = uuid.UUID('4b026c0c-7189-4edf-9ea0-568c9d092257')
    def get_ServerName(self):
        '''Method ITemporalFeatureClass2.get_ServerName

           OUTPUT
            Name                : BSTR*'''
        return super(ITemporalFeatureClass2, self).get_ServerName()
    def get_ConnectionName(self):
        '''Method ITemporalFeatureClass2.get_ConnectionName

           OUTPUT
            Name                : BSTR*'''
        return super(ITemporalFeatureClass2, self).get_ConnectionName()
    ConnectionName = property(get_ConnectionName, None, None)
    ServerName = property(get_ServerName, None, None)

class ITemporalTable(_esriGeoDatabaseExtensions.ITemporalTable):
    _IID = uuid.UUID('18fb46e0-461a-11d5-b7e5-00010265adc5')

    def __init__(self, *args, **kw):
        super(ITemporalTable, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def FindField(self, Name):
        '''Method ITemporalTable.FindField

           INPUT
            Name                : BSTR

           OUTPUT
            FieldIndex          : long*'''
        return super(ITemporalTable, self).FindField(Name)
    def get_Fields(self):
        '''Method ITemporalTable.get_Fields

           OUTPUT
            Fields              : IFields**'''
        return super(ITemporalTable, self).get_Fields()
    def AddField(self, Field):
        '''Method ITemporalTable.AddField

           INPUT
            Field               : IField*'''
        return super(ITemporalTable, self).AddField(Field)
    def DeleteField(self, Field):
        '''Method ITemporalTable.DeleteField

           INPUT
            Field               : IField*'''
        return super(ITemporalTable, self).DeleteField(Field)
    def CreateRow(self):
        '''Method ITemporalTable.CreateRow

           OUTPUT
            Row                 : IRow**'''
        return super(ITemporalTable, self).CreateRow()
    def GetRow(self, OID):
        '''Method ITemporalTable.GetRow

           INPUT
            OID                 : long

           OUTPUT
            Row                 : IRow**'''
        return super(ITemporalTable, self).GetRow(OID)
    def CreateRowBuffer(self):
        '''Method ITemporalTable.CreateRowBuffer

           OUTPUT
            Buffer              : IRowBuffer**'''
        return super(ITemporalTable, self).CreateRowBuffer()
    def RowCount(self, QueryFilter):
        '''Method ITemporalTable.RowCount

           INPUT
            QueryFilter         : IQueryFilter*

           OUTPUT
            NumRows             : long*'''
        return super(ITemporalTable, self).RowCount(QueryFilter)
    def Search(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Search

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalTable, self).Search(QueryFilter, Recycling)
    def Update(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Update

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalTable, self).Update(QueryFilter, Recycling)
    def Insert(self, useBuffering):
        '''Method ITemporalTable.Insert

           INPUT
            useBuffering        : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalTable, self).Insert(useBuffering)
    def Select(self, QueryFilter, selType, selOption, selectionContainer):
        '''Method ITemporalTable.Select

           INPUTS
            QueryFilter         : IQueryFilter*
            selType             : esriSelectionType
            selOption           : esriSelectionOption
            selectionContainer  : IWorkspace*

           OUTPUT
            ppSelectionSet      : ISelectionSet**'''
        return super(ITemporalTable, self).Select(QueryFilter, selType, selOption, selectionContainer)
    def get_HasGeometry(self):
        '''Method ITemporalTable.get_HasGeometry

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ITemporalTable, self).get_HasGeometry()
    def get_GeometryColumnName(self):
        '''Method ITemporalTable.get_GeometryColumnName

           OUTPUT
            pbstrColumnName     : BSTR*'''
        return super(ITemporalTable, self).get_GeometryColumnName()
    def put_GeometryColumnName(self, pbstrColumnName):
        '''Method ITemporalTable.put_GeometryColumnName

           INPUT
            pbstrColumnName     : BSTR'''
        return super(ITemporalTable, self).put_GeometryColumnName(pbstrColumnName)
    Fields = property(get_Fields, None, None)
    GeometryColumnName = property(get_GeometryColumnName, put_GeometryColumnName, None)
    HasGeometry = property(get_HasGeometry, None, None)

class IInternalTable(_esriGeoDatabaseExtensions.IInternalTable):
    _IID = uuid.UUID('a677ab63-2fb8-11d5-b7e2-00010265adc5')

    def __init__(self, *args, **kw):
        super(IInternalTable, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def AddRow(self, piDataMessage):
        '''Method IInternalTable.AddRow

           INPUT
            piDataMessage       : IDataMessage*

           OUTPUT
            plRowID             : long*'''
        return super(IInternalTable, self).AddRow(piDataMessage)
    def FindField(self, Name):
        '''Method ITemporalTable.FindField (from ITemporalTable)

           INPUT
            Name                : BSTR

           OUTPUT
            FieldIndex          : long*'''
        return super(IInternalTable, self).FindField(Name)
    def get_Fields(self):
        '''Method ITemporalTable.get_Fields (from ITemporalTable)

           OUTPUT
            Fields              : IFields**'''
        return super(IInternalTable, self).get_Fields()
    def AddField(self, Field):
        '''Method ITemporalTable.AddField (from ITemporalTable)

           INPUT
            Field               : IField*'''
        return super(IInternalTable, self).AddField(Field)
    def DeleteField(self, Field):
        '''Method ITemporalTable.DeleteField (from ITemporalTable)

           INPUT
            Field               : IField*'''
        return super(IInternalTable, self).DeleteField(Field)
    def CreateRow(self):
        '''Method ITemporalTable.CreateRow (from ITemporalTable)

           OUTPUT
            Row                 : IRow**'''
        return super(IInternalTable, self).CreateRow()
    def GetRow(self, OID):
        '''Method ITemporalTable.GetRow (from ITemporalTable)

           INPUT
            OID                 : long

           OUTPUT
            Row                 : IRow**'''
        return super(IInternalTable, self).GetRow(OID)
    def CreateRowBuffer(self):
        '''Method ITemporalTable.CreateRowBuffer (from ITemporalTable)

           OUTPUT
            Buffer              : IRowBuffer**'''
        return super(IInternalTable, self).CreateRowBuffer()
    def RowCount(self, QueryFilter):
        '''Method ITemporalTable.RowCount (from ITemporalTable)

           INPUT
            QueryFilter         : IQueryFilter*

           OUTPUT
            NumRows             : long*'''
        return super(IInternalTable, self).RowCount(QueryFilter)
    def Search(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Search (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(IInternalTable, self).Search(QueryFilter, Recycling)
    def Update(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Update (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(IInternalTable, self).Update(QueryFilter, Recycling)
    def Insert(self, useBuffering):
        '''Method ITemporalTable.Insert (from ITemporalTable)

           INPUT
            useBuffering        : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(IInternalTable, self).Insert(useBuffering)
    def Select(self, QueryFilter, selType, selOption, selectionContainer):
        '''Method ITemporalTable.Select (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            selType             : esriSelectionType
            selOption           : esriSelectionOption
            selectionContainer  : IWorkspace*

           OUTPUT
            ppSelectionSet      : ISelectionSet**'''
        return super(IInternalTable, self).Select(QueryFilter, selType, selOption, selectionContainer)
    def get_HasGeometry(self):
        '''Method ITemporalTable.get_HasGeometry (from ITemporalTable)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IInternalTable, self).get_HasGeometry()
    def get_GeometryColumnName(self):
        '''Method ITemporalTable.get_GeometryColumnName (from ITemporalTable)

           OUTPUT
            pbstrColumnName     : BSTR*'''
        return super(IInternalTable, self).get_GeometryColumnName()
    def put_GeometryColumnName(self, pbstrColumnName):
        '''Method ITemporalTable.put_GeometryColumnName (from ITemporalTable)

           INPUT
            pbstrColumnName     : BSTR'''
        return super(IInternalTable, self).put_GeometryColumnName(pbstrColumnName)
    Fields = property(get_Fields, None, None)
    GeometryColumnName = property(get_GeometryColumnName, put_GeometryColumnName, None)
    HasGeometry = property(get_HasGeometry, None, None)

class ITemporalObservationsTable(_esriGeoDatabaseExtensions.ITemporalObservationsTable):
    _IID = uuid.UUID('a677ab5f-2fb8-11d5-b7e2-00010265adc5')

    def __init__(self, *args, **kw):
        super(ITemporalObservationsTable, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_AutoPurge(self):
        '''Method ITemporalObservationsTable.get_AutoPurge

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ITemporalObservationsTable, self).get_AutoPurge()
    def put_AutoPurge(self, pVal):
        '''Method ITemporalObservationsTable.put_AutoPurge

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(ITemporalObservationsTable, self).put_AutoPurge(pVal)
    def get_Threshold(self):
        '''Method ITemporalObservationsTable.get_Threshold

           OUTPUT
            pvarVal             : VARIANT*'''
        return super(ITemporalObservationsTable, self).get_Threshold()
    def put_Threshold(self, pvarVal):
        '''Method ITemporalObservationsTable.put_Threshold

           INPUT
            pvarVal             : VARIANT'''
        return super(ITemporalObservationsTable, self).put_Threshold(pvarVal)
    def get_PurgePercentage(self):
        '''Method ITemporalObservationsTable.get_PurgePercentage

           OUTPUT
            pVal                : double*'''
        return super(ITemporalObservationsTable, self).get_PurgePercentage()
    def put_PurgePercentage(self, pVal):
        '''Method ITemporalObservationsTable.put_PurgePercentage

           INPUT
            pVal                : double'''
        return super(ITemporalObservationsTable, self).put_PurgePercentage(pVal)
    def get_Persistant(self):
        '''Method ITemporalObservationsTable.get_Persistant

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ITemporalObservationsTable, self).get_Persistant()
    def put_Persistant(self, pVal):
        '''Method ITemporalObservationsTable.put_Persistant

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(ITemporalObservationsTable, self).put_Persistant(pVal)
    def get_TemporalColumnName(self):
        '''Method ITemporalObservationsTable.get_TemporalColumnName

           OUTPUT
            pVal                : BSTR*'''
        return super(ITemporalObservationsTable, self).get_TemporalColumnName()
    def put_TemporalColumnName(self, pVal):
        '''Method ITemporalObservationsTable.put_TemporalColumnName

           INPUT
            pVal                : BSTR'''
        return super(ITemporalObservationsTable, self).put_TemporalColumnName(pVal)
    def get_PurgeRule(self):
        '''Method ITemporalObservationsTable.get_PurgeRule

           OUTPUT
            pVal                : enumPurgeRule*'''
        return super(ITemporalObservationsTable, self).get_PurgeRule()
    def put_PurgeRule(self, pVal):
        '''Method ITemporalObservationsTable.put_PurgeRule

           INPUT
            pVal                : enumPurgeRule'''
        return super(ITemporalObservationsTable, self).put_PurgeRule(pVal)
    def PruneTable(self):
        '''Method ITemporalObservationsTable.PruneTable'''
        return super(ITemporalObservationsTable, self).PruneTable()
    def QueryTemporalExtent(self):
        '''Method ITemporalObservationsTable.QueryTemporalExtent

           OUTPUTS
            pvarStartTime       : VARIANT*
            pvarEndTime         : VARIANT*'''
        return super(ITemporalObservationsTable, self).QueryTemporalExtent()
    def FindField(self, Name):
        '''Method ITemporalTable.FindField (from ITemporalTable)

           INPUT
            Name                : BSTR

           OUTPUT
            FieldIndex          : long*'''
        return super(ITemporalObservationsTable, self).FindField(Name)
    def get_Fields(self):
        '''Method ITemporalTable.get_Fields (from ITemporalTable)

           OUTPUT
            Fields              : IFields**'''
        return super(ITemporalObservationsTable, self).get_Fields()
    def AddField(self, Field):
        '''Method ITemporalTable.AddField (from ITemporalTable)

           INPUT
            Field               : IField*'''
        return super(ITemporalObservationsTable, self).AddField(Field)
    def DeleteField(self, Field):
        '''Method ITemporalTable.DeleteField (from ITemporalTable)

           INPUT
            Field               : IField*'''
        return super(ITemporalObservationsTable, self).DeleteField(Field)
    def CreateRow(self):
        '''Method ITemporalTable.CreateRow (from ITemporalTable)

           OUTPUT
            Row                 : IRow**'''
        return super(ITemporalObservationsTable, self).CreateRow()
    def GetRow(self, OID):
        '''Method ITemporalTable.GetRow (from ITemporalTable)

           INPUT
            OID                 : long

           OUTPUT
            Row                 : IRow**'''
        return super(ITemporalObservationsTable, self).GetRow(OID)
    def CreateRowBuffer(self):
        '''Method ITemporalTable.CreateRowBuffer (from ITemporalTable)

           OUTPUT
            Buffer              : IRowBuffer**'''
        return super(ITemporalObservationsTable, self).CreateRowBuffer()
    def RowCount(self, QueryFilter):
        '''Method ITemporalTable.RowCount (from ITemporalTable)

           INPUT
            QueryFilter         : IQueryFilter*

           OUTPUT
            NumRows             : long*'''
        return super(ITemporalObservationsTable, self).RowCount(QueryFilter)
    def Search(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Search (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalObservationsTable, self).Search(QueryFilter, Recycling)
    def Update(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Update (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalObservationsTable, self).Update(QueryFilter, Recycling)
    def Insert(self, useBuffering):
        '''Method ITemporalTable.Insert (from ITemporalTable)

           INPUT
            useBuffering        : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalObservationsTable, self).Insert(useBuffering)
    def Select(self, QueryFilter, selType, selOption, selectionContainer):
        '''Method ITemporalTable.Select (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            selType             : esriSelectionType
            selOption           : esriSelectionOption
            selectionContainer  : IWorkspace*

           OUTPUT
            ppSelectionSet      : ISelectionSet**'''
        return super(ITemporalObservationsTable, self).Select(QueryFilter, selType, selOption, selectionContainer)
    def get_HasGeometry(self):
        '''Method ITemporalTable.get_HasGeometry (from ITemporalTable)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ITemporalObservationsTable, self).get_HasGeometry()
    def get_GeometryColumnName(self):
        '''Method ITemporalTable.get_GeometryColumnName (from ITemporalTable)

           OUTPUT
            pbstrColumnName     : BSTR*'''
        return super(ITemporalObservationsTable, self).get_GeometryColumnName()
    def put_GeometryColumnName(self, pbstrColumnName):
        '''Method ITemporalTable.put_GeometryColumnName (from ITemporalTable)

           INPUT
            pbstrColumnName     : BSTR'''
        return super(ITemporalObservationsTable, self).put_GeometryColumnName(pbstrColumnName)
    AutoPurge = property(get_AutoPurge, put_AutoPurge, None)
    Fields = property(get_Fields, None, None)
    GeometryColumnName = property(get_GeometryColumnName, put_GeometryColumnName, None)
    HasGeometry = property(get_HasGeometry, None, None)
    Persistant = property(get_Persistant, put_Persistant, None)
    PurgePercentage = property(get_PurgePercentage, put_PurgePercentage, None)
    PurgeRule = property(get_PurgeRule, put_PurgeRule, None)
    TemporalColumnName = property(get_TemporalColumnName, put_TemporalColumnName, None)
    Threshold = property(get_Threshold, put_Threshold, None)

class ITemporalObjectTable(_esriGeoDatabaseExtensions.ITemporalObjectTable):
    _IID = uuid.UUID('a677ab60-2fb8-11d5-b7e2-00010265adc5')

    def __init__(self, *args, **kw):
        super(ITemporalObjectTable, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TrackingColumnName(self):
        '''Method ITemporalObjectTable.get_TrackingColumnName

           OUTPUT
            pbstrColumnName     : BSTR*'''
        return super(ITemporalObjectTable, self).get_TrackingColumnName()
    def FindField(self, Name):
        '''Method ITemporalTable.FindField (from ITemporalTable)

           INPUT
            Name                : BSTR

           OUTPUT
            FieldIndex          : long*'''
        return super(ITemporalObjectTable, self).FindField(Name)
    def get_Fields(self):
        '''Method ITemporalTable.get_Fields (from ITemporalTable)

           OUTPUT
            Fields              : IFields**'''
        return super(ITemporalObjectTable, self).get_Fields()
    def AddField(self, Field):
        '''Method ITemporalTable.AddField (from ITemporalTable)

           INPUT
            Field               : IField*'''
        return super(ITemporalObjectTable, self).AddField(Field)
    def DeleteField(self, Field):
        '''Method ITemporalTable.DeleteField (from ITemporalTable)

           INPUT
            Field               : IField*'''
        return super(ITemporalObjectTable, self).DeleteField(Field)
    def CreateRow(self):
        '''Method ITemporalTable.CreateRow (from ITemporalTable)

           OUTPUT
            Row                 : IRow**'''
        return super(ITemporalObjectTable, self).CreateRow()
    def GetRow(self, OID):
        '''Method ITemporalTable.GetRow (from ITemporalTable)

           INPUT
            OID                 : long

           OUTPUT
            Row                 : IRow**'''
        return super(ITemporalObjectTable, self).GetRow(OID)
    def CreateRowBuffer(self):
        '''Method ITemporalTable.CreateRowBuffer (from ITemporalTable)

           OUTPUT
            Buffer              : IRowBuffer**'''
        return super(ITemporalObjectTable, self).CreateRowBuffer()
    def RowCount(self, QueryFilter):
        '''Method ITemporalTable.RowCount (from ITemporalTable)

           INPUT
            QueryFilter         : IQueryFilter*

           OUTPUT
            NumRows             : long*'''
        return super(ITemporalObjectTable, self).RowCount(QueryFilter)
    def Search(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Search (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalObjectTable, self).Search(QueryFilter, Recycling)
    def Update(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Update (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalObjectTable, self).Update(QueryFilter, Recycling)
    def Insert(self, useBuffering):
        '''Method ITemporalTable.Insert (from ITemporalTable)

           INPUT
            useBuffering        : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalObjectTable, self).Insert(useBuffering)
    def Select(self, QueryFilter, selType, selOption, selectionContainer):
        '''Method ITemporalTable.Select (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            selType             : esriSelectionType
            selOption           : esriSelectionOption
            selectionContainer  : IWorkspace*

           OUTPUT
            ppSelectionSet      : ISelectionSet**'''
        return super(ITemporalObjectTable, self).Select(QueryFilter, selType, selOption, selectionContainer)
    def get_HasGeometry(self):
        '''Method ITemporalTable.get_HasGeometry (from ITemporalTable)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ITemporalObjectTable, self).get_HasGeometry()
    def get_GeometryColumnName(self):
        '''Method ITemporalTable.get_GeometryColumnName (from ITemporalTable)

           OUTPUT
            pbstrColumnName     : BSTR*'''
        return super(ITemporalObjectTable, self).get_GeometryColumnName()
    def put_GeometryColumnName(self, pbstrColumnName):
        '''Method ITemporalTable.put_GeometryColumnName (from ITemporalTable)

           INPUT
            pbstrColumnName     : BSTR'''
        return super(ITemporalObjectTable, self).put_GeometryColumnName(pbstrColumnName)
    Fields = property(get_Fields, None, None)
    GeometryColumnName = property(get_GeometryColumnName, put_GeometryColumnName, None)
    HasGeometry = property(get_HasGeometry, None, None)
    TrackingColumnName = property(get_TrackingColumnName, None, None)

class ITemporalObservationsTable2(_esriGeoDatabaseExtensions.ITemporalObservationsTable2):
    _IID = uuid.UUID('aec7a38a-f684-40fc-b2f2-96000ebf22d8')

    def __init__(self, *args, **kw):
        super(ITemporalObservationsTable2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_TrackingColumnIndex(self, _arg1):
        '''Method ITemporalObservationsTable2.put_TrackingColumnIndex

           INPUT
            _arg1               : long'''
        return super(ITemporalObservationsTable2, self).put_TrackingColumnIndex(_arg1)
    def get_AutoPurge(self):
        '''Method ITemporalObservationsTable.get_AutoPurge (from ITemporalObservationsTable)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ITemporalObservationsTable2, self).get_AutoPurge()
    def put_AutoPurge(self, pVal):
        '''Method ITemporalObservationsTable.put_AutoPurge (from ITemporalObservationsTable)

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(ITemporalObservationsTable2, self).put_AutoPurge(pVal)
    def get_Threshold(self):
        '''Method ITemporalObservationsTable.get_Threshold (from ITemporalObservationsTable)

           OUTPUT
            pvarVal             : VARIANT*'''
        return super(ITemporalObservationsTable2, self).get_Threshold()
    def put_Threshold(self, pvarVal):
        '''Method ITemporalObservationsTable.put_Threshold (from ITemporalObservationsTable)

           INPUT
            pvarVal             : VARIANT'''
        return super(ITemporalObservationsTable2, self).put_Threshold(pvarVal)
    def get_PurgePercentage(self):
        '''Method ITemporalObservationsTable.get_PurgePercentage (from ITemporalObservationsTable)

           OUTPUT
            pVal                : double*'''
        return super(ITemporalObservationsTable2, self).get_PurgePercentage()
    def put_PurgePercentage(self, pVal):
        '''Method ITemporalObservationsTable.put_PurgePercentage (from ITemporalObservationsTable)

           INPUT
            pVal                : double'''
        return super(ITemporalObservationsTable2, self).put_PurgePercentage(pVal)
    def get_Persistant(self):
        '''Method ITemporalObservationsTable.get_Persistant (from ITemporalObservationsTable)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ITemporalObservationsTable2, self).get_Persistant()
    def put_Persistant(self, pVal):
        '''Method ITemporalObservationsTable.put_Persistant (from ITemporalObservationsTable)

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(ITemporalObservationsTable2, self).put_Persistant(pVal)
    def get_TemporalColumnName(self):
        '''Method ITemporalObservationsTable.get_TemporalColumnName (from ITemporalObservationsTable)

           OUTPUT
            pVal                : BSTR*'''
        return super(ITemporalObservationsTable2, self).get_TemporalColumnName()
    def put_TemporalColumnName(self, pVal):
        '''Method ITemporalObservationsTable.put_TemporalColumnName (from ITemporalObservationsTable)

           INPUT
            pVal                : BSTR'''
        return super(ITemporalObservationsTable2, self).put_TemporalColumnName(pVal)
    def get_PurgeRule(self):
        '''Method ITemporalObservationsTable.get_PurgeRule (from ITemporalObservationsTable)

           OUTPUT
            pVal                : enumPurgeRule*'''
        return super(ITemporalObservationsTable2, self).get_PurgeRule()
    def put_PurgeRule(self, pVal):
        '''Method ITemporalObservationsTable.put_PurgeRule (from ITemporalObservationsTable)

           INPUT
            pVal                : enumPurgeRule'''
        return super(ITemporalObservationsTable2, self).put_PurgeRule(pVal)
    def PruneTable(self):
        '''Method ITemporalObservationsTable.PruneTable (from ITemporalObservationsTable)'''
        return super(ITemporalObservationsTable2, self).PruneTable()
    def QueryTemporalExtent(self):
        '''Method ITemporalObservationsTable.QueryTemporalExtent (from ITemporalObservationsTable)

           OUTPUTS
            pvarStartTime       : VARIANT*
            pvarEndTime         : VARIANT*'''
        return super(ITemporalObservationsTable2, self).QueryTemporalExtent()
    def FindField(self, Name):
        '''Method ITemporalTable.FindField (from ITemporalTable)

           INPUT
            Name                : BSTR

           OUTPUT
            FieldIndex          : long*'''
        return super(ITemporalObservationsTable2, self).FindField(Name)
    def get_Fields(self):
        '''Method ITemporalTable.get_Fields (from ITemporalTable)

           OUTPUT
            Fields              : IFields**'''
        return super(ITemporalObservationsTable2, self).get_Fields()
    def AddField(self, Field):
        '''Method ITemporalTable.AddField (from ITemporalTable)

           INPUT
            Field               : IField*'''
        return super(ITemporalObservationsTable2, self).AddField(Field)
    def DeleteField(self, Field):
        '''Method ITemporalTable.DeleteField (from ITemporalTable)

           INPUT
            Field               : IField*'''
        return super(ITemporalObservationsTable2, self).DeleteField(Field)
    def CreateRow(self):
        '''Method ITemporalTable.CreateRow (from ITemporalTable)

           OUTPUT
            Row                 : IRow**'''
        return super(ITemporalObservationsTable2, self).CreateRow()
    def GetRow(self, OID):
        '''Method ITemporalTable.GetRow (from ITemporalTable)

           INPUT
            OID                 : long

           OUTPUT
            Row                 : IRow**'''
        return super(ITemporalObservationsTable2, self).GetRow(OID)
    def CreateRowBuffer(self):
        '''Method ITemporalTable.CreateRowBuffer (from ITemporalTable)

           OUTPUT
            Buffer              : IRowBuffer**'''
        return super(ITemporalObservationsTable2, self).CreateRowBuffer()
    def RowCount(self, QueryFilter):
        '''Method ITemporalTable.RowCount (from ITemporalTable)

           INPUT
            QueryFilter         : IQueryFilter*

           OUTPUT
            NumRows             : long*'''
        return super(ITemporalObservationsTable2, self).RowCount(QueryFilter)
    def Search(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Search (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalObservationsTable2, self).Search(QueryFilter, Recycling)
    def Update(self, QueryFilter, Recycling):
        '''Method ITemporalTable.Update (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalObservationsTable2, self).Update(QueryFilter, Recycling)
    def Insert(self, useBuffering):
        '''Method ITemporalTable.Insert (from ITemporalTable)

           INPUT
            useBuffering        : VARIANT_BOOL

           OUTPUT
            Cursor              : ICursor**'''
        return super(ITemporalObservationsTable2, self).Insert(useBuffering)
    def Select(self, QueryFilter, selType, selOption, selectionContainer):
        '''Method ITemporalTable.Select (from ITemporalTable)

           INPUTS
            QueryFilter         : IQueryFilter*
            selType             : esriSelectionType
            selOption           : esriSelectionOption
            selectionContainer  : IWorkspace*

           OUTPUT
            ppSelectionSet      : ISelectionSet**'''
        return super(ITemporalObservationsTable2, self).Select(QueryFilter, selType, selOption, selectionContainer)
    def get_HasGeometry(self):
        '''Method ITemporalTable.get_HasGeometry (from ITemporalTable)

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(ITemporalObservationsTable2, self).get_HasGeometry()
    def get_GeometryColumnName(self):
        '''Method ITemporalTable.get_GeometryColumnName (from ITemporalTable)

           OUTPUT
            pbstrColumnName     : BSTR*'''
        return super(ITemporalObservationsTable2, self).get_GeometryColumnName()
    def put_GeometryColumnName(self, pbstrColumnName):
        '''Method ITemporalTable.put_GeometryColumnName (from ITemporalTable)

           INPUT
            pbstrColumnName     : BSTR'''
        return super(ITemporalObservationsTable2, self).put_GeometryColumnName(pbstrColumnName)
    AutoPurge = property(get_AutoPurge, put_AutoPurge, None)
    Fields = property(get_Fields, None, None)
    GeometryColumnName = property(get_GeometryColumnName, put_GeometryColumnName, None)
    HasGeometry = property(get_HasGeometry, None, None)
    Persistant = property(get_Persistant, put_Persistant, None)
    PurgePercentage = property(get_PurgePercentage, put_PurgePercentage, None)
    PurgeRule = property(get_PurgeRule, put_PurgeRule, None)
    TemporalColumnName = property(get_TemporalColumnName, put_TemporalColumnName, None)
    Threshold = property(get_Threshold, put_Threshold, None)
    TrackingColumnIndex = property(None, put_TrackingColumnIndex, None)

class IExcludedEventIDs(_esriGeoDatabaseExtensions.IExcludedEventIDs):
    _IID = uuid.UUID('2eb7644e-63dd-4a25-9ef9-b794ec6bf691')

    def __init__(self, *args, **kw):
        super(IExcludedEventIDs, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ExcludedTrackingEventIDs(self):
        '''Method IExcludedEventIDs.get_ExcludedTrackingEventIDs

           OUTPUT
            pVal                : IStringArray**'''
        return super(IExcludedEventIDs, self).get_ExcludedTrackingEventIDs()
    def put_ExcludedTrackingEventIDs(self, pVal):
        '''Method IExcludedEventIDs.put_ExcludedTrackingEventIDs

           INPUT
            pVal                : IStringArray*'''
        return super(IExcludedEventIDs, self).put_ExcludedTrackingEventIDs(pVal)
    ExcludedTrackingEventIDs = property(get_ExcludedTrackingEventIDs, put_ExcludedTrackingEventIDs, None)

class ITemporalQueryFilter(_esriGeoDatabaseExtensions.ITemporalQueryFilter):
    _IID = uuid.UUID('d0cee203-56da-11d5-ae49-00104ba2abcc')

    def __init__(self, *args, **kw):
        super(ITemporalQueryFilter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TemporalOrder(self):
        '''Method ITemporalQueryFilter.get_TemporalOrder

           OUTPUT
            pVal                : enumTemporalOrder*'''
        return super(ITemporalQueryFilter, self).get_TemporalOrder()
    def put_TemporalOrder(self, pVal):
        '''Method ITemporalQueryFilter.put_TemporalOrder

           INPUT
            pVal                : enumTemporalOrder'''
        return super(ITemporalQueryFilter, self).put_TemporalOrder(pVal)
    def get_TemporalRelationship(self):
        '''Method ITemporalQueryFilter.get_TemporalRelationship

           OUTPUT
            pVal                : enumTemporalRelation*'''
        return super(ITemporalQueryFilter, self).get_TemporalRelationship()
    def put_TemporalRelationship(self, pVal):
        '''Method ITemporalQueryFilter.put_TemporalRelationship

           INPUT
            pVal                : enumTemporalRelation'''
        return super(ITemporalQueryFilter, self).put_TemporalRelationship(pVal)
    def get_StartingDate(self):
        '''Method ITemporalQueryFilter.get_StartingDate

           OUTPUT
            pVal                : VARIANT*'''
        return super(ITemporalQueryFilter, self).get_StartingDate()
    def put_StartingDate(self, pVal):
        '''Method ITemporalQueryFilter.put_StartingDate

           INPUT
            pVal                : VARIANT'''
        return super(ITemporalQueryFilter, self).put_StartingDate(pVal)
    def get_EndingDate(self):
        '''Method ITemporalQueryFilter.get_EndingDate

           OUTPUT
            pVal                : VARIANT*'''
        return super(ITemporalQueryFilter, self).get_EndingDate()
    def put_EndingDate(self, pVal):
        '''Method ITemporalQueryFilter.put_EndingDate

           INPUT
            pVal                : VARIANT'''
        return super(ITemporalQueryFilter, self).put_EndingDate(pVal)
    def get_TemporalConversion(self):
        '''Method ITemporalQueryFilter.get_TemporalConversion

           OUTPUT
            pVal                : enumTemporalConversion*'''
        return super(ITemporalQueryFilter, self).get_TemporalConversion()
    def put_TemporalConversion(self, pVal):
        '''Method ITemporalQueryFilter.put_TemporalConversion

           INPUT
            pVal                : enumTemporalConversion'''
        return super(ITemporalQueryFilter, self).put_TemporalConversion(pVal)
    def get_RelativeTimeOperator(self):
        '''Method ITemporalQueryFilter.get_RelativeTimeOperator

           OUTPUT
            pVal                : ITemporalOperator**'''
        return super(ITemporalQueryFilter, self).get_RelativeTimeOperator()
    def put_RelativeTimeOperator(self, pVal):
        '''Method ITemporalQueryFilter.put_RelativeTimeOperator

           INPUT
            pVal                : ITemporalOperator*'''
        return super(ITemporalQueryFilter, self).put_RelativeTimeOperator(pVal)
    EndingDate = property(get_EndingDate, put_EndingDate, None)
    RelativeTimeOperator = property(get_RelativeTimeOperator, put_RelativeTimeOperator, None)
    StartingDate = property(get_StartingDate, put_StartingDate, None)
    TemporalConversion = property(get_TemporalConversion, put_TemporalConversion, None)
    TemporalOrder = property(get_TemporalOrder, put_TemporalOrder, None)
    TemporalRelationship = property(get_TemporalRelationship, put_TemporalRelationship, None)

class ITemporalQueryFilter2(_esriGeoDatabaseExtensions.ITemporalQueryFilter2):
    _IID = uuid.UUID('6d3465e9-f6f4-43d6-bba9-87eee56c146e')

    def __init__(self, *args, **kw):
        super(ITemporalQueryFilter2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TimeReference(self):
        '''Method ITemporalQueryFilter2.get_TimeReference

           OUTPUT
            TimeReference       : ITimeReference**'''
        return super(ITemporalQueryFilter2, self).get_TimeReference()
    def putref_TimeReference(self, TimeReference):
        '''Method ITemporalQueryFilter2.putref_TimeReference

           INPUT
            TimeReference       : ITimeReference*'''
        return super(ITemporalQueryFilter2, self).putref_TimeReference(TimeReference)
    def get_TemporalOrder(self):
        '''Method ITemporalQueryFilter.get_TemporalOrder (from ITemporalQueryFilter)

           OUTPUT
            pVal                : enumTemporalOrder*'''
        return super(ITemporalQueryFilter2, self).get_TemporalOrder()
    def put_TemporalOrder(self, pVal):
        '''Method ITemporalQueryFilter.put_TemporalOrder (from ITemporalQueryFilter)

           INPUT
            pVal                : enumTemporalOrder'''
        return super(ITemporalQueryFilter2, self).put_TemporalOrder(pVal)
    def get_TemporalRelationship(self):
        '''Method ITemporalQueryFilter.get_TemporalRelationship (from ITemporalQueryFilter)

           OUTPUT
            pVal                : enumTemporalRelation*'''
        return super(ITemporalQueryFilter2, self).get_TemporalRelationship()
    def put_TemporalRelationship(self, pVal):
        '''Method ITemporalQueryFilter.put_TemporalRelationship (from ITemporalQueryFilter)

           INPUT
            pVal                : enumTemporalRelation'''
        return super(ITemporalQueryFilter2, self).put_TemporalRelationship(pVal)
    def get_StartingDate(self):
        '''Method ITemporalQueryFilter.get_StartingDate (from ITemporalQueryFilter)

           OUTPUT
            pVal                : VARIANT*'''
        return super(ITemporalQueryFilter2, self).get_StartingDate()
    def put_StartingDate(self, pVal):
        '''Method ITemporalQueryFilter.put_StartingDate (from ITemporalQueryFilter)

           INPUT
            pVal                : VARIANT'''
        return super(ITemporalQueryFilter2, self).put_StartingDate(pVal)
    def get_EndingDate(self):
        '''Method ITemporalQueryFilter.get_EndingDate (from ITemporalQueryFilter)

           OUTPUT
            pVal                : VARIANT*'''
        return super(ITemporalQueryFilter2, self).get_EndingDate()
    def put_EndingDate(self, pVal):
        '''Method ITemporalQueryFilter.put_EndingDate (from ITemporalQueryFilter)

           INPUT
            pVal                : VARIANT'''
        return super(ITemporalQueryFilter2, self).put_EndingDate(pVal)
    def get_TemporalConversion(self):
        '''Method ITemporalQueryFilter.get_TemporalConversion (from ITemporalQueryFilter)

           OUTPUT
            pVal                : enumTemporalConversion*'''
        return super(ITemporalQueryFilter2, self).get_TemporalConversion()
    def put_TemporalConversion(self, pVal):
        '''Method ITemporalQueryFilter.put_TemporalConversion (from ITemporalQueryFilter)

           INPUT
            pVal                : enumTemporalConversion'''
        return super(ITemporalQueryFilter2, self).put_TemporalConversion(pVal)
    def get_RelativeTimeOperator(self):
        '''Method ITemporalQueryFilter.get_RelativeTimeOperator (from ITemporalQueryFilter)

           OUTPUT
            pVal                : ITemporalOperator**'''
        return super(ITemporalQueryFilter2, self).get_RelativeTimeOperator()
    def put_RelativeTimeOperator(self, pVal):
        '''Method ITemporalQueryFilter.put_RelativeTimeOperator (from ITemporalQueryFilter)

           INPUT
            pVal                : ITemporalOperator*'''
        return super(ITemporalQueryFilter2, self).put_RelativeTimeOperator(pVal)
    EndingDate = property(get_EndingDate, put_EndingDate, None)
    RelativeTimeOperator = property(get_RelativeTimeOperator, put_RelativeTimeOperator, None)
    StartingDate = property(get_StartingDate, put_StartingDate, None)
    TemporalConversion = property(get_TemporalConversion, put_TemporalConversion, None)
    TemporalOrder = property(get_TemporalOrder, put_TemporalOrder, None)
    TemporalRelationship = property(get_TemporalRelationship, put_TemporalRelationship, None)
    TimeReference = property(get_TimeReference, putref_TimeReference, None)

class IListener(_esriGeoDatabaseExtensions.IListener):
    _IID = uuid.UUID('d890e524-dab5-11d5-b811-00010265adc5')
    def AddData(self, piFeatureClass, dXMin, dYMin, dXMax, dYMax):
        '''Method IListener.AddData

           INPUTS
            piFeatureClass      : IFeatureClass*
            dXMin               : double
            dYMin               : double
            dXMax               : double
            dYMax               : double'''
        return super(IListener, self).AddData(piFeatureClass, dXMin, dYMin, dXMax, dYMax)
    def RemoveData(self, piFeatureClass, dXMin, dYMin, dXMax, dYMax):
        '''Method IListener.RemoveData

           INPUTS
            piFeatureClass      : IFeatureClass*
            dXMin               : double
            dYMin               : double
            dXMax               : double
            dYMax               : double'''
        return super(IListener, self).RemoveData(piFeatureClass, dXMin, dYMin, dXMax, dYMax)

class ITemporalFeature(_esriGeoDatabaseExtensions.ITemporalFeature):
    _IID = uuid.UUID('a677ab62-2fb8-11d5-b7e2-00010265adc5')

    def __init__(self, *args, **kw):
        super(ITemporalFeature, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TemporalFeatureType(self):
        '''Method ITemporalFeature.get_TemporalFeatureType

           OUTPUT
            pVal                : enumTemporalFeatureType*'''
        return super(ITemporalFeature, self).get_TemporalFeatureType()
    def get_ShapeCopy(self):
        '''Method IFeature.get_ShapeCopy (from IFeature)

           OUTPUT
            Shape               : IGeometry**'''
        return super(ITemporalFeature, self).get_ShapeCopy()
    def get_Shape(self):
        '''Method IFeature.get_Shape (from IFeature)

           OUTPUT
            Shape               : IGeometry**'''
        return super(ITemporalFeature, self).get_Shape()
    def putref_Shape(self, Shape):
        '''Method IFeature.putref_Shape (from IFeature)

           INPUT
            Shape               : IGeometry*'''
        return super(ITemporalFeature, self).putref_Shape(Shape)
    def get_Extent(self):
        '''Method IFeature.get_Extent (from IFeature)

           OUTPUT
            Extent              : IEnvelope**'''
        return super(ITemporalFeature, self).get_Extent()
    def get_FeatureType(self):
        '''Method IFeature.get_FeatureType (from IFeature)

           OUTPUT
            Type                : esriFeatureType*'''
        return super(ITemporalFeature, self).get_FeatureType()
    def get_Class(self):
        '''Method IObject.get_Class (from IObject)

           OUTPUT
            Table               : IObjectClass**'''
        return super(ITemporalFeature, self).get_Class()
    def get_HasOID(self):
        '''Method IRow.get_HasOID (from IRow)

           OUTPUT
            HasOID              : VARIANT_BOOL*'''
        return super(ITemporalFeature, self).get_HasOID()
    def get_OID(self):
        '''Method IRow.get_OID (from IRow)

           OUTPUT
            OID                 : long*'''
        return super(ITemporalFeature, self).get_OID()
    def get_Table(self):
        '''Method IRow.get_Table (from IRow)

           OUTPUT
            Table               : ITable**'''
        return super(ITemporalFeature, self).get_Table()
    def Store(self):
        '''Method IRow.Store (from IRow)'''
        return super(ITemporalFeature, self).Store()
    def Delete(self):
        '''Method IRow.Delete (from IRow)'''
        return super(ITemporalFeature, self).Delete()
    def get_Value(self, Index):
        '''Method IRowBuffer.get_Value (from IRowBuffer)

           INPUT
            Index               : long

           OUTPUT
            Value               : VARIANT*'''
        return super(ITemporalFeature, self).get_Value(Index)
    def put_Value(self, Index, Value):
        '''Method IRowBuffer.put_Value (from IRowBuffer)

           INPUTS
            Index               : long
            Value               : VARIANT'''
        return super(ITemporalFeature, self).put_Value(Index, Value)
    def get_Fields(self):
        '''Method IRowBuffer.get_Fields (from IRowBuffer)

           OUTPUT
            Fields              : IFields**'''
        return super(ITemporalFeature, self).get_Fields()
    Class = property(get_Class, None, None)
    Extent = property(get_Extent, None, None)
    FeatureType = property(get_FeatureType, None, None)
    Fields = property(get_Fields, None, None)
    HasOID = property(get_HasOID, None, None)
    OID = property(get_OID, None, None)
    Shape = property(get_Shape, putref_Shape, None)
    ShapeCopy = property(get_ShapeCopy, None, None)
    Table = property(get_Table, None, None)
    TemporalFeatureType = property(get_TemporalFeatureType, None, None)
    Value = property(None, put_Value, None)
    Value = IndexProperty(get_Value, None)

class IAMSDatasetName(_esriGeoDatabaseExtensions.IAMSDatasetName):
    _IID = uuid.UUID('a677ab64-2fb8-11d5-b7e2-00010265adc5')

    def __init__(self, *args, **kw):
        super(IAMSDatasetName, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Visible(self):
        '''Method IAMSDatasetName.get_Visible

           OUTPUT
            pVal                : VARIANT_BOOL*'''
        return super(IAMSDatasetName, self).get_Visible()
    def put_Visible(self, pVal):
        '''Method IAMSDatasetName.put_Visible

           INPUT
            pVal                : VARIANT_BOOL'''
        return super(IAMSDatasetName, self).put_Visible(pVal)
    def get_TemporalColumnName(self):
        '''Method IAMSDatasetName.get_TemporalColumnName

           OUTPUT
            pVal                : BSTR*'''
        return super(IAMSDatasetName, self).get_TemporalColumnName()
    def get_TrackingService(self):
        '''Method IAMSDatasetName.get_TrackingService

           OUTPUT
            pVal                : ITrackingServiceDef**'''
        return super(IAMSDatasetName, self).get_TrackingService()
    def putref_TrackingService(self, pVal):
        '''Method IAMSDatasetName.putref_TrackingService

           INPUT
            pVal                : ITrackingServiceDef*'''
        return super(IAMSDatasetName, self).putref_TrackingService(pVal)
    def get_ShapeType(self):
        '''Method IAMSDatasetName.get_ShapeType

           OUTPUT
            Type                : esriGeometryType*'''
        return super(IAMSDatasetName, self).get_ShapeType()
    def put_ShapeType(self, Type):
        '''Method IAMSDatasetName.put_ShapeType

           INPUT
            Type                : esriGeometryType'''
        return super(IAMSDatasetName, self).put_ShapeType(Type)
    def get_FeatureDatasetName(self):
        '''Method IAMSDatasetName.get_FeatureDatasetName

           OUTPUT
            FeatureDatasetName  : IDatasetName**'''
        return super(IAMSDatasetName, self).get_FeatureDatasetName()
    def putref_FeatureDatasetName(self, FeatureDatasetName):
        '''Method IAMSDatasetName.putref_FeatureDatasetName

           INPUT
            FeatureDatasetName  : IDatasetName*'''
        return super(IAMSDatasetName, self).putref_FeatureDatasetName(FeatureDatasetName)
    def get_FeatureType(self):
        '''Method IAMSDatasetName.get_FeatureType

           OUTPUT
            Type                : esriFeatureType*'''
        return super(IAMSDatasetName, self).get_FeatureType()
    def put_FeatureType(self, Type):
        '''Method IAMSDatasetName.put_FeatureType

           INPUT
            Type                : esriFeatureType'''
        return super(IAMSDatasetName, self).put_FeatureType(Type)
    def get_ShapeFieldName(self):
        '''Method IAMSDatasetName.get_ShapeFieldName

           OUTPUT
            Name                : BSTR*'''
        return super(IAMSDatasetName, self).get_ShapeFieldName()
    def put_ShapeFieldName(self, Name):
        '''Method IAMSDatasetName.put_ShapeFieldName

           INPUT
            Name                : BSTR'''
        return super(IAMSDatasetName, self).put_ShapeFieldName(Name)
    def get_Name(self):
        '''Method IDatasetName.get_Name (from IDatasetName)

           OUTPUT
            Name                : BSTR*'''
        return super(IAMSDatasetName, self).get_Name()
    def put_Name(self, Name):
        '''Method IDatasetName.put_Name (from IDatasetName)

           INPUT
            Name                : BSTR'''
        return super(IAMSDatasetName, self).put_Name(Name)
    def get_Type(self):
        '''Method IDatasetName.get_Type (from IDatasetName)

           OUTPUT
            Type                : esriDatasetType*'''
        return super(IAMSDatasetName, self).get_Type()
    def get_Category(self):
        '''Method IDatasetName.get_Category (from IDatasetName)

           OUTPUT
            Category            : BSTR*'''
        return super(IAMSDatasetName, self).get_Category()
    def put_Category(self, Category):
        '''Method IDatasetName.put_Category (from IDatasetName)

           INPUT
            Category            : BSTR'''
        return super(IAMSDatasetName, self).put_Category(Category)
    def get_WorkspaceName(self):
        '''Method IDatasetName.get_WorkspaceName (from IDatasetName)

           OUTPUT
            WorkspaceName       : IWorkspaceName**'''
        return super(IAMSDatasetName, self).get_WorkspaceName()
    def putref_WorkspaceName(self, WorkspaceName):
        '''Method IDatasetName.putref_WorkspaceName (from IDatasetName)

           INPUT
            WorkspaceName       : IWorkspaceName*'''
        return super(IAMSDatasetName, self).putref_WorkspaceName(WorkspaceName)
    def get_SubsetNames(self):
        '''Method IDatasetName.get_SubsetNames (from IDatasetName)

           OUTPUT
            SubsetNames         : IEnumDatasetName**'''
        return super(IAMSDatasetName, self).get_SubsetNames()
    Category = property(get_Category, put_Category, None)
    FeatureDatasetName = property(get_FeatureDatasetName, putref_FeatureDatasetName, None)
    FeatureType = property(get_FeatureType, put_FeatureType, None)
    Name = property(get_Name, put_Name, None)
    ShapeFieldName = property(get_ShapeFieldName, put_ShapeFieldName, None)
    ShapeType = property(get_ShapeType, put_ShapeType, None)
    SubsetNames = property(get_SubsetNames, None, None)
    TemporalColumnName = property(get_TemporalColumnName, None, None)
    TrackingService = property(get_TrackingService, putref_TrackingService, None)
    Type = property(get_Type, None, None)
    Visible = property(get_Visible, put_Visible, None)
    WorkspaceName = property(get_WorkspaceName, putref_WorkspaceName, None)

class ITemporalFeatureClassStatistics(_esriGeoDatabaseExtensions.ITemporalFeatureClassStatistics):
    _IID = uuid.UUID('5f007f4d-9fae-463c-a3d6-0aad83eb59a5')

    def __init__(self, *args, **kw):
        super(ITemporalFeatureClassStatistics, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TrackCount(self):
        '''Method ITemporalFeatureClassStatistics.get_TrackCount

           OUTPUT
            plTrackCount        : long*'''
        return super(ITemporalFeatureClassStatistics, self).get_TrackCount()
    def get_MessageRate(self):
        '''Method ITemporalFeatureClassStatistics.get_MessageRate

           OUTPUT
            pdMessageRate       : double*'''
        return super(ITemporalFeatureClassStatistics, self).get_MessageRate()
    def get_SampleSize(self):
        '''Method ITemporalFeatureClassStatistics.get_SampleSize

           OUTPUT
            plSampleSize        : long*'''
        return super(ITemporalFeatureClassStatistics, self).get_SampleSize()
    def put_SampleSize(self, plSampleSize):
        '''Method ITemporalFeatureClassStatistics.put_SampleSize

           INPUT
            plSampleSize        : long'''
        return super(ITemporalFeatureClassStatistics, self).put_SampleSize(plSampleSize)
    def get_TotalFeatureCount(self):
        '''Method ITemporalFeatureClassStatistics.get_TotalFeatureCount

           OUTPUT
            pvarTotalFeatureCount: VARIANT*'''
        return super(ITemporalFeatureClassStatistics, self).get_TotalFeatureCount()
    def ResetFeatureCount(self):
        '''Method ITemporalFeatureClassStatistics.ResetFeatureCount'''
        return super(ITemporalFeatureClassStatistics, self).ResetFeatureCount()
    def ResetMessageRate(self):
        '''Method ITemporalFeatureClassStatistics.ResetMessageRate'''
        return super(ITemporalFeatureClassStatistics, self).ResetMessageRate()
    MessageRate = property(get_MessageRate, None, None)
    SampleSize = property(get_SampleSize, put_SampleSize, None)
    TotalFeatureCount = property(get_TotalFeatureCount, None, None)
    TrackCount = property(get_TrackCount, None, None)

class ITemporalWorkspaceStatistics(_esriGeoDatabaseExtensions.ITemporalWorkspaceStatistics):
    _IID = uuid.UUID('052ac5b2-cdc1-479d-b69e-479e34a2c071')
    def get_AllTrackCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_AllTrackCounts

           OUTPUT
            ppiAllTrackCounts   : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_AllTrackCounts()
    def get_AllMessageRates(self):
        '''Method ITemporalWorkspaceStatistics.get_AllMessageRates

           OUTPUT
            ppiAllMessageRates  : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_AllMessageRates()
    def get_AllSampleSizes(self):
        '''Method ITemporalWorkspaceStatistics.get_AllSampleSizes

           OUTPUT
            ppiAllSampleSizes   : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_AllSampleSizes()
    def get_AllTotalFeatureCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_AllTotalFeatureCounts

           OUTPUT
            ppiAllTotalFeatureCounts: IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_AllTotalFeatureCounts()
    def get_ConnectionStatus(self):
        '''Method ITemporalWorkspaceStatistics.get_ConnectionStatus

           OUTPUT
            ppiConnectionStatus : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_ConnectionStatus()
    def get_ReceivedMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_ReceivedMessageCounts

           OUTPUT
            ppiReceivedMsgCounts: IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_ReceivedMessageCounts()
    def get_PulledMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_PulledMessageCounts

           OUTPUT
            ppiPulledMsgCounts  : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_PulledMessageCounts()
    def get_DiscardedMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_DiscardedMessageCounts

           OUTPUT
            ppiDiscardedMsgCounts: IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_DiscardedMessageCounts()
    def get_CurrentDiscardedMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_CurrentDiscardedMessageCounts

           OUTPUT
            ppiCurDiscardedMsgCounts: IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_CurrentDiscardedMessageCounts()
    def get_QueuedMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_QueuedMessageCounts

           OUTPUT
            ppiQueuedMsgCounts  : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics, self).get_QueuedMessageCounts()
    def ResetAllFeatureCounts(self):
        '''Method ITemporalWorkspaceStatistics.ResetAllFeatureCounts'''
        return super(ITemporalWorkspaceStatistics, self).ResetAllFeatureCounts()
    def ResetAllMessageRates(self):
        '''Method ITemporalWorkspaceStatistics.ResetAllMessageRates'''
        return super(ITemporalWorkspaceStatistics, self).ResetAllMessageRates()
    def SetAllSampleSizes(self, lSampleSize):
        '''Method ITemporalWorkspaceStatistics.SetAllSampleSizes

           INPUT
            lSampleSize         : long'''
        return super(ITemporalWorkspaceStatistics, self).SetAllSampleSizes(lSampleSize)
    AllMessageRates = property(get_AllMessageRates, None, None)
    AllSampleSizes = property(get_AllSampleSizes, None, None)
    AllTotalFeatureCounts = property(get_AllTotalFeatureCounts, None, None)
    AllTrackCounts = property(get_AllTrackCounts, None, None)
    ConnectionStatus = property(get_ConnectionStatus, None, None)
    CurrentDiscardedMessageCounts = property(get_CurrentDiscardedMessageCounts, None, None)
    DiscardedMessageCounts = property(get_DiscardedMessageCounts, None, None)
    PulledMessageCounts = property(get_PulledMessageCounts, None, None)
    QueuedMessageCounts = property(get_QueuedMessageCounts, None, None)
    ReceivedMessageCounts = property(get_ReceivedMessageCounts, None, None)

class ITemporalWorkspaceStatistics2(_esriGeoDatabaseExtensions.ITemporalWorkspaceStatistics2):
    _IID = uuid.UUID('f5677ccf-e3d7-4b9a-8803-670895aa262f')
    def get_ConnectionTime(self):
        '''Method ITemporalWorkspaceStatistics2.get_ConnectionTime

           OUTPUT
            ConnectionTime      : ITime**'''
        return super(ITemporalWorkspaceStatistics2, self).get_ConnectionTime()
    def get_Subscribed(self, serviceName):
        '''Method ITemporalWorkspaceStatistics2.get_Subscribed

           INPUT
            serviceName         : BSTR

           OUTPUT
            Subscribed          : VARIANT_BOOL*'''
        return super(ITemporalWorkspaceStatistics2, self).get_Subscribed(serviceName)
    def get_SubscriptionTime(self, serviceName):
        '''Method ITemporalWorkspaceStatistics2.get_SubscriptionTime

           INPUT
            serviceName         : BSTR

           OUTPUT
            SubscriptionTime    : ITime**'''
        return super(ITemporalWorkspaceStatistics2, self).get_SubscriptionTime(serviceName)
    def get_AllTrackCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_AllTrackCounts (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiAllTrackCounts   : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_AllTrackCounts()
    def get_AllMessageRates(self):
        '''Method ITemporalWorkspaceStatistics.get_AllMessageRates (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiAllMessageRates  : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_AllMessageRates()
    def get_AllSampleSizes(self):
        '''Method ITemporalWorkspaceStatistics.get_AllSampleSizes (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiAllSampleSizes   : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_AllSampleSizes()
    def get_AllTotalFeatureCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_AllTotalFeatureCounts (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiAllTotalFeatureCounts: IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_AllTotalFeatureCounts()
    def get_ConnectionStatus(self):
        '''Method ITemporalWorkspaceStatistics.get_ConnectionStatus (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiConnectionStatus : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_ConnectionStatus()
    def get_ReceivedMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_ReceivedMessageCounts (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiReceivedMsgCounts: IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_ReceivedMessageCounts()
    def get_PulledMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_PulledMessageCounts (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiPulledMsgCounts  : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_PulledMessageCounts()
    def get_DiscardedMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_DiscardedMessageCounts (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiDiscardedMsgCounts: IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_DiscardedMessageCounts()
    def get_CurrentDiscardedMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_CurrentDiscardedMessageCounts (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiCurDiscardedMsgCounts: IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_CurrentDiscardedMessageCounts()
    def get_QueuedMessageCounts(self):
        '''Method ITemporalWorkspaceStatistics.get_QueuedMessageCounts (from ITemporalWorkspaceStatistics)

           OUTPUT
            ppiQueuedMsgCounts  : IPropertySet**'''
        return super(ITemporalWorkspaceStatistics2, self).get_QueuedMessageCounts()
    def ResetAllFeatureCounts(self):
        '''Method ITemporalWorkspaceStatistics.ResetAllFeatureCounts (from ITemporalWorkspaceStatistics)'''
        return super(ITemporalWorkspaceStatistics2, self).ResetAllFeatureCounts()
    def ResetAllMessageRates(self):
        '''Method ITemporalWorkspaceStatistics.ResetAllMessageRates (from ITemporalWorkspaceStatistics)'''
        return super(ITemporalWorkspaceStatistics2, self).ResetAllMessageRates()
    def SetAllSampleSizes(self, lSampleSize):
        '''Method ITemporalWorkspaceStatistics.SetAllSampleSizes (from ITemporalWorkspaceStatistics)

           INPUT
            lSampleSize         : long'''
        return super(ITemporalWorkspaceStatistics2, self).SetAllSampleSizes(lSampleSize)
    AllMessageRates = property(get_AllMessageRates, None, None)
    AllSampleSizes = property(get_AllSampleSizes, None, None)
    AllTotalFeatureCounts = property(get_AllTotalFeatureCounts, None, None)
    AllTrackCounts = property(get_AllTrackCounts, None, None)
    ConnectionStatus = property(get_ConnectionStatus, None, None)
    ConnectionTime = property(get_ConnectionTime, None, None)
    CurrentDiscardedMessageCounts = property(get_CurrentDiscardedMessageCounts, None, None)
    DiscardedMessageCounts = property(get_DiscardedMessageCounts, None, None)
    PulledMessageCounts = property(get_PulledMessageCounts, None, None)
    QueuedMessageCounts = property(get_QueuedMessageCounts, None, None)
    ReceivedMessageCounts = property(get_ReceivedMessageCounts, None, None)
    Subscribed = IndexProperty(get_Subscribed, None)
    SubscriptionTime = IndexProperty(get_SubscriptionTime, None)

class ILockedFeatureSearch(_esriGeoDatabaseExtensions.ILockedFeatureSearch):
    _IID = uuid.UUID('6fb36881-6399-4bd6-be3d-b07033a79114')
    def get_AllLockedFIDs(self):
        '''Method ILockedFeatureSearch.get_AllLockedFIDs

           OUTPUT
            ppiAllLockedFIDs    : IFIDSet**'''
        return super(ILockedFeatureSearch, self).get_AllLockedFIDs()
    def SearchAndLock(self, piQueryFilter, Recycling):
        '''Method ILockedFeatureSearch.SearchAndLock

           INPUTS
            piQueryFilter       : IQueryFilter*
            Recycling           : VARIANT_BOOL

           OUTPUT
            ppiCursor           : ICursor**'''
        return super(ILockedFeatureSearch, self).SearchAndLock(piQueryFilter, Recycling)
    def SelectAndLock(self, piQueryFilter, selType, selOption, piSelectionContainer):
        '''Method ILockedFeatureSearch.SelectAndLock

           INPUTS
            piQueryFilter       : IQueryFilter*
            selType             : esriSelectionType
            selOption           : esriSelectionOption
            piSelectionContainer: IWorkspace*

           OUTPUT
            ppiSelectionSet     : ISelectionSet**'''
        return super(ILockedFeatureSearch, self).SelectAndLock(piQueryFilter, selType, selOption, piSelectionContainer)
    def UnlockAllFeatures(self):
        '''Method ILockedFeatureSearch.UnlockAllFeatures'''
        return super(ILockedFeatureSearch, self).UnlockAllFeatures()
    AllLockedFIDs = property(get_AllLockedFIDs, None, None)

class ITxWorkspaceEditor(_esriGeoDatabaseExtensions.ITxWorkspaceEditor):
    _IID = uuid.UUID('a1ff9810-87a9-11d7-b87a-00010265adc5')

    def __init__(self, *args, **kw):
        super(ITxWorkspaceEditor, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ConnectionProperties(self, ppiConnectionProperties):
        '''Method ITxWorkspaceEditor.put_ConnectionProperties

           INPUT
            ppiConnectionProperties: IPropertySet*'''
        return super(ITxWorkspaceEditor, self).put_ConnectionProperties(ppiConnectionProperties)
    def get_ConnectionProperties(self):
        '''Method ITxWorkspaceEditor.get_ConnectionProperties

           OUTPUT
            ppiConnectionProperties: IPropertySet**'''
        return super(ITxWorkspaceEditor, self).get_ConnectionProperties()
    def Invoke(self, hParentWnd):
        '''Method ITxWorkspaceEditor.Invoke

           INPUT
            hParentWnd          : OLE_HANDLE'''
        return super(ITxWorkspaceEditor, self).Invoke(hParentWnd)
    ConnectionProperties = property(get_ConnectionProperties, put_ConnectionProperties, None)

class ITemporalRecordSet(_esriGeoDatabaseExtensions.ITemporalRecordSet):
    _IID = uuid.UUID('78c74302-17cf-11d5-b7cf-00010265adc5')

    def __init__(self, *args, **kw):
        super(ITemporalRecordSet, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TemporalColumnName(self):
        '''Method ITemporalRecordSet.get_TemporalColumnName

           OUTPUT
            Name                : BSTR*'''
        return super(ITemporalRecordSet, self).get_TemporalColumnName()
    def put_TemporalColumnName(self, Name):
        '''Method ITemporalRecordSet.put_TemporalColumnName

           INPUT
            Name                : BSTR'''
        return super(ITemporalRecordSet, self).put_TemporalColumnName(Name)
    def get_FeatureClass(self):
        '''Method ITemporalRecordSet.get_FeatureClass

           OUTPUT
            FeatureClass        : IFeatureClass**'''
        return super(ITemporalRecordSet, self).get_FeatureClass()
    def putref_FeatureClass(self, FeatureClass):
        '''Method ITemporalRecordSet.putref_FeatureClass

           INPUT
            FeatureClass        : IFeatureClass*'''
        return super(ITemporalRecordSet, self).putref_FeatureClass(FeatureClass)
    def IndexFeatureClass(self, cacheStartingTime, cacheEndingTime, selSet, QueryFilter, localeLanguageID, dateFormat, timeFormat, amDesignator, pmDesignator):
        '''Method ITemporalRecordSet.IndexFeatureClass

           INPUTS
            cacheStartingTime   : VARIANT
            cacheEndingTime     : VARIANT
            selSet              : ISelectionSet*
            QueryFilter         : IQueryFilter*
            localeLanguageID    : long
            dateFormat          : BSTR
            timeFormat          : BSTR
            amDesignator        : BSTR
            pmDesignator        : BSTR'''
        return super(ITemporalRecordSet, self).IndexFeatureClass(cacheStartingTime, cacheEndingTime, selSet, QueryFilter, localeLanguageID, dateFormat, timeFormat, amDesignator, pmDesignator)
    def get_Count(self):
        '''Method ITemporalRecordSet.get_Count

           OUTPUT
            Count               : long*'''
        return super(ITemporalRecordSet, self).get_Count()
    def Search(self, QueryFilter, Recycling, forDrawing):
        '''Method ITemporalRecordSet.Search

           INPUTS
            QueryFilter         : IQueryFilter*
            Recycling           : VARIANT_BOOL
            forDrawing          : VARIANT_BOOL

           OUTPUT
            featureCursor       : IFeatureCursor**'''
        return super(ITemporalRecordSet, self).Search(QueryFilter, Recycling, forDrawing)
    def get_CacheFeatures(self):
        '''Method ITemporalRecordSet.get_CacheFeatures

           OUTPUT
            cacheTheFeatures    : VARIANT_BOOL*'''
        return super(ITemporalRecordSet, self).get_CacheFeatures()
    def put_CacheFeatures(self, cacheTheFeatures):
        '''Method ITemporalRecordSet.put_CacheFeatures

           INPUT
            cacheTheFeatures    : VARIANT_BOOL'''
        return super(ITemporalRecordSet, self).put_CacheFeatures(cacheTheFeatures)
    def get_TimeSeriesColumnName(self):
        '''Method ITemporalRecordSet.get_TimeSeriesColumnName

           OUTPUT
            Name                : BSTR*'''
        return super(ITemporalRecordSet, self).get_TimeSeriesColumnName()
    def put_TimeSeriesColumnName(self, Name):
        '''Method ITemporalRecordSet.put_TimeSeriesColumnName

           INPUT
            Name                : BSTR'''
        return super(ITemporalRecordSet, self).put_TimeSeriesColumnName(Name)
    def get_FeatureCacheWindow(self):
        '''Method ITemporalRecordSet.get_FeatureCacheWindow

           OUTPUT
            percent             : int*'''
        return super(ITemporalRecordSet, self).get_FeatureCacheWindow()
    def put_FeatureCacheWindow(self, percent):
        '''Method ITemporalRecordSet.put_FeatureCacheWindow

           INPUT
            percent             : int'''
        return super(ITemporalRecordSet, self).put_FeatureCacheWindow(percent)
    def get_OldestFeature(self):
        '''Method ITemporalRecordSet.get_OldestFeature

           OUTPUT
            feature             : VARIANT*'''
        return super(ITemporalRecordSet, self).get_OldestFeature()
    def get_MostCurrentFeature(self):
        '''Method ITemporalRecordSet.get_MostCurrentFeature

           OUTPUT
            feature             : VARIANT*'''
        return super(ITemporalRecordSet, self).get_MostCurrentFeature()
    def SelectByDate(self, StartDate, endDate):
        '''Method ITemporalRecordSet.SelectByDate

           INPUTS
            StartDate           : VARIANT
            endDate             : VARIANT

           OUTPUT
            selectionSet        : ISelectionSet**'''
        return super(ITemporalRecordSet, self).SelectByDate(StartDate, endDate)
    CacheFeatures = property(get_CacheFeatures, put_CacheFeatures, None)
    Count = property(get_Count, None, None)
    FeatureCacheWindow = property(get_FeatureCacheWindow, put_FeatureCacheWindow, None)
    FeatureClass = property(get_FeatureClass, putref_FeatureClass, None)
    MostCurrentFeature = property(get_MostCurrentFeature, None, None)
    OldestFeature = property(get_OldestFeature, None, None)
    TemporalColumnName = property(get_TemporalColumnName, put_TemporalColumnName, None)
    TimeSeriesColumnName = property(get_TimeSeriesColumnName, put_TimeSeriesColumnName, None)

class ITxFeatureClass(_esriGeoDatabaseExtensions.ITxFeatureClass):
    _IID = uuid.UUID('b7a65dde-9218-4e42-8c62-299ac695a66a')

    def __init__(self, *args, **kw):
        super(ITxFeatureClass, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_FeatureClass(self):
        '''Method ITxFeatureClass.get_FeatureClass

           OUTPUT
            FeatureClass        : IFeatureClass**'''
        return super(ITxFeatureClass, self).get_FeatureClass()
    def putref_FeatureClass(self, FeatureClass):
        '''Method ITxFeatureClass.putref_FeatureClass

           INPUT
            FeatureClass        : IFeatureClass*'''
        return super(ITxFeatureClass, self).putref_FeatureClass(FeatureClass)
    def get_CachingMode(self):
        '''Method ITxFeatureClass.get_CachingMode

           OUTPUT
            CachingMode         : esriTxFeatureClassCachingMode*'''
        return super(ITxFeatureClass, self).get_CachingMode()
    def put_CachingMode(self, CachingMode):
        '''Method ITxFeatureClass.put_CachingMode

           INPUT
            CachingMode         : esriTxFeatureClassCachingMode'''
        return super(ITxFeatureClass, self).put_CachingMode(CachingMode)
    def get_TrackIDFieldName(self):
        '''Method ITxFeatureClass.get_TrackIDFieldName

           OUTPUT
            Name                : BSTR*'''
        return super(ITxFeatureClass, self).get_TrackIDFieldName()
    def put_TrackIDFieldName(self, Name):
        '''Method ITxFeatureClass.put_TrackIDFieldName

           INPUT
            Name                : BSTR'''
        return super(ITxFeatureClass, self).put_TrackIDFieldName(Name)
    def get_StartTimeFieldName(self):
        '''Method ITxFeatureClass.get_StartTimeFieldName

           OUTPUT
            Name                : BSTR*'''
        return super(ITxFeatureClass, self).get_StartTimeFieldName()
    def put_StartTimeFieldName(self, Name):
        '''Method ITxFeatureClass.put_StartTimeFieldName

           INPUT
            Name                : BSTR'''
        return super(ITxFeatureClass, self).put_StartTimeFieldName(Name)
    def get_EndTimeFieldName(self):
        '''Method ITxFeatureClass.get_EndTimeFieldName

           OUTPUT
            Name                : BSTR*'''
        return super(ITxFeatureClass, self).get_EndTimeFieldName()
    def put_EndTimeFieldName(self, Name):
        '''Method ITxFeatureClass.put_EndTimeFieldName

           INPUT
            Name                : BSTR'''
        return super(ITxFeatureClass, self).put_EndTimeFieldName(Name)
    def get_TimeFieldFormat(self):
        '''Method ITxFeatureClass.get_TimeFieldFormat

           OUTPUT
            TimeFieldFormat     : BSTR*'''
        return super(ITxFeatureClass, self).get_TimeFieldFormat()
    def put_TimeFieldFormat(self, TimeFieldFormat):
        '''Method ITxFeatureClass.put_TimeFieldFormat

           INPUT
            TimeFieldFormat     : BSTR'''
        return super(ITxFeatureClass, self).put_TimeFieldFormat(TimeFieldFormat)
    def get_TimeFieldAmFormat(self):
        '''Method ITxFeatureClass.get_TimeFieldAmFormat

           OUTPUT
            amFormat            : BSTR*'''
        return super(ITxFeatureClass, self).get_TimeFieldAmFormat()
    def put_TimeFieldAmFormat(self, amFormat):
        '''Method ITxFeatureClass.put_TimeFieldAmFormat

           INPUT
            amFormat            : BSTR'''
        return super(ITxFeatureClass, self).put_TimeFieldAmFormat(amFormat)
    def get_TimeFieldPmFormat(self):
        '''Method ITxFeatureClass.get_TimeFieldPmFormat

           OUTPUT
            pmFormat            : BSTR*'''
        return super(ITxFeatureClass, self).get_TimeFieldPmFormat()
    def put_TimeFieldPmFormat(self, pmFormat):
        '''Method ITxFeatureClass.put_TimeFieldPmFormat

           INPUT
            pmFormat            : BSTR'''
        return super(ITxFeatureClass, self).put_TimeFieldPmFormat(pmFormat)
    def get_TimeFieldLocaleID(self):
        '''Method ITxFeatureClass.get_TimeFieldLocaleID

           OUTPUT
            localeID            : long*'''
        return super(ITxFeatureClass, self).get_TimeFieldLocaleID()
    def put_TimeFieldLocaleID(self, localeID):
        '''Method ITxFeatureClass.put_TimeFieldLocaleID

           INPUT
            localeID            : long'''
        return super(ITxFeatureClass, self).put_TimeFieldLocaleID(localeID)
    def IndexFeatureClass2(self, startingTime, endingTime, selSet, QueryFilter):
        '''Method ITxFeatureClass.IndexFeatureClass2

           INPUTS
            startingTime        : VARIANT
            endingTime          : VARIANT
            selSet              : ISelectionSet*
            QueryFilter         : IQueryFilter*'''
        return super(ITxFeatureClass, self).IndexFeatureClass2(startingTime, endingTime, selSet, QueryFilter)
    def RebuildIndex(self):
        '''Method ITxFeatureClass.RebuildIndex'''
        return super(ITxFeatureClass, self).RebuildIndex()
    CachingMode = property(get_CachingMode, put_CachingMode, None)
    EndTimeFieldName = property(get_EndTimeFieldName, put_EndTimeFieldName, None)
    FeatureClass = property(get_FeatureClass, putref_FeatureClass, None)
    StartTimeFieldName = property(get_StartTimeFieldName, put_StartTimeFieldName, None)
    TimeFieldAmFormat = property(get_TimeFieldAmFormat, put_TimeFieldAmFormat, None)
    TimeFieldFormat = property(get_TimeFieldFormat, put_TimeFieldFormat, None)
    TimeFieldLocaleID = property(get_TimeFieldLocaleID, put_TimeFieldLocaleID, None)
    TimeFieldPmFormat = property(get_TimeFieldPmFormat, put_TimeFieldPmFormat, None)
    TrackIDFieldName = property(get_TrackIDFieldName, put_TrackIDFieldName, None)

class ITxEnumTrackId(_esriGeoDatabaseExtensions.ITxEnumTrackId):
    _IID = uuid.UUID('057b4c30-5c61-4b6c-a24d-b02f98be418f')
    def get_FirstTrackId(self):
        '''Method ITxEnumTrackId.get_FirstTrackId

           OUTPUT
            trackId             : BSTR*'''
        return super(ITxEnumTrackId, self).get_FirstTrackId()
    def get_NextTrackId(self):
        '''Method ITxEnumTrackId.get_NextTrackId

           OUTPUT
            trackId             : BSTR*'''
        return super(ITxEnumTrackId, self).get_NextTrackId()
    def get_TrackIds(self):
        '''Method ITxEnumTrackId.get_TrackIds

           OUTPUT
            TrackIds            : SAFEARRAY**'''
        return super(ITxEnumTrackId, self).get_TrackIds()
    def get_TrackFeatures(self, trackId):
        '''Method ITxEnumTrackId.get_TrackFeatures

           INPUT
            trackId             : BSTR

           OUTPUT
            features            : ISelectionSet**'''
        return super(ITxEnumTrackId, self).get_TrackFeatures(trackId)
    def get_LastUpdateTime(self, trackId):
        '''Method ITxEnumTrackId.get_LastUpdateTime

           INPUT
            trackId             : BSTR

           OUTPUT
            LastUpdateTime      : ITime**'''
        return super(ITxEnumTrackId, self).get_LastUpdateTime(trackId)
    def QueryTrackTimeExtent(self, trackId):
        '''Method ITxEnumTrackId.QueryTrackTimeExtent

           INPUT
            trackId             : BSTR

           OUTPUTS
            startTime           : ITime**
            endTime             : ITime**'''
        return super(ITxEnumTrackId, self).QueryTrackTimeExtent(trackId)
    FirstTrackId = property(get_FirstTrackId, None, None)
    NextTrackId = property(get_NextTrackId, None, None)
    TrackIds = property(get_TrackIds, None, None)
    LastUpdateTime = IndexProperty(get_LastUpdateTime, None)
    TrackFeatures = IndexProperty(get_TrackFeatures, None)

class ITemporalCursor(_esriGeoDatabaseExtensions.ITemporalCursor):
    _IID = uuid.UUID('cc018a66-24fb-11d4-b34c-00104ba2abcc')
    def NextObject(self):
        '''Method ITemporalCursor.NextObject

           OUTPUTS
            ppiFeature          : IFeature**
            pvarTimeSeries      : VARIANT*
            phyTimeStamp        : __int64*
            plOID               : long*'''
        return super(ITemporalCursor, self).NextObject()
    def Reset(self):
        '''Method ITemporalCursor.Reset'''
        return super(ITemporalCursor, self).Reset()
    def FindField(self, Name):
        '''Method IFeatureCursor.FindField (from IFeatureCursor)

           INPUT
            Name                : BSTR

           OUTPUT
            FieldIndex          : long*'''
        return super(ITemporalCursor, self).FindField(Name)
    def get_Fields(self):
        '''Method IFeatureCursor.get_Fields (from IFeatureCursor)

           OUTPUT
            Fields              : IFields**'''
        return super(ITemporalCursor, self).get_Fields()
    def NextFeature(self):
        '''Method IFeatureCursor.NextFeature (from IFeatureCursor)

           OUTPUT
            Object              : IFeature**'''
        return super(ITemporalCursor, self).NextFeature()
    def UpdateFeature(self, Object):
        '''Method IFeatureCursor.UpdateFeature (from IFeatureCursor)

           INPUT
            Object              : IFeature*'''
        return super(ITemporalCursor, self).UpdateFeature(Object)
    def DeleteFeature(self):
        '''Method IFeatureCursor.DeleteFeature (from IFeatureCursor)'''
        return super(ITemporalCursor, self).DeleteFeature()
    def InsertFeature(self, buffer):
        '''Method IFeatureCursor.InsertFeature (from IFeatureCursor)

           INPUT
            buffer              : IFeatureBuffer*

           OUTPUT
            ID                  : VARIANT*'''
        return super(ITemporalCursor, self).InsertFeature(buffer)
    def Flush(self):
        '''Method IFeatureCursor.Flush (from IFeatureCursor)'''
        return super(ITemporalCursor, self).Flush()
    Fields = property(get_Fields, None, None)

class ITerrain(_esriGeoDatabaseExtensions.ITerrain):
    _IID = uuid.UUID('f657c7ed-fe73-493e-8cf7-845e20cb7d9b')
    def get_Name(self):
        '''Method ITerrain.get_Name

           OUTPUT
            pName               : BSTR*'''
        return super(ITerrain, self).get_Name()
    def get_ID(self):
        '''Method ITerrain.get_ID

           OUTPUT
            pID                 : long*'''
        return super(ITerrain, self).get_ID()
    def get_Size(self):
        '''Method ITerrain.get_Size

           OUTPUT
            pcPoints            : double*'''
        return super(ITerrain, self).get_Size()
    def get_IsValid(self):
        '''Method ITerrain.get_IsValid

           OUTPUT
            pbIsValid           : VARIANT_BOOL*'''
        return super(ITerrain, self).get_IsValid()
    def get_IsDirty(self):
        '''Method ITerrain.get_IsDirty

           OUTPUT
            pbIsDirty           : VARIANT_BOOL*'''
        return super(ITerrain, self).get_IsDirty()
    def get_SpatialReference(self):
        '''Method ITerrain.get_SpatialReference

           OUTPUT
            ppSpatialRef        : ISpatialReference**'''
        return super(ITerrain, self).get_SpatialReference()
    def get_Extent(self):
        '''Method ITerrain.get_Extent

           OUTPUT
            ppExtent            : IEnvelope**'''
        return super(ITerrain, self).get_Extent()
    def get_FeatureDataset(self):
        '''Method ITerrain.get_FeatureDataset

           OUTPUT
            ppDataset           : IFeatureDataset**'''
        return super(ITerrain, self).get_FeatureDataset()
    def get_DataSourceCount(self):
        '''Method ITerrain.get_DataSourceCount

           OUTPUT
            pcDataSources       : long*'''
        return super(ITerrain, self).get_DataSourceCount()
    def get_DataSource(self, index):
        '''Method ITerrain.get_DataSource

           INPUT
            index               : long

           OUTPUT
            ppDataSource        : ITerrainDataSource**'''
        return super(ITerrain, self).get_DataSource(index)
    def get_PyramidLevelCount(self):
        '''Method ITerrain.get_PyramidLevelCount

           OUTPUT
            pcPyramidLevels     : long*'''
        return super(ITerrain, self).get_PyramidLevelCount()
    def get_PyramidLevel(self, index):
        '''Method ITerrain.get_PyramidLevel

           INPUT
            index               : long

           OUTPUT
            ppPyramidLevel      : ITerrainPyramidLevel**'''
        return super(ITerrain, self).get_PyramidLevel(index)
    def get_TileSize(self):
        '''Method ITerrain.get_TileSize

           OUTPUT
            pSize               : double*'''
        return super(ITerrain, self).get_TileSize()
    def get_PyramidType(self):
        '''Method ITerrain.get_PyramidType

           OUTPUT
            pType               : esriTerrainPyramidType*'''
        return super(ITerrain, self).get_PyramidType()
    def get_MaxOverviewTerrainPoints(self):
        '''Method ITerrain.get_MaxOverviewTerrainPoints

           OUTPUT
            pcPoints            : long*'''
        return super(ITerrain, self).get_MaxOverviewTerrainPoints()
    def get_MaxPointsPerShape(self):
        '''Method ITerrain.get_MaxPointsPerShape

           OUTPUT
            pcPoints            : long*'''
        return super(ITerrain, self).get_MaxPointsPerShape()
    def QueryTileInfo(self):
        '''Method ITerrain.QueryTileInfo

           OUTPUTS
            pRowBegin           : long*
            pRowEnd             : long*
            pColBegin           : long*
            pColEnd             : long*
            pXMin               : double*
            pYMin               : double*
            pTileSize           : double*
            pRowCountDomain     : long*
            pColCountDomain     : long*'''
        return super(ITerrain, self).QueryTileInfo()
    def GetDirtyTiles(self):
        '''Method ITerrain.GetDirtyTiles

           OUTPUT
            ppTiles             : IEnumEnvelope**'''
        return super(ITerrain, self).GetDirtyTiles()
    def GetPointCount(self, pAOI, Resolution):
        '''Method ITerrain.GetPointCount

           INPUTS
            pAOI                : IEnvelope*
            Resolution          : double

           OUTPUT
            pcPoints            : double*'''
        return super(ITerrain, self).GetPointCount(pAOI, Resolution)
    def CreateDynamicSurface(self):
        '''Method ITerrain.CreateDynamicSurface

           OUTPUT
            ppDynamicSurface    : IDynamicSurface**'''
        return super(ITerrain, self).CreateDynamicSurface()
    def ExtractFromEmbeddedDataSource(self, index, pFeatureClass, pAOI, Resolution, pTrackCancel):
        '''Method ITerrain.ExtractFromEmbeddedDataSource

           INPUTS
            index               : long
            pFeatureClass       : IFeatureClass*
            pAOI                : IEnvelope*
            Resolution          : double
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrain, self).ExtractFromEmbeddedDataSource(index, pFeatureClass, pAOI, Resolution, pTrackCancel)
    DataSourceCount = property(get_DataSourceCount, None, None)
    Extent = property(get_Extent, None, None)
    FeatureDataset = property(get_FeatureDataset, None, None)
    ID = property(get_ID, None, None)
    IsDirty = property(get_IsDirty, None, None)
    IsValid = property(get_IsValid, None, None)
    MaxOverviewTerrainPoints = property(get_MaxOverviewTerrainPoints, None, None)
    MaxPointsPerShape = property(get_MaxPointsPerShape, None, None)
    Name = property(get_Name, None, None)
    PyramidLevelCount = property(get_PyramidLevelCount, None, None)
    PyramidType = property(get_PyramidType, None, None)
    Size = property(get_Size, None, None)
    SpatialReference = property(get_SpatialReference, None, None)
    TileSize = property(get_TileSize, None, None)
    DataSource = IndexProperty(get_DataSource, None)
    PyramidLevel = IndexProperty(get_PyramidLevel, None)

class IDynamicSurface(_esriGeoDatabaseExtensions.IDynamicSurface):
    _IID = uuid.UUID('36e5cbc7-14b3-4ea8-b19d-f084cb0911d9')

    def __init__(self, *args, **kw):
        super(IDynamicSurface, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_RasterBlockSize(self, pSize):
        '''Method IDynamicSurface.put_RasterBlockSize

           INPUT
            pSize               : long'''
        return super(IDynamicSurface, self).put_RasterBlockSize(pSize)
    def get_RasterBlockSize(self):
        '''Method IDynamicSurface.get_RasterBlockSize

           OUTPUT
            pSize               : long*'''
        return super(IDynamicSurface, self).get_RasterBlockSize()
    def get_Terrain(self):
        '''Method IDynamicSurface.get_Terrain

           OUTPUT
            ppTerrain           : ITerrain**'''
        return super(IDynamicSurface, self).get_Terrain()
    def GetTin(self, pAreaOfInterest, Resolution, bClipWithAOI, pTrackCancel):
        '''Method IDynamicSurface.GetTin

           INPUTS
            pAreaOfInterest     : IEnvelope*
            Resolution          : double
            bClipWithAOI        : VARIANT_BOOL
            pTrackCancel        : ITrackCancel*

           OUTPUT
            ppTin               : ITin**'''
        return super(IDynamicSurface, self).GetTin(pAreaOfInterest, Resolution, bClipWithAOI, pTrackCancel)
    def QueryRaster(self, pDataset, pAreaOfInterest, Resolution, Method, pTrackCancel):
        '''Method IDynamicSurface.QueryRaster

           INPUTS
            pDataset            : IRasterDataset*
            pAreaOfInterest     : IEnvelope*
            Resolution          : double
            Method              : esriSurfaceInterpolationType
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface, self).QueryRaster(pDataset, pAreaOfInterest, Resolution, Method, pTrackCancel)
    def QueryAsFeatureClass(self, pFeatureClass, pAreaOfInterest, Resolution, pTrackCancel):
        '''Method IDynamicSurface.QueryAsFeatureClass

           INPUTS
            pFeatureClass       : IFeatureClass*
            pAreaOfInterest     : IEnvelope*
            Resolution          : double
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface, self).QueryAsFeatureClass(pFeatureClass, pAreaOfInterest, Resolution, pTrackCancel)
    RasterBlockSize = property(get_RasterBlockSize, put_RasterBlockSize, None)
    Terrain = property(get_Terrain, None, None)

class ITerrain2(_esriGeoDatabaseExtensions.ITerrain2):
    _IID = uuid.UUID('5d6d7322-d2d5-4c16-a52d-0b1199efa98d')
    def GetEmbeddedDataSourceShapeFieldName(self):
        '''Method ITerrain2.GetEmbeddedDataSourceShapeFieldName

           OUTPUT
            pName               : BSTR*'''
        return super(ITerrain2, self).GetEmbeddedDataSourceShapeFieldName()
    def SearchFromEmbeddedDataSource(self, index, pAOI, Resolution, pSubFields):
        '''Method ITerrain2.SearchFromEmbeddedDataSource

           INPUTS
            index               : long
            pAOI                : IEnvelope*
            Resolution          : double
            pSubFields          : IStringArray*

           OUTPUTS
            ppCursor            : IFeatureCursor**
            ppFieldIndices      : ILongArray**'''
        return super(ITerrain2, self).SearchFromEmbeddedDataSource(index, pAOI, Resolution, pSubFields)
    def get_Name(self):
        '''Method ITerrain.get_Name (from ITerrain)

           OUTPUT
            pName               : BSTR*'''
        return super(ITerrain2, self).get_Name()
    def get_ID(self):
        '''Method ITerrain.get_ID (from ITerrain)

           OUTPUT
            pID                 : long*'''
        return super(ITerrain2, self).get_ID()
    def get_Size(self):
        '''Method ITerrain.get_Size (from ITerrain)

           OUTPUT
            pcPoints            : double*'''
        return super(ITerrain2, self).get_Size()
    def get_IsValid(self):
        '''Method ITerrain.get_IsValid (from ITerrain)

           OUTPUT
            pbIsValid           : VARIANT_BOOL*'''
        return super(ITerrain2, self).get_IsValid()
    def get_IsDirty(self):
        '''Method ITerrain.get_IsDirty (from ITerrain)

           OUTPUT
            pbIsDirty           : VARIANT_BOOL*'''
        return super(ITerrain2, self).get_IsDirty()
    def get_SpatialReference(self):
        '''Method ITerrain.get_SpatialReference (from ITerrain)

           OUTPUT
            ppSpatialRef        : ISpatialReference**'''
        return super(ITerrain2, self).get_SpatialReference()
    def get_Extent(self):
        '''Method ITerrain.get_Extent (from ITerrain)

           OUTPUT
            ppExtent            : IEnvelope**'''
        return super(ITerrain2, self).get_Extent()
    def get_FeatureDataset(self):
        '''Method ITerrain.get_FeatureDataset (from ITerrain)

           OUTPUT
            ppDataset           : IFeatureDataset**'''
        return super(ITerrain2, self).get_FeatureDataset()
    def get_DataSourceCount(self):
        '''Method ITerrain.get_DataSourceCount (from ITerrain)

           OUTPUT
            pcDataSources       : long*'''
        return super(ITerrain2, self).get_DataSourceCount()
    def get_DataSource(self, index):
        '''Method ITerrain.get_DataSource (from ITerrain)

           INPUT
            index               : long

           OUTPUT
            ppDataSource        : ITerrainDataSource**'''
        return super(ITerrain2, self).get_DataSource(index)
    def get_PyramidLevelCount(self):
        '''Method ITerrain.get_PyramidLevelCount (from ITerrain)

           OUTPUT
            pcPyramidLevels     : long*'''
        return super(ITerrain2, self).get_PyramidLevelCount()
    def get_PyramidLevel(self, index):
        '''Method ITerrain.get_PyramidLevel (from ITerrain)

           INPUT
            index               : long

           OUTPUT
            ppPyramidLevel      : ITerrainPyramidLevel**'''
        return super(ITerrain2, self).get_PyramidLevel(index)
    def get_TileSize(self):
        '''Method ITerrain.get_TileSize (from ITerrain)

           OUTPUT
            pSize               : double*'''
        return super(ITerrain2, self).get_TileSize()
    def get_PyramidType(self):
        '''Method ITerrain.get_PyramidType (from ITerrain)

           OUTPUT
            pType               : esriTerrainPyramidType*'''
        return super(ITerrain2, self).get_PyramidType()
    def get_MaxOverviewTerrainPoints(self):
        '''Method ITerrain.get_MaxOverviewTerrainPoints (from ITerrain)

           OUTPUT
            pcPoints            : long*'''
        return super(ITerrain2, self).get_MaxOverviewTerrainPoints()
    def get_MaxPointsPerShape(self):
        '''Method ITerrain.get_MaxPointsPerShape (from ITerrain)

           OUTPUT
            pcPoints            : long*'''
        return super(ITerrain2, self).get_MaxPointsPerShape()
    def QueryTileInfo(self):
        '''Method ITerrain.QueryTileInfo (from ITerrain)

           OUTPUTS
            pRowBegin           : long*
            pRowEnd             : long*
            pColBegin           : long*
            pColEnd             : long*
            pXMin               : double*
            pYMin               : double*
            pTileSize           : double*
            pRowCountDomain     : long*
            pColCountDomain     : long*'''
        return super(ITerrain2, self).QueryTileInfo()
    def GetDirtyTiles(self):
        '''Method ITerrain.GetDirtyTiles (from ITerrain)

           OUTPUT
            ppTiles             : IEnumEnvelope**'''
        return super(ITerrain2, self).GetDirtyTiles()
    def GetPointCount(self, pAOI, Resolution):
        '''Method ITerrain.GetPointCount (from ITerrain)

           INPUTS
            pAOI                : IEnvelope*
            Resolution          : double

           OUTPUT
            pcPoints            : double*'''
        return super(ITerrain2, self).GetPointCount(pAOI, Resolution)
    def CreateDynamicSurface(self):
        '''Method ITerrain.CreateDynamicSurface (from ITerrain)

           OUTPUT
            ppDynamicSurface    : IDynamicSurface**'''
        return super(ITerrain2, self).CreateDynamicSurface()
    def ExtractFromEmbeddedDataSource(self, index, pFeatureClass, pAOI, Resolution, pTrackCancel):
        '''Method ITerrain.ExtractFromEmbeddedDataSource (from ITerrain)

           INPUTS
            index               : long
            pFeatureClass       : IFeatureClass*
            pAOI                : IEnvelope*
            Resolution          : double
            pTrackCancel        : ITrackCancel*'''
        return super(ITerrain2, self).ExtractFromEmbeddedDataSource(index, pFeatureClass, pAOI, Resolution, pTrackCancel)
    DataSourceCount = property(get_DataSourceCount, None, None)
    Extent = property(get_Extent, None, None)
    FeatureDataset = property(get_FeatureDataset, None, None)
    ID = property(get_ID, None, None)
    IsDirty = property(get_IsDirty, None, None)
    IsValid = property(get_IsValid, None, None)
    MaxOverviewTerrainPoints = property(get_MaxOverviewTerrainPoints, None, None)
    MaxPointsPerShape = property(get_MaxPointsPerShape, None, None)
    Name = property(get_Name, None, None)
    PyramidLevelCount = property(get_PyramidLevelCount, None, None)
    PyramidType = property(get_PyramidType, None, None)
    Size = property(get_Size, None, None)
    SpatialReference = property(get_SpatialReference, None, None)
    TileSize = property(get_TileSize, None, None)
    DataSource = IndexProperty(get_DataSource, None)
    PyramidLevel = IndexProperty(get_PyramidLevel, None)

class IDynamicSurface2(_esriGeoDatabaseExtensions.IDynamicSurface2):
    _IID = uuid.UUID('d7de4992-54f7-4f46-8310-c9d991937c3c')

    def __init__(self, *args, **kw):
        super(IDynamicSurface2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_MinimizeResourceUsage(self, pbMinimize):
        '''Method IDynamicSurface2.put_MinimizeResourceUsage

           INPUT
            pbMinimize          : VARIANT_BOOL'''
        return super(IDynamicSurface2, self).put_MinimizeResourceUsage(pbMinimize)
    def get_MinimizeResourceUsage(self):
        '''Method IDynamicSurface2.get_MinimizeResourceUsage

           OUTPUT
            pbMinimize          : VARIANT_BOOL*'''
        return super(IDynamicSurface2, self).get_MinimizeResourceUsage()
    def put_RefineBoundaryMatching(self, pbRefine):
        '''Method IDynamicSurface2.put_RefineBoundaryMatching

           INPUT
            pbRefine            : VARIANT_BOOL'''
        return super(IDynamicSurface2, self).put_RefineBoundaryMatching(pbRefine)
    def get_RefineBoundaryMatching(self):
        '''Method IDynamicSurface2.get_RefineBoundaryMatching

           OUTPUT
            pbRefine            : VARIANT_BOOL*'''
        return super(IDynamicSurface2, self).get_RefineBoundaryMatching()
    def InterpolateShape(self, pInShape, Resolution, Type, pTrackCancel, pStepSize):
        '''Method IDynamicSurface2.InterpolateShape

           INPUTS
            pInShape            : IGeometry*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pTrackCancel        : ITrackCancel*
            pStepSize           : VARIANT*

           OUTPUT
            ppOutShape          : IGeometry**'''
        return super(IDynamicSurface2, self).InterpolateShape(pInShape, Resolution, Type, pTrackCancel, pStepSize)
    def InterpolateShapeVertices(self, pInShape, Resolution, Type, pTrackCancel):
        '''Method IDynamicSurface2.InterpolateShapeVertices

           INPUTS
            pInShape            : IGeometry*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pTrackCancel        : ITrackCancel*

           OUTPUT
            ppOutShape          : IGeometry**'''
        return super(IDynamicSurface2, self).InterpolateShapeVertices(pInShape, Resolution, Type, pTrackCancel)
    def InterpolateFeatureClass(self, pInFeatureClass, pFilter, Resolution, Type, pOutFeatureClass, pTrackCancel, pStepSize):
        '''Method IDynamicSurface2.InterpolateFeatureClass

           INPUTS
            pInFeatureClass     : IFeatureClass*
            pFilter             : IQueryFilter*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pOutFeatureClass    : IFeatureClass*
            pTrackCancel        : ITrackCancel*
            pStepSize           : VARIANT*'''
        return super(IDynamicSurface2, self).InterpolateFeatureClass(pInFeatureClass, pFilter, Resolution, Type, pOutFeatureClass, pTrackCancel, pStepSize)
    def InterpolateFeatureCursor(self, pCursor, Resolution, Type, pOutFeatureClass, pTrackCancel, pStepSize):
        '''Method IDynamicSurface2.InterpolateFeatureCursor

           INPUTS
            pCursor             : IFeatureCursor*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pOutFeatureClass    : IFeatureClass*
            pTrackCancel        : ITrackCancel*
            pStepSize           : VARIANT*'''
        return super(IDynamicSurface2, self).InterpolateFeatureCursor(pCursor, Resolution, Type, pOutFeatureClass, pTrackCancel, pStepSize)
    def InterpolateFeatureClassVertices(self, pInFeatureClass, pFilter, Resolution, Type, pOutFeatureClass, pTrackCancel):
        '''Method IDynamicSurface2.InterpolateFeatureClassVertices

           INPUTS
            pInFeatureClass     : IFeatureClass*
            pFilter             : IQueryFilter*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pOutFeatureClass    : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface2, self).InterpolateFeatureClassVertices(pInFeatureClass, pFilter, Resolution, Type, pOutFeatureClass, pTrackCancel)
    def InterpolateFeatureCursorVertices(self, pCursor, Resolution, Type, pOutFeatureClass, pTrackCancel):
        '''Method IDynamicSurface2.InterpolateFeatureCursorVertices

           INPUTS
            pCursor             : IFeatureCursor*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pOutFeatureClass    : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface2, self).InterpolateFeatureCursorVertices(pCursor, Resolution, Type, pOutFeatureClass, pTrackCancel)
    def get_CanDoCurvature(self):
        '''Method IDynamicSurface2.get_CanDoCurvature

           OUTPUT
            pbCanDo             : VARIANT_BOOL*'''
        return super(IDynamicSurface2, self).get_CanDoCurvature()
    def GetLineOfSight(self, pObserver, pTarget, Resolution, pTrackCancel, bApplyCurvature, bApplyRefraction, pRefractionFactor):
        '''Method IDynamicSurface2.GetLineOfSight

           INPUTS
            pObserver           : IPoint*
            pTarget             : IPoint*
            Resolution          : double
            pTrackCancel        : ITrackCancel*
            bApplyCurvature     : VARIANT_BOOL
            bApplyRefraction    : VARIANT_BOOL
            pRefractionFactor   : VARIANT*

           OUTPUTS
            ppObstruction       : IPoint**
            ppVisibleLines      : IPolyline**
            ppInvisibleLines    : IPolyline**
            pbIsVisible         : VARIANT_BOOL*'''
        return super(IDynamicSurface2, self).GetLineOfSight(pObserver, pTarget, Resolution, pTrackCancel, bApplyCurvature, bApplyRefraction, pRefractionFactor)
    def GetLineOfSightFeatureCursor(self, pCursor, Resolution, pTrackCancel, pOutputLines, pObstructionPoints, bApplyCurvature, bApplyRefraction, pRefractionFactor):
        '''Method IDynamicSurface2.GetLineOfSightFeatureCursor

           INPUTS
            pCursor             : IFeatureCursor*
            Resolution          : double
            pTrackCancel        : ITrackCancel*
            pOutputLines        : IFeatureClass*
            pObstructionPoints  : IFeatureClass*
            bApplyCurvature     : VARIANT_BOOL
            bApplyRefraction    : VARIANT_BOOL
            pRefractionFactor   : VARIANT*'''
        return super(IDynamicSurface2, self).GetLineOfSightFeatureCursor(pCursor, Resolution, pTrackCancel, pOutputLines, pObstructionPoints, bApplyCurvature, bApplyRefraction, pRefractionFactor)
    def GetTileBasedDataArea(self, pTrackCancel):
        '''Method IDynamicSurface2.GetTileBasedDataArea

           INPUT
            pTrackCancel        : ITrackCancel*

           OUTPUT
            ppDataArea          : IPolygon**'''
        return super(IDynamicSurface2, self).GetTileBasedDataArea(pTrackCancel)
    def put_RasterBlockSize(self, pSize):
        '''Method IDynamicSurface.put_RasterBlockSize (from IDynamicSurface)

           INPUT
            pSize               : long'''
        return super(IDynamicSurface2, self).put_RasterBlockSize(pSize)
    def get_RasterBlockSize(self):
        '''Method IDynamicSurface.get_RasterBlockSize (from IDynamicSurface)

           OUTPUT
            pSize               : long*'''
        return super(IDynamicSurface2, self).get_RasterBlockSize()
    def get_Terrain(self):
        '''Method IDynamicSurface.get_Terrain (from IDynamicSurface)

           OUTPUT
            ppTerrain           : ITerrain**'''
        return super(IDynamicSurface2, self).get_Terrain()
    def GetTin(self, pAreaOfInterest, Resolution, bClipWithAOI, pTrackCancel):
        '''Method IDynamicSurface.GetTin (from IDynamicSurface)

           INPUTS
            pAreaOfInterest     : IEnvelope*
            Resolution          : double
            bClipWithAOI        : VARIANT_BOOL
            pTrackCancel        : ITrackCancel*

           OUTPUT
            ppTin               : ITin**'''
        return super(IDynamicSurface2, self).GetTin(pAreaOfInterest, Resolution, bClipWithAOI, pTrackCancel)
    def QueryRaster(self, pDataset, pAreaOfInterest, Resolution, Method, pTrackCancel):
        '''Method IDynamicSurface.QueryRaster (from IDynamicSurface)

           INPUTS
            pDataset            : IRasterDataset*
            pAreaOfInterest     : IEnvelope*
            Resolution          : double
            Method              : esriSurfaceInterpolationType
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface2, self).QueryRaster(pDataset, pAreaOfInterest, Resolution, Method, pTrackCancel)
    def QueryAsFeatureClass(self, pFeatureClass, pAreaOfInterest, Resolution, pTrackCancel):
        '''Method IDynamicSurface.QueryAsFeatureClass (from IDynamicSurface)

           INPUTS
            pFeatureClass       : IFeatureClass*
            pAreaOfInterest     : IEnvelope*
            Resolution          : double
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface2, self).QueryAsFeatureClass(pFeatureClass, pAreaOfInterest, Resolution, pTrackCancel)
    CanDoCurvature = property(get_CanDoCurvature, None, None)
    MinimizeResourceUsage = property(get_MinimizeResourceUsage, put_MinimizeResourceUsage, None)
    RasterBlockSize = property(get_RasterBlockSize, put_RasterBlockSize, None)
    RefineBoundaryMatching = property(get_RefineBoundaryMatching, put_RefineBoundaryMatching, None)
    Terrain = property(get_Terrain, None, None)

class IDynamicSurface3(_esriGeoDatabaseExtensions.IDynamicSurface3):
    _IID = uuid.UUID('9dc0a59e-494e-41b6-be82-f283e3431577')

    def __init__(self, *args, **kw):
        super(IDynamicSurface3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def CreateBlockCursor(self, pAOI, Resolution, bSingleTileOnly, pTrackCancel):
        '''Method IDynamicSurface3.CreateBlockCursor

           INPUTS
            pAOI                : IGeometry*
            Resolution          : double
            bSingleTileOnly     : VARIANT_BOOL
            pTrackCancel        : ITrackCancel*

           OUTPUT
            pCursor             : ITerrainBlockCursor**'''
        return super(IDynamicSurface3, self).CreateBlockCursor(pAOI, Resolution, bSingleTileOnly, pTrackCancel)
    def ConvertToExtent(self, rowBegin, rowEnd, colBegin, colEnd):
        '''Method IDynamicSurface3.ConvertToExtent

           INPUTS
            rowBegin            : long
            rowEnd              : long
            colBegin            : long
            colEnd              : long

           OUTPUT
            ppExtent            : IEnvelope**'''
        return super(IDynamicSurface3, self).ConvertToExtent(rowBegin, rowEnd, colBegin, colEnd)
    def ContourList(self, pAOI, Resolution, pBreaks, pOutFeatureClass, FieldName, digitsAfterDecimalPoint, pTrackCancel):
        '''Method IDynamicSurface3.ContourList

           INPUTS
            pAOI                : IEnvelope*
            Resolution          : double
            pBreaks             : IDoubleArray*
            pOutFeatureClass    : IFeatureClass*
            FieldName           : BSTR
            digitsAfterDecimalPoint: long
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface3, self).ContourList(pAOI, Resolution, pBreaks, pOutFeatureClass, FieldName, digitsAfterDecimalPoint, pTrackCancel)
    def Contour(self, pAOI, Resolution, referenceContourHeight, interval, elevationFieldName, indexContourFactor, indexContourFieldName, digitsAfterDecimalPoint, pOutFeatureClass, pTrackCancel):
        '''Method IDynamicSurface3.Contour

           INPUTS
            pAOI                : IEnvelope*
            Resolution          : double
            referenceContourHeight: double
            interval            : double
            elevationFieldName  : BSTR
            indexContourFactor  : long
            indexContourFieldName: BSTR
            digitsAfterDecimalPoint: long
            pOutFeatureClass    : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface3, self).Contour(pAOI, Resolution, referenceContourHeight, interval, elevationFieldName, indexContourFactor, indexContourFieldName, digitsAfterDecimalPoint, pOutFeatureClass, pTrackCancel)
    def GetVolumeAndArea(self, pAOI, Resolution, reference, Type, pTrackCancel):
        '''Method IDynamicSurface3.GetVolumeAndArea

           INPUTS
            pAOI                : IGeometry*
            Resolution          : double
            reference           : double
            Type                : esriPlaneReferenceType
            pTrackCancel        : ITrackCancel*

           OUTPUTS
            pbIsOutsideDataArea : VARIANT_BOOL*
            pVolume             : VARIANT*
            pSurfaceArea        : VARIANT*
            pProjectedArea      : VARIANT*'''
        return super(IDynamicSurface3, self).GetVolumeAndArea(pAOI, Resolution, reference, Type, pTrackCancel)
    def Intersect(self, pAOI, Resolution, pReferenceSurface, referenceRsolution, bReverse, pOutFeatureClass, volumeFieldName, surfaceAreaFieldName, codeFieldName, pTrackCancel):
        '''Method IDynamicSurface3.Intersect

           INPUTS
            pAOI                : IGeometry*
            Resolution          : double
            pReferenceSurface   : IUnknown*
            referenceRsolution  : double
            bReverse            : VARIANT_BOOL
            pOutFeatureClass    : IFeatureClass*
            volumeFieldName     : BSTR
            surfaceAreaFieldName: BSTR
            codeFieldName       : BSTR
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface3, self).Intersect(pAOI, Resolution, pReferenceSurface, referenceRsolution, bReverse, pOutFeatureClass, volumeFieldName, surfaceAreaFieldName, codeFieldName, pTrackCancel)
    def put_ProfileWeedTolerance(self, pTolerance):
        '''Method IDynamicSurface3.put_ProfileWeedTolerance

           INPUT
            pTolerance          : double'''
        return super(IDynamicSurface3, self).put_ProfileWeedTolerance(pTolerance)
    def get_ProfileWeedTolerance(self):
        '''Method IDynamicSurface3.get_ProfileWeedTolerance

           OUTPUT
            pTolerance          : double*'''
        return super(IDynamicSurface3, self).get_ProfileWeedTolerance()
    def get_ZFactor(self):
        '''Method IDynamicSurface3.get_ZFactor

           OUTPUT
            pFactor             : double*'''
        return super(IDynamicSurface3, self).get_ZFactor()
    def put_ZFactor(self, pFactor):
        '''Method IDynamicSurface3.put_ZFactor

           INPUT
            pFactor             : double'''
        return super(IDynamicSurface3, self).put_ZFactor(pFactor)
    def put_MinimizeResourceUsage(self, pbMinimize):
        '''Method IDynamicSurface2.put_MinimizeResourceUsage (from IDynamicSurface2)

           INPUT
            pbMinimize          : VARIANT_BOOL'''
        return super(IDynamicSurface3, self).put_MinimizeResourceUsage(pbMinimize)
    def get_MinimizeResourceUsage(self):
        '''Method IDynamicSurface2.get_MinimizeResourceUsage (from IDynamicSurface2)

           OUTPUT
            pbMinimize          : VARIANT_BOOL*'''
        return super(IDynamicSurface3, self).get_MinimizeResourceUsage()
    def put_RefineBoundaryMatching(self, pbRefine):
        '''Method IDynamicSurface2.put_RefineBoundaryMatching (from IDynamicSurface2)

           INPUT
            pbRefine            : VARIANT_BOOL'''
        return super(IDynamicSurface3, self).put_RefineBoundaryMatching(pbRefine)
    def get_RefineBoundaryMatching(self):
        '''Method IDynamicSurface2.get_RefineBoundaryMatching (from IDynamicSurface2)

           OUTPUT
            pbRefine            : VARIANT_BOOL*'''
        return super(IDynamicSurface3, self).get_RefineBoundaryMatching()
    def InterpolateShape(self, pInShape, Resolution, Type, pTrackCancel, pStepSize):
        '''Method IDynamicSurface2.InterpolateShape (from IDynamicSurface2)

           INPUTS
            pInShape            : IGeometry*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pTrackCancel        : ITrackCancel*
            pStepSize           : VARIANT*

           OUTPUT
            ppOutShape          : IGeometry**'''
        return super(IDynamicSurface3, self).InterpolateShape(pInShape, Resolution, Type, pTrackCancel, pStepSize)
    def InterpolateShapeVertices(self, pInShape, Resolution, Type, pTrackCancel):
        '''Method IDynamicSurface2.InterpolateShapeVertices (from IDynamicSurface2)

           INPUTS
            pInShape            : IGeometry*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pTrackCancel        : ITrackCancel*

           OUTPUT
            ppOutShape          : IGeometry**'''
        return super(IDynamicSurface3, self).InterpolateShapeVertices(pInShape, Resolution, Type, pTrackCancel)
    def InterpolateFeatureClass(self, pInFeatureClass, pFilter, Resolution, Type, pOutFeatureClass, pTrackCancel, pStepSize):
        '''Method IDynamicSurface2.InterpolateFeatureClass (from IDynamicSurface2)

           INPUTS
            pInFeatureClass     : IFeatureClass*
            pFilter             : IQueryFilter*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pOutFeatureClass    : IFeatureClass*
            pTrackCancel        : ITrackCancel*
            pStepSize           : VARIANT*'''
        return super(IDynamicSurface3, self).InterpolateFeatureClass(pInFeatureClass, pFilter, Resolution, Type, pOutFeatureClass, pTrackCancel, pStepSize)
    def InterpolateFeatureCursor(self, pCursor, Resolution, Type, pOutFeatureClass, pTrackCancel, pStepSize):
        '''Method IDynamicSurface2.InterpolateFeatureCursor (from IDynamicSurface2)

           INPUTS
            pCursor             : IFeatureCursor*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pOutFeatureClass    : IFeatureClass*
            pTrackCancel        : ITrackCancel*
            pStepSize           : VARIANT*'''
        return super(IDynamicSurface3, self).InterpolateFeatureCursor(pCursor, Resolution, Type, pOutFeatureClass, pTrackCancel, pStepSize)
    def InterpolateFeatureClassVertices(self, pInFeatureClass, pFilter, Resolution, Type, pOutFeatureClass, pTrackCancel):
        '''Method IDynamicSurface2.InterpolateFeatureClassVertices (from IDynamicSurface2)

           INPUTS
            pInFeatureClass     : IFeatureClass*
            pFilter             : IQueryFilter*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pOutFeatureClass    : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface3, self).InterpolateFeatureClassVertices(pInFeatureClass, pFilter, Resolution, Type, pOutFeatureClass, pTrackCancel)
    def InterpolateFeatureCursorVertices(self, pCursor, Resolution, Type, pOutFeatureClass, pTrackCancel):
        '''Method IDynamicSurface2.InterpolateFeatureCursorVertices (from IDynamicSurface2)

           INPUTS
            pCursor             : IFeatureCursor*
            Resolution          : double
            Type                : esriSurfaceInterpolationType
            pOutFeatureClass    : IFeatureClass*
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface3, self).InterpolateFeatureCursorVertices(pCursor, Resolution, Type, pOutFeatureClass, pTrackCancel)
    def get_CanDoCurvature(self):
        '''Method IDynamicSurface2.get_CanDoCurvature (from IDynamicSurface2)

           OUTPUT
            pbCanDo             : VARIANT_BOOL*'''
        return super(IDynamicSurface3, self).get_CanDoCurvature()
    def GetLineOfSight(self, pObserver, pTarget, Resolution, pTrackCancel, bApplyCurvature, bApplyRefraction, pRefractionFactor):
        '''Method IDynamicSurface2.GetLineOfSight (from IDynamicSurface2)

           INPUTS
            pObserver           : IPoint*
            pTarget             : IPoint*
            Resolution          : double
            pTrackCancel        : ITrackCancel*
            bApplyCurvature     : VARIANT_BOOL
            bApplyRefraction    : VARIANT_BOOL
            pRefractionFactor   : VARIANT*

           OUTPUTS
            ppObstruction       : IPoint**
            ppVisibleLines      : IPolyline**
            ppInvisibleLines    : IPolyline**
            pbIsVisible         : VARIANT_BOOL*'''
        return super(IDynamicSurface3, self).GetLineOfSight(pObserver, pTarget, Resolution, pTrackCancel, bApplyCurvature, bApplyRefraction, pRefractionFactor)
    def GetLineOfSightFeatureCursor(self, pCursor, Resolution, pTrackCancel, pOutputLines, pObstructionPoints, bApplyCurvature, bApplyRefraction, pRefractionFactor):
        '''Method IDynamicSurface2.GetLineOfSightFeatureCursor (from IDynamicSurface2)

           INPUTS
            pCursor             : IFeatureCursor*
            Resolution          : double
            pTrackCancel        : ITrackCancel*
            pOutputLines        : IFeatureClass*
            pObstructionPoints  : IFeatureClass*
            bApplyCurvature     : VARIANT_BOOL
            bApplyRefraction    : VARIANT_BOOL
            pRefractionFactor   : VARIANT*'''
        return super(IDynamicSurface3, self).GetLineOfSightFeatureCursor(pCursor, Resolution, pTrackCancel, pOutputLines, pObstructionPoints, bApplyCurvature, bApplyRefraction, pRefractionFactor)
    def GetTileBasedDataArea(self, pTrackCancel):
        '''Method IDynamicSurface2.GetTileBasedDataArea (from IDynamicSurface2)

           INPUT
            pTrackCancel        : ITrackCancel*

           OUTPUT
            ppDataArea          : IPolygon**'''
        return super(IDynamicSurface3, self).GetTileBasedDataArea(pTrackCancel)
    def put_RasterBlockSize(self, pSize):
        '''Method IDynamicSurface.put_RasterBlockSize (from IDynamicSurface)

           INPUT
            pSize               : long'''
        return super(IDynamicSurface3, self).put_RasterBlockSize(pSize)
    def get_RasterBlockSize(self):
        '''Method IDynamicSurface.get_RasterBlockSize (from IDynamicSurface)

           OUTPUT
            pSize               : long*'''
        return super(IDynamicSurface3, self).get_RasterBlockSize()
    def get_Terrain(self):
        '''Method IDynamicSurface.get_Terrain (from IDynamicSurface)

           OUTPUT
            ppTerrain           : ITerrain**'''
        return super(IDynamicSurface3, self).get_Terrain()
    def GetTin(self, pAreaOfInterest, Resolution, bClipWithAOI, pTrackCancel):
        '''Method IDynamicSurface.GetTin (from IDynamicSurface)

           INPUTS
            pAreaOfInterest     : IEnvelope*
            Resolution          : double
            bClipWithAOI        : VARIANT_BOOL
            pTrackCancel        : ITrackCancel*

           OUTPUT
            ppTin               : ITin**'''
        return super(IDynamicSurface3, self).GetTin(pAreaOfInterest, Resolution, bClipWithAOI, pTrackCancel)
    def QueryRaster(self, pDataset, pAreaOfInterest, Resolution, Method, pTrackCancel):
        '''Method IDynamicSurface.QueryRaster (from IDynamicSurface)

           INPUTS
            pDataset            : IRasterDataset*
            pAreaOfInterest     : IEnvelope*
            Resolution          : double
            Method              : esriSurfaceInterpolationType
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface3, self).QueryRaster(pDataset, pAreaOfInterest, Resolution, Method, pTrackCancel)
    def QueryAsFeatureClass(self, pFeatureClass, pAreaOfInterest, Resolution, pTrackCancel):
        '''Method IDynamicSurface.QueryAsFeatureClass (from IDynamicSurface)

           INPUTS
            pFeatureClass       : IFeatureClass*
            pAreaOfInterest     : IEnvelope*
            Resolution          : double
            pTrackCancel        : ITrackCancel*'''
        return super(IDynamicSurface3, self).QueryAsFeatureClass(pFeatureClass, pAreaOfInterest, Resolution, pTrackCancel)
    CanDoCurvature = property(get_CanDoCurvature, None, None)
    MinimizeResourceUsage = property(get_MinimizeResourceUsage, put_MinimizeResourceUsage, None)
    ProfileWeedTolerance = property(get_ProfileWeedTolerance, put_ProfileWeedTolerance, None)
    RasterBlockSize = property(get_RasterBlockSize, put_RasterBlockSize, None)
    RefineBoundaryMatching = property(get_RefineBoundaryMatching, put_RefineBoundaryMatching, None)
    Terrain = property(get_Terrain, None, None)
    ZFactor = property(get_ZFactor, put_ZFactor, None)


# IIDs
IID_IDETerrain = IDETerrain._IID
IID_IDETerrainWindowSize = IDETerrainWindowSize._IID
IID_ITerrainDataSource = ITerrainDataSource._IID
IID_ITerrainPyramidLevel = ITerrainPyramidLevel._IID
IID_IEnumEnvelope = IEnumEnvelope._IID
IID_ITerrainEdit = ITerrainEdit._IID
IID_ITerrainEdit2 = ITerrainEdit2._IID
IID_ITerrainEdit3 = ITerrainEdit3._IID
IID_ITerrainName = ITerrainName._IID
IID_ITerrainDataSource2 = ITerrainDataSource2._IID
IID_ITerrainEmbeddedDataSource = ITerrainEmbeddedDataSource._IID
IID_ITerrainFieldStatistics = ITerrainFieldStatistics._IID
IID_ITerrainEmbeddedDataSource2 = ITerrainEmbeddedDataSource2._IID
IID_ITerrainBlockCursor = ITerrainBlockCursor._IID
IID_ITerrainDataImporter = ITerrainDataImporter._IID
IID_ITerrainLasDataImporter = ITerrainLasDataImporter._IID
IID_ITerrainAsciiDataImporter = ITerrainAsciiDataImporter._IID
IID_ITerrainAsciiDataImporter2 = ITerrainAsciiDataImporter2._IID
IID_ITerrainLasDataInfo = ITerrainLasDataInfo._IID
IID_ITerrainBlobReader = ITerrainBlobReader._IID
IID_ITerrainBlobWriter = ITerrainBlobWriter._IID
IID_ITerrainEditEvents = ITerrainEditEvents._IID
IID_ITerrainLasDataInfo2 = ITerrainLasDataInfo2._IID
IID_IGPTerrainMembership = IGPTerrainMembership._IID
IID_ISimpleStatistics = ISimpleStatistics._IID
IID_ILasReturnStatistics = ILasReturnStatistics._IID
IID_ILasClassCodeStatistics = ILasClassCodeStatistics._IID
IID_ILasStatistics = ILasStatistics._IID
IID_ILasHeaderInfo = ILasHeaderInfo._IID
IID_ILasFile = ILasFile._IID
IID_ILasAttributeFilter = ILasAttributeFilter._IID
IID_ILasPointFilter = ILasPointFilter._IID
IID_ILasFilter = ILasFilter._IID
IID_ILasSurface = ILasSurface._IID
IID_ILasDataset = ILasDataset._IID
IID_ILasDatasetEdit = ILasDatasetEdit._IID
IID_IEnumLasPoint = IEnumLasPoint._IID
IID_ILasPointInfo = ILasPointInfo._IID
IID_ILasPointCloud = ILasPointCloud._IID
IID_ILasDatasetWorkspace = ILasDatasetWorkspace._IID
IID_ILasDataset2 = ILasDataset2._IID
IID_ILasPointEdit = ILasPointEdit._IID
IID_ICadastralJob = ICadastralJob._IID
IID_ICadastralFabric = ICadastralFabric._IID
IID_ICadastralFabric2 = ICadastralFabric2._IID
IID_ICadastralFabric3 = ICadastralFabric3._IID
IID_ICadastralFabricName = ICadastralFabricName._IID
IID_IDECadastralFabric = IDECadastralFabric._IID
IID_ICadastralTransformationData = ICadastralTransformationData._IID
IID_ICadastralAdjustmentVectors = ICadastralAdjustmentVectors._IID
IID_ICadastralFabricLocks = ICadastralFabricLocks._IID
IID_ICadastralFabricLocks2 = ICadastralFabricLocks2._IID
IID_ICadastralFabricSchemaEdit = ICadastralFabricSchemaEdit._IID
IID_ICadastralFabricSchemaEdit2 = ICadastralFabricSchemaEdit2._IID
IID_ICadastralTableFieldEdits = ICadastralTableFieldEdits._IID
IID_IDECadastralFabric2 = IDECadastralFabric2._IID
IID_IDECadastralFabric3 = IDECadastralFabric3._IID
IID_IParcelConstructionData = IParcelConstructionData._IID
IID_IConstructionParentParcels = IConstructionParentParcels._IID
IID_IConstructionBreakPoints = IConstructionBreakPoints._IID
IID_IConstructionBasisOfBearing = IConstructionBasisOfBearing._IID
IID_IConstructionJoinLinks = IConstructionJoinLinks._IID
IID_IConstructionUnbuildableLines = IConstructionUnbuildableLines._IID
IID_IConstructionPoints = IConstructionPoints._IID
IID_IConstructionAdjustment = IConstructionAdjustment._IID
IID_ILineResequencer = ILineResequencer._IID
IID_ICadastralFabricRegeneration = ICadastralFabricRegeneration._IID
IID_ICadastralUnitConversion = ICadastralUnitConversion._IID
IID_ICadastralGroundToGridTools = ICadastralGroundToGridTools._IID
IID_ICadastralUnitTools = ICadastralUnitTools._IID
IID_ICadastralFabricEditControl = ICadastralFabricEditControl._IID
IID_IDataMessage = IDataMessage._IID
IID_ITemporalOperator = ITemporalOperator._IID
IID_ITrackingServiceDef = ITrackingServiceDef._IID
IID__ITemporalFeatureClassEvents = _ITemporalFeatureClassEvents._IID
IID_ITemporalFeatureClass2 = ITemporalFeatureClass2._IID
IID_ITemporalTable = ITemporalTable._IID
IID_IInternalTable = IInternalTable._IID
IID_ITemporalObservationsTable = ITemporalObservationsTable._IID
IID_ITemporalObjectTable = ITemporalObjectTable._IID
IID_ITemporalObservationsTable2 = ITemporalObservationsTable2._IID
IID_IExcludedEventIDs = IExcludedEventIDs._IID
IID_ITemporalQueryFilter = ITemporalQueryFilter._IID
IID_ITemporalQueryFilter2 = ITemporalQueryFilter2._IID
IID_IListener = IListener._IID
IID_ITemporalFeature = ITemporalFeature._IID
IID_IAMSDatasetName = IAMSDatasetName._IID
IID_ITemporalFeatureClassStatistics = ITemporalFeatureClassStatistics._IID
IID_ITemporalWorkspaceStatistics = ITemporalWorkspaceStatistics._IID
IID_ITemporalWorkspaceStatistics2 = ITemporalWorkspaceStatistics2._IID
IID_ILockedFeatureSearch = ILockedFeatureSearch._IID
IID_ITxWorkspaceEditor = ITxWorkspaceEditor._IID
IID_ITemporalRecordSet = ITemporalRecordSet._IID
IID_ITxFeatureClass = ITxFeatureClass._IID
IID_ITxEnumTrackId = ITxEnumTrackId._IID
IID_ITemporalCursor = ITemporalCursor._IID
IID_ITerrain = ITerrain._IID
IID_IDynamicSurface = IDynamicSurface._IID
IID_ITerrain2 = ITerrain2._IID
IID_IDynamicSurface2 = IDynamicSurface2._IID
IID_IDynamicSurface3 = IDynamicSurface3._IID
_IIDMap[IID_IDETerrain] = IDETerrain
_IIDMap[IID_IDETerrainWindowSize] = IDETerrainWindowSize
_IIDMap[IID_ITerrainDataSource] = ITerrainDataSource
_IIDMap[IID_ITerrainPyramidLevel] = ITerrainPyramidLevel
_IIDMap[IID_IEnumEnvelope] = IEnumEnvelope
_IIDMap[IID_ITerrainEdit] = ITerrainEdit
_IIDMap[IID_ITerrainEdit2] = ITerrainEdit2
_IIDMap[IID_ITerrainEdit3] = ITerrainEdit3
_IIDMap[IID_ITerrainName] = ITerrainName
_IIDMap[IID_ITerrainDataSource2] = ITerrainDataSource2
_IIDMap[IID_ITerrainEmbeddedDataSource] = ITerrainEmbeddedDataSource
_IIDMap[IID_ITerrainFieldStatistics] = ITerrainFieldStatistics
_IIDMap[IID_ITerrainEmbeddedDataSource2] = ITerrainEmbeddedDataSource2
_IIDMap[IID_ITerrainBlockCursor] = ITerrainBlockCursor
_IIDMap[IID_ITerrainDataImporter] = ITerrainDataImporter
_IIDMap[IID_ITerrainLasDataImporter] = ITerrainLasDataImporter
_IIDMap[IID_ITerrainAsciiDataImporter] = ITerrainAsciiDataImporter
_IIDMap[IID_ITerrainAsciiDataImporter2] = ITerrainAsciiDataImporter2
_IIDMap[IID_ITerrainLasDataInfo] = ITerrainLasDataInfo
_IIDMap[IID_ITerrainBlobReader] = ITerrainBlobReader
_IIDMap[IID_ITerrainBlobWriter] = ITerrainBlobWriter
_IIDMap[IID_ITerrainEditEvents] = ITerrainEditEvents
_IIDMap[IID_ITerrainLasDataInfo2] = ITerrainLasDataInfo2
_IIDMap[IID_IGPTerrainMembership] = IGPTerrainMembership
_IIDMap[IID_ISimpleStatistics] = ISimpleStatistics
_IIDMap[IID_ILasReturnStatistics] = ILasReturnStatistics
_IIDMap[IID_ILasClassCodeStatistics] = ILasClassCodeStatistics
_IIDMap[IID_ILasStatistics] = ILasStatistics
_IIDMap[IID_ILasHeaderInfo] = ILasHeaderInfo
_IIDMap[IID_ILasFile] = ILasFile
_IIDMap[IID_ILasAttributeFilter] = ILasAttributeFilter
_IIDMap[IID_ILasPointFilter] = ILasPointFilter
_IIDMap[IID_ILasFilter] = ILasFilter
_IIDMap[IID_ILasSurface] = ILasSurface
_IIDMap[IID_ILasDataset] = ILasDataset
_IIDMap[IID_ILasDatasetEdit] = ILasDatasetEdit
_IIDMap[IID_IEnumLasPoint] = IEnumLasPoint
_IIDMap[IID_ILasPointInfo] = ILasPointInfo
_IIDMap[IID_ILasPointCloud] = ILasPointCloud
_IIDMap[IID_ILasDatasetWorkspace] = ILasDatasetWorkspace
_IIDMap[IID_ILasDataset2] = ILasDataset2
_IIDMap[IID_ILasPointEdit] = ILasPointEdit
_IIDMap[IID_ICadastralJob] = ICadastralJob
_IIDMap[IID_ICadastralFabric] = ICadastralFabric
_IIDMap[IID_ICadastralFabric2] = ICadastralFabric2
_IIDMap[IID_ICadastralFabric3] = ICadastralFabric3
_IIDMap[IID_ICadastralFabricName] = ICadastralFabricName
_IIDMap[IID_IDECadastralFabric] = IDECadastralFabric
_IIDMap[IID_ICadastralTransformationData] = ICadastralTransformationData
_IIDMap[IID_ICadastralAdjustmentVectors] = ICadastralAdjustmentVectors
_IIDMap[IID_ICadastralFabricLocks] = ICadastralFabricLocks
_IIDMap[IID_ICadastralFabricLocks2] = ICadastralFabricLocks2
_IIDMap[IID_ICadastralFabricSchemaEdit] = ICadastralFabricSchemaEdit
_IIDMap[IID_ICadastralFabricSchemaEdit2] = ICadastralFabricSchemaEdit2
_IIDMap[IID_ICadastralTableFieldEdits] = ICadastralTableFieldEdits
_IIDMap[IID_IDECadastralFabric2] = IDECadastralFabric2
_IIDMap[IID_IDECadastralFabric3] = IDECadastralFabric3
_IIDMap[IID_IParcelConstructionData] = IParcelConstructionData
_IIDMap[IID_IConstructionParentParcels] = IConstructionParentParcels
_IIDMap[IID_IConstructionBreakPoints] = IConstructionBreakPoints
_IIDMap[IID_IConstructionBasisOfBearing] = IConstructionBasisOfBearing
_IIDMap[IID_IConstructionJoinLinks] = IConstructionJoinLinks
_IIDMap[IID_IConstructionUnbuildableLines] = IConstructionUnbuildableLines
_IIDMap[IID_IConstructionPoints] = IConstructionPoints
_IIDMap[IID_IConstructionAdjustment] = IConstructionAdjustment
_IIDMap[IID_ILineResequencer] = ILineResequencer
_IIDMap[IID_ICadastralFabricRegeneration] = ICadastralFabricRegeneration
_IIDMap[IID_ICadastralUnitConversion] = ICadastralUnitConversion
_IIDMap[IID_ICadastralGroundToGridTools] = ICadastralGroundToGridTools
_IIDMap[IID_ICadastralUnitTools] = ICadastralUnitTools
_IIDMap[IID_ICadastralFabricEditControl] = ICadastralFabricEditControl
_IIDMap[IID_IDataMessage] = IDataMessage
_IIDMap[IID_ITemporalOperator] = ITemporalOperator
_IIDMap[IID_ITrackingServiceDef] = ITrackingServiceDef
_IIDMap[IID__ITemporalFeatureClassEvents] = _ITemporalFeatureClassEvents
_IIDMap[IID_ITemporalFeatureClass2] = ITemporalFeatureClass2
_IIDMap[IID_ITemporalTable] = ITemporalTable
_IIDMap[IID_IInternalTable] = IInternalTable
_IIDMap[IID_ITemporalObservationsTable] = ITemporalObservationsTable
_IIDMap[IID_ITemporalObjectTable] = ITemporalObjectTable
_IIDMap[IID_ITemporalObservationsTable2] = ITemporalObservationsTable2
_IIDMap[IID_IExcludedEventIDs] = IExcludedEventIDs
_IIDMap[IID_ITemporalQueryFilter] = ITemporalQueryFilter
_IIDMap[IID_ITemporalQueryFilter2] = ITemporalQueryFilter2
_IIDMap[IID_IListener] = IListener
_IIDMap[IID_ITemporalFeature] = ITemporalFeature
_IIDMap[IID_IAMSDatasetName] = IAMSDatasetName
_IIDMap[IID_ITemporalFeatureClassStatistics] = ITemporalFeatureClassStatistics
_IIDMap[IID_ITemporalWorkspaceStatistics] = ITemporalWorkspaceStatistics
_IIDMap[IID_ITemporalWorkspaceStatistics2] = ITemporalWorkspaceStatistics2
_IIDMap[IID_ILockedFeatureSearch] = ILockedFeatureSearch
_IIDMap[IID_ITxWorkspaceEditor] = ITxWorkspaceEditor
_IIDMap[IID_ITemporalRecordSet] = ITemporalRecordSet
_IIDMap[IID_ITxFeatureClass] = ITxFeatureClass
_IIDMap[IID_ITxEnumTrackId] = ITxEnumTrackId
_IIDMap[IID_ITemporalCursor] = ITemporalCursor
_IIDMap[IID_ITerrain] = ITerrain
_IIDMap[IID_IDynamicSurface] = IDynamicSurface
_IIDMap[IID_ITerrain2] = ITerrain2
_IIDMap[IID_IDynamicSurface2] = IDynamicSurface2
_IIDMap[IID_IDynamicSurface3] = IDynamicSurface3


# CLSIDs
CLSID_TerrainWorkspaceExtension = uuid.UUID('d472bd51-30dc-4e57-a5f6-469e92d934b3')
CLSID_TerrainName = uuid.UUID('4ced9311-6566-44f6-b135-657d6f48143e')
CLSID_TerrainDataSource = uuid.UUID('2fbea8fd-19f5-4cc6-8d99-fb921fcae57d')
CLSID_TerrainPyramidLevelZTolerance = uuid.UUID('211d08c6-6f1d-490d-bb84-68e699b54a15')
CLSID_TerrainPyramidLevelWindowSize = uuid.UUID('47724afe-3fb9-4fc3-b96b-55f56ef9dede')
CLSID_DETerrain = uuid.UUID('546543b6-327a-4d3c-ac15-8122c8b6680a')
CLSID_TerrainLasDataImporter = uuid.UUID('e0879549-ca26-41ab-a9c6-463ec3b1b1ca')
CLSID_TerrainAsciiDataImporter = uuid.UUID('eeb6b206-c144-496c-88d2-b6e2da4d37e7')
CLSID_TerrainBlobReader = uuid.UUID('564bba1a-9f3a-40c5-b4bf-e8e534388944')
CLSID_TerrainBlobWriter = uuid.UUID('0ea06d19-aeec-4110-a231-2705a08b9366')
CLSID_TerrainBlockCursor = uuid.UUID('ad220bb5-bd26-435e-9dbc-28fe5bac9171')
CLSID_TerrainFieldStatistics = uuid.UUID('ce7821b4-04ae-4518-842b-07d66ff6e605')
CLSID_GPTerrainMembership = uuid.UUID('242a9245-015f-4fdf-a16a-fae4d24b45d6')
CLSID_DETerrainType = uuid.UUID('2d9d8047-6490-41e5-85da-ecb5926582a2')
CLSID_TerrainFeatureDatasetExtension = uuid.UUID('9a88d1b2-a418-4ad7-9107-fe41de647faf')
CLSID_Terrain = uuid.UUID('ea9eb4a1-77b3-433c-a7dd-bb4436fa0e98')
CLSID_DynamicSurface = uuid.UUID('7c3b1045-dfad-4f31-9d55-bf743da91648')
CLSID_LasDatasetWorkspaceFactory = uuid.UUID('7ab01d9a-fdfe-4dfb-9209-86603ee9aec6')
CLSID_LasDatasetName = uuid.UUID('2029a994-9bc0-4094-a1c7-e5381869e4e3')
CLSID_LasDataset = uuid.UUID('711e7d01-2a82-4b7f-8d77-061c51baf8dd')
CLSID_LasFilter = uuid.UUID('6aa74d41-734b-4bad-87ea-245977e51ee1')
CLSID_LasPointInfo = uuid.UUID('fd112eb0-4a24-4135-ad29-98ec25e37821')
CLSID_LasHeaderInfo = uuid.UUID('8463e10e-689a-45c1-b468-f660b5ec1dd1')
CLSID_LasFile = uuid.UUID('767b20c5-40c4-4875-a3d8-d6de321c62bf')
CLSID_LasSurface = uuid.UUID('a83fb64e-0b76-43e0-b8ae-6c96a9913147')
CLSID_LasStatistics = uuid.UUID('a3cb49f5-6cdb-4911-bb7b-7e4b39c4d2ee')
CLSID_LasAttributeStatistics = uuid.UUID('cbef81ba-43fd-4ae5-a235-7e69724bee49')
CLSID_LasReturnStatistics = uuid.UUID('0135c452-608b-4831-9262-1c6c772f300e')
CLSID_LasClassCodeStatistics = uuid.UUID('421e5140-a9be-4215-9357-c4a9852f8cab')
CLSID_LasPointEnumerator = uuid.UUID('ddb996e0-31df-4d77-b903-5295e60ac459')
CLSID_LasToRasterFunction = uuid.UUID('9889d8fb-93f6-49b1-b352-d8e2b331c797')
CLSID_LasToRasterFunctionArguments = uuid.UUID('fb8e343b-8014-4ce9-b457-e72389d2b339')
CLSID_TerrainToRasterFunction = uuid.UUID('d4d3a0bb-3770-40ef-acf1-bb3c1c98a38e')
CLSID_TerrainToRasterFunctionArguments = uuid.UUID('8bf576ca-96c8-4106-9020-a2d78d221dc4')
CLSID_LasDatasetToRasterFunction = uuid.UUID('06a78a67-ba8a-4592-83e5-5dd4362f6636')
CLSID_LasDatasetToRasterFunctionArguments = uuid.UUID('67876aa0-40eb-470a-abc9-036085756c53')
CLSID_CadastralFabric = uuid.UUID('8081ca69-9711-4caf-bdd9-45daab4a4666')
CLSID_CadastralFabricName = uuid.UUID('5c947220-ffb5-4e71-a059-af201ae081a6')
CLSID_CadastralWorkspaceDatasetExtension = uuid.UUID('be58e469-f14d-49c6-8080-0b027271ef91')
CLSID_DECadastralFabric = uuid.UUID('b0f868c0-bfbc-4669-b263-cd348d65d7ae')
CLSID_CadastralFabricFDExtension = uuid.UUID('0822e62d-8c8f-4483-8eb7-96dd0c343343')
CLSID_CadastralJob = uuid.UUID('f8027b0a-a3fb-448a-8fe2-b1beadcf672e')
CLSID_CadastralTransformationData = uuid.UUID('f0e92e5d-39fb-4ead-8192-1a027fab68c1')
CLSID_CadastralTableFieldEdits = uuid.UUID('dee35dfb-81a2-468e-aba8-2414e757a0d9')
CLSID_DECadastralFabricType = uuid.UUID('931bf28c-b23d-4416-96ed-f653aa60524d')
CLSID_ParcelConstructionData = uuid.UUID('bcb1e8c9-1aa6-4012-aeaa-8fb4f62d85cb')
CLSID_LineResequencer = uuid.UUID('dae9512c-77a7-4857-8624-225fc5294f46')
CLSID_CadastralFabricRegenerator = uuid.UUID('c3d97ce1-22f7-4f5a-942b-aa899f61ad34')
CLSID_CadastralUnitConversion = uuid.UUID('c99a1138-f8b4-4113-862c-ec5407453301')
CLSID_CadastralDataTools = uuid.UUID('2faf44e5-2951-4021-a6e9-209fe3125a12')

# Enumerations
class esriTerrainPyramidType(Enumeration):
    __slots__ = ['esriTerrainPyramidZTolerance',
                 'esriTerrainPyramidWindowSize']
    esriTerrainPyramidZTolerance = 0
    esriTerrainPyramidWindowSize = 1

class esriTerrainWindowSizeMethod(Enumeration):
    __slots__ = ['esriTerrainWindowSizeZmin',
                 'esriTerrainWindowSizeZmax',
                 'esriTerrainWindowSizeZminZmax',
                 'esriTerrainWindowSizeZaverage']
    esriTerrainWindowSizeZmin = 0
    esriTerrainWindowSizeZmax = 1
    esriTerrainWindowSizeZminZmax = 2
    esriTerrainWindowSizeZaverage = 3

class esriTerrainZThresholdStrategy(Enumeration):
    __slots__ = ['esriTerrainZThresholdMildThinning',
                 'esriTerrainZThresholdModerateThinning',
                 'esriTerrainZThresholdStrongThinning']
    esriTerrainZThresholdMildThinning = 0
    esriTerrainZThresholdModerateThinning = 1
    esriTerrainZThresholdStrongThinning = 2

class esriTerrainBlobDataType(Enumeration):
    __slots__ = ['esriTerrainChar',
                 'esriTerrainUChar',
                 'esriTerrainShort',
                 'esriTerrainUShort',
                 'esriTerrainLong',
                 'esriTerrainULong',
                 'esriTerrainFloat',
                 'esriTerrainDouble']
    esriTerrainChar = 1
    esriTerrainUChar = 2
    esriTerrainShort = 3
    esriTerrainUShort = 4
    esriTerrainLong = 5
    esriTerrainULong = 6
    esriTerrainFloat = 7
    esriTerrainDouble = 9

class esriTerrainLasDataPropertyType(Enumeration):
    __slots__ = ['esriTerrainLasIntensity',
                 'esriTerrainLasReturnNumber',
                 'esriTerrainLasNumberOfReturns',
                 'esriTerrainLasScanDirectionFlag',
                 'esriTerrainLasEdgeOfFlightLine',
                 'esriTerrainLasClassification',
                 'esriTerrainLasScanAngleRank',
                 'esriTerrainLasFileMarker',
                 'esriTerrainLasUserBitField',
                 'esriTerrainLasGpsTime',
                 'esriTerrainLasColorRed',
                 'esriTerrainLasColorGreen',
                 'esriTerrainLasColorBlue']
    esriTerrainLasIntensity = 1
    esriTerrainLasReturnNumber = 2
    esriTerrainLasNumberOfReturns = 4
    esriTerrainLasScanDirectionFlag = 8
    esriTerrainLasEdgeOfFlightLine = 16
    esriTerrainLasClassification = 32
    esriTerrainLasScanAngleRank = 64
    esriTerrainLasFileMarker = 128
    esriTerrainLasUserBitField = 256
    esriTerrainLasGpsTime = 512
    esriTerrainLasColorRed = 1024
    esriTerrainLasColorGreen = 2048
    esriTerrainLasColorBlue = 4096

class esriTerrainLasReturnType(Enumeration):
    __slots__ = ['esriTerrainLasReturn1',
                 'esriTerrainLasReturn2',
                 'esriTerrainLasReturn3',
                 'esriTerrainLasReturn4',
                 'esriTerrainLasReturn5',
                 'esriTerrainLasReturn6',
                 'esriTerrainLasReturn7',
                 'esriTerrainLasReturn8',
                 'esriTerrainLasReturnLast',
                 'esriTerrainLasReturnSingle',
                 'esriTerrainLasReturnFirstOfMany',
                 'esriTerrainLasReturnLastOfMany',
                 'esriTerrainLasReturnAll']
    esriTerrainLasReturn1 = 1
    esriTerrainLasReturn2 = 2
    esriTerrainLasReturn3 = 3
    esriTerrainLasReturn4 = 4
    esriTerrainLasReturn5 = 5
    esriTerrainLasReturn6 = 6
    esriTerrainLasReturn7 = 7
    esriTerrainLasReturn8 = 8
    esriTerrainLasReturnLast = 256
    esriTerrainLasReturnSingle = 257
    esriTerrainLasReturnFirstOfMany = 258
    esriTerrainLasReturnLastOfMany = 259
    esriTerrainLasReturnAll = -1

class esriTerrainAsciiDataFormatType(Enumeration):
    __slots__ = ['esriTerrainAsciiDataFormatXYZ',
                 'esriTerrainAsciiDataFormatGenerate',
                 'esriTerrainAsciiDataFormatXYZI']
    esriTerrainAsciiDataFormatXYZ = 0
    esriTerrainAsciiDataFormatGenerate = 1
    esriTerrainAsciiDataFormatXYZI = 2

class esriTerrainDecimalSeparatorType(Enumeration):
    __slots__ = ['esriTerrainDecimalSeparatorPoint',
                 'esriTerrainDecimalSeparatorComma']
    esriTerrainDecimalSeparatorPoint = 0
    esriTerrainDecimalSeparatorComma = 1

class esriTerrainError(Enumeration):
    __slots__ = ['E_TERRAIN_INVALID_DATA_SOURCE',
                 'E_TERRAIN_DATA_SOURCE_EXISTS',
                 'E_TERRAIN_INDEX_OUT_OF_RANGE',
                 'E_TERRAIN_NOT_INITIALIZED',
                 'E_TERRAIN_CANCELLED',
                 'E_TERRAIN_EDIT_SESSION_REQUIRED',
                 'E_TERRAIN_MUST_BE_ZLESS',
                 'E_TERRAIN_FILE_EXISTS',
                 'E_TERRAIN_FILE_NOT_EXISTS',
                 'E_TERRAIN_FILE_OPEN_ERROR',
                 'E_TERRAIN_FILE_READ_ERROR',
                 'E_TERRAIN_NOT_MATCH',
                 'E_TERRAIN_WRONG_FORMAT',
                 'E_TERRAIN_NO_RETURN',
                 'E_TERRAIN_BAD_SHAPE_SIZE',
                 'E_TERRAIN_NOT_MULTIPOINT',
                 'E_TERRAIN_UNKNOWN_FIELD',
                 'E_TERRAIN_FC_OUTSIDE',
                 'E_TERRAIN_ZTOLERANCE_EXISTS',
                 'E_TERRAIN_INVALID_TERRAIN',
                 'E_TERRAIN_INVALID_DEFINITION',
                 'E_TERRAIN_IN_EDIT_SESSION',
                 'E_TERRAIN_INVALID_BOUNDS',
                 'E_TERRAIN_BOUNDS_OVERLAP',
                 'E_TERRAIN_INCONSIST',
                 'E_TERRAIN_WRONG_GEOMETRY_TYPE',
                 'E_TERRAIN_MIXING_2D_AND_3D',
                 'E_TERRAIN_TOO_MANY_BASE',
                 'E_TERRAIN_MUST_NOT_BE_GROUPED',
                 'E_TERRAIN_WRONG_SF_TYPE',
                 'E_TERRAIN_INCONSIST_LOR',
                 'E_TERRAIN_CHANGE_CLASS_ID',
                 'E_TERRAIN_NOT_EMBEDDED',
                 'E_TERRAIN_NULL_FIELD_VALUE',
                 'E_TERRAIN_FIELD_NULLABLE',
                 'E_TERRAIN_TERRAIN_NOT_FOUND',
                 'E_TERRAIN_TERRAIN_NOT_SUPPORTED_IN_RELEASE',
                 'E_TERRAIN_TERRAIN_ALREADY_EXISTS',
                 'E_TERRAIN_INVALID_GEOMETRY_TYPE_FOR_TERRAIN',
                 'E_TERRAIN_CANNOT_ADD_REGISTERED_CLASS_TO_TERRAIN',
                 'E_TERRAIN_INVALID_TERRAIN_NAME',
                 'E_TERRAIN_WRONG_DATASET_TYPE',
                 'E_TERRAIN_WRONG_PYRAMID_TYPE',
                 'E_TERRAIN_CANNOT_CHANGE_SCHEMA',
                 'E_TERRAIN_NOT_MULTIPOINT_Z',
                 'E_TERRAIN_UNKNOWN_BLOB',
                 'E_TERRAIN_NEED_UPDATE',
                 'E_TERRAIN_OLD_VERSION',
                 'E_TERRAIN_CANNOT_PERFORM_SIMPLIFY_OVERVIEW',
                 'E_TERRAIN_NO_DATA',
                 'E_TERRAIN_EDIT_OPERATION_REQUIRED',
                 'E_TERRAIN_INVALID_EMBEDDED_FC_NAME',
                 'E_TERRAIN_TOO_MANY_CLIPPING_SOURCES',
                 'E_TERRAIN_INVALID_Z',
                 'E_TERRAIN_BAD_WINDOWSIZE',
                 'E_TERRAIN_NO_SPATIALREF_INFO',
                 'E_TERRAIN_NOT_PROJECTED_SYSTEM',
                 'E_TERRAIN_WRONG_TOPOLOGY',
                 'E_TERRAIN_VALUE_OVERFLOW',
                 'E_TERRAIN_DATA_TYPE_MISMATCH',
                 'E_TERRAIN_DIRTY_TERRAIN',
                 'E_TERRAIN_WINSIZE_NOT_SUPPORTED',
                 'E_TERRAIN_FIELD_TYPE_MISMATCH',
                 'E_TERRAIN_CANNOT_BE_ANCHORED',
                 'E_TERRAIN_ANCHOR_POINTS_NOT_SUPPORTED',
                 'E_TERRAIN_MUST_APPLY_TO_OVERVIEW',
                 'E_TERRAIN_VERSION_NOT_SUPPORTED',
                 'E_TERRAIN_FORMAT_NOT_SUPPORTED',
                 'E_TERRAIN_FILE_WRITE_ERROR',
                 'E_TERRAIN_INVALID_FILE',
                 'E_TERRAIN_WKT_NOT_SUPPORTED']
    E_TERRAIN_INVALID_DATA_SOURCE = -2147205120
    E_TERRAIN_DATA_SOURCE_EXISTS = -2147205119
    E_TERRAIN_INDEX_OUT_OF_RANGE = -2147205118
    E_TERRAIN_NOT_INITIALIZED = -2147205117
    E_TERRAIN_CANCELLED = -2147205116
    E_TERRAIN_EDIT_SESSION_REQUIRED = -2147205115
    E_TERRAIN_MUST_BE_ZLESS = -2147205114
    E_TERRAIN_FILE_EXISTS = -2147205113
    E_TERRAIN_FILE_NOT_EXISTS = -2147205112
    E_TERRAIN_FILE_OPEN_ERROR = -2147205111
    E_TERRAIN_FILE_READ_ERROR = -2147205110
    E_TERRAIN_NOT_MATCH = -2147205109
    E_TERRAIN_WRONG_FORMAT = -2147205108
    E_TERRAIN_NO_RETURN = -2147205107
    E_TERRAIN_BAD_SHAPE_SIZE = -2147205106
    E_TERRAIN_NOT_MULTIPOINT = -2147205105
    E_TERRAIN_UNKNOWN_FIELD = -2147205104
    E_TERRAIN_FC_OUTSIDE = -2147205103
    E_TERRAIN_ZTOLERANCE_EXISTS = -2147205102
    E_TERRAIN_INVALID_TERRAIN = -2147205101
    E_TERRAIN_INVALID_DEFINITION = -2147205100
    E_TERRAIN_IN_EDIT_SESSION = -2147205099
    E_TERRAIN_INVALID_BOUNDS = -2147205098
    E_TERRAIN_BOUNDS_OVERLAP = -2147205097
    E_TERRAIN_INCONSIST = -2147205096
    E_TERRAIN_WRONG_GEOMETRY_TYPE = -2147205095
    E_TERRAIN_MIXING_2D_AND_3D = -2147205094
    E_TERRAIN_TOO_MANY_BASE = -2147205093
    E_TERRAIN_MUST_NOT_BE_GROUPED = -2147205092
    E_TERRAIN_WRONG_SF_TYPE = -2147205091
    E_TERRAIN_INCONSIST_LOR = -2147205090
    E_TERRAIN_CHANGE_CLASS_ID = -2147205089
    E_TERRAIN_NOT_EMBEDDED = -2147205088
    E_TERRAIN_NULL_FIELD_VALUE = -2147205087
    E_TERRAIN_FIELD_NULLABLE = -2147205086
    E_TERRAIN_TERRAIN_NOT_FOUND = -2147205085
    E_TERRAIN_TERRAIN_NOT_SUPPORTED_IN_RELEASE = -2147205084
    E_TERRAIN_TERRAIN_ALREADY_EXISTS = -2147205083
    E_TERRAIN_INVALID_GEOMETRY_TYPE_FOR_TERRAIN = -2147205082
    E_TERRAIN_CANNOT_ADD_REGISTERED_CLASS_TO_TERRAIN = -2147205081
    E_TERRAIN_INVALID_TERRAIN_NAME = -2147205080
    E_TERRAIN_WRONG_DATASET_TYPE = -2147205079
    E_TERRAIN_WRONG_PYRAMID_TYPE = -2147205078
    E_TERRAIN_CANNOT_CHANGE_SCHEMA = -2147205077
    E_TERRAIN_NOT_MULTIPOINT_Z = -2147205076
    E_TERRAIN_UNKNOWN_BLOB = -2147205075
    E_TERRAIN_NEED_UPDATE = -2147205074
    E_TERRAIN_OLD_VERSION = -2147205073
    E_TERRAIN_CANNOT_PERFORM_SIMPLIFY_OVERVIEW = -2147205072
    E_TERRAIN_NO_DATA = -2147205071
    E_TERRAIN_EDIT_OPERATION_REQUIRED = -2147205070
    E_TERRAIN_INVALID_EMBEDDED_FC_NAME = -2147205069
    E_TERRAIN_TOO_MANY_CLIPPING_SOURCES = -2147205068
    E_TERRAIN_INVALID_Z = -2147205067
    E_TERRAIN_BAD_WINDOWSIZE = -2147205066
    E_TERRAIN_NO_SPATIALREF_INFO = -2147205065
    E_TERRAIN_NOT_PROJECTED_SYSTEM = -2147219400
    E_TERRAIN_WRONG_TOPOLOGY = -2147219399
    E_TERRAIN_VALUE_OVERFLOW = -2147219398
    E_TERRAIN_DATA_TYPE_MISMATCH = -2147219397
    E_TERRAIN_DIRTY_TERRAIN = -2147219396
    E_TERRAIN_WINSIZE_NOT_SUPPORTED = -2147205059
    E_TERRAIN_FIELD_TYPE_MISMATCH = -2147219394
    E_TERRAIN_CANNOT_BE_ANCHORED = -2147219393
    E_TERRAIN_ANCHOR_POINTS_NOT_SUPPORTED = -2147219392
    E_TERRAIN_MUST_APPLY_TO_OVERVIEW = -2147219391
    E_TERRAIN_VERSION_NOT_SUPPORTED = -2147219390
    E_TERRAIN_FORMAT_NOT_SUPPORTED = -2147219389
    E_TERRAIN_FILE_WRITE_ERROR = -2147205052
    E_TERRAIN_INVALID_FILE = -2147205051
    E_TERRAIN_WKT_NOT_SUPPORTED = -2147205050

class esriLasAttributeType(Enumeration):
    __slots__ = ['esriLasNone',
                 'esriLasIntensity',
                 'esriLasReturnNumber',
                 'esriLasNumberOfReturns',
                 'esriLasScanDirectionFlag',
                 'esriLasEdgeOfFlightLine',
                 'esriLasClassCode',
                 'esriLasScanAngleRank',
                 'esriLasUserData',
                 'esriLasPointSourceID',
                 'esriLasGpsTime',
                 'esriLasColorRed',
                 'esriLasColorGreen',
                 'esriLasColorBlue',
                 'esriLasColorRGB',
                 'esriLasZ']
    esriLasNone = 0
    esriLasIntensity = 1
    esriLasReturnNumber = 2
    esriLasNumberOfReturns = 4
    esriLasScanDirectionFlag = 8
    esriLasEdgeOfFlightLine = 16
    esriLasClassCode = 32
    esriLasScanAngleRank = 64
    esriLasUserData = 128
    esriLasPointSourceID = 256
    esriLasGpsTime = 512
    esriLasColorRed = 1024
    esriLasColorGreen = 2048
    esriLasColorBlue = 4096
    esriLasColorRGB = 8192
    esriLasZ = 16384

class esriTinPointSelectionMethod(Enumeration):
    __slots__ = ['esriTinPointSelectionRandom',
                 'esriTinPointSelectionZmin',
                 'esriTinPointSelectionZmax',
                 'esriTinPointSelectionZaverage']
    esriTinPointSelectionRandom = 1
    esriTinPointSelectionZmin = 2
    esriTinPointSelectionZmax = 3
    esriTinPointSelectionZaverage = 4

class esriPointToRasterMethod(Enumeration):
    __slots__ = ['esriPointToRasterZmin',
                 'esriPointToRasterZmax',
                 'esriPointToRasterZaverage',
                 'esriPointToRasterIDW',
                 'esriPointToRasterNearest']
    esriPointToRasterZmin = 1
    esriPointToRasterZmax = 2
    esriPointToRasterZaverage = 3
    esriPointToRasterIDW = 4
    esriPointToRasterNearest = 5

class esriLasZSource(Enumeration):
    __slots__ = ['esriLasZSourceZ',
                 'esriLasZSourceIntensity',
                 'esriLasZSourceColorRed',
                 'esriLasZSourceColorGreen',
                 'esriLasZSourceColorBlue',
                 'esriLasZSourceColorRGB']
    esriLasZSourceZ = 0
    esriLasZSourceIntensity = 1
    esriLasZSourceColorRed = 2
    esriLasZSourceColorGreen = 3
    esriLasZSourceColorBlue = 4
    esriLasZSourceColorRGB = 5

class esriPointToRasterVoidFillMethod(Enumeration):
    __slots__ = ['esriPointToRasterVoidFillNoFill',
                 'esriPointToRasterVoidFillSimple',
                 'esriPointToRasterVoidFillInterpolation']
    esriPointToRasterVoidFillNoFill = 1
    esriPointToRasterVoidFillSimple = 2
    esriPointToRasterVoidFillInterpolation = 3

class esriLasPointStatsType(Enumeration):
    __slots__ = ['esriLasPointStatsPointCount',
                 'esriLasPointStatsPulseCount',
                 'esriLasPointStatsRange',
                 'esriLasPointStatsMostFrequent']
    esriLasPointStatsPointCount = 1
    esriLasPointStatsPulseCount = 2
    esriLasPointStatsRange = 4
    esriLasPointStatsMostFrequent = 8

class esriLasDatasetError(Enumeration):
    __slots__ = ['E_LAS_BAD_Z_SOURCE',
                 'E_LAS_DATASET_EXISTS',
                 'E_LAS_FAILED_TO_OVER_WRITE',
                 'E_LAS_FAILED_TO_SAVE',
                 'E_LAS_FAILED_TO_OPEN',
                 'E_LAS_NO_STATISTICS',
                 'E_LAS_FAILED_TO_COPY_FILE',
                 'E_LAS_IN_MEMORY_DATASET',
                 'E_LAS_CLASS_FLAG_NOT_SUPPORTED',
                 'E_LAS_BAD_CLASS_CODE']
    E_LAS_BAD_Z_SOURCE = -2147201024
    E_LAS_DATASET_EXISTS = -2147201023
    E_LAS_FAILED_TO_OVER_WRITE = -2147201022
    E_LAS_FAILED_TO_SAVE = -2147201021
    E_LAS_FAILED_TO_OPEN = -2147201020
    E_LAS_NO_STATISTICS = -2147201019
    E_LAS_FAILED_TO_COPY_FILE = -2147201018
    E_LAS_IN_MEMORY_DATASET = -2147201017
    E_LAS_CLASS_FLAG_NOT_SUPPORTED = -2147201016
    E_LAS_BAD_CLASS_CODE = -2147201015

class esriLasClassFlag(Enumeration):
    __slots__ = ['esriLasClassFlagNone',
                 'esriLasClassFlagSynthetic',
                 'esriLasClassFlagKey',
                 'esriLasClassFlagWithheld']
    esriLasClassFlagNone = 1
    esriLasClassFlagSynthetic = 2
    esriLasClassFlagKey = 4
    esriLasClassFlagWithheld = 8

class esriLasClassFlagEditType(Enumeration):
    __slots__ = ['esriLasClassFlagNoChange',
                 'esriLasClassFlagSet',
                 'esriLasClassFlagClear']
    esriLasClassFlagNoChange = 0
    esriLasClassFlagSet = 1
    esriLasClassFlagClear = 2

class esriCadastralJob(Enumeration):
    __slots__ = ['esriCFJobAll',
                 'esriCFJobActive',
                 'esriCFJobCommitted']
    esriCFJobAll = -1
    esriCFJobActive = 0
    esriCFJobCommitted = 1

class esriCadastralFabricTable(Enumeration):
    __slots__ = ['esriCFTControl',
                 'esriCFTPoints',
                 'esriCFTLines',
                 'esriCFTParcels',
                 'esriCFTPlans',
                 'esriCFTJobs',
                 'esriCFTLinePoints',
                 'esriCFTHistory',
                 'esriCFTAdjustments',
                 'esriCFTVectors',
                 'esriCFTJobObjects',
                 'esriCFTLevels',
                 'esriCFTAccuracy']
    esriCFTControl = 0
    esriCFTPoints = 1
    esriCFTLines = 2
    esriCFTParcels = 3
    esriCFTPlans = 4
    esriCFTJobs = 5
    esriCFTLinePoints = 6
    esriCFTHistory = 7
    esriCFTAdjustments = 8
    esriCFTVectors = 9
    esriCFTJobObjects = 10
    esriCFTLevels = 11
    esriCFTAccuracy = 12

class esriCadastralPacketSetting(Enumeration):
    __slots__ = ['esriCadastralPacketNoSetting',
                 'esriCadastralPacketNeighborsInPacket']
    esriCadastralPacketNoSetting = 0
    esriCadastralPacketNeighborsInPacket = 1

class esriCadastralLineCategory(Enumeration):
    __slots__ = ['esriCadastralLineBoundary',
                 'esriCadastralLineDependent',
                 'esriCadastralLinePreciseConnection',
                 'esriCadastralLineConnection',
                 'esriCadastralLineRadial',
                 'esriCadastralLineRoad',
                 'esriCadastralLineOriginConnection',
                 'esriCadastralLinePartConnection']
    esriCadastralLineBoundary = 0
    esriCadastralLineDependent = 1
    esriCadastralLinePreciseConnection = 2
    esriCadastralLineConnection = 3
    esriCadastralLineRadial = 4
    esriCadastralLineRoad = 5
    esriCadastralLineOriginConnection = 6
    esriCadastralLinePartConnection = 7

class esriCadastralPointCategory(Enumeration):
    __slots__ = ['esriCadastralPointStandard',
                 'esriCadastralPointConstruction',
                 'esriCadastralPointControl',
                 'esriCadastralPointInterpolated',
                 'esriCadastralPointReferenceMark',
                 'esriCadastralPointBenchMark',
                 'esriCadastralPointStation']
    esriCadastralPointStandard = 0
    esriCadastralPointConstruction = 1
    esriCadastralPointControl = 2
    esriCadastralPointInterpolated = 3
    esriCadastralPointReferenceMark = 4
    esriCadastralPointBenchMark = 5
    esriCadastralPointStation = 6

class esriCadastralLineParameters(Enumeration):
    __slots__ = ['esriCadastralLPBearingAndDistance',
                 'esriCadastralLPAngleAndDistance',
                 'esriCadastralLPChordBearingAndDeltaAndRadius',
                 'esriCadastralLPDeltaAndRadius',
                 'esriCadastralLPChordBearingAndChordLengthAndRadius',
                 'esriCadastralLPChordLengthAndRadius',
                 'esriCadastralLPChordBearingAndArcLengthAndRadius',
                 'esriCadastralLPArcLengthAndRadius',
                 'esriCadastralLPChordBearingAndDeltaAndArcLength',
                 'esriCadastralLPDeltaAndArcLength',
                 'esriCadastralLPRadialBearingAndDeltaAndRadius',
                 'esriCadastralLPRadialBearingAndChordLengthAndRadius',
                 'esriCadastralLPRadialBearingAndArcLengthAndRadius',
                 'esriCadastralLPRadialBearingAndDeltaAndArcLength',
                 'esriCadastralLPTangentBearingAndDeltaAndRadius',
                 'esriCadastralLPTangentBearingAndChordLengthAndRadius',
                 'esriCadastralLPTangentBearingAndArcLengthAndRadius',
                 'esriCadastralLPTangentBearingAndDeltaAndArcLength']
    esriCadastralLPBearingAndDistance = 0
    esriCadastralLPAngleAndDistance = 1
    esriCadastralLPChordBearingAndDeltaAndRadius = 2
    esriCadastralLPDeltaAndRadius = 3
    esriCadastralLPChordBearingAndChordLengthAndRadius = 4
    esriCadastralLPChordLengthAndRadius = 5
    esriCadastralLPChordBearingAndArcLengthAndRadius = 6
    esriCadastralLPArcLengthAndRadius = 7
    esriCadastralLPChordBearingAndDeltaAndArcLength = 8
    esriCadastralLPDeltaAndArcLength = 9
    esriCadastralLPRadialBearingAndDeltaAndRadius = 10
    esriCadastralLPRadialBearingAndChordLengthAndRadius = 11
    esriCadastralLPRadialBearingAndArcLengthAndRadius = 12
    esriCadastralLPRadialBearingAndDeltaAndArcLength = 13
    esriCadastralLPTangentBearingAndDeltaAndRadius = 14
    esriCadastralLPTangentBearingAndChordLengthAndRadius = 15
    esriCadastralLPTangentBearingAndArcLengthAndRadius = 16
    esriCadastralLPTangentBearingAndDeltaAndArcLength = 17

class esriCadastralDistanceUnits(Enumeration):
    __slots__ = ['esriCDUMeter',
                 'esriCDUFoot',
                 'esriCDUChain',
                 'esriCDULink',
                 'esriCDURod',
                 'esriCDUUSSurveyFoot',
                 'esriCDUUSSurveyChain',
                 'esriCDUUSSurveyLink',
                 'esriCDUUSSurveyRod']
    esriCDUMeter = 9001
    esriCDUFoot = 9002
    esriCDUChain = 9097
    esriCDULink = 9098
    esriCDURod = 109010
    esriCDUUSSurveyFoot = 9003
    esriCDUUSSurveyChain = 9033
    esriCDUUSSurveyLink = 9034
    esriCDUUSSurveyRod = 109011

class esriCadastralAreaUnits(Enumeration):
    __slots__ = ['esriCAUImperial',
                 'esriCAUMetric',
                 'esriCAUSquareMeter',
                 'esriCAUHectare',
                 'esriCAUAcre',
                 'esriCAUSquareRods',
                 'esriCAURoods',
                 'esriCAUPerches',
                 'esriCAUSquareFoot',
                 'esriCAUSquareUSFoot',
                 'esriCAUQuarterSections',
                 'esriCAUSections']
    esriCAUImperial = 0
    esriCAUMetric = 1
    esriCAUSquareMeter = 2
    esriCAUHectare = 3
    esriCAUAcre = 4
    esriCAUSquareRods = 5
    esriCAURoods = 6
    esriCAUPerches = 7
    esriCAUSquareFoot = 8
    esriCAUSquareUSFoot = 9
    esriCAUQuarterSections = 10
    esriCAUSections = 11

class esriCadastralDensifiedType(Enumeration):
    __slots__ = ['esriCadastralDensifiedNormal',
                 'esriCadastralDensifiedGCS',
                 'esriCadastralDensifiedCurve',
                 'esriCadastralDensifiedLineString']
    esriCadastralDensifiedNormal = 0
    esriCadastralDensifiedGCS = 1
    esriCadastralDensifiedCurve = 2
    esriCadastralDensifiedLineString = 3

class esriCadastralFabricType(Enumeration):
    __slots__ = ['esriCadastralMap',
                 'esriCadastralSurvey']
    esriCadastralMap = 0
    esriCadastralSurvey = 1

class esriParcelAdjustmentType(Enumeration):
    __slots__ = ['esriParcelAdjustmentNone',
                 'esriParcelAdjustmentCompass',
                 'esriParcelAdjustmentTransit',
                 'esriParcelAdjustmentCrandall']
    esriParcelAdjustmentNone = -1
    esriParcelAdjustmentCompass = 0
    esriParcelAdjustmentTransit = 1
    esriParcelAdjustmentCrandall = 2

class esriCadastralPropertySetType(Enumeration):
    __slots__ = ['esriCadastralPropSetUserDefined',
                 'esriCadastralPropSetImporterLoading',
                 'esriCadastralPropSetCoordinateTolerances',
                 'esriCadastralPropSetEditSettings',
                 'esriCadastralPropSetCatalogDataset']
    esriCadastralPropSetUserDefined = 0
    esriCadastralPropSetImporterLoading = 1
    esriCadastralPropSetCoordinateTolerances = 2
    esriCadastralPropSetEditSettings = 3
    esriCadastralPropSetCatalogDataset = 4

class esriCadastralLinePointCategory(Enumeration):
    __slots__ = ['esriCadastralLinePointStandard',
                 'esriCadastralLinePointBreak']
    esriCadastralLinePointStandard = 0
    esriCadastralLinePointBreak = 1

class esriCadastralRegeneratorSetting(Enumeration):
    __slots__ = ['esriCadastralRegenRegenerateGeometries',
                 'esriCadastralRegenRegenerateMissingRadials',
                 'esriCadastralRegenRegenerateMissingPoints',
                 'esriCadastralRegenRemoveOrphanPoints',
                 'esriCadastralRegenRemoveInvalidLinePoints',
                 'esriCadastralRegenSnapLinePoints',
                 'esriCadastralRegenRepairLineSequencing']
    esriCadastralRegenRegenerateGeometries = 1
    esriCadastralRegenRegenerateMissingRadials = 2
    esriCadastralRegenRegenerateMissingPoints = 4
    esriCadastralRegenRemoveOrphanPoints = 8
    esriCadastralRegenRemoveInvalidLinePoints = 16
    esriCadastralRegenSnapLinePoints = 32
    esriCadastralRegenRepairLineSequencing = 64

class enumMessageType(Enumeration):
    __slots__ = ['msgtypeCOMMAND',
                 'msgtypeDATA',
                 'msgtypeRESPONSE',
                 'msgtypeSTATUS']
    msgtypeCOMMAND = 10
    msgtypeDATA = 11
    msgtypeRESPONSE = 12
    msgtypeSTATUS = 13

class enumTemporalOperatorUnits(Enumeration):
    __slots__ = ['enumTemporalOperatorMilliseconds',
                 'enumTemporalOperatorSeconds',
                 'enumTemporalOperatorMinutes',
                 'enumTemporalOperatorHours',
                 'enumTemporalOperatorDays',
                 'enumTemporalOperatorWeeks',
                 'enumTemporalOperatorMonths',
                 'enumTemporalOperatorYears']
    enumTemporalOperatorMilliseconds = 0
    enumTemporalOperatorSeconds = 1
    enumTemporalOperatorMinutes = 2
    enumTemporalOperatorHours = 3
    enumTemporalOperatorDays = 4
    enumTemporalOperatorWeeks = 5
    enumTemporalOperatorMonths = 6
    enumTemporalOperatorYears = 7

class enumTemporalOperatorType(Enumeration):
    __slots__ = ['enumTemporalOperatorDateTime',
                 'enumTemporalOperatorInterval']
    enumTemporalOperatorDateTime = 0
    enumTemporalOperatorInterval = 1

class enumObjectSource(Enumeration):
    __slots__ = ['sourceDynamic',
                 'sourceShapeFile',
                 'sourceLocalGeoDatabase',
                 'sourceSDE']
    sourceDynamic = 0
    sourceShapeFile = 1
    sourceLocalGeoDatabase = 2
    sourceSDE = 3

class enumShapeSource(Enumeration):
    __slots__ = ['shapefromObject',
                 'shapefromObservation']
    shapefromObject = 0
    shapefromObservation = 1

class enumPurgeRule(Enumeration):
    __slots__ = ['enumOldest',
                 'enumKeepLatest']
    enumOldest = 0
    enumKeepLatest = 1

class enumTemporalOrder(Enumeration):
    __slots__ = ['ASCENDING',
                 'DESCENDING']
    ASCENDING = 0
    DESCENDING = 1

class enumTemporalRelation(Enumeration):
    __slots__ = ['enumTemporalRelationIntersects',
                 'enumTemporalRelationContains']
    enumTemporalRelationIntersects = 0
    enumTemporalRelationContains = 1

class enumTemporalConversion(Enumeration):
    __slots__ = ['enumTemporalConversionNone',
                 'enumTemporalConversionToString',
                 'enumTemporalConversionToOLEDate']
    enumTemporalConversionNone = 0
    enumTemporalConversionToString = 1
    enumTemporalConversionToOLEDate = 2

class enumTemporalFeatureType(Enumeration):
    __slots__ = ['enumTimeStamp']
    enumTimeStamp = 0

class esriTxFeatureClassCachingMode(Enumeration):
    __slots__ = ['esriTFCMNone',
                 'esriTFCMCacheAll']
    esriTFCMNone = 0
    esriTFCMCacheAll = 3

class enumTemporalSource(Enumeration):
    __slots__ = ['enumTemporalSourceField']
    enumTemporalSourceField = 0

class enumTemporalCursorType(Enumeration):
    __slots__ = ['enumSelect',
                 'enumSelect_OID',
                 'enumCount',
                 'enumUpdate',
                 'enumInsert',
                 'enumSearch']
    enumSelect = 0
    enumSelect_OID = 1
    enumCount = 2
    enumUpdate = 3
    enumInsert = 4
    enumSearch = 5

# Records
class RGB32(_esriGeoDatabaseExtensions.RGB32):

    def __init__(self, *args, **kw):
        super(RGB32, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    Red = property(_esriGeoDatabaseExtensions.RGB32.get_Red, _esriGeoDatabaseExtensions.RGB32.put_Red, None, u'long')
    Green = property(_esriGeoDatabaseExtensions.RGB32.get_Green, _esriGeoDatabaseExtensions.RGB32.put_Green, None, u'long')
    Blue = property(_esriGeoDatabaseExtensions.RGB32.get_Blue, _esriGeoDatabaseExtensions.RGB32.put_Blue, None, u'long')
_RecordMap[u'RGB32'] = RGB32

