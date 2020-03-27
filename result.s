	.set noreorder
	.text
	.align 2
	.globl f
f:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-16
addiu $29,$29,-16
nop
nop
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
#////////ending current frame//////
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
