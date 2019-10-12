global _ft_strlen

	;rdi : char *str

_ft_strlen:

	xor ecx, ecx
	not ecx ; ecx = -1
	xor al, al
	cld
	repne scasb ; ecx = -strlen - 2
	not ecx ; reversing all bits of a negative number results in its absolute value - 1 (ecx = strlen + 1)
	dec ecx
	mov rax, rcx
	ret
