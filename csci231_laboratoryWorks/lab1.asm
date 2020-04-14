.data
# creating Fib and its data

Fib: .word 0 1

.text
# loading the adress of Fib

la $s0 Fib

# loading up first two values

lw $t1 Fib
lw $t2 4($s0)

# using the three temp values
# to calculate the next value
# the least will be rewritten
# calculate again and loop

add $t3 $t2 $t1
sw $t3 8($s0)

add $t1 $t2 $t3
sw $t1 12($s0)

add $t2 $t3 $t1
sw $t2 16($s0)

add $t3 $t2 $t1
sw $t3 20($s0)

add $t1 $t2 $t3
sw $t1 24($s0)
