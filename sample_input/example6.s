	.data
sum:	.word	0x1000000
data1:	.word	0x10
data2:	.word	0x100
iter:	.word	0x1
	.text
main:
	addi	x29, x29, -8
	sw	x30, 4(x29)
	add	x30, x29, x0
	jal	x0, loop1
loop3:
	la	x2, sum
	sltiu	x2, x2, 3
	bne	x2, x0, loop2
	la	x2, sum
	srli	x3, x2, 1
	sw	x2, 0(x2)
loop2:
	la	x2, iter
	addi	x3, x2, 1
	sw	x3, 0(x2)
loop1:
	la	x2, iter
	sltiu	x2, x2, 10
	bne	x2, x0, loop3
	add	x2, x2, x0
	add	x29, x30, x0
	lw	x30, 4(x29)
	addi	x29, x29, 8
