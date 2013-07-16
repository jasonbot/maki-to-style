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




// Interface IProtectNamesDataSourcesNetCDF

typedef struct PyIProtectNamesDataSourcesNetCDFObject {
    PyObject_HEAD
    IProtectNamesDataSourcesNetCDF* m_pIProtectNamesDataSourcesNetCDF;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIProtectNamesDataSourcesNetCDFObject;

static PyObject*
PyIProtectNamesDataSourcesNetCDFObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIProtectNamesDataSourcesNetCDFObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IProtectNamesDataSourcesNetCDF* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IProtectNamesDataSourcesNetCDF, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IProtectNamesDataSourcesNetCDF with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIProtectNamesDataSourcesNetCDFObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IProtectNamesDataSourcesNetCDF");
            return NULL;
        }
        self->m_pIProtectNamesDataSourcesNetCDF = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IProtectNamesDataSourcesNetCDF");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IProtectNamesDataSourcesNetCDF");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IProtectNamesDataSourcesNetCDF* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IProtectNamesDataSourcesNetCDF, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IProtectNamesDataSourcesNetCDF");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIProtectNamesDataSourcesNetCDFObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IProtectNamesDataSourcesNetCDF");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIProtectNamesDataSourcesNetCDF = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIProtectNamesDataSourcesNetCDFObject_dealloc(PyIProtectNamesDataSourcesNetCDFObject* self)
{
    if (self->m_pIProtectNamesDataSourcesNetCDF)
        self->m_pIProtectNamesDataSourcesNetCDF->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIProtectNamesDataSourcesNetCDF_GetpUnk(PyIProtectNamesDataSourcesNetCDFObject* self)
{
    if (!self->m_pIProtectNamesDataSourcesNetCDF)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIProtectNamesDataSourcesNetCDF->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IProtectNamesDataSourcesNetCDF to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIProtectNamesDataSourcesNetCDF_GetPointer(PyIProtectNamesDataSourcesNetCDFObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIProtectNamesDataSourcesNetCDF);
}

static PyObject*
PyIProtectNamesDataSourcesNetCDF_GetIID(PyIProtectNamesDataSourcesNetCDFObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "00e0f03e-d94d-4cb0-a711-7f7c59c51196");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIProtectNamesDataSourcesNetCDF_GetHR(PyIProtectNamesDataSourcesNetCDFObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIProtectNamesDataSourcesNetCDF_GetIgnoreFailures(PyIProtectNamesDataSourcesNetCDFObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIProtectNamesDataSourcesNetCDF_SetIgnoreFailures(PyIProtectNamesDataSourcesNetCDFObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIProtectNamesDataSourcesNetCDF_SupportsInterface(PyIProtectNamesDataSourcesNetCDFObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIProtectNamesDataSourcesNetCDF->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IProtectNamesDataSourcesNetCDFMethod_Variable(PyIProtectNamesDataSourcesNetCDFObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIProtectNamesDataSourcesNetCDF->Variable();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIProtectNamesDataSourcesNetCDF->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IProtectNamesDataSourcesNetCDF) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IProtectNamesDataSourcesNetCDF.Variable() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}


PyMethodDef PyIProtectNamesDataSourcesNetCDFMethods[] = {
    {"supports", (PyCFunction)PyIProtectNamesDataSourcesNetCDF_SupportsInterface, METH_O, ""},
    {"Variable", (PyCFunction)IProtectNamesDataSourcesNetCDFMethod_Variable, METH_NOARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIProtectNamesDataSourcesNetCDFGetSet[] = {
  {"_pUnk", (getter)PyIProtectNamesDataSourcesNetCDF_GetpUnk, NULL, "Get opaque pointer to an Unknown from IProtectNamesDataSourcesNetCDF", NULL},
  {"_pointer", (getter)PyIProtectNamesDataSourcesNetCDF_GetPointer, NULL, "Get memory address for IProtectNamesDataSourcesNetCDF", NULL},
  {"_IID", (getter)PyIProtectNamesDataSourcesNetCDF_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIProtectNamesDataSourcesNetCDF_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIProtectNamesDataSourcesNetCDF_GetIgnoreFailures, (setter)PyIProtectNamesDataSourcesNetCDF_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIProtectNamesDataSourcesNetCDFObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesNetCDF.IProtectNamesDataSourcesNetCDFObject",                          
                                              /* tp_name */
  sizeof(PyIProtectNamesDataSourcesNetCDFObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIProtectNamesDataSourcesNetCDFObject_dealloc,      
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
  PyIProtectNamesDataSourcesNetCDFMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIProtectNamesDataSourcesNetCDFGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIProtectNamesDataSourcesNetCDFObject_new,                      
                                              /* tp_new */
};

// Interface IMDDatasetView

typedef struct PyIMDDatasetViewObject {
    PyObject_HEAD
    IMDDatasetView* m_pIMDDatasetView;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIMDDatasetViewObject;

static PyObject*
PyIMDDatasetViewObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIMDDatasetViewObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IMDDatasetView* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IMDDatasetView, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IMDDatasetView with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIMDDatasetViewObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDDatasetView");
            return NULL;
        }
        self->m_pIMDDatasetView = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IMDDatasetView");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IMDDatasetView");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IMDDatasetView* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IMDDatasetView, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IMDDatasetView");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIMDDatasetViewObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDDatasetView");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIMDDatasetView = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIMDDatasetViewObject_dealloc(PyIMDDatasetViewObject* self)
{
    if (self->m_pIMDDatasetView)
        self->m_pIMDDatasetView->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIMDDatasetView_GetpUnk(PyIMDDatasetViewObject* self)
{
    if (!self->m_pIMDDatasetView)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIMDDatasetView->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IMDDatasetView to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIMDDatasetView_GetPointer(PyIMDDatasetViewObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIMDDatasetView);
}

static PyObject*
PyIMDDatasetView_GetIID(PyIMDDatasetViewObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "4656178f-0eda-4446-9d51-900e96efd27c");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIMDDatasetView_GetHR(PyIMDDatasetViewObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIMDDatasetView_GetIgnoreFailures(PyIMDDatasetViewObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIMDDatasetView_SetIgnoreFailures(PyIMDDatasetViewObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIMDDatasetView_SupportsInterface(PyIMDDatasetViewObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IMDDatasetViewMethod_SelectDimensionByValue(PyIMDDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdim = 0;
    PyObject* pyvar_dim;
    PyObject* unicodedim = NULL;
    VARIANT vvValue;
    ::VariantInit(&vvValue);
    PyObject* pyvar_vValue = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OO", &pyvar_dim, &pyvar_vValue))
      goto imddatasetview_selectdimensionbyvalue_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dim))
        unicodedim = PyUnicode_FromObject(pyvar_dim);
    else if (PyUnicode_Check(pyvar_dim))
    {
        unicodedim = pyvar_dim;
        Py_INCREF(unicodedim);
    }
    else if (pyvar_dim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dim at index 0");
    if (unicodedim)
        bsdim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedim));
    
    if (PyErr_Occurred())
      goto imddatasetview_selectdimensionbyvalue_method_cleanup;
    
    PyObject_AsVariant(pyvar_vValue, &vvValue);
    
    if (PyErr_Occurred())
      goto imddatasetview_selectdimensionbyvalue_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDDatasetView->SelectDimensionByValue(bsdim, vvValue);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDDatasetView.SelectDimensionByValue() returned %ld", (long)hr);
        goto imddatasetview_selectdimensionbyvalue_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dim
    // No teardown for vValue

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imddatasetview_selectdimensionbyvalue_method_cleanup;

    imddatasetview_selectdimensionbyvalue_method_cleanup:
    self->m_HR = hr;
    if (bsdim)
        ::SysFreeString(bsdim);
    
    ::VariantClear(&vvValue);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDDatasetView.SelectDimensionByValue");
    return return_tuple;
}

static PyObject*
IMDDatasetViewMethod_SelectDimensionByIndex(PyIMDDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdim = 0;
    PyObject* pyvar_dim;
    PyObject* unicodedim = NULL;
    long lindex = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "Ol", &pyvar_dim, &lindex))
      goto imddatasetview_selectdimensionbyindex_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dim))
        unicodedim = PyUnicode_FromObject(pyvar_dim);
    else if (PyUnicode_Check(pyvar_dim))
    {
        unicodedim = pyvar_dim;
        Py_INCREF(unicodedim);
    }
    else if (pyvar_dim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dim at index 0");
    if (unicodedim)
        bsdim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedim));
    
    if (PyErr_Occurred())
      goto imddatasetview_selectdimensionbyindex_method_cleanup;
    
    // No setup for index

    // Call method on actual COM interface
    hr = self->m_pIMDDatasetView->SelectDimensionByIndex(bsdim, lindex);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDDatasetView.SelectDimensionByIndex() returned %ld", (long)hr);
        goto imddatasetview_selectdimensionbyindex_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dim
    // No teardown for index

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imddatasetview_selectdimensionbyindex_method_cleanup;

    imddatasetview_selectdimensionbyindex_method_cleanup:
    self->m_HR = hr;
    if (bsdim)
        ::SysFreeString(bsdim);
    
    // No cleanup for index
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDDatasetView.SelectDimensionByIndex");
    return return_tuple;
}

static PyObject*
IMDDatasetViewMethod_GetDimensionValue(PyIMDDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdim = 0;
    PyObject* pyvar_dim;
    PyObject* unicodedim = NULL;
    VARIANT vpVal;
    ::VariantInit(&vpVal);
    PyObject* pyvar_pVal = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dim))
      goto imddatasetview_getdimensionvalue_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dim))
        unicodedim = PyUnicode_FromObject(pyvar_dim);
    else if (PyUnicode_Check(pyvar_dim))
    {
        unicodedim = pyvar_dim;
        Py_INCREF(unicodedim);
    }
    else if (pyvar_dim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dim at index 0");
    if (unicodedim)
        bsdim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedim));
    
    if (PyErr_Occurred())
      goto imddatasetview_getdimensionvalue_method_cleanup;
    
    // No setup for pVal

    // Call method on actual COM interface
    hr = self->m_pIMDDatasetView->GetDimensionValue(bsdim, &vpVal);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDDatasetView.GetDimensionValue() returned %ld", (long)hr);
        goto imddatasetview_getdimensionvalue_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dim
    pyvar_pVal = Variant_AsPyObject(&vpVal);
    if (PyErr_Occurred())
      goto imddatasetview_getdimensionvalue_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pVal);
    goto imddatasetview_getdimensionvalue_method_cleanup;

    imddatasetview_getdimensionvalue_method_cleanup:
    self->m_HR = hr;
    if (bsdim)
        ::SysFreeString(bsdim);
    
    ::VariantClear(&vpVal);
    Py_XDECREF(pyvar_pVal);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDDatasetView.GetDimensionValue");
    return return_tuple;
}

