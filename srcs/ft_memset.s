section .text

global _ft_memset

_ft_memset:

	;rdi : void *buffer
	;rsi : int c
	;rdx : size_t size

	push rdi

.fill_chars:
	cmp rdx, 0
	je .end
	mov byte [rdi], sil
	sub rdx, 1
	inc rdi
	jmp .fill_chars

.end:
	pop rdi
	mov rax, rdi
	ret

