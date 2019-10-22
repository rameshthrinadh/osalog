#include<iostream>
using namespace std;
int main(){
	int pn,rn;
	cout<<"enter the no of process: ";
	cin>>pn;
	cout<<"enter the no.of resource types : ";
	cin>>rn;
	int alc[pn][rn],max[pn][rn],avl[rn];
	for(int i=0;i<pn;i++){
		cout<<"enter for process "<<i<<" allocated resources :";
		for(int j=0;j<rn;j++){
			cin>>alc[i][j];
		}
		cout<<"and max resources needed to complete : ";
		for(int j=0;j<rn;j++){
			cin>>max[i][j];
		}
	}
	cout<<"enter available resources : ";
	for(int i=0;i<rn;i++){
		cin>>avl[i];
	}
int need[pn][rn],fn[pn],sol[pn],n=0;
for(int i=0;i<pn;i++){fn[i]=0;}
	for(int i=0;i<pn;i++){
		for(int j=0;j<rn;j++){
			need[i][j]=max[i][j]-alc[i][j];
		}
	}
	for(int i=0;i<pn;i++){
		for(int j=0;j<pn;j++){
			int tr=0;
			if(fn[j]==0){
				for(int k=0;k<rn;k++){
					if(need[j][k]>avl[k]){
						tr=1;break;		
					}
				}
				if(tr==0){
					sol[n++]=j;
					for(int p=0;p<rn;p++){
						avl[p]+=alc[j][p];
						fn[j]=1;
					}
				}
			}
		}
	}
	cout<<"entered data is :";
	cout<<"\n process \t\t alloc\t\t max \t\t need \n";
for(int i=0;i<pn;i++){
	
		cout<<"process "<<i<<"\t\t";
	
		for(int j=0;j<rn;j++){
			cout<<alc[i][j]<<" ";
		}
		cout<<"\t\t";
		for(int j=0;j<rn;j++){
			cout<<max[i][j]<<" ";
		}
		cout<<"\t\t";
		for(int j=0;j<rn;j++){
			cout<<need[i][j]<<" ";
		}
		cout<<"\n";
}		
cout<<"the available process after allocating is : ";
for(int i=0;i<rn;i++){
	cout<<avl[i]<<" ";
}
cout<<"\nthe seqence of processes to be executed is : ";
	for(int i=0;i<pn;i++){
		cout<<"pr->"<<sol[i]<<" ";
		}
}
