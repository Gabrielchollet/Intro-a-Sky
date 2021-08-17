#include <iostream>
#include <string.h>
#include "Bateria.hpp"
#include "Drone.hpp"
using namespace std;

Drone::Drone(string nome, Bateria *bateria, double posicao)
{
  this->nome = nome;
  this->bateria = bateria;
  this->posicao = posicao;
}

virtual Drone::~Drone()

    bool Drone::enough_charge(int tempoDeUso)
{
  if (tempoDeUso <= bateria->calculaTempoDeVoo())
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Drone::takeoff(int altura)
{
  int tempoDeUso = altura / 60;
  if (this->enough_charge(tempoDeUso))
  {
    this->decolado = true;
    this->bateria->setCarregavel(false);

    this->altura = altura;
    cout << this->nome << " decolado para altura " << this->altura << endl;

    this->bateria->usar(tempoDeUso);
  }
  else
  {
    cout << "O drone nao possui bateria suficiente!" << endl;
  }
}

bool Drone::setPosition(double x, double y)
{
  if (this->decolado)
  {
    if (y > 0)
    {
      double distance = (x * *2 + y * *2) * *0.5;
      int tempoDeUso = distance / 60;
      if (this->enough_charge(tempoDeUso))
      {
        this->posicao = x;
        this->altura = y;
        return true;
      }
      else
      {
        cout << "O drone nao possui bateria suficiente!" << endl;
        return false;
      }
    }
    else
    {
      cout << "O drone nao pode ir para uma altura <= 0." << endl;
      return false;
    }
  }
  else
  {
    cout << "O drone precisa ser decolado!" << endl;
    return false;
  }
}

double Drone::getPosicao()
{
  return this->posicao;
}

double Drone::getAltura()
{
  return this->altura;
}

void land()
{
  this->altura = 0;
  this->decolado = false;
  this->bateria->carregavel = true;
  cout << ""
}