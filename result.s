	.set noreorder
	.text
	.align 2
	.globl main
main:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-20
addiu $29,$29,-100
nop
#result_offset in init_declarator: 0
#get a primary expression as number : 1
li $2,1
sw $2,-8($30)
sw $2,0($30)
lw $2,0($30)
nop
sw $2,-12($30)
#get a primary expression as number : 2
li $2,2
sw $2,-16($30)
lw $3,-16($30)
nop
lw $2,-12($30)
nop
sll $2,$2,3
sw $2,-20($30)
lw $2,0($30)
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
