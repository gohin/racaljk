![giorgio-vasaris-500th-birthday](https://lh3.googleusercontent.com/fr-W9oiyvto1g26WVExOIv431QtvXSFoeeDGQSLricHMIdRjpWApHFcXPosVvAOmdJBmvaPIYyeQQdQ135_kJ9uRVaUEYKpd3oAk59a_ng=s660)

## Windows
* 用记事本打开`C:\Windows\System32\drivers\etc`中的hosts文件，把[hosts](https://github.com/racaljk/hosts_for_google_service/blob/master/hosts)中的代码复制到hosts文件中覆盖里面的内容，保存即可。
<br>注意：如果遇到无法保存，请右键hosts->属性->安全，然后选择你登陆的用户名，最后点击编辑，勾选"写入"即可。

## GNU/Linux 
* 以Ubuntu为例,终端输入`gksudo gedit /etc/hosts`,然后把[hosts](https://raw.githubusercontent.com/racaljk/hosts/master/hosts) 中的代码复制到hosts文件中覆盖里面的内容，保存即可。

## Hosts Tool
* `/hosts_tool_source` hosts自动配置工具,使用C++构建,GUI基于Qt,源码(hosts_tool/hosts_tool_source)遵守GPL协议发布
* `script_tool_for_windows.bat` windows环境的hosts自动配置脚本,由@SMoUNiVeS贡献
* `script_tool_for_linux.bash` linux环境的hosts自动配置脚本,由@lstoars贡献

## Others
* 如果Facebook， Twitter, Youtube等无法成功打开，请使用https方式访问，Youtube看视频的可能性不大，建议使用Firefox浏览器插件下载Youtube视频
* 如果项目中某些分类IP失效但未更新,请及时通过Issue反馈或者Pull Request你的有效IP List到本项目
* 谷歌IP不一定有用,如果上述hosts还是无法登陆谷歌请使用[GoGo Tester](https://raw.githubusercontent.com/azzvx/gogotester/2.3/GoGo%20Tester/bin/Release/GoGo%20Tester.exe)寻找IP作为最后解决方案

Copyright © 2015 racaljk, All Rights Reserved.
