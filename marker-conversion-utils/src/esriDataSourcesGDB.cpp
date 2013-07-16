// This source is all automatically generated. Editing it may very
// well be an exercise in futility and frustration.
#include "Python.h"
#include "datetime.h"

// imports
#import "ArcGISVersion.dll" raw_interfaces_only, raw_native_types, no_namespace, named_guids, rename("esriProductCode", "esriVersionProductCode"), rename("VersionManager", "ArcGISVersionManager")
#import "esriSystem.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids, exclude("OLE_COLOR", "OLE_HANDLE", "VARTYPE")
#import "esriSystemUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriGeometry.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriGraphicsCore.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriGraphicsSymbols.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriDisplay.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriServer.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriOutput.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriGeoDatabase.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriGeoDatabaseDistributed.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriGeoDatabaseExtensions.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriGeoDatabasePS.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriGISClient.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriDataSourcesFile.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriDataSourcesGDB.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriDataSourcesOleDB.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriDataSourcesRaster.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriDataSourcesNetCDF.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriDataSourcesRasterUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "esriCarto.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids, exclude("UINT_PTR")
#import "esriFramework.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids, exclude("UINT_PTR")


// Globals we need to keep around -- a reference to the UUID class for mapping
// GUIDs to Python-usable UUIDs and the IUnknown type we'll be using across the
// board.
static PyObject* g_pUUID_type = NULL;
static PyObject* g_pUnk_type = NULL;
static PyObject* g_pIIDMap = NULL;
static PyObject* g_pCLSIDMap = NULL;
static PyObject* g_pRecordMap = NULL;

// PyObject destructor for PyCObjects that hold IUnknown* in them
static void
destr_unknown(void* pvUnk)
{
    IUnknown* pUnk = (IUnknown*)pvUnk;
    if (pUnk)
        pUnk->Release();
}

// Checker/caster to see if we can get a GUID from a Python object, either
// by  checking if the object is an instance of the uuid.UUID type, or if
// it is a string, coercing it with the constructor and seeing if it accepts
// it.
//
// def GuidFromPyObject(potentialIID, GUID*):
//     if isinstance(potentialIID, basestring):
//         try:
//             potentialIID = uuid.UUID(potentialIID)
//         except:
//             return False
//     if isinstance(potentialIID, uuid.UUID):
//         if (<copy raw bytes of UUID data in object to out GUID*>):
//             return True
//     return False
//
static bool
GuidFromPyObject(PyObject* potentialIID, GUID* pOutGUID)
{
    if (!g_pUUID_type)
        return false;

    // See if we can cast a string into a UUID instance, if that's what we've got.
    if (PyString_Check(potentialIID) || PyUnicode_Check(potentialIID))
    {
        PyObject* piid_object = PyObject_CallFunction(g_pUUID_type, "O", potentialIID);
        bool retval = (piid_object)?GuidFromPyObject(piid_object, pOutGUID): false;
        Py_XDECREF(piid_object);
        if (!piid_object || PyErr_Occurred())
        {
            PyErr_Clear();
            PyObject* unicodearg = NULL;
            if (PyString_Check(potentialIID))
                unicodearg = PyUnicode_FromObject(potentialIID);
            else if (PyUnicode_Check(potentialIID))
            {
                unicodearg = potentialIID;
                Py_INCREF(unicodearg);
            }
            if (unicodearg)
            {
                BSTR classname = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodearg),
                                                     (UINT)PyUnicode_GET_SIZE(unicodearg));
                CLSID clsid;
                if (CLSIDFromProgID(classname, &clsid) == S_OK)
                {
                    retval = true;
                    if (memcpy_s((void *)pOutGUID, sizeof(GUID), (void *)&clsid, 16))
                        retval = false;
                }
                ::SysFreeString(classname);
            }
            Py_XDECREF(unicodearg);
        }
        return retval;
    }
    else if (PyObject_IsInstance(potentialIID, g_pUUID_type))
    {
        // Fetch raw bytes string -- need to fetch "bytes" on big-endian, 
        // "bytes_le" on little-endian architectures
        const int i = 1;
        PyObject* pBytes = NULL;
        if ( (*(char*)&i) == 0 )        
            pBytes = PyObject_GetAttrString(potentialIID, "bytes");
        else
            pBytes = PyObject_GetAttrString(potentialIID, "bytes_le");
        if (pBytes)
        {
            bool retval = true;
            // Pointer to raw data
            char* pRawBytes = PyString_AsString(pBytes);
            if (memcpy_s((void *)pOutGUID, sizeof(GUID), (void *)pRawBytes, 16))
                retval = false;
            Py_XDECREF(pBytes);
            return retval;
        }
        PyErr_Clear();
    }
    return false;
}

static PyObject*
GUIDToPythonUUID(const GUID* UUID)
{
    if (UUID)
    {
        // Lie to Python and tell it that our GUID is a 16-byte string
        PyObject* PyUUIDString = PyString_FromStringAndSize((char *)UUID, sizeof(GUID));
        if (!PyUUIDString)
            return NULL;
        // Args, varargs
        PyObject* PyArgs = PyTuple_New(0);
        PyObject* PyKWArgs = PyDict_New();
        PyObject* RetVal = NULL;
        // Dict with single value: the keyword argument bytes_le.
        const int i = 1;
        PyObject* pBytes = NULL;
        if ( (*(char*)&i) == 0 )
            PyDict_SetItemString(PyKWArgs, "bytes", PyUUIDString);
        else
            PyDict_SetItemString(PyKWArgs, "bytes_le", PyUUIDString);
        // New UUID with KW
        if (g_pUUID_type)
            RetVal = PyObject_Call(g_pUUID_type, PyArgs, PyKWArgs);
        else
            PyErr_SetString(PyExc_ImportError, "UUID module import failed");

        Py_DECREF(PyUUIDString);
        Py_DECREF(PyArgs);
        Py_DECREF(PyKWArgs);
        return RetVal;
    }
    else
    {
        PyErr_SetString(PyExc_ValueError, "Bad GUID");
        return NULL;
    }
}

static PyObject*
IUnknownToPythonIIDObject(IUnknown* pUnk, const GUID* IID)
{
    PyObject* RetVal = NULL;
    pUnk->AddRef();
    PyObject* PyUnk = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    //return PyUnk;

    PyObject* pCall = NULL;

    PyObject* pGuidObject = GUIDToPythonUUID(IID);
    if (!pGuidObject || !g_pIIDMap)
        return PyUnk;

    if (PyDict_Contains(g_pIIDMap, pGuidObject) == 1)
        pCall = PyDict_GetItem(g_pIIDMap, pGuidObject);
    if (!pCall)
        pCall = g_pUnk_type;
    if (pCall)
        RetVal = PyObject_CallFunction(pCall, "O", PyUnk);

    if (!RetVal)
        RetVal = PyUnk;
    else
        Py_DECREF(PyUnk);

    Py_XDECREF(pGuidObject);
    return RetVal;
}

static PyObject*
DATE_AsPyObject(DATE in_date)
{
  PyDateTime_IMPORT;
  // Round to even number of days
  int days = (int)in_date;
  // Convert what's left (after the decimal) to seconds; 86400 seconds per day.
  int seconds = (int)((in_date - (double)days) * 86400.0);
  if (in_date < 0)
    seconds *= -1;
  // TimeDelta to add to the date representing the start of all Variant VT_DATEs
  PyObject* pDelta = PyDelta_FromDSU(days, seconds, 0);
  // Midnight 30 December 1899
  PyObject* pStartOfVariantTime = PyDateTime_FromDateAndTime(1899, 12, 30, 0, 0, 0, 0);
  // Do addition of computed delta to 1899-12-30 00:00:00
  PyObject* pRetVal = PyObject_CallMethod(pStartOfVariantTime, "__add__", "O", pDelta);

  Py_XDECREF(pDelta);
  Py_XDECREF(pStartOfVariantTime);

  return pRetVal;
}

static DATE
PyObject_AsDATE(PyObject* in_date)
{
  PyDateTime_IMPORT;
  if (!PyDateTime_Check(in_date))
  {
    PyErr_SetString(PyExc_ValueError, "Cannot convert this Python object to a datetime");
    return (DATE)0.0;
  }

  double out_date;

  PyObject* pStartOfVariantTime = PyDateTime_FromDateAndTime(1899, 12, 30, 0, 0, 0, 0);
  PyDateTime_Delta* pDelta = (PyDateTime_Delta *)PyObject_CallMethod(in_date, "__sub__", "O", pStartOfVariantTime);
  Py_XDECREF(pStartOfVariantTime);
  
  if (pDelta && PyDelta_Check((PyObject *)pDelta))
  {
    out_date = (double)pDelta->days;
    out_date += (double)(pDelta->seconds) / 86400.0;
  }
  
  Py_XDECREF(pDelta);
  return (DATE)out_date;
}

static bool
PyObject_AsVariant(PyObject* in_object, VARIANT* out_variant)
{
  ::VariantClear(out_variant);
  PyDateTime_IMPORT;

  if (in_object == Py_None)
    return true;
  else if (PyUnicode_Check(in_object))
  {
    out_variant->vt = VT_BSTR;
    BSTR out_string = ::SysAllocStringLen(PyUnicode_AS_UNICODE(in_object), 
                                          (UINT)PyUnicode_GET_SIZE(in_object));
    out_variant->bstrVal = out_string;
    return true;
  }
  else if (PyString_Check(in_object))
  {
    PyObject* pUnicode = PyUnicode_FromObject(in_object);
    if (pUnicode)
    {
      out_variant->vt = VT_BSTR;
      BSTR out_string = ::SysAllocStringLen(PyUnicode_AS_UNICODE(pUnicode), 
                                            (UINT)PyUnicode_GET_SIZE(pUnicode));
      out_variant->bstrVal = out_string;
      Py_DECREF(pUnicode);
      return true;
    }
    return false;
  }
  else if (PyFloat_Check(in_object))
  {
    out_variant->vt = VT_R8;
    out_variant->dblVal = PyFloat_AsDouble(in_object);
    return true;
  }
  else if (PyInt_Check(in_object))
  {
    out_variant->vt = VT_I8;
    out_variant->llVal = PyInt_AsLong(in_object);
    return true;
  }
  else if (PyLong_Check(in_object))
  {
    out_variant->vt = VT_I8;
    out_variant->llVal = PyLong_AsLongLong(in_object);
    if (PyErr_Occurred())
    {
      PyErr_Clear();
      PyObject* strval = PyObject_Str(in_object);
      if (strval)
      {
        PyObject* unival = PyUnicode_FromObject(strval);
        out_variant->vt = VT_BSTR;
        BSTR out_string = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unival), 
                                              (UINT)PyUnicode_GET_SIZE(unival));
        out_variant->bstrVal = out_string;
        Py_DecRef(unival);
        Py_DecRef(strval);
        return true;
      }
      return false;
    }
    else
      return true;
  }
  else if (PyDateTime_Check(in_object))
  {
    out_variant->vt = VT_DATE;
    out_variant->date = PyObject_AsDATE(in_object);

    return true;
  }
  else if (PyObject_HasAttrString(in_object, "_pUnk"))
  {
    PyObject* pUnk = PyObject_GetAttrString(in_object, "_pUnk");
    if (pUnk && PyCObject_Check(pUnk))
    {
      IUnknown* pIUnknown = (IUnknown*)PyCObject_AsVoidPtr(pUnk);
      pIUnknown->AddRef();
      out_variant->vt = VT_UNKNOWN;
      out_variant->punkVal = pIUnknown;
      Py_DecRef(pUnk);
      return true;
    }
    Py_XDECREF(pUnk);
  }
  PyObject* repr = PyObject_Repr(in_object);
  PyErr_Format(PyExc_ValueError, "Can't convert %s to Variant.", repr?PyString_AsString(repr):"<Undef>", NULL);
  Py_XDECREF(repr);
  return false;
}

// Forward decl!
static PyObject* SAFEARRAYToPyObject(SAFEARRAY*, VARTYPE);

static PyObject*
Variant_AsPyObject(VARIANT* in_variant)
{
  if (in_variant->vt == VT_EMPTY)
    Py_RETURN_NONE;
  else if (in_variant->vt  == (VT_BYREF|VT_I1))
    return PyInt_FromLong(*(in_variant->pcVal)); //CHAR                *
  else if (in_variant->vt == (VT_BYREF|VT_UI2))
    return PyInt_FromLong(*(in_variant->puiVal)); //USHORT              *
  else if (in_variant->vt == (VT_BYREF|VT_UI4))
    return PyInt_FromLong(*(in_variant->pulVal)); //ULONG               *
  else if (in_variant->vt == (VT_BYREF|VT_UI8))
    return PyLong_FromUnsignedLongLong(*(in_variant->pullVal)); //ULONGLONG           *
  else if (in_variant->vt == (VT_BYREF|VT_INT))
    return PyInt_FromLong(*(in_variant->pintVal)); //INT                 *
  else if (in_variant->vt == (VT_BYREF|VT_UINT))
    return PyInt_FromLong(*(in_variant->puintVal)); //UINT                *
  else if (in_variant->vt == (VT_BYREF|VT_UI1))
    return PyInt_FromLong(*(in_variant->pbVal)); //BYTE                *
  else if (in_variant->vt == (VT_BYREF|VT_I2))
    return PyInt_FromLong(*(in_variant->piVal)); //SHORT               *
  else if (in_variant->vt == (VT_BYREF|VT_I4))
    return PyInt_FromLong(*(in_variant->plVal)); //LONG                *
  else if (in_variant->vt == (VT_BYREF|VT_I8))
    return PyLong_FromLongLong(*(in_variant->pllVal)); //LONGLONG            *
  else if (in_variant->vt == (VT_BYREF|VT_R4))
    return PyFloat_FromDouble((double)*(in_variant->pfltVal)); //FLOAT               *
  else if (in_variant->vt == (VT_BYREF|VT_R8))
    return PyFloat_FromDouble((double)*(in_variant->pdblVal)); //DOUBLE              *
  else if (in_variant->vt == (VT_BYREF|VT_BOOL))
    if ((*(in_variant->pboolVal)) == VARIANT_TRUE)
      Py_RETURN_TRUE;
    else
      Py_RETURN_FALSE;
  else if (in_variant->vt == (VT_BYREF|VT_BSTR))
    return PyUnicode_FromWideChar(*(in_variant->pbstrVal),::SysStringLen(*(in_variant->pbstrVal)));  //BSTR                *
  else if (in_variant->vt == (VT_BYREF|VT_UNKNOWN))
  {
    IUnknown* pUnk = *(in_variant->ppunkVal);
    return IUnknownToPythonIIDObject(pUnk, &IID_IUnknown);
  }
  else if (in_variant->vt == (VT_BYREF|VT_DISPATCH))
  {
    IDispatch* pDisp = *(in_variant->ppdispVal);
    return IUnknownToPythonIIDObject(pDisp, &IID_IUnknown);
  }
  else if (in_variant->vt == (VT_BYREF|VT_VARIANT))
    return Variant_AsPyObject(in_variant->pvarVal); //VARIANT             *
  else if (in_variant->vt  == VT_I8)
    return PyLong_FromLongLong(in_variant->llVal); //LONGLONG           
  else if (in_variant->vt == VT_I4)
    return PyInt_FromLong(in_variant->lVal); //LONG               
  else if (in_variant->vt == VT_UI1)
    return PyInt_FromLong((unsigned)in_variant->bVal); //BYTE               
  else if (in_variant->vt == VT_I2)
    return PyInt_FromLong(in_variant->iVal); //SHORT              
  else if (in_variant->vt == VT_R4)
    return PyFloat_FromDouble((double)(in_variant->fltVal)); //FLOAT              
  else if (in_variant->vt == VT_R8)
    return PyFloat_FromDouble((double)(in_variant->dblVal)); //DOUBLE             
  else if (in_variant->vt == VT_BOOL)
    if ((in_variant->boolVal) == VARIANT_TRUE)
      Py_RETURN_TRUE;
    else
      Py_RETURN_FALSE;              
  else if (in_variant->vt == VT_BSTR)
    return PyUnicode_FromWideChar(in_variant->bstrVal, ::SysStringLen(in_variant->bstrVal)); //BSTR               
  else if (in_variant->vt == VT_UNKNOWN)
  {
    IUnknown* pUnk = in_variant->punkVal;
    return IUnknownToPythonIIDObject(pUnk, &IID_IUnknown);
  }
  else if (in_variant->vt == VT_DISPATCH)
  {
    IDispatch* pDisp = in_variant->pdispVal;
    return IUnknownToPythonIIDObject(pDisp, &IID_IUnknown);
  }
  else if (in_variant->vt == VT_I1)
    return PyInt_FromLong(in_variant->cVal); //CHAR               
  else if (in_variant->vt == VT_UI2)
    return PyInt_FromLong(in_variant->uiVal); //USHORT             
  else if (in_variant->vt == VT_UI4)
    return PyInt_FromLong(in_variant->ulVal); //ULONG              
  else if (in_variant->vt == VT_UI8)
    return PyLong_FromUnsignedLongLong(in_variant->ullVal); //ULONGLONG          
  else if (in_variant->vt == VT_INT)
    return PyInt_FromLong(in_variant->intVal); //INT                
  else if (in_variant->vt == VT_UINT)
    return PyInt_FromLong(in_variant->uintVal); //UINT               
  else if ((in_variant->vt & VT_DATE) == VT_DATE)
  {
    DATE in_date = (in_variant->vt & VT_BYREF)?(*(in_variant->pdate)):in_variant->date;
    return DATE_AsPyObject(in_date);
  }
  else if (in_variant->vt & VT_ARRAY)
  {
    return SAFEARRAYToPyObject((in_variant->vt & VT_BYREF) ? 
                                        *(in_variant->pparray) : 
                                        in_variant->parray,
                                (in_variant->vt));
  }

  PyErr_SetString(PyExc_ValueError, "Cannot convert this variant to a Python object");
  return NULL;
}

