#include <iostream>
#include "ProperFraction.h"

int main()
{
    ProperFraction first (4, 12);
    std::cout << "First proper fraction: ";
    first.print();
    ProperFraction copy (first);
    std::cout << "Its copy: ";
    copy.print();
    ProperFraction second(-8, 12);
    std::cout << "Second proper fraction: ";
    second.print();
    //first.Add(second);
    //std::cout << "Their sum is: ";
    //first.print();
    //first.Multiply(second);
    //std::cout << "Their composition is: ";
    //first.print();
    //first.Divide(second);
    //std::cout << "Their quotient is: ";
    //first.print();
    return 0;
}