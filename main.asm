section .data
    hello db 'Hello, World!', 0

section .text
    global _start

_start:
    ; Write "Hello, World!" to stdout (file descriptor 1)
    mov eax, 4         ; syscall number for sys_write
    mov ebx, 1         ; file descriptor for stdout
    mov ecx, hello     ; pointer to the message to write
    mov edx, 13        ; length of the message
    int 0x80           ; execute the syscall

    ; Exit the program
    mov eax, 1         ; syscall number for sys_exit
    xor ebx, ebx       ; exit code 0
    int 0x80           ; execute the syscall

