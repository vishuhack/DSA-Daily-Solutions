/*
----------------------------------------------------
Problem  : Maximum Side Length of Square with Sum <= Threshold
Approach : Prefix Sum + Binary Search Optimization
Author   : Vishvesh Paturkar
GitHub   : https://github.com/vishuhack
Date     : 18/01/2026
----------------------------------------------------
*/
#include<bits/stdc++.h>
class Solution {
public:
    int maxSideLength(vector<vector<int>>& matrix, int threshold) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Prefix Sum Matrix
        vector<vector<int>> preSum(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                preSum[i][j] = matrix[i][j]
                            + (i > 0 ? preSum[i-1][j] : 0)
                            + (j > 0 ? preSum[i][j-1] : 0)
                            - (i > 0 && j > 0 ? preSum[i-1][j-1] : 0);
            }
        }

        // Function to get sum of sub-square
        auto getSquareSum = [&](int r1, int c1, int r2, int c2) {

            int total = preSum[r2][c2];

            if(r1 > 0) total -= preSum[r1-1][c2];
            if(c1 > 0) total -= preSum[r2][c1-1];
            if(r1 > 0 && c1 > 0) total += preSum[r1-1][c1-1];

            return total;
        };

        // Check if any square of given side is valid
        auto isPossible = [&](int len) {

            for(int i = 0; i + len - 1 < n; i++){
                for(int j = 0; j + len - 1 < m; j++){

                    if(getSquareSum(i, j, i + len - 1, j + len - 1) <= threshold)
                        return true;
                }
            }
            return false;
        };

        // Binary Search on Side Length
        int left = 1;
        int right = min(n, m);
        int ans = 0;

        while(left <= right){

            int mid = left + (right - left) / 2;

            if(isPossible(mid)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return ans;
    }
};
