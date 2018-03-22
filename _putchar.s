	.file	"_putchar.c"
	.text
	.globl	_putchar
	.type	_putchar, @function
_putchar:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	leaq	-4(%rbp), %rax
	movl	$1, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	write
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_putchar, .-_putchar
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~14.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
