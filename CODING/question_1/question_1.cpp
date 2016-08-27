//linux compiler supported
#include <iostream>
void averager(); 
using namespace std ;
int main()  
{
averager();  //function header averager can be used in other prorams also
}

void averager() //all inputs form 0 to 360 accpeted
{		//for requesting output send in a '-ve' number  
long double avg=0;
int t=0;
int val=0;
while(1){
t++;
cin>>val;
if(val<0){
cout<<avg;
}
else if(val>=0&&val<=360)
{
avg=(avg*(t-1)+val)/t;  //average calculation=> (prevoius average * previous count + new number )/new count
}
	
}
}
