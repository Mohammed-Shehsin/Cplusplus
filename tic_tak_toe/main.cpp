#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
char currentPlayer = 'X';

void drawBoard() {
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
  cout << "---+---+---" << endl;
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
  cout << "---+---+---" << endl;
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool isMoveValid(int row, int col) {
  if (row < 0 || row > 2 || col < 0 || col > 2) {
    return false;
  }
  if (board[row][col] == 'X' || board[row][col] == 'O') {
    return false;
  }
  return true;
}

bool isGameOver() {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return true;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return true;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return true;
  }

  // Check for tie game
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 'X' && board[i][j] != 'O') {
        return false;
      }
    }
  }
  return true;
}

void switchPlayer() {
  if (currentPlayer == 'X') {
   currentPlayer = 'O';
  } else {
    currentPlayer = 'X';

  }
}

void play() {
  int row, col;
  cout << "Player " << currentPlayer << " make your move:" << endl;
  cin >> row >> col;
  if (!isMoveValid(row, col)) {
    cout << "Invalid move. Try again." << endl;
    play();
  } else {
    board[row][col] = currentPlayer;
    drawBoard();
    if (isGameOver()) {
      cout << "Game over."<<endl<<" Player " << currentPlayer << " wins!" << endl;
    } else {
      switchPlayer();
      play();
    }
  }
}

int main() {
  drawBoard();
  play();
  return 0;
}
