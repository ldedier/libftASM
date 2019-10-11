section .text

global 	_ft_putstr_fd
extern	_ft_strlen

_ft_putstr_fd:

	sub rsp, 8
	push rdi
	push rsi
	call _ft_strlen
	pop rdi
	pop rsi
	mov rdx, rax ; nbytes
	mov rax, 0x2000004 ; write
	syscall
	add rsp, 8
	ret
