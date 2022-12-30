/*
	Write a program that converts a given decimal integer to binary.
*/

#include <iostream>
#include <math.h>

void reverseResult(std::string result) {

	int arrLength = result.length();
	std::string reversed = "";
	
	for (int i = arrLength; i >= 0; i--) {
		reversed += result[i];
	}

	std::cout << "The result in string is " << reversed << std::endl;
}

// void convertDecToBit(int decimal) {

// 	std::string result = "";

// 	int param = decimal;
// 	int mod;

// 	for(int i = 0; param > 0; i++) {
// 		mod = param % 2;
// 		param /= 2; 
// 		result += std::to_string(mod);
// 	}

// 	reverseResult(result);

// }

// Correction

int optimal_no_bits( int decimal) {
	return (decimal == 0) ? 1 : (decimal < 0) ? (log2(-1*decimal) + 1) : (log2(decimal*1) + 1);
}

int* convertDecToBit(int decimal) {
	int n = optimal_no_bits(decimal);
	int *result = new int[n];

	int dec = decimal;
	while(n >= 0){
		result[n - 1] = dec % 2;
		dec = dec / 2;
		n--;
	}
	return result;
}

int main() {

	int decimal, ans;

	std::cout << "Input an integer in base 10: ";
	std::cin >> decimal;

	int *result = convertDecToBit(decimal);
	for(int i = 0; i < optimal_no_bits(decimal); i++)
		std::cout << result[i];
	std::cout<<std::endl;

	return 0;
}