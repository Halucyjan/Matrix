#include "Matrix.h"
#include <iostream>
#include "main.h"
#include <filesystem>

int main()
{
    std::vector<double> row;
    row.resize(5, 1);

    std::vector<std::vector<double> > tab2d;
    tab2d.resize(4, row);
    row.~vector();

    for (int i = 0; i < tab2d.size(); i++)
        for (int j = 0; j < tab2d[i].size(); j++)
            tab2d[i][j] = (int)(i*j);

    Matrix mat1(tab2d);
    mat1.print();
    std::cout << std::endl;
    Matrix mat2(mat1);
    Matrix mat3(4,5);
    mat2.add(mat1);
    mat2.print();
    std::cout << std::endl;
    mat1.add(mat1);
    mat1.print();
    std::cout << std::endl;
    mat3 = mat1;
    mat1.subtract(mat1);
    mat1.print();
    std::cout << std::endl;
    //mat3 = mat1;
    mat3.print();
    std::cout << std::endl;

    std::cout << std::endl;

    for (int i = 0; i < tab2d.size(); i++)
    {
        for (int j = 0; j < tab2d[i].size(); j++)
            std::cout << tab2d[i][j] << " ";
        std::cout << std::endl;
    }
}