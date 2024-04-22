#include <iostream>
#include <string>
using namespace std;

int main() {
    char grid[3][3] = {
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}
    };

    const char playerA = 'A';
    const char playerB = 'B';
    char currentPlayer = playerA;
    int r = -1;
    int c = -1;
    char winner = ' ';
