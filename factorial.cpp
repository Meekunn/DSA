/* 
	Write a program that computes the factorial of a given integer. 
	This program takes an integer, n, as input and it outputs its factorial as the result. 
	Note: write a function factorial to implement this program.
*/

#include <iostream>

//Using unsigned long long int (64 bytes) allows higher value with a maximum of 65!.
//Using int data type allows a maximum of 33!.
//A calculator's memory space for storing integer is higher than that of the computer (64 bytes).

void factorial(int n) {

	unsigned long long int result = 1;

	for (int i = n; i > 0; i--) {
		result *= i;
	}
	
	std::cout << n << "! = " << result << "." << std::endl;

}

int main() {

	int n;
	std::cout << "Input an Integer: ";
	std::cin >> n;

	factorial(n);

	return 0;
}

//Time Complexity = O(n)
//where n is the number of times the loop is called; like the input n.
// and the time complexity increases linearly.
