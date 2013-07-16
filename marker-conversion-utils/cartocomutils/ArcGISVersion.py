'Type library'
__all__ = ['IEnumVersions', 'IArcGISVersion', 'IVersionHost', 'ArcGISVersionManager', 'IID_IEnumVersions', 'IID_IArcGISVersion', 'IID_IVersionHost', 'CLSID_ArcGISVersionManager', 'esriVersionProductCode']
from cartocomutils import _ArcGISVersion
from cartocomutils._ArcGISVersion import ArcGISVersionManager
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IEnumVersions(_ArcGISVersion.IEnumVersions):
    _IID = uuid.UUID('18f07a02-956a-4d44-979b-b006ecc81d93')
    def Reset(self):
        '''Method IEnumVersions.Reset'''
        return super(IEnumVersions, self).Reset()
    def Next(self):
        '''Method IEnumVersions.Next

           OUTPUTS
            pCode               : esriVersionProductCode*
            pVer                : BSTR*
            path                : BSTR*'''
        return super(IEnumVersions, self).Next()
    def __iter__(self):
        try:
            super(IEnumVersions, self).Reset()
            val = super(IEnumVersions, self).Next()
            while any(val):
                yield val
                val = super(IEnumVersions, self).Next()
        except:
            pass

class IArcGISVersion(_ArcGISVersion.IArcGISVersion):
    _IID = uuid.UUID('4b666ca0-021e-408c-9abe-a1cc182729fa')
    def LoadVersion(self, productCode, engineVersion):
        '''Method IArcGISVersion.LoadVersion

           INPUTS
            productCode         : esriVersionProductCode
            engineVersion       : BSTR

           OUTPUT
            succeeded           : VARIANT_BOOL*'''
        return super(IArcGISVersion, self).LoadVersion(productCode, engineVersion)
    def GetActiveVersion(self):
        '''Method IArcGISVersion.GetActiveVersion

           OUTPUTS
            pCode               : esriVersionProductCode*
            pVer                : BSTR*
            pPath               : BSTR*'''
        return super(IArcGISVersion, self).GetActiveVersion()
    def GetVersions(self):
        '''Method IArcGISVersion.GetVersions

           OUTPUT
            ppVersions          : IEnumVersions**'''
        return super(IArcGISVersion, self).GetVersions()
    def ProductNameFromCode(self, __MIDL__IArcGISVersion0000):
        '''Method IArcGISVersion.ProductNameFromCode

           INPUT
            __MIDL__IArcGISVersion0000: esriVersionProductCode

           OUTPUT
            pProductName        : BSTR*'''
        return super(IArcGISVersion, self).ProductNameFromCode(__MIDL__IArcGISVersion0000)

class IVersionHost(_ArcGISVersion.IVersionHost):
    _IID = uuid.UUID('a4092e33-e459-4b9c-b04e-263fb7a8e1d1')
    def CreateObject(self, clsid):
        '''Method IVersionHost.CreateObject

           INPUT
            clsid               : GUID

           OUTPUT
            ppv                 : IUnknown**'''
        return super(IVersionHost, self).CreateObject(clsid)


# IIDs
IID_IEnumVersions = IEnumVersions._IID
IID_IArcGISVersion = IArcGISVersion._IID
IID_IVersionHost = IVersionHost._IID
_IIDMap[IID_IEnumVersions] = IEnumVersions
_IIDMap[IID_IArcGISVersion] = IArcGISVersion
_IIDMap[IID_IVersionHost] = IVersionHost


# CLSIDs
CLSID_ArcGISVersionManager = uuid.UUID('d0705d7d-0270-4607-bcdb-1d4f18624748')

# Enumerations
class esriVersionProductCode(Enumeration):
    __slots__ = ['esriArcGIS',
                 'esriArcGISDesktop',
                 'esriArcGISEngine',
                 'esriArcGISReader',
                 'esriArcGISExplorer',
                 'esriArcGISServer']
    esriArcGIS = 0
    esriArcGISDesktop = 1
    esriArcGISEngine = 2
    esriArcGISReader = 3
    esriArcGISExplorer = 4
    esriArcGISServer = 5

