.data
message:
        .asciz "Move disk %d from peg %c to peg %c\n"
.text

.global tower_s
.func tower_s
        
tower_s:
        sub sp, sp, #16
        str lr, [sp]
        str r0, [sp, #4]
        strb r1, [sp, #8]
        strb r2, [sp, #9]
        strb r3, [sp, #10]
        cmp r0, #1
        bne rec_start
        ldr r1, [sp, #4]
        ldrb r2, [sp, #8]
        ldrb r3, [sp, #9]
        ldr r0, =message
        bl printf
        b tower_s_end
rec_start:
        ldr r0, [sp, #4]                /* start first recursion */
        sub r0, r0, #1
        ldrb r1, [sp, #8]
        ldrb r2, [sp, #10]
        ldrb r3, [sp, #9]
        bl tower_s
        ldr r1, [sp, #4]
        ldrb r2, [sp, #8]
        ldrb r3, [sp, #9]
        ldr r0, =message
        bl printf
        ldr r0, [sp, #4]                /* start second recursion */
        sub r0, r0, #1
        ldrb r1, [sp, #10]
        ldrb r2, [sp, #9]
        ldrb r3, [sp, #8]
        bl tower_s
tower_s_end:
        ldr lr, [sp]
        add sp, sp, #16
        bx lr
.endfunc
        
.global printf
