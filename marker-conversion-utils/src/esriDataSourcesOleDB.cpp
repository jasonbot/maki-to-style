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




// Interface IFDOToADOConnection

typedef struct PyIFDOToADOConnectionObject {
    PyObject_HEAD
    IFDOToADOConnection* m_pIFDOToADOConnection;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIFDOToADOConnectionObject;

static PyObject*
PyIFDOToADOConnectionObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIFDOToADOConnectionObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IFDOToADOConnection* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IFDOToADOConnection, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IFDOToADOConnection with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIFDOToADOConnectionObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IFDOToADOConnection");
            return NULL;
        }
        self->m_pIFDOToADOConnection = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IFDOToADOConnection");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IFDOToADOConnection");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IFDOToADOConnection* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IFDOToADOConnection, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IFDOToADOConnection");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIFDOToADOConnectionObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IFDOToADOConnection");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIFDOToADOConnection = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIFDOToADOConnectionObject_dealloc(PyIFDOToADOConnectionObject* self)
{
    if (self->m_pIFDOToADOConnection)
        self->m_pIFDOToADOConnection->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIFDOToADOConnection_GetpUnk(PyIFDOToADOConnectionObject* self)
{
    if (!self->m_pIFDOToADOConnection)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIFDOToADOConnection->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IFDOToADOConnection to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIFDOToADOConnection_GetPointer(PyIFDOToADOConnectionObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIFDOToADOConnection);
}

static PyObject*
PyIFDOToADOConnection_GetIID(PyIFDOToADOConnectionObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "7461df2c-6389-11d2-aaaf-00c04fa37849");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIFDOToADOConnection_GetHR(PyIFDOToADOConnectionObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIFDOToADOConnection_GetIgnoreFailures(PyIFDOToADOConnectionObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIFDOToADOConnection_SetIgnoreFailures(PyIFDOToADOConnectionObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIFDOToADOConnection_SupportsInterface(PyIFDOToADOConnectionObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIFDOToADOConnection->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IFDOToADOConnectionMethod_Connect(PyIFDOToADOConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IWorkspace* ippWorkspace = NULL;
    PyObject* py_pWorkspace;
    IUnknown* ippADOConnection = NULL;
    PyObject* py_pADOConnection;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OO", &py_pWorkspace, &py_pADOConnection))
      goto ifdotoadoconnection_connect_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_pWorkspace, &IID_IWorkspace, (void**)&ippWorkspace))
        PyErr_SetString(PyExc_TypeError, "Argument pWorkspace (position 0) is not IWorkspace");
    
    if (PyErr_Occurred())
      goto ifdotoadoconnection_connect_method_cleanup;
    
    if (!IFaceFromPyObject(py_pADOConnection, &IID_IUnknown, (void**)&ippADOConnection))
        PyErr_SetString(PyExc_TypeError, "Argument pADOConnection (position 1) is not IUnknown");
    
    if (PyErr_Occurred())
      goto ifdotoadoconnection_connect_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIFDOToADOConnection->Connect(ippWorkspace, ippADOConnection);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIFDOToADOConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IFDOToADOConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IFDOToADOConnection.Connect() returned %ld", (long)hr);
        goto ifdotoadoconnection_connect_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pWorkspace
    // No teardown for pADOConnection

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto ifdotoadoconnection_connect_method_cleanup;

    ifdotoadoconnection_connect_method_cleanup:
    self->m_HR = hr;
    if (ippWorkspace)
      ippWorkspace->Release();
    if (ippADOConnection)
      ippADOConnection->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IFDOToADOConnection.Connect");
    return return_tuple;
}

static PyObject*
IFDOToADOConnectionMethod_CreateADOConnection(PyIFDOToADOConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IWorkspace* ippWorkspace = NULL;
    PyObject* py_pWorkspace;
    IUnknown* ippADOConnection = NULL;
    PyObject* py_pADOConnection = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_pWorkspace))
      goto ifdotoadoconnection_createadoconnection_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_pWorkspace, &IID_IWorkspace, (void**)&ippWorkspace))
        PyErr_SetString(PyExc_TypeError, "Argument pWorkspace (position 0) is not IWorkspace");
    
    if (PyErr_Occurred())
      goto ifdotoadoconnection_createadoconnection_method_cleanup;
    
    // No setup for pADOConnection

    // Call method on actual COM interface
    hr = self->m_pIFDOToADOConnection->CreateADOConnection(ippWorkspace, &ippADOConnection);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIFDOToADOConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IFDOToADOConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IFDOToADOConnection.CreateADOConnection() returned %ld", (long)hr);
        goto ifdotoadoconnection_createadoconnection_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pWorkspace
    Py_XDECREF(py_pADOConnection);
    if (ippADOConnection)
    {
        IUnknown* pUnk = NULL;
        ippADOConnection->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_pADOConnection = IUnknownToPythonIIDObject(pUnk, &IID_IUnknown);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_pADOConnection)
    {
        if (py_pADOConnection)
           Py_DECREF(py_pADOConnection);
        py_pADOConnection = Py_None;
        Py_INCREF(py_pADOConnection);
    }
    if (PyErr_Occurred())
      goto ifdotoadoconnection_createadoconnection_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_pADOConnection);
    goto ifdotoadoconnection_createadoconnection_method_cleanup;

    ifdotoadoconnection_createadoconnection_method_cleanup:
    self->m_HR = hr;
    if (ippWorkspace)
      ippWorkspace->Release();
    Py_XDECREF(py_pADOConnection);
    if (ippADOConnection)
      ippADOConnection->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IFDOToADOConnection.CreateADOConnection");
    return return_tuple;
}


