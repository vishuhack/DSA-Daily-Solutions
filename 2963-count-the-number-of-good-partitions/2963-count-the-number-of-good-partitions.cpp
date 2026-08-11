class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int M = 1e9 + 7;
        int n = nums.size();

        // Store the last occurrence of every number
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        int i = 0;

        // Rightmost index till which current group must extend
        int j = mp[nums[0]];

        int result = 1;

        while (i < n) {

            // Previous group is completely finished
            // So we found a new valid partition boundary
            if (i > j) {
                result = (result * 2) % M;
            }

            // Extend j if current element appears later
            j = max(j, mp[nums[i]]);

            i++;
        }

        return result;
    }
};