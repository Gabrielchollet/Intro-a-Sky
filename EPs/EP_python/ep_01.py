# Simulação simplificada da estação de controle da Skyrats
import numpy as np


def main():
    print("Simulador de Drones Skyrats")

    drone = input("Qual drone voce esta usando?\n")

    global posicao
    posicao = float(input("Posição inicial: "))

    global altura
    altura = float(input("Altura inicial: "))

    global armado
    armado = False

    global voando
    voando = False

    escolha = 0
    while escolha != 5:
        print("O que voce quer fazer com o drone?")
        print("\t1) Armar o drone")
        print("\t2) Decolar o drone")
        print("\t3) Mudar a posição do drone")
        print("\t4) Pousar o drone")
        print("\t5) Sair")
        escolha = int(input(""))
        if escolha == 1:
            armado = armar(drone, armado, voando)
        elif escolha == 2:
            voando = decolar(drone, armado, voando)
        elif escolha == 3:
            mudar_posicao(drone, armado, voando)
        elif escolha == 4:
            pousar(drone, armado, voando)
        else:
            return 0


def armar(drone, armado, voando):
    # Verificar se o drone foi armado
    if armado == True:
        print("%s já foi armado!" % (drone))
        return True
    else:
        print("%s armado com sucesso!" % (drone))
        armado = True
    return True


def decolar(drone, armado, voando):
    global altura

    # Verificar se o drone foi armado
    if armado == False:
        print("%s precisa ser armado antes de decolar!" % (drone))
        return False

    # Verificar se o drone ja esta voando
    if voando == True:
        print("%s ja esta voando" % (drone))

    # Verificar se o drone esta armado e no chao
    if armado == True and altura == 0:
        altura = float(
            input("Para qual altura voce quer que seu drone decole?\n"))
        print("%s decolado com sucesso para altura %.1f" % (drone, altura))
    return True


def mudar_posicao(drone, armado, voando):
    global posicao
    global altura
    altura_inicial = altura
    posicao_inicial = posicao
    altura_t = altura_inicial
    posicao_t = posicao_inicial
    tempo = 0

    # Verificar se o drone ja foi decolado
    if voando == False:
        print("%s precisa ser decolado antes de mudar de posicao" % (drone))
        return
    #
    else:
        print("Posicao atual: (%.1f,%.1f)" % (posicao, altura))
        print("Qual posicao voce quer ir?")
        posicao = float(input("Posicao desejada: "))
        altura = float(input("Altura desejada: "))
        velocidade = float(input("Velocidade do drone: "))

        # Calcular as componentes do vetor velocidade
        alpha = np.arctan2(altura - altura_inicial, posicao - posicao_inicial)
        vel_x = velocidade * np.cos(alpha)
        vel_y = velocidade * np.sin(alpha)

        # Indicar a posicao e a altura do drone a cada segundo

        while posicao_t < posicao or altura_t < altura:
            print("Posicao no instante t%d: (%f, %f)" %
                  (tempo, posicao_t, altura_t))
            posicao_t += vel_x
            altura_t += vel_y
            tempo += 1

        print(drone, "foi para (%.1f,%.1f) com sucesso!" % (posicao, altura))


def pousar(drone, armado, voando):
    global altura

    # Verificar se o drone esta no chao
    if altura == 0:
        print("%s ja esta no chao" % (drone))
    elif voando == True:
        print("%s pousado com sucesso!" % (drone))
        altura = 0
        voando = False
        armado = False


main()
