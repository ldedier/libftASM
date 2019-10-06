section .text

global 	_ft_cat

extern	_ft_puts

;rdi : int fd

_ft_cat:

	sub rsp, 4096 ; 4096
;	push rdi

.read_chunk:

;	pop rdi
	mov rax, 0x2000003 ; read opcode
	mov rsi, rsp ; get address of the top of the stack in rsi (buffer)
;	add rsi, 8
	mov edx, 4095
	push rdi
	syscall ; read
	cmp rax, 0
	jl .end_cat

	mov rcx, 0
	mov byte [rsi + rax], cl ; buffer[ret] = 0

	mov rdi, rsi
	call _ft_puts
	jmp .read_chunk

.end_cat:
;	pop rdi
	add rsp, 4096
	ret
