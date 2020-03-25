	.set noreorder
	.text
	.align 2
	.globl main
main:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-32
addiu $29,$29,-208
nop
li $2,100
sw $2,-8($30)
sw $2,0($30)
li $2,200
sw $2,-16($30)
sw $2,-4($30)
li $2,10
sw $2,-24($30)
sw $2,-8($30)
li $2,20
sw $2,-32($30)
lw $2,-8($30)
nop
sw $2,-36($30)
lw $3,-36($30)
nop
lw $2,-32($30)
nop
add $2,$2,$3
sw $2,-40($30)
lw $2,0($30)
nop
sw $2,-44($30)
lw $3,-44($30)
nop
lw $2,-40($30)
nop
add $2,$2,$3
sw $2,-48($30)
lw $2,-4($30)
nop
sw $2,-52($30)
lw $3,-52($30)
nop
lw $2,-48($30)
nop
add $2,$2,$3
sw $2,-56($30)
sw $2,-12($30)
lw $2,-12($30)
nop
sw $2,-60($30)
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
