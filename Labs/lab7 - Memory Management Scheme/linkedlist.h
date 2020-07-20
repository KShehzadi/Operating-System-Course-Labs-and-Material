class node
{
	public:
		int data;
		bool assigned;
		int processnumber;
		int processsize;
		node * next;
};

class LinkedList
{
public:
		node * head;
public:
		LinkedList();
		~LinkedList();
		void insert(int v, bool assigned);
		void deleteone(int v);
		int deletelast();
		void updateassigned(bool assigned, int v,int processnumber, int processsize);
    void deletemultiple(int v);
		void print();
		int search(int v);
		int sort();
		int reversesort();
};

class Stack:public LinkedList
{
public:
	void push(int v);
	int pop();
};
class Queue:public LinkedList
{
public:
	void enqueue(int v);
	int dequeue();
};
