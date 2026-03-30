	.data
data1:	.word	1
data2:	.word	10
	.text
main:
	addi	x29, x29, -24
	sw	x30, 20(x29)
	add	x30, x29, x0
	sw	x0, 8(x30)
loop1:
	lw	x2, 8(x30)
	sltiu	x2, x2, 20
	beq	x2, x0, loop2
	lui	x4, 0x10000
	lw	x2, 0(x4)
	sw	x2, 12(x30)
	lw	x3, 4(x4)
	sw	x3, 0(x4)
	lw	x3, 12(x30)
	sw	x3, 4(x4)
	lw	x2, 8(x30)
	addi	x2, x2, 1
	sw	x2, 8(x30)
	jal	x0, loop1
loop2:
	add	x2, x2, x0
	add	x29, x30, x0
	lw	x30, 20(x29)
	addi	x29, x29, 24