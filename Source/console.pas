{$mode objfpc}

{$assertions on}

{$ifdef darwin}
  {$ifdef CPUAARCH64}
    {$linklib ./PythonBridge/aarch64-darwin/libpython3.7m.a}
  {$else}
    {$linklib ./PythonBridge/x86_64-darwin/libpython3.7m.a}
  {$endif}
{$endif}
{$ifdef linux}
  {$linklib c}
  {$linklib m}
  {$linklib pthread}
  {$linklib util}
  {$linklib dl}
  {$linklib ./PythonBridge/x86_64-linuxs/libpython3.7m.a}
{$endif}

program Main;
uses
  Classes, Python3Core, PythonBridge, SysUtils;

type
  TForm = class
    procedure GotPythonData(str: UnicodeString); 
  end;

procedure TForm.GotPythonData(str: UnicodeString); 
begin
  write(str);
end;

function PyVERSION(Self, Args : PPyObject): PPyObject; cdecl;
begin
  result:= PyString_FromString('0.0.1b');
end;

function PyAZIMUTH(Self, Args : PPyObject): PPyObject; cdecl;
var
  fl: single;
  ret: integer;
begin
  ret := PyArg_ParseTuple(Args, 'f:azimuth', @fl);
  result := PyBool_FromLong(ret);
  if (ret = 0) then exit();
  writeln('Azimuth set to ' + floattostr(fl));
end;

function PyREPEATSTRING(Self, Args : PPyObject): PPyObject; cdecl;
var
  s: PChar;
  ret, n, i: integer;
begin
  ret := PyArg_ParseTuple(Args, 'is:repeatstring', @i, @s);
  result := PyBool_FromLong(ret);
  if (ret = 0) then exit();
  if i < 1 then exit;
  for n := 1 to i do
    writeln(string(s));
end;

var
  methods: array[0..2] of TPythonBridgeMethod = (
    (name: 'azimuth'; callback: @PyAZIMUTH; help: 'azimuth(f): set azimuth of camera'),
    (name: 'repeatstring'; callback: @PyREPEATSTRING; help: 'repeatstring(i, s): print the string `s` for `i` times'),
    (name: 'version'; callback: @PyVERSION; help: 'doc string for function `version`')
   );

var
  atest_file: ansistring = 'import gl'+LF+
                          'print("a", "b\nc")'+LF+
                          'print(" a", "b")'+LF+
                                  #0;

  test_file: ansistring = 'import gl'+LF+
                          'import sys'+LF+
                          'print(gl.version())'+LF+
                          'print(gl.azimuth(42.0))'+LF+
                          'print(gl.repeatstring(3," -> repeatString"))'+LF+
                          'print(sys.path)'+LF+
                          'print("40+2 = ", 40+2)'+LF+
                          #0;

var
  test_help: ansistring = 'import gl'+LF+
                          'print(gl.__doc__)'+LF+
                          'for key in dir( gl ):'+LF+
                          '  if not key.startswith(''_''):'+LF+
                          '    x = getattr( gl, key ).__doc__'+LF+
                          '    print(key+'' (built-in function): '')'+LF+
                          '    print(x)'+LF+
                          #0;

var
  form: TForm;
begin
  form := TForm.Create;
  {$ifdef windows}
  PythonLoadAndInitialize(ExtractFileDir(ParamStr(0)) + pathdelim + 'WindowsResources', @form.GotPythonData);
  {$else}
  PythonLoadAndInitialize(ExtractFileDir(ParamStr(0)) + pathdelim + 'UnixResources', @form.GotPythonData);
  {$endif}
  PythonAddModule('gl', @methods, length(methods));
  PyRun_SimpleString(PAnsiChar(atest_file));
  PyRun_SimpleString(PAnsiChar(test_help));
end.
