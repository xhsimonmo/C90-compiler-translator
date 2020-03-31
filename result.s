	.set noreorder
	.text
	.align 2
	.globl g
g:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-388
addiu $29,$29,-404
nop
sw $4,12($30)
nop
lw $2,12($30)
nop
sw $2,-8($30)
b switchcondition2
lw $2,12($30)
nop
Label2:
li $2,1
sw $2,-12($30)
li $2,10
sw $2,-16($30)
#////////ending current frame//////
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
nop
Label4:
li $2,2
sw $2,-8($30)
li $2,11
sw $2,-12($30)
#////////ending current frame//////
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
nop
switchcondition2:
li $3,1
beq $2,$3,Label2
nop
li $3,2
beq $2,$3,Label4
nop
end_switch2:
