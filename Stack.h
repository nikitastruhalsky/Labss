#ifndef LAB_8_STACK_STACK_H
#define LAB_8_STACK_STACK_H



template<typename T>
class Stack
{
private:
    std::string *arr;
    int capacity;
    int top;

public:
    Stack(int size);
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
    std::string operator >> (std::basic_string<char> number);
    Stack& operator = (const Stack &massive);
};

template<typename T>
std::string & Stack<T>::operator [] (int n)
{
    if (n < 0 || n >= size())
    {
        std::cout << "Mistake! You can't use this index!" << std::endl;
    }
    std::cout << arr[n];
    return arr[n];
}

template<typename T>
bool Stack<T>::operator == (const Stack &st2)
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

template<typename T>
bool Stack<T>::operator != (const Stack &st2)
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

template<typename T>
bool Stack<T>::operator < (const Stack &st2)
{
    bool result = capacity < st2.capacity;
    return result;
}

template<typename T>
bool Stack<T>::operator > (const Stack &st2)
{
    bool result = capacity > st2.capacity;
    return result;
}

template<typename T>
void Stack<T>::operator << (double number)
{
    push(number);
}

template<typename T>
std::string Stack<T>::operator >> (std::string number)
{
    number = arr[top];
    return number;
}

template<typename T>
Stack<T>& Stack<T>::operator = (const Stack &massive)
{
    this -> capacity = massive.capacity;
    for (int i = 0; i < massive.capacity; ++i)
    {
        this -> arr[i] = massive.arr[i];
    }
    return *this;
}

template<typename T>
Stack<T>::Stack(int size)
{
    arr = new std::string[size];
    capacity = size;
    top = -1;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] arr;
}

template<typename T>
void Stack<T>::push(const std::string& element)
{
    if (IsFull())
    {
        std::cout << "Mistake! Stack is full!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        arr[++top] = element;
    }
}

template<typename T>
std::string Stack<T>::pop()
{
    if (IsEmpty())
    {
        std::cout << "Mistake! Stack is empty!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        return arr[top--];
    }
}

template<typename T>
std::string Stack<T>::peek()
{
    if (IsEmpty())
    {
        std::cout << "Mistake! Stack is empty!" <<  std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        //std::cout << arr[top];
        return arr[top];
    }
}

template<typename T>
bool Stack<T>::IsEmpty()
{
    return top == -1;
}

template<typename T>
bool Stack<T>::IsFull()
{
    return top == capacity - 1;
}

template<typename T>
int Stack<T>::size()
{
    return top + 1;
}

#endif //LAB_8_STACK_STACK_H
