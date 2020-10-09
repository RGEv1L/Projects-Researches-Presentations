/*  Q-4.20

The examination-results program of Fig. 4.16 assumes that any value
input by the user that is not a 1 must be a 2. Modify the application to validate its inputs. On
any input, if the value entered is other than 1 or 2, keep looping until the user enters a correct value.
*/

#include <iostream>
using namespace std;

int main()
{
  
   int passes = 0;     // number of passes       
   int failures = 0;   // number of failures   
   int studentCounter = 1; // student counter
   int result;          // one exam result (1 = pass, 2 = fail)

                                     
   while ( studentCounter <= 10 ) 	// process 10 students using counter-controlled loop
   {
      
      cout << "Enter result (1 = pass, 2 = fail): ";  // prompt user for input and obtain value from user
      cin >> result; 	// input result

     	                        // if...else nested in while                           
      if ( result == 1 )          // if result is 1,         
         passes = passes + 1;     // increment passes;       
      else if  (result == 2)               // else result is not 1, so
         failures = failures + 1; // increment failures      
	  else
	  {
		  cout << "Incorrect input! Try again." << endl;
		  studentCounter--;
	  }

      
      studentCounter++ ; 	// increment studentCounter so loop eventually terminates
   } 

   
   cout << "Passed " <<passes<< "\nFailed " << failures << endl;		// termination phase; display number of passes and failures

   
   if ( passes > 8 )			// determine whether more than eight students passed
      cout << "Bonus to instructor!" << endl; 
} 
