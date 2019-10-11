section .text

global 	_ft_putstr
extern	_ft_strlen

_ft_putstr:

	push rdi
;	mov rsi, rdi ; pass str to 2nd parameter of write
	call _ft_strlen
	mov rdx, rax ; nbytes
	mov edi, 1 ; fd
	pop rsi
	sub rsp, 8
	mov rax, 0x2000004 ; write
	syscall
	add rsp, 8
