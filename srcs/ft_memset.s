section .text

global _ft_memset

_ft_memset:

	;rdi : void *buffer
	;rsi : int c
	;rdx : size_t size

	push rdi

	mov ecx, edx ; set counter to size

	mov al, sil ; set byte to c
	
	rep stosb
	
	pop rdi
	mov rax, rdi
	ret
