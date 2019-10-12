section .text

global _ft_strcmp

extern	_ft_strlen

_ft_strcmp:

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
	inc rcx

	cld
	repe cmpsb ; rdi and rsi -> added of rax + 1

	dec rdi
	dec rsi

	
	xor rax, rax
	xor rcx, rcx

	mov byte al, [rdi]
	mov byte cl, [rsi]
	sub eax, ecx
	add rsp, 8
	ret
