#include "JsbIotSensorPresenca.h"

short PINO_SENSOR_PRESENSA = 7;
short PINO_RELE = 6;
int TEMPO = 17000;

JsbIotSensorPresenca sensorPresenca(PINO_SENSOR_PRESENSA, PINO_RELE);

void setup(){
  sensorPresenca.setTempoMininoLuzAcesa(17000);
  //sensorPresenca.ativarDelayDe1Segundo();
  Serial.begin(115200);
}

void loop() {
  Serial.print("getTempoMininoLuzAcesa: ");
  Serial.println(sensorPresenca.getTempoMininoLuzAcesa());

  sensorPresenca.executar();
}
