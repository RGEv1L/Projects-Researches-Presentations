/*  Q-4.15

A large company pays its salespeople on a commission basis.
The salespeople each receive $200 per week plus 9% of their gross sales for that week. For example,
a salesperson who sells $5000 worth of chemicals in a week receives $200 plus 9% of $5000, or a
total of $650. Develop a C++ program that uses a while statement to input each salesperson’s gross
sales for last week and calculates and displays that salesperson’s earnings. Process one salesperson’s
figures at a time.
*/

#include<iostream>
using namespace std;

int main()
{
float gross = 200,sales,earning;

	cout<<"Welcome To Sales Commission Calculator\n";
	
while	(sales != -1)        //Loop for sales calculations
{
	cout<<"Enter sales in dollars (-1 to end):";  
	cin>>sales;
	
	if(sales == -1)         //Instant loop break
	break;

	earning = gross + (sales *9)/100 ;
	
	cout<<"Salary is:"<<earning<<"$\n";
	
	system ("Pause");     //Holds the screen
	system ("CLS");		  ////Clears the screen	
   }
	


return 0;	
}
