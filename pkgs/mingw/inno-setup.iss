#define MyAppName "solo-oss-demo"
#define MyAppVersion "1.0"
#define MyAppPublisher "SOlO Tech."
#define MyAppURL "http://www.luoxiangyong.cn/"
#define MyAppExeName "solo-navi-viewer.exe"

[Setup]
AppName={#MyAppName}
AppVersion={#MyAppVersion}
WizardStyle=modern
DefaultDirName={autopf}\{#MyAppName}
DefaultGroupName={#MyAppName}
UninstallDisplayIcon=.\contents\bin\{#MyAppName}.ico
OutputDir=..
OutputBaseFilename={#MyAppName}-{#MyAppVersion}-x86_64-inno
SetupIconFile=.\contents\bin\{#MyAppName}.ico
Compression=lzma2
SolidCompression=yes
UserInfoPage=yes
;OutputDir=userdocs:Inno Setup Examples Output
; "ArchitecturesAllowed=x64" specifies that Setup cannot run on
; anything but x64.
ArchitecturesAllowed=x64
; "ArchitecturesInstallIn64BitMode=x64" requests that the install be
; done in "64-bit mode" on x64, meaning it should use the native
; 64-bit Program Files directory and the 64-bit view of the registry.
ArchitecturesInstallIn64BitMode=x64

AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}

[Files]
Source: ".\contents\bin\*.exe"; DestDir: "{app}\bin"
Source: ".\contents\bin\*.ico"; DestDir: "{app}\bin"
Source: ".\contents\bin\*.dll"; DestDir: "{app}\bin"
;Source: ".\contents\bin\solo-hello.exe"; DestDir: "{app}\bin"
;Source: ".\contents\bin\*.dll"; DestDir: "{app}\bin"
Source: ".\contents\share\pixmaps\*"; DestDir: "{app}\share\pixmaps"
Source: ".\contents\share\doc\solo-oss-demo\*"; DestDir: "{app}\share\doc\solo-oss-demo"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
;[Icons]
;Name: "{group}\solo-oss-demo"; Filename: "{app}\bin\solo-oss-demo.exe"