static PyObject*
IMDDatasetViewMethod_GetDimensionIndex(PyIMDDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdim = 0;
    PyObject* pyvar_dim;
    PyObject* unicodedim = NULL;
    long lpVal = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dim))
      goto imddatasetview_getdimensionindex_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dim))
        unicodedim = PyUnicode_FromObject(pyvar_dim);
    else if (PyUnicode_Check(pyvar_dim))
    {
        unicodedim = pyvar_dim;
        Py_INCREF(unicodedim);
    }
    else if (pyvar_dim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dim at index 0");
    if (unicodedim)
        bsdim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedim));
    
    if (PyErr_Occurred())
      goto imddatasetview_getdimensionindex_method_cleanup;
    
    // No setup for pVal

    // Call method on actual COM interface
    hr = self->m_pIMDDatasetView->GetDimensionIndex(bsdim, &lpVal);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDDatasetView.GetDimensionIndex() returned %ld", (long)hr);
        goto imddatasetview_getdimensionindex_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dim
    // No teardown for pVal

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lpVal);
    goto imddatasetview_getdimensionindex_method_cleanup;

    imddatasetview_getdimensionindex_method_cleanup:
    self->m_HR = hr;
    if (bsdim)
        ::SysFreeString(bsdim);
    
    // No cleanup for pVal
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDDatasetView.GetDimensionIndex");
    return return_tuple;
}

static PyObject*
IMDDatasetViewMethod_GetSelectedDimensions(PyIMDDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppNames = NULL;
    PyObject* py_ppNames = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppNames

    // Call method on actual COM interface
    hr = self->m_pIMDDatasetView->GetSelectedDimensions(&ipppNames);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDDatasetView.GetSelectedDimensions() returned %ld", (long)hr);
        goto imddatasetview_getselecteddimensions_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppNames);
    if (ipppNames)
    {
        IUnknown* pUnk = NULL;
        ipppNames->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppNames = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
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
      goto imddatasetview_getselecteddimensions_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppNames);
    goto imddatasetview_getselecteddimensions_method_cleanup;

    imddatasetview_getselecteddimensions_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppNames);
    if (ipppNames)
      ipppNames->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDDatasetView.GetSelectedDimensions");
    return return_tuple;
}

static PyObject*
IMDDatasetViewMethod_GetSelectedDimensionValues(PyIMDDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IVariantArray* ipppValues = NULL;
    PyObject* py_ppValues = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppValues

    // Call method on actual COM interface
    hr = self->m_pIMDDatasetView->GetSelectedDimensionValues(&ipppValues);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDDatasetView.GetSelectedDimensionValues() returned %ld", (long)hr);
        goto imddatasetview_getselecteddimensionvalues_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppValues);
    if (ipppValues)
    {
        IUnknown* pUnk = NULL;
        ipppValues->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppValues = IUnknownToPythonIIDObject(pUnk, &IID_IVariantArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppValues)
    {
        if (py_ppValues)
           Py_DECREF(py_ppValues);
        py_ppValues = Py_None;
        Py_INCREF(py_ppValues);
    }
    if (PyErr_Occurred())
      goto imddatasetview_getselecteddimensionvalues_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppValues);
    goto imddatasetview_getselecteddimensionvalues_method_cleanup;

    imddatasetview_getselecteddimensionvalues_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppValues);
    if (ipppValues)
      ipppValues->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDDatasetView.GetSelectedDimensionValues");
    return return_tuple;
}

static PyObject*
IMDDatasetViewMethod_GetSelectedDimensionIndices(PyIMDDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    ILongArray* ipppIndices = NULL;
    PyObject* py_ppIndices = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppIndices

    // Call method on actual COM interface
    hr = self->m_pIMDDatasetView->GetSelectedDimensionIndices(&ipppIndices);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDDatasetView.GetSelectedDimensionIndices() returned %ld", (long)hr);
        goto imddatasetview_getselecteddimensionindices_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppIndices);
    if (ipppIndices)
    {
        IUnknown* pUnk = NULL;
        ipppIndices->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppIndices = IUnknownToPythonIIDObject(pUnk, &IID_ILongArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppIndices)
    {
        if (py_ppIndices)
           Py_DECREF(py_ppIndices);
        py_ppIndices = Py_None;
        Py_INCREF(py_ppIndices);
    }
    if (PyErr_Occurred())
      goto imddatasetview_getselecteddimensionindices_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppIndices);
    goto imddatasetview_getselecteddimensionindices_method_cleanup;

    imddatasetview_getselecteddimensionindices_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppIndices);
    if (ipppIndices)
      ipppIndices->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDDatasetView.GetSelectedDimensionIndices");
    return return_tuple;
}

static PyObject*
IMDDatasetViewMethod_ClearSelectedDimensions(PyIMDDatasetViewObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIMDDatasetView->ClearSelectedDimensions();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDDatasetView.ClearSelectedDimensions() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IMDDatasetViewMethod_GetDimensions(PyIMDDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppDims = NULL;
    PyObject* py_ppDims = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppDims

    // Call method on actual COM interface
    hr = self->m_pIMDDatasetView->GetDimensions(&ipppDims);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDDatasetView.GetDimensions() returned %ld", (long)hr);
        goto imddatasetview_getdimensions_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppDims);
    if (ipppDims)
    {
        IUnknown* pUnk = NULL;
        ipppDims->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppDims = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppDims)
    {
        if (py_ppDims)
           Py_DECREF(py_ppDims);
        py_ppDims = Py_None;
        Py_INCREF(py_ppDims);
    }
    if (PyErr_Occurred())
      goto imddatasetview_getdimensions_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppDims);
    goto imddatasetview_getdimensions_method_cleanup;

    imddatasetview_getdimensions_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppDims);
    if (ipppDims)
      ipppDims->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDDatasetView.GetDimensions");
    return return_tuple;
}


