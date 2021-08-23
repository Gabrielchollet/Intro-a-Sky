#ifndef DRONE_H
#define DRONE_H

#include "Bateria.hpp"
using namespace std;

class Drone
{
protected:
    string nome;
    Bateria *bateria;
    double posicao;
    int altura = 0;
    bool decolado = false;

public:
    Drone(string nome, Bateria *bateria, double posicao);
    ~Drone();

    bool enough_charge(double tempoDeUso);
    void takeoff(int altura);
    bool setPosition(double x, double y);
    void land();
    virtual bool mapear();
    void status();

    string getNome();
    Bateria *getBateria();
    double getPosicao();
    double getAltura();
    bool getDecolado();
};

#endif
