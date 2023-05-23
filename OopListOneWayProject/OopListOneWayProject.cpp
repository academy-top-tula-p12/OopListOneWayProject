#include <iostream>
#include "List.h"

int main()
{
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
}
