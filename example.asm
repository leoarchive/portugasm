secao_dados
num1 1byte 30 
num2 1byte 70
num3 1byte 99
soma 1byte 00
subtracao 1byte 00

secao_texto
global principal
principal:
    mover eax <- dados.num1 
    mover ebx <- dados.num2
    mover ecx <- dados.num3
    adicionar eax <- ebx
    MOVER dados.soma <- eax
    subtrair eax <- ecx 
    mover dados.subtracao <- eax
    mover eax <- 0
    retornar 
