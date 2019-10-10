section .text

global _ft_strcpy

extern _ft_strlen
extern _ft_memcpy

_ft_strcpy:

	push rdi
	call _ft_strlen
	pop rdi
	
	mov rdx, rax
	
	push rax
	push rdi

	call _ft_memcpy
	
	pop rdi
	pop rax
	mov [edi + eax], 0

	mov rax, rdi
	ret
