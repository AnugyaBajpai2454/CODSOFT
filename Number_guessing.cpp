#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  srand((unsigned int) time(NULL));
  int Number_To_Guess = (rand() % 100) + 1; 
  int Guess = 0;
}