PyMethodDef PyIFDOToADOConnectionMethods[] = {
    {"supports", (PyCFunction)PyIFDOToADOConnection_SupportsInterface, METH_O, ""},
    {"Connect", (PyCFunction)IFDOToADOConnectionMethod_Connect, METH_VARARGS, ""},
    {"CreateADOConnection", (PyCFunction)IFDOToADOConnectionMethod_CreateADOConnection, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIFDOToADOConnectionGetSet[] = {
  {"_pUnk", (getter)PyIFDOToADOConnection_GetpUnk, NULL, "Get opaque pointer to an Unknown from IFDOToADOConnection", NULL},
  {"_pointer", (getter)PyIFDOToADOConnection_GetPointer, NULL, "Get memory address for IFDOToADOConnection", NULL},
  {"_IID", (getter)PyIFDOToADOConnection_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIFDOToADOConnection_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIFDOToADOConnection_GetIgnoreFailures, (setter)PyIFDOToADOConnection_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIFDOToADOConnectionObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesOleDB.IFDOToADOConnectionObject",                          
                                              /* tp_name */
  sizeof(PyIFDOToADOConnectionObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIFDOToADOConnectionObject_dealloc,      
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
  PyIFDOToADOConnectionMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIFDOToADOConnectionGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIFDOToADOConnectionObject_new,                      
                                              /* tp_new */
};

// Interface IOleDBFDOHelper

typedef struct PyIOleDBFDOHelperObject {
    PyObject_HEAD
    IOleDBFDOHelper* m_pIOleDBFDOHelper;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIOleDBFDOHelperObject;

static PyObject*
PyIOleDBFDOHelperObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIOleDBFDOHelperObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IOleDBFDOHelper* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IOleDBFDOHelper, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IOleDBFDOHelper with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIOleDBFDOHelperObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IOleDBFDOHelper");
            return NULL;
        }
        self->m_pIOleDBFDOHelper = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IOleDBFDOHelper");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IOleDBFDOHelper");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IOleDBFDOHelper* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IOleDBFDOHelper, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IOleDBFDOHelper");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIOleDBFDOHelperObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IOleDBFDOHelper");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIOleDBFDOHelper = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIOleDBFDOHelperObject_dealloc(PyIOleDBFDOHelperObject* self)
{
    if (self->m_pIOleDBFDOHelper)
        self->m_pIOleDBFDOHelper->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIOleDBFDOHelper_GetpUnk(PyIOleDBFDOHelperObject* self)
{
    if (!self->m_pIOleDBFDOHelper)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIOleDBFDOHelper->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IOleDBFDOHelper to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIOleDBFDOHelper_GetPointer(PyIOleDBFDOHelperObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIOleDBFDOHelper);
}

static PyObject*
PyIOleDBFDOHelper_GetIID(PyIOleDBFDOHelperObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "7461df2b-6389-11d2-aaaf-00c04fa37849");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIOleDBFDOHelper_GetHR(PyIOleDBFDOHelperObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIOleDBFDOHelper_GetIgnoreFailures(PyIOleDBFDOHelperObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIOleDBFDOHelper_SetIgnoreFailures(PyIOleDBFDOHelperObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIOleDBFDOHelper_SupportsInterface(PyIOleDBFDOHelperObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIOleDBFDOHelper->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IOleDBFDOHelperMethod_AttachWorkspace(PyIOleDBFDOHelperObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IWorkspace* ippWorkspace = NULL;
    PyObject* py_pWorkspace;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_pWorkspace))
      goto ioledbfdohelper_attachworkspace_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_pWorkspace, &IID_IWorkspace, (void**)&ippWorkspace))
        PyErr_SetString(PyExc_TypeError, "Argument pWorkspace (position 0) is not IWorkspace");
    
    if (PyErr_Occurred())
      goto ioledbfdohelper_attachworkspace_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIOleDBFDOHelper->AttachWorkspace(ippWorkspace);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOleDBFDOHelper->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOleDBFDOHelper) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOleDBFDOHelper.AttachWorkspace() returned %ld", (long)hr);
        goto ioledbfdohelper_attachworkspace_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pWorkspace

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto ioledbfdohelper_attachworkspace_method_cleanup;

    ioledbfdohelper_attachworkspace_method_cleanup:
    self->m_HR = hr;
    if (ippWorkspace)
      ippWorkspace->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOleDBFDOHelper.AttachWorkspace");
    return return_tuple;
}


PyMethodDef PyIOleDBFDOHelperMethods[] = {
    {"supports", (PyCFunction)PyIOleDBFDOHelper_SupportsInterface, METH_O, ""},
    {"AttachWorkspace", (PyCFunction)IOleDBFDOHelperMethod_AttachWorkspace, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIOleDBFDOHelperGetSet[] = {
  {"_pUnk", (getter)PyIOleDBFDOHelper_GetpUnk, NULL, "Get opaque pointer to an Unknown from IOleDBFDOHelper", NULL},
  {"_pointer", (getter)PyIOleDBFDOHelper_GetPointer, NULL, "Get memory address for IOleDBFDOHelper", NULL},
  {"_IID", (getter)PyIOleDBFDOHelper_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIOleDBFDOHelper_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIOleDBFDOHelper_GetIgnoreFailures, (setter)PyIOleDBFDOHelper_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIOleDBFDOHelperObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesOleDB.IOleDBFDOHelperObject",                          
                                              /* tp_name */
  sizeof(PyIOleDBFDOHelperObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIOleDBFDOHelperObject_dealloc,      
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
  PyIOleDBFDOHelperMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIOleDBFDOHelperGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIOleDBFDOHelperObject_new,                      
                                              /* tp_new */
};

// Interface IESRIDataSourceCreate

typedef struct PyIESRIDataSourceCreateObject {
    PyObject_HEAD
    IESRIDataSourceCreate* m_pIESRIDataSourceCreate;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIESRIDataSourceCreateObject;

static PyObject*
PyIESRIDataSourceCreateObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIESRIDataSourceCreateObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IESRIDataSourceCreate* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IESRIDataSourceCreate, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IESRIDataSourceCreate with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIESRIDataSourceCreateObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IESRIDataSourceCreate");
            return NULL;
        }
        self->m_pIESRIDataSourceCreate = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IESRIDataSourceCreate");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IESRIDataSourceCreate");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IESRIDataSourceCreate* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IESRIDataSourceCreate, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IESRIDataSourceCreate");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIESRIDataSourceCreateObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IESRIDataSourceCreate");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIESRIDataSourceCreate = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIESRIDataSourceCreateObject_dealloc(PyIESRIDataSourceCreateObject* self)
{
    if (self->m_pIESRIDataSourceCreate)
        self->m_pIESRIDataSourceCreate->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIESRIDataSourceCreate_GetpUnk(PyIESRIDataSourceCreateObject* self)
{
    if (!self->m_pIESRIDataSourceCreate)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIESRIDataSourceCreate->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IESRIDataSourceCreate to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIESRIDataSourceCreate_GetPointer(PyIESRIDataSourceCreateObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIESRIDataSourceCreate);
}

static PyObject*
PyIESRIDataSourceCreate_GetIID(PyIESRIDataSourceCreateObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "7e82a55f-637d-11d2-aaaf-00c04fa37849");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIESRIDataSourceCreate_GetHR(PyIESRIDataSourceCreateObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIESRIDataSourceCreate_GetIgnoreFailures(PyIESRIDataSourceCreateObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIESRIDataSourceCreate_SetIgnoreFailures(PyIESRIDataSourceCreateObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIESRIDataSourceCreate_SupportsInterface(PyIESRIDataSourceCreateObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIESRIDataSourceCreate->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IESRIDataSourceCreateMethod_CreateDataSource(PyIESRIDataSourceCreateObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IWorkspace* ippWorkspace = NULL;
    PyObject* py_pWorkspace;
    IUnknown* ippDataSource = NULL;
    PyObject* py_pDataSource = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_pWorkspace))
      goto iesridatasourcecreate_createdatasource_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_pWorkspace, &IID_IWorkspace, (void**)&ippWorkspace))
        PyErr_SetString(PyExc_TypeError, "Argument pWorkspace (position 0) is not IWorkspace");
    
    if (PyErr_Occurred())
      goto iesridatasourcecreate_createdatasource_method_cleanup;
    
    // No setup for pDataSource

    // Call method on actual COM interface
    hr = self->m_pIESRIDataSourceCreate->CreateDataSource(ippWorkspace, &ippDataSource);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIESRIDataSourceCreate->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IESRIDataSourceCreate) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IESRIDataSourceCreate.CreateDataSource() returned %ld", (long)hr);
        goto iesridatasourcecreate_createdatasource_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pWorkspace
    Py_XDECREF(py_pDataSource);
    if (ippDataSource)
    {
        IUnknown* pUnk = NULL;
        ippDataSource->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_pDataSource = IUnknownToPythonIIDObject(pUnk, &IID_IUnknown);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_pDataSource)
    {
        if (py_pDataSource)
           Py_DECREF(py_pDataSource);
        py_pDataSource = Py_None;
        Py_INCREF(py_pDataSource);
    }
    if (PyErr_Occurred())
      goto iesridatasourcecreate_createdatasource_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_pDataSource);
    goto iesridatasourcecreate_createdatasource_method_cleanup;

    iesridatasourcecreate_createdatasource_method_cleanup:
    self->m_HR = hr;
    if (ippWorkspace)
      ippWorkspace->Release();
    Py_XDECREF(py_pDataSource);
    if (ippDataSource)
      ippDataSource->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IESRIDataSourceCreate.CreateDataSource");
    return return_tuple;
}


PyMethodDef PyIESRIDataSourceCreateMethods[] = {
    {"supports", (PyCFunction)PyIESRIDataSourceCreate_SupportsInterface, METH_O, ""},
    {"CreateDataSource", (PyCFunction)IESRIDataSourceCreateMethod_CreateDataSource, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIESRIDataSourceCreateGetSet[] = {
  {"_pUnk", (getter)PyIESRIDataSourceCreate_GetpUnk, NULL, "Get opaque pointer to an Unknown from IESRIDataSourceCreate", NULL},
  {"_pointer", (getter)PyIESRIDataSourceCreate_GetPointer, NULL, "Get memory address for IESRIDataSourceCreate", NULL},
  {"_IID", (getter)PyIESRIDataSourceCreate_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIESRIDataSourceCreate_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIESRIDataSourceCreate_GetIgnoreFailures, (setter)PyIESRIDataSourceCreate_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIESRIDataSourceCreateObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesOleDB.IESRIDataSourceCreateObject",                          
                                              /* tp_name */
  sizeof(PyIESRIDataSourceCreateObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIESRIDataSourceCreateObject_dealloc,      
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
  PyIESRIDataSourceCreateMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIESRIDataSourceCreateGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIESRIDataSourceCreateObject_new,                      
                                              /* tp_new */
};





static PyObject*
CoCreateOLEDBWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_OLEDBWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of OLEDBWorkspaceFactory");
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
            // clsid_key_lookup = uuid.UUID("59158055-3171-11d2-aa94-00c04fa37849")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "59158055-3171-11d2-aa94-00c04fa37849");
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
CoCreateTextFileWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_TextFileWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of TextFileWorkspaceFactory");
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
            // clsid_key_lookup = uuid.UUID("72ce59ec-0be8-11d4-ae03-00c04fa33a15")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "72ce59ec-0be8-11d4-ae03-00c04fa33a15");
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
CoCreateExcelWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_ExcelWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of ExcelWorkspaceFactory");
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
            // clsid_key_lookup = uuid.UUID("30f6f271-852b-4ee8-bd2d-099f51d6b238")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "30f6f271-852b-4ee8-bd2d-099f51d6b238");
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
CoCreateFdoAdoConnection(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_FdoAdoConnection, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of FdoAdoConnection");
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
            // clsid_key_lookup = uuid.UUID("fdde3870-638b-11d2-aaaf-00c04fa37849")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "fdde3870-638b-11d2-aaaf-00c04fa37849");
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



static PyMethodDef _esriDataSourcesOleDBMethods[] = {
    {"OLEDBWorkspaceFactory", (PyCFunction)CoCreateOLEDBWorkspaceFactory, METH_NOARGS,
     "Create instance of OLEDBWorkspaceFactory\n"},
    {"TextFileWorkspaceFactory", (PyCFunction)CoCreateTextFileWorkspaceFactory, METH_NOARGS,
     "Create instance of TextFileWorkspaceFactory\n"},
    {"ExcelWorkspaceFactory", (PyCFunction)CoCreateExcelWorkspaceFactory, METH_NOARGS,
     "Create instance of ExcelWorkspaceFactory\n"},
    {"FdoAdoConnection", (PyCFunction)CoCreateFdoAdoConnection, METH_NOARGS,
     "Create instance of FdoAdoConnection\n"},
    {NULL, NULL, 0, NULL}
};

extern "C" {

    PyMODINIT_FUNC
    init_esriDataSourcesOleDB(void)
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
        module = Py_InitModule3("cartocomutils._esriDataSourcesOleDB",
                                 _esriDataSourcesOleDBMethods,
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
        // IFDOToADOConnection
        PyType_Ready(&PyIFDOToADOConnectionObject_Type);
        Py_INCREF((PyObject* )&PyIFDOToADOConnectionObject_Type);
        PyModule_AddObject(module, "IFDOToADOConnection", 
                           (PyObject *)&PyIFDOToADOConnectionObject_Type);

        // IOleDBFDOHelper
        PyType_Ready(&PyIOleDBFDOHelperObject_Type);
        Py_INCREF((PyObject* )&PyIOleDBFDOHelperObject_Type);
        PyModule_AddObject(module, "IOleDBFDOHelper", 
                           (PyObject *)&PyIOleDBFDOHelperObject_Type);

        // IESRIDataSourceCreate
        PyType_Ready(&PyIESRIDataSourceCreateObject_Type);
        Py_INCREF((PyObject* )&PyIESRIDataSourceCreateObject_Type);
        PyModule_AddObject(module, "IESRIDataSourceCreate", 
                           (PyObject *)&PyIESRIDataSourceCreateObject_Type);


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
