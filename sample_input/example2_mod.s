	.data
array:	.word	3
	.word	123
	.word	4346
array2:	.word	0x11111111
	.text
main:
	addi	x2, x0, 1024
	add	x3, x2, x2
	or	x4, x3, x2
	slli	x6, x5, 16
	lui	x28, 2
	addi	x28, x28, 0x70F
	add	x7, x6, x28
	sub	x8, x7, x2
	or	x9, x4, x3
	xori	x9, x9, -1
	ori	x10, x2, 255
	srli	x11, x6, 5
	la	x4, array2
	and	x13, x11, x5
	andi	x14, x4, 100
	lui	x17, 0x640
	addi	x2, x0, 0xa