section .data

msg  db  'Hello, world!'

section .text

global _ft_hello

extern			_ft_puts

_ft_hello:

	lea rdi, [rel msg]
	sub rsp, 8
	call _ft_puts
	add rsp, 8
	ret

