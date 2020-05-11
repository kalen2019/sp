
```
PS D:\ccc\course\sp\code\c\xss\c6> ./cc -d -o test/sum.o test/sum.c
obj_read(): oFile=test/sum.o objLen=623
obj_head(): codeLen=304 dataLen=12 relLen=16 stLen=203 symLen=16 objLen=623
obj_head(): hc[O]=72 hd[O]=376 hr[O]=388 ht[O]==404 hs[O]=607
obj_head:pc=10092916 code=10092688 entry=57
1> 0057:ENT  0
2> 0059:IMM  10092992
3> 0061:PSH
4> 0062:IMM  10
5> 0064:PSH
6> 0065:JSR  11075684
```

# 

mingw32 位元的 read 有問題

讀取 sum.o, fib.o 時，長度會有錯誤。

應該是 6xx 位元，讀到的卻只有 256 位元。

解決方式，沒有指定 binary, 改用 fread(..."rb") 就可以解決。

