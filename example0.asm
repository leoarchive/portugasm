secao_dados
num1 1byte 30 
num2 1byte 70
num3 1byte 99
soma 1byte 00
subtracao 1byte 00

secao_texto
global principal
principal:
    mover eax <- [num1]
    mover ebx <- [num2]
    mover ecx <- [num3]
    adicionar eax <- ebx
    mover [soma] <- eax
    subtrair eax <- ecx 
    mover [subtracao] <- eax
    mover eax <- 0
    retornar 
