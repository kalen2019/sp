	.text
	.globl	_hcode
	.def	_hcode;	.scl	2;	.type	32;	.endef
_hcode:
L0: # @8
	movl $8, %eax
L1: # D=A
	movl %eax, %ebx
	movl %ebx, %edx
L2: # @0
	movl $0, %eax
L3: # M=D
	movl %edx, %ebx
	movl %ebx, _m(%eax,%eax)
L4: # @5
	movl $5, %eax
L5: # D=A
	movl %eax, %ebx
	movl %ebx, %edx
L6: # @1
	movl $1, %eax
L7: # M=D
	movl %edx, %ebx
	movl %ebx, _m(%eax,%eax)
L8: # @0
	movl $0, %eax
L9: # D=M
	movl _m(%eax,%eax), %ebx
	movl %ebx, %edx
L10: # @1
	movl $1, %eax
L11: # D=D-M
	movl %edx, %ebx
	movl _m(%eax,%eax), %ecx
	subl %ecx, %ebx
	movl %ebx, %edx
L12: # @18
	movl $18, %eax
L13: # D;JGT
	movl %edx, %ebx
	cmpl $0, %ebx
	movl %eax, %ecx
	sall $2, %ecx
	addl $JumpTable, %ecx
	movl (%ecx), %ecx
	jg SKIP0
	jmp *%ecx
SKIP0:
L14: # @1
	movl $1, %eax
L15: # D=M
	movl _m(%eax,%eax), %ebx
	movl %ebx, %edx
L16: # @20
	movl $20, %eax
L17: # 0;JMP
	movl $0, %ebx
	movl %eax, %ecx
	sall $2, %ecx
	addl $JumpTable, %ecx
	movl (%ecx), %ecx
	jmp *%ecx
L18: # @0
	movl $0, %eax
L19: # D=M
	movl _m(%eax,%eax), %ebx
	movl %ebx, %edx
L20: # @2
	movl $2, %eax
L21: # M=D
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
	.long L6
	.long L7
	.long L8
	.long L9
	.long L10
	.long L11
	.long L12
	.long L13
	.long L14
	.long L15
	.long L16
	.long L17
	.long L18
	.long L19
	.long L20
	.long L21
	.text
