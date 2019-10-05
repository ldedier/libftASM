section .text

global _ft_isdigit

_ft_isdigit:
	
	xor rax, rax
	cmp rdi, '0'
	jl .not_a_digit
	cmp rdi, '9'
	setle al
	ret

.not_a_digit:
	ret
