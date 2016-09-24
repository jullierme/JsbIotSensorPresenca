/*
*	JsbIotSensorPresenca.h
*	Autor: Jullierme Barros
*/

#ifndef JsbIotSensorPresenca_h
#define JsbIotSensorPresenca_h

#include "Arduino.h"

/*Ao adicionar um método aqui, add também em keywords.txt*/
class JsbIotSensorPresenca{
	public:
		JsbIotSensorPresenca(int pinSensorPresenca, int pinRele);
		void ativarLog();
		void desativarLog();
		void desativaSensor();
		void ativaSensor();
		bool isSensorAtivo();
		void executar();
		void setTempoMinimoLuzAcesa(int tempoEmMilessegundos);
		int getTempoMinimoLuzAcesa();
		void ativarDelayDe1Segundo();
		void desativarDelayDe1Segundo();
		bool isAtivarDelayDe1Segundo();

	private:
		int _pinSensorPresenca;
		int _pinRele;
		int _tempoEmMilessegundos = 15000;
		bool _isSensorInativo = false;
		bool _ativarLog = false;
		bool _ativarDelayDe1Segundo = true;
		short _VALOR_SENSOR_PRESENCA = 0;

		short _ACIONA_RELE = LOW;
		short _DESLIGA_RELE = HIGH;

		int _contadorDeTempoQueDevePermanecerLigado = 0;
		short _UM_SEGUNDO = 1000;
};

#endif
