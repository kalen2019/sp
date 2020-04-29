	.file	"tinyHello.c"
	.globl	_str
	.section .rdata,"dr"
LC0:
	.ascii "Hello world!\12\0"
	.data
	.align 4
_str:
	.long	LC0
	.text
	.globl	_print
	.def	_print;	.scl	2;	.type	32;	.endef
_print:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	_str, %eax
/APP
 # 4 "tinyHello.c" 1
	movl $13, %edx
	movl $0,  %ecx
	movl $0,  %ebx
	movl $4,  %eax
	int $0x80
	
 # 0 "" 2
/NO_APP
	nop
	popl	%ebx
	popl	%ebp
	ret
	.globl	_exit
	.def	_exit;	.scl	2;	.type	32;	.endef
_exit:
	pushl	%ebp
	movl	%esp, %ebp
/APP
 # 13 "tinyHello.c" 1
	movl $42, %%ebx
	movl $1, %%eax
	int $0x80
	
 # 0 "" 2
/NO_APP
	nop
	popl	%ebp
	ret
	.globl	_nomain
	.def	_nomain;	.scl	2;	.type	32;	.endef
_nomain:
	pushl	%ebp
	movl	%esp, %ebp
	call	_print
	call	_exit
	nop
	popl	%ebp
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
