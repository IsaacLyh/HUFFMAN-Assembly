@Name : yuhang lian
@PID  : A91018743

.syntax unified

.text

.align 3
.global binaryToText
.func binaryToText, binaryToText
.type binaryToText, %function

@ void binaryToText(FILE *in, FILE *out)
binaryToText:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
	cmp r0,#0
	beq isNull
	cmp r1,#0
	beq isNull	@null check
	mov r4,r0
	mov r5,r1
	mov r0,#6
	bl malloc
	cmp r0,#0
	beq isNull
	mov r6,r0
	mov r7,#0
	loop:
		mov r0,r4
		bl feof
		cmp r0,#0
		bne return
		cmp r7,#6
		beq else
		mov r0,r4   @mov the value in r4 to r0
		bl fgetc
		cmp r0,#49
		bne zero
		mov r9,#49
		str r9,[r6,r7]
		add r7,r7,#1
		bl loop
	zero:
		mov r9,#48      @mov in r9 the required val
		str r9,[r6,r7]
		add r7,r7,#1
		bl loop     @enter the loop
	else:
		mov r0,r6
		bl decodeChar       @call decodeChar
		mov r1,r5
		bl fputc
		mov r7,#0
		bl loop

	isNull:
                    @RETURN IF ITS NULL
	return:
    	@ restore caller's registers
    	pop {r4-r11, ip, lr}

    	@ ARM equivalent of return
    	BX lr
.endfunc

.end
