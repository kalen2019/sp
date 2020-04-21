	.file	"mystrcpy1.c"
 # GNU C11 (tdm-1) version 5.1.0 (mingw32)
 #	compiled by GNU C version 5.1.0, GMP version 4.3.2, MPFR version 2.4.2, MPC version 0.8.2
 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: 
 # -iprefix C:/Program Files (x86)/CodeBlocks/MinGW/bin/../lib/gcc/mingw32/5.1.0/
 # -D_REENTRANT mystrcpy1.c -mtune=generic -march=pentiumpro
 # -auxbase-strip mystrcpy1.s -O3 -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations -falign-labels
 # -fasynchronous-unwind-tables -fauto-inc-dec -fbranch-count-reg
 # -fcaller-saves -fchkp-check-incomplete-type -fchkp-check-read
 # -fchkp-check-write -fchkp-instrument-calls -fchkp-narrow-bounds
 # -fchkp-optimize -fchkp-store-bounds -fchkp-use-static-bounds
 # -fchkp-use-static-const-bounds -fchkp-use-wrappers
 # -fcombine-stack-adjustments -fcommon -fcompare-elim -fcprop-registers
 # -fcrossjumping -fcse-follow-jumps -fdefer-pop
 # -fdelete-null-pointer-checks -fdevirtualize -fdevirtualize-speculatively
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -fexpensive-optimizations -fforward-propagate -ffunction-cse -fgcse
 # -fgcse-after-reload -fgcse-lm -fgnu-runtime -fgnu-unique
 # -fguess-branch-probability -fhoist-adjacent-loads -fident
 # -fif-conversion -fif-conversion2 -findirect-inlining -finline
 # -finline-atomics -finline-functions -finline-functions-called-once
 # -finline-small-functions -fipa-cp -fipa-cp-alignment -fipa-cp-clone
 # -fipa-icf -fipa-icf-functions -fipa-icf-variables -fipa-profile
 # -fipa-pure-const -fipa-ra -fipa-reference -fipa-sra -fira-hoist-pressure
 # -fira-share-save-slots -fira-share-spill-slots
 # -fisolate-erroneous-paths-dereference -fivopts -fkeep-inline-dllexport
 # -fkeep-static-consts -fleading-underscore -flifetime-dse -flra-remat
 # -flto-odr-type-merging -fmath-errno -fmerge-constants
 # -fmerge-debug-strings -fmove-loop-invariants -fomit-frame-pointer
 # -foptimize-sibling-calls -foptimize-strlen -fpartial-inlining -fpeephole
 # -fpeephole2 -fpredictive-commoning -fprefetch-loop-arrays -free
 # -freg-struct-return -freorder-blocks -freorder-blocks-and-partition
 # -freorder-functions -frerun-cse-after-loop
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fschedule-insns2
 # -fsemantic-interposition -fset-stack-executable -fshow-column
 # -fshrink-wrap -fsigned-zeros -fsplit-ivs-in-unroller -fsplit-wide-types
 # -fssa-phiopt -fstdarg-opt -fstrict-aliasing -fstrict-overflow
 # -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
 # -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp
 # -ftree-builtin-call-dce -ftree-ccp -ftree-ch -ftree-coalesce-vars
 # -ftree-copy-prop -ftree-copyrename -ftree-cselim -ftree-dce
 # -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
 # -ftree-loop-distribute-patterns -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-loop-vectorize
 # -ftree-parallelize-loops= -ftree-partial-pre -ftree-phiprop -ftree-pre
 # -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink
 # -ftree-slp-vectorize -ftree-slsr -ftree-sra -ftree-switch-conversion
 # -ftree-tail-merge -ftree-ter -ftree-vrp -funit-at-a-time
 # -funswitch-loops -funwind-tables -fverbose-asm -fzero-initialized-in-bss
 # -m32 -m80387 -m96bit-long-double -maccumulate-outgoing-args
 # -malign-double -malign-stringops -mavx256-split-unaligned-load
 # -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387
 # -mieee-fp -mlong-double-80 -mms-bitfields -mno-red-zone -mno-sse4
 # -mpush-args -msahf -mstack-arg-probe -mvzeroupper

	.section	.text.unlikely,"x"
LCOLDB0:
	.text
LHOTB0:
	.p2align 4,,15
	.globl	_mystrcpy1
	.def	_mystrcpy1;	.scl	2;	.type	32;	.endef
