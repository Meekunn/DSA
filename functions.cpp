#include <iostream>

int add (int a, int b) {
	return a + b;
}

int subtract (int a, int b) {
	return a - b;
}

int product (int a, int b) {
	return a * b;
}

float divide (int a, int b) {
	return a / (float)b;
}

int main() {

	int a, b, sum, minus, multiply;
	float div;

	std::cout << "Input the first integer: ";
	std::cin >> a;
	std::cout << "Input the second integer: ";
	std::cin >> b;

	sum = add(a, b);
	minus = subtract(a, b);
	div = divide(a, b);
	multiply = product(a, b);

	std::cout << "The sum of " << a << " and " << b << " is " << sum << "." << std::endl;
	std::cout << "The subtraction of " << a << " from " << b << " is " << minus << "." << std::endl;
	std::cout << "The product of " << a << " and " << b << " is " << multiply << "." << std::endl;
	std::cout << "The division of " << a << " and " << b << " is " << div << "." << std::endl;

	return 0;
}