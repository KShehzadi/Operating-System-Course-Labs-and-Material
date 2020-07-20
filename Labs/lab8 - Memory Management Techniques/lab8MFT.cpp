#include "linkedlist.cpp"
#include <iostream>
using namespace std;
int main()
{
	LinkedList * MemoryBlocks = new LinkedList();
	int NumberOfMemoryBlocks;
	int UsableBlockSize;
	int backupMemorySize;
	int MemorySize;
	cout<<"###########################################################################"<< endl;
	cout<<"                            MEMORY SIZE                                    "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<<"Enter Memory Size you want to create "<< endl;
	cin>> MemorySize;
	backupMemorySize = MemorySize;
	cout<<"###########################################################################"<< endl;
	cout<<"                        USABLE BLOCK SIZE                                    "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<<"Enter Usable Block Size. "<< endl;
	cin>> UsableBlockSize;
	int temp1;
	for(int i = 0; MemorySize > 0; i++)
	{
		if(MemorySize > UsableBlockSize)
		{
			MemorySize = MemorySize -UsableBlockSize;
			temp1 = UsableBlockSize;
		}
		else
		{
			temp1 = MemorySize;
			MemorySize = 0;
			NumberOfMemoryBlocks = i+1;
		}
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
	
	LinkedList * l1 = new LinkedList();
	LinkedList * l2 = new LinkedList();
	LinkedList * l3 = new LinkedList();
	LinkedList * show = new LinkedList();
	l1->head = Processes->head; 
	show->insert(0,false);
	l3->head = show->head; 
	if(true)
	{
		for(int i = 0; i < numberofprocess ;i++)
		{
			bool assigned = false;
			l2->head = MemoryBlocks->head;
		   
			for(int j = 0; j < NumberOfMemoryBlocks; j++)
			{
			
				if(l2->head->data >= l1->head->data && l2->head->assigned == false && l2->head->data == UsableBlockSize)
				{
				  
					l2->updateassigned(true, l2->head->data, i+1, l1->head->data);
					
					l3->updateassigned(true,l2->head->data,i+1, l1->head->data);
				
					 show->insert(0,false);
				
					assigned = true;
					break;
			   }	
				l2->head = l2->head->next;
			}
			if(assigned == false)
			{
				l3->updateassigned(false,0,i+1, l1->head->data);
				 show->insert(0,false);
			}
			l1->head = l1->head->next;
			l3->head = l3->head->next;
		}
	}
	l1->head = show->head;
	int internalf=0;
	int externalf = 0;
	int usedmemory = 0;
	cout<< "Process #       | Process Size             | Memory Block #       | Memory Block Size   | Block Allocated   | FragmentSize"<< endl;
	for(int i = 0; i < numberofprocess; i++)
	{
		 cout<<l1->head->processnumber<<"               |"<<l1->head->processsize<<"                       |"<< i+1<< "                     |"<< l1->head->data;
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
	cout<< "Internal Fragmentation "<< internalf<<endl;
	cout<<"External Fragmentation "<< externalf<<endl;
}
