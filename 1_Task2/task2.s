	.file	"task2.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"*********************************************************"
.LC1:
	.string	"\nWelcome to my command shell"
	.align 8
.LC2:
	.string	"Please note that the max command size is 100\n"
.LC3:
	.string	"mesa_mesa>"
.LC4:
	.string	"\n"
.LC5:
	.string	"exit"
.LC6:
	.string	"Good Bye:)"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$68, -112(%rbp)
	movq	$0, -104(%rbp)
	movq	$0, -96(%rbp)
	movq	$0, -88(%rbp)
	movq	$0, -80(%rbp)
	movq	$0, -72(%rbp)
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movl	$0, -16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L2
.L3:
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	stdin(%rip), %rdx
	leaq	-112(%rbp), %rax
	movl	$100, %esi
	movq	%rax, %rdi
	call	fgets@PLT
	leaq	-112(%rbp), %rax
	leaq	.LC4(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcspn@PLT
	movb	$0, -112(%rbp,%rax)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L2:
	leaq	-112(%rbp), %rax
	leaq	.LC5(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L3
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
