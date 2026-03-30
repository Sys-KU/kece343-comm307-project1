	.data
data1:	.word	5
data2:	.word	10
	.text
main:
	la	x5, data1
	lw	x6, 0(x5)

	la	x5, data2
	lw	x7, 0(x5)

	blt	x6, x7, lab1
	jal	x0, lab2

lab1:
	bge	x7, x6, lab3
	jal	x0, lab2

lab3:
	addi	x10, x0, 1
	jal	x0, exit

lab2:
	addi	x10, x0, 0

exit:
	jal	x0, exit