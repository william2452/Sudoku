#include <iostream>
#include <stdio.h>

using namespace std;

#define N 9

int sudokuBoard[N][N] =
{
  {0, 0, 6, 5, 0, 8, 4, 0, 0},
  {5, 2, 0, 0, 0, 1, 0, 0, 0},
  {0, 7, 8, 0, 0, 0, 0, 0, 1},
  {0, 0, 4, 0, 1, 0, 0, 8, 0},
  {9, 0, 0, 8, 2, 3, 0, 0, 5},
  {0, 5, 0, 0, 9, 0, 6, 0, 0},
  {1, 3, 0, 0, 0, 0, 2, 5, 0},
  {0, 0, 0, 0, 0, 0, 0, 7, 4},
  {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

bool checkColumn(int column, int value) {
  for(int row = 0; row < N; row++) {
    if(sudokuBoard[row][column] == value) {
      return true;
    }//end if
  }//end for
  return false;
}//end checkColumn

bool checkRow(int row, int value) {
  for(int column = 0; column < N; column++) {
    if(sudokuBoard[row][column] == value) {
      return true;
    }//end if
  }//end for
  return false;
}//end checkRow

bool checkBox(int initial_row, int initial_column, int value) {
  for(int row = 0; row < 3; row++) {
    for(int column = 0; column < 3; column++) {
        if(sudokuBoard[row + initial_row][column + initial_column] == value) {
            return true;
        }//end if
    }//end inner for
  }//end outer for
  return false;
}//end checkBox

void showGame() {
    for(int row = 0; row < N; row++) {
        for(int column = 0; column < N; column++) {
            if(column == 3 || column == 6) {
                cout << " | ";
            }//end if
            cout << sudokuBoard[row][column] << " ";
        }//end inner for
        if(row == 2 || row == 5) {
            cout << endl;
            for(int i = 0; i < N; i++) {
                cout << "---";
            }//end for
        }//end if
        cout << endl;
    }//end outer for
}//end showGame

bool findBox(int &row, int &column) {
    for(row = 0; row < N; row++) {
        for(column = 0; column < N; column++) {
            if(sudokuBoard[row] == 0) {
                return true;
            }//end if
        }//end inner for
    }//end outer for
    return false;
}//end findBox

bool canEnter(int row, int column, int value) {
    return !checkRow(row, value) && !checkColumn(column, value) && !checkBox(row-row%3, column-column%3, value);
}//end canEnter

bool finalSolution() {
    int row, column;
    if(!findBox(row, column)) {
        return true;
    }//end if
    for(int value = 1; value <= 9; value++) {
        if(canEnter(row, column, value)) {
            sudokuBoard[row][column] = value;
            if(finalSolution()) {
                return true;
            }//end if
            sudokuBoard[row][column] = 0;
        }//end if
    }//end for
    return false;
}//end finalSolution

int main() {
    if(finalSolution() == true) {
        showGame();
    } else {
        cout << "This game cannot be solved." << endl;
    }//end if/else


}//end main

