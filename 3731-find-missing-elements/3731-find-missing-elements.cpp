class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int start = nums[0];
        int end = nums[nums.size()-1];
        int p = 0;
        for(int i = start; i <= end && p < nums.size(); i++){
            if(nums[p] != i){
                res.push_back(i);
                p--;
            }
            p++;
        }
        return res;
    }
};