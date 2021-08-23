#include <iostream>
#include <string.h>
#include <vector>

#include "./drone/Bateria.hpp"
#include "./drone/Drone.hpp"
#include "./drone/S1000.hpp"

using namespace std;

void mainInterface();
int escolherBateria(vector<Bateria> *baterias);

int main()
{
    vector<Bateria> *baterias = new vector<Bateria>();

    vector<Drone> *drones = new vector<Drone>();

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
            Bateria *bateria_comprada = new Bateria(mah, tempoDeCarregamento);
            baterias->push_back(*bateria_comprada);
        }
        else if (escolha == 2)
        {
            double posicao;
            string nome = "S1000";
            // Comprar um S1000
            cout << "Em que posicao seu S1000 se encontra?" << endl;
            cin >> posicao;
            Bateria *batS1000 = new Bateria(22000, 40);
            S1000 *S1000_comprado = new S1000(nome, batS1000, posicao);
            drones->push_back(*S1000_comprado);
        }
        else if (escolha == 3)
        {
            string nome;
            double posicao;
            // Montar um drone genérico
            cout << "Qual o nome do seu drone?" << endl;
            cin >> nome;
            cout << "Em que posicao seu S1000 se encontra?" << endl;
            cin >> posicao;

            int bateriaId = escolherBateria(baterias);
            baterias->at(bateriaId).setUso(false);

            Drone *drone_montado = new Drone(nome, &baterias->at(bateriaId), posicao);
            drones->push_back(*drone_montado);

            vector<Bateria>::iterator iterator = baterias->begin() + bateriaId;
            baterias->erase(iterator);

            cout << "Seu drone foi montado com sucesso :)" << endl;
        }
        else if (escolha == 4)
        {
            // Usar os drones
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

int escolherBateria(vector<Bateria> *baterias)
{
    // Mostrar as baterias disponiveis
    // pedir uma escolha do usuario
    // retirar a bateria escolhida do vetor de baterias
    int numBat;
    if (baterias->empty())
    {
        cout << "Aparentemente nao existem baterias disponiveis no momento :(" << endl;
        return 1;
    }
    else
    {
        for (int i = 0; i < baterias->size() && baterias->at(i).getUso(); i++)
        {
            printf("Bateria %d: (%d, %d)", i + 1, baterias->at(i).getMah(), baterias->at(i).getTempoDeCarregamento());
        }
    }
    cout << "Qual o numero da bateria escolhida?" << endl;
    cin >> numBat;
    return numBat - 1;
}

void listarDrones(vector<Drone> *drones)
{
    if (drones->empty())
    {
        cout << "Nao existem drones disponiveis no momento :(" << endl;
        return 1;
    }
    else
    {
        for (int i = 0; i < drones->size(); i)
    }
}