	.file	"mystrcpy1.c"
 # GNU C11 (tdm-1) version 5.1.0 (mingw32)
 #	compiled by GNU C version 5.1.0, GMP version 4.3.2, MPFR version 2.4.2, MPC version 0.8.2
 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: 
 # -iprefix C:/Program Files (x86)/CodeBlocks/MinGW/bin/../lib/gcc/mingw32/5.1.0/
 # -D_REENTRANT mystrcpy1.c -mtune=generic -march=pentiumpro
 # -auxbase-strip mystrcpy1_O0.s -O0 -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations
 # -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
 # -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
 # -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
 # -fchkp-use-static-bounds -fchkp-use-static-const-bounds
 # -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
 # -finline-atomics -fira-hoist-pressure -fira-share-save-slots
 # -fira-share-spill-slots -fivopts -fkeep-inline-dllexport
 # -fkeep-static-consts -fleading-underscore -flifetime-dse
 # -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
 # -fprefetch-loop-arrays -freg-struct-return
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
 # -fset-stack-executable -fshow-column -fsigned-zeros
 # -fsplit-ivs-in-unroller -fstdarg-opt -fstrict-volatile-bitfields
 # -fsync-libcalls -ftrapping-math -ftree-coalesce-vars -ftree-cselim
 # -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
 # -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
 # -funwind-tables -fverbose-asm -fzero-initialized-in-bss -m32 -m80387
 # -m96bit-long-double -maccumulate-outgoing-args -malign-double
 # -malign-stringops -mavx256-split-unaligned-load
 # -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387
 # -mieee-fp -mlong-double-80 -mms-bitfields -mno-red-zone -mno-sse4
 # -mpush-args -msahf -mstack-arg-probe -mvzeroupper

	.text
	.globl	_mystrcpy1
	.def	_mystrcpy1;	.scl	2;	.type	32;	.endef
_mystrcpy1:
	pushl	%ebp	 #
	movl	%esp, %ebp	 #,
	subl	$40, %esp	 #,
	movl	8(%ebp), %eax	 # source, tmp94
	movl	%eax, (%esp)	 # tmp94,
	call	_strlen	 #
	movl	%eax, -16(%ebp)	 # D.1799, len
	movl	$0, -12(%ebp)	 #, i
	jmp	L2	 #
L3:
	movl	-12(%ebp), %edx	 # i, D.1800
	movl	12(%ebp), %eax	 # target, tmp95
	addl	%eax, %edx	 # tmp95, D.1801
	movl	-12(%ebp), %ecx	 # i, D.1800
	movl	8(%ebp), %eax	 # source, tmp96
	addl	%ecx, %eax	 # D.1800, D.1801
	movzbl	(%eax), %eax	 # *_12, D.1802
	movb	%al, (%edx)	 # D.1802, *_10
	addl	$1, -12(%ebp)	 #, i
L2:
	movl	-12(%ebp), %eax	 # i, tmp97
	cmpl	-16(%ebp), %eax	 # len, tmp97
	jl	L3	 #,
	nop
	leave
	ret
	.globl	_mystrcpy2
	.def	_mystrcpy2;	.scl	2;	.type	32;	.endef
_mystrcpy2:
	pushl	%ebp	 #
	movl	%esp, %ebp	 #,
	subl	$40, %esp	 #,
	movl	$0, -12(%ebp)	 #, i
	jmp	L5	 #
L6:
	movl	-12(%ebp), %edx	 # i, D.1804
	movl	12(%ebp), %eax	 # target, tmp95
	addl	%eax, %edx	 # tmp95, D.1805
	movl	-12(%ebp), %ecx	 # i, D.1804
	movl	8(%ebp), %eax	 # source, tmp96
	addl	%ecx, %eax	 # D.1804, D.1805
	movzbl	(%eax), %eax	 # *_12, D.1806
	movb	%al, (%edx)	 # D.1806, *_10
	addl	$1, -12(%ebp)	 #, i
L5:
	movl	8(%ebp), %eax	 # source, tmp97
	movl	%eax, (%esp)	 # tmp97,
	call	_strlen	 #
	movl	%eax, %edx	 #, D.1803
	movl	-12(%ebp), %eax	 # i, D.1803
	cmpl	%eax, %edx	 # D.1803, D.1803
	ja	L6	 #,
	nop
	leave
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	_strlen;	.scl	2;	.type	32;	.endef
