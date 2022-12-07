#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>

class Matrix
{
public:
	//TODO
	//find error in constructor, and add new one

	//dynamic matrix define by user, during program run
	Matrix();
	//create matrix filled by zeros
	Matrix(int awidth, int aheight);
	//copy other matrix ?? i dont rememebr
	Matrix(const std::vector<std::vector<double> >& otherMatrix);
	//creating matrix from 2d vector?? dont rememebr
	Matrix(const Matrix& other);
	//probably i dont need this destructor
	~Matrix();

	//function to show matrix
	void print() const;

	//basics operations
	void add(const Matrix& other);
	void subtract(const Matrix& other);
	void multiply(const Matrix& other);

	//other operations
	int determinant();
	bool MatrixIsSquare() const;
	float getValue(int w, int h);
	Matrix transpose();

	//operators overloads
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	//overload <<operator to make "std::cout <<" works
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

