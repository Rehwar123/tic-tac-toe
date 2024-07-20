#include<iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkWin(char player) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for(int i=0; i<3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
       (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    initializeBoard();
    char currentPlayer = 'X';
    int row, col;
    while(true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        row--; col--; // Convert to 0-based index
        if(row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid move, try again.\n";
            continue;
        }
        if(board[row][col] != '-') {
            cout << "Cell is already occupied, try again.\n";
            continue;
        }
        board[row][col] = currentPlayer;
        if(checkWin(currentPlayer)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if(checkDraw()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    playGame();
    return 0;
}