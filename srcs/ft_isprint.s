global _ft_isprint

_ft_isprint:
	
	xor rax, rax
	cmp rdi, 32
	jl .not_printable
	cmp rdi, 126
	setle al
	ret

.not_printable:
	ret
