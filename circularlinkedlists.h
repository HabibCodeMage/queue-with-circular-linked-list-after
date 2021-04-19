#pragma once
#ifndef CIRCULARLINKEDLISTS_H
#define CIRCULARLINKEDLISTS_H
#include<stddef.h>
template<typename T>
class circularlinkedlist
{
private:
	class cnode
	{
	private:
		T name;
		cnode* next;
		friend class circularlinkedlist;
	};
	cnode* cursor;
public:
	circularlinkedlist() :cursor(NULL)
	{}
	void addnode(const T& name)
	{
		cnode* create = new cnode;
		create->name = name;
		if (cursor == NULL)
		{
			cursor = create;
			(*create).next = create;
		}
		else
		{
			create->next = cursor->next;
			cursor->next = create;
		}
	}
	void advance()
	{
		if (cursor)
		{
			cursor = cursor->next;
		}
	}
	void deletenode()
	{
		if (cursor)
		{
			cnode* ptr = cursor->next;
			if (ptr == cursor)
				cursor = NULL;
			else
				cursor->next = ptr->next;
			delete ptr;
			return;
		}
		throw"empty queue";

	}
	T back()
	{
		if (cursor)
			return cursor->name;
		throw"empty queue";
	}
	T front()
	{
		if (cursor)
			return cursor->next->name;
		throw"empty queue";
	}
	~circularlinkedlist()
	{
		if (cursor)
		{
			cnode* traverse = cursor->next;
			while (traverse != cursor)
			{
				cnode* back = traverse;
				traverse = traverse->next;
				delete back;
			}
			delete cursor;
		}


	}
};
#endif // !CIRCULARLINKEDLISTS_h


