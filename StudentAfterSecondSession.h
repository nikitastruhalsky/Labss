//
// Created by Owner on 12.11.2020.
//

#ifndef LAB_7_STUDENTAFTERSECONDSESSION_H
#define LAB_7_STUDENTAFTERSECONDSESSION_H
#include "Student.h"
#include "StudentAfterFirstSession.h"


class StudentAfterSecondSession : public StudentAfterFirstSession
{
private:
    int *marks2;
public:
    StudentAfterSecondSession (const StudentAfterFirstSession &, const int *nsecond_session);
    StudentAfterSecondSession (const StudentAfterSecondSession &);
    int *GetSecondSession();
    int *setmarks2(const int *valueSecondSession);
    friend std::ostream& operator << (std::ostream& out, StudentAfterSecondSession&);
    double AverageMark() override;
};


#endif //LAB_7_STUDENTAFTERSECONDSESSION_H
