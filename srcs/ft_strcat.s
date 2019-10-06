section .text

global _ft_strcat

extern _ft_strlen
extern _ft_strcpy

_ft_strcat:

	sub rsp, 8
	call _ft_strlen
	add rdi, rax
	call _ft_strcpy
	add rsp, 8
	ret
