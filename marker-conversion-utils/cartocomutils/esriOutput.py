'Type library'
__all__ = ['IFontMap', 'IFontMap2', 'IFontMapCollection', 'IFontMapEnvironment', 'IExporter', 'IExporter2', 'IExporterPriority', 'IOutputCleanup', 'IWorldFileSettings', 'IWorldFileSettings2', 'IStepProgressorSetup', 'ITrackCancelSetup', 'ISettingsInRegistry', 'IExportColorspaceSettings', 'IPrintAndExportPageOptions', 'IEmfExporter', 'ISpotPlate', 'ISpotPlateCollection', 'IColorCorrection', 'IPSDriver', 'IPSDriver2', 'IPsExporter', 'IOutputPageOptionsAdmin', 'IPDFDriver', 'IAIDriver', 'IAIExporter', 'IPaper', 'IPaper2', 'IPrinter', 'IPrinterMPage', 'IPsPrinter', 'IExport', 'IExportImage', 'IExportBMP', 'IExportJPEG', 'IExportPNG', 'IExportTIFF', 'IExportGIF', 'IExportVectorOptions', 'IExportVectorOptionsEx', 'IExportEMF', 'IExportPS', 'IExportPS2', 'IExportPDF', 'IExportPDF2', 'IExportPDF3', 'IExportPagesMultipleFile', 'IExportAI', 'IExportAI2', 'IExportSVG', 'IExportPDFPasswordSecurity', 'IDibExporter', 'IJpegExporter', 'IBmpExporter', 'ITiffExporter', 'FontMap', 'FontMapCollection', 'FontMapEnvironment', 'PrintAndExportPageOptions', 'EmfExporter', 'PSDriver', 'PsExporter', 'SpotPlate', 'PDFDriver', 'PDFExporter', 'AIDriver', 'AIExporter', 'Paper', 'EmfPrinter', 'PsPrinter', 'ExportBMP', 'ExportJPEG', 'ExportPNG', 'ExportTIFF', 'ExportGIF', 'ExportEMF', 'ExportPS', 'ExportPDF', 'ExportAI', 'ExportSVG', 'DibExporter', 'JpegExporter', 'TiffExporter', 'IID_IFontMap', 'IID_IFontMap2', 'IID_IFontMapCollection', 'IID_IFontMapEnvironment', 'IID_IExporter', 'IID_IExporter2', 'IID_IExporterPriority', 'IID_IOutputCleanup', 'IID_IWorldFileSettings', 'IID_IWorldFileSettings2', 'IID_IStepProgressorSetup', 'IID_ITrackCancelSetup', 'IID_ISettingsInRegistry', 'IID_IExportColorspaceSettings', 'IID_IPrintAndExportPageOptions', 'IID_IEmfExporter', 'IID_ISpotPlate', 'IID_ISpotPlateCollection', 'IID_IColorCorrection', 'IID_IPSDriver', 'IID_IPSDriver2', 'IID_IPsExporter', 'IID_IOutputPageOptionsAdmin', 'IID_IPDFDriver', 'IID_IAIDriver', 'IID_IAIExporter', 'IID_IPaper', 'IID_IPaper2', 'IID_IPrinter', 'IID_IPrinterMPage', 'IID_IPsPrinter', 'IID_IExport', 'IID_IExportImage', 'IID_IExportBMP', 'IID_IExportJPEG', 'IID_IExportPNG', 'IID_IExportTIFF', 'IID_IExportGIF', 'IID_IExportVectorOptions', 'IID_IExportVectorOptionsEx', 'IID_IExportEMF', 'IID_IExportPS', 'IID_IExportPS2', 'IID_IExportPDF', 'IID_IExportPDF2', 'IID_IExportPDF3', 'IID_IExportPagesMultipleFile', 'IID_IExportAI', 'IID_IExportAI2', 'IID_IExportSVG', 'IID_IExportPDFPasswordSecurity', 'IID_IDibExporter', 'IID_IJpegExporter', 'IID_IBmpExporter', 'IID_ITiffExporter', 'CLSID_FontMap', 'CLSID_FontMapCollection', 'CLSID_FontMapEnvironment', 'CLSID_PrintAndExportPageOptions', 'CLSID_EmfExporter', 'CLSID_PSDriver', 'CLSID_PsExporter', 'CLSID_SpotPlate', 'CLSID_PDFDriver', 'CLSID_PDFExporter', 'CLSID_AIDriver', 'CLSID_AIExporter', 'CLSID_Paper', 'CLSID_EmfPrinter', 'CLSID_PsPrinter', 'CLSID_ExportBMP', 'CLSID_ExportJPEG', 'CLSID_ExportPNG', 'CLSID_ExportTIFF', 'CLSID_ExportGIF', 'CLSID_ExportEMF', 'CLSID_ExportPS', 'CLSID_ExportPDF', 'CLSID_ExportAI', 'CLSID_ExportSVG', 'CLSID_DibExporter', 'CLSID_JpegExporter', 'CLSID_TiffExporter', 'esriExportErrorReturnCodes', 'esriOutputErrorReturnCodes', 'esriPDFExtensionErrorCodes', 'esriExportColorspace', 'esriOutputSelection', 'esriPSDriverEmulsion', 'esriPSDriverImage', 'esriPSDriverImageCompression', 'esriPSDriverPSLanguageLevel', 'esriPSDriverHalfTone', 'esriPSDriverSeparates', 'esriPSDriverMarks', 'esriColorCorrectionDataType', 'esriCMYKIndex', 'esriAIDriverOptions', 'esriExportImageType', 'esriTIFFCompression', 'esriGIFCompression', 'esriExportPSEmulsion', 'esriExportPSImage', 'esriExportPSLanguageLevel', 'esriExportImageCompression', 'esriExportPDFLayerOptions', 'esriExportMultipleFiles', 'esriPDFExtensionSecurityEncryptionOption', 'esriPDFExtensionSecurityEncryptionMethod', 'esriPDFExtensionSecurityPermission']
from cartocomutils import _esriOutput
from cartocomutils._esriOutput import FontMap, FontMapCollection, FontMapEnvironment, PrintAndExportPageOptions, EmfExporter, PSDriver, PsExporter, SpotPlate, PDFDriver, PDFExporter, AIDriver, AIExporter, Paper, EmfPrinter, PsPrinter, ExportBMP, ExportJPEG, ExportPNG, ExportTIFF, ExportGIF, ExportEMF, ExportPS, ExportPDF, ExportAI, ExportSVG, DibExporter, JpegExporter, TiffExporter
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IFontMap(_esriOutput.IFontMap):
    _IID = uuid.UUID('7539e7dc-2d89-11d3-9fc6-00c04f6bc8dd')

    def __init__(self, *args, **kw):
        super(IFontMap, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_TrueTypeFont(self):
        '''Method IFontMap.get_TrueTypeFont

           OUTPUT
            font                : BSTR*'''
        return super(IFontMap, self).get_TrueTypeFont()
    def get_MappedFont(self):
        '''Method IFontMap.get_MappedFont

           OUTPUT
            font                : BSTR*'''
        return super(IFontMap, self).get_MappedFont()
    def put_Mapping(self, TrueTypeFont, _arg2):
        '''Method IFontMap.put_Mapping

           INPUTS
            TrueTypeFont        : BSTR
            _arg2               : BSTR'''
        return super(IFontMap, self).put_Mapping(TrueTypeFont, _arg2)
    MappedFont = property(get_MappedFont, None, None)
    Mapping = property(None, put_Mapping, None)
    TrueTypeFont = property(get_TrueTypeFont, None, None)

class IFontMap2(_esriOutput.IFontMap2):
    _IID = uuid.UUID('e4f70d20-046d-490d-a5e3-066e681ab5b1')

    def __init__(self, *args, **kw):
        super(IFontMap2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def SetMapping(self, TrueTypeFont, MappedFont):
        '''Method IFontMap2.SetMapping

           INPUTS
            TrueTypeFont        : BSTR
            MappedFont          : BSTR'''
        return super(IFontMap2, self).SetMapping(TrueTypeFont, MappedFont)
    def get_TrueTypeFont(self):
        '''Method IFontMap2.get_TrueTypeFont

           OUTPUT
            font                : BSTR*'''
        return super(IFontMap2, self).get_TrueTypeFont()
    def get_MappedFont(self):
        '''Method IFontMap2.get_MappedFont

           OUTPUT
            font                : BSTR*'''
        return super(IFontMap2, self).get_MappedFont()
    def put_Mapping(self, TrueTypeFont, _arg2):
        '''Method IFontMap2.put_Mapping

           INPUTS
            TrueTypeFont        : BSTR
            _arg2               : BSTR'''
        return super(IFontMap2, self).put_Mapping(TrueTypeFont, _arg2)
    MappedFont = property(get_MappedFont, None, None)
    Mapping = property(None, put_Mapping, None)
    TrueTypeFont = property(get_TrueTypeFont, None, None)

class IFontMapCollection(_esriOutput.IFontMapCollection):
    _IID = uuid.UUID('7539e7dd-2d89-11d3-9fc6-00c04f6bc8dd')
    def get_Count(self):
        '''Method IFontMapCollection.get_Count

           OUTPUT
            Count               : long*'''
        return super(IFontMapCollection, self).get_Count()
    def get_FontMap(self, index):
        '''Method IFontMapCollection.get_FontMap

           INPUT
            index               : long

           OUTPUT
            FontMap             : IFontMap**'''
        return super(IFontMapCollection, self).get_FontMap(index)
    def Add(self, FontMap):
        '''Method IFontMapCollection.Add

           INPUT
            FontMap             : IFontMap*'''
        return super(IFontMapCollection, self).Add(FontMap)
    def Insert(self, index, FontMap):
        '''Method IFontMapCollection.Insert

           INPUTS
            index               : long
            FontMap             : IFontMap*'''
        return super(IFontMapCollection, self).Insert(index, FontMap)
    def Remove(self, index):
        '''Method IFontMapCollection.Remove

           INPUT
            index               : long'''
        return super(IFontMapCollection, self).Remove(index)
    def RemoveAll(self):
        '''Method IFontMapCollection.RemoveAll'''
        return super(IFontMapCollection, self).RemoveAll()
    Count = property(get_Count, None, None)
    FontMap = IndexProperty(get_FontMap, None)

class IFontMapEnvironment(_esriOutput.IFontMapEnvironment):
    _IID = uuid.UUID('9ecb85b2-6caa-11d3-b685-0080c8ea4fd5')

    def __init__(self, *args, **kw):
        super(IFontMapEnvironment, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_SaveMappings(self, SaveMappings):
        '''Method IFontMapEnvironment.put_SaveMappings

           INPUT
            SaveMappings        : VARIANT_BOOL'''
        return super(IFontMapEnvironment, self).put_SaveMappings(SaveMappings)
    def get_SaveMappings(self):
        '''Method IFontMapEnvironment.get_SaveMappings

           OUTPUT
            SaveMappings        : VARIANT_BOOL*'''
        return super(IFontMapEnvironment, self).get_SaveMappings()
    def get_FontMapCollection(self):
        '''Method IFontMapEnvironment.get_FontMapCollection

           OUTPUT
            FontMapCollection   : IFontMapCollection**'''
        return super(IFontMapEnvironment, self).get_FontMapCollection()
    def put_DefaultMappingsChoices(self, defaultMappingChoices):
        '''Method IFontMapEnvironment.put_DefaultMappingsChoices

           INPUT
            defaultMappingChoices: VARIANT'''
        return super(IFontMapEnvironment, self).put_DefaultMappingsChoices(defaultMappingChoices)
    def get_DefaultMappingsChoices(self):
        '''Method IFontMapEnvironment.get_DefaultMappingsChoices

           OUTPUT
            defaultMappingChoices: VARIANT*'''
        return super(IFontMapEnvironment, self).get_DefaultMappingsChoices()
    def put_DefaultMapping(self, DefaultMapping):
        '''Method IFontMapEnvironment.put_DefaultMapping

           INPUT
            DefaultMapping      : BSTR'''
        return super(IFontMapEnvironment, self).put_DefaultMapping(DefaultMapping)
    def get_DefaultMapping(self):
        '''Method IFontMapEnvironment.get_DefaultMapping

           OUTPUT
            DefaultMapping      : BSTR*'''
        return super(IFontMapEnvironment, self).get_DefaultMapping()
    def put_ApplyDefaultMappingDesc(self, ApplyDefaultMappingDesc):
        '''Method IFontMapEnvironment.put_ApplyDefaultMappingDesc

           INPUT
            ApplyDefaultMappingDesc: BSTR'''
        return super(IFontMapEnvironment, self).put_ApplyDefaultMappingDesc(ApplyDefaultMappingDesc)
    def get_ApplyDefaultMappingDesc(self):
        '''Method IFontMapEnvironment.get_ApplyDefaultMappingDesc

           OUTPUT
            ApplyDefaultMappingDesc: BSTR*'''
        return super(IFontMapEnvironment, self).get_ApplyDefaultMappingDesc()
    ApplyDefaultMappingDesc = property(get_ApplyDefaultMappingDesc, put_ApplyDefaultMappingDesc, None)
    DefaultMapping = property(get_DefaultMapping, put_DefaultMapping, None)
    DefaultMappingsChoices = property(get_DefaultMappingsChoices, put_DefaultMappingsChoices, None)
    FontMapCollection = property(get_FontMapCollection, None, None)
    SaveMappings = property(get_SaveMappings, put_SaveMappings, None)

class IExporter(_esriOutput.IExporter):
    _IID = uuid.UUID('7d4881e2-57c6-11d1-945e-080009eebecb')

    def __init__(self, *args, **kw):
        super(IExporter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IExporter.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IExporter, self).get_Name()
    def get_Filter(self):
        '''Method IExporter.get_Filter

           OUTPUT
            Filter              : BSTR*'''
        return super(IExporter, self).get_Filter()
    def get_FileExtension(self):
        '''Method IExporter.get_FileExtension

           OUTPUT
            Name                : BSTR*'''
        return super(IExporter, self).get_FileExtension()
    def put_PixelBounds(self, PixelBounds):
        '''Method IExporter.put_PixelBounds

           INPUT
            PixelBounds         : IEnvelope*'''
        return super(IExporter, self).put_PixelBounds(PixelBounds)
    def get_PixelBounds(self):
        '''Method IExporter.get_PixelBounds

           OUTPUT
            PixelBounds         : IEnvelope**'''
        return super(IExporter, self).get_PixelBounds()
    def put_ExportFileName(self, fileName):
        '''Method IExporter.put_ExportFileName

           INPUT
            fileName            : BSTR'''
        return super(IExporter, self).put_ExportFileName(fileName)
    def get_ExportFileName(self):
        '''Method IExporter.get_ExportFileName

           OUTPUT
            fileName            : BSTR*'''
        return super(IExporter, self).get_ExportFileName()
    def get_Resolution(self):
        '''Method IExporter.get_Resolution

           OUTPUT
            res                 : short*'''
        return super(IExporter, self).get_Resolution()
    def put_Resolution(self, res):
        '''Method IExporter.put_Resolution

           INPUT
            res                 : short'''
        return super(IExporter, self).put_Resolution(res)
    def get_ClipToGraphicExtent(self):
        '''Method IExporter.get_ClipToGraphicExtent

           OUTPUT
            clipToGraphicsExtent: VARIANT_BOOL*'''
        return super(IExporter, self).get_ClipToGraphicExtent()
    def put_ClipToGraphicExtent(self, clipToGraphicsExtent):
        '''Method IExporter.put_ClipToGraphicExtent

           INPUT
            clipToGraphicsExtent: VARIANT_BOOL'''
        return super(IExporter, self).put_ClipToGraphicExtent(clipToGraphicsExtent)
    def StartExporting(self):
        '''Method IExporter.StartExporting

           OUTPUT
            hDC                 : OLE_HANDLE*'''
        return super(IExporter, self).StartExporting()
    def FinishExporting(self):
        '''Method IExporter.FinishExporting'''
        return super(IExporter, self).FinishExporting()
    ClipToGraphicExtent = property(get_ClipToGraphicExtent, put_ClipToGraphicExtent, None)
    ExportFileName = property(get_ExportFileName, put_ExportFileName, None)
    FileExtension = property(get_FileExtension, None, None)
    Filter = property(get_Filter, None, None)
    Name = property(get_Name, None, None)
    PixelBounds = property(get_PixelBounds, put_PixelBounds, None)
    Resolution = property(get_Resolution, put_Resolution, None)

class IExporter2(_esriOutput.IExporter2):
    _IID = uuid.UUID('b87ad35e-1242-4c30-b67f-ff3cfa2f1928')

    def __init__(self, *args, **kw):
        super(IExporter2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def putref_ExportExtent(self, _arg1):
        '''Method IExporter2.putref_ExportExtent

           INPUT
            _arg1               : IEnvelope*'''
        return super(IExporter2, self).putref_ExportExtent(_arg1)
    def get_Name(self):
        '''Method IExporter2.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IExporter2, self).get_Name()
    def get_Filter(self):
        '''Method IExporter2.get_Filter

           OUTPUT
            Filter              : BSTR*'''
        return super(IExporter2, self).get_Filter()
    def get_FileExtension(self):
        '''Method IExporter2.get_FileExtension

           OUTPUT
            Name                : BSTR*'''
        return super(IExporter2, self).get_FileExtension()
    def put_PixelBounds(self, PixelBounds):
        '''Method IExporter2.put_PixelBounds

           INPUT
            PixelBounds         : IEnvelope*'''
        return super(IExporter2, self).put_PixelBounds(PixelBounds)
    def get_PixelBounds(self):
        '''Method IExporter2.get_PixelBounds

           OUTPUT
            PixelBounds         : IEnvelope**'''
        return super(IExporter2, self).get_PixelBounds()
    def put_ExportFileName(self, fileName):
        '''Method IExporter2.put_ExportFileName

           INPUT
            fileName            : BSTR'''
        return super(IExporter2, self).put_ExportFileName(fileName)
    def get_ExportFileName(self):
        '''Method IExporter2.get_ExportFileName

           OUTPUT
            fileName            : BSTR*'''
        return super(IExporter2, self).get_ExportFileName()
    def get_Resolution(self):
        '''Method IExporter2.get_Resolution

           OUTPUT
            res                 : short*'''
        return super(IExporter2, self).get_Resolution()
    def put_Resolution(self, res):
        '''Method IExporter2.put_Resolution

           INPUT
            res                 : short'''
        return super(IExporter2, self).put_Resolution(res)
    def get_ClipToGraphicExtent(self):
        '''Method IExporter2.get_ClipToGraphicExtent

           OUTPUT
            clipToGraphicsExtent: VARIANT_BOOL*'''
        return super(IExporter2, self).get_ClipToGraphicExtent()
    def put_ClipToGraphicExtent(self, clipToGraphicsExtent):
        '''Method IExporter2.put_ClipToGraphicExtent

           INPUT
            clipToGraphicsExtent: VARIANT_BOOL'''
        return super(IExporter2, self).put_ClipToGraphicExtent(clipToGraphicsExtent)
    def StartExporting(self):
        '''Method IExporter2.StartExporting

           OUTPUT
            hDC                 : OLE_HANDLE*'''
        return super(IExporter2, self).StartExporting()
    def FinishExporting(self):
        '''Method IExporter2.FinishExporting'''
        return super(IExporter2, self).FinishExporting()
    ClipToGraphicExtent = property(get_ClipToGraphicExtent, put_ClipToGraphicExtent, None)
    ExportExtent = property(None, putref_ExportExtent, None)
    ExportFileName = property(get_ExportFileName, put_ExportFileName, None)
    FileExtension = property(get_FileExtension, None, None)
    Filter = property(get_Filter, None, None)
    Name = property(get_Name, None, None)
    PixelBounds = property(get_PixelBounds, put_PixelBounds, None)
    Resolution = property(get_Resolution, put_Resolution, None)

class IExporterPriority(_esriOutput.IExporterPriority):
    _IID = uuid.UUID('10aae67f-d5ab-4905-a0bf-82636ba2ed02')
    def get_Priority(self):
        '''Method IExporterPriority.get_Priority

           OUTPUT
            pPriority           : long*'''
        return super(IExporterPriority, self).get_Priority()
    Priority = property(get_Priority, None, None)

class IOutputCleanup(_esriOutput.IOutputCleanup):
    _IID = uuid.UUID('2b8765ec-8808-474c-8fd3-869d08df20f6')
    def Cleanup(self):
        '''Method IOutputCleanup.Cleanup'''
        return super(IOutputCleanup, self).Cleanup()

class IWorldFileSettings(_esriOutput.IWorldFileSettings):
    _IID = uuid.UUID('27bf29ca-71a8-422a-a66d-ff875a9de13b')

    def __init__(self, *args, **kw):
        super(IWorldFileSettings, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_MapExtent(self, MapExtent):
        '''Method IWorldFileSettings.put_MapExtent

           INPUT
            MapExtent           : IEnvelope*'''
        return super(IWorldFileSettings, self).put_MapExtent(MapExtent)
    def get_MapExtent(self):
        '''Method IWorldFileSettings.get_MapExtent

           OUTPUT
            MapExtent           : IEnvelope**'''
        return super(IWorldFileSettings, self).get_MapExtent()
    def put_OutputWorldFile(self, OutputWorldFile):
        '''Method IWorldFileSettings.put_OutputWorldFile

           INPUT
            OutputWorldFile     : VARIANT_BOOL'''
        return super(IWorldFileSettings, self).put_OutputWorldFile(OutputWorldFile)
    def get_OutputWorldFile(self):
        '''Method IWorldFileSettings.get_OutputWorldFile

           OUTPUT
            OutputWorldFile     : VARIANT_BOOL*'''
        return super(IWorldFileSettings, self).get_OutputWorldFile()
    MapExtent = property(get_MapExtent, put_MapExtent, None)
    OutputWorldFile = property(get_OutputWorldFile, put_OutputWorldFile, None)

class IWorldFileSettings2(_esriOutput.IWorldFileSettings2):
    _IID = uuid.UUID('167806fc-6bcb-491e-9fb0-827baf2c3dec')

    def __init__(self, *args, **kw):
        super(IWorldFileSettings2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_MapRotation(self, mapRotAngle):
        '''Method IWorldFileSettings2.put_MapRotation

           INPUT
            mapRotAngle         : double'''
        return super(IWorldFileSettings2, self).put_MapRotation(mapRotAngle)
    def get_MapRotation(self):
        '''Method IWorldFileSettings2.get_MapRotation

           OUTPUT
            mapRotAngle         : double*'''
        return super(IWorldFileSettings2, self).get_MapRotation()
    MapRotation = property(get_MapRotation, put_MapRotation, None)

class IStepProgressorSetup(_esriOutput.IStepProgressorSetup):
    _IID = uuid.UUID('1c538193-8806-489c-8a79-4b54c8c18b37')

    def __init__(self, *args, **kw):
        super(IStepProgressorSetup, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_StepProgressor(self, _arg1):
        '''Method IStepProgressorSetup.put_StepProgressor

           INPUT
            _arg1               : IStepProgressor*'''
        return super(IStepProgressorSetup, self).put_StepProgressor(_arg1)
    StepProgressor = property(None, put_StepProgressor, None)

class ITrackCancelSetup(_esriOutput.ITrackCancelSetup):
    _IID = uuid.UUID('5e091c46-d015-471f-8187-f774c7ad9d48')

    def __init__(self, *args, **kw):
        super(ITrackCancelSetup, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_TrackCancel(self, _arg1):
        '''Method ITrackCancelSetup.put_TrackCancel

           INPUT
            _arg1               : ITrackCancel*'''
        return super(ITrackCancelSetup, self).put_TrackCancel(_arg1)
    TrackCancel = property(None, put_TrackCancel, None)

class ISettingsInRegistry(_esriOutput.ISettingsInRegistry):
    _IID = uuid.UUID('bb518176-e7e3-420a-9787-ae6e3487eb68')
    def RestoreForCurrentUser(self, bstrRegPath):
        '''Method ISettingsInRegistry.RestoreForCurrentUser

           INPUT
            bstrRegPath         : BSTR'''
        return super(ISettingsInRegistry, self).RestoreForCurrentUser(bstrRegPath)
    def StoreForCurrentUser(self, bstrRegPath):
        '''Method ISettingsInRegistry.StoreForCurrentUser

           INPUT
            bstrRegPath         : BSTR'''
        return super(ISettingsInRegistry, self).StoreForCurrentUser(bstrRegPath)
    def RestoreDefault(self):
        '''Method ISettingsInRegistry.RestoreDefault'''
        return super(ISettingsInRegistry, self).RestoreDefault()

class IExportColorspaceSettings(_esriOutput.IExportColorspaceSettings):
    _IID = uuid.UUID('c42431dc-237a-4628-996a-39a89af74158')

    def __init__(self, *args, **kw):
        super(IExportColorspaceSettings, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Colorspace(self, pcolorspace):
        '''Method IExportColorspaceSettings.put_Colorspace

           INPUT
            pcolorspace         : esriExportColorspace'''
        return super(IExportColorspaceSettings, self).put_Colorspace(pcolorspace)
    def get_Colorspace(self):
        '''Method IExportColorspaceSettings.get_Colorspace

           OUTPUT
            pcolorspace         : esriExportColorspace*'''
        return super(IExportColorspaceSettings, self).get_Colorspace()
    Colorspace = property(get_Colorspace, put_Colorspace, None)

class IPrintAndExportPageOptions(_esriOutput.IPrintAndExportPageOptions):
    _IID = uuid.UUID('1f685f17-704a-4755-834f-4c0d67303a2f')

    def __init__(self, *args, **kw):
        super(IPrintAndExportPageOptions, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_OutputSelection(self, pOption):
        '''Method IPrintAndExportPageOptions.put_OutputSelection

           INPUT
            pOption             : esriOutputSelection'''
        return super(IPrintAndExportPageOptions, self).put_OutputSelection(pOption)
    def get_OutputSelection(self):
        '''Method IPrintAndExportPageOptions.get_OutputSelection

           OUTPUT
            pOption             : esriOutputSelection*'''
        return super(IPrintAndExportPageOptions, self).get_OutputSelection()
    def put_PageRange(self, range):
        '''Method IPrintAndExportPageOptions.put_PageRange

           INPUT
            range               : BSTR'''
        return super(IPrintAndExportPageOptions, self).put_PageRange(range)
    def get_PageRange(self):
        '''Method IPrintAndExportPageOptions.get_PageRange

           OUTPUT
            range               : BSTR*'''
        return super(IPrintAndExportPageOptions, self).get_PageRange()
    def get_OutputPageSelection(self):
        '''Method IPrintAndExportPageOptions.get_OutputPageSelection

           OUTPUT
            flag                : VARIANT_BOOL*'''
        return super(IPrintAndExportPageOptions, self).get_OutputPageSelection()
    def put_OutputPageSelection(self, flag):
        '''Method IPrintAndExportPageOptions.put_OutputPageSelection

           INPUT
            flag                : VARIANT_BOOL'''
        return super(IPrintAndExportPageOptions, self).put_OutputPageSelection(flag)
    OutputPageSelection = property(get_OutputPageSelection, put_OutputPageSelection, None)
    OutputSelection = property(get_OutputSelection, put_OutputSelection, None)
    PageRange = property(get_PageRange, put_PageRange, None)

class IEmfExporter(_esriOutput.IEmfExporter):
    _IID = uuid.UUID('7d4881e3-57c6-11d1-945e-080009eebecb')

    def __init__(self, *args, **kw):
        super(IEmfExporter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_IsInMemory(self, pIsInMemory):
        '''Method IEmfExporter.put_IsInMemory

           INPUT
            pIsInMemory         : VARIANT_BOOL'''
        return super(IEmfExporter, self).put_IsInMemory(pIsInMemory)
    def get_IsInMemory(self):
        '''Method IEmfExporter.get_IsInMemory

           OUTPUT
            pIsInMemory         : VARIANT_BOOL*'''
        return super(IEmfExporter, self).get_IsInMemory()
    def get_HENHMETAFILE(self):
        '''Method IEmfExporter.get_HENHMETAFILE

           OUTPUT
            pHandle             : OLE_HANDLE*'''
        return super(IEmfExporter, self).get_HENHMETAFILE()
    def TakeHENHMETAFILE(self):
        '''Method IEmfExporter.TakeHENHMETAFILE

           OUTPUT
            pHandle             : OLE_HANDLE*'''
        return super(IEmfExporter, self).TakeHENHMETAFILE()
    def put_Description(self, pDescription):
        '''Method IEmfExporter.put_Description

           INPUT
            pDescription        : BSTR'''
        return super(IEmfExporter, self).put_Description(pDescription)
    def get_Description(self):
        '''Method IEmfExporter.get_Description

           OUTPUT
            pDescription        : BSTR*'''
        return super(IEmfExporter, self).get_Description()
    Description = property(get_Description, put_Description, None)
    HENHMETAFILE = property(get_HENHMETAFILE, None, None)
    IsInMemory = property(get_IsInMemory, put_IsInMemory, None)

class ISpotPlate(_esriOutput.ISpotPlate):
    _IID = uuid.UUID('481614e4-9407-11d1-9127-0000f87808ee')

    def __init__(self, *args, **kw):
        super(ISpotPlate, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Color(self, Color):
        '''Method ISpotPlate.put_Color

           INPUT
            Color               : IPostScriptColor*'''
        return super(ISpotPlate, self).put_Color(Color)
    def get_Color(self):
        '''Method ISpotPlate.get_Color

           OUTPUT
            Color               : IPostScriptColor**'''
        return super(ISpotPlate, self).get_Color()
    def put_Separate(self, Separate):
        '''Method ISpotPlate.put_Separate

           INPUT
            Separate            : esriPSDriverSeparates'''
        return super(ISpotPlate, self).put_Separate(Separate)
    def get_Separate(self):
        '''Method ISpotPlate.get_Separate

           OUTPUT
            Separate            : esriPSDriverSeparates*'''
        return super(ISpotPlate, self).get_Separate()
    def put_ScreenAngle(self, angle):
        '''Method ISpotPlate.put_ScreenAngle

           INPUT
            angle               : double'''
        return super(ISpotPlate, self).put_ScreenAngle(angle)
    def get_ScreenAngle(self):
        '''Method ISpotPlate.get_ScreenAngle

           OUTPUT
            angle               : double*'''
        return super(ISpotPlate, self).get_ScreenAngle()
    Color = property(get_Color, put_Color, None)
    ScreenAngle = property(get_ScreenAngle, put_ScreenAngle, None)
    Separate = property(get_Separate, put_Separate, None)

class ISpotPlateCollection(_esriOutput.ISpotPlateCollection):
    _IID = uuid.UUID('f480e790-2b0f-11d3-9fc3-00c04f6bc8dd')
    def get_Count(self):
        '''Method ISpotPlateCollection.get_Count

           OUTPUT
            Count               : long*'''
        return super(ISpotPlateCollection, self).get_Count()
    def get_SpotPlate(self, index):
        '''Method ISpotPlateCollection.get_SpotPlate

           INPUT
            index               : long

           OUTPUT
            SpotPlate           : ISpotPlate**'''
        return super(ISpotPlateCollection, self).get_SpotPlate(index)
    def Add(self, SpotPlate):
        '''Method ISpotPlateCollection.Add

           INPUT
            SpotPlate           : ISpotPlate*'''
        return super(ISpotPlateCollection, self).Add(SpotPlate)
    def Insert(self, index, SpotPlate):
        '''Method ISpotPlateCollection.Insert

           INPUTS
            index               : long
            SpotPlate           : ISpotPlate*'''
        return super(ISpotPlateCollection, self).Insert(index, SpotPlate)
    def Remove(self, index):
        '''Method ISpotPlateCollection.Remove

           INPUT
            index               : long'''
        return super(ISpotPlateCollection, self).Remove(index)
    def RemoveAll(self):
        '''Method ISpotPlateCollection.RemoveAll'''
        return super(ISpotPlateCollection, self).RemoveAll()
    Count = property(get_Count, None, None)
    SpotPlate = IndexProperty(get_SpotPlate, None)

class IColorCorrection(_esriOutput.IColorCorrection):
    _IID = uuid.UUID('80b77a31-4db6-11d3-b654-0080c8ea4fd5')

    def __init__(self, *args, **kw):
        super(IColorCorrection, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_SupportedColorCorrections(self):
        '''Method IColorCorrection.get_SupportedColorCorrections

           OUTPUT
            val                 : short*'''
        return super(IColorCorrection, self).get_SupportedColorCorrections()
    def get_Lightness(self, dataType):
        '''Method IColorCorrection.get_Lightness

           INPUT
            dataType            : esriColorCorrectionDataType

           OUTPUT
            val                 : short*'''
        return super(IColorCorrection, self).get_Lightness(dataType)
    def put_Lightness(self, dataType, val):
        '''Method IColorCorrection.put_Lightness

           INPUTS
            dataType            : esriColorCorrectionDataType
            val                 : short'''
        return super(IColorCorrection, self).put_Lightness(dataType, val)
    def get_Saturation(self, dataType):
        '''Method IColorCorrection.get_Saturation

           INPUT
            dataType            : esriColorCorrectionDataType

           OUTPUT
            val                 : short*'''
        return super(IColorCorrection, self).get_Saturation(dataType)
    def put_Saturation(self, dataType, val):
        '''Method IColorCorrection.put_Saturation

           INPUTS
            dataType            : esriColorCorrectionDataType
            val                 : short'''
        return super(IColorCorrection, self).put_Saturation(dataType, val)
    def get_UnderColorRemoval(self, dataType):
        '''Method IColorCorrection.get_UnderColorRemoval

           INPUT
            dataType            : esriColorCorrectionDataType

           OUTPUT
            val                 : short*'''
        return super(IColorCorrection, self).get_UnderColorRemoval(dataType)
    def put_UnderColorRemoval(self, dataType, val):
        '''Method IColorCorrection.put_UnderColorRemoval

           INPUTS
            dataType            : esriColorCorrectionDataType
            val                 : short'''
        return super(IColorCorrection, self).put_UnderColorRemoval(dataType, val)
    def get_CMYKCorrection(self, dataType, index):
        '''Method IColorCorrection.get_CMYKCorrection

           INPUTS
            dataType            : esriColorCorrectionDataType
            index               : esriCMYKIndex

           OUTPUT
            val                 : short*'''
        return super(IColorCorrection, self).get_CMYKCorrection(dataType, index)
    def put_CMYKCorrection(self, dataType, index, val):
        '''Method IColorCorrection.put_CMYKCorrection

           INPUTS
            dataType            : esriColorCorrectionDataType
            index               : esriCMYKIndex
            val                 : short'''
        return super(IColorCorrection, self).put_CMYKCorrection(dataType, index, val)
    CMYKCorrection = property(None, put_CMYKCorrection, None)
    Lightness = property(None, put_Lightness, None)
    Saturation = property(None, put_Saturation, None)
    SupportedColorCorrections = property(get_SupportedColorCorrections, None, None)
    UnderColorRemoval = property(None, put_UnderColorRemoval, None)
    Lightness = IndexProperty(get_Lightness, None)
    Saturation = IndexProperty(get_Saturation, None)
    UnderColorRemoval = IndexProperty(get_UnderColorRemoval, None)

class IPSDriver(_esriOutput.IPSDriver):
    _IID = uuid.UUID('cd754684-a222-11d0-a68f-080009d57b9a')

    def __init__(self, *args, **kw):
        super(IPSDriver, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_ImageCompression(self):
        '''Method IPSDriver.get_ImageCompression

           OUTPUT
            ImageCompression    : esriPSDriverImageCompression*'''
        return super(IPSDriver, self).get_ImageCompression()
    def put_ImageCompression(self, ImageCompression):
        '''Method IPSDriver.put_ImageCompression

           INPUT
            ImageCompression    : esriPSDriverImageCompression'''
        return super(IPSDriver, self).put_ImageCompression(ImageCompression)
    def get_ArcPressSeparateImage(self):
        '''Method IPSDriver.get_ArcPressSeparateImage

           OUTPUT
            sepImage            : VARIANT_BOOL*'''
        return super(IPSDriver, self).get_ArcPressSeparateImage()
    def put_ArcPressSeparateImage(self, sepImage):
        '''Method IPSDriver.put_ArcPressSeparateImage

           INPUT
            sepImage            : VARIANT_BOOL'''
        return super(IPSDriver, self).put_ArcPressSeparateImage(sepImage)
    def get_ArcPressSeparateImageRotate(self):
        '''Method IPSDriver.get_ArcPressSeparateImageRotate

           OUTPUT
            sepImage            : VARIANT_BOOL*'''
        return super(IPSDriver, self).get_ArcPressSeparateImageRotate()
    def put_ArcPressSeparateImageRotate(self, sepImage):
        '''Method IPSDriver.put_ArcPressSeparateImageRotate

           INPUT
            sepImage            : VARIANT_BOOL'''
        return super(IPSDriver, self).put_ArcPressSeparateImageRotate(sepImage)
    def get_FontMapCollection(self):
        '''Method IPSDriver.get_FontMapCollection

           OUTPUT
            FontMapCollection   : IFontMapCollection**'''
        return super(IPSDriver, self).get_FontMapCollection()
    def putref_FontMapCollection(self, FontMapCollection):
        '''Method IPSDriver.putref_FontMapCollection

           INPUT
            FontMapCollection   : IFontMapCollection*'''
        return super(IPSDriver, self).putref_FontMapCollection(FontMapCollection)
    def get_PPDFile(self):
        '''Method IPSDriver.get_PPDFile

           OUTPUT
            PPDFile             : BSTR*'''
        return super(IPSDriver, self).get_PPDFile()
    def put_PPDFile(self, PPDFile):
        '''Method IPSDriver.put_PPDFile

           INPUT
            PPDFile             : BSTR'''
        return super(IPSDriver, self).put_PPDFile(PPDFile)
    def get_Marks(self):
        '''Method IPSDriver.get_Marks

           OUTPUT
            Marks               : short*'''
        return super(IPSDriver, self).get_Marks()
    def put_Marks(self, Marks):
        '''Method IPSDriver.put_Marks

           INPUT
            Marks               : short'''
        return super(IPSDriver, self).put_Marks(Marks)
    def get_HalfTone(self, HalfTone):
        '''Method IPSDriver.get_HalfTone

           INPUT
            HalfTone            : esriPSDriverHalfTone

           OUTPUT
            value               : long*'''
        return super(IPSDriver, self).get_HalfTone(HalfTone)
    def put_HalfTone(self, HalfTone, value):
        '''Method IPSDriver.put_HalfTone

           INPUTS
            HalfTone            : esriPSDriverHalfTone
            value               : long'''
        return super(IPSDriver, self).put_HalfTone(HalfTone, value)
    def get_FormName(self):
        '''Method IPSDriver.get_FormName

           OUTPUT
            FormName            : BSTR*'''
        return super(IPSDriver, self).get_FormName()
    def put_FormName(self, FormName):
        '''Method IPSDriver.put_FormName

           INPUT
            FormName            : BSTR'''
        return super(IPSDriver, self).put_FormName(FormName)
    def get_PrintableBounds(self):
        '''Method IPSDriver.get_PrintableBounds

           OUTPUT
            ppBounds            : IEnvelope**'''
        return super(IPSDriver, self).get_PrintableBounds()
    def put_PrintableBounds(self, ppBounds):
        '''Method IPSDriver.put_PrintableBounds

           INPUT
            ppBounds            : IEnvelope*'''
        return super(IPSDriver, self).put_PrintableBounds(ppBounds)
    def get_Orientation(self):
        '''Method IPSDriver.get_Orientation

           OUTPUT
            Orientation         : short*'''
        return super(IPSDriver, self).get_Orientation()
    def put_Orientation(self, Orientation):
        '''Method IPSDriver.put_Orientation

           INPUT
            Orientation         : short'''
        return super(IPSDriver, self).put_Orientation(Orientation)
    def get_Emulsion(self):
        '''Method IPSDriver.get_Emulsion

           OUTPUT
            Emulsion            : esriPSDriverEmulsion*'''
        return super(IPSDriver, self).get_Emulsion()
    def put_Emulsion(self, Emulsion):
        '''Method IPSDriver.put_Emulsion

           INPUT
            Emulsion            : esriPSDriverEmulsion'''
        return super(IPSDriver, self).put_Emulsion(Emulsion)
    def get_Image(self):
        '''Method IPSDriver.get_Image

           OUTPUT
            Image               : esriPSDriverImage*'''
        return super(IPSDriver, self).get_Image()
    def put_Image(self, Image):
        '''Method IPSDriver.put_Image

           INPUT
            Image               : esriPSDriverImage'''
        return super(IPSDriver, self).put_Image(Image)
    def get_OneBitImageTransparency(self):
        '''Method IPSDriver.get_OneBitImageTransparency

           OUTPUT
            imageTransparency   : VARIANT_BOOL*'''
        return super(IPSDriver, self).get_OneBitImageTransparency()
    def put_OneBitImageTransparency(self, imageTransparency):
        '''Method IPSDriver.put_OneBitImageTransparency

           INPUT
            imageTransparency   : VARIANT_BOOL'''
        return super(IPSDriver, self).put_OneBitImageTransparency(imageTransparency)
    def get_UseEMFFrameBoxForPSBoundingBox(self):
        '''Method IPSDriver.get_UseEMFFrameBoxForPSBoundingBox

           OUTPUT
            useFrameBox         : VARIANT_BOOL*'''
        return super(IPSDriver, self).get_UseEMFFrameBoxForPSBoundingBox()
    def put_UseEMFFrameBoxForPSBoundingBox(self, useFrameBox):
        '''Method IPSDriver.put_UseEMFFrameBoxForPSBoundingBox

           INPUT
            useFrameBox         : VARIANT_BOOL'''
        return super(IPSDriver, self).put_UseEMFFrameBoxForPSBoundingBox(useFrameBox)
    def get_PSLanguageLevel(self):
        '''Method IPSDriver.get_PSLanguageLevel

           OUTPUT
            pslevel             : esriPSDriverPSLanguageLevel*'''
        return super(IPSDriver, self).get_PSLanguageLevel()
    def put_PSLanguageLevel(self, pslevel):
        '''Method IPSDriver.put_PSLanguageLevel

           INPUT
            pslevel             : esriPSDriverPSLanguageLevel'''
        return super(IPSDriver, self).put_PSLanguageLevel(pslevel)
    def put_StepProgressor(self, _arg1):
        '''Method IPSDriver.put_StepProgressor

           INPUT
            _arg1               : IStepProgressor*'''
        return super(IPSDriver, self).put_StepProgressor(_arg1)
    def CreatePS(self, InputFileName, OutputFileName):
        '''Method IPSDriver.CreatePS

           INPUTS
            InputFileName       : BSTR
            OutputFileName      : BSTR'''
        return super(IPSDriver, self).CreatePS(InputFileName, OutputFileName)
    ArcPressSeparateImage = property(get_ArcPressSeparateImage, put_ArcPressSeparateImage, None)
    ArcPressSeparateImageRotate = property(get_ArcPressSeparateImageRotate, put_ArcPressSeparateImageRotate, None)
    Emulsion = property(get_Emulsion, put_Emulsion, None)
    FontMapCollection = property(get_FontMapCollection, putref_FontMapCollection, None)
    FormName = property(get_FormName, put_FormName, None)
    HalfTone = property(None, put_HalfTone, None)
    Image = property(get_Image, put_Image, None)
    ImageCompression = property(get_ImageCompression, put_ImageCompression, None)
    Marks = property(get_Marks, put_Marks, None)
    OneBitImageTransparency = property(get_OneBitImageTransparency, put_OneBitImageTransparency, None)
    Orientation = property(get_Orientation, put_Orientation, None)
    PPDFile = property(get_PPDFile, put_PPDFile, None)
    PSLanguageLevel = property(get_PSLanguageLevel, put_PSLanguageLevel, None)
    PrintableBounds = property(get_PrintableBounds, put_PrintableBounds, None)
    StepProgressor = property(None, put_StepProgressor, None)
    UseEMFFrameBoxForPSBoundingBox = property(get_UseEMFFrameBoxForPSBoundingBox, put_UseEMFFrameBoxForPSBoundingBox, None)
    HalfTone = IndexProperty(get_HalfTone, None)

class IPSDriver2(_esriOutput.IPSDriver2):
    _IID = uuid.UUID('25164bc3-56da-4af1-a195-1506ecfec53c')

    def __init__(self, *args, **kw):
        super(IPSDriver2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Copies(self):
        '''Method IPSDriver2.get_Copies

           OUTPUT
            Copies              : short*'''
        return super(IPSDriver2, self).get_Copies()
    def put_Copies(self, Copies):
        '''Method IPSDriver2.put_Copies

           INPUT
            Copies              : short'''
        return super(IPSDriver2, self).put_Copies(Copies)
    def get_ImageCompression(self):
        '''Method IPSDriver2.get_ImageCompression

           OUTPUT
            ImageCompression    : esriPSDriverImageCompression*'''
        return super(IPSDriver2, self).get_ImageCompression()
    def put_ImageCompression(self, ImageCompression):
        '''Method IPSDriver2.put_ImageCompression

           INPUT
            ImageCompression    : esriPSDriverImageCompression'''
        return super(IPSDriver2, self).put_ImageCompression(ImageCompression)
    def get_ArcPressSeparateImage(self):
        '''Method IPSDriver2.get_ArcPressSeparateImage

           OUTPUT
            sepImage            : VARIANT_BOOL*'''
        return super(IPSDriver2, self).get_ArcPressSeparateImage()
    def put_ArcPressSeparateImage(self, sepImage):
        '''Method IPSDriver2.put_ArcPressSeparateImage

           INPUT
            sepImage            : VARIANT_BOOL'''
        return super(IPSDriver2, self).put_ArcPressSeparateImage(sepImage)
    def get_ArcPressSeparateImageRotate(self):
        '''Method IPSDriver2.get_ArcPressSeparateImageRotate

           OUTPUT
            sepImage            : VARIANT_BOOL*'''
        return super(IPSDriver2, self).get_ArcPressSeparateImageRotate()
    def put_ArcPressSeparateImageRotate(self, sepImage):
        '''Method IPSDriver2.put_ArcPressSeparateImageRotate

           INPUT
            sepImage            : VARIANT_BOOL'''
        return super(IPSDriver2, self).put_ArcPressSeparateImageRotate(sepImage)
    def get_FontMapCollection(self):
        '''Method IPSDriver2.get_FontMapCollection

           OUTPUT
            FontMapCollection   : IFontMapCollection**'''
        return super(IPSDriver2, self).get_FontMapCollection()
    def putref_FontMapCollection(self, FontMapCollection):
        '''Method IPSDriver2.putref_FontMapCollection

           INPUT
            FontMapCollection   : IFontMapCollection*'''
        return super(IPSDriver2, self).putref_FontMapCollection(FontMapCollection)
    def get_PPDFile(self):
        '''Method IPSDriver2.get_PPDFile

           OUTPUT
            PPDFile             : BSTR*'''
        return super(IPSDriver2, self).get_PPDFile()
    def put_PPDFile(self, PPDFile):
        '''Method IPSDriver2.put_PPDFile

           INPUT
            PPDFile             : BSTR'''
        return super(IPSDriver2, self).put_PPDFile(PPDFile)
    def get_Marks(self):
        '''Method IPSDriver2.get_Marks

           OUTPUT
            Marks               : short*'''
        return super(IPSDriver2, self).get_Marks()
    def put_Marks(self, Marks):
        '''Method IPSDriver2.put_Marks

           INPUT
            Marks               : short'''
        return super(IPSDriver2, self).put_Marks(Marks)
    def get_HalfTone(self, HalfTone):
        '''Method IPSDriver2.get_HalfTone

           INPUT
            HalfTone            : esriPSDriverHalfTone

           OUTPUT
            value               : long*'''
        return super(IPSDriver2, self).get_HalfTone(HalfTone)
    def put_HalfTone(self, HalfTone, value):
        '''Method IPSDriver2.put_HalfTone

           INPUTS
            HalfTone            : esriPSDriverHalfTone
            value               : long'''
        return super(IPSDriver2, self).put_HalfTone(HalfTone, value)
    def get_FormName(self):
        '''Method IPSDriver2.get_FormName

           OUTPUT
            FormName            : BSTR*'''
        return super(IPSDriver2, self).get_FormName()
    def put_FormName(self, FormName):
        '''Method IPSDriver2.put_FormName

           INPUT
            FormName            : BSTR'''
        return super(IPSDriver2, self).put_FormName(FormName)
    def get_PrintableBounds(self):
        '''Method IPSDriver2.get_PrintableBounds

           OUTPUT
            ppBounds            : IEnvelope**'''
        return super(IPSDriver2, self).get_PrintableBounds()
    def put_PrintableBounds(self, ppBounds):
        '''Method IPSDriver2.put_PrintableBounds

           INPUT
            ppBounds            : IEnvelope*'''
        return super(IPSDriver2, self).put_PrintableBounds(ppBounds)
    def get_Orientation(self):
        '''Method IPSDriver2.get_Orientation

           OUTPUT
            Orientation         : short*'''
        return super(IPSDriver2, self).get_Orientation()
    def put_Orientation(self, Orientation):
        '''Method IPSDriver2.put_Orientation

           INPUT
            Orientation         : short'''
        return super(IPSDriver2, self).put_Orientation(Orientation)
    def get_Emulsion(self):
        '''Method IPSDriver2.get_Emulsion

           OUTPUT
            Emulsion            : esriPSDriverEmulsion*'''
        return super(IPSDriver2, self).get_Emulsion()
    def put_Emulsion(self, Emulsion):
        '''Method IPSDriver2.put_Emulsion

           INPUT
            Emulsion            : esriPSDriverEmulsion'''
        return super(IPSDriver2, self).put_Emulsion(Emulsion)
    def get_Image(self):
        '''Method IPSDriver2.get_Image

           OUTPUT
            Image               : esriPSDriverImage*'''
        return super(IPSDriver2, self).get_Image()
    def put_Image(self, Image):
        '''Method IPSDriver2.put_Image

           INPUT
            Image               : esriPSDriverImage'''
        return super(IPSDriver2, self).put_Image(Image)
    def get_OneBitImageTransparency(self):
        '''Method IPSDriver2.get_OneBitImageTransparency

           OUTPUT
            imageTransparency   : VARIANT_BOOL*'''
        return super(IPSDriver2, self).get_OneBitImageTransparency()
    def put_OneBitImageTransparency(self, imageTransparency):
        '''Method IPSDriver2.put_OneBitImageTransparency

           INPUT
            imageTransparency   : VARIANT_BOOL'''
        return super(IPSDriver2, self).put_OneBitImageTransparency(imageTransparency)
    def get_UseEMFFrameBoxForPSBoundingBox(self):
        '''Method IPSDriver2.get_UseEMFFrameBoxForPSBoundingBox

           OUTPUT
            useFrameBox         : VARIANT_BOOL*'''
        return super(IPSDriver2, self).get_UseEMFFrameBoxForPSBoundingBox()
    def put_UseEMFFrameBoxForPSBoundingBox(self, useFrameBox):
        '''Method IPSDriver2.put_UseEMFFrameBoxForPSBoundingBox

           INPUT
            useFrameBox         : VARIANT_BOOL'''
        return super(IPSDriver2, self).put_UseEMFFrameBoxForPSBoundingBox(useFrameBox)
    def get_PSLanguageLevel(self):
        '''Method IPSDriver2.get_PSLanguageLevel

           OUTPUT
            pslevel             : esriPSDriverPSLanguageLevel*'''
        return super(IPSDriver2, self).get_PSLanguageLevel()
    def put_PSLanguageLevel(self, pslevel):
        '''Method IPSDriver2.put_PSLanguageLevel

           INPUT
            pslevel             : esriPSDriverPSLanguageLevel'''
        return super(IPSDriver2, self).put_PSLanguageLevel(pslevel)
    def put_StepProgressor(self, _arg1):
        '''Method IPSDriver2.put_StepProgressor

           INPUT
            _arg1               : IStepProgressor*'''
        return super(IPSDriver2, self).put_StepProgressor(_arg1)
    def CreatePS(self, InputFileName, OutputFileName):
        '''Method IPSDriver2.CreatePS

           INPUTS
            InputFileName       : BSTR
            OutputFileName      : BSTR'''
        return super(IPSDriver2, self).CreatePS(InputFileName, OutputFileName)
    ArcPressSeparateImage = property(get_ArcPressSeparateImage, put_ArcPressSeparateImage, None)
    ArcPressSeparateImageRotate = property(get_ArcPressSeparateImageRotate, put_ArcPressSeparateImageRotate, None)
    Copies = property(get_Copies, put_Copies, None)
    Emulsion = property(get_Emulsion, put_Emulsion, None)
    FontMapCollection = property(get_FontMapCollection, putref_FontMapCollection, None)
    FormName = property(get_FormName, put_FormName, None)
    HalfTone = property(None, put_HalfTone, None)
    Image = property(get_Image, put_Image, None)
    ImageCompression = property(get_ImageCompression, put_ImageCompression, None)
    Marks = property(get_Marks, put_Marks, None)
    OneBitImageTransparency = property(get_OneBitImageTransparency, put_OneBitImageTransparency, None)
    Orientation = property(get_Orientation, put_Orientation, None)
    PPDFile = property(get_PPDFile, put_PPDFile, None)
    PSLanguageLevel = property(get_PSLanguageLevel, put_PSLanguageLevel, None)
    PrintableBounds = property(get_PrintableBounds, put_PrintableBounds, None)
    StepProgressor = property(None, put_StepProgressor, None)
    UseEMFFrameBoxForPSBoundingBox = property(get_UseEMFFrameBoxForPSBoundingBox, put_UseEMFFrameBoxForPSBoundingBox, None)
    HalfTone = IndexProperty(get_HalfTone, None)

class IPsExporter(_esriOutput.IPsExporter):
    _IID = uuid.UUID('7d4881e6-57c6-11d1-945e-080009eebecb')
    def QueryPSDriver(self):
        '''Method IPsExporter.QueryPSDriver

           OUTPUT
            PSDriver            : IPSDriver**'''
        return super(IPsExporter, self).QueryPSDriver()

class IOutputPageOptionsAdmin(_esriOutput.IOutputPageOptionsAdmin):
    _IID = uuid.UUID('1f685f18-704a-4755-834f-4c0d67303a2f')

    def __init__(self, *args, **kw):
        super(IOutputPageOptionsAdmin, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_OutputtingPageLayout(self):
        '''Method IOutputPageOptionsAdmin.get_OutputtingPageLayout

           OUTPUT
            flag                : VARIANT_BOOL*'''
        return super(IOutputPageOptionsAdmin, self).get_OutputtingPageLayout()
    def put_OutputtingPageLayout(self, flag):
        '''Method IOutputPageOptionsAdmin.put_OutputtingPageLayout

           INPUT
            flag                : VARIANT_BOOL'''
        return super(IOutputPageOptionsAdmin, self).put_OutputtingPageLayout(flag)
    def get_PageSelectionExists(self):
        '''Method IOutputPageOptionsAdmin.get_PageSelectionExists

           OUTPUT
            flag                : VARIANT_BOOL*'''
        return super(IOutputPageOptionsAdmin, self).get_PageSelectionExists()
    def put_PageSelectionExists(self, flag):
        '''Method IOutputPageOptionsAdmin.put_PageSelectionExists

           INPUT
            flag                : VARIANT_BOOL'''
        return super(IOutputPageOptionsAdmin, self).put_PageSelectionExists(flag)
    def get_PageCount(self):
        '''Method IOutputPageOptionsAdmin.get_PageCount

           OUTPUT
            Count               : long*'''
        return super(IOutputPageOptionsAdmin, self).get_PageCount()
    def put_PageCount(self, Count):
        '''Method IOutputPageOptionsAdmin.put_PageCount

           INPUT
            Count               : long'''
        return super(IOutputPageOptionsAdmin, self).put_PageCount(Count)
    def get_SelectedPageCount(self):
        '''Method IOutputPageOptionsAdmin.get_SelectedPageCount

           OUTPUT
            Count               : long*'''
        return super(IOutputPageOptionsAdmin, self).get_SelectedPageCount()
    def put_SelectedPageCount(self, Count):
        '''Method IOutputPageOptionsAdmin.put_SelectedPageCount

           INPUT
            Count               : long'''
        return super(IOutputPageOptionsAdmin, self).put_SelectedPageCount(Count)
    def get_CurrentIndex(self):
        '''Method IOutputPageOptionsAdmin.get_CurrentIndex

           OUTPUT
            index               : long*'''
        return super(IOutputPageOptionsAdmin, self).get_CurrentIndex()
    def put_CurrentIndex(self, index):
        '''Method IOutputPageOptionsAdmin.put_CurrentIndex

           INPUT
            index               : long'''
        return super(IOutputPageOptionsAdmin, self).put_CurrentIndex(index)
    CurrentIndex = property(get_CurrentIndex, put_CurrentIndex, None)
    OutputtingPageLayout = property(get_OutputtingPageLayout, put_OutputtingPageLayout, None)
    PageCount = property(get_PageCount, put_PageCount, None)
    PageSelectionExists = property(get_PageSelectionExists, put_PageSelectionExists, None)
    SelectedPageCount = property(get_SelectedPageCount, put_SelectedPageCount, None)

class IPDFDriver(_esriOutput.IPDFDriver):
    _IID = uuid.UUID('0201602d-1521-11d3-9f97-00c04f6bc8dd')

    def __init__(self, *args, **kw):
        super(IPDFDriver, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_FontMapCollection(self):
        '''Method IPDFDriver.get_FontMapCollection

           OUTPUT
            FontMapCollection   : IFontMapCollection**'''
        return super(IPDFDriver, self).get_FontMapCollection()
    def putref_FontMapCollection(self, FontMapCollection):
        '''Method IPDFDriver.putref_FontMapCollection

           INPUT
            FontMapCollection   : IFontMapCollection*'''
        return super(IPDFDriver, self).putref_FontMapCollection(FontMapCollection)
    def CreatePDF(self, InputFileName, OutputFileName):
        '''Method IPDFDriver.CreatePDF

           INPUTS
            InputFileName       : BSTR
            OutputFileName      : BSTR'''
        return super(IPDFDriver, self).CreatePDF(InputFileName, OutputFileName)
    FontMapCollection = property(get_FontMapCollection, putref_FontMapCollection, None)

class IAIDriver(_esriOutput.IAIDriver):
    _IID = uuid.UUID('9e790106-4047-4fb3-be12-8f29106a1f86')

    def __init__(self, *args, **kw):
        super(IAIDriver, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def CreateAI(self, InputFileName, OutputFileName):
        '''Method IAIDriver.CreateAI

           INPUTS
            InputFileName       : BSTR
            OutputFileName      : BSTR'''
        return super(IAIDriver, self).CreateAI(InputFileName, OutputFileName)
    def get_AIDriverOptions(self):
        '''Method IAIDriver.get_AIDriverOptions

           OUTPUT
            aiOptions           : esriAIDriverOptions*'''
        return super(IAIDriver, self).get_AIDriverOptions()
    def put_AIDriverOptions(self, aiOptions):
        '''Method IAIDriver.put_AIDriverOptions

           INPUT
            aiOptions           : esriAIDriverOptions'''
        return super(IAIDriver, self).put_AIDriverOptions(aiOptions)
    AIDriverOptions = property(get_AIDriverOptions, put_AIDriverOptions, None)

class IAIExporter(_esriOutput.IAIExporter):
    _IID = uuid.UUID('722a2714-cd07-4c68-b07a-86a8d7b925e3')
    def QueryAIDriver(self):
        '''Method IAIExporter.QueryAIDriver

           OUTPUT
            AIDriver            : IAIDriver**'''
        return super(IAIExporter, self).QueryAIDriver()

class IPaper(_esriOutput.IPaper):
    _IID = uuid.UUID('387bc1d1-3f54-11d1-885e-0000f87808ee')

    def __init__(self, *args, **kw):
        super(IPaper, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Units(self):
        '''Method IPaper.get_Units

           OUTPUT
            Units               : esriUnits*'''
        return super(IPaper, self).get_Units()
    def get_PrintableBounds(self):
        '''Method IPaper.get_PrintableBounds

           OUTPUT
            bounds              : IEnvelope**'''
        return super(IPaper, self).get_PrintableBounds()
    def get_Orientation(self):
        '''Method IPaper.get_Orientation

           OUTPUT
            Orientation         : short*'''
        return super(IPaper, self).get_Orientation()
    def put_Orientation(self, Orientation):
        '''Method IPaper.put_Orientation

           INPUT
            Orientation         : short'''
        return super(IPaper, self).put_Orientation(Orientation)
    def get_Forms(self):
        '''Method IPaper.get_Forms

           OUTPUT
            Forms               : IEnumNamedID**'''
        return super(IPaper, self).get_Forms()
    def get_FormName(self):
        '''Method IPaper.get_FormName

           OUTPUT
            FormName            : BSTR*'''
        return super(IPaper, self).get_FormName()
    def get_FormID(self):
        '''Method IPaper.get_FormID

           OUTPUT
            FormID              : short*'''
        return super(IPaper, self).get_FormID()
    def put_FormID(self, FormID):
        '''Method IPaper.put_FormID

           INPUT
            FormID              : short'''
        return super(IPaper, self).put_FormID(FormID)
    def get_Trays(self):
        '''Method IPaper.get_Trays

           OUTPUT
            Trays               : IEnumNamedID**'''
        return super(IPaper, self).get_Trays()
    def get_TrayID(self):
        '''Method IPaper.get_TrayID

           OUTPUT
            TrayID              : short*'''
        return super(IPaper, self).get_TrayID()
    def put_TrayID(self, TrayID):
        '''Method IPaper.put_TrayID

           INPUT
            TrayID              : short'''
        return super(IPaper, self).put_TrayID(TrayID)
    def get_PrinterName(self):
        '''Method IPaper.get_PrinterName

           OUTPUT
            PrinterName         : BSTR*'''
        return super(IPaper, self).get_PrinterName()
    def put_PrinterName(self, PrinterName):
        '''Method IPaper.put_PrinterName

           INPUT
            PrinterName         : BSTR'''
        return super(IPaper, self).put_PrinterName(PrinterName)
    def Attach(self, hDevMode, hDevNames):
        '''Method IPaper.Attach

           INPUTS
            hDevMode            : OLE_HANDLE
            hDevNames           : OLE_HANDLE'''
        return super(IPaper, self).Attach(hDevMode, hDevNames)
    def QueryPaperSize(self):
        '''Method IPaper.QueryPaperSize

           OUTPUTS
            Width               : double*
            Height              : double*'''
        return super(IPaper, self).QueryPaperSize()
    def get_PrinterInfo(self):
        '''Method IPaper.get_PrinterInfo

           OUTPUTS
            hDevMode            : OLE_HANDLE*
            hDevNames           : OLE_HANDLE*'''
        return super(IPaper, self).get_PrinterInfo()
    FormID = property(get_FormID, put_FormID, None)
    FormName = property(get_FormName, None, None)
    Forms = property(get_Forms, None, None)
    Orientation = property(get_Orientation, put_Orientation, None)
    PrintableBounds = property(get_PrintableBounds, None, None)
    PrinterInfo = property(get_PrinterInfo, None, None)
    PrinterName = property(get_PrinterName, put_PrinterName, None)
    TrayID = property(get_TrayID, put_TrayID, None)
    Trays = property(get_Trays, None, None)
    Units = property(get_Units, None, None)

class IPaper2(_esriOutput.IPaper2):
    _IID = uuid.UUID('6a319332-d3e2-413a-97f4-f25ce438feda')
    def get_Resolution(self):
        '''Method IPaper2.get_Resolution

           OUTPUT
            Resolution          : short*'''
        return super(IPaper2, self).get_Resolution()
    Resolution = property(get_Resolution, None, None)

class IPrinter(_esriOutput.IPrinter):
    _IID = uuid.UUID('2ab49820-9406-11d0-87ef-080009ec732a')

    def __init__(self, *args, **kw):
        super(IPrinter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IPrinter.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IPrinter, self).get_Name()
    def get_Filter(self):
        '''Method IPrinter.get_Filter

           OUTPUT
            Filter              : BSTR*'''
        return super(IPrinter, self).get_Filter()
    def get_FileExtension(self):
        '''Method IPrinter.get_FileExtension

           OUTPUT
            Name                : BSTR*'''
        return super(IPrinter, self).get_FileExtension()
    def put_PrintToFile(self, fileName):
        '''Method IPrinter.put_PrintToFile

           INPUT
            fileName            : BSTR'''
        return super(IPrinter, self).put_PrintToFile(fileName)
    def get_PrintToFile(self):
        '''Method IPrinter.get_PrintToFile

           OUTPUT
            fileName            : BSTR*'''
        return super(IPrinter, self).get_PrintToFile()
    def get_DriverName(self):
        '''Method IPrinter.get_DriverName

           OUTPUT
            DriverName          : BSTR*'''
        return super(IPrinter, self).get_DriverName()
    def put_SpoolFileName(self, SpoolFileName):
        '''Method IPrinter.put_SpoolFileName

           INPUT
            SpoolFileName       : BSTR'''
        return super(IPrinter, self).put_SpoolFileName(SpoolFileName)
    def get_SpoolFileName(self):
        '''Method IPrinter.get_SpoolFileName

           OUTPUT
            SpoolFileName       : BSTR*'''
        return super(IPrinter, self).get_SpoolFileName()
    def put_Resolution(self, res):
        '''Method IPrinter.put_Resolution

           INPUT
            res                 : short'''
        return super(IPrinter, self).put_Resolution(res)
    def get_Resolution(self):
        '''Method IPrinter.get_Resolution

           OUTPUT
            res                 : short*'''
        return super(IPrinter, self).get_Resolution()
    def put_StepProgressor(self, _arg1):
        '''Method IPrinter.put_StepProgressor

           INPUT
            _arg1               : IStepProgressor*'''
        return super(IPrinter, self).put_StepProgressor(_arg1)
    def putref_Paper(self, Paper):
        '''Method IPrinter.putref_Paper

           INPUT
            Paper               : IPaper*'''
        return super(IPrinter, self).putref_Paper(Paper)
    def get_Paper(self):
        '''Method IPrinter.get_Paper

           OUTPUT
            Paper               : IPaper**'''
        return super(IPrinter, self).get_Paper()
    def QueryPaperSize(self):
        '''Method IPrinter.QueryPaperSize

           OUTPUTS
            Width               : double*
            Height              : double*'''
        return super(IPrinter, self).QueryPaperSize()
    def get_PrintableBounds(self):
        '''Method IPrinter.get_PrintableBounds

           OUTPUT
            bounds              : IEnvelope**'''
        return super(IPrinter, self).get_PrintableBounds()
    def get_Units(self):
        '''Method IPrinter.get_Units

           OUTPUT
            Units               : esriUnits*'''
        return super(IPrinter, self).get_Units()
    def VerifyDriverSettings(self):
        '''Method IPrinter.VerifyDriverSettings

           OUTPUT
            ok                  : VARIANT_BOOL*'''
        return super(IPrinter, self).VerifyDriverSettings()
    def DoesDriverSupportPrinter(self, PrinterName):
        '''Method IPrinter.DoesDriverSupportPrinter

           INPUT
            PrinterName         : BSTR

           OUTPUT
            supported           : VARIANT_BOOL*'''
        return super(IPrinter, self).DoesDriverSupportPrinter(PrinterName)
    def StartPrinting(self, PixelBounds, hDcPrinter):
        '''Method IPrinter.StartPrinting

           INPUTS
            PixelBounds         : IEnvelope*
            hDcPrinter          : OLE_HANDLE

           OUTPUT
            hDcRet              : OLE_HANDLE*'''
        return super(IPrinter, self).StartPrinting(PixelBounds, hDcPrinter)
    def FinishPrinting(self):
        '''Method IPrinter.FinishPrinting'''
        return super(IPrinter, self).FinishPrinting()
    DriverName = property(get_DriverName, None, None)
    FileExtension = property(get_FileExtension, None, None)
    Filter = property(get_Filter, None, None)
    Name = property(get_Name, None, None)
    Paper = property(get_Paper, putref_Paper, None)
    PrintToFile = property(get_PrintToFile, put_PrintToFile, None)
    PrintableBounds = property(get_PrintableBounds, None, None)
    Resolution = property(get_Resolution, put_Resolution, None)
    SpoolFileName = property(get_SpoolFileName, put_SpoolFileName, None)
    StepProgressor = property(None, put_StepProgressor, None)
    Units = property(get_Units, None, None)

class IPrinterMPage(_esriOutput.IPrinterMPage):
    _IID = uuid.UUID('4004040c-a184-4c77-ba78-0475d93a3803')
    def StartMapDocument(self):
        '''Method IPrinterMPage.StartMapDocument'''
        return super(IPrinterMPage, self).StartMapDocument()
    def StartPage(self, PixelBounds, hDcPrinter):
        '''Method IPrinterMPage.StartPage

           INPUTS
            PixelBounds         : IEnvelope*
            hDcPrinter          : OLE_HANDLE

           OUTPUT
            hDcRet              : OLE_HANDLE*'''
        return super(IPrinterMPage, self).StartPage(PixelBounds, hDcPrinter)
    def EndPage(self):
        '''Method IPrinterMPage.EndPage'''
        return super(IPrinterMPage, self).EndPage()
    def EndMapDocument(self):
        '''Method IPrinterMPage.EndMapDocument'''
        return super(IPrinterMPage, self).EndMapDocument()

class IPsPrinter(_esriOutput.IPsPrinter):
    _IID = uuid.UUID('de6dcd82-3f54-11d1-885e-0000f87808ee')

    def __init__(self, *args, **kw):
        super(IPsPrinter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_PPDFile(self, PPDFile):
        '''Method IPsPrinter.put_PPDFile

           INPUT
            PPDFile             : BSTR'''
        return super(IPsPrinter, self).put_PPDFile(PPDFile)
    def get_PPDFile(self):
        '''Method IPsPrinter.get_PPDFile

           OUTPUT
            PPDFile             : BSTR*'''
        return super(IPsPrinter, self).get_PPDFile()
    PPDFile = property(get_PPDFile, put_PPDFile, None)

class IExport(_esriOutput.IExport):
    _IID = uuid.UUID('55c11165-0c2d-4e2d-afea-10b4186c4364')

    def __init__(self, *args, **kw):
        super(IExport, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Name(self):
        '''Method IExport.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IExport, self).get_Name()
    def get_Filter(self):
        '''Method IExport.get_Filter

           OUTPUT
            Filter              : BSTR*'''
        return super(IExport, self).get_Filter()
    def get_Priority(self):
        '''Method IExport.get_Priority

           OUTPUT
            pPriority           : long*'''
        return super(IExport, self).get_Priority()
    def putref_StepProgressor(self, _arg1):
        '''Method IExport.putref_StepProgressor

           INPUT
            _arg1               : IStepProgressor*'''
        return super(IExport, self).putref_StepProgressor(_arg1)
    def putref_TrackCancel(self, _arg1):
        '''Method IExport.putref_TrackCancel

           INPUT
            _arg1               : ITrackCancel*'''
        return super(IExport, self).putref_TrackCancel(_arg1)
    def put_PixelBounds(self, PixelBounds):
        '''Method IExport.put_PixelBounds

           INPUT
            PixelBounds         : IEnvelope*'''
        return super(IExport, self).put_PixelBounds(PixelBounds)
    def get_PixelBounds(self):
        '''Method IExport.get_PixelBounds

           OUTPUT
            PixelBounds         : IEnvelope**'''
        return super(IExport, self).get_PixelBounds()
    def put_ExportFileName(self, fileName):
        '''Method IExport.put_ExportFileName

           INPUT
            fileName            : BSTR'''
        return super(IExport, self).put_ExportFileName(fileName)
    def get_ExportFileName(self):
        '''Method IExport.get_ExportFileName

           OUTPUT
            fileName            : BSTR*'''
        return super(IExport, self).get_ExportFileName()
    def put_Resolution(self, res):
        '''Method IExport.put_Resolution

           INPUT
            res                 : double'''
        return super(IExport, self).put_Resolution(res)
    def get_Resolution(self):
        '''Method IExport.get_Resolution

           OUTPUT
            res                 : double*'''
        return super(IExport, self).get_Resolution()
    def StartExporting(self):
        '''Method IExport.StartExporting

           OUTPUT
            hDC                 : OLE_HANDLE*'''
        return super(IExport, self).StartExporting()
    def FinishExporting(self):
        '''Method IExport.FinishExporting'''
        return super(IExport, self).FinishExporting()
    def Cleanup(self):
        '''Method IExport.Cleanup'''
        return super(IExport, self).Cleanup()
    ExportFileName = property(get_ExportFileName, put_ExportFileName, None)
    Filter = property(get_Filter, None, None)
    Name = property(get_Name, None, None)
    PixelBounds = property(get_PixelBounds, put_PixelBounds, None)
    Priority = property(get_Priority, None, None)
    Resolution = property(get_Resolution, put_Resolution, None)
    StepProgressor = property(None, putref_StepProgressor, None)
    TrackCancel = property(None, putref_TrackCancel, None)

class IExportImage(_esriOutput.IExportImage):
    _IID = uuid.UUID('4bf7d12a-5c15-4671-a9e2-11fce89f0873')

    def __init__(self, *args, **kw):
        super(IExportImage, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ImageType(self, pimageType):
        '''Method IExportImage.put_ImageType

           INPUT
            pimageType          : esriExportImageType'''
        return super(IExportImage, self).put_ImageType(pimageType)
    def get_ImageType(self):
        '''Method IExportImage.get_ImageType

           OUTPUT
            pimageType          : esriExportImageType*'''
        return super(IExportImage, self).get_ImageType()
    def put_BackgroundColor(self, ppBackgroundColor):
        '''Method IExportImage.put_BackgroundColor

           INPUT
            ppBackgroundColor   : IColor*'''
        return super(IExportImage, self).put_BackgroundColor(ppBackgroundColor)
    def get_BackgroundColor(self):
        '''Method IExportImage.get_BackgroundColor

           OUTPUT
            ppBackgroundColor   : IColor**'''
        return super(IExportImage, self).get_BackgroundColor()
    def put_Width(self, pWidth):
        '''Method IExportImage.put_Width

           INPUT
            pWidth              : long'''
        return super(IExportImage, self).put_Width(pWidth)
    def get_Width(self):
        '''Method IExportImage.get_Width

           OUTPUT
            pWidth              : long*'''
        return super(IExportImage, self).get_Width()
    def put_Height(self, pHeight):
        '''Method IExportImage.put_Height

           INPUT
            pHeight             : long'''
        return super(IExportImage, self).put_Height(pHeight)
    def get_Height(self):
        '''Method IExportImage.get_Height

           OUTPUT
            pHeight             : long*'''
        return super(IExportImage, self).get_Height()
    BackgroundColor = property(get_BackgroundColor, put_BackgroundColor, None)
    Height = property(get_Height, put_Height, None)
    ImageType = property(get_ImageType, put_ImageType, None)
    Width = property(get_Width, put_Width, None)

class IExportBMP(_esriOutput.IExportBMP):
    _IID = uuid.UUID('759be840-8eb9-45a0-b511-2a297096344b')

    def __init__(self, *args, **kw):
        super(IExportBMP, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Bitmap(self):
        '''Method IExportBMP.get_Bitmap

           OUTPUT
            phBmp               : OLE_HANDLE*'''
        return super(IExportBMP, self).get_Bitmap()
    def get_Palette(self):
        '''Method IExportBMP.get_Palette

           OUTPUT
            phPal               : OLE_HANDLE*'''
        return super(IExportBMP, self).get_Palette()
    def put_RLECompression(self, compression):
        '''Method IExportBMP.put_RLECompression

           INPUT
            compression         : VARIANT_BOOL'''
        return super(IExportBMP, self).put_RLECompression(compression)
    def get_RLECompression(self):
        '''Method IExportBMP.get_RLECompression

           OUTPUT
            compression         : VARIANT_BOOL*'''
        return super(IExportBMP, self).get_RLECompression()
    def put_BiLevelThreshold(self, threshold):
        '''Method IExportBMP.put_BiLevelThreshold

           INPUT
            threshold           : int'''
        return super(IExportBMP, self).put_BiLevelThreshold(threshold)
    def get_BiLevelThreshold(self):
        '''Method IExportBMP.get_BiLevelThreshold

           OUTPUT
            threshold           : int*'''
        return super(IExportBMP, self).get_BiLevelThreshold()
    BiLevelThreshold = property(get_BiLevelThreshold, put_BiLevelThreshold, None)
    Bitmap = property(get_Bitmap, None, None)
    Palette = property(get_Palette, None, None)
    RLECompression = property(get_RLECompression, put_RLECompression, None)

class IExportJPEG(_esriOutput.IExportJPEG):
    _IID = uuid.UUID('8746bb14-4c79-42f0-b0f1-3327651eb378')

    def __init__(self, *args, **kw):
        super(IExportJPEG, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Quality(self, Quality):
        '''Method IExportJPEG.put_Quality

           INPUT
            Quality             : short'''
        return super(IExportJPEG, self).put_Quality(Quality)
    def get_Quality(self):
        '''Method IExportJPEG.get_Quality

           OUTPUT
            Quality             : short*'''
        return super(IExportJPEG, self).get_Quality()
    def put_ProgressiveMode(self, bprogressive):
        '''Method IExportJPEG.put_ProgressiveMode

           INPUT
            bprogressive        : VARIANT_BOOL'''
        return super(IExportJPEG, self).put_ProgressiveMode(bprogressive)
    def get_ProgressiveMode(self):
        '''Method IExportJPEG.get_ProgressiveMode

           OUTPUT
            bprogressive        : VARIANT_BOOL*'''
        return super(IExportJPEG, self).get_ProgressiveMode()
    ProgressiveMode = property(get_ProgressiveMode, put_ProgressiveMode, None)
    Quality = property(get_Quality, put_Quality, None)

class IExportPNG(_esriOutput.IExportPNG):
    _IID = uuid.UUID('3b12ac60-9d1a-45c8-bde5-a2b4cdced76f')

    def __init__(self, *args, **kw):
        super(IExportPNG, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_InterlaceMode(self, interlace):
        '''Method IExportPNG.put_InterlaceMode

           INPUT
            interlace           : VARIANT_BOOL'''
        return super(IExportPNG, self).put_InterlaceMode(interlace)
    def get_InterlaceMode(self):
        '''Method IExportPNG.get_InterlaceMode

           OUTPUT
            interlace           : VARIANT_BOOL*'''
        return super(IExportPNG, self).get_InterlaceMode()
    def put_TransparentColor(self, Color):
        '''Method IExportPNG.put_TransparentColor

           INPUT
            Color               : IColor*'''
        return super(IExportPNG, self).put_TransparentColor(Color)
    def get_TransparentColor(self):
        '''Method IExportPNG.get_TransparentColor

           OUTPUT
            Color               : IColor**'''
        return super(IExportPNG, self).get_TransparentColor()
    def put_BiLevelThreshold(self, threshold):
        '''Method IExportPNG.put_BiLevelThreshold

           INPUT
            threshold           : int'''
        return super(IExportPNG, self).put_BiLevelThreshold(threshold)
    def get_BiLevelThreshold(self):
        '''Method IExportPNG.get_BiLevelThreshold

           OUTPUT
            threshold           : int*'''
        return super(IExportPNG, self).get_BiLevelThreshold()
    BiLevelThreshold = property(get_BiLevelThreshold, put_BiLevelThreshold, None)
    InterlaceMode = property(get_InterlaceMode, put_InterlaceMode, None)
    TransparentColor = property(get_TransparentColor, put_TransparentColor, None)

class IExportTIFF(_esriOutput.IExportTIFF):
    _IID = uuid.UUID('b13d58c7-603f-4610-8538-5b501908ee26')

    def __init__(self, *args, **kw):
        super(IExportTIFF, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_CompressionType(self, type):
        '''Method IExportTIFF.put_CompressionType

           INPUT
            type                : esriTIFFCompression'''
        return super(IExportTIFF, self).put_CompressionType(type)
    def get_CompressionType(self):
        '''Method IExportTIFF.get_CompressionType

           OUTPUT
            type                : esriTIFFCompression*'''
        return super(IExportTIFF, self).get_CompressionType()
    def put_GeoTiff(self, bGeoTiff):
        '''Method IExportTIFF.put_GeoTiff

           INPUT
            bGeoTiff            : VARIANT_BOOL'''
        return super(IExportTIFF, self).put_GeoTiff(bGeoTiff)
    def get_GeoTiff(self):
        '''Method IExportTIFF.get_GeoTiff

           OUTPUT
            bGeoTiff            : VARIANT_BOOL*'''
        return super(IExportTIFF, self).get_GeoTiff()
    def put_JPEGOrDeflateQuality(self, Quality):
        '''Method IExportTIFF.put_JPEGOrDeflateQuality

           INPUT
            Quality             : short'''
        return super(IExportTIFF, self).put_JPEGOrDeflateQuality(Quality)
    def get_JPEGOrDeflateQuality(self):
        '''Method IExportTIFF.get_JPEGOrDeflateQuality

           OUTPUT
            Quality             : short*'''
        return super(IExportTIFF, self).get_JPEGOrDeflateQuality()
    def put_BiLevelThreshold(self, threshold):
        '''Method IExportTIFF.put_BiLevelThreshold

           INPUT
            threshold           : int'''
        return super(IExportTIFF, self).put_BiLevelThreshold(threshold)
    def get_BiLevelThreshold(self):
        '''Method IExportTIFF.get_BiLevelThreshold

           OUTPUT
            threshold           : int*'''
        return super(IExportTIFF, self).get_BiLevelThreshold()
    BiLevelThreshold = property(get_BiLevelThreshold, put_BiLevelThreshold, None)
    CompressionType = property(get_CompressionType, put_CompressionType, None)
    GeoTiff = property(get_GeoTiff, put_GeoTiff, None)
    JPEGOrDeflateQuality = property(get_JPEGOrDeflateQuality, put_JPEGOrDeflateQuality, None)

class IExportGIF(_esriOutput.IExportGIF):
    _IID = uuid.UUID('6c43ec0f-352c-42ef-9bd6-83d37529e3e5')

    def __init__(self, *args, **kw):
        super(IExportGIF, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_InterlaceMode(self, interlace):
        '''Method IExportGIF.put_InterlaceMode

           INPUT
            interlace           : VARIANT_BOOL'''
        return super(IExportGIF, self).put_InterlaceMode(interlace)
    def get_InterlaceMode(self):
        '''Method IExportGIF.get_InterlaceMode

           OUTPUT
            interlace           : VARIANT_BOOL*'''
        return super(IExportGIF, self).get_InterlaceMode()
    def put_CompressionType(self, type):
        '''Method IExportGIF.put_CompressionType

           INPUT
            type                : esriGIFCompression'''
        return super(IExportGIF, self).put_CompressionType(type)
    def get_CompressionType(self):
        '''Method IExportGIF.get_CompressionType

           OUTPUT
            type                : esriGIFCompression*'''
        return super(IExportGIF, self).get_CompressionType()
    def put_TransparentColor(self, Color):
        '''Method IExportGIF.put_TransparentColor

           INPUT
            Color               : IColor*'''
        return super(IExportGIF, self).put_TransparentColor(Color)
    def get_TransparentColor(self):
        '''Method IExportGIF.get_TransparentColor

           OUTPUT
            Color               : IColor**'''
        return super(IExportGIF, self).get_TransparentColor()
    def put_BiLevelThreshold(self, threshold):
        '''Method IExportGIF.put_BiLevelThreshold

           INPUT
            threshold           : int'''
        return super(IExportGIF, self).put_BiLevelThreshold(threshold)
    def get_BiLevelThreshold(self):
        '''Method IExportGIF.get_BiLevelThreshold

           OUTPUT
            threshold           : int*'''
        return super(IExportGIF, self).get_BiLevelThreshold()
    BiLevelThreshold = property(get_BiLevelThreshold, put_BiLevelThreshold, None)
    CompressionType = property(get_CompressionType, put_CompressionType, None)
    InterlaceMode = property(get_InterlaceMode, put_InterlaceMode, None)
    TransparentColor = property(get_TransparentColor, put_TransparentColor, None)

class IExportVectorOptions(_esriOutput.IExportVectorOptions):
    _IID = uuid.UUID('1c16bcac-81dd-4662-a6ab-810a205fc645')

    def __init__(self, *args, **kw):
        super(IExportVectorOptions, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_PolygonizeMarkers(self, bPolygonizeMarkers):
        '''Method IExportVectorOptions.put_PolygonizeMarkers

           INPUT
            bPolygonizeMarkers  : VARIANT_BOOL'''
        return super(IExportVectorOptions, self).put_PolygonizeMarkers(bPolygonizeMarkers)
    def get_PolygonizeMarkers(self):
        '''Method IExportVectorOptions.get_PolygonizeMarkers

           OUTPUT
            bPolygonizeMarkers  : VARIANT_BOOL*'''
        return super(IExportVectorOptions, self).get_PolygonizeMarkers()
    def put_MaxVertexNumber(self, lMaxVertices):
        '''Method IExportVectorOptions.put_MaxVertexNumber

           INPUT
            lMaxVertices        : long'''
        return super(IExportVectorOptions, self).put_MaxVertexNumber(lMaxVertices)
    def get_MaxVertexNumber(self):
        '''Method IExportVectorOptions.get_MaxVertexNumber

           OUTPUT
            lMaxVertices        : long*'''
        return super(IExportVectorOptions, self).get_MaxVertexNumber()
    MaxVertexNumber = property(get_MaxVertexNumber, put_MaxVertexNumber, None)
    PolygonizeMarkers = property(get_PolygonizeMarkers, put_PolygonizeMarkers, None)

class IExportVectorOptionsEx(_esriOutput.IExportVectorOptionsEx):
    _IID = uuid.UUID('ccf50555-74e3-4f29-9ffe-1fc489d1552c')

    def __init__(self, *args, **kw):
        super(IExportVectorOptionsEx, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ExportPictureSymbolOptions(self, opt):
        '''Method IExportVectorOptionsEx.put_ExportPictureSymbolOptions

           INPUT
            opt                 : esriPictureSymbolOptions'''
        return super(IExportVectorOptionsEx, self).put_ExportPictureSymbolOptions(opt)
    def get_ExportPictureSymbolOptions(self):
        '''Method IExportVectorOptionsEx.get_ExportPictureSymbolOptions

           OUTPUT
            opt                 : esriPictureSymbolOptions*'''
        return super(IExportVectorOptionsEx, self).get_ExportPictureSymbolOptions()
    ExportPictureSymbolOptions = property(get_ExportPictureSymbolOptions, put_ExportPictureSymbolOptions, None)

class IExportEMF(_esriOutput.IExportEMF):
    _IID = uuid.UUID('94123bcd-eae7-42a9-9fef-d09a57b87a0f')

    def __init__(self, *args, **kw):
        super(IExportEMF, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Handle(self):
        '''Method IExportEMF.get_Handle

           OUTPUT
            pHandle             : OLE_HANDLE*'''
        return super(IExportEMF, self).get_Handle()
    def put_Description(self, pDescription):
        '''Method IExportEMF.put_Description

           INPUT
            pDescription        : BSTR'''
        return super(IExportEMF, self).put_Description(pDescription)
    def get_Description(self):
        '''Method IExportEMF.get_Description

           OUTPUT
            pDescription        : BSTR*'''
        return super(IExportEMF, self).get_Description()
    Description = property(get_Description, put_Description, None)
    Handle = property(get_Handle, None, None)

class IExportPS(_esriOutput.IExportPS):
    _IID = uuid.UUID('efcd8d47-8d2a-47a4-b35b-15ca74bce73c')

    def __init__(self, *args, **kw):
        super(IExportPS, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_Emulsion(self, Emulsion):
        '''Method IExportPS.put_Emulsion

           INPUT
            Emulsion            : esriExportPSEmulsion'''
        return super(IExportPS, self).put_Emulsion(Emulsion)
    def get_Emulsion(self):
        '''Method IExportPS.get_Emulsion

           OUTPUT
            Emulsion            : esriExportPSEmulsion*'''
        return super(IExportPS, self).get_Emulsion()
    def put_Image(self, Image):
        '''Method IExportPS.put_Image

           INPUT
            Image               : esriExportPSImage'''
        return super(IExportPS, self).put_Image(Image)
    def get_Image(self):
        '''Method IExportPS.get_Image

           OUTPUT
            Image               : esriExportPSImage*'''
        return super(IExportPS, self).get_Image()
    def put_LanguageLevel(self, pslevel):
        '''Method IExportPS.put_LanguageLevel

           INPUT
            pslevel             : esriExportPSLanguageLevel'''
        return super(IExportPS, self).put_LanguageLevel(pslevel)
    def get_LanguageLevel(self):
        '''Method IExportPS.get_LanguageLevel

           OUTPUT
            pslevel             : esriExportPSLanguageLevel*'''
        return super(IExportPS, self).get_LanguageLevel()
    def put_ImageCompression(self, compression):
        '''Method IExportPS.put_ImageCompression

           INPUT
            compression         : esriExportImageCompression'''
        return super(IExportPS, self).put_ImageCompression(compression)
    def get_ImageCompression(self):
        '''Method IExportPS.get_ImageCompression

           OUTPUT
            compression         : esriExportImageCompression*'''
        return super(IExportPS, self).get_ImageCompression()
    def put_EmbedFonts(self, EmbedFonts):
        '''Method IExportPS.put_EmbedFonts

           INPUT
            EmbedFonts          : VARIANT_BOOL'''
        return super(IExportPS, self).put_EmbedFonts(EmbedFonts)
    def get_EmbedFonts(self):
        '''Method IExportPS.get_EmbedFonts

           OUTPUT
            EmbedFonts          : VARIANT_BOOL*'''
        return super(IExportPS, self).get_EmbedFonts()
    EmbedFonts = property(get_EmbedFonts, put_EmbedFonts, None)
    Emulsion = property(get_Emulsion, put_Emulsion, None)
    Image = property(get_Image, put_Image, None)
    ImageCompression = property(get_ImageCompression, put_ImageCompression, None)
    LanguageLevel = property(get_LanguageLevel, put_LanguageLevel, None)

class IExportPS2(_esriOutput.IExportPS2):
    _IID = uuid.UUID('36ce3f37-30c9-4544-afa6-89a7315abce7')

    def __init__(self, *args, **kw):
        super(IExportPS2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_JPEGCompressionQuality(self, pImageQuality):
        '''Method IExportPS2.put_JPEGCompressionQuality

           INPUT
            pImageQuality       : short'''
        return super(IExportPS2, self).put_JPEGCompressionQuality(pImageQuality)
    def get_JPEGCompressionQuality(self):
        '''Method IExportPS2.get_JPEGCompressionQuality

           OUTPUT
            pImageQuality       : short*'''
        return super(IExportPS2, self).get_JPEGCompressionQuality()
    JPEGCompressionQuality = property(get_JPEGCompressionQuality, put_JPEGCompressionQuality, None)

class IExportPDF(_esriOutput.IExportPDF):
    _IID = uuid.UUID('6a2a0820-e1b6-4eb0-af9b-6449dae7a952')

    def __init__(self, *args, **kw):
        super(IExportPDF, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Compressed(self):
        '''Method IExportPDF.get_Compressed

           OUTPUT
            Compressed          : VARIANT_BOOL*'''
        return super(IExportPDF, self).get_Compressed()
    def put_Compressed(self, Compressed):
        '''Method IExportPDF.put_Compressed

           INPUT
            Compressed          : VARIANT_BOOL'''
        return super(IExportPDF, self).put_Compressed(Compressed)
    def put_ImageCompression(self, compression):
        '''Method IExportPDF.put_ImageCompression

           INPUT
            compression         : esriExportImageCompression'''
        return super(IExportPDF, self).put_ImageCompression(compression)
    def get_ImageCompression(self):
        '''Method IExportPDF.get_ImageCompression

           OUTPUT
            compression         : esriExportImageCompression*'''
        return super(IExportPDF, self).get_ImageCompression()
    def put_EmbedFonts(self, EmbedFonts):
        '''Method IExportPDF.put_EmbedFonts

           INPUT
            EmbedFonts          : VARIANT_BOOL'''
        return super(IExportPDF, self).put_EmbedFonts(EmbedFonts)
    def get_EmbedFonts(self):
        '''Method IExportPDF.get_EmbedFonts

           OUTPUT
            EmbedFonts          : VARIANT_BOOL*'''
        return super(IExportPDF, self).get_EmbedFonts()
    Compressed = property(get_Compressed, put_Compressed, None)
    EmbedFonts = property(get_EmbedFonts, put_EmbedFonts, None)
    ImageCompression = property(get_ImageCompression, put_ImageCompression, None)

class IExportPDF2(_esriOutput.IExportPDF2):
    _IID = uuid.UUID('86d86855-631d-4a75-ad19-725b460208c7')

    def __init__(self, *args, **kw):
        super(IExportPDF2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ExportPDFLayersAndFeatureAttributes(self, pOption):
        '''Method IExportPDF2.put_ExportPDFLayersAndFeatureAttributes

           INPUT
            pOption             : esriExportPDFLayerOptions'''
        return super(IExportPDF2, self).put_ExportPDFLayersAndFeatureAttributes(pOption)
    def get_ExportPDFLayersAndFeatureAttributes(self):
        '''Method IExportPDF2.get_ExportPDFLayersAndFeatureAttributes

           OUTPUT
            pOption             : esriExportPDFLayerOptions*'''
        return super(IExportPDF2, self).get_ExportPDFLayersAndFeatureAttributes()
    def put_ExportMeasureInfo(self, pbMeasureInformation):
        '''Method IExportPDF2.put_ExportMeasureInfo

           INPUT
            pbMeasureInformation: VARIANT_BOOL'''
        return super(IExportPDF2, self).put_ExportMeasureInfo(pbMeasureInformation)
    def get_ExportMeasureInfo(self):
        '''Method IExportPDF2.get_ExportMeasureInfo

           OUTPUT
            pbMeasureInformation: VARIANT_BOOL*'''
        return super(IExportPDF2, self).get_ExportMeasureInfo()
    ExportMeasureInfo = property(get_ExportMeasureInfo, put_ExportMeasureInfo, None)
    ExportPDFLayersAndFeatureAttributes = property(get_ExportPDFLayersAndFeatureAttributes, put_ExportPDFLayersAndFeatureAttributes, None)

class IExportPDF3(_esriOutput.IExportPDF3):
    _IID = uuid.UUID('083bc81c-e835-4103-aad6-454aa037966b')

    def __init__(self, *args, **kw):
        super(IExportPDF3, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_JPEGCompressionQuality(self, pImageQuality):
        '''Method IExportPDF3.put_JPEGCompressionQuality

           INPUT
            pImageQuality       : short'''
        return super(IExportPDF3, self).put_JPEGCompressionQuality(pImageQuality)
    def get_JPEGCompressionQuality(self):
        '''Method IExportPDF3.get_JPEGCompressionQuality

           OUTPUT
            pImageQuality       : short*'''
        return super(IExportPDF3, self).get_JPEGCompressionQuality()
    JPEGCompressionQuality = property(get_JPEGCompressionQuality, put_JPEGCompressionQuality, None)

class IExportPagesMultipleFile(_esriOutput.IExportPagesMultipleFile):
    _IID = uuid.UUID('1a551946-895a-4809-80d8-d417d654f3ac')

    def __init__(self, *args, **kw):
        super(IExportPagesMultipleFile, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_MultipleFileOutput(self, pOption):
        '''Method IExportPagesMultipleFile.put_MultipleFileOutput

           INPUT
            pOption             : esriExportMultipleFiles'''
        return super(IExportPagesMultipleFile, self).put_MultipleFileOutput(pOption)
    def get_MultipleFileOutput(self):
        '''Method IExportPagesMultipleFile.get_MultipleFileOutput

           OUTPUT
            pOption             : esriExportMultipleFiles*'''
        return super(IExportPagesMultipleFile, self).get_MultipleFileOutput()
    MultipleFileOutput = property(get_MultipleFileOutput, put_MultipleFileOutput, None)

class IExportAI(_esriOutput.IExportAI):
    _IID = uuid.UUID('69822e67-c74b-4138-ab20-aa4e00cb87dd')

    def __init__(self, *args, **kw):
        super(IExportAI, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_EmbedFonts(self, EmbedFonts):
        '''Method IExportAI.put_EmbedFonts

           INPUT
            EmbedFonts          : VARIANT_BOOL'''
        return super(IExportAI, self).put_EmbedFonts(EmbedFonts)
    def get_EmbedFonts(self):
        '''Method IExportAI.get_EmbedFonts

           OUTPUT
            EmbedFonts          : VARIANT_BOOL*'''
        return super(IExportAI, self).get_EmbedFonts()
    EmbedFonts = property(get_EmbedFonts, put_EmbedFonts, None)

class IExportAI2(_esriOutput.IExportAI2):
    _IID = uuid.UUID('0ab19cc6-7c0b-4916-8d8d-8b6b9c4e4a8a')

    def __init__(self, *args, **kw):
        super(IExportAI2, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ExportFeatureName(self, pExportAttrs):
        '''Method IExportAI2.put_ExportFeatureName

           INPUT
            pExportAttrs        : VARIANT_BOOL'''
        return super(IExportAI2, self).put_ExportFeatureName(pExportAttrs)
    def get_ExportFeatureName(self):
        '''Method IExportAI2.get_ExportFeatureName

           OUTPUT
            pExportAttrs        : VARIANT_BOOL*'''
        return super(IExportAI2, self).get_ExportFeatureName()
    ExportFeatureName = property(get_ExportFeatureName, put_ExportFeatureName, None)

class IExportSVG(_esriOutput.IExportSVG):
    _IID = uuid.UUID('0a149c8e-5d95-4a5c-9f48-5d30b3f12fa2')

    def __init__(self, *args, **kw):
        super(IExportSVG, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Compressed(self):
        '''Method IExportSVG.get_Compressed

           OUTPUT
            Compressed          : VARIANT_BOOL*'''
        return super(IExportSVG, self).get_Compressed()
    def put_Compressed(self, Compressed):
        '''Method IExportSVG.put_Compressed

           INPUT
            Compressed          : VARIANT_BOOL'''
        return super(IExportSVG, self).put_Compressed(Compressed)
    def put_EmbedFonts(self, EmbedFonts):
        '''Method IExportSVG.put_EmbedFonts

           INPUT
            EmbedFonts          : VARIANT_BOOL'''
        return super(IExportSVG, self).put_EmbedFonts(EmbedFonts)
    def get_EmbedFonts(self):
        '''Method IExportSVG.get_EmbedFonts

           OUTPUT
            EmbedFonts          : VARIANT_BOOL*'''
        return super(IExportSVG, self).get_EmbedFonts()
    Compressed = property(get_Compressed, put_Compressed, None)
    EmbedFonts = property(get_EmbedFonts, put_EmbedFonts, None)

class IExportPDFPasswordSecurity(_esriOutput.IExportPDFPasswordSecurity):
    _IID = uuid.UUID('6c9a13e6-f9ec-4ebf-af52-bb1d822622df')

    def __init__(self, *args, **kw):
        super(IExportPDFPasswordSecurity, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_UserPassword(self, pPasswd):
        '''Method IExportPDFPasswordSecurity.put_UserPassword

           INPUT
            pPasswd             : BSTR'''
        return super(IExportPDFPasswordSecurity, self).put_UserPassword(pPasswd)
    def get_UserPassword(self):
        '''Method IExportPDFPasswordSecurity.get_UserPassword

           OUTPUT
            pPasswd             : BSTR*'''
        return super(IExportPDFPasswordSecurity, self).get_UserPassword()
    def put_MasterPassword(self, pPasswd):
        '''Method IExportPDFPasswordSecurity.put_MasterPassword

           INPUT
            pPasswd             : BSTR'''
        return super(IExportPDFPasswordSecurity, self).put_MasterPassword(pPasswd)
    def get_MasterPassword(self):
        '''Method IExportPDFPasswordSecurity.get_MasterPassword

           OUTPUT
            pPasswd             : BSTR*'''
        return super(IExportPDFPasswordSecurity, self).get_MasterPassword()
    def put_SecurityPermissions(self, pPermission):
        '''Method IExportPDFPasswordSecurity.put_SecurityPermissions

           INPUT
            pPermission         : long'''
        return super(IExportPDFPasswordSecurity, self).put_SecurityPermissions(pPermission)
    def get_SecurityPermissions(self):
        '''Method IExportPDFPasswordSecurity.get_SecurityPermissions

           OUTPUT
            pPermission         : long*'''
        return super(IExportPDFPasswordSecurity, self).get_SecurityPermissions()
    def put_SecurityEncryptionOption(self, pEncryptionOption):
        '''Method IExportPDFPasswordSecurity.put_SecurityEncryptionOption

           INPUT
            pEncryptionOption   : esriPDFExtensionSecurityEncryptionOption'''
        return super(IExportPDFPasswordSecurity, self).put_SecurityEncryptionOption(pEncryptionOption)
    def get_SecurityEncryptionOption(self):
        '''Method IExportPDFPasswordSecurity.get_SecurityEncryptionOption

           OUTPUT
            pEncryptionOption   : esriPDFExtensionSecurityEncryptionOption*'''
        return super(IExportPDFPasswordSecurity, self).get_SecurityEncryptionOption()
    def put_SecurityEncryptionMethod(self, pEncryptionMethod):
        '''Method IExportPDFPasswordSecurity.put_SecurityEncryptionMethod

           INPUT
            pEncryptionMethod   : esriPDFExtensionSecurityEncryptionMethod'''
        return super(IExportPDFPasswordSecurity, self).put_SecurityEncryptionMethod(pEncryptionMethod)
    def get_SecurityEncryptionMethod(self):
        '''Method IExportPDFPasswordSecurity.get_SecurityEncryptionMethod

           OUTPUT
            pEncryptionMethod   : esriPDFExtensionSecurityEncryptionMethod*'''
        return super(IExportPDFPasswordSecurity, self).get_SecurityEncryptionMethod()
    MasterPassword = property(get_MasterPassword, put_MasterPassword, None)
    SecurityEncryptionMethod = property(get_SecurityEncryptionMethod, put_SecurityEncryptionMethod, None)
    SecurityEncryptionOption = property(get_SecurityEncryptionOption, put_SecurityEncryptionOption, None)
    SecurityPermissions = property(get_SecurityPermissions, put_SecurityPermissions, None)
    UserPassword = property(get_UserPassword, put_UserPassword, None)

class IDibExporter(_esriOutput.IDibExporter):
    _IID = uuid.UUID('7d4881e5-57c6-11d1-945e-080009eebecb')

    def __init__(self, *args, **kw):
        super(IDibExporter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_IsInMemory(self, pIsInMemory):
        '''Method IDibExporter.put_IsInMemory

           INPUT
            pIsInMemory         : VARIANT_BOOL'''
        return super(IDibExporter, self).put_IsInMemory(pIsInMemory)
    def get_IsInMemory(self):
        '''Method IDibExporter.get_IsInMemory

           OUTPUT
            pIsInMemory         : VARIANT_BOOL*'''
        return super(IDibExporter, self).get_IsInMemory()
    def get_HDIB(self):
        '''Method IDibExporter.get_HDIB

           OUTPUT
            pHandle             : OLE_HANDLE*'''
        return super(IDibExporter, self).get_HDIB()
    def put_BitsPerPixel(self, pBitsPerPixel):
        '''Method IDibExporter.put_BitsPerPixel

           INPUT
            pBitsPerPixel       : short'''
        return super(IDibExporter, self).put_BitsPerPixel(pBitsPerPixel)
    def get_BitsPerPixel(self):
        '''Method IDibExporter.get_BitsPerPixel

           OUTPUT
            pBitsPerPixel       : short*'''
        return super(IDibExporter, self).get_BitsPerPixel()
    def put_BackgroundColor(self, ppBackgroundColor):
        '''Method IDibExporter.put_BackgroundColor

           INPUT
            ppBackgroundColor   : IColor*'''
        return super(IDibExporter, self).put_BackgroundColor(ppBackgroundColor)
    def get_BackgroundColor(self):
        '''Method IDibExporter.get_BackgroundColor

           OUTPUT
            ppBackgroundColor   : IColor**'''
        return super(IDibExporter, self).get_BackgroundColor()
    def put_Width(self, pWidth):
        '''Method IDibExporter.put_Width

           INPUT
            pWidth              : short'''
        return super(IDibExporter, self).put_Width(pWidth)
    def get_Width(self):
        '''Method IDibExporter.get_Width

           OUTPUT
            pWidth              : short*'''
        return super(IDibExporter, self).get_Width()
    def put_Height(self, pHeight):
        '''Method IDibExporter.put_Height

           INPUT
            pHeight             : short'''
        return super(IDibExporter, self).put_Height(pHeight)
    def get_Height(self):
        '''Method IDibExporter.get_Height

           OUTPUT
            pHeight             : short*'''
        return super(IDibExporter, self).get_Height()
    BackgroundColor = property(get_BackgroundColor, put_BackgroundColor, None)
    BitsPerPixel = property(get_BitsPerPixel, put_BitsPerPixel, None)
    HDIB = property(get_HDIB, None, None)
    Height = property(get_Height, put_Height, None)
    IsInMemory = property(get_IsInMemory, put_IsInMemory, None)
    Width = property(get_Width, put_Width, None)

class IJpegExporter(_esriOutput.IJpegExporter):
    _IID = uuid.UUID('511ff079-55c4-11d3-9ffd-00c04f6bc8dd')

    def __init__(self, *args, **kw):
        super(IJpegExporter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_BackgroundColor(self, ppBackgroundColor):
        '''Method IJpegExporter.put_BackgroundColor

           INPUT
            ppBackgroundColor   : IColor*'''
        return super(IJpegExporter, self).put_BackgroundColor(ppBackgroundColor)
    def get_BackgroundColor(self):
        '''Method IJpegExporter.get_BackgroundColor

           OUTPUT
            ppBackgroundColor   : IColor**'''
        return super(IJpegExporter, self).get_BackgroundColor()
    def put_Width(self, pWidth):
        '''Method IJpegExporter.put_Width

           INPUT
            pWidth              : short'''
        return super(IJpegExporter, self).put_Width(pWidth)
    def get_Width(self):
        '''Method IJpegExporter.get_Width

           OUTPUT
            pWidth              : short*'''
        return super(IJpegExporter, self).get_Width()
    def put_Height(self, pHeight):
        '''Method IJpegExporter.put_Height

           INPUT
            pHeight             : short'''
        return super(IJpegExporter, self).put_Height(pHeight)
    def get_Height(self):
        '''Method IJpegExporter.get_Height

           OUTPUT
            pHeight             : short*'''
        return super(IJpegExporter, self).get_Height()
    def put_Quality(self, Quality):
        '''Method IJpegExporter.put_Quality

           INPUT
            Quality             : short'''
        return super(IJpegExporter, self).put_Quality(Quality)
    def get_Quality(self):
        '''Method IJpegExporter.get_Quality

           OUTPUT
            Quality             : short*'''
        return super(IJpegExporter, self).get_Quality()
    BackgroundColor = property(get_BackgroundColor, put_BackgroundColor, None)
    Height = property(get_Height, put_Height, None)
    Quality = property(get_Quality, put_Quality, None)
    Width = property(get_Width, put_Width, None)

class IBmpExporter(_esriOutput.IBmpExporter):
    _IID = uuid.UUID('4c59f34d-db32-11d3-9ff6-00c04f6bc8dd')
    def get_Bitmap(self):
        '''Method IBmpExporter.get_Bitmap

           OUTPUT
            hBmp                : OLE_HANDLE*'''
        return super(IBmpExporter, self).get_Bitmap()
    def get_Palette(self):
        '''Method IBmpExporter.get_Palette

           OUTPUT
            hPal                : OLE_HANDLE*'''
        return super(IBmpExporter, self).get_Palette()
    Bitmap = property(get_Bitmap, None, None)
    Palette = property(get_Palette, None, None)

class ITiffExporter(_esriOutput.ITiffExporter):
    _IID = uuid.UUID('71001418-565a-4588-90b7-3ffb04b74be7')

    def __init__(self, *args, **kw):
        super(ITiffExporter, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_BackgroundColor(self, ppBackgroundColor):
        '''Method ITiffExporter.put_BackgroundColor

           INPUT
            ppBackgroundColor   : IColor*'''
        return super(ITiffExporter, self).put_BackgroundColor(ppBackgroundColor)
    def get_BackgroundColor(self):
        '''Method ITiffExporter.get_BackgroundColor

           OUTPUT
            ppBackgroundColor   : IColor**'''
        return super(ITiffExporter, self).get_BackgroundColor()
    def put_Width(self, pWidth):
        '''Method ITiffExporter.put_Width

           INPUT
            pWidth              : short'''
        return super(ITiffExporter, self).put_Width(pWidth)
    def get_Width(self):
        '''Method ITiffExporter.get_Width

           OUTPUT
            pWidth              : short*'''
        return super(ITiffExporter, self).get_Width()
    def put_Height(self, pHeight):
        '''Method ITiffExporter.put_Height

           INPUT
            pHeight             : short'''
        return super(ITiffExporter, self).put_Height(pHeight)
    def get_Height(self):
        '''Method ITiffExporter.get_Height

           OUTPUT
            pHeight             : short*'''
        return super(ITiffExporter, self).get_Height()
    BackgroundColor = property(get_BackgroundColor, put_BackgroundColor, None)
    Height = property(get_Height, put_Height, None)
    Width = property(get_Width, put_Width, None)


# IIDs
IID_IFontMap = IFontMap._IID
IID_IFontMap2 = IFontMap2._IID
IID_IFontMapCollection = IFontMapCollection._IID
IID_IFontMapEnvironment = IFontMapEnvironment._IID
IID_IExporter = IExporter._IID
IID_IExporter2 = IExporter2._IID
IID_IExporterPriority = IExporterPriority._IID
IID_IOutputCleanup = IOutputCleanup._IID
IID_IWorldFileSettings = IWorldFileSettings._IID
IID_IWorldFileSettings2 = IWorldFileSettings2._IID
IID_IStepProgressorSetup = IStepProgressorSetup._IID
IID_ITrackCancelSetup = ITrackCancelSetup._IID
IID_ISettingsInRegistry = ISettingsInRegistry._IID
IID_IExportColorspaceSettings = IExportColorspaceSettings._IID
IID_IPrintAndExportPageOptions = IPrintAndExportPageOptions._IID
IID_IEmfExporter = IEmfExporter._IID
IID_ISpotPlate = ISpotPlate._IID
IID_ISpotPlateCollection = ISpotPlateCollection._IID
IID_IColorCorrection = IColorCorrection._IID
IID_IPSDriver = IPSDriver._IID
IID_IPSDriver2 = IPSDriver2._IID
IID_IPsExporter = IPsExporter._IID
IID_IOutputPageOptionsAdmin = IOutputPageOptionsAdmin._IID
IID_IPDFDriver = IPDFDriver._IID
IID_IAIDriver = IAIDriver._IID
IID_IAIExporter = IAIExporter._IID
IID_IPaper = IPaper._IID
IID_IPaper2 = IPaper2._IID
IID_IPrinter = IPrinter._IID
IID_IPrinterMPage = IPrinterMPage._IID
IID_IPsPrinter = IPsPrinter._IID
IID_IExport = IExport._IID
IID_IExportImage = IExportImage._IID
IID_IExportBMP = IExportBMP._IID
IID_IExportJPEG = IExportJPEG._IID
IID_IExportPNG = IExportPNG._IID
IID_IExportTIFF = IExportTIFF._IID
IID_IExportGIF = IExportGIF._IID
IID_IExportVectorOptions = IExportVectorOptions._IID
IID_IExportVectorOptionsEx = IExportVectorOptionsEx._IID
IID_IExportEMF = IExportEMF._IID
IID_IExportPS = IExportPS._IID
IID_IExportPS2 = IExportPS2._IID
IID_IExportPDF = IExportPDF._IID
IID_IExportPDF2 = IExportPDF2._IID
IID_IExportPDF3 = IExportPDF3._IID
IID_IExportPagesMultipleFile = IExportPagesMultipleFile._IID
IID_IExportAI = IExportAI._IID
IID_IExportAI2 = IExportAI2._IID
IID_IExportSVG = IExportSVG._IID
IID_IExportPDFPasswordSecurity = IExportPDFPasswordSecurity._IID
IID_IDibExporter = IDibExporter._IID
IID_IJpegExporter = IJpegExporter._IID
IID_IBmpExporter = IBmpExporter._IID
IID_ITiffExporter = ITiffExporter._IID
_IIDMap[IID_IFontMap] = IFontMap
_IIDMap[IID_IFontMap2] = IFontMap2
_IIDMap[IID_IFontMapCollection] = IFontMapCollection
_IIDMap[IID_IFontMapEnvironment] = IFontMapEnvironment
_IIDMap[IID_IExporter] = IExporter
_IIDMap[IID_IExporter2] = IExporter2
_IIDMap[IID_IExporterPriority] = IExporterPriority
_IIDMap[IID_IOutputCleanup] = IOutputCleanup
_IIDMap[IID_IWorldFileSettings] = IWorldFileSettings
_IIDMap[IID_IWorldFileSettings2] = IWorldFileSettings2
_IIDMap[IID_IStepProgressorSetup] = IStepProgressorSetup
_IIDMap[IID_ITrackCancelSetup] = ITrackCancelSetup
_IIDMap[IID_ISettingsInRegistry] = ISettingsInRegistry
_IIDMap[IID_IExportColorspaceSettings] = IExportColorspaceSettings
_IIDMap[IID_IPrintAndExportPageOptions] = IPrintAndExportPageOptions
_IIDMap[IID_IEmfExporter] = IEmfExporter
_IIDMap[IID_ISpotPlate] = ISpotPlate
_IIDMap[IID_ISpotPlateCollection] = ISpotPlateCollection
_IIDMap[IID_IColorCorrection] = IColorCorrection
_IIDMap[IID_IPSDriver] = IPSDriver
_IIDMap[IID_IPSDriver2] = IPSDriver2
_IIDMap[IID_IPsExporter] = IPsExporter
_IIDMap[IID_IOutputPageOptionsAdmin] = IOutputPageOptionsAdmin
_IIDMap[IID_IPDFDriver] = IPDFDriver
_IIDMap[IID_IAIDriver] = IAIDriver
_IIDMap[IID_IAIExporter] = IAIExporter
_IIDMap[IID_IPaper] = IPaper
_IIDMap[IID_IPaper2] = IPaper2
_IIDMap[IID_IPrinter] = IPrinter
_IIDMap[IID_IPrinterMPage] = IPrinterMPage
_IIDMap[IID_IPsPrinter] = IPsPrinter
_IIDMap[IID_IExport] = IExport
_IIDMap[IID_IExportImage] = IExportImage
_IIDMap[IID_IExportBMP] = IExportBMP
_IIDMap[IID_IExportJPEG] = IExportJPEG
_IIDMap[IID_IExportPNG] = IExportPNG
_IIDMap[IID_IExportTIFF] = IExportTIFF
_IIDMap[IID_IExportGIF] = IExportGIF
_IIDMap[IID_IExportVectorOptions] = IExportVectorOptions
_IIDMap[IID_IExportVectorOptionsEx] = IExportVectorOptionsEx
_IIDMap[IID_IExportEMF] = IExportEMF
_IIDMap[IID_IExportPS] = IExportPS
_IIDMap[IID_IExportPS2] = IExportPS2
_IIDMap[IID_IExportPDF] = IExportPDF
_IIDMap[IID_IExportPDF2] = IExportPDF2
_IIDMap[IID_IExportPDF3] = IExportPDF3
_IIDMap[IID_IExportPagesMultipleFile] = IExportPagesMultipleFile
_IIDMap[IID_IExportAI] = IExportAI
_IIDMap[IID_IExportAI2] = IExportAI2
_IIDMap[IID_IExportSVG] = IExportSVG
_IIDMap[IID_IExportPDFPasswordSecurity] = IExportPDFPasswordSecurity
_IIDMap[IID_IDibExporter] = IDibExporter
_IIDMap[IID_IJpegExporter] = IJpegExporter
_IIDMap[IID_IBmpExporter] = IBmpExporter
_IIDMap[IID_ITiffExporter] = ITiffExporter


# CLSIDs
CLSID_FontMap = uuid.UUID('0710508f-2d9e-11d3-9fc6-00c04f6bc8dd')
CLSID_FontMapCollection = uuid.UUID('eb0e7543-2d97-11d3-9fc6-00c04f6bc8dd')
CLSID_FontMapEnvironment = uuid.UUID('9ecb85b1-6caa-11d3-b685-0080c8ea4fd5')
CLSID_PrintAndExportPageOptions = uuid.UUID('36673b39-2ecf-4bb9-8304-98f58d829054')
CLSID_EmfExporter = uuid.UUID('20cd4011-8f3d-11d0-8590-0800091a2a72')
CLSID_PSDriver = uuid.UUID('cd754683-a222-11d0-a68f-080009d57b9a')
CLSID_PsExporter = uuid.UUID('20cd4014-8f3d-11d0-8590-0800091a2a72')
CLSID_SpotPlate = uuid.UUID('481614e5-9407-11d1-9127-0000f87808ee')
CLSID_PDFDriver = uuid.UUID('02016031-1521-11d3-9f97-00c04f6bc8dd')
CLSID_PDFExporter = uuid.UUID('4aa8cc0e-151d-11d3-9f97-00c04f6bc8dd')
CLSID_AIDriver = uuid.UUID('2bd83bf2-eca7-4b7f-9b41-3ad52eae1b1d')
CLSID_AIExporter = uuid.UUID('94512290-b913-4a0b-a509-03f803f19922')
CLSID_Paper = uuid.UUID('e28c4e63-3f55-11d1-885e-0000f87808ee')
CLSID_EmfPrinter = uuid.UUID('ae064d01-d6ce-11d0-867a-0000f8751720')
CLSID_PsPrinter = uuid.UUID('e28c4e61-3f55-11d1-885e-0000f87808ee')
CLSID_ExportBMP = uuid.UUID('058d2242-918d-4941-a048-8b259aaa1aa7')
CLSID_ExportJPEG = uuid.UUID('8e29f55c-f8d2-48b3-8227-34b279de8358')
CLSID_ExportPNG = uuid.UUID('69fa668c-58d9-4fd4-805c-964b5c383c8b')
CLSID_ExportTIFF = uuid.UUID('77c648d5-c2e1-4ec5-8764-9034181f9858')
CLSID_ExportGIF = uuid.UUID('167d909e-2528-4e5d-b5ee-c2e4b553b224')
CLSID_ExportEMF = uuid.UUID('b4d7ae22-1d09-4b5b-8d37-4ff7d5f9233a')
CLSID_ExportPS = uuid.UUID('1918f0e0-69ff-4d19-b06d-4c2f8c6067a3')
CLSID_ExportPDF = uuid.UUID('a0d673ef-bcb9-4c6d-9226-214e4142fbc7')
CLSID_ExportAI = uuid.UUID('c5f4e89d-20fc-4c43-922c-b165d09c12aa')
CLSID_ExportSVG = uuid.UUID('637180af-72cf-4e99-afce-887b9a1091c3')
CLSID_DibExporter = uuid.UUID('20cd4013-8f3d-11d0-8590-0800091a2a72')
CLSID_JpegExporter = uuid.UUID('511ff07a-55c4-11d3-9ffd-00c04f6bc8dd')
CLSID_TiffExporter = uuid.UUID('39c10487-b0fa-4f2b-ac7b-c76e0bce9a95')

# Enumerations
class esriExportErrorReturnCodes(Enumeration):
    __slots__ = ['E_CGMVERSION3NEEDED',
                 'E_LICENSENOTAVAILABLE',
                 'E_OBJECTSETUP',
                 'E_TEMPMETAFILE',
                 'E_MAPMETAFILE',
                 'E_PAPERREFREQ',
                 'E_DRIVERNOTMATCH',
                 'E_PARAMETER',
                 'E_REGISTRYSETTINGS',
                 'E_FILECREATION',
                 'E_METAFILEPARSING',
                 'E_OPENPRINTER',
                 'E_BITMAPOUTOFMEMORY',
                 'E_STARTPRINTING',
                 'E_WASNOTACTIVATED',
                 'E_OUTPUTFILENAME',
                 'E_PIXELBOUNDS']
    E_CGMVERSION3NEEDED = -2147220735
    E_LICENSENOTAVAILABLE = -2147220734
    E_OBJECTSETUP = -2147220733
    E_TEMPMETAFILE = -2147220732
    E_MAPMETAFILE = -2147220731
    E_PAPERREFREQ = -2147220730
    E_DRIVERNOTMATCH = -2147220729
    E_PARAMETER = -2147220728
    E_REGISTRYSETTINGS = -2147220727
    E_FILECREATION = -2147220726
    E_METAFILEPARSING = -2147220725
    E_OPENPRINTER = -2147220724
    E_BITMAPOUTOFMEMORY = -2147220723
    E_STARTPRINTING = -2147220722
    E_WASNOTACTIVATED = -2147220721
    E_OUTPUTFILENAME = -2147220720
    E_PIXELBOUNDS = -2147220719

class esriOutputErrorReturnCodes(Enumeration):
    __slots__ = ['E_INTERNALERROR',
                 'E_REQUESTEDFUNCTIONALITYDOESNOTSUPPORTED',
                 'E_MEMORYOUT',
                 'E_MEMORYERROR',
                 'E_INVALIDORCURRUPTFILE',
                 'E_FILEREADINGERROR',
                 'E_FILEWRITINGERROR',
                 'E_FILEOPENINGERROR',
                 'E_FILECREATIONERROR',
                 'E_IMAGEDIRECTORYREADINGERROR',
                 'E_IMAGEDIRECTORYWRITINGERROR',
                 'E_CANNOTCOMPRESSORDECOMPRESS',
                 'E_READORWRITEJPEGMARKER',
                 'E_INCOMPATIBLEZLIB',
                 'E_INVALIDIMAGEPARAMETERS',
                 'E_INVALIDPARAMETERS',
                 'E_CLASSSETTEDUPINCORRECTLY',
                 'S_SAVEDPRINTERNOTFOUND',
                 'S_NOPRINTERSINSTALLED']
    E_INTERNALERROR = -2147220686
    E_REQUESTEDFUNCTIONALITYDOESNOTSUPPORTED = -2147220685
    E_MEMORYOUT = -2147220684
    E_MEMORYERROR = -2147220683
    E_INVALIDORCURRUPTFILE = -2147220682
    E_FILEREADINGERROR = -2147220681
    E_FILEWRITINGERROR = -2147220680
    E_FILEOPENINGERROR = -2147220679
    E_FILECREATIONERROR = -2147220678
    E_IMAGEDIRECTORYREADINGERROR = -2147220677
    E_IMAGEDIRECTORYWRITINGERROR = -2147220676
    E_CANNOTCOMPRESSORDECOMPRESS = -2147220675
    E_READORWRITEJPEGMARKER = -2147220674
    E_INCOMPATIBLEZLIB = -2147220673
    E_INVALIDIMAGEPARAMETERS = -2147220672
    E_INVALIDPARAMETERS = -2147220671
    E_CLASSSETTEDUPINCORRECTLY = -2147220670
    S_SAVEDPRINTERNOTFOUND = 262979
    S_NOPRINTERSINSTALLED = 262980

class esriPDFExtensionErrorCodes(Enumeration):
    __slots__ = ['E_PDFEXTENSIONERROR',
                 'E_NEEDPASSWD',
                 'E_INSUFFICIENTMEMORY',
                 'E_TOOMANYPAGESFOROPEN',
                 'E_OPNOTPERMITTED',
                 'E_UNABLEOPENDOC',
                 'E_UNABLEOPENDOCFORWRITING',
                 'E_UNABLEWRITINGDOC',
                 'E_UNABLERENTEMPFILE',
                 'E_UNABLEREADILE',
                 'E_UNKNOWNFILETYPE',
                 'E_FILEALREADYOPEN',
                 'E_NOSPACEFORTEMPFILE',
                 'E_TOOMANYPAGESFORINSERT',
                 'E_AFTERSAVE',
                 'E_FILEERROR',
                 'E_DIRFULL',
                 'E_DISKFULL',
                 'E_FILEIO',
                 'E_FILEREAD',
                 'E_FILEWRITE',
                 'E_FILELOCKED',
                 'E_FILEEXISTS',
                 'E_FILEINUSE',
                 'E_FILEACCESSDENIED',
                 'E_FILEACCESSNOWRITE',
                 'E_FILENOTFOUND',
                 'E_FILEOPENFAILED',
                 'E_METADATABADXMP',
                 'E_METADATASYNTXERR',
                 'E_XAPCREATIONERR',
                 'E_METADATAINTERNAL',
                 'E_INTERROR',
                 'E_OUTMEMORY',
                 'E_BADPARAMETER',
                 'E_USERCANCEL']
    E_PDFEXTENSIONERROR = -2147220667
    E_NEEDPASSWD = -2147220666
    E_INSUFFICIENTMEMORY = -2147220665
    E_TOOMANYPAGESFOROPEN = -2147220664
    E_OPNOTPERMITTED = -2147220663
    E_UNABLEOPENDOC = -2147220662
    E_UNABLEOPENDOCFORWRITING = -2147220661
    E_UNABLEWRITINGDOC = -2147220660
    E_UNABLERENTEMPFILE = -2147220659
    E_UNABLEREADILE = -2147220658
    E_UNKNOWNFILETYPE = -2147220657
    E_FILEALREADYOPEN = -2147220656
    E_NOSPACEFORTEMPFILE = -2147220655
    E_TOOMANYPAGESFORINSERT = -2147220655
    E_AFTERSAVE = -2147220654
    E_FILEERROR = -2147220653
    E_DIRFULL = -2147220652
    E_DISKFULL = -2147220651
    E_FILEIO = -2147220650
    E_FILEREAD = -2147220649
    E_FILEWRITE = -2147220648
    E_FILELOCKED = -2147220647
    E_FILEEXISTS = -2147220646
    E_FILEINUSE = -2147220645
    E_FILEACCESSDENIED = -2147220644
    E_FILEACCESSNOWRITE = -2147220643
    E_FILENOTFOUND = -2147220642
    E_FILEOPENFAILED = -2147220641
    E_METADATABADXMP = -2147220640
    E_METADATASYNTXERR = -2147220639
    E_XAPCREATIONERR = -2147220638
    E_METADATAINTERNAL = -2147220637
    E_INTERROR = -2147220636
    E_OUTMEMORY = -2147220635
    E_BADPARAMETER = -2147220634
    E_USERCANCEL = -2147220633

class esriExportColorspace(Enumeration):
    __slots__ = ['esriExportColorspaceRGB',
                 'esriExportColorspaceCMYK']
    esriExportColorspaceRGB = 0
    esriExportColorspaceCMYK = 1

class esriOutputSelection(Enumeration):
    __slots__ = ['esriOutputAll',
                 'esriOutputSelected',
                 'esriOutputCurrent',
                 'esriOutputRange',
                 'esriOutputWhereClause']
    esriOutputAll = 0
    esriOutputSelected = 1
    esriOutputCurrent = 2
    esriOutputRange = 3
    esriOutputWhereClause = 4

class esriPSDriverEmulsion(Enumeration):
    __slots__ = ['esriPSDriverEmulUP',
                 'esriPSDriverEmulDOWN']
    esriPSDriverEmulUP = 0
    esriPSDriverEmulDOWN = 1

class esriPSDriverImage(Enumeration):
    __slots__ = ['esriPSDriverImagePOS',
                 'esriPSDriverImageNEG']
    esriPSDriverImagePOS = 0
    esriPSDriverImageNEG = 1

class esriPSDriverImageCompression(Enumeration):
    __slots__ = ['esriPSDriverPSLevel1NoCompress',
                 'esriPSDriverPSLevel1Compress',
                 'esriPSDriverPSLevel2NoCompress',
                 'esriPSDriverPSLevel2Compress']
    esriPSDriverPSLevel1NoCompress = 0
    esriPSDriverPSLevel1Compress = 1
    esriPSDriverPSLevel2NoCompress = 2
    esriPSDriverPSLevel2Compress = 3

class esriPSDriverPSLanguageLevel(Enumeration):
    __slots__ = ['esriPSDriverPSLevel2',
                 'esriPSDriverPSLevel3']
    esriPSDriverPSLevel2 = 0
    esriPSDriverPSLevel3 = 1

class esriPSDriverHalfTone(Enumeration):
    __slots__ = ['esriPSDriverDPI',
                 'esriPSDriverLPI',
                 'esriPSDriverLastHalfTone']
    esriPSDriverDPI = 0
    esriPSDriverLPI = 1
    esriPSDriverLastHalfTone = 2

class esriPSDriverSeparates(Enumeration):
    __slots__ = ['esriPSDriverSeparateCyan',
                 'esriPSDriverSeparateMagenta',
                 'esriPSDriverSeparateYellow',
                 'esriPSDriverSeparateBlack',
                 'esriPSDriverSeparateCustom']
    esriPSDriverSeparateCyan = 1
    esriPSDriverSeparateMagenta = 2
    esriPSDriverSeparateYellow = 3
    esriPSDriverSeparateBlack = 4
    esriPSDriverSeparateCustom = 5

class esriPSDriverMarks(Enumeration):
    __slots__ = ['esriPSDriverNone',
                 'esriPSDriverRegistration',
                 'esriPSDriverCrop',
                 'esriPSDriverLabel',
                 'esriPSDriverGrayScale']
    esriPSDriverNone = 0
    esriPSDriverRegistration = 1
    esriPSDriverCrop = 2
    esriPSDriverLabel = 4
    esriPSDriverGrayScale = 8

class esriColorCorrectionDataType(Enumeration):
    __slots__ = ['esriColorCorrectionDataTypeTotal',
                 'esriColorCorrectionDataTypeRaster',
                 'esriColorCorrectionDataTypeVector']
    esriColorCorrectionDataTypeTotal = 1
    esriColorCorrectionDataTypeRaster = 2
    esriColorCorrectionDataTypeVector = 4

class esriCMYKIndex(Enumeration):
    __slots__ = ['esriCMYKIndexCyan',
                 'esriCMYKIndexMagenta',
                 'esriCMYKIndexYellow',
                 'esriCMYKIndexBlack']
    esriCMYKIndexCyan = 0
    esriCMYKIndexMagenta = 1
    esriCMYKIndexYellow = 2
    esriCMYKIndexBlack = 3

class esriAIDriverOptions(Enumeration):
    __slots__ = ['esriAIMapFonts',
                 'esriAIPolygonizeMarkers']
    esriAIMapFonts = 1
    esriAIPolygonizeMarkers = 2

class esriExportImageType(Enumeration):
    __slots__ = ['esriExportImageTypeBiLevelMask',
                 'esriExportImageTypeBiLevelThreshold',
                 'esriExportImageTypeGrayscale',
                 'esriExportImageTypeIndexed',
                 'esriExportImageTypeTrueColor']
    esriExportImageTypeBiLevelMask = 1
    esriExportImageTypeBiLevelThreshold = 2
    esriExportImageTypeGrayscale = 7
    esriExportImageTypeIndexed = 8
    esriExportImageTypeTrueColor = 24

class esriTIFFCompression(Enumeration):
    __slots__ = ['esriTIFFCompressionNone',
                 'esriTIFFCompressionPackBits',
                 'esriTIFFCompressionJPEG',
                 'esriTIFFCompressionLZW',
                 'esriTIFFCompressionDeflate',
                 'esriTIFFCompressionFax4']
    esriTIFFCompressionNone = 0
    esriTIFFCompressionPackBits = 1
    esriTIFFCompressionJPEG = 2
    esriTIFFCompressionLZW = 3
    esriTIFFCompressionDeflate = 4
    esriTIFFCompressionFax4 = 5

class esriGIFCompression(Enumeration):
    __slots__ = ['esriGIFCompressionNone',
                 'esriGIFCompressionRLE',
                 'esriGIFCompressionLZW']
    esriGIFCompressionNone = 0
    esriGIFCompressionRLE = 1
    esriGIFCompressionLZW = 3

class esriExportPSEmulsion(Enumeration):
    __slots__ = ['esriExportPSEmulsionUp',
                 'esriExportPSEmulsionDown']
    esriExportPSEmulsionUp = 0
    esriExportPSEmulsionDown = 1

class esriExportPSImage(Enumeration):
    __slots__ = ['esriExportPSImagePositive',
                 'esriExportPSImageNegative']
    esriExportPSImagePositive = 0
    esriExportPSImageNegative = 1

class esriExportPSLanguageLevel(Enumeration):
    __slots__ = ['esriExportPSLevel2',
                 'esriExportPSLevel3']
    esriExportPSLevel2 = 2
    esriExportPSLevel3 = 3

class esriExportImageCompression(Enumeration):
    __slots__ = ['esriExportImageCompressionNone',
                 'esriExportImageCompressionRLE',
                 'esriExportImageCompressionDeflate',
                 'esriExportImageCompressionLZW',
                 'esriExportImageCompressionJPEG',
                 'esriExportImageCompressionAdaptive']
    esriExportImageCompressionNone = 0
    esriExportImageCompressionRLE = 1
    esriExportImageCompressionDeflate = 2
    esriExportImageCompressionLZW = 3
    esriExportImageCompressionJPEG = 4
    esriExportImageCompressionAdaptive = 80000000

class esriExportPDFLayerOptions(Enumeration):
    __slots__ = ['esriExportPDFLayerOptionsNone',
                 'esriExportPDFLayerOptionsLayersOnly',
                 'esriExportPDFLayerOptionsLayersAndFeatureAttributes']
    esriExportPDFLayerOptionsNone = 0
    esriExportPDFLayerOptionsLayersOnly = 1
    esriExportPDFLayerOptionsLayersAndFeatureAttributes = 2

class esriExportMultipleFiles(Enumeration):
    __slots__ = ['esriExportMultipleFiles_None',
                 'esriExportMultipleFiles_PageNames',
                 'esriExportMultipleFiles_PageIndex']
    esriExportMultipleFiles_None = 0
    esriExportMultipleFiles_PageNames = 1
    esriExportMultipleFiles_PageIndex = 2

class esriPDFExtensionSecurityEncryptionOption(Enumeration):
    __slots__ = ['esriPDFExtensionSecurityEncryptionOptionAllContent',
                 'esriPDFExtensionSecurityEncryptionOptionNoMetaData',
                 'esriPDFExtensionSecurityEncryptionOptionFileAttachmentOnly']
    esriPDFExtensionSecurityEncryptionOptionAllContent = 1
    esriPDFExtensionSecurityEncryptionOptionNoMetaData = 2
    esriPDFExtensionSecurityEncryptionOptionFileAttachmentOnly = 3

class esriPDFExtensionSecurityEncryptionMethod(Enumeration):
    __slots__ = ['esriPDFExtensionSecurityEncryptionMethodRC4_V2',
                 'esriPDFExtensionSecurityEncryptionMethodAES_V1',
                 'esriPDFExtensionSecurityEncryptionMethodAES_V2']
    esriPDFExtensionSecurityEncryptionMethodRC4_V2 = 2
    esriPDFExtensionSecurityEncryptionMethodAES_V1 = 5
    esriPDFExtensionSecurityEncryptionMethodAES_V2 = 6

class esriPDFExtensionSecurityPermission(Enumeration):
    __slots__ = ['esriPDFExtensionSecurityPermissionNone',
                 'esriPDFExtensionSecurityPermissionOpen',
                 'esriPDFExtensionSecurityPermissionSecure',
                 'esriPDFExtensionSecurityPermissionPrint',
                 'esriPDFExtensionSecurityPermissionEdit',
                 'esriPDFExtensionSecurityPermissionCopy',
                 'esriPDFExtensionSecurityPermissionEditNotes',
                 'esriPDFExtensionSecurityPermissionFillAndSign',
                 'esriPDFExtensionSecurityPermissionAccessible',
                 'esriPDFExtensionSecurityPermissionDocAssembly',
                 'esriPDFExtensionSecurityPermissionHighPrint',
                 'esriPDFExtensionSecurityFormSpawnTempl',
                 'esriPDFExtensionSecurityPermissionAll',
                 'esriPDFExtensionSecurityPermissionAllMaster']
    esriPDFExtensionSecurityPermissionNone = 0
    esriPDFExtensionSecurityPermissionOpen = 1
    esriPDFExtensionSecurityPermissionSecure = 2
    esriPDFExtensionSecurityPermissionPrint = 4
    esriPDFExtensionSecurityPermissionEdit = 8
    esriPDFExtensionSecurityPermissionCopy = 16
    esriPDFExtensionSecurityPermissionEditNotes = 32
    esriPDFExtensionSecurityPermissionFillAndSign = 256
    esriPDFExtensionSecurityPermissionAccessible = 512
    esriPDFExtensionSecurityPermissionDocAssembly = 1024
    esriPDFExtensionSecurityPermissionHighPrint = 2052
    esriPDFExtensionSecurityFormSpawnTempl = 131072
    esriPDFExtensionSecurityPermissionAll = -268435457
    esriPDFExtensionSecurityPermissionAllMaster = 2108

