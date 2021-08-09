#include <iostream>
#include <cmath>
#include "drone.hpp"
using namespace std;

int main()
{
  bool armado = false, decolado = false;
  double altura = 0, posicao = 0, velocidade = 0;
  string drone;

  cout << "Simulador de Drones Skyrats" << endl;
  cout << "Qual drone voce esta usando?" << endl;
  cin >> drone;

  cout << "Posicao inicial: ";
  cin >> posicao;
  cout << "Altura inicial: ";
  cin >> altura;

  Drone *meu_drone = new Drone(drone, altura, posicao, velocidade, armado, decolado);

  int escolha = 0;

  while (escolha != 5)
  {
    cout << "O que voce quer fazer com o drone?" << endl;
    cout << "\t1) Armar o drone" << endl;
    cout << "\t2) Decolar o drone" << endl;
    cout << "\t3) Mudar a posicao do drone" << endl;
    cout << "\t4) Pousar o drone" << endl;
    cout << "\t5) Sair" << endl;
    cin >> escolha;
    if (escolha == 1)
    {
      meu_drone->set_armado(meu_drone->armar());
    }
    else if (escolha == 2)
    {
      meu_drone->set_decolado(meu_drone->decolar());
    }
    else if (escolha == 3)
    {
      meu_drone->mudar_posicao();
    }
    else if (escolha == 4)
    {
      meu_drone->pousar();
    }
    else
    {
      return 0;
    }
  }
}