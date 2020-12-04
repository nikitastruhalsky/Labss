#ifndef LAB_8_STACK_STACK_H
#define LAB_8_STACK_STACK_H

class Stack
{
private:
    double *arr;
    int capacity;
    int top;

public:
    Stack(int size);
    ~Stack();

    void push(double element);
    double pop();
    double peek();

    int size();
    bool IsEmpty();
    bool IsFull();

    double &operator [] (int n);
    bool operator == (const Stack &st2);
    bool operator != (const Stack &st2);
    bool operator < (const Stack &st2);
    bool operator > (const Stack &st2);
    void operator << (double number);
    double operator >> (double &number);
    Stack& operator = (const Stack &massive);
};

#endif //LAB_8_STACK_STACK_H
