	.data
data1:	.word	0x12c
data2:	.word	0xc8
	.text
main:
	and	x10, x10, x0
	and	x11, x11, x0
	la	x8, data1
	la	x9, data2
	addi	x10, x10, 0x1
	slli	x10, x10, 1
	slli	x11, x11, 1
loop:
	addi	x10, x10, 0x1
	addi	x11, x11, 1
	or	x9, x9, x0
	sub	x18, x18, x10
	slli	x18, x17, 1
	slli	x17, x18, 1
	add	x11, x11, x31
	or	x16, x17, x18
	xori	x16, x16, -1
	bne	x11, x8, loop
	jal	x0, exit
exit:
	andi	x15, x15, 0x0f
