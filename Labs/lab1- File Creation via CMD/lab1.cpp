#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

inline bool exists_test1 (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}
int main()
{
  string input;
  cout<< "****************************************************************"<<'\n';
  cout << "Enter file name to create." << '\n';
  cout<< "****************************************************************"<<'\n';
  cin >> input;
  
  string txt = ".txt";
  string newinput;
  newinput = input+txt;
  cout<< "request for "<<newinput<<" file creation sent." <<'\n';
  ifstream infile;
  
  infile.open(newinput.c_str());
  if(exists_test1(newinput))
  {
  	cout<< '\n';
  	cout<< "file with same name already exists new one will be created with a postfix ."<< '\n';
  	cout<< '\n';
  }
  
  int i = 1;
  while(true)
  {
  	if(!exists_test1(newinput))
  	{
  		break;
	}
  	stringstream ss;
  	ss << i;
    string j = ss.str();
    newinput = input +"_"+ j + txt;
    i++;
  }
  
  string finalinput = newinput;
  ofstream outfile(finalinput.c_str(), ios::out | ios::trunc);
  cout<< "****************************************************************"<<'\n';
  cout<<input << "file with "<< newinput<<" name is created successfully"<< '\n';
  cout<< "****************************************************************"<<'\n';
  return 0;

}
