.data
	src: .asciiz "hello"
	dest: .asciiz
	length: .word 5
.text
	la $a0, src
	lw $t0, length
	add $a1, $a0, $t0
	la $a2, dest
	
main:
	jal strcpy

    li $v0, 4
    la $a0, dest
    syscall

	j exit
strcpy:
	loop:
		lb $t0, 0($a0)
		sb $t0, 0($a2)
		
		addi $a0, $a0, 1
		addi $a2, $a2, 1
		
		bne $a0, $a1, loop
	jr $ra
exit:
	li $v0, 10
	syscall