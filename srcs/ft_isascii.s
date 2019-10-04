global _ft_isascii

_ft_isascii:
	
	xor rax, rax
	cmp rdi, 0
	jl .not_ascii
	cmp rdi, 177o
	setle al
	ret

.not_ascii:
	ret
