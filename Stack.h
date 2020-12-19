#ifndef LAB_8_STACK_STACK_H
#define LAB_8_STACK_STACK_H

#define SIZE 100

template<typename T>
class Stack
{
private:
    std::string *arr;
    int capacity;
    int top;

public:
    Stack(int size = SIZE);
    ~Stack();

    void push(const std::string& element);
    std::string pop();
    std::string peek();

    int size();
    bool IsEmpty();
    bool IsFull();

    std::string &operator [] (int n);
    bool operator == (const Stack &st2);
    bool operator != (const Stack &st2);
    bool operator < (const Stack &st2);
    bool operator > (const Stack &st2);
    void operator << (double number);
    double operator >> (double &number);
    Stack& operator = (const Stack &massive);
};

#endif //LAB_8_STACK_STACK_H
