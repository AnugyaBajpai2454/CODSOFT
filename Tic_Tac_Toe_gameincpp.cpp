#include <iostream>
#include <string>
using namespace std;

int main() {
    char grid_line[3][3] = {
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

    for (int i = 0; i < 9; i++) {
        cout << "   |   |   " << endl;
        cout << " " << grid_line[0][0] << " | " << grid_line[0][1] << " | " << grid_line[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << grid_line[1][0] << " | " << grid_line[1][1] << " | " << grid_line[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << grid_line[2][0] << " | " << grid_line[2][1] << " | " << grid_line[2][2] << endl;
        cout << "   |   |   " << endl;

        if (winner != ' ') {
            break;
        }

        cout << "Current Player is " << currentPlayer << endl;
        while (true) {
            cout << "Enter row and column one at a time (starting from 0 to 2 example: 0 0, 0 1,0 2,1 0) (Input will be taken in line break form): ";
            cin >> r >> c;
            if (r < 0 || r > 2 || c < 0 || c > 2) {
                cout << "Invalid input,please try again." << endl;
            }
            else if (grid_line[r][c] != ' ') {
                cout << "Tile is full, please try again." << endl;
            }
            else {
                break;
            }
            r = -1;
            c = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        grid_line[r][c] = currentPlayer;
        currentPlayer = (currentPlayer == playerA) ? playerB : playerA;

        for (int r = 0; r < 3; r++) {
            if (grid_line[r][0] != ' ' && grid_line[r][0] == grid_line[r][1] && grid_line[r][1] == grid_line[r][2]) {
                winner = grid_line[r][0];
                break;
            }
        }

        for (int c = 0; c < 3; c++) {
            if (grid_line[0][c] != ' ' && grid_line[0][c] == grid_line[1][c] && grid_line[1][c] == grid_line[2][c]) {
                winner = grid_line[0][c];
                break;
            }
        }

        if (grid_line[0][0] != ' ' && grid_line[0][0] == grid_line[1][1] && grid_line[1][1] == grid_line[2][2]) {
            winner = grid_line[0][0];
        }
        else if (grid_line[0][2] != ' ' && grid_line[0][2] == grid_line[1][1] && grid_line[1][1] == grid_line[2][0]) {
            winner = grid_line[0][2];
        }
    }

    if (winner != ' ') {
        cout << "Player " << winner << " wins!!" << endl;
    }
    else {
        cout << "It's a draw!, you can play again !" << endl;
    }
}
