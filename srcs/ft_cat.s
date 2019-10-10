section .text

global 	_ft_cat

extern	_ft_puts
extern	_ft_hello

;rdi : int fd

_ft_cat:

	sub rsp, 4096 + 8; 4096
	push rdi
	mov rsi, rsp ; get address of the top of the stack in rsi (buffer)

.read_chunk:

	pop rdi
	mov rax, 0x2000003 ; read opcode
	mov rdx, 4095
	push rdi
	push rsi
	syscall
	pop rsi
	cmp rax, 0
	jl .end_cat
	mov rcx, 0
	mov byte [rsi + rax], cl ; buffer[ret] = 0
	mov rdi, rsi
	call _ft_puts ; putstr instead
	jmp .read_chunk

.end_cat:
	pop rdi
	add rsp, 4096 + 8
	ret
