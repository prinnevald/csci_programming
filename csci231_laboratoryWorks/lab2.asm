.data
	arr: .word 21 20 51 83 20 20
	length: .word 6
	x: .word 20
	y: .word 5
	sp: .asciiz " "
.text
	la $s0, arr
	lw $s1, length
	li $s2, 0
	lw $s3, x
	lw $s4, y
	la $s5, 0($s0)
main:
	beq $s2, $s1, exit
	lw $t1, 0($s5)
	
	bne $t1, $s3, print
	sw $s4, 0($s5)
	
	j print
print:
	li $v0, 1
	lw $t0, 0($s5)
	move $a0, $t0
	syscall
	
	li $v0, 4
	la $a0, sp
	syscall
	
	addi $s2, $s2, 1
	addi $s5, $s5, 4
	
	j main
exit:
	li $v0, 10
	syscall