static PyObject*
SAFEARRAYToPyObject(SAFEARRAY* pArray, VARTYPE vt)
{
  if (!pArray)
    Py_RETURN_NONE;
  PyObject* return_array(NULL);
  long entry_count(1);
  for (ssize_t dimension(0); dimension < pArray->cDims; ++dimension)
    entry_count *= (pArray->rgsabound[dimension]).cElements;
  if (pArray->fFeatures & FADF_BSTR)
  {
    return_array = PyList_New(0);
    BSTR* barray = (BSTR*)pArray->pvData;
    for (long string_index = 0; string_index < entry_count; ++string_index)
    {
      PyObject* new_string = PyUnicode_FromWideChar(barray[string_index], ::SysStringLen(barray[string_index]));
      PyList_Append(return_array, new_string);
      Py_DECREF(new_string);
    }
  }
  else if (pArray->fFeatures & FADF_VARIANT)
  {
    return_array = PyList_New(0);
    VARIANT* varray = (VARIANT*)pArray->pvData;
    for (long variant_index(0); variant_index < entry_count; ++variant_index)
    {
      PyObject* new_variant = Variant_AsPyObject(&varray[variant_index]);
      if (new_variant)
      {
        PyList_Append(return_array, new_variant);
        Py_DECREF(new_variant);
      }
      else
      {
        PyErr_Clear();
        PyList_Append(return_array, Py_None);
      }
    }
  }
  else if (pArray->fFeatures & FADF_UNKNOWN)
  {
    return_array = PyList_New(0);
    IUnknown** oarray = (IUnknown**)pArray->pvData;
    for (long object_index(0); object_index < entry_count; ++object_index)
    {
      PyObject* new_object = IUnknownToPythonIIDObject(oarray[object_index], &IID_IUnknown);
      PyList_Append(return_array, new_object);
      Py_DECREF(new_object);
    }
  }
  else if (vt == (VT_UI1 | VT_ARRAY))
  {
    return_array = PyByteArray_FromStringAndSize((char*)(pArray->pvData), entry_count);
  }

  if (!return_array)
  {
    if (PyErr_WarnEx(PyExc_Warning, "conversion for this error type not implemented", -1) != 0)
      return 0;

    return_array = Py_BuildValue("(HHNK)", (unsigned short)vt,
                                           (unsigned short)pArray->fFeatures,
                                           PyByteArray_FromStringAndSize((char*)(pArray->pvData), 
                                                                         sizeof(pArray->pvData)),
                                           (unsigned long long)pArray->pvData);
  }
  return return_array;
}

// Attempt to get an interface pointer from a Python object
static bool
IFaceFromPyObject(PyObject* pIn, const GUID* pOutGuid, void** pOutIFace)
{
    IUnknown* pUnk = NULL;

    if (pIn == Py_None)
    {
        *pOutIFace = NULL;
        return true;
    }
    else if (PyCObject_Check(pIn))
    {
        pUnk = (IUnknown *)PyCObject_AsVoidPtr(pIn);
    }
    else
    {
        bool need_decref(false);
        if (PyObject_HasAttrString(pIn, "_arc_object"))
        {
          pIn = PyObject_GetAttrString(pIn, "_arc_object");
          if (pIn)
            need_decref = true;
        }
        PyObject* pObject = PyObject_GetAttrString(pIn, "_pUnk");
        if (!pObject)
            return false;
        if (!PyCObject_Check(pObject))
            return false;
        else
            pUnk = (IUnknown *)PyCObject_AsVoidPtr(pObject);
        if (need_decref)
            Py_DECREF(pIn);
        Py_XDECREF(pObject);
    }
    if (pUnk && SUCCEEDED(pUnk->QueryInterface(*pOutGuid, pOutIFace)))
        return true;

    return false;
}



// Every module implements this IUnknown thing but only one reference to the 
// _Type struct will be used between them, so type checking will still work.
// This has the happy side effect of letting us pick and choose which of the
// OLBs that are offered as wrappers (and just plain remove them) without 
// needing to worry about it. Whichever of the C modules in the suite that gets
// imported first is fully capable and will do its best to bootstrap the system.

typedef struct IUnknownObject {
    PyObject_HEAD
    IUnknown* m_pUnk;
} IUnknownObject;

static PyObject*
IUnknownObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    IUnknownObject* self;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {        
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IUnknown with provided CLSID");
            return NULL;
        }
    }
    // Are we passed an opaque pointer?
    else if (PyCObject_Check(argument))
    {
        pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
        pUnk->AddRef();
    }
    // No? See if there's an object._pUnk attribute that is one!
    else
    {
        argument = PyObject_GetAttrString(argument, "_pUnk");
        if (!argument)
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IUnknown");
            return NULL;
        }
        if (!PyCObject_Check(argument))
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IUnknown");
            return NULL;
        }
        else
        {
            pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
            pUnk->AddRef();
        }
        if (argument)
            Py_DECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    if (!(self = ((IUnknownObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IUnknown");
        return NULL;
    }

    self->m_pUnk = pUnk;
    return (PyObject *)self;
}

static void
IUnknownObject_dealloc(IUnknownObject* self)
{
    if (self->m_pUnk)
        self->m_pUnk->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
IUnknown_GetpUnk(IUnknownObject* self)
{
    if (!self->m_pUnk)
        Py_RETURN_NONE;
    self->m_pUnk->AddRef();
    return PyCObject_FromVoidPtr((void*)self->m_pUnk, destr_unknown);
}

static PyObject*
IUnknown_GetPointer(IUnknownObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pUnk);
}

static PyObject*
IUnknown_GetIID(IUnknownObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "{00000000-0000-0000-C000-000000000046}");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
IUnknown_SupportsInterface(IUnknownObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pUnk->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
        {
            ipUnk->Release();
            Py_RETURN_TRUE;
        }
        Py_RETURN_FALSE;
    }
    PyErr_SetString(PyExc_ValueError, "Bad interface ID.");
    return NULL;
}

PyMethodDef IUnknownMethods[] = {
    {"supports", (PyCFunction)IUnknown_SupportsInterface, METH_O, ""},
};

PyGetSetDef IUnknownGetSet[] = {
  {"_IID", (getter)IUnknown_GetIID, NULL, "Get IID for Unknown", NULL},
  {"_pUnk", (getter)IUnknown_GetpUnk, NULL, "Get opaque pointer to Unknown", NULL},
  {"_pointer", (getter)IUnknown_GetPointer, NULL, "Get long pointer to Unknown", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject IUnknownObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "cartocomutils.IUnknown",
                                              /* tp_name */
  sizeof(IUnknownObject),                     /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)IUnknownObject_dealloc,         /* tp_dealloc */
  0,                                          /* tp_print */
  0,                                          /* tp_getattr */
  0,                                          /* tp_setattr */
  0,                                          /* tp_compare */
  0,                                          /* tp_repr */
  0,                                          /* tp_as_number */
  0,                                          /* tp_as_sequence */
  0,                                          /* tp_as_mapping */
  0,                                          /* tp_hash  */
  0,                                          /* tp_call */
  0,                                          /* tp_str */
  0,                                          /* tp_getattro */
  0,                                          /* tp_setattro */
  0,                                          /* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
  "IUnknown",                                 /* tp_doc */
  0,                                          /* tp_traverse */
  0,                                          /* tp_clear */
  0,                                          /* tp_richcompare */
  0,                                          /* tp_weaklistoffset */
  0,                                          /* tp_iter */
  0,                                          /* tp_iternext */
  IUnknownMethods,                            /* tp_methods */
  0,                                          /* tp_members */
  IUnknownGetSet,                             /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  IUnknownObject_new,                         /* tp_new */
};




// Interface IDatabaseLockInfo

typedef struct PyIDatabaseLockInfoObject {
    PyObject_HEAD
    IDatabaseLockInfo* m_pIDatabaseLockInfo;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIDatabaseLockInfoObject;

static PyObject*
PyIDatabaseLockInfoObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIDatabaseLockInfoObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IDatabaseLockInfo* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IDatabaseLockInfo, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IDatabaseLockInfo with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIDatabaseLockInfoObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IDatabaseLockInfo");
            return NULL;
        }
        self->m_pIDatabaseLockInfo = pIFace;
        self->m_HR = hr;
        self->m_ignore_failures = 0;
        return (PyObject *)self;
    }
    // Are we passed an opaque pointer?
    else if (PyCObject_Check(argument))
    {
        pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
    }
    // No? See if there's an object._pUnk attribute that is one!
    else
    {
        argument = PyObject_GetAttrString(argument, "_pUnk");
        if (!argument)
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IDatabaseLockInfo");
            Py_XDECREF(argument);
            return NULL;
        }
        else if (PyCObject_Check(argument))
        {
            pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
        }
        else
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IDatabaseLockInfo");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IDatabaseLockInfo* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IDatabaseLockInfo, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IDatabaseLockInfo");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIDatabaseLockInfoObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IDatabaseLockInfo");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIDatabaseLockInfo = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIDatabaseLockInfoObject_dealloc(PyIDatabaseLockInfoObject* self)
{
    if (self->m_pIDatabaseLockInfo)
        self->m_pIDatabaseLockInfo->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIDatabaseLockInfo_GetpUnk(PyIDatabaseLockInfoObject* self)
{
    if (!self->m_pIDatabaseLockInfo)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIDatabaseLockInfo->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IDatabaseLockInfo to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIDatabaseLockInfo_GetPointer(PyIDatabaseLockInfoObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIDatabaseLockInfo);
}

static PyObject*
PyIDatabaseLockInfo_GetIID(PyIDatabaseLockInfoObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "58f47253-0f9d-4e59-a573-6a3267d0810c");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIDatabaseLockInfo_GetHR(PyIDatabaseLockInfoObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIDatabaseLockInfo_GetIgnoreFailures(PyIDatabaseLockInfoObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIDatabaseLockInfo_SetIgnoreFailures(PyIDatabaseLockInfoObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIDatabaseLockInfo_SupportsInterface(PyIDatabaseLockInfoObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIDatabaseLockInfo->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
        {
            ipUnk->Release();
            Py_RETURN_TRUE;
        }
        Py_RETURN_FALSE;
    }
    PyErr_SetString(PyExc_ValueError, "Bad interface ID.");
    return NULL;
}


static PyObject*
IDatabaseLockInfoMethod_get_SessionID(PyIDatabaseLockInfoObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lSessionID = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for SessionID

    // Call method on actual COM interface
    hr = self->m_pIDatabaseLockInfo->get_SessionID(&lSessionID);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDatabaseLockInfo->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDatabaseLockInfo) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDatabaseLockInfo.get_SessionID() returned %ld", (long)hr);
        goto idatabaselockinfo_get_sessionid_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for SessionID

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lSessionID);
    goto idatabaselockinfo_get_sessionid_method_cleanup;

    idatabaselockinfo_get_sessionid_method_cleanup:
    self->m_HR = hr;
    // No cleanup for SessionID
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDatabaseLockInfo.get_SessionID");
    return return_tuple;
}

static PyObject*
IDatabaseLockInfoMethod_get_LockOwner(PyIDatabaseLockInfoObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsowner;
    PyObject* pyvar_owner = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for owner

    // Call method on actual COM interface
    hr = self->m_pIDatabaseLockInfo->get_LockOwner(&bsowner);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDatabaseLockInfo->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDatabaseLockInfo) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDatabaseLockInfo.get_LockOwner() returned %ld", (long)hr);
        goto idatabaselockinfo_get_lockowner_method_cleanup;
    }

    // Set up return values as needed
    pyvar_owner = PyUnicode_FromWideChar(bsowner,::SysStringLen(bsowner));
    ::SysFreeString(bsowner);
    
    if (PyErr_Occurred())
      goto idatabaselockinfo_get_lockowner_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_owner);
    goto idatabaselockinfo_get_lockowner_method_cleanup;

    idatabaselockinfo_get_lockowner_method_cleanup:
    self->m_HR = hr;
    if (pyvar_owner != Py_None)
        Py_XDECREF(pyvar_owner);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDatabaseLockInfo.get_LockOwner");
    return return_tuple;
}

static PyObject*
IDatabaseLockInfoMethod_get_LockMode(PyIDatabaseLockInfoObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       OUTPUT [u'esriSdeLockMode', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IDatabaseLockInfo.get_LockMode not implemented.");
    return NULL;
}

static PyObject*
IDatabaseLockInfoMethod_get_LockTime(PyIDatabaseLockInfoObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT vtime;
    ::VariantInit(&vtime);
    PyObject* pyvar_time = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for time

    // Call method on actual COM interface
    hr = self->m_pIDatabaseLockInfo->get_LockTime(&vtime);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDatabaseLockInfo->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDatabaseLockInfo) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDatabaseLockInfo.get_LockTime() returned %ld", (long)hr);
        goto idatabaselockinfo_get_locktime_method_cleanup;
    }

    // Set up return values as needed
    pyvar_time = Variant_AsPyObject(&vtime);
    if (PyErr_Occurred())
      goto idatabaselockinfo_get_locktime_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_time);
    goto idatabaselockinfo_get_locktime_method_cleanup;

    idatabaselockinfo_get_locktime_method_cleanup:
    self->m_HR = hr;
    ::VariantClear(&vtime);
    Py_XDECREF(pyvar_time);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDatabaseLockInfo.get_LockTime");
    return return_tuple;
}

static PyObject*
IDatabaseLockInfoMethod_get_LockType(PyIDatabaseLockInfoObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       OUTPUT [u'esriSdeLockType', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IDatabaseLockInfo.get_LockType not implemented.");
    return NULL;
}

static PyObject*
IDatabaseLockInfoMethod_get_ObjectID(PyIDatabaseLockInfoObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       OUTPUT [u'__int64', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IDatabaseLockInfo.get_ObjectID not implemented.");
    return NULL;
}

static PyObject*
IDatabaseLockInfoMethod_get_ObjectName(PyIDatabaseLockInfoObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsname;
    PyObject* pyvar_name = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for name

    // Call method on actual COM interface
    hr = self->m_pIDatabaseLockInfo->get_ObjectName(&bsname);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDatabaseLockInfo->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDatabaseLockInfo) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDatabaseLockInfo.get_ObjectName() returned %ld", (long)hr);
        goto idatabaselockinfo_get_objectname_method_cleanup;
    }

    // Set up return values as needed
    pyvar_name = PyUnicode_FromWideChar(bsname,::SysStringLen(bsname));
    ::SysFreeString(bsname);
    
    if (PyErr_Occurred())
      goto idatabaselockinfo_get_objectname_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_name);
    goto idatabaselockinfo_get_objectname_method_cleanup;

    idatabaselockinfo_get_objectname_method_cleanup:
    self->m_HR = hr;
    if (pyvar_name != Py_None)
        Py_XDECREF(pyvar_name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDatabaseLockInfo.get_ObjectName");
    return return_tuple;
}

static PyObject*
IDatabaseLockInfoMethod_get_DatasetType(PyIDatabaseLockInfoObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriDatasetType etype;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for type

    // Call method on actual COM interface
    hr = self->m_pIDatabaseLockInfo->get_DatasetType(&etype);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDatabaseLockInfo->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDatabaseLockInfo) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDatabaseLockInfo.get_DatasetType() returned %ld", (long)hr);
        goto idatabaselockinfo_get_datasettype_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for type

    // Initialize output tuple
    return_tuple = Py_BuildValue("i",
                                            (int)etype);
    goto idatabaselockinfo_get_datasettype_method_cleanup;

    idatabaselockinfo_get_datasettype_method_cleanup:
    self->m_HR = hr;
    // No cleanup for type
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDatabaseLockInfo.get_DatasetType");
    return return_tuple;
}

static PyObject*
IDatabaseLockInfoMethod_get_IsOwnLock(PyIDatabaseLockInfoObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_IsOwnLock = VARIANT_FALSE;
    PyObject* pyvar_IsOwnLock = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for IsOwnLock

    // Call method on actual COM interface
    hr = self->m_pIDatabaseLockInfo->get_IsOwnLock(&b_IsOwnLock);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDatabaseLockInfo->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDatabaseLockInfo) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDatabaseLockInfo.get_IsOwnLock() returned %ld", (long)hr);
        goto idatabaselockinfo_get_isownlock_method_cleanup;
    }

    // Set up return values as needed
    pyvar_IsOwnLock = ((b_IsOwnLock == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto idatabaselockinfo_get_isownlock_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_IsOwnLock);
    goto idatabaselockinfo_get_isownlock_method_cleanup;

    idatabaselockinfo_get_isownlock_method_cleanup:
    self->m_HR = hr;
    // No cleanup for IsOwnLock
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDatabaseLockInfo.get_IsOwnLock");
    return return_tuple;
}


