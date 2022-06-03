//Variaveis do sensor UltraSonico e do Potenciometro
const int potPin = 32;
const int saidaPWM = 23; //saida PWM
const int trigPin = 21;
const int echoPin = 22;

int potValue = 0;

//Variavel PWM
const int frequencia = 5000; // frequencia
const int Channel = 0; //canal 0
const int resolucao = 8; // 8 bits


//definine a velocidade do som em cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

//Variaveis para o codigo duração e distancia 
long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Inicia a comunicação serial
  pinMode(trigPin, OUTPUT); // Define o trigPin como uma saída
  pinMode(echoPin, INPUT); // Define o echoPin como uma entrada


  
  ledcSetup(Channel,frequencia,resolucao); // difine o canal a frequencia e a resolução que foi definida acima
  ledcAttachPin(saidaPWM,Channel); //atribui um pino para o PWM 23 no canal 0
  delay(1000);

}

void loop() {
  // Limpa o trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Define o trigPin no estado HIGH por 10 microssegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  // Define o trigPin no estado LOW
  digitalWrite(trigPin, LOW);



  // Lê o echoPin, retorna o tempo de viagem da onda sonora em microssegundos
  duration = pulseIn(echoPin, HIGH);

  // Calcula a distância do ponto zero
  distanceCm = 50 - (duration * SOUND_SPEED/2);


  // Imprime a distância no Monitor Serial
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

 
  delay(1000);

  potValue = analogRead(potPin); // Le o potenciometro
  Serial.println(potValue);

  int dutyCycle = (potValue/16); // PWM de 8bits e para isso dividimos por 16
  ledcWrite(Channel,dutyCycle);
  delay(500);
}
