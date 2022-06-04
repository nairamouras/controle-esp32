# controle-esp32

### Controle de nível e malha fechada utilizando ESP32
*Apresentação em vídeo disponível [aqui](https://youtu.be/C1YepbcfvZM)*

## Conteúdo

1. [Objetivo](https://github.com/nairamouras/controle-esp32/blob/main/README.md#objetivo)
2. [Materiais utilizados](https://github.com/nairamouras/controle-esp32/blob/main/README.md#materiais-utilizados)
3. [Diagrama do projeto](https://github.com/nairamouras/controle-esp32/blob/main/README.md#diagrama-do-projeto)
4. [Controle com malha aberta](https://github.com/nairamouras/controle-esp32/blob/main/README.md#controle-com-malha-aberta)
5. [Controle com malha fechada](https://github.com/nairamouras/controle-esp32/blob/main/README.md#controle-com-malha-fechada)
6. [Referências](https://github.com/nairamouras/controle-esp32/blob/main/README.md#refer%C3%AAncias)

## Objetivo

O objetivo deste projeto era simular o controle de nível em malha fechada utilizando o ESP32.

## Materiais utilizados

- 1 ESP32
- 3 protoboards
- 55 cm de cano de esgoto 75 mm
- 1 funil
- 1 cooler 12V e 0.21A
- 1 régua transparente 50 cm
- 1 bolinha de isopor
- 1 rede de coador
- 1 potenciômetro 10K
- 1 sensor ultrassônico
- 1 fita isolante
- 1 fita crepe
- 1 fonte 12V
- 1 acoplador 4N35
- 1 transistor TIP31
- 4 parafusos
- 4 buchas de parafuso
- 1 arame
- Fios de ligação
- 1 resistor 330R
- 1 diodo 1N4001
- Papelão

## Diagrama do projeto

![](https://media.discordapp.net/attachments/948707544208125965/982131393490456646/IMG-20220602-WA0023.jpg?width=586&height=406)

## Controle com malha aberta

O código da malha aberta utiliza a técnica do ***Pulse Width Modulation*** (PWM) para obter a leitura do valor analógico e possibilitar a configuração manual do potenciômetro para controlar a velocidade de rotação do cooler. Além disso, o código também faz a programação do sensor ultrassônico para o cálculo da posição da bolinha dentro do cano.

## Controle com malha fechada

Nesse caso, o código da malha fechada não foi finalizado a tempo e por isso foi necessário o auxílio do orientador da disciplina. Dessa forma, foram inseridas a definição do erro e uma fórmula de sinal de controle, onde ocorre o fechamento da malha. Ademais, esta última etapa foi feita com Controle Integral (PI) sem sintonia.

## Referências

RANDOM NERD TUTORIALS. ***ESP32 ADC – Read Analog Values with Arduino IDE***. Dispnível em: <<https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/>>

RANDOM NERD TUTORIALS. ***ESP32 with HC-SR04 Ultrasonic Sensor with Arduino IDE***. Disponível em: <<https://randomnerdtutorials.com/esp32-hc-sr04-ultrasonic-arduino/>>

ESP32 I/O. ***ESP32 - Ultrassonic Sensor***. Disponível em: <<https://esp32io.com/tutorials/esp32-ultrasonic-sensor>>
