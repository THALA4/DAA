#include <iostream>
using namespace std;

bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check if there's a conflict in the column or diagonal
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueens(int board[], int row, int n) {
    if (row == n) {
        // Print one of the possible solutions
        cout << "Solution: ";
        for (int i = 0; i < n; i++) {
            cout << board[i] + 1 << " ";  // +1 to convert to 1-based index
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;            // Place queen at (row, col)
            solveNQueens(board, row + 1, n); // Move to the next row
        }
        // Backtracking: board[row] will be overwritten in the next loop iteration
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    int board[n];  // Array to store column positions of queens
    solveNQueens(board, 0, n);

    return 0;
}
