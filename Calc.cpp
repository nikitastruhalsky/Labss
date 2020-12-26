#include "Calc.h"
#include <iostream>
#include <sstream>


int Calculator::priority(std::string symbol)
{
    if (symbol == "^")
    {
        return 3;
    }
    if ((symbol == "*") || (symbol == "/"))
    {
        return 2;
    }
    if ((symbol == "+") || (symbol == "-"))
    {
        return 1;
    }
    if ((symbol == "(") || (symbol == ")"))
    {
        return 0;
    }
    return -1;
}

bool Calculator::NumberOfBrackets(const std::vector<std::string>& line)
{
    int number1 = 0, number2 = 0;
    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] == ")")
        {
            number1++;
        }
        if (line[i] == "(")
        {
            number2++;
        }
    }
    if (number1 == number2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Calculator::CorrectWord(const std::vector<std::string>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        std::string word = v[i];
        if ((isdigit(*word.begin())) || ((*word.begin() == '-') && (isdigit(*(word.end() - 1)))))
        {
            for (int j = 0; j < word.size() - 1; ++j)
            {
                if (!isdigit(word[j + 1]))
                {
                    if ((word[j + 1] == '.') && (j + 1 != v.size() - 1))
                    {
                        for (int k = j + 2; k < word.size(); ++k)
                        {
                            if (word[k] == '.')
                            {
                                return false;
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            char elem = *word.begin();
            if ((elem == ')') || (elem == '(') || (elem == '+') || ((elem == '-') && (!isdigit(*(word.end() - 1))))
                || (elem == '*') || (elem == '/') || (elem == '^'))
            {
                if (word.size() != 1)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

bool Calculator::IsCorrect(const std::string& line)
{
    std::vector<std::string> v1;
    std::stringstream ss;
    ss << line;
    std::string temp;
    while (ss >> temp)
    {
        v1.emplace_back(temp);
    }
    if ((!isdigit(*(--v1[0].end()))) && (v1[0] != ")") && (v1[0] != "("))
    {
        return false;
    }

    for (int i = 0; i < v1.size(); ++i)
    {
        if ((isdigit(*(--v1[i].end()))) && ((!isdigit(*(v1[i].begin()))) && (*v1[i].begin() != '-')) ||
             ((!isdigit(*(--v1[i].end()))) && (isdigit(*(v1[i].begin())))))
        {
            return false;
        }
    }

    for (int i = 0; i < v1.size() - 1; ++i)
    {
        if (((v1[i] == "(") && (v1[i + 1] == ")")) || ((v1[i] == ")") && (v1[i + 1] == "(")))
        {
            return false;
        }
        if ((isdigit(*(--v1[i].end()))) && ((v1[i + 1] == "(") || (isdigit(*(--v1[i + 1].end())))))
        {
            return false;
        }
        if ((v1[i] == "*") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end())))))
        {
            return false;
        }
        if ((v1[i] == "/") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end())))))
        {
            return false;
        }
        if ((v1[i] == "+") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end())))))
        {
            return false;
        }
        if (((v1[i] == "-") && (!isdigit(*(--v1[i].end())))) && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end())))))
        {
            return false;
        }
        if ((v1[i] == "^") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end())))))
        {
            return false;
        }
        if ((v1[i] == "(") && ((v1[i + 1] != "(") && (!isdigit(*(--v1[i + 1].end())))))
        {
            return false;
        }
        if ((v1[i] == ")") && ((v1[i + 1] == "(") || (isdigit(*(--v1[i + 1].end())))))
        {
            return false;
        }
    }

    if (!NumberOfBrackets(v1))
    {
        return false;
    }

    if (!CorrectWord(v1))
    {
        return false;
    }

    if ((!isdigit(*(--v1[v1.size() - 1].end()))) && (v1[v1.size() - 1] != ")") && (v1[v1.size() - 1] != "("))
    {
        return false;
    }

    return true;
}

