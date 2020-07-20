#include <iostream>
using namespace std;

int main()
{
	int arrivalflag, numberofprocess, arrivaltime, bursttime, completiontime, turnarroundtime, waitingtime;
	
	
	
	cout<<"###########################################################################"<< endl;
	cout<<"                   Arrival Time Decision(0 for all or different)                       "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<<"Enter 1 if you want different arrival time ,0 for same arrival time "<< endl;
	cin>> arrivalflag;
	
	
	
	
	cout<<"###########################################################################"<< endl;
	cout<<"                               Number of Processes                       "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<< "Enter Number of processes you want to create"<< endl;
	cin >> numberofprocess;
	int burstarray[numberofprocess];
	int arrivalarray[numberofprocess];
	
	
	
	
	if(arrivalflag == 1)
	{
	cout<<"###########################################################################"<< endl;
	cout<<"                      Enter Arrival Time for each Process                     "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
		for(int i = 0; i < numberofprocess; i++)
		{
			cout<< "Enter arrival time for process pid_"<< i<< endl;
			cin>> arrivaltime;
			arrivalarray[i] = arrivaltime;
		}
	}
	else
	{
		for(int i = 0; i < numberofprocess; i++)
		{
			arrivalarray[i] = 0;
		}
	}
	
	
	
	
	
	cout<<"###########################################################################"<< endl;
	cout<<"                      Enter Burst Time for each Process                     "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	for(int i = 0; i < numberofprocess; i++)
	{
			cout<< "Enter burst time for process pid_"<< i<< endl;
			cin>> bursttime;
			burstarray[i] = bursttime;
	}
	int temp = 0;
	int process[numberofprocess][3];
	for(int i = 0; i < numberofprocess; i++)
	{
		process[i][0]= i;
		process[i][1]= arrivalarray[i];
		process[i][2]= burstarray[i];
	}
	
	
	
	// Sorting Array by Arrival time
	if(arrivalflag == 1)
	{
	
	int t[3]={0,0,0};
	for(int i=0; i < numberofprocess-1; i++)
	{
	    for(int j=0; j< numberofprocess-i-1; j++)
		{
			if(process[j][1] > process[j+1][1])
			{
			
				t[0] = process[j][0];
				t[1]= process[j][1];
				t[2]= process[j][2];
				process[j][0] = process[j+1][0];
				process[j][1] =process[j+1][1];
				process[j][2] = process[j+1][2];
				process[j+1][0] = t[0];
				process[j+1][1] = t[1];
				process[j+1][2] = t[2];
			
			}
		}
	}
	
}



	cout<<"###########################################################################"<< endl;
	cout<<"                     Evaluating Times for each Process                     "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;	
	float averagewaittime = 0;
	float averageturnarroundtime = 0;


	cout<< "Arrival time | ProcessID | BurstTime | CompletionTime | TurnArroundTime | WaitingTime"<< endl;


	if(true)
	{
	for(int i = 0; i < numberofprocess; i++)
	{
		arrivaltime = process[i][1];
		bursttime = process[i][2];
		completiontime = bursttime + arrivaltime;
		if(temp > arrivaltime)
		{
			completiontime = temp + bursttime;
			temp = completiontime;
		}
		else
		{
			temp = completiontime;
		}
		
		
		turnarroundtime = completiontime - arrivaltime;
		waitingtime= turnarroundtime - bursttime;
		
		cout<< arrivaltime<<" 	     |"<<"pid_"<< process[i][0]<<"    	 |"<< bursttime<<"  	     |"<<completiontime<<" 	      |"<<turnarroundtime<<"  		|"<<waitingtime<< endl;
		averagewaittime = averagewaittime + waitingtime;
		averageturnarroundtime = averageturnarroundtime + turnarroundtime;		
	}
	averageturnarroundtime = averageturnarroundtime/numberofprocess;
	averagewaittime = averagewaittime/numberofprocess;
	




	cout<<"###########################################################################"<< endl;
	cout<<"                      Average Wait and Turn arround Time                  "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	
	cout<< "Average Turn Arround Time :"<< averageturnarroundtime << endl;
	cout<< "Average Wait Time :"<<averagewaittime<< endl;
}
	
}

