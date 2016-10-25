#ifndef _MATRIX_
#define _MATRIX_ 

#include <vector>
#include <iostream>

template <class T>
class Matrix {
private:
	int rows, columns;
	std::vector<std::vector<T>> matrix;

public:
	Matrix() : rows{1}, columns{1} {
		this->matrix = {{0}};
	}

	Matrix(int rows, int columns) : rows{rows}, columns{columns} {
		for (int i = 0; i < this->rows; ++i)
		{	
			std::vector<T> row;
			for (int j = 0; j < this->columns; ++j)
			{
				row.push_back(0);
			}
			this->matrix.push_back(row);
		}
	}

	void operator=(const Matrix<T>& right) {
		rows = right.rows;
		columns = right.columns;

		this->matrix.resize(rows);
		for (const auto& row : this->matrix) {
			row.resize(columns);
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				this->matrix[i][j] = right[i][j];
			}
		}
	}

	void operator=(std::vector<std::vector<T>>&& right) {
		rows = right.size();
		columns = right[0].size();

		this->matrix.resize(rows);
		for (const auto& row : this->matrix) {
			row.resize(columns);
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				this->matrix[i][j] = right[i][j];
			}
		}

	}

	Matrix<T> dot(const Matrix<T>& right) {
		Matrix<T> result(this->rows, right.columns);
		
		for (int i = 0; i < result.columns; ++i)
		{
			for (int k = 0; k < this->rows; ++k)
			{
				T sum = 0;
				for (int m = 0; m < this->columns; ++m)
				{
					sum += this->matrix[k][m] * right[m][i];
				}
				result[k][i] = sum;
				
			}
		}

		return result;
	} 

	std::vector<T>& operator[](int index) {
		return this->matrix[index];
	}

	Matrix<T> operator*(double n) {
		Matrix<T> result;
		result.matrix = this->matrix;
		result.rows = this->rows;
		result.columns = this->columns;

		for (auto& row : result.matrix) {
			for (auto& column : row) {
				column *= n;
			}
		}
		return result;
	}


	void print() {
		for (int i = 0; i < this->rows; ++i)
		{
			std::cout << "[";
			for (int j = 0; j < this->columns; ++j)
			{
				std::cout << " " << this->matrix[i][j] << " ";
			}
			std::cout << "]\n";
		}
		std::cout << std::endl;
	}
};


#endif