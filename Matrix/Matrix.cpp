#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	std::cout << "give width: ";
	std::cin >> this->width;
	std::cout << "give height: ";
	std::cin >> this->height;

	std::vector<double> matrixRow;
	matrixRow.resize(width, 0);
	matrixTab.resize(height, matrixRow);
}

Matrix::Matrix(int awidth, int aheight)
	:width(awidth), height(aheight)
{
	std::vector<double> matrixRow;
	matrixRow.resize(width, 0);
	matrixTab.resize(height, matrixRow);
}

Matrix::Matrix(const std::vector<std::vector<double>>& otherMatrix)
	:width(otherMatrix.size()), height(otherMatrix[0].size())
{
	this->matrixTab = otherMatrix;
}

Matrix::Matrix(const Matrix& other)
	:width(other.width), height(other.height)
{
			this->matrixTab = other.matrixTab;
}

Matrix::~Matrix()
{
	//std::cout << "destructor" << std::endl;
}

void Matrix::print() const
{
	for (int i = 0; i < matrixTab.size(); i++)
	{
		for (int j = 0; j < matrixTab[i].size(); j++)
			std::cout << matrixTab[i][j] << " ";
		std::cout << std::endl;
	}
}

void Matrix::add(const Matrix& other)
{
	if (this->height == other.height and this->width == other.width)
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				this->matrixTab[i][j] = this->matrixTab[i][j] + other.matrixTab[i][j];
	}
	else{	std::cout << "(add) invalid matrix size!\n";	}
}

void Matrix::subtract(const Matrix& other)
{
	if (this->height == other.height and this->width == other.width)
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				this->matrixTab[i][j] = this->matrixTab[i][j] - other.matrixTab[i][j];
	}
	else { std::cout << "(subtract) invalid matrix size!\n"; }
}

void Matrix::multiply(const Matrix& other)
{
	if (this->width == other.height)
	{
		Matrix temp(other.width, this->height);

		for(int i = 0; i <temp.width; i++)
			for (int j = 0; j < temp.height; j++)
			{
				double tempDouble = 0;
				
				for (int k = 0; k < temp.width; k++)
					tempDouble += this->matrixTab[k][j] * other.matrixTab[i][k];

					temp.matrixTab[i][j] = tempDouble;
			}
		*this = temp;
	}
	else
		throw std::invalid_argument("(multiply) invalid matrix size!\n"); 
}

bool Matrix::MatrixIsSquare() const
{
	if (this->width == this->height)
		return true;
	else
		return false;
}

int Matrix::determinant()
{
	if (!this->MatrixIsSquare())
	{	
		throw std::invalid_argument("Matrix must be square");
	}
	else if(this->width == 1)
	{
		return this->det1x1();
	}
	else if(this->width == 2)
	{
		return det2x2(*this);
	}
	else
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
			{

			}
	}
		
}



float Matrix::det(Matrix mat)
{
	return 0;
}

float Matrix::det2x2(Matrix mat2x2)
{
	return (mat2x2.getValue(0,0) * mat2x2.getValue(1,1)) - (mat2x2.getValue(1, 0) * mat2x2.getValue(0, 1));
}

float Matrix::det1x1()
{
	return this->matrixTab[0][0];
}

float Matrix::getValue(int w, int h)
{
	return this->matrixTab[w][h];
}

Matrix Matrix::transpose()
{
	//this is weird, but its work
	//probably something with constructor is broken
	Matrix temp(this->width, this->height);
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			temp.matrixTab[j][i] = matrixTab[i][j];
		}
	return temp;
}

Matrix Matrix::operator+(const Matrix& other)
{
	if (this->height == other.height and this->width == other.width)
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				this->matrixTab[i][j] = this->matrixTab[i][j] + other.matrixTab[i][j];
		return *this;
	}
	else { throw std::invalid_argument("(+) invalid matrix size!\n"); }
}

Matrix Matrix::operator-(const Matrix& other)
{
	if (this->height == other.height and this->width == other.width)
	{
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				this->matrixTab[i][j] = this->matrixTab[i][j] - other.matrixTab[i][j];
		return *this;
	}
	else { throw std::invalid_argument("(-) invalid matrix size!\n"); }
}

Matrix Matrix::operator*(const Matrix& other)
{
	if (this->width == other.height)
	{
		Matrix temp(other.width, this->height);

		for (int i = 0; i < temp.width; i++)
			for (int j = 0; j < temp.height; j++)
			{
				double tempDouble = 0;

				for (int k = 0; k < temp.width; k++)
					tempDouble += this->matrixTab[k][j] * other.matrixTab[i][k];

				temp.matrixTab[i][j] = tempDouble;
			}
		//*this = temp;
		return temp;
	}
	else { throw std::invalid_argument("(multiply) invalid matrix size!\n"); }
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat)
{
	mat.print();
	return os;
}
