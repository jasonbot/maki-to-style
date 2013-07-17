// This source is all automatically generated. Editing it may very
// well be an exercise in futility and frustration.
#include "Python.h"
#include "datetime.h"

// imports
#import "c:\Program Files (x86)\Common Files\ArcGIS\bin\ArcGISVersion.dll" raw_interfaces_only, raw_native_types, no_namespace, named_guids, rename("esriProductCode", "esriVersionProductCode"), rename("VersionManager", "ArcGISVersionManager")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriSystem.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids, exclude("OLE_COLOR", "OLE_HANDLE", "VARTYPE")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriSystemUI.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriGeometry.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriGraphicsCore.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriGraphicsSymbols.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriDisplay.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriServer.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriGeoDatabase.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriGISClient.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriCarto.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids, exclude("UINT_PTR")
#import "C:\Program Files (x86)\ArcGIS\Desktop10.2\com\esriFramework.olb" raw_interfaces_only, raw_native_types, no_namespace, named_guids, exclude("UINT_PTR")


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




// Interface IProgressDialog

typedef struct PyIProgressDialogObject {
    PyObject_HEAD
    IProgressDialog* m_pIProgressDialog;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIProgressDialogObject;

static PyObject*
PyIProgressDialogObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIProgressDialogObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IProgressDialog* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IProgressDialog, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IProgressDialog with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIProgressDialogObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IProgressDialog");
            return NULL;
        }
        self->m_pIProgressDialog = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IProgressDialog");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IProgressDialog");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IProgressDialog* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IProgressDialog, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IProgressDialog");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIProgressDialogObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IProgressDialog");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIProgressDialog = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIProgressDialogObject_dealloc(PyIProgressDialogObject* self)
{
    if (self->m_pIProgressDialog)
        self->m_pIProgressDialog->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIProgressDialog_GetpUnk(PyIProgressDialogObject* self)
{
    if (!self->m_pIProgressDialog)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIProgressDialog->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IProgressDialog to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIProgressDialog_GetPointer(PyIProgressDialogObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIProgressDialog);
}

static PyObject*
PyIProgressDialog_GetIID(PyIProgressDialogObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "923a1b5a-90e5-4d23-add8-eca3d7d6b1c8");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIProgressDialog_GetHR(PyIProgressDialogObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIProgressDialog_GetIgnoreFailures(PyIProgressDialogObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIProgressDialog_SetIgnoreFailures(PyIProgressDialogObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIProgressDialog_SupportsInterface(PyIProgressDialogObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIProgressDialog->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IProgressDialogMethod_ShowDialog(PyIProgressDialogObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIProgressDialog->ShowDialog();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIProgressDialog->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IProgressDialog) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IProgressDialog.ShowDialog() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IProgressDialogMethod_HideDialog(PyIProgressDialogObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIProgressDialog->HideDialog();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIProgressDialog->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IProgressDialog) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IProgressDialog.HideDialog() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IProgressDialogMethod_get_CancelEnabled(PyIProgressDialogObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_bVal = VARIANT_FALSE;
    PyObject* pyvar_bVal = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for bVal

    // Call method on actual COM interface
    hr = self->m_pIProgressDialog->get_CancelEnabled(&b_bVal);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIProgressDialog->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IProgressDialog) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IProgressDialog.get_CancelEnabled() returned %ld", (long)hr);
        goto iprogressdialog_get_cancelenabled_method_cleanup;
    }

    // Set up return values as needed
    pyvar_bVal = ((b_bVal == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto iprogressdialog_get_cancelenabled_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bVal);
    goto iprogressdialog_get_cancelenabled_method_cleanup;

    iprogressdialog_get_cancelenabled_method_cleanup:
    self->m_HR = hr;
    // No cleanup for bVal
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IProgressDialog.get_CancelEnabled");
    return return_tuple;
}

static PyObject*
IProgressDialogMethod_put_CancelEnabled(PyIProgressDialogObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_bVal = VARIANT_FALSE;
    PyObject* pyvar_bVal = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_bVal))
      goto iprogressdialog_put_cancelenabled_method_cleanup;

    // Set up initial variable values as needed
    b_bVal = ((PyObject_IsTrue(pyvar_bVal) == 1)?VARIANT_TRUE:VARIANT_FALSE);
    
    if (PyErr_Occurred())
      goto iprogressdialog_put_cancelenabled_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIProgressDialog->put_CancelEnabled(b_bVal);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIProgressDialog->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IProgressDialog) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IProgressDialog.put_CancelEnabled() returned %ld", (long)hr);
        goto iprogressdialog_put_cancelenabled_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for bVal

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto iprogressdialog_put_cancelenabled_method_cleanup;

    iprogressdialog_put_cancelenabled_method_cleanup:
    self->m_HR = hr;
    // No cleanup for bVal
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IProgressDialog.put_CancelEnabled");
    return return_tuple;
}


PyMethodDef PyIProgressDialogMethods[] = {
    {"supports", (PyCFunction)PyIProgressDialog_SupportsInterface, METH_O, ""},
    {"ShowDialog", (PyCFunction)IProgressDialogMethod_ShowDialog, METH_NOARGS, ""},
    {"HideDialog", (PyCFunction)IProgressDialogMethod_HideDialog, METH_NOARGS, ""},
    {"get_CancelEnabled", (PyCFunction)IProgressDialogMethod_get_CancelEnabled, METH_VARARGS, ""},
    {"put_CancelEnabled", (PyCFunction)IProgressDialogMethod_put_CancelEnabled, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIProgressDialogGetSet[] = {
  {"_pUnk", (getter)PyIProgressDialog_GetpUnk, NULL, "Get opaque pointer to an Unknown from IProgressDialog", NULL},
  {"_pointer", (getter)PyIProgressDialog_GetPointer, NULL, "Get memory address for IProgressDialog", NULL},
  {"_IID", (getter)PyIProgressDialog_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIProgressDialog_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIProgressDialog_GetIgnoreFailures, (setter)PyIProgressDialog_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIProgressDialogObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IProgressDialogObject",                          
                                              /* tp_name */
  sizeof(PyIProgressDialogObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIProgressDialogObject_dealloc,      
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
  PyIProgressDialogMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIProgressDialogGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIProgressDialogObject_new,                      
                                              /* tp_new */
};

// Interface ICommand

typedef struct PyICommandObject {
    PyObject_HEAD
    ICommand* m_pICommand;
    HRESULT m_HR;
    int m_ignore_failures;
} PyICommandObject;

static PyObject*
PyICommandObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyICommandObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        ICommand* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_ICommand, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate ICommand with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyICommandObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate ICommand");
            return NULL;
        }
        self->m_pICommand = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for ICommand");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to ICommand");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    ICommand* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_ICommand, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to ICommand");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyICommandObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate ICommand");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pICommand = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyICommandObject_dealloc(PyICommandObject* self)
{
    if (self->m_pICommand)
        self->m_pICommand->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyICommand_GetpUnk(PyICommandObject* self)
{
    if (!self->m_pICommand)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pICommand->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI ICommand to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyICommand_GetPointer(PyICommandObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pICommand);
}

static PyObject*
PyICommand_GetIID(PyICommandObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "36b06538-4437-11d1-b970-080009ee4e51");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyICommand_GetHR(PyICommandObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyICommand_GetIgnoreFailures(PyICommandObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyICommand_SetIgnoreFailures(PyICommandObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyICommand_SupportsInterface(PyICommandObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
ICommandMethod_get_Enabled(PyICommandObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_Enabled = VARIANT_FALSE;
    PyObject* pyvar_Enabled = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Enabled

    // Call method on actual COM interface
    hr = self->m_pICommand->get_Enabled(&b_Enabled);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_Enabled() returned %ld", (long)hr);
        goto icommand_get_enabled_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Enabled = ((b_Enabled == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto icommand_get_enabled_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Enabled);
    goto icommand_get_enabled_method_cleanup;

    icommand_get_enabled_method_cleanup:
    self->m_HR = hr;
    // No cleanup for Enabled
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_Enabled");
    return return_tuple;
}

static PyObject*
ICommandMethod_get_Checked(PyICommandObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_Checked = VARIANT_FALSE;
    PyObject* pyvar_Checked = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Checked

    // Call method on actual COM interface
    hr = self->m_pICommand->get_Checked(&b_Checked);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_Checked() returned %ld", (long)hr);
        goto icommand_get_checked_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Checked = ((b_Checked == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto icommand_get_checked_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Checked);
    goto icommand_get_checked_method_cleanup;

    icommand_get_checked_method_cleanup:
    self->m_HR = hr;
    // No cleanup for Checked
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_Checked");
    return return_tuple;
}

static PyObject*
ICommandMethod_get_Name(PyICommandObject* self, PyObject* args)
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
    hr = self->m_pICommand->get_Name(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_Name() returned %ld", (long)hr);
        goto icommand_get_name_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto icommand_get_name_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto icommand_get_name_method_cleanup;

    icommand_get_name_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_Name");
    return return_tuple;
}

static PyObject*
ICommandMethod_get_Caption(PyICommandObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsCaption;
    PyObject* pyvar_Caption = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Caption

    // Call method on actual COM interface
    hr = self->m_pICommand->get_Caption(&bsCaption);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_Caption() returned %ld", (long)hr);
        goto icommand_get_caption_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Caption = PyUnicode_FromWideChar(bsCaption,::SysStringLen(bsCaption));
    ::SysFreeString(bsCaption);
    
    if (PyErr_Occurred())
      goto icommand_get_caption_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Caption);
    goto icommand_get_caption_method_cleanup;

    icommand_get_caption_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Caption != Py_None)
        Py_XDECREF(pyvar_Caption);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_Caption");
    return return_tuple;
}

static PyObject*
ICommandMethod_get_Tooltip(PyICommandObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsTooltip;
    PyObject* pyvar_Tooltip = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Tooltip

    // Call method on actual COM interface
    hr = self->m_pICommand->get_Tooltip(&bsTooltip);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_Tooltip() returned %ld", (long)hr);
        goto icommand_get_tooltip_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Tooltip = PyUnicode_FromWideChar(bsTooltip,::SysStringLen(bsTooltip));
    ::SysFreeString(bsTooltip);
    
    if (PyErr_Occurred())
      goto icommand_get_tooltip_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Tooltip);
    goto icommand_get_tooltip_method_cleanup;

    icommand_get_tooltip_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Tooltip != Py_None)
        Py_XDECREF(pyvar_Tooltip);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_Tooltip");
    return return_tuple;
}

static PyObject*
ICommandMethod_get_Message(PyICommandObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsMessage;
    PyObject* pyvar_Message = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Message

    // Call method on actual COM interface
    hr = self->m_pICommand->get_Message(&bsMessage);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_Message() returned %ld", (long)hr);
        goto icommand_get_message_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Message = PyUnicode_FromWideChar(bsMessage,::SysStringLen(bsMessage));
    ::SysFreeString(bsMessage);
    
    if (PyErr_Occurred())
      goto icommand_get_message_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Message);
    goto icommand_get_message_method_cleanup;

    icommand_get_message_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Message != Py_None)
        Py_XDECREF(pyvar_Message);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_Message");
    return return_tuple;
}

static PyObject*
ICommandMethod_get_HelpFile(PyICommandObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsHelpFile;
    PyObject* pyvar_HelpFile = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for HelpFile

    // Call method on actual COM interface
    hr = self->m_pICommand->get_HelpFile(&bsHelpFile);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_HelpFile() returned %ld", (long)hr);
        goto icommand_get_helpfile_method_cleanup;
    }

    // Set up return values as needed
    pyvar_HelpFile = PyUnicode_FromWideChar(bsHelpFile,::SysStringLen(bsHelpFile));
    ::SysFreeString(bsHelpFile);
    
    if (PyErr_Occurred())
      goto icommand_get_helpfile_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_HelpFile);
    goto icommand_get_helpfile_method_cleanup;

    icommand_get_helpfile_method_cleanup:
    self->m_HR = hr;
    if (pyvar_HelpFile != Py_None)
        Py_XDECREF(pyvar_HelpFile);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_HelpFile");
    return return_tuple;
}

static PyObject*
ICommandMethod_get_HelpContextID(PyICommandObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lhelpID = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for helpID

    // Call method on actual COM interface
    hr = self->m_pICommand->get_HelpContextID(&lhelpID);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_HelpContextID() returned %ld", (long)hr);
        goto icommand_get_helpcontextid_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for helpID

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lhelpID);
    goto icommand_get_helpcontextid_method_cleanup;

    icommand_get_helpcontextid_method_cleanup:
    self->m_HR = hr;
    // No cleanup for helpID
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_HelpContextID");
    return return_tuple;
}

static PyObject*
ICommandMethod_get_Bitmap(PyICommandObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    OLE_HANDLE HBitmap = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Bitmap

    // Call method on actual COM interface
    hr = self->m_pICommand->get_Bitmap(&HBitmap);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_Bitmap() returned %ld", (long)hr);
        goto icommand_get_bitmap_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Bitmap

    // Initialize output tuple
    return_tuple = Py_BuildValue("I",
                                            HBitmap);
    goto icommand_get_bitmap_method_cleanup;

    icommand_get_bitmap_method_cleanup:
    self->m_HR = hr;
    // No cleanup for Bitmap
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_Bitmap");
    return return_tuple;
}

static PyObject*
ICommandMethod_get_Category(PyICommandObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bscategoryName;
    PyObject* pyvar_categoryName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for categoryName

    // Call method on actual COM interface
    hr = self->m_pICommand->get_Category(&bscategoryName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.get_Category() returned %ld", (long)hr);
        goto icommand_get_category_method_cleanup;
    }

    // Set up return values as needed
    pyvar_categoryName = PyUnicode_FromWideChar(bscategoryName,::SysStringLen(bscategoryName));
    ::SysFreeString(bscategoryName);
    
    if (PyErr_Occurred())
      goto icommand_get_category_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_categoryName);
    goto icommand_get_category_method_cleanup;

    icommand_get_category_method_cleanup:
    self->m_HR = hr;
    if (pyvar_categoryName != Py_None)
        Py_XDECREF(pyvar_categoryName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommand.get_Category");
    return return_tuple;
}

static PyObject*
ICommandMethod_OnCreate(PyICommandObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'IDispatch', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for ICommand.OnCreate not implemented.");
    return NULL;
}

static PyObject*
ICommandMethod_OnClick(PyICommandObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pICommand->OnClick();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommand->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommand) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommand.OnClick() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}


PyMethodDef PyICommandMethods[] = {
    {"supports", (PyCFunction)PyICommand_SupportsInterface, METH_O, ""},
    {"get_Enabled", (PyCFunction)ICommandMethod_get_Enabled, METH_VARARGS, ""},
    {"get_Checked", (PyCFunction)ICommandMethod_get_Checked, METH_VARARGS, ""},
    {"get_Name", (PyCFunction)ICommandMethod_get_Name, METH_VARARGS, ""},
    {"get_Caption", (PyCFunction)ICommandMethod_get_Caption, METH_VARARGS, ""},
    {"get_Tooltip", (PyCFunction)ICommandMethod_get_Tooltip, METH_VARARGS, ""},
    {"get_Message", (PyCFunction)ICommandMethod_get_Message, METH_VARARGS, ""},
    {"get_HelpFile", (PyCFunction)ICommandMethod_get_HelpFile, METH_VARARGS, ""},
    {"get_HelpContextID", (PyCFunction)ICommandMethod_get_HelpContextID, METH_VARARGS, ""},
    {"get_Bitmap", (PyCFunction)ICommandMethod_get_Bitmap, METH_VARARGS, ""},
    {"get_Category", (PyCFunction)ICommandMethod_get_Category, METH_VARARGS, ""},
    {"OnCreate", (PyCFunction)ICommandMethod_OnCreate, METH_VARARGS, ""},
    {"OnClick", (PyCFunction)ICommandMethod_OnClick, METH_NOARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyICommandGetSet[] = {
  {"_pUnk", (getter)PyICommand_GetpUnk, NULL, "Get opaque pointer to an Unknown from ICommand", NULL},
  {"_pointer", (getter)PyICommand_GetPointer, NULL, "Get memory address for ICommand", NULL},
  {"_IID", (getter)PyICommand_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyICommand_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyICommand_GetIgnoreFailures, (setter)PyICommand_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyICommandObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.ICommandObject",                          
                                              /* tp_name */
  sizeof(PyICommandObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyICommandObject_dealloc,      
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
  PyICommandMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyICommandGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyICommandObject_new,                      
                                              /* tp_new */
};

// Interface IComponentTip

typedef struct PyIComponentTipObject {
    PyObject_HEAD
    IComponentTip* m_pIComponentTip;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIComponentTipObject;

static PyObject*
PyIComponentTipObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIComponentTipObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IComponentTip* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IComponentTip, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IComponentTip with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIComponentTipObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IComponentTip");
            return NULL;
        }
        self->m_pIComponentTip = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IComponentTip");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IComponentTip");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IComponentTip* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IComponentTip, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IComponentTip");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIComponentTipObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IComponentTip");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIComponentTip = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIComponentTipObject_dealloc(PyIComponentTipObject* self)
{
    if (self->m_pIComponentTip)
        self->m_pIComponentTip->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIComponentTip_GetpUnk(PyIComponentTipObject* self)
{
    if (!self->m_pIComponentTip)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIComponentTip->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IComponentTip to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIComponentTip_GetPointer(PyIComponentTipObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIComponentTip);
}

static PyObject*
PyIComponentTip_GetIID(PyIComponentTipObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "fd86ed38-01c7-4a41-a72c-5502031aa216");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIComponentTip_GetHR(PyIComponentTipObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIComponentTip_GetIgnoreFailures(PyIComponentTipObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIComponentTip_SetIgnoreFailures(PyIComponentTipObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIComponentTip_SupportsInterface(PyIComponentTipObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIComponentTip->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IComponentTipMethod_get_Heading(PyIComponentTipObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsHeading;
    PyObject* pyvar_Heading = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Heading

    // Call method on actual COM interface
    hr = self->m_pIComponentTip->get_Heading(&bsHeading);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComponentTip->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComponentTip) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComponentTip.get_Heading() returned %ld", (long)hr);
        goto icomponenttip_get_heading_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Heading = PyUnicode_FromWideChar(bsHeading,::SysStringLen(bsHeading));
    ::SysFreeString(bsHeading);
    
    if (PyErr_Occurred())
      goto icomponenttip_get_heading_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Heading);
    goto icomponenttip_get_heading_method_cleanup;

    icomponenttip_get_heading_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Heading != Py_None)
        Py_XDECREF(pyvar_Heading);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComponentTip.get_Heading");
    return return_tuple;
}

static PyObject*
IComponentTipMethod_get_Tip(PyIComponentTipObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsTip;
    PyObject* pyvar_Tip = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Tip

    // Call method on actual COM interface
    hr = self->m_pIComponentTip->get_Tip(&bsTip);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComponentTip->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComponentTip) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComponentTip.get_Tip() returned %ld", (long)hr);
        goto icomponenttip_get_tip_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Tip = PyUnicode_FromWideChar(bsTip,::SysStringLen(bsTip));
    ::SysFreeString(bsTip);
    
    if (PyErr_Occurred())
      goto icomponenttip_get_tip_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Tip);
    goto icomponenttip_get_tip_method_cleanup;

    icomponenttip_get_tip_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Tip != Py_None)
        Py_XDECREF(pyvar_Tip);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComponentTip.get_Tip");
    return return_tuple;
}

static PyObject*
IComponentTipMethod_get_Image(PyIComponentTipObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    OLE_HANDLE HImage = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Image

    // Call method on actual COM interface
    hr = self->m_pIComponentTip->get_Image(&HImage);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComponentTip->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComponentTip) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComponentTip.get_Image() returned %ld", (long)hr);
        goto icomponenttip_get_image_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Image

    // Initialize output tuple
    return_tuple = Py_BuildValue("I",
                                            HImage);
    goto icomponenttip_get_image_method_cleanup;

    icomponenttip_get_image_method_cleanup:
    self->m_HR = hr;
    // No cleanup for Image
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComponentTip.get_Image");
    return return_tuple;
}


PyMethodDef PyIComponentTipMethods[] = {
    {"supports", (PyCFunction)PyIComponentTip_SupportsInterface, METH_O, ""},
    {"get_Heading", (PyCFunction)IComponentTipMethod_get_Heading, METH_VARARGS, ""},
    {"get_Tip", (PyCFunction)IComponentTipMethod_get_Tip, METH_VARARGS, ""},
    {"get_Image", (PyCFunction)IComponentTipMethod_get_Image, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIComponentTipGetSet[] = {
  {"_pUnk", (getter)PyIComponentTip_GetpUnk, NULL, "Get opaque pointer to an Unknown from IComponentTip", NULL},
  {"_pointer", (getter)PyIComponentTip_GetPointer, NULL, "Get memory address for IComponentTip", NULL},
  {"_IID", (getter)PyIComponentTip_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIComponentTip_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIComponentTip_GetIgnoreFailures, (setter)PyIComponentTip_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIComponentTipObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IComponentTipObject",                          
                                              /* tp_name */
  sizeof(PyIComponentTipObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIComponentTipObject_dealloc,      
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
  PyIComponentTipMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIComponentTipGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIComponentTipObject_new,                      
                                              /* tp_new */
};

// Interface IComboBoxHook

typedef struct PyIComboBoxHookObject {
    PyObject_HEAD
    IComboBoxHook* m_pIComboBoxHook;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIComboBoxHookObject;

static PyObject*
PyIComboBoxHookObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIComboBoxHookObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IComboBoxHook* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IComboBoxHook, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IComboBoxHook with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIComboBoxHookObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IComboBoxHook");
            return NULL;
        }
        self->m_pIComboBoxHook = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IComboBoxHook");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IComboBoxHook");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IComboBoxHook* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IComboBoxHook, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IComboBoxHook");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIComboBoxHookObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IComboBoxHook");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIComboBoxHook = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIComboBoxHookObject_dealloc(PyIComboBoxHookObject* self)
{
    if (self->m_pIComboBoxHook)
        self->m_pIComboBoxHook->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIComboBoxHook_GetpUnk(PyIComboBoxHookObject* self)
{
    if (!self->m_pIComboBoxHook)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIComboBoxHook->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IComboBoxHook to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIComboBoxHook_GetPointer(PyIComboBoxHookObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIComboBoxHook);
}

static PyObject*
PyIComboBoxHook_GetIID(PyIComboBoxHookObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "457fa6e9-2b50-4335-9990-b321ff228daf");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIComboBoxHook_GetHR(PyIComboBoxHookObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIComboBoxHook_GetIgnoreFailures(PyIComboBoxHookObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIComboBoxHook_SetIgnoreFailures(PyIComboBoxHookObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIComboBoxHook_SupportsInterface(PyIComboBoxHookObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIComboBoxHook->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IComboBoxHookMethod_get_Hook(PyIComboBoxHookObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       OUTPUT [u'IDispatch', u'*', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IComboBoxHook.get_Hook not implemented.");
    return NULL;
}

static PyObject*
IComboBoxHookMethod_Add(PyIComboBoxHookObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsstr = 0;
    PyObject* pyvar_str;
    PyObject* unicodestr = NULL;
    long lcookie = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_str))
      goto icomboboxhook_add_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_str))
        unicodestr = PyUnicode_FromObject(pyvar_str);
    else if (PyUnicode_Check(pyvar_str))
    {
        unicodestr = pyvar_str;
        Py_INCREF(unicodestr);
    }
    else if (pyvar_str != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter str at index 0");
    if (unicodestr)
        bsstr = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodestr), 
                                            (UINT)PyUnicode_GET_SIZE(unicodestr));
    
    if (PyErr_Occurred())
      goto icomboboxhook_add_method_cleanup;
    
    // No setup for cookie

    // Call method on actual COM interface
    hr = self->m_pIComboBoxHook->Add(bsstr, &lcookie);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBoxHook->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBoxHook) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBoxHook.Add() returned %ld", (long)hr);
        goto icomboboxhook_add_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for str
    // No teardown for cookie

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lcookie);
    goto icomboboxhook_add_method_cleanup;

    icomboboxhook_add_method_cleanup:
    self->m_HR = hr;
    if (bsstr)
        ::SysFreeString(bsstr);
    
    // No cleanup for cookie
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBoxHook.Add");
    return return_tuple;
}

static PyObject*
IComboBoxHookMethod_Remove(PyIComboBoxHookObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lcookie = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lcookie))
      goto icomboboxhook_remove_method_cleanup;

    // Set up initial variable values as needed
    // No setup for cookie

    // Call method on actual COM interface
    hr = self->m_pIComboBoxHook->Remove(lcookie);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBoxHook->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBoxHook) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBoxHook.Remove() returned %ld", (long)hr);
        goto icomboboxhook_remove_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for cookie

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto icomboboxhook_remove_method_cleanup;

    icomboboxhook_remove_method_cleanup:
    self->m_HR = hr;
    // No cleanup for cookie
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBoxHook.Remove");
    return return_tuple;
}

