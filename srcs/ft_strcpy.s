section .text

global _ft_strcpy

_ft_strcpy:

	;rdi : char *dest
	;rsi : char *src

	xor rcx, rcx

.fill_chars:
	xor rdx, rdx
	cmp [rsi + rcx], rdx
	je .end
	mov byte dl, [rsi + rcx]
	mov byte [rdi + rcx], dl
	inc rcx
	jmp .fill_chars

.end:
	xor rdx, rdx
	mov [rdi + rcx], rdx
	ret

