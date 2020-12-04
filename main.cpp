#include <iostream>
#include <cstdlib>
#include "Stack.h"

int main()
{
//    Stack st1(5);
//    st1.push(3);
//    st1.push(7);
//    st1.push(2);
//    st1.push(1);
    Stack st2(5);
    st2.push(3);
    st2.push(7);
    st2.push(2);
    st2.push(9);
//    st2.operator[](3);
//    bool result = st1 != st2;
//    bool result1 = st1 < st2;
//    bool result2 = st1 > st2;
    st2 << 6;
    st2.size();
    double a;
    st2 >> a;
    Stack massive(4);
    st2 = massive;
}