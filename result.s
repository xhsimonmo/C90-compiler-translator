	.set noreorder
	.text
	.align 2
	.globl f
f:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-96
nop
nop
li $2,1
sw $2,-4($30)
move $4,$2
li $2,2
sw $2,-8($30)
move $5,$2
li $2,3
sw $2,-12($30)
move $6,$2
li $2,4
sw $2,-16($30)
move $7,$2
li $2,5
sw $2,-20($30)
sw $2,16($29)
jal g
nop
#////////ending current frame//////
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
