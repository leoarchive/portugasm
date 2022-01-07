; Ola, Mundo. compilar em 64-bit, apenas Linux.
; Compilar:
; 	  
;	  ptasm -felf64 example1.asm
;     nasm -felf64 example1.asm && ld example1.o && ./a.out

SECAO_DE_DADOS
mensagem 1BYTE "Ola, Mundo!", 10 ; 10 é o valor para nova linha

SECAO_DE_TEXTO
GLOBAL principal
principal:   
	MOVER rax <- 1          
    MOVER rdi <- 1            
    MOVER rsi <- mensagem     
    MOVER rdx <- 13         
    CHAMADA_SISTEMA                  
    MOVER rax <- 60       
    XOR rdi <- rdi     
    CHAMADA_SISTEMA
