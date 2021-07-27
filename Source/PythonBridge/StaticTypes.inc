Py_DebugFlag:cint; cvar; external;
Py_VerboseFlag:cint; cvar; external;
Py_InteractiveFlag:cint; cvar; external;
Py_OptimizeFlag:cint; cvar; external;
Py_NoSiteFlag:cint; cvar; external;
Py_FrozenFlag:cint; cvar; external;
Py_IgnoreEnvironmentFlag:cint; cvar; external;
PyImport_FrozenModules:PP_frozen; cvar; external;
Py_Ellipsis:PPyObject; cvar; external;
// https://docs.python.org/3.3/c-api/bool.html
Py_None:PPyObject = nil;
Py_False:PPyIntObject = nil;
Py_True:PPyIntObject = nil;
_Py_TrueStruct:PPyIntObject; cvar; external;
_Py_NoneStruct:PPyIntObject; cvar; external;
_Py_FalseStruct:PPyIntObject; cvar; external;
Py_NotImplemented:PPyObject; cvar; external;
PyExc_AttributeError:PPPyObject; cvar; external;
PyExc_EOFError:PPPyObject; cvar; external;
PyExc_IOError:PPPyObject; cvar; external;
PyExc_ImportError:PPPyObject; cvar; external;
PyExc_IndexError:PPPyObject; cvar; external;
PyExc_KeyError:PPPyObject; cvar; external;
PyExc_KeyboardInterrupt:PPPyObject; cvar; external;
PyExc_MemoryError:PPPyObject; cvar; external;
PyExc_NameError:PPPyObject; cvar; external;
PyExc_OverflowError:PPPyObject; cvar; external;
PyExc_RuntimeError:PPPyObject; cvar; external;
PyExc_SyntaxError:PPPyObject; cvar; external;
PyExc_SystemError:PPPyObject; cvar; external;
PyExc_SystemExit:PPPyObject; cvar; external;
PyExc_TypeError:PPPyObject; cvar; external;
PyExc_ValueError:PPPyObject; cvar; external;
PyExc_ZeroDivisionError:PPPyObject; cvar; external;
PyExc_ArithmeticError:PPPyObject; cvar; external;
PyExc_Exception:PPPyObject; cvar; external;
PyExc_FloatingPointError:PPPyObject; cvar; external;
PyExc_LookupError:PPPyObject; cvar; external;
PyExc_AssertionError:PPPyObject; cvar; external;
PyExc_EnvironmentError:PPPyObject; cvar; external;
PyExc_IndentationError:PPPyObject; cvar; external;
PyExc_MemoryErrorInst:PPPyObject; cvar; external;
PyExc_NotImplementedError:PPPyObject; cvar; external;
PyExc_OSError:PPPyObject; cvar; external;
PyExc_TabError:PPPyObject; cvar; external;
PyExc_UnboundLocalError:PPPyObject; cvar; external;
PyExc_UnicodeError:PPPyObject; cvar; external;
PyExc_WindowsError:PPPyObject; cvar; external;
PyExc_Warning:PPPyObject; cvar; external;
PyExc_DeprecationWarning:PPPyObject; cvar; external;
PyExc_RuntimeWarning:PPPyObject; cvar; external;
PyExc_SyntaxWarning:PPPyObject; cvar; external;
PyExc_UserWarning:PPPyObject; cvar; external;
PyExc_ReferenceError:PPPyObject; cvar; external;
PyExc_StopIteration:PPPyObject; cvar; external;
PyExc_FutureWarning:PPPyObject; cvar; external;
PyExc_PendingDeprecationWarning:PPPyObject; cvar; external;
PyExc_UnicodeDecodeError:PPPyObject; cvar; external;
PyExc_UnicodeEncodeError:PPPyObject; cvar; external;
PyExc_UnicodeTranslateError:PPPyObject; cvar; external;
PyType_Type:PPyTypeObject; cvar; external;
PyCFunction_Type:PPyTypeObject; cvar; external;
PyCObject_Type:PPyTypeObject; cvar; external;
PyCode_Type:PPyTypeObject; cvar; external;
PyComplex_Type:PPyTypeObject; cvar; external;
PyDict_Type:PPyTypeObject; cvar; external;
PyFile_Type:PPyTypeObject; cvar; external;
PyFloat_Type:PPyTypeObject; cvar; external;
PyFrame_Type:PPyTypeObject; cvar; external;
PyFunction_Type:PPyTypeObject; cvar; external;
PyList_Type:PPyTypeObject; cvar; external;
PyLong_Type:PPyTypeObject; cvar; external;
PyMethod_Type:PPyTypeObject; cvar; external;
PyModule_Type:PPyTypeObject; cvar; external;
PyObject_Type:PPyTypeObject; cvar; external;
PyRange_Type:PPyTypeObject; cvar; external;
PySlice_Type:PPyTypeObject; cvar; external;
PyTuple_Type:PPyTypeObject; cvar; external;
PyBaseObject_Type:PPyTypeObject; cvar; external;
PyBuffer_Type:PPyTypeObject; cvar; external;
PyCallIter_Type:PPyTypeObject; cvar; external;
PyCell_Type:PPyTypeObject; cvar; external;
PyClassMethod_Type:PPyTypeObject; cvar; external;
PyProperty_Type:PPyTypeObject; cvar; external;
PySeqIter_Type:PPyTypeObject; cvar; external;
PyStaticMethod_Type:PPyTypeObject; cvar; external;
PySuper_Type:PPyTypeObject; cvar; external;
PyTraceBack_Type:PPyTypeObject; cvar; external;
PyUnicode_Type:PPyTypeObject; cvar; external;
PyWrapperDescr_Type:PPyTypeObject; cvar; external;
_PyWeakref_RefType:PPyTypeObject; cvar; external;
_PyWeakref_ProxyType:PPyTypeObject; cvar; external;
_PyWeakref_CallableProxyType:PPyTypeObject; cvar; external;
PyBool_Type:PPyTypeObject; cvar; external;
PyEnum_Type:PPyTypeObject; cvar; external;
PyBytes_Type:PPyTypeObject; cvar; external;

