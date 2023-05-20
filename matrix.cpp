#include <iostream>
#include <iomanip>

class Matrix {
	public:
		Matrix() {
			this->row = 2;
			this->col = 2;
			matrix = new float*[this->row];
			for (int i = 0; i < this->row; i++) {
				matrix[i] = new float[this->col];
			}
		}
		Matrix(int row, int col) {
			this->row = row;
			this->col = col;
			this->matrix = new float*[this->row];
			for (int i = 0; i < this->row; i++) {
				matrix[i] = new float[this->col];
			}
		}
		~Matrix() {
			for (int i = 0; i < this->row; i++) {
				delete matrix[i];
			}
			delete matrix;
		}
		void setValues() {
			for (int i = 0; i < this->row; i++) {
				for (int j = 0; j < this->col; j++) {
					std::cout << "Input value of row " << i + 1 << " column " << j + 1 << ": ";
					std::cin >> matrix[i][j];
				}
			}
		}
		void dispMatrix() {
			for (int i = 0; i < this->row; i++) {
				for (int j = 0; j < this->col; j++) {
					std::cout << std::fixed << std::setprecision(2) << this->matrix[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}
		Matrix scalarMul(int scalar) {
			Matrix result(this->row, this->col);
			//std::cout << "I ran2 " << std::endl;
			for (int i = 0; i < this->row; i++) {
				for (int j = 0; j < this->col; j++) {
					result.matrix[i][j] = this->matrix[i][j] * scalar;
				}
			}
			return result;
		}
		//passing (Matrix matrix2), by value causes segmentation error, why??
		Matrix addMatrices(Matrix& matrix2) {
			Matrix result(this->row, this->col);
			if (matrix2.row != this->row && matrix2.col != this->col) {
				std::cout << "The Two Matrices need to have the same number of rows and columns. " << std::endl;
			} else {
				for (int i = 0; i < this->row; i++){
					for (int j = 0; j < this->col; j++ ) {
						result.matrix[i][j] = this->matrix[i][j] + matrix2.matrix[i][j];
					}
				}
			}
			return result;
		}
		Matrix minusMatrices(Matrix& matrix2) {
			Matrix result(this->row, this->col);
			if (matrix2.row != this->row || matrix2.col != this->col) {
				std::cout << "The Two Matrices need to have the same number of rows and columns. " << std::endl;
			} else {
				for (int i = 0; i < this->row; i++){
					for (int j = 0; j < this->col; j++ ) {
						result.matrix[i][j] = this->matrix[i][j] - matrix2.matrix[i][j];
					}
				}
			}
			return result;
		}

		Matrix multiplyMatrices(Matrix& matrix2) {
			//std::cout << matrix2.col << std::endl;
			Matrix result(this->row, matrix2.col);
			if(this->col != matrix2.row) {
				std::cout << "The Two Matrices are not compatible " << std::endl;
			} else {
				for (int i = 0; i < this->row; i++) {
					for (int j = 0; j < matrix2.col; j++) {
						result.matrix[i][j] = 0;
						for (int k = 0; k < this->col; k++) {
							result.matrix[i][j] = result.matrix[i][j] + (this->matrix[i][k] * matrix2.matrix[k][j]);
						}
					}
				}
			}
			return result;
		}

	private:
		int row;
		int col;
		float **matrix;
};

int main() {

		float scalar;
		Matrix matrix(2, 2), matrix2(2,2), matrix3(2, 1);
		matrix.setValues();
		matrix.dispMatrix();

		//Scalar Multiplication
		// std::cout << "Input a scalar value: ";
		// std::cin >> scalar;
		// Matrix scalar_mul = matrix.scalarMul(scalar);
		// scalar_mul.dispMatrix();

		//Addition
		// matrix2.setValues();
		// matrix2.dispMatrix();
		// Matrix add_matrices = matrix.addMatrices(matrix2);
		// add_matrices.dispMatrix();

		//Subtraction
		// matrix2.setValues();
		// matrix2.dispMatrix();
		// Matrix minus_matrices = matrix.minusMatrices(matrix2);
		// minus_matrices.dispMatrix();

		//Subtraction
		matrix3.setValues();
		matrix3.dispMatrix();
		Matrix product_matrices = matrix.multiplyMatrices(matrix3);
		product_matrices.dispMatrix();

		return 0;
}

// Returns Segmentation error;
//  Matrix scalar_mul;
//  scalar_mul = matrix.scalarMul(2);