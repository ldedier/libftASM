section .text

global 	_ft_putchar

_ft_putchar:

	mov rsi, rdi

	mov edx, 1 ; nbytes
	mov rax, 0x2000004; write
	mov edi, 1

	push rsi ; push on top of the stack
	mov rsi, rsp ; get address of the top of the stack (rsp) in rsi

	syscall
	pop rsi ; pop what we pushed on the stack
	mov rax, rsi
	ret
