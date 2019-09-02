#include<iostream> 
#include<typeinfo>
using namespace std;
 
void swap(int *p,int *q){
	int t=*p;
	*p=*q;*q=t;
}
void cttime(int pr[],int at[],int bt[],int n,int ct[]) 
{ 														//cttime....
	for(int i=0;i<n;i++){
		int co=0;
		if(i==0){
		ct[i]=bt[i]+at[i];
		cout<<ct[i]<<"\n";
		}
		else{
			for(int j=i;j<n;j++){
				if(at[j]<=ct[i-1]){co++;}
				}
			for(int k=i;k<=co;k++){
				for(int l=k+1;l<=co;l++){
					if(bt[k]>bt[l]){
						swap(&at[k],&at[l]);
						swap(&bt[k],&bt[l]);
						swap(&pr[k],&pr[l]);
					}
				}
			}	
			if(at[i]<=ct[i-1]){
				
				ct[i]=bt[i]+at[i]+(ct[i-1]-at[i]);
			}	
			else{
				
				ct[i]=bt[i]+at[i];
			}
			}
		}											//tat and wttime.....
	int tat[n],wt[n];
	for(int i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		}
	cout << "processes " << " burst Time " << " arrival time "<< " waiting time " << "   	 	  tat          " << " completion time\n"; 
	int totalwt = 0, totaltat = 0,l=0; 
	for (int i = 0 ; i < n ; i++) 
	{ 
		totalwt = totalwt + wt[i]; 
		totaltat = totaltat + tat[i];
		l=tat[i]+at[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] << "\t\t"	<< at[i] << "\t\t" << wt[i] << "\t\t "<< tat[i] << "\t\t " << ct[i] << endl; 
	} 

	cout << "avg waiting time = "<< (float)totalwt / (float)n; 
	cout << "\naverage turn around time = "	<< (float)totaltat / (float)n; 

}
		


void sort(int pr[],int at[],int bt[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(at[i]>at[j]){
				swap(&at[i],&at[j]);
				swap(&bt[j],&bt[i]);
				swap(&pr[i],&pr[j]);
			}
			else if(at[i]==at[j]){
				if(bt[i]>bt[j]){
				swap(&at[i],&at[j]);
				swap(&bt[j],&bt[i]);
				swap(&pr[i],&pr[j]);}
			}
		}
	}
	int ct[n];
	cttime(pr,at,bt,n,ct);
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
	sort(pr,at,bt,n);

	return 0; 
} 