PyMethodDef PyIMDDatasetViewMethods[] = {
    {"supports", (PyCFunction)PyIMDDatasetView_SupportsInterface, METH_O, ""},
    {"SelectDimensionByValue", (PyCFunction)IMDDatasetViewMethod_SelectDimensionByValue, METH_VARARGS, ""},
    {"SelectDimensionByIndex", (PyCFunction)IMDDatasetViewMethod_SelectDimensionByIndex, METH_VARARGS, ""},
    {"GetDimensionValue", (PyCFunction)IMDDatasetViewMethod_GetDimensionValue, METH_VARARGS, ""},
    {"GetDimensionIndex", (PyCFunction)IMDDatasetViewMethod_GetDimensionIndex, METH_VARARGS, ""},
    {"GetSelectedDimensions", (PyCFunction)IMDDatasetViewMethod_GetSelectedDimensions, METH_VARARGS, ""},
    {"GetSelectedDimensionValues", (PyCFunction)IMDDatasetViewMethod_GetSelectedDimensionValues, METH_VARARGS, ""},
    {"GetSelectedDimensionIndices", (PyCFunction)IMDDatasetViewMethod_GetSelectedDimensionIndices, METH_VARARGS, ""},
    {"ClearSelectedDimensions", (PyCFunction)IMDDatasetViewMethod_ClearSelectedDimensions, METH_NOARGS, ""},
    {"GetDimensions", (PyCFunction)IMDDatasetViewMethod_GetDimensions, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIMDDatasetViewGetSet[] = {
  {"_pUnk", (getter)PyIMDDatasetView_GetpUnk, NULL, "Get opaque pointer to an Unknown from IMDDatasetView", NULL},
  {"_pointer", (getter)PyIMDDatasetView_GetPointer, NULL, "Get memory address for IMDDatasetView", NULL},
  {"_IID", (getter)PyIMDDatasetView_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIMDDatasetView_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIMDDatasetView_GetIgnoreFailures, (setter)PyIMDDatasetView_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIMDDatasetViewObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesNetCDF.IMDDatasetViewObject",                          
                                              /* tp_name */
  sizeof(PyIMDDatasetViewObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIMDDatasetViewObject_dealloc,      
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
  PyIMDDatasetViewMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIMDDatasetViewGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIMDDatasetViewObject_new,                      
                                              /* tp_new */
};

// Interface IMDWorkspace

typedef struct PyIMDWorkspaceObject {
    PyObject_HEAD
    IMDWorkspace* m_pIMDWorkspace;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIMDWorkspaceObject;

static PyObject*
PyIMDWorkspaceObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIMDWorkspaceObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IMDWorkspace* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IMDWorkspace, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IMDWorkspace with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIMDWorkspaceObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDWorkspace");
            return NULL;
        }
        self->m_pIMDWorkspace = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IMDWorkspace");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IMDWorkspace");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IMDWorkspace* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IMDWorkspace, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IMDWorkspace");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIMDWorkspaceObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDWorkspace");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIMDWorkspace = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIMDWorkspaceObject_dealloc(PyIMDWorkspaceObject* self)
{
    if (self->m_pIMDWorkspace)
        self->m_pIMDWorkspace->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIMDWorkspace_GetpUnk(PyIMDWorkspaceObject* self)
{
    if (!self->m_pIMDWorkspace)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIMDWorkspace->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IMDWorkspace to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIMDWorkspace_GetPointer(PyIMDWorkspaceObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIMDWorkspace);
}

static PyObject*
PyIMDWorkspace_GetIID(PyIMDWorkspaceObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "88b7b494-1c1d-4b6c-a1db-28900afa96ec");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIMDWorkspace_GetHR(PyIMDWorkspaceObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIMDWorkspace_GetIgnoreFailures(PyIMDWorkspaceObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIMDWorkspace_SetIgnoreFailures(PyIMDWorkspaceObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIMDWorkspace_SupportsInterface(PyIMDWorkspaceObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIMDWorkspace->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IMDWorkspaceMethod_CreateView(PyIMDWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsviewName = 0;
    PyObject* pyvar_viewName;
    PyObject* unicodeviewName = NULL;
    IMDDatasetView* ippView = NULL;
    PyObject* py_pView;
    IDataset* ipppOut = NULL;
    PyObject* py_ppOut = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OO", &pyvar_viewName, &py_pView))
      goto imdworkspace_createview_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_viewName))
        unicodeviewName = PyUnicode_FromObject(pyvar_viewName);
    else if (PyUnicode_Check(pyvar_viewName))
    {
        unicodeviewName = pyvar_viewName;
        Py_INCREF(unicodeviewName);
    }
    else if (pyvar_viewName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter viewName at index 0");
    if (unicodeviewName)
        bsviewName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeviewName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeviewName));
    
    if (PyErr_Occurred())
      goto imdworkspace_createview_method_cleanup;
    
    if (!IFaceFromPyObject(py_pView, &IID_IMDDatasetView, (void**)&ippView))
        PyErr_SetString(PyExc_TypeError, "Argument pView (position 1) is not IMDDatasetView");
    
    if (PyErr_Occurred())
      goto imdworkspace_createview_method_cleanup;
    
    // No setup for ppOut

    // Call method on actual COM interface
    hr = self->m_pIMDWorkspace->CreateView(bsviewName, ippView, &ipppOut);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDWorkspace.CreateView() returned %ld", (long)hr);
        goto imdworkspace_createview_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for viewName
    // No teardown for pView
    Py_XDECREF(py_ppOut);
    if (ipppOut)
    {
        IUnknown* pUnk = NULL;
        ipppOut->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppOut = IUnknownToPythonIIDObject(pUnk, &IID_IDataset);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppOut)
    {
        if (py_ppOut)
           Py_DECREF(py_ppOut);
        py_ppOut = Py_None;
        Py_INCREF(py_ppOut);
    }
    if (PyErr_Occurred())
      goto imdworkspace_createview_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppOut);
    goto imdworkspace_createview_method_cleanup;

    imdworkspace_createview_method_cleanup:
    self->m_HR = hr;
    if (bsviewName)
        ::SysFreeString(bsviewName);
    
    if (ippView)
      ippView->Release();
    Py_XDECREF(py_ppOut);
    if (ipppOut)
      ipppOut->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDWorkspace.CreateView");
    return return_tuple;
}


PyMethodDef PyIMDWorkspaceMethods[] = {
    {"supports", (PyCFunction)PyIMDWorkspace_SupportsInterface, METH_O, ""},
    {"CreateView", (PyCFunction)IMDWorkspaceMethod_CreateView, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIMDWorkspaceGetSet[] = {
  {"_pUnk", (getter)PyIMDWorkspace_GetpUnk, NULL, "Get opaque pointer to an Unknown from IMDWorkspace", NULL},
  {"_pointer", (getter)PyIMDWorkspace_GetPointer, NULL, "Get memory address for IMDWorkspace", NULL},
  {"_IID", (getter)PyIMDWorkspace_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIMDWorkspace_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIMDWorkspace_GetIgnoreFailures, (setter)PyIMDWorkspace_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIMDWorkspaceObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesNetCDF.IMDWorkspaceObject",                          
                                              /* tp_name */
  sizeof(PyIMDWorkspaceObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIMDWorkspaceObject_dealloc,      
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
  PyIMDWorkspaceMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIMDWorkspaceGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIMDWorkspaceObject_new,                      
                                              /* tp_new */
};

// Interface IMDRasterDatasetView

typedef struct PyIMDRasterDatasetViewObject {
    PyObject_HEAD
    IMDRasterDatasetView* m_pIMDRasterDatasetView;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIMDRasterDatasetViewObject;

static PyObject*
PyIMDRasterDatasetViewObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIMDRasterDatasetViewObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IMDRasterDatasetView* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IMDRasterDatasetView, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IMDRasterDatasetView with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIMDRasterDatasetViewObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDRasterDatasetView");
            return NULL;
        }
        self->m_pIMDRasterDatasetView = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IMDRasterDatasetView");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IMDRasterDatasetView");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IMDRasterDatasetView* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IMDRasterDatasetView, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IMDRasterDatasetView");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIMDRasterDatasetViewObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDRasterDatasetView");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIMDRasterDatasetView = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIMDRasterDatasetViewObject_dealloc(PyIMDRasterDatasetViewObject* self)
{
    if (self->m_pIMDRasterDatasetView)
        self->m_pIMDRasterDatasetView->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIMDRasterDatasetView_GetpUnk(PyIMDRasterDatasetViewObject* self)
{
    if (!self->m_pIMDRasterDatasetView)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIMDRasterDatasetView->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IMDRasterDatasetView to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIMDRasterDatasetView_GetPointer(PyIMDRasterDatasetViewObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIMDRasterDatasetView);
}

static PyObject*
PyIMDRasterDatasetView_GetIID(PyIMDRasterDatasetViewObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "08cebfb9-db3e-433b-bf80-84adf3424fb0");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIMDRasterDatasetView_GetHR(PyIMDRasterDatasetViewObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIMDRasterDatasetView_GetIgnoreFailures(PyIMDRasterDatasetViewObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIMDRasterDatasetView_SetIgnoreFailures(PyIMDRasterDatasetViewObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIMDRasterDatasetView_SupportsInterface(PyIMDRasterDatasetViewObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIMDRasterDatasetView->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IMDRasterDatasetViewMethod_get_XDimension(PyIMDRasterDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspXDim;
    PyObject* pyvar_pXDim = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pXDim

    // Call method on actual COM interface
    hr = self->m_pIMDRasterDatasetView->get_XDimension(&bspXDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDRasterDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDRasterDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDRasterDatasetView.get_XDimension() returned %ld", (long)hr);
        goto imdrasterdatasetview_get_xdimension_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pXDim = PyUnicode_FromWideChar(bspXDim,::SysStringLen(bspXDim));
    ::SysFreeString(bspXDim);
    
    if (PyErr_Occurred())
      goto imdrasterdatasetview_get_xdimension_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pXDim);
    goto imdrasterdatasetview_get_xdimension_method_cleanup;

    imdrasterdatasetview_get_xdimension_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pXDim != Py_None)
        Py_XDECREF(pyvar_pXDim);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDRasterDatasetView.get_XDimension");
    return return_tuple;
}

static PyObject*
IMDRasterDatasetViewMethod_put_XDimension(PyIMDRasterDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspXDim = 0;
    PyObject* pyvar_pXDim;
    PyObject* unicodepXDim = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_pXDim))
      goto imdrasterdatasetview_put_xdimension_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_pXDim))
        unicodepXDim = PyUnicode_FromObject(pyvar_pXDim);
    else if (PyUnicode_Check(pyvar_pXDim))
    {
        unicodepXDim = pyvar_pXDim;
        Py_INCREF(unicodepXDim);
    }
    else if (pyvar_pXDim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter pXDim at index 0");
    if (unicodepXDim)
        bspXDim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodepXDim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodepXDim));
    
    if (PyErr_Occurred())
      goto imdrasterdatasetview_put_xdimension_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDRasterDatasetView->put_XDimension(bspXDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDRasterDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDRasterDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDRasterDatasetView.put_XDimension() returned %ld", (long)hr);
        goto imdrasterdatasetview_put_xdimension_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pXDim

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdrasterdatasetview_put_xdimension_method_cleanup;

    imdrasterdatasetview_put_xdimension_method_cleanup:
    self->m_HR = hr;
    if (bspXDim)
        ::SysFreeString(bspXDim);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDRasterDatasetView.put_XDimension");
    return return_tuple;
}

static PyObject*
IMDRasterDatasetViewMethod_get_YDimension(PyIMDRasterDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspYDim;
    PyObject* pyvar_pYDim = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pYDim

    // Call method on actual COM interface
    hr = self->m_pIMDRasterDatasetView->get_YDimension(&bspYDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDRasterDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDRasterDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDRasterDatasetView.get_YDimension() returned %ld", (long)hr);
        goto imdrasterdatasetview_get_ydimension_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pYDim = PyUnicode_FromWideChar(bspYDim,::SysStringLen(bspYDim));
    ::SysFreeString(bspYDim);
    
    if (PyErr_Occurred())
      goto imdrasterdatasetview_get_ydimension_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pYDim);
    goto imdrasterdatasetview_get_ydimension_method_cleanup;

    imdrasterdatasetview_get_ydimension_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pYDim != Py_None)
        Py_XDECREF(pyvar_pYDim);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDRasterDatasetView.get_YDimension");
    return return_tuple;
}

static PyObject*
IMDRasterDatasetViewMethod_put_YDimension(PyIMDRasterDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspYDim = 0;
    PyObject* pyvar_pYDim;
    PyObject* unicodepYDim = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_pYDim))
      goto imdrasterdatasetview_put_ydimension_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_pYDim))
        unicodepYDim = PyUnicode_FromObject(pyvar_pYDim);
    else if (PyUnicode_Check(pyvar_pYDim))
    {
        unicodepYDim = pyvar_pYDim;
        Py_INCREF(unicodepYDim);
    }
    else if (pyvar_pYDim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter pYDim at index 0");
    if (unicodepYDim)
        bspYDim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodepYDim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodepYDim));
    
    if (PyErr_Occurred())
      goto imdrasterdatasetview_put_ydimension_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDRasterDatasetView->put_YDimension(bspYDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDRasterDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDRasterDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDRasterDatasetView.put_YDimension() returned %ld", (long)hr);
        goto imdrasterdatasetview_put_ydimension_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pYDim

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdrasterdatasetview_put_ydimension_method_cleanup;

    imdrasterdatasetview_put_ydimension_method_cleanup:
    self->m_HR = hr;
    if (bspYDim)
        ::SysFreeString(bspYDim);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDRasterDatasetView.put_YDimension");
    return return_tuple;
}

static PyObject*
IMDRasterDatasetViewMethod_get_BandDimension(PyIMDRasterDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspBandDim;
    PyObject* pyvar_pBandDim = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pBandDim

    // Call method on actual COM interface
    hr = self->m_pIMDRasterDatasetView->get_BandDimension(&bspBandDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDRasterDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDRasterDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDRasterDatasetView.get_BandDimension() returned %ld", (long)hr);
        goto imdrasterdatasetview_get_banddimension_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pBandDim = PyUnicode_FromWideChar(bspBandDim,::SysStringLen(bspBandDim));
    ::SysFreeString(bspBandDim);
    
    if (PyErr_Occurred())
      goto imdrasterdatasetview_get_banddimension_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pBandDim);
    goto imdrasterdatasetview_get_banddimension_method_cleanup;

    imdrasterdatasetview_get_banddimension_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pBandDim != Py_None)
        Py_XDECREF(pyvar_pBandDim);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDRasterDatasetView.get_BandDimension");
    return return_tuple;
}

static PyObject*
IMDRasterDatasetViewMethod_put_BandDimension(PyIMDRasterDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspBandDim = 0;
    PyObject* pyvar_pBandDim;
    PyObject* unicodepBandDim = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_pBandDim))
      goto imdrasterdatasetview_put_banddimension_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_pBandDim))
        unicodepBandDim = PyUnicode_FromObject(pyvar_pBandDim);
    else if (PyUnicode_Check(pyvar_pBandDim))
    {
        unicodepBandDim = pyvar_pBandDim;
        Py_INCREF(unicodepBandDim);
    }
    else if (pyvar_pBandDim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter pBandDim at index 0");
    if (unicodepBandDim)
        bspBandDim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodepBandDim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodepBandDim));
    
    if (PyErr_Occurred())
      goto imdrasterdatasetview_put_banddimension_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDRasterDatasetView->put_BandDimension(bspBandDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDRasterDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDRasterDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDRasterDatasetView.put_BandDimension() returned %ld", (long)hr);
        goto imdrasterdatasetview_put_banddimension_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pBandDim

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdrasterdatasetview_put_banddimension_method_cleanup;

    imdrasterdatasetview_put_banddimension_method_cleanup:
    self->m_HR = hr;
    if (bspBandDim)
        ::SysFreeString(bspBandDim);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDRasterDatasetView.put_BandDimension");
    return return_tuple;
}

static PyObject*
IMDRasterDatasetViewMethod_get_Variable(PyIMDRasterDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspVar;
    PyObject* pyvar_pVar = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pVar

    // Call method on actual COM interface
    hr = self->m_pIMDRasterDatasetView->get_Variable(&bspVar);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDRasterDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDRasterDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDRasterDatasetView.get_Variable() returned %ld", (long)hr);
        goto imdrasterdatasetview_get_variable_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pVar = PyUnicode_FromWideChar(bspVar,::SysStringLen(bspVar));
    ::SysFreeString(bspVar);
    
    if (PyErr_Occurred())
      goto imdrasterdatasetview_get_variable_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pVar);
    goto imdrasterdatasetview_get_variable_method_cleanup;

    imdrasterdatasetview_get_variable_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pVar != Py_None)
        Py_XDECREF(pyvar_pVar);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDRasterDatasetView.get_Variable");
    return return_tuple;
}

static PyObject*
IMDRasterDatasetViewMethod_put_Variable(PyIMDRasterDatasetViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspVar = 0;
    PyObject* pyvar_pVar;
    PyObject* unicodepVar = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_pVar))
      goto imdrasterdatasetview_put_variable_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_pVar))
        unicodepVar = PyUnicode_FromObject(pyvar_pVar);
    else if (PyUnicode_Check(pyvar_pVar))
    {
        unicodepVar = pyvar_pVar;
        Py_INCREF(unicodepVar);
    }
    else if (pyvar_pVar != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter pVar at index 0");
    if (unicodepVar)
        bspVar = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodepVar), 
                                            (UINT)PyUnicode_GET_SIZE(unicodepVar));
    
    if (PyErr_Occurred())
      goto imdrasterdatasetview_put_variable_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDRasterDatasetView->put_Variable(bspVar);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDRasterDatasetView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDRasterDatasetView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDRasterDatasetView.put_Variable() returned %ld", (long)hr);
        goto imdrasterdatasetview_put_variable_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pVar

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdrasterdatasetview_put_variable_method_cleanup;

    imdrasterdatasetview_put_variable_method_cleanup:
    self->m_HR = hr;
    if (bspVar)
        ::SysFreeString(bspVar);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDRasterDatasetView.put_Variable");
    return return_tuple;
}


