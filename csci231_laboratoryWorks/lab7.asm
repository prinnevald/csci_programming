.data
	base: .word
	exponent: .word
	intro_1: .asciiz "enter a base:\n"
	intro_2: .asciiz "enter an exponent:\n"
	outro: .asciiz "the result is:\n"
.text

	li $v0, 4
	la $a0, intro_1
	syscall

	li $v0, 5
	syscall
	move $t0, $v0

	li $v0, 4
	la $a0, intro_2
	syscall

	li $v0, 5
	syscall
	move $t1, $v0
	
	move $a0, $t0
	move $a1, $t1

	jal initpow
	
	initpow:
	    addi $a2, $zero, 1
		beq $a1, $zero, exit
		jal pow
		j exit

	pow:
		beq $a1, $zero, exitpow
		subi $a1, $a1, 1
		
		addi $sp, $sp, -4
		sw $ra, 0($sp)
		
		mul $a2, $a2, $a0
		
		jal pow


	exitpow:
		addi $sp, $sp, 4
		lw $ra, 0($sp)
		jr $ra
		
	
	exit:
		li $v0, 4
		la $a0, outro
		syscall
		
		li $v0, 1
		move $a0, $a2
		syscall
	
		li $v0, 10
		syscall
		
.ktext 0x80000180

	#put exception code here
