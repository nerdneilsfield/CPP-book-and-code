# 第 2 章 调试、测试和文档

调试:
1. 程序逻辑问题(使用 GDB )
2. 内存滥用和泄露问题(使用 Valgrind)

文档:
1. 文档管理工具(Doxgen)
2. 程序每一步归档工具(CWEB, git)
    
## 2.1 使用调试器

> 永远使用调试器 

**堆栈帧**

启动 `main` 的时候系统会创建一个帧来存变量和函数信息，每调用一个新的函数就会有一个新的帧被
加入到堆上，函数结束执行以后，堆上的帧会被 **弹出**。

使用 `backtrace` 命令可以看到堆栈帧的列表。结果格式如下:

```shell
#地址后面是函数名、它的输入参数（恰好argv也 是一个十六进制地址），以及当前执行到的源代码行号。
#2 0x00404f9b in main (argc=1, argv=0x7fffffffe278) at addresses.c:227
```

### 2.1.1 调试的侦探工作

[stddev-bugged.c](https://raw.githubusercontent.com/fierlion/modern-c/master/debuglearn/bugged/stddev_bugged.c)

编译程序的时候需要添加 `-g` flag。
 
使用 `gdb stddev_bugged.out` 来启动程序.
 
在 `gdb` 的窗口中用 `r` 来运行程序。

在 `gdb` 的窗口中用 `list` 或简写 `l` 来查看代码。

如果需要在某个函数暂停，需要在那里放置一个断点 `break` 或简写 `b`, `break [num]` 或者 `break [func]` 都可以。

使用 `print` 或 `p` 来打印数据。 `p *data` 来打印数组， `p *data@10*` 打印数组的前十个元素。

使用 `bt` 来回退。查看堆栈里面有几帧。使用 `f [num]` 来回退到某帧。如果想回到第 0 帧，可以使用 `down` 来回退。

多线程的原因， `info threads(GDB)` 或者 `LLDB: thread list` 来获得线程的列表。 `*` 代表我们正在
那个线程调试。可以在 `.gdbinit` 里面关闭新线程的同志 `set print thread-events off`。

单步调试 `n`。单步执行等。 `snuc` 这四个命令中的一个。

使用 `LLDB: break list` 和 `GDB: info break` 来查看断点。

如果不在需要某个断点，可以使其处在不活跃状态, `GDB: dis 1` 或 `LLDB: break dis 1`。重新启动可以
使用 `GDB: enable 1` 或者 `LLDB: break enable 1` 来重使其有效。或者可以直接删除: `GDB: del 1` 或者 `LLDB: break dis 1`。

`r` 重新开始， `c` 继续运行程序。

`GDB: info local` 或 `LLDB: frame variable` 查看本地变量表。

`GDB: info args` 来查看输入的参数, `LLDB: frame variable`  包括了这一项。

`disp [variable]` 可以替代每次循环输入 `p [variable]`, 使用 `undisp [variable]` 来取消。



