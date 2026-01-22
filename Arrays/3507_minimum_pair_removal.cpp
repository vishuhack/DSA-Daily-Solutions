/*
----------------------------------------------------
Problem  : Minimum Pair Removal to Make Array Sorted
Approach : Greedy + Simulation
Author   : Vishvesh Paturkar
GitHub   : https://github.com/vishuhack
Day      : Day 4
Date     : 22/01/2026
----------------------------------------------------
*/

class Solution {
public:
    int minPairSums(vector<int>& nums){
        int minSum = INT_MAX;
        int index = -1;

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] + nums[i + 1] < minSum){
                minSum = nums[i] + nums[i + 1];
                index = i;
            }
        }
        return index;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while(!is_sorted(nums.begin(), nums.end())){
            int index = minPairSums(nums);
            nums[index] += nums[index + 1];
            nums.erase(nums.begin() + index + 1);
            ops++;
        }
        return ops;
    }
};
