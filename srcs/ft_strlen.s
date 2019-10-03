SECTION .text

_ft_strlen:

	xor rbx rbx
	jz end

end:
	mov rax, rbx
	ret
