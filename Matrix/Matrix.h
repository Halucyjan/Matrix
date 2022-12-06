#pragma once

#include <memory>
#include <vector>
#include <iostream>

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
	int determinant();
	bool MatrixIsSquare() const;
	float getValue(int w, int h);
	Matrix transpose();


	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);

	friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);



private:
	//determinant function
	float det(Matrix);
	float det1x1();
	float det2x2(Matrix mat2x2);
	
	//variables
	std::vector<std::vector<double> > matrixTab;
	int width, height;
};

