#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

std::string ConsoleReader(std::string msg)
{
    std::string line;
    std::cout << msg << std::endl;
    std::cin >> line;
    return line;
}

int IsNotDecreasingOrder(std::string msg)
{
    std::string zero = "0";
    for (int i = 0; i < msg.length(); ++i)
    {
        if (i % 2 == 0)
        {
            msg.replace(i, 1, zero);
        }
    }
    for (int i = 0; i < msg.length(); ++i)
    {
        if (msg[i] == char(48))
        {
            msg.erase(i, 1);
        }
    }
    for (int i = 0; i < msg.length() - 1; ++i)
    {
        if (static_cast<int>(msg[i]) > static_cast<int>(msg[i+1]))
        {
            std::cout << "No. Symbols in odd places do not go in non-decreasing order" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes. Symbols in odd places go in non-decreasing order" << std::endl;
    std::cout << msg << std::endl;
    return 0;
}

std::vector<std::string>FileReader(std::string input_file)
{
    std::vector<std::string> input;
    std::ifstream fin(input_file);
    std::string s;
    while (std::getline(fin, s))
    {
        input.push_back(s);
        s.clear();
    }
    fin.close();
    return input;
}

std::vector<std::string>WordParser(std::vector<std::string> lines)
{
    std::vector<std::string> vec;
    for (int i = 0; i < lines.size(); ++i)
    {
        std::stringstream ss(lines[i]);
        std::string single_word;
        while (ss >> single_word)
        {
            lines.push_back(single_word);
            single_word.clear();
        }
    }
    return vec;
}

std::vector<std::string>FindItems(std::vector<std::string> words)
{
    std::vector<std::string> word;
    words = WordParser(word);
    for (int i = 0; i < words.size(); ++i)
    {
        if (IsNotDecreasingOrder(words[i]))
        {
            word.push_back(words[i]);
        }
    }
    return word;
}
int main()
{
    std::string msg = ConsoleReader("Enter a line");
    IsNotDecreasingOrder(msg);
    std::string input = ConsoleReader("Enter a name of your file");
    FileReader(input);
    std::vector<std::string> lines;
    std::vector<std::string> words;
    WordParser(lines);
    FindItems(words);
    return 0;
}