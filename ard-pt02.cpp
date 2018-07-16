int pinVermelho = 10;
int pinAmarelo = 9;
int pinVerde = 8;
int pinBotao = 7;
int pinPedestreVermelho = 3;
int pinPedestreVerde = 2;

int faseSemaforo;

int estadoBotao;
int estadoAnteriorBotao;

int tempoPisca;
int estadoPisca;

void setup() {
	
	pinMode(pinVerde, OUTPUT);
	pinMode(pinAmarelo, OUTPUT);
	pinMode(pinVermelho, OUTPUT);
	pinMode(pinBotao, INPUT);
	pinMode(pinPedestreVerde, OUTPUT);
	pinMode(pinPedestreVermelho, OUTPUT);

	faseSemaforo = 1;

	estadoAnteriorBotao = digitalRead(pinBotao);
}

void loop() {

	estadoBotao = digitalRead(pinBotao);

	tempoPisca = 0;
	estadoPisca = HIGH;

	if ((estadoBotao == HIGH) && (estadoAnteriorBotao == LOW)) {
		
		if (faseSemaforo < 4) {
			faseSemaforo = faseSemaforo + 1;
		} else {
			faseSemaforo = 1;
		}
		

	}

	estadoAnteriorBotao = estadoBotao;

	if (faseSemaforo == 1) {	//SEMAFORO ABERTO (VERDE)
		digitalWrite(pinVerde, HIGH);
		digitalWrite(pinAmarelo, LOW);
		digitalWrite(pinVermelho, LOW);

		digitalWrite(pinPedestreVerde, LOW);
		digitalWrite(pinPedestreVermelho, HIGH);
	}

	if (faseSemaforo == 2) {	//SEMAFORO AMARELO
		digitalWrite(pinVerde, LOW);
		digitalWrite(pinAmarelo, HIGH);
		digitalWrite(pinVermelho, LOW);

		digitalWrite(pinPedestreVerde, LOW);
		digitalWrite(pinPedestreVermelho, HIGH);
	}

	if (faseSemaforo == 3) {	//SEMAFORO VERMELHO (VERMELHO)
		digitalWrite(pinVerde, LOW);
		digitalWrite(pinAmarelo, LOW);
		digitalWrite(pinVermelho, HIGH);

		digitalWrite(pinPedestreVerde, HIGH);
		digitalWrite(pinPedestreVermelho, LOW);
	}

	if (faseSemaforo == 4) {	//SEMAFORO PESDESTRE PISCANDO
		digitalWrite(pinVerde, LOW);
		digitalWrite(pinAmarelo, LOW);
		digitalWrite(pinVermelho, HIGH);

		tempoPisca = tempoPisca + 1;

		if (tempoPisca == 400) {
			estadoPisca = !estadoPisca;
			tempoPisca = 0;
		}

		digitalWrite(pinPedestreVerde, LOW);
		digitalWrite(pinPedestreVermelho, estadoPisca);
	}

	delay(1);
	
}