<<<<<<< HEAD
	.set noreorder
	.text
	.align 2
	.globl f
f:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-72
nop
sw $4,12($30)
sw $5,16($30)
nop
lw $2,12($30)
nop
sw $2,-12($30)
lw $2,16($30)
nop
sw $2,-16($30)
#load right index from memory
lw $3,-16($30)
nop
#load left index from memory
lw $2,-12($30)
nop
#additive expression
add $2,$2,$3
sw $2,-20($30)
#////////ending current frame//////
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
=======
>>>>>>> 923fb23b72dbc68564ceea88cb58c89d1cef221a
