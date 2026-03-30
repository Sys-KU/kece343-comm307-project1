	.data
data1:	.word	100
data2:	.word	200
data3:	.word	0x12345678
	.word	0x12341
	.text
main:
	lui	x3, 0x10000
	lw	x5, 0(x3)
	lw	x8, 4(x3)
	lw	x9, 8(x3)
	lw	x10, 12(x3)
	addi	x5, x5, 24
	addi	x6, x0, 124
	add	x7, x5, x6
	sw	x5, 16(x3)
	sw	x6, 20(x3)
	sw	x7, 24(x3)
	addi	x3, x3, 12
	lw	x12, -4(x3)
	lw	x13, -8(x3)
	lw	x14, -12(x3)