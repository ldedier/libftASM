section .text

global _ft_atoi

extern _ft_isdigit

_ft_iswhitespace:

	xor eax, eax
	cmp edi, 09h
	jz .is_whitespace
	cmp edi, 0ah
	jz .is_whitespace
	cmp edi, 20h
	jz .is_whitespace
	ret

.is_whitespace:
	mov eax, 1
	ret

_ft_atoi:

	sub rsp, 8
	mov rsi, rdi
	xor rdi, rdi
.skip_spaces:

	mov byte dil, [rsi]
	call _ft_iswhitespace
	cmp rax, 1
	jne .skipped_spaces
	inc rsi
	jmp .skip_spaces

.skipped_spaces:
	add rsp, 8
	push rsi
	mov r11d, '+' 
	cmp [rsi], r11b
	je .inc_sign
	mov r11d, '-' 
	cmp [rsi], r11b
	je .inc_sign
	jmp .fill_res

.inc_sign:
	inc rsi
.fill_res:
	xor rdi, rdi
	xor rdx, rdx
.fill_loop:
	mov byte dil, [rsi]
	call _ft_isdigit
	cmp rax, 1
	je .process_fill_loop
	jmp .add_sign

.process_fill_loop:
	
	imul rdx, 10
	sub dil, '0'
	add rdx, rdi
	inc rsi
	jmp .fill_loop

.add_sign:

	pop rsi

	mov r11d, '-'
	cmp [rsi], r11b
	je .negate_ret
	jmp .end

.negate_ret:
	not rdx
	add rdx, 1
.end:
	mov rax, rdx
	ret
