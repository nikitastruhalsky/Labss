#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string path = "input.txt";

    std::ifstream fin;
    fin.open(path);

    std::ofstream out_pal;
    out_pal.open("output_palindrom.txt");
    std::ofstream out_same;
    out_same.open("output_same.txt");

    if (!fin.is_open())
    {
        std::cout << "Mistake." << std::endl;
    }
    else
    {
        std::string str;
        int n;
        while (!fin.eof())
        {
            str = "";
            std::getline(fin, str);
            if (str == std::string(str.rbegin(), str.rend()))
            {
                if (out_pal.is_open())
                {
                    out_pal << str << std::endl;
                }
            }
            n = 0;
            for (int i = 0; i < str.length(); ++i)
            {
                if (str[i] == str[0])
                {
                    n++;
                }
            }
            if (n == str.length())
            {
                out_same << str << std::endl;
            }
        }
    }
    fin.close();

    char ch = '/';
    for (int i = 0; i < 50; ++i)
    {
        std::cout << ch;
    }
    std::cout << std::endl;

    std::string line1;
    std::ifstream openfile1 ("output_palindrom.txt");
    if(openfile1.is_open())
    {
        std::cout << "File 'output_palindrom':" << std::endl;
        while(std::getline(openfile1, line1))
        {
            std::cout << line1 << std::endl;
        }
    }

    for (int i = 0; i < 50; ++i)
    {
        std::cout << ch;
    }

    std::cout << "  (separator string between files)" << std::endl;

    std::string line2;
    std::ifstream openfile2 ("output_same.txt");
    if(openfile2.is_open())
    {
        std::cout << "File 'output_same':" << std::endl;
        while(std::getline(openfile2, line2))
        {
            std::cout << line2 << std::endl;
        }
    }
    for (int i = 0; i < 50; ++i)
    {
        std::cout << ch;
    }
    return 0;
}