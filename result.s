main:
addiu $29,$29,-12
sw $30,4($29)
addiu $29,$29,-16
sw $31,8($29)
move $29,$30
move $29,$30
lw $31,8($29)
nop
lw $30,4($29)
nop
addiu $29,$29,12
j $31
nop
