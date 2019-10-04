global _ft_isalpha

_ft_isalpha:
	xor rax, rax

.check_maj:
	cmp rdi, 'A'
	jl .not_alpha
	cmp rdi, 'Z'
	jg .check_min
	mov rax, 1
	ret

.check_min:
	cmp rdi, 'a'
	jl .not_alpha
	cmp rdi, 'z'
	setle al

.not_alpha:
	ret
