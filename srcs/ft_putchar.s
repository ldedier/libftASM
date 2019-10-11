section .text

global 	_ft_putchar
extern	_putchar

_ft_putchar:

	sub rsp, 8
	call _putchar
	add rsp, 8
	ret

;;	push rdi
;	mov rsi, rsp
;	mov edx, 1 ; nbytes
;	mov rax, 0x2000004; write
;	mov edi, 1
;	syscall
;	pop rsi
;	mov rax, rsi
;	ret
