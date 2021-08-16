class Drone():
    def __init__(self, nome, bateria, posicao):
        self.nome = nome
        self.bateria = bateria
        self.posicao = posicao
        self.altura = 0
        self.decolado = False

    def enough_charge(self, tempo_de_uso):
        if tempo_de_uso <= self.bateria.calcula_tempo_de_voo():
            return True
        else:
            return False

    def takeoff(self, altura):
        tempo_de_uso = altura / 60
        if self.enough_charge(tempo_de_uso):
            self.bateria.usar(tempo_de_uso)
            self.altura = altura
            self.decolado = True
            self.bateria.carregavel = False
            self.bateria.uso = True
            print("Drone decolado para altura: " + altura)
            return True
        else:
            print("O drone nao possui bateria suficiente!")
            return False

    def set_position(self, x, y):
        distance = (x**2 + y**2) ** 0.5
        tempo_de_uso = distance / 60

        if self.enough_charge(tempo_de_uso) and self.decolado == True and y > 0:
            self.bateria.usar(tempo_de_uso)
            self.posicao = x
            self.altura = y
            return True
        else:
            print("O drone nao possui bateria suficiente!")
            return False

    def land(self):
        if self.altura == 0:
            print("%s ja esta no chao" % (self.nome))
        elif self.voando == True:
            print("%s pousado com sucesso!" % (self.nome))
            self.bateria.carregavel = True
            self.altura = 0
            self.decolado = False

    def mapear(self):
        print("O drone " + self.name + " nao eh capaz de mapear :(")
        return False

    def status(self):
        print("Drone " + self.nome)
        print("Bateria com " + str(self.bateria.carga) + " mAh")
        print("Drone esta na posicao (%.1f,%.1f)" %
              (self.posicao, self.altura))
