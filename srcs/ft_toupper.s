global _ft_toupper

_ft_toupper:
	
	mov rax, rdi
	cmp rdi, 'a'
	jl .not_a_lowercase
	cmp rdi, 'z'
	jg .not_a_lowercase
	sub rax, 'a' - 'A'
	ret

.not_a_lowercase:
	ret
