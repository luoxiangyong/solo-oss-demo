﻿; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "solo-oss-demo"
!define PRODUCT_VERSION "1.0"
!define PRODUCT_PUBLISHER "SOLO Tech."
!define PRODUCT_WEB_SITE "http://www.luoxiangyong.cn"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\${PRODUCT_NAME}\${PRODUCT_NAME}.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
;!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
!define MUI_ICON ".\contents\bin\${PRODUCT_NAME}.ico"
!define MUI_UNICON ".\contents\bin\${PRODUCT_NAME}.ico"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
;!insertmacro MUI_PAGE_LICENSE "..\..\..\..\path\to\licence\YourSoftwareLicence.txt"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_RUN "$INSTDIR\bin\solo-navi-viewer.exe"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "..\${PRODUCT_NAME}-${PRODUCT_VERSION}-x86_64-nsis.exe"
InstallDir "$PROGRAMFILES64\solo-oss-demo"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  SetOutPath "$INSTDIR\bin"
  SetOverwrite try
  ;File ".\contents\bin\libbz2-1.dll"
  ;File ".\contents\bin\libfreetype-6.dll"
  ;File ".\contents\bin\libgcc_s_seh-1.dll"
  ;File ".\contents\bin\libglib-2.0-0.dll"
  ;File ".\contents\bin\libgraphite2.dll"
  ;File ".\contents\bin\libharfbuzz-0.dll"
  ;File ".\contents\bin\libiconv-2.dll"
  ;File ".\contents\bin\libicudt62.dll"
  ;File ".\contents\bin\libicuin62.dll"
  ;File ".\contents\bin\libicuuc62.dll"
  ;File ".\contents\bin\libintl-8.dll"
  ;File ".\contents\bin\libpcre-1.dll"
  ;File ".\contents\bin\libpcre2-16-0.dll"
  ;File ".\contents\bin\libpng16-16.dll"
  ;File ".\contents\bin\libsolo-basic-0.dll"
  ;File ".\contents\bin\libstdc++-6.dll"
  ;File ".\contents\bin\libwinpthread-1.dll"
  ;File ".\contents\bin\Qt5Core.dll"
  ;File ".\contents\bin\Qt5Gui.dll"
  ;File ".\contents\bin\Qt5Widgets.dll"
  File ".\contents\bin\*.dll"
  File ".\contents\bin\solo-hello.exe"
  File ".\contents\bin\solo-navi-viewer.exe"
  CreateDirectory "$SMPROGRAMS\solo-oss-demo"
  CreateShortCut "$SMPROGRAMS\solo-oss-demo\solo-oss-demo.lnk" "$INSTDIR\bin\solo-navi-viewer.exe"
  CreateShortCut "$DESKTOP\solo-oss-demo.lnk" "$INSTDIR\bin\solo-navi-viewer.exe"
  File ".\contents\bin\solo-oss-demo.ico"
  File ".\contents\bin\zlib1.dll"
  SetOutPath "$INSTDIR\lib"
  File ".\contents\lib\libsolo-basic.a"
  File ".\contents\lib\libsolo-basic.dll.a"
  File ".\contents\lib\libsolo-basic.la"
  SetOutPath "$INSTDIR\share\applications"
  File ".\contents\share\applications\solo-oss-demo.desktop"
  SetOutPath "$INSTDIR\share\doc\solo-oss-demo"
  File ".\contents\share\doc\solo-oss-demo\README"
  SetOutPath "$INSTDIR\share\pixmaps"
  File ".\contents\share\pixmaps\solo-oss-demo.png"

  CreateDirectory "$SMPROGRAMS\solo-oss-demo\bin\platforms"
  SetOutPath "$INSTDIR\bin\platforms"
  File ".\contents\bin\platforms\*.dll"
SectionEnd

Section -AdditionalIcons
  SetOutPath $INSTDIR
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\solo-oss-demo\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\solo-oss-demo\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\${PRODUCT_NAME}.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\AppMainExe.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd


Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name) 已成功地从你的计算机移除。"
FunctionEnd

Function un.onInit
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "你确实要完全移除 $(^Name) ，其及所有的组件？" IDYES +2
  Abort
FunctionEnd

Section Uninstall
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\share\pixmaps\solo-oss-demo.png"
  Delete "$INSTDIR\share\doc\solo-oss-demo\README"
  Delete "$INSTDIR\share\applications\solo-oss-demo.desktop"
  Delete "$INSTDIR\lib\*"
  ;Delete "$INSTDIR\lib\libsolo-basic.la"
  ;Delete "$INSTDIR\lib\libsolo-basic.dll.a"
  ;Delete "$INSTDIR\lib\libsolo-basic.a"
  ;Delete "$INSTDIR\bin\zlib1.dll"
  ;Delete "$INSTDIR\bin\solo-oss-demo.ico"
  ;Delete "$INSTDIR\bin\solo-navi-viewer.exe"
  ;Delete "$INSTDIR\bin\solo-hello.exe"
  Delete "$INSTDIR\bin\*.exe"
  Delete "$INSTDIR\bin\*.dll"
  Delete "$INSTDIR\bin\*.ico"
  ;Delete "$INSTDIR\bin\Qt5Widgets.dll"
  ;Delete "$INSTDIR\bin\Qt5Gui.dll"
  ;Delete "$INSTDIR\bin\Qt5Core.dll"
  ;Delete "$INSTDIR\bin\libwinpthread-1.dll"
  ;Delete "$INSTDIR\bin\libstdc++-6.dll"
  ;Delete "$INSTDIR\bin\libsolo-basic-0.dll"
  ;Delete "$INSTDIR\bin\libpng16-16.dll"
  ;Delete "$INSTDIR\bin\libpcre2-16-0.dll"
  ;Delete "$INSTDIR\bin\libpcre-1.dll"
  ;Delete "$INSTDIR\bin\libintl-8.dll"
  ;Delete "$INSTDIR\bin\libicuuc62.dll"
  ;Delete "$INSTDIR\bin\libicuin62.dll"
  ;Delete "$INSTDIR\bin\libicudt62.dll"
  ;Delete "$INSTDIR\bin\libiconv-2.dll"
  ;Delete "$INSTDIR\bin\libharfbuzz-0.dll"
  ;Delete "$INSTDIR\bin\libgraphite2.dll"
  ;Delete "$INSTDIR\bin\libglib-2.0-0.dll"
  ;Delete "$INSTDIR\bin\libgcc_s_seh-1.dll"
  ;Delete "$INSTDIR\bin\libfreetype-6.dll"
  ;Delete "$INSTDIR\bin\libbz2-1.dll"
  Delete "$INSTDIR\bin\platforms\*"

  Delete "$SMPROGRAMS\solo-oss-demo\Uninstall.lnk"
  Delete "$SMPROGRAMS\solo-oss-demo\Website.lnk"
  Delete "$DESKTOP\solo-oss-demo.lnk"
  Delete "$SMPROGRAMS\solo-oss-demo\solo-oss-demo.lnk"

  RMDir "$SMPROGRAMS\solo-oss-demo"
  RMDir "$INSTDIR\share\pixmaps"
  RMDir "$INSTDIR\share\doc\solo-oss-demo"
  RMDir "$INSTDIR\share\applications"
  RMDir "$INSTDIR\share\doc"
  RMDir "$INSTDIR\bin\platforms"  

  RMDir "$INSTDIR\share"
  RMDir "$INSTDIR\lib"
  RMDir "$INSTDIR\bin"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd