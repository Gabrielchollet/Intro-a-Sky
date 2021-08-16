import bateria as b
import drone as d


def escolhe_bateria(baterias):
    if len(baterias) > 0:
        escolha = 0
        for index, value in enumerate(baterias):
            print("Bateria " + str(index + 1) + ":\n")
            print("\t Carga total: %.1f; Tempo de Carregamento: %.1f" %
                  (value.mah, value.tempoDeCarregamento))
        escolha = int(input("Digite o numero da bateria desejada: "))
        bateria_escolhida = baterias[escolha - 1]
        del(baterias[escolha])
        return bateria_escolhida
    else:
        print("Nao existem baterias disponiveis!")
        return False


def interface_drone(drone):
    print("O que voce quer fazer com o drone?")
    escolha = 0
    while escolha != 5:
        print("\t1. Decolar o drone")
        print("\t2. Ir para uma posicao")
        print("\t3. Pousar o drone")
        print("\t4. Mapear")
        print("\t5. Sair")
        escolha = int(input(""))
        if escolha == 1:
            altura = int(input("Para que altura deseja que o drone decole?"))
            drone.takeoff(altura)
        elif escolha == 2:
            print("Posicao atual: (%.1f,%.1f)" % (drone.posicao, drone.altura))
            print("Qual posicao voce quer ir?")
            posicao = float(input("Posicao desejada: "))
            altura = float(input("Altura desejada: "))
            drone.set_position(posicao, altura)
        elif escolha == 3:
            drone.land()
        elif escolha == 4:
            drone.mapear()
        else:
            return 0


def main():
    baterias = []
    drones = []

    escolha = 0
    while escolha != 8:
        print("1. Comprar bateria")
        print("2. Comprar um S1000")
        print("3. Montar um drone generico")
        print("4. Usar os drones existentes")
        print("5. Carregar baterias disponiveis")
        print("6. Listar Drones existentes")
        print("7. Listar Baterias existentes")
        print("8. Sair")
        escolha = int(input(""))
        if escolha == 1:
            mah = float(input("Carga total desejada: "))
            tempoDeCarregamento = float(
                input("Tempo de Carregamento da bateria: "))

            baterias.append(b.Bateria(mah, tempoDeCarregamento))
        elif escolha == 2:
            posicao = float(input("Qual a posicao no eixo x do S1000?"))
            drones.append(d.Drone("S1000", b.Bateria(22000, 40), posicao))
        elif escolha == 3:
            nome = input("Qual o nome do drone?\n")
            posicao = float(input("Qual a posicao no eixo x do drone?\n"))
            drones.append(nome, escolhe_bateria(baterias), posicao)

        elif escolha == 4:
            for index, value in enumerate(drones):
                print("Drone %d: %s\n" % (index + 1, value.nome))
            num_esc = int(input("Digite o numero do drone desejado: "))
            interface_drone(drones[num_esc])
        elif escolha == 5:
            tempoTotalCarregamento = 0
            for index, value in enumerate(baterias):
                tempoTotalCarregamento += value.tempoDeCarregamento
            print("Tempo total de carregamento: " + tempoTotalCarregamento)
        elif escolha == 6:
            for index, value in enumerate(drones):
                print("Drone %d: %s\n" % (index + 1, value.nome))
        elif escolha == 7:
            for index, value in enumerate(baterias):
                print("Bateria " + str(index + 1) + ":\n")
                print("\t Carga total: %.1f; Tempo de Carregamento: %.1f" %
                      (value.mah, value.tempoDeCarregamento))
        else:
            return 0


main()
