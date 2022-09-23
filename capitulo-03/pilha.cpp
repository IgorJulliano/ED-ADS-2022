#include <stdlib.h>
using namespace std;

template <typename T>
class Stack
{
public:
    int topIndex = -1;
    int maxCapacity;
    T* items;

    Stack(int capacity)
    {
        maxCapacity = capacity;
        items = (T*)malloc(capacity * sizeof(T));
    }
    ~Stack()
    {
        free(this->items);
    }

    T pop()
    {
        if (!isEmpty())
        {
            return items[topIndex--];
        } else throw;
    }

    T top()
    {
        if (!isEmpty())
        {
            return items[topIndex];
        } else throw;
    }

    void push(T item)
    {
        if (!isFull())
        {
            items[++topIndex] = item;
        }
    }

    void pushAll(T *items[]){
        for (int i = 0; items[i]; i++)
        {
            push(items[i]);
        }
        
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }
    bool isFull()
    {
        return topIndex == maxCapacity - 1;
    }

    // string toString(char sep = 0) {
    //     string str = "";
    //     for (int i = 0; i < topIndex; i++)
    //     {
    //         str += string(items[i]);
    //         str += sep;
    //     }
    //     return str;
    // }

    // Stack.fromString(string* str, char sep = " ") {
    //     maxCapacity = str.length();
    //     topIndex = str.length() - 1;

    //     string[] strArr =

    //         for (int i = 0; i < str->length(); i++)
    //         {
    //             items[i] = T(str[i]);
    //         }


    // }
};