static PyObject*
IComboBoxHookMethod_put_Value(PyIComboBoxHookObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsValue = 0;
    PyObject* pyvar_Value;
    PyObject* unicodeValue = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_Value))
      goto icomboboxhook_put_value_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_Value))
        unicodeValue = PyUnicode_FromObject(pyvar_Value);
    else if (PyUnicode_Check(pyvar_Value))
    {
        unicodeValue = pyvar_Value;
        Py_INCREF(unicodeValue);
    }
    else if (pyvar_Value != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter Value at index 0");
    if (unicodeValue)
        bsValue = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeValue), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeValue));
    
    if (PyErr_Occurred())
      goto icomboboxhook_put_value_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIComboBoxHook->put_Value(bsValue);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBoxHook->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBoxHook) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBoxHook.put_Value() returned %ld", (long)hr);
        goto icomboboxhook_put_value_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Value

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto icomboboxhook_put_value_method_cleanup;

    icomboboxhook_put_value_method_cleanup:
    self->m_HR = hr;
    if (bsValue)
        ::SysFreeString(bsValue);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBoxHook.put_Value");
    return return_tuple;
}

static PyObject*
IComboBoxHookMethod_get_Value(PyIComboBoxHookObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsValue;
    PyObject* pyvar_Value = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Value

    // Call method on actual COM interface
    hr = self->m_pIComboBoxHook->get_Value(&bsValue);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBoxHook->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBoxHook) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBoxHook.get_Value() returned %ld", (long)hr);
        goto icomboboxhook_get_value_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Value = PyUnicode_FromWideChar(bsValue,::SysStringLen(bsValue));
    ::SysFreeString(bsValue);
    
    if (PyErr_Occurred())
      goto icomboboxhook_get_value_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Value);
    goto icomboboxhook_get_value_method_cleanup;

    icomboboxhook_get_value_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Value != Py_None)
        Py_XDECREF(pyvar_Value);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBoxHook.get_Value");
    return return_tuple;
}

static PyObject*
IComboBoxHookMethod_Clear(PyIComboBoxHookObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIComboBoxHook->Clear();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBoxHook->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBoxHook) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBoxHook.Clear() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IComboBoxHookMethod_Select(PyIComboBoxHookObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lcookie = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lcookie))
      goto icomboboxhook_select_method_cleanup;

    // Set up initial variable values as needed
    // No setup for cookie

    // Call method on actual COM interface
    hr = self->m_pIComboBoxHook->Select(lcookie);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBoxHook->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBoxHook) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBoxHook.Select() returned %ld", (long)hr);
        goto icomboboxhook_select_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for cookie

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto icomboboxhook_select_method_cleanup;

    icomboboxhook_select_method_cleanup:
    self->m_HR = hr;
    // No cleanup for cookie
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBoxHook.Select");
    return return_tuple;
}

static PyObject*
IComboBoxHookMethod_get_Selected(PyIComboBoxHookObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lcookie = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for cookie

    // Call method on actual COM interface
    hr = self->m_pIComboBoxHook->get_Selected(&lcookie);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBoxHook->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBoxHook) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBoxHook.get_Selected() returned %ld", (long)hr);
        goto icomboboxhook_get_selected_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for cookie

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lcookie);
    goto icomboboxhook_get_selected_method_cleanup;

    icomboboxhook_get_selected_method_cleanup:
    self->m_HR = hr;
    // No cleanup for cookie
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBoxHook.get_Selected");
    return return_tuple;
}


PyMethodDef PyIComboBoxHookMethods[] = {
    {"supports", (PyCFunction)PyIComboBoxHook_SupportsInterface, METH_O, ""},
    {"get_Hook", (PyCFunction)IComboBoxHookMethod_get_Hook, METH_VARARGS, ""},
    {"Add", (PyCFunction)IComboBoxHookMethod_Add, METH_VARARGS, ""},
    {"Remove", (PyCFunction)IComboBoxHookMethod_Remove, METH_VARARGS, ""},
    {"put_Value", (PyCFunction)IComboBoxHookMethod_put_Value, METH_VARARGS, ""},
    {"get_Value", (PyCFunction)IComboBoxHookMethod_get_Value, METH_VARARGS, ""},
    {"Clear", (PyCFunction)IComboBoxHookMethod_Clear, METH_NOARGS, ""},
    {"Select", (PyCFunction)IComboBoxHookMethod_Select, METH_VARARGS, ""},
    {"get_Selected", (PyCFunction)IComboBoxHookMethod_get_Selected, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIComboBoxHookGetSet[] = {
  {"_pUnk", (getter)PyIComboBoxHook_GetpUnk, NULL, "Get opaque pointer to an Unknown from IComboBoxHook", NULL},
  {"_pointer", (getter)PyIComboBoxHook_GetPointer, NULL, "Get memory address for IComboBoxHook", NULL},
  {"_IID", (getter)PyIComboBoxHook_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIComboBoxHook_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIComboBoxHook_GetIgnoreFailures, (setter)PyIComboBoxHook_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIComboBoxHookObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IComboBoxHookObject",                          
                                              /* tp_name */
  sizeof(PyIComboBoxHookObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIComboBoxHookObject_dealloc,      
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
  PyIComboBoxHookMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIComboBoxHookGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIComboBoxHookObject_new,                      
                                              /* tp_new */
};

// Interface IComboBox

typedef struct PyIComboBoxObject {
    PyObject_HEAD
    IComboBox* m_pIComboBox;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIComboBoxObject;

static PyObject*
PyIComboBoxObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIComboBoxObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IComboBox* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IComboBox, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IComboBox with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIComboBoxObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IComboBox");
            return NULL;
        }
        self->m_pIComboBox = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IComboBox");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IComboBox");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IComboBox* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IComboBox, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IComboBox");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIComboBoxObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IComboBox");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIComboBox = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIComboBoxObject_dealloc(PyIComboBoxObject* self)
{
    if (self->m_pIComboBox)
        self->m_pIComboBox->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIComboBox_GetpUnk(PyIComboBoxObject* self)
{
    if (!self->m_pIComboBox)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIComboBox->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IComboBox to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIComboBox_GetPointer(PyIComboBoxObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIComboBox);
}

static PyObject*
PyIComboBox_GetIID(PyIComboBoxObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "b3cf6f42-40b5-42c4-8714-0b6fd2de8c85");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIComboBox_GetHR(PyIComboBoxObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIComboBox_GetIgnoreFailures(PyIComboBoxObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIComboBox_SetIgnoreFailures(PyIComboBoxObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIComboBox_SupportsInterface(PyIComboBoxObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IComboBoxMethod_get_Editable(PyIComboBoxObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_Editable = VARIANT_FALSE;
    PyObject* pyvar_Editable = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Editable

    // Call method on actual COM interface
    hr = self->m_pIComboBox->get_Editable(&b_Editable);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.get_Editable() returned %ld", (long)hr);
        goto icombobox_get_editable_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Editable = ((b_Editable == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto icombobox_get_editable_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Editable);
    goto icombobox_get_editable_method_cleanup;

    icombobox_get_editable_method_cleanup:
    self->m_HR = hr;
    // No cleanup for Editable
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBox.get_Editable");
    return return_tuple;
}

static PyObject*
IComboBoxMethod_get_Width(PyIComboBoxObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsstringForWidth;
    PyObject* pyvar_stringForWidth = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for stringForWidth

    // Call method on actual COM interface
    hr = self->m_pIComboBox->get_Width(&bsstringForWidth);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.get_Width() returned %ld", (long)hr);
        goto icombobox_get_width_method_cleanup;
    }

    // Set up return values as needed
    pyvar_stringForWidth = PyUnicode_FromWideChar(bsstringForWidth,::SysStringLen(bsstringForWidth));
    ::SysFreeString(bsstringForWidth);
    
    if (PyErr_Occurred())
      goto icombobox_get_width_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_stringForWidth);
    goto icombobox_get_width_method_cleanup;

    icombobox_get_width_method_cleanup:
    self->m_HR = hr;
    if (pyvar_stringForWidth != Py_None)
        Py_XDECREF(pyvar_stringForWidth);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBox.get_Width");
    return return_tuple;
}

static PyObject*
IComboBoxMethod_get_DropDownWidth(PyIComboBoxObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsstringForWidth;
    PyObject* pyvar_stringForWidth = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for stringForWidth

    // Call method on actual COM interface
    hr = self->m_pIComboBox->get_DropDownWidth(&bsstringForWidth);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.get_DropDownWidth() returned %ld", (long)hr);
        goto icombobox_get_dropdownwidth_method_cleanup;
    }

    // Set up return values as needed
    pyvar_stringForWidth = PyUnicode_FromWideChar(bsstringForWidth,::SysStringLen(bsstringForWidth));
    ::SysFreeString(bsstringForWidth);
    
    if (PyErr_Occurred())
      goto icombobox_get_dropdownwidth_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_stringForWidth);
    goto icombobox_get_dropdownwidth_method_cleanup;

    icombobox_get_dropdownwidth_method_cleanup:
    self->m_HR = hr;
    if (pyvar_stringForWidth != Py_None)
        Py_XDECREF(pyvar_stringForWidth);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBox.get_DropDownWidth");
    return return_tuple;
}

static PyObject*
IComboBoxMethod_get_DropDownHeight(PyIComboBoxObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lrowsHigh = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for rowsHigh

    // Call method on actual COM interface
    hr = self->m_pIComboBox->get_DropDownHeight(&lrowsHigh);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.get_DropDownHeight() returned %ld", (long)hr);
        goto icombobox_get_dropdownheight_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for rowsHigh

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lrowsHigh);
    goto icombobox_get_dropdownheight_method_cleanup;

    icombobox_get_dropdownheight_method_cleanup:
    self->m_HR = hr;
    // No cleanup for rowsHigh
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBox.get_DropDownHeight");
    return return_tuple;
}

static PyObject*
IComboBoxMethod_get_HintText(PyIComboBoxObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsHintText;
    PyObject* pyvar_HintText = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for HintText

    // Call method on actual COM interface
    hr = self->m_pIComboBox->get_HintText(&bsHintText);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.get_HintText() returned %ld", (long)hr);
        goto icombobox_get_hinttext_method_cleanup;
    }

    // Set up return values as needed
    pyvar_HintText = PyUnicode_FromWideChar(bsHintText,::SysStringLen(bsHintText));
    ::SysFreeString(bsHintText);
    
    if (PyErr_Occurred())
      goto icombobox_get_hinttext_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_HintText);
    goto icombobox_get_hinttext_method_cleanup;

    icombobox_get_hinttext_method_cleanup:
    self->m_HR = hr;
    if (pyvar_HintText != Py_None)
        Py_XDECREF(pyvar_HintText);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBox.get_HintText");
    return return_tuple;
}

static PyObject*
IComboBoxMethod_OnSelChange(PyIComboBoxObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lcookie = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lcookie))
      goto icombobox_onselchange_method_cleanup;

    // Set up initial variable values as needed
    // No setup for cookie

    // Call method on actual COM interface
    hr = self->m_pIComboBox->OnSelChange(lcookie);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.OnSelChange() returned %ld", (long)hr);
        goto icombobox_onselchange_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for cookie

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto icombobox_onselchange_method_cleanup;

    icombobox_onselchange_method_cleanup:
    self->m_HR = hr;
    // No cleanup for cookie
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBox.OnSelChange");
    return return_tuple;
}

static PyObject*
IComboBoxMethod_OnEditChange(PyIComboBoxObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bseditString = 0;
    PyObject* pyvar_editString;
    PyObject* unicodeeditString = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_editString))
      goto icombobox_oneditchange_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_editString))
        unicodeeditString = PyUnicode_FromObject(pyvar_editString);
    else if (PyUnicode_Check(pyvar_editString))
    {
        unicodeeditString = pyvar_editString;
        Py_INCREF(unicodeeditString);
    }
    else if (pyvar_editString != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter editString at index 0");
    if (unicodeeditString)
        bseditString = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeeditString), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeeditString));
    
    if (PyErr_Occurred())
      goto icombobox_oneditchange_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIComboBox->OnEditChange(bseditString);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.OnEditChange() returned %ld", (long)hr);
        goto icombobox_oneditchange_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for editString

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto icombobox_oneditchange_method_cleanup;

    icombobox_oneditchange_method_cleanup:
    self->m_HR = hr;
    if (bseditString)
        ::SysFreeString(bseditString);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBox.OnEditChange");
    return return_tuple;
}

static PyObject*
IComboBoxMethod_OnFocus(PyIComboBoxObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_set = VARIANT_FALSE;
    PyObject* pyvar_set = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_set))
      goto icombobox_onfocus_method_cleanup;

    // Set up initial variable values as needed
    b_set = ((PyObject_IsTrue(pyvar_set) == 1)?VARIANT_TRUE:VARIANT_FALSE);
    
    if (PyErr_Occurred())
      goto icombobox_onfocus_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIComboBox->OnFocus(b_set);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.OnFocus() returned %ld", (long)hr);
        goto icombobox_onfocus_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for set

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto icombobox_onfocus_method_cleanup;

    icombobox_onfocus_method_cleanup:
    self->m_HR = hr;
    // No cleanup for set
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBox.OnFocus");
    return return_tuple;
}

static PyObject*
IComboBoxMethod_OnEnter(PyIComboBoxObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIComboBox->OnEnter();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.OnEnter() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IComboBoxMethod_get_ShowCaption(PyIComboBoxObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_ShowCaption = VARIANT_FALSE;
    PyObject* pyvar_ShowCaption = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ShowCaption

    // Call method on actual COM interface
    hr = self->m_pIComboBox->get_ShowCaption(&b_ShowCaption);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComboBox->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComboBox) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComboBox.get_ShowCaption() returned %ld", (long)hr);
        goto icombobox_get_showcaption_method_cleanup;
    }

    // Set up return values as needed
    pyvar_ShowCaption = ((b_ShowCaption == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto icombobox_get_showcaption_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_ShowCaption);
    goto icombobox_get_showcaption_method_cleanup;

    icombobox_get_showcaption_method_cleanup:
    self->m_HR = hr;
    // No cleanup for ShowCaption
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IComboBox.get_ShowCaption");
    return return_tuple;
}


