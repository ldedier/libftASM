section .text

global _ft_strequ

extern			_ft_strlen

_ft_strequ:

	sub rsp, 8

	push rsi
	push rdi

	call _ft_strlen 

	mov rdx, rax ; rdx -> length of rdi

	pop rsi
	pop rdi

	push rsi
	push rdi

	call _ft_strlen ; rax -> length of rsi

	pop rsi
	pop rdi

	cmp rdx, rax
	cmovl rax, rdx

	mov rcx, rax ; get minimum of both strlen
	inc rcx;

	xor rax, rax
	cld
	repe cmpsb
	setz al
	add rsp, 8
	ret
