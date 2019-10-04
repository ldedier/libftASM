global _ft_bzero

_ft_bzero:

	mov bx, 1000h
	shr ebx, 4
	mov eax, [ebx]
