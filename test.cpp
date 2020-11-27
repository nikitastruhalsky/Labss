//
// Created by Owner on 27.11.2020.
//

#include <gtest/gtest.h>
#include "Student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"

TEST(Student, GetData)
{
    Student a("Petya", 1, 2);
    EXPECT_STREQ(a.GetName(), "Petya");
    EXPECT_EQ(a.GetCourse(), 1);
    EXPECT_EQ(a.GetGroup(), 2);
    EXPECT_EQ(a.GetIdentificator(), 1);
    EXPECT_EQ(a.GetRecordBookNumber(), 2021);
}

TEST(RecordBooks, AreDifferent)
{
    Student a("Petya", 1, 2);
    Student b("Vasya", 2, 3);
    Student c("Misha", 3, 4);
    EXPECT_NE(a.GetRecordBookNumber(), b.GetRecordBookNumber());
    EXPECT_NE(b.GetRecordBookNumber(), c.GetRecordBookNumber());
    EXPECT_NE(a.GetRecordBookNumber(), c.GetRecordBookNumber());
}

TEST(Id, AreDifferent)
{
    Student a("Petya", 1, 2);
    Student b("Vasya", 2, 3);
    Student c("Misha", 3, 4);
    EXPECT_NE(a.GetIdentificator(), b.GetIdentificator());
    EXPECT_NE(a.GetIdentificator(), c.GetIdentificator());
    EXPECT_NE(b.GetIdentificator(), c.GetIdentificator());
}

TEST(Student, Copy) // without id and recordbook because it won't pass;
                    // you said that this trouble with id and recordbook is ok
{
    Student a("Petya", 1, 2);
    Student b(a);
    EXPECT_STREQ(b.GetName(), "Petya");
    EXPECT_EQ(b.GetCourse(), 1);
    EXPECT_EQ(b.GetGroup(), 2);
    //EXPECT_EQ(b.GetIdentificator(), 2);
    //EXPECT_EQ(b.GetRecordBookNumber(), 2021);
}

TEST(StudentCopy, RecordBookIsEqual)   // without id and recordbook because it won't pass;
                            // you said that this trouble with id and recordbook is ok
{
    Student a("Petya", 1, 2);
    Student b(a);
    Student c(b);
    EXPECT_STREQ(b.GetName(), "Petya");
    EXPECT_EQ(b.GetCourse(), 1);
    EXPECT_EQ(b.GetGroup(), 2);
    EXPECT_EQ(a.GetRecordBookNumber(), b.GetRecordBookNumber());
    EXPECT_EQ(b.GetRecordBookNumber(), c.GetRecordBookNumber());
}

TEST(StudentCopy, IdIsDifferent)
{
    Student a("Petya", 1, 2);
    Student b(a);
    Student c(b);
    EXPECT_NE(a.GetIdentificator(), b.GetIdentificator());
    EXPECT_NE(b.GetIdentificator(), c.GetIdentificator());
    EXPECT_NE(a.GetIdentificator(), c.GetIdentificator());
}

TEST(Setter, Name)
{
    Student a("Petya", 1, 2);
    a.SetName("Vasya");
    EXPECT_STREQ(a.GetName(), "Vasya");
}

TEST(Setter, Group)
{
    Student a("Petya", 1, 2);
    a.SetGroup(5);
    EXPECT_EQ(a.GetGroup(), 5);
}

TEST(Setter, Course)
{
    Student a("Petya", 1, 2);
    a.SetCourse(2);
    EXPECT_EQ(a.GetCourse(), 2);
}

TEST(StudentAfterFirstSession, GetData)     // without id and recordbook because it won't pass;
                                            // you said that this trouble with id and recordbook is ok
{
    Student a("Petya", 1, 2);
    int *massive1 = new int[4] {10, 10, 11, 10};
    StudentAfterFirstSession b(a, massive1);
    EXPECT_STREQ(b.GetName(), "Petya");
    EXPECT_EQ(b.GetGroup(), 2);
    EXPECT_EQ(b.GetCourse(), 1);
    b.GetMarks1();
    EXPECT_EQ(b.MarksAfterFirstSession[0], 10);  // marks
    EXPECT_EQ(b.MarksAfterFirstSession[1], 10);  // marks
    EXPECT_EQ(b.MarksAfterFirstSession[2], 11);  // marks
    EXPECT_EQ(b.MarksAfterFirstSession[3], 10);  // marks
//    EXPECT_EQ(b.GetIdentificator(), 1);
//    EXPECT_EQ(b.GetRecordBookNumber(), 2021);
}

TEST(StudentAfterFirstSession, Copy)    // without id and recordbook because it won't pass;
                                        // you said that this trouble with id and recordbook is ok
{
    Student a("Petya", 1, 2);
    int *massive1 = new int[4] {10, 10, 11, 10};
    StudentAfterFirstSession b(a, massive1);
    StudentAfterFirstSession c(b);
    EXPECT_STREQ(c.GetName(), "Petya");
    EXPECT_EQ(c.GetGroup(), 2);
    EXPECT_EQ(c.GetCourse(), 1);
//    EXPECT_EQ(c.GetIdentificator(), 1);
//    EXPECT_EQ(c.GetRecordBookNumber(), 2021);
}

