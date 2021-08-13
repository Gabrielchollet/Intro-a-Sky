import drone


class S1000(drone.Drone):
    def __init__(self, nome, bateria, posicao):
        super().__init__(nome, bateria, posicao)

    def mapear(self):
        if self.decolado == True and self.enough_charge(10):
            print("Mapeando...")
            print("  /\ ___ /\ ")
            print(" (  o   o  )")
            print("  \  >#<  /")
            print("  /       \ ")
            print(" /         \       ^")
            print("|           |     //")
            print(" \         /    //")
            print("  ///  ///   --")
            print("Mapeamento feito!")
            return True
        else:
            print("O drone " + self.name + " nao eh capaz de mapear :(")
            return False