PyMethodDef PyIComboBoxMethods[] = {
    {"supports", (PyCFunction)PyIComboBox_SupportsInterface, METH_O, ""},
    {"get_Editable", (PyCFunction)IComboBoxMethod_get_Editable, METH_VARARGS, ""},
    {"get_Width", (PyCFunction)IComboBoxMethod_get_Width, METH_VARARGS, ""},
    {"get_DropDownWidth", (PyCFunction)IComboBoxMethod_get_DropDownWidth, METH_VARARGS, ""},
    {"get_DropDownHeight", (PyCFunction)IComboBoxMethod_get_DropDownHeight, METH_VARARGS, ""},
    {"get_HintText", (PyCFunction)IComboBoxMethod_get_HintText, METH_VARARGS, ""},
    {"OnSelChange", (PyCFunction)IComboBoxMethod_OnSelChange, METH_VARARGS, ""},
    {"OnEditChange", (PyCFunction)IComboBoxMethod_OnEditChange, METH_VARARGS, ""},
    {"OnFocus", (PyCFunction)IComboBoxMethod_OnFocus, METH_VARARGS, ""},
    {"OnEnter", (PyCFunction)IComboBoxMethod_OnEnter, METH_NOARGS, ""},
    {"get_ShowCaption", (PyCFunction)IComboBoxMethod_get_ShowCaption, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIComboBoxGetSet[] = {
  {"_pUnk", (getter)PyIComboBox_GetpUnk, NULL, "Get opaque pointer to an Unknown from IComboBox", NULL},
  {"_pointer", (getter)PyIComboBox_GetPointer, NULL, "Get memory address for IComboBox", NULL},
  {"_IID", (getter)PyIComboBox_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIComboBox_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIComboBox_GetIgnoreFailures, (setter)PyIComboBox_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIComboBoxObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IComboBoxObject",                          
                                              /* tp_name */
  sizeof(PyIComboBoxObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIComboBoxObject_dealloc,      
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
  PyIComboBoxMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIComboBoxGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIComboBoxObject_new,                      
                                              /* tp_new */
};

// Interface ICompletionNotify

typedef struct PyICompletionNotifyObject {
    PyObject_HEAD
    ICompletionNotify* m_pICompletionNotify;
    HRESULT m_HR;
    int m_ignore_failures;
} PyICompletionNotifyObject;

static PyObject*
PyICompletionNotifyObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyICompletionNotifyObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        ICompletionNotify* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_ICompletionNotify, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate ICompletionNotify with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyICompletionNotifyObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate ICompletionNotify");
            return NULL;
        }
        self->m_pICompletionNotify = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for ICompletionNotify");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to ICompletionNotify");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    ICompletionNotify* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_ICompletionNotify, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to ICompletionNotify");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyICompletionNotifyObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate ICompletionNotify");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pICompletionNotify = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyICompletionNotifyObject_dealloc(PyICompletionNotifyObject* self)
{
    if (self->m_pICompletionNotify)
        self->m_pICompletionNotify->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyICompletionNotify_GetpUnk(PyICompletionNotifyObject* self)
{
    if (!self->m_pICompletionNotify)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pICompletionNotify->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI ICompletionNotify to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyICompletionNotify_GetPointer(PyICompletionNotifyObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pICompletionNotify);
}

static PyObject*
PyICompletionNotify_GetIID(PyICompletionNotifyObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "12f412e9-2cbc-11d2-94c8-080009eebecb");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyICompletionNotify_GetHR(PyICompletionNotifyObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyICompletionNotify_GetIgnoreFailures(PyICompletionNotifyObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyICompletionNotify_SetIgnoreFailures(PyICompletionNotifyObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyICompletionNotify_SupportsInterface(PyICompletionNotifyObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pICompletionNotify->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
ICompletionNotifyMethod_SetComplete(PyICompletionNotifyObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pICompletionNotify->SetComplete();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICompletionNotify->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICompletionNotify) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICompletionNotify.SetComplete() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}


PyMethodDef PyICompletionNotifyMethods[] = {
    {"supports", (PyCFunction)PyICompletionNotify_SupportsInterface, METH_O, ""},
    {"SetComplete", (PyCFunction)ICompletionNotifyMethod_SetComplete, METH_NOARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyICompletionNotifyGetSet[] = {
  {"_pUnk", (getter)PyICompletionNotify_GetpUnk, NULL, "Get opaque pointer to an Unknown from ICompletionNotify", NULL},
  {"_pointer", (getter)PyICompletionNotify_GetPointer, NULL, "Get memory address for ICompletionNotify", NULL},
  {"_IID", (getter)PyICompletionNotify_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyICompletionNotify_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyICompletionNotify_GetIgnoreFailures, (setter)PyICompletionNotify_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyICompletionNotifyObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.ICompletionNotifyObject",                          
                                              /* tp_name */
  sizeof(PyICompletionNotifyObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyICompletionNotifyObject_dealloc,      
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
  PyICompletionNotifyMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyICompletionNotifyGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyICompletionNotifyObject_new,                      
                                              /* tp_new */
};

// Interface IToolControl

typedef struct PyIToolControlObject {
    PyObject_HEAD
    IToolControl* m_pIToolControl;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIToolControlObject;

static PyObject*
PyIToolControlObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIToolControlObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IToolControl* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IToolControl, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IToolControl with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIToolControlObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolControl");
            return NULL;
        }
        self->m_pIToolControl = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IToolControl");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IToolControl");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IToolControl* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IToolControl, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IToolControl");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIToolControlObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolControl");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIToolControl = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIToolControlObject_dealloc(PyIToolControlObject* self)
{
    if (self->m_pIToolControl)
        self->m_pIToolControl->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIToolControl_GetpUnk(PyIToolControlObject* self)
{
    if (!self->m_pIToolControl)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIToolControl->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IToolControl to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIToolControl_GetPointer(PyIToolControlObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIToolControl);
}

static PyObject*
PyIToolControl_GetIID(PyIToolControlObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "e2287753-940f-11d0-835b-080009b996cc");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIToolControl_GetHR(PyIToolControlObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIToolControl_GetIgnoreFailures(PyIToolControlObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIToolControl_SetIgnoreFailures(PyIToolControlObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIToolControl_SupportsInterface(PyIToolControlObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIToolControl->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IToolControlMethod_get_hWnd(PyIToolControlObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    OLE_HANDLE HhWnd = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for hWnd

    // Call method on actual COM interface
    hr = self->m_pIToolControl->get_hWnd(&HhWnd);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolControl->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolControl) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolControl.get_hWnd() returned %ld", (long)hr);
        goto itoolcontrol_get_hwnd_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for hWnd

    // Initialize output tuple
    return_tuple = Py_BuildValue("I",
                                            HhWnd);
    goto itoolcontrol_get_hwnd_method_cleanup;

    itoolcontrol_get_hwnd_method_cleanup:
    self->m_HR = hr;
    // No cleanup for hWnd
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolControl.get_hWnd");
    return return_tuple;
}

static PyObject*
IToolControlMethod_OnFocus(PyIToolControlObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    ICompletionNotify* ipcomplete = NULL;
    PyObject* py_complete;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_complete))
      goto itoolcontrol_onfocus_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_complete, &IID_ICompletionNotify, (void**)&ipcomplete))
        PyErr_SetString(PyExc_TypeError, "Argument complete (position 0) is not ICompletionNotify");
    
    if (PyErr_Occurred())
      goto itoolcontrol_onfocus_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIToolControl->OnFocus(ipcomplete);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolControl->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolControl) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolControl.OnFocus() returned %ld", (long)hr);
        goto itoolcontrol_onfocus_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for complete

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto itoolcontrol_onfocus_method_cleanup;

    itoolcontrol_onfocus_method_cleanup:
    self->m_HR = hr;
    if (ipcomplete)
      ipcomplete->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolControl.OnFocus");
    return return_tuple;
}

static PyObject*
IToolControlMethod_OnDrop(PyIToolControlObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriCmdBarType ebarType;
    VARIANT_BOOL b_bValid = VARIANT_FALSE;
    PyObject* pyvar_bValid = Py_False;

    // Unpack values
    if (!PyArg_ParseTuple(args, "i", (int *)&ebarType))
      goto itoolcontrol_ondrop_method_cleanup;

    // Set up initial variable values as needed
    // No setup for barType
    // No setup for bValid

    // Call method on actual COM interface
    hr = self->m_pIToolControl->OnDrop(ebarType, &b_bValid);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolControl->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolControl) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolControl.OnDrop() returned %ld", (long)hr);
        goto itoolcontrol_ondrop_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for barType
    pyvar_bValid = ((b_bValid == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto itoolcontrol_ondrop_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bValid);
    goto itoolcontrol_ondrop_method_cleanup;

    itoolcontrol_ondrop_method_cleanup:
    self->m_HR = hr;
    // No cleanup for barType
    // No cleanup for bValid
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolControl.OnDrop");
    return return_tuple;
}


PyMethodDef PyIToolControlMethods[] = {
    {"supports", (PyCFunction)PyIToolControl_SupportsInterface, METH_O, ""},
    {"get_hWnd", (PyCFunction)IToolControlMethod_get_hWnd, METH_VARARGS, ""},
    {"OnFocus", (PyCFunction)IToolControlMethod_OnFocus, METH_VARARGS, ""},
    {"OnDrop", (PyCFunction)IToolControlMethod_OnDrop, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIToolControlGetSet[] = {
  {"_pUnk", (getter)PyIToolControl_GetpUnk, NULL, "Get opaque pointer to an Unknown from IToolControl", NULL},
  {"_pointer", (getter)PyIToolControl_GetPointer, NULL, "Get memory address for IToolControl", NULL},
  {"_IID", (getter)PyIToolControl_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIToolControl_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIToolControl_GetIgnoreFailures, (setter)PyIToolControl_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIToolControlObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IToolControlObject",                          
                                              /* tp_name */
  sizeof(PyIToolControlObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIToolControlObject_dealloc,      
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
  PyIToolControlMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIToolControlGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIToolControlObject_new,                      
                                              /* tp_new */
};

// Interface IToolPalette

typedef struct PyIToolPaletteObject {
    PyObject_HEAD
    IToolPalette* m_pIToolPalette;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIToolPaletteObject;

static PyObject*
PyIToolPaletteObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIToolPaletteObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IToolPalette* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IToolPalette, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IToolPalette with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIToolPaletteObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolPalette");
            return NULL;
        }
        self->m_pIToolPalette = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IToolPalette");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IToolPalette");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IToolPalette* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IToolPalette, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IToolPalette");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIToolPaletteObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolPalette");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIToolPalette = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIToolPaletteObject_dealloc(PyIToolPaletteObject* self)
{
    if (self->m_pIToolPalette)
        self->m_pIToolPalette->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIToolPalette_GetpUnk(PyIToolPaletteObject* self)
{
    if (!self->m_pIToolPalette)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIToolPalette->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IToolPalette to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIToolPalette_GetPointer(PyIToolPaletteObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIToolPalette);
}

static PyObject*
PyIToolPalette_GetIID(PyIToolPaletteObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "5678b14a-102b-493f-badb-1a83ae8a3830");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIToolPalette_GetHR(PyIToolPaletteObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIToolPalette_GetIgnoreFailures(PyIToolPaletteObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIToolPalette_SetIgnoreFailures(PyIToolPaletteObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIToolPalette_SupportsInterface(PyIToolPaletteObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIToolPalette->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IToolPaletteMethod_get_PaletteItemCount(PyIToolPaletteObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lnumItems = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for numItems

    // Call method on actual COM interface
    hr = self->m_pIToolPalette->get_PaletteItemCount(&lnumItems);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolPalette->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolPalette) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolPalette.get_PaletteItemCount() returned %ld", (long)hr);
        goto itoolpalette_get_paletteitemcount_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for numItems

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lnumItems);
    goto itoolpalette_get_paletteitemcount_method_cleanup;

    itoolpalette_get_paletteitemcount_method_cleanup:
    self->m_HR = hr;
    // No cleanup for numItems
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolPalette.get_PaletteItemCount");
    return return_tuple;
}

static PyObject*
IToolPaletteMethod_get_PaletteItem(PyIToolPaletteObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lpos = 0;
    BSTR bsID;
    PyObject* pyvar_ID = Py_None;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lpos))
      goto itoolpalette_get_paletteitem_method_cleanup;

    // Set up initial variable values as needed
    // No setup for pos
    // No setup for ID

    // Call method on actual COM interface
    hr = self->m_pIToolPalette->get_PaletteItem(lpos, &bsID);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolPalette->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolPalette) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolPalette.get_PaletteItem() returned %ld", (long)hr);
        goto itoolpalette_get_paletteitem_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pos
    pyvar_ID = PyUnicode_FromWideChar(bsID,::SysStringLen(bsID));
    ::SysFreeString(bsID);
    
    if (PyErr_Occurred())
      goto itoolpalette_get_paletteitem_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_ID);
    goto itoolpalette_get_paletteitem_method_cleanup;

    itoolpalette_get_paletteitem_method_cleanup:
    self->m_HR = hr;
    // No cleanup for pos
    if (pyvar_ID != Py_None)
        Py_XDECREF(pyvar_ID);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolPalette.get_PaletteItem");
    return return_tuple;
}

static PyObject*
IToolPaletteMethod_get_PaletteColumns(PyIToolPaletteObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lcolumns = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for columns

    // Call method on actual COM interface
    hr = self->m_pIToolPalette->get_PaletteColumns(&lcolumns);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolPalette->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolPalette) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolPalette.get_PaletteColumns() returned %ld", (long)hr);
        goto itoolpalette_get_palettecolumns_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for columns

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lcolumns);
    goto itoolpalette_get_palettecolumns_method_cleanup;

    itoolpalette_get_palettecolumns_method_cleanup:
    self->m_HR = hr;
    // No cleanup for columns
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolPalette.get_PaletteColumns");
    return return_tuple;
}

static PyObject*
IToolPaletteMethod_get_MenuStyle(PyIToolPaletteObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_menu = VARIANT_FALSE;
    PyObject* pyvar_menu = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for menu

    // Call method on actual COM interface
    hr = self->m_pIToolPalette->get_MenuStyle(&b_menu);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolPalette->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolPalette) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolPalette.get_MenuStyle() returned %ld", (long)hr);
        goto itoolpalette_get_menustyle_method_cleanup;
    }

    // Set up return values as needed
    pyvar_menu = ((b_menu == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto itoolpalette_get_menustyle_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_menu);
    goto itoolpalette_get_menustyle_method_cleanup;

    itoolpalette_get_menustyle_method_cleanup:
    self->m_HR = hr;
    // No cleanup for menu
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolPalette.get_MenuStyle");
    return return_tuple;
}

static PyObject*
IToolPaletteMethod_get_TearOff(PyIToolPaletteObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_TearOff = VARIANT_FALSE;
    PyObject* pyvar_TearOff = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for TearOff

    // Call method on actual COM interface
    hr = self->m_pIToolPalette->get_TearOff(&b_TearOff);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolPalette->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolPalette) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolPalette.get_TearOff() returned %ld", (long)hr);
        goto itoolpalette_get_tearoff_method_cleanup;
    }

    // Set up return values as needed
    pyvar_TearOff = ((b_TearOff == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto itoolpalette_get_tearoff_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_TearOff);
    goto itoolpalette_get_tearoff_method_cleanup;

    itoolpalette_get_tearoff_method_cleanup:
    self->m_HR = hr;
    // No cleanup for TearOff
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolPalette.get_TearOff");
    return return_tuple;
}


PyMethodDef PyIToolPaletteMethods[] = {
    {"supports", (PyCFunction)PyIToolPalette_SupportsInterface, METH_O, ""},
    {"get_PaletteItemCount", (PyCFunction)IToolPaletteMethod_get_PaletteItemCount, METH_VARARGS, ""},
    {"get_PaletteItem", (PyCFunction)IToolPaletteMethod_get_PaletteItem, METH_VARARGS, ""},
    {"get_PaletteColumns", (PyCFunction)IToolPaletteMethod_get_PaletteColumns, METH_VARARGS, ""},
    {"get_MenuStyle", (PyCFunction)IToolPaletteMethod_get_MenuStyle, METH_VARARGS, ""},
    {"get_TearOff", (PyCFunction)IToolPaletteMethod_get_TearOff, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIToolPaletteGetSet[] = {
  {"_pUnk", (getter)PyIToolPalette_GetpUnk, NULL, "Get opaque pointer to an Unknown from IToolPalette", NULL},
  {"_pointer", (getter)PyIToolPalette_GetPointer, NULL, "Get memory address for IToolPalette", NULL},
  {"_IID", (getter)PyIToolPalette_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIToolPalette_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIToolPalette_GetIgnoreFailures, (setter)PyIToolPalette_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIToolPaletteObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IToolPaletteObject",                          
                                              /* tp_name */
  sizeof(PyIToolPaletteObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIToolPaletteObject_dealloc,      
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
  PyIToolPaletteMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIToolPaletteGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIToolPaletteObject_new,                      
                                              /* tp_new */
};

// Interface ITool

typedef struct PyIToolObject {
    PyObject_HEAD
    ITool* m_pITool;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIToolObject;

static PyObject*
PyIToolObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIToolObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        ITool* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_ITool, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate ITool with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIToolObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate ITool");
            return NULL;
        }
        self->m_pITool = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for ITool");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to ITool");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    ITool* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_ITool, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to ITool");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIToolObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate ITool");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pITool = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIToolObject_dealloc(PyIToolObject* self)
{
    if (self->m_pITool)
        self->m_pITool->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyITool_GetpUnk(PyIToolObject* self)
{
    if (!self->m_pITool)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pITool->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI ITool to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyITool_GetPointer(PyIToolObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pITool);
}

static PyObject*
PyITool_GetIID(PyIToolObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "2a6b0172-4ed2-11d0-98be-00805f7ced21");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyITool_GetHR(PyIToolObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyITool_GetIgnoreFailures(PyIToolObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyITool_SetIgnoreFailures(PyIToolObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyITool_SupportsInterface(PyIToolObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pITool->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IToolMethod_get_Cursor(PyIToolObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    OLE_HANDLE HCursor = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Cursor

    // Call method on actual COM interface
    hr = self->m_pITool->get_Cursor(&HCursor);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.get_Cursor() returned %ld", (long)hr);
        goto itool_get_cursor_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Cursor

    // Initialize output tuple
    return_tuple = Py_BuildValue("I",
                                            HCursor);
    goto itool_get_cursor_method_cleanup;

    itool_get_cursor_method_cleanup:
    self->m_HR = hr;
    // No cleanup for Cursor
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ITool.get_Cursor");
    return return_tuple;
}

static PyObject*
IToolMethod_OnMouseDown(PyIToolObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lbutton = 0;
    long lshift = 0;
    long lx = 0;
    long ly = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "llll", &lbutton, &lshift, &lx, &ly))
      goto itool_onmousedown_method_cleanup;

    // Set up initial variable values as needed
    // No setup for button
    // No setup for shift
    // No setup for x
    // No setup for y

    // Call method on actual COM interface
    hr = self->m_pITool->OnMouseDown(lbutton, lshift, lx, ly);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.OnMouseDown() returned %ld", (long)hr);
        goto itool_onmousedown_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for button
    // No teardown for shift
    // No teardown for x
    // No teardown for y

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto itool_onmousedown_method_cleanup;

    itool_onmousedown_method_cleanup:
    self->m_HR = hr;
    // No cleanup for button
    // No cleanup for shift
    // No cleanup for x
    // No cleanup for y
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ITool.OnMouseDown");
    return return_tuple;
}

static PyObject*
IToolMethod_OnMouseMove(PyIToolObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lbutton = 0;
    long lshift = 0;
    long lx = 0;
    long ly = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "llll", &lbutton, &lshift, &lx, &ly))
      goto itool_onmousemove_method_cleanup;

    // Set up initial variable values as needed
    // No setup for button
    // No setup for shift
    // No setup for x
    // No setup for y

    // Call method on actual COM interface
    hr = self->m_pITool->OnMouseMove(lbutton, lshift, lx, ly);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.OnMouseMove() returned %ld", (long)hr);
        goto itool_onmousemove_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for button
    // No teardown for shift
    // No teardown for x
    // No teardown for y

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto itool_onmousemove_method_cleanup;

    itool_onmousemove_method_cleanup:
    self->m_HR = hr;
    // No cleanup for button
    // No cleanup for shift
    // No cleanup for x
    // No cleanup for y
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ITool.OnMouseMove");
    return return_tuple;
}

static PyObject*
IToolMethod_OnMouseUp(PyIToolObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lbutton = 0;
    long lshift = 0;
    long lx = 0;
    long ly = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "llll", &lbutton, &lshift, &lx, &ly))
      goto itool_onmouseup_method_cleanup;

    // Set up initial variable values as needed
    // No setup for button
    // No setup for shift
    // No setup for x
    // No setup for y

    // Call method on actual COM interface
    hr = self->m_pITool->OnMouseUp(lbutton, lshift, lx, ly);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.OnMouseUp() returned %ld", (long)hr);
        goto itool_onmouseup_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for button
    // No teardown for shift
    // No teardown for x
    // No teardown for y

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto itool_onmouseup_method_cleanup;

    itool_onmouseup_method_cleanup:
    self->m_HR = hr;
    // No cleanup for button
    // No cleanup for shift
    // No cleanup for x
    // No cleanup for y
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ITool.OnMouseUp");
    return return_tuple;
}

static PyObject*
IToolMethod_OnDblClick(PyIToolObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pITool->OnDblClick();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.OnDblClick() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IToolMethod_OnKeyDown(PyIToolObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lkeyCode = 0;
    long lshift = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "ll", &lkeyCode, &lshift))
      goto itool_onkeydown_method_cleanup;

    // Set up initial variable values as needed
    // No setup for keyCode
    // No setup for shift

    // Call method on actual COM interface
    hr = self->m_pITool->OnKeyDown(lkeyCode, lshift);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.OnKeyDown() returned %ld", (long)hr);
        goto itool_onkeydown_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for keyCode
    // No teardown for shift

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto itool_onkeydown_method_cleanup;

    itool_onkeydown_method_cleanup:
    self->m_HR = hr;
    // No cleanup for keyCode
    // No cleanup for shift
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ITool.OnKeyDown");
    return return_tuple;
}

static PyObject*
IToolMethod_OnKeyUp(PyIToolObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lkeyCode = 0;
    long lshift = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "ll", &lkeyCode, &lshift))
      goto itool_onkeyup_method_cleanup;

    // Set up initial variable values as needed
    // No setup for keyCode
    // No setup for shift

    // Call method on actual COM interface
    hr = self->m_pITool->OnKeyUp(lkeyCode, lshift);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.OnKeyUp() returned %ld", (long)hr);
        goto itool_onkeyup_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for keyCode
    // No teardown for shift

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto itool_onkeyup_method_cleanup;

    itool_onkeyup_method_cleanup:
    self->m_HR = hr;
    // No cleanup for keyCode
    // No cleanup for shift
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ITool.OnKeyUp");
    return return_tuple;
}

static PyObject*
IToolMethod_OnContextMenu(PyIToolObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lx = 0;
    long ly = 0;
    VARIANT_BOOL b_handled = VARIANT_FALSE;
    PyObject* pyvar_handled = Py_False;

    // Unpack values
    if (!PyArg_ParseTuple(args, "ll", &lx, &ly))
      goto itool_oncontextmenu_method_cleanup;

    // Set up initial variable values as needed
    // No setup for x
    // No setup for y
    // No setup for handled

    // Call method on actual COM interface
    hr = self->m_pITool->OnContextMenu(lx, ly, &b_handled);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.OnContextMenu() returned %ld", (long)hr);
        goto itool_oncontextmenu_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for x
    // No teardown for y
    pyvar_handled = ((b_handled == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto itool_oncontextmenu_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_handled);
    goto itool_oncontextmenu_method_cleanup;

    itool_oncontextmenu_method_cleanup:
    self->m_HR = hr;
    // No cleanup for x
    // No cleanup for y
    // No cleanup for handled
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ITool.OnContextMenu");
    return return_tuple;
}

static PyObject*
IToolMethod_Refresh(PyIToolObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    OLE_HANDLE Hhdc = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "I", &Hhdc))
      goto itool_refresh_method_cleanup;

    // Set up initial variable values as needed
    // No setup for hdc

    // Call method on actual COM interface
    hr = self->m_pITool->Refresh(Hhdc);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.Refresh() returned %ld", (long)hr);
        goto itool_refresh_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for hdc

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto itool_refresh_method_cleanup;

    itool_refresh_method_cleanup:
    self->m_HR = hr;
    // No cleanup for hdc
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ITool.Refresh");
    return return_tuple;
}

static PyObject*
IToolMethod_Deactivate(PyIToolObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_complete = VARIANT_FALSE;
    PyObject* pyvar_complete = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for complete

    // Call method on actual COM interface
    hr = self->m_pITool->Deactivate(&b_complete);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pITool->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ITool) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ITool.Deactivate() returned %ld", (long)hr);
        goto itool_deactivate_method_cleanup;
    }

    // Set up return values as needed
    pyvar_complete = ((b_complete == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto itool_deactivate_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_complete);
    goto itool_deactivate_method_cleanup;

    itool_deactivate_method_cleanup:
    self->m_HR = hr;
    // No cleanup for complete
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ITool.Deactivate");
    return return_tuple;
}


