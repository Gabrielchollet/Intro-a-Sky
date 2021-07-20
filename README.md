![image](https://scontent.ffor4-1.fna.fbcdn.net/v/t31.18172-8/s960x960/22829824_298404297328920_5472367341930442515_o.png?_nc_cat=105&ccb=1-3&_nc_sid=e3f864&_nc_eui2=AeGKfpva6MUKiTfm4OF1ZwfhuMeM7wPChIK4x4zvA8KEgqyiFjJ_rdlynDo32lvWOA7QMzTEDCRuCf5kxGsxnfzI&_nc_ohc=lcMl6UPASl4AX-Rz3Nj&_nc_ht=scontent.ffor4-1.fna&oh=7324a5f22986e190def666cbd10b7efb&oe=60F7DBCC)

# Workshops - Exercícios Programas: Skyrats

Este repositório contém em alguns dos códigos e aprendizados desenvolvidos durante os workshops incríveis feitos pelo pessoal>

## Roadmap 

1. Ubuntando o PC
2. Intro a Git e Linux 
3. C++ e Python

<hr>

## Exercício Programa (EP) - Workshop de introdução à Programação

<details>
<summary>Expandir</summary>

### Introdução

Desenvolvemos uma versão simplificada de uma estação de controle nas linguagens de programação Python e C++.

### Funcionamento

Nosso drone só poderá se mover em dois eixos, altura e posição horizontal.
O código deverá iniciar pedindo:
- O nome do drone (como uma string)
- A posição de início do drone (como um float)

O código deve ter uma interface em que o usuário tem 5 opções de escolha:
1. Armar o drone
2. Decolar o drone
3. Mudar a posição do drone
4. Pousar o drone
5. Sair da interface
Essa interface deverá aparecer para o usuário até que ele escolha a opção número 5.

### C++ 

<hr>

### Python
Desafio: Criar uma versão da solução desse exercício aplcando os conceitos de POO (Programação Orientada a Objeto)

#### Conceitos aprendidos:

<details>
<summary>Expandir</summary>
O método especial `__init__`
- Conhecido como **Construtor** de classe
- Chamado automaticamente pelo interpretador quando os objetos são criados
  - *Ex: quando as classes são instanciadas*

```
class Drone:
    def __init__(self, nome, posicao, altura, armado, voando):
        self.nome = nome
        self.posicao = posicao
        self.altura = altura
        self.armado = armado
        self.voando = voando
```


</details>

</details>