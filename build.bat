@echo off
SET "VSCMD_ARG_HOST_ARCH=x64"
SET "VSCMD_ARG_TGT_ARCH=x64"
SET "DevEnvDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\"
SET "INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.26.28801\include;C:\Program Files (x86)\Windows Kits\NETFXSDK\4.8\include\um;C:\Program Files (x86)\Windows Kits\10\include\10.0.16299.0\ucrt;C:\Program Files (x86)\Windows Kits\10\include\10.0.16299.0\shared;C:\Program Files (x86)\Windows Kits\10\include\10.0.16299.0\um;C:\Program Files (x86)\Windows Kits\10\include\10.0.16299.0\winrt;C:\Program Files (x86)\Windows Kits\10\include\10.0.16299.0\cppwinrt"
SET "VCIDEInstallDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\"
SET "VCINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\"
SET "VCToolsInstallDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.26.28801\"
SET "VCToolsRedistDir=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Redist\MSVC\14.26.28720\"
SET "VCToolsVersion=14.26.28801"
SET "VisualStudioVersion=16.0"
SET "VS160COMNTOOLS=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\"
SET "VSCMD_VCVARSALL_INIT="
SET "VSCMD_VER=16.6.1"
SET "VSINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\"
SET "IFCPATH="
SET "LIB=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.26.28801\lib\x64;C:\Program Files (x86)\Windows Kits\NETFXSDK\4.8\lib\um\x64;C:\Program Files (x86)\Windows Kits\10\lib\10.0.16299.0\ucrt\x64;C:\Program Files (x86)\Windows Kits\10\lib\10.0.16299.0\um\x64;"
SET "LIBPATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.26.28801\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.26.28801\lib\x86\store\references;C:\Program Files (x86)\Windows Kits\10\UnionMetadata\10.0.16299.0;C:\Program Files (x86)\Windows Kits\10\References\10.0.16299.0;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;"
SET "Path=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\\Extensions\Microsoft\IntelliCode\CLI;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.26.28801\bin\HostX64\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\VCPackages;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TeamFoundation\Team Explorer;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\bin\Roslyn;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Team Tools\Performance Tools\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Team Tools\Performance Tools;C:\Program Files (x86)\Microsoft Visual Studio\Shared\Common\VSPerfCollectionTools\vs2019\\x64;C:\Program Files (x86)\Microsoft Visual Studio\Shared\Common\VSPerfCollectionTools\vs2019\;C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.8 Tools\x64\;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\FSharp\;C:\Program Files (x86)\Windows Kits\10\bin\10.0.16299.0\x64;C:\Program Files (x86)\Windows Kits\10\bin\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\\MSBuild\Current\Bin;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\;C:\Program Files\Alacritty\;C:\Python27\;C:\Python27\Scripts;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files\Git\cmd;C:\Program Files (x86)\Calibre2\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Android;C:\Program Files\Calibre2\;C:\TDM-GCC-64\bin;C:\Program Files\dotnet\;C:\Program Files\Microsoft SQL Server\130\Tools\Binn\;C:\Program Files\Microsoft SQL Server\Client SDK\ODBC\170\Tools\Binn\;C:\PATH;C:\Program Files (x86)\Certbot\bin;D:\Programs;C:\Program Files\Docker\Docker\resources\bin;C:\ProgramData\DockerDesktop\version-bin;C:\Program Files\Go\bin;C:\Program Files\nodejs\;C:\Program Files\JSONBuddy;C:\Users\lucas\.cargo\bin;C:\Python27;C:\Users\lucas\AppData\Local\Microsoft\WindowsApps;C:\Program Files\JetBrains\JetBrains Rider 2019.2\bin;C:\Users\lucas\Downloads\pypy2.7-v7.2.0-win32\pypy2.7-v7.2.0-win32;C:\Program Files\Java\jdk-11.0.6\bin\java;C:\Users\lucas\go\bin;C:\Users\lucas\.dotnet\tools;C:\PATH;C:\Program Files\LLVM\bin;D:\CLion 2020.1.2\bin;;C:\Program Files\Graphviz 2.44.1\bin;C:\Program Files\Graphviz 2.44.1\bin\dot.exe;C:\Users\lucas\AppData\Local\Programs\Python\Python37;C:\Users\lucas\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\JetBrains\PyCharm 2020.2.3\bin;;C:\PATH\Neovim\bin;C:\Program Files\GNU\units;C:\Windows\System32\WindowsPowerShell\v1.0;;C:\Users\lucas\AppData\Local\Programs\EmEditor;C:\Users\lucas\go\bin;C:\Users\lucas\AppData\Roaming\npm;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\Linux\bin\ConnectionManagerExe"

REM change O2 to Od when done
set CommonCompilerFlags=-MTd -Gm- -nologo -GR- -EHa- -Oi -O2 -WX -W4 ^
 -wd4201 -wd4505 -wd4100 -wd4189 -wd4028 -wd4146 ^
	-wd4996 ^
	-FC -Zi -GL -Gw ^
	/Zo
set CommonLinkerFlags=-incremental:no -opt:ref

cl  %CommonCompilerFlags% main.cpp