//
// Created by Owner on 12.11.2020.
//
#include <iostream>
#include "Student.h"

Student::Student (char *name1, int ncourse, int ngroup)
{
    name = new char [strlen(name1)];
    for (int i = 0; i < strlen(name1); ++i)
    {
        name[i] = name1[i];
        if (i == strlen(name1) - 1)
        {
            name[i + 1] = '\0';
        }
    }
    course = ncourse;
    group = ngroup;
    count_id++;
    identificator = count_id;
    count_rec++;
    recordbook_number = count_rec;
}

Student::Student (const Student &b)
{
    name = new char [strlen(b.name)];
    for (int i = 0; i < strlen(b.name); ++i)
    {
        name[i] = b.name[i];
        if (i == strlen(b.name) - 1)
        {
            name[i + 1] = '\0';
        }
    }
    course = b.course;
    group = b.group;
    count_id++;
    identificator = count_id;
    recordbook_number = b.recordbook_number;
    count_rec++;
}

int Student::count_id = 0;
int Student::count_rec = 2020;


char* Student::GetName()
{
    return name;
}

int Student::GetCourse()
{
    return course;
}

int Student::GetGroup()
{
    return group;
}

int Student::GetIdentificator()
{
    return identificator;
}

int Student::GetRecordBookNumber()
{
    return recordbook_number;
}

void Student::SetName(char *valueName)
{
    name = new char [strlen(valueName)];
    for (int i = 0; i < strlen(valueName); ++i)
    {
        name[i] = valueName[i];
        if (i == strlen(valueName) - 1)
        {
            name[i + 1] = '\0';
        }
    }
}

void Student::SetCourse(int valueCourse)
{
    course = valueCourse;
}

void Student::SetGroup(int valueGroup)
{
    group = valueGroup;
}

std::ostream& operator << (std::ostream& out, Student& b)
{
    out << "Name: " << b.name << "\tGroup: " << b.group << "\tCourse: " << b.course << "\tId: "
    << b.identificator << "\tRecordBook: " << b.recordbook_number;
    std::cout << std::endl;
    return out;
}

double Student::AverageMark()
{
    return 0;
}

int Student::GetSession()
{
    return 0;
}