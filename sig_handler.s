	.file	"sig_handler.c"
	.text
	.globl	sig_handler
	.type	sig_handler, @function
sig_handler:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$2, -4(%rbp)
	jne	.L3
	movl	$13, %edi
	call	_putchar
.L3:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	sig_handler, .-sig_handler
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~14.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
