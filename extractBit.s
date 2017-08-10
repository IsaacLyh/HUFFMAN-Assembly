@Name : yuhang lian
@PID  : A91018743

.syntax unified

.text

.align 3
.global extractBit
.func extractBit, extractBit
.type extractBit, %function

@ int extractBit(char c, int index)
extractBit:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    mov r4,r0
    mov r5,r1
    mov r6,#0
    cmp r1,#0
    beq mask1
    cmp r1,#1
    beq mask2
    cmp r1,#2
    beq mask3
    cmp r1,#3   @CHECK WHAT TO USE ON THE GIVEN INDEX
    beq mask4
    cmp r1,#4
    beq mask5
    cmp r1,#5
    beq mask6
    cmp r1,#6
    beq mask7
    cmp r1,#7
    beq mask8
    mask1:
        and r6,r4,0b1
        lsr r6,r6,r5
        bl return
    mask2:
        and r6,r4,0b10
        lsr r6,r6,r5
        bl return
    mask3:
        and r6,r4,0b100
        lsr r6,r6,r5
        bl return
    mask4:
        and r6,r4,0b1000    @MASKS THAT WILL GET REQUIRED INDEX
        lsr r6,r6,r5
        bl return
    mask5:
        and r6,r4,0b10000
        lsr r6,r6,r5
        bl return
    mask6:
        and r6,r4,0b100000
        lsr r6,r6,r5        @BASED ON THE REQUIRED INDEX
        bl return
    mask7:
        and r6,r4,0b1000000
        lsr r6,r6,r5
        bl return               @DIFFERENT MASKS WILL BE CHOSEN
    mask8:
        and r6,r4,0b10000000
        lsr r6,r6,r5
        bl return
return:
    mov r0,r6               @STORE THE VALUE AND RETURN
    @ restore caller's registers
    pop {r4-r11, ip, lr}
    
    @ ARM equivalent of return
    BX lr
.endfunc

.end
