	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
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
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$111, -20(%rbp)
	movl	$222, -24(%rbp)
	movl	$333, -28(%rbp)         ## imm = 0x14D
	leaq	_env(%rip), %rdi
	callq	_setjmp
	cmpl	$0, %eax
	jne	LBB0_2
## %bb.1:
	movl	$777, -20(%rbp)         ## imm = 0x309
	movl	$888, -24(%rbp)         ## imm = 0x378
	movl	$999, -28(%rbp)         ## imm = 0x3E7
	movl	-20(%rbp), %edi
	movl	-24(%rbp), %esi
	movl	-28(%rbp), %edx
	callq	_doJump
	jmp	LBB0_3
LBB0_2:
	movl	-20(%rbp), %esi
	movl	-24(%rbp), %edx
	movl	-28(%rbp), %ecx
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB0_3:
	xorl	%edi, %edi
	callq	_exit
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function doJump
_doJump:                                ## @doJump
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	-4(%rbp), %esi
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %ecx
	leaq	L_.str.1(%rip), %rdi
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	callq	_printf
	leaq	_env(%rip), %rdi
	movl	$1, %esi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	callq	_longjmp
	.cfi_endproc
                                        ## -- End function
.zerofill __DATA,__bss,_env,148,4       ## @env
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"After longjmp: nvar=%d, rvar=%d, vvar=%d\n"

L_.str.1:                               ## @.str.1
	.asciz	"Inside doJump: nvar=%d, rvar=%d, vvar=%d\n"


.subsections_via_symbols
