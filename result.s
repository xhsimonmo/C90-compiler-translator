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
	.set noreorder
	.text
	.align 2
	.globl g
g:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-36
nop
sw $4,12($30)
nop
lw $2,12($30)
nop
sw $2,-8($30)
#////////ending current frame//////
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
	.set noreorder
	.text
	.align 2
	.globl main
main:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-88
nop
nop
#result_offset in init_declarator: 0
#get a primary expression as number : 1
li $2,1
sw $2,-8($30)
sw $2,0($30)
#result_offset in init_declarator: -8
#get a primary expression as number : 2
li $2,2
sw $2,-16($30)
sw $2,-8($30)
lw $2,0($30)
nop
sw $2,-20($30)
move $4,$2
jal g
nop
move $5,$2
lw $2,-8($30)
nop
sw $2,-24($30)
move $6,$2
jal f
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
