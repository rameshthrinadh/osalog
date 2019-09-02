#include<iostream> 
using namespace std; 
void wttime(int pr[], int n, int bt[],int wt[], int at[],int ct) 
{ 
	int st[n]; 
	st[0] = 0; 
	wt[0] = 0;

	for (int i = 1; i < n ; i++) 
	{ 
		st[i] = st[i-1] + bt[i-1]; 
		ct=ct+st[i];
		if(ct<at[i])
		{
				ct=ct+(at[i]-ct);
				st[i]=ct;
		}	
	wt[i] = st[i] - at[i]; 
		if (wt[i] < 0) 
			wt[i] = 0; 
	} 
} 
void tattime(int pr[], int n, int bt[],int wt[], int tat[]) 
{ 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 
void avgtime(int pr[], int n, int bt[], int at[],int ct) 
{ 
	int wt[n], tat[n]; 
	wttime(pr, n, bt, wt, at,ct); 
	tattime(pr, n, bt, wt, tat); 
	cout << "processes " << " burst Time " << " arrival time "<< " waiting time " << "tat" << " completion time\n"; 
	int totalwt = 0, totaltat = 0; 
	for (int i = 0 ; i < n ; i++) 
	{ 
		totalwt = totalwt + wt[i]; 
		totaltat = totaltat + tat[i]; 
		int compltime = tat[i] + at[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] << "\t\t"	<< at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i] << "\t\t " << compltime << endl; 
	} 

	cout << "avg waiting time = "<< (float)totalwt / (float)n; 
	cout << "\naverage turn around time = "	<< (float)totaltat / (float)n; 
} 
int main() 
{ int n,ct=0;
	cout<<"enter the no of process: ";
	cin>> n;
	int at[n],bt[n],pr[n];
	cout<<"enter details: \n";
	for(int i=0;i<n;i++){
		cout<<"enter  id of "<<i+1<<"th process : ";cin>>pr[i];cout<<"\n";
		cout<<"enter arrival time : "<<i+1<<"th process : ";cin>>at[i];cout<<"\n";
		cout<<"enter burst time: "<<i+1<<"th process : ";cin>>bt[i];cout<<"\n";
		
	}
	avgtime(pr, n, bt, at,ct); 

	return 0; 
} 

