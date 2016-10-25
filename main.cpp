#include "matrix.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	Matrix<float> matrix1(3, 2);
	matrix1 = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
	matrix1.print();

	Matrix<float> matrix2(2, 2);
	matrix2 = {
		{1,2},
		{3,4},
		{5,6},
		{7,8},
		{9, 10}
	};

	matrix2.print();

	Matrix<float> result = matrix1.dot(matrix2);
	result.print();

	Matrix<double> matrix3(1, 1);
	matrix3 = {{1,2},{3,4}};
	matrix3.print();

	matrix3.dot(matrix3).print();

	Matrix<int> matrix4;
	matrix4.print();

	matrix3 = matrix3 * 2.6;
	matrix3.print();
	return 0;
}