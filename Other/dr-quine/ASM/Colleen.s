section .data
	str: db "section .data%3$c%2$cstr: db %4$c%1$s%4$c, 0%3$c%3$csection .text%3$c%2$cglobal _start%3$c%2$cextern printf%3$c%2$cextern fflush%3$c%3$c; Hello World !%3$c%3$c_dr_quine:%3$c%2$ccall%2$cprintf%3$c%2$cret%3$c%3$cmain:%3$c%3$c%2$c; tab = 9, new_line = 10, double_quote = 34%3$c%2$cmov%2$c%2$crdi, str%3$c%2$cmov%2$c%2$crsi, str%3$c%2$cmov%2$c%2$crdx, 9%3$c%2$cmov%2$c%2$crcx, 10%3$c%2$cmov%2$c%2$cr8,  34%3$c%2$ccall%2$c_dr_quine%3$c%2$c%3$c%2$cxor%2$c%2$cedi, edi%3$c%2$ccall%2$cfflush %3$c%2$c%3$c%2$cret%3$c%3$c_start:%3$c%2$ccall%2$cmain%3$c%3$c%2$cmov%2$c%2$crdi, rax%3$c%2$cmov%2$c%2$crax, 60%3$c%2$csyscall%3$c", 0

section .text
	global _start
	extern printf
	extern fflush

; Hello World !

_dr_quine:
	call	printf
	ret

main:

	; tab = 9, new_line = 10, double_quote = 34
	mov		rdi, str
	mov		rsi, str
	mov		rdx, 9
	mov		rcx, 10
	mov		r8,  34
	call	_dr_quine
	
	xor		edi, edi
	call	fflush 
	
	ret

_start:
	call	main

	mov		rdi, rax
	mov		rax, 60
	syscall
