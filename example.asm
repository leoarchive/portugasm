SECAO .dados
num1 DD 30 
num2 DD 70
num3 DD 99
soma DD 00
subtracao DD 00

SECAO .texto 
GLOBAL main
main:
    MOVER EAX, [num1] 
    MOVER EBX, [num2]
    MOVER ECX, [num3]
    ADICIONAR EAX, EBX
    MOVER [soma], EAX
    SUBTRAIR EAX, ECX 
    MOVER [subtracao], EAX
    MOVER EAX, 0
    RETORNAR 
