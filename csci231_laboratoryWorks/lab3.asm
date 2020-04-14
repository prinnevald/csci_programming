.data
	arr: .word 21 20 51 83 20 20
	length: .word 6
	x: .word 20
	y: .word 5
	sp: .asciiz " "
	nl: .asciiz "\n"

.text
	la $s0, arr
	lw $s1, length
	li $s2, 0
	lw $s3, x
	lw $s4, y
	la $s5, 0($s0)

main:

	addi $s6, $s6, 1
	la $s5, 0($s0)

	jal print_procedure

	jal fullchange

	li $v0, 4
	la $a0, nl
	syscall

	jal print_procedure

    j exit

print_procedure:
	addi $sp, $sp, -4
	sw $s2, 0($sp)
	
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
		
		bne $s2, $s1, print 
	
	la $s5, 0($s0)
	lw $s2, 0($sp)
	addi $sp, $sp, 4
	
	jr $ra

fullchange:

	addi $sp, $sp, -4
	sw $s2, 0($sp)
	
	changeloop:
		lw $t0, 0($s5)
		beq $t0, $s3, replaceone
		
		ret:
		addi $s2, $s2, 1
		addi $s5, $s5, 4
		
		bne $s2, $s1, changeloop
	
	la $s5, 0($s0)
	lw $s2, 0($sp)
	addi $sp, $sp, 4
	
	jr $ra

replaceone:
	sw $s4, 0($s5)
	j ret

exit:
	li $v0, 10
	syscall
