/*
	Write a program that converts a given decimal integer to binary.
*/

#include <iostream>
#include <vector>

void reverseResult(std::string result) {

	int arrLength = result.length();
	std::string reversed = "";
	
	for (int i = arrLength; i >= 0; i--) {
		reversed += result[i];
	}

	std::cout << "The result in string is " << reversed << std::endl;
}

void convertDecToBit(int decimal) {

	std::string result = "";

	int param = decimal;
	int mod;

	for(int i = 0; param > 0; i++) {
		mod = param % 2;
		param /= 2; 
		result += std::to_string(mod);
	}

	reverseResult(result);

}

int main() {

	int decimal, ans;

	std::cout << "Input an integer in base 10: ";
	std::cin >> decimal;

	// decimal /= 2;
	// std::cout << decimal << std::endl;

	convertDecToBit(decimal);

	return 0;
}