
@Name : yuhang lian
@PID  : A91018743
.syntax unified

.text

.align 3
.global codeToBinary
.func codeToBinary, codeToBinary
.type codeToBinary, %function

@void codeToBinary(FILE *in, FILE *out, int index);

codeToBinary:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
	cmp r0,#0
	beq return
	cmp r1,#0
	beq return
	cmp r2,#0
	blt return
	cmp r2,#8
	bge return
	mov r4,r0
	mov r5,r1
	mov r6,r2
	loop:
		mov r0,r4 @move the in file
		bl feof
		cmp r0,#1 @check if it is the end
		beq return
		mov r0,r4 
		bl fgetc
		mov r7,r0 @r7 = char
		mov r1,r6 @r1 = index
		bl extractBit
		cmp r0,#0
		beq zero
		mov r0,#49
		mov r1,r5
		bl fputc
		bl loop
	zero:
		mov r0,#48
		mov r1,r5
		bl fputc
		bl loop

return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
