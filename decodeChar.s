@Name : yuhang lian
@PID  : A91018743

.syntax unified

.text

.align 3
.global decodeChar
.func decodeChar, decodeChar
.type decodeChar, %function

@ char decodeChar(char *b)
decodeChar:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    cmp r0,#0	@check for null
    beq end	@if so end
    mov r4,#0	@clear r4
    ldrb r4,[r0]
    mov r10,#32
    mul r4,r4,r10
    ldrb r5,[r0,#1]
    mov r10,#16
    mul r5,r5,r10
    ldrb r6,[r0,#2]
    mov r10,#8      @MOV 8 IN TO R8
    mul r6,r6,r10
    ldrb r7,[r0,#3]
    mov r10,#4
    mul r7,r7,r10
    ldrb r8,[r0,#4]
    mov r10,#2
    mul r8,r8,r10
    ldrb r9,[r0,#5]
    mov r10,#1
    mul r9,r9,r10   @FIND THE REQUIRED NUMBER
    add r4,r4,r5
    add r4,r4,r6
    add r4,r4,r7
    add r4,r4,r8
    add r4,r4,r9
    mov r10,#0
    ldr r10,=MAPPING    @LOAD THE MAPPING
    bl return
end:
    pop {r4-r11,ip,lr}
    bx lr

return:
    ldrb r0,[r10,r4]
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
