#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
int compare_string(string first, string second)
{
	int count = first.length();
	if(first.length() > second.length())
	{
		count = second.length();
		
	}
	for(int i = 0; i < 1; i++)
	{
		if(first[i] > 64 && first[i] < 91)
		{
			first[i] = first[i] + 32;
		}
		if(second[i] > 64 && second[i] < 91)
		{
			second[i] = second[i] + 32;
		}
		if(first[i] > second[i])
		{
			return 1;
		}
		if(first[i] < second[i])
		{
			return -1;
		}
	}

	return 0;
}
int main()
{
	char tokenizer, tokenizer2;
	string input;
	cout<<"***************************************************"<<"\n";
	cout<<"Enter a String line to tokenize it"<<"\n";
	cout<<"***************************************************"<<"\n";
	getline(cin, input);
	cout<<"***************************************************"<<"\n";
	cout<< "Enter your tokenizer"<< "\n";
	cout<<"***************************************************"<<"\n";
	tokenizer = getche();
	if(tokenizer > 64 && tokenizer < 91)
	{
		tokenizer2 = tokenizer + 32;
	}
	if(tokenizer > 96 && tokenizer < 123)
	{
		tokenizer2 = tokenizer - 32;
	}
	cout<< "\n";
	int i = 0;
	string array[50];
	string p;
	int k = 0;
	cout<<"***************************************************"<<"\n";
	cout<< "TOKENIZED STRING"<< "\n";
	cout<<"***************************************************"<<"\n";
	while(i < input.length())
	{
		if(input[i] == tokenizer || input[i] == tokenizer2)
		{
			cout<< "\n";	
		}
		else if(input[i] == ' ')
		{
			cout<< "_";	
		}
		else
		{
			cout<<input[i];	
		}		
		i++;
	
	}
	i = 0;
	k = 0;
	while(i <= input.length())
	{
		if(input[i] == ' ' && tokenizer != ' ')
		{
			
			p.push_back('_');
		}
		else if(input[i] == tokenizer || input[i] == tokenizer2)
		{
			array[k] = p;
			k++;
			p.clear();
		}
		else if(input[i] != tokenizer || input[i] != tokenizer2)
		{
			p.push_back(input[i]);
			
		}
		i++;
	}
	array[k] = p;
	cout<< "\n";
	string t;
	int j = 0;
	k = 0;
	string myarray[10];
	int count = sizeof(array)/sizeof(array[0]);
	while( j < count)
	{
		if(array[j] != " " && array[j] != "\n")
		{
			myarray[k] = array[j];
			k++;
		}
		j++;
	}
	count = sizeof(myarray)/sizeof(myarray[0]);
    for(i=0; i < count-1; i++)
	{
	    for(j=0; j< count-i-1; j++)
		{
			if(compare_string(myarray[j], myarray[j+1]) == 1)
			{
				t = myarray[j];
				myarray[j] = myarray[j+1];
				myarray[j+1] = t;
			}
		}
	}
	i = 0;
	cout<<"***************************************************"<<"\n";
	cout<< "SORTED TOKENIZED STRINGS"<< "\n";
	cout<<"***************************************************"<<"\n";
	while( i< count)
	{
		if(myarray[i] == "\0") {}
		
		else {
		cout<< myarray[i]<< "\n";
		}
		i++;	
	}
}
