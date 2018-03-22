	.file	"shell.c"
	.section	.rodata
.LC0:
	.string	"No such file or directory"
.LC1:
	.string	"($) "
.LC2:
	.string	"TS0: %s\n"
.LC3:
	.string	"Child process has started"
.LC4:
	.string	"fail!"
.LC5:
	.string	"Parent process is waiting"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	$0, -24(%rbp)
	movq	$.LC0, -16(%rbp)
	movq	$0, -48(%rbp)
	movl	$sig_handler, %esi
	movl	$2, %edi
	call	signal
	cmpl	$1, -68(%rbp)
	jne	.L2
.L8:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	stdin(%rip), %rdx
	leaq	-32(%rbp), %rcx
	leaq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	getline
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	exit_handler
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	subq	$1, %rdx
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$10, %al
	jne	.L3
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	subq	$1, %rdx
	addq	%rdx, %rax
	movb	$0, (%rax)
.L3:
	movq	-24(%rbp), %rax
	leaq	-48(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_strtok
	movq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	call	fork
	movl	%eax, -52(%rbp)
	cmpl	$0, -52(%rbp)
	jns	.L4
	movl	$-1, %eax
	jmp	.L9
.L4:
	cmpl	$0, -52(%rbp)
	jne	.L6
	movq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC3, %edi
	call	puts
	movq	-48(%rbp), %rax
	leaq	-48(%rbp), %rcx
	movl	$0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	execve
	cmpl	$-1, %eax
	jne	.L7
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$-1, %eax
	jmp	.L9
.L6:
	movl	$.LC5, %edi
	call	puts
.L7:
	movl	$0, %eax
	movq	%rax, %rdi
	call	wait
	jmp	.L8
.L2:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movl	$0, %eax
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~14.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
