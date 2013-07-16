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




// Interface IEnumVersions

typedef struct PyIEnumVersionsObject {
    PyObject_HEAD
    IEnumVersions* m_pIEnumVersions;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIEnumVersionsObject;

static PyObject*
PyIEnumVersionsObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIEnumVersionsObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IEnumVersions* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IEnumVersions, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IEnumVersions with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIEnumVersionsObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IEnumVersions");
            return NULL;
        }
        self->m_pIEnumVersions = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IEnumVersions");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IEnumVersions");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IEnumVersions* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IEnumVersions, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IEnumVersions");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIEnumVersionsObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IEnumVersions");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIEnumVersions = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIEnumVersionsObject_dealloc(PyIEnumVersionsObject* self)
{
    if (self->m_pIEnumVersions)
        self->m_pIEnumVersions->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIEnumVersions_GetpUnk(PyIEnumVersionsObject* self)
{
    if (!self->m_pIEnumVersions)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIEnumVersions->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IEnumVersions to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIEnumVersions_GetPointer(PyIEnumVersionsObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIEnumVersions);
}

static PyObject*
PyIEnumVersions_GetIID(PyIEnumVersionsObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "18f07a02-956a-4d44-979b-b006ecc81d93");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIEnumVersions_GetHR(PyIEnumVersionsObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIEnumVersions_GetIgnoreFailures(PyIEnumVersionsObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIEnumVersions_SetIgnoreFailures(PyIEnumVersionsObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIEnumVersions_SupportsInterface(PyIEnumVersionsObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIEnumVersions->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IEnumVersionsMethod_Reset(PyIEnumVersionsObject* self, PyObject* args)
{
    HRESULT hr = 0;
    Py_BEGIN_ALLOW_THREADS
    hr = self->m_pIEnumVersions->Reset();
    Py_END_ALLOW_THREADS
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIEnumVersions->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IEnumVersions) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IEnumVersions.Reset() returned %ld", (long)hr);
        self->m_HR = hr;
        return NULL;
    }
    self->m_HR = hr;
    Py_RETURN_NONE;
}

static PyObject*
IEnumVersionsMethod_Next(PyIEnumVersionsObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriVersionProductCode epCode;
    BSTR bspVer;
    PyObject* pyvar_pVer = Py_None;
    BSTR bspath;
    PyObject* pyvar_path = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pCode
    // No setup for pVer
    // No setup for path

    // Call method on actual COM interface
    hr = self->m_pIEnumVersions->Next(&epCode, &bspVer, &bspath);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIEnumVersions->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IEnumVersions) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IEnumVersions.Next() returned %ld", (long)hr);
        goto ienumversions_next_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pCode
    pyvar_pVer = PyUnicode_FromWideChar(bspVer,::SysStringLen(bspVer));
    ::SysFreeString(bspVer);
    
    if (PyErr_Occurred())
      goto ienumversions_next_method_cleanup;
    
    pyvar_path = PyUnicode_FromWideChar(bspath,::SysStringLen(bspath));
    ::SysFreeString(bspath);
    
    if (PyErr_Occurred())
      goto ienumversions_next_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("iOO",
                                            (int)epCode, pyvar_pVer, pyvar_path);
    goto ienumversions_next_method_cleanup;

    ienumversions_next_method_cleanup:
    self->m_HR = hr;
    // No cleanup for pCode
    if (pyvar_pVer != Py_None)
        Py_XDECREF(pyvar_pVer);
    if (pyvar_path != Py_None)
        Py_XDECREF(pyvar_path);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IEnumVersions.Next");
    return return_tuple;
}


PyMethodDef PyIEnumVersionsMethods[] = {
    {"supports", (PyCFunction)PyIEnumVersions_SupportsInterface, METH_O, ""},
    {"Reset", (PyCFunction)IEnumVersionsMethod_Reset, METH_NOARGS, ""},
    {"Next", (PyCFunction)IEnumVersionsMethod_Next, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIEnumVersionsGetSet[] = {
  {"_pUnk", (getter)PyIEnumVersions_GetpUnk, NULL, "Get opaque pointer to an Unknown from IEnumVersions", NULL},
  {"_pointer", (getter)PyIEnumVersions_GetPointer, NULL, "Get memory address for IEnumVersions", NULL},
  {"_IID", (getter)PyIEnumVersions_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIEnumVersions_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIEnumVersions_GetIgnoreFailures, (setter)PyIEnumVersions_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIEnumVersionsObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_ArcGISVersion.IEnumVersionsObject",                          
                                              /* tp_name */
  sizeof(PyIEnumVersionsObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIEnumVersionsObject_dealloc,      
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
  PyIEnumVersionsMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIEnumVersionsGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIEnumVersionsObject_new,                      
                                              /* tp_new */
};

// Interface IArcGISVersion

typedef struct PyIArcGISVersionObject {
    PyObject_HEAD
    IArcGISVersion* m_pIArcGISVersion;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIArcGISVersionObject;

static PyObject*
PyIArcGISVersionObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIArcGISVersionObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IArcGISVersion* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IArcGISVersion, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IArcGISVersion with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIArcGISVersionObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IArcGISVersion");
            return NULL;
        }
        self->m_pIArcGISVersion = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IArcGISVersion");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IArcGISVersion");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IArcGISVersion* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IArcGISVersion, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IArcGISVersion");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIArcGISVersionObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IArcGISVersion");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIArcGISVersion = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIArcGISVersionObject_dealloc(PyIArcGISVersionObject* self)
{
    if (self->m_pIArcGISVersion)
        self->m_pIArcGISVersion->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIArcGISVersion_GetpUnk(PyIArcGISVersionObject* self)
{
    if (!self->m_pIArcGISVersion)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIArcGISVersion->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IArcGISVersion to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIArcGISVersion_GetPointer(PyIArcGISVersionObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIArcGISVersion);
}

static PyObject*
PyIArcGISVersion_GetIID(PyIArcGISVersionObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "4b666ca0-021e-408c-9abe-a1cc182729fa");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIArcGISVersion_GetHR(PyIArcGISVersionObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIArcGISVersion_GetIgnoreFailures(PyIArcGISVersionObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIArcGISVersion_SetIgnoreFailures(PyIArcGISVersionObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIArcGISVersion_SupportsInterface(PyIArcGISVersionObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIArcGISVersion->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IArcGISVersionMethod_LoadVersion(PyIArcGISVersionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriVersionProductCode eproductCode;
    BSTR bsengineVersion = 0;
    PyObject* pyvar_engineVersion;
    PyObject* unicodeengineVersion = NULL;
    VARIANT_BOOL b_succeeded = VARIANT_FALSE;
    PyObject* pyvar_succeeded = Py_False;

    // Unpack values
    if (!PyArg_ParseTuple(args, "iO", (int *)&eproductCode, &pyvar_engineVersion))
      goto iarcgisversion_loadversion_method_cleanup;

    // Set up initial variable values as needed
    // No setup for productCode
    if (PyString_Check(pyvar_engineVersion))
        unicodeengineVersion = PyUnicode_FromObject(pyvar_engineVersion);
    else if (PyUnicode_Check(pyvar_engineVersion))
    {
        unicodeengineVersion = pyvar_engineVersion;
        Py_INCREF(unicodeengineVersion);
    }
    else if (pyvar_engineVersion != Py_None)
        PyErr_SetString(PyExc_ValueError, "Invalid value for parameter engineVersion at index 1");
    if (unicodeengineVersion)
        bsengineVersion = ::SysAllocStringLen(PyUnicode_AS_UNICODE(unicodeengineVersion), 
                                            (UINT)PyUnicode_GET_SIZE(unicodeengineVersion));
    
    if (PyErr_Occurred())
      goto iarcgisversion_loadversion_method_cleanup;
    
    // No setup for succeeded

    // Call method on actual COM interface
    hr = self->m_pIArcGISVersion->LoadVersion(eproductCode, bsengineVersion, &b_succeeded);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISVersion->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISVersion) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISVersion.LoadVersion() returned %ld", (long)hr);
        goto iarcgisversion_loadversion_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for productCode
    // No teardown for engineVersion
    pyvar_succeeded = ((b_succeeded == VARIANT_TRUE)?Py_True:Py_False);
    if (PyErr_Occurred())
      goto iarcgisversion_loadversion_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_succeeded);
    goto iarcgisversion_loadversion_method_cleanup;

    iarcgisversion_loadversion_method_cleanup:
    self->m_HR = hr;
    // No cleanup for productCode
    if (bsengineVersion)
        ::SysFreeString(bsengineVersion);
    
    // No cleanup for succeeded
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISVersion.LoadVersion");
    return return_tuple;
}

static PyObject*
IArcGISVersionMethod_GetActiveVersion(PyIArcGISVersionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriVersionProductCode epCode;
    BSTR bspVer;
    PyObject* pyvar_pVer = Py_None;
    BSTR bspPath;
    PyObject* pyvar_pPath = Py_None;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for pCode
    // No setup for pVer
    // No setup for pPath

    // Call method on actual COM interface
    hr = self->m_pIArcGISVersion->GetActiveVersion(&epCode, &bspVer, &bspPath);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISVersion->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISVersion) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISVersion.GetActiveVersion() returned %ld", (long)hr);
        goto iarcgisversion_getactiveversion_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for pCode
    pyvar_pVer = PyUnicode_FromWideChar(bspVer,::SysStringLen(bspVer));
    ::SysFreeString(bspVer);
    
    if (PyErr_Occurred())
      goto iarcgisversion_getactiveversion_method_cleanup;
    
    pyvar_pPath = PyUnicode_FromWideChar(bspPath,::SysStringLen(bspPath));
    ::SysFreeString(bspPath);
    
    if (PyErr_Occurred())
      goto iarcgisversion_getactiveversion_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("iOO",
                                            (int)epCode, pyvar_pVer, pyvar_pPath);
    goto iarcgisversion_getactiveversion_method_cleanup;

    iarcgisversion_getactiveversion_method_cleanup:
    self->m_HR = hr;
    // No cleanup for pCode
    if (pyvar_pVer != Py_None)
        Py_XDECREF(pyvar_pVer);
    if (pyvar_pPath != Py_None)
        Py_XDECREF(pyvar_pPath);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISVersion.GetActiveVersion");
    return return_tuple;
}

static PyObject*
IArcGISVersionMethod_GetVersions(PyIArcGISVersionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    IEnumVersions* ipppVersions = NULL;
    PyObject* py_ppVersions = NULL;

    // Unpack values
    // No inputs to unpack

    // Set up initial variable values as needed
    // No setup for ppVersions

    // Call method on actual COM interface
    hr = self->m_pIArcGISVersion->GetVersions(&ipppVersions);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISVersion->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISVersion) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISVersion.GetVersions() returned %ld", (long)hr);
        goto iarcgisversion_getversions_method_cleanup;
    }

    // Set up return values as needed
    Py_XDECREF(py_ppVersions);
    if (ipppVersions)
    {
        IUnknown* pUnk = NULL;
        ipppVersions->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppVersions = IUnknownToPythonIIDObject(pUnk, &IID_IEnumVersions);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppVersions)
    {
        if (py_ppVersions)
           Py_DECREF(py_ppVersions);
        py_ppVersions = Py_None;
        Py_INCREF(py_ppVersions);
    }
    if (PyErr_Occurred())
      goto iarcgisversion_getversions_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppVersions);
    goto iarcgisversion_getversions_method_cleanup;

    iarcgisversion_getversions_method_cleanup:
    self->m_HR = hr;
    Py_XDECREF(py_ppVersions);
    if (ipppVersions)
      ipppVersions->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISVersion.GetVersions");
    return return_tuple;
}

static PyObject*
IArcGISVersionMethod_ProductNameFromCode(PyIArcGISVersionObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    esriVersionProductCode e__MIDL__IArcGISVersion0000;
    BSTR bspProductName;
    PyObject* pyvar_pProductName = Py_None;

    // Unpack values
    if (!PyArg_ParseTuple(args, "i", (int *)&e__MIDL__IArcGISVersion0000))
      goto iarcgisversion_productnamefromcode_method_cleanup;

    // Set up initial variable values as needed
    // No setup for __MIDL__IArcGISVersion0000
    // No setup for pProductName

    // Call method on actual COM interface
    hr = self->m_pIArcGISVersion->ProductNameFromCode(e__MIDL__IArcGISVersion0000, &bspProductName);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIArcGISVersion->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IArcGISVersion) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IArcGISVersion.ProductNameFromCode() returned %ld", (long)hr);
        goto iarcgisversion_productnamefromcode_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for __MIDL__IArcGISVersion0000
    pyvar_pProductName = PyUnicode_FromWideChar(bspProductName,::SysStringLen(bspProductName));
    ::SysFreeString(bspProductName);
    
    if (PyErr_Occurred())
      goto iarcgisversion_productnamefromcode_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            pyvar_pProductName);
    goto iarcgisversion_productnamefromcode_method_cleanup;

    iarcgisversion_productnamefromcode_method_cleanup:
    self->m_HR = hr;
    // No cleanup for __MIDL__IArcGISVersion0000
    if (pyvar_pProductName != Py_None)
        Py_XDECREF(pyvar_pProductName);
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IArcGISVersion.ProductNameFromCode");
    return return_tuple;
}


PyMethodDef PyIArcGISVersionMethods[] = {
    {"supports", (PyCFunction)PyIArcGISVersion_SupportsInterface, METH_O, ""},
    {"LoadVersion", (PyCFunction)IArcGISVersionMethod_LoadVersion, METH_VARARGS, ""},
    {"GetActiveVersion", (PyCFunction)IArcGISVersionMethod_GetActiveVersion, METH_VARARGS, ""},
    {"GetVersions", (PyCFunction)IArcGISVersionMethod_GetVersions, METH_VARARGS, ""},
    {"ProductNameFromCode", (PyCFunction)IArcGISVersionMethod_ProductNameFromCode, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIArcGISVersionGetSet[] = {
  {"_pUnk", (getter)PyIArcGISVersion_GetpUnk, NULL, "Get opaque pointer to an Unknown from IArcGISVersion", NULL},
  {"_pointer", (getter)PyIArcGISVersion_GetPointer, NULL, "Get memory address for IArcGISVersion", NULL},
  {"_IID", (getter)PyIArcGISVersion_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIArcGISVersion_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIArcGISVersion_GetIgnoreFailures, (setter)PyIArcGISVersion_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIArcGISVersionObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_ArcGISVersion.IArcGISVersionObject",                          
                                              /* tp_name */
  sizeof(PyIArcGISVersionObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIArcGISVersionObject_dealloc,      
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
  PyIArcGISVersionMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIArcGISVersionGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIArcGISVersionObject_new,                      
                                              /* tp_new */
};

// Interface IVersionHost

typedef struct PyIVersionHostObject {
    PyObject_HEAD
    IVersionHost* m_pIVersionHost;
    HRESULT m_HR;
    int m_ignore_failures;
} PyIVersionHostObject;

static PyObject*
PyIVersionHostObject_new(PyTypeObject* type, PyObject* args, PyObject* keywds)
{
    PyIVersionHostObject* self = NULL;
    IUnknown* pUnk = NULL;
    GUID pCLSID;

    PyObject* argument;
    if (!PyArg_ParseTuple(args, "O", &argument))
        return NULL;

    // Are we passed a UUID instance?
    if (GuidFromPyObject(argument, &pCLSID))
    {
        IVersionHost* pIFace;
        HRESULT hr = ::CoCreateInstance(pCLSID, 0, CLSCTX_ALL, IID_IVersionHost, (void**)&pIFace);
        if (FAILED(hr))
        {
            PyErr_SetString(PyExc_RuntimeError, "Could not CoCreate IVersionHost with provided CLSID");
            return NULL;
        }
        if (!(self = ((PyIVersionHostObject *)type->tp_alloc(type, 0))))
        {
            PyErr_SetString(PyExc_MemoryError, "Could not allocate IVersionHost");
            return NULL;
        }
        self->m_pIVersionHost = pIFace;
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
            PyErr_SetString(PyExc_ValueError, "Not an acceptable value for IVersionHost");
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
            PyErr_SetString(PyExc_TypeError, "Not an acceptable pointer type to IVersionHost");
            Py_XDECREF(argument);
            return NULL;
        }
        Py_XDECREF(argument);
    }

    // Null pointers!
    if (pUnk == NULL)
        Py_RETURN_NONE;

    IVersionHost* pmVar = NULL;
    if (FAILED(pUnk->QueryInterface(IID_IVersionHost, (void**)&pmVar)))
    {
        PyErr_SetString(PyExc_TypeError, "Could not convert to IVersionHost");
        return NULL;
    }

    if (pmVar == NULL)
        Py_RETURN_NONE;

    if (!(self = ((PyIVersionHostObject *)type->tp_alloc(type, 0))))
    {
        PyErr_SetString(PyExc_MemoryError, "Could not allocate IVersionHost");
        return NULL;
    }

    //pmVar->AddRef();
    self->m_pIVersionHost = pmVar;
    self->m_HR = S_OK;
    self->m_ignore_failures = 0;
    return (PyObject *)self;
}

static void
PyIVersionHostObject_dealloc(PyIVersionHostObject* self)
{
    if (self->m_pIVersionHost)
        self->m_pIVersionHost->Release();
    self->ob_type->tp_free(self);    
}

static PyObject*
PyIVersionHost_GetpUnk(PyIVersionHostObject* self)
{
    if (!self->m_pIVersionHost)
        Py_RETURN_NONE;
    IUnknown* pu = NULL;
    
    HRESULT hr;
    if (FAILED(hr = self->m_pIVersionHost->QueryInterface(IID_IUnknown, (void **)&pu)))
    {
        PyErr_SetString(PyExc_TypeError, "Cannot QI IVersionHost to Unknown?");
        return NULL;
    }

    self->m_HR = hr;

    if (!pu)
        Py_RETURN_NONE;

    return PyCObject_FromVoidPtr((void*)pu, destr_unknown);
}

static PyObject*
PyIVersionHost_GetPointer(PyIVersionHostObject* self)
{
    return PyLong_FromVoidPtr((void*)self->m_pIVersionHost);
}

static PyObject*
PyIVersionHost_GetIID(PyIVersionHostObject* self)
{
    if (g_pUUID_type)
        return PyObject_CallFunction(g_pUUID_type, "s", "a4092e33-e459-4b9c-b04e-263fb7a8e1d1");
    PyErr_SetString(PyExc_ImportError, "No UUID module loaded!");
    return NULL;
}

static PyObject*
PyIVersionHost_GetHR(PyIVersionHostObject* self)
{
    return PyLong_FromUnsignedLong((unsigned long)self->m_HR);
}

static PyObject*
PyIVersionHost_GetIgnoreFailures(PyIVersionHostObject* self)
{
    if (self->m_ignore_failures)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static int
PyIVersionHost_SetIgnoreFailures(PyIVersionHostObject* self, PyObject* val)
{
    self->m_ignore_failures = PyObject_IsTrue(val);
    return 0;
}

static PyObject*
PyIVersionHost_SupportsInterface(PyIVersionHostObject* self, PyObject* iface)
{
    GUID iid;
    if (GuidFromPyObject(iface, &iid))
    {
        IUnknown* ipUnk;
        if (SUCCEEDED(self->m_pIVersionHost->QueryInterface(iid, (void**)&ipUnk)) && ipUnk)
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
IVersionHostMethod_CreateObject(PyIVersionHostObject* self, PyObject* args)
{
    PyObject* return_tuple = NULL;
    HRESULT hr = 0;

    // Initialize variables
    PyObject* py_clsid = NULL;
    GUID gclsid;
    IUnknown* ipppv = NULL;
    PyObject* py_ppv = NULL;

    // Unpack values
    if (!PyArg_ParseTuple(args, "O", &py_clsid))
      goto iversionhost_createobject_method_cleanup;

    // Set up initial variable values as needed
    if (!GuidFromPyObject(py_clsid, &gclsid))
        PyErr_SetString(PyExc_TypeError, "Argument clsid (position 0) is not UUID");
    
    if (PyErr_Occurred())
      goto iversionhost_createobject_method_cleanup;
    
    // No setup for ppv

    // Call method on actual COM interface
    hr = self->m_pIVersionHost->CreateObject(gclsid, &ipppv);
    if (FAILED(hr) && !(self->m_ignore_failures))
    {
        ISupportErrorInfo* pSuppErrInfo;
        if (SUCCEEDED(self->m_pIVersionHost->QueryInterface(IID_ISupportErrorInfo, (void**)&pSuppErrInfo)) 
            && pSuppErrInfo
            && pSuppErrInfo->InterfaceSupportsErrorInfo(IID_IVersionHost) == S_OK)
        {
            IErrorInfo* pErrInfo = 0; 
            if (::GetErrorInfo(0, &pErrInfo) == S_OK 
                && pErrInfo)
            {
                BSTR errstring;
                pErrInfo->GetDescription(&errstring);
                PyObject* pyErrMsg = PyUnicode_FromWideChar(errstring,::SysStringLen(errstring));
                ::SysFreeString(errstring);
                PyErr_SetObject(PyExc_RuntimeError, pyErrMsg);
                Py_XDECREF(pyErrMsg);
                pErrInfo->Release();
            }
        }
        if (pSuppErrInfo)
            pSuppErrInfo->Release();
        if (!PyErr_Occurred())
            PyErr_Format(PyExc_RuntimeError, "Failure: IVersionHost.CreateObject() returned %ld", (long)hr);
        goto iversionhost_createobject_method_cleanup;
    }

    // Set up return values as needed
    // No teardown for clsid
    Py_XDECREF(py_ppv);
    if (ipppv)
    {
        IUnknown* pUnk = NULL;
        ipppv->QueryInterface(IID_IUnknown, (void **)&pUnk);
        py_ppv = IUnknownToPythonIIDObject(pUnk, &IID_IUnknown);
        if (pUnk)
           pUnk->Release();}
    if (PyErr_Occurred() || !py_ppv)
    {
        if (py_ppv)
           Py_DECREF(py_ppv);
        py_ppv = Py_None;
        Py_INCREF(py_ppv);
    }
    if (PyErr_Occurred())
      goto iversionhost_createobject_method_cleanup;
    

    // Initialize output tuple
    return_tuple = Py_BuildValue("O",
                                            py_ppv);
    goto iversionhost_createobject_method_cleanup;

    iversionhost_createobject_method_cleanup:
    self->m_HR = hr;
    // No cleanup for clsid
    Py_XDECREF(py_ppv);
    if (ipppv)
      ipppv->Release();
    if (!return_tuple && !PyErr_Occurred())
        PyErr_SetString(PyExc_RuntimeError, "Unspecified error in IVersionHost.CreateObject");
    return return_tuple;
}


PyMethodDef PyIVersionHostMethods[] = {
    {"supports", (PyCFunction)PyIVersionHost_SupportsInterface, METH_O, ""},
    {"CreateObject", (PyCFunction)IVersionHostMethod_CreateObject, METH_VARARGS, ""},
    {NULL, NULL, NULL, NULL}
};

PyGetSetDef PyIVersionHostGetSet[] = {
  {"_pUnk", (getter)PyIVersionHost_GetpUnk, NULL, "Get opaque pointer to an Unknown from IVersionHost", NULL},
  {"_pointer", (getter)PyIVersionHost_GetPointer, NULL, "Get memory address for IVersionHost", NULL},
  {"_IID", (getter)PyIVersionHost_GetIID, NULL, "Get reference to the GUID for this interface", NULL},
  {"_HR", (getter)PyIVersionHost_GetHR, NULL, "Get the HRESULT from the last function call on this object", NULL},
  {"_ignore_failures", (getter)PyIVersionHost_GetIgnoreFailures, (setter)PyIVersionHost_SetIgnoreFailures, "Whether to raise if the HR is a failure", NULL},
  {NULL, NULL, NULL, NULL, NULL}
};

static PyTypeObject PyIVersionHostObject_Type = {
  PyObject_HEAD_INIT(NULL)
  0,                                          /* ob_size */
  "_ArcGISVersion.IVersionHostObject",                          
                                              /* tp_name */
  sizeof(PyIVersionHostObject),                  
                                              /* tp_basicsize */
  0,                                          /* tp_itemsize */
  (destructor)PyIVersionHostObject_dealloc,      
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
  PyIVersionHostMethods,
                                              /* tp_methods */
  0,                                          /* tp_members */
  PyIVersionHostGetSet,
                                              /* tp_getset */
  0,                                          /* tp_base */
  0,                                          /* tp_dict */
  0,                                          /* tp_descr_get */
  0,                                          /* tp_descr_set */
  0,                                          /* tp_dictoffset */
  0,                                          /* tp_init */
  0,                                          /* tp_alloc */
  PyIVersionHostObject_new,                      
                                              /* tp_new */
};





static PyObject*
CoCreateArcGISVersionManager(PyObject* self)
{
    IUnknown* pUnk;

    HRESULT hr = ::CoCreateInstance(CLSID_ArcGISVersionManager, 0, CLSCTX_ALL, IID_IUnknown, (void**)&pUnk);

    if (FAILED(hr))
    {
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize instance of ArcGISVersionManager");
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
            // clsid_key_lookup = uuid.UUID("d0705d7d-0270-4607-bcdb-1d4f18624748")
            clsid_key_lookup = PyObject_CallFunction(g_pUUID_type, "s", "d0705d7d-0270-4607-bcdb-1d4f18624748");
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



static PyMethodDef _ArcGISVersionMethods[] = {
    {"ArcGISVersionManager", (PyCFunction)CoCreateArcGISVersionManager, METH_NOARGS,
     "Create instance of ArcGISVersionManager\n"},
    {NULL, NULL, 0, NULL}
};

extern "C" {

    PyMODINIT_FUNC
    init_ArcGISVersion(void)
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
        module = Py_InitModule3("cartocomutils._ArcGISVersion",
                                 _ArcGISVersionMethods,
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
        // IEnumVersions
        PyType_Ready(&PyIEnumVersionsObject_Type);
        Py_INCREF((PyObject* )&PyIEnumVersionsObject_Type);
        PyModule_AddObject(module, "IEnumVersions", 
                           (PyObject *)&PyIEnumVersionsObject_Type);

        // IArcGISVersion
        PyType_Ready(&PyIArcGISVersionObject_Type);
        Py_INCREF((PyObject* )&PyIArcGISVersionObject_Type);
        PyModule_AddObject(module, "IArcGISVersion", 
                           (PyObject *)&PyIArcGISVersionObject_Type);

        // IVersionHost
        PyType_Ready(&PyIVersionHostObject_Type);
        Py_INCREF((PyObject* )&PyIVersionHostObject_Type);
        PyModule_AddObject(module, "IVersionHost", 
                           (PyObject *)&PyIVersionHostObject_Type);


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
