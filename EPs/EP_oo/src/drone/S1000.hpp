#ifndef S1000_H
#define S1000_H

#include "Bateria.hpp"
#include "Drone.hpp"

class S1000 : public Drone
{
public:
    S1000(string nome, Bateria *bateria, double posicao);
    ~S1000();
    bool mapear();
};

#endif
