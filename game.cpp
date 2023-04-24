#include <iostream>
#include <cstdlib>

using namespace std;

char gameboard[3][3]; // the tic tac toe gameboard

// initializes the gameboard with empty spaces
void initializegameboard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            gameboard[i][j] = ' ';
        }
    }
}

// displays the current state of the gameboard
void displaygameboard() {
       cout << "\nTic Tac Toe : Game status" << endl;
       cout << "1 2 3" << endl;
       cout << "--------------";
     for (int i = 0; i < 3; i ++){ 
       cout << endl;
        for (int j =0; j < 3; j ++){
            cout << gameboard[i][j] << " | ";
        }
    }
    cout << "\n";
    cout << "--------------" << endl;
}

// checks if the gameboard is over (either someone won or the gameboard is full)
bool isGameover() {
    // check rows
    for(int i = 0; i < 3; i++) {
        if(gameboard[i][0] != ' ' && gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2]) {
            return true;
        }
    }

    // check columns
    for(int i = 0; i < 3; i++) {
        if(gameboard[0][i] != ' ' && gameboard[0][i] == gameboard[1][i] && gameboard[1][i] == gameboard[2][i]) {
            return true;
        }
    }

    // check diagonals
    if(gameboard[0][0] != ' ' && gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2]) {
        return true;
    }
    if(gameboard[0][2] != ' ' && gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0]) {
        return true;
    }

    // check if gameboard is full
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(gameboard[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// gets the user's next move
void getNextMove(int& row, int& col) {
    cout << "Enter row (1-3) for the next move: ";
    cin >> row;
    if (row > 3){
        cout << "Enter new row number that is in between 1 to 3:";
        cin >> row;
    }
    cout << "Enter column(1-3) for the next move: ";
    cin >> col;
    if (col > 3){
        cout << "Enter new column number that is in between 1 to 3:";
        cin >> col;
    }
    row--;
    col--;
}

// performs a move for the specified player (X or O) at the specified location
void performMove(int row, int col, char player) {
    int newrow, newcol;
    if(gameboard[row][col] == 'O' or gameboard[row][col] == 'X'){
        cout << "Please, enter an empty box with a new row and new column:" ;
        cin >> newrow >> newcol;
        newrow --;
        newcol --;
        gameboard[newrow][newcol] = player;
    }
    else{
        gameboard[row][col] = player;
    }
}

int main() {
    initializegameboard();
    char currentPlayer = 'X';

    while(!isGameover()) {
        displaygameboard();
        int row, col;
        getNextMove(row, col);
        performMove(row, col, currentPlayer);

        // switch players
        if(currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }

    displaygameboard();

    // determine winner
    if(isGameover()) {
        cout << "Game over!" << endl;
        if(currentPlayer == 'X') {
            cout << "O wins!" << endl;
        }
        else {
            cout << "X wins!" << endl;
        }
    }
}   