#include <iostream>
#include <cstring>

using namespace std;

class Sudoku {
private:
    int grid[9][9]{};

public:
    explicit Sudoku(int (*grid)[9]) {
        memcpy(this->grid, grid, 9 * 9 * sizeof(int));
    }

    bool operator==(const int (*otherGrid)[9]) {
        for (int i = 0; i < 9 * 9; i++) {
            if (grid[i % 9][i / 9] != otherGrid[i % 9][i / 9]) {
                return false;
            }
        }
        return true;
    }

    bool operator==(const Sudoku &other) {
        for (int i = 0; i < 9 * 9; i++) {
#ifdef PRINT
            printf("comparing grid(%d, %d)\n", i%9, i/9);
#endif
            if (grid[i % 9][i / 9] != other.grid[i % 9][i / 9]) {
                return false;
            }
        }
        return true;
    }

    int get(int i, int j) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j];
        }

        return -1;
    }

    int set(int i, int j, int val) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j] = val;
        }
        return -1;
    }

    void print() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf(" [%d] ", get(i, j));
                if (j == 8) {
                    printf("\n");
                }
            }
        }
        printf("===============================================\n");
    }
    //code based on https://codepumpkin.com/sudoku-solver-using-backtracking/

    bool containsInRow(int row, int number) {
        for (int i = 0; i < 9; i++) {
            if (grid[row][i] == number) {
                return true;
            }
        }
        return false;
    }

    bool containsInCol(int col, int number) {
        for (int i = 0; i < 9; i++) {
            if (grid[i][col] == number) {
                return true;
            }
        }
        return false;
    }


    bool containsInBox(int row, int col, int number) {
        int r = row - row % 3;
        int c = col - col % 3;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (grid[i][j] == number) {
                    return true;
                }
            }

        }
        return false;
    }


    bool isValid(int row, int col, int number) {
        return !(containsInRow(row, number)
                 || containsInCol(col, number)
                 || containsInBox(row, col, number));

    }

    bool solve() {
        // homework
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (grid[row][col] == 0) {
                    for (int number = 1; number <= 9; number++) {
                        if (isValid(row, col, number)) {
                            grid[row][col] = number;
                            if (solve()) {
                                return true;
                            } else {
                                grid[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};