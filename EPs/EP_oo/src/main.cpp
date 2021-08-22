#include <iostream>
#include <string.h>
#include <vector>
#include "Bateria.hpp"
#include "Drone.hpp"
#include "S1000.hpp"
using namespace std;

void mainInterface();

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
        }
        else if (escolha == 2)
        {
        }
        else if (escolha == 3)
        {
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