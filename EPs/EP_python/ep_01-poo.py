# Classe: Drone;
# Instãncia: meu_drone;
# Atributos: nome, altura, posicao, velocidade, armado, voando;
# Métodos: armar(), decolar(), mudar_posicao(), pousar();

import numpy as np


def main():
    # Instanciação de um objeto da classe Drone
    meu_drone = Drone(input("Qual drone voce esta usando?\n"), float(
        input("Posição inicial: ")), float(input("Altura inicial: ")), False, False)

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
            meu_drone.armar()
        elif escolha == 2:
            meu_drone.decolar()
        elif escolha == 3:
            meu_drone.mudar_posicao()
        elif escolha == 4:
            meu_drone.pousar()
        else:
            return 0


class Drone:
    def __init__(self, nome, posicao, altura, armado, voando):
        self.nome = nome
        self.posicao = posicao
        self.altura = altura
        self.armado = armado
        self.voando = voando

    def armar(self):
        # Verifica se o drone foi armado
        if self.armado == True:
            print("%s já foi armado!" % (self.nome))
            return True
        else:
            print("%s armado com sucesso!" % (self.nome))
            self.armado = True
        return True

    def decolar(self):
        # Verificar se o drone foi armado
        if self.armado == False:
            print("%s precisa ser armado antes de decolar!" % (self.nome))
            return False

        # Verificar se o drone ja esta voando
        if self.voando == True:
            print("%s ja esta voando" % (self.nome))

        # Verificar se o drone esta armado e no chao
        if self.armado == True and self.altura == 0:
            self.altura = float(
                input("Para qual altura voce quer que seu drone decole?\n"))
            print("%s decolado com sucesso para altura %.1f" %
                  (self.nome, self.altura))
            self.voando = True
        return True

    def mudar_posicao(self):
        altura_inicial = self.altura
        posicao_inicial = self.posicao
        altura_t = altura_inicial
        posicao_t = posicao_inicial
        tempo = 0

        # Verificar se o drone ja foi decolado
        if self.voando == False:
            print("%s precisa ser decolado antes de mudar de posicao" %
                  (self.nome))
            return

        else:
            print("Posicao atual: (%.1f,%.1f)" % (self.posicao, self.altura))
            print("Qual posicao voce quer ir?")
            self.posicao = float(input("Posicao desejada: "))
            self.altura = float(input("Altura desejada: "))
            self.velocidade = float(input("Velocidade do drone: "))

            # Calcular as componentes do vetor velocidade
            alpha = np.arctan2(self.altura - altura_inicial,
                               self.posicao - posicao_inicial)
            vel_x = self.velocidade * np.cos(alpha)
            vel_y = self.velocidade * np.sin(alpha)

            # Indicar a posicao e a altura do drone a cada segundo

            while posicao_t < self.posicao or altura_t < self.altura:
                print("Posicao no instante t%d: (%f, %f)" %
                      (tempo, posicao_t, altura_t))
                posicao_t += vel_x
                altura_t += vel_y
                tempo += 1

            print("%s foi para (%.1f,%.1f) com sucesso!" %
                  (self.nome, self.posicao, self.altura))

    def pousar(self):
        if self.altura == 0:
            print("%s ja esta no chao" % (self.nome))
        elif self.voando == True:
            print("%s pousado com sucesso!" % (self.nome))
            self.altura = 0
            self.voando = False
            self.armado = False


main()
