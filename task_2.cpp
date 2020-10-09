#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    char tractor[300];
    std::ifstream fin("task2.txt");
    int quantity = 0;
    int max = 0;
    int max_max = 0;
    std::vector<char> vect;
    int n = 0;
    while (fin.getline(tractor, 300))
    {
        vect.clear();
        max_max = 0;
        char word[300];
        int l = std::strlen(tractor);
        tractor[l] = ' ';
        tractor[l + 1] = '\0';
        l++;
        int index = 0;
        for (int i = 0; i < l; ++i)
        {
            if (tractor[i] == ' ')
            {
                word[index] = '\0';
                if (index > 0)
                {
                    index = 0;
                    max = 0;
                    for (int j = 0; j < strlen(word); ++j)
                    {
                        quantity = 0;

                        for (int k = j + 1; k < strlen(word); ++k)
                        {
                            if (word[k] == word[j])
                            {
                                quantity++;
                            }
                        }
                        if (quantity == 0)
                        {
                            max++;
                        }
                    }
                    if (max >= max_max)
                    {
                        vect.clear();
                        max_max = max;
                        for (int i = 0; i < strlen(word); ++i)
                        {
                            vect.push_back(word[i]);
                        }
                    }
                }
                continue;
            }
            word[index] = tractor[i];
            index++;
        }
        for (int i = 0; i < vect.size(); ++i)
        {
            std::cout << vect[i];
        }
        std::cout << std::endl;
    }
    return 0;
}