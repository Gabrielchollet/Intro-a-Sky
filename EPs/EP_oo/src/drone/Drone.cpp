#include <iostream>
#include <string.h>
#include <math.h>
#include "Bateria.hpp"
#include "Drone.hpp"
using namespace std;

Drone::Drone(string nome, Bateria *bateria, double posicao)
{
  this->nome = nome;
  this->bateria = bateria;
  this->posicao = posicao;
}

Drone::~Drone() {}

bool Drone::enough_charge(double tempoDeUso)
{
  if (tempoDeUso <= bateria->calculaTempoDeVoo() && bateria->calculaTempoDeVoo() != 0)
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
  double tempoDeUso = altura / 60;
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
      double distance = sqrt(pow(x - this->posicao, 2) + pow(y - this->altura, 2));
      int tempoDeUso = distance / 60;
      if (this->enough_charge(tempoDeUso))
      {
        this->posicao = x;
        this->altura = y;
        cout << this->nome << " se encontra em (" << this->posicao << "," << this->altura << ")" << endl;
        this->bateria->usar(tempoDeUso);
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
      cout << "O drone nao pode ir para uma altura menor ou igual a 0." << endl;
      return false;
    }
  }
  else
  {
    cout << "O drone precisa ser decolado!" << endl;
    return false;
  }
}

void Drone::land()
{
  this->altura = 0;
  this->decolado = false;
  this->bateria->setCarregavel(true);
  cout << this->nome << " foi pousado com sucesso!" << endl;
}

bool Drone::mapear()
{
  cout << this->nome << " nao eh capaz de mapear :(" << endl;
  return false;
}

void Drone::status()
{
  cout << "Drone " << this->nome << endl;
  cout << "Bateria com " << this->bateria->getCarga() << " mAh" << endl;
  cout << this->nome << "esta na posicao (" << this->posicao << "," << this->altura << endl;
}

string Drone::getNome()
{
  return this->nome;
}

Bateria *Drone::getBateria()
{
  return this->bateria;
}

double Drone::getPosicao()
{
  return this->posicao;
}

double Drone::getAltura()
{
  return this->altura;
}

bool Drone::getDecolado()
{
  return this->decolado;
}