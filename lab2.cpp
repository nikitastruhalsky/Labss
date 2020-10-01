#include <iostream>
#include <cstdlib>
#include <iomanip>
int main()
{
    const int size = 20;
    std::cout << "Size = " << size << std::endl;
    int n;
    std::cout << "Enter a number of elements: ";
    std::cin >> n;
    if (n < 1)
    {
        std::cout << "Mistake! Number of elements should be minimum 1. Try again!" << std::endl;
        return 0;
    }
    if (n > size)
    {
        std::cout << "Mistake! Number of elements can't be more than Size. Try again!" << std::endl;
        return 0;
    }
    int *arr = new int [n];
    int choice;
    std::cout << "If you want to enter massive elements by yourself, press 1" << std::endl;
    std::cout << "If you want to have random elements, press 2" << std::endl;
    std::cin >> choice;
    if ((choice != 1) && (choice != 2))
    {
        std::cout << "Mistake. Try again!" << std::endl;
        return 0;
    }
    else
    {
        switch (choice)
        {
            case 1:
            {
                std::cout << "These elements: ";
                for (int i = 0; i < n; ++i)
                {
                    std::cin >> arr[i];
                }
                break;
            }
            case 2:
            {
                int a = 0;
                int b = 0;
                std::cout << "Enter number a (lower border of a random): " << std::endl;
                std::cin >> a;
                std::cout << "Enter number b (upper border of a random): " << std::endl;
                std::cin >> b;
                std::cout << "These elements: ";
                for (int i = 0; i < n; ++i)
                {
                    arr[i] = rand() % (b - a) + a;
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
    int sign_change = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (((arr[i] >= 0) && (arr[i + 1] < 0)) || ((arr[i] < 0) && (arr[i + 1] >= 0)))
        {
            sign_change++;
        }
    }
    std::cout << "A number of sign changes is: " << sign_change << std::endl;
    int first_zero = 0, second_zero = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 0)
        {
            first_zero = i + 1;
            break;
        }
    }
    for (int j = first_zero; j < n; ++j)
    {
        if (arr[j] == 0)
        {
            second_zero = j;
            break;
        }
    }
    double multipl = 1;
    for (int i = first_zero; i < second_zero; ++i)
    {
        multipl = multipl * arr[i];
    }
    if ((first_zero == 0) || (second_zero == 0))
    {
        std::cout << "Not enough 'zero' elements in the massive" << std::endl;
    }
    else
    {
        std::cout << "The product of the required elements is: " << multipl << std::endl;
    }
    /*for (int i = n - 1; i >= 0; --i)
    {
        if (arr[i] % 2 == 0)
        {
            //for (int j = 0; j < n; ++j)
            //{
                std::swap(arr[0], arr[i]);
            //}
        }
    }*/
    int swapped = 0;
    int sorted = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((arr[i] % 2 == 1) || (arr[i] % 2 == -1))
        {
            break;
        }
        else
        {
            sorted++;
        }
    }
    for (int i = sorted; i < n; ++i)
    {
        if (arr[i] % 2 == 0)
        {
            for (int j = i; j > (swapped + sorted); --j)
            {
                std::swap(arr[j], arr[j - 1]);
            }
            swapped++;
        }
    }
    std::cout << "New massive: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
