#include <iostream>
#include <cmath>
#include "drone.hpp"
using namespace std;

void Drone::set_name(string drone)
{
  this->Nome = drone;
}

string Drone::get_name()
{
  return Nome;
}

void Drone::set_altura(double altura)
{
  this->Altura = altura;
}

double Drone::get_altura()
{
  return Altura;
}

void Drone::set_posicao(double posicao)
{
  this->Posicao = posicao;
}

double Drone::get_posicao()
{
  return Posicao;
}

void Drone::set_armado(bool armado)
{
  this->Armado = armado;
}

bool Drone::get_armado()
{
  return Armado;
}

void Drone::set_decolado(bool decolado)
{
  this->Decolado = decolado;
}

bool Drone::get_decolado()
{
  return Decolado;
}

void Drone::set_velocidade(double velocidade)
{
  this->Velocidade = velocidade;
}

double Drone::get_velocidade()
{
  return Velocidade;
}

bool Drone::armar()
{
  if (this->Armado == true)
  {
    cout << this->Nome << " ja foi armado!" << endl;
    return true;
  }
  else
  {
    cout << this->Nome << " armado com sucesso!" << endl;
    this->Armado = true;
  }
  return true;
}

bool Drone::decolar()
{
  if (this->Armado == false)
  {
    cout << this->Nome << " precisa ser armado antes de decolar" << endl;
    return false;
  }
  if (this->Decolado == true)
  {
    cout << this->Nome << " ja esta voando" << endl;
    return true;
  }
  if (this->Armado == true && this->Altura == 0)
  {
    cout << "Para qual altura voce quer que seu drone decole?" << endl;
    cin >> this->Altura;
    set_altura(this->Altura);
    cout << this->Nome << " decolado com sucesso para altura " << this->Altura << endl;
    return true;
  }
}

void Drone::mudar_posicao()
{
  double altura_inicial = this->Altura;
  double posicao_inicial = this->Posicao;

  double altura_t = altura_inicial;
  double posicao_t = posicao_inicial;

  double vel_x, vel_y, alpha;

  this->Velocidade = 0;

  int tempo = 0;

  if (this->Decolado == false)
  {
    cout << this->Nome << " precisa ser decolado antes de mudar de posicao" << endl;
    return;
  }
  else
  {
    cout << "Posicao atual: "
         << "(" << this->Posicao << "," << this->Altura << ")" << endl;
    cout << "Qual posicao voce quer ir?" << endl;
    cout << "Posicao desejada: ";
    cin >> this->Posicao;
    cout << "Altura desejada: ";
    cin >> this->Altura;
    cout << "Velocidade desejada: ";
    cin >> this->Velocidade;
    alpha = atan2(this->Altura - altura_inicial, this->Posicao - posicao_inicial);
    vel_x = this->Velocidade * cos(alpha);
    vel_y = this->Velocidade * sin(alpha);
  }

  while ((altura_t < this->Altura) || (posicao_t < this->Posicao))
  {
    cout << "Posicao no instante t" << tempo << ": (" << posicao_t << "," << altura_t << ")" << endl;
    posicao_t += vel_x;
    altura_t += vel_y;
    tempo++;
  }
  cout << this->Nome << " foi para (" << this->Posicao << "," << this->Altura << ") com sucesso!" << endl;
}

void Drone::pousar()
{
  if (this->Altura == 0)
  {
    cout << this->Nome << " ja esta no chao" << endl;
    return;
  }
  else if (this->Decolado == true)
  {
    cout << this->Nome << " pousado com sucesso!" << endl;
    this->Altura = 0;
    this->Decolado = false;
  }
}

Drone::Drone(string nome, double altura, double posicao, double velocidade, bool armado, bool decolado)
{
  set_name(nome);
  set_altura(altura);
  set_velocidade(posicao);
  set_velocidade(velocidade);
  set_armado(armado);
  set_decolado(decolado);
}