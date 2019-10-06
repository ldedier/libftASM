section .text

global _ft_strcmp

extern			_strcmp

_ft_strcmp:

	sub rsp, 8
	call _strcmp
	add rsp, 8
	ret


