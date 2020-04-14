.data
	array: .space 1024
.text
#Number of blocks: 1
#Cache block size: 32
#YOUR METRIC SCORE: 17408

#The reasons for my optimisation

#In Assembly code:
# I did not add unnecessary stuff, because it accesses memory
#In the configuration of cahce parameters:
#just picked best configuration6

la $s0, array
li $s1, 1024
li $s2, 1

	loop:
		sb $s2, 0($s0)
		addi $s0, $s0, 4
		subi $s1, $s1, 1			
		bne $zero, $s1, loop

la $v0, 10
syscall
