# c6 -- 將 C 語言編譯為堆疊機 vm 的目的檔格式

c6 是一個可自我編譯的極簡版 C 語言編譯器，由陳鍾誠修改自 c4 專案。

c4 專案的來源為 -- https://github.com/rswier/c4 。

陳鍾誠修改之處:

1. 加上中文註解
2. 讓函數更模組化，例如增加虛擬機函數 xvm_run(), 不受現在只有 4 個函數。
3. 讓虛擬機的 JMP, BZ, BNZ 等指令改為相對 PC 定址，而不是絕對定址，這樣可以有助於產生比較少修改紀錄的目的檔。
4. 加入 WRITE, MCPY 系統呼叫。
5. 可以指定 -o 輸出虛擬機目的檔。
6. 可以載入目的檔然後執行之。

## 建置執行

```
$ gcc -m32 c5.c -o c5

$ gcc -m32 -Wall c5.c -o c5
$ ./c5 test/sum.c
sum(10)=55
exit(0) cycle = 303

$ ./c5 c5.c test/sum.c
sum(10)=55
exit(0) cycle = 303
exit(0) cycle = 89784

$ ./c5 c5.c c5.c test/sum.c     
sum(10)=55
exit(0) cycle = 303
exit(0) cycle = 89784
exit(0) cycle = 18504595

$ ./c5 -s test/hello.c
1: #include <stdio.h>
2:
3: int main()
4: {
5:   printf("hello, world\n");
    ENT  0
    IMM  10158168
    PSH
    PRTF
    ADJ  1
6:   return 0;
    IMM  0
    LEV
7: }
    LEV

$ ./c5 -d test/hello.c
1> 0001:ENT  0
2> 0003:IMM  12648536
3> 0005:PSH
4> 0006:PRTF
hello, world
5> 0007:ADJ  1
6> 0009:IMM  0
7> 0011:LEV
8> 327678:PSH
9> 327679:EXIT
exit(0) cycle = 9
```

## 目前測試

```
PS D:\ccc\course\sp\code\c\xss\c6> make
gcc -D__VM__ -Wall -std=gnu99 -o vm c6.c
gcc -D__OBJDUMP__ -Wall -std=gnu99 -o objdump c6.c

PS D:\ccc\course\sp\code\c\xss\c6> ./cc -o test/hello.o test/hello.c
PS D:\ccc\course\sp\code\c\xss\c6> ./cc -o test/sum.o test/sum.c    
PS D:\ccc\course\sp\code\c\xss\c6> ./cc -o test/fib.o test/fib.c    
PS D:\ccc\course\sp\code\c\xss\c6> ./vm test/fib.o
f(7)=13
exit(8) cycle = 920
PS D:\ccc\course\sp\code\c\xss\c6> ./vm test/sum.o
sum(10)=55
exit(11) cycle = 302
PS D:\ccc\course\sp\code\c\xss\c6> ./vm test/hello.o
hello, world
exit(0) cycle = 9
```
