section .text

global _ft_isalnum

extern			_ft_isalpha
extern			_ft_isdigit

_ft_isalnum:
	xor rax, rax

.check_alpha:
	
	call _ft_isalpha
	cmp rax, 0
	je .check_digit
	ret

.check_digit:
	call _ft_isdigit
	ret

