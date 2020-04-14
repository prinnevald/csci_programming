.data
	n: .word 6
.text
	lw $a0, n
	li $v0, 1
main:
	jal fibonacci
	syscall
	j exit
fibonacci:
	beq $a0, $zero, fibexit

	li $t0, 0
	li $t1, 1
	li $t2, 2
	
	loop:
		add $t3, $t0, $t1
		move $t0, $t1
		move $t1, $t3 
		
		addi $t2, $t2, 1
		bne $t2, $a0, loop

	move $a0, $t1
	jr $ra
fibexit:
	addi $a0, $a0, 0
	syscall
	j exit
exit:
	la $v0, 10
	syscall