PyMethodDef PyIDatabaseLockInfoMethods[] = {
    {"supports", (PyCFunction)PyIDatabaseLockInfo_SupportsInterface, METH_O, ""},
    {"get_SessionID", (PyCFunction)IDatabaseLockInfoMethod_get_SessionID, METH_VARARGS, ""},
    {"get_LockOwner", (PyCFunction)IDatabaseLockInfoMethod_get_LockOwner, METH_VARARGS, ""},
    {"get_LockMode", (PyCFunction)IDatabaseLockInfoMethod_get_LockMode, METH_VARARGS, ""},
    {"get_LockTime", (PyCFunction)IDatabaseLockInfoMethod_get_LockTime, METH_VARARGS, ""},
    {"get_LockType", (PyCFunction)IDatabaseLockInfoMethod_get_LockType, METH_VARARGS, ""},
    {"get_ObjectID", (PyCFunction)IDatabaseLockInfoMethod_get_ObjectID, METH_VARARGS, ""},
    {"get_ObjectName", (PyCFunction)IDatabaseLockInfoMethod_get_ObjectName, METH_VARARGS, ""},
    {"get_DatasetType", (PyCFunction)IDatabaseLockInfoMethod_get_DatasetType, METH_VARARGS, ""},
    {"get_IsOwnLock", (PyCFunction)IDatabaseLockInfoMethod_get_IsOwnLock, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIDatabaseLockInfoGetSet[] = {
  {"_pUnk", (getter)PyIDatabaseLockInfo_GetpUnk, NULL, "Get opaque pointer to an Unknown from IDatabaseLockInfo", NULL},
  {"_pointer", (getter)PyIDatabaseLockInfo_GetPointer, NULL, "Get memory address for IDatabaseLockInfo", NULL},
  {"_IID", (getter)PyIDatabaseLockInfo_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIDatabaseLockInfo_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIDatabaseLockInfo_GetIgnoreFailures, (setter)PyIDatabaseLockInfo_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIDatabaseLockInfoObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesGDB.IDatabaseLockInfoObject",                          
                                              /* tp_name */
  sizeof(PyIDatabaseLockInfoObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIDatabaseLockInfoObject_dealloc,      
                                              /* tp_dealloc */
  0,                                          /* tp_print */
  0,                                          /* tp_getattr */
  0,                                          /* tp_setattr */
  0,                                          /* tp_compare */
  0,                                          /* tp_repr */
  0,                                          /* tp_as_number */
  0,                                          /* tp_as_sequence */
  0,                                          /* tp_as_mapping */
  0,                                          /* tp_hash  */
  0,                                          /* tp_call */
  0,                                          /* tp_str */
  0,                                          /* tp_getattro */
  0,                                          /* tp_setattro */
  0,                                          /* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
  "",                                  
                                              /* tp_doc */
  0,                                          /* tp_traverse */
  0,                                          /* tp_clear */
  0,                                          /* tp_richcompare */
  0,                                          /* tp_weaklistoffset */
  0,                                          /* tp_iter */
  0,                                          /* tp_iternext */
  PyIDatabaseLockInfoMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIDatabaseLockInfoGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIDatabaseLockInfoObject_new,                      
                                              /* tp_new */
};

// Interface IEnumDatabaseLockInfo

typedef struct PyIEnumDatabaseLockInfoObject {
    PyObject_HEAD
    IEnumDatabaseLockInfo* m_pIEnumDatabaseLockInfo;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIEnumDatabaseLockInfoObject;

static PyObject*
PyIEnumDatabaseLockInfoObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIEnumDatabaseLockInfoObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IEnumDatabaseLockInfo* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IEnumDatabaseLockInfo, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IEnumDatabaseLockInfo with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIEnumDatabaseLockInfoObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IEnumDatabaseLockInfo");
            return NULL;
        }
        self->m_pIEnumDatabaseLockInfo = pIFace;
        self->m_HR = hr;
        self->m_ignore_failures = 0;
        return (PyObject *)self;
    }
    // Are we passed an opaque pointer?
    else if (PyCObject_Check(argument))
    {
        pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
    }
    // No? See if there's an object._pUnk attribute that is one!
    else
    {
        argument = PyObject_GetAttrString(argument, "_pUnk");
        if (!argument)
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IEnumDatabaseLockInfo");
            Py_XDECREF(argument);
            return NULL;
        }
        else if (PyCObject_Check(argument))
        {
            pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
        }
        else
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IEnumDatabaseLockInfo");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IEnumDatabaseLockInfo* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IEnumDatabaseLockInfo, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IEnumDatabaseLockInfo");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIEnumDatabaseLockInfoObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IEnumDatabaseLockInfo");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIEnumDatabaseLockInfo = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIEnumDatabaseLockInfoObject_dealloc(PyIEnumDatabaseLockInfoObject* self)
{
    if (self->m_pIEnumDatabaseLockInfo)
        self->m_pIEnumDatabaseLockInfo->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIEnumDatabaseLockInfo_GetpUnk(PyIEnumDatabaseLockInfoObject* self)
{
    if (!self->m_pIEnumDatabaseLockInfo)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIEnumDatabaseLockInfo->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IEnumDatabaseLockInfo to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIEnumDatabaseLockInfo_GetPointer(PyIEnumDatabaseLockInfoObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIEnumDatabaseLockInfo);
}

static PyObject*
PyIEnumDatabaseLockInfo_GetIID(PyIEnumDatabaseLockInfoObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "225e1781-17cf-468e-a3d2-a59df3bb2d62");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIEnumDatabaseLockInfo_GetHR(PyIEnumDatabaseLockInfoObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIEnumDatabaseLockInfo_GetIgnoreFailures(PyIEnumDatabaseLockInfoObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIEnumDatabaseLockInfo_SetIgnoreFailures(PyIEnumDatabaseLockInfoObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIEnumDatabaseLockInfo_SupportsInterface(PyIEnumDatabaseLockInfoObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIEnumDatabaseLockInfo->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
        {
            ipUnk->Release();
            Py_RETURN_TRUE;
        }
        Py_RETURN_FALSE;
    }
    PyErr_SetString(PyExc_ValueError, "Bad interface ID.");
    return NULL;
}


static PyObject*
IEnumDatabaseLockInfoMethod_Reset(PyIEnumDatabaseLockInfoObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIEnumDatabaseLockInfo->Reset();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIEnumDatabaseLockInfo->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IEnumDatabaseLockInfo) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IEnumDatabaseLockInfo.Reset() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IEnumDatabaseLockInfoMethod_Next(PyIEnumDatabaseLockInfoObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IDatabaseLockInfo* iplockInfo = NULL;
    PyObject* py_lockInfo = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for lockInfo

    // Call method on actual COM interface
    hr = self->m_pIEnumDatabaseLockInfo->Next(&iplockInfo);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIEnumDatabaseLockInfo->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IEnumDatabaseLockInfo) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IEnumDatabaseLockInfo.Next() returned %ld", (long)hr);
        goto ienumdatabaselockinfo_next_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_lockInfo);
    if (iplockInfo)
    {
        IUnknown* pUnk = NULL;
        iplockInfo->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_lockInfo = IUnknownToPythonIIDObject(pUnk, &IID_IDatabaseLockInfo);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_lockInfo)
    {
        if (py_lockInfo)
           Py_DECREF(py_lockInfo);
        py_lockInfo = Py_None;
        Py_INCREF(py_lockInfo);
    }
    if (PyErr_Occurred())
      goto ienumdatabaselockinfo_next_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_lockInfo);
    goto ienumdatabaselockinfo_next_method_cleanup;

    ienumdatabaselockinfo_next_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_lockInfo);
    if (iplockInfo)
      iplockInfo->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IEnumDatabaseLockInfo.Next");
    return return_tuple;
}


PyMethodDef PyIEnumDatabaseLockInfoMethods[] = {
    {"supports", (PyCFunction)PyIEnumDatabaseLockInfo_SupportsInterface, METH_O, ""},
    {"Reset", (PyCFunction)IEnumDatabaseLockInfoMethod_Reset, METH_NOARGS, ""},
    {"Next", (PyCFunction)IEnumDatabaseLockInfoMethod_Next, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIEnumDatabaseLockInfoGetSet[] = {
  {"_pUnk", (getter)PyIEnumDatabaseLockInfo_GetpUnk, NULL, "Get opaque pointer to an Unknown from IEnumDatabaseLockInfo", NULL},
  {"_pointer", (getter)PyIEnumDatabaseLockInfo_GetPointer, NULL, "Get memory address for IEnumDatabaseLockInfo", NULL},
  {"_IID", (getter)PyIEnumDatabaseLockInfo_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIEnumDatabaseLockInfo_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIEnumDatabaseLockInfo_GetIgnoreFailures, (setter)PyIEnumDatabaseLockInfo_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIEnumDatabaseLockInfoObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesGDB.IEnumDatabaseLockInfoObject",                          
                                              /* tp_name */
  sizeof(PyIEnumDatabaseLockInfoObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIEnumDatabaseLockInfoObject_dealloc,      
                                              /* tp_dealloc */
  0,                                          /* tp_print */
  0,                                          /* tp_getattr */
  0,                                          /* tp_setattr */
  0,                                          /* tp_compare */
  0,                                          /* tp_repr */
  0,                                          /* tp_as_number */
  0,                                          /* tp_as_sequence */
  0,                                          /* tp_as_mapping */
  0,                                          /* tp_hash  */
  0,                                          /* tp_call */
  0,                                          /* tp_str */
  0,                                          /* tp_getattro */
  0,                                          /* tp_setattro */
  0,                                          /* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
  "",                                  
                                              /* tp_doc */
  0,                                          /* tp_traverse */
  0,                                          /* tp_clear */
  0,                                          /* tp_richcompare */
  0,                                          /* tp_weaklistoffset */
  0,                                          /* tp_iter */
  0,                                          /* tp_iternext */
  PyIEnumDatabaseLockInfoMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIEnumDatabaseLockInfoGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIEnumDatabaseLockInfoObject_new,                      
                                              /* tp_new */
};

// Interface IDatabaseLocksInfo

typedef struct PyIDatabaseLocksInfoObject {
    PyObject_HEAD
    IDatabaseLocksInfo* m_pIDatabaseLocksInfo;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIDatabaseLocksInfoObject;

static PyObject*
PyIDatabaseLocksInfoObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIDatabaseLocksInfoObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IDatabaseLocksInfo* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IDatabaseLocksInfo, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IDatabaseLocksInfo with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIDatabaseLocksInfoObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IDatabaseLocksInfo");
            return NULL;
        }
        self->m_pIDatabaseLocksInfo = pIFace;
        self->m_HR = hr;
        self->m_ignore_failures = 0;
        return (PyObject *)self;
    }
    // Are we passed an opaque pointer?
    else if (PyCObject_Check(argument))
    {
        pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
    }
    // No? See if there's an object._pUnk attribute that is one!
    else
    {
        argument = PyObject_GetAttrString(argument, "_pUnk");
        if (!argument)
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IDatabaseLocksInfo");
            Py_XDECREF(argument);
            return NULL;
        }
        else if (PyCObject_Check(argument))
        {
            pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
        }
        else
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IDatabaseLocksInfo");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IDatabaseLocksInfo* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IDatabaseLocksInfo, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IDatabaseLocksInfo");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIDatabaseLocksInfoObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IDatabaseLocksInfo");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIDatabaseLocksInfo = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIDatabaseLocksInfoObject_dealloc(PyIDatabaseLocksInfoObject* self)
{
    if (self->m_pIDatabaseLocksInfo)
        self->m_pIDatabaseLocksInfo->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIDatabaseLocksInfo_GetpUnk(PyIDatabaseLocksInfoObject* self)
{
    if (!self->m_pIDatabaseLocksInfo)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIDatabaseLocksInfo->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IDatabaseLocksInfo to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIDatabaseLocksInfo_GetPointer(PyIDatabaseLocksInfoObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIDatabaseLocksInfo);
}

static PyObject*
PyIDatabaseLocksInfo_GetIID(PyIDatabaseLocksInfoObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "8aee3af9-4b7c-4c88-ba9f-388a9791d907");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIDatabaseLocksInfo_GetHR(PyIDatabaseLocksInfoObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIDatabaseLocksInfo_GetIgnoreFailures(PyIDatabaseLocksInfoObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIDatabaseLocksInfo_SetIgnoreFailures(PyIDatabaseLocksInfoObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIDatabaseLocksInfo_SupportsInterface(PyIDatabaseLocksInfoObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIDatabaseLocksInfo->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
        {
            ipUnk->Release();
            Py_RETURN_TRUE;
        }
        Py_RETURN_FALSE;
    }
    PyErr_SetString(PyExc_ValueError, "Bad interface ID.");
    return NULL;
}


static PyObject*
IDatabaseLocksInfoMethod_get_AllLocks(PyIDatabaseLocksInfoObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IEnumDatabaseLockInfo* iplocks = NULL;
    PyObject* py_locks = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for locks

    // Call method on actual COM interface
    hr = self->m_pIDatabaseLocksInfo->get_AllLocks(&iplocks);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDatabaseLocksInfo->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDatabaseLocksInfo) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDatabaseLocksInfo.get_AllLocks() returned %ld", (long)hr);
        goto idatabaselocksinfo_get_alllocks_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_locks);
    if (iplocks)
    {
        IUnknown* pUnk = NULL;
        iplocks->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_locks = IUnknownToPythonIIDObject(pUnk, &IID_IEnumDatabaseLockInfo);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_locks)
    {
        if (py_locks)
           Py_DECREF(py_locks);
        py_locks = Py_None;
        Py_INCREF(py_locks);
    }
    if (PyErr_Occurred())
      goto idatabaselocksinfo_get_alllocks_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_locks);
    goto idatabaselocksinfo_get_alllocks_method_cleanup;

    idatabaselocksinfo_get_alllocks_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_locks);
    if (iplocks)
      iplocks->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDatabaseLocksInfo.get_AllLocks");
    return return_tuple;
}


PyMethodDef PyIDatabaseLocksInfoMethods[] = {
    {"supports", (PyCFunction)PyIDatabaseLocksInfo_SupportsInterface, METH_O, ""},
    {"get_AllLocks", (PyCFunction)IDatabaseLocksInfoMethod_get_AllLocks, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIDatabaseLocksInfoGetSet[] = {
  {"_pUnk", (getter)PyIDatabaseLocksInfo_GetpUnk, NULL, "Get opaque pointer to an Unknown from IDatabaseLocksInfo", NULL},
  {"_pointer", (getter)PyIDatabaseLocksInfo_GetPointer, NULL, "Get memory address for IDatabaseLocksInfo", NULL},
  {"_IID", (getter)PyIDatabaseLocksInfo_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIDatabaseLocksInfo_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIDatabaseLocksInfo_GetIgnoreFailures, (setter)PyIDatabaseLocksInfo_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIDatabaseLocksInfoObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesGDB.IDatabaseLocksInfoObject",                          
                                              /* tp_name */
  sizeof(PyIDatabaseLocksInfoObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIDatabaseLocksInfoObject_dealloc,      
                                              /* tp_dealloc */
  0,                                          /* tp_print */
  0,                                          /* tp_getattr */
  0,                                          /* tp_setattr */
  0,                                          /* tp_compare */
  0,                                          /* tp_repr */
  0,                                          /* tp_as_number */
  0,                                          /* tp_as_sequence */
  0,                                          /* tp_as_mapping */
  0,                                          /* tp_hash  */
  0,                                          /* tp_call */
  0,                                          /* tp_str */
  0,                                          /* tp_getattro */
  0,                                          /* tp_setattro */
  0,                                          /* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
  "",                                  
                                              /* tp_doc */
  0,                                          /* tp_traverse */
  0,                                          /* tp_clear */
  0,                                          /* tp_richcompare */
  0,                                          /* tp_weaklistoffset */
  0,                                          /* tp_iter */
  0,                                          /* tp_iternext */
  PyIDatabaseLocksInfoMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIDatabaseLocksInfoGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIDatabaseLocksInfoObject_new,                      
                                              /* tp_new */
};

// Interface IFileGDBLockWaiting

typedef struct PyIFileGDBLockWaitingObject {
    PyObject_HEAD
    IFileGDBLockWaiting* m_pIFileGDBLockWaiting;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIFileGDBLockWaitingObject;

static PyObject*
PyIFileGDBLockWaitingObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIFileGDBLockWaitingObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IFileGDBLockWaiting* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IFileGDBLockWaiting, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IFileGDBLockWaiting with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIFileGDBLockWaitingObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IFileGDBLockWaiting");
            return NULL;
        }
        self->m_pIFileGDBLockWaiting = pIFace;
        self->m_HR = hr;
        self->m_ignore_failures = 0;
        return (PyObject *)self;
    }
    // Are we passed an opaque pointer?
    else if (PyCObject_Check(argument))
    {
        pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
    }
    // No? See if there's an object._pUnk attribute that is one!
    else
    {
        argument = PyObject_GetAttrString(argument, "_pUnk");
        if (!argument)
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IFileGDBLockWaiting");
            Py_XDECREF(argument);
            return NULL;
        }
        else if (PyCObject_Check(argument))
        {
            pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
        }
        else
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IFileGDBLockWaiting");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IFileGDBLockWaiting* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IFileGDBLockWaiting, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IFileGDBLockWaiting");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIFileGDBLockWaitingObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IFileGDBLockWaiting");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIFileGDBLockWaiting = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIFileGDBLockWaitingObject_dealloc(PyIFileGDBLockWaitingObject* self)
{
    if (self->m_pIFileGDBLockWaiting)
        self->m_pIFileGDBLockWaiting->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIFileGDBLockWaiting_GetpUnk(PyIFileGDBLockWaitingObject* self)
{
    if (!self->m_pIFileGDBLockWaiting)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIFileGDBLockWaiting->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IFileGDBLockWaiting to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIFileGDBLockWaiting_GetPointer(PyIFileGDBLockWaitingObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIFileGDBLockWaiting);
}

static PyObject*
PyIFileGDBLockWaiting_GetIID(PyIFileGDBLockWaitingObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "097854c7-dbcb-483e-8730-fa5f42744ecc");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIFileGDBLockWaiting_GetHR(PyIFileGDBLockWaitingObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIFileGDBLockWaiting_GetIgnoreFailures(PyIFileGDBLockWaitingObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIFileGDBLockWaiting_SetIgnoreFailures(PyIFileGDBLockWaitingObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIFileGDBLockWaiting_SupportsInterface(PyIFileGDBLockWaitingObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIFileGDBLockWaiting->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
        {
            ipUnk->Release();
            Py_RETURN_TRUE;
        }
        Py_RETURN_FALSE;
    }
    PyErr_SetString(PyExc_ValueError, "Bad interface ID.");
    return NULL;
}


static PyObject*
IFileGDBLockWaitingMethod_EnableWriteLockWaiting(PyIFileGDBLockWaitingObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lretryCount = 0;
    long lwaitTime1 = 0;
    long lwaitTime2 = 0;
    long lwaitTime3 = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "llll", &lretryCount, &lwaitTime1, &lwaitTime2, &lwaitTime3))
      goto ifilegdblockwaiting_enablewritelockwaiting_method_cleanup;

    // Set up initial variable values as needed
    // No setup for retryCount
    // No setup for waitTime1
    // No setup for waitTime2
    // No setup for waitTime3

    // Call method on actual COM interface
    hr = self->m_pIFileGDBLockWaiting->EnableWriteLockWaiting(lretryCount, lwaitTime1, lwaitTime2, lwaitTime3);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIFileGDBLockWaiting->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IFileGDBLockWaiting) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IFileGDBLockWaiting.EnableWriteLockWaiting() returned %ld", (long)hr);
        goto ifilegdblockwaiting_enablewritelockwaiting_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for retryCount
    // No teardown for waitTime1
    // No teardown for waitTime2
    // No teardown for waitTime3

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto ifilegdblockwaiting_enablewritelockwaiting_method_cleanup;

    ifilegdblockwaiting_enablewritelockwaiting_method_cleanup:
    self->m_HR = hr;
    // No cleanup for retryCount
    // No cleanup for waitTime1
    // No cleanup for waitTime2
    // No cleanup for waitTime3
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IFileGDBLockWaiting.EnableWriteLockWaiting");
    return return_tuple;
}

static PyObject*
IFileGDBLockWaitingMethod_DisableWriteLockWaiting(PyIFileGDBLockWaitingObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIFileGDBLockWaiting->DisableWriteLockWaiting();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIFileGDBLockWaiting->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IFileGDBLockWaiting) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IFileGDBLockWaiting.DisableWriteLockWaiting() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}


PyMethodDef PyIFileGDBLockWaitingMethods[] = {
    {"supports", (PyCFunction)PyIFileGDBLockWaiting_SupportsInterface, METH_O, ""},
    {"EnableWriteLockWaiting", (PyCFunction)IFileGDBLockWaitingMethod_EnableWriteLockWaiting, METH_VARARGS, ""},
    {"DisableWriteLockWaiting", (PyCFunction)IFileGDBLockWaitingMethod_DisableWriteLockWaiting, METH_NOARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIFileGDBLockWaitingGetSet[] = {
  {"_pUnk", (getter)PyIFileGDBLockWaiting_GetpUnk, NULL, "Get opaque pointer to an Unknown from IFileGDBLockWaiting", NULL},
  {"_pointer", (getter)PyIFileGDBLockWaiting_GetPointer, NULL, "Get memory address for IFileGDBLockWaiting", NULL},
  {"_IID", (getter)PyIFileGDBLockWaiting_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIFileGDBLockWaiting_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIFileGDBLockWaiting_GetIgnoreFailures, (setter)PyIFileGDBLockWaiting_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIFileGDBLockWaitingObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesGDB.IFileGDBLockWaitingObject",                          
                                              /* tp_name */
  sizeof(PyIFileGDBLockWaitingObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIFileGDBLockWaitingObject_dealloc,      
                                              /* tp_dealloc */
  0,                                          /* tp_print */
  0,                                          /* tp_getattr */
  0,                                          /* tp_setattr */
  0,                                          /* tp_compare */
  0,                                          /* tp_repr */
  0,                                          /* tp_as_number */
  0,                                          /* tp_as_sequence */
  0,                                          /* tp_as_mapping */
  0,                                          /* tp_hash  */
  0,                                          /* tp_call */
  0,                                          /* tp_str */
  0,                                          /* tp_getattro */
  0,                                          /* tp_setattro */
  0,                                          /* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
  "",                                  
                                              /* tp_doc */
  0,                                          /* tp_traverse */
  0,                                          /* tp_clear */
  0,                                          /* tp_richcompare */
  0,                                          /* tp_weaklistoffset */
  0,                                          /* tp_iter */
  0,                                          /* tp_iternext */
  PyIFileGDBLockWaitingMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIFileGDBLockWaitingGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIFileGDBLockWaitingObject_new,                      
                                              /* tp_new */
};

// Interface IDataServerManager

typedef struct PyIDataServerManagerObject {
    PyObject_HEAD
    IDataServerManager* m_pIDataServerManager;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIDataServerManagerObject;

static PyObject*
PyIDataServerManagerObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIDataServerManagerObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IDataServerManager* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IDataServerManager, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IDataServerManager with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIDataServerManagerObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IDataServerManager");
            return NULL;
        }
        self->m_pIDataServerManager = pIFace;
        self->m_HR = hr;
        self->m_ignore_failures = 0;
        return (PyObject *)self;
    }
    // Are we passed an opaque pointer?
    else if (PyCObject_Check(argument))
    {
        pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
    }
    // No? See if there's an object._pUnk attribute that is one!
    else
    {
        argument = PyObject_GetAttrString(argument, "_pUnk");
        if (!argument)
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IDataServerManager");
            Py_XDECREF(argument);
            return NULL;
        }
        else if (PyCObject_Check(argument))
        {
            pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
        }
        else
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IDataServerManager");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IDataServerManager* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IDataServerManager, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IDataServerManager");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIDataServerManagerObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IDataServerManager");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIDataServerManager = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIDataServerManagerObject_dealloc(PyIDataServerManagerObject* self)
{
    if (self->m_pIDataServerManager)
        self->m_pIDataServerManager->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIDataServerManager_GetpUnk(PyIDataServerManagerObject* self)
{
    if (!self->m_pIDataServerManager)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIDataServerManager->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IDataServerManager to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIDataServerManager_GetPointer(PyIDataServerManagerObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIDataServerManager);
}

static PyObject*
PyIDataServerManager_GetIID(PyIDataServerManagerObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "737ef71f-3646-49f3-95b9-667259a5d498");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIDataServerManager_GetHR(PyIDataServerManagerObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIDataServerManager_GetIgnoreFailures(PyIDataServerManagerObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIDataServerManager_SetIgnoreFailures(PyIDataServerManagerObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIDataServerManager_SupportsInterface(PyIDataServerManagerObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
        {
            ipUnk->Release();
            Py_RETURN_TRUE;
        }
        Py_RETURN_FALSE;
    }
    PyErr_SetString(PyExc_ValueError, "Bad interface ID.");
    return NULL;
}


static PyObject*
IDataServerManagerMethod_Connect(PyIDataServerManagerObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIDataServerManager->Connect();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.Connect() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IDataServerManagerMethod_Disconnect(PyIDataServerManagerObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIDataServerManager->Disconnect();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.Disconnect() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IDataServerManagerMethod_put_ServerName(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsServerName = 0;
    PyObject* pyvar_ServerName;
    PyObject* unicodeServerName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_ServerName))
      goto idataservermanager_put_servername_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_ServerName))
        unicodeServerName = PyUnicode_FromObject(pyvar_ServerName);
    else if (PyUnicode_Check(pyvar_ServerName))
    {
        unicodeServerName = pyvar_ServerName;
        Py_INCREF(unicodeServerName);
    }
    else if (pyvar_ServerName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter ServerName at index 0");
    if (unicodeServerName)
        bsServerName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeServerName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeServerName));
    
    if (PyErr_Occurred())
      goto idataservermanager_put_servername_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->put_ServerName(bsServerName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.put_ServerName() returned %ld", (long)hr);
        goto idataservermanager_put_servername_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for ServerName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanager_put_servername_method_cleanup;

    idataservermanager_put_servername_method_cleanup:
    self->m_HR = hr;
    if (bsServerName)
        ::SysFreeString(bsServerName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.put_ServerName");
    return return_tuple;
}

static PyObject*
IDataServerManagerMethod_get_ServerName(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsServerName;
    PyObject* pyvar_ServerName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ServerName

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->get_ServerName(&bsServerName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.get_ServerName() returned %ld", (long)hr);
        goto idataservermanager_get_servername_method_cleanup;
    }

    // Set up return values as needed
    pyvar_ServerName = PyUnicode_FromWideChar(bsServerName,::SysStringLen(bsServerName));
    ::SysFreeString(bsServerName);
    
    if (PyErr_Occurred())
      goto idataservermanager_get_servername_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_ServerName);
    goto idataservermanager_get_servername_method_cleanup;

    idataservermanager_get_servername_method_cleanup:
    self->m_HR = hr;
    if (pyvar_ServerName != Py_None)
        Py_XDECREF(pyvar_ServerName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.get_ServerName");
    return return_tuple;
}

static PyObject*
IDataServerManagerMethod_InitFromFile(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdsFileName = 0;
    PyObject* pyvar_gdsFileName;
    PyObject* unicodegdsFileName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_gdsFileName))
      goto idataservermanager_initfromfile_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdsFileName))
        unicodegdsFileName = PyUnicode_FromObject(pyvar_gdsFileName);
    else if (PyUnicode_Check(pyvar_gdsFileName))
    {
        unicodegdsFileName = pyvar_gdsFileName;
        Py_INCREF(unicodegdsFileName);
    }
    else if (pyvar_gdsFileName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdsFileName at index 0");
    if (unicodegdsFileName)
        bsgdsFileName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdsFileName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdsFileName));
    
    if (PyErr_Occurred())
      goto idataservermanager_initfromfile_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->InitFromFile(bsgdsFileName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.InitFromFile() returned %ld", (long)hr);
        goto idataservermanager_initfromfile_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdsFileName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanager_initfromfile_method_cleanup;

    idataservermanager_initfromfile_method_cleanup:
    self->m_HR = hr;
    if (bsgdsFileName)
        ::SysFreeString(bsgdsFileName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.InitFromFile");
    return return_tuple;
}

static PyObject*
IDataServerManagerMethod_CreateConnectionFile(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspathName = 0;
    PyObject* pyvar_pathName;
    PyObject* unicodepathName = NULL;
    BSTR bsServerName = 0;
    PyObject* pyvar_ServerName;
    PyObject* unicodeServerName = NULL;
    BSTR bsconnFileName;
    PyObject* pyvar_connFileName = Py_None;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OO", &pyvar_pathName, &pyvar_ServerName))
      goto idataservermanager_createconnectionfile_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_pathName))
        unicodepathName = PyUnicode_FromObject(pyvar_pathName);
    else if (PyUnicode_Check(pyvar_pathName))
    {
        unicodepathName = pyvar_pathName;
        Py_INCREF(unicodepathName);
    }
    else if (pyvar_pathName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter pathName at index 0");
    if (unicodepathName)
        bspathName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodepathName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodepathName));
    
    if (PyErr_Occurred())
      goto idataservermanager_createconnectionfile_method_cleanup;
    
    if (PyString_Check(pyvar_ServerName))
        unicodeServerName = PyUnicode_FromObject(pyvar_ServerName);
    else if (PyUnicode_Check(pyvar_ServerName))
    {
        unicodeServerName = pyvar_ServerName;
        Py_INCREF(unicodeServerName);
    }
    else if (pyvar_ServerName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter ServerName at index 1");
    if (unicodeServerName)
        bsServerName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeServerName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeServerName));
    
    if (PyErr_Occurred())
      goto idataservermanager_createconnectionfile_method_cleanup;
    
    // No setup for connFileName

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->CreateConnectionFile(bspathName, bsServerName, &bsconnFileName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.CreateConnectionFile() returned %ld", (long)hr);
        goto idataservermanager_createconnectionfile_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pathName
    // No teardown for ServerName
    pyvar_connFileName = PyUnicode_FromWideChar(bsconnFileName,::SysStringLen(bsconnFileName));
    ::SysFreeString(bsconnFileName);
    
    if (PyErr_Occurred())
      goto idataservermanager_createconnectionfile_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_connFileName);
    goto idataservermanager_createconnectionfile_method_cleanup;

    idataservermanager_createconnectionfile_method_cleanup:
    self->m_HR = hr;
    if (bspathName)
        ::SysFreeString(bspathName);
    
    if (bsServerName)
        ::SysFreeString(bsServerName);
    
    if (pyvar_connFileName != Py_None)
        Py_XDECREF(pyvar_connFileName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.CreateConnectionFile");
    return return_tuple;
}

static PyObject*
IDataServerManagerMethod_get_IsConnected(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_IsConnected = VARIANT_FALSE;
    PyObject* pyvar_IsConnected = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for IsConnected

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->get_IsConnected(&b_IsConnected);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.get_IsConnected() returned %ld", (long)hr);
        goto idataservermanager_get_isconnected_method_cleanup;
    }

    // Set up return values as needed
    pyvar_IsConnected = ((b_IsConnected == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto idataservermanager_get_isconnected_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_IsConnected);
    goto idataservermanager_get_isconnected_method_cleanup;

    idataservermanager_get_isconnected_method_cleanup:
    self->m_HR = hr;
    // No cleanup for IsConnected
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.get_IsConnected");
    return return_tuple;
}

static PyObject*
IDataServerManagerMethod_get_DataServerType(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriDataServerType etype;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for type

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->get_DataServerType(&etype);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.get_DataServerType() returned %ld", (long)hr);
        goto idataservermanager_get_dataservertype_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for type

    // Initialize output tuple
    return_tuple = Py_BuildValue("i",
                                            (int)etype);
    goto idataservermanager_get_dataservertype_method_cleanup;

    idataservermanager_get_dataservertype_method_cleanup:
    self->m_HR = hr;
    // No cleanup for type
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.get_DataServerType");
    return return_tuple;
}

static PyObject*
IDataServerManagerMethod_get_ProductName(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsname;
    PyObject* pyvar_name = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for name

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->get_ProductName(&bsname);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.get_ProductName() returned %ld", (long)hr);
        goto idataservermanager_get_productname_method_cleanup;
    }

    // Set up return values as needed
    pyvar_name = PyUnicode_FromWideChar(bsname,::SysStringLen(bsname));
    ::SysFreeString(bsname);
    
    if (PyErr_Occurred())
      goto idataservermanager_get_productname_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_name);
    goto idataservermanager_get_productname_method_cleanup;

    idataservermanager_get_productname_method_cleanup:
    self->m_HR = hr;
    if (pyvar_name != Py_None)
        Py_XDECREF(pyvar_name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.get_ProductName");
    return return_tuple;
}

