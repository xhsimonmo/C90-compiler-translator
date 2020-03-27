	.set noreorder
	.text
	.align 2
	.globl main
main:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-24
addiu $29,$29,-88
nop
nop
#result_offset in init_declarator: 0
#get a primary expression as number : 2
li $2,2
sw $2,-8($30)
sw $2,0($30)
#result_offset in init_declarator: -8
lw $2,0($30)
nop
sw $2,-16($30)
li $2,8
sw $2,-20($30)
sw $2,-8($30)
lw $2,-8($30)
nop
sw $2,-24($30)
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
