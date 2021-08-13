import Bateria
import Drone


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

            baterias.append(Bateria(mah, tempoDeCarregamento))
        elif escolha == 2:
            posicao = float(input("Qual a posicao no eixo x do S1000?"))
            drones.append(Drone("S1000", Bateria(22000, 40), posicao))
        elif escolha == 3:
            nome = input("Qual o nome do drone?\n")
            posicao = float(input("Qual a posicao no eixo x do drone?\n"))
            drones.append(nome, escolhe_bateria(baterias), posicao)

        # elif escolha == 4:

        # elif escolha == 5:

        # elif escolha == 6:

        # elif escolha == 7:

        # else:
        #     return 0

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


main()
