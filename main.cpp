#include <iostream>
#include <vector>
#include "Student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"


double AverageMarkForAllStudents(std::vector<Student*> students)
{
    double sum=0;
    for (auto& person : students)
    {
        sum += person -> AverageMark();
    }
    return (double)sum / students.size();
}
double AverageMarkForAGroup(std::vector<Student*> students, int course, int group, int session)
{
    double sum = 0;
    double count = 0;
    if (session == 0)
    {
        return 0;
    }
    for (auto& person : students)
    {
        if (person -> GetCourse() == course && person -> GetGroup() == group && person -> GetSession() == session)
        {
            sum += person -> AverageMark();
            count++;
        }
    }
    if (count == 0)
    {
        std::cout << "AAAAAAAAAAA" << std::endl;
        return 0;
    }
    return sum / count;
}


int main()
{
    int *massive1 = new int[4] {10, 10, 11, 10};
    int *massive2 = new int[5] {9, 9, 10, 9, 10};
    Student student1("Ivan Ivanov", 1, 3);
    std::cout << student1 << std::endl;
    student1.GetName();
    StudentAfterFirstSession student5(student1, massive1);
    student5.setmarks1(massive1);
    StudentAfterSecondSession student6(student5, massive2);
    student6.setmarks2(massive2);
    std::cout << student5 << std::endl;
    std::cout << student6 << std::endl;
    student5.AverageMark();
    student6.AverageMark();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    int *massive3 = new int[4] {8, 10, 9, 9};
    int *massive4 = new int[5] {10, 9, 7, 9, 9};
    Student student2("Piotr Petrov", 1, 4);
    StudentAfterFirstSession student3(student2, massive3);
    student3.setmarks1(massive3);
    StudentAfterSecondSession student4(student3, massive4);
    student4.setmarks2(massive4);
    std::cout << student2 << std::endl;
    std::cout << student3 << std::endl;
    std::cout << student4 << std::endl;
    student3.AverageMark();
    student4.AverageMark();

    StudentAfterSecondSession student7(student5, massive2);
    Student student8("Misha Mishin", 1, 4);
    StudentAfterFirstSession student9(student8, massive3);
    StudentAfterSecondSession student10(student9, massive2);

    std::vector<Student*> all_students;
    all_students.push_back(&student1);
    all_students.push_back(&student2);
    all_students.push_back(&student3);
    all_students.push_back(&student5);
    all_students.push_back(&student6);
    all_students.push_back(&student4);
    all_students.push_back(&student7);
    all_students.push_back(&student10);

    std::cout << "Average mark for 4 group is: ";
    std::cout << AverageMarkForAGroup(all_students,1,4,2) << std::endl;
    return 0;
}