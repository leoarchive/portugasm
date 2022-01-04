SECAO_DE_DADOS
num1 1BYTE 30 
num2 1BYTE 70
num3 1BYTE 99
soma 1BYTE 00
subtracao 1BYTE 00

SECAO_DE_TEXTO
GLOBAL principal
principal:
    MOVER EAX, [num1] 
    MOVER EBX, [num2]
    MOVER ECX, [num3]
    ADICIONAR EAX, EBX
    MOVER [soma], EAX
    SUBTRAIR EAX, ECX 
    MOVER [subtracao], EAX
    MOVER EAX, 0
    RETORNAR 
