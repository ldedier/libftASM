section .text

global _ft_bzero

_ft_bzero:

	;rdi : void *buffer
	;rsi : size_t size

.fill_quad_word:

	cmp rsi, 8
	jb .fill_chars
	mov qword [rdi], 0
	sub rsi, 8
	add rdi, 8
	jmp .fill_quad_word

.fill_chars:
	cmp rsi, 0
	je .end
	mov byte [rdi], 0
	sub rsi, 1
	add rdi, 1
	jmp .fill_chars

.end:
	ret

