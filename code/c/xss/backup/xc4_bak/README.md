# xcc -- 將 C 語言編譯為堆疊機 xvm 的 elf 格式

xcc 修改自 jserv 的 amacc 專案！

* https://github.com/jserv/amacc

amacc 專案則是擴充自 c4 專案。

* https://github.com/rswier/c4

## 建置執行

```
PS D:\ccc\course\sp\code\c\xss\xc4> make xcc
gcc -m32 -Wall -std=c99 -O0 xcc.c xvm.c -o xcc

PS D:\ccc\course\sp\code\c\xss\xc4> ./xcc test/sum.c
sum(10)=55
exit(0) cycle = 303

PS D:\ccc\course\sp\code\c\xss\xc4> ./xcc c4.c test/sum.c
sum(10)=55
exit(0) cycle = 303
exit(0) cycle = 89668
```
