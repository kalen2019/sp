# xv6 原始碼

## 檔案列表

# basic headers 
01 types.h
01 param.h
02 memlayout.h
02 defs.h
04 x86.h
06 asm.h
07 mmu.h
09 elf.h

# entering xv6
10 entry.S
11 entryother.S
12 main.c

# locks 
14 spinlock.h
14 spinlock.c


# processes
16 vm.c
20 proc.h
21 proc.c
27 swtch.S
27 kalloc.c

# system calls
29 traps.h
29 vectors.pl
30 trapasm.S
30 trap.c
32 syscall.h
32 syscall.c
34 sysproc.c

# file system
35 buf.h
35 fcntl.h
36 stat.h
36 fs.h
37 file.h
38 ide.c
40 bio.c
41 log.c
44 fs.c
52 file.c 78 sh.c
54 sysfile.c
59 exec.c

# pipes
60 pipe.c


# processes 52 file.c 78 sh.c
16 vm.c 54 sysfile.c
20 proc.h 59 exec.c # bootloa
# locks 38 ide.c # user−level
14 spinlock.h 40 bio.c 77 initcode.S
14 spinlock.c 41 log.c 77 usys.S
44 fs.c 78 init.c
# processes 52 file.c 78 sh.c
16 vm.c 54 sysfile.c
20 proc.h 59 exec.c # bootloader

