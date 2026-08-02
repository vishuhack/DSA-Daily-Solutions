class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() -1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            // if left half sorted
            // then on its starting point there will be minimim element that is low
            // same for right half sorted the minimim elemnt will be on mid
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                ans  = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};