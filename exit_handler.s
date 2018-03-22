	.file	"exit_handler.c"
	.section	.rodata
.LC0:
	.string	"exit"
	.text
	.globl	exit_handler
	.type	exit_handler, @function
exit_handler:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	_strcmp
	testl	%eax, %eax
	jne	.L2
	cmpq	$-1, -16(%rbp)
	jne	.L3
	movl	$10, %edi
	call	_putchar
.L3:
	movl	$0, %edi
	call	exit
.L2:
	movq	-16(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L5
	movl	$10, %edi
	call	_putchar
	movl	$0, %edi
	call	exit
.L5:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	exit_handler, .-exit_handler
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~14.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
