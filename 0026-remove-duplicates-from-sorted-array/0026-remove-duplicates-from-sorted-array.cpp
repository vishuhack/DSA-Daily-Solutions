class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt= 0;
        vector<int> expectedNums;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] != nums[i-1]){
                cnt++;
                expectedNums.push_back(nums[i]);
            }
        }
        for(int i = 0; i < expectedNums.size(); i++){
            nums[i] = expectedNums[i];
        }
        return cnt;
    }
};