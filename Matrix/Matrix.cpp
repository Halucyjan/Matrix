#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	std::cout << "give width: ";
	std::cin >> this->width;
	std::cout << "give height: ";
	std::cin >> this->height;
	this->mat = std::make_unique < std::unique_ptr<double[]> []> (this->height);

	for (int i = 0; i < this->height; i++)
		this->mat[i] = std::make_unique<double[]>(this->width);
}

Matrix::Matrix(int W, int H)
	:width(W), height(H)
{
	this->mat = std::make_unique < std::unique_ptr<double[]>[]>(this->height);

	for (int i = 0; i < this->height; i++)
		this->mat[i] = std::make_unique<double[]>(this->width);
}

Matrix::Matrix(const Matrix& other)
	:width(other.width), height(other.height)
{
	this->mat = std::make_unique < std::unique_ptr<double[]>[]>(this->height);

	for (int i = 0; i < this->height; i++)
		this->mat[i] = std::make_unique<double[]>(this->width);

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			this->mat[i][j] = other.mat[i][j];
}

void Matrix::print() const
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			std::cout << mat[i][j] << " ";
		std::cout << std::endl;
	}
}

//Matrix& Matrix::operator=(const Matrix& other)
//{
//	if (this->height == other.height and this->width == other.width)
//	{
//		for (int i = 0; i < height; i++)
//			for (int j = 0; j < width; j++)
//				 this->mat[i][j] = other.mat[i][j];	
//		return *this;
//	}
//	else
//	{
//		std::cout << "(=) invalid matrix size!\n";
//		return *this;
//	}
//}
