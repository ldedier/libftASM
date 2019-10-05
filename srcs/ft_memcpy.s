section .text

global _ft_memcpy

_ft_memcpy:

	;rdi : void *dest
	;rsi : void *src
	;rdx : size_t size

.fill_quad_word:

	cmp rdx, 8
	jb .fill_chars
	mov qword rcx , [rsi]
	mov qword [rdi], rcx
	add rdi, 8
	add rsi, 8
	sub rdx, 8
	jmp .fill_quad_word

.fill_chars:
	cmp rdx, 0
	je .end
	mov byte cl , [rsi]
	mov byte [rdi], cl
	add rdi, 1
	add rsi, 1
	sub rdx, 1
	jmp .fill_chars

.end:
	ret

