// int resPin = 3;
// int indusPin = 4;
// int comPin = 6;
// int uniPin = 7;
int pins[4] = {3, 4, 6, 7};
int arr[8][4] = {{1, 1, 0, 1}, {0, 1, 1, 1}, {0, 1, 1, 1}, {0, 1, 1, 1}, {1, 0, 1, 1}, {1, 0, 0, 1}, {0, 1, 0, 0}, {1, 1, 0, 0}};

void setup() {
	pinMode(pins[0], OUTPUT);
	pinMode(pins[1], OUTPUT);
	pinMode(pins[2], OUTPUT);
	pinMode(pins[3], OUTPUT);
}

void loop() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			digitalWrite(pins[j], arr[i][j]);
		}
		delay(5000);
	}
}
	// for (int hour = 0; hour < 24; hour++) {
	// 	if()
	// }