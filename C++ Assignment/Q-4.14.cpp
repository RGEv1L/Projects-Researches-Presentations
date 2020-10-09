/*  Q-4.14

Develop a C++ program that will determine whether a department-store
customer has exceeded the credit limit on a charge account. For each customer, the following
facts are available:
a) Account number (an integer)
b) Balance at the beginning of the month
c) Total of all items charged by this customer this month
d) Total of all credits applied to this customer's account this month
e) Allowed credit limit
The program should use a while statement to input each of these facts, calculate the new balance
(= beginning balance + charges – credits) and determine whether the new balance exceeds the customer’s
credit limit. For those customers whose credit limit is exceeded, the program should display
the customer’s account number, credit limit, new balance and the message “Credit Limit Exceeded.”
*/

#include<iostream>
using namespace std;

int main()
{
float N_Bal,B_Bal,C_Limit,Charges,Credits;
int   A_Num;

	cout<<"Welcome to Credit Limit Calculator\n";
	
while (A_Num != -1 )                   //Repitition Loop
{
	cout<<"Enter Account Number (or -1 to quit):";
	cin>>A_Num;
	
	if(A_Num == -1)  	//Instant loop break
	break;
	
	cout<<"Enter Beginning Balance:";
	cin>>B_Bal;
	
	cout<<"Enter total Charges:";
	cin>>Charges;
	
	cout<<"Enter total Credits:";
	cin>> Credits;
	
	cout<<"Enter Credit limit:";
	cin>>C_Limit;
	
	N_Bal = B_Bal + Charges - Credits;
	
	cout<<"New Balance:"<<N_Bal<<endl;
	
	if (N_Bal > C_Limit)            //Check Loop for limit 
	{
	cout<<"\nAccount#:"<<A_Num;
	cout<<"\nCredit Limit:"<<C_Limit;
	cout<<"\nBalance:"<<N_Bal;
	cout<<"\n 					Credit Limit Exceeded\n\n\n" ;
	
	system ("Pause");         //Hold the Screeen
	system ("CLS");			  //Clears the Screen

    } 


}	
	
	
	return 0;
}
