section .text

global _ft_memcpy

_ft_memcpy:

	;rdi : void *dest
	;rsi : void *src
	;rdx : size_t size

	push rdi
	rep movsb
	mov rcx, rdx
	pop rdi
	mov rax, rdi
	ret
