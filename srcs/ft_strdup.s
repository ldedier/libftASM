section .text

global 	_ft_strdup

extern	_ft_strlen
extern	_ft_strcpy
extern	_ft_hello
extern	_malloc

_ft_strdup:

	sub	rsp, 8
	mov rsi, rdi		;rsi -> str
	call _ft_strlen
	mov rdi, rax		; ->rdi len
	inc rdi				;->rdi len + 1
	call _malloc
	cmp rax, 0
	jz .failed_malloc
	call _ft_hello
	mov rdi, rax
	call _ft_strcpy
	mov rax, rdi
	add rsp, 8
	ret

.failed_malloc:
	call _ft_hello
	call _ft_hello
	call _ft_hello
	add rsp, 8
	ret
