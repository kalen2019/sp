# Assembly Language

組譯器 -- gas
來源 -- https://cs.lmu.edu/~ray/notes/gasexamples/

這些範例只能在 Linux 上跑

要連上 linux ，請先安裝 putty

* https://www.putty.org/

然後連上我的虛擬主機

網址: guest@172.104.100.202
密碼: csienqu

連上後請切到資料夾 ~/course/sp/code/c/03-asmVm/asm/linux

之後就可以執行範例，例如 hello.s

先切到 01-hello

```
$ gcc -c hello.s
$ ld hello.o -o hello
$ ./hello
Hello, world
```
