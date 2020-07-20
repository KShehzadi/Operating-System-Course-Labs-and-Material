#include "linkedlist.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
	head = NULL;
}
void LinkedList::insert(int v, bool assigned)
{
	node * n = new node();
	n->data = v;
	n->assigned = assigned;
	if(this->head == NULL)
	{
		this->head = n;
		
	}
  else
  {
    node * tptr = head;
    while (tptr->next != NULL)
    {
      tptr = tptr->next;
    }
    tptr->next = n;
  }
}
void LinkedList::print()
{
	node *ptr = head;
	while(ptr != NULL)
	{
		cout<< ptr->data<< endl;
		ptr = ptr->next;
	}
}
int LinkedList::search(int v)
{
  int count = 0;
  node* ptr = head;
  while(ptr != NULL)
  {
    if(ptr->data == v)
    {
      return count;
    }
    count++;
    ptr = ptr->next;
  }
  return 0;
}
void LinkedList::deleteone(int v)
{
	if(head != NULL && head->data == v)
	{
		head = head->next;
	}
	else
	{
		node *fptr = this->head;
		node *tptr = this->head;
		while(tptr != NULL && tptr->data != v)
		{
			fptr = tptr;
			tptr = tptr->next;
		}
		if(tptr != NULL)
		{
			fptr->next = tptr->next;
		}
	}
}
void LinkedList::updateassigned(bool assigned, int v, int processnumber, int processsize)
{
	if(head != NULL && head->data == v && head->assigned == assigned)
	{
		head->data = v;
		head->assigned = assigned;
		head->processnumber = processnumber;
		head->processsize = processsize;
	}
	else
	{
		node *fptr = this->head;
		node *tptr = this->head;
		while(tptr != NULL && tptr->data != v && tptr->assigned == assigned)
		{
			fptr = tptr;
			tptr = tptr->next;
		}
		if(tptr != NULL)
		{
			fptr->data = v;
			fptr->assigned = assigned;
		   fptr->processnumber = processnumber;
		   fptr->processsize = processsize;
		}
	}
}
int LinkedList::sort()
{

	if(this->head == NULL || this->head->next == NULL)
	{
		return 0;
	}
	else
	{
		node *current = head;
		node *current2 = head->next;
		int temp1, temp2, temp3;
		bool temp4;
    while(current->next != NULL)
    {
        if(current->data > current2->data)
        {
            temp1 = current->data;
            current->data = current2->data;
            current2->data = temp1;
            
            
            temp2 = current->processnumber;
            current->processnumber = current2->processnumber;
            current2->processnumber = temp2;
            
            temp3 = current->processsize;
            current->processsize = current2->processsize;
            current2->processsize = temp3;
            
            temp4 = current->assigned;
            current->assigned = current2->assigned;
            current2->assigned = temp4;
            
            
			current = head;
			current2 = current->next;
        }
		else
		{
			current = current->next;
			current2 = current2->next;
		}
    }
	}
	return 1;
}
int LinkedList::reversesort()
{

	if(this->head == NULL || this->head->next == NULL)
	{
		return 0;
	}
	else
	{
		node *current = head;
		node *current2 = head->next;
		int temp1, temp2, temp3;
		bool temp4;
    while(current->next != NULL)
    {
        if(current->data < current2->data)
        {
            temp1 = current->data;
            current->data = current2->data;
            current2->data = temp1;
            
            
            temp2 = current->processnumber;
            current->processnumber = current2->processnumber;
            current2->processnumber = temp2;
            
            temp3 = current->processsize;
            current->processsize = current2->processsize;
            current2->processsize = temp3;
            
            temp4 = current->assigned;
            current->assigned = current2->assigned;
            current2->assigned = temp4;
            
            
			current = head;
			current2 = current->next;
        }
		else
		{
			current = current->next;
			current2 = current2->next;
		}
    }
	}
	return 1;
}
int LinkedList::deletelast()
{
	if(head == NULL || head->next == NULL)
	{
		if(head->next == NULL)
		{
			int temp;
			temp = head->data;
			head = NULL;
			return temp;
		}
		head = NULL;
	}
	else
	{
		int temp;
		node *ptr;
		ptr = head;
		while(ptr->next->next != NULL)
		{
			ptr = ptr->next;
		}
		temp = ptr->next->data;
		ptr->next = NULL;
		return temp;
	}

}
void Stack::push(int v)
{
	insert(v, false);
}
int Stack::pop()
{
	deletelast();
}

void Queue::enqueue(int v)
{
	insert(v, false);
}
int Queue::dequeue()
{
	if (head != NULL)
	{
		int temp;
		temp = head->data;
		head = head->next;
		return temp;
	}
}

LinkedList::~LinkedList()
{
  delete head;
}
