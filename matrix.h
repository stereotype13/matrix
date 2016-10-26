#ifndef _MATRIX_
#define _MATRIX_ 

#include <vector>
#include <iostream>

template <class T>
class Matrix {
private:
	int rows, columns;
	std::vector<std::vector<T>> matrix;

	void setSize(int rows, int columns) {
		size.rows = rows;
		size.columns = columns;
	}

public:
	struct Size {
		int rows, columns;
		int operator[](int index) {
			switch (index) {
				case 0:
				return rows;
				break;

				case 1:
				return columns;
			}
		}
	};

	Size size;

	Matrix() : rows{1}, columns{1} {
		this->matrix = {{0}};
		setSize(rows, columns);
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
		setSize(rows, columns);
	}

	Matrix(const Matrix<T>& right) : rows{right.rows}, columns{right.columns}, matrix{right.matrix} {}

	Matrix(Matrix<T>&& right) {
		std::swap(this->rows, right.rows);
		std::swap(this->columns, right.columns);
		std::swap(this->matrix, right.matrix);
		setSize(rows, columns);
	}

	Matrix(std::vector<std::vector<T>>&& right) {
		rows = right.size();
		columns = right[0].size();

		this->matrix = right;
		setSize(rows, columns);
	}

	void operator=(Matrix<T>& right) {
		rows = right.rows;
		columns = right.columns;
		setSize(rows, columns);

		this->matrix.resize(rows);
		for (auto& row : this->matrix) {
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

	void operator=(Matrix<T>&& right) {
		std::swap(rows, right.rows);
		std::swap(columns, right.columns);
		std::swap(matrix, right.matrix);
		setSize(rows, columns);
	}

	void operator=(std::vector<std::vector<T>>&& right) {
		rows = right.size();
		columns = right[0].size();

		std::swap(matrix, right);
		setSize(rows, columns);

	}

	Matrix<T> dot(Matrix<T>& right) {
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

	template <typename T2>
	Matrix<T> dot(Matrix<T2>& right) {
		Matrix<T> result(this->rows, right.size[1]);
		
		for (int i = 0; i < result.columns; ++i)
		{
			for (int k = 0; k < this->rows; ++k)
			{
				T sum = 0;
				for (int m = 0; m < this->columns; ++m)
				{
					sum += this->matrix[k][m] * (T)right[m][i];
				}
				result[k][i] = sum;
				
			}
		}

		return result;
	} 

	std::vector<T>& operator[](int index)  {
		return this->matrix[index];
	}

	Matrix<T> operator+(Matrix<T>& right) {
		Matrix<T> result;
		result.matrix = this->matrix;
		result.rows = this->rows;
		result.columns = this->columns;

		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->columns; ++j)
			{
				result[i][j] += right[i][j];
			}
		}
		return result;
	}

	Matrix<T> operator-(Matrix<T>& right) {
		Matrix<T> result;
		result.matrix = this->matrix;
		result.rows = this->rows;
		result.columns = this->columns;

		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->columns; ++j)
			{
				result[i][j] -= right[i][j];
			}
		}
		return result;
	}

	Matrix<T> operator*(Matrix<T>& right) {
		Matrix<T> result;
		result.matrix = this->matrix;
		result.rows = this->rows;
		result.columns = this->columns;

		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->columns; ++j)
			{
				result[i][j] *= right[i][j];
			}
		}
		return result;
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