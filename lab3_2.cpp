#include <iostream>

extern "C"
{
    void __cdecl Mult(int* arr1, int* arr2, int n, int* res2);
    int __cdecl Triangle(int a, int b, int c);
    int __cdecl Equation(int a, int b, int c, int y, int one, int ndiv, int nmod, int temp,
        int mult, int ndiv1, int nmod1, int temp1, int mult1);
}

int main()
{

    //////////  TASK 1  /////////////

    int a1, b1, c1, y;
    int one = 1;
    int ndiv = 0, nmod = 0, temp = 0, mult = 0, ndiv1 = 0, nmod1 = 0, temp1 = 0, mult1 = 0;
    std::cout << "Enter a, b, c, y: ";
    std::cin >> a1 >> b1 >> c1 >> y;
    std::cout << "\"x\" after rounding = " << Equation(a1, b1, c1, y, one, ndiv, nmod, temp, mult, ndiv1, nmod1, temp1, mult1) << std::endl;






    //////////  TASK 2.1    /////////////

    int a, b, c;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;
    if (Triangle(a, b, c) == 0)
    {
        std::cout << "No!" << std::endl;
    }
    if (Triangle(a, b, c) == 1)
    {
        std::cout << "Yes!" << std::endl;
    }



    /////////// TASK 2.2    /////////////

    int res2[3] = { 0, 0, 0 };
    int n;
    std::cout << "Enter a number of elements: ";
    std::cin >> n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr1[i];
        std::cin >> arr2[i];
    }
    Mult(arr1, arr2, n, res2);
    std::cout << res2[0] << std::endl;
    return 0;
}
