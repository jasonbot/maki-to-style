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




// Interface IRasterSdeConnection

typedef struct PyIRasterSdeConnectionObject {
    PyObject_HEAD
    IRasterSdeConnection* m_pIRasterSdeConnection;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIRasterSdeConnectionObject;

static PyObject*
PyIRasterSdeConnectionObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIRasterSdeConnectionObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IRasterSdeConnection* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IRasterSdeConnection, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IRasterSdeConnection with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIRasterSdeConnectionObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IRasterSdeConnection");
            return NULL;
        }
        self->m_pIRasterSdeConnection = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IRasterSdeConnection");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IRasterSdeConnection");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IRasterSdeConnection* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IRasterSdeConnection, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IRasterSdeConnection");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIRasterSdeConnectionObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IRasterSdeConnection");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIRasterSdeConnection = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIRasterSdeConnectionObject_dealloc(PyIRasterSdeConnectionObject* self)
{
    if (self->m_pIRasterSdeConnection)
        self->m_pIRasterSdeConnection->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIRasterSdeConnection_GetpUnk(PyIRasterSdeConnectionObject* self)
{
    if (!self->m_pIRasterSdeConnection)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIRasterSdeConnection->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IRasterSdeConnection to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIRasterSdeConnection_GetPointer(PyIRasterSdeConnectionObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIRasterSdeConnection);
}

static PyObject*
PyIRasterSdeConnection_GetIID(PyIRasterSdeConnectionObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "7d00f368-fddf-11d3-b2be-00c04f8edeff");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIRasterSdeConnection_GetHR(PyIRasterSdeConnectionObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIRasterSdeConnection_GetIgnoreFailures(PyIRasterSdeConnectionObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIRasterSdeConnection_SetIgnoreFailures(PyIRasterSdeConnectionObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIRasterSdeConnection_SupportsInterface(PyIRasterSdeConnectionObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IRasterSdeConnectionMethod_put_ServerName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsName = 0;
    PyObject* pyvar_Name;
    PyObject* unicodeName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_Name))
      goto irastersdeconnection_put_servername_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_Name))
        unicodeName = PyUnicode_FromObject(pyvar_Name);
    else if (PyUnicode_Check(pyvar_Name))
    {
        unicodeName = pyvar_Name;
        Py_INCREF(unicodeName);
    }
    else if (pyvar_Name != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter Name at index 0");
    if (unicodeName)
        bsName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection_put_servername_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->put_ServerName(bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.put_ServerName() returned %ld", (long)hr);
        goto irastersdeconnection_put_servername_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Name

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection_put_servername_method_cleanup;

    irastersdeconnection_put_servername_method_cleanup:
    self->m_HR = hr;
    if (bsName)
        ::SysFreeString(bsName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.put_ServerName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_get_ServerName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsName;
    PyObject* pyvar_Name = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Name

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->get_ServerName(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.get_ServerName() returned %ld", (long)hr);
        goto irastersdeconnection_get_servername_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection_get_servername_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto irastersdeconnection_get_servername_method_cleanup;

    irastersdeconnection_get_servername_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.get_ServerName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_put_Instance(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsName = 0;
    PyObject* pyvar_Name;
    PyObject* unicodeName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_Name))
      goto irastersdeconnection_put_instance_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_Name))
        unicodeName = PyUnicode_FromObject(pyvar_Name);
    else if (PyUnicode_Check(pyvar_Name))
    {
        unicodeName = pyvar_Name;
        Py_INCREF(unicodeName);
    }
    else if (pyvar_Name != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter Name at index 0");
    if (unicodeName)
        bsName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection_put_instance_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->put_Instance(bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.put_Instance() returned %ld", (long)hr);
        goto irastersdeconnection_put_instance_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Name

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection_put_instance_method_cleanup;

    irastersdeconnection_put_instance_method_cleanup:
    self->m_HR = hr;
    if (bsName)
        ::SysFreeString(bsName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.put_Instance");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_get_Instance(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsName;
    PyObject* pyvar_Name = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Name

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->get_Instance(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.get_Instance() returned %ld", (long)hr);
        goto irastersdeconnection_get_instance_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection_get_instance_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto irastersdeconnection_get_instance_method_cleanup;

    irastersdeconnection_get_instance_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.get_Instance");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_put_Database(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdatabaseName = 0;
    PyObject* pyvar_databaseName;
    PyObject* unicodedatabaseName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_databaseName))
      goto irastersdeconnection_put_database_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_databaseName))
        unicodedatabaseName = PyUnicode_FromObject(pyvar_databaseName);
    else if (PyUnicode_Check(pyvar_databaseName))
    {
        unicodedatabaseName = pyvar_databaseName;
        Py_INCREF(unicodedatabaseName);
    }
    else if (pyvar_databaseName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter databaseName at index 0");
    if (unicodedatabaseName)
        bsdatabaseName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedatabaseName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedatabaseName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection_put_database_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->put_Database(bsdatabaseName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.put_Database() returned %ld", (long)hr);
        goto irastersdeconnection_put_database_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for databaseName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection_put_database_method_cleanup;

    irastersdeconnection_put_database_method_cleanup:
    self->m_HR = hr;
    if (bsdatabaseName)
        ::SysFreeString(bsdatabaseName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.put_Database");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_get_Database(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdatabaseName;
    PyObject* pyvar_databaseName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for databaseName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->get_Database(&bsdatabaseName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.get_Database() returned %ld", (long)hr);
        goto irastersdeconnection_get_database_method_cleanup;
    }

    // Set up return values as needed
    pyvar_databaseName = PyUnicode_FromWideChar(bsdatabaseName,::SysStringLen(bsdatabaseName));
    ::SysFreeString(bsdatabaseName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection_get_database_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_databaseName);
    goto irastersdeconnection_get_database_method_cleanup;

    irastersdeconnection_get_database_method_cleanup:
    self->m_HR = hr;
    if (pyvar_databaseName != Py_None)
        Py_XDECREF(pyvar_databaseName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.get_Database");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_put_SdeRasterName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsoutputName = 0;
    PyObject* pyvar_outputName;
    PyObject* unicodeoutputName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_outputName))
      goto irastersdeconnection_put_sderastername_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_outputName))
        unicodeoutputName = PyUnicode_FromObject(pyvar_outputName);
    else if (PyUnicode_Check(pyvar_outputName))
    {
        unicodeoutputName = pyvar_outputName;
        Py_INCREF(unicodeoutputName);
    }
    else if (pyvar_outputName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter outputName at index 0");
    if (unicodeoutputName)
        bsoutputName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeoutputName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeoutputName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection_put_sderastername_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->put_SdeRasterName(bsoutputName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.put_SdeRasterName() returned %ld", (long)hr);
        goto irastersdeconnection_put_sderastername_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for outputName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection_put_sderastername_method_cleanup;

    irastersdeconnection_put_sderastername_method_cleanup:
    self->m_HR = hr;
    if (bsoutputName)
        ::SysFreeString(bsoutputName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.put_SdeRasterName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_get_SdeRasterName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsoutputName;
    PyObject* pyvar_outputName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for outputName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->get_SdeRasterName(&bsoutputName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.get_SdeRasterName() returned %ld", (long)hr);
        goto irastersdeconnection_get_sderastername_method_cleanup;
    }

    // Set up return values as needed
    pyvar_outputName = PyUnicode_FromWideChar(bsoutputName,::SysStringLen(bsoutputName));
    ::SysFreeString(bsoutputName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection_get_sderastername_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_outputName);
    goto irastersdeconnection_get_sderastername_method_cleanup;

    irastersdeconnection_get_sderastername_method_cleanup:
    self->m_HR = hr;
    if (pyvar_outputName != Py_None)
        Py_XDECREF(pyvar_outputName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.get_SdeRasterName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_put_UserName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsUserName = 0;
    PyObject* pyvar_UserName;
    PyObject* unicodeUserName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_UserName))
      goto irastersdeconnection_put_username_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_UserName))
        unicodeUserName = PyUnicode_FromObject(pyvar_UserName);
    else if (PyUnicode_Check(pyvar_UserName))
    {
        unicodeUserName = pyvar_UserName;
        Py_INCREF(unicodeUserName);
    }
    else if (pyvar_UserName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter UserName at index 0");
    if (unicodeUserName)
        bsUserName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeUserName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeUserName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection_put_username_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->put_UserName(bsUserName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.put_UserName() returned %ld", (long)hr);
        goto irastersdeconnection_put_username_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for UserName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection_put_username_method_cleanup;

    irastersdeconnection_put_username_method_cleanup:
    self->m_HR = hr;
    if (bsUserName)
        ::SysFreeString(bsUserName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.put_UserName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_get_UserName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsUserName;
    PyObject* pyvar_UserName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for UserName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->get_UserName(&bsUserName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.get_UserName() returned %ld", (long)hr);
        goto irastersdeconnection_get_username_method_cleanup;
    }

    // Set up return values as needed
    pyvar_UserName = PyUnicode_FromWideChar(bsUserName,::SysStringLen(bsUserName));
    ::SysFreeString(bsUserName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection_get_username_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_UserName);
    goto irastersdeconnection_get_username_method_cleanup;

    irastersdeconnection_get_username_method_cleanup:
    self->m_HR = hr;
    if (pyvar_UserName != Py_None)
        Py_XDECREF(pyvar_UserName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.get_UserName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_put_Password(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsPassword = 0;
    PyObject* pyvar_Password;
    PyObject* unicodePassword = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_Password))
      goto irastersdeconnection_put_password_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_Password))
        unicodePassword = PyUnicode_FromObject(pyvar_Password);
    else if (PyUnicode_Check(pyvar_Password))
    {
        unicodePassword = pyvar_Password;
        Py_INCREF(unicodePassword);
    }
    else if (pyvar_Password != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter Password at index 0");
    if (unicodePassword)
        bsPassword = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodePassword), 
                                            (UINT)PyUnicode_GET_SIZE(unicodePassword));
    
    if (PyErr_Occurred())
      goto irastersdeconnection_put_password_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->put_Password(bsPassword);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.put_Password() returned %ld", (long)hr);
        goto irastersdeconnection_put_password_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Password

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection_put_password_method_cleanup;

    irastersdeconnection_put_password_method_cleanup:
    self->m_HR = hr;
    if (bsPassword)
        ::SysFreeString(bsPassword);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.put_Password");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_get_Password(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsPassword;
    PyObject* pyvar_Password = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Password

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->get_Password(&bsPassword);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.get_Password() returned %ld", (long)hr);
        goto irastersdeconnection_get_password_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Password = PyUnicode_FromWideChar(bsPassword,::SysStringLen(bsPassword));
    ::SysFreeString(bsPassword);
    
    if (PyErr_Occurred())
      goto irastersdeconnection_get_password_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Password);
    goto irastersdeconnection_get_password_method_cleanup;

    irastersdeconnection_get_password_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Password != Py_None)
        Py_XDECREF(pyvar_Password);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.get_Password");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_put_InputRasterName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsinputName = 0;
    PyObject* pyvar_inputName;
    PyObject* unicodeinputName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_inputName))
      goto irastersdeconnection_put_inputrastername_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_inputName))
        unicodeinputName = PyUnicode_FromObject(pyvar_inputName);
    else if (PyUnicode_Check(pyvar_inputName))
    {
        unicodeinputName = pyvar_inputName;
        Py_INCREF(unicodeinputName);
    }
    else if (pyvar_inputName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter inputName at index 0");
    if (unicodeinputName)
        bsinputName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeinputName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeinputName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection_put_inputrastername_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->put_InputRasterName(bsinputName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.put_InputRasterName() returned %ld", (long)hr);
        goto irastersdeconnection_put_inputrastername_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for inputName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection_put_inputrastername_method_cleanup;

    irastersdeconnection_put_inputrastername_method_cleanup:
    self->m_HR = hr;
    if (bsinputName)
        ::SysFreeString(bsinputName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.put_InputRasterName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_get_InputRasterName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsinputName;
    PyObject* pyvar_inputName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for inputName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->get_InputRasterName(&bsinputName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.get_InputRasterName() returned %ld", (long)hr);
        goto irastersdeconnection_get_inputrastername_method_cleanup;
    }

    // Set up return values as needed
    pyvar_inputName = PyUnicode_FromWideChar(bsinputName,::SysStringLen(bsinputName));
    ::SysFreeString(bsinputName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection_get_inputrastername_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_inputName);
    goto irastersdeconnection_get_inputrastername_method_cleanup;

    irastersdeconnection_get_inputrastername_method_cleanup:
    self->m_HR = hr;
    if (pyvar_inputName != Py_None)
        Py_XDECREF(pyvar_inputName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.get_InputRasterName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_put_InputBitMaskName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsbitMaskName = 0;
    PyObject* pyvar_bitMaskName;
    PyObject* unicodebitMaskName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_bitMaskName))
      goto irastersdeconnection_put_inputbitmaskname_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_bitMaskName))
        unicodebitMaskName = PyUnicode_FromObject(pyvar_bitMaskName);
    else if (PyUnicode_Check(pyvar_bitMaskName))
    {
        unicodebitMaskName = pyvar_bitMaskName;
        Py_INCREF(unicodebitMaskName);
    }
    else if (pyvar_bitMaskName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter bitMaskName at index 0");
    if (unicodebitMaskName)
        bsbitMaskName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodebitMaskName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodebitMaskName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection_put_inputbitmaskname_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->put_InputBitMaskName(bsbitMaskName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.put_InputBitMaskName() returned %ld", (long)hr);
        goto irastersdeconnection_put_inputbitmaskname_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for bitMaskName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection_put_inputbitmaskname_method_cleanup;

    irastersdeconnection_put_inputbitmaskname_method_cleanup:
    self->m_HR = hr;
    if (bsbitMaskName)
        ::SysFreeString(bsbitMaskName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.put_InputBitMaskName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_get_InputBitMaskName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsbitMaskName;
    PyObject* pyvar_bitMaskName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for bitMaskName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->get_InputBitMaskName(&bsbitMaskName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.get_InputBitMaskName() returned %ld", (long)hr);
        goto irastersdeconnection_get_inputbitmaskname_method_cleanup;
    }

    // Set up return values as needed
    pyvar_bitMaskName = PyUnicode_FromWideChar(bsbitMaskName,::SysStringLen(bsbitMaskName));
    ::SysFreeString(bsbitMaskName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection_get_inputbitmaskname_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bitMaskName);
    goto irastersdeconnection_get_inputbitmaskname_method_cleanup;

    irastersdeconnection_get_inputbitmaskname_method_cleanup:
    self->m_HR = hr;
    if (pyvar_bitMaskName != Py_None)
        Py_XDECREF(pyvar_bitMaskName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.get_InputBitMaskName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnectionMethod_put_SdeConnection(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'IGxDatabase', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IRasterSdeConnection.put_SdeConnection not implemented.");
    return NULL;
}

static PyObject*
IRasterSdeConnectionMethod_put_SdeWorkspaceName(PyIRasterSdeConnectionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IWorkspaceName* ip_arg1 = NULL;
    PyObject* py__arg1;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py__arg1))
      goto irastersdeconnection_put_sdeworkspacename_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py__arg1, &IID_IWorkspaceName, (void**)&ip_arg1))
        PyErr_SetString(PyExc_TypeError, "Argument _arg1 (position 0) is not IWorkspaceName");
    
    if (PyErr_Occurred())
      goto irastersdeconnection_put_sdeworkspacename_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection->put_SdeWorkspaceName(ip_arg1);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection.put_SdeWorkspaceName() returned %ld", (long)hr);
        goto irastersdeconnection_put_sdeworkspacename_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for _arg1

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection_put_sdeworkspacename_method_cleanup;

    irastersdeconnection_put_sdeworkspacename_method_cleanup:
    self->m_HR = hr;
    if (ip_arg1)
      ip_arg1->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection.put_SdeWorkspaceName");
    return return_tuple;
}


