#include <iostream>
#include <string.h>
#include <vector>

#include <Bateria.hpp>
#include <Drone.hpp>
#include <S1000.hpp>

using namespace std;

void mainInterface();
int escolherBateria(vector<Bateria> baterias);

int main()
{
    vector<Bateria> baterias = new vector<Bateria>();

    vector<Drone> drones = new vector<Drone>();

    cout << "\tWellcome to My Drone Simulator" << endl;

    //Interface Principal
    int escolha = 0;

    while (escolha != 8)
    {
        mainInterface();
        cin >> escolha;

        if (escolha == 1)
        {
            int mah, tempoDeCarregamento;
            // Comprar bateria
            cout << "Qual a carga total em mAh da bateria que voce quer comprar?" << endl;
            cin >> mah;
            cout << "Qual o tempo de carregamento maximo da bateria desejada?" << endl;
            cin >> tempoDeCarregamento;

            baterias.push_back(new Bateria(mah, tempoDeCarregamento));
        }
        else if (escolha == 2)
        {
            double posicao;
            // Comprar um S1000
            cout << "Em que posicao seu S1000 se encontra?" cin >> posicao;

            drones.push_back(new Drone("S1000", Bateria(22000, 40), posicao))
        }
        else if (escolha == 3)
        {
            string nome;

            // Montar um drone genérico
            cout << "Qual o nome do seu drone?" << endl;
            cin >> nome;
            cout << "Em que posicao seu S1000 se encontra?" cin >> posicao;
            int bateriaId = escolherBateria(baterias);
            drones.push_back(new Drone(nome, baterias.at(bateriaId), posicao));

            baterias.erase(bateriaId);
            cout << "Seu drone foi montado com sucesso :)" << endl;
        }
        else if (escolha == 4)
        {
        }
        else if (escolha == 5)
        {
        }
        else if (escolha == 6)
        {
        }
        else if (escolha == 7)
        {
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

void mainInterface()
{
    cout << "1. Comprar bateria" << endl;
    cout << "2. Comprar um S1000" << endl;
    cout << "3. Montar um drone genérico" << endl;
    cout << "4. Usar os drones existentes" << endl;
    cout << "5. Carregar baterias disponíveis" << endl;
    cout << "6. Listar Drones existentes" << endl;
    cout << "7. Listar Baterias existentes" << endl;
    cout << "8. Sair" << endl;
}

int escolherBateria(vector<Bateria> baterias)
{
    // Mostrar as baterias disponiveis
    // pedir uma escolha do usuario
    // retirar a bateria escolhida do vetor de baterias
    int numBat;
    if (baterias.empty())
    {
        cout << "Aparentemente nao existem baterias disponiveis no momento :(" << endl;
        return 1;
    }
    else
    {
        for (int i = 0; i < baterias.size(); i++)
        {
            printf("Bateria %d: (%d, %d)", i + 1, baterias.at(i).getMah, baterias.at(i).getTempoDeCarregamento())
        }
    }
    cout << "Qual o numero da bateria escolhida?" << endl;
    cin >> numBat;
    return numBat - 1;
}