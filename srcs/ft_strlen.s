global _ft_strlen

_ft_strlen:

	;rdi : char *str

	xor rax, rax
.count_len:

	mov byte cl, [rdi + rax]
	cmp cl, 0
	jz .end
	inc rax
	jmp .count_len

.end:
	ret