PyMethodDef PyIToolMethods[] = {
    {"supports", (PyCFunction)PyITool_SupportsInterface, METH_O, ""},
    {"get_Cursor", (PyCFunction)IToolMethod_get_Cursor, METH_VARARGS, ""},
    {"OnMouseDown", (PyCFunction)IToolMethod_OnMouseDown, METH_VARARGS, ""},
    {"OnMouseMove", (PyCFunction)IToolMethod_OnMouseMove, METH_VARARGS, ""},
    {"OnMouseUp", (PyCFunction)IToolMethod_OnMouseUp, METH_VARARGS, ""},
    {"OnDblClick", (PyCFunction)IToolMethod_OnDblClick, METH_NOARGS, ""},
    {"OnKeyDown", (PyCFunction)IToolMethod_OnKeyDown, METH_VARARGS, ""},
    {"OnKeyUp", (PyCFunction)IToolMethod_OnKeyUp, METH_VARARGS, ""},
    {"OnContextMenu", (PyCFunction)IToolMethod_OnContextMenu, METH_VARARGS, ""},
    {"Refresh", (PyCFunction)IToolMethod_Refresh, METH_VARARGS, ""},
    {"Deactivate", (PyCFunction)IToolMethod_Deactivate, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIToolGetSet[] = {
  {"_pUnk", (getter)PyITool_GetpUnk, NULL, "Get opaque pointer to an Unknown from ITool", NULL},
  {"_pointer", (getter)PyITool_GetPointer, NULL, "Get memory address for ITool", NULL},
  {"_IID", (getter)PyITool_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyITool_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyITool_GetIgnoreFailures, (setter)PyITool_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIToolObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IToolObject",                          
                                              /* tp_name */
  sizeof(PyIToolObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIToolObject_dealloc,      
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
  PyIToolMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIToolGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIToolObject_new,                      
                                              /* tp_new */
};

// Interface IToolKeys

typedef struct PyIToolKeysObject {
    PyObject_HEAD
    IToolKeys* m_pIToolKeys;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIToolKeysObject;

static PyObject*
PyIToolKeysObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIToolKeysObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IToolKeys* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IToolKeys, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IToolKeys with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIToolKeysObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolKeys");
            return NULL;
        }
        self->m_pIToolKeys = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IToolKeys");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IToolKeys");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IToolKeys* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IToolKeys, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IToolKeys");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIToolKeysObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolKeys");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIToolKeys = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIToolKeysObject_dealloc(PyIToolKeysObject* self)
{
    if (self->m_pIToolKeys)
        self->m_pIToolKeys->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIToolKeys_GetpUnk(PyIToolKeysObject* self)
{
    if (!self->m_pIToolKeys)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIToolKeys->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IToolKeys to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIToolKeys_GetPointer(PyIToolKeysObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIToolKeys);
}

static PyObject*
PyIToolKeys_GetIID(PyIToolKeysObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "10107f77-6a0f-413f-8e88-ede3b6dedf66");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIToolKeys_GetHR(PyIToolKeysObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIToolKeys_GetIgnoreFailures(PyIToolKeysObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIToolKeys_SetIgnoreFailures(PyIToolKeysObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIToolKeys_SupportsInterface(PyIToolKeysObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIToolKeys->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IToolKeysMethod_OverrideKey(PyIToolKeysObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lkeyCode = 0;
    long lshift = 0;
    VARIANT_BOOL b_override = VARIANT_FALSE;
    PyObject* pyvar_override = Py_False;

    // Unpack values
    if (!PyArg_ParseTuple(args, "ll", &lkeyCode, &lshift))
      goto itoolkeys_overridekey_method_cleanup;

    // Set up initial variable values as needed
    // No setup for keyCode
    // No setup for shift
    // No setup for override

    // Call method on actual COM interface
    hr = self->m_pIToolKeys->OverrideKey(lkeyCode, lshift, &b_override);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolKeys->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolKeys) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolKeys.OverrideKey() returned %ld", (long)hr);
        goto itoolkeys_overridekey_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for keyCode
    // No teardown for shift
    pyvar_override = ((b_override == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto itoolkeys_overridekey_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_override);
    goto itoolkeys_overridekey_method_cleanup;

    itoolkeys_overridekey_method_cleanup:
    self->m_HR = hr;
    // No cleanup for keyCode
    // No cleanup for shift
    // No cleanup for override
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolKeys.OverrideKey");
    return return_tuple;
}


PyMethodDef PyIToolKeysMethods[] = {
    {"supports", (PyCFunction)PyIToolKeys_SupportsInterface, METH_O, ""},
    {"OverrideKey", (PyCFunction)IToolKeysMethod_OverrideKey, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIToolKeysGetSet[] = {
  {"_pUnk", (getter)PyIToolKeys_GetpUnk, NULL, "Get opaque pointer to an Unknown from IToolKeys", NULL},
  {"_pointer", (getter)PyIToolKeys_GetPointer, NULL, "Get memory address for IToolKeys", NULL},
  {"_IID", (getter)PyIToolKeys_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIToolKeys_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIToolKeys_GetIgnoreFailures, (setter)PyIToolKeys_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIToolKeysObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IToolKeysObject",                          
                                              /* tp_name */
  sizeof(PyIToolKeysObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIToolKeysObject_dealloc,      
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
  PyIToolKeysMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIToolKeysGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIToolKeysObject_new,                      
                                              /* tp_new */
};

// Interface IItemDef

typedef struct PyIItemDefObject {
    PyObject_HEAD
    IItemDef* m_pIItemDef;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIItemDefObject;

static PyObject*
PyIItemDefObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIItemDefObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IItemDef* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IItemDef, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IItemDef with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIItemDefObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IItemDef");
            return NULL;
        }
        self->m_pIItemDef = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IItemDef");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IItemDef");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IItemDef* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IItemDef, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IItemDef");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIItemDefObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IItemDef");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIItemDef = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIItemDefObject_dealloc(PyIItemDefObject* self)
{
    if (self->m_pIItemDef)
        self->m_pIItemDef->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIItemDef_GetpUnk(PyIItemDefObject* self)
{
    if (!self->m_pIItemDef)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIItemDef->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IItemDef to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIItemDef_GetPointer(PyIItemDefObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIItemDef);
}

static PyObject*
PyIItemDef_GetIID(PyIItemDefObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "857336bf-e12b-11d1-9495-080009eebecb");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIItemDef_GetHR(PyIItemDefObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIItemDef_GetIgnoreFailures(PyIItemDefObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIItemDef_SetIgnoreFailures(PyIItemDefObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIItemDef_SupportsInterface(PyIItemDefObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIItemDef->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IItemDefMethod_put_ID(PyIItemDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bs_arg1 = 0;
    PyObject* pyvar__arg1;
    PyObject* unicode_arg1 = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar__arg1))
      goto iitemdef_put_id_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar__arg1))
        unicode_arg1 = PyUnicode_FromObject(pyvar__arg1);
    else if (PyUnicode_Check(pyvar__arg1))
    {
        unicode_arg1 = pyvar__arg1;
        Py_INCREF(unicode_arg1);
    }
    else if (pyvar__arg1 != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter _arg1 at index 0");
    if (unicode_arg1)
        bs_arg1 = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicode_arg1), 
                                            (UINT)PyUnicode_GET_SIZE(unicode_arg1));
    
    if (PyErr_Occurred())
      goto iitemdef_put_id_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIItemDef->put_ID(bs_arg1);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIItemDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IItemDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IItemDef.put_ID() returned %ld", (long)hr);
        goto iitemdef_put_id_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for _arg1

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto iitemdef_put_id_method_cleanup;

    iitemdef_put_id_method_cleanup:
    self->m_HR = hr;
    if (bs_arg1)
        ::SysFreeString(bs_arg1);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IItemDef.put_ID");
    return return_tuple;
}

static PyObject*
IItemDefMethod_put_Group(PyIItemDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b__arg1 = VARIANT_FALSE;
    PyObject* pyvar__arg1 = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar__arg1))
      goto iitemdef_put_group_method_cleanup;

    // Set up initial variable values as needed
    b__arg1 = ((PyObject_IsTrue(pyvar__arg1) == 1)?VARIANT_TRUE:VARIANT_FALSE);
    
    if (PyErr_Occurred())
      goto iitemdef_put_group_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIItemDef->put_Group(b__arg1);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIItemDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IItemDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IItemDef.put_Group() returned %ld", (long)hr);
        goto iitemdef_put_group_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for _arg1

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto iitemdef_put_group_method_cleanup;

    iitemdef_put_group_method_cleanup:
    self->m_HR = hr;
    // No cleanup for _arg1
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IItemDef.put_Group");
    return return_tuple;
}

static PyObject*
IItemDefMethod_put_SubType(PyIItemDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long l_arg1 = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &l_arg1))
      goto iitemdef_put_subtype_method_cleanup;

    // Set up initial variable values as needed
    // No setup for _arg1

    // Call method on actual COM interface
    hr = self->m_pIItemDef->put_SubType(l_arg1);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIItemDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IItemDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IItemDef.put_SubType() returned %ld", (long)hr);
        goto iitemdef_put_subtype_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for _arg1

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto iitemdef_put_subtype_method_cleanup;

    iitemdef_put_subtype_method_cleanup:
    self->m_HR = hr;
    // No cleanup for _arg1
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IItemDef.put_SubType");
    return return_tuple;
}


PyMethodDef PyIItemDefMethods[] = {
    {"supports", (PyCFunction)PyIItemDef_SupportsInterface, METH_O, ""},
    {"put_ID", (PyCFunction)IItemDefMethod_put_ID, METH_VARARGS, ""},
    {"put_Group", (PyCFunction)IItemDefMethod_put_Group, METH_VARARGS, ""},
    {"put_SubType", (PyCFunction)IItemDefMethod_put_SubType, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIItemDefGetSet[] = {
  {"_pUnk", (getter)PyIItemDef_GetpUnk, NULL, "Get opaque pointer to an Unknown from IItemDef", NULL},
  {"_pointer", (getter)PyIItemDef_GetPointer, NULL, "Get memory address for IItemDef", NULL},
  {"_IID", (getter)PyIItemDef_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIItemDef_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIItemDef_GetIgnoreFailures, (setter)PyIItemDef_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIItemDefObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IItemDefObject",                          
                                              /* tp_name */
  sizeof(PyIItemDefObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIItemDefObject_dealloc,      
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
  PyIItemDefMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIItemDefGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIItemDefObject_new,                      
                                              /* tp_new */
};

// Interface ICommandSubType

typedef struct PyICommandSubTypeObject {
    PyObject_HEAD
    ICommandSubType* m_pICommandSubType;
    HRESULT m_HR;
    int m_ignore_failures;
} PyICommandSubTypeObject;

static PyObject*
PyICommandSubTypeObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyICommandSubTypeObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        ICommandSubType* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_ICommandSubType, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate ICommandSubType with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyICommandSubTypeObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate ICommandSubType");
            return NULL;
        }
        self->m_pICommandSubType = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for ICommandSubType");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to ICommandSubType");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    ICommandSubType* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_ICommandSubType, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to ICommandSubType");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyICommandSubTypeObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate ICommandSubType");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pICommandSubType = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyICommandSubTypeObject_dealloc(PyICommandSubTypeObject* self)
{
    if (self->m_pICommandSubType)
        self->m_pICommandSubType->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyICommandSubType_GetpUnk(PyICommandSubTypeObject* self)
{
    if (!self->m_pICommandSubType)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pICommandSubType->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI ICommandSubType to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyICommandSubType_GetPointer(PyICommandSubTypeObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pICommandSubType);
}

static PyObject*
PyICommandSubType_GetIID(PyICommandSubTypeObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "5a141a5b-d096-11d1-b9a9-080009ee4e51");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyICommandSubType_GetHR(PyICommandSubTypeObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyICommandSubType_GetIgnoreFailures(PyICommandSubTypeObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyICommandSubType_SetIgnoreFailures(PyICommandSubTypeObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyICommandSubType_SupportsInterface(PyICommandSubTypeObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pICommandSubType->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
ICommandSubTypeMethod_SetSubType(PyICommandSubTypeObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lSubType = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lSubType))
      goto icommandsubtype_setsubtype_method_cleanup;

    // Set up initial variable values as needed
    // No setup for SubType

    // Call method on actual COM interface
    hr = self->m_pICommandSubType->SetSubType(lSubType);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommandSubType->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommandSubType) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommandSubType.SetSubType() returned %ld", (long)hr);
        goto icommandsubtype_setsubtype_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for SubType

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto icommandsubtype_setsubtype_method_cleanup;

    icommandsubtype_setsubtype_method_cleanup:
    self->m_HR = hr;
    // No cleanup for SubType
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommandSubType.SetSubType");
    return return_tuple;
}

static PyObject*
ICommandSubTypeMethod_GetCount(PyICommandSubTypeObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lCount = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Count

    // Call method on actual COM interface
    hr = self->m_pICommandSubType->GetCount(&lCount);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommandSubType->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommandSubType) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommandSubType.GetCount() returned %ld", (long)hr);
        goto icommandsubtype_getcount_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Count

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lCount);
    goto icommandsubtype_getcount_method_cleanup;

    icommandsubtype_getcount_method_cleanup:
    self->m_HR = hr;
    // No cleanup for Count
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommandSubType.GetCount");
    return return_tuple;
}


PyMethodDef PyICommandSubTypeMethods[] = {
    {"supports", (PyCFunction)PyICommandSubType_SupportsInterface, METH_O, ""},
    {"SetSubType", (PyCFunction)ICommandSubTypeMethod_SetSubType, METH_VARARGS, ""},
    {"GetCount", (PyCFunction)ICommandSubTypeMethod_GetCount, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyICommandSubTypeGetSet[] = {
  {"_pUnk", (getter)PyICommandSubType_GetpUnk, NULL, "Get opaque pointer to an Unknown from ICommandSubType", NULL},
  {"_pointer", (getter)PyICommandSubType_GetPointer, NULL, "Get memory address for ICommandSubType", NULL},
  {"_IID", (getter)PyICommandSubType_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyICommandSubType_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyICommandSubType_GetIgnoreFailures, (setter)PyICommandSubType_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyICommandSubTypeObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.ICommandSubTypeObject",                          
                                              /* tp_name */
  sizeof(PyICommandSubTypeObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyICommandSubTypeObject_dealloc,      
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
  PyICommandSubTypeMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyICommandSubTypeGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyICommandSubTypeObject_new,                      
                                              /* tp_new */
};

// Interface IToolBarDef

typedef struct PyIToolBarDefObject {
    PyObject_HEAD
    IToolBarDef* m_pIToolBarDef;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIToolBarDefObject;

static PyObject*
PyIToolBarDefObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIToolBarDefObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IToolBarDef* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IToolBarDef, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IToolBarDef with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIToolBarDefObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolBarDef");
            return NULL;
        }
        self->m_pIToolBarDef = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IToolBarDef");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IToolBarDef");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IToolBarDef* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IToolBarDef, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IToolBarDef");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIToolBarDefObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolBarDef");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIToolBarDef = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIToolBarDefObject_dealloc(PyIToolBarDefObject* self)
{
    if (self->m_pIToolBarDef)
        self->m_pIToolBarDef->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIToolBarDef_GetpUnk(PyIToolBarDefObject* self)
{
    if (!self->m_pIToolBarDef)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIToolBarDef->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IToolBarDef to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIToolBarDef_GetPointer(PyIToolBarDefObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIToolBarDef);
}

static PyObject*
PyIToolBarDef_GetIID(PyIToolBarDefObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "61b318f0-cda0-11d1-b9a8-080009ee4e51");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIToolBarDef_GetHR(PyIToolBarDefObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIToolBarDef_GetIgnoreFailures(PyIToolBarDefObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIToolBarDef_SetIgnoreFailures(PyIToolBarDefObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIToolBarDef_SupportsInterface(PyIToolBarDefObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIToolBarDef->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IToolBarDefMethod_get_ItemCount(PyIToolBarDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lnumItems = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for numItems

    // Call method on actual COM interface
    hr = self->m_pIToolBarDef->get_ItemCount(&lnumItems);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolBarDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolBarDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolBarDef.get_ItemCount() returned %ld", (long)hr);
        goto itoolbardef_get_itemcount_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for numItems

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lnumItems);
    goto itoolbardef_get_itemcount_method_cleanup;

    itoolbardef_get_itemcount_method_cleanup:
    self->m_HR = hr;
    // No cleanup for numItems
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolBarDef.get_ItemCount");
    return return_tuple;
}

static PyObject*
IToolBarDefMethod_GetItemInfo(PyIToolBarDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lpos = 0;
    IItemDef* ipitemDef = NULL;
    PyObject* py_itemDef;

    // Unpack values
    if (!PyArg_ParseTuple(args, "lO", &lpos, &py_itemDef))
      goto itoolbardef_getiteminfo_method_cleanup;

    // Set up initial variable values as needed
    // No setup for pos
    if (!IFaceFromPyObject(py_itemDef, &IID_IItemDef, (void**)&ipitemDef))
        PyErr_SetString(PyExc_TypeError, "Argument itemDef (position 1) is not IItemDef");
    
    if (PyErr_Occurred())
      goto itoolbardef_getiteminfo_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIToolBarDef->GetItemInfo(lpos, ipitemDef);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolBarDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolBarDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolBarDef.GetItemInfo() returned %ld", (long)hr);
        goto itoolbardef_getiteminfo_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pos
    // No teardown for itemDef

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto itoolbardef_getiteminfo_method_cleanup;

    itoolbardef_getiteminfo_method_cleanup:
    self->m_HR = hr;
    // No cleanup for pos
    if (ipitemDef)
      ipitemDef->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolBarDef.GetItemInfo");
    return return_tuple;
}

static PyObject*
IToolBarDefMethod_get_Name(PyIToolBarDefObject* self, PyObject* args)
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
    hr = self->m_pIToolBarDef->get_Name(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolBarDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolBarDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolBarDef.get_Name() returned %ld", (long)hr);
        goto itoolbardef_get_name_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto itoolbardef_get_name_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto itoolbardef_get_name_method_cleanup;

    itoolbardef_get_name_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolBarDef.get_Name");
    return return_tuple;
}

static PyObject*
IToolBarDefMethod_get_Caption(PyIToolBarDefObject* self, PyObject* args)
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
    hr = self->m_pIToolBarDef->get_Caption(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolBarDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolBarDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolBarDef.get_Caption() returned %ld", (long)hr);
        goto itoolbardef_get_caption_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto itoolbardef_get_caption_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto itoolbardef_get_caption_method_cleanup;

    itoolbardef_get_caption_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolBarDef.get_Caption");
    return return_tuple;
}


PyMethodDef PyIToolBarDefMethods[] = {
    {"supports", (PyCFunction)PyIToolBarDef_SupportsInterface, METH_O, ""},
    {"get_ItemCount", (PyCFunction)IToolBarDefMethod_get_ItemCount, METH_VARARGS, ""},
    {"GetItemInfo", (PyCFunction)IToolBarDefMethod_GetItemInfo, METH_VARARGS, ""},
    {"get_Name", (PyCFunction)IToolBarDefMethod_get_Name, METH_VARARGS, ""},
    {"get_Caption", (PyCFunction)IToolBarDefMethod_get_Caption, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIToolBarDefGetSet[] = {
  {"_pUnk", (getter)PyIToolBarDef_GetpUnk, NULL, "Get opaque pointer to an Unknown from IToolBarDef", NULL},
  {"_pointer", (getter)PyIToolBarDef_GetPointer, NULL, "Get memory address for IToolBarDef", NULL},
  {"_IID", (getter)PyIToolBarDef_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIToolBarDef_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIToolBarDef_GetIgnoreFailures, (setter)PyIToolBarDef_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIToolBarDefObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IToolBarDefObject",                          
                                              /* tp_name */
  sizeof(PyIToolBarDefObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIToolBarDefObject_dealloc,      
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
  PyIToolBarDefMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIToolBarDefGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIToolBarDefObject_new,                      
                                              /* tp_new */
};

// Interface IMenuDef

typedef struct PyIMenuDefObject {
    PyObject_HEAD
    IMenuDef* m_pIMenuDef;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIMenuDefObject;

static PyObject*
PyIMenuDefObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIMenuDefObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IMenuDef* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IMenuDef, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IMenuDef with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIMenuDefObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IMenuDef");
            return NULL;
        }
        self->m_pIMenuDef = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IMenuDef");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IMenuDef");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IMenuDef* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IMenuDef, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IMenuDef");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIMenuDefObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IMenuDef");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIMenuDef = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIMenuDefObject_dealloc(PyIMenuDefObject* self)
{
    if (self->m_pIMenuDef)
        self->m_pIMenuDef->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIMenuDef_GetpUnk(PyIMenuDefObject* self)
{
    if (!self->m_pIMenuDef)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIMenuDef->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IMenuDef to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIMenuDef_GetPointer(PyIMenuDefObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIMenuDef);
}

static PyObject*
PyIMenuDef_GetIID(PyIMenuDefObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "58e2c6a1-cd8d-11d1-91a7-0080c718df97");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIMenuDef_GetHR(PyIMenuDefObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIMenuDef_GetIgnoreFailures(PyIMenuDefObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIMenuDef_SetIgnoreFailures(PyIMenuDefObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIMenuDef_SupportsInterface(PyIMenuDefObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIMenuDef->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IMenuDefMethod_get_ItemCount(PyIMenuDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lnumItems = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for numItems

    // Call method on actual COM interface
    hr = self->m_pIMenuDef->get_ItemCount(&lnumItems);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMenuDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMenuDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMenuDef.get_ItemCount() returned %ld", (long)hr);
        goto imenudef_get_itemcount_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for numItems

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lnumItems);
    goto imenudef_get_itemcount_method_cleanup;

    imenudef_get_itemcount_method_cleanup:
    self->m_HR = hr;
    // No cleanup for numItems
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMenuDef.get_ItemCount");
    return return_tuple;
}

static PyObject*
IMenuDefMethod_GetItemInfo(PyIMenuDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lpos = 0;
    IItemDef* ipitemDef = NULL;
    PyObject* py_itemDef;

    // Unpack values
    if (!PyArg_ParseTuple(args, "lO", &lpos, &py_itemDef))
      goto imenudef_getiteminfo_method_cleanup;

    // Set up initial variable values as needed
    // No setup for pos
    if (!IFaceFromPyObject(py_itemDef, &IID_IItemDef, (void**)&ipitemDef))
        PyErr_SetString(PyExc_TypeError, "Argument itemDef (position 1) is not IItemDef");
    
    if (PyErr_Occurred())
      goto imenudef_getiteminfo_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIMenuDef->GetItemInfo(lpos, ipitemDef);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMenuDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMenuDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMenuDef.GetItemInfo() returned %ld", (long)hr);
        goto imenudef_getiteminfo_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pos
    // No teardown for itemDef

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imenudef_getiteminfo_method_cleanup;

    imenudef_getiteminfo_method_cleanup:
    self->m_HR = hr;
    // No cleanup for pos
    if (ipitemDef)
      ipitemDef->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMenuDef.GetItemInfo");
    return return_tuple;
}

static PyObject*
IMenuDefMethod_get_Name(PyIMenuDefObject* self, PyObject* args)
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
    hr = self->m_pIMenuDef->get_Name(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMenuDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMenuDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMenuDef.get_Name() returned %ld", (long)hr);
        goto imenudef_get_name_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto imenudef_get_name_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto imenudef_get_name_method_cleanup;

    imenudef_get_name_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMenuDef.get_Name");
    return return_tuple;
}

static PyObject*
IMenuDefMethod_get_Caption(PyIMenuDefObject* self, PyObject* args)
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
    hr = self->m_pIMenuDef->get_Caption(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMenuDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMenuDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMenuDef.get_Caption() returned %ld", (long)hr);
        goto imenudef_get_caption_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto imenudef_get_caption_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto imenudef_get_caption_method_cleanup;

    imenudef_get_caption_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMenuDef.get_Caption");
    return return_tuple;
}


PyMethodDef PyIMenuDefMethods[] = {
    {"supports", (PyCFunction)PyIMenuDef_SupportsInterface, METH_O, ""},
    {"get_ItemCount", (PyCFunction)IMenuDefMethod_get_ItemCount, METH_VARARGS, ""},
    {"GetItemInfo", (PyCFunction)IMenuDefMethod_GetItemInfo, METH_VARARGS, ""},
    {"get_Name", (PyCFunction)IMenuDefMethod_get_Name, METH_VARARGS, ""},
    {"get_Caption", (PyCFunction)IMenuDefMethod_get_Caption, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIMenuDefGetSet[] = {
  {"_pUnk", (getter)PyIMenuDef_GetpUnk, NULL, "Get opaque pointer to an Unknown from IMenuDef", NULL},
  {"_pointer", (getter)PyIMenuDef_GetPointer, NULL, "Get memory address for IMenuDef", NULL},
  {"_IID", (getter)PyIMenuDef_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIMenuDef_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIMenuDef_GetIgnoreFailures, (setter)PyIMenuDef_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIMenuDefObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IMenuDefObject",                          
                                              /* tp_name */
  sizeof(PyIMenuDefObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIMenuDefObject_dealloc,      
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
  PyIMenuDefMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIMenuDefGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIMenuDefObject_new,                      
                                              /* tp_new */
};

// Interface IPaletteDef

typedef struct PyIPaletteDefObject {
    PyObject_HEAD
    IPaletteDef* m_pIPaletteDef;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIPaletteDefObject;

static PyObject*
PyIPaletteDefObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIPaletteDefObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IPaletteDef* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IPaletteDef, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IPaletteDef with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIPaletteDefObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IPaletteDef");
            return NULL;
        }
        self->m_pIPaletteDef = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IPaletteDef");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IPaletteDef");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IPaletteDef* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IPaletteDef, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IPaletteDef");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIPaletteDefObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IPaletteDef");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIPaletteDef = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIPaletteDefObject_dealloc(PyIPaletteDefObject* self)
{
    if (self->m_pIPaletteDef)
        self->m_pIPaletteDef->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIPaletteDef_GetpUnk(PyIPaletteDefObject* self)
{
    if (!self->m_pIPaletteDef)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIPaletteDef->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IPaletteDef to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIPaletteDef_GetPointer(PyIPaletteDefObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIPaletteDef);
}

static PyObject*
PyIPaletteDef_GetIID(PyIPaletteDefObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "1db60dbd-ab2b-4d46-a2ee-f2fa3c5b55fb");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIPaletteDef_GetHR(PyIPaletteDefObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIPaletteDef_GetIgnoreFailures(PyIPaletteDefObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIPaletteDef_SetIgnoreFailures(PyIPaletteDefObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIPaletteDef_SupportsInterface(PyIPaletteDefObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIPaletteDef->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IPaletteDefMethod_get_Caption(PyIPaletteDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspVal;
    PyObject* pyvar_pVal = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pVal

    // Call method on actual COM interface
    hr = self->m_pIPaletteDef->get_Caption(&bspVal);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIPaletteDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IPaletteDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IPaletteDef.get_Caption() returned %ld", (long)hr);
        goto ipalettedef_get_caption_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pVal = PyUnicode_FromWideChar(bspVal,::SysStringLen(bspVal));
    ::SysFreeString(bspVal);
    
    if (PyErr_Occurred())
      goto ipalettedef_get_caption_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pVal);
    goto ipalettedef_get_caption_method_cleanup;

    ipalettedef_get_caption_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pVal != Py_None)
        Py_XDECREF(pyvar_pVal);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IPaletteDef.get_Caption");
    return return_tuple;
}

static PyObject*
IPaletteDefMethod_get_Name(PyIPaletteDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bspVal;
    PyObject* pyvar_pVal = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pVal

    // Call method on actual COM interface
    hr = self->m_pIPaletteDef->get_Name(&bspVal);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIPaletteDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IPaletteDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IPaletteDef.get_Name() returned %ld", (long)hr);
        goto ipalettedef_get_name_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pVal = PyUnicode_FromWideChar(bspVal,::SysStringLen(bspVal));
    ::SysFreeString(bspVal);
    
    if (PyErr_Occurred())
      goto ipalettedef_get_name_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pVal);
    goto ipalettedef_get_name_method_cleanup;

    ipalettedef_get_name_method_cleanup:
    self->m_HR = hr;
    if (pyvar_pVal != Py_None)
        Py_XDECREF(pyvar_pVal);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IPaletteDef.get_Name");
    return return_tuple;
}

static PyObject*
IPaletteDefMethod_get_ItemCount(PyIPaletteDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lpVal = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pVal

    // Call method on actual COM interface
    hr = self->m_pIPaletteDef->get_ItemCount(&lpVal);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIPaletteDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IPaletteDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IPaletteDef.get_ItemCount() returned %ld", (long)hr);
        goto ipalettedef_get_itemcount_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pVal

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lpVal);
    goto ipalettedef_get_itemcount_method_cleanup;

    ipalettedef_get_itemcount_method_cleanup:
    self->m_HR = hr;
    // No cleanup for pVal
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IPaletteDef.get_ItemCount");
    return return_tuple;
}

static PyObject*
IPaletteDefMethod_GetItemInfo(PyIPaletteDefObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lpos = 0;
    IItemDef* ipitemDef = NULL;
    PyObject* py_itemDef;

    // Unpack values
    if (!PyArg_ParseTuple(args, "lO", &lpos, &py_itemDef))
      goto ipalettedef_getiteminfo_method_cleanup;

    // Set up initial variable values as needed
    // No setup for pos
    if (!IFaceFromPyObject(py_itemDef, &IID_IItemDef, (void**)&ipitemDef))
        PyErr_SetString(PyExc_TypeError, "Argument itemDef (position 1) is not IItemDef");
    
    if (PyErr_Occurred())
      goto ipalettedef_getiteminfo_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIPaletteDef->GetItemInfo(lpos, ipitemDef);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIPaletteDef->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IPaletteDef) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IPaletteDef.GetItemInfo() returned %ld", (long)hr);
        goto ipalettedef_getiteminfo_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pos
    // No teardown for itemDef

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto ipalettedef_getiteminfo_method_cleanup;

    ipalettedef_getiteminfo_method_cleanup:
    self->m_HR = hr;
    // No cleanup for pos
    if (ipitemDef)
      ipitemDef->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IPaletteDef.GetItemInfo");
    return return_tuple;
}


PyMethodDef PyIPaletteDefMethods[] = {
    {"supports", (PyCFunction)PyIPaletteDef_SupportsInterface, METH_O, ""},
    {"get_Caption", (PyCFunction)IPaletteDefMethod_get_Caption, METH_VARARGS, ""},
    {"get_Name", (PyCFunction)IPaletteDefMethod_get_Name, METH_VARARGS, ""},
    {"get_ItemCount", (PyCFunction)IPaletteDefMethod_get_ItemCount, METH_VARARGS, ""},
    {"GetItemInfo", (PyCFunction)IPaletteDefMethod_GetItemInfo, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIPaletteDefGetSet[] = {
  {"_pUnk", (getter)PyIPaletteDef_GetpUnk, NULL, "Get opaque pointer to an Unknown from IPaletteDef", NULL},
  {"_pointer", (getter)PyIPaletteDef_GetPointer, NULL, "Get memory address for IPaletteDef", NULL},
  {"_IID", (getter)PyIPaletteDef_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIPaletteDef_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIPaletteDef_GetIgnoreFailures, (setter)PyIPaletteDef_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIPaletteDefObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IPaletteDefObject",                          
                                              /* tp_name */
  sizeof(PyIPaletteDefObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIPaletteDefObject_dealloc,      
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
  PyIPaletteDefMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIPaletteDefGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIPaletteDefObject_new,                      
                                              /* tp_new */
};

// Interface IMultiItemSeparator

typedef struct PyIMultiItemSeparatorObject {
    PyObject_HEAD
    IMultiItemSeparator* m_pIMultiItemSeparator;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIMultiItemSeparatorObject;

static PyObject*
PyIMultiItemSeparatorObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIMultiItemSeparatorObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IMultiItemSeparator* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IMultiItemSeparator, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IMultiItemSeparator with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIMultiItemSeparatorObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IMultiItemSeparator");
            return NULL;
        }
        self->m_pIMultiItemSeparator = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IMultiItemSeparator");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IMultiItemSeparator");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IMultiItemSeparator* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IMultiItemSeparator, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IMultiItemSeparator");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIMultiItemSeparatorObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IMultiItemSeparator");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIMultiItemSeparator = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIMultiItemSeparatorObject_dealloc(PyIMultiItemSeparatorObject* self)
{
    if (self->m_pIMultiItemSeparator)
        self->m_pIMultiItemSeparator->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIMultiItemSeparator_GetpUnk(PyIMultiItemSeparatorObject* self)
{
    if (!self->m_pIMultiItemSeparator)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIMultiItemSeparator->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IMultiItemSeparator to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIMultiItemSeparator_GetPointer(PyIMultiItemSeparatorObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIMultiItemSeparator);
}

static PyObject*
PyIMultiItemSeparator_GetIID(PyIMultiItemSeparatorObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "5398cee2-0a8e-4bdf-af26-77c9af2ebc63");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIMultiItemSeparator_GetHR(PyIMultiItemSeparatorObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIMultiItemSeparator_GetIgnoreFailures(PyIMultiItemSeparatorObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIMultiItemSeparator_SetIgnoreFailures(PyIMultiItemSeparatorObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIMultiItemSeparator_SupportsInterface(PyIMultiItemSeparatorObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIMultiItemSeparator->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IMultiItemSeparatorMethod_get_Separator(PyIMultiItemSeparatorObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    VARIANT_BOOL b_bSeparator = VARIANT_FALSE;
    PyObject* pyvar_bSeparator = Py_False;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto imultiitemseparator_get_separator_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    // No setup for bSeparator

    // Call method on actual COM interface
    hr = self->m_pIMultiItemSeparator->get_Separator(lindex, &b_bSeparator);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItemSeparator->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItemSeparator) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItemSeparator.get_Separator() returned %ld", (long)hr);
        goto imultiitemseparator_get_separator_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    pyvar_bSeparator = ((b_bSeparator == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto imultiitemseparator_get_separator_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bSeparator);
    goto imultiitemseparator_get_separator_method_cleanup;

    imultiitemseparator_get_separator_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    // No cleanup for bSeparator
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItemSeparator.get_Separator");
    return return_tuple;
}


PyMethodDef PyIMultiItemSeparatorMethods[] = {
    {"supports", (PyCFunction)PyIMultiItemSeparator_SupportsInterface, METH_O, ""},
    {"get_Separator", (PyCFunction)IMultiItemSeparatorMethod_get_Separator, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIMultiItemSeparatorGetSet[] = {
  {"_pUnk", (getter)PyIMultiItemSeparator_GetpUnk, NULL, "Get opaque pointer to an Unknown from IMultiItemSeparator", NULL},
  {"_pointer", (getter)PyIMultiItemSeparator_GetPointer, NULL, "Get memory address for IMultiItemSeparator", NULL},
  {"_IID", (getter)PyIMultiItemSeparator_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIMultiItemSeparator_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIMultiItemSeparator_GetIgnoreFailures, (setter)PyIMultiItemSeparator_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIMultiItemSeparatorObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IMultiItemSeparatorObject",                          
                                              /* tp_name */
  sizeof(PyIMultiItemSeparatorObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIMultiItemSeparatorObject_dealloc,      
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
  PyIMultiItemSeparatorMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIMultiItemSeparatorGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIMultiItemSeparatorObject_new,                      
                                              /* tp_new */
};

// Interface IMultiItem

typedef struct PyIMultiItemObject {
    PyObject_HEAD
    IMultiItem* m_pIMultiItem;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIMultiItemObject;

static PyObject*
PyIMultiItemObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIMultiItemObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IMultiItem* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IMultiItem, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IMultiItem with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIMultiItemObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IMultiItem");
            return NULL;
        }
        self->m_pIMultiItem = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IMultiItem");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IMultiItem");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IMultiItem* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IMultiItem, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IMultiItem");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIMultiItemObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IMultiItem");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIMultiItem = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIMultiItemObject_dealloc(PyIMultiItemObject* self)
{
    if (self->m_pIMultiItem)
        self->m_pIMultiItem->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIMultiItem_GetpUnk(PyIMultiItemObject* self)
{
    if (!self->m_pIMultiItem)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIMultiItem->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IMultiItem to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIMultiItem_GetPointer(PyIMultiItemObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIMultiItem);
}

static PyObject*
PyIMultiItem_GetIID(PyIMultiItemObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "af948931-11d1-11d2-94b4-080009eebecb");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIMultiItem_GetHR(PyIMultiItemObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIMultiItem_GetIgnoreFailures(PyIMultiItemObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIMultiItem_SetIgnoreFailures(PyIMultiItemObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIMultiItem_SupportsInterface(PyIMultiItemObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IMultiItemMethod_get_Name(PyIMultiItemObject* self, PyObject* args)
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
    hr = self->m_pIMultiItem->get_Name(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.get_Name() returned %ld", (long)hr);
        goto imultiitem_get_name_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto imultiitem_get_name_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto imultiitem_get_name_method_cleanup;

    imultiitem_get_name_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.get_Name");
    return return_tuple;
}

static PyObject*
IMultiItemMethod_get_Caption(PyIMultiItemObject* self, PyObject* args)
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
    hr = self->m_pIMultiItem->get_Caption(&bsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.get_Caption() returned %ld", (long)hr);
        goto imultiitem_get_caption_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Name = PyUnicode_FromWideChar(bsName,::SysStringLen(bsName));
    ::SysFreeString(bsName);
    
    if (PyErr_Occurred())
      goto imultiitem_get_caption_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Name);
    goto imultiitem_get_caption_method_cleanup;

    imultiitem_get_caption_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Name != Py_None)
        Py_XDECREF(pyvar_Name);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.get_Caption");
    return return_tuple;
}

static PyObject*
IMultiItemMethod_get_Message(PyIMultiItemObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsMessage;
    PyObject* pyvar_Message = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Message

    // Call method on actual COM interface
    hr = self->m_pIMultiItem->get_Message(&bsMessage);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.get_Message() returned %ld", (long)hr);
        goto imultiitem_get_message_method_cleanup;
    }

    // Set up return values as needed
    pyvar_Message = PyUnicode_FromWideChar(bsMessage,::SysStringLen(bsMessage));
    ::SysFreeString(bsMessage);
    
    if (PyErr_Occurred())
      goto imultiitem_get_message_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Message);
    goto imultiitem_get_message_method_cleanup;

    imultiitem_get_message_method_cleanup:
    self->m_HR = hr;
    if (pyvar_Message != Py_None)
        Py_XDECREF(pyvar_Message);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.get_Message");
    return return_tuple;
}

static PyObject*
IMultiItemMethod_get_HelpFile(PyIMultiItemObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsHelpFile;
    PyObject* pyvar_HelpFile = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for HelpFile

    // Call method on actual COM interface
    hr = self->m_pIMultiItem->get_HelpFile(&bsHelpFile);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.get_HelpFile() returned %ld", (long)hr);
        goto imultiitem_get_helpfile_method_cleanup;
    }

    // Set up return values as needed
    pyvar_HelpFile = PyUnicode_FromWideChar(bsHelpFile,::SysStringLen(bsHelpFile));
    ::SysFreeString(bsHelpFile);
    
    if (PyErr_Occurred())
      goto imultiitem_get_helpfile_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_HelpFile);
    goto imultiitem_get_helpfile_method_cleanup;

    imultiitem_get_helpfile_method_cleanup:
    self->m_HR = hr;
    if (pyvar_HelpFile != Py_None)
        Py_XDECREF(pyvar_HelpFile);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.get_HelpFile");
    return return_tuple;
}

static PyObject*
IMultiItemMethod_get_HelpContextID(PyIMultiItemObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lID = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ID

    // Call method on actual COM interface
    hr = self->m_pIMultiItem->get_HelpContextID(&lID);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.get_HelpContextID() returned %ld", (long)hr);
        goto imultiitem_get_helpcontextid_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for ID

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lID);
    goto imultiitem_get_helpcontextid_method_cleanup;

    imultiitem_get_helpcontextid_method_cleanup:
    self->m_HR = hr;
    // No cleanup for ID
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.get_HelpContextID");
    return return_tuple;
}

static PyObject*
IMultiItemMethod_OnPopup(PyIMultiItemObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'IDispatch', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IMultiItem.OnPopup not implemented.");
    return NULL;
}

static PyObject*
IMultiItemMethod_get_ItemCaption(PyIMultiItemObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    BSTR bsitemName;
    PyObject* pyvar_itemName = Py_None;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto imultiitem_get_itemcaption_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    // No setup for itemName

    // Call method on actual COM interface
    hr = self->m_pIMultiItem->get_ItemCaption(lindex, &bsitemName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.get_ItemCaption() returned %ld", (long)hr);
        goto imultiitem_get_itemcaption_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    pyvar_itemName = PyUnicode_FromWideChar(bsitemName,::SysStringLen(bsitemName));
    ::SysFreeString(bsitemName);
    
    if (PyErr_Occurred())
      goto imultiitem_get_itemcaption_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_itemName);
    goto imultiitem_get_itemcaption_method_cleanup;

    imultiitem_get_itemcaption_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    if (pyvar_itemName != Py_None)
        Py_XDECREF(pyvar_itemName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.get_ItemCaption");
    return return_tuple;
}

static PyObject*
IMultiItemMethod_get_ItemBitmap(PyIMultiItemObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    OLE_HANDLE HBitmap = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto imultiitem_get_itembitmap_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    // No setup for Bitmap

    // Call method on actual COM interface
    hr = self->m_pIMultiItem->get_ItemBitmap(lindex, &HBitmap);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.get_ItemBitmap() returned %ld", (long)hr);
        goto imultiitem_get_itembitmap_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    // No teardown for Bitmap

    // Initialize output tuple
    return_tuple = Py_BuildValue("I",
                                            HBitmap);
    goto imultiitem_get_itembitmap_method_cleanup;

    imultiitem_get_itembitmap_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    // No cleanup for Bitmap
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.get_ItemBitmap");
    return return_tuple;
}

static PyObject*
IMultiItemMethod_OnItemClick(PyIMultiItemObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto imultiitem_onitemclick_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index

    // Call method on actual COM interface
    hr = self->m_pIMultiItem->OnItemClick(lindex);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.OnItemClick() returned %ld", (long)hr);
        goto imultiitem_onitemclick_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto imultiitem_onitemclick_method_cleanup;

    imultiitem_onitemclick_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.OnItemClick");
    return return_tuple;
}

static PyObject*
IMultiItemMethod_get_ItemChecked(PyIMultiItemObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    VARIANT_BOOL b_bChecked = VARIANT_FALSE;
    PyObject* pyvar_bChecked = Py_False;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto imultiitem_get_itemchecked_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    // No setup for bChecked

    // Call method on actual COM interface
    hr = self->m_pIMultiItem->get_ItemChecked(lindex, &b_bChecked);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.get_ItemChecked() returned %ld", (long)hr);
        goto imultiitem_get_itemchecked_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    pyvar_bChecked = ((b_bChecked == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto imultiitem_get_itemchecked_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bChecked);
    goto imultiitem_get_itemchecked_method_cleanup;

    imultiitem_get_itemchecked_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    // No cleanup for bChecked
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.get_ItemChecked");
    return return_tuple;
}

static PyObject*
IMultiItemMethod_get_ItemEnabled(PyIMultiItemObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    VARIANT_BOOL b_bEnabled = VARIANT_FALSE;
    PyObject* pyvar_bEnabled = Py_False;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto imultiitem_get_itemenabled_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    // No setup for bEnabled

    // Call method on actual COM interface
    hr = self->m_pIMultiItem->get_ItemEnabled(lindex, &b_bEnabled);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItem->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItem) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItem.get_ItemEnabled() returned %ld", (long)hr);
        goto imultiitem_get_itemenabled_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    pyvar_bEnabled = ((b_bEnabled == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto imultiitem_get_itemenabled_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bEnabled);
    goto imultiitem_get_itemenabled_method_cleanup;

    imultiitem_get_itemenabled_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    // No cleanup for bEnabled
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItem.get_ItemEnabled");
    return return_tuple;
}


PyMethodDef PyIMultiItemMethods[] = {
    {"supports", (PyCFunction)PyIMultiItem_SupportsInterface, METH_O, ""},
    {"get_Name", (PyCFunction)IMultiItemMethod_get_Name, METH_VARARGS, ""},
    {"get_Caption", (PyCFunction)IMultiItemMethod_get_Caption, METH_VARARGS, ""},
    {"get_Message", (PyCFunction)IMultiItemMethod_get_Message, METH_VARARGS, ""},
    {"get_HelpFile", (PyCFunction)IMultiItemMethod_get_HelpFile, METH_VARARGS, ""},
    {"get_HelpContextID", (PyCFunction)IMultiItemMethod_get_HelpContextID, METH_VARARGS, ""},
    {"OnPopup", (PyCFunction)IMultiItemMethod_OnPopup, METH_VARARGS, ""},
    {"get_ItemCaption", (PyCFunction)IMultiItemMethod_get_ItemCaption, METH_VARARGS, ""},
    {"get_ItemBitmap", (PyCFunction)IMultiItemMethod_get_ItemBitmap, METH_VARARGS, ""},
    {"OnItemClick", (PyCFunction)IMultiItemMethod_OnItemClick, METH_VARARGS, ""},
    {"get_ItemChecked", (PyCFunction)IMultiItemMethod_get_ItemChecked, METH_VARARGS, ""},
    {"get_ItemEnabled", (PyCFunction)IMultiItemMethod_get_ItemEnabled, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIMultiItemGetSet[] = {
  {"_pUnk", (getter)PyIMultiItem_GetpUnk, NULL, "Get opaque pointer to an Unknown from IMultiItem", NULL},
  {"_pointer", (getter)PyIMultiItem_GetPointer, NULL, "Get memory address for IMultiItem", NULL},
  {"_IID", (getter)PyIMultiItem_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIMultiItem_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIMultiItem_GetIgnoreFailures, (setter)PyIMultiItem_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIMultiItemObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IMultiItemObject",                          
                                              /* tp_name */
  sizeof(PyIMultiItemObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIMultiItemObject_dealloc,      
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
  PyIMultiItemMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIMultiItemGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIMultiItemObject_new,                      
                                              /* tp_new */
};

// Interface IMultiItemEx

typedef struct PyIMultiItemExObject {
    PyObject_HEAD
    IMultiItemEx* m_pIMultiItemEx;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIMultiItemExObject;

static PyObject*
PyIMultiItemExObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIMultiItemExObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IMultiItemEx* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IMultiItemEx, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IMultiItemEx with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIMultiItemExObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IMultiItemEx");
            return NULL;
        }
        self->m_pIMultiItemEx = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IMultiItemEx");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IMultiItemEx");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IMultiItemEx* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IMultiItemEx, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IMultiItemEx");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIMultiItemExObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IMultiItemEx");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIMultiItemEx = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIMultiItemExObject_dealloc(PyIMultiItemExObject* self)
{
    if (self->m_pIMultiItemEx)
        self->m_pIMultiItemEx->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIMultiItemEx_GetpUnk(PyIMultiItemExObject* self)
{
    if (!self->m_pIMultiItemEx)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIMultiItemEx->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IMultiItemEx to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIMultiItemEx_GetPointer(PyIMultiItemExObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIMultiItemEx);
}

static PyObject*
PyIMultiItemEx_GetIID(PyIMultiItemExObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "1e29f387-f77a-42cc-ad58-5fb1f5f8e11d");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIMultiItemEx_GetHR(PyIMultiItemExObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIMultiItemEx_GetIgnoreFailures(PyIMultiItemExObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIMultiItemEx_SetIgnoreFailures(PyIMultiItemExObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIMultiItemEx_SupportsInterface(PyIMultiItemExObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIMultiItemEx->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IMultiItemExMethod_get_ItemMessage(PyIMultiItemExObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    BSTR bsMessage;
    PyObject* pyvar_Message = Py_None;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto imultiitemex_get_itemmessage_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    // No setup for Message

    // Call method on actual COM interface
    hr = self->m_pIMultiItemEx->get_ItemMessage(lindex, &bsMessage);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItemEx->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItemEx) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItemEx.get_ItemMessage() returned %ld", (long)hr);
        goto imultiitemex_get_itemmessage_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    pyvar_Message = PyUnicode_FromWideChar(bsMessage,::SysStringLen(bsMessage));
    ::SysFreeString(bsMessage);
    
    if (PyErr_Occurred())
      goto imultiitemex_get_itemmessage_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_Message);
    goto imultiitemex_get_itemmessage_method_cleanup;

    imultiitemex_get_itemmessage_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    if (pyvar_Message != Py_None)
        Py_XDECREF(pyvar_Message);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItemEx.get_ItemMessage");
    return return_tuple;
}

static PyObject*
IMultiItemExMethod_get_ItemHelpFile(PyIMultiItemExObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    BSTR bsHelpFile;
    PyObject* pyvar_HelpFile = Py_None;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto imultiitemex_get_itemhelpfile_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    // No setup for HelpFile

    // Call method on actual COM interface
    hr = self->m_pIMultiItemEx->get_ItemHelpFile(lindex, &bsHelpFile);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItemEx->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItemEx) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItemEx.get_ItemHelpFile() returned %ld", (long)hr);
        goto imultiitemex_get_itemhelpfile_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    pyvar_HelpFile = PyUnicode_FromWideChar(bsHelpFile,::SysStringLen(bsHelpFile));
    ::SysFreeString(bsHelpFile);
    
    if (PyErr_Occurred())
      goto imultiitemex_get_itemhelpfile_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_HelpFile);
    goto imultiitemex_get_itemhelpfile_method_cleanup;

    imultiitemex_get_itemhelpfile_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    if (pyvar_HelpFile != Py_None)
        Py_XDECREF(pyvar_HelpFile);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItemEx.get_ItemHelpFile");
    return return_tuple;
}

static PyObject*
IMultiItemExMethod_get_ItemHelpContextID(PyIMultiItemExObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    long lID = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto imultiitemex_get_itemhelpcontextid_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    // No setup for ID

    // Call method on actual COM interface
    hr = self->m_pIMultiItemEx->get_ItemHelpContextID(lindex, &lID);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIMultiItemEx->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IMultiItemEx) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IMultiItemEx.get_ItemHelpContextID() returned %ld", (long)hr);
        goto imultiitemex_get_itemhelpcontextid_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    // No teardown for ID

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lID);
    goto imultiitemex_get_itemhelpcontextid_method_cleanup;

    imultiitemex_get_itemhelpcontextid_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    // No cleanup for ID
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IMultiItemEx.get_ItemHelpContextID");
    return return_tuple;
}


PyMethodDef PyIMultiItemExMethods[] = {
    {"supports", (PyCFunction)PyIMultiItemEx_SupportsInterface, METH_O, ""},
    {"get_ItemMessage", (PyCFunction)IMultiItemExMethod_get_ItemMessage, METH_VARARGS, ""},
    {"get_ItemHelpFile", (PyCFunction)IMultiItemExMethod_get_ItemHelpFile, METH_VARARGS, ""},
    {"get_ItemHelpContextID", (PyCFunction)IMultiItemExMethod_get_ItemHelpContextID, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIMultiItemExGetSet[] = {
  {"_pUnk", (getter)PyIMultiItemEx_GetpUnk, NULL, "Get opaque pointer to an Unknown from IMultiItemEx", NULL},
  {"_pointer", (getter)PyIMultiItemEx_GetPointer, NULL, "Get memory address for IMultiItemEx", NULL},
  {"_IID", (getter)PyIMultiItemEx_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIMultiItemEx_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIMultiItemEx_GetIgnoreFailures, (setter)PyIMultiItemEx_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIMultiItemExObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IMultiItemExObject",                          
                                              /* tp_name */
  sizeof(PyIMultiItemExObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIMultiItemExObject_dealloc,      
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
  PyIMultiItemExMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIMultiItemExGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIMultiItemExObject_new,                      
                                              /* tp_new */
};

// Interface IComPropertySheetEvents

typedef struct PyIComPropertySheetEventsObject {
    PyObject_HEAD
    IComPropertySheetEvents* m_pIComPropertySheetEvents;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIComPropertySheetEventsObject;

static PyObject*
PyIComPropertySheetEventsObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIComPropertySheetEventsObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IComPropertySheetEvents* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IComPropertySheetEvents, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IComPropertySheetEvents with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIComPropertySheetEventsObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IComPropertySheetEvents");
            return NULL;
        }
        self->m_pIComPropertySheetEvents = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IComPropertySheetEvents");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IComPropertySheetEvents");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IComPropertySheetEvents* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IComPropertySheetEvents, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IComPropertySheetEvents");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIComPropertySheetEventsObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IComPropertySheetEvents");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIComPropertySheetEvents = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIComPropertySheetEventsObject_dealloc(PyIComPropertySheetEventsObject* self)
{
    if (self->m_pIComPropertySheetEvents)
        self->m_pIComPropertySheetEvents->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIComPropertySheetEvents_GetpUnk(PyIComPropertySheetEventsObject* self)
{
    if (!self->m_pIComPropertySheetEvents)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIComPropertySheetEvents->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IComPropertySheetEvents to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIComPropertySheetEvents_GetPointer(PyIComPropertySheetEventsObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIComPropertySheetEvents);
}

static PyObject*
PyIComPropertySheetEvents_GetIID(PyIComPropertySheetEventsObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "6b7b57f8-5765-11d0-92d9-00805f7c28b0");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIComPropertySheetEvents_GetHR(PyIComPropertySheetEventsObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIComPropertySheetEvents_GetIgnoreFailures(PyIComPropertySheetEventsObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIComPropertySheetEvents_SetIgnoreFailures(PyIComPropertySheetEventsObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIComPropertySheetEvents_SupportsInterface(PyIComPropertySheetEventsObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIComPropertySheetEvents->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IComPropertySheetEventsMethod_OnApply(PyIComPropertySheetEventsObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIComPropertySheetEvents->OnApply();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIComPropertySheetEvents->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IComPropertySheetEvents) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IComPropertySheetEvents.OnApply() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}


PyMethodDef PyIComPropertySheetEventsMethods[] = {
    {"supports", (PyCFunction)PyIComPropertySheetEvents_SupportsInterface, METH_O, ""},
    {"OnApply", (PyCFunction)IComPropertySheetEventsMethod_OnApply, METH_NOARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIComPropertySheetEventsGetSet[] = {
  {"_pUnk", (getter)PyIComPropertySheetEvents_GetpUnk, NULL, "Get opaque pointer to an Unknown from IComPropertySheetEvents", NULL},
  {"_pointer", (getter)PyIComPropertySheetEvents_GetPointer, NULL, "Get memory address for IComPropertySheetEvents", NULL},
  {"_IID", (getter)PyIComPropertySheetEvents_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIComPropertySheetEvents_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIComPropertySheetEvents_GetIgnoreFailures, (setter)PyIComPropertySheetEvents_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIComPropertySheetEventsObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IComPropertySheetEventsObject",                          
                                              /* tp_name */
  sizeof(PyIComPropertySheetEventsObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIComPropertySheetEventsObject_dealloc,      
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
  PyIComPropertySheetEventsMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIComPropertySheetEventsGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIComPropertySheetEventsObject_new,                      
                                              /* tp_new */
};

// Interface IOperation

typedef struct PyIOperationObject {
    PyObject_HEAD
    IOperation* m_pIOperation;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIOperationObject;

static PyObject*
PyIOperationObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIOperationObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IOperation* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IOperation, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IOperation with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIOperationObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IOperation");
            return NULL;
        }
        self->m_pIOperation = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IOperation");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IOperation");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IOperation* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IOperation, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IOperation");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIOperationObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IOperation");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIOperation = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIOperationObject_dealloc(PyIOperationObject* self)
{
    if (self->m_pIOperation)
        self->m_pIOperation->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIOperation_GetpUnk(PyIOperationObject* self)
{
    if (!self->m_pIOperation)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIOperation->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IOperation to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIOperation_GetPointer(PyIOperationObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIOperation);
}

static PyObject*
PyIOperation_GetIID(PyIOperationObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "80a807ab-7bb9-11d0-87ec-080009ec732a");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIOperation_GetHR(PyIOperationObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIOperation_GetIgnoreFailures(PyIOperationObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIOperation_SetIgnoreFailures(PyIOperationObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIOperation_SupportsInterface(PyIOperationObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIOperation->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IOperationMethod_get_MenuString(PyIOperationObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bstext;
    PyObject* pyvar_text = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for text

    // Call method on actual COM interface
    hr = self->m_pIOperation->get_MenuString(&bstext);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperation->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperation) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperation.get_MenuString() returned %ld", (long)hr);
        goto ioperation_get_menustring_method_cleanup;
    }

    // Set up return values as needed
    pyvar_text = PyUnicode_FromWideChar(bstext,::SysStringLen(bstext));
    ::SysFreeString(bstext);
    
    if (PyErr_Occurred())
      goto ioperation_get_menustring_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_text);
    goto ioperation_get_menustring_method_cleanup;

    ioperation_get_menustring_method_cleanup:
    self->m_HR = hr;
    if (pyvar_text != Py_None)
        Py_XDECREF(pyvar_text);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOperation.get_MenuString");
    return return_tuple;
}

static PyObject*
IOperationMethod_get_CanUndo(PyIOperationObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_result = VARIANT_FALSE;
    PyObject* pyvar_result = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for result

    // Call method on actual COM interface
    hr = self->m_pIOperation->get_CanUndo(&b_result);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperation->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperation) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperation.get_CanUndo() returned %ld", (long)hr);
        goto ioperation_get_canundo_method_cleanup;
    }

    // Set up return values as needed
    pyvar_result = ((b_result == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto ioperation_get_canundo_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_result);
    goto ioperation_get_canundo_method_cleanup;

    ioperation_get_canundo_method_cleanup:
    self->m_HR = hr;
    // No cleanup for result
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOperation.get_CanUndo");
    return return_tuple;
}

static PyObject*
IOperationMethod_get_CanRedo(PyIOperationObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_result = VARIANT_FALSE;
    PyObject* pyvar_result = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for result

    // Call method on actual COM interface
    hr = self->m_pIOperation->get_CanRedo(&b_result);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperation->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperation) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperation.get_CanRedo() returned %ld", (long)hr);
        goto ioperation_get_canredo_method_cleanup;
    }

    // Set up return values as needed
    pyvar_result = ((b_result == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto ioperation_get_canredo_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_result);
    goto ioperation_get_canredo_method_cleanup;

    ioperation_get_canredo_method_cleanup:
    self->m_HR = hr;
    // No cleanup for result
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOperation.get_CanRedo");
    return return_tuple;
}

static PyObject*
IOperationMethod_Do(PyIOperationObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIOperation->Do();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperation->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperation) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperation.Do() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IOperationMethod_Undo(PyIOperationObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIOperation->Undo();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperation->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperation) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperation.Undo() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IOperationMethod_Redo(PyIOperationObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIOperation->Redo();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperation->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperation) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperation.Redo() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}


PyMethodDef PyIOperationMethods[] = {
    {"supports", (PyCFunction)PyIOperation_SupportsInterface, METH_O, ""},
    {"get_MenuString", (PyCFunction)IOperationMethod_get_MenuString, METH_VARARGS, ""},
    {"get_CanUndo", (PyCFunction)IOperationMethod_get_CanUndo, METH_VARARGS, ""},
    {"get_CanRedo", (PyCFunction)IOperationMethod_get_CanRedo, METH_VARARGS, ""},
    {"Do", (PyCFunction)IOperationMethod_Do, METH_NOARGS, ""},
    {"Undo", (PyCFunction)IOperationMethod_Undo, METH_NOARGS, ""},
    {"Redo", (PyCFunction)IOperationMethod_Redo, METH_NOARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIOperationGetSet[] = {
  {"_pUnk", (getter)PyIOperation_GetpUnk, NULL, "Get opaque pointer to an Unknown from IOperation", NULL},
  {"_pointer", (getter)PyIOperation_GetPointer, NULL, "Get memory address for IOperation", NULL},
  {"_IID", (getter)PyIOperation_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIOperation_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIOperation_GetIgnoreFailures, (setter)PyIOperation_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIOperationObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IOperationObject",                          
                                              /* tp_name */
  sizeof(PyIOperationObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIOperationObject_dealloc,      
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
  PyIOperationMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIOperationGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIOperationObject_new,                      
                                              /* tp_new */
};

// Interface IOperationStack

typedef struct PyIOperationStackObject {
    PyObject_HEAD
    IOperationStack* m_pIOperationStack;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIOperationStackObject;

static PyObject*
PyIOperationStackObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIOperationStackObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IOperationStack* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IOperationStack, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IOperationStack with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIOperationStackObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IOperationStack");
            return NULL;
        }
        self->m_pIOperationStack = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IOperationStack");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IOperationStack");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IOperationStack* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IOperationStack, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IOperationStack");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIOperationStackObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IOperationStack");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIOperationStack = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIOperationStackObject_dealloc(PyIOperationStackObject* self)
{
    if (self->m_pIOperationStack)
        self->m_pIOperationStack->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIOperationStack_GetpUnk(PyIOperationStackObject* self)
{
    if (!self->m_pIOperationStack)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIOperationStack->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IOperationStack to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIOperationStack_GetPointer(PyIOperationStackObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIOperationStack);
}

static PyObject*
PyIOperationStack_GetIID(PyIOperationStackObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "303ee675-3087-11d2-94c9-080009eebecb");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIOperationStack_GetHR(PyIOperationStackObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIOperationStack_GetIgnoreFailures(PyIOperationStackObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIOperationStack_SetIgnoreFailures(PyIOperationStackObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIOperationStack_SupportsInterface(PyIOperationStackObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IOperationStackMethod_get_Count(PyIOperationStackObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lCount = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for Count

    // Call method on actual COM interface
    hr = self->m_pIOperationStack->get_Count(&lCount);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperationStack) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperationStack.get_Count() returned %ld", (long)hr);
        goto ioperationstack_get_count_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for Count

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lCount);
    goto ioperationstack_get_count_method_cleanup;

    ioperationstack_get_count_method_cleanup:
    self->m_HR = hr;
    // No cleanup for Count
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOperationStack.get_Count");
    return return_tuple;
}

static PyObject*
IOperationStackMethod_get_Item(PyIOperationStackObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;
    IOperation* ipoperation = NULL;
    PyObject* py_operation = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto ioperationstack_get_item_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index
    // No setup for operation

    // Call method on actual COM interface
    hr = self->m_pIOperationStack->get_Item(lindex, &ipoperation);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperationStack) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperationStack.get_Item() returned %ld", (long)hr);
        goto ioperationstack_get_item_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index
    Py_XDECREF(py_operation);
    if (ipoperation)
    {
        IUnknown* pUnk = NULL;
        ipoperation->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_operation = IUnknownToPythonIIDObject(pUnk, &IID_IOperation);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_operation)
    {
        if (py_operation)
           Py_DECREF(py_operation);
        py_operation = Py_None;
        Py_INCREF(py_operation);
    }
    if (PyErr_Occurred())
      goto ioperationstack_get_item_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_operation);
    goto ioperationstack_get_item_method_cleanup;

    ioperationstack_get_item_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    Py_XDECREF(py_operation);
    if (ipoperation)
      ipoperation->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOperationStack.get_Item");
    return return_tuple;
}

static PyObject*
IOperationStackMethod_Reset(PyIOperationStackObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIOperationStack->Reset();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperationStack) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperationStack.Reset() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IOperationStackMethod_Do(PyIOperationStackObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IOperation* ipoperation = NULL;
    PyObject* py_operation;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_operation))
      goto ioperationstack_do_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_operation, &IID_IOperation, (void**)&ipoperation))
        PyErr_SetString(PyExc_TypeError, "Argument operation (position 0) is not IOperation");
    
    if (PyErr_Occurred())
      goto ioperationstack_do_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIOperationStack->Do(ipoperation);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperationStack) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperationStack.Do() returned %ld", (long)hr);
        goto ioperationstack_do_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for operation

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto ioperationstack_do_method_cleanup;

    ioperationstack_do_method_cleanup:
    self->m_HR = hr;
    if (ipoperation)
      ipoperation->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOperationStack.Do");
    return return_tuple;
}

static PyObject*
IOperationStackMethod_Undo(PyIOperationStackObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIOperationStack->Undo();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperationStack) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperationStack.Undo() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IOperationStackMethod_Redo(PyIOperationStackObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIOperationStack->Redo();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperationStack) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperationStack.Redo() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IOperationStackMethod_get_UndoOperation(PyIOperationStackObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IOperation* ipoperation = NULL;
    PyObject* py_operation = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for operation

    // Call method on actual COM interface
    hr = self->m_pIOperationStack->get_UndoOperation(&ipoperation);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperationStack) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperationStack.get_UndoOperation() returned %ld", (long)hr);
        goto ioperationstack_get_undooperation_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_operation);
    if (ipoperation)
    {
        IUnknown* pUnk = NULL;
        ipoperation->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_operation = IUnknownToPythonIIDObject(pUnk, &IID_IOperation);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_operation)
    {
        if (py_operation)
           Py_DECREF(py_operation);
        py_operation = Py_None;
        Py_INCREF(py_operation);
    }
    if (PyErr_Occurred())
      goto ioperationstack_get_undooperation_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_operation);
    goto ioperationstack_get_undooperation_method_cleanup;

    ioperationstack_get_undooperation_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_operation);
    if (ipoperation)
      ipoperation->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOperationStack.get_UndoOperation");
    return return_tuple;
}

static PyObject*
IOperationStackMethod_get_RedoOperation(PyIOperationStackObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IOperation* ipoperation = NULL;
    PyObject* py_operation = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for operation

    // Call method on actual COM interface
    hr = self->m_pIOperationStack->get_RedoOperation(&ipoperation);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperationStack) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperationStack.get_RedoOperation() returned %ld", (long)hr);
        goto ioperationstack_get_redooperation_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_operation);
    if (ipoperation)
    {
        IUnknown* pUnk = NULL;
        ipoperation->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_operation = IUnknownToPythonIIDObject(pUnk, &IID_IOperation);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_operation)
    {
        if (py_operation)
           Py_DECREF(py_operation);
        py_operation = Py_None;
        Py_INCREF(py_operation);
    }
    if (PyErr_Occurred())
      goto ioperationstack_get_redooperation_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_operation);
    goto ioperationstack_get_redooperation_method_cleanup;

    ioperationstack_get_redooperation_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_operation);
    if (ipoperation)
      ipoperation->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOperationStack.get_RedoOperation");
    return return_tuple;
}

static PyObject*
IOperationStackMethod_Remove(PyIOperationStackObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lindex = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lindex))
      goto ioperationstack_remove_method_cleanup;

    // Set up initial variable values as needed
    // No setup for index

    // Call method on actual COM interface
    hr = self->m_pIOperationStack->Remove(lindex);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIOperationStack->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IOperationStack) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IOperationStack.Remove() returned %ld", (long)hr);
        goto ioperationstack_remove_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for index

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto ioperationstack_remove_method_cleanup;

    ioperationstack_remove_method_cleanup:
    self->m_HR = hr;
    // No cleanup for index
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IOperationStack.Remove");
    return return_tuple;
}


PyMethodDef PyIOperationStackMethods[] = {
    {"supports", (PyCFunction)PyIOperationStack_SupportsInterface, METH_O, ""},
    {"get_Count", (PyCFunction)IOperationStackMethod_get_Count, METH_VARARGS, ""},
    {"get_Item", (PyCFunction)IOperationStackMethod_get_Item, METH_VARARGS, ""},
    {"Reset", (PyCFunction)IOperationStackMethod_Reset, METH_NOARGS, ""},
    {"Do", (PyCFunction)IOperationStackMethod_Do, METH_VARARGS, ""},
    {"Undo", (PyCFunction)IOperationStackMethod_Undo, METH_NOARGS, ""},
    {"Redo", (PyCFunction)IOperationStackMethod_Redo, METH_NOARGS, ""},
    {"get_UndoOperation", (PyCFunction)IOperationStackMethod_get_UndoOperation, METH_VARARGS, ""},
    {"get_RedoOperation", (PyCFunction)IOperationStackMethod_get_RedoOperation, METH_VARARGS, ""},
    {"Remove", (PyCFunction)IOperationStackMethod_Remove, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIOperationStackGetSet[] = {
  {"_pUnk", (getter)PyIOperationStack_GetpUnk, NULL, "Get opaque pointer to an Unknown from IOperationStack", NULL},
  {"_pointer", (getter)PyIOperationStack_GetPointer, NULL, "Get memory address for IOperationStack", NULL},
  {"_IID", (getter)PyIOperationStack_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIOperationStack_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIOperationStack_GetIgnoreFailures, (setter)PyIOperationStack_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIOperationStackObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IOperationStackObject",                          
                                              /* tp_name */
  sizeof(PyIOperationStackObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIOperationStackObject_dealloc,      
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
  PyIOperationStackMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIOperationStackGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIOperationStackObject_new,                      
                                              /* tp_new */
};

// Interface IToolSelectedLayer

typedef struct PyIToolSelectedLayerObject {
    PyObject_HEAD
    IToolSelectedLayer* m_pIToolSelectedLayer;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIToolSelectedLayerObject;

static PyObject*
PyIToolSelectedLayerObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIToolSelectedLayerObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IToolSelectedLayer* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IToolSelectedLayer, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IToolSelectedLayer with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIToolSelectedLayerObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolSelectedLayer");
            return NULL;
        }
        self->m_pIToolSelectedLayer = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IToolSelectedLayer");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IToolSelectedLayer");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IToolSelectedLayer* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IToolSelectedLayer, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IToolSelectedLayer");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIToolSelectedLayerObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IToolSelectedLayer");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIToolSelectedLayer = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIToolSelectedLayerObject_dealloc(PyIToolSelectedLayerObject* self)
{
    if (self->m_pIToolSelectedLayer)
        self->m_pIToolSelectedLayer->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIToolSelectedLayer_GetpUnk(PyIToolSelectedLayerObject* self)
{
    if (!self->m_pIToolSelectedLayer)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIToolSelectedLayer->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IToolSelectedLayer to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIToolSelectedLayer_GetPointer(PyIToolSelectedLayerObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIToolSelectedLayer);
}

static PyObject*
PyIToolSelectedLayer_GetIID(PyIToolSelectedLayerObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "fc6732db-6295-4b39-b257-8c799ae20567");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIToolSelectedLayer_GetHR(PyIToolSelectedLayerObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIToolSelectedLayer_GetIgnoreFailures(PyIToolSelectedLayerObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIToolSelectedLayer_SetIgnoreFailures(PyIToolSelectedLayerObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIToolSelectedLayer_SupportsInterface(PyIToolSelectedLayerObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIToolSelectedLayer->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IToolSelectedLayerMethod_put_LayerIndex(PyIToolSelectedLayerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lLayerIndex = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lLayerIndex))
      goto itoolselectedlayer_put_layerindex_method_cleanup;

    // Set up initial variable values as needed
    // No setup for LayerIndex

    // Call method on actual COM interface
    hr = self->m_pIToolSelectedLayer->put_LayerIndex(lLayerIndex);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolSelectedLayer->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolSelectedLayer) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolSelectedLayer.put_LayerIndex() returned %ld", (long)hr);
        goto itoolselectedlayer_put_layerindex_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for LayerIndex

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto itoolselectedlayer_put_layerindex_method_cleanup;

    itoolselectedlayer_put_layerindex_method_cleanup:
    self->m_HR = hr;
    // No cleanup for LayerIndex
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolSelectedLayer.put_LayerIndex");
    return return_tuple;
}

static PyObject*
IToolSelectedLayerMethod_get_LayerIndex(PyIToolSelectedLayerObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lLayerIndex = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for LayerIndex

    // Call method on actual COM interface
    hr = self->m_pIToolSelectedLayer->get_LayerIndex(&lLayerIndex);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIToolSelectedLayer->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IToolSelectedLayer) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IToolSelectedLayer.get_LayerIndex() returned %ld", (long)hr);
        goto itoolselectedlayer_get_layerindex_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for LayerIndex

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lLayerIndex);
    goto itoolselectedlayer_get_layerindex_method_cleanup;

    itoolselectedlayer_get_layerindex_method_cleanup:
    self->m_HR = hr;
    // No cleanup for LayerIndex
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IToolSelectedLayer.get_LayerIndex");
    return return_tuple;
}


PyMethodDef PyIToolSelectedLayerMethods[] = {
    {"supports", (PyCFunction)PyIToolSelectedLayer_SupportsInterface, METH_O, ""},
    {"put_LayerIndex", (PyCFunction)IToolSelectedLayerMethod_put_LayerIndex, METH_VARARGS, ""},
    {"get_LayerIndex", (PyCFunction)IToolSelectedLayerMethod_get_LayerIndex, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIToolSelectedLayerGetSet[] = {
  {"_pUnk", (getter)PyIToolSelectedLayer_GetpUnk, NULL, "Get opaque pointer to an Unknown from IToolSelectedLayer", NULL},
  {"_pointer", (getter)PyIToolSelectedLayer_GetPointer, NULL, "Get memory address for IToolSelectedLayer", NULL},
  {"_IID", (getter)PyIToolSelectedLayer_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIToolSelectedLayer_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIToolSelectedLayer_GetIgnoreFailures, (setter)PyIToolSelectedLayer_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIToolSelectedLayerObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IToolSelectedLayerObject",                          
                                              /* tp_name */
  sizeof(PyIToolSelectedLayerObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIToolSelectedLayerObject_dealloc,      
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
  PyIToolSelectedLayerMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIToolSelectedLayerGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIToolSelectedLayerObject_new,                      
                                              /* tp_new */
};

// Interface ISystemMouseCursor

typedef struct PyISystemMouseCursorObject {
    PyObject_HEAD
    ISystemMouseCursor* m_pISystemMouseCursor;
    HRESULT m_HR;
    int m_ignore_failures;
} PyISystemMouseCursorObject;

static PyObject*
PyISystemMouseCursorObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyISystemMouseCursorObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        ISystemMouseCursor* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_ISystemMouseCursor, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate ISystemMouseCursor with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyISystemMouseCursorObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate ISystemMouseCursor");
            return NULL;
        }
        self->m_pISystemMouseCursor = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for ISystemMouseCursor");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to ISystemMouseCursor");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    ISystemMouseCursor* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_ISystemMouseCursor, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to ISystemMouseCursor");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyISystemMouseCursorObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate ISystemMouseCursor");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pISystemMouseCursor = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyISystemMouseCursorObject_dealloc(PyISystemMouseCursorObject* self)
{
    if (self->m_pISystemMouseCursor)
        self->m_pISystemMouseCursor->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyISystemMouseCursor_GetpUnk(PyISystemMouseCursorObject* self)
{
    if (!self->m_pISystemMouseCursor)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pISystemMouseCursor->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI ISystemMouseCursor to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyISystemMouseCursor_GetPointer(PyISystemMouseCursorObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pISystemMouseCursor);
}

static PyObject*
PyISystemMouseCursor_GetIID(PyISystemMouseCursorObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "623bf41c-3e34-4586-a729-c2e34cbe8fa9");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyISystemMouseCursor_GetHR(PyISystemMouseCursorObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyISystemMouseCursor_GetIgnoreFailures(PyISystemMouseCursorObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyISystemMouseCursor_SetIgnoreFailures(PyISystemMouseCursorObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyISystemMouseCursor_SupportsInterface(PyISystemMouseCursorObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pISystemMouseCursor->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
ISystemMouseCursorMethod_Load(PyISystemMouseCursorObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriSystemMouseCursor emouseCursorType;

    // Unpack values
    if (!PyArg_ParseTuple(args, "i", (int *)&emouseCursorType))
      goto isystemmousecursor_load_method_cleanup;

    // Set up initial variable values as needed
    // No setup for mouseCursorType

    // Call method on actual COM interface
    hr = self->m_pISystemMouseCursor->Load(emouseCursorType);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pISystemMouseCursor->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ISystemMouseCursor) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ISystemMouseCursor.Load() returned %ld", (long)hr);
        goto isystemmousecursor_load_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for mouseCursorType

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto isystemmousecursor_load_method_cleanup;

    isystemmousecursor_load_method_cleanup:
    self->m_HR = hr;
    // No cleanup for mouseCursorType
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ISystemMouseCursor.Load");
    return return_tuple;
}

static PyObject*
ISystemMouseCursorMethod_LoadFromFile(PyISystemMouseCursorObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsfileName = 0;
    PyObject* pyvar_fileName;
    PyObject* unicodefileName = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_fileName))
      goto isystemmousecursor_loadfromfile_method_cleanup;

    // Set up initial variable values as needed
    if (PyString_Check(pyvar_fileName))
        unicodefileName = PyUnicode_FromObject(pyvar_fileName);
    else if (PyUnicode_Check(pyvar_fileName))
    {
        unicodefileName = pyvar_fileName;
        Py_INCREF(unicodefileName);
    }
    else if (pyvar_fileName != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter fileName at index 0");
    if (unicodefileName)
        bsfileName = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodefileName), 
                                            (UINT)PyUnicode_GET_SIZE(unicodefileName));
    
    if (PyErr_Occurred())
      goto isystemmousecursor_loadfromfile_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pISystemMouseCursor->LoadFromFile(bsfileName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pISystemMouseCursor->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ISystemMouseCursor) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ISystemMouseCursor.LoadFromFile() returned %ld", (long)hr);
        goto isystemmousecursor_loadfromfile_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for fileName

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto isystemmousecursor_loadfromfile_method_cleanup;

    isystemmousecursor_loadfromfile_method_cleanup:
    self->m_HR = hr;
    if (bsfileName)
        ::SysFreeString(bsfileName);
    
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ISystemMouseCursor.LoadFromFile");
    return return_tuple;
}

static PyObject*
ISystemMouseCursorMethod_get_Cursor(PyISystemMouseCursorObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    OLE_HANDLE HmouseCursor = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for mouseCursor

    // Call method on actual COM interface
    hr = self->m_pISystemMouseCursor->get_Cursor(&HmouseCursor);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pISystemMouseCursor->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ISystemMouseCursor) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ISystemMouseCursor.get_Cursor() returned %ld", (long)hr);
        goto isystemmousecursor_get_cursor_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for mouseCursor

    // Initialize output tuple
    return_tuple = Py_BuildValue("I",
                                            HmouseCursor);
    goto isystemmousecursor_get_cursor_method_cleanup;

    isystemmousecursor_get_cursor_method_cleanup:
    self->m_HR = hr;
    // No cleanup for mouseCursor
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ISystemMouseCursor.get_Cursor");
    return return_tuple;
}

static PyObject*
ISystemMouseCursorMethod_put_Cursor(PyISystemMouseCursorObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    OLE_HANDLE HmouseCursor = 0;

    // Unpack values
    if (!PyArg_ParseTuple(args, "I", &HmouseCursor))
      goto isystemmousecursor_put_cursor_method_cleanup;

    // Set up initial variable values as needed
    // No setup for mouseCursor

    // Call method on actual COM interface
    hr = self->m_pISystemMouseCursor->put_Cursor(HmouseCursor);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pISystemMouseCursor->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ISystemMouseCursor) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ISystemMouseCursor.put_Cursor() returned %ld", (long)hr);
        goto isystemmousecursor_put_cursor_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for mouseCursor

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto isystemmousecursor_put_cursor_method_cleanup;

    isystemmousecursor_put_cursor_method_cleanup:
    self->m_HR = hr;
    // No cleanup for mouseCursor
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ISystemMouseCursor.put_Cursor");
    return return_tuple;
}


PyMethodDef PyISystemMouseCursorMethods[] = {
    {"supports", (PyCFunction)PyISystemMouseCursor_SupportsInterface, METH_O, ""},
    {"Load", (PyCFunction)ISystemMouseCursorMethod_Load, METH_VARARGS, ""},
    {"LoadFromFile", (PyCFunction)ISystemMouseCursorMethod_LoadFromFile, METH_VARARGS, ""},
    {"get_Cursor", (PyCFunction)ISystemMouseCursorMethod_get_Cursor, METH_VARARGS, ""},
    {"put_Cursor", (PyCFunction)ISystemMouseCursorMethod_put_Cursor, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyISystemMouseCursorGetSet[] = {
  {"_pUnk", (getter)PyISystemMouseCursor_GetpUnk, NULL, "Get opaque pointer to an Unknown from ISystemMouseCursor", NULL},
  {"_pointer", (getter)PyISystemMouseCursor_GetPointer, NULL, "Get memory address for ISystemMouseCursor", NULL},
  {"_IID", (getter)PyISystemMouseCursor_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyISystemMouseCursor_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyISystemMouseCursor_GetIgnoreFailures, (setter)PyISystemMouseCursor_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyISystemMouseCursorObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.ISystemMouseCursorObject",                          
                                              /* tp_name */
  sizeof(PyISystemMouseCursorObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyISystemMouseCursorObject_dealloc,      
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
  PyISystemMouseCursorMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyISystemMouseCursorGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyISystemMouseCursorObject_new,                      
                                              /* tp_new */
};

// Interface IDataObjectHelper

typedef struct PyIDataObjectHelperObject {
    PyObject_HEAD
    IDataObjectHelper* m_pIDataObjectHelper;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIDataObjectHelperObject;

static PyObject*
PyIDataObjectHelperObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIDataObjectHelperObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IDataObjectHelper* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IDataObjectHelper, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IDataObjectHelper with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIDataObjectHelperObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IDataObjectHelper");
            return NULL;
        }
        self->m_pIDataObjectHelper = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IDataObjectHelper");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IDataObjectHelper");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IDataObjectHelper* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IDataObjectHelper, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IDataObjectHelper");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIDataObjectHelperObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IDataObjectHelper");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIDataObjectHelper = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIDataObjectHelperObject_dealloc(PyIDataObjectHelperObject* self)
{
    if (self->m_pIDataObjectHelper)
        self->m_pIDataObjectHelper->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIDataObjectHelper_GetpUnk(PyIDataObjectHelperObject* self)
{
    if (!self->m_pIDataObjectHelper)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIDataObjectHelper->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IDataObjectHelper to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIDataObjectHelper_GetPointer(PyIDataObjectHelperObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIDataObjectHelper);
}

static PyObject*
PyIDataObjectHelper_GetIID(PyIDataObjectHelperObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "e0ccbcb0-cd47-11d5-a9e6-00104bb6fc1c");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIDataObjectHelper_GetHR(PyIDataObjectHelperObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIDataObjectHelper_GetIgnoreFailures(PyIDataObjectHelperObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIDataObjectHelper_SetIgnoreFailures(PyIDataObjectHelperObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIDataObjectHelper_SupportsInterface(PyIDataObjectHelperObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIDataObjectHelper->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IDataObjectHelperMethod_putref_InternalObject(PyIDataObjectHelperObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IUnknown* ipppObject = NULL;
    PyObject* py_ppObject;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_ppObject))
      goto idataobjecthelper_putref_internalobject_method_cleanup;

    // Set up initial variable values as needed
    if (!IFaceFromPyObject(py_ppObject, &IID_IUnknown, (void**)&ipppObject))
        PyErr_SetString(PyExc_TypeError, "Argument ppObject (position 0) is not IUnknown");
    
    if (PyErr_Occurred())
      goto idataobjecthelper_putref_internalobject_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pIDataObjectHelper->putref_InternalObject(ipppObject);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataObjectHelper->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataObjectHelper) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataObjectHelper.putref_InternalObject() returned %ld", (long)hr);
        goto idataobjecthelper_putref_internalobject_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for ppObject

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto idataobjecthelper_putref_internalobject_method_cleanup;

    idataobjecthelper_putref_internalobject_method_cleanup:
    self->m_HR = hr;
    if (ipppObject)
      ipppObject->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataObjectHelper.putref_InternalObject");
    return return_tuple;
}

static PyObject*
IDataObjectHelperMethod_get_InternalObject(PyIDataObjectHelperObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IUnknown* ipppObject = NULL;
    PyObject* py_ppObject = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppObject

    // Call method on actual COM interface
    hr = self->m_pIDataObjectHelper->get_InternalObject(&ipppObject);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataObjectHelper->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataObjectHelper) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataObjectHelper.get_InternalObject() returned %ld", (long)hr);
        goto idataobjecthelper_get_internalobject_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppObject);
    if (ipppObject)
    {
        IUnknown* pUnk = NULL;
        ipppObject->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppObject = IUnknownToPythonIIDObject(pUnk, &IID_IUnknown);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppObject)
    {
        if (py_ppObject)
           Py_DECREF(py_ppObject);
        py_ppObject = Py_None;
        Py_INCREF(py_ppObject);
    }
    if (PyErr_Occurred())
      goto idataobjecthelper_get_internalobject_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppObject);
    goto idataobjecthelper_get_internalobject_method_cleanup;

    idataobjecthelper_get_internalobject_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppObject);
    if (ipppObject)
      ipppObject->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataObjectHelper.get_InternalObject");
    return return_tuple;
}

static PyObject*
IDataObjectHelperMethod_GetData(PyIDataObjectHelperObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lformat = 0;
    VARIANT vpvData;
    ::VariantInit(&vpvData);
    PyObject* pyvar_pvData = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lformat))
      goto idataobjecthelper_getdata_method_cleanup;

    // Set up initial variable values as needed
    // No setup for format
    // No setup for pvData

    // Call method on actual COM interface
    hr = self->m_pIDataObjectHelper->GetData(lformat, &vpvData);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataObjectHelper->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataObjectHelper) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataObjectHelper.GetData() returned %ld", (long)hr);
        goto idataobjecthelper_getdata_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for format
    pyvar_pvData = Variant_AsPyObject(&vpvData);
    if (PyErr_Occurred())
      goto idataobjecthelper_getdata_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pvData);
    goto idataobjecthelper_getdata_method_cleanup;

    idataobjecthelper_getdata_method_cleanup:
    self->m_HR = hr;
    // No cleanup for format
    ::VariantClear(&vpvData);
    Py_XDECREF(pyvar_pvData);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataObjectHelper.GetData");
    return return_tuple;
}

static PyObject*
IDataObjectHelperMethod_GetFormat(PyIDataObjectHelperObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lformat = 0;
    VARIANT_BOOL b_pbFormatSupported = VARIANT_FALSE;
    PyObject* pyvar_pbFormatSupported = Py_False;

    // Unpack values
    if (!PyArg_ParseTuple(args, "l", &lformat))
      goto idataobjecthelper_getformat_method_cleanup;

    // Set up initial variable values as needed
    // No setup for format
    // No setup for pbFormatSupported

    // Call method on actual COM interface
    hr = self->m_pIDataObjectHelper->GetFormat(lformat, &b_pbFormatSupported);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataObjectHelper->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataObjectHelper) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataObjectHelper.GetFormat() returned %ld", (long)hr);
        goto idataobjecthelper_getformat_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for format
    pyvar_pbFormatSupported = ((b_pbFormatSupported == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto idataobjecthelper_getformat_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pbFormatSupported);
    goto idataobjecthelper_getformat_method_cleanup;

    idataobjecthelper_getformat_method_cleanup:
    self->m_HR = hr;
    // No cleanup for format
    // No cleanup for pbFormatSupported
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataObjectHelper.GetFormat");
    return return_tuple;
}

static PyObject*
IDataObjectHelperMethod_CanGetFiles(PyIDataObjectHelperObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_CanGetFiles = VARIANT_FALSE;
    PyObject* pyvar_CanGetFiles = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for CanGetFiles

    // Call method on actual COM interface
    hr = self->m_pIDataObjectHelper->CanGetFiles(&b_CanGetFiles);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataObjectHelper->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataObjectHelper) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataObjectHelper.CanGetFiles() returned %ld", (long)hr);
        goto idataobjecthelper_cangetfiles_method_cleanup;
    }

    // Set up return values as needed
    pyvar_CanGetFiles = ((b_CanGetFiles == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto idataobjecthelper_cangetfiles_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_CanGetFiles);
    goto idataobjecthelper_cangetfiles_method_cleanup;

    idataobjecthelper_cangetfiles_method_cleanup:
    self->m_HR = hr;
    // No cleanup for CanGetFiles
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataObjectHelper.CanGetFiles");
    return return_tuple;
}

static PyObject*
IDataObjectHelperMethod_GetFiles(PyIDataObjectHelperObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT vpvData;
    ::VariantInit(&vpvData);
    PyObject* pyvar_pvData = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pvData

    // Call method on actual COM interface
    hr = self->m_pIDataObjectHelper->GetFiles(&vpvData);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataObjectHelper->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataObjectHelper) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataObjectHelper.GetFiles() returned %ld", (long)hr);
        goto idataobjecthelper_getfiles_method_cleanup;
    }

    // Set up return values as needed
    pyvar_pvData = Variant_AsPyObject(&vpvData);
    if (PyErr_Occurred())
      goto idataobjecthelper_getfiles_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pvData);
    goto idataobjecthelper_getfiles_method_cleanup;

    idataobjecthelper_getfiles_method_cleanup:
    self->m_HR = hr;
    ::VariantClear(&vpvData);
    Py_XDECREF(pyvar_pvData);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataObjectHelper.GetFiles");
    return return_tuple;
}

static PyObject*
IDataObjectHelperMethod_CanGetNames(PyIDataObjectHelperObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_CanGetNames = VARIANT_FALSE;
    PyObject* pyvar_CanGetNames = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for CanGetNames

    // Call method on actual COM interface
    hr = self->m_pIDataObjectHelper->CanGetNames(&b_CanGetNames);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataObjectHelper->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataObjectHelper) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataObjectHelper.CanGetNames() returned %ld", (long)hr);
        goto idataobjecthelper_cangetnames_method_cleanup;
    }

    // Set up return values as needed
    pyvar_CanGetNames = ((b_CanGetNames == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto idataobjecthelper_cangetnames_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_CanGetNames);
    goto idataobjecthelper_cangetnames_method_cleanup;

    idataobjecthelper_cangetnames_method_cleanup:
    self->m_HR = hr;
    // No cleanup for CanGetNames
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataObjectHelper.CanGetNames");
    return return_tuple;
}

static PyObject*
IDataObjectHelperMethod_GetNames(PyIDataObjectHelperObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IEnumName* ipppNames = NULL;
    PyObject* py_ppNames = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppNames

    // Call method on actual COM interface
    hr = self->m_pIDataObjectHelper->GetNames(&ipppNames);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIDataObjectHelper->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IDataObjectHelper) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IDataObjectHelper.GetNames() returned %ld", (long)hr);
        goto idataobjecthelper_getnames_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppNames);
    if (ipppNames)
    {
        IUnknown* pUnk = NULL;
        ipppNames->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppNames = IUnknownToPythonIIDObject(pUnk, &IID_IEnumName);
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
      goto idataobjecthelper_getnames_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppNames);
    goto idataobjecthelper_getnames_method_cleanup;

    idataobjecthelper_getnames_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppNames);
    if (ipppNames)
      ipppNames->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IDataObjectHelper.GetNames");
    return return_tuple;
}


PyMethodDef PyIDataObjectHelperMethods[] = {
    {"supports", (PyCFunction)PyIDataObjectHelper_SupportsInterface, METH_O, ""},
    {"putref_InternalObject", (PyCFunction)IDataObjectHelperMethod_putref_InternalObject, METH_VARARGS, ""},
    {"get_InternalObject", (PyCFunction)IDataObjectHelperMethod_get_InternalObject, METH_VARARGS, ""},
    {"GetData", (PyCFunction)IDataObjectHelperMethod_GetData, METH_VARARGS, ""},
    {"GetFormat", (PyCFunction)IDataObjectHelperMethod_GetFormat, METH_VARARGS, ""},
    {"CanGetFiles", (PyCFunction)IDataObjectHelperMethod_CanGetFiles, METH_VARARGS, ""},
    {"GetFiles", (PyCFunction)IDataObjectHelperMethod_GetFiles, METH_VARARGS, ""},
    {"CanGetNames", (PyCFunction)IDataObjectHelperMethod_CanGetNames, METH_VARARGS, ""},
    {"GetNames", (PyCFunction)IDataObjectHelperMethod_GetNames, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIDataObjectHelperGetSet[] = {
  {"_pUnk", (getter)PyIDataObjectHelper_GetpUnk, NULL, "Get opaque pointer to an Unknown from IDataObjectHelper", NULL},
  {"_pointer", (getter)PyIDataObjectHelper_GetPointer, NULL, "Get memory address for IDataObjectHelper", NULL},
  {"_IID", (getter)PyIDataObjectHelper_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIDataObjectHelper_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIDataObjectHelper_GetIgnoreFailures, (setter)PyIDataObjectHelper_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIDataObjectHelperObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IDataObjectHelperObject",                          
                                              /* tp_name */
  sizeof(PyIDataObjectHelperObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIDataObjectHelperObject_dealloc,      
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
  PyIDataObjectHelperMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIDataObjectHelperGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIDataObjectHelperObject_new,                      
                                              /* tp_new */
};

// Interface ICommandHost

typedef struct PyICommandHostObject {
    PyObject_HEAD
    ICommandHost* m_pICommandHost;
    HRESULT m_HR;
    int m_ignore_failures;
} PyICommandHostObject;

static PyObject*
PyICommandHostObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyICommandHostObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        ICommandHost* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_ICommandHost, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate ICommandHost with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyICommandHostObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate ICommandHost");
            return NULL;
        }
        self->m_pICommandHost = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for ICommandHost");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to ICommandHost");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    ICommandHost* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_ICommandHost, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to ICommandHost");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyICommandHostObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate ICommandHost");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pICommandHost = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyICommandHostObject_dealloc(PyICommandHostObject* self)
{
    if (self->m_pICommandHost)
        self->m_pICommandHost->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyICommandHost_GetpUnk(PyICommandHostObject* self)
{
    if (!self->m_pICommandHost)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pICommandHost->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI ICommandHost to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyICommandHost_GetPointer(PyICommandHostObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pICommandHost);
}

static PyObject*
PyICommandHost_GetIID(PyICommandHostObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "14cb3146-6fdd-4b45-8759-0a297a4dad10");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyICommandHost_GetHR(PyICommandHostObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyICommandHost_GetIgnoreFailures(PyICommandHostObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyICommandHost_SetIgnoreFailures(PyICommandHostObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyICommandHost_SupportsInterface(PyICommandHostObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pICommandHost->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
ICommandHostMethod_SetCommand(PyICommandHostObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT vcommandInstance;
    ::VariantInit(&vcommandInstance);
    PyObject* pyvar_commandInstance = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &pyvar_commandInstance))
      goto icommandhost_setcommand_method_cleanup;

    // Set up initial variable values as needed
    PyObject_AsVariant(pyvar_commandInstance, &vcommandInstance);
    
    if (PyErr_Occurred())
      goto icommandhost_setcommand_method_cleanup;
    

    // Call method on actual COM interface
    hr = self->m_pICommandHost->SetCommand(&vcommandInstance);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pICommandHost->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_ICommandHost) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: ICommandHost.SetCommand() returned %ld", (long)hr);
        goto icommandhost_setcommand_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for commandInstance

    // Initialize output tuple
    // No outputs
    return_tuple = Py_None;
    Py_INCREF(return_tuple);
    goto icommandhost_setcommand_method_cleanup;

    icommandhost_setcommand_method_cleanup:
    self->m_HR = hr;
    ::VariantClear(&vcommandInstance);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in ICommandHost.SetCommand");
    return return_tuple;
}


PyMethodDef PyICommandHostMethods[] = {
    {"supports", (PyCFunction)PyICommandHost_SupportsInterface, METH_O, ""},
    {"SetCommand", (PyCFunction)ICommandHostMethod_SetCommand, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyICommandHostGetSet[] = {
  {"_pUnk", (getter)PyICommandHost_GetpUnk, NULL, "Get opaque pointer to an Unknown from ICommandHost", NULL},
  {"_pointer", (getter)PyICommandHost_GetPointer, NULL, "Get memory address for ICommandHost", NULL},
  {"_IID", (getter)PyICommandHost_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyICommandHost_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyICommandHost_GetIgnoreFailures, (setter)PyICommandHost_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyICommandHostObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.ICommandHostObject",                          
                                              /* tp_name */
  sizeof(PyICommandHostObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyICommandHostObject_dealloc,      
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
  PyICommandHostMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyICommandHostGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyICommandHostObject_new,                      
                                              /* tp_new */
};

// Interface IArcGISPortal

typedef struct PyIArcGISPortalObject {
    PyObject_HEAD
    IArcGISPortal* m_pIArcGISPortal;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIArcGISPortalObject;

static PyObject*
PyIArcGISPortalObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIArcGISPortalObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IArcGISPortal* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IArcGISPortal, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IArcGISPortal with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIArcGISPortalObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IArcGISPortal");
            return NULL;
        }
        self->m_pIArcGISPortal = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IArcGISPortal");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IArcGISPortal");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IArcGISPortal* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IArcGISPortal, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IArcGISPortal");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIArcGISPortalObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IArcGISPortal");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIArcGISPortal = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIArcGISPortalObject_dealloc(PyIArcGISPortalObject* self)
{
    if (self->m_pIArcGISPortal)
        self->m_pIArcGISPortal->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIArcGISPortal_GetpUnk(PyIArcGISPortalObject* self)
{
    if (!self->m_pIArcGISPortal)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIArcGISPortal->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IArcGISPortal to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIArcGISPortal_GetPointer(PyIArcGISPortalObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIArcGISPortal);
}

static PyObject*
PyIArcGISPortal_GetIID(PyIArcGISPortalObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "a128a18c-6769-4e4f-90a9-df413d139192");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIArcGISPortal_GetHR(PyIArcGISPortalObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIArcGISPortal_GetIgnoreFailures(PyIArcGISPortalObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIArcGISPortal_SetIgnoreFailures(PyIArcGISPortalObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIArcGISPortal_SupportsInterface(PyIArcGISPortalObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIArcGISPortal->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IArcGISPortalMethod_get_Portal(PyIArcGISPortalObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsbsPortal;
    PyObject* pyvar_bsPortal = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for bsPortal

    // Call method on actual COM interface
    hr = self->m_pIArcGISPortal->get_Portal(&bsbsPortal);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISPortal->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISPortal) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISPortal.get_Portal() returned %ld", (long)hr);
        goto iarcgisportal_get_portal_method_cleanup;
    }

    // Set up return values as needed
    pyvar_bsPortal = PyUnicode_FromWideChar(bsbsPortal,::SysStringLen(bsbsPortal));
    ::SysFreeString(bsbsPortal);
    
    if (PyErr_Occurred())
      goto iarcgisportal_get_portal_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bsPortal);
    goto iarcgisportal_get_portal_method_cleanup;

    iarcgisportal_get_portal_method_cleanup:
    self->m_HR = hr;
    if (pyvar_bsPortal != Py_None)
        Py_XDECREF(pyvar_bsPortal);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISPortal.get_Portal");
    return return_tuple;
}

static PyObject*
IArcGISPortalMethod_get_SignonImage(PyIArcGISPortalObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lhBitmap = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for hBitmap

    // Call method on actual COM interface
    hr = self->m_pIArcGISPortal->get_SignonImage(&lhBitmap);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISPortal->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISPortal) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISPortal.get_SignonImage() returned %ld", (long)hr);
        goto iarcgisportal_get_signonimage_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for hBitmap

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lhBitmap);
    goto iarcgisportal_get_signonimage_method_cleanup;

    iarcgisportal_get_signonimage_method_cleanup:
    self->m_HR = hr;
    // No cleanup for hBitmap
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISPortal.get_SignonImage");
    return return_tuple;
}

static PyObject*
IArcGISPortalMethod_get_BannerImage(PyIArcGISPortalObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    long lhBitmap = 0;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for hBitmap

    // Call method on actual COM interface
    hr = self->m_pIArcGISPortal->get_BannerImage(&lhBitmap);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISPortal->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISPortal) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISPortal.get_BannerImage() returned %ld", (long)hr);
        goto iarcgisportal_get_bannerimage_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for hBitmap

    // Initialize output tuple
    return_tuple = Py_BuildValue("l",
                                            lhBitmap);
    goto iarcgisportal_get_bannerimage_method_cleanup;

    iarcgisportal_get_bannerimage_method_cleanup:
    self->m_HR = hr;
    // No cleanup for hBitmap
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISPortal.get_BannerImage");
    return return_tuple;
}

static PyObject*
IArcGISPortalMethod_get_BannerImageUrl(PyIArcGISPortalObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsbsUrl;
    PyObject* pyvar_bsUrl = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for bsUrl

    // Call method on actual COM interface
    hr = self->m_pIArcGISPortal->get_BannerImageUrl(&bsbsUrl);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISPortal->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISPortal) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISPortal.get_BannerImageUrl() returned %ld", (long)hr);
        goto iarcgisportal_get_bannerimageurl_method_cleanup;
    }

    // Set up return values as needed
    pyvar_bsUrl = PyUnicode_FromWideChar(bsbsUrl,::SysStringLen(bsbsUrl));
    ::SysFreeString(bsbsUrl);
    
    if (PyErr_Occurred())
      goto iarcgisportal_get_bannerimageurl_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bsUrl);
    goto iarcgisportal_get_bannerimageurl_method_cleanup;

    iarcgisportal_get_bannerimageurl_method_cleanup:
    self->m_HR = hr;
    if (pyvar_bsUrl != Py_None)
        Py_XDECREF(pyvar_bsUrl);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISPortal.get_BannerImageUrl");
    return return_tuple;
}

static PyObject*
IArcGISPortalMethod_get_Name(PyIArcGISPortalObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    BSTR bsbsName;
    PyObject* pyvar_bsName = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for bsName

    // Call method on actual COM interface
    hr = self->m_pIArcGISPortal->get_Name(&bsbsName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISPortal->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISPortal) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISPortal.get_Name() returned %ld", (long)hr);
        goto iarcgisportal_get_name_method_cleanup;
    }

    // Set up return values as needed
    pyvar_bsName = PyUnicode_FromWideChar(bsbsName,::SysStringLen(bsbsName));
    ::SysFreeString(bsbsName);
    
    if (PyErr_Occurred())
      goto iarcgisportal_get_name_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_bsName);
    goto iarcgisportal_get_name_method_cleanup;

    iarcgisportal_get_name_method_cleanup:
    self->m_HR = hr;
    if (pyvar_bsName != Py_None)
        Py_XDECREF(pyvar_bsName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISPortal.get_Name");
    return return_tuple;
}

static PyObject*
IArcGISPortalMethod_get_IsMultiTenant(PyIArcGISPortalObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    VARIANT_BOOL b_isMulti = VARIANT_FALSE;
    PyObject* pyvar_isMulti = Py_False;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for isMulti

    // Call method on actual COM interface
    hr = self->m_pIArcGISPortal->get_IsMultiTenant(&b_isMulti);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISPortal->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISPortal) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISPortal.get_IsMultiTenant() returned %ld", (long)hr);
        goto iarcgisportal_get_ismultitenant_method_cleanup;
    }

    // Set up return values as needed
    pyvar_isMulti = ((b_isMulti == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto iarcgisportal_get_ismultitenant_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_isMulti);
    goto iarcgisportal_get_ismultitenant_method_cleanup;

    iarcgisportal_get_ismultitenant_method_cleanup:
    self->m_HR = hr;
    // No cleanup for isMulti
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISPortal.get_IsMultiTenant");
    return return_tuple;
}


PyMethodDef PyIArcGISPortalMethods[] = {
    {"supports", (PyCFunction)PyIArcGISPortal_SupportsInterface, METH_O, ""},
    {"get_Portal", (PyCFunction)IArcGISPortalMethod_get_Portal, METH_VARARGS, ""},
    {"get_SignonImage", (PyCFunction)IArcGISPortalMethod_get_SignonImage, METH_VARARGS, ""},
    {"get_BannerImage", (PyCFunction)IArcGISPortalMethod_get_BannerImage, METH_VARARGS, ""},
    {"get_BannerImageUrl", (PyCFunction)IArcGISPortalMethod_get_BannerImageUrl, METH_VARARGS, ""},
    {"get_Name", (PyCFunction)IArcGISPortalMethod_get_Name, METH_VARARGS, ""},
    {"get_IsMultiTenant", (PyCFunction)IArcGISPortalMethod_get_IsMultiTenant, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIArcGISPortalGetSet[] = {
  {"_pUnk", (getter)PyIArcGISPortal_GetpUnk, NULL, "Get opaque pointer to an Unknown from IArcGISPortal", NULL},
  {"_pointer", (getter)PyIArcGISPortal_GetPointer, NULL, "Get memory address for IArcGISPortal", NULL},
  {"_IID", (getter)PyIArcGISPortal_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIArcGISPortal_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIArcGISPortal_GetIgnoreFailures, (setter)PyIArcGISPortal_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIArcGISPortalObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IArcGISPortalObject",                          
                                              /* tp_name */
  sizeof(PyIArcGISPortalObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIArcGISPortalObject_dealloc,      
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
  PyIArcGISPortalMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIArcGISPortalGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIArcGISPortalObject_new,                      
                                              /* tp_new */
};

// Interface IArcGISSingleSignon

typedef struct PyIArcGISSingleSignonObject {
    PyObject_HEAD
    IArcGISSingleSignon* m_pIArcGISSingleSignon;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIArcGISSingleSignonObject;

static PyObject*
PyIArcGISSingleSignonObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIArcGISSingleSignonObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IArcGISSingleSignon* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IArcGISSingleSignon, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IArcGISSingleSignon with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIArcGISSingleSignonObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IArcGISSingleSignon");
            return NULL;
        }
        self->m_pIArcGISSingleSignon = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IArcGISSingleSignon");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IArcGISSingleSignon");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IArcGISSingleSignon* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IArcGISSingleSignon, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IArcGISSingleSignon");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIArcGISSingleSignonObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IArcGISSingleSignon");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIArcGISSingleSignon = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIArcGISSingleSignonObject_dealloc(PyIArcGISSingleSignonObject* self)
{
    if (self->m_pIArcGISSingleSignon)
        self->m_pIArcGISSingleSignon->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIArcGISSingleSignon_GetpUnk(PyIArcGISSingleSignonObject* self)
{
    if (!self->m_pIArcGISSingleSignon)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIArcGISSingleSignon->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IArcGISSingleSignon to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIArcGISSingleSignon_GetPointer(PyIArcGISSingleSignonObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIArcGISSingleSignon);
}

static PyObject*
PyIArcGISSingleSignon_GetIID(PyIArcGISSingleSignonObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "e36dc321-5c5b-4d6b-884e-19ff4b5bbcac");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIArcGISSingleSignon_GetHR(PyIArcGISSingleSignonObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIArcGISSingleSignon_GetIgnoreFailures(PyIArcGISSingleSignonObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIArcGISSingleSignon_SetIgnoreFailures(PyIArcGISSingleSignonObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIArcGISSingleSignon_SupportsInterface(PyIArcGISSingleSignonObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIArcGISSingleSignon->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IArcGISSingleSignonMethod_GetToken(PyIArcGISSingleSignonObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'BSTR', u'*']
       INPUT [u'BSTR', u'*']
       INPUT [u'long', u'*']
       INPUT [u'BSTR', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IArcGISSingleSignon.GetToken not implemented.");
    return NULL;
}

static PyObject*
IArcGISSingleSignonMethod_SignOut(PyIArcGISSingleSignonObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIArcGISSingleSignon->SignOut();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISSingleSignon->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISSingleSignon) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISSingleSignon.SignOut() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IArcGISSingleSignonMethod_GetCurrentToken(PyIArcGISSingleSignonObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'BSTR', u'*']
       INPUT [u'BSTR', u'*']
       INPUT [u'long', u'*']
       INPUT [u'BSTR', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IArcGISSingleSignon.GetCurrentToken not implemented.");
    return NULL;
}

static PyObject*
IArcGISSingleSignonMethod_GetURI(PyIArcGISSingleSignonObject* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'BSTR', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IArcGISSingleSignon.GetURI not implemented.");
    return NULL;
}


PyMethodDef PyIArcGISSingleSignonMethods[] = {
    {"supports", (PyCFunction)PyIArcGISSingleSignon_SupportsInterface, METH_O, ""},
    {"GetToken", (PyCFunction)IArcGISSingleSignonMethod_GetToken, METH_VARARGS, ""},
    {"SignOut", (PyCFunction)IArcGISSingleSignonMethod_SignOut, METH_NOARGS, ""},
    {"GetCurrentToken", (PyCFunction)IArcGISSingleSignonMethod_GetCurrentToken, METH_VARARGS, ""},
    {"GetURI", (PyCFunction)IArcGISSingleSignonMethod_GetURI, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIArcGISSingleSignonGetSet[] = {
  {"_pUnk", (getter)PyIArcGISSingleSignon_GetpUnk, NULL, "Get opaque pointer to an Unknown from IArcGISSingleSignon", NULL},
  {"_pointer", (getter)PyIArcGISSingleSignon_GetPointer, NULL, "Get memory address for IArcGISSingleSignon", NULL},
  {"_IID", (getter)PyIArcGISSingleSignon_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIArcGISSingleSignon_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIArcGISSingleSignon_GetIgnoreFailures, (setter)PyIArcGISSingleSignon_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIArcGISSingleSignonObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IArcGISSingleSignonObject",                          
                                              /* tp_name */
  sizeof(PyIArcGISSingleSignonObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIArcGISSingleSignonObject_dealloc,      
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
  PyIArcGISSingleSignonMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIArcGISSingleSignonGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIArcGISSingleSignonObject_new,                      
                                              /* tp_new */
};

// Interface IArcGISSingleSignon2

typedef struct PyIArcGISSingleSignon2Object {
    PyObject_HEAD
    IArcGISSingleSignon2* m_pIArcGISSingleSignon2;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIArcGISSingleSignon2Object;

static PyObject*
PyIArcGISSingleSignon2Object_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIArcGISSingleSignon2Object* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IArcGISSingleSignon2* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IArcGISSingleSignon2, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IArcGISSingleSignon2 with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIArcGISSingleSignon2Object *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IArcGISSingleSignon2");
            return NULL;
        }
        self->m_pIArcGISSingleSignon2 = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IArcGISSingleSignon2");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IArcGISSingleSignon2");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IArcGISSingleSignon2* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IArcGISSingleSignon2, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IArcGISSingleSignon2");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIArcGISSingleSignon2Object *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IArcGISSingleSignon2");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIArcGISSingleSignon2 = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIArcGISSingleSignon2Object_dealloc(PyIArcGISSingleSignon2Object* self)
{
    if (self->m_pIArcGISSingleSignon2)
        self->m_pIArcGISSingleSignon2->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIArcGISSingleSignon2_GetpUnk(PyIArcGISSingleSignon2Object* self)
{
    if (!self->m_pIArcGISSingleSignon2)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIArcGISSingleSignon2->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IArcGISSingleSignon2 to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIArcGISSingleSignon2_GetPointer(PyIArcGISSingleSignon2Object* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIArcGISSingleSignon2);
}

static PyObject*
PyIArcGISSingleSignon2_GetIID(PyIArcGISSingleSignon2Object* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "10ef05c7-241f-4da0-a623-23ef607e0cab");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIArcGISSingleSignon2_GetHR(PyIArcGISSingleSignon2Object* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIArcGISSingleSignon2_GetIgnoreFailures(PyIArcGISSingleSignon2Object* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIArcGISSingleSignon2_SetIgnoreFailures(PyIArcGISSingleSignon2Object* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIArcGISSingleSignon2_SupportsInterface(PyIArcGISSingleSignon2Object* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIArcGISSingleSignon2->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IArcGISSingleSignon2Method_GetBingToken(PyIArcGISSingleSignon2Object* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'BSTR', u'*']
       INPUT [u'BSTR', u'*']
       INPUT [u'long', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IArcGISSingleSignon2.GetBingToken not implemented.");
    return NULL;
}

static PyObject*
IArcGISSingleSignon2Method_GetToken(PyIArcGISSingleSignon2Object* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'BSTR', u'*']
       INPUT [u'BSTR', u'*']
       INPUT [u'long', u'*']
       INPUT [u'BSTR', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IArcGISSingleSignon2.GetToken not implemented.");
    return NULL;
}

static PyObject*
IArcGISSingleSignon2Method_SignOut(PyIArcGISSingleSignon2Object* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIArcGISSingleSignon2->SignOut();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISSingleSignon2->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISSingleSignon2) == S_OK)
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
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISSingleSignon2.SignOut() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IArcGISSingleSignon2Method_GetCurrentToken(PyIArcGISSingleSignon2Object* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'BSTR', u'*']
       INPUT [u'BSTR', u'*']
       INPUT [u'long', u'*']
       INPUT [u'BSTR', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IArcGISSingleSignon2.GetCurrentToken not implemented.");
    return NULL;
}

static PyObject*
IArcGISSingleSignon2Method_GetURI(PyIArcGISSingleSignon2Object* self, PyObject* args)
{
    /* Param types that are unhandleable: 
       INPUT [u'BSTR', u'*']
    */
    PyErr_SetString(PyExc_NotImplementedError, "Wrapper for IArcGISSingleSignon2.GetURI not implemented.");
    return NULL;
}


PyMethodDef PyIArcGISSingleSignon2Methods[] = {
    {"supports", (PyCFunction)PyIArcGISSingleSignon2_SupportsInterface, METH_O, ""},
    {"GetBingToken", (PyCFunction)IArcGISSingleSignon2Method_GetBingToken, METH_VARARGS, ""},
    {"GetToken", (PyCFunction)IArcGISSingleSignon2Method_GetToken, METH_VARARGS, ""},
    {"SignOut", (PyCFunction)IArcGISSingleSignon2Method_SignOut, METH_NOARGS, ""},
    {"GetCurrentToken", (PyCFunction)IArcGISSingleSignon2Method_GetCurrentToken, METH_VARARGS, ""},
    {"GetURI", (PyCFunction)IArcGISSingleSignon2Method_GetURI, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIArcGISSingleSignon2GetSet[] = {
  {"_pUnk", (getter)PyIArcGISSingleSignon2_GetpUnk, NULL, "Get opaque pointer to an Unknown from IArcGISSingleSignon2", NULL},
  {"_pointer", (getter)PyIArcGISSingleSignon2_GetPointer, NULL, "Get memory address for IArcGISSingleSignon2", NULL},
  {"_IID", (getter)PyIArcGISSingleSignon2_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIArcGISSingleSignon2_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIArcGISSingleSignon2_GetIgnoreFailures, (setter)PyIArcGISSingleSignon2_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIArcGISSingleSignon2Object_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_esriSystemUI.IArcGISSingleSignon2Object",                          
                                              /* tp_name */
  sizeof(PyIArcGISSingleSignon2Object),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIArcGISSingleSignon2Object_dealloc,      
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
  PyIArcGISSingleSignon2Methods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIArcGISSingleSignon2GetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIArcGISSingleSignon2Object_new,                      
                                              /* tp_new */
};





static PyObject*
CoCreateDataObjectHelper(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_DataObjectHelper, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of DataObjectHelper");
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
            // clsid_key_lookup = uuid.UUID("e0ccbcb1-cd47-11d5-a9e6-00104bb6fc1c")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "e0ccbcb1-cd47-11d5-a9e6-00104bb6fc1c");
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
CoCreateControlsOperationStack(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_ControlsOperationStack, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of ControlsOperationStack");
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
            // clsid_key_lookup = uuid.UUID("05e57adb-7785-4d48-b982-8255730a41e3")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "05e57adb-7785-4d48-b982-8255730a41e3");
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
CoCreateCommandHost(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_CommandHost, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of CommandHost");
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
            // clsid_key_lookup = uuid.UUID("a318a696-3ed1-4775-a922-147e8c36d79d")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "a318a696-3ed1-4775-a922-147e8c36d79d");
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
CoCreateToolHost(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_ToolHost, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of ToolHost");
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
            // clsid_key_lookup = uuid.UUID("60598c68-56ca-4a38-a2d4-328cb74dc665")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "60598c68-56ca-4a38-a2d4-328cb74dc665");
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
CoCreateComPropertySheetEventsProxyHelper(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_ComPropertySheetEventsProxyHelper, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of ComPropertySheetEventsProxyHelper");
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
            // clsid_key_lookup = uuid.UUID("ef32cd1c-e37d-4524-b8d5-6d89d1e85bed")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "ef32cd1c-e37d-4524-b8d5-6d89d1e85bed");
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
CoCreateSystemFont(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_SystemFont, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of SystemFont");
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
            // clsid_key_lookup = uuid.UUID("f130210c-5478-43de-8012-1c02ddd97ba1")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "f130210c-5478-43de-8012-1c02ddd97ba1");
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
CoCreateSystemMouseCursor(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_SystemMouseCursor, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of SystemMouseCursor");
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
            // clsid_key_lookup = uuid.UUID("cf0c4485-2091-4e5a-a64c-69e4b802f444")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "cf0c4485-2091-4e5a-a64c-69e4b802f444");
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
CoCreateArcGISSingleSignon(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_ArcGISSingleSignon, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of ArcGISSingleSignon");
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
            // clsid_key_lookup = uuid.UUID("dae2351b-241b-426d-a3da-056839a54743")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "dae2351b-241b-426d-a3da-056839a54743");
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



static PyMethodDef _esriSystemUIMethods[] = {
    {"DataObjectHelper", (PyCFunction)CoCreateDataObjectHelper, METH_NOARGS,
     "Create instance of DataObjectHelper\n"},
    {"ControlsOperationStack", (PyCFunction)CoCreateControlsOperationStack, METH_NOARGS,
     "Create instance of ControlsOperationStack\n"},
    {"CommandHost", (PyCFunction)CoCreateCommandHost, METH_NOARGS,
     "Create instance of CommandHost\n"},
    {"ToolHost", (PyCFunction)CoCreateToolHost, METH_NOARGS,
     "Create instance of ToolHost\n"},
    {"ComPropertySheetEventsProxyHelper", (PyCFunction)CoCreateComPropertySheetEventsProxyHelper, METH_NOARGS,
     "Create instance of ComPropertySheetEventsProxyHelper\n"},
    {"SystemFont", (PyCFunction)CoCreateSystemFont, METH_NOARGS,
     "Create instance of SystemFont\n"},
    {"SystemMouseCursor", (PyCFunction)CoCreateSystemMouseCursor, METH_NOARGS,
     "Create instance of SystemMouseCursor\n"},
    {"ArcGISSingleSignon", (PyCFunction)CoCreateArcGISSingleSignon, METH_NOARGS,
     "Create instance of ArcGISSingleSignon\n"},
    {NULL, NULL, 0, NULL}
};

extern "C" {

    PyMODINIT_FUNC
    init_esriSystemUI(void)
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
        module = Py_InitModule3("cartocomutils._esriSystemUI",
                                 _esriSystemUIMethods,
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
        // IProgressDialog
        PyType_Ready(&PyIProgressDialogObject_Type);
        Py_INCREF((PyObject* )&PyIProgressDialogObject_Type);
        PyModule_AddObject(module, "IProgressDialog", 
                           (PyObject *)&PyIProgressDialogObject_Type);

        // ICommand
        PyType_Ready(&PyICommandObject_Type);
        Py_INCREF((PyObject* )&PyICommandObject_Type);
        PyModule_AddObject(module, "ICommand", 
                           (PyObject *)&PyICommandObject_Type);

        // IComponentTip
        PyType_Ready(&PyIComponentTipObject_Type);
        Py_INCREF((PyObject* )&PyIComponentTipObject_Type);
        PyModule_AddObject(module, "IComponentTip", 
                           (PyObject *)&PyIComponentTipObject_Type);

        // IComboBoxHook
        PyType_Ready(&PyIComboBoxHookObject_Type);
        Py_INCREF((PyObject* )&PyIComboBoxHookObject_Type);
        PyModule_AddObject(module, "IComboBoxHook", 
                           (PyObject *)&PyIComboBoxHookObject_Type);

        // IComboBox
        PyType_Ready(&PyIComboBoxObject_Type);
        Py_INCREF((PyObject* )&PyIComboBoxObject_Type);
        PyModule_AddObject(module, "IComboBox", 
                           (PyObject *)&PyIComboBoxObject_Type);

        // ICompletionNotify
        PyType_Ready(&PyICompletionNotifyObject_Type);
        Py_INCREF((PyObject* )&PyICompletionNotifyObject_Type);
        PyModule_AddObject(module, "ICompletionNotify", 
                           (PyObject *)&PyICompletionNotifyObject_Type);

        // IToolControl
        PyType_Ready(&PyIToolControlObject_Type);
        Py_INCREF((PyObject* )&PyIToolControlObject_Type);
        PyModule_AddObject(module, "IToolControl", 
                           (PyObject *)&PyIToolControlObject_Type);

        // IToolPalette
        PyType_Ready(&PyIToolPaletteObject_Type);
        Py_INCREF((PyObject* )&PyIToolPaletteObject_Type);
        PyModule_AddObject(module, "IToolPalette", 
                           (PyObject *)&PyIToolPaletteObject_Type);

        // ITool
        PyType_Ready(&PyIToolObject_Type);
        Py_INCREF((PyObject* )&PyIToolObject_Type);
        PyModule_AddObject(module, "ITool", 
                           (PyObject *)&PyIToolObject_Type);

        // IToolKeys
        PyType_Ready(&PyIToolKeysObject_Type);
        Py_INCREF((PyObject* )&PyIToolKeysObject_Type);
        PyModule_AddObject(module, "IToolKeys", 
                           (PyObject *)&PyIToolKeysObject_Type);

        // IItemDef
        PyType_Ready(&PyIItemDefObject_Type);
        Py_INCREF((PyObject* )&PyIItemDefObject_Type);
        PyModule_AddObject(module, "IItemDef", 
                           (PyObject *)&PyIItemDefObject_Type);

        // ICommandSubType
        PyType_Ready(&PyICommandSubTypeObject_Type);
        Py_INCREF((PyObject* )&PyICommandSubTypeObject_Type);
        PyModule_AddObject(module, "ICommandSubType", 
                           (PyObject *)&PyICommandSubTypeObject_Type);

        // IToolBarDef
        PyType_Ready(&PyIToolBarDefObject_Type);
        Py_INCREF((PyObject* )&PyIToolBarDefObject_Type);
        PyModule_AddObject(module, "IToolBarDef", 
                           (PyObject *)&PyIToolBarDefObject_Type);

        // IMenuDef
        PyType_Ready(&PyIMenuDefObject_Type);
        Py_INCREF((PyObject* )&PyIMenuDefObject_Type);
        PyModule_AddObject(module, "IMenuDef", 
                           (PyObject *)&PyIMenuDefObject_Type);

        // IPaletteDef
        PyType_Ready(&PyIPaletteDefObject_Type);
        Py_INCREF((PyObject* )&PyIPaletteDefObject_Type);
        PyModule_AddObject(module, "IPaletteDef", 
                           (PyObject *)&PyIPaletteDefObject_Type);

        // IMultiItemSeparator
        PyType_Ready(&PyIMultiItemSeparatorObject_Type);
        Py_INCREF((PyObject* )&PyIMultiItemSeparatorObject_Type);
        PyModule_AddObject(module, "IMultiItemSeparator", 
                           (PyObject *)&PyIMultiItemSeparatorObject_Type);

        // IMultiItem
        PyType_Ready(&PyIMultiItemObject_Type);
        Py_INCREF((PyObject* )&PyIMultiItemObject_Type);
        PyModule_AddObject(module, "IMultiItem", 
                           (PyObject *)&PyIMultiItemObject_Type);

        // IMultiItemEx
        PyType_Ready(&PyIMultiItemExObject_Type);
        Py_INCREF((PyObject* )&PyIMultiItemExObject_Type);
        PyModule_AddObject(module, "IMultiItemEx", 
                           (PyObject *)&PyIMultiItemExObject_Type);

        // IComPropertySheetEvents
        PyType_Ready(&PyIComPropertySheetEventsObject_Type);
        Py_INCREF((PyObject* )&PyIComPropertySheetEventsObject_Type);
        PyModule_AddObject(module, "IComPropertySheetEvents", 
                           (PyObject *)&PyIComPropertySheetEventsObject_Type);

        // IOperation
        PyType_Ready(&PyIOperationObject_Type);
        Py_INCREF((PyObject* )&PyIOperationObject_Type);
        PyModule_AddObject(module, "IOperation", 
                           (PyObject *)&PyIOperationObject_Type);

        // IOperationStack
        PyType_Ready(&PyIOperationStackObject_Type);
        Py_INCREF((PyObject* )&PyIOperationStackObject_Type);
        PyModule_AddObject(module, "IOperationStack", 
                           (PyObject *)&PyIOperationStackObject_Type);

        // IToolSelectedLayer
        PyType_Ready(&PyIToolSelectedLayerObject_Type);
        Py_INCREF((PyObject* )&PyIToolSelectedLayerObject_Type);
        PyModule_AddObject(module, "IToolSelectedLayer", 
                           (PyObject *)&PyIToolSelectedLayerObject_Type);

        // ISystemMouseCursor
        PyType_Ready(&PyISystemMouseCursorObject_Type);
        Py_INCREF((PyObject* )&PyISystemMouseCursorObject_Type);
        PyModule_AddObject(module, "ISystemMouseCursor", 
                           (PyObject *)&PyISystemMouseCursorObject_Type);

        // IDataObjectHelper
        PyType_Ready(&PyIDataObjectHelperObject_Type);
        Py_INCREF((PyObject* )&PyIDataObjectHelperObject_Type);
        PyModule_AddObject(module, "IDataObjectHelper", 
                           (PyObject *)&PyIDataObjectHelperObject_Type);

        // ICommandHost
        PyType_Ready(&PyICommandHostObject_Type);
        Py_INCREF((PyObject* )&PyICommandHostObject_Type);
        PyModule_AddObject(module, "ICommandHost", 
                           (PyObject *)&PyICommandHostObject_Type);

        // IArcGISPortal
        PyType_Ready(&PyIArcGISPortalObject_Type);
        Py_INCREF((PyObject* )&PyIArcGISPortalObject_Type);
        PyModule_AddObject(module, "IArcGISPortal", 
                           (PyObject *)&PyIArcGISPortalObject_Type);

        // IArcGISSingleSignon
        PyType_Ready(&PyIArcGISSingleSignonObject_Type);
        Py_INCREF((PyObject* )&PyIArcGISSingleSignonObject_Type);
        PyModule_AddObject(module, "IArcGISSingleSignon", 
                           (PyObject *)&PyIArcGISSingleSignonObject_Type);

        // IArcGISSingleSignon2
        PyType_Ready(&PyIArcGISSingleSignon2Object_Type);
        Py_INCREF((PyObject* )&PyIArcGISSingleSignon2Object_Type);
        PyModule_AddObject(module, "IArcGISSingleSignon2", 
                           (PyObject *)&PyIArcGISSingleSignon2Object_Type);


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
