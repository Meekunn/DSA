/*
	Write a program that computes the nth fibonacci number. 
	This program takes an integer, n, as input and it outputs the nth fibonacci number as the result.

	fibonacci_series = [0, 1, 1, 2, 3, 5, 8]
	fibonacci(6) = 8
*/

#include <iostream>

unsigned long long int fibonacci ( int nth) {
	unsigned long long int a = 0;
	unsigned long long int b = 1;
	unsigned long long int c;

	for(int i = 2; i < nth+1 ; i++ ) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

//refactoring
unsigned long long int  r_fibonacci (int nth) {
	if (nth <= 0) return 0;
	else if ( nth == 1) return 1;
	else return r_fibonacci(nth - 1) + r_fibonacci(nth - 2);
}

unsigned long long int* fibonacci_series(int nth) {
	unsigned long long int  a = 0;
	unsigned long long int  b = 1;
	unsigned long long int  c;
	unsigned long long int  *series = new unsigned long long int[nth + 1];
	series[0] = a;
	series[1] = b;
	
	for(int i = 2; i < nth+1 ; i++ ) {
		c = a + b;
		a = b;
		b = c;
		series[i] = c;
	}

	return series;
}

int main() {

	int nth;
	unsigned long long int *series, result;

	std::cout << "Input the nth fibonacci number: ";
	std::cin >> nth;

	result = r_fibonacci(nth);
	series = fibonacci_series(nth);
	
	for (int i = 0; i < nth + 1; i++) {
		if (nth == 0) std::cout << "The fibonacci series is [" << series[i] << "]";
		else if ( i == 0) std::cout << "The fibonacci series is [" << series[i] << ", ";
		else if ( i == nth) std::cout << series[i] << "]";
		else std::cout << series[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << "The fibonacci number is " << result << std::endl;

	return 0;
}