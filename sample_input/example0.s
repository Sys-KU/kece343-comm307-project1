	.data
data1:	.word	100
	.text
main:
	la	x5, data1
	la	x6, data1
	add	x10, x5, x6
	sub	x11, x5, x6