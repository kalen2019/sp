# qvm.c

目前 Add, Max 都對了，但是 sum 當掉。

```
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> gcc main.c Add.s -o Add
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> ./Add
A=0 D=5
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> gcc main.c Max.s -o Max
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> ./Max
A=2 D=5
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> gcc main.c sum.s -o vm 
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> gcc main.c sum.s -o sum
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> ./sum
// 當掉
```


```
   @8
   D=A
   @R0
   M=D
   @5
   D=A
   @R1
   M=D
// Computes R2 = max(R0, R1)  (R0,R1,R2 refer to  RAM[0],RAM[1],RAM[2])
   @R0
   D=M              // D = first number
   @R1
   D=D-M            // D = first number - second number
   @OUTPUT_FIRST
   D;JGT            // if D>0 (first is greater) goto output_first
   @R1
   D=M              // D = second number
   @OUTPUT_D
   0;JMP            // goto output_d
(OUTPUT_FIRST)
   @R0             
   D=M              // D = first number
(OUTPUT_D)
   @R2
   M=D              // M[2] = D (greatest number)
// (INFINITE_LOOP)
//    @INFINITE_LOOP
//    0;JMP            // infinite loop

```


Run: 

```
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c> ./vm ../test/Max.bin
PC=0000 I=0008 A=0008 D=0000 m[A]=0000
PC=0001 I=EC10 A=0008 D=0008 m[A]=0000 a=0 c=30 d=2 j=0
PC=0002 I=0000 A=0000 D=0008 m[A]=0000
PC=0003 I=E308 A=0000 D=0008 m[A]=0008 a=0 c=0C d=1 j=0
PC=0004 I=0005 A=0005 D=0008 m[A]=0000
PC=0005 I=EC10 A=0005 D=0005 m[A]=0000 a=0 c=30 d=2 j=0
PC=0006 I=0001 A=0001 D=0005 m[A]=0000
PC=0007 I=E308 A=0001 D=0005 m[A]=0005 a=0 c=0C d=1 j=0
PC=0008 I=0000 A=0000 D=0005 m[A]=0008
PC=0009 I=FC10 A=0000 D=0008 m[A]=0008 a=1 c=30 d=2 j=0
PC=000A I=0001 A=0001 D=0008 m[A]=0005
PC=000B I=F4D0 A=0001 D=0003 m[A]=0005 a=1 c=13 d=2 j=0
PC=000C I=0012 A=0012 D=0003 m[A]=0000
PC=000D I=E301 A=0012 D=0003 m[A]=0000 a=0 c=0C d=0 j=1
PC=0012 I=0000 A=0000 D=0003 m[A]=0008
PC=0013 I=FC10 A=0000 D=0008 m[A]=0008 a=1 c=30 d=2 j=0
PC=0014 I=0002 A=0002 D=0008 m[A]=0000
PC=0015 I=E308 A=0002 D=0008 m[A]=0008 a=0 c=0C d=1 j=0
exit program !
```