#include <iostream>
#include "Bateria.hpp"
using namespace std;

Bateria::Bateria(int mah, int tempoDeCarregamento)
{
  this->mah = mah;
  this->tempoDeCarregamento = tempoDeCarregamento;
}

virtual Bateria::~Bateria()

    bool Bateria::carregar(int tempo)
{
  if (this->carregavel == true)
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
  if (this->carga > consumo_de_bateria)
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

int Bateria::getUso()
{
  return this->uso;
}

int Bateria::getCarregavel()
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

void Bateria::status() const
{
  cout << "Bateria com capacidade " << this->mah << " e tempo de carregamento " << this->tempoDeCarregamento << endl;
  cout << "Com carga atual: " << this->carga << endl;
  cout << "Tempo de voo disponivel: " << this->calculaTempoDeVoo() << endl;
  cout << "Esta sendo usada" << (this->uso) ? "sim" : "nao" << endl;
  cout << "Pode ser carregada no momento: " << (this->carregavel) ? "sim" : "nao" << endl;
}