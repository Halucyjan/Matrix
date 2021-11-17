#include "Matrix.h"
#include <iostream>
#include "main.h"

int main()
{
    Matrix mat1(3,4);
    mat1.print();
    std::cout << "Hello World!\n";
    Matrix mat2(5,8);
    //mat2 = mat1;
    mat2.print();
}