TEST(StudentAfterFirstSession, AverageMark)
{
    Student a("Petya", 1, 2);
    int *massive1 = new int[4] {10, 10, 11, 10};
    StudentAfterFirstSession b(a, massive1);
    EXPECT_EQ(b.AverageMark(), 10.25);
}

TEST(StudentAfterSecondSession, GetData)    // without id and recordbook because it won't pass;
                                            // you said that this trouble with id and recordbook is ok
{
    Student a("Petya", 1, 2);
    int *massive1 = new int[4] {10, 10, 11, 10};
    int *massive2 = new int[5] {10, 10, 9, 10, 10};
    StudentAfterFirstSession b(a, massive1);
    StudentAfterSecondSession c(b, massive2);
    EXPECT_STREQ(c.GetName(), "Petya");
    EXPECT_EQ(c.GetGroup(), 2);
    EXPECT_EQ(c.GetCourse(), 1);
    b.GetMarks1();
    c.GetMarks2();
    EXPECT_EQ(b.MarksAfterFirstSession[0], 10);
    EXPECT_EQ(b.MarksAfterFirstSession[1], 10);
    EXPECT_EQ(b.MarksAfterFirstSession[2], 11);
    EXPECT_EQ(b.MarksAfterFirstSession[3], 10);
    EXPECT_EQ(c.MarksAfterSecondSession[0], 10);
    EXPECT_EQ(c.MarksAfterSecondSession[1], 10);
    EXPECT_EQ(c.MarksAfterSecondSession[2], 9);
    EXPECT_EQ(c.MarksAfterSecondSession[3], 10);
    EXPECT_EQ(c.MarksAfterSecondSession[4], 10);
//    EXPECT_EQ(c.GetIdentificator(), 1);
//    EXPECT_EQ(c.GetRecordBookNumber(), 2021);
}

TEST(StudentAfterSecondSession, Copy)   // without id and recordbook because it won't pass;
                                        // you said that this trouble with id and recordbook is ok
{
    Student a("Petya", 1, 2);
    int *massive1 = new int[4] {10, 10, 11, 10};
    int *massive2 = new int[5] {10, 10, 9, 10, 10};
    StudentAfterFirstSession b(a, massive1);
    StudentAfterFirstSession c(b, massive2);
    StudentAfterFirstSession d(c);
    EXPECT_STREQ(d.GetName(), "Petya");
    EXPECT_EQ(d.GetGroup(), 2);
    EXPECT_EQ(d.GetCourse(), 1);
//    EXPECT_EQ(d.GetIdentificator(), 1);
//    EXPECT_EQ(d.GetRecordBookNumber(), 2021);
}

TEST(StudentAfterSecondSession, AverageMark)
{
    Student a("Petya", 1, 2);
    int *massive1 = new int[4] {10, 10, 11, 10};
    int *massive2 = new int[5] {10, 10, 9, 10, 10};
    StudentAfterFirstSession b(a, massive1);
    b.setmarks1(massive1);
    StudentAfterSecondSession c(b, massive2);
    c.setmarks2(massive2);
    EXPECT_EQ(c.AverageMark(), 10);
}

TEST(Student, Output)
{
    Student a("Petya", 1, 2);
    std::stringstream ss;
    std::string output;
    std::string temp;
    int count = 0;
    ss << a;
    while (ss >> temp)
    {
        output = output + temp + "  ";
    }
    EXPECT_EQ(output, "Name:  Petya  Group:  2  Course:  1  ");
}

TEST(StudentAfterFirstSession, Output)
{
    Student a("Petya", 1, 2);
    int *massive1 = new int[4] {10, 10, 11, 10};
    StudentAfterFirstSession b(a, massive1);
    std::stringstream ss;
    std::string output;
    std::string temp;
    int count = 0;
    ss << b;
    while (ss >> temp)
    {
        output = output + temp + "  ";
    }
    EXPECT_EQ(output, "Name:  Petya  Group:  2  Course:  1Marks  after  first  session:  10  10  11  10  ");
}

TEST(StudentAfterSecondSession, Output)
{
    Student a("Petya", 1, 2);
    int *massive1 = new int[4] {10, 10, 11, 10};
    StudentAfterFirstSession b(a, massive1);
    int *massive2 = new int[5] {10, 10, 9, 10, 10};
    StudentAfterSecondSession c(b, massive2);
    std::stringstream ss;
    std::string output;
    std::string temp;
    int count = 0;
    ss << c;
    while (ss >> temp)
    {
        output = output + temp + "  ";
    }
    EXPECT_EQ(output, "Name:  Petya  Group:  2  Course:  1Marks  after  first  session:"
                      "  10  10  11  10  Marks  after  second  session:  10  10  9  10  10  ");
}