function PyComplex_FromCComplex (c: Py_complex):PPyObject; cdecl; external;
function PyComplex_FromDoubles (realv,imag : double):PPyObject; cdecl; external;
function PyComplex_RealAsDouble (op : PPyObject ): double; cdecl; external;
function PyComplex_ImagAsDouble (op : PPyObject ): double; cdecl; external;
function PyComplex_AsCComplex (op : PPyObject ): Py_complex; cdecl; external;
function PyCFunction_GetFunction (ob : PPyObject): Pointer; cdecl; external;
function PyCFunction_GetSelf (ob : PPyObject): PPyObject; cdecl; external;
function PyCallable_Check (ob : PPyObject): integer; cdecl; external;
function PyClass_New (ob1,ob2,ob3 :  PPyObject): PPyObject; cdecl; external;
//function PyClass_New (ob1,ob2,ob3 :  PPyObject): PPyObject; cdecl; external name 'PyObject_New';
//function PyClass_IsSubclass (ob1, ob2 : PPyObject): integer; cdecl; external name 'PyObject_IsSubclass';
function PyModule_Create (moduledef: PPyModuleDef):PPyObject; cdecl; external name '_PyModule_CreateInitialized';
function PyModule_Create2 (moduledef: PPyModuleDef; Api_Version: Integer):PPyObject; cdecl; external;
function PyErr_BadArgument : integer; cdecl; external;
procedure PyErr_BadInternalCall ; cdecl; external;
function PyErr_CheckSignals : integer; cdecl; external;
procedure PyErr_Clear ; cdecl; external;
procedure PyErr_Fetch ( errtype, errvalue, errtraceback: PPPyObject); cdecl; external;
function PyErr_NoMemory : PPyObject; cdecl; external;
function PyErr_Occurred : PPyObject; cdecl; external;
procedure PyErr_Print ; cdecl; external;
procedure PyErr_Restore (errtype, errvalue, errtraceback: PPyObject); cdecl; external;
function PyErr_SetFromErrno (ob :  PPyObject):PPyObject; cdecl; external;
procedure PyErr_SetNone (value: PPyObject); cdecl; external;
procedure PyErr_SetObject (ob1, ob2  : PPyObject); cdecl; external;
procedure PyErr_SetString ( ErrorObject: PPyObject; text: PAnsiChar); cdecl; external;
function PyImport_GetModuleDict : PPyObject; cdecl; external;
function PyArg_Parse ( args: PPyObject; format: PAnsiChar) :  Integer; cdecl varargs; external;
//function PyArg_ParseTuple ( args: PPyObject; format: PAnsiChar): Integer; cdecl varargs; external;
function PyArg_ParseTuple ( args: PPyObject; format: PAnsiChar {;...}): Integer; cdecl varargs; external;
function Py_BuildValue ( format: PAnsiChar): PPyObject; cdecl varargs; external;
procedure Py_Initialize ; cdecl; external;
procedure Py_Exit ( RetVal: Integer); cdecl; external;
function PyEval_GetBuiltins : PPyObject; cdecl; external;
function PyDict_Copy (mp: PPyObject):PPyObject; cdecl; external;
function PyDict_GetItem (mp, key : PPyObject):PPyObject; cdecl; external;
function PyDict_SetItem (mp, key, item :PPyObject ):integer; cdecl; external;
function PyDict_DelItem (mp, key : PPyObject ):integer; cdecl; external;
procedure PyDict_Clear (mp : PPyObject); cdecl; external;
function PyDict_Next (mp : PPyObject; pos: PNativeInt; key, value: PPPyObject):integer; cdecl; external;
function PyDict_Keys (mp: PPyObject):PPyObject; cdecl; external;
function PyDict_Values (mp: PPyObject):PPyObject; cdecl; external;
function PyDict_Items (mp: PPyObject):PPyObject; cdecl; external;
function PyDict_Size (mp: PPyObject):NativeInt; cdecl; external;
function PyDict_DelItemString (dp : PPyObject;key : PAnsiChar ):integer; cdecl; external;
function PyDict_New : PPyObject; cdecl; external;
function PyDict_GetItemString ( dp: PPyObject; key: PAnsiChar): PPyObject; cdecl; external;
function PyDict_SetItemString ( dp: PPyObject; key: PAnsiChar; item: PPyObject): Integer; cdecl; external;
function PyDictProxy_New (obj : PPyObject) : PPyObject; cdecl; external;
function PyModule_GetDict ( module:PPyObject): PPyObject; cdecl; external;
function PyObject_Str ( v: PPyObject): PPyObject; cdecl; external;
function PyRun_String ( str: PAnsiChar; start: Integer; globals: PPyObject; locals: PPyObject): PPyObject; cdecl; external;
function PyRun_SimpleString ( str: PAnsiChar): Integer; cdecl; external;
function PyBytes_AsString ( ob: PPyObject): PAnsiChar; cdecl; external;
function PyBytes_AsStringAndSize ( ob: PPyObject; var buffer: PAnsiChar; var size: NativeInt): integer; cdecl; external;
procedure PySys_SetArgv ( argc: Integer; argv: PPWideChar); cdecl; external;
function PyCFunction_New (md:PPyMethodDef;ob:PPyObject):PPyObject; cdecl; external;
function PyCFunction_NewEx (md:PPyMethodDef;self, ob:PPyObject):PPyObject; cdecl; external;
function PyEval_CallObjectWithKeywords (callable_obj, args, kw:PPyObject):PPyObject; cdecl; external;
function PyEval_GetFrame :PPyObject; cdecl; external;
function PyEval_GetGlobals :PPyObject; cdecl; external;
function PyEval_GetLocals :PPyObject; cdecl; external;
function PyEval_GetRestricted :integer; cdecl; external;
procedure PyEval_InitThreads ; cdecl; external;
procedure PyEval_RestoreThread ( tstate: PPyThreadState); cdecl; external;
function PyEval_SaveThread :PPyThreadState; cdecl; external;
function PyFile_FromString (pc1,pc2:PAnsiChar):PPyObject; cdecl; external;
function PyFile_GetLine (ob:PPyObject;i:integer):PPyObject; cdecl; external;
function PyFile_Name (ob:PPyObject):PPyObject; cdecl; external;
procedure PyFile_SetBufSize (ob:PPyObject;i:integer); cdecl; external;
function PyFile_SoftSpace (ob:PPyObject;i:integer):integer; cdecl; external;
function PyFile_WriteObject (ob1,ob2:PPyObject;i:integer):integer; cdecl; external;
procedure PyFile_WriteString (s:PAnsiChar;ob:PPyObject); cdecl; external;
function PyFloat_AsDouble (ob:PPyObject):DOUBLE; cdecl; external;
function PyFloat_FromDouble (db:double):PPyObject; cdecl; external;
function PyFunction_GetCode (ob:PPyObject):PPyObject; cdecl; external;
function PyFunction_GetGlobals (ob:PPyObject):PPyObject; cdecl; external;
function PyFunction_New (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyImport_AddModule (name:PAnsiChar):PPyObject; cdecl; external;
procedure PyImport_Cleanup ; cdecl; external;
function PyImport_GetMagicNumber :LONGINT; cdecl; external;
function PyImport_ImportFrozenModule (key:PAnsiChar):integer; cdecl; external;
function PyImport_ImportModule (name:PAnsiChar):PPyObject; cdecl; external;
function PyImport_Import (name:PPyObject):PPyObject; cdecl; external;
function PyImport_ReloadModule (ob:PPyObject):PPyObject; cdecl; external;
function PyInstance_New (obClass, obArg, obKW:PPyObject):PPyObject; cdecl; external;
function PyList_Append (ob1,ob2:PPyObject):integer; cdecl; external;
function PyList_AsTuple (ob:PPyObject):PPyObject; cdecl; external;
function PyList_GetItem (ob:PPyObject;i:NativeInt):PPyObject; cdecl; external;
function PyList_GetSlice (ob:PPyObject;i1,i2:NativeInt):PPyObject; cdecl; external;
function PyList_Insert (dp:PPyObject;idx:NativeInt;item:PPyObject):integer; cdecl; external;
function PyList_New (size:NativeInt):PPyObject; cdecl; external;
function PyList_Reverse (ob:PPyObject):integer; cdecl; external;
function PyList_SetItem (dp:PPyObject;idx:NativeInt;item:PPyObject):integer; cdecl; external;
function PyList_SetSlice (ob:PPyObject;i1,i2:NativeInt;ob2:PPyObject):integer; cdecl; external;
function PyList_Size (ob:PPyObject):NativeInt; cdecl; external;
function PyList_Sort (ob:PPyObject):integer; cdecl; external;
function PyLong_AsDouble (ob:PPyObject):DOUBLE; cdecl; external;
function PyLong_AsLong (ob:PPyObject):LONGINT; cdecl; external;
function PyLong_FromDouble (db:double):PPyObject; cdecl; external;
function PyLong_FromLong (l:longint):PPyObject; cdecl; external;
function PyLong_FromString (pc:PAnsiChar;var ppc:PAnsiChar;i:integer):PPyObject; cdecl; external;
function PyLong_FromUnsignedLong (val:cardinal) : PPyObject; cdecl; external;
function PyLong_AsUnsignedLong (ob:PPyObject) : Cardinal; cdecl; external;
function PyLong_FromUnicode (ob:PPyObject; a, b : integer) : PPyObject; cdecl; external;
function PyLong_FromLongLong (val:Int64) : PPyObject; cdecl; external;
function PyLong_AsLongLong (ob:PPyObject) : Int64; cdecl; external;
function PyMapping_Check (ob:PPyObject):integer; cdecl; external;
function PyMapping_GetItemString (ob:PPyObject;key:PAnsiChar):PPyObject; cdecl; external;
function PyMapping_HasKey (ob,key:PPyObject):integer; cdecl; external;
function PyMapping_HasKeyString (ob:PPyObject;key:PAnsiChar):integer; cdecl; external;
function PyMapping_Length (ob:PPyObject):NativeInt; cdecl; external;
function PyMapping_SetItemString (ob:PPyObject; key:PAnsiChar; value:PPyObject):integer; cdecl; external;
function PyMethod_Class (ob:PPyObject):PPyObject; cdecl; external;
function PyMethod_Function (ob:PPyObject):PPyObject; cdecl; external;
function PyMethod_New (ob1,ob2,ob3:PPyObject):PPyObject; cdecl; external;
function PyMethod_Self (ob:PPyObject):PPyObject; cdecl; external;
function PyModule_GetName (ob:PPyObject):PAnsiChar; cdecl; external;
function PyModule_New (key:PAnsiChar):PPyObject; cdecl; external;
function PyNumber_Absolute (ob:PPyObject):PPyObject; cdecl; external;
function PyNumber_Add (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_And (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_Check (ob:PPyObject):integer; cdecl; external;
function PyNumber_Coerce (var ob1,ob2:PPyObject):integer; cdecl; external;
function PyNumber_Divide (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_FloorDivide (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_TrueDivide (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_Divmod (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_Float (ob:PPyObject):PPyObject; cdecl; external;
function PyNumber_Int (ob:PPyObject):PPyObject; cdecl; external;
function PyNumber_Invert (ob:PPyObject):PPyObject; cdecl; external;
function PyNumber_Long (ob:PPyObject):PPyObject; cdecl; external;
function PyNumber_Lshift (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_Multiply (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_Negative (ob:PPyObject):PPyObject; cdecl; external;
function PyNumber_Or (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_Positive (ob:PPyObject):PPyObject; cdecl; external;
function PyNumber_Power (ob1,ob2,ob3:PPyObject):PPyObject; cdecl; external;
function PyNumber_Remainder (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_Rshift (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_Subtract (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyNumber_Xor (ob1,ob2:PPyObject):PPyObject; cdecl; external;
procedure PyOS_InitInterrupts ; cdecl; external;
function PyOS_InterruptOccurred :integer; cdecl; external;
function PyObject_CallObject (ob,args:PPyObject):PPyObject; cdecl; external;
function PyObject_CallMethod ( obj : PPyObject; method, format : PAnsiChar {...}) : PPyObject; cdecl varargs; external;
function PyObject_Compare (ob1,ob2:PPyObject):integer; cdecl; external;
function PyObject_RichCompare (ob1,ob2:PPyObject;opid:integer):PPyObject; cdecl; external;
function PyObject_RichCompareBool (ob1,ob2:PPyObject;opid:integer):Integer; cdecl; external;
function PyObject_GetAttr (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PyObject_GetAttrString (ob:PPyObject;c:PAnsiChar):PPyObject; cdecl; external;
function PyObject_GetItem (ob,key:PPyObject):PPyObject; cdecl; external;
function PyObject_DelItem (ob,key:PPyObject):PPyObject; cdecl; external;
function PyObject_HasAttrString (ob:PPyObject;key:PAnsiChar):integer; cdecl; external;
function PyObject_Hash (ob:PPyObject):NativeInt; cdecl; external;
function PyObject_IsTrue (ob:PPyObject):integer; cdecl; external;
function PyObject_Length (ob:PPyObject):NativeInt; cdecl; external;
function PyObject_Repr (ob:PPyObject):PPyObject; cdecl; external;
function PyObject_SetAttr (ob1,ob2,ob3:PPyObject):integer; cdecl; external;
function PyObject_SetAttrString (ob:PPyObject;key:PAnsiChar;value:PPyObject):integer; cdecl; external;
function PyObject_SetItem (ob1,ob2,ob3:PPyObject):integer; cdecl; external;
function PyObject_Init (ob:PPyObject; t:PPyTypeObject):PPyObject; cdecl; external;
function PyObject_InitVar (ob:PPyObject; t:PPyTypeObject; size:NativeInt):PPyObject; cdecl; external;
function PyObject_New (t:PPyTypeObject):PPyObject; cdecl; external;
function PyObject_NewVar (t:PPyTypeObject; size:NativeInt):PPyObject; cdecl; external;
procedure PyObject_Free (ob:PPyObject); cdecl; external;
function PyObject_GetIter (obj: PPyObject) : PPyObject; cdecl; external;
function PyIter_Next (obj: PPyObject) : PPyObject; cdecl; external;
function PyObject_IsInstance (inst, cls:PPyObject):integer; cdecl; external;
function PyObject_IsSubclass (derived, cls:PPyObject):integer; cdecl; external;
function PyObject_Call (ob, args, kw:PPyObject):PPyObject; cdecl; external;
function PyObject_GenericGetAttr (obj, name : PPyObject) : PPyObject; cdecl; external;
function PyObject_GenericSetAttr (obj, name, value : PPyObject) : Integer; cdecl; external;
function PyObject_GC_Malloc (size:NativeUInt):PPyObject; cdecl; external;
function PyObject_GC_New (t:PPyTypeObject):PPyObject; cdecl; external;
function PyObject_GC_NewVar (t:PPyTypeObject; size:NativeInt):PPyObject; cdecl; external;
function PyObject_GC_Resize (t:PPyObject; newsize:NativeInt):PPyObject; cdecl; external;
procedure PyObject_GC_Del (ob:PPyObject); cdecl; external;
procedure PyObject_GC_Track (ob:PPyObject); cdecl; external;
procedure PyObject_GC_UnTrack (ob:PPyObject); cdecl; external;
function PySequence_Check (ob:PPyObject):integer; cdecl; external;
function PySequence_Concat (ob1,ob2:PPyObject):PPyObject; cdecl; external;
function PySequence_Count (ob1,ob2:PPyObject):integer; cdecl; external;
function PySequence_GetItem (ob:PPyObject;i:NativeInt):PPyObject; cdecl; external;
function PySequence_GetSlice (ob:PPyObject;i1,i2:NativeInt):PPyObject; cdecl; external;
function PySequence_In (ob1,ob2:PPyObject):integer; cdecl; external;
function PySequence_Index (ob1,ob2:PPyObject):NativeInt; cdecl; external;
function PySequence_Length (ob:PPyObject):NativeInt; cdecl; external;
function PySequence_Repeat (ob:PPyObject;count:NativeInt):PPyObject; cdecl; external;
function PySequence_SetItem (ob:PPyObject;i:NativeInt;value:PPyObject):integer; cdecl; external;
function PySequence_SetSlice (ob:PPyObject;i1,i2:NativeInt;value:PPyObject):integer; cdecl; external;
function PySequence_DelSlice (ob:PPyObject;i1,i2:NativeInt):integer; cdecl; external;
function PySequence_Tuple (ob:PPyObject):PPyObject; cdecl; external;
function PySequence_Contains (ob, value:PPyObject):integer; cdecl; external;
function PySeqIter_New (obj : PPyObject) : PPyObject; cdecl; external;
function PySlice_GetIndices (ob:PPySliceObject;length:NativeInt;var start,stop,step:NativeInt):integer; cdecl; external;
function PySlice_GetIndicesEx (ob:PPySliceObject;length:NativeInt;var start,stop,step,slicelength:NativeInt):integer; cdecl; external;
function PySlice_New (start,stop,step:PPyObject):PPyObject; cdecl; external;
procedure PyBytes_Concat (var ob1:PPyObject;ob2:PPyObject); cdecl; external;
procedure PyBytes_ConcatAndDel (var ob1:PPyObject;ob2:PPyObject); cdecl; external;
function PyBytes_FromStringAndSize (s:PAnsiChar;i:NativeInt):PPyObject; cdecl; external;
function PyBytes_Size (ob:PPyObject):NativeInt; cdecl; external;
function PyBytes_DecodeEscape (s:PAnsiChar; len:NativeInt; errors:PAnsiChar; unicode:NativeInt; recode_encoding:PAnsiChar):PPyObject; cdecl; external;
function PyBytes_Repr (ob:PPyObject; smartquotes:integer):PPyObject; cdecl; external;
function PySys_GetObject (s:PAnsiChar):PPyObject; cdecl; external;
function PySys_SetObject (s:PAnsiChar;ob:PPyObject):integer; cdecl; external;
procedure PySys_SetPath (path:PAnsiChar); cdecl; external;
function PyTraceBack_Here (p:pointer):integer; cdecl; external;
function PyTraceBack_Print (ob1,ob2:PPyObject):integer; cdecl; external;
function PyTuple_GetItem (ob:PPyObject;i:NativeInt):PPyObject; cdecl; external;
function PyTuple_GetSlice (ob:PPyObject;i1,i2:NativeInt):PPyObject; cdecl; external;
function PyTuple_New (size:NativeInt):PPyObject; cdecl; external;
function PyTuple_SetItem (ob:PPyObject;key:NativeInt;value:PPyObject):integer; cdecl; external;
function PyTuple_Size (ob:PPyObject):NativeInt; cdecl; external;
function PyType_IsSubtype (a, b : PPyTypeObject):integer; cdecl; external;
function PyType_GenericAlloc (atype: PPyTypeObject; nitems:NativeInt) : PPyObject; cdecl; external;
function PyType_GenericNew (atype: PPyTypeObject; args, kwds : PPyObject) : PPyObject; cdecl; external;
function PyType_Ready (atype: PPyTypeObject) : integer; cdecl; external;
function PyUnicode_FromWideChar (const w:PWideChar; size:NativeInt):PPyObject; cdecl; external;
function PyUnicode_AsWideChar (unicode: PPyObject; w:PWideChar; size:NativeInt):integer; cdecl; external;
function PyUnicode_Decode (const s:PAnsiChar; size: NativeInt; const encoding : PAnsiChar; const errors: PAnsiChar):PPyObject; cdecl; external;
function PyUnicode_AsEncodedString (unicode:PPyObject; const encoding:PAnsiChar; const errors:PAnsiChar):PPyObject; cdecl; external;
function PyUnicode_FromOrdinal (ordinal:integer):PPyObject; cdecl; external;
function PyUnicode_GetSize (unicode:PPyObject):NativeInt; cdecl; external;
function PyWeakref_GetObject ( ref : PPyObject) : PPyObject; cdecl; external;
function PyWeakref_NewProxy ( ob, callback : PPyObject) : PPyObject; cdecl; external;
function PyWeakref_NewRef ( ob, callback : PPyObject) : PPyObject; cdecl; external;
function PyWrapper_New ( ob1, ob2 : PPyObject) : PPyObject; cdecl; external;
function PyBool_FromLong ( ok : Integer) : PPyObject; cdecl; external;
function PyThreadState_SetAsyncExc (t_id :LongInt; exc :PPyObject) : Integer; cdecl; external;
function Py_AtExit (proc: AtExitProc):integer; cdecl; external;
function Py_CompileStringFlags (s1,s2:PAnsiChar;i:integer;flags:PPyCompilerFlags):PPyObject; cdecl; external;
function Py_CompileStringExFlags (s1,s2:PAnsiChar;i:integer;flags:PPyCompilerFlags;optimize:integer):PPyObject; cdecl; external;
procedure Py_FatalError (s:PAnsiChar); cdecl; external;
function Py_FindMethod (md:PPyMethodDef;ob:PPyObject;key:PAnsiChar):PPyObject; cdecl; external;
function Py_FindMethodInChain (mc:PPyMethodChain;ob:PPyObject;key:PAnsiChar):PPyObject; cdecl; external;
function _PyObject_New (obt:PPyTypeObject;ob:PPyObject):PPyObject; cdecl; external;
function _PyString_Resize (var ob:PPyObject;i:NativeInt):integer; cdecl; external;
procedure Py_Finalize ; cdecl; external;
function PyErr_ExceptionMatches ( exc : PPyObject) : Integer; cdecl; external;
function PyErr_GivenExceptionMatches ( raised_exc, exc : PPyObject) : Integer; cdecl; external;
function PyEval_EvalCode ( co : PPyCodeObject; globals, locals : PPyObject) : PPyObject; cdecl; external;
function Py_GetVersion : PAnsiChar; cdecl; external;
function Py_GetCopyright : PAnsiChar; cdecl; external;
function Py_GetExecPrefix : PAnsiChar; cdecl; external;
function Py_GetPath : PAnsiChar; cdecl; external;
procedure Py_SetPythonHome (home : PWideChar); cdecl; external;
function Py_GetPythonHome : PWideChar; cdecl; external;
function Py_DecodeLocale (arg: PAnsiChar; size: pinteger): PWideChar; cdecl; external;
function Py_GetPrefix : PAnsiChar; cdecl; external;
function Py_GetProgramName : PAnsiChar; cdecl; external;
function PyParser_SimpleParseStringFlags ( str : PAnsiChar; start, flags : Integer) : PNode; cdecl; external;
procedure PyNode_Free ( n : PNode ); cdecl; external;
function PyErr_NewException ( name : PAnsiChar; base, dict : PPyObject ) : PPyObject; cdecl; external;
function Py_Malloc ( size : NativeInt ) : Pointer; external;
function PyMem_Malloc ( size : NativeInt ) : Pointer; external;
procedure Py_SetProgramName ( name: PWideChar); cdecl; external;
function Py_IsInitialized : integer; cdecl; external;
function Py_GetProgramFullPath : PAnsiChar; cdecl; external;
function Py_NewInterpreter : PPyThreadState; cdecl; external;
procedure Py_EndInterpreter ( tstate: PPyThreadState); cdecl; external;
procedure PyEval_AcquireLock ; cdecl; external;
procedure PyEval_ReleaseLock ; cdecl; external;
procedure PyEval_AcquireThread ( tstate: PPyThreadState); cdecl; external;
procedure PyEval_ReleaseThread ( tstate: PPyThreadState); cdecl; external;
function PyInterpreterState_New : PPyInterpreterState; cdecl; external;
procedure PyInterpreterState_Clear ( interp: PPyInterpreterState); cdecl; external;
procedure PyInterpreterState_Delete ( interp: PPyInterpreterState); cdecl; external;
function PyThreadState_New ( interp: PPyInterpreterState): PPyThreadState; cdecl; external;
procedure PyThreadState_Clear ( tstate: PPyThreadState); cdecl; external;
procedure PyThreadState_Delete ( tstate: PPyThreadState); cdecl; external;
function PyThreadState_Get : PPyThreadState; cdecl; external;
function PyThreadState_Swap ( tstate: PPyThreadState): PPyThreadState; cdecl; external;
procedure PyErr_SetInterrupt ; cdecl; external;
function PyGILState_Ensure () : PyGILstate_STATE; cdecl; external;
procedure PyGILState_Release (gilstate : PyGILState_STATE); cdecl; external;