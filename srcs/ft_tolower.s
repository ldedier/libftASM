global _ft_tolower

_ft_tolower:
	
	mov rax, rdi
	cmp rdi, 'A'
	jl .not_an_uppercase
	cmp rdi, 'Z'
	jg .not_an_uppercase
	add rax, 'a' - 'A'
	ret

.not_an_uppercase:
	ret
