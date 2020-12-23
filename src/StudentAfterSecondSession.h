//
// Created by Owner on 12.11.2020.
//

#pragma once
#include "Student.h"
#include "StudentAfterFirstSession.h"


class StudentAfterSecondSession : public StudentAfterFirstSession
{
private:
    int *marks2;
public:
    StudentAfterSecondSession (const StudentAfterFirstSession &, const int *nsecond_session);
    StudentAfterSecondSession (const StudentAfterSecondSession &);
    int *GetMarks2();
    int *setmarks2(const int *valueSecondSession);
    friend std::ostream& operator << (std::ostream& out, StudentAfterSecondSession&);
    double AverageMark() override;
    int MarksAfterSecondSession[5];
};