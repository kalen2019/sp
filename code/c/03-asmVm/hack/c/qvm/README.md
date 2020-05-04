# qvm.c

```
D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>gcc hack2x86.c -o hack2x86
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> ./run Add

D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>hack2x86 Add
@2
D=A
@3
D=D+A
@0
M=D

D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>gcc main.c Add.s -o Add

D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>Add
A=0 D=5
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> ./run Max

D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>hack2x86 Max
@8
D=A
@0
M=D
@5
D=A
@1
M=D
@0
D=M
@1
@18
D;JGT
@1
D=M
@20
0;JMP
@0
D=M
@2
M=D

D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>gcc main.c Max.s -o Max

D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>Max
eax=18 ebx=2686979 ecx=5 edx=3
A=2 D=8
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> ./run sum

D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>hack2x86 sum
@10
D=A
@0
M=D
@16
M=1
@17
M=0
@16
D=M
@0
D=D-M
@22
D;JGT
@16
D=M
@17
M=D+M
@16
M=M+1
@8
0;JMP
@17
D=M
@1
M=D

D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>gcc main.c sum.s -o sum

D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm>sum
eax=8 ebx=3538944 ecx=10 edx=1
eax=8 ebx=3538944 ecx=4194314 edx=2
eax=8 ebx=3538944 ecx=4194314 edx=3
eax=8 ebx=3538944 ecx=4194314 edx=4
eax=8 ebx=3538944 ecx=4194314 edx=5
eax=8 ebx=3538944 ecx=4194314 edx=6
eax=8 ebx=3538944 ecx=4194314 edx=7
eax=8 ebx=3538944 ecx=4194314 edx=8
eax=8 ebx=3538944 ecx=4194314 edx=9
eax=8 ebx=3538944 ecx=4194314 edx=10
eax=22 ebx=3538945 ecx=4194314 edx=1
A=1 D=55
```

## 測試跳轉

```
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> gcc main.c hcodeMy.s -o hcodeMy
PS D:\ccc\course\sp\code\c\03-asmVm\hack\c\qvm> ./hcodeMy
eax=1 ebx=1 ecx=0 edx=0
eax=1 ebx=2 ecx=4199342 edx=0
eax=1 ebx=3 ecx=4199342 edx=0
eax=1 ebx=4 ecx=4199342 edx=0
```

