section .text
	extern sprintf
	extern fprintf
	extern fopen
	extern fclose
	extern system
	global _start

_start:
	push	rbp
	mov		rbp, rsp
							; rbp - 08 = i
							; rbp - 10 = kid
							; int i = 5;
	mov		rax, 5
							; i--;
	sub		rax, 1
	push	rax
							; sprintf(filename, "Sully_%d.s", i);
	lea		rdi, [filename]
	lea		rsi, [filename]
	mov		rdx, [rbp - 0x08]
	call	sprintf
							; FILE *kid = fopen(filename, "w");
	lea		rdi, [filename]
	lea		rsi, [accessmode]
	call	fopen
	push	rax
							; if (kid) {
	test	rax, rax
	je		_exit
							; fprintf(kid, STR, STR, 9, 10, 34, i - 1);
	mov		rdi, rax
	lea		rsi, [str]
	lea		rdx, [str]
	mov		rcx, 9
	mov		r8, 10
	mov		r9, 34
	mov		rax, [rbp - 0x08]
	push	rax
	call	fprintf
							; fclose(kid);
	mov		rdi, [rbp - 0x10]
	call	fclose
							; if (i > 0) {
	mov		rax, [rbp - 0x08]
	cmp		rax, 0
	jl		_exit
							; sprintf(filename, "Sully_%d.s", i);
	lea		rdi, [cmd]
	lea		rsi, [cmd]
	mov		rdx, [rbp - 0x08]
	call	sprintf
							; system(cmd);
	lea		rdi, [cmd]
	call	system
_exit:
	pop		rbp
							; exit(0);
	mov		rax, 60
	mov		rdi, 0
	syscall

section .data

filename: db "Sully_%d.s", 0, 0
accessmode: db "w", 0
cmd: db "nasm -f elf64 -g -F dwarf -DPIC Sully_%1$d.s -o Sully_%1$d.o; ld Sully_%1$d.o -o Sully_%1$d -lc -I /lib64/ld-linux-x86-64.so.2; ./Sully_%1$d", 0, 0, 0, 0, 0
str: db "section .text%3$c%2$cextern sprintf%3$c%2$cextern fprintf%3$c%2$cextern fopen%3$c%2$cextern fclose%3$c%2$cextern system%3$c%2$cglobal _start%3$c%3$c_start:%3$c%2$cpush%2$crbp%3$c%2$cmov%2$c%2$crbp, rsp%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; rbp - 08 = i%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; rbp - 10 = kid%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; int i = 5;%3$c%2$cmov%2$c%2$crax, %5$d%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; i--;%3$c%2$csub%2$c%2$crax, 1%3$c%2$cpush%2$crax%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; sprintf(filename, %4$cSully_%%d.s%4$c, i);%3$c%2$clea%2$c%2$crdi, [filename]%3$c%2$clea%2$c%2$crsi, [filename]%3$c%2$cmov%2$c%2$crdx, [rbp - 0x08]%3$c%2$ccall%2$csprintf%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; FILE *kid = fopen(filename, %4$cw%4$c);%3$c%2$clea%2$c%2$crdi, [filename]%3$c%2$clea%2$c%2$crsi, [accessmode]%3$c%2$ccall%2$cfopen%3$c%2$cpush%2$crax%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; if (kid) {%3$c%2$ctest%2$crax, rax%3$c%2$cje%2$c%2$c_exit%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; fprintf(kid, STR, STR, 9, 10, 34, i - 1);%3$c%2$cmov%2$c%2$crdi, rax%3$c%2$clea%2$c%2$crsi, [str]%3$c%2$clea%2$c%2$crdx, [str]%3$c%2$cmov%2$c%2$crcx, 9%3$c%2$cmov%2$c%2$cr8, 10%3$c%2$cmov%2$c%2$cr9, 34%3$c%2$cmov%2$c%2$crax, [rbp - 0x08]%3$c%2$cpush%2$crax%3$c%2$ccall%2$cfprintf%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; fclose(kid);%3$c%2$cmov%2$c%2$crdi, [rbp - 0x10]%3$c%2$ccall%2$cfclose%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; if (i > 0) {%3$c%2$cmov%2$c%2$crax, [rbp - 0x08]%3$c%2$ccmp%2$c%2$crax, 0%3$c%2$cjl%2$c%2$c_exit%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; sprintf(filename, %4$cSully_%%d.s%4$c, i);%3$c%2$clea%2$c%2$crdi, [cmd]%3$c%2$clea%2$c%2$crsi, [cmd]%3$c%2$cmov%2$c%2$crdx, [rbp - 0x08]%3$c%2$ccall%2$csprintf%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; system(cmd);%3$c%2$clea%2$c%2$crdi, [cmd]%3$c%2$ccall%2$csystem%3$c_exit:%3$c%2$cpop%2$c%2$crbp%3$c%2$c%2$c%2$c%2$c%2$c%2$c%2$c; exit(0);%3$c%2$cmov%2$c%2$crax, 60%3$c%2$cmov%2$c%2$crdi, 0%3$c%2$csyscall%3$c%3$csection .data%3$c%3$cfilename: db %4$cSully_%%d.s%4$c, 0, 0%3$caccessmode: db %4$cw%4$c, 0%3$ccmd: db %4$cnasm -f elf64 -g -F dwarf -DPIC Sully_%%1$d.s -o Sully_%%1$d.o; ld Sully_%%1$d.o -o Sully_%%1$d -lc -I /lib64/ld-linux-x86-64.so.2; ./Sully_%%1$d%4$c, 0, 0, 0, 0, 0%3$cstr: db %4$c%1$s%4$c, 0%3$c", 0
