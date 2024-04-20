#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  srand((unsigned int) time(NULL));
  int Number_To_Guess = (rand() % 100) + 1; 
  int Guess = 0;
  do
  {
    cout << "Enter Guess (Enter the number you think the code will take as random guess) (1-100): ";
    cin >> Guess;
    if (Guess > Number_To_Guess)
      cout << "Guess lower!" << endl;
    else if (Guess < Number_To_Guess)
      cout << "Guess higher!" << endl;
    else
      cout << "You won!" << endl;
  } while (Guess != Number_To_Guess);
   
  return 0;
}
