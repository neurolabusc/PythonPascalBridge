unit gui_main;

{$mode objfpc}{$H+}
{$IFDEF Darwin}
  {$modeswitch objectivec1}
{$ENDIF}
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

interface

uses
  {$IFDEF Darwin} CocoaAll, {$ENDIF}
  LCLType, Python3Core, PythonBridge,
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls;

type

  { TGLForm1 }

  TGLForm1 = class(TForm)
    Edit1: TEdit;
    Label1: TLabel;
    ScriptMemo: TMemo;
    Panel1: TPanel;
    procedure Edit1KeyPress(Sender: TObject; var Key: char);
    procedure FormCreate(Sender: TObject);
    procedure GotPythonData(str: UnicodeString);
    procedure Printf(s: string);

  private

  public

  end;

var
  GLForm1: TGLForm1;

implementation

{$R *.lfm}

function PyAZIMUTH(Self, Args : PPyObject): PPyObject; cdecl;
var
  fl: single;
  ret: integer;
begin
  ret := PyArg_ParseTuple(Args, 'f:azimuth', @fl);
  result := PyBool_FromLong(ret);
  if (ret = 0) then exit();
  GLForm1.printf('Azimuth set to ' + floattostr(fl));
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
    GLForm1.printf(string(s));
end;

function PyVERSION(Self, Args : PPyObject): PPyObject; cdecl;
begin
  result:= PyString_FromString('0.0.1b');
end;

{$IFDEF Darwin}
function ResourceDir (): string;
begin
	result := NSBundle.mainBundle.resourcePath.UTF8String;
end;
{$ENDIF}
{$IFDEF Windows}
function ResourceDir (): string;
begin
  result := ExtractFilePath(Paramstr(0))+'WindowsResources';
end;
{$ENDIF}

{$IFDEF Linux}
function ResourceDir (): string;
begin
  result := ExtractFilePath(Paramstr(0))+'UnixResources';
end;
{$ENDIF}

var
  methods: array[0..2] of TPythonBridgeMethod = (
	(name: 'azimuth'; callback: @PyAZIMUTH; help: 'azimuth(f): set azimuth of camera'),
    (name: 'repeatstring'; callback: @PyREPEATSTRING; help: 'repeatstring(i, s): print the string `s` for `i` times'),
  	(name: 'version'; callback: @PyVERSION; help: 'version(): doc string for function `version`')
                                                );

var
  test_file: ansistring = 'import gl'+LF+
                          'import sys'+LF+
                          'print("gl Version "+gl.version())'+LF+
                          'gl.azimuth(2)'+LF+
                          'gl.repeatstring(3," repeat after me...")'+LF+
                          'print(sys.path)'+LF+
                          'print("a", "b\nc")'+LF+
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
  gPythonData: UnicodeString = '';
procedure TGLForm1.GotPythonData(str: UnicodeString);
var
  i: integer;
begin
  if length(str) < 1 then exit;
  for i := 1 to length(str) do begin
    if str[i] = LF then begin
      ScriptMemo.lines.add(gPythonData);
      gPythonData := '';
    end else
      gPythonData += str[i];
  end;
end;

procedure TGLForm1.Printf(s: string);
begin
  ScriptMemo.lines.add(s);
  {$IFDEF UNIX}
  writeln(s);
  {$ENDIF}
end;

procedure TGLForm1.Edit1KeyPress(Sender: TObject; var Key: char);
begin
  if ord(Key) <> VK_RETURN then exit;
  ScriptMemo.lines.add('>>> ' + Edit1.Text);
  PyRun_SimpleString(PAnsiChar(Edit1.Text));
  Edit1.Text := '';
end;

procedure TGLForm1.FormCreate(Sender: TObject);
begin
  printf(ResourceDir());
  PythonLoadAndInitialize(ResourceDir(), @GLForm1.GotPythonData);
  PythonAddModule('gl', @methods, length(methods));
  PyRun_SimpleString(PAnsiChar(test_file));
  PyRun_SimpleString(PAnsiChar(test_help));
end;

end.

