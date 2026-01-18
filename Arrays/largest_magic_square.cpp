/*
----------------------------------------------------
Problem  : Largest Magic Square in Grid
Approach : Prefix Sum (Row + Column) Optimization
Author   : Vishvesh Paturkar
GitHub   : https://github.com/your-username
Date     : 2026
----------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int totalRows = grid.size();
        int totalCols = grid[0].size();

        // Row Prefix Sum
        vector<vector<int>> rowPrefix(totalRows, vector<int>(totalCols, 0));
        for (int r = 0; r < totalRows; r++) {
            rowPrefix[r][0] = grid[r][0];
            for (int c = 1; c < totalCols; c++) {
                rowPrefix[r][c] = rowPrefix[r][c - 1] + grid[r][c];
            }
        }

        // Column Prefix Sum
        vector<vector<int>> colPrefix(totalRows, vector<int>(totalCols, 0));
        for (int c = 0; c < totalCols; c++) {
            colPrefix[0][c] = grid[0][c];
            for (int r = 1; r < totalRows; r++) {
                colPrefix[r][c] = colPrefix[r - 1][c] + grid[r][c];
            }
        }

        // Try biggest square first (Optimization)
        for (int squareSize = min(totalRows, totalCols); squareSize >= 2; squareSize--) {

            for (int startRow = 0; startRow + squareSize - 1 < totalRows; startRow++) {
                for (int startCol = 0; startCol + squareSize - 1 < totalCols; startCol++) {

                    // Target Sum (First Row of Square)
                    int expectedSum = rowPrefix[startRow][startCol + squareSize - 1] -
                                      (startCol > 0 ? rowPrefix[startRow][startCol - 1] : 0);

                    bool isMagic = true;

                    // Check All Rows
                    for (int r = startRow + 1; r < startRow + squareSize; r++) {
                        int currentRowSum = rowPrefix[r][startCol + squareSize - 1] -
                                            (startCol > 0 ? rowPrefix[r][startCol - 1] : 0);

                        if (currentRowSum != expectedSum) {
                            isMagic = false;
                            break;
                        }
                    }

                    if (!isMagic) continue;

                    // Check All Columns
                    for (int c = startCol; c < startCol + squareSize; c++) {
                        int currentColSum = colPrefix[startRow + squareSize - 1][c] -
                                            (startRow > 0 ? colPrefix[startRow - 1][c] : 0);

                        if (currentColSum != expectedSum) {
                            isMagic = false;
                            break;
                        }
                    }

                    if (!isMagic) continue;

                    // Check Diagonals
                    int mainDiagonalSum = 0;
                    int antiDiagonalSum = 0;

                    for (int k = 0; k < squareSize; k++) {
                        mainDiagonalSum += grid[startRow + k][startCol + k];
                        antiDiagonalSum += grid[startRow + k][startCol + squareSize - 1 - k];
                    }

                    if (mainDiagonalSum == expectedSum && antiDiagonalSum == expectedSum) {
                        return squareSize;
                    }
                }
            }
        }

        // Minimum magic square size is always 1
        return 1;
    }
};
