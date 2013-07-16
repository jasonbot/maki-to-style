'Type library'
__all__ = ['IProtectNamesDataSourcesNetCDF', 'IMDDatasetView', 'IMDWorkspace', 'IMDRasterDatasetView', 'IMDTableView', 'IMDFeatureClassView', 'INetCDFWorkspace', 'NetCDFWorkspaceFactory', 'NetCDFWorkspace', 'NetCDFRasterDatasetName', 'NetCDFTableName', 'NetCDFFeatureClassName', 'IID_IProtectNamesDataSourcesNetCDF', 'IID_IMDDatasetView', 'IID_IMDWorkspace', 'IID_IMDRasterDatasetView', 'IID_IMDTableView', 'IID_IMDFeatureClassView', 'IID_INetCDFWorkspace', 'CLSID_NetCDFWorkspaceFactory', 'CLSID_NetCDFWorkspace', 'CLSID_NetCDFRasterDatasetName', 'CLSID_NetCDFTableName', 'CLSID_NetCDFFeatureClassName', 'esriNetCDFError']
from cartocomutils import _esriDataSourcesNetCDF
from cartocomutils._esriDataSourcesNetCDF import NetCDFWorkspaceFactory, NetCDFWorkspace, NetCDFRasterDatasetName, NetCDFTableName, NetCDFFeatureClassName
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IProtectNamesDataSourcesNetCDF(_esriDataSourcesNetCDF.IProtectNamesDataSourcesNetCDF):
    _IID = uuid.UUID('00e0f03e-d94d-4cb0-a711-7f7c59c51196')
    def Variable(self):
        '''Method IProtectNamesDataSourcesNetCDF.Variable'''
        return super(IProtectNamesDataSourcesNetCDF, self).Variable()

class IMDDatasetView(_esriDataSourcesNetCDF.IMDDatasetView):
    _IID = uuid.UUID('4656178f-0eda-4446-9d51-900e96efd27c')
    def SelectDimensionByValue(self, dim, vValue):
        '''Method IMDDatasetView.SelectDimensionByValue

           INPUTS
            dim                 : BSTR
            vValue              : VARIANT'''
        return super(IMDDatasetView, self).SelectDimensionByValue(dim, vValue)
    def SelectDimensionByIndex(self, dim, index):
        '''Method IMDDatasetView.SelectDimensionByIndex

           INPUTS
            dim                 : BSTR
            index               : long'''
        return super(IMDDatasetView, self).SelectDimensionByIndex(dim, index)
    def GetDimensionValue(self, dim):
        '''Method IMDDatasetView.GetDimensionValue

           INPUT
            dim                 : BSTR

           OUTPUT
            pVal                : VARIANT*'''
        return super(IMDDatasetView, self).GetDimensionValue(dim)
    def GetDimensionIndex(self, dim):
        '''Method IMDDatasetView.GetDimensionIndex

           INPUT
            dim                 : BSTR

           OUTPUT
            pVal                : long*'''
        return super(IMDDatasetView, self).GetDimensionIndex(dim)
    def GetSelectedDimensions(self):
        '''Method IMDDatasetView.GetSelectedDimensions

           OUTPUT
            ppNames             : IStringArray**'''
        return super(IMDDatasetView, self).GetSelectedDimensions()
    def GetSelectedDimensionValues(self):
        '''Method IMDDatasetView.GetSelectedDimensionValues

           OUTPUT
            ppValues            : IVariantArray**'''
        return super(IMDDatasetView, self).GetSelectedDimensionValues()
    def GetSelectedDimensionIndices(self):
        '''Method IMDDatasetView.GetSelectedDimensionIndices

           OUTPUT
            ppIndices           : ILongArray**'''
        return super(IMDDatasetView, self).GetSelectedDimensionIndices()
    def ClearSelectedDimensions(self):
        '''Method IMDDatasetView.ClearSelectedDimensions'''
        return super(IMDDatasetView, self).ClearSelectedDimensions()
    def GetDimensions(self):
        '''Method IMDDatasetView.GetDimensions

           OUTPUT
            ppDims              : IStringArray**'''
        return super(IMDDatasetView, self).GetDimensions()

class IMDWorkspace(_esriDataSourcesNetCDF.IMDWorkspace):
    _IID = uuid.UUID('88b7b494-1c1d-4b6c-a1db-28900afa96ec')
    def CreateView(self, viewName, pView):
        '''Method IMDWorkspace.CreateView

           INPUTS
            viewName            : BSTR
            pView               : IMDDatasetView*

           OUTPUT
            ppOut               : IDataset**'''
        return super(IMDWorkspace, self).CreateView(viewName, pView)

