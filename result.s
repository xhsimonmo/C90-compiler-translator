	.set noreorder
	.text
	.align 2
	.globl f
f:
addiu $29,$29,-12
sw $30,4($29)
sw $31,8($29)
move $30,$29
addiu $29,$29,-228
nop
nop
#In Iteration!
#it's a for loop!
lw $2,-4($30)
nop
sw $2,-12($30)
li $2,0
sw $2,-16($30)
nop
sw $2,-4($30)
for_start6:
b statement1
nop
for_state3:
label7:
lw $2,-4($30)
nop
sw $2,-20($30)
lw $2,-4($30)
nop
sw $2,-24($30)
li $2,1
sw $2,-28($30)
#load right index from memory
lw $3,-28($30)
nop
#load left index from memory
lw $2,-24($30)
nop
#additive expression
add $2,$2,$3
sw $2,-32($30)
nop
sw $2,-4($30)
b for_start6
statement1:
lw $2,-4($30)
nop
sw $2,-36($30)
li $2,1
sw $2,-40($30)
#load right index from memory
lw $3,-40($30)
nop
#load left index from memory
lw $2,-36($30)
nop
slt $2,$2,$3
sw $2,-44($30)
bne $2,$0,for_state3
nop
for_end5:
lw $2,-4($30)
nop
sw $2,-48($30)
li $2,19937
sw $2,-52($30)
#load right index from memory
lw $3,-52($30)
nop
#load left index from memory
lw $2,-48($30)
nop
#additive expression
add $2,$2,$3
sw $2,-56($30)
#////////ending current frame//////
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
