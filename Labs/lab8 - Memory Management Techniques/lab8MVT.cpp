#include "linkedlist.cpp"
#include <iostream>
using namespace std;
int main()
{
	LinkedList * MemoryBlocks = new LinkedList();
	int NumberOfMemoryBlocks;
	int UsableBlockSize;
	int MemorySize;
	int backupMemorySize;
	cout<<"###########################################################################"<< endl;
	cout<<"                            MEMORY SIZE                                    "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<<"Enter Memory Size you want to create "<< endl;
	cin>> MemorySize;
	backupMemorySize = MemorySize;
	LinkedList * l1 = new LinkedList();
	LinkedList * l2 = new LinkedList();
	LinkedList * mylist = new LinkedList();
	mylist->insert(0, false);
	l2->head = mylist->head;
	int i = 1;
	int processsize;
	cout<<"###########################################################################"<< endl;
	cout<<"                               Processes                       "<< endl;
	cout<<"###########################################################################"<< endl;
	while(true)
	{
		cout<< "Enter Process Size for Process #"<<i<<endl;
		cin>> processsize;
		
		if(processsize <= MemorySize)
		{
			MemorySize = MemorySize - processsize;
			l2->updateassigned(true,processsize,i,processsize);
			mylist->insert(0, false);
			i++;
			l2->head = l2->head->next;
		}
		else
		{
				l2->updateassigned(false,0,i,processsize);
				mylist->insert(0, false);
				i++;
				l2->head = l2->head->next;
		}
		cout<< "Enter 0 to exit and 1 for continue"<< endl;
		cin>> processsize;
		if(processsize == 0)
		{
			break;
		}
	}
	
	
	l1->head = mylist->head;
	int internalf=0;
	int externalf = 0;
	int usedmemory = 0;

	cout<< "Process #       | Process Size             | Memory Block #       | Memory Block Size   | Block Allocated   | FragmentSize"<< endl;
	for(int j = 0; j < i-1; j++)
	{
		 cout<<l1->head->processnumber<<"               |"<<l1->head->processsize<<"                       |"<< j+1<< "                     |"<< l1->head->data;
		 if(l1->head->assigned)
		 {
		 	cout<<"                  |yes"<<"                |"<<l1->head->data - l1->head->processsize <<endl;
		 	internalf = internalf + (l1->head->data - l1->head->processsize );
		 	usedmemory = usedmemory + l1->head->data;
		 }
		 else
		 {
		 	cout<<"                    |No"<<"                 |-"<<endl;
		 	
		 }
		 l1->head = l1->head->next;
	}
	externalf = backupMemorySize - usedmemory;
	cout<< "Memory Allocated is :"<< usedmemory<<endl;
	cout<< "Internal Fragmentation "<< internalf<<endl;
	cout<<"External Fragmentation "<< externalf<<endl;
}