static PyObject*
IDataServerManagerMethod_get_ProductVersion(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsversion;
    PyObject* pyvar_version = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for version

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->get_ProductVersion(&bsversion);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.get_ProductVersion() returned %ld", (long)hr);
        goto idataservermanager_get_productversion_method_cleanup;
    }

    // Set up return values as needed
    pyvar_version = PyUnicode_FromWideChar(bsversion,::SysStringLen(bsversion));
    ::SysFreeString(bsversion);
    
    if (PyErr_Occurred())
      goto idataservermanager_get_productversion_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_version);
    goto idataservermanager_get_productversion_method_cleanup;

    idataservermanager_get_productversion_method_cleanup:
    self->m_HR = hr;
    if (pyvar_version != Py_None)
        Py_XDECREF(pyvar_version);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.get_ProductVersion");
    return return_tuple;
}

static PyObject*
IDataServerManagerMethod_get_AvailableMemory(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lmemory = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for memory

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->get_AvailableMemory(&lmemory);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.get_AvailableMemory() returned %ld", (long)hr);
        goto idataservermanager_get_availablememory_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for memory

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lmemory);
    goto idataservermanager_get_availablememory_method_cleanup;

    idataservermanager_get_availablememory_method_cleanup:
    self->m_HR = hr;
    // No cleanup for memory
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.get_AvailableMemory");
    return return_tuple;
}

static PyObject*
IDataServerManagerMethod_get_DataServerClass(PyIDataServerManagerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriGeodatabaseServerClassType esclass;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for sclass

    // Call method on actual COM interface
    hr = self->m_pIDataServerManager->get_DataServerClass(&esclass);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManager->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManager) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManager.get_DataServerClass() returned %ld", (long)hr);
        goto idataservermanager_get_dataserverclass_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for sclass

    // Initialize output tuple
    return_tuple = Py_BuildValue("i",
                                            (int)esclass);
    goto idataservermanager_get_dataserverclass_method_cleanup;

    idataservermanager_get_dataserverclass_method_cleanup:
    self->m_HR = hr;
    // No cleanup for sclass
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManager.get_DataServerClass");
    return return_tuple;
}


