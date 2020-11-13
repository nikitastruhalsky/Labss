#include <iostream>
#include "Student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"

int main()
{
    int *massive1 = new int[4] {10, 10, 11, 10};
    int *massive2 = new int[5] {9, 9, 10, 9, 10};
    Student student1("Ivan Ivanov", 1, 4);
    StudentAfterFirstSession a(student1, massive1);
    a.setmarks1(massive1);
    StudentAfterSecondSession b(a, massive2);
    b.setmarks2(massive2);
    std::cout << student1 << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a.AverageMark();
    b.AverageMark();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    int *massive3 = new int[4] {8, 10, 9, 9};
    int *massive4 = new int[5] {10, 9, 7, 9, 9};
    Student student2("Piotr Petrov", 1, 4);
    StudentAfterFirstSession c(student2, massive3);
    c.setmarks1(massive3);
    StudentAfterSecondSession d(c, massive4);
    d.setmarks2(massive4);
    std::cout << student2 << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    c.AverageMark();
    d.AverageMark();
    return 0;
}