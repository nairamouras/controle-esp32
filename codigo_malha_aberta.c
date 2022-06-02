//https://randomnerdtutorials.com/esp32-hc-sr04-ultrasonic-arduino/
//https://esp32io.com/tutorials/esp32-ultrasonic-sensor

const int potPin = 32;
const int saidaPWM = 23;
const int trigPin = 21;
const int echoPin = 22;

int potValue = 0;

const int frequencia = 5000;
const int Channel = 0;
const int resolucao = 8;



//definir a velocidade do som em cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Inicia a comunicação serial
  pinMode(trigPin, OUTPUT); // Define o trigPin como uma saída
  pinMode(echoPin, INPUT); // Define o echoPin como uma entrada


  ledcSetup(Channel,frequencia,resolucao);
  ledcAttachPin(saidaPWM,Channel);
  delay(1000);

}

void loop() {
  // Limpa o trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Define o trigPin no estado HIGH por 10 microssegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);



  // Lê o echoPin, retorna o tempo de viagem da onda sonora em microssegundos
  duration = pulseIn(echoPin, HIGH);

  // Calcula a distância
  distanceCm = 50 - (duration * SOUND_SPEED/2);


  // Imprime a distância no Monitor Serial
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

 
  delay(1000);

  potValue = analogRead(potPin);
  Serial.println(potValue);

  int dutyCycle = (potValue/16);
  ledcWrite(Channel,dutyCycle);
  delay(500);
}