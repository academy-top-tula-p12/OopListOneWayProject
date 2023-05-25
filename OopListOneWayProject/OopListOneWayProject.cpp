#include <iostream>
#include "List.h"
#include "Stack.h"

int main()
{
    /*
    List<int> list;
    list.PushBack(10);
    list.PushBack(20);
    list.PushBack(30);

    list.PrintConsole();

    list.PushFront(40);
    list.PushFront(50);

    list.PrintConsole();

    list.Insert(60, 2);

    list.PrintConsole();

    list.Insert(70, 0);
    list.Insert(80, -1);

    list.PrintConsole();

    list.Insert(90, 8);
    list.Insert(100, 20);

    list.PrintConsole();

    std::cout << list.PopBack() << "\n";

    list.PrintConsole();

    std::cout << list.PopFront() << "\n";

    list.PrintConsole();

    std::cout << list.Remove(3) << "\n";

    list.PrintConsole();

    std::cout << list.PeekFront() << "\n";
    std::cout << list.PeekBack() << "\n";
    std::cout << list.At(3) << "\n";
    std::cout << list[3] << "\n";

    list[3] = 200;

    list.PrintConsole();

    list.Clear();

    list.PrintConsole();
    */

    Stack<int> stack;
    stack.Push(100);
    stack.Push(200);
    stack.Push(300);

    stack.Print();
}
