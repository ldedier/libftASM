section .text

global 	_ft_cat

extern	_ft_putstr
extern	_ft_hello

;rdi : int fd

_ft_cat:

	sub rsp, 4096 + 8; 4096
	mov rsi, rsp ; get address of the top of the stack in rsi (buffer)
	push rdi

.read_chunk:

	pop rdi
	mov rax, 0x2000003 ; read opcode
	mov rdx, 4095
	push rdi
	push rsi
	syscall
	pop rsi
	cmp rax, 0
	jle .end_cat
	mov rcx, 0
	mov byte [rsi + rax], cl ; buffer[ret] = 0
	mov rdi, rsi
	push rsi
	call _ft_putstr
	pop rsi
	jmp .read_chunk

.end_cat:
	pop rdi
	add rsp, 4096 + 8
	ret