_mystrcpy1:
	pushl	%ebp	 #
	pushl	%edi	 #
	pushl	%esi	 #
	pushl	%ebx	 #
	subl	$28, %esp	 #,
	movl	48(%esp), %ebx	 # source, source
	movl	52(%esp), %esi	 # target, target
	movl	%ebx, (%esp)	 # source,
	call	_strlen	 #
	testl	%eax, %eax	 # tmp130
	jle	L8	 #,
	leal	4(%ebx), %edx	 #, D.1837
	cmpl	%edx, %esi	 # D.1837, target
	leal	4(%esi), %edx	 #, D.1837
	setnb	%cl	 #, D.1840
	cmpl	%edx, %ebx	 # D.1837, source
	setnb	%dl	 #, D.1840
	orl	%ecx, %edx	 # D.1840, D.1840
	movl	%ebx, %ecx	 # source, D.1835
	orl	%esi, %ecx	 # target, D.1835
	andl	$3, %ecx	 #, D.1835
	sete	%cl	 #, D.1840
	testb	%cl, %dl	 # D.1840, D.1840
	je	L10	 #,
	cmpl	$9, %eax	 #, tmp130
	jbe	L10	 #,
	leal	-4(%eax), %ecx	 #, D.1839
	xorl	%edx, %edx	 # D.1839
	shrl	$2, %ecx	 #, D.1839
	addl	$1, %ecx	 #, bnd.9
	leal	0(,%ecx,4), %edi	 #, ratio_mult_vf.10
L4:
	movl	(%ebx,%edx,4), %ebp	 # MEM[base: source_4(D), index: _12, step: 4, offset: 0B], tmp149
	movl	%ebp, (%esi,%edx,4)	 # tmp149, MEM[base: target_8(D), index: _12, step: 4, offset: 0B]
	addl	$1, %edx	 #, D.1839
	cmpl	%edx, %ecx	 # D.1839, bnd.9
	ja	L4	 #,
	cmpl	%edi, %eax	 # ratio_mult_vf.10, tmp130
	je	L8	 #,
	movzbl	(%ebx,%ecx,4), %edx	 # *_7, D.1838
	movb	%dl, (%esi,%ecx,4)	 # D.1838, *_16
	leal	1(%edi), %edx	 #, i
	cmpl	%edx, %eax	 # i, tmp130
	jle	L8	 #,
	movzbl	1(%ebx,%edi), %edx	 # *_72, D.1838
	movb	%dl, 1(%esi,%edi)	 # D.1838, *_71
	leal	2(%edi), %edx	 #, i
	cmpl	%edx, %eax	 # i, tmp130
	jle	L8	 #,
	movzbl	2(%ebx,%edi), %eax	 # *_49, D.1838
	movb	%al, 2(%esi,%edi)	 # D.1838, *_48
L8:
	addl	$28, %esp	 #,
	xorl	%eax, %eax	 #
	popl	%ebx	 #
	popl	%esi	 #
	popl	%edi	 #
	popl	%ebp	 #
	ret
	.p2align 4,,10
L10:
	xorl	%edx, %edx	 # i
	.p2align 4,,10
L3:
	movzbl	(%ebx,%edx), %ecx	 # MEM[base: source_4(D), index: _59, offset: 0B], D.1838
	movb	%cl, (%esi,%edx)	 # D.1838, MEM[base: target_8(D), index: _59, offset: 0B]
	addl	$1, %edx	 #, i
	cmpl	%edx, %eax	 # i, tmp130
	jne	L3	 #,
	addl	$28, %esp	 #,
	xorl	%eax, %eax	 #
	popl	%ebx	 #
	popl	%esi	 #
	popl	%edi	 #
	popl	%ebp	 #
	ret
	.section	.text.unlikely,"x"
LCOLDE0:
	.text
LHOTE0:
	.section	.text.unlikely,"x"
LCOLDB1:
	.text
LHOTB1:
	.p2align 4,,15
	.globl	_mystrcpy2
	.def	_mystrcpy2;	.scl	2;	.type	32;	.endef
_mystrcpy2:
	movl	4(%esp), %edx	 # source, source
	movl	8(%esp), %ecx	 # target, target
	movzbl	(%edx), %eax	 # *source_3(D), D.1844
	testb	%al, %al	 # D.1844
	je	L27	 #,
	.p2align 4,,10
L28:
	movb	%al, (%ecx)	 # D.1844, *target_5(D)
	movzbl	(%edx), %eax	 # *source_3(D), D.1844
	testb	%al, %al	 # D.1844
	jne	L28	 #,
L27:
	xorl	%eax, %eax	 # <retval>
	ret
	.section	.text.unlikely,"x"
LCOLDE1:
	.text
LHOTE1:
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	_strlen;	.scl	2;	.type	32;	.endef
