#pragma once
#include <iostream>
#include "List.h"

template <typename T>
class Stack
{
	List<T> stack;
	int head;
public:
	Stack() : head{ -1 } {}
	void Push(T value);
	T Pop();
	T Peek();

	void Print();
};

template<typename T>
inline void Stack<T>::Push(T value)
{
	stack.PushFront(value);
	head++;
}

template<typename T>
inline T Stack<T>::Pop()
{
	head--;
	return stack.PopFront();
}

template<typename T>
inline T Stack<T>::Peek()
{
	return stack.PeekFront();
}

template<typename T>
inline void Stack<T>::Print()
{
	stack.PrintConsole();
}



