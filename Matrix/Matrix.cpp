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

Matrix::Matrix(int Width, int Height)
	:width(Width), height(Height)
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
	//std::cout << "destruktor" << std::endl;
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
	else{ std::cout << "(multiply) invalid matrix size!\n"; }
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
	else { std::cout << "(+) invalid matrix size!\n"; }
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
	else { std::cout << "(-) invalid matrix size!\n"; }
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
	else { std::cout << "(multiply) invalid matrix size!\n"; }
}
