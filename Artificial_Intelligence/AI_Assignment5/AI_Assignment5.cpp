#include<iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string checkWin(const vector<vector<string>>& board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != "" && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == "x") ? "computer" : "player";
        }
        if (board[0][i] != "" && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == "x") ? "computer" : "player";
        }
    }

    if (board[0][0] != "" && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == "x") ? "computer" : "player";
    }
    if (board[0][2] != "" && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == "x") ? "computer" : "player";
    }

    bool isDraw = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == "") {
                isDraw = false;
                break;
            }
        }
        if (!isDraw) break;
    }

    if (isDraw) {
        return "Draw";
    }

    return "Pending";
}

int minimax(vector<vector<string>>& board, bool isMaximizingPlayer) {
    string result = checkWin(board);
    if (result == "computer") return 1;
    if (result == "player") return -1;
    if (result == "Draw") return 0;

    if (isMaximizingPlayer) {
        int bestScore = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == "") {
                    board[i][j] = "x";
                    int score = minimax(board, false);
                    board[i][j] = "";
                    bestScore = max(bestScore, score);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == "") {
                    board[i][j] = "o";
                    int score = minimax(board, true);
                    board[i][j] = "";
                    bestScore = min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}

pair<int, int> findBestMove(vector<vector<string>>& board) {
    int bestScore = -1000;
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == "") {
                board[i][j] = "x";
                int score = minimax(board, false);
                board[i][j] = "";

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {i, j};
                }
            }
        }
    }
    return bestMove;
}

void printBoard(const vector<vector<string>>& board) {
    cout << "\n-----------------" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "| " << (board[i][j] == "" ? " " : board[i][j]) << " |";
        }
        cout << "\n-----------------" << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<string>> board(3, vector<string>(3, ""));
    int moveCount = 0;

    cout << "Tic-Tac-Toe" << endl;
    cout << "You are 'o', and the computer is 'x'." << endl;

    while (true) {
        printBoard(board);
        string winner = checkWin(board);

        if (winner != "Pending") {
            cout << "Game Over! Result: " << winner << endl;
            break;
        }

        if (moveCount % 2 == 0) {
            cout << "Computer's turn..." << endl;
            pair<int, int> bestMove = findBestMove(board);
            board[bestMove.first][bestMove.second] = "x";
            moveCount++;
        } else {
            int row, col;
            cout << "Enter your move (row and column, e.g., '0 1'): ";
            cin >> row >> col;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == "") {
                board[row][col] = "o";
                moveCount++;
            } else {
                cout << "Invalid move. Please try again." << endl;
            }
        }
    }
    
    printBoard(board);
    return 0;
}