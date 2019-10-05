section .text

global 	_ft_strdup

extern	_ft_strlen
extern	_ft_strcpy
extern	_ft_puts
extern	_ft_hello
extern	_malloc

_ft_strdup:

	mov rsi, rdi ;rsi -> str
	call _ft_strlen
	mov rdi, rax ; ->rdi len
	add rdi, 1 ;->rdi len + 1
	call _ft_hello
	call _malloc
	call _ft_hello
	cmp rax, 0
	jz .failed_malloc
	mov rdi, rax
	call _ft_strcpy
	ret

.failed_malloc:
	ret
