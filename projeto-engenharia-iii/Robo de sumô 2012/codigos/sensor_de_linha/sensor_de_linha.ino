int pinoSensorDireito = A0;
int pinoSensorEsquerdo = A1;
int valorSensorDireito = 0;
int valorSensorEsquerdo = 0;
 
void setup(){
    Serial.begin(9600);
}
 
void loop(){
    valorSensorDireito = analogRead(pinoSensorDireito);
    valorSensorEsquerdo = analogRead(pinoSensorEsquerdo);

    Serial.print("Sensor direito: ");
    Serial.println(valorSensorDireito);
    Serial.print("Sensor esquerdo: ");
    Serial.println(valorSensorEsquerdo); 

    delay(1000);
}
