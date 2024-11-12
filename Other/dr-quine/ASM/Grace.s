%define DECLARE_MAIN global _start
%define MAIN_INJECTION _start:

section .text
	extern fprintf
	extern fopen
	extern fclose
	DECLARE_MAIN

MAIN_INJECTION
	mov		rdi, filepath
	mov		rsi, accessmode
	call	fopen
	mov		r12, rax

	; tab = 9, new_line = 10, double_quote = 34
	mov		rdi, rax
	mov		rsi, format
	mov		rdx, format
	mov		rcx, 9
	mov		r8,  10
	mov		r9,  34
	call	fprintf

	mov		rdi, r12
	call	fclose
	mov		rax, 60
	mov		rdi, 0
	syscall

section .data

format:		db "%%define DECLARE_MAIN global _start%3$c%%define MAIN_INJECTION _start:%3$c%3$csection .text%3$c%2$cextern fprintf%3$c%2$cextern fopen%3$c%2$cextern fclose%3$c%2$cDECLARE_MAIN%3$c%3$cMAIN_INJECTION%3$c%2$cmov%2$c%2$crdi, filepath%3$c%2$cmov%2$c%2$crsi, accessmode%3$c%2$ccall%2$cfopen%3$c%2$cmov%2$c%2$cr12, rax%3$c%3$c%2$c; tab = 9, new_line = 10, double_quote = 34%3$c%2$cmov%2$c%2$crdi, rax%3$c%2$cmov%2$c%2$crsi, format%3$c%2$cmov%2$c%2$crdx, format%3$c%2$cmov%2$c%2$crcx, 9%3$c%2$cmov%2$c%2$cr8,  10%3$c%2$cmov%2$c%2$cr9,  34%3$c%2$ccall%2$cfprintf%3$c%3$c%2$cmov%2$c%2$crdi, r12%3$c%2$ccall%2$cfclose%3$c%2$cmov%2$c%2$crax, 60%3$c%2$cmov%2$c%2$crdi, 0%3$c%2$csyscall%3$c%3$csection .data%3$c%3$cformat:%2$c%2$cdb %4$c%1$s%4$c, 0%3$cfilepath:%2$cdb %4$cGrace_kid.s%4$c, 0%3$caccessmode:%2$cdb %4$cw%4$c, 0%3$c", 0
filepath:	db "Grace_kid.s", 0
accessmode:	db "w", 0