PyMethodDef PyIRasterSdeConnectionMethods[] = {
    {"supports", (PyCFunction)PyIRasterSdeConnection_SupportsInterface, METH_O, ""},
    {"put_ServerName", (PyCFunction)IRasterSdeConnectionMethod_put_ServerName, METH_VARARGS, ""},
    {"get_ServerName", (PyCFunction)IRasterSdeConnectionMethod_get_ServerName, METH_VARARGS, ""},
    {"put_Instance", (PyCFunction)IRasterSdeConnectionMethod_put_Instance, METH_VARARGS, ""},
    {"get_Instance", (PyCFunction)IRasterSdeConnectionMethod_get_Instance, METH_VARARGS, ""},
    {"put_Database", (PyCFunction)IRasterSdeConnectionMethod_put_Database, METH_VARARGS, ""},
    {"get_Database", (PyCFunction)IRasterSdeConnectionMethod_get_Database, METH_VARARGS, ""},
    {"put_SdeRasterName", (PyCFunction)IRasterSdeConnectionMethod_put_SdeRasterName, METH_VARARGS, ""},
    {"get_SdeRasterName", (PyCFunction)IRasterSdeConnectionMethod_get_SdeRasterName, METH_VARARGS, ""},
    {"put_UserName", (PyCFunction)IRasterSdeConnectionMethod_put_UserName, METH_VARARGS, ""},
    {"get_UserName", (PyCFunction)IRasterSdeConnectionMethod_get_UserName, METH_VARARGS, ""},
    {"put_Password", (PyCFunction)IRasterSdeConnectionMethod_put_Password, METH_VARARGS, ""},
    {"get_Password", (PyCFunction)IRasterSdeConnectionMethod_get_Password, METH_VARARGS, ""},
    {"put_InputRasterName", (PyCFunction)IRasterSdeConnectionMethod_put_InputRasterName, METH_VARARGS, ""},
    {"get_InputRasterName", (PyCFunction)IRasterSdeConnectionMethod_get_InputRasterName, METH_VARARGS, ""},
    {"put_InputBitMaskName", (PyCFunction)IRasterSdeConnectionMethod_put_InputBitMaskName, METH_VARARGS, ""},
    {"get_InputBitMaskName", (PyCFunction)IRasterSdeConnectionMethod_get_InputBitMaskName, METH_VARARGS, ""},
    {"put_SdeConnection", (PyCFunction)IRasterSdeConnectionMethod_put_SdeConnection, METH_VARARGS, ""},
    {"put_SdeWorkspaceName", (PyCFunction)IRasterSdeConnectionMethod_put_SdeWorkspaceName, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIRasterSdeConnectionGetSet[] = {
  {"_pUnk", (getter)PyIRasterSdeConnection_GetpUnk, NULL, "Get opaque pointer to an Unknown from IRasterSdeConnection", NULL},
  {"_pointer", (getter)PyIRasterSdeConnection_GetPointer, NULL, "Get memory address for IRasterSdeConnection", NULL},
  {"_IID", (getter)PyIRasterSdeConnection_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIRasterSdeConnection_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIRasterSdeConnection_GetIgnoreFailures, (setter)PyIRasterSdeConnection_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIRasterSdeConnectionObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesRasterUI.IRasterSdeConnectionObject",                          
                                              /* tp_name */
  sizeof(PyIRasterSdeConnectionObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIRasterSdeConnectionObject_dealloc,      
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
  PyIRasterSdeConnectionMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIRasterSdeConnectionGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIRasterSdeConnectionObject_new,                      
                                              /* tp_new */
};

// Interface IRasterSdeConnection2

typedef struct PyIRasterSdeConnection2Object {
    PyObject_HEAD
    IRasterSdeConnection2* m_pIRasterSdeConnection2;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIRasterSdeConnection2Object;

static PyObject*
PyIRasterSdeConnection2Object_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIRasterSdeConnection2Object* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IRasterSdeConnection2* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IRasterSdeConnection2, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IRasterSdeConnection2 with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIRasterSdeConnection2Object *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IRasterSdeConnection2");
            return NULL;
        }
        self->m_pIRasterSdeConnection2 = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IRasterSdeConnection2");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IRasterSdeConnection2");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IRasterSdeConnection2* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IRasterSdeConnection2, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IRasterSdeConnection2");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIRasterSdeConnection2Object *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IRasterSdeConnection2");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIRasterSdeConnection2 = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIRasterSdeConnection2Object_dealloc(PyIRasterSdeConnection2Object* self)
{
    if (self->m_pIRasterSdeConnection2)
        self->m_pIRasterSdeConnection2->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIRasterSdeConnection2_GetpUnk(PyIRasterSdeConnection2Object* self)
{
    if (!self->m_pIRasterSdeConnection2)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIRasterSdeConnection2->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IRasterSdeConnection2 to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIRasterSdeConnection2_GetPointer(PyIRasterSdeConnection2Object* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIRasterSdeConnection2);
}

static PyObject*
PyIRasterSdeConnection2_GetIID(PyIRasterSdeConnection2Object* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "999df174-4f53-45ec-9784-4d921dbb6a52");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIRasterSdeConnection2_GetHR(PyIRasterSdeConnection2Object* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIRasterSdeConnection2_GetIgnoreFailures(PyIRasterSdeConnection2Object* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIRasterSdeConnection2_SetIgnoreFailures(PyIRasterSdeConnection2Object* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIRasterSdeConnection2_SupportsInterface(PyIRasterSdeConnection2Object* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IRasterSdeConnection2Method_put_ServerName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsName = 0;
    PyObject* pyvar_Name;
    PyObject* unicodeName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_Name))
      goto irastersdeconnection2_put_servername_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_Name))
        unicodeName = PyUnicode_FromObject(pyvar_Name);
    else if (PyUnicode_Check(pyvar_Name))
    {
        unicodeName = pyvar_Name;
        Py_INCREF(unicodeName);
    }
    else if (pyvar_Name != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter Name at index 0");
    if (unicodeName)
        bsName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_put_servername_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->put_ServerName(bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.put_ServerName() returned %ld", (long)hr);
        goto irastersdeconnection2_put_servername_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Name

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_put_servername_method_cleanup;

    irastersdeconnection2_put_servername_method_cleanup:
    self->m_HR = hr;
    if (bsName)
        ::SysFreeString(bsName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.put_ServerName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_ServerName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsName;
    PyObject* pyvar_Name = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Name

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_ServerName(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_ServerName() returned %ld", (long)hr);
        goto irastersdeconnection2_get_servername_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_servername_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto irastersdeconnection2_get_servername_method_cleanup;

    irastersdeconnection2_get_servername_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_ServerName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_put_Instance(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsName = 0;
    PyObject* pyvar_Name;
    PyObject* unicodeName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_Name))
      goto irastersdeconnection2_put_instance_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_Name))
        unicodeName = PyUnicode_FromObject(pyvar_Name);
    else if (PyUnicode_Check(pyvar_Name))
    {
        unicodeName = pyvar_Name;
        Py_INCREF(unicodeName);
    }
    else if (pyvar_Name != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter Name at index 0");
    if (unicodeName)
        bsName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_put_instance_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->put_Instance(bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.put_Instance() returned %ld", (long)hr);
        goto irastersdeconnection2_put_instance_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Name

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_put_instance_method_cleanup;

    irastersdeconnection2_put_instance_method_cleanup:
    self->m_HR = hr;
    if (bsName)
        ::SysFreeString(bsName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.put_Instance");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_Instance(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsName;
    PyObject* pyvar_Name = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Name

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_Instance(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_Instance() returned %ld", (long)hr);
        goto irastersdeconnection2_get_instance_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_instance_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto irastersdeconnection2_get_instance_method_cleanup;

    irastersdeconnection2_get_instance_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_Instance");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_put_Database(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdatabaseName = 0;
    PyObject* pyvar_databaseName;
    PyObject* unicodedatabaseName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_databaseName))
      goto irastersdeconnection2_put_database_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_databaseName))
        unicodedatabaseName = PyUnicode_FromObject(pyvar_databaseName);
    else if (PyUnicode_Check(pyvar_databaseName))
    {
        unicodedatabaseName = pyvar_databaseName;
        Py_INCREF(unicodedatabaseName);
    }
    else if (pyvar_databaseName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter databaseName at index 0");
    if (unicodedatabaseName)
        bsdatabaseName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedatabaseName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedatabaseName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_put_database_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->put_Database(bsdatabaseName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.put_Database() returned %ld", (long)hr);
        goto irastersdeconnection2_put_database_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for databaseName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_put_database_method_cleanup;

    irastersdeconnection2_put_database_method_cleanup:
    self->m_HR = hr;
    if (bsdatabaseName)
        ::SysFreeString(bsdatabaseName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.put_Database");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_Database(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdatabaseName;
    PyObject* pyvar_databaseName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for databaseName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_Database(&bsdatabaseName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_Database() returned %ld", (long)hr);
        goto irastersdeconnection2_get_database_method_cleanup;
    }

    // Set up return values as needed
    pyvar_databaseName = PyUnicode_FromWideChar(bsdatabaseName,::SysStringLen(bsdatabaseName));
    ::SysFreeString(bsdatabaseName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_database_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_databaseName);
    goto irastersdeconnection2_get_database_method_cleanup;

    irastersdeconnection2_get_database_method_cleanup:
    self->m_HR = hr;
    if (pyvar_databaseName != Py_None)
        Py_XDECREF(pyvar_databaseName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_Database");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_put_SdeRasterName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsoutputName = 0;
    PyObject* pyvar_outputName;
    PyObject* unicodeoutputName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_outputName))
      goto irastersdeconnection2_put_sderastername_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_outputName))
        unicodeoutputName = PyUnicode_FromObject(pyvar_outputName);
    else if (PyUnicode_Check(pyvar_outputName))
    {
        unicodeoutputName = pyvar_outputName;
        Py_INCREF(unicodeoutputName);
    }
    else if (pyvar_outputName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter outputName at index 0");
    if (unicodeoutputName)
        bsoutputName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeoutputName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeoutputName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_put_sderastername_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->put_SdeRasterName(bsoutputName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.put_SdeRasterName() returned %ld", (long)hr);
        goto irastersdeconnection2_put_sderastername_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for outputName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_put_sderastername_method_cleanup;

    irastersdeconnection2_put_sderastername_method_cleanup:
    self->m_HR = hr;
    if (bsoutputName)
        ::SysFreeString(bsoutputName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.put_SdeRasterName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_SdeRasterName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsoutputName;
    PyObject* pyvar_outputName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for outputName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_SdeRasterName(&bsoutputName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_SdeRasterName() returned %ld", (long)hr);
        goto irastersdeconnection2_get_sderastername_method_cleanup;
    }

    // Set up return values as needed
    pyvar_outputName = PyUnicode_FromWideChar(bsoutputName,::SysStringLen(bsoutputName));
    ::SysFreeString(bsoutputName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_sderastername_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_outputName);
    goto irastersdeconnection2_get_sderastername_method_cleanup;

    irastersdeconnection2_get_sderastername_method_cleanup:
    self->m_HR = hr;
    if (pyvar_outputName != Py_None)
        Py_XDECREF(pyvar_outputName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_SdeRasterName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_put_UserName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsUserName = 0;
    PyObject* pyvar_UserName;
    PyObject* unicodeUserName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_UserName))
      goto irastersdeconnection2_put_username_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_UserName))
        unicodeUserName = PyUnicode_FromObject(pyvar_UserName);
    else if (PyUnicode_Check(pyvar_UserName))
    {
        unicodeUserName = pyvar_UserName;
        Py_INCREF(unicodeUserName);
    }
    else if (pyvar_UserName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter UserName at index 0");
    if (unicodeUserName)
        bsUserName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeUserName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeUserName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_put_username_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->put_UserName(bsUserName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.put_UserName() returned %ld", (long)hr);
        goto irastersdeconnection2_put_username_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for UserName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_put_username_method_cleanup;

    irastersdeconnection2_put_username_method_cleanup:
    self->m_HR = hr;
    if (bsUserName)
        ::SysFreeString(bsUserName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.put_UserName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_UserName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsUserName;
    PyObject* pyvar_UserName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for UserName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_UserName(&bsUserName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_UserName() returned %ld", (long)hr);
        goto irastersdeconnection2_get_username_method_cleanup;
    }

    // Set up return values as needed
    pyvar_UserName = PyUnicode_FromWideChar(bsUserName,::SysStringLen(bsUserName));
    ::SysFreeString(bsUserName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_username_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_UserName);
    goto irastersdeconnection2_get_username_method_cleanup;

    irastersdeconnection2_get_username_method_cleanup:
    self->m_HR = hr;
    if (pyvar_UserName != Py_None)
        Py_XDECREF(pyvar_UserName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_UserName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_put_Password(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsPassword = 0;
    PyObject* pyvar_Password;
    PyObject* unicodePassword = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_Password))
      goto irastersdeconnection2_put_password_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_Password))
        unicodePassword = PyUnicode_FromObject(pyvar_Password);
    else if (PyUnicode_Check(pyvar_Password))
    {
        unicodePassword = pyvar_Password;
        Py_INCREF(unicodePassword);
    }
    else if (pyvar_Password != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter Password at index 0");
    if (unicodePassword)
        bsPassword = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodePassword), 
                                            (UINT)PyUnicode_GET_SIZE(unicodePassword));
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_put_password_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->put_Password(bsPassword);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.put_Password() returned %ld", (long)hr);
        goto irastersdeconnection2_put_password_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Password

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_put_password_method_cleanup;

    irastersdeconnection2_put_password_method_cleanup:
    self->m_HR = hr;
    if (bsPassword)
        ::SysFreeString(bsPassword);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.put_Password");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_Password(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsPassword;
    PyObject* pyvar_Password = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Password

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_Password(&bsPassword);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_Password() returned %ld", (long)hr);
        goto irastersdeconnection2_get_password_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Password = PyUnicode_FromWideChar(bsPassword,::SysStringLen(bsPassword));
    ::SysFreeString(bsPassword);
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_password_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Password);
    goto irastersdeconnection2_get_password_method_cleanup;

    irastersdeconnection2_get_password_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Password != Py_None)
        Py_XDECREF(pyvar_Password);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_Password");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_put_InputRasterName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsinputName = 0;
    PyObject* pyvar_inputName;
    PyObject* unicodeinputName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_inputName))
      goto irastersdeconnection2_put_inputrastername_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_inputName))
        unicodeinputName = PyUnicode_FromObject(pyvar_inputName);
    else if (PyUnicode_Check(pyvar_inputName))
    {
        unicodeinputName = pyvar_inputName;
        Py_INCREF(unicodeinputName);
    }
    else if (pyvar_inputName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter inputName at index 0");
    if (unicodeinputName)
        bsinputName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeinputName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeinputName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_put_inputrastername_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->put_InputRasterName(bsinputName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.put_InputRasterName() returned %ld", (long)hr);
        goto irastersdeconnection2_put_inputrastername_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for inputName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_put_inputrastername_method_cleanup;

    irastersdeconnection2_put_inputrastername_method_cleanup:
    self->m_HR = hr;
    if (bsinputName)
        ::SysFreeString(bsinputName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.put_InputRasterName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_InputRasterName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsinputName;
    PyObject* pyvar_inputName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for inputName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_InputRasterName(&bsinputName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_InputRasterName() returned %ld", (long)hr);
        goto irastersdeconnection2_get_inputrastername_method_cleanup;
    }

    // Set up return values as needed
    pyvar_inputName = PyUnicode_FromWideChar(bsinputName,::SysStringLen(bsinputName));
    ::SysFreeString(bsinputName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_inputrastername_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_inputName);
    goto irastersdeconnection2_get_inputrastername_method_cleanup;

    irastersdeconnection2_get_inputrastername_method_cleanup:
    self->m_HR = hr;
    if (pyvar_inputName != Py_None)
        Py_XDECREF(pyvar_inputName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_InputRasterName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_put_InputBitMaskName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsbitMaskName = 0;
    PyObject* pyvar_bitMaskName;
    PyObject* unicodebitMaskName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_bitMaskName))
      goto irastersdeconnection2_put_inputbitmaskname_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_bitMaskName))
        unicodebitMaskName = PyUnicode_FromObject(pyvar_bitMaskName);
    else if (PyUnicode_Check(pyvar_bitMaskName))
    {
        unicodebitMaskName = pyvar_bitMaskName;
        Py_INCREF(unicodebitMaskName);
    }
    else if (pyvar_bitMaskName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter bitMaskName at index 0");
    if (unicodebitMaskName)
        bsbitMaskName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodebitMaskName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodebitMaskName));
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_put_inputbitmaskname_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->put_InputBitMaskName(bsbitMaskName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.put_InputBitMaskName() returned %ld", (long)hr);
        goto irastersdeconnection2_put_inputbitmaskname_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for bitMaskName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_put_inputbitmaskname_method_cleanup;

    irastersdeconnection2_put_inputbitmaskname_method_cleanup:
    self->m_HR = hr;
    if (bsbitMaskName)
        ::SysFreeString(bsbitMaskName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.put_InputBitMaskName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_InputBitMaskName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsbitMaskName;
    PyObject* pyvar_bitMaskName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for bitMaskName

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_InputBitMaskName(&bsbitMaskName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_InputBitMaskName() returned %ld", (long)hr);
        goto irastersdeconnection2_get_inputbitmaskname_method_cleanup;
    }

    // Set up return values as needed
    pyvar_bitMaskName = PyUnicode_FromWideChar(bsbitMaskName,::SysStringLen(bsbitMaskName));
    ::SysFreeString(bsbitMaskName);
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_inputbitmaskname_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bitMaskName);
    goto irastersdeconnection2_get_inputbitmaskname_method_cleanup;

    irastersdeconnection2_get_inputbitmaskname_method_cleanup:
    self->m_HR = hr;
    if (pyvar_bitMaskName != Py_None)
        Py_XDECREF(pyvar_bitMaskName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_InputBitMaskName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_put_SdeConnection(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'IGxDatabase', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IRasterSdeConnection2.put_SdeConnection not implemented.");
    return NULL;
}

static PyObject*
IRasterSdeConnection2Method_put_SdeWorkspaceName(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IWorkspaceName* ip_arg1 = NULL;
    PyObject* py__arg1;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py__arg1))
      goto irastersdeconnection2_put_sdeworkspacename_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py__arg1, &IID_IWorkspaceName, (void**)&ip_arg1))
        PyErr_SetString(PyExc_TypeError, "Argument _arg1 (position 0) is not IWorkspaceName");
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_put_sdeworkspacename_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->put_SdeWorkspaceName(ip_arg1);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.put_SdeWorkspaceName() returned %ld", (long)hr);
        goto irastersdeconnection2_put_sdeworkspacename_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for _arg1

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_put_sdeworkspacename_method_cleanup;

    irastersdeconnection2_put_sdeworkspacename_method_cleanup:
    self->m_HR = hr;
    if (ip_arg1)
      ip_arg1->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.put_SdeWorkspaceName");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_Raster(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IRaster* ipRaster = NULL;
    PyObject* py_Raster = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Raster

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_Raster(&ipRaster);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_Raster() returned %ld", (long)hr);
        goto irastersdeconnection2_get_raster_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_Raster);
    if (ipRaster)
    {
        IUnknown* pUnk = NULL;
        ipRaster->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_Raster = IUnknownToPythonIIDObject(pUnk, &IID_IRaster);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_Raster)
    {
        if (py_Raster)
           Py_DECREF(py_Raster);
        py_Raster = Py_None;
        Py_INCREF(py_Raster);
    }
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_raster_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_Raster);
    goto irastersdeconnection2_get_raster_method_cleanup;

    irastersdeconnection2_get_raster_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_Raster);
    if (ipRaster)
      ipRaster->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_Raster");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_putref_Raster(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IRaster* ipRaster = NULL;
    PyObject* py_Raster;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_Raster))
      goto irastersdeconnection2_putref_raster_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_Raster, &IID_IRaster, (void**)&ipRaster))
        PyErr_SetString(PyExc_TypeError, "Argument Raster (position 0) is not IRaster");
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_putref_raster_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->putref_Raster(ipRaster);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.putref_Raster() returned %ld", (long)hr);
        goto irastersdeconnection2_putref_raster_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Raster

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_putref_raster_method_cleanup;

    irastersdeconnection2_putref_raster_method_cleanup:
    self->m_HR = hr;
    if (ipRaster)
      ipRaster->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.putref_Raster");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_get_MaskRaster(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IRaster* ipMaskRaster = NULL;
    PyObject* py_MaskRaster = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for MaskRaster

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->get_MaskRaster(&ipMaskRaster);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.get_MaskRaster() returned %ld", (long)hr);
        goto irastersdeconnection2_get_maskraster_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_MaskRaster);
    if (ipMaskRaster)
    {
        IUnknown* pUnk = NULL;
        ipMaskRaster->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_MaskRaster = IUnknownToPythonIIDObject(pUnk, &IID_IRaster);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_MaskRaster)
    {
        if (py_MaskRaster)
           Py_DECREF(py_MaskRaster);
        py_MaskRaster = Py_None;
        Py_INCREF(py_MaskRaster);
    }
    if (PyErr_Occurred())
      goto irastersdeconnection2_get_maskraster_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_MaskRaster);
    goto irastersdeconnection2_get_maskraster_method_cleanup;

    irastersdeconnection2_get_maskraster_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_MaskRaster);
    if (ipMaskRaster)
      ipMaskRaster->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.get_MaskRaster");
    return return_tuple;
}

