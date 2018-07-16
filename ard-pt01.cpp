 	void setup(){
 		pinMode(10, OUTPUT);
 		pinMode(9, OUTPUT);
 		pinMode(7, INPUT);
 		pinMode(7, INPUT_PULLUP);
 	}

 	void loop(){


 		digitalWrite(10, HIGH);
 		digitalWrite(9, HIGH);
 		delay(1000);


 		int estado = digitaRead(7);

 		digitalWrite(10, estado);
 		digitalWrite(9, !estado);
 		delay(1000);

 	}