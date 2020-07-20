#include "linkedlist.cpp"
#include <iostream>
using namespace std;
int main()
{
	LinkedList * MemoryBlocks = new LinkedList();
	int NumberOfMemoryBlocks;
	cout<<"###########################################################################"<< endl;
	cout<<"                   NUMBER OF MEMORY BLOCKS                                 "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<<"Enter number of memory blocks you want to create "<< endl;
	cin>> NumberOfMemoryBlocks;
	int temp1;
	for(int i = 0; i < NumberOfMemoryBlocks; i++)
	{
		cout<< "Memory Size for Block #"<< i+1<< endl;
		cin>> temp1;
		MemoryBlocks->insert(temp1, false);
	}
	int numberofprocess;
	cout<<"###########################################################################"<< endl;
	cout<<"                               Number of Processes                       "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<< "Enter Number of processes you want to create"<< endl;
	cin >> numberofprocess;
	LinkedList * Processes = new LinkedList();
	for(int i = 0; i < numberofprocess; i++)
	{
		cout<< "Enter Process Size for Process #"<< i+1<<endl;
		cin>> temp1;
		Processes->insert(temp1, false);
	}
	int method;
	cout<<"###########################################################################"<< endl;
	cout<<"            	Enter Number of Method You want to use                       "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<< "1- First Fit                       2- Best Fit                   3- Worst Fit"<< endl;
	cin >> method;
	LinkedList * l1 = new LinkedList();
	LinkedList * l2 = new LinkedList();
	l1->head = Processes->head;  
	if(method == 1)
	{
		for(int i = 0; i < numberofprocess ;i++)
		{
			l2->head = MemoryBlocks->head;
			for(int j = 0; j < NumberOfMemoryBlocks; j++)
			{
			
				if(l2->head->data >= l1->head->data && l2->head->assigned == false)
				{
				
					l2->updateassigned(true, l2->head->data, i+1, l1->head->data);
					break;
				}
				l2->head = l2->head->next;
			}
			l1->head = l1->head->next;
		}
	}
	else if(method == 2)
	{
		
		MemoryBlocks->sort();
	
		for(int i = 0; i < numberofprocess ;i++)
		{
			l2->head = MemoryBlocks->head;
			for(int j = 0; j < NumberOfMemoryBlocks; j++)
			{
			
				if(l2->head->data >= l1->head->data && l2->head->assigned == false)
				{
				
					l2->updateassigned(true, l2->head->data, i+1, l1->head->data);
					break;
				}
				l2->head = l2->head->next;
			}
			l1->head = l1->head->next;
		}
	}
	else if(method == 3)
	{
		l1->reversesort();
		for(int i = 0; i < numberofprocess ;i++)
		{
			l2->head = MemoryBlocks->head;
			for(int j = 0; j < NumberOfMemoryBlocks; j++)
			{
			
				if(l2->head->data >= l1->head->data && l2->head->assigned == false)
				{
				
					l2->updateassigned(true, l2->head->data, i+1, l1->head->data);
					break;
				}
				l2->head = l2->head->next;
			}
			l1->head = l1->head->next;
		}
	}
	
	
	
	
	
	l1->head = MemoryBlocks->head;
	cout<< "Process #       | Process Size           | Memory Block #       | Memory Block Size"<< endl;
	for(int i = 0; i < NumberOfMemoryBlocks; i++)
	{
		 cout<<l1->head->processnumber<<"               |"<<l1->head->processsize<<"                       |"<< i+1<< "                     |"<< l1->head->data<< endl;
		 l1->head = l1->head->next;
	}
}
