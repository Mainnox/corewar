	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpl	$2, -8(%rbp)
	je	LBB0_2
## %bb.1:
	leaq	L_.str(%rip), %rdi
	leaq	L_.str.1(%rip), %rsi
	movb	$0, %al
	callq	_ft_printf
	movl	%eax, -48(%rbp)         ## 4-byte Spill
LBB0_2:
	leaq	L_.str(%rip), %rdi
	leaq	L_.str.2(%rip), %rsi
	movb	$0, %al
	callq	_ft_printf
	leaq	-40(%rbp), %rdi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	callq	_init_handle
	movq	-16(%rbp), %rsi
	movq	8(%rsi), %rdi
	movl	-36(%rbp), %esi
	movb	$0, %al
	callq	_open
	xorl	%esi, %esi
	movl	%eax, -44(%rbp)
	movl	%esi, %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function init_handle
_init_handle:                           ## @init_handle
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movl	$0, (%rdi)
	movq	-8(%rbp), %rdi
	movl	$0, 4(%rdi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%s\n"

L_.str.1:                               ## @.str.1
	.asciz	"wrong number of arguments"

L_.str.2:                               ## @.str.2
	.asciz	"usage: ./asm champion.s"


.subsections_via_symbols
