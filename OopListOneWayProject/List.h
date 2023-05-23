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

	~List();
};

template<typename T>
inline List<T>::List()
	: size{ 0 }, head{ nullptr } {}

template<typename T>
inline void List<T>::Clear()
{
	Node<T>* nodeDelete;
	while (head)
	{
		nodeDelete = head;
		head = head->next;
		delete nodeDelete;
	}
	size = 0;
}

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
	
	T value;

	if (size > 1)
	{
		Node<T>* nodeCurrent = head;
		for (int i = 0; i < size - 2; i++)
			nodeCurrent = nodeCurrent->next;

		value = nodeCurrent->next->value;
		delete nodeCurrent->next;
		nodeCurrent->next = nullptr;
	}
	else
	{
		value = head->value;
		delete head;
		head = nullptr;
	}
	size--;
	return value;
}

template<typename T>
inline T List<T>::PopFront()
{
	if (!head)
		new std::exception("list is empty");

	Node<T>* nodeDelete = head;
	head = head->next;

	T value = nodeDelete->value;
	delete nodeDelete;

	size--;
	return value;
}

template<typename T>
inline T List<T>::PeekBack()
{
	if (!head)
		new std::exception("list is empty");

	Node<T>* nodeCurrent = head;
	for (int i = 0; i < size - 1; i++)
		nodeCurrent = nodeCurrent->next;
	return nodeCurrent->value;
}

template<typename T>
inline T List<T>::PeekFront()
{
	if (!head)
		new std::exception("list is empty");

	return head->value;
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
inline List<T>::~List()
{
	this->Clear();
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

template<typename T>
inline T List<T>::Remove(int index)
{
	if (!head)
		new std::exception("list is empty");
	if (index <= 0)
		return this->PopFront();
	if (index >= size)
		return this->PopBack();

	Node<T>* nodeCurrent = head;
	for (int i = 0; i < index - 1; i++)
		nodeCurrent = nodeCurrent->next;

	Node<T>* nodeDelete = nodeCurrent->next;
	nodeCurrent->next = nodeDelete->next;

	T value = nodeDelete->value;
	delete nodeDelete;

	size--;
	return value;
}

template<typename T>
inline T List<T>::At(int index)
{
	Node<T>* nodeCurrent = head;
	for (int i = 0; i < index; i++)
		nodeCurrent = nodeCurrent->next;
	return nodeCurrent->value;
}

template<typename T>
inline T& List<T>::operator[](int index)
{
	Node<T>* nodeCurrent = head;
	for (int i = 0; i < index; i++)
		nodeCurrent = nodeCurrent->next;
	return nodeCurrent->value;
}
