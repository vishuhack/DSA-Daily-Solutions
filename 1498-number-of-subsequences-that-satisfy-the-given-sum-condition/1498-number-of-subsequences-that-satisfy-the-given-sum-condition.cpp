class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int M = 1e9 + 7;
        int n = nums.size();
        int result = 0;
        int l = 0, r = nums.size() - 1;

        vector<int> power(n);
        power[0] = 1;
        for(int i = 1; i < n; i++){
            power[i] = (power[i-1] * 2)%M;
        }

        sort(nums.begin(), nums.end());
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                result = (result%M + power[r-l])%M;
                l++;
            } else {
                r--;
            }
        }
        return result;
    }
};