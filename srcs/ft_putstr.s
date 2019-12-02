section .data

msg  db  '(null)', 0h

section .text

global 	_ft_putstr
extern	_ft_strlen

_ft_putstr:

	sub rsp, 8
	cmp rdi, 0x0
	je .nullptr

.count_len:
	mov rsi, rdi ; pass str to 2nd parameter of write
	call _ft_strlen
	mov rdx, rax ; nbytes
	mov edi, 1 ; fd
	mov rax, 0x2000004 ; write
	syscall
	add rsp, 8
	ret

.nullptr:
	lea rdi, [rel msg]
	jmp .count_len
