//
//  main.cpp
//  project
//
//  Created by valentin student on 16.10.2023.
//

#include <iostream>
#include <vector>

using namespace std;

bool isValidMove(int x, int y, int N, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

void solveKnightTour(int N, int startRow, int startCol) {
    vector<vector<int>> board(N, vector<int>(N, -1));

    int moveX[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int moveY[] = {1, 2, 2, 1, -1, -2, -2, -1};

    int moveNumber = 0;
    board[startRow][startCol] = moveNumber;

    for (moveNumber = 1; moveNumber < N * N; moveNumber++) {
        int currentRow = startRow;
        int currentCol = startCol;
        int minNeighbors = 9;
        int nextMove = -1;

        for (int k = 0; k < 8; k++) {
            int nextRow = currentRow + moveX[k];
            int nextCol = currentCol + moveY[k];

            if (isValidMove(nextRow, nextCol, N, board)) {
                int neighbors = 0;

                for (int m = 0; m < 8; m++) {
                    int neighborX = nextRow + moveX[m];
                    int neighborY = nextCol + moveY[m];

                    if (isValidMove(neighborX, neighborY, N, board)) {
                        neighbors++;
                    }
                }

                if (neighbors < minNeighbors) {
                    minNeighbors = neighbors;
                    nextMove = k;
                }
            }
        }

        if (nextMove == -1) {
            cout << "Nu este posibila crearea schemei cu mutarea calului.\n";
            return;
        }

        startRow += moveX[nextMove];
        startCol += moveY[nextMove];
        board[startRow][startCol] = moveNumber;
    }

    cout << "Solutia pentru circuitul calului:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int N, i, j;

    cout << "Introduceti dimensiunea tablei de sah (N): ";
    cin >> N;
    cout << "Introduceti coordonatele initiale ale calului (i, j): ";
    cin >> i >> j;

    if (i < 0 || i >= N || j < 0 || j >= N) {
        cout << "Coordonatele initiale ale calului nu sunt valide.\n";
        return 1;
    }

    solveKnightTour(N, i, j);

    return 0;
}
