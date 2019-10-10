section .text

global 	_ft_puts
extern	_ft_strlen
extern	_ft_putstr

_ft_puts:

.put_str:

	sub rsp, 8
	call _ft_putstr
	add rsp, 8

.put_nl:
	mov edx, 1 ; nbytes
	mov rax, 0x2000004; write
	mov edi, 1

	mov rsi, 0ah 
	push rsi ; push 0ah (new line) on top of the stack
	mov rsi, rsp ; get address of the top of the stack (rsp) in rsi (buffer)
	syscall
	pop rsi ; pop what we pushed on the stack
	mov rax, 10
	ret
