class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0) return;
        int i = 0;
        int j;
        int n = nums.size();
        while(i < n && nums[i] != 0)
            i++;
        j = i+1;
        while( j < n && nums[j] == 0 ){
            j++;
        }
        while(i < n && j < n && i < j && i!= j){
            swap(nums[i], nums[j]);
            i++;
            while( j < n && nums[j] == 0 ){
                j++;
            }
        }
        
    }
};