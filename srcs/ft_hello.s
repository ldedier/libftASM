section .data

msg  db  'Hello, world!'

section .text

global _ft_hello

extern			_ft_puts

_ft_hello:

	mov rdi, msg
	call _ft_puts
	ret

