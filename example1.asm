; Ola, Mundo. compilar em 64-bit, apenas Linux.
; Compilar:
; 	  
; ptasm -felf64 example1.asm
; nasm -felf64 example1.asm && ld example1.o && ./a.out

secao_dados
mensagem 1byte "Ola, Mundo!", 10 ; 10 é o valor para nova linha

secao_texto
GLOBAL principal
principal:   
    mover rax <- 1          
    mover rdi <- 1            
    mover rsi <- mensagem     
    mover rdx <- 13         
    chamadasis
    mover rax <- 60       
    xor rdi <- rdi     
    chamadasis
