@echo off
cls
%1 %2
ver|find " 5.">nul &&goto :st
echo 正在进行 UAC 提权...
mshta vbscript:createobject("shell.application").shellexecute("%~s0","goto :st","","runas",1)(window.close)&goto :eof
:st

copy "%~0" "%windir%\system32\"
cls
::@echo off
@REM HostsGet Version0.4
cd /d %~dp0

set LogFilePath=%temp%\HostsGeter_log.txt
set DLScriptPath=%temp%\downloadhosts.vbs
set DLPath=%windir%\system32\drivers\etc\hosts_downloaded
set BackupDir=%windir%\system32\drivers\etc
set HostsPath=%windir%\system32\drivers\etc\hosts

set LogToFile=^>^>%LogFilePath% 2^>^&1
set EchoAndLog=call :echoandlog
echo. %LogToFile%
echo ==========[%date% %time%]========== %LogToFile%
echo 日志文件：
echo %LogFilePath%
echo.

echo iLocal=LCase("%DLPath%") > %DLScriptPath% ||(
 call :error downloadhosts.vbs 文件创建/写入失败.
)
echo iRemote=LCase("https://raw.githubusercontent.com/racaljk/hosts/master/hosts") >> %DLScriptPath%
echo Set xPost=createObject("Microsoft.XMLHTTP") 'Set Post = CreateObject("Msxml2.XMLHTTP") >> %DLScriptPath%
echo xPost.Open "GET",iRemote,0 >> %DLScriptPath%
echo xPost.Send() >> %DLScriptPath%
echo set sGet=createObject("ADODB.Stream") >> %DLScriptPath%
echo sGet.Mode=3 >> %DLScriptPath%
echo sGet.Type=1 >> %DLScriptPath%
echo sGet.Open() >> %DLScriptPath%
echo sGet.Write xPost.ResponseBody >> %DLScriptPath%
echo sGet.SaveToFile iLocal,2 >> %DLScriptPath%

%EchoAndLog% 开始从 GitHub 中下载 hosts 文件...
if exist %DLPath% del %DLPath% /s /q %LogToFile%
%DLScriptPath% || call :error hosts 文件下载失败.
del %DLScriptPath% /s /q %LogToFile%
if not exist %DLPath% call :error hosts 文件下载失败.
%EchoAndLog% 下载完成.
echo.

if exist %HostsPath% (
    call :backuphosts
) else (
    %EchoAndLog% （原 hosts 文件不存在，跳过备份）
)
%EchoAndLog% 正在替换 hosts 文件...
move %DLPath% %HostsPath% %LogToFile% || call :error hosts 文件替换失败.
%EchoAndLog% hosts 文件已替换.
echo.

%EchoAndLog% 正在刷新系统 DNS 缓存...
ipconfig /flushdns %LogToFile% || call :error DNS 缓存刷新失败.
%EchoAndLog% DNS 缓存已刷新.
echo.
%EchoAndLog% 【操作全部完成！】
echo.

echo 按任意键访问 google.com.hk 进行测试，如取消，请直接关闭本窗口
pause >nul
start https://www.google.com.hk
echo 已经帮你访问 google.com.hk 如可以访问则替换成功.
echo.
goto :end

:backuphosts
%EchoAndLog% 正在备份原 hosts 文件...
set "bakfilename=hosts_%date%_%time:~0,8%.bak"
set bakfilename=%bakfilename:/=-%
set bakfilename=%bakfilename:\=-%
set bakfilename=%bakfilename::=-%
set bakfilename=%bakfilename: =_%
copy %HostsPath% %BackupDir%\%bakfilename% %LogToFile% || call :error hosts 文件备份失败.
%EchoAndLog% 原 hosts 文件已备份到 %BackupDir%\%bakfilename%.
echo.
goto :eof

:error
echo ======================
%EchoAndLog% 错误：%*
start %LogFilePath%
echo 已打开日志文件
goto :end

:echoandlog
echo %*
echo %* %LogToFile%
goto :eof

:end
echo 按任意键关闭
pause >nul
exit
