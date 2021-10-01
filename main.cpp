#include <iostream>
#include <vector>
#include <functional>
#include <string>


class List;
class Visitor
{
public:
    virtual void visit(List &list) = 0;
};
class VisitorSum;
class Iterator
{
    public:
        virtual int First() = 0;
        virtual void Next() = 0;
        virtual bool IsDone() = 0;
        virtual int Current() = 0;
};

class ListIterator;

class Model
{
public:
    std::vector<std::function<void(Model*)> *> subscribers;
    void subscribe(std::function<void(Model*)> *sub)
    {
        subscribers.push_back(sub);
    }
    void notify()
    {
        for (auto sub : subscribers) sub -> operator()(this);
    }
    virtual void accept(Visitor &v) = 0;
    virtual void to_console() = 0;
    virtual std::string to_string() = 0;
};

class Node
{
public:
    Node* pNext;
    int data;

    Node(int data = int(), Node* pNext = nullptr)
    {
        this -> data = data;
        this -> pNext = pNext;
    }
};

class List : public Model
{
public:
    int size;
    Node* head;
    int elements_sum;


    void accept(Visitor &v) override
    {
        v.visit(*this);
    }

    void to_console() override
    {
        std::cout << "Sum of elements: " << this -> elements_sum << std::endl;
    }

    std::string to_string() override
    {
        Node* current = this -> head;
        std::string elements_of_a_list;
        while (current -> pNext != nullptr)
        {
            elements_of_a_list += std::to_string(current -> data);
            elements_of_a_list += " ";
            current = current -> pNext;
        }
        elements_of_a_list += std::to_string(current -> data);
        return elements_of_a_list;
    }


    List()
    {
        size = 0;
        head = nullptr;
    }

    ~List()
    = default;
};

class ListController
{
public:
    List model;
public:
    explicit ListController(List &list) : model(list) {}
    void push_back(int data)
    {
        if (model.head == nullptr)
        {
            model.head = new Node(data);
        }
        else
        {
            Node* current = model.head;
            while (current -> pNext != nullptr)
            {
                current = current -> pNext;
            }
            current -> pNext = new Node(data);
        }
        model.size++;
        model.notify();
    }

    void push_front(int data)
    {
        if (model.head == nullptr)
        {
            model.head = new Node(data);
        }
        else
        {
            Node* new_head = new Node(data);
            new_head -> pNext = model.head;
            model.head = new_head;
        }
        model.size++;
        model.notify();
    }

    void pop_back()
    {
        if (model.head == nullptr)
        {
            return;
        }

        Node* current = model.head;
        while (current -> pNext != nullptr)
        {
            current = current -> pNext;
        }
        delete current;
        model.size--;

        int count = 0;
        current = model.head;
        while (count < model.size - 1)
        {
            current = current -> pNext;
            count++;
        }
        current -> pNext = nullptr;
        model.notify();
    }

    void pop_front()
    {
        if (model.head == nullptr)
        {
            return;
        }

        Node* current = model.head;
        Node* new_head = current -> pNext;
        delete current;
        model.size--;
        model.head = new_head;
        model.notify();
    }
};

template<typename Control>
class View
{
public:
    std::string modelAppearance;
    void showData()
    {
        std::cout << modelAppearance << std::endl;
    }

    std::function<void(Model*)> updateView = [this](Model* m)
    {
        modelAppearance = m -> to_string();
    };

    Control& controller;
    View(Control &controller) : controller(controller)
    {
        controller.model.subscribe(&updateView);
    }
};

class ListView : public View<ListController>
{
private:
    void ListCommands()
    {
        std::cout << "push_back - insert in the end\npush_front - insert in the begin\n"
                     " pop_back - delete in the end\npop_front - delete in the begin\n"
                     " stop - stop the view\n\n";
    }
public:
    ListView(ListController& controller) : View<ListController>(controller) {}
    List Start()
    {
        ListCommands();
        while (true)
        {
            std::string command;
            std::cin >> command;
            if (command == "stop")
            {
                break;
            }
            if (command == "push_back")
            {
                int element;
                std::cout << "Element: ";
                std::cin >> element;
                this -> controller.push_back(element);
                showData();
            }
            if (command == "push_front")
            {
                int element;
                std::cout << "Element: ";
                std::cin >> element;
                this -> controller.push_front(element);
                showData();
            }
            if (command == "pop_back")
            {
                this -> controller.pop_back();
                showData();
            }
            if (command == "pop_front")
            {
                this -> controller.pop_front();
                showData();
            }
        }
        return this -> controller.model;
    }
};

class ListIterator : Iterator
{
public:
    List list;
    int current_index = 0;

    ListIterator(List& list1)
    {
        list = list1;
    }

    int First() override
    {
        return list.head -> data;
    }

    void Next() override
    {
        if (current_index < list.size)
        {
            current_index++;
        }
    }

    int Current() override
    {
        int count = 0;
        Node* current = list.head;
        while (count != current_index)
        {
            current = current -> pNext;
            count++;
        }

        return current -> data;
    }

    bool IsDone() override
    {
        return current_index >= list.size;
    }
};

class VisitorSum : public Visitor
{
    List* l;
public:
    VisitorSum(List* list1)
    {
        this -> l = list1;
    }

    void visit(List &list) override
    {
        ListIterator listIterator = ListIterator(list);
        int sum = 0;
        do
        {
            sum += listIterator.Current();
            listIterator.Next();
        }
        while (!listIterator.IsDone());
        list.elements_sum = sum;
    }
};

int main()
{
    List list;
    ListController listController(list);
    ListView listView(listController);
    list = listView.Start();


    VisitorSum visitorSum = VisitorSum(&list);
    list.accept(visitorSum);
    list.to_console();


    ListIterator listIterator = ListIterator(list);
    while (!listIterator.IsDone())
    {
        std::cout << listIterator.Current() << " ";
        listIterator.Next();
    }
    return 0;
}
