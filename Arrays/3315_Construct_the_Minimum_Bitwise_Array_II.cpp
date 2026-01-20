/*
----------------------------------------------------
File Name: 1292_Minimum_Bitwise_Array.cpp
Problem  : Minimum Bitwise Array (ans[i] OR (ans[i]+1) = nums[i])
Approach : Bit Manipulation (Finding First Unset Bit)
Author   : Vishvesh Paturkar
GitHub   : https://github.com/vishuhack
Date     : 20/01/2026
----------------------------------------------------
*/
#inlcude<bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int>& nums) {
    int n = nums.size();

    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 2) {
            result.push_back(-1);
            continue;
        }

        bool found = false;

        for (int j = 1; j < 32; j++) {
            if ((nums[i] & (1 << j)) > 0) { // bit is set
                continue;
            }

            int prev = j - 1;
            int x = nums[i] ^ (1 << prev);
            result.push_back(x);

            found = true;
            break;
        }

        if (found == false) {
            result.push_back(-1);
        }
    }

    return result;
}
