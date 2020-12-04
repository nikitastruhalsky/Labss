#include <iostream>
#include "Stack.h"


double& Stack::operator [] (int n)
{
    if (n < 0 || n >= size())
    {
        std::cout << "Mistake! You can't use this index!" << std::endl;
    }
    std::cout << arr[n];
    return arr[n];
}

bool Stack::operator == (const Stack &st2)
{
    for (int i = 0; i < size(); ++i)
    {
        if (this -> arr[i] == st2.arr[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool Stack::operator != (const Stack &st2)
{
    for (int i = 0; i < size(); ++i)
    {
        if (this -> arr[i] != st2.arr[i])
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}

bool Stack::operator < (const Stack &st2)
{
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size(); ++i)
    {
        sum1 += this -> arr[i];
        sum2 += st2.arr[i];
    }
    if (sum1 < sum2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::operator > (const Stack &st2)
{
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size(); ++i)
    {
        sum1 += this -> arr[i];
        sum2 += st2.arr[i];
    }
    if (sum1 > sum2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::operator << (double number)
{
    this -> push(number);
}

double Stack::operator >> (double &number)
{
    number = peek();
    this -> pop();
    return number;
}

Stack& Stack::operator = (const Stack &massive)
{
    this -> capacity = massive.capacity;
    for (int i = 0; i < massive.capacity; ++i)
    {
        this -> arr[i] = massive.arr[i];
    }
    return *this;
}

Stack::Stack(int size)
{
    arr = new double[size];
    capacity = size;
    top = -1;
}

Stack::~Stack()
{
    delete[] arr;
}

void Stack::push(double element)
{
    if (IsFull())
    {
        std::cout << "Mistake! Stack is full!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "Push " << element << std::endl;
        arr[++top] = element;
    }
}

double Stack::pop()
{
    if (IsEmpty())
    {
        std::cout << "Mistake! Stack is empty!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "Pop " << peek() << std::endl;
        return arr[top--];
    }
}

double Stack::peek()
{
    if (IsEmpty())
    {
        std::cout << "Mistake! Stack is empty!" <<  std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << arr[top];
        return arr[top];
    }
}

bool Stack::IsEmpty()
{
    return top == -1;
}

bool Stack::IsFull()
{
    return top == capacity - 1;
}

int Stack::size()
{
    return top + 1;
}

