section .text

global _ft_strcat

extern _ft_strlen
extern _ft_strcpy

_ft_strcat:

	push rdi
	call _ft_strlen
	pop rdi
	mov rcx, rdi
	push rcx
	add rdi, rax
	call _ft_strcpy
	pop rdi
	mov rax, rdi
	ret
