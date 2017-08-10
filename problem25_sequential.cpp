#include<iostream>
#include<math.h>
using namespace std;
float sum;
int x=2;

float factorial(float val){
	
	if(val ==0){
		return 1;
	}
	
for(int i=val-1;i>=1;i--){
val = val*i;

}

return val;

}


int main(int argc, char** argv)
{

 for(int i=0;i<=99;i=i++){	
 sum = sum + (pow(x,i))/factorial(i);
 }
 cout<<"sum: "<<sum<<endl;

return 0;
}
