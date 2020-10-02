#include <iostream>
#include <cstdlib>

int dyn_matr(int** dynamicMatrix, int i, int j)
{
    if (j > i)
    {
        return dynamicMatrix[j][i];
    }
    else
    {
        return dynamicMatrix[i][j];
    }
}


int main()
{
    int A;
    std::cout << "Enter a number of lines and columns (between 1 and 10): ";
    std::cin >> A;
    if ((A > 10) || (A < 1))
    {
        std::cout << "Mistake! 'A' must be from 1 to 10. Try again!" << std::endl;
        return 0;
    }
    int fact = 0;
    for (int i = 1; i < A + 1; ++i)
    {
        fact += i;
    }
    int **dynamicMatrix = new int*[A];
    int choice;
    std::cout << "Press 1, if you want to enter the elements by yourself, press 2, if you want to use random: ";
    std::cin >> choice;
    switch (choice)
    {
        case 1:
        {
            int a = fact;
            std::cout << "Enter " << a << " elements:" << std::endl;
            for (int i = 0; i < A; ++i)
            {
                dynamicMatrix[i] = new int[i + 1];
                for (int j = 0; j < i + 1; ++j)
                {
                    std::cin >> dynamicMatrix[i][j];
                }
            }
            for (int i = 0; i < A; ++i)
            {
                for (int j = 0; j < A; ++j)
                {
                    if(j > i)
                    {
                        std::cout << dynamicMatrix[j][i] << "   ";
                    }
                    else
                    {
                        std::cout << dynamicMatrix[i][j] << "   ";
                    }
                }
                std::cout << std::endl;
            }
            break;
        }
        case 2:
        {
            int x = 0, y = 0;
            std::cout << "Enter x (lower border of a random): ";
            std::cin >> x;
            std::cout << "Enter y (upper border of a random): ";
            std::cin >> y;
            for (int i = 0; i < A; ++i)
            {
                dynamicMatrix[i] = new int[i + 1];
                for (int j = 0; j < i + 1; ++j)
                {
                    dynamicMatrix[i][j] = rand() % (y - x) + x;
                }
            }
            for (int i = 0; i < A; ++i)
            {
                for (int j = 0; j < A; ++j)
                {
                    if(j > i)
                    {
                        std::cout << dynamicMatrix[j][i] << "   ";
                    }
                    else
                    {
                        std::cout << dynamicMatrix[i][j] << "   ";
                    }
                }
                std::cout << std::endl;
            }
            break;
        }
        default:
        {
            std::cout << "Mistake! You should enter a number 1 or 2. Try again!" << std::endl;
            return 0;
        }
    }

    //TASK 2
    if (A == 1)
    {
        std::cout << "There are no elements to compare with." << std::endl;
        return 0;
    }
    int local_max = dynamicMatrix[0][0];
    int local_max_x = 0, local_max_y = 0;
    int no_local_max = 1;
    for (int i = 0; i < A; ++i)
    {
        for (int j = 0; j < A; ++j)
        {
            if ((i != 0) && (j != 0) && (i != A - 1) && (j != A - 1)
            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j))
            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j + 1))
            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j + 1))
            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j))
            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j - 1))
            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j - 1))
            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j + 1))
            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j - 1))
            && (dyn_matr(dynamicMatrix, i, j) > local_max))
            {
                local_max = dyn_matr(dynamicMatrix, i, j);
                local_max_x = i;
                local_max_y = j;
            }
            else
            {
                if ((i == 0) && (j != 0) && (j != A - 1)
                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j))
                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j + 1))
                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j + 1))
                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j - 1))
                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j - 1)))
                {
                    local_max = dyn_matr(dynamicMatrix, i, j);
                    local_max_x = i;
                    local_max_y = j;
                }
                else
                {
                    if ((i != 0) && (j == 0) && (i != A - 1)
                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j))
                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j + 1))
                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j + 1))
                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j + 1))
                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j)))
                    {
                        local_max = dyn_matr(dynamicMatrix, i, j);
                        local_max_x = i;
                        local_max_y = j;
                    }
                    else
                    {
                        if ((i == 0) && (j == 0)
                        && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j))
                        && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j + 1))
                        && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j + 1)))
                        {
                            local_max = dyn_matr(dynamicMatrix, i, j);
                            local_max_x = i;
                            local_max_y = j;
                        }
                        else
                        {
                            if ((i == A - 1) && (j == A - 1)
                            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j - 1))
                            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j))
                            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j - 1)))
                            {
                                local_max = dyn_matr(dynamicMatrix, i, j);
                                local_max_x = i;
                                local_max_y = j;
                            }
                            else
                            {
                                if ((i != A - 1) && (j == A - 1)
                                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j))
                                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j - 1))
                                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j - 1))
                                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j - 1))
                                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j)))
                                {
                                    local_max = dyn_matr(dynamicMatrix, i, j);
                                    local_max_x = i;
                                    local_max_y = j;
                                }
                                else
                                {
                                    if ((i == A - 1) && (j != A - 1)
                                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j - 1))
                                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j - 1))
                                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j))
                                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j + 1))
                                    && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j + 1)))
                                    {
                                        local_max = dyn_matr(dynamicMatrix, i, j);
                                        local_max_x = i;
                                        local_max_y = j;
                                    }
                                    else
                                    {
                                        if ((i != 0) && (j == 0) && (i == A - 1)
                                            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j))
                                            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i - 1, j + 1))
                                            && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j + 1)))
                                        {
                                            local_max = dyn_matr(dynamicMatrix, i, j);
                                            local_max_x = i;
                                            local_max_y = j;
                                        }
                                        else
                                        {
                                            if ((i == 0) && (j != 0) && (j == A - 1)
                                                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i, j - 1))
                                                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j - 1))
                                                && (dyn_matr(dynamicMatrix, i, j) > dyn_matr(dynamicMatrix, i + 1, j)))
                                            {
                                                local_max = dyn_matr(dynamicMatrix, i, j);
                                                local_max_x = i;
                                                local_max_y = j;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (local_max == dynamicMatrix[0][0])
    {
        if ((dynamicMatrix[0][0] > dyn_matr(dynamicMatrix, 0, 1))
        && (dynamicMatrix[0][0] > dyn_matr(dynamicMatrix, 1, 0)))
        {
            local_max = dynamicMatrix[0][0];
            local_max_x = 0;
            local_max_y = 0;
        }
        else
        {
            no_local_max = 0;
        }
    }
    if (no_local_max != 0)
    {
        std::cout << "The max local max is: " << local_max << std::endl;
        std::cout << "Its coordinates are: " << "[" << local_max_x << ", " << local_max_y << "]" << std::endl;
    }
    else
    {
        std::cout << "There is no max local max in this matrix." << std::endl;
    }



    //TASK 3
    int pr = 1;
    for (int i = A - 1; i > 0; --i)
    {
        for (int j = A - i; j < A; ++j)
        {
            pr *= dyn_matr(dynamicMatrix, i, j);
        }
    }
    std::cout << "The desired product is: " << pr << std::endl;
    return 0;
}
