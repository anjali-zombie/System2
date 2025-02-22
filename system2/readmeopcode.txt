 Name:- Anjali
 Roll Number :- 23111004

FOLLOWING IS THE README FILE FOR  OPCODE TABLE GENERATED VIA INSTRUCTION ADDRESSES:

we cosidered 12 instructions i.e mov,add,sub,mul,div,cmp,xor,jmp,jnz,jz,inc,dec
where mov contains 5 possible instructions: mov reg,reg
                                            mov reg , imm
					    mov reg , [mem]
					    mov [mem] , imm
					    mov [mem] , reg

and add , sub , cmp , xor contains 7 possible instructions :

reg , reg
reg ,imm8
reg ,imm32
reg ,[mem]
[mem] ,imm8
[mem] ,reg
[mem] ,imm32

jmp ,jnz, jz ,inc and dec conatins only one operand

where jmp is : jmp reg
		jmp imm8
		jmp imm16
		jmp imm32
		jmp [mem]

jnz is :  jnz imm
jn is : jn imm

inc is : inc reg
	 inc [mem]

dec is : dec reg
	 dec [mem]

after writing all this instructions in a file let's say data.asm compile the file writing command "nasm -felf32 data.asm -l p.lst" after compilation write less p.lst it will show address of instruction where they are stored where first first two bit will indicate which instruction it is either mov ,add, sub or mul etc..

this opcode does nothing but help us retrack instruction from given addresses from given opcode codes which we find through help of intel book.

this opcode table contains 9 columns :

which are: opcode , instruction , operand 1 , operand 2 , size , MOD r/m , +rd , no. of args , no. of bytes.

for example :==

mov reg , imm 

for this instruction opcode table is as follows

B8 +rd id , mov , reg , imm , 5, N , Y, 2 , NO COUNT OF " NO. OF BYTES SINCE" , THERE IS NO IMMEDIATE

SIZE = 5 which is no. of bytes
MOD/rm = N because there is no 1 at first byte of innstruction
 + rd = yes because there exist +rd

no. of args = there exist two arguments




