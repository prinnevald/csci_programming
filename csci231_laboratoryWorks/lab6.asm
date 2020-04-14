.data
	arr: .asciiz "You typed wrong numbers!\n"
	arr2: .asciiz "enter a number "
.text
	main:

    	li $v0, 4
    	la $a0, arr2
    	syscall
		
		li $v0, 5
		syscall
		move $t0, $v0
		
    	li $v0, 4
    	la $a0, arr2
    	syscall		
		
		li $v0, 5
		syscall
		move $t1, $v0
		
		li $v0, 1
		add $a0, $t0, $t1
		syscall
	
		li $v0, 10
		syscall
		
.ktext 0x80000180

    li $v0, 4
    la $a0, arr
    syscall
    
	la $k0, main
	mtc0 $k0, $14
	
	eret
