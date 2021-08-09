#include "drone.hpp"

void Drone::set_name()
{
  Nome = drone;
}

string Drone::get_name()
{
  return Nome;
}

void Drone::set_altura(double altura)
{
  Altura = altura;
}

double Drone::get_altura()
{
  return Altura;
}

void Drone::set_posicao(double posicao)
{
  Posicao = posicao;
}

double Drone::get_posicao()
{
  return Posicao;
}

void Drone::set_armado(bool armado)
{
  Armado = armado;
}

bool Drone::get_armado()
{
  return Armado;
}

void Drone::set_decolado()
{
  Decolado = decolado;
}

bool Drone::get_decolado()
{
  return Decolado;
}

void Drone::set_velocidade()
{
  Velocidade = velocidade;
}

double Drone::get_velocidade()
{
  return Velocidade;
}

bool Drone::armar(string drone, bool armado, bool decolado)
{
  if (armado == true)
  {
    cout << drone << " ja foi armado!" << endl;
    return true;
  }
  else
  {
    cout << drone << " armado com sucesso!" << endl;
    armado = true;
  }
  return true;
}

bool Drone::decolar(string drone, bool armado, bool decolado, double altura)
{
  if (armado == false)
  {
    cout << drone << " precisa ser armado antes de decolar" << endl;
    return false;
  }
  if (decolado == true)
  {
    cout << drone << " ja esta voando" << endl;
    return true;
  }
  if (armado == true && altura == 0)
  {
    cout << "Para qual altura voce quer que seu drone decole?" << endl;
    cin >> altura;
    set_altura(altura);
    cout << drone << " decolado com sucesso para altura " << altura << endl;
    return true;
  }
}

void Drone::mudar_posicao(string drone, bool decolado, double &posicao, double &altura)
{
  double altura_inicial = altura;
  double posicao_inicial = posicao;

  double altura_t = altura_inicial;
  double posicao_t = posicao_inicial;

  double velocidade = 0, vel_x, vel_y, alpha;

  int tempo = 0;

  if (decolado == false)
  {
    cout << drone << " precisa ser decolado antes de mudar de posicao" << endl;
    return;
  }
  else
  {
    cout << "Posicao atual: "
         << "(" << posicao << "," << altura << ")" << endl;
    cout << "Qual posicao voce quer ir?" << endl;
    cout << "Posicao desejada: ";
    cin >> posicao;
    cout << "Altura desejada: ";
    cin >> altura;
    cout << "Velocidade desejada: ";
    cin >> velocidade;
    alpha = atan2(altura - altura_inicial, posicao - posicao_inicial);
    vel_x = velocidade * cos(alpha);
    vel_y = velocidade * sin(alpha);
  }

  while ((altura_t < altura) || (posicao_t < posicao))
  {
    cout << "Posicao no instante t" << tempo << ": (" << posicao_t << "," << altura_t << ")" << endl;
    posicao_t += vel_x;
    altura_t += vel_y;
    tempo++;
  }
  cout << drone << " foi para (" << posicao << "," << altura << ") com sucesso!" << endl;
}

void Drone::pousar(string drone, bool decolado, bool armado, double altura)
{
  if (altura == 0)
  {
    cout << drone << " ja esta no chao" << endl;
    return;
  }
  else if (decolado == true)
  {
    cout << drone << " pousado com sucesso!" << endl;
    altura = 0;
    decolado = false;
  }
}

void Drone::Drone(string nome, double altura, double posicao, double velocidade, bool armado, bool decolado)
{
  set_name(nome);
  set_altura(altura);
  set_velocidade(posicao);
  set_velocidade(velocidade);
  set_armado(armado);
  set_decolado(decolado);
}