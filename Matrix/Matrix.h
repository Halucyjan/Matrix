#pragma once

#include <memory>

class Matrix
{
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	void print() const;
	//Matrix& operator=(const Matrix&);


private:
	std::unique_ptr<std::unique_ptr<double[]> []> mat;
	int width, height;
};

