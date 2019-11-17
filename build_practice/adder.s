	.text
	.def	 @feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.file	"adder.c"
	.def	 add;
	.scl	2;
	.type	32;
	.endef
	.globl	add                     # -- Begin function add
	.p2align	4, 0x90
add:                                    # @add
.seh_proc add
# %bb.0:
	pushq	%rax
	.seh_stackalloc 8
	.seh_endprologue
	movl	%edx, 4(%rsp)
	movl	%ecx, (%rsp)
	movl	(%rsp), %eax
	addl	4(%rsp), %eax
	popq	%rcx
	retq
	.seh_handlerdata
	.text
	.seh_endproc
                                        # -- End function

	.addrsig
