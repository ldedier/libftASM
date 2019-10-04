global _ft_isalnum

%include		'ft_isalpha.s'
%include		'ft_isdigit.s'

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