PyMethodDef PyIMDRasterDatasetViewMethods[] = {
    {"supports", (PyCFunction)PyIMDRasterDatasetView_SupportsInterface, METH_O, ""},
    {"get_XDimension", (PyCFunction)IMDRasterDatasetViewMethod_get_XDimension, METH_VARARGS, ""},
    {"put_XDimension", (PyCFunction)IMDRasterDatasetViewMethod_put_XDimension, METH_VARARGS, ""},
    {"get_YDimension", (PyCFunction)IMDRasterDatasetViewMethod_get_YDimension, METH_VARARGS, ""},
    {"put_YDimension", (PyCFunction)IMDRasterDatasetViewMethod_put_YDimension, METH_VARARGS, ""},
    {"get_BandDimension", (PyCFunction)IMDRasterDatasetViewMethod_get_BandDimension, METH_VARARGS, ""},
    {"put_BandDimension", (PyCFunction)IMDRasterDatasetViewMethod_put_BandDimension, METH_VARARGS, ""},
    {"get_Variable", (PyCFunction)IMDRasterDatasetViewMethod_get_Variable, METH_VARARGS, ""},
    {"put_Variable", (PyCFunction)IMDRasterDatasetViewMethod_put_Variable, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIMDRasterDatasetViewGetSet[] = {
  {"_pUnk", (getter)PyIMDRasterDatasetView_GetpUnk, NULL, "Get opaque pointer to an Unknown from IMDRasterDatasetView", NULL},
  {"_pointer", (getter)PyIMDRasterDatasetView_GetPointer, NULL, "Get memory address for IMDRasterDatasetView", NULL},
  {"_IID", (getter)PyIMDRasterDatasetView_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIMDRasterDatasetView_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIMDRasterDatasetView_GetIgnoreFailures, (setter)PyIMDRasterDatasetView_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIMDRasterDatasetViewObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesNetCDF.IMDRasterDatasetViewObject",                          
                                              /* tp_name */
  sizeof(PyIMDRasterDatasetViewObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIMDRasterDatasetViewObject_dealloc,      
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
  PyIMDRasterDatasetViewMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIMDRasterDatasetViewGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIMDRasterDatasetViewObject_new,                      
                                              /* tp_new */
};

// Interface IMDTableView

typedef struct PyIMDTableViewObject {
    PyObject_HEAD
    IMDTableView* m_pIMDTableView;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIMDTableViewObject;

static PyObject*
PyIMDTableViewObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIMDTableViewObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IMDTableView* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IMDTableView, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IMDTableView with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIMDTableViewObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDTableView");
            return NULL;
        }
        self->m_pIMDTableView = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IMDTableView");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IMDTableView");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IMDTableView* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IMDTableView, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IMDTableView");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIMDTableViewObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDTableView");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIMDTableView = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIMDTableViewObject_dealloc(PyIMDTableViewObject* self)
{
    if (self->m_pIMDTableView)
        self->m_pIMDTableView->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIMDTableView_GetpUnk(PyIMDTableViewObject* self)
{
    if (!self->m_pIMDTableView)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIMDTableView->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IMDTableView to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIMDTableView_GetPointer(PyIMDTableViewObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIMDTableView);
}

static PyObject*
PyIMDTableView_GetIID(PyIMDTableViewObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "6c4f3247-039e-4d7b-a815-df16a04b9827");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIMDTableView_GetHR(PyIMDTableViewObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIMDTableView_GetIgnoreFailures(PyIMDTableViewObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIMDTableView_SetIgnoreFailures(PyIMDTableViewObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIMDTableView_SupportsInterface(PyIMDTableViewObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIMDTableView->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IMDTableViewMethod_get_VariableList(PyIMDTableViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppVars = NULL;
    PyObject* py_ppVars = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppVars

    // Call method on actual COM interface
    hr = self->m_pIMDTableView->get_VariableList(&ipppVars);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDTableView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDTableView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDTableView.get_VariableList() returned %ld", (long)hr);
        goto imdtableview_get_variablelist_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppVars);
    if (ipppVars)
    {
        IUnknown* pUnk = NULL;
        ipppVars->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppVars = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppVars)
    {
        if (py_ppVars)
           Py_DECREF(py_ppVars);
        py_ppVars = Py_None;
        Py_INCREF(py_ppVars);
    }
    if (PyErr_Occurred())
      goto imdtableview_get_variablelist_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppVars);
    goto imdtableview_get_variablelist_method_cleanup;

    imdtableview_get_variablelist_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppVars);
    if (ipppVars)
      ipppVars->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDTableView.get_VariableList");
    return return_tuple;
}

static PyObject*
IMDTableViewMethod_put_VariableList(PyIMDTableViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppVars = NULL;
    PyObject* py_ppVars;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_ppVars))
      goto imdtableview_put_variablelist_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_ppVars, &IID_IStringArray, (void**)&ipppVars))
        PyErr_SetString(PyExc_TypeError, "Argument ppVars (position 0) is not IStringArray");
    
    if (PyErr_Occurred())
      goto imdtableview_put_variablelist_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDTableView->put_VariableList(ipppVars);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDTableView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDTableView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDTableView.put_VariableList() returned %ld", (long)hr);
        goto imdtableview_put_variablelist_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for ppVars

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdtableview_put_variablelist_method_cleanup;

    imdtableview_put_variablelist_method_cleanup:
    self->m_HR = hr;
    if (ipppVars)
      ipppVars->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDTableView.put_VariableList");
    return return_tuple;
}

static PyObject*
IMDTableViewMethod_get_DimensionList(PyIMDTableViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppDims = NULL;
    PyObject* py_ppDims = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppDims

    // Call method on actual COM interface
    hr = self->m_pIMDTableView->get_DimensionList(&ipppDims);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDTableView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDTableView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDTableView.get_DimensionList() returned %ld", (long)hr);
        goto imdtableview_get_dimensionlist_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppDims);
    if (ipppDims)
    {
        IUnknown* pUnk = NULL;
        ipppDims->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppDims = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppDims)
    {
        if (py_ppDims)
           Py_DECREF(py_ppDims);
        py_ppDims = Py_None;
        Py_INCREF(py_ppDims);
    }
    if (PyErr_Occurred())
      goto imdtableview_get_dimensionlist_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppDims);
    goto imdtableview_get_dimensionlist_method_cleanup;

    imdtableview_get_dimensionlist_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppDims);
    if (ipppDims)
      ipppDims->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDTableView.get_DimensionList");
    return return_tuple;
}

static PyObject*
IMDTableViewMethod_put_DimensionList(PyIMDTableViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppDims = NULL;
    PyObject* py_ppDims;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_ppDims))
      goto imdtableview_put_dimensionlist_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_ppDims, &IID_IStringArray, (void**)&ipppDims))
        PyErr_SetString(PyExc_TypeError, "Argument ppDims (position 0) is not IStringArray");
    
    if (PyErr_Occurred())
      goto imdtableview_put_dimensionlist_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDTableView->put_DimensionList(ipppDims);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDTableView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDTableView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDTableView.put_DimensionList() returned %ld", (long)hr);
        goto imdtableview_put_dimensionlist_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for ppDims

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdtableview_put_dimensionlist_method_cleanup;

    imdtableview_put_dimensionlist_method_cleanup:
    self->m_HR = hr;
    if (ipppDims)
      ipppDims->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDTableView.put_DimensionList");
    return return_tuple;
}


