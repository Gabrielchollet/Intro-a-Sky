class Bateria():
    def __init__(self, mah, tempoDeCarregamento):
        self.mah = mah
        self.tempoDeCarregamento = tempoDeCarregamento
        self.carga = 0
        self.uso
        self.carregavel

    def carregar(self, tempo):
        if self.carregavel == True:
            if self.carga == self.mah:
                print("A bateria ja esta carregada!")
                return False
            else:
                print("A bateria foi carregada com sucesso!")
                self.carga += (self.mah * tempo) / self.tempoDeCarregamento
                return True
        else:
            print("A bateria nao pode ser carregada!")
            return False

    def usar(self, tempo):
        # tempoDeCarregamento == tempoDeVoo
        consumo = (self.mah * tempo) / self.tempoDeCarregamento
        if self.carga > consumo:
            self.carga -= consumo
            return True
        else:
            print("A bateria nao aguenta ser usada por esse intervalo de tempo!")
            return False

    def calcula_tempo_de_voo(self):
        return (self.carga * self.tempoDeCarregamento) / self.mah

    def status(self):
        print("Bateria com capacidade " + str(self.mah) +
              " e tempo de carregamento " + str(self.tempoDeCarregamento))
        print("Com carga atual: " + str(self.carga))
        print("Tempo de voo disponivel: " + str(self.calcula_tempo_de_voo()))
        print("Esta sendo usada: " + "sim" if self.uso == True else "nao")
        print("Pode ser carregada no momento: " + str(self.carregar(0)))
