/*
*	JsbIotSensorPresenca.cpp
*	Autor: Jullierme Barros
*/

#include "Arduino.h"
#include "JsbIotSensorPresenca.h"

JsbIotSensorPresenca::JsbIotSensorPresenca(int pinSensorPresenca, int pinRele){
	_pinSensorPresenca = pinSensorPresenca;
	_pinRele = pinRele;

	pinMode(pinRele, OUTPUT); //saida - relé
	pinMode(pinSensorPresenca, INPUT); // entrada - sensor presença
}

void JsbIotSensorPresenca::ativarDelayDe1Segundo(){
	_ativarDelayDe1Segundo = true;
}

void JsbIotSensorPresenca::desativarDelayDe1Segundo(){
	_ativarDelayDe1Segundo = false;
}

void JsbIotSensorPresenca::ativarLog(){
	_ativarLog = true;
}

void JsbIotSensorPresenca::desativarLog(){
	_ativarLog = false;
}

bool JsbIotSensorPresenca::isAtivarDelayDe1Segundo(){
	return _ativarDelayDe1Segundo;
}

int JsbIotSensorPresenca::getTempoMinimoLuzAcesa(){
	return _tempoEmMilessegundos;
}

void JsbIotSensorPresenca::setTempoMinimoLuzAcesa(int tempoEmMilessegundos){
	_tempoEmMilessegundos = tempoEmMilessegundos;
}

bool JsbIotSensorPresenca::isSensorAtivo(){
	return _isSensorInativo == false;
}

void JsbIotSensorPresenca::desativaSensor(){
	_isSensorInativo = true;
}

void JsbIotSensorPresenca::ativaSensor(){
	_isSensorInativo = false;
}

void JsbIotSensorPresenca::executar(){
	if(_isSensorInativo == false){
		_VALOR_SENSOR_PRESENCA = digitalRead(_pinSensorPresenca);

		if (_VALOR_SENSOR_PRESENCA == HIGH) {
			_contadorDeTempoQueDevePermanecerLigado = _tempoEmMilessegundos;

			if(_ativarLog){
				Serial.print("Movimento detectado. O sensor de presença vai ser desligado em ");
				Serial.println(_contadorDeTempoQueDevePermanecerLigado/_UM_SEGUNDO);
			}

			digitalWrite(_pinRele, _ACIONA_RELE);
		}
		else {
			if(_contadorDeTempoQueDevePermanecerLigado > 0){
				if(_ativarLog){
					Serial.print("O sensor de presença vai ser desligado em ");
					Serial.println(_contadorDeTempoQueDevePermanecerLigado/_UM_SEGUNDO);
				}

				_contadorDeTempoQueDevePermanecerLigado -= _UM_SEGUNDO;
			}
			else{
				digitalWrite(_pinRele, _DESLIGA_RELE);
			}
		}

		if(_ativarDelayDe1Segundo){
			delay(_UM_SEGUNDO);
		}
	}
}
