.data
	arr: .asciiz "fedcba"
	length: .word 6

.text
	la $a0, arr
	lw $s0, length
	add $a1, $a0, $s0
	move $a3, $a1

sorter:
	loop1:
		loop2:
			addi $a1, $a1, -1
			lb $t3, 0($a1)
			lb $t2, 0($a0)
			
			slt $t0, $t2, $t3
			beq $zero, $t0, swap
			ret:

			slt	$t1, $a0, $a1
			bne $t1, $zero, loop2

		move $a1, $a3
		slt $t0, $a0, $a3
		beq $zero, $t0, exit
		addi $a0, $a0, 1
		j loop1

swap:
	sb $t2, 0($a1)
	sb $t3, 0($a0)
	j ret	

exit:
    li $v0, 4
    la $a0, arr
    syscall
    
	li $v0, 10
	syscall