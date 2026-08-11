class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int M = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int k = 0; k < nums.size(); k++)
            mp[nums[k]] = k;

        int i = 0;
        int j = mp[nums[0]];
        int result = 1;

        while (i < n) {
            if (i > j) {
                result = (result * 2)%M;
            }
            j = max(j, mp[nums[i]]);
            i++;
        }

        return result;
    }
};