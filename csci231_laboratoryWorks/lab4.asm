.data
	arr: .asciiz "Hello"
	length: .word 5

.text
	la $a0, arr
	lw $s0, length
	addi $s0, $s0, -1
	add $a1, $a0, $s0

main:
	
    jal flipper

    li $v0, 4
    la $a0, arr
    syscall

    j exit

flipper:
	
	saving:
		
		lb $t0, 0($a1)
		lb $t2, 0($a0)
		sb $t2, 0($a1)
		sb $t0, 0($a0)
		
		addi $a0, $a0, 1
		addi $a1, $a1, -1
				
		slt	$t1, $a0, $a1
		bne $t1, $zero, saving
	
	jr $ra

exit:
	li $v0, 10
	syscall
