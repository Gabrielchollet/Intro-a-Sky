#include <iostream>
#include <string.h>
#include "Bateria.hpp"
#include "Drone.hpp"
#include "S1000.hpp"
using namespace std;

S1000::S1000(string nome, Bateria *bateria, double posicao)
{
  this->nome = nome;
  this->bateria = bateria;
  this->posicao = posicao;
}

S1000::~S1000() {}

bool S1000::mapear()
{
  if (this->getDecolado())
  {
    if (this->enough_charge(10))
    {
      cout << "Mapeando..." << endl;
      cout << "  /| ___ /| " << endl;
      cout << " (  o   o  )" << endl;
      cout << "  |  >#<  /" << endl;
      cout << "  /       | " << endl;
      cout << " /         |       ^" << endl;
      cout << "|           |     //" << endl;
      cout << " |         /    //" << endl;
      cout << "  ///  ///  ---" << endl;
      cout << "Mapeamento feito!" << endl;
      return true;
    }
    else
    {
      cout << "O drone nao tem carga suficiente para realizar o mapeamento!" << endl;
      return false;
    }
  }
  else
  {
    cout << "O drone precisa ser decolado primeiro!" << endl;
    return false;
  }
}