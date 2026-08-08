class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Appraoch 1 : without two pointers
        // int cnt= 0;
        // vector<int> expectedNums;
        // for(int i = 0; i < nums.size(); i++){
        //     if(i == 0 || nums[i] != nums[i-1]){
        //         cnt++;
        //         expectedNums.push_back(nums[i]);
        //     }
        // }
        // for(int i = 0; i < expectedNums.size(); i++){
        //     nums[i] = expectedNums[i];
        // }
        // return cnt;

        //Approach 2 : Two pointers
        int i = 0;
        int j = i+1;
        int n = nums.size();

        while(j < n){
            if(nums[i] == nums[j]){
                j++;
            }
            else if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i+1;
    }
};