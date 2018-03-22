	.file	"_strtok.c"
	.section	.rodata
.LC0:
	.string	" "
	.text
	.globl	_strtok
	.type	_strtok, @function
_strtok:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$0, -28(%rbp)
	movq	-40(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	strtok
	movq	%rax, -24(%rbp)
	jmp	.L2
.L3:
	addl	$1, -28(%rbp)
	movl	$.LC0, %esi
	movl	$0, %edi
	call	strtok
	movq	%rax, -24(%rbp)
.L2:
	cmpq	$0, -24(%rbp)
	jne	.L3
	movl	-28(%rbp), %eax
	salq	$3, %rax
	addq	$1, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, (%rax)
	cmpq	$0, -48(%rbp)
	je	.L9
	movl	$0, -28(%rbp)
	movq	-40(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	strtok
	movq	%rax, -24(%rbp)
	jmp	.L6
.L8:
	movl	-28(%rbp), %eax
	leaq	0(,%rax,8), %rdx
	movq	-48(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, %rdi
	call	malloc
	movq	%rax, (%rbx)
	movl	-28(%rbp), %eax
	leaq	0(,%rax,8), %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L10
	movl	-28(%rbp), %eax
	leaq	0(,%rax,8), %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rax, (%rdx)
	addl	$1, -28(%rbp)
	movl	$.LC0, %esi
	movl	$0, %edi
	call	strtok
	movq	%rax, -24(%rbp)
.L6:
	cmpq	$0, -24(%rbp)
	jne	.L8
	jmp	.L1
.L9:
	nop
	jmp	.L1
.L10:
	nop
.L1:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_strtok, .-_strtok
	.ident	"GCC: (Ubuntu 5.4.1-2ubuntu1~14.04) 5.4.1 20160904"
	.section	.note.GNU-stack,"",@progbits