PyMethodDef PyIMDTableViewMethods[] = {
    {"supports", (PyCFunction)PyIMDTableView_SupportsInterface, METH_O, ""},
    {"get_VariableList", (PyCFunction)IMDTableViewMethod_get_VariableList, METH_VARARGS, ""},
    {"put_VariableList", (PyCFunction)IMDTableViewMethod_put_VariableList, METH_VARARGS, ""},
    {"get_DimensionList", (PyCFunction)IMDTableViewMethod_get_DimensionList, METH_VARARGS, ""},
    {"put_DimensionList", (PyCFunction)IMDTableViewMethod_put_DimensionList, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIMDTableViewGetSet[] = {
  {"_pUnk", (getter)PyIMDTableView_GetpUnk, NULL, "Get opaque pointer to an Unknown from IMDTableView", NULL},
  {"_pointer", (getter)PyIMDTableView_GetPointer, NULL, "Get memory address for IMDTableView", NULL},
  {"_IID", (getter)PyIMDTableView_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIMDTableView_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIMDTableView_GetIgnoreFailures, (setter)PyIMDTableView_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIMDTableViewObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesNetCDF.IMDTableViewObject",                          
                                              /* tp_name */
  sizeof(PyIMDTableViewObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIMDTableViewObject_dealloc,      
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
  PyIMDTableViewMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIMDTableViewGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIMDTableViewObject_new,                      
                                              /* tp_new */
};

// Interface IMDFeatureClassView

typedef struct PyIMDFeatureClassViewObject {
    PyObject_HEAD
    IMDFeatureClassView* m_pIMDFeatureClassView;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIMDFeatureClassViewObject;

static PyObject*
PyIMDFeatureClassViewObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIMDFeatureClassViewObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IMDFeatureClassView* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IMDFeatureClassView, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IMDFeatureClassView with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIMDFeatureClassViewObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDFeatureClassView");
            return NULL;
        }
        self->m_pIMDFeatureClassView = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IMDFeatureClassView");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IMDFeatureClassView");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IMDFeatureClassView* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IMDFeatureClassView, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IMDFeatureClassView");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIMDFeatureClassViewObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IMDFeatureClassView");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIMDFeatureClassView = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIMDFeatureClassViewObject_dealloc(PyIMDFeatureClassViewObject* self)
{
    if (self->m_pIMDFeatureClassView)
        self->m_pIMDFeatureClassView->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIMDFeatureClassView_GetpUnk(PyIMDFeatureClassViewObject* self)
{
    if (!self->m_pIMDFeatureClassView)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIMDFeatureClassView->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IMDFeatureClassView to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIMDFeatureClassView_GetPointer(PyIMDFeatureClassViewObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIMDFeatureClassView);
}

static PyObject*
PyIMDFeatureClassView_GetIID(PyIMDFeatureClassViewObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "f065307e-3adf-4b57-b59d-4ba1465bb40c");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIMDFeatureClassView_GetHR(PyIMDFeatureClassViewObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIMDFeatureClassView_GetIgnoreFailures(PyIMDFeatureClassViewObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIMDFeatureClassView_SetIgnoreFailures(PyIMDFeatureClassViewObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIMDFeatureClassView_SupportsInterface(PyIMDFeatureClassViewObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IMDFeatureClassViewMethod_get_VariableList(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppVars = NULL;
    PyObject* py_ppVars = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppVars

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->get_VariableList(&ipppVars);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.get_VariableList() returned %ld", (long)hr);
        goto imdfeatureclassview_get_variablelist_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppVars);
    if (ipppVars)
    {
        IUnknown* pUnk = NULL;
        ipppVars->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppVars = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppVars)
    {
        if (py_ppVars)
           Py_DECREF(py_ppVars);
        py_ppVars = Py_None;
        Py_INCREF(py_ppVars);
    }
    if (PyErr_Occurred())
      goto imdfeatureclassview_get_variablelist_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppVars);
    goto imdfeatureclassview_get_variablelist_method_cleanup;

    imdfeatureclassview_get_variablelist_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppVars);
    if (ipppVars)
      ipppVars->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.get_VariableList");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_put_VariableList(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppVars = NULL;
    PyObject* py_ppVars;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_ppVars))
      goto imdfeatureclassview_put_variablelist_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_ppVars, &IID_IStringArray, (void**)&ipppVars))
        PyErr_SetString(PyExc_TypeError, "Argument ppVars (position 0) is not IStringArray");
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_put_variablelist_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->put_VariableList(ipppVars);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.put_VariableList() returned %ld", (long)hr);
        goto imdfeatureclassview_put_variablelist_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for ppVars

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdfeatureclassview_put_variablelist_method_cleanup;

    imdfeatureclassview_put_variablelist_method_cleanup:
    self->m_HR = hr;
    if (ipppVars)
      ipppVars->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.put_VariableList");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_get_XDimension(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspXDim;
    PyObject* pyvar_pXDim = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pXDim

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->get_XDimension(&bspXDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.get_XDimension() returned %ld", (long)hr);
        goto imdfeatureclassview_get_xdimension_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pXDim = PyUnicode_FromWideChar(bspXDim,::SysStringLen(bspXDim));
    ::SysFreeString(bspXDim);
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_get_xdimension_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pXDim);
    goto imdfeatureclassview_get_xdimension_method_cleanup;

    imdfeatureclassview_get_xdimension_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pXDim != Py_None)
        Py_XDECREF(pyvar_pXDim);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.get_XDimension");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_put_XDimension(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspXDim = 0;
    PyObject* pyvar_pXDim;
    PyObject* unicodepXDim = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_pXDim))
      goto imdfeatureclassview_put_xdimension_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_pXDim))
        unicodepXDim = PyUnicode_FromObject(pyvar_pXDim);
    else if (PyUnicode_Check(pyvar_pXDim))
    {
        unicodepXDim = pyvar_pXDim;
        Py_INCREF(unicodepXDim);
    }
    else if (pyvar_pXDim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter pXDim at index 0");
    if (unicodepXDim)
        bspXDim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodepXDim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodepXDim));
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_put_xdimension_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->put_XDimension(bspXDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.put_XDimension() returned %ld", (long)hr);
        goto imdfeatureclassview_put_xdimension_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pXDim

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdfeatureclassview_put_xdimension_method_cleanup;

    imdfeatureclassview_put_xdimension_method_cleanup:
    self->m_HR = hr;
    if (bspXDim)
        ::SysFreeString(bspXDim);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.put_XDimension");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_get_YDimension(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspYDim;
    PyObject* pyvar_pYDim = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pYDim

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->get_YDimension(&bspYDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.get_YDimension() returned %ld", (long)hr);
        goto imdfeatureclassview_get_ydimension_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pYDim = PyUnicode_FromWideChar(bspYDim,::SysStringLen(bspYDim));
    ::SysFreeString(bspYDim);
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_get_ydimension_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pYDim);
    goto imdfeatureclassview_get_ydimension_method_cleanup;

    imdfeatureclassview_get_ydimension_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pYDim != Py_None)
        Py_XDECREF(pyvar_pYDim);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.get_YDimension");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_put_YDimension(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspYDim = 0;
    PyObject* pyvar_pYDim;
    PyObject* unicodepYDim = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_pYDim))
      goto imdfeatureclassview_put_ydimension_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_pYDim))
        unicodepYDim = PyUnicode_FromObject(pyvar_pYDim);
    else if (PyUnicode_Check(pyvar_pYDim))
    {
        unicodepYDim = pyvar_pYDim;
        Py_INCREF(unicodepYDim);
    }
    else if (pyvar_pYDim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter pYDim at index 0");
    if (unicodepYDim)
        bspYDim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodepYDim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodepYDim));
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_put_ydimension_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->put_YDimension(bspYDim);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.put_YDimension() returned %ld", (long)hr);
        goto imdfeatureclassview_put_ydimension_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pYDim

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdfeatureclassview_put_ydimension_method_cleanup;

    imdfeatureclassview_put_ydimension_method_cleanup:
    self->m_HR = hr;
    if (bspYDim)
        ::SysFreeString(bspYDim);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.put_YDimension");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_get_RowDimensionList(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppRowDims = NULL;
    PyObject* py_ppRowDims = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppRowDims

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->get_RowDimensionList(&ipppRowDims);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.get_RowDimensionList() returned %ld", (long)hr);
        goto imdfeatureclassview_get_rowdimensionlist_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppRowDims);
    if (ipppRowDims)
    {
        IUnknown* pUnk = NULL;
        ipppRowDims->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppRowDims = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppRowDims)
    {
        if (py_ppRowDims)
           Py_DECREF(py_ppRowDims);
        py_ppRowDims = Py_None;
        Py_INCREF(py_ppRowDims);
    }
    if (PyErr_Occurred())
      goto imdfeatureclassview_get_rowdimensionlist_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppRowDims);
    goto imdfeatureclassview_get_rowdimensionlist_method_cleanup;

    imdfeatureclassview_get_rowdimensionlist_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppRowDims);
    if (ipppRowDims)
      ipppRowDims->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.get_RowDimensionList");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_put_RowDimensionList(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppRowDims = NULL;
    PyObject* py_ppRowDims;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_ppRowDims))
      goto imdfeatureclassview_put_rowdimensionlist_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_ppRowDims, &IID_IStringArray, (void**)&ipppRowDims))
        PyErr_SetString(PyExc_TypeError, "Argument ppRowDims (position 0) is not IStringArray");
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_put_rowdimensionlist_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->put_RowDimensionList(ipppRowDims);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.put_RowDimensionList() returned %ld", (long)hr);
        goto imdfeatureclassview_put_rowdimensionlist_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for ppRowDims

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdfeatureclassview_put_rowdimensionlist_method_cleanup;

    imdfeatureclassview_put_rowdimensionlist_method_cleanup:
    self->m_HR = hr;
    if (ipppRowDims)
      ipppRowDims->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.put_RowDimensionList");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_get_ZItem(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspZItem;
    PyObject* pyvar_pZItem = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pZItem

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->get_ZItem(&bspZItem);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.get_ZItem() returned %ld", (long)hr);
        goto imdfeatureclassview_get_zitem_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pZItem = PyUnicode_FromWideChar(bspZItem,::SysStringLen(bspZItem));
    ::SysFreeString(bspZItem);
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_get_zitem_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pZItem);
    goto imdfeatureclassview_get_zitem_method_cleanup;

    imdfeatureclassview_get_zitem_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pZItem != Py_None)
        Py_XDECREF(pyvar_pZItem);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.get_ZItem");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_put_ZItem(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspZItem = 0;
    PyObject* pyvar_pZItem;
    PyObject* unicodepZItem = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_pZItem))
      goto imdfeatureclassview_put_zitem_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_pZItem))
        unicodepZItem = PyUnicode_FromObject(pyvar_pZItem);
    else if (PyUnicode_Check(pyvar_pZItem))
    {
        unicodepZItem = pyvar_pZItem;
        Py_INCREF(unicodepZItem);
    }
    else if (pyvar_pZItem != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter pZItem at index 0");
    if (unicodepZItem)
        bspZItem = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodepZItem), 
                                            (UINT)PyUnicode_GET_SIZE(unicodepZItem));
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_put_zitem_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->put_ZItem(bspZItem);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.put_ZItem() returned %ld", (long)hr);
        goto imdfeatureclassview_put_zitem_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pZItem

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdfeatureclassview_put_zitem_method_cleanup;

    imdfeatureclassview_put_zitem_method_cleanup:
    self->m_HR = hr;
    if (bspZItem)
        ::SysFreeString(bspZItem);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.put_ZItem");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_get_MItem(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspMItem;
    PyObject* pyvar_pMItem = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pMItem

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->get_MItem(&bspMItem);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.get_MItem() returned %ld", (long)hr);
        goto imdfeatureclassview_get_mitem_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pMItem = PyUnicode_FromWideChar(bspMItem,::SysStringLen(bspMItem));
    ::SysFreeString(bspMItem);
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_get_mitem_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pMItem);
    goto imdfeatureclassview_get_mitem_method_cleanup;

    imdfeatureclassview_get_mitem_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pMItem != Py_None)
        Py_XDECREF(pyvar_pMItem);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.get_MItem");
    return return_tuple;
}

static PyObject*
IMDFeatureClassViewMethod_put_MItem(PyIMDFeatureClassViewObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspMItem = 0;
    PyObject* pyvar_pMItem;
    PyObject* unicodepMItem = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_pMItem))
      goto imdfeatureclassview_put_mitem_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_pMItem))
        unicodepMItem = PyUnicode_FromObject(pyvar_pMItem);
    else if (PyUnicode_Check(pyvar_pMItem))
    {
        unicodepMItem = pyvar_pMItem;
        Py_INCREF(unicodepMItem);
    }
    else if (pyvar_pMItem != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter pMItem at index 0");
    if (unicodepMItem)
        bspMItem = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodepMItem), 
                                            (UINT)PyUnicode_GET_SIZE(unicodepMItem));
    
    if (PyErr_Occurred())
      goto imdfeatureclassview_put_mitem_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMDFeatureClassView->put_MItem(bspMItem);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMDFeatureClassView->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMDFeatureClassView) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMDFeatureClassView.put_MItem() returned %ld", (long)hr);
        goto imdfeatureclassview_put_mitem_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pMItem

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imdfeatureclassview_put_mitem_method_cleanup;

    imdfeatureclassview_put_mitem_method_cleanup:
    self->m_HR = hr;
    if (bspMItem)
        ::SysFreeString(bspMItem);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMDFeatureClassView.put_MItem");
    return return_tuple;
}


