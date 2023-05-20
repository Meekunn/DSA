// Problem: Binary LED Converter

// You are tasked with creating an Arduino project that converts a decimal number to binary and displays the binary representation using three LEDs. The LEDs will represent the three least significant bits of the binary number, with each LED corresponding to a single bit (LED 1 represents the least significant bit, LED 3 represents the most significant bit).

// Write a program that performs the following steps:

// 1. Prompt the user to enter a decimal number between 0 and 7 (inclusive).
// 2. Read the decimal number entered by the user.
// 3. Convert the decimal number to its binary representation using a binary converting function.
// 4. Store the binary representation in an array.
// 5. Use three digital output pins on the Arduino to control the LEDs.
// 6. Turn on or off each LED based on the corresponding bits in the binary representation.
// If a bit is 1, turn on the corresponding LED.
// If a bit is 0, turn off the corresponding LED.
// 7. Display the binary representation using the LEDs.
// 8. Wait for a short delay before repeating the process.

#include <math.h>

//int arr[3];
void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.print("Enter a decimal number between 0 and 7 inclusive: ");
	Serial.print("\n");
	// reply only when you receive data:
  if (Serial.available() > 0) {
    int decimal = Serial.parseInt(); 
  }
}
int optimal_no_bits(int decimal) {
	return (decimal == 0) ? 1 : (decimal < 0) ? (log2(-1*decimal) + 1) : (log2(decimal*1) + 1);
}

int convertDecToBit(int decimal) {
	int n = optimal_no_bits(decimal);
	int result = new int[n];

	int dec = decimal;
	while(n >= 0){
		result[n - 1] = dec % 2;
		dec = dec / 2;
		n--;
	}
	return result;
}
