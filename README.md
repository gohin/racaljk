![](http://gb.cri.cn/mmsource/images/2015/04/07/nk20150401016.jpg)
**纪念中国人民抗日战争暨世界反法西斯战争胜利70周年！**

Commemoration of 70th Anniversary of Victory of Chinese People's Resistance against **Japanese Aggression** and World Anti-Fascist War

### Windows
* 用文本编辑器(如Notepad++|记事本)打开`C:\Windows\System32\drivers\etc`中的hosts文件，  
把 -> [hosts](https://raw.githubusercontent.com/racaljk/hosts/master/hosts) <- 全部内容复制到hosts文件中，保存后按下述方法令其生效。
<br>**注意：如果遇到无法保存，请右键hosts->属性->安全，然后选择你登陆的用户名，最后点击编辑，勾选"写入"即可。**

### GNU/Linux
* Linux 系统通用（推荐）：  
使用wget或curl命令，以wget为例：  
终端输入`sudo rename /etc/hosts /etc/hosts.bak`
之后输入
`sudo wget -q https://raw.githubusercontent.com/racaljk/hosts/master/hosts -O /etc/hosts`
按下述方法令其生效  

* Ubuntu：  
打开终端(快捷键Ctrl + Alt + T), 在终端输入  
`sudo rename /etc/hosts /etc/hosts.bak`备份原hosts文件之后输入
`gksudo gedit /etc/hosts`
把 -> [hosts](https://raw.githubusercontent.com/racaljk/hosts/master/hosts) <- 复制到文本编辑器中，保存后按下述方法令其生效。

* Gnome 桌面系统：  
终端输入`sudo rename /etc/hosts /etc/hosts.bak`之后输入  
`gnomesu gedit /etc/hosts`把 -> [hosts](https://raw.githubusercontent.com/racaljk/hosts/master/hosts) <- 复制到文本编辑器中，保存后按下述方法令其生效。

* KDE 桌面系统：  
终端输入`sudo rename /etc/hosts /etc/hosts.bak`之后输入  
`kdesu kwrite /etc/hosts`把 -> [hosts](https://raw.githubusercontent.com/racaljk/hosts/master/hosts) <- 复制到文本编辑器中，保存后按下述方法令其生效。

### 修改hosts后生效的方法
* Windows  
开始 -> 运行 -> 输入cmd -> 在CMD窗口输入`ipconfig /flushdns`
  
* Linux  
开启终端(快捷键为Ctrl + Alt + T)，输入`sudo rcnscd restart`
  
* Mac OS X  
终端输入`sudo killall -HUP mDNSResponder`
  
* Android  
开启飞行模式 -> 关闭飞行模式  
  
* 通用方法  
拔网线(断网) -> 插网线(重新连接网络)  
  
### Others
* 更多细节请访问[hosts wiki](https://github.com/racaljk/hosts/wiki)
* 如果Facebook， Twitter, Google等无法成功打开，请确认是否为https方式访问，用hosts看Youtube视频基本无法实现，需要看Youtube的朋友请寻找其他途径。
* 如果项目中某些分类IP失效但未更新,请及时通过Issue反馈或者Pull Request你的有效IP List到本项目
* 如果上述hosts还是无法登陆谷歌请使用[GoGo Tester](https://raw.githubusercontent.com/azzvx/gogotester/2.3/GoGo%20Tester/bin/Release/GoGo%20Tester.exe)寻找IP作为最后解决方案

Copyright © 2015 racaljk, All Rights Reserved.
