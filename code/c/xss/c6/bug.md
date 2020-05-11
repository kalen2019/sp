## 

hello, sum, 成功了

但 fib 出來前失敗了 (unknown instruction = 691480678)。

```
PS D:\ccc\course\sp\code\c\xss\c6> ./cc -o test/hello.o test/hello.c
obj_read(): oFile=test/hello.o objLen=294
obj_head(): hc[O]=72 hd[O]=120 hr[O]=136 ht[O]==144 hs[O]=286
obj_head:pc=10551444 code=10551440 entry=1 data=10551488
obj_head:code0=11862096 data0=12124248
hello, world
exit(0) cycle = 9


PS D:\ccc\course\sp\code\c\xss\c6> ./cc -o test/sum.o test/sum.c    
obj_read(): oFile=test/sum.o objLen=725
obj_head(): codeLen=352 dataLen=36 relLen=32 stLen=217 symLen=16 objLen=725
obj_head(): hc[O]=72 hd[O]=424 hr[O]=460 ht[O]==492 hs[O]=709
obj_head:pc=12190092 code=12189840 entry=63 data=12190192
obj_head:code0=13500496 data0=13762648
main:enter
sum:enter
sum(10)=55
exit(0) cycle = 311

PS D:\ccc\course\sp\code\c\xss\c6> ./cc -o test/fib.o test/fib.c   
obj_read(): oFile=test/fib.o objLen=600
obj_head(): codeLen=284 dataLen=12 relLen=32 stLen=184 symLen=16 objLen=600
obj_head(): hc[O]=72 hd[O]=356 hr[O]=368 ht[O]==400 hs[O]=584
obj_head:pc=6422892 code=6422672 entry=55 data=6422956
obj_head:code0=13566032 data0=13828184
f(7)=13
unknown instruction = 691480678! cycle = 918
```

## 

```
PS D:\ccc\course\sp\code\c\xss\c6> ./cc -o test/sum.o test/sum.c
obj_read(): oFile=test/sum.o objLen=725
obj_head(): codeLen=352 dataLen=36 relLen=32 stLen=217 symLen=16 objLen=725
obj_head(): hc[O]=72 hd[O]=424 hr[O]=460 ht[O]==492 hs[O]=709
obj_head:pc=7799180 code=7798928 entry=63 data=7799280
obj_head:code0=13107280 data0=13369432
obj_load():code=7798928 data=7799280 code0=13107280 data0=13369432
rel:offset=4
rel:old:*cp=13369432
rel:type=1
rel:new:*cp=7799280
rel:offset=66
rel:old:*cp=13369444
rel:type=1
rel:new:*cp=7799292
rel:offset=72
rel:old:*cp=13369456
rel:type=1
rel:new:*cp=7799304
rel:offset=78
rel:old:*cp=13107284
rel:type=0
rel:new:*cp=11780196 // 奇怪，這應該是 7799*** 才對啊，為何會是 117....
main:enter
```


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

看來是只要有 JSR 就掛掉了，應該是 relocate 沒做好！

# 

mingw32 位元的 read 有問題

讀取 sum.o, fib.o 時，長度會有錯誤。

應該是 6xx 位元，讀到的卻只有 256 位元。

解決方式，沒有指定 binary, 改用 fread(..."rb") 就可以解決。

