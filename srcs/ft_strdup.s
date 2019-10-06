section .text

global 	_ft_strdup

extern	_ft_strlen
extern	_ft_strcpy
extern	_malloc

_ft_strdup:

	mov rsi, rdi
	push rsi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	call _malloc
	cmp rax, 0
	jz .failed_malloc
	mov rdi, rax
	pop rsi
	sub rsp, 8
	call _ft_strcpy
	mov rax, rdi
	add rsp, 8
	ret

.failed_malloc:
	pop rsi
	ret
