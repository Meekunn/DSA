// Recursion Factorial of an integer
// Another method to solve a recursion function is using *STACK method*.

#include <iostream>

int factorial(int n) {
	if(n <= 1) return 1;
	else return n * factorial(n-1);
}

int main() {

	int n, result;
	std::cout << "Input an Integer: ";
	std::cin >> n;

	result = factorial(n);
	std::cout << n << "! = " << result << "." << std::endl;

	return 0;
}