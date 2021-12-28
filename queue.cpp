#include "Header.h"
#include <exception>


Queue::Queue() {}

Queue::Queue(int a)
{
	next = new Node();
	next->prev = nullptr;
	next->next = nullptr;
	next->a = a;
}

Queue& Queue::operator=(Queue&& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete next;
	next = other.next;
	other.next = nullptr;
}

int Queue::GetSize() const
{
	if (!HasElements()) { return 0; }
	int i = 0;
	Node* a = next;
	while (a != nullptr)
	{
		a = a->next;
		++i;
	}
	return i;
}

void Queue::Push(const int a)
{
	Node* newnode = new Node();
	Node* checking = next;
	if (HasElements())
	{
		while (checking->next != nullptr)
		{
			checking = checking->next;
		}
		checking->next = newnode;
	}
	else
	{
		next = newnode;
	}
	newnode->a = a;
	newnode->prev = checking;
	newnode->next = nullptr;
}

void Queue::Pop(int& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	Node* tempnode = next->next;
	if (next->next != nullptr)
	{
		next->next->prev = nullptr;
	}
	a = next->a;
	delete next;
	next = tempnode;
}

void Queue::Peek(int& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	a = next->a;
}


bool Queue::HasElements() const
{
	if (this->next != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
