section .text

global _ft_strcmp

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
	cmovg rax, rdx

	mov rcx, rax ; get minimum of both strlen

	push rcx
	xor rax, rax
	cld
	repe cmpsb
	jz .equals
	setz al
	add rsp, 8
	ret


.equals
	xor rax, rax
	ret 
