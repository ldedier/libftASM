section .text

global _ft_strcpy

extern _ft_strlen
extern _ft_memcpy

	;rdi: dest
	;rsi: src

_ft_strcpy:

	sub rsp, 8
	push rdi
	push rsi
	mov rdi, rsi
	call _ft_strlen
	pop rsi
	pop rdi

	mov rdx, rax

	push rax
	push rdi

	call _ft_memcpy
	
	pop rdi
	pop rax
	xor dl, dl
	mov byte [rdi + rax], dl
	mov rax, rdi
	add rsp, 8
	ret