PyMethodDef PyIDataServerManagerMethods[] = {
    {"supports", (PyCFunction)PyIDataServerManager_SupportsInterface, METH_O, ""},
    {"Connect", (PyCFunction)IDataServerManagerMethod_Connect, METH_NOARGS, ""},
    {"Disconnect", (PyCFunction)IDataServerManagerMethod_Disconnect, METH_NOARGS, ""},
    {"put_ServerName", (PyCFunction)IDataServerManagerMethod_put_ServerName, METH_VARARGS, ""},
    {"get_ServerName", (PyCFunction)IDataServerManagerMethod_get_ServerName, METH_VARARGS, ""},
    {"InitFromFile", (PyCFunction)IDataServerManagerMethod_InitFromFile, METH_VARARGS, ""},
    {"CreateConnectionFile", (PyCFunction)IDataServerManagerMethod_CreateConnectionFile, METH_VARARGS, ""},
    {"get_IsConnected", (PyCFunction)IDataServerManagerMethod_get_IsConnected, METH_VARARGS, ""},
    {"get_DataServerType", (PyCFunction)IDataServerManagerMethod_get_DataServerType, METH_VARARGS, ""},
    {"get_ProductName", (PyCFunction)IDataServerManagerMethod_get_ProductName, METH_VARARGS, ""},
    {"get_ProductVersion", (PyCFunction)IDataServerManagerMethod_get_ProductVersion, METH_VARARGS, ""},
    {"get_AvailableMemory", (PyCFunction)IDataServerManagerMethod_get_AvailableMemory, METH_VARARGS, ""},
    {"get_DataServerClass", (PyCFunction)IDataServerManagerMethod_get_DataServerClass, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIDataServerManagerGetSet[] = {
  {"_pUnk", (getter)PyIDataServerManager_GetpUnk, NULL, "Get opaque pointer to an Unknown from IDataServerManager", NULL},
  {"_pointer", (getter)PyIDataServerManager_GetPointer, NULL, "Get memory address for IDataServerManager", NULL},
  {"_IID", (getter)PyIDataServerManager_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIDataServerManager_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIDataServerManager_GetIgnoreFailures, (setter)PyIDataServerManager_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIDataServerManagerObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesGDB.IDataServerManagerObject",                          
                                              /* tp_name */
  sizeof(PyIDataServerManagerObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIDataServerManagerObject_dealloc,      
                                              /* tp_dealloc */
  0,                                          /* tp_print */
  0,                                          /* tp_getattr */
  0,                                          /* tp_setattr */
  0,                                          /* tp_compare */
  0,                                          /* tp_repr */
  0,                                          /* tp_as_number */
  0,                                          /* tp_as_sequence */
  0,                                          /* tp_as_mapping */
  0,                                          /* tp_hash  */
  0,                                          /* tp_call */
  0,                                          /* tp_str */
  0,                                          /* tp_getattro */
  0,                                          /* tp_setattro */
  0,                                          /* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
  "",                                  
                                              /* tp_doc */
  0,                                          /* tp_traverse */
  0,                                          /* tp_clear */
  0,                                          /* tp_richcompare */
  0,                                          /* tp_weaklistoffset */
  0,                                          /* tp_iter */
  0,                                          /* tp_iternext */
  PyIDataServerManagerMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIDataServerManagerGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIDataServerManagerObject_new,                      
                                              /* tp_new */
};

// Interface IDataServerManagerAdmin

typedef struct PyIDataServerManagerAdminObject {
    PyObject_HEAD
    IDataServerManagerAdmin* m_pIDataServerManagerAdmin;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIDataServerManagerAdminObject;

static PyObject*
PyIDataServerManagerAdminObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIDataServerManagerAdminObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IDataServerManagerAdmin* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IDataServerManagerAdmin, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IDataServerManagerAdmin with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIDataServerManagerAdminObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IDataServerManagerAdmin");
            return NULL;
        }
        self->m_pIDataServerManagerAdmin = pIFace;
        self->m_HR = hr;
        self->m_ignore_failures = 0;
        return (PyObject *)self;
    }
    // Are we passed an opaque pointer?
    else if (PyCObject_Check(argument))
    {
        pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
    }
    // No? See if there's an object._pUnk attribute that is one!
    else
    {
        argument = PyObject_GetAttrString(argument, "_pUnk");
        if (!argument)
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IDataServerManagerAdmin");
            Py_XDECREF(argument);
            return NULL;
        }
        else if (PyCObject_Check(argument))
        {
            pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
        }
        else
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IDataServerManagerAdmin");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IDataServerManagerAdmin* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IDataServerManagerAdmin, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IDataServerManagerAdmin");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIDataServerManagerAdminObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IDataServerManagerAdmin");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIDataServerManagerAdmin = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIDataServerManagerAdminObject_dealloc(PyIDataServerManagerAdminObject* self)
{
    if (self->m_pIDataServerManagerAdmin)
        self->m_pIDataServerManagerAdmin->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIDataServerManagerAdmin_GetpUnk(PyIDataServerManagerAdminObject* self)
{
    if (!self->m_pIDataServerManagerAdmin)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIDataServerManagerAdmin->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IDataServerManagerAdmin to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIDataServerManagerAdmin_GetPointer(PyIDataServerManagerAdminObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIDataServerManagerAdmin);
}

static PyObject*
PyIDataServerManagerAdmin_GetIID(PyIDataServerManagerAdminObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "dd374473-eda4-4a24-80f5-0b8c708a453b");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIDataServerManagerAdmin_GetHR(PyIDataServerManagerAdminObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIDataServerManagerAdmin_GetIgnoreFailures(PyIDataServerManagerAdminObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIDataServerManagerAdmin_SetIgnoreFailures(PyIDataServerManagerAdminObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIDataServerManagerAdmin_SupportsInterface(PyIDataServerManagerAdminObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
        {
            ipUnk->Release();
            Py_RETURN_TRUE;
        }
        Py_RETURN_FALSE;
    }
    PyErr_SetString(PyExc_ValueError, "Bad interface ID.");
    return NULL;
}


static PyObject*
IDataServerManagerAdminMethod_CreateGeodatabase(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;
    BSTR bsgdbFileName = 0;
    PyObject* pyvar_gdbFileName;
    PyObject* unicodegdbFileName = NULL;
    long lgdbFileSize = 0;
    BSTR bslogFileName = 0;
    PyObject* pyvar_logFileName;
    PyObject* unicodelogFileName = NULL;
    long llogFileSize = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OOlOl", &pyvar_gdbName, &pyvar_gdbFileName, &lgdbFileSize, &pyvar_logFileName, &llogFileSize))
      goto idataservermanageradmin_creategeodatabase_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_creategeodatabase_method_cleanup;
    
    if (PyString_Check(pyvar_gdbFileName))
        unicodegdbFileName = PyUnicode_FromObject(pyvar_gdbFileName);
    else if (PyUnicode_Check(pyvar_gdbFileName))
    {
        unicodegdbFileName = pyvar_gdbFileName;
        Py_INCREF(unicodegdbFileName);
    }
    else if (pyvar_gdbFileName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbFileName at index 1");
    if (unicodegdbFileName)
        bsgdbFileName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbFileName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbFileName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_creategeodatabase_method_cleanup;
    
    // No setup for gdbFileSize
    if (PyString_Check(pyvar_logFileName))
        unicodelogFileName = PyUnicode_FromObject(pyvar_logFileName);
    else if (PyUnicode_Check(pyvar_logFileName))
    {
        unicodelogFileName = pyvar_logFileName;
        Py_INCREF(unicodelogFileName);
    }
    else if (pyvar_logFileName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter logFileName at index 3");
    if (unicodelogFileName)
        bslogFileName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodelogFileName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodelogFileName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_creategeodatabase_method_cleanup;
    
    // No setup for logFileSize

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->CreateGeodatabase(bsgdbName, bsgdbFileName, lgdbFileSize, bslogFileName, llogFileSize);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.CreateGeodatabase() returned %ld", (long)hr);
        goto idataservermanageradmin_creategeodatabase_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName
    // No teardown for gdbFileName
    // No teardown for gdbFileSize
    // No teardown for logFileName
    // No teardown for logFileSize

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_creategeodatabase_method_cleanup;

    idataservermanageradmin_creategeodatabase_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (bsgdbFileName)
        ::SysFreeString(bsgdbFileName);
    
    // No cleanup for gdbFileSize
    if (bslogFileName)
        ::SysFreeString(bslogFileName);
    
    // No cleanup for logFileSize
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.CreateGeodatabase");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_DeleteGeodatabase(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_gdbName))
      goto idataservermanageradmin_deletegeodatabase_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_deletegeodatabase_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->DeleteGeodatabase(bsgdbName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.DeleteGeodatabase() returned %ld", (long)hr);
        goto idataservermanageradmin_deletegeodatabase_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_deletegeodatabase_method_cleanup;

    idataservermanageradmin_deletegeodatabase_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.DeleteGeodatabase");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_CreateLogin(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsloginName = 0;
    PyObject* pyvar_loginName;
    PyObject* unicodeloginName = NULL;
    VARIANT_BOOL b_isAdministrator = VARIANT_FALSE;
    PyObject* pyvar_isAdministrator = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OO", &pyvar_loginName, &pyvar_isAdministrator))
      goto idataservermanageradmin_createlogin_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_loginName))
        unicodeloginName = PyUnicode_FromObject(pyvar_loginName);
    else if (PyUnicode_Check(pyvar_loginName))
    {
        unicodeloginName = pyvar_loginName;
        Py_INCREF(unicodeloginName);
    }
    else if (pyvar_loginName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter loginName at index 0");
    if (unicodeloginName)
        bsloginName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeloginName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeloginName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_createlogin_method_cleanup;
    
    b_isAdministrator = ((PyObject_IsTrue(pyvar_isAdministrator) == 1)?VARIANT_TRUE:VARIANT_FALSE);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_createlogin_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->CreateLogin(bsloginName, b_isAdministrator);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.CreateLogin() returned %ld", (long)hr);
        goto idataservermanageradmin_createlogin_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for loginName
    // No teardown for isAdministrator

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_createlogin_method_cleanup;

    idataservermanageradmin_createlogin_method_cleanup:
    self->m_HR = hr;
    if (bsloginName)
        ::SysFreeString(bsloginName);
    
    // No cleanup for isAdministrator
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.CreateLogin");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_ModifyLoginSecurity(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsloginName = 0;
    PyObject* pyvar_loginName;
    PyObject* unicodeloginName = NULL;
    VARIANT_BOOL b_isAdministrator = VARIANT_FALSE;
    PyObject* pyvar_isAdministrator = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OO", &pyvar_loginName, &pyvar_isAdministrator))
      goto idataservermanageradmin_modifyloginsecurity_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_loginName))
        unicodeloginName = PyUnicode_FromObject(pyvar_loginName);
    else if (PyUnicode_Check(pyvar_loginName))
    {
        unicodeloginName = pyvar_loginName;
        Py_INCREF(unicodeloginName);
    }
    else if (pyvar_loginName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter loginName at index 0");
    if (unicodeloginName)
        bsloginName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeloginName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeloginName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_modifyloginsecurity_method_cleanup;
    
    b_isAdministrator = ((PyObject_IsTrue(pyvar_isAdministrator) == 1)?VARIANT_TRUE:VARIANT_FALSE);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_modifyloginsecurity_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->ModifyLoginSecurity(bsloginName, b_isAdministrator);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.ModifyLoginSecurity() returned %ld", (long)hr);
        goto idataservermanageradmin_modifyloginsecurity_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for loginName
    // No teardown for isAdministrator

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_modifyloginsecurity_method_cleanup;

    idataservermanageradmin_modifyloginsecurity_method_cleanup:
    self->m_HR = hr;
    if (bsloginName)
        ::SysFreeString(bsloginName);
    
    // No cleanup for isAdministrator
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.ModifyLoginSecurity");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_ModifyGeodatabaseSecurity(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdbName = 0;
    PyObject* pyvar_dbName;
    PyObject* unicodedbName = NULL;
    BSTR bsloginName = 0;
    PyObject* pyvar_loginName;
    PyObject* unicodeloginName = NULL;
    esriGeodatabasePermissionsType epermission;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OOi", &pyvar_dbName, &pyvar_loginName, (int *)&epermission))
      goto idataservermanageradmin_modifygeodatabasesecurity_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dbName))
        unicodedbName = PyUnicode_FromObject(pyvar_dbName);
    else if (PyUnicode_Check(pyvar_dbName))
    {
        unicodedbName = pyvar_dbName;
        Py_INCREF(unicodedbName);
    }
    else if (pyvar_dbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dbName at index 0");
    if (unicodedbName)
        bsdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_modifygeodatabasesecurity_method_cleanup;
    
    if (PyString_Check(pyvar_loginName))
        unicodeloginName = PyUnicode_FromObject(pyvar_loginName);
    else if (PyUnicode_Check(pyvar_loginName))
    {
        unicodeloginName = pyvar_loginName;
        Py_INCREF(unicodeloginName);
    }
    else if (pyvar_loginName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter loginName at index 1");
    if (unicodeloginName)
        bsloginName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeloginName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeloginName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_modifygeodatabasesecurity_method_cleanup;
    
    // No setup for permission

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->ModifyGeodatabaseSecurity(bsdbName, bsloginName, epermission);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.ModifyGeodatabaseSecurity() returned %ld", (long)hr);
        goto idataservermanageradmin_modifygeodatabasesecurity_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dbName
    // No teardown for loginName
    // No teardown for permission

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_modifygeodatabasesecurity_method_cleanup;

    idataservermanageradmin_modifygeodatabasesecurity_method_cleanup:
    self->m_HR = hr;
    if (bsdbName)
        ::SysFreeString(bsdbName);
    
    if (bsloginName)
        ::SysFreeString(bsloginName);
    
    // No cleanup for permission
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.ModifyGeodatabaseSecurity");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_DeleteLogin(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsloginName = 0;
    PyObject* pyvar_loginName;
    PyObject* unicodeloginName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_loginName))
      goto idataservermanageradmin_deletelogin_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_loginName))
        unicodeloginName = PyUnicode_FromObject(pyvar_loginName);
    else if (PyUnicode_Check(pyvar_loginName))
    {
        unicodeloginName = pyvar_loginName;
        Py_INCREF(unicodeloginName);
    }
    else if (pyvar_loginName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter loginName at index 0");
    if (unicodeloginName)
        bsloginName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeloginName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeloginName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_deletelogin_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->DeleteLogin(bsloginName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.DeleteLogin() returned %ld", (long)hr);
        goto idataservermanageradmin_deletelogin_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for loginName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_deletelogin_method_cleanup;

    idataservermanageradmin_deletelogin_method_cleanup:
    self->m_HR = hr;
    if (bsloginName)
        ::SysFreeString(bsloginName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.DeleteLogin");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_GetGeodatabaseNames(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IEnumBSTR* ipppNames = NULL;
    PyObject* py_ppNames = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppNames

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->GetGeodatabaseNames(&ipppNames);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.GetGeodatabaseNames() returned %ld", (long)hr);
        goto idataservermanageradmin_getgeodatabasenames_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppNames);
    if (ipppNames)
    {
        IUnknown* pUnk = NULL;
        ipppNames->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppNames = IUnknownToPythonIIDObject(pUnk, &IID_IEnumBSTR);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppNames)
    {
        if (py_ppNames)
           Py_DECREF(py_ppNames);
        py_ppNames = Py_None;
        Py_INCREF(py_ppNames);
    }
    if (PyErr_Occurred())
      goto idataservermanageradmin_getgeodatabasenames_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppNames);
    goto idataservermanageradmin_getgeodatabasenames_method_cleanup;

    idataservermanageradmin_getgeodatabasenames_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppNames);
    if (ipppNames)
      ipppNames->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.GetGeodatabaseNames");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_GetLogins(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IEnumBSTR* iploginNames = NULL;
    PyObject* py_loginNames = NULL;
    IEnumBSTR* ipdbNames = NULL;
    PyObject* py_dbNames = NULL;
    IEnumBSTR* iploginTypes = NULL;
    PyObject* py_loginTypes = NULL;
    IEnumBSTR* iplanguages = NULL;
    PyObject* py_languages = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for loginNames
    // No setup for dbNames
    // No setup for loginTypes
    // No setup for languages

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->GetLogins(&iploginNames, &ipdbNames, &iploginTypes, &iplanguages);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.GetLogins() returned %ld", (long)hr);
        goto idataservermanageradmin_getlogins_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_loginNames);
    if (iploginNames)
    {
        IUnknown* pUnk = NULL;
        iploginNames->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_loginNames = IUnknownToPythonIIDObject(pUnk, &IID_IEnumBSTR);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_loginNames)
    {
        if (py_loginNames)
           Py_DECREF(py_loginNames);
        py_loginNames = Py_None;
        Py_INCREF(py_loginNames);
    }
    if (PyErr_Occurred())
      goto idataservermanageradmin_getlogins_method_cleanup;
    
    Py_XDECREF(py_dbNames);
    if (ipdbNames)
    {
        IUnknown* pUnk = NULL;
        ipdbNames->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_dbNames = IUnknownToPythonIIDObject(pUnk, &IID_IEnumBSTR);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_dbNames)
    {
        if (py_dbNames)
           Py_DECREF(py_dbNames);
        py_dbNames = Py_None;
        Py_INCREF(py_dbNames);
    }
    if (PyErr_Occurred())
      goto idataservermanageradmin_getlogins_method_cleanup;
    
    Py_XDECREF(py_loginTypes);
    if (iploginTypes)
    {
        IUnknown* pUnk = NULL;
        iploginTypes->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_loginTypes = IUnknownToPythonIIDObject(pUnk, &IID_IEnumBSTR);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_loginTypes)
    {
        if (py_loginTypes)
           Py_DECREF(py_loginTypes);
        py_loginTypes = Py_None;
        Py_INCREF(py_loginTypes);
    }
    if (PyErr_Occurred())
      goto idataservermanageradmin_getlogins_method_cleanup;
    
    Py_XDECREF(py_languages);
    if (iplanguages)
    {
        IUnknown* pUnk = NULL;
        iplanguages->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_languages = IUnknownToPythonIIDObject(pUnk, &IID_IEnumBSTR);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_languages)
    {
        if (py_languages)
           Py_DECREF(py_languages);
        py_languages = Py_None;
        Py_INCREF(py_languages);
    }
    if (PyErr_Occurred())
      goto idataservermanageradmin_getlogins_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("OOOO",
                                            py_loginNames, py_dbNames, py_loginTypes, py_languages);
    goto idataservermanageradmin_getlogins_method_cleanup;

    idataservermanageradmin_getlogins_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_loginNames);
    if (iploginNames)
      iploginNames->Release();
    Py_XDECREF(py_dbNames);
    if (ipdbNames)
      ipdbNames->Release();
    Py_XDECREF(py_loginTypes);
    if (iploginTypes)
      iploginTypes->Release();
    Py_XDECREF(py_languages);
    if (iplanguages)
      iplanguages->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.GetLogins");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_DetachGeodatabase(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdbName = 0;
    PyObject* pyvar_dbName;
    PyObject* unicodedbName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dbName))
      goto idataservermanageradmin_detachgeodatabase_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dbName))
        unicodedbName = PyUnicode_FromObject(pyvar_dbName);
    else if (PyUnicode_Check(pyvar_dbName))
    {
        unicodedbName = pyvar_dbName;
        Py_INCREF(unicodedbName);
    }
    else if (pyvar_dbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dbName at index 0");
    if (unicodedbName)
        bsdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_detachgeodatabase_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->DetachGeodatabase(bsdbName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.DetachGeodatabase() returned %ld", (long)hr);
        goto idataservermanageradmin_detachgeodatabase_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dbName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_detachgeodatabase_method_cleanup;

    idataservermanageradmin_detachgeodatabase_method_cleanup:
    self->m_HR = hr;
    if (bsdbName)
        ::SysFreeString(bsdbName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.DetachGeodatabase");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_AttachGeodatabase(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdbName = 0;
    PyObject* pyvar_dbName;
    PyObject* unicodedbName = NULL;
    BSTR bsdataFileName = 0;
    PyObject* pyvar_dataFileName;
    PyObject* unicodedataFileName = NULL;
    BSTR bslogFileName = 0;
    PyObject* pyvar_logFileName;
    PyObject* unicodelogFileName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OOO", &pyvar_dbName, &pyvar_dataFileName, &pyvar_logFileName))
      goto idataservermanageradmin_attachgeodatabase_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dbName))
        unicodedbName = PyUnicode_FromObject(pyvar_dbName);
    else if (PyUnicode_Check(pyvar_dbName))
    {
        unicodedbName = pyvar_dbName;
        Py_INCREF(unicodedbName);
    }
    else if (pyvar_dbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dbName at index 0");
    if (unicodedbName)
        bsdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_attachgeodatabase_method_cleanup;
    
    if (PyString_Check(pyvar_dataFileName))
        unicodedataFileName = PyUnicode_FromObject(pyvar_dataFileName);
    else if (PyUnicode_Check(pyvar_dataFileName))
    {
        unicodedataFileName = pyvar_dataFileName;
        Py_INCREF(unicodedataFileName);
    }
    else if (pyvar_dataFileName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dataFileName at index 1");
    if (unicodedataFileName)
        bsdataFileName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedataFileName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedataFileName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_attachgeodatabase_method_cleanup;
    
    if (PyString_Check(pyvar_logFileName))
        unicodelogFileName = PyUnicode_FromObject(pyvar_logFileName);
    else if (PyUnicode_Check(pyvar_logFileName))
    {
        unicodelogFileName = pyvar_logFileName;
        Py_INCREF(unicodelogFileName);
    }
    else if (pyvar_logFileName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter logFileName at index 2");
    if (unicodelogFileName)
        bslogFileName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodelogFileName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodelogFileName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_attachgeodatabase_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->AttachGeodatabase(bsdbName, bsdataFileName, bslogFileName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.AttachGeodatabase() returned %ld", (long)hr);
        goto idataservermanageradmin_attachgeodatabase_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dbName
    // No teardown for dataFileName
    // No teardown for logFileName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_attachgeodatabase_method_cleanup;

    idataservermanageradmin_attachgeodatabase_method_cleanup:
    self->m_HR = hr;
    if (bsdbName)
        ::SysFreeString(bsdbName);
    
    if (bsdataFileName)
        ::SysFreeString(bsdataFileName);
    
    if (bslogFileName)
        ::SysFreeString(bslogFileName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.AttachGeodatabase");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_UpgradeGeoDatabase(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_gdbName))
      goto idataservermanageradmin_upgradegeodatabase_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_upgradegeodatabase_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->UpgradeGeoDatabase(bsgdbName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.UpgradeGeoDatabase() returned %ld", (long)hr);
        goto idataservermanageradmin_upgradegeodatabase_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_upgradegeodatabase_method_cleanup;

    idataservermanageradmin_upgradegeodatabase_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.UpgradeGeoDatabase");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_UpgradeSDESchema(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_gdbName))
      goto idataservermanageradmin_upgradesdeschema_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_upgradesdeschema_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->UpgradeSDESchema(bsgdbName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.UpgradeSDESchema() returned %ld", (long)hr);
        goto idataservermanageradmin_upgradesdeschema_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_upgradesdeschema_method_cleanup;

    idataservermanageradmin_upgradesdeschema_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.UpgradeSDESchema");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_GetGeodatabaseName(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdataFileName = 0;
    PyObject* pyvar_dataFileName;
    PyObject* unicodedataFileName = NULL;
    BSTR bsdbName;
    PyObject* pyvar_dbName = Py_None;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dataFileName))
      goto idataservermanageradmin_getgeodatabasename_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dataFileName))
        unicodedataFileName = PyUnicode_FromObject(pyvar_dataFileName);
    else if (PyUnicode_Check(pyvar_dataFileName))
    {
        unicodedataFileName = pyvar_dataFileName;
        Py_INCREF(unicodedataFileName);
    }
    else if (pyvar_dataFileName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dataFileName at index 0");
    if (unicodedataFileName)
        bsdataFileName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedataFileName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedataFileName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getgeodatabasename_method_cleanup;
    
    // No setup for dbName

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->GetGeodatabaseName(bsdataFileName, &bsdbName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.GetGeodatabaseName() returned %ld", (long)hr);
        goto idataservermanageradmin_getgeodatabasename_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dataFileName
    pyvar_dbName = PyUnicode_FromWideChar(bsdbName,::SysStringLen(bsdbName));
    ::SysFreeString(bsdbName);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getgeodatabasename_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_dbName);
    goto idataservermanageradmin_getgeodatabasename_method_cleanup;

    idataservermanageradmin_getgeodatabasename_method_cleanup:
    self->m_HR = hr;
    if (bsdataFileName)
        ::SysFreeString(bsdataFileName);
    
    if (pyvar_dbName != Py_None)
        Py_XDECREF(pyvar_dbName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.GetGeodatabaseName");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_BackupGeodatabase(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;
    BSTR bsbackupFileName = 0;
    PyObject* pyvar_backupFileName;
    PyObject* unicodebackupFileName = NULL;
    BSTR bsbackupName = 0;
    PyObject* pyvar_backupName;
    PyObject* unicodebackupName = NULL;
    BSTR bsdescription = 0;
    PyObject* pyvar_description;
    PyObject* unicodedescription = NULL;
    VARIANT_BOOL b_IsSimpleRecoveryModel = VARIANT_FALSE;
    PyObject* pyvar_IsSimpleRecoveryModel = Py_False;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OOOO", &pyvar_gdbName, &pyvar_backupFileName, &pyvar_backupName, &pyvar_description))
      goto idataservermanageradmin_backupgeodatabase_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_backupgeodatabase_method_cleanup;
    
    if (PyString_Check(pyvar_backupFileName))
        unicodebackupFileName = PyUnicode_FromObject(pyvar_backupFileName);
    else if (PyUnicode_Check(pyvar_backupFileName))
    {
        unicodebackupFileName = pyvar_backupFileName;
        Py_INCREF(unicodebackupFileName);
    }
    else if (pyvar_backupFileName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter backupFileName at index 1");
    if (unicodebackupFileName)
        bsbackupFileName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodebackupFileName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodebackupFileName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_backupgeodatabase_method_cleanup;
    
    if (PyString_Check(pyvar_backupName))
        unicodebackupName = PyUnicode_FromObject(pyvar_backupName);
    else if (PyUnicode_Check(pyvar_backupName))
    {
        unicodebackupName = pyvar_backupName;
        Py_INCREF(unicodebackupName);
    }
    else if (pyvar_backupName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter backupName at index 2");
    if (unicodebackupName)
        bsbackupName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodebackupName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodebackupName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_backupgeodatabase_method_cleanup;
    
    if (PyString_Check(pyvar_description))
        unicodedescription = PyUnicode_FromObject(pyvar_description);
    else if (PyUnicode_Check(pyvar_description))
    {
        unicodedescription = pyvar_description;
        Py_INCREF(unicodedescription);
    }
    else if (pyvar_description != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter description at index 3");
    if (unicodedescription)
        bsdescription = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedescription), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedescription));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_backupgeodatabase_method_cleanup;
    
    // No setup for IsSimpleRecoveryModel

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->BackupGeodatabase(bsgdbName, bsbackupFileName, bsbackupName, bsdescription, &b_IsSimpleRecoveryModel);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.BackupGeodatabase() returned %ld", (long)hr);
        goto idataservermanageradmin_backupgeodatabase_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName
    // No teardown for backupFileName
    // No teardown for backupName
    // No teardown for description
    pyvar_IsSimpleRecoveryModel = ((b_IsSimpleRecoveryModel == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto idataservermanageradmin_backupgeodatabase_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_IsSimpleRecoveryModel);
    goto idataservermanageradmin_backupgeodatabase_method_cleanup;

    idataservermanageradmin_backupgeodatabase_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (bsbackupFileName)
        ::SysFreeString(bsbackupFileName);
    
    if (bsbackupName)
        ::SysFreeString(bsbackupName);
    
    if (bsdescription)
        ::SysFreeString(bsdescription);
    
    // No cleanup for IsSimpleRecoveryModel
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.BackupGeodatabase");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_RestoreGeodatabase(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;
    BSTR bsbackupFileName = 0;
    PyObject* pyvar_backupFileName;
    PyObject* unicodebackupFileName = NULL;
    BSTR bsdbFilePath = 0;
    PyObject* pyvar_dbFilePath;
    PyObject* unicodedbFilePath = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OOO", &pyvar_gdbName, &pyvar_backupFileName, &pyvar_dbFilePath))
      goto idataservermanageradmin_restoregeodatabase_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_restoregeodatabase_method_cleanup;
    
    if (PyString_Check(pyvar_backupFileName))
        unicodebackupFileName = PyUnicode_FromObject(pyvar_backupFileName);
    else if (PyUnicode_Check(pyvar_backupFileName))
    {
        unicodebackupFileName = pyvar_backupFileName;
        Py_INCREF(unicodebackupFileName);
    }
    else if (pyvar_backupFileName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter backupFileName at index 1");
    if (unicodebackupFileName)
        bsbackupFileName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodebackupFileName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodebackupFileName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_restoregeodatabase_method_cleanup;
    
    if (PyString_Check(pyvar_dbFilePath))
        unicodedbFilePath = PyUnicode_FromObject(pyvar_dbFilePath);
    else if (PyUnicode_Check(pyvar_dbFilePath))
    {
        unicodedbFilePath = pyvar_dbFilePath;
        Py_INCREF(unicodedbFilePath);
    }
    else if (pyvar_dbFilePath != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dbFilePath at index 2");
    if (unicodedbFilePath)
        bsdbFilePath = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedbFilePath), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedbFilePath));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_restoregeodatabase_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->RestoreGeodatabase(bsgdbName, bsbackupFileName, bsdbFilePath);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.RestoreGeodatabase() returned %ld", (long)hr);
        goto idataservermanageradmin_restoregeodatabase_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName
    // No teardown for backupFileName
    // No teardown for dbFilePath

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_restoregeodatabase_method_cleanup;

    idataservermanageradmin_restoregeodatabase_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (bsbackupFileName)
        ::SysFreeString(bsbackupFileName);
    
    if (bsdbFilePath)
        ::SysFreeString(bsdbFilePath);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.RestoreGeodatabase");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_IsSimpleRecoveryModel(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'VARIANT_BOOL', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IDataServerManagerAdmin.IsSimpleRecoveryModel not implemented.");
    return NULL;
}

static PyObject*
IDataServerManagerAdminMethod_SetGeodatabaseToSimpleRecoveryModel(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_gdbName))
      goto idataservermanageradmin_setgeodatabasetosimplerecoverymodel_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_setgeodatabasetosimplerecoverymodel_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->SetGeodatabaseToSimpleRecoveryModel(bsgdbName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.SetGeodatabaseToSimpleRecoveryModel() returned %ld", (long)hr);
        goto idataservermanageradmin_setgeodatabasetosimplerecoverymodel_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_setgeodatabasetosimplerecoverymodel_method_cleanup;

    idataservermanageradmin_setgeodatabasetosimplerecoverymodel_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.SetGeodatabaseToSimpleRecoveryModel");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_get_IsConnectedUserAdministrator(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_isAdministrator = VARIANT_FALSE;
    PyObject* pyvar_isAdministrator = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for isAdministrator

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->get_IsConnectedUserAdministrator(&b_isAdministrator);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.get_IsConnectedUserAdministrator() returned %ld", (long)hr);
        goto idataservermanageradmin_get_isconnecteduseradministrator_method_cleanup;
    }

    // Set up return values as needed
    pyvar_isAdministrator = ((b_isAdministrator == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto idataservermanageradmin_get_isconnecteduseradministrator_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_isAdministrator);
    goto idataservermanageradmin_get_isconnecteduseradministrator_method_cleanup;

    idataservermanageradmin_get_isconnecteduseradministrator_method_cleanup:
    self->m_HR = hr;
    // No cleanup for isAdministrator
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.get_IsConnectedUserAdministrator");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_CreateWorkspaceName(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;
    BSTR bsversionPropName = 0;
    PyObject* pyvar_versionPropName;
    PyObject* unicodeversionPropName = NULL;
    VARIANT vversionSpecifier;
    ::VariantInit(&vversionSpecifier);
    PyObject* pyvar_versionSpecifier = NULL;
    IWorkspaceName* ipworkspaceName = NULL;
    PyObject* py_workspaceName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OOO", &pyvar_gdbName, &pyvar_versionPropName, &pyvar_versionSpecifier))
      goto idataservermanageradmin_createworkspacename_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_createworkspacename_method_cleanup;
    
    if (PyString_Check(pyvar_versionPropName))
        unicodeversionPropName = PyUnicode_FromObject(pyvar_versionPropName);
    else if (PyUnicode_Check(pyvar_versionPropName))
    {
        unicodeversionPropName = pyvar_versionPropName;
        Py_INCREF(unicodeversionPropName);
    }
    else if (pyvar_versionPropName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter versionPropName at index 1");
    if (unicodeversionPropName)
        bsversionPropName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeversionPropName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeversionPropName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_createworkspacename_method_cleanup;
    
    PyObject_AsVariant(pyvar_versionSpecifier, &vversionSpecifier);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_createworkspacename_method_cleanup;
    
    // No setup for workspaceName

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->CreateWorkspaceName(bsgdbName, bsversionPropName, vversionSpecifier, &ipworkspaceName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.CreateWorkspaceName() returned %ld", (long)hr);
        goto idataservermanageradmin_createworkspacename_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName
    // No teardown for versionPropName
    // No teardown for versionSpecifier
    Py_XDECREF(py_workspaceName);
    if (ipworkspaceName)
    {
        IUnknown* pUnk = NULL;
        ipworkspaceName->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_workspaceName = IUnknownToPythonIIDObject(pUnk, &IID_IWorkspaceName);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_workspaceName)
    {
        if (py_workspaceName)
           Py_DECREF(py_workspaceName);
        py_workspaceName = Py_None;
        Py_INCREF(py_workspaceName);
    }
    if (PyErr_Occurred())
      goto idataservermanageradmin_createworkspacename_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_workspaceName);
    goto idataservermanageradmin_createworkspacename_method_cleanup;

    idataservermanageradmin_createworkspacename_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (bsversionPropName)
        ::SysFreeString(bsversionPropName);
    
    ::VariantClear(&vversionSpecifier);
    Py_XDECREF(py_workspaceName);
    if (ipworkspaceName)
      ipworkspaceName->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.CreateWorkspaceName");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_GetDBProperties(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdbName = 0;
    PyObject* pyvar_dbName;
    PyObject* unicodedbName = NULL;
    BSTR bsstatus;
    PyObject* pyvar_status = Py_None;
    long ldbSize = 0;
    BSTR bsowner;
    PyObject* pyvar_owner = Py_None;
    VARIANT vcreateDate;
    ::VariantInit(&vcreateDate);
    PyObject* pyvar_createDate = NULL;
    VARIANT vdbBackup;
    ::VariantInit(&vdbBackup);
    PyObject* pyvar_dbBackup = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dbName))
      goto idataservermanageradmin_getdbproperties_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dbName))
        unicodedbName = PyUnicode_FromObject(pyvar_dbName);
    else if (PyUnicode_Check(pyvar_dbName))
    {
        unicodedbName = pyvar_dbName;
        Py_INCREF(unicodedbName);
    }
    else if (pyvar_dbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dbName at index 0");
    if (unicodedbName)
        bsdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getdbproperties_method_cleanup;
    
    // No setup for status
    // No setup for dbSize
    // No setup for owner
    // No setup for createDate
    // No setup for dbBackup

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->GetDBProperties(bsdbName, &bsstatus, &ldbSize, &bsowner, &vcreateDate, &vdbBackup);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.GetDBProperties() returned %ld", (long)hr);
        goto idataservermanageradmin_getdbproperties_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dbName
    pyvar_status = PyUnicode_FromWideChar(bsstatus,::SysStringLen(bsstatus));
    ::SysFreeString(bsstatus);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getdbproperties_method_cleanup;
    
    // No teardown for dbSize
    pyvar_owner = PyUnicode_FromWideChar(bsowner,::SysStringLen(bsowner));
    ::SysFreeString(bsowner);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getdbproperties_method_cleanup;
    
    pyvar_createDate = Variant_AsPyObject(&vcreateDate);
    if (PyErr_Occurred())
      goto idataservermanageradmin_getdbproperties_method_cleanup;
    
    pyvar_dbBackup = Variant_AsPyObject(&vdbBackup);
    if (PyErr_Occurred())
      goto idataservermanageradmin_getdbproperties_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("OlOOO",
                                            pyvar_status, ldbSize, pyvar_owner, pyvar_createDate, pyvar_dbBackup);
    goto idataservermanageradmin_getdbproperties_method_cleanup;

    idataservermanageradmin_getdbproperties_method_cleanup:
    self->m_HR = hr;
    if (bsdbName)
        ::SysFreeString(bsdbName);
    
    if (pyvar_status != Py_None)
        Py_XDECREF(pyvar_status);
    // No cleanup for dbSize
    if (pyvar_owner != Py_None)
        Py_XDECREF(pyvar_owner);
    ::VariantClear(&vcreateDate);
    Py_XDECREF(pyvar_createDate);
    ::VariantClear(&vdbBackup);
    Py_XDECREF(pyvar_dbBackup);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.GetDBProperties");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_GetFileProperties(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdbName = 0;
    PyObject* pyvar_dbName;
    PyObject* unicodedbName = NULL;
    BSTR bsdataName;
    PyObject* pyvar_dataName = Py_None;
    BSTR bsdataPhysicalName;
    PyObject* pyvar_dataPhysicalName = Py_None;
    long ldataFileSize = 0;
    BSTR bslogName;
    PyObject* pyvar_logName = Py_None;
    BSTR bslogPhysicalName;
    PyObject* pyvar_logPhysicalName = Py_None;
    long llogFileSize = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dbName))
      goto idataservermanageradmin_getfileproperties_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dbName))
        unicodedbName = PyUnicode_FromObject(pyvar_dbName);
    else if (PyUnicode_Check(pyvar_dbName))
    {
        unicodedbName = pyvar_dbName;
        Py_INCREF(unicodedbName);
    }
    else if (pyvar_dbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dbName at index 0");
    if (unicodedbName)
        bsdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getfileproperties_method_cleanup;
    
    // No setup for dataName
    // No setup for dataPhysicalName
    // No setup for dataFileSize
    // No setup for logName
    // No setup for logPhysicalName
    // No setup for logFileSize

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->GetFileProperties(bsdbName, &bsdataName, &bsdataPhysicalName, &ldataFileSize, &bslogName, &bslogPhysicalName, &llogFileSize);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.GetFileProperties() returned %ld", (long)hr);
        goto idataservermanageradmin_getfileproperties_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dbName
    pyvar_dataName = PyUnicode_FromWideChar(bsdataName,::SysStringLen(bsdataName));
    ::SysFreeString(bsdataName);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getfileproperties_method_cleanup;
    
    pyvar_dataPhysicalName = PyUnicode_FromWideChar(bsdataPhysicalName,::SysStringLen(bsdataPhysicalName));
    ::SysFreeString(bsdataPhysicalName);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getfileproperties_method_cleanup;
    
    // No teardown for dataFileSize
    pyvar_logName = PyUnicode_FromWideChar(bslogName,::SysStringLen(bslogName));
    ::SysFreeString(bslogName);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getfileproperties_method_cleanup;
    
    pyvar_logPhysicalName = PyUnicode_FromWideChar(bslogPhysicalName,::SysStringLen(bslogPhysicalName));
    ::SysFreeString(bslogPhysicalName);
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getfileproperties_method_cleanup;
    
    // No teardown for logFileSize

    // Initialize output tuple
    return_tuple = Py_BuildValue("OOlOOl",
                                            pyvar_dataName, pyvar_dataPhysicalName, ldataFileSize, pyvar_logName, pyvar_logPhysicalName, llogFileSize);
    goto idataservermanageradmin_getfileproperties_method_cleanup;

    idataservermanageradmin_getfileproperties_method_cleanup:
    self->m_HR = hr;
    if (bsdbName)
        ::SysFreeString(bsdbName);
    
    if (pyvar_dataName != Py_None)
        Py_XDECREF(pyvar_dataName);
    if (pyvar_dataPhysicalName != Py_None)
        Py_XDECREF(pyvar_dataPhysicalName);
    // No cleanup for dataFileSize
    if (pyvar_logName != Py_None)
        Py_XDECREF(pyvar_logName);
    if (pyvar_logPhysicalName != Py_None)
        Py_XDECREF(pyvar_logPhysicalName);
    // No cleanup for logFileSize
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.GetFileProperties");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_Analyze(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_gdbName))
      goto idataservermanageradmin_analyze_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_analyze_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->Analyze(bsgdbName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.Analyze() returned %ld", (long)hr);
        goto idataservermanageradmin_analyze_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_analyze_method_cleanup;

    idataservermanageradmin_analyze_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.Analyze");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_RebuildIndices(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_gdbName))
      goto idataservermanageradmin_rebuildindices_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_rebuildindices_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->RebuildIndices(bsgdbName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.RebuildIndices() returned %ld", (long)hr);
        goto idataservermanageradmin_rebuildindices_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_rebuildindices_method_cleanup;

    idataservermanageradmin_rebuildindices_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.RebuildIndices");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_ShrinkGeodatabase(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsgdbName = 0;
    PyObject* pyvar_gdbName;
    PyObject* unicodegdbName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_gdbName))
      goto idataservermanageradmin_shrinkgeodatabase_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_gdbName))
        unicodegdbName = PyUnicode_FromObject(pyvar_gdbName);
    else if (PyUnicode_Check(pyvar_gdbName))
    {
        unicodegdbName = pyvar_gdbName;
        Py_INCREF(unicodegdbName);
    }
    else if (pyvar_gdbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter gdbName at index 0");
    if (unicodegdbName)
        bsgdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodegdbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodegdbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_shrinkgeodatabase_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->ShrinkGeodatabase(bsgdbName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.ShrinkGeodatabase() returned %ld", (long)hr);
        goto idataservermanageradmin_shrinkgeodatabase_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for gdbName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataservermanageradmin_shrinkgeodatabase_method_cleanup;

    idataservermanageradmin_shrinkgeodatabase_method_cleanup:
    self->m_HR = hr;
    if (bsgdbName)
        ::SysFreeString(bsgdbName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.ShrinkGeodatabase");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_GetConnectedUsers(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdbName = 0;
    PyObject* pyvar_dbName;
    PyObject* unicodedbName = NULL;
    long lnUsers = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dbName))
      goto idataservermanageradmin_getconnectedusers_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dbName))
        unicodedbName = PyUnicode_FromObject(pyvar_dbName);
    else if (PyUnicode_Check(pyvar_dbName))
    {
        unicodedbName = pyvar_dbName;
        Py_INCREF(unicodedbName);
    }
    else if (pyvar_dbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dbName at index 0");
    if (unicodedbName)
        bsdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getconnectedusers_method_cleanup;
    
    // No setup for nUsers

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->GetConnectedUsers(bsdbName, &lnUsers);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.GetConnectedUsers() returned %ld", (long)hr);
        goto idataservermanageradmin_getconnectedusers_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dbName
    // No teardown for nUsers

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lnUsers);
    goto idataservermanageradmin_getconnectedusers_method_cleanup;

    idataservermanageradmin_getconnectedusers_method_cleanup:
    self->m_HR = hr;
    if (bsdbName)
        ::SysFreeString(bsdbName);
    
    // No cleanup for nUsers
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.GetConnectedUsers");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_GetServerAdministrators(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IEnumBSTR* ipuserNames = NULL;
    PyObject* py_userNames = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for userNames

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->GetServerAdministrators(&ipuserNames);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.GetServerAdministrators() returned %ld", (long)hr);
        goto idataservermanageradmin_getserveradministrators_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_userNames);
    if (ipuserNames)
    {
        IUnknown* pUnk = NULL;
        ipuserNames->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_userNames = IUnknownToPythonIIDObject(pUnk, &IID_IEnumBSTR);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_userNames)
    {
        if (py_userNames)
           Py_DECREF(py_userNames);
        py_userNames = Py_None;
        Py_INCREF(py_userNames);
    }
    if (PyErr_Occurred())
      goto idataservermanageradmin_getserveradministrators_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_userNames);
    goto idataservermanageradmin_getserveradministrators_method_cleanup;

    idataservermanageradmin_getserveradministrators_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_userNames);
    if (ipuserNames)
      ipuserNames->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.GetServerAdministrators");
    return return_tuple;
}

