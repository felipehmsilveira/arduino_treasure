byte valorX;
byte valorY;
byte valorZ;

void setup() {
	Serial.begin(9600);

	valorX = 10;
	valorY = 500;
	valorZ = valorX + valorY;

	Serial.print("ValorX");
	Serial.print(valorX);

	Serial.print("Valory");
	Serial.print(valorY);

	Serial.print("ValorZ");
	Serial.println(valorZ);
}