# Simulação simplificada da estação de controle da Skyrats

import math as np

def main():
    print("Simulador de Drones Skyrats")
    drone = input("Qual drone voce esta usando? ")
    global posicao
    global altura
    posicao = float(input("Posição inicial: "))
    altura = float(input("Altura inicial: "))
    armado = False 
    voando = False
    escolha = 0
    while escolha != 5:
        print("O que voce quer fazer com o drone?")
        print("1) Armar o drone")
        print("2) Decolar o drone")
        print("3) Mudar a posição do drone")
        print("4) Pousar o drone")
        print("5) Sair")
        escolha = int(input(""))

    if escolha == 1:
        armar(drone, armado, voando)
    elif escolha == 2:
        decolar(drone, armado, voando)
    elif escolha == 3:
        mudar_posicao(drone, armado, voando)
    elif escolha == 4:
        pousar(drone, armado, voando)
    else:
        return 0



    
main()

def armar(drone, armado, voando):
    print(drone)
    print(" armado com sucesso!")
    return armado == True
    
def decolar(drone, armado, voando):
    if armado == False:
        print(drone)
        print(" precisa ser armado antes de decolar!")
        return False
    if voando == True:
        print(drone)
        print(" ja esta voando")
        return True
    if armado == True and altura == 0:
        altura = int(input("Para qual altura voce quer que seu drone decole? "))
        print(altura)
        return altura


def mudar_posicao(drone, armado, voando):
    if voando == False:
        print(drone)
        print(" precisa ser decolado antes de mudar de posicao")
        return
    else:
        print("Posicao atual: (%f,%f)" % (posicao, altura))
        print("Qual posicao voce quer ir?")
        posicao = input("Posicao desejada: ")
        altura = input("Altura desejada:")
        velocidade = input("Velocidade do drone: ")

    for i in range (0, )


def pousar(drone, armado, voando):


