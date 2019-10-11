global _ft_strlen

	;rdi : char *str

_ft_strlen:

	xor rcx, rcx
	not rcx ; ecx = -1
	xor al, al
	cld
	repne scasb ; ecx = -strlen - 2
	not rcx ; reversing all bits of a negative number results in its absolute value - 1 (ecx = strlen + 1)
	dec rcx
	mov rax, rcx
	ret