PyMethodDef PyIMDFeatureClassViewMethods[] = {
    {"supports", (PyCFunction)PyIMDFeatureClassView_SupportsInterface, METH_O, ""},
    {"get_VariableList", (PyCFunction)IMDFeatureClassViewMethod_get_VariableList, METH_VARARGS, ""},
    {"put_VariableList", (PyCFunction)IMDFeatureClassViewMethod_put_VariableList, METH_VARARGS, ""},
    {"get_XDimension", (PyCFunction)IMDFeatureClassViewMethod_get_XDimension, METH_VARARGS, ""},
    {"put_XDimension", (PyCFunction)IMDFeatureClassViewMethod_put_XDimension, METH_VARARGS, ""},
    {"get_YDimension", (PyCFunction)IMDFeatureClassViewMethod_get_YDimension, METH_VARARGS, ""},
    {"put_YDimension", (PyCFunction)IMDFeatureClassViewMethod_put_YDimension, METH_VARARGS, ""},
    {"get_RowDimensionList", (PyCFunction)IMDFeatureClassViewMethod_get_RowDimensionList, METH_VARARGS, ""},
    {"put_RowDimensionList", (PyCFunction)IMDFeatureClassViewMethod_put_RowDimensionList, METH_VARARGS, ""},
    {"get_ZItem", (PyCFunction)IMDFeatureClassViewMethod_get_ZItem, METH_VARARGS, ""},
    {"put_ZItem", (PyCFunction)IMDFeatureClassViewMethod_put_ZItem, METH_VARARGS, ""},
    {"get_MItem", (PyCFunction)IMDFeatureClassViewMethod_get_MItem, METH_VARARGS, ""},
    {"put_MItem", (PyCFunction)IMDFeatureClassViewMethod_put_MItem, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIMDFeatureClassViewGetSet[] = {
  {"_pUnk", (getter)PyIMDFeatureClassView_GetpUnk, NULL, "Get opaque pointer to an Unknown from IMDFeatureClassView", NULL},
  {"_pointer", (getter)PyIMDFeatureClassView_GetPointer, NULL, "Get memory address for IMDFeatureClassView", NULL},
  {"_IID", (getter)PyIMDFeatureClassView_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIMDFeatureClassView_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIMDFeatureClassView_GetIgnoreFailures, (setter)PyIMDFeatureClassView_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIMDFeatureClassViewObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesNetCDF.IMDFeatureClassViewObject",                          
                                              /* tp_name */
  sizeof(PyIMDFeatureClassViewObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIMDFeatureClassViewObject_dealloc,      
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
  PyIMDFeatureClassViewMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIMDFeatureClassViewGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIMDFeatureClassViewObject_new,                      
                                              /* tp_new */
};

// Interface INetCDFWorkspace

typedef struct PyINetCDFWorkspaceObject {
    PyObject_HEAD
    INetCDFWorkspace* m_pINetCDFWorkspace;
    HRESULT m_HR;
    int m_ignore_failures;
} PyINetCDFWorkspaceObject;

static PyObject*
PyINetCDFWorkspaceObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyINetCDFWorkspaceObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        INetCDFWorkspace* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_INetCDFWorkspace, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate INetCDFWorkspace with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyINetCDFWorkspaceObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate INetCDFWorkspace");
            return NULL;
        }
        self->m_pINetCDFWorkspace = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for INetCDFWorkspace");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to INetCDFWorkspace");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    INetCDFWorkspace* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_INetCDFWorkspace, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to INetCDFWorkspace");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyINetCDFWorkspaceObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate INetCDFWorkspace");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pINetCDFWorkspace = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyINetCDFWorkspaceObject_dealloc(PyINetCDFWorkspaceObject* self)
{
    if (self->m_pINetCDFWorkspace)
        self->m_pINetCDFWorkspace->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyINetCDFWorkspace_GetpUnk(PyINetCDFWorkspaceObject* self)
{
    if (!self->m_pINetCDFWorkspace)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pINetCDFWorkspace->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI INetCDFWorkspace to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyINetCDFWorkspace_GetPointer(PyINetCDFWorkspaceObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pINetCDFWorkspace);
}

static PyObject*
PyINetCDFWorkspace_GetIID(PyINetCDFWorkspaceObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "2d289ea0-e56e-44e9-bdb7-1bc829222cc3");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyINetCDFWorkspace_GetHR(PyINetCDFWorkspaceObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyINetCDFWorkspace_GetIgnoreFailures(PyINetCDFWorkspaceObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyINetCDFWorkspace_SetIgnoreFailures(PyINetCDFWorkspaceObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyINetCDFWorkspace_SupportsInterface(PyINetCDFWorkspaceObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
INetCDFWorkspaceMethod_GetVariables(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppOut = NULL;
    PyObject* py_ppOut = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppOut

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetVariables(&ipppOut);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetVariables() returned %ld", (long)hr);
        goto inetcdfworkspace_getvariables_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppOut);
    if (ipppOut)
    {
        IUnknown* pUnk = NULL;
        ipppOut->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppOut = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppOut)
    {
        if (py_ppOut)
           Py_DECREF(py_ppOut);
        py_ppOut = Py_None;
        Py_INCREF(py_ppOut);
    }
    if (PyErr_Occurred())
      goto inetcdfworkspace_getvariables_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppOut);
    goto inetcdfworkspace_getvariables_method_cleanup;

    inetcdfworkspace_getvariables_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppOut);
    if (ipppOut)
      ipppOut->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetVariables");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetDimensions(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IStringArray* ipppOut = NULL;
    PyObject* py_ppOut = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppOut

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetDimensions(&ipppOut);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetDimensions() returned %ld", (long)hr);
        goto inetcdfworkspace_getdimensions_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppOut);
    if (ipppOut)
    {
        IUnknown* pUnk = NULL;
        ipppOut->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppOut = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppOut)
    {
        if (py_ppOut)
           Py_DECREF(py_ppOut);
        py_ppOut = Py_None;
        Py_INCREF(py_ppOut);
    }
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensions_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppOut);
    goto inetcdfworkspace_getdimensions_method_cleanup;

    inetcdfworkspace_getdimensions_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppOut);
    if (ipppOut)
      ipppOut->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetDimensions");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetAttributeNames(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsvarName = 0;
    PyObject* pyvar_varName;
    PyObject* unicodevarName = NULL;
    IStringArray* ipppAttNames = NULL;
    PyObject* py_ppAttNames = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_varName))
      goto inetcdfworkspace_getattributenames_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_varName))
        unicodevarName = PyUnicode_FromObject(pyvar_varName);
    else if (PyUnicode_Check(pyvar_varName))
    {
        unicodevarName = pyvar_varName;
        Py_INCREF(unicodevarName);
    }
    else if (pyvar_varName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter varName at index 0");
    if (unicodevarName)
        bsvarName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodevarName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodevarName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getattributenames_method_cleanup;
    
    // No setup for ppAttNames

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetAttributeNames(bsvarName, &ipppAttNames);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetAttributeNames() returned %ld", (long)hr);
        goto inetcdfworkspace_getattributenames_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for varName
    Py_XDECREF(py_ppAttNames);
    if (ipppAttNames)
    {
        IUnknown* pUnk = NULL;
        ipppAttNames->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppAttNames = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppAttNames)
    {
        if (py_ppAttNames)
           Py_DECREF(py_ppAttNames);
        py_ppAttNames = Py_None;
        Py_INCREF(py_ppAttNames);
    }
    if (PyErr_Occurred())
      goto inetcdfworkspace_getattributenames_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppAttNames);
    goto inetcdfworkspace_getattributenames_method_cleanup;

    inetcdfworkspace_getattributenames_method_cleanup:
    self->m_HR = hr;
    if (bsvarName)
        ::SysFreeString(bsvarName);
    
    Py_XDECREF(py_ppAttNames);
    if (ipppAttNames)
      ipppAttNames->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetAttributeNames");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetDimensionSize(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdimName = 0;
    PyObject* pyvar_dimName;
    PyObject* unicodedimName = NULL;
    long ldimSize = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dimName))
      goto inetcdfworkspace_getdimensionsize_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dimName))
        unicodedimName = PyUnicode_FromObject(pyvar_dimName);
    else if (PyUnicode_Check(pyvar_dimName))
    {
        unicodedimName = pyvar_dimName;
        Py_INCREF(unicodedimName);
    }
    else if (pyvar_dimName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dimName at index 0");
    if (unicodedimName)
        bsdimName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedimName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedimName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensionsize_method_cleanup;
    
    // No setup for dimSize

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetDimensionSize(bsdimName, &ldimSize);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetDimensionSize() returned %ld", (long)hr);
        goto inetcdfworkspace_getdimensionsize_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dimName
    // No teardown for dimSize

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            ldimSize);
    goto inetcdfworkspace_getdimensionsize_method_cleanup;

    inetcdfworkspace_getdimensionsize_method_cleanup:
    self->m_HR = hr;
    if (bsdimName)
        ::SysFreeString(bsdimName);
    
    // No cleanup for dimSize
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetDimensionSize");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetDimensionsByVariable(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsvarName = 0;
    PyObject* pyvar_varName;
    PyObject* unicodevarName = NULL;
    IStringArray* ipppOut = NULL;
    PyObject* py_ppOut = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_varName))
      goto inetcdfworkspace_getdimensionsbyvariable_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_varName))
        unicodevarName = PyUnicode_FromObject(pyvar_varName);
    else if (PyUnicode_Check(pyvar_varName))
    {
        unicodevarName = pyvar_varName;
        Py_INCREF(unicodevarName);
    }
    else if (pyvar_varName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter varName at index 0");
    if (unicodevarName)
        bsvarName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodevarName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodevarName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensionsbyvariable_method_cleanup;
    
    // No setup for ppOut

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetDimensionsByVariable(bsvarName, &ipppOut);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetDimensionsByVariable() returned %ld", (long)hr);
        goto inetcdfworkspace_getdimensionsbyvariable_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for varName
    Py_XDECREF(py_ppOut);
    if (ipppOut)
    {
        IUnknown* pUnk = NULL;
        ipppOut->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppOut = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppOut)
    {
        if (py_ppOut)
           Py_DECREF(py_ppOut);
        py_ppOut = Py_None;
        Py_INCREF(py_ppOut);
    }
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensionsbyvariable_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppOut);
    goto inetcdfworkspace_getdimensionsbyvariable_method_cleanup;

    inetcdfworkspace_getdimensionsbyvariable_method_cleanup:
    self->m_HR = hr;
    if (bsvarName)
        ::SysFreeString(bsvarName);
    
    Py_XDECREF(py_ppOut);
    if (ipppOut)
      ipppOut->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetDimensionsByVariable");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetVariablesByDimension(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdimName = 0;
    PyObject* pyvar_dimName;
    PyObject* unicodedimName = NULL;
    IStringArray* ipppOut = NULL;
    PyObject* py_ppOut = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dimName))
      goto inetcdfworkspace_getvariablesbydimension_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dimName))
        unicodedimName = PyUnicode_FromObject(pyvar_dimName);
    else if (PyUnicode_Check(pyvar_dimName))
    {
        unicodedimName = pyvar_dimName;
        Py_INCREF(unicodedimName);
    }
    else if (pyvar_dimName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dimName at index 0");
    if (unicodedimName)
        bsdimName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedimName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedimName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getvariablesbydimension_method_cleanup;
    
    // No setup for ppOut

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetVariablesByDimension(bsdimName, &ipppOut);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetVariablesByDimension() returned %ld", (long)hr);
        goto inetcdfworkspace_getvariablesbydimension_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dimName
    Py_XDECREF(py_ppOut);
    if (ipppOut)
    {
        IUnknown* pUnk = NULL;
        ipppOut->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppOut = IUnknownToPythonIIDObject(pUnk, &IID_IStringArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppOut)
    {
        if (py_ppOut)
           Py_DECREF(py_ppOut);
        py_ppOut = Py_None;
        Py_INCREF(py_ppOut);
    }
    if (PyErr_Occurred())
      goto inetcdfworkspace_getvariablesbydimension_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppOut);
    goto inetcdfworkspace_getvariablesbydimension_method_cleanup;

    inetcdfworkspace_getvariablesbydimension_method_cleanup:
    self->m_HR = hr;
    if (bsdimName)
        ::SysFreeString(bsdimName);
    
    Py_XDECREF(py_ppOut);
    if (ipppOut)
      ipppOut->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetVariablesByDimension");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetDimensionValue(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdimName = 0;
    PyObject* pyvar_dimName;
    PyObject* unicodedimName = NULL;
    long lindex = 0;
    VARIANT vvValue;
    ::VariantInit(&vvValue);
    PyObject* pyvar_vValue = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "Ol", &pyvar_dimName, &lindex))
      goto inetcdfworkspace_getdimensionvalue_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dimName))
        unicodedimName = PyUnicode_FromObject(pyvar_dimName);
    else if (PyUnicode_Check(pyvar_dimName))
    {
        unicodedimName = pyvar_dimName;
        Py_INCREF(unicodedimName);
    }
    else if (pyvar_dimName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dimName at index 0");
    if (unicodedimName)
        bsdimName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedimName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedimName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensionvalue_method_cleanup;
    
    // No setup for index
    // No setup for vValue

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetDimensionValue(bsdimName, lindex, &vvValue);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetDimensionValue() returned %ld", (long)hr);
        goto inetcdfworkspace_getdimensionvalue_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dimName
    // No teardown for index
    pyvar_vValue = Variant_AsPyObject(&vvValue);
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensionvalue_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_vValue);
    goto inetcdfworkspace_getdimensionvalue_method_cleanup;

    inetcdfworkspace_getdimensionvalue_method_cleanup:
    self->m_HR = hr;
    if (bsdimName)
        ::SysFreeString(bsdimName);
    
    // No cleanup for index
    ::VariantClear(&vvValue);
    Py_XDECREF(pyvar_vValue);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetDimensionValue");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetDimensionIndex(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdimName = 0;
    PyObject* pyvar_dimName;
    PyObject* unicodedimName = NULL;
    VARIANT vvValue;
    ::VariantInit(&vvValue);
    PyObject* pyvar_vValue = NULL;
    long lindex = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OO", &pyvar_dimName, &pyvar_vValue))
      goto inetcdfworkspace_getdimensionindex_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dimName))
        unicodedimName = PyUnicode_FromObject(pyvar_dimName);
    else if (PyUnicode_Check(pyvar_dimName))
    {
        unicodedimName = pyvar_dimName;
        Py_INCREF(unicodedimName);
    }
    else if (pyvar_dimName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dimName at index 0");
    if (unicodedimName)
        bsdimName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedimName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedimName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensionindex_method_cleanup;
    
    PyObject_AsVariant(pyvar_vValue, &vvValue);
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensionindex_method_cleanup;
    
    // No setup for index

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetDimensionIndex(bsdimName, vvValue, &lindex);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetDimensionIndex() returned %ld", (long)hr);
        goto inetcdfworkspace_getdimensionindex_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dimName
    // No teardown for vValue
    // No teardown for index

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lindex);
    goto inetcdfworkspace_getdimensionindex_method_cleanup;

    inetcdfworkspace_getdimensionindex_method_cleanup:
    self->m_HR = hr;
    if (bsdimName)
        ::SysFreeString(bsdimName);
    
    ::VariantClear(&vvValue);
    // No cleanup for index
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetDimensionIndex");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetAttributeValue(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsvarName = 0;
    PyObject* pyvar_varName;
    PyObject* unicodevarName = NULL;
    BSTR bsattName = 0;
    PyObject* pyvar_attName;
    PyObject* unicodeattName = NULL;
    long lvalueIndex = 0;
    VARIANT vpValue;
    ::VariantInit(&vpValue);
    PyObject* pyvar_pValue = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OOl", &pyvar_varName, &pyvar_attName, &lvalueIndex))
      goto inetcdfworkspace_getattributevalue_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_varName))
        unicodevarName = PyUnicode_FromObject(pyvar_varName);
    else if (PyUnicode_Check(pyvar_varName))
    {
        unicodevarName = pyvar_varName;
        Py_INCREF(unicodevarName);
    }
    else if (pyvar_varName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter varName at index 0");
    if (unicodevarName)
        bsvarName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodevarName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodevarName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getattributevalue_method_cleanup;
    
    if (PyString_Check(pyvar_attName))
        unicodeattName = PyUnicode_FromObject(pyvar_attName);
    else if (PyUnicode_Check(pyvar_attName))
    {
        unicodeattName = pyvar_attName;
        Py_INCREF(unicodeattName);
    }
    else if (pyvar_attName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter attName at index 1");
    if (unicodeattName)
        bsattName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeattName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeattName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getattributevalue_method_cleanup;
    
    // No setup for valueIndex
    // No setup for pValue

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetAttributeValue(bsvarName, bsattName, lvalueIndex, &vpValue);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetAttributeValue() returned %ld", (long)hr);
        goto inetcdfworkspace_getattributevalue_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for varName
    // No teardown for attName
    // No teardown for valueIndex
    pyvar_pValue = Variant_AsPyObject(&vpValue);
    if (PyErr_Occurred())
      goto inetcdfworkspace_getattributevalue_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pValue);
    goto inetcdfworkspace_getattributevalue_method_cleanup;

    inetcdfworkspace_getattributevalue_method_cleanup:
    self->m_HR = hr;
    if (bsvarName)
        ::SysFreeString(bsvarName);
    
    if (bsattName)
        ::SysFreeString(bsattName);
    
    // No cleanup for valueIndex
    ::VariantClear(&vpValue);
    Py_XDECREF(pyvar_pValue);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetAttributeValue");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetDimensionValues(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsdimName = 0;
    PyObject* pyvar_dimName;
    PyObject* unicodedimName = NULL;
    IVariantArray* ipppValues = NULL;
    PyObject* py_ppValues = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_dimName))
      goto inetcdfworkspace_getdimensionvalues_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_dimName))
        unicodedimName = PyUnicode_FromObject(pyvar_dimName);
    else if (PyUnicode_Check(pyvar_dimName))
    {
        unicodedimName = pyvar_dimName;
        Py_INCREF(unicodedimName);
    }
    else if (pyvar_dimName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter dimName at index 0");
    if (unicodedimName)
        bsdimName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodedimName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodedimName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensionvalues_method_cleanup;
    
    // No setup for ppValues

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetDimensionValues(bsdimName, &ipppValues);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetDimensionValues() returned %ld", (long)hr);
        goto inetcdfworkspace_getdimensionvalues_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for dimName
    Py_XDECREF(py_ppValues);
    if (ipppValues)
    {
        IUnknown* pUnk = NULL;
        ipppValues->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppValues = IUnknownToPythonIIDObject(pUnk, &IID_IVariantArray);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppValues)
    {
        if (py_ppValues)
           Py_DECREF(py_ppValues);
        py_ppValues = Py_None;
        Py_INCREF(py_ppValues);
    }
    if (PyErr_Occurred())
      goto inetcdfworkspace_getdimensionvalues_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppValues);
    goto inetcdfworkspace_getdimensionvalues_method_cleanup;

    inetcdfworkspace_getdimensionvalues_method_cleanup:
    self->m_HR = hr;
    if (bsdimName)
        ::SysFreeString(bsdimName);
    
    Py_XDECREF(py_ppValues);
    if (ipppValues)
      ipppValues->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetDimensionValues");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetSpatialReference(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsvarName = 0;
    PyObject* pyvar_varName;
    PyObject* unicodevarName = NULL;
    BSTR bsxDim = 0;
    PyObject* pyvar_xDim;
    PyObject* unicodexDim = NULL;
    BSTR bsyDim = 0;
    PyObject* pyvar_yDim;
    PyObject* unicodeyDim = NULL;
    ISpatialReference* ipppSpatRef = NULL;
    PyObject* py_ppSpatRef = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OOO", &pyvar_varName, &pyvar_xDim, &pyvar_yDim))
      goto inetcdfworkspace_getspatialreference_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_varName))
        unicodevarName = PyUnicode_FromObject(pyvar_varName);
    else if (PyUnicode_Check(pyvar_varName))
    {
        unicodevarName = pyvar_varName;
        Py_INCREF(unicodevarName);
    }
    else if (pyvar_varName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter varName at index 0");
    if (unicodevarName)
        bsvarName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodevarName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodevarName));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getspatialreference_method_cleanup;
    
    if (PyString_Check(pyvar_xDim))
        unicodexDim = PyUnicode_FromObject(pyvar_xDim);
    else if (PyUnicode_Check(pyvar_xDim))
    {
        unicodexDim = pyvar_xDim;
        Py_INCREF(unicodexDim);
    }
    else if (pyvar_xDim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter xDim at index 1");
    if (unicodexDim)
        bsxDim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodexDim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodexDim));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getspatialreference_method_cleanup;
    
    if (PyString_Check(pyvar_yDim))
        unicodeyDim = PyUnicode_FromObject(pyvar_yDim);
    else if (PyUnicode_Check(pyvar_yDim))
    {
        unicodeyDim = pyvar_yDim;
        Py_INCREF(unicodeyDim);
    }
    else if (pyvar_yDim != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter yDim at index 2");
    if (unicodeyDim)
        bsyDim = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeyDim), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeyDim));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getspatialreference_method_cleanup;
    
    // No setup for ppSpatRef

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetSpatialReference(bsvarName, bsxDim, bsyDim, &ipppSpatRef);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetSpatialReference() returned %ld", (long)hr);
        goto inetcdfworkspace_getspatialreference_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for varName
    // No teardown for xDim
    // No teardown for yDim
    Py_XDECREF(py_ppSpatRef);
    if (ipppSpatRef)
    {
        IUnknown* pUnk = NULL;
        ipppSpatRef->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppSpatRef = IUnknownToPythonIIDObject(pUnk, &IID_ISpatialReference);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppSpatRef)
    {
        if (py_ppSpatRef)
           Py_DECREF(py_ppSpatRef);
        py_ppSpatRef = Py_None;
        Py_INCREF(py_ppSpatRef);
    }
    if (PyErr_Occurred())
      goto inetcdfworkspace_getspatialreference_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppSpatRef);
    goto inetcdfworkspace_getspatialreference_method_cleanup;

    inetcdfworkspace_getspatialreference_method_cleanup:
    self->m_HR = hr;
    if (bsvarName)
        ::SysFreeString(bsvarName);
    
    if (bsxDim)
        ::SysFreeString(bsxDim);
    
    if (bsyDim)
        ::SysFreeString(bsyDim);
    
    Py_XDECREF(py_ppSpatRef);
    if (ipppSpatRef)
      ipppSpatRef->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetSpatialReference");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetFieldType(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsname = 0;
    PyObject* pyvar_name;
    PyObject* unicodename = NULL;
    esriFieldType efieldType;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_name))
      goto inetcdfworkspace_getfieldtype_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_name))
        unicodename = PyUnicode_FromObject(pyvar_name);
    else if (PyUnicode_Check(pyvar_name))
    {
        unicodename = pyvar_name;
        Py_INCREF(unicodename);
    }
    else if (pyvar_name != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter name at index 0");
    if (unicodename)
        bsname = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodename), 
                                            (UINT)PyUnicode_GET_SIZE(unicodename));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getfieldtype_method_cleanup;
    
    // No setup for fieldType

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetFieldType(bsname, &efieldType);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetFieldType() returned %ld", (long)hr);
        goto inetcdfworkspace_getfieldtype_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for name
    // No teardown for fieldType

    // Initialize output tuple
    return_tuple = Py_BuildValue("i",
                                            (int)efieldType);
    goto inetcdfworkspace_getfieldtype_method_cleanup;

    inetcdfworkspace_getfieldtype_method_cleanup:
    self->m_HR = hr;
    if (bsname)
        ::SysFreeString(bsname);
    
    // No cleanup for fieldType
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetFieldType");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetValueFromIndex(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    BSTR bsname = 0;
    PyObject* pyvar_name;
    PyObject* unicodename = NULL;
    VARIANT vpVal;
    ::VariantInit(&vpVal);
    PyObject* pyvar_pVal = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "lO", &lindex, &pyvar_name))
      goto inetcdfworkspace_getvaluefromindex_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    if (PyString_Check(pyvar_name))
        unicodename = PyUnicode_FromObject(pyvar_name);
    else if (PyUnicode_Check(pyvar_name))
    {
        unicodename = pyvar_name;
        Py_INCREF(unicodename);
    }
    else if (pyvar_name != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter name at index 1");
    if (unicodename)
        bsname = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodename), 
                                            (UINT)PyUnicode_GET_SIZE(unicodename));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getvaluefromindex_method_cleanup;
    
    // No setup for pVal

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetValueFromIndex(lindex, bsname, &vpVal);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetValueFromIndex() returned %ld", (long)hr);
        goto inetcdfworkspace_getvaluefromindex_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    // No teardown for name
    pyvar_pVal = Variant_AsPyObject(&vpVal);
    if (PyErr_Occurred())
      goto inetcdfworkspace_getvaluefromindex_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pVal);
    goto inetcdfworkspace_getvaluefromindex_method_cleanup;

    inetcdfworkspace_getvaluefromindex_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    if (bsname)
        ::SysFreeString(bsname);
    
    ::VariantClear(&vpVal);
    Py_XDECREF(pyvar_pVal);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetValueFromIndex");
    return return_tuple;
}

