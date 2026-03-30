	.data
data1:	.word	100
data2:	.word	200
data3:	.word	0x12345678
	.text
main:
	and	x17, x17, x0
	and	x18, x18, x0
	la	x8, data1
	la	x9, data2
	and	x10, x10, x0
lab1:
	and	x11, x11, x0
lab2:
	addi	x17, x17, 0x1
	addi	x11, x11, 0x1
	or	x9, x9, x0
	bne	x11, x8, lab2
lab3:
	addi	x18, x18, 0x2
	addi	x11, x11, 1
	slli	x18, x17, 1
	srli	x17, x18, 1
	and	x19, x17, x18
	bne	x11, x9, lab3
lab4:
	add	x5, x5, x31
	or	x16, x17, x18
	xori	x16, x16, -1
	beq	x10, x8, lab5
	jal	x0, lab1
lab5:
	lui	x6, 0xf
	addi	x6, x6, 0xf0
	or	x16, x16, x6