#include <iostream>
#include <math.h>
#include <iomanip> //This header is used the manipulate the output of streams.(Parametric manipulators).

class Vector {
	public:
		Vector() {
			this->size = 3;
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}
		~Vector(){};

		void editSize(int size) {
			this->size = size;
		}
		void updateX(float x) {
			this->x = x;
		}

		void updateY(float y) {
			this->y = y;
		}

		void updateZ(float z) {
			this->z = z;
		}

		void insert(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector scalarMul(float scalar) {
			Vector xyz;
			xyz.x = this->x * scalar;
			xyz.y = this->y * scalar;
			xyz.z = this->z * scalar;

			return xyz;
		}

		Vector sumVectors(Vector xyz) {
			Vector result;
			result.x = this->x + xyz.x;
			result.y = this->y + xyz.y;
			result.z = this->z + xyz.z;
			return result;
		}

		Vector minusVectors(Vector xyz) {
			Vector result;
			result.x = this->x - xyz.x;
			result.y = this->y - xyz.y;
			result.z = this->z - xyz.z;
			return result;
		}

		float magnitude() {
			float result = sqrt(((this->x) * (this->x)) + ((this->y) * (this->y)) + ((this->z) * (this->z)));
			return result;
		}

		Vector crossProduct(Vector xyz) {
			Vector result;
			result.x = ((this->y) * xyz.z) - ((this->z) * xyz.y);
			result.y = ((this->z) * xyz.x) - ((this->x) * xyz.z);
			result.z = ((this->x) * xyz.y) - ((this->x) * xyz.y);
			return result;
		}

		float dotProduct (Vector xyz) {
			float result;
			result = this->x * xyz.x;
			result += (this->y * xyz.y);
			result += (this->z * xyz.z);
			return result;
		}

		void displayVector() {
			std::cout << "[" << std::fixed << std::setprecision(2) << this->x << ", " << std::fixed << std::setprecision(2) << this->y << ", " << std::fixed << std::setprecision(2) << this->z << "]." << std::endl;
			//return "The vector [" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + "]";
		}

	private:
		int size;
		float x;
		float y;
		float z;
};

int main() {

	Vector vector_a, vector_b, scalar_mul, sum_of_vectors, diff_of_vectors, cross_prod;
	float *arr1 = new float[3];
	float *arr2 = new float[3];
	float scalar, dot_prod;
	float test = 2.35700;

	std::cout << "Input the scalar value: ";
	std::cin >> scalar;

	std::cout << "Input the x value of the vector A: ";
	std::cin >> arr1[0];
	std::cout << "Input the y value of the vector A: ";
	std::cin >> arr1[1];
	std::cout << "Input the z value of the vector A: ";
	std::cin >> arr1[2];
	vector_a.insert(arr1[0], arr1[1], arr1[2]);


	std::cout << "Input the x value of the vector B: ";
	std::cin >> arr2[0];
	std::cout << "Input the y value of the vector B: ";
	std::cin >> arr2[1];
	std::cout << "Input the z value of the vector B: ";
	std::cin >> arr2[2];
	vector_b.insert(arr2[0], arr2[1], arr2[2]);

	scalar_mul = vector_a.scalarMul(scalar);
	sum_of_vectors = vector_a.sumVectors(vector_b);
	diff_of_vectors = vector_a.minusVectors(vector_b);
	cross_prod = vector_a.crossProduct(vector_b);
	dot_prod = vector_a.dotProduct(vector_b);

	std::cout << "The scalar multiplication of vector A and scalar " << scalar << " is ";
	scalar_mul.displayVector();
	std::cout << "The sum of vector A and vector B is ";
	sum_of_vectors.displayVector();
	std::cout << "The subtraction of vector B from vector A is ";
	diff_of_vectors.displayVector();
	std::cout << "The cross product of vector A and vector B is ";
	cross_prod.displayVector();
	std::cout << "The dot product of vector A and vector B is " << dot_prod << std::endl;

	return 0;
}