static PyObject*
INetCDFWorkspaceMethod_GetIndexFromValue(PyINetCDFWorkspaceObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsname = 0;
    PyObject* pyvar_name;
    PyObject* unicodename = NULL;
    VARIANT vvalue;
    ::VariantInit(&vvalue);
    PyObject* pyvar_value = NULL;
    long lindex = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "OO", &pyvar_name, &pyvar_value))
      goto inetcdfworkspace_getindexfromvalue_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_name))
        unicodename = PyUnicode_FromObject(pyvar_name);
    else if (PyUnicode_Check(pyvar_name))
    {
        unicodename = pyvar_name;
        Py_INCREF(unicodename);
    }
    else if (pyvar_name != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter name at index 0");
    if (unicodename)
        bsname = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodename), 
                                            (UINT)PyUnicode_GET_SIZE(unicodename));
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getindexfromvalue_method_cleanup;
    
    PyObject_AsVariant(pyvar_value, &vvalue);
    
    if (PyErr_Occurred())
      goto inetcdfworkspace_getindexfromvalue_method_cleanup;
    
    // No setup for index

    // Call method on actual COM interface
    hr = self->m_pINetCDFWorkspace->GetIndexFromValue(bsname, vvalue, &lindex);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pINetCDFWorkspace->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_INetCDFWorkspace) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: INetCDFWorkspace.GetIndexFromValue() returned %ld", (long)hr);
        goto inetcdfworkspace_getindexfromvalue_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for name
    // No teardown for value
    // No teardown for index

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lindex);
    goto inetcdfworkspace_getindexfromvalue_method_cleanup;

    inetcdfworkspace_getindexfromvalue_method_cleanup:
    self->m_HR = hr;
    if (bsname)
        ::SysFreeString(bsname);
    
    ::VariantClear(&vvalue);
    // No cleanup for index
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in INetCDFWorkspace.GetIndexFromValue");
    return return_tuple;
}