static PyObject*
IDataServerManagerAdminMethod_GetUsersByPermissionType(PyIDataServerManagerAdminObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdbName = 0;
    PyObject* pyvar_dbName;
    PyObject* unicodedbName = NULL;
    esriGeodatabasePermissionsType epermission;
    IEnumBSTR* ipuserNames = NULL;
    PyObject* py_userNames = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "Oi", &pyvar_dbName, (int *)&epermission))
      goto idataservermanageradmin_getusersbypermissiontype_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dbName))
        unicodedbName = PyUnicode_FromObject(pyvar_dbName);
    else if (PyUnicode_Check(pyvar_dbName))
    {
        unicodedbName = pyvar_dbName;
        Py_INCREF(unicodedbName);
    }
    else if (pyvar_dbName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dbName at index 0");
    if (unicodedbName)
        bsdbName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedbName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedbName));
    
    if (PyErr_Occurred())
      goto idataservermanageradmin_getusersbypermissiontype_method_cleanup;
    
    // No setup for permission
    // No setup for userNames

    // Call method on actual COM interface
    hr = self->m_pIDataServerManagerAdmin->GetUsersByPermissionType(bsdbName, epermission, &ipuserNames);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataServerManagerAdmin->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataServerManagerAdmin) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataServerManagerAdmin.GetUsersByPermissionType() returned %ld", (long)hr);
        goto idataservermanageradmin_getusersbypermissiontype_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dbName
    // No teardown for permission
    Py_XDECREF(py_userNames);
    if (ipuserNames)
    {
        IUnknown* pUnk = NULL;
        ipuserNames->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_userNames = IUnknownToPythonIIDObject(pUnk, &IID_IEnumBSTR);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_userNames)
    {
        if (py_userNames)
           Py_DECREF(py_userNames);
        py_userNames = Py_None;
        Py_INCREF(py_userNames);
    }
    if (PyErr_Occurred())
      goto idataservermanageradmin_getusersbypermissiontype_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_userNames);
    goto idataservermanageradmin_getusersbypermissiontype_method_cleanup;

    idataservermanageradmin_getusersbypermissiontype_method_cleanup:
    self->m_HR = hr;
    if (bsdbName)
        ::SysFreeString(bsdbName);
    
    // No cleanup for permission
    Py_XDECREF(py_userNames);
    if (ipuserNames)
      ipuserNames->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataServerManagerAdmin.GetUsersByPermissionType");
    return return_tuple;
}


