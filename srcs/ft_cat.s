section .text

global 	_ft_cat

extern	_ft_putstr

;rdi : int fd

_ft_cat:

	cmp edi, 0
	jl .end

	sub rsp, 4096 + 8
	mov rsi, rsp ; get address of the top of the stack in rsi (buffer)
	push rdi

.read_chunk:

	pop rdi
	mov rax, 0x2000003 ; read opcode
	mov rdx, 4095
	push rdi
	push rsi
	syscall

	js .pop_and_end
	jc .pop_and_end
	jmp .check_read_end

.pop_and_end:
	pop rsi
	jmp .end_cat

.check_read_end:
	pop rsi
	cmp eax, 0
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
.end:
	ret
