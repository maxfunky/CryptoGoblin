	mov	 QWORD PTR [rsp+24], rbx
	push	 rbp
	push	 rsi
	push	 rdi
	push	 r12
	push	 r13
	push	 r14
	push	 r15
	sub	 rsp, 80

	stmxcsr DWORD PTR [rsp]
	mov DWORD PTR [rsp+4], 24448
	ldmxcsr DWORD PTR [rsp+4]

	mov	 rax, QWORD PTR [rcx+48]
	mov	 r9, rcx
	xor	 rax, QWORD PTR [rcx+16]
	mov	 esi, 524288
	mov	 r8, QWORD PTR [rcx+32]
	mov	 r13d, -2147483647
	xor	 r8, QWORD PTR [rcx]
	mov	 r11, QWORD PTR [rcx+40]
	mov	 r10, r8
	mov	 rdx, QWORD PTR [rcx+56]
	movd	 xmm4, rax
	xor	 rdx, QWORD PTR [rcx+24]
	xor	 r11, QWORD PTR [rcx+8]
	mov	 rbx, QWORD PTR [rcx+224]
	mov	 rax, QWORD PTR [r9+80]
	xor	 rax, QWORD PTR [r9+64]
	movd	 xmm0, rdx
	mov	 rcx, QWORD PTR [rcx+88]
	xor	 rcx, QWORD PTR [r9+72]
	movq	 xmm3, QWORD PTR [r9+104]
	movaps	 XMMWORD PTR [rsp+64], xmm6
	movaps	 XMMWORD PTR [rsp+48], xmm7
	movaps	 XMMWORD PTR [rsp+32], xmm8
	and	 r10d, 2097136
	movd	 xmm5, rax

	xor eax, eax
	mov QWORD PTR [rsp+16], rax

	mov ax, 1023
	shl rax, 52
	movd xmm8, rax
	mov r15, QWORD PTR [r9+96]
	punpcklqdq xmm4, xmm0
	movd	 xmm0, rcx
	punpcklqdq xmm5, xmm0

	ALIGN 8
main_loop_ivybridge:
	movdqu	 xmm6, XMMWORD PTR [r10+rbx]
	lea	 rdx, QWORD PTR [r10+rbx]
	mov	 ecx, r10d
	mov	 eax, r10d
	mov rdi, r15
	xor	 ecx, 16
	xor	 eax, 32
	xor	 r10d, 48
	movd	 xmm0, r11
	movd	 xmm7, r8
	punpcklqdq xmm7, xmm0
	aesenc	 xmm6, xmm7
	movdqu	 xmm1, XMMWORD PTR [rax+rbx]
	movdqu	 xmm0, XMMWORD PTR [r10+rbx]
	paddq	 xmm1, xmm7
	movdqu	 xmm2, XMMWORD PTR [rcx+rbx]
	paddq	 xmm0, xmm5
	paddq	 xmm2, xmm4
	movdqu	 XMMWORD PTR [rcx+rbx], xmm0
	movd	 rcx, xmm3
	movdqu	 XMMWORD PTR [rax+rbx], xmm2
	mov	 rax, rcx
	movdqu	 XMMWORD PTR [r10+rbx], xmm1
	shl	 rax, 32
	xor	 rdi, rax
	movd	 rbp, xmm6
	movdqa	 xmm0, xmm6
	pxor	 xmm0, xmm4
	mov	 r10, rbp
	and	 r10d, 2097136
	movdqu	 XMMWORD PTR [rdx], xmm0
	xor	 rdi, QWORD PTR [r10+rbx]
	lea	 r14, QWORD PTR [r10+rbx]
	mov	 r12, QWORD PTR [r10+rbx+8]
	xor	 edx, edx
	lea	 r9d, DWORD PTR [ecx+ecx]
	add	 r9d, ebp
	movdqa	 xmm0, xmm6
	psrldq	 xmm0, 8
	or	 r9d, r13d
	movd	 rax, xmm0
	div	 r9
	mov	 eax, eax
	shl	 rdx, 32
	add	 rdx, rax
	lea	 r9, QWORD PTR [rdx+rbp]
	mov r15, rdx
	mov	 rax, r9
	shr	 rax, 12
	movd	 xmm0, rax
	paddq	 xmm0, xmm8
	sqrtsd	 xmm3, xmm0
	movd	 rdx, xmm3
	test	 rdx, 524287
	je	 sqrt_fixup_ivybridge
	psrlq	 xmm3, 19
	psubq	 xmm3, XMMWORD PTR [rsp+16]
sqrt_fixup_ivybridge_ret:

	mov	 r9, r10
	mov	 rax, rdi
	mul	 rbp

	xor	 r9, 16
	mov	 rcx, r10
	xor	 rcx, 32
	xor	 r10, 48
	add	 r8, rdx
	add	 r11, rax
	movdqu	 xmm0, XMMWORD PTR [r10+rbx]
	movdqu	 xmm2, XMMWORD PTR [r9+rbx]
	paddq	 xmm0, xmm5
	movdqu	 xmm1, XMMWORD PTR [rcx+rbx]
	paddq	 xmm2, xmm4
	paddq	 xmm1, xmm7
	movdqa	 xmm5, xmm4
	movdqu	 XMMWORD PTR [r9+rbx], xmm0
	movdqa	 xmm4, xmm6
	movdqu	 XMMWORD PTR [rcx+rbx], xmm2
	movdqu	 XMMWORD PTR [r10+rbx], xmm1
	mov	 QWORD PTR [r14], r8
	xor	 r8, rdi
	mov	 r10, r8
	mov	 QWORD PTR [r14+8], r11
	and	 r10d, 2097136
	xor	 r11, r12
	dec rsi
	jne	 main_loop_ivybridge

	ldmxcsr DWORD PTR [rsp]
	mov	 rbx, QWORD PTR [rsp+160]
	movaps	 xmm6, XMMWORD PTR [rsp+64]
	movaps	 xmm7, XMMWORD PTR [rsp+48]
	movaps	 xmm8, XMMWORD PTR [rsp+32]
	add	 rsp, 80
	pop	 r15
	pop	 r14
	pop	 r13
	pop	 r12
	pop	 rdi
	pop	 rsi
	pop	 rbp
	jmp cnv2_main_loop_ivybridge_endp

sqrt_fixup_ivybridge:
	dec	 rdx
	mov  r13, -4389456576512
	mov	 rax, rdx
	shr	 rdx, 19
	shr	 rax, 20
	mov	 rcx, rdx
	sub	 rcx, rax
	add	 rax, r13
	mov  r13, 4389456576511
	sub	 rcx, r13
	mov	 r13d, -2147483647
	imul	 rcx, rax
	sub	 rcx, r9
	adc	 rdx, 0
	movd	 xmm3, rdx
	jmp	 sqrt_fixup_ivybridge_ret

cnv2_main_loop_ivybridge_endp: