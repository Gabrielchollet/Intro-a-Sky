#include <iostream>
#include "Bateria.hpp"
using namespace std;

Bateria::Bateria(int mah, int tempoDeCarregamento)
{
  this->mah = mah;
  this->tempoDeCarregamento = tempoDeCarregamento;
}

Bateria::~Bateria() {}

bool Bateria::carregar(int tempo)
{
  if (this->getCarregavel() == true)
  {
    if (carga == this->mah)
    {
      cout << "A bateria ja esta carregada!" << endl;
      return false;
    }
    else
    {
      cout << "A bateria foi carregada com sucesso!" << endl;
      this->carga += (this->mah * tempo) / this->tempoDeCarregamento;
      return true;
    }
  }
  else
  {
    cout << "A bateria nao pode ser carregada!" << endl;
    return false;
  }
}

bool Bateria::usar(int tempo)
{
  int consumo_de_bateria = (this->mah * tempo) / this->tempoDeCarregamento;
  if (this->carga >= consumo_de_bateria && this->carga != 0 && this->uso == true)
  {
    this->carga -= consumo_de_bateria;
    return true;
  }
  else
  {
    cout << "A bateria nao aguenta ser usada por esse intervalo de tempo!" << endl;
    return false;
  }
}

int Bateria::calculaTempoDeVoo()
{
  return (this->carga * this->tempoDeCarregamento) / this->mah;
}

int Bateria::getCarga()
{
  return this->carga;
}

int Bateria::getTempoDeCarregamento()
{
  return this->tempoDeCarregamento;
}

int Bateria::getMah()
{
  return this->mah;
}

bool Bateria::getUso()
{
  return this->uso;
}

bool Bateria::getCarregavel()
{
  return this->carregavel;
}

void Bateria::setUso(bool uso)
{
  this->uso = uso;
}

void Bateria::setCarregavel(bool carregavel)
{
  this->carregavel = carregavel;
}

void Bateria::status()
{
  cout << "Bateria com capacidade " << this->mah << " e tempo de carregamento " << this->tempoDeCarregamento << endl;
  cout << "Com carga atual: " << this->carga << endl;
  cout << "Tempo de voo disponivel: " << this->calculaTempoDeVoo() << endl;
  if (this->uso)
  {
    cout << "Esta sendo usada: sim." << endl;
  }
  else
  {
    cout << "Esta sendo usada: nao." << endl;
  }

  if (this->carregavel)
  {
    cout << "Pode ser carregada no momento: Sim." << endl;
  }
  else
  {
    cout << "Pode ser carregada no momento: Nao." << endl;
  }
}