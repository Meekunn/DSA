#include <iostream>

int no_of_bits(int binary) {
	int count = 0;
	int number = binary;
	while(number!=0) {
		number = number/10;
		count++;
	}
	return count;
}

int* convertIntToArr(int binary, int n) {
	int *bin_arr = new int[n];
	int bits = binary;

	for(int i=0; i < n; i++) {
		bin_arr[i] = bits % 10;
		bits = bits / 10;
	}

	return bin_arr;
}

int convertBitToDec(int *arr, int n) {
	int decimal = 0;
	int power = 1;
	int j = 1;
	int mul;

	for(int i=0; i < n; i++) {
		while(j<=i){
			power *= 2;
			j++;
		}
		if (arr[i] > 1 || arr[i] < 0) {
			std::cout << "Binary should consists of only 0s and 1s" << std::endl;
			break;
		} else {
				if( i == 0) {
				mul = arr[i] * 1;
			} else {
				mul = arr[i] * power;
			}
		 decimal += mul;
		}
	}
	return decimal;
}

