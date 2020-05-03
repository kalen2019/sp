	.text
	.globl	_hcode
	.def	_hcode;	.scl	2;	.type	32;	.endef
_hcode:
L0: # @2
	movl $2, %eax
L1: # D=A
	movl %eax, %ebx
	movl %ebx, %edx
L2: # @3
	movl $3, %eax
L3: # D=D+A
	movl %edx, %ebx
	addl %eax, %ebx
	movl %ebx, %edx
L4: # @0
	movl $0, %eax
L5: # M=D
	movl %edx, %ebx
	movl %ebx, _m(%eax,%eax)
	movw	%ax, _A
	movw	%dx, _D
	ret
.section .rdata,"dr"
	.align 4
JumpTable:
	.long L0
	.long L1
	.long L2
	.long L3
	.long L4
	.long L5
	.text
