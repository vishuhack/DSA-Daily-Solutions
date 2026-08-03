class Solution {
public:
    int result;
    // vector<vector<int>> result;
    void solve(int idx, int k, vector<int>& nums,
               unordered_map<int, int>& mpp) {
        if (idx >= nums.size()) {
            result++;
            return;
        }
        if (!mpp[nums[idx] + k] && !mpp[nums[idx] - k]) {
            mpp[nums[idx]]++;
            solve(idx + 1, k, nums, mpp);
            mpp[nums[idx]]--;
        }
        solve(idx + 1, k, nums, mpp);
    }
    int beautifulSubsets(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;
        solve(0, k, nums, mpp);
        return result - 1;
    }
};