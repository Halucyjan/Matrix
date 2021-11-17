#pragma once

#include <memory>

class Matrix
{
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix& other);
	void print() const;
	void add(const Matrix& other);
	void subtract(const Matrix& other);
	void multiply(const Matrix& other);

	//Matrix& operator=(const Matrix&);


private:
	std::unique_ptr<std::unique_ptr<double[]> []> mat;
	int width, height;
};

