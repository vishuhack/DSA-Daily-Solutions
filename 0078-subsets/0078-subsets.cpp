class Solution {
public:
    vector<vector<int>> result;
    void solve(int idx, vector<int>& nums, vector<int>& temp){
        if(idx == nums.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]); // take
        solve(idx+1, nums, temp); // explore
        temp.pop_back(); // not take
        solve(idx+1, nums, temp); // explore
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, temp);
        return result;
    }
};