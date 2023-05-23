#pragma once
#include <iostream>
#include <exception>

template <typename T>
struct Node
{
	T value;
	Node<T>* next = nullptr;
};

template <typename T>
class List
{
	Node<T>* head;
	int size;
public:
	List();

	void Clear();
	void PushBack(T value);
	void PushFront(T value);
	T PopBack();
	T PopFront();
	T PeekBack();
	T PeekFront();

	void Insert(T value, int index);
	T Remove(int index);
	T At(int index);

	T& operator[](int index);

	int Size();

	void PrintConsole();

	//~List();
};

template<typename T>
inline List<T>::List()
	: size{ 0 }, head{ nullptr } {}

template<typename T>
inline void List<T>::PushBack(T value)
{
	Node<T>* nodeNew = new Node<T>;
	nodeNew->value = value;

	if (head)
	{
		Node<T>* nodeCurrent = head;
		while (nodeCurrent->next)
			nodeCurrent = nodeCurrent->next;

		nodeCurrent->next = nodeNew;
	}
	else
		head = nodeNew;
	
	size++;
}

template<typename T>
inline void List<T>::PushFront(T value)
{
	Node<T>* nodeNew = new Node<T>;
	nodeNew->value = value;
	nodeNew->next = head;
	head = nodeNew;
	size++;
}

template<typename T>
inline T List<T>::PopBack()
{
	if (!head)
		new std::exception("list is empty");

	if (size > 1)
	{
		Node<T>* nodeCurrent = head;
		for (int i = 0; i < size - 2; i++)
			nodeCurrent = nodeCurrent->next;

		int value = nodeCurrent->next->value;
		delete nodeCurrent->next;
		nodeCurrent->next = nullptr;
	}
	else
	{
		delete head;
		head = nullptr
	}
	size--;
}

template<typename T>
inline int List<T>::Size()
{
	return size;
}

template<typename T>
inline void List<T>::PrintConsole()
{
	Node<T>* nodeCurrent = head;
	while (nodeCurrent)
	{
		std::cout << nodeCurrent->value << " ";
		nodeCurrent = nodeCurrent->next;
	}
	std::cout << "\n";
}

template<typename T>
inline void List<T>::Insert(T value, int index)
{
	if (index <= 0)
	{
		this->PushFront(value);
		return;
	}
		
	if (index >= size)
	{
		this->PushBack(value);
		return;
	}

	Node<T>* nodeNew = new Node<T>;
	nodeNew->value = value;

	Node<T>* nodeCurrent = head;
	for (int i = 0; i < index - 1; i++)
		nodeCurrent = nodeCurrent->next;

	nodeNew->next = nodeCurrent->next;
	nodeCurrent->next = nodeNew;

	size++;
}
