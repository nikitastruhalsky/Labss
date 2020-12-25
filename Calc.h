#ifndef LAB_8_STACK_CALCULATOR_H
#define LAB_8_STACK_CALCULATOR_H

#include <string>
#include <vector>
#include "Stack.h"

class Calculator
{
public:
    double count(const std::string& final_line);
    std::string algorithm();
    int priority(std::string symbol);
    bool NumberOfBrackets(const std::vector<std::string>& line);
    bool CorrectWord(const std::vector<std::string>& v);
    bool IsCorrect(const std::string& line);
};


#endif //LAB_8_STACK_CALCULATOR_H
