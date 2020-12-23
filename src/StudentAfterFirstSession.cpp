//
// Created by Owner on 12.11.2020.
//
#include <iostream>
#include "StudentAfterFirstSession.h"

StudentAfterFirstSession::StudentAfterFirstSession (const Student &student, const int *nfirst_session) : Student(student)
{
    marks1 = new int[4];
    for (int i = 0; i < 4; ++i)
    {
        marks1[i] = nfirst_session[i];
    }
}

StudentAfterFirstSession::StudentAfterFirstSession (const StudentAfterFirstSession &c) : Student(c)
{
    marks1 = new int[4];
    for (int i = 0; i < 4; ++i)
    {
        marks1[i] = c.marks1[i];
    }
}

int* StudentAfterFirstSession::setmarks1(const int *valueFirstSession)
{
    marks1 = new int[4];
    for (int i = 0; i < 4; ++i)
    {
        marks1[i] = valueFirstSession[i];
    }
    return marks1;
}

std::ostream& operator << (std::ostream& out, StudentAfterFirstSession &c)
{
    out << "Name: " << c.name << "\tGroup: " << c.group << "\tCourse: " << c.course;
    std::cout << std::endl;
    out << "Marks after first session: ";
    for (int i = 0; i < 4; ++i)
    {
        out << c.marks1[i] << " ";
    }
    std::cout << std::endl;
    return out;
}

int* StudentAfterFirstSession::GetMarks1()
{
    for (int i = 0; i < 4; ++i)
    {
        MarksAfterFirstSession[i] = marks1[i];
    }
    return marks1;
}

double StudentAfterFirstSession::AverageMark()
{
    double average_mark = 0;
    for (int i = 0; i < 4; ++i)
    {
        average_mark += marks1[i];
    }
    average_mark = (double) average_mark / 4;
    std::cout << "The average mark after 1 session is: " << average_mark << std::endl;
    return average_mark;
}


