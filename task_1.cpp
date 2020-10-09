#include <iostream>
#include <fstream>

char digit(int num)
{
    switch (num)
    {
        case 0:
        {
            return '0';
        }
        case 1:
        {
            return '1';
        }
        case 2:
        {
            return '2';
        }
        case 3:
        {
            return '3';
        }
        case 4:
        {
            return '4';
        }
        case 5:
        {
            return '5';
        }
        case 6:
        {
            return '6';
        }
        case 7:
        {
            return '7';
        }
        case 8:
        {
            return '8';
        }
        case 9:
        {
            return '9';
        }
        case 10:
        {
            return 'A';
        }
        case 11:
        {
            return 'B';
        }
        case 12:
        {
            return 'C';
        }
        case 13:
        {
            return 'D';
        }
        case 14:
        {
            return 'E';
        }
        case 15:
        {
            return 'F';
        }
        case 16:
        {
            return 'G';
        }
        case 17:
        {
            return 'H';
        }
        case 18:
        {
            return 'I';
        }
        case 19:
        {
            return 'J';
        }
        case 20:
        {
            return 'K';
        }
        case 21:
        {
            return 'L';
        }
        case 22:
        {
            return 'M';
        }
        case 23:
        {
            return 'N';
        }
        case 24:
        {
            return 'O';
        }
        case 25:
        {
            return 'P';
        }
        case 26:
        {
            return 'Q';
        }
        case 27:
        {
            return 'R';
        }
        case 28:
        {
            return 'S';
        }
        case 29:
        {
            return 'T';
        }
        case 30:
        {
            return 'U';
        }
        case 31:
        {
            return 'V';
        }
        case 32:
        {
            return 'W';
        }
        case 33:
        {
            return 'X';
        }
        case 34:
        {
            return 'Y';
        }
        case 35:
        {
            return 'Z';
        }
    }
}


int integer_part(int number, int radix, char *new_number)
{
    int *num = new int (number);
    int rest = *num % radix;
    *num /= radix;
    if (*num == 0)
    {
        new_number[0] = digit(rest);
        return 1;
    }
    int i = integer_part(*num, radix, new_number);
    new_number[i++] = digit(rest);
    return i;
}


int main()
{
    int number = 0;
    std::ifstream fin("task1.txt");
    fin >> number;
    int radix = 0;
    char new_number[300] = { 0 };
    std::cout << "Enter the radix (from 2 to 36): ";
    std::cin >> radix;
    if ((radix > 36) || (radix < 2))
    {
        std::cout << "Mistake! Radix should be from 2 to 36. Try again!" << std::endl;
        return 0;
    }
    int i = integer_part((int) number, radix, new_number);
    std::cout << "New number is: ";
    std::cout << new_number << std::endl;
    return 0;
}