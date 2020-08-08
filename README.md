# xbook2操作系统内核
xbook2操作系统内核是一个基于intel x86平台的32位处理器的系统内核，可运行在qemu，bochs，virtual box，vmware等虚拟机中。也可以在物理机上面运行（需要有系统支持的驱动才行）

宏内核的内容比较大，像文件系统，网络协议等内容都比较庞大，在内核中会占用很多空间。因此，xbook将这部分内容转移到用户态，以服务（service）的形式出现。这样的话，内核空间减小了，并且，在一定程度上也能保障内核的健壮。但是缺点就是和服务通信效率低下，这一直以来就是在微内核中老生常谈的事情，只有以后慢慢提升通信效率。  
  
除此之外，内核的划分也比较清晰，多任务（TASK 进程/线程），虚拟内存管理（VMM），进程间通信（IPC），以及驱动（DRIVERS），主要由这及部分组成。  
  
xbook2被设计成一个跨处理器平台的架构，有ARCH目录，可以在里面添加一个新的处理器平台。不过目前也是尽量将平台相关的分离到arch里面，并为完全分离出来，待后面多实现几个平台后，才能更好的让处理器平台和内核部分进行更优化的分离。  
  
内核结构示意图：
```
USER MODE:
+---------------------------------+
|shell | text edit | compiler     |
+---------------------------------+  
|netsrv | filesrv| guisrv| libOS  |
+---------------------------------+
KERNEL MODE: 
+---------------------------+
|task | ipc | vmm | drivers |
+---------------------------+
|            arch           | 
+---------------------------+
\                           /
+---------------------------+
|          hardware         |
+---------------------------+
```

系统功能列表：
```
多进程，内核多线程，用户多线程
虚拟内存管理，分页内存管理，物理内存管理
管道通信，共享内存，消息队列，信号量

IDE硬盘驱动，PS/2鼠标，键盘驱动，VBE视频驱动
RTL8139网卡驱动，UART串口驱动

FATFS文件系统，LWIP网络协议
PTHREAD线程库
```

开发环境准备（Windows/Linux）：  
```
整体思路：
1. 用git从仓库克隆源码或者直接下载源码。
2. 配置最基础的工具集：gcc, nasm, ld, dd, rm, objdump, objcopy。
3. 配置虚拟机：qemu（默认），bochs，virtual box， vmware任选其一。
5. 进入xbook2的根目录目录，打开终端或者命令行，输入命令make build先构建环境，然后make run编译运行。
```

## Windows环境搭建
```
1.下载我提取的工具包：http://www.book-os.org/tools/BuildTools-v5.rar
2.下载Mingw，官网下载或进QQ群下载：http://www.mingw.org/
3.解压工具包和Mingw后配置环境变量到系统环境变量Path里面
4.修改源码tools/fatfs/Makefile的Windows中gcc和头文件环境的路径为你Mingw的路径。
5.下载qemu最新版：https://www.qemu.org/ 下载后安装，配置安装目录环境变量到系统环境变量Path里面
    或者下载我提取的版本：http://www.book-os.org/tools/Qemu-i386.rar
    下载后配置解压目录环境变量到系统环境变量Path里面
！！！注意：BuilTools的环境配置要放在Mingw的前面
```

## Linux环境搭建
```
1.安装gcc, nasm: 
    Ubuntu/Kali Linux: apt-get install gcc nasm
    Red hot/Fedora/Centos: yum install gcc nasm
    
2.安装qemu虚拟机：
    Ubuntu/Kali Linux: apt-get install qemu*
    Red hot/Fedora/Centos: yum install qemu*
    
```



编译使用命令：
```
> make          # 只编译源码
> make build    # 构建环境
> make debuild  # 清理环境
> make run      # 编译并运行，默认使用qemu虚拟机运行
> make qemu     # 使用qemu虚拟机运行
> make qemudbg  # 使用qemu虚拟机进行调试
> make clean    # 清除编译产生的对象文件以及可执行文件
```

联系方式：
开源官网：www.book-os.org  
E-mail: book_os@163.com  
个人邮箱：2323168280@qq.com  
个人QQ: 2323168280  
开发交流QQ群：913813452  
