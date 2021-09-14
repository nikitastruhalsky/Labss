#include <iostream>
#include <map>
#include <string>

class Iterator
{
public:
    virtual std::string First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual std::string Current() = 0;
};

class ArrayIterator : Iterator
{
public:
    std::string* _array;
    int current_index = 0;
    int array_length;

    ArrayIterator(std::string* array, int length)
    {
        _array = array;
        array_length = length;
    }

    std::string First() override
    {
        return _array[0];
    }

    void Next() override
    {
        if (current_index < array_length - 1)
        {
            current_index++;
        }
    }

    std::string Current() override
    {
        return _array[current_index];
    }

    bool IsDone() override
    {
        return current_index >= array_length - 1;
    }
};

class MapIterator : Iterator
{
public:
    std::map<std::string, int> _mp;
    int current_index = 0;
    int map_length = 0;

    MapIterator(std::map<std::string, int> mp, std::string elem)
    {
        auto it = mp.begin();
        for (int i = 0; it != mp.end(); ++it, ++i)
        {
            std::string key = it -> first;
            for (int j = 0; j < key.length(); ++j)
            {
                if (key[j] == elem[0])
                {
                    int count = 0;
                    for (int k = j; k < j + elem.length(); ++k)
                    {
                        if (key[k] != elem[count])
                        {
                            break;
                        }

                        ++count;
                    }
                    if (count == elem.length())
                    {
                        _mp.insert(std::pair<std::string, int> (it -> first, it -> second));
                        map_length++;
                    }
                }
            }
        }
    }

    std::string First() override
    {
        auto it = _mp.begin();
        return it -> first;
    }

    void Next() override
    {
        if (current_index < map_length - 1)
        {
            current_index++;
        }
    }

    std::string Current() override
    {
        if (current_index < map_length)
        {
            auto it = _mp.begin();
            for (int i = 0; i < current_index; ++i)
            {
                ++it;
            }
            return it -> first;
        }

        return "";
    }

    bool IsDone() override
    {
        return current_index >= map_length - 1;
    }
};

int main()
{
    std::string array[] = {"0", "1", "2"};
    ArrayIterator it(array, 3);
    std::cout << it.Current() << std::endl << it.First() << std::endl;
    it.Next();
    std::cout << it.Current() << std::endl;
    std::cout << it.IsDone() << std::endl;
    it.Next();
    std::cout << it.IsDone() << std::endl;
    std::cout << it.Current() << std::endl;

    std::map<std::string, int> mp;
    mp["hllo"] = 1;
    mp["aloha"] = 2;
    mp["alohe"] = 3;
    mp["haaae"] = 4;
    mp["ffheff"] = 5;
    MapIterator mapIterator(mp, "he");
    std::cout << mapIterator.Current() << std::endl;
    std::cout << mapIterator.First() << std::endl;
    mapIterator.Next();
    std::cout << mapIterator.Current() << std::endl;
    std::cout << mapIterator.IsDone() << std::endl;
    return 0;
}
