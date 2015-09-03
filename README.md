![](http://gb.cri.cn/mmsource/images/2015/04/07/nk20150401016.jpg)
**纪念中国人民抗日战争暨世界反法西斯战争胜利70周年！**

Commemoration of 70th Anniversary of Victory of Chinese People's Resistance against **Japanese Aggression** and World Anti-Fascist War

### Windows
* 用记事本打开`C:\Windows\System32\drivers\etc`中的hosts文件，把[hosts](https://raw.githubusercontent.com/racaljk/hosts/master/hosts)中的代码复制到hosts文件中覆盖里面的内容，保存即可。
<br>注意：如果遇到无法保存，请右键hosts->属性->安全，然后选择你登陆的用户名，最后点击编辑，勾选"写入"即可。

### GNU/Linux 
* 以Ubuntu为例,终端输入`gksudo gedit /etc/hosts`,然后把[hosts](https://raw.githubusercontent.com/racaljk/hosts/master/hosts) 中的代码复制到hosts文件中覆盖里面的内容，保存即可。

### Others
* 更多细节请访问[hosts wiki](https://github.com/racaljk/hosts/wiki)
* 如果Facebook， Twitter, Google等无法成功打开，请确认是否为https方式访问，用hosts看Youtube视频基本不可能(每个视频都有独立的分域名)，需要看Youtube的朋友请寻找其他途径。
* 如果项目中某些分类IP失效但未更新,请及时通过Issue反馈或者Pull Request你的有效IP List到本项目
* 谷歌IP不一定有用,如果上述hosts还是无法登陆谷歌请使用[GoGo Tester](https://raw.githubusercontent.com/azzvx/gogotester/2.3/GoGo%20Tester/bin/Release/GoGo%20Tester.exe)寻找IP作为最后解决方案

Copyright © 2015 racaljk, All Rights Reserved.
