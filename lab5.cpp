#include <iostream>

extern "C"
{
    int __cdecl Arcsin (float x);
    float __cdecl Task2 (float x, float eps);
}

int main()
{
    /*float x, eps, result = 0;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << Arcsin(x) << std::endl;
    std::cout << "Enter an epsilon: ";
    std::cin >> eps;*/
    std::cout << Task2(2, 0.2) << std::endl;
    return 0;
}