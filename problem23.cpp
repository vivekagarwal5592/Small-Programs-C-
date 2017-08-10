#include<iostream>
using namespace std;

int main()
{
	
	int val[10] = {2,3,1,0,15,6,11,8,9,5};
	int rank[10] = {0,0,0,0,0,0,0,0,0,0};
	int newval[10];
	
	for(int i=0;i<=9;i++){
		for(int j=i+1;j<=9;j++){
			
			if(val[i]>=val[j]){
				rank[i] +=1;
			}
			else{
				rank[j] +=1;
			}	
		}
		
	}
	
	for(int i=0;i<=9;i++){
		newval[rank[i]] = val[i];
	}
	
	for(int i=0;i<=9;i++){	
		cout<<newval[i]<<endl;
	}

return 0;
}
