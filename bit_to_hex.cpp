#include <iostream>
#include <math.h>
#include "bitdec.h"

int convertToDec(int binary, int n) {

	int *intArr = convertIntToArr(binary, n);
	int decimal = convertBitToDec(intArr, n);
	
	return decimal;
}

char* convertDecToHex(int dec, int no_of_el) {
	char *result = new char[no_of_el];
	int decimal = dec;

	for (int i = no_of_el - 1; i >= 0; i--) {
		int mod = decimal % 16;
		if (mod >= 0 && mod < 10) {
			result[i] = mod + '0';
			std::cout << result[i] << std::endl;
		}
		else if (mod == 10)
			result[i] = 'A';
		else if (mod == 11)
			result[i] = 'B';
		else if (mod == 12)
			result[i] = 'C';
		else if (mod == 13)
			result[i] = 'D';
		else if (mod == 14)
			result[i] = 'E';
		else if (mod == 15)
			result[i] = 'F';
		else
			std::cout << "sth is wrong" << std::endl;
		decimal = decimal / 16;
	}
	std::cout << *result << std::endl;
	return result;
}

int main() {
	int binary, n, dec;

	std::cout << "Enter binary digits: ";
	std::cin >> binary;

	n = no_of_bits(binary);

	float no_of_el = ceil(n / 4.0);
	//std::cout << "no_of_el" << no_of_el << std::endl;

	dec = convertToDec(binary, n);
	char *hex = convertDecToHex(dec, no_of_el);

	std::cout << "Th hexadecimal equivalent is " << hex << std::endl;
	for (int i = 0; i < no_of_el; i++)
	{
		std::cout << hex[i];
	}

	return 0;
}