class IMDRasterDatasetView(_esriDataSourcesNetCDF.IMDRasterDatasetView):
    _IID = uuid.UUID('08cebfb9-db3e-433b-bf80-84adf3424fb0')

    def __init__(self, *args, **kw):
        super(IMDRasterDatasetView, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_XDimension(self):
        '''Method IMDRasterDatasetView.get_XDimension

           OUTPUT
            pXDim               : BSTR*'''
        return super(IMDRasterDatasetView, self).get_XDimension()
    def put_XDimension(self, pXDim):
        '''Method IMDRasterDatasetView.put_XDimension

           INPUT
            pXDim               : BSTR'''
        return super(IMDRasterDatasetView, self).put_XDimension(pXDim)
    def get_YDimension(self):
        '''Method IMDRasterDatasetView.get_YDimension

           OUTPUT
            pYDim               : BSTR*'''
        return super(IMDRasterDatasetView, self).get_YDimension()
    def put_YDimension(self, pYDim):
        '''Method IMDRasterDatasetView.put_YDimension

           INPUT
            pYDim               : BSTR'''
        return super(IMDRasterDatasetView, self).put_YDimension(pYDim)
    def get_BandDimension(self):
        '''Method IMDRasterDatasetView.get_BandDimension

           OUTPUT
            pBandDim            : BSTR*'''
        return super(IMDRasterDatasetView, self).get_BandDimension()
    def put_BandDimension(self, pBandDim):
        '''Method IMDRasterDatasetView.put_BandDimension

           INPUT
            pBandDim            : BSTR'''
        return super(IMDRasterDatasetView, self).put_BandDimension(pBandDim)
    def get_Variable(self):
        '''Method IMDRasterDatasetView.get_Variable

           OUTPUT
            pVar                : BSTR*'''
        return super(IMDRasterDatasetView, self).get_Variable()
    def put_Variable(self, pVar):
        '''Method IMDRasterDatasetView.put_Variable

           INPUT
            pVar                : BSTR'''
        return super(IMDRasterDatasetView, self).put_Variable(pVar)
    BandDimension = property(get_BandDimension, put_BandDimension, None)
    Variable = property(get_Variable, put_Variable, None)
    XDimension = property(get_XDimension, put_XDimension, None)
    YDimension = property(get_YDimension, put_YDimension, None)

class IMDTableView(_esriDataSourcesNetCDF.IMDTableView):
    _IID = uuid.UUID('6c4f3247-039e-4d7b-a815-df16a04b9827')

    def __init__(self, *args, **kw):
        super(IMDTableView, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_VariableList(self):
        '''Method IMDTableView.get_VariableList

           OUTPUT
            ppVars              : IStringArray**'''
        return super(IMDTableView, self).get_VariableList()
    def put_VariableList(self, ppVars):
        '''Method IMDTableView.put_VariableList

           INPUT
            ppVars              : IStringArray*'''
        return super(IMDTableView, self).put_VariableList(ppVars)
    def get_DimensionList(self):
        '''Method IMDTableView.get_DimensionList

           OUTPUT
            ppDims              : IStringArray**'''
        return super(IMDTableView, self).get_DimensionList()
    def put_DimensionList(self, ppDims):
        '''Method IMDTableView.put_DimensionList

           INPUT
            ppDims              : IStringArray*'''
        return super(IMDTableView, self).put_DimensionList(ppDims)
    DimensionList = property(get_DimensionList, put_DimensionList, None)
    VariableList = property(get_VariableList, put_VariableList, None)

class IMDFeatureClassView(_esriDataSourcesNetCDF.IMDFeatureClassView):
    _IID = uuid.UUID('f065307e-3adf-4b57-b59d-4ba1465bb40c')

    def __init__(self, *args, **kw):
        super(IMDFeatureClassView, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_VariableList(self):
        '''Method IMDFeatureClassView.get_VariableList

           OUTPUT
            ppVars              : IStringArray**'''
        return super(IMDFeatureClassView, self).get_VariableList()
    def put_VariableList(self, ppVars):
        '''Method IMDFeatureClassView.put_VariableList

           INPUT
            ppVars              : IStringArray*'''
        return super(IMDFeatureClassView, self).put_VariableList(ppVars)
    def get_XDimension(self):
        '''Method IMDFeatureClassView.get_XDimension

           OUTPUT
            pXDim               : BSTR*'''
        return super(IMDFeatureClassView, self).get_XDimension()
    def put_XDimension(self, pXDim):
        '''Method IMDFeatureClassView.put_XDimension

           INPUT
            pXDim               : BSTR'''
        return super(IMDFeatureClassView, self).put_XDimension(pXDim)
    def get_YDimension(self):
        '''Method IMDFeatureClassView.get_YDimension

           OUTPUT
            pYDim               : BSTR*'''
        return super(IMDFeatureClassView, self).get_YDimension()
    def put_YDimension(self, pYDim):
        '''Method IMDFeatureClassView.put_YDimension

           INPUT
            pYDim               : BSTR'''
        return super(IMDFeatureClassView, self).put_YDimension(pYDim)
    def get_RowDimensionList(self):
        '''Method IMDFeatureClassView.get_RowDimensionList

           OUTPUT
            ppRowDims           : IStringArray**'''
        return super(IMDFeatureClassView, self).get_RowDimensionList()
    def put_RowDimensionList(self, ppRowDims):
        '''Method IMDFeatureClassView.put_RowDimensionList

           INPUT
            ppRowDims           : IStringArray*'''
        return super(IMDFeatureClassView, self).put_RowDimensionList(ppRowDims)
    def get_ZItem(self):
        '''Method IMDFeatureClassView.get_ZItem

           OUTPUT
            pZItem              : BSTR*'''
        return super(IMDFeatureClassView, self).get_ZItem()
    def put_ZItem(self, pZItem):
        '''Method IMDFeatureClassView.put_ZItem

           INPUT
            pZItem              : BSTR'''
        return super(IMDFeatureClassView, self).put_ZItem(pZItem)
    def get_MItem(self):
        '''Method IMDFeatureClassView.get_MItem

           OUTPUT
            pMItem              : BSTR*'''
        return super(IMDFeatureClassView, self).get_MItem()
    def put_MItem(self, pMItem):
        '''Method IMDFeatureClassView.put_MItem

           INPUT
            pMItem              : BSTR'''
        return super(IMDFeatureClassView, self).put_MItem(pMItem)
    MItem = property(get_MItem, put_MItem, None)
    RowDimensionList = property(get_RowDimensionList, put_RowDimensionList, None)
    VariableList = property(get_VariableList, put_VariableList, None)
    XDimension = property(get_XDimension, put_XDimension, None)
    YDimension = property(get_YDimension, put_YDimension, None)
    ZItem = property(get_ZItem, put_ZItem, None)

class INetCDFWorkspace(_esriDataSourcesNetCDF.INetCDFWorkspace):
    _IID = uuid.UUID('2d289ea0-e56e-44e9-bdb7-1bc829222cc3')
    def GetVariables(self):
        '''Method INetCDFWorkspace.GetVariables

           OUTPUT
            ppOut               : IStringArray**'''
        return super(INetCDFWorkspace, self).GetVariables()
    def GetDimensions(self):
        '''Method INetCDFWorkspace.GetDimensions

           OUTPUT
            ppOut               : IStringArray**'''
        return super(INetCDFWorkspace, self).GetDimensions()
    def GetAttributeNames(self, varName):
        '''Method INetCDFWorkspace.GetAttributeNames

           INPUT
            varName             : BSTR

           OUTPUT
            ppAttNames          : IStringArray**'''
        return super(INetCDFWorkspace, self).GetAttributeNames(varName)
    def GetDimensionSize(self, dimName):
        '''Method INetCDFWorkspace.GetDimensionSize

           INPUT
            dimName             : BSTR

           OUTPUT
            dimSize             : long*'''
        return super(INetCDFWorkspace, self).GetDimensionSize(dimName)
    def GetDimensionsByVariable(self, varName):
        '''Method INetCDFWorkspace.GetDimensionsByVariable

           INPUT
            varName             : BSTR

           OUTPUT
            ppOut               : IStringArray**'''
        return super(INetCDFWorkspace, self).GetDimensionsByVariable(varName)
    def GetVariablesByDimension(self, dimName):
        '''Method INetCDFWorkspace.GetVariablesByDimension

           INPUT
            dimName             : BSTR

           OUTPUT
            ppOut               : IStringArray**'''
        return super(INetCDFWorkspace, self).GetVariablesByDimension(dimName)
    def GetDimensionValue(self, dimName, index):
        '''Method INetCDFWorkspace.GetDimensionValue

           INPUTS
            dimName             : BSTR
            index               : long

           OUTPUT
            vValue              : VARIANT*'''
        return super(INetCDFWorkspace, self).GetDimensionValue(dimName, index)
    def GetDimensionIndex(self, dimName, vValue):
        '''Method INetCDFWorkspace.GetDimensionIndex

           INPUTS
            dimName             : BSTR
            vValue              : VARIANT

           OUTPUT
            index               : long*'''
        return super(INetCDFWorkspace, self).GetDimensionIndex(dimName, vValue)
    def GetAttributeValue(self, varName, attName, valueIndex):
        '''Method INetCDFWorkspace.GetAttributeValue

           INPUTS
            varName             : BSTR
            attName             : BSTR
            valueIndex          : long

           OUTPUT
            pValue              : VARIANT*'''
        return super(INetCDFWorkspace, self).GetAttributeValue(varName, attName, valueIndex)
    def GetDimensionValues(self, dimName):
        '''Method INetCDFWorkspace.GetDimensionValues

           INPUT
            dimName             : BSTR

           OUTPUT
            ppValues            : IVariantArray**'''
        return super(INetCDFWorkspace, self).GetDimensionValues(dimName)
    def GetSpatialReference(self, varName, xDim, yDim):
        '''Method INetCDFWorkspace.GetSpatialReference

           INPUTS
            varName             : BSTR
            xDim                : BSTR
            yDim                : BSTR

           OUTPUT
            ppSpatRef           : ISpatialReference**'''
        return super(INetCDFWorkspace, self).GetSpatialReference(varName, xDim, yDim)
    def GetFieldType(self, name):
        '''Method INetCDFWorkspace.GetFieldType

           INPUT
            name                : BSTR

           OUTPUT
            fieldType           : esriFieldType*'''
        return super(INetCDFWorkspace, self).GetFieldType(name)
    def GetValueFromIndex(self, index, name):
        '''Method INetCDFWorkspace.GetValueFromIndex

           INPUTS
            index               : long
            name                : BSTR

           OUTPUT
            pVal                : VARIANT*'''
        return super(INetCDFWorkspace, self).GetValueFromIndex(index, name)
    def GetIndexFromValue(self, name, value):
        '''Method INetCDFWorkspace.GetIndexFromValue

           INPUTS
            name                : BSTR
            value               : VARIANT

           OUTPUT
            index               : long*'''
        return super(INetCDFWorkspace, self).GetIndexFromValue(name, value)


# IIDs
IID_IProtectNamesDataSourcesNetCDF = IProtectNamesDataSourcesNetCDF._IID
IID_IMDDatasetView = IMDDatasetView._IID
IID_IMDWorkspace = IMDWorkspace._IID
IID_IMDRasterDatasetView = IMDRasterDatasetView._IID
IID_IMDTableView = IMDTableView._IID
IID_IMDFeatureClassView = IMDFeatureClassView._IID
IID_INetCDFWorkspace = INetCDFWorkspace._IID
_IIDMap[IID_IProtectNamesDataSourcesNetCDF] = IProtectNamesDataSourcesNetCDF
_IIDMap[IID_IMDDatasetView] = IMDDatasetView
_IIDMap[IID_IMDWorkspace] = IMDWorkspace
_IIDMap[IID_IMDRasterDatasetView] = IMDRasterDatasetView
_IIDMap[IID_IMDTableView] = IMDTableView
_IIDMap[IID_IMDFeatureClassView] = IMDFeatureClassView
_IIDMap[IID_INetCDFWorkspace] = INetCDFWorkspace


# CLSIDs
CLSID_NetCDFWorkspaceFactory = uuid.UUID('df61a9e1-b8e2-498f-bde5-98de42e801f9')
CLSID_NetCDFWorkspace = uuid.UUID('434116cc-611e-44be-a194-e4594c2fc926')
CLSID_NetCDFRasterDatasetName = uuid.UUID('8cb4aa2b-58ce-438f-8cd8-f5f0bef41aaf')
CLSID_NetCDFTableName = uuid.UUID('2d597a23-a989-43c1-9b1b-19e75bbfb78f')
CLSID_NetCDFFeatureClassName = uuid.UUID('ee5ef168-7b62-4ed5-89bb-ff73d390af93')

# Enumerations
class esriNetCDFError(Enumeration):
    __slots__ = ['E_NETCDF_FILE_NOT_FOUND',
                 'E_NETCDF_FILE_INVALID_EXTENSION',
                 'E_NETCDF_RENDERER_INVALID_BAND_INDEX',
                 'E_NETCDF_FILE_FAILED_TO_RENAME',
                 'E_NETCDF_FILE_FAILED_TO_COPY',
                 'E_NETCDF_ACCESS_IS_DENIED',
                 'E_NETCDF_DATASET_EXIST',
                 'E_NETCDF_UNKNOWN_ERROR']
    E_NETCDF_FILE_NOT_FOUND = -2147217407
    E_NETCDF_FILE_INVALID_EXTENSION = -2147217406
    E_NETCDF_RENDERER_INVALID_BAND_INDEX = -2147217405
    E_NETCDF_FILE_FAILED_TO_RENAME = -2147217404
    E_NETCDF_FILE_FAILED_TO_COPY = -2147217403
    E_NETCDF_ACCESS_IS_DENIED = -2147217402
    E_NETCDF_DATASET_EXIST = -2147217401
    E_NETCDF_UNKNOWN_ERROR = -2147217408

