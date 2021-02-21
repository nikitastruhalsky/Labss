#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <regex>
#include <memory>
#include <unordered_set>


struct person
{
    std::string name, surname, middle_name, status, course = "kursa";
    int course_number;
    long int id;
};

std::istream& operator >> (std::istream& in, person& p)
{
    in >> p.surname >> p.name >> p.middle_name >> p.status >> p.course_number
    >> p.course >> p.id;
    return in;
}

std::ostream& operator << (std::ostream& out, const std::shared_ptr<person>& p)
{
    out << p -> surname << " " << p -> name << " " << p -> middle_name << " " << p -> status
    << " " << p -> course_number << " " << p -> course << " " << p -> id;
    return out;
}

int main()
{
    std::ifstream fin("L1_ANSI.txt");
    std::string line;
    std::vector<std::string> v1;
    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            v1.push_back(line);
        }
    }
    fin.close();

    std::regex exp (R"(^([a-zA-Z']+)\d+([a-zA-Z']+)\d+([a-zA-Z']+)\d+([a-zA-Z]+)\d+(\d)[a-zA-Z]+\d+(\d{8})$)");

    std::ofstream out;
    out.open("L1_ANSI.txt");
    if (out.is_open())
    {
        for (int i = 0; i < v1.size(); ++i)
        {
            out << std::regex_replace (v1[i], exp, "$1 $2 $3 $4 $5 kursa $6") << std::endl;
        }
    }

    std::ifstream fin1("L1_ANSI.txt");

    std::vector<person> v;
    std::vector<std::shared_ptr<person>> v_clever(12);

    std::copy(std::istream_iterator<person>(fin1), std::istream_iterator<person>(), std::back_inserter(v));

    for (int i = 0; i < v_clever.size(); ++i)
    {
        v_clever[i] = std::make_shared<person>(v[i]);
    }

    int min_course;
    std::cout << "Enter a min course: ";
    std::cin >> min_course;

    auto result = std::remove_if(v_clever.begin(), v_clever.end(), [min_course](const std::shared_ptr<person> &p)
    {
        return p -> course_number < min_course;
    });
    v_clever.erase(result, v_clever.end());

    std::sort(v_clever.begin(), v_clever.end(), [](const std::shared_ptr<person> &p1, const std::shared_ptr<person> &p2)
    {
        if (p1 -> surname != p2 -> surname)
        {
            return p2 -> surname > p1 -> surname;
        }
        else
        {
            return p2 -> name > p1 -> name;
        }
    });

    std::copy(v_clever.begin(), v_clever.end(), std::ostream_iterator<std::shared_ptr<person>>(std::cout, "\n"));

//    auto set = std::unordered_set<std::shared_ptr<person>>();
//    for (int i = 0; i < v_clever.size(); ++i)
//    {
//        set.insert(v_clever[i]);
//    }

    while(true)
    {
        std::string info;
        std::cout << "Enter a participant's information:" << std::endl;
        std::getline(std::cin, info);
        for (int i = 0; i < v_clever.size(); ++i)
        {
            std::string check;
            check = v_clever[i]->surname + " " + v_clever[i]->name + " " + v_clever[i]->middle_name;
            if (info == check)
            {
                std::cout << "ID of this person is: " << v_clever[i]->id << std::endl;
                break;
            }
            else
            {
                if (i == v_clever.size() - 1)
                {
                    std::cout << "Mistake! There is no participant with such data." << std::endl;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return 0;
}