PyMethodDef PyIDataServerManagerAdminMethods[] = {
    {"supports", (PyCFunction)PyIDataServerManagerAdmin_SupportsInterface, METH_O, ""},
    {"CreateGeodatabase", (PyCFunction)IDataServerManagerAdminMethod_CreateGeodatabase, METH_VARARGS, ""},
    {"DeleteGeodatabase", (PyCFunction)IDataServerManagerAdminMethod_DeleteGeodatabase, METH_VARARGS, ""},
    {"CreateLogin", (PyCFunction)IDataServerManagerAdminMethod_CreateLogin, METH_VARARGS, ""},
    {"ModifyLoginSecurity", (PyCFunction)IDataServerManagerAdminMethod_ModifyLoginSecurity, METH_VARARGS, ""},
    {"ModifyGeodatabaseSecurity", (PyCFunction)IDataServerManagerAdminMethod_ModifyGeodatabaseSecurity, METH_VARARGS, ""},
    {"DeleteLogin", (PyCFunction)IDataServerManagerAdminMethod_DeleteLogin, METH_VARARGS, ""},
    {"GetGeodatabaseNames", (PyCFunction)IDataServerManagerAdminMethod_GetGeodatabaseNames, METH_VARARGS, ""},
    {"GetLogins", (PyCFunction)IDataServerManagerAdminMethod_GetLogins, METH_VARARGS, ""},
    {"DetachGeodatabase", (PyCFunction)IDataServerManagerAdminMethod_DetachGeodatabase, METH_VARARGS, ""},
    {"AttachGeodatabase", (PyCFunction)IDataServerManagerAdminMethod_AttachGeodatabase, METH_VARARGS, ""},
    {"UpgradeGeoDatabase", (PyCFunction)IDataServerManagerAdminMethod_UpgradeGeoDatabase, METH_VARARGS, ""},
    {"UpgradeSDESchema", (PyCFunction)IDataServerManagerAdminMethod_UpgradeSDESchema, METH_VARARGS, ""},
    {"GetGeodatabaseName", (PyCFunction)IDataServerManagerAdminMethod_GetGeodatabaseName, METH_VARARGS, ""},
    {"BackupGeodatabase", (PyCFunction)IDataServerManagerAdminMethod_BackupGeodatabase, METH_VARARGS, ""},
    {"RestoreGeodatabase", (PyCFunction)IDataServerManagerAdminMethod_RestoreGeodatabase, METH_VARARGS, ""},
    {"IsSimpleRecoveryModel", (PyCFunction)IDataServerManagerAdminMethod_IsSimpleRecoveryModel, METH_VARARGS, ""},
    {"SetGeodatabaseToSimpleRecoveryModel", (PyCFunction)IDataServerManagerAdminMethod_SetGeodatabaseToSimpleRecoveryModel, METH_VARARGS, ""},
    {"get_IsConnectedUserAdministrator", (PyCFunction)IDataServerManagerAdminMethod_get_IsConnectedUserAdministrator, METH_VARARGS, ""},
    {"CreateWorkspaceName", (PyCFunction)IDataServerManagerAdminMethod_CreateWorkspaceName, METH_VARARGS, ""},
    {"GetDBProperties", (PyCFunction)IDataServerManagerAdminMethod_GetDBProperties, METH_VARARGS, ""},
    {"GetFileProperties", (PyCFunction)IDataServerManagerAdminMethod_GetFileProperties, METH_VARARGS, ""},
    {"Analyze", (PyCFunction)IDataServerManagerAdminMethod_Analyze, METH_VARARGS, ""},
    {"RebuildIndices", (PyCFunction)IDataServerManagerAdminMethod_RebuildIndices, METH_VARARGS, ""},
    {"ShrinkGeodatabase", (PyCFunction)IDataServerManagerAdminMethod_ShrinkGeodatabase, METH_VARARGS, ""},
    {"GetConnectedUsers", (PyCFunction)IDataServerManagerAdminMethod_GetConnectedUsers, METH_VARARGS, ""},
    {"GetServerAdministrators", (PyCFunction)IDataServerManagerAdminMethod_GetServerAdministrators, METH_VARARGS, ""},
    {"GetUsersByPermissionType", (PyCFunction)IDataServerManagerAdminMethod_GetUsersByPermissionType, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIDataServerManagerAdminGetSet[] = {
  {"_pUnk", (getter)PyIDataServerManagerAdmin_GetpUnk, NULL, "Get opaque pointer to an Unknown from IDataServerManagerAdmin", NULL},
  {"_pointer", (getter)PyIDataServerManagerAdmin_GetPointer, NULL, "Get memory address for IDataServerManagerAdmin", NULL},
  {"_IID", (getter)PyIDataServerManagerAdmin_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIDataServerManagerAdmin_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIDataServerManagerAdmin_GetIgnoreFailures, (setter)PyIDataServerManagerAdmin_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIDataServerManagerAdminObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesGDB.IDataServerManagerAdminObject",                          
                                              /* tp_name */
  sizeof(PyIDataServerManagerAdminObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIDataServerManagerAdminObject_dealloc,      
                                              /* tp_dealloc */
  0,                                          /* tp_print */
  0,                                          /* tp_getattr */
  0,                                          /* tp_setattr */
  0,                                          /* tp_compare */
  0,                                          /* tp_repr */
  0,                                          /* tp_as_number */
  0,                                          /* tp_as_sequence */
  0,                                          /* tp_as_mapping */
  0,                                          /* tp_hash  */
  0,                                          /* tp_call */
  0,                                          /* tp_str */
  0,                                          /* tp_getattro */
  0,                                          /* tp_setattro */
  0,                                          /* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
  "",                                  
                                              /* tp_doc */
  0,                                          /* tp_traverse */
  0,                                          /* tp_clear */
  0,                                          /* tp_richcompare */
  0,                                          /* tp_weaklistoffset */
  0,                                          /* tp_iter */
  0,                                          /* tp_iternext */
  PyIDataServerManagerAdminMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIDataServerManagerAdminGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIDataServerManagerAdminObject_new,                      
                                              /* tp_new */
};

// Interface IServiceControl

typedef struct PyIServiceControlObject {
    PyObject_HEAD
    IServiceControl* m_pIServiceControl;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIServiceControlObject;

static PyObject*
PyIServiceControlObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIServiceControlObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IServiceControl* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IServiceControl, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IServiceControl with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIServiceControlObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IServiceControl");
            return NULL;
        }
        self->m_pIServiceControl = pIFace;
        self->m_HR = hr;
        self->m_ignore_failures = 0;
        return (PyObject *)self;
    }
    // Are we passed an opaque pointer?
    else if (PyCObject_Check(argument))
    {
        pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
    }
    // No? See if there's an object._pUnk attribute that is one!
    else
    {
        argument = PyObject_GetAttrString(argument, "_pUnk");
        if (!argument)
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IServiceControl");
            Py_XDECREF(argument);
            return NULL;
        }
        else if (PyCObject_Check(argument))
        {
            pUnk = (IUnknown *)PyCObject_AsVoidPtr(argument);
        }
        else
        {
            PyErr_Clear();
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IServiceControl");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IServiceControl* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IServiceControl, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IServiceControl");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIServiceControlObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IServiceControl");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIServiceControl = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIServiceControlObject_dealloc(PyIServiceControlObject* self)
{
    if (self->m_pIServiceControl)
        self->m_pIServiceControl->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIServiceControl_GetpUnk(PyIServiceControlObject* self)
{
    if (!self->m_pIServiceControl)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIServiceControl->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IServiceControl to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIServiceControl_GetPointer(PyIServiceControlObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIServiceControl);
}

static PyObject*
PyIServiceControl_GetIID(PyIServiceControlObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "271445cb-af1b-483a-a91e-337fa7bf2c0c");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIServiceControl_GetHR(PyIServiceControlObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIServiceControl_GetIgnoreFailures(PyIServiceControlObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIServiceControl_SetIgnoreFailures(PyIServiceControlObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIServiceControl_SupportsInterface(PyIServiceControlObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIServiceControl->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
        {
            ipUnk->Release();
            Py_RETURN_TRUE;
        }
        Py_RETURN_FALSE;
    }
    PyErr_SetString(PyExc_ValueError, "Bad interface ID.");
    return NULL;
}


static PyObject*
IServiceControlMethod_get_ServerStatus(PyIServiceControlObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriDataServerStatusType estatus;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for status

    // Call method on actual COM interface
    hr = self->m_pIServiceControl->get_ServerStatus(&estatus);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIServiceControl->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IServiceControl) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IServiceControl.get_ServerStatus() returned %ld", (long)hr);
        goto iservicecontrol_get_serverstatus_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for status

    // Initialize output tuple
    return_tuple = Py_BuildValue("i",
                                            (int)estatus);
    goto iservicecontrol_get_serverstatus_method_cleanup;

    iservicecontrol_get_serverstatus_method_cleanup:
    self->m_HR = hr;
    // No cleanup for status
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IServiceControl.get_ServerStatus");
    return return_tuple;
}

static PyObject*
IServiceControlMethod_get_HasControlPermissions(PyIServiceControlObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_hasPermissions = VARIANT_FALSE;
    PyObject* pyvar_hasPermissions = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for hasPermissions

    // Call method on actual COM interface
    hr = self->m_pIServiceControl->get_HasControlPermissions(&b_hasPermissions);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIServiceControl->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IServiceControl) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IServiceControl.get_HasControlPermissions() returned %ld", (long)hr);
        goto iservicecontrol_get_hascontrolpermissions_method_cleanup;
    }

    // Set up return values as needed
    pyvar_hasPermissions = ((b_hasPermissions == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto iservicecontrol_get_hascontrolpermissions_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_hasPermissions);
    goto iservicecontrol_get_hascontrolpermissions_method_cleanup;

    iservicecontrol_get_hascontrolpermissions_method_cleanup:
    self->m_HR = hr;
    // No cleanup for hasPermissions
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IServiceControl.get_HasControlPermissions");
    return return_tuple;
}

static PyObject*
IServiceControlMethod_StopServer(PyIServiceControlObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIServiceControl->StopServer();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIServiceControl->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IServiceControl) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IServiceControl.StopServer() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IServiceControlMethod_StartServer(PyIServiceControlObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIServiceControl->StartServer();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIServiceControl->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IServiceControl) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IServiceControl.StartServer() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IServiceControlMethod_PauseServer(PyIServiceControlObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIServiceControl->PauseServer();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIServiceControl->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IServiceControl) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IServiceControl.PauseServer() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IServiceControlMethod_ContinueServer(PyIServiceControlObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIServiceControl->ContinueServer();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIServiceControl->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IServiceControl) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IServiceControl.ContinueServer() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}


PyMethodDef PyIServiceControlMethods[] = {
    {"supports", (PyCFunction)PyIServiceControl_SupportsInterface, METH_O, ""},
    {"get_ServerStatus", (PyCFunction)IServiceControlMethod_get_ServerStatus, METH_VARARGS, ""},
    {"get_HasControlPermissions", (PyCFunction)IServiceControlMethod_get_HasControlPermissions, METH_VARARGS, ""},
    {"StopServer", (PyCFunction)IServiceControlMethod_StopServer, METH_NOARGS, ""},
    {"StartServer", (PyCFunction)IServiceControlMethod_StartServer, METH_NOARGS, ""},
    {"PauseServer", (PyCFunction)IServiceControlMethod_PauseServer, METH_NOARGS, ""},
    {"ContinueServer", (PyCFunction)IServiceControlMethod_ContinueServer, METH_NOARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIServiceControlGetSet[] = {
  {"_pUnk", (getter)PyIServiceControl_GetpUnk, NULL, "Get opaque pointer to an Unknown from IServiceControl", NULL},
  {"_pointer", (getter)PyIServiceControl_GetPointer, NULL, "Get memory address for IServiceControl", NULL},
  {"_IID", (getter)PyIServiceControl_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIServiceControl_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIServiceControl_GetIgnoreFailures, (setter)PyIServiceControl_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIServiceControlObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesGDB.IServiceControlObject",                          
                                              /* tp_name */
  sizeof(PyIServiceControlObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIServiceControlObject_dealloc,      
                                              /* tp_dealloc */
  0,                                          /* tp_print */
  0,                                          /* tp_getattr */
  0,                                          /* tp_setattr */
  0,                                          /* tp_compare */
  0,                                          /* tp_repr */
  0,                                          /* tp_as_number */
  0,                                          /* tp_as_sequence */
  0,                                          /* tp_as_mapping */
  0,                                          /* tp_hash  */
  0,                                          /* tp_call */
  0,                                          /* tp_str */
  0,                                          /* tp_getattro */
  0,                                          /* tp_setattro */
  0,                                          /* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
  "",                                  
                                              /* tp_doc */
  0,                                          /* tp_traverse */
  0,                                          /* tp_clear */
  0,                                          /* tp_richcompare */
  0,                                          /* tp_weaklistoffset */
  0,                                          /* tp_iter */
  0,                                          /* tp_iternext */
  PyIServiceControlMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIServiceControlGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIServiceControlObject_new,                      
                                              /* tp_new */
};





static PyObject*
CoCreateAccessWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_AccessWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of AccessWorkspaceFactory");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("dd48c96a-d92a-11d1-aa81-00c04fa33a15")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "dd48c96a-d92a-11d1-aa81-00c04fa33a15");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateScratchWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_ScratchWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of ScratchWorkspaceFactory");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("06dc8e4c-951c-11d2-ae75-080009ec732a")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "06dc8e4c-951c-11d2-ae75-080009ec732a");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateSdeWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_SdeWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of SdeWorkspaceFactory");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("d9b4fa40-d6d9-11d1-aa81-00c04fa33a15")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "d9b4fa40-d6d9-11d1-aa81-00c04fa33a15");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateSde4Workspace(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_Sde4Workspace, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of Sde4Workspace");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("977c9b25-9b31-11d0-9ce2-0080c79f698f")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "977c9b25-9b31-11d0-9ce2-0080c79f698f");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateSde3Workspace(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_Sde3Workspace, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of Sde3Workspace");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("156ebb05-1488-11d3-9f40-00c04f6bddd9")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "156ebb05-1488-11d3-9f40-00c04f6bddd9");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateFgdbTableName(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_FgdbTableName, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of FgdbTableName");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("846c88c5-6cc5-49c7-a6fe-8fa03d79bd07")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "846c88c5-6cc5-49c7-a6fe-8fa03d79bd07");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateFgdbFeatureClassName(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_FgdbFeatureClassName, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of FgdbFeatureClassName");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("75e10086-4226-42ac-afec-cbb9b748f847")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "75e10086-4226-42ac-afec-cbb9b748f847");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateFileGDBWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_FileGDBWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of FileGDBWorkspaceFactory");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("71fe75f0-ea0c-4406-873e-b7d53748ae7e")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "71fe75f0-ea0c-4406-873e-b7d53748ae7e");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateFileGDBScratchWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_FileGDBScratchWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of FileGDBScratchWorkspaceFactory");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("d9652a31-6b85-480d-8637-91a7dba2fe28")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "d9652a31-6b85-480d-8637-91a7dba2fe28");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateDataServerManager(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_DataServerManager, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of DataServerManager");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("2db75dea-bded-482d-80d9-331e92449627")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "2db75dea-bded-482d-80d9-331e92449627");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateInMemoryWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_InMemoryWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of InMemoryWorkspaceFactory");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("7f2bc55c-b902-43d0-a566-aa47ea9fda2c")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "7f2bc55c-b902-43d0-a566-aa47ea9fda2c");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateSqlWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_SqlWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of SqlWorkspaceFactory");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("5297187b-fd2b-4a5f-8991-eb3f6f1ca502")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "5297187b-fd2b-4a5f-8991-eb3f6f1ca502");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyObject*
CoCreateSqlWorkspace(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_SqlWorkspace, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of SqlWorkspace");
        return NULL;
    }

    PyObject* retval = PyCObject_FromVoidPtr((void*)pUnk, destr_unknown);

    if (g_pUnk_type)
    {
        // new_retval = IUnknown(pointer_to_unknown)
        PyObject* new_retval = PyObject_CallFunction(g_pUnk_type, "O", retval);
        PyObject* clsid_key_lookup = NULL;
        PyObject* pIID = NULL;
        if (g_pUUID_type)
        {
            // Look up clsid in CLSID map
            // clsid_key_lookup = uuid.UUID("1c062199-9253-4463-8e7a-e956f2998d65")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "1c062199-9253-4463-8e7a-e956f2998d65");
            // If the key is there we can fetch the default interface
            // if clsid_key_lookup in _CLSID_Map:
            if (g_pCLSIDMap && 
                g_pIIDMap &&
                clsid_key_lookup &&
                (PyDict_Contains(g_pCLSIDMap, clsid_key_lookup) == 1))
            {
                // pIID = _CLSID_Map[clsid]
                pIID = PyDict_GetItem(g_pCLSIDMap, clsid_key_lookup);

                // pCall = _IID_Map[pIID]
                PyObject* pCall = NULL;
                if (PyDict_Contains(g_pIIDMap, pIID) == 1)
                    pCall = PyDict_GetItem(g_pIIDMap, pIID);

                // new_item = pCall(new_retval)
                PyObject* new_item = NULL;
                if (pCall)
                    new_item = PyObject_CallFunction(pCall, "O", new_retval);

                if (new_item)
                {
                    // Replace with new object
                    Py_DECREF(new_retval);
                    new_retval = new_item;
                }
            }
            PyErr_Clear();
        }
        Py_XDECREF(clsid_key_lookup);
        Py_XDECREF(pIID);
        Py_DECREF(retval);
        return new_retval;
    }

    return retval;
}



