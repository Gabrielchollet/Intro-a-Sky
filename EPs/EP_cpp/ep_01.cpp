#include <iostream>
#include <cmath>
using namespace std;

/* Indica se o drone esta armado*/
bool armar(string drone, bool armado, bool decolado);
/**/
bool decolar(string drone, bool armado, bool decolado, double &altura);
/**/
void mudar_posicao(string drone, bool decolado, double &posicao, double &altura);
/**/
void pousar(string drone, bool &decolado, bool &armado, double &altura);

int main()
{
  bool armado, decolado;
  double altura = 0, posicao = 0;
  string drone;
  int escolha = 0;

  cout << "Simulador de Drones Skyrats" << endl;
  cout << "Qual drone voce esta usando?" << endl;
  cin >> drone;

  cout << "Posicao inicial: ";
  cin >> posicao;
  cout << "Altura inicial: ";
  cin >> altura;

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
      armado = armar(drone, armado, decolado);
    }
    else if (escolha == 2)
    {
      decolado = decolar(drone, armado, decolado, altura);
    }
    else if (escolha == 3)
    {
      mudar_posicao(drone, decolado, posicao, altura);
    }
    else if (escolha == 4)
    {
      pousar(drone, decolado, armado, altura);
    }
    else
    {
      return 0;
    }
  }
}

bool armar(string drone, bool armado, bool decolado)
{
  if (armado == true)
  {
    cout << drone << " ja foi armado" << endl;
    return true;
  }
  else
  {
    cout << drone << " armado com sucesso!" << endl;
    armado = true;
  }
  return true;
}

bool decolar(string drone, bool armado, bool decolado, double &altura)
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
    cout << drone << " decolado com sucesso para altura " << altura << endl;
    return true;
  }
}

void mudar_posicao(string drone, bool decolado, double &posicao, double &altura)
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

void pousar(string drone, bool &decolado, bool &armado, double &altura)
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