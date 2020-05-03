	.text
	.globl	_hcode
	.def	_hcode;	.scl	2;	.type	32;	.endef
_hcode:
	movw	$3, _A
	movw	$5, _D
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
