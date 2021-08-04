#ifndef Drone_
#define Drone_

#include <string>
using namespace std;

class Drone
{
private:
  string Nome;
  double Altura;
  double Posicao;
  bool Armado;
  bool Decolado;
  double Velocidade;

public:
  void set_name();
  string get_name();

  void set_altura(double altura);
  double get_altura();

  void set_posicao(double posicao);
  double get_posicao();

  void set_armado(bool armado);
  bool get_armado();

  void set_decolado(bool decolado);
  bool get_decolado();

  void set_velocidade(double velocidade);
  double get_velocidade();

  bool armar(string drone, bool armado, bool decolado);

  bool decolar(string drone, bool armado, bool decolado, double altura);

  void mudar_posicao(string drone, bool decolado, double posicao, double altura);

  void pousar(string drone, bool decolado, bool armado, double altura);
  // Construtor
  Drone(string nome, double altura, double posicao, double velocidade, bool armado, bool decolado);
};

#endif