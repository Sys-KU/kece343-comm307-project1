	.data
	.text
main:
	add	x2, x4, x5
	add	x2, x6, x7
	sub	x9, x3, x2
lab1:
	and	x11, x11, x0
	addi	x10, x10, 0x1
	or	x6, x6, x0
	jal	x1, lab3
lab3:
	slli	x7, x6, 2
	srli	x5, x4, 2
	sltiu	x9, x10, 100
	beq	x9, x0, lab4
	jalr	x0, 0(x1)
lab4:
	sltu	x4, x2, x3
	bne	x4, x0, lab5
	jal	x0, lab1
lab5:
	lui	x17, 0xf
	addi	x17, x17, 0xf0
	or	x16, x16, x17