static PyObject*
IRasterSdeConnection2Method_putref_MaskRaster(PyIRasterSdeConnection2Object* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IRaster* ipMaskRaster = NULL;
    PyObject* py_MaskRaster;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_MaskRaster))
      goto irastersdeconnection2_putref_maskraster_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_MaskRaster, &IID_IRaster, (void**)&ipMaskRaster))
        PyErr_SetString(PyExc_TypeError, "Argument MaskRaster (position 0) is not IRaster");
    
    if (PyErr_Occurred())
      goto irastersdeconnection2_putref_maskraster_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIRasterSdeConnection2->putref_MaskRaster(ipMaskRaster);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIRasterSdeConnection2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IRasterSdeConnection2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IRasterSdeConnection2.putref_MaskRaster() returned %ld", (long)hr);
        goto irastersdeconnection2_putref_maskraster_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for MaskRaster

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto irastersdeconnection2_putref_maskraster_method_cleanup;

    irastersdeconnection2_putref_maskraster_method_cleanup:
    self->m_HR = hr;
    if (ipMaskRaster)
      ipMaskRaster->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IRasterSdeConnection2.putref_MaskRaster");
    return return_tuple;
}


PyMethodDef PyIRasterSdeConnection2Methods[] = {
    {"supports", (PyCFunction)PyIRasterSdeConnection2_SupportsInterface, METH_O, ""},
    {"put_ServerName", (PyCFunction)IRasterSdeConnection2Method_put_ServerName, METH_VARARGS, ""},
    {"get_ServerName", (PyCFunction)IRasterSdeConnection2Method_get_ServerName, METH_VARARGS, ""},
    {"put_Instance", (PyCFunction)IRasterSdeConnection2Method_put_Instance, METH_VARARGS, ""},
    {"get_Instance", (PyCFunction)IRasterSdeConnection2Method_get_Instance, METH_VARARGS, ""},
    {"put_Database", (PyCFunction)IRasterSdeConnection2Method_put_Database, METH_VARARGS, ""},
    {"get_Database", (PyCFunction)IRasterSdeConnection2Method_get_Database, METH_VARARGS, ""},
    {"put_SdeRasterName", (PyCFunction)IRasterSdeConnection2Method_put_SdeRasterName, METH_VARARGS, ""},
    {"get_SdeRasterName", (PyCFunction)IRasterSdeConnection2Method_get_SdeRasterName, METH_VARARGS, ""},
    {"put_UserName", (PyCFunction)IRasterSdeConnection2Method_put_UserName, METH_VARARGS, ""},
    {"get_UserName", (PyCFunction)IRasterSdeConnection2Method_get_UserName, METH_VARARGS, ""},
    {"put_Password", (PyCFunction)IRasterSdeConnection2Method_put_Password, METH_VARARGS, ""},
    {"get_Password", (PyCFunction)IRasterSdeConnection2Method_get_Password, METH_VARARGS, ""},
    {"put_InputRasterName", (PyCFunction)IRasterSdeConnection2Method_put_InputRasterName, METH_VARARGS, ""},
    {"get_InputRasterName", (PyCFunction)IRasterSdeConnection2Method_get_InputRasterName, METH_VARARGS, ""},
    {"put_InputBitMaskName", (PyCFunction)IRasterSdeConnection2Method_put_InputBitMaskName, METH_VARARGS, ""},
    {"get_InputBitMaskName", (PyCFunction)IRasterSdeConnection2Method_get_InputBitMaskName, METH_VARARGS, ""},
    {"put_SdeConnection", (PyCFunction)IRasterSdeConnection2Method_put_SdeConnection, METH_VARARGS, ""},
    {"put_SdeWorkspaceName", (PyCFunction)IRasterSdeConnection2Method_put_SdeWorkspaceName, METH_VARARGS, ""},
    {"get_Raster", (PyCFunction)IRasterSdeConnection2Method_get_Raster, METH_VARARGS, ""},
    {"putref_Raster", (PyCFunction)IRasterSdeConnection2Method_putref_Raster, METH_VARARGS, ""},
    {"get_MaskRaster", (PyCFunction)IRasterSdeConnection2Method_get_MaskRaster, METH_VARARGS, ""},
    {"putref_MaskRaster", (PyCFunction)IRasterSdeConnection2Method_putref_MaskRaster, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIRasterSdeConnection2GetSet[] = {
  {"_pUnk", (getter)PyIRasterSdeConnection2_GetpUnk, NULL, "Get opaque pointer to an Unknown from IRasterSdeConnection2", NULL},
  {"_pointer", (getter)PyIRasterSdeConnection2_GetPointer, NULL, "Get memory address for IRasterSdeConnection2", NULL},
  {"_IID", (getter)PyIRasterSdeConnection2_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIRasterSdeConnection2_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIRasterSdeConnection2_GetIgnoreFailures, (setter)PyIRasterSdeConnection2_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIRasterSdeConnection2Object_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesRasterUI.IRasterSdeConnection2Object",                          
                                              /* tp_name */
  sizeof(PyIRasterSdeConnection2Object),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIRasterSdeConnection2Object_dealloc,      
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
  PyIRasterSdeConnection2Methods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIRasterSdeConnection2GetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIRasterSdeConnection2Object_new,                      
                                              /* tp_new */
};





static PyObject*
CoCreateCreateRasterDatasetDlg(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_CreateRasterDatasetDlg, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of CreateRasterDatasetDlg");
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
            // clsid_key_lookup = uuid.UUID("6956b489-197d-4b3b-ae85-9b5a4aef7c62")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "6956b489-197d-4b3b-ae85-9b5a4aef7c62");
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
CoCreateRasterSdeLoader(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_RasterSdeLoader, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of RasterSdeLoader");
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
            // clsid_key_lookup = uuid.UUID("cc17adc2-fe14-11d3-b2bf-00c04f8edeff")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "cc17adc2-fe14-11d3-b2bf-00c04f8edeff");
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



static PyMethodDef _esriDataSourcesRasterUIMethods[] = {
    {"CreateRasterDatasetDlg", (PyCFunction)CoCreateCreateRasterDatasetDlg, METH_NOARGS,
     "Create instance of CreateRasterDatasetDlg\n"},
    {"RasterSdeLoader", (PyCFunction)CoCreateRasterSdeLoader, METH_NOARGS,
     "Create instance of RasterSdeLoader\n"},
    {NULL, NULL, 0, NULL}
};

extern "C" {

    PyMODINIT_FUNC
    init_esriDataSourcesRasterUI(void)
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
        module = Py_InitModule3("cartocomutils._esriDataSourcesRasterUI",
                                 _esriDataSourcesRasterUIMethods,
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
        // IRasterSdeConnection
        PyType_Ready(&PyIRasterSdeConnectionObject_Type);
        Py_INCREF((PyObject* )&PyIRasterSdeConnectionObject_Type);
        PyModule_AddObject(module, "IRasterSdeConnection", 
                           (PyObject *)&PyIRasterSdeConnectionObject_Type);

        // IRasterSdeConnection2
        PyType_Ready(&PyIRasterSdeConnection2Object_Type);
        Py_INCREF((PyObject* )&PyIRasterSdeConnection2Object_Type);
        PyModule_AddObject(module, "IRasterSdeConnection2", 
                           (PyObject *)&PyIRasterSdeConnection2Object_Type);


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
