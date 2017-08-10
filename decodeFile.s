@Name : yuhang lian
@PID  : A91018743

.syntax unified

.text

.align 3
.global decodeFile
.func decodeFile, decodeFile
.type decodeFile, %function
mode1: .asciz "r"
mode2: .asciz "w"


@ void decodeFile(char *input, char *bin, char * output, int index)
decodeFile:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
	mov r4,r0	@r4 = input
	mov r5,r1	@r5 = bin
	mov r6,r2	@r6 = output
	mov r7,r3	@r7 = index
	mov r8,r5	@r8 = bin 
	cmp r0,#0
	beq end
	cmp r1,#0
	beq end
	cmp r2,#0
	beq end
	mov r0,r4
	ldr r1,=mode1
	bl fopen
	mov r4,r0	@r4 = inputFile
	mov r0,r5
	ldr r1,=mode2	
	bl fopen	
	mov r5,r0	@r5 = binFile
	mov r0,r4
	mov r1,r5
	mov r2,r7
	bl codeToBinary	
	mov r0,r4
	bl fclose
	mov r0,r5
	bl fclose
	mov r0,r8
	ldr r1,=mode1
	bl fopen
	mov r4,r0	@r4 = new inputfile
	mov r0,r6
	ldr r1,=mode2
	bl fopen	
	mov r6,r0	@r6 = outputFile
	mov r0,r4
	mov r1,r6
	bl binaryToText
	mov r0,r4
	bl fclose
	mov r0,r6
	bl fclose
	bl return
	end:
		pop {r4-r11,ip,lr}
		bx lr
return:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