std::string Calculator::algorithm(std::string line)
{
    Stack<char> a (100);
    std::string final_line;
    if (!IsCorrect(line))
    {
        throw std::invalid_argument ("Invalid!!!");
    }
    std::stringstream x;
    x << line;
    std::vector<std::string> v1;
    std::stringstream ss;
    ss << line;
    std::string temp;
    while (ss >> temp)
    {
        v1.emplace_back(temp);
    }

    int i = 0;
    while (i < v1.size())
    {
        if (v1[i] == " ")
        {
            final_line += v1[i];
            final_line += " ";
            i++;
            continue;
        }
        if ((v1[i] != " ") && (v1[i] != "(") && (v1[i] != ")") && (v1[i] != "+")
            && (v1[i] != "-") && (v1[i] != "*") && (v1[i] != "/") && (v1[i] != "^"))
        {
            final_line += v1[i];
            final_line += " ";
            i++;
            continue;
        }
        if (v1[i] == "(")
        {
            a.push("(");
            i++;
            continue;
        }
        if (v1[i] == ")")
        {
            while (a.peek() != "(")
            {
                if (!a.IsEmpty())
                {
                    final_line += a.peek();
                    final_line += " ";
                    a.pop();
                    continue;
                }
            }
            if (a.peek() == "(")
            {
                if (!a.IsEmpty())
                {
                    a.pop();
                    i++;
                    continue;
                }
            }
        }

        if ((v1[i] == "*") || (v1[i] == "+") || (v1[i] == "-")
            || (v1[i] == "/") || (v1[i] == "^"))
        {
            if ((priority(v1[i])) == 1)
            {
                if (!a.IsEmpty())
                {
                    while ((!a.IsEmpty()) && ((priority(v1[i])) <= (priority(a.peek()))))
                    {

                        final_line += a.peek();
                        final_line += " ";
                        a.pop();
                        if (a.IsEmpty())
                        {
                            break;
                        }
                    }
                    a.push(v1[i]);
                    i++;
                    continue;
                }
                a.push(v1[i]);
                i++;
                continue;
            }
            if (((priority(v1[i])) == 2) || ((priority(v1[i])) == 3))
            {
                if (!a.IsEmpty())
                {
                    while ((!a.IsEmpty()) && (priority(a.peek()) >= (priority(v1[i]))))
                    {
                        if (!a.IsEmpty())
                        {
                            final_line += a.peek();
                            final_line += " ";
                            a.pop();
                            continue;
                        }
                    }
                }
                a.push(v1[i]);
                i++;
                continue;
            }
        }
    }

    while (!a.IsEmpty())
    {
        final_line += a.peek();
        final_line += " ";
        a.pop();
    }

    final_line.pop_back();
    return final_line;
}

double Calculator::count(const std::string& final_line)
{
    Stack<char> Boo (100);
    int i = 0;
    std::string word;
    std::stringstream x;
    x << final_line;
    while (x >> word)
    {
        if (isdigit(*(--word.end())))
        {
            Boo.push(word);
            i++;
            continue;
        }
        if ((word == "*") || (word == "+") || (word == "-")
            || (word == "/") || (word == "^"))
        {
            if (!Boo.IsEmpty())
            {
                double a = std::stod(Boo.pop());
                double b;
                if (Boo.size() == 0)
                {
                    b = 0;
                }
                else
                {
                    b = std::stod(Boo.pop());
                }
                if (word == "*")
                {
                    double c = a * b;
                    std::stringstream ss;
                    ss << c;
                    std::string s (ss.str());
                    Boo.push(s);
                    i++;
                    continue;
                }
                if (word == "+")
                {
                    double c = a + b;
                    std::stringstream ss;
                    ss << c;
                    std::string s (ss.str());
                    Boo.push(s);
                    i++;
                    continue;
                }
                if (word == "/")
                {
                    if (a == 0)
                    {
                        throw std::invalid_argument ("Invalid!!!");
                    }
                    else
                    {
                        double c = (double)b / a;
                        std::stringstream ss;
                        ss << c;
                        std::string s (ss.str());
                        Boo.push(s);
                        i++;
                        continue;
                    }
                }
                if (word == "-")
                {
                    double c = b - a;
                    std::stringstream ss;
                    ss << c;
                    std::string s (ss.str());
                    Boo.push(s);
                    i++;
                    continue;
                }
                if (word == "^")
                {
                    double c = pow(b,a);
                    std::stringstream ss;
                    ss << c;
                    std::string s (ss.str());
                    Boo.push(s);
                    i++;
                    continue;
                }
            }
        }
    }
    //std::cout << "Result: " << std::stod(Boo.peek()) << std::endl;
    return std::stod(Boo.peek());
}