PyMethodDef PyINetCDFWorkspaceMethods[] = {
    {"supports", (PyCFunction)PyINetCDFWorkspace_SupportsInterface, METH_O, ""},
    {"GetVariables", (PyCFunction)INetCDFWorkspaceMethod_GetVariables, METH_VARARGS, ""},
    {"GetDimensions", (PyCFunction)INetCDFWorkspaceMethod_GetDimensions, METH_VARARGS, ""},
    {"GetAttributeNames", (PyCFunction)INetCDFWorkspaceMethod_GetAttributeNames, METH_VARARGS, ""},
    {"GetDimensionSize", (PyCFunction)INetCDFWorkspaceMethod_GetDimensionSize, METH_VARARGS, ""},
    {"GetDimensionsByVariable", (PyCFunction)INetCDFWorkspaceMethod_GetDimensionsByVariable, METH_VARARGS, ""},
    {"GetVariablesByDimension", (PyCFunction)INetCDFWorkspaceMethod_GetVariablesByDimension, METH_VARARGS, ""},
    {"GetDimensionValue", (PyCFunction)INetCDFWorkspaceMethod_GetDimensionValue, METH_VARARGS, ""},
    {"GetDimensionIndex", (PyCFunction)INetCDFWorkspaceMethod_GetDimensionIndex, METH_VARARGS, ""},
    {"GetAttributeValue", (PyCFunction)INetCDFWorkspaceMethod_GetAttributeValue, METH_VARARGS, ""},
    {"GetDimensionValues", (PyCFunction)INetCDFWorkspaceMethod_GetDimensionValues, METH_VARARGS, ""},
    {"GetSpatialReference", (PyCFunction)INetCDFWorkspaceMethod_GetSpatialReference, METH_VARARGS, ""},
    {"GetFieldType", (PyCFunction)INetCDFWorkspaceMethod_GetFieldType, METH_VARARGS, ""},
    {"GetValueFromIndex", (PyCFunction)INetCDFWorkspaceMethod_GetValueFromIndex, METH_VARARGS, ""},
    {"GetIndexFromValue", (PyCFunction)INetCDFWorkspaceMethod_GetIndexFromValue, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyINetCDFWorkspaceGetSet[] = {
  {"_pUnk", (getter)PyINetCDFWorkspace_GetpUnk, NULL, "Get opaque pointer to an Unknown from INetCDFWorkspace", NULL},
  {"_pointer", (getter)PyINetCDFWorkspace_GetPointer, NULL, "Get memory address for INetCDFWorkspace", NULL},
  {"_IID", (getter)PyINetCDFWorkspace_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyINetCDFWorkspace_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyINetCDFWorkspace_GetIgnoreFailures, (setter)PyINetCDFWorkspace_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyINetCDFWorkspaceObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriDataSourcesNetCDF.INetCDFWorkspaceObject",                          
                                              /* tp_name */
  sizeof(PyINetCDFWorkspaceObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyINetCDFWorkspaceObject_dealloc,      
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
  PyINetCDFWorkspaceMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyINetCDFWorkspaceGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyINetCDFWorkspaceObject_new,                      
                                              /* tp_new */
};





static PyObject*
CoCreateNetCDFWorkspaceFactory(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_NetCDFWorkspaceFactory, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of NetCDFWorkspaceFactory");
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
            // clsid_key_lookup = uuid.UUID("df61a9e1-b8e2-498f-bde5-98de42e801f9")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "df61a9e1-b8e2-498f-bde5-98de42e801f9");
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
CoCreateNetCDFWorkspace(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_NetCDFWorkspace, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of NetCDFWorkspace");
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
            // clsid_key_lookup = uuid.UUID("434116cc-611e-44be-a194-e4594c2fc926")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "434116cc-611e-44be-a194-e4594c2fc926");
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
CoCreateNetCDFRasterDatasetName(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_NetCDFRasterDatasetName, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of NetCDFRasterDatasetName");
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
            // clsid_key_lookup = uuid.UUID("8cb4aa2b-58ce-438f-8cd8-f5f0bef41aaf")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "8cb4aa2b-58ce-438f-8cd8-f5f0bef41aaf");
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
CoCreateNetCDFTableName(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_NetCDFTableName, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of NetCDFTableName");
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
            // clsid_key_lookup = uuid.UUID("2d597a23-a989-43c1-9b1b-19e75bbfb78f")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "2d597a23-a989-43c1-9b1b-19e75bbfb78f");
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
CoCreateNetCDFFeatureClassName(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_NetCDFFeatureClassName, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of NetCDFFeatureClassName");
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
            // clsid_key_lookup = uuid.UUID("ee5ef168-7b62-4ed5-89bb-ff73d390af93")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "ee5ef168-7b62-4ed5-89bb-ff73d390af93");
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



static PyMethodDef _esriDataSourcesNetCDFMethods[] = {
    {"NetCDFWorkspaceFactory", (PyCFunction)CoCreateNetCDFWorkspaceFactory, METH_NOARGS,
     "Create instance of NetCDFWorkspaceFactory\n"},
    {"NetCDFWorkspace", (PyCFunction)CoCreateNetCDFWorkspace, METH_NOARGS,
     "Create instance of NetCDFWorkspace\n"},
    {"NetCDFRasterDatasetName", (PyCFunction)CoCreateNetCDFRasterDatasetName, METH_NOARGS,
     "Create instance of NetCDFRasterDatasetName\n"},
    {"NetCDFTableName", (PyCFunction)CoCreateNetCDFTableName, METH_NOARGS,
     "Create instance of NetCDFTableName\n"},
    {"NetCDFFeatureClassName", (PyCFunction)CoCreateNetCDFFeatureClassName, METH_NOARGS,
     "Create instance of NetCDFFeatureClassName\n"},
    {NULL, NULL, 0, NULL}
};

extern "C" {

    PyMODINIT_FUNC
    init_esriDataSourcesNetCDF(void)
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
        module = Py_InitModule3("cartocomutils._esriDataSourcesNetCDF",
                                 _esriDataSourcesNetCDFMethods,
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
        // IProtectNamesDataSourcesNetCDF
        PyType_Ready(&PyIProtectNamesDataSourcesNetCDFObject_Type);
        Py_INCREF((PyObject* )&PyIProtectNamesDataSourcesNetCDFObject_Type);
        PyModule_AddObject(module, "IProtectNamesDataSourcesNetCDF", 
                           (PyObject *)&PyIProtectNamesDataSourcesNetCDFObject_Type);

        // IMDDatasetView
        PyType_Ready(&PyIMDDatasetViewObject_Type);
        Py_INCREF((PyObject* )&PyIMDDatasetViewObject_Type);
        PyModule_AddObject(module, "IMDDatasetView", 
                           (PyObject *)&PyIMDDatasetViewObject_Type);

        // IMDWorkspace
        PyType_Ready(&PyIMDWorkspaceObject_Type);
        Py_INCREF((PyObject* )&PyIMDWorkspaceObject_Type);
        PyModule_AddObject(module, "IMDWorkspace", 
                           (PyObject *)&PyIMDWorkspaceObject_Type);

        // IMDRasterDatasetView
        PyType_Ready(&PyIMDRasterDatasetViewObject_Type);
        Py_INCREF((PyObject* )&PyIMDRasterDatasetViewObject_Type);
        PyModule_AddObject(module, "IMDRasterDatasetView", 
                           (PyObject *)&PyIMDRasterDatasetViewObject_Type);

        // IMDTableView
        PyType_Ready(&PyIMDTableViewObject_Type);
        Py_INCREF((PyObject* )&PyIMDTableViewObject_Type);
        PyModule_AddObject(module, "IMDTableView", 
                           (PyObject *)&PyIMDTableViewObject_Type);

        // IMDFeatureClassView
        PyType_Ready(&PyIMDFeatureClassViewObject_Type);
        Py_INCREF((PyObject* )&PyIMDFeatureClassViewObject_Type);
        PyModule_AddObject(module, "IMDFeatureClassView", 
                           (PyObject *)&PyIMDFeatureClassViewObject_Type);

        // INetCDFWorkspace
        PyType_Ready(&PyINetCDFWorkspaceObject_Type);
        Py_INCREF((PyObject* )&PyINetCDFWorkspaceObject_Type);
        PyModule_AddObject(module, "INetCDFWorkspace", 
                           (PyObject *)&PyINetCDFWorkspaceObject_Type);


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
