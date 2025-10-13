#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1)) {
                return true;
            }
            board[i][col] = 0;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0)) {
        cout << "Solution found:" << endl;
        printBoard(board);
    } else {
        cout << "Solution does not exist." << endl;
    }

    return 0;
}