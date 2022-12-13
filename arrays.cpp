#include <iostream>

// an array of 10 integers.  
// If arr[0] is stored at
// address x, then arr[1] is
// stored at x + sizeof(int)
// arr[2] is stored at x + 
// sizeof(int) + sizeof(int)
// and so on.

int *array (int length) {
	int *intArr = new int[length];

	for (int i = 0; i < length; i++) {
		intArr[i] = length * (i + 1);
	}

	return intArr;
}

int main () {

	int length;

	std::cout << "Input the length of the array: ";
	std::cin >> length;

	int *result = array(length);

	for ( int i = 0; i < length; i++) {
		if (i == length - 1 ) std::cout << result[i] << std::endl; 
		else std::cout << result[i] << ", ";
	}

	// int listArray [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	return 0;
}