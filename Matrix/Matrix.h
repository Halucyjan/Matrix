#pragma once

#include <memory>
#include <vector>

class Matrix
{
public:
	Matrix();
	Matrix(int, int);
	Matrix(const std::vector<std::vector<double> >& otherMatrix);
	Matrix(const Matrix& other);
	~Matrix();

	void print() const;
	void add(const Matrix& other);
	void subtract(const Matrix& other);
	void multiply(const Matrix& other);

	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);


private:
	std::vector<std::vector<double> > matrixTab;
	int width, height;
};

