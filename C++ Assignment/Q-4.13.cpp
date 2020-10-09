/*  Q-4.13

Drivers are concerned with the mileage obtained by their automobiles. One
driver has kept track of several tankfuls of gasoline by recording miles driven and gallons used for
each tankful. Develop a C++ program that uses a while statement to input the miles driven and gallons
used for each tankful. The program should calculate and display the miles per gallon obtained
for each tankful and print the combined miles per gallon obtained for all tankfuls up to this point.
*/

#include<iostream>
using namespace std;

int main()
{ 
float MPG,Miles,Gas,T_MPG,T_Miles,T_Gas;
int c = 1;      	//Control variable

	while(Miles != -1)  //Control Loop
{
  cout<<"Enter Miles and Gas used or Enter -1 to exit.\n";
  		cin>>Miles>>Gas;
    
    if (Miles == -1)       //Instant loop break
    break;
    
  MPG = Miles / Gas;
  T_Miles = T_Miles + Miles;
  T_Gas = T_Gas + Gas;
  T_MPG = T_Miles / T_Gas;
  
  	cout<<"Miles/Gallon:"<<MPG;                 //Miles per Gas for this iteration
	cout<<"\nTotal MPG AvG:"<<T_MPG<<endl;		//Miles per Gas for overall iterations
	
	
	cout<<endl;

}
	return 0;
}
