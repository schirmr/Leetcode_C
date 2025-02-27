#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool lin[9][9] = { false };
    bool col[9][9] = { false };
    bool caixa[9][9] = { false };

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char num = board[i][j];
            if (num != '.') {
                int digit = num - '1';
                int caixaIndex = (i / 3) * 3 + (j / 3);

                if (lin[i][digit] || col[j][digit] || caixa[caixaIndex][digit]) {
                    return false;
                }

                lin[i][digit] = true;
                col[j][digit] = true;
                caixa[caixaIndex][digit] = true;
            }
        }
    }

    return true;
}

int main() {
    char* board[9] = {{"53..7...."},
                        {"6..195..."},
                        {".98....6."},
                        {"8...6...3"},
                        {"4..8.3..1"},
                        {"7...2...6"},
                        {".6....28."},
                        {"...419..5"},
                        {"....8..79"}};
    int boardColSize = 9;
    if (isValidSudoku(board,9,&boardColSize)) {
        printf("TRUE");
    }
    else {
        printf("FALSE");
    }
    return 0;
}