static PyMethodDef _esriDataSourcesGDBMethods[] = {
    {"AccessWorkspaceFactory", (PyCFunction)CoCreateAccessWorkspaceFactory, METH_NOARGS,
     "Create instance of AccessWorkspaceFactory\n"},
    {"ScratchWorkspaceFactory", (PyCFunction)CoCreateScratchWorkspaceFactory, METH_NOARGS,
     "Create instance of ScratchWorkspaceFactory\n"},
    {"SdeWorkspaceFactory", (PyCFunction)CoCreateSdeWorkspaceFactory, METH_NOARGS,
     "Create instance of SdeWorkspaceFactory\n"},
    {"Sde4Workspace", (PyCFunction)CoCreateSde4Workspace, METH_NOARGS,
     "Create instance of Sde4Workspace\n"},
    {"Sde3Workspace", (PyCFunction)CoCreateSde3Workspace, METH_NOARGS,
     "Create instance of Sde3Workspace\n"},
    {"FgdbTableName", (PyCFunction)CoCreateFgdbTableName, METH_NOARGS,
     "Create instance of FgdbTableName\n"},
    {"FgdbFeatureClassName", (PyCFunction)CoCreateFgdbFeatureClassName, METH_NOARGS,
     "Create instance of FgdbFeatureClassName\n"},
    {"FileGDBWorkspaceFactory", (PyCFunction)CoCreateFileGDBWorkspaceFactory, METH_NOARGS,
     "Create instance of FileGDBWorkspaceFactory\n"},
    {"FileGDBScratchWorkspaceFactory", (PyCFunction)CoCreateFileGDBScratchWorkspaceFactory, METH_NOARGS,
     "Create instance of FileGDBScratchWorkspaceFactory\n"},
    {"DataServerManager", (PyCFunction)CoCreateDataServerManager, METH_NOARGS,
     "Create instance of DataServerManager\n"},
    {"InMemoryWorkspaceFactory", (PyCFunction)CoCreateInMemoryWorkspaceFactory, METH_NOARGS,
     "Create instance of InMemoryWorkspaceFactory\n"},
    {"SqlWorkspaceFactory", (PyCFunction)CoCreateSqlWorkspaceFactory, METH_NOARGS,
     "Create instance of SqlWorkspaceFactory\n"},
    {"SqlWorkspace", (PyCFunction)CoCreateSqlWorkspace, METH_NOARGS,
     "Create instance of SqlWorkspace\n"},
    {NULL, NULL, 0, NULL}
};

extern "C" {

    PyMODINIT_FUNC
    init_esriDataSourcesGDB(void)
    {
        // Import UUID module and keep a global pointer to the UUID object
        PyObject* uuid_module = PyImport_ImportModuleNoBlock("uuid");
        if (!uuid_module)
        {
            PyErr_SetString(PyExc_ImportError, "Could not import UUID module");
            return;
        }
        if (g_pUUID_type)
            Py_DECREF(g_pUUID_type);
        g_pUUID_type = PyObject_GetAttrString(uuid_module, "UUID");

        // Initialize module, make it show up in the right place
        PyObject* module;
        module = Py_InitModule3("cartocomutils._esriDataSourcesGDB",
                                 _esriDataSourcesGDBMethods,
                                "Type library");
        Py_INCREF(module);

        // Add IUnknown base type to parent module so every typelib is using the same
        // Py_Type pointer when typechecking.
        PyObject* parent = PyImport_ImportModuleNoBlock("cartocomutils");
        if (parent)
        {
            if (!PyObject_HasAttrString(parent, "IUnknown"))
            {
                // Bootstrapping
                PyType_Ready(&IUnknownObject_Type);
                PyModule_AddObject(parent, "IUnknown", (PyObject*)(&IUnknownObject_Type));
                // Also probably means we need to coinitialize
                ::CoInitialize(NULL);
            }
            g_pUnk_type = PyObject_GetAttrString(parent, "IUnknown");
            if (!PyObject_HasAttrString(parent, "_IIDMap"))
                PyModule_AddObject(parent, "_IIDMap", PyDict_New());
            if (!PyObject_HasAttrString(parent, "_CLSIDMap"))
                PyModule_AddObject(parent, "_CLSIDMap", PyDict_New());
            g_pIIDMap = PyObject_GetAttrString(parent, "_IIDMap");
            Py_XINCREF(g_pIIDMap);
            // Set global unknown object
            if (g_pUnk_type && g_pIIDMap)
                PyDict_SetItem(g_pIIDMap, PyObject_CallFunction(g_pUUID_type, "s", "{00000000-0000-0000-C000-000000000046}"), g_pUnk_type);
            g_pCLSIDMap = PyObject_GetAttrString(parent, "_CLSIDMap");
            Py_XINCREF(g_pCLSIDMap);
            g_pRecordMap = PyObject_GetAttrString(parent, "_RecordMap");
            Py_XINCREF(g_pRecordMap);
            PyErr_Clear();
        }

        // Bulk add all interfaces as objects
        // IDatabaseLockInfo
        PyType_Ready(&PyIDatabaseLockInfoObject_Type);
        Py_INCREF((PyObject* )&PyIDatabaseLockInfoObject_Type);
        PyModule_AddObject(module, "IDatabaseLockInfo", 
                           (PyObject *)&PyIDatabaseLockInfoObject_Type);

        // IEnumDatabaseLockInfo
        PyType_Ready(&PyIEnumDatabaseLockInfoObject_Type);
        Py_INCREF((PyObject* )&PyIEnumDatabaseLockInfoObject_Type);
        PyModule_AddObject(module, "IEnumDatabaseLockInfo", 
                           (PyObject *)&PyIEnumDatabaseLockInfoObject_Type);

        // IDatabaseLocksInfo
        PyType_Ready(&PyIDatabaseLocksInfoObject_Type);
        Py_INCREF((PyObject* )&PyIDatabaseLocksInfoObject_Type);
        PyModule_AddObject(module, "IDatabaseLocksInfo", 
                           (PyObject *)&PyIDatabaseLocksInfoObject_Type);

        // IFileGDBLockWaiting
        PyType_Ready(&PyIFileGDBLockWaitingObject_Type);
        Py_INCREF((PyObject* )&PyIFileGDBLockWaitingObject_Type);
        PyModule_AddObject(module, "IFileGDBLockWaiting", 
                           (PyObject *)&PyIFileGDBLockWaitingObject_Type);

        // IDataServerManager
        PyType_Ready(&PyIDataServerManagerObject_Type);
        Py_INCREF((PyObject* )&PyIDataServerManagerObject_Type);
        PyModule_AddObject(module, "IDataServerManager", 
                           (PyObject *)&PyIDataServerManagerObject_Type);

        // IDataServerManagerAdmin
        PyType_Ready(&PyIDataServerManagerAdminObject_Type);
        Py_INCREF((PyObject* )&PyIDataServerManagerAdminObject_Type);
        PyModule_AddObject(module, "IDataServerManagerAdmin", 
                           (PyObject *)&PyIDataServerManagerAdminObject_Type);

        // IServiceControl
        PyType_Ready(&PyIServiceControlObject_Type);
        Py_INCREF((PyObject* )&PyIServiceControlObject_Type);
        PyModule_AddObject(module, "IServiceControl", 
                           (PyObject *)&PyIServiceControlObject_Type);


        // Bulk add all the IID_* CLSID_* from this type lib
        if (g_pUUID_type)
        {
            // guids registration for interfaces
            if (g_pIIDMap)
            {
// Disabled for now, done in the .py file
            }

            // clsids registration for known coclasses
            if (g_pCLSIDMap)
            {
// Disabled for now, done in the .py file
            }
        }
        Py_XDECREF(g_pIIDMap);
        Py_XDECREF(g_pCLSIDMap);
    }

}
