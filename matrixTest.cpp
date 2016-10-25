#include <iostream>
#include "matrix.h"

int main(int argc, char const *argv[])
{
	Matrix<float> matrix(5,7, 1.2);
	/*std::cout << matrix << std::endl;*/
	auto shape = matrix.shape();
 	std::cout << shape[0] << " " << shape[1] << std::endl;
	return 0;
}