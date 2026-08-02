class Solution {
public:
    int findLower(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            // } else if (nums[mid] > target) {
                // high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int findUpper(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {

                ans = mid;
                high = mid - 1;

            // } else if (nums[mid] < target) {
                // low = mid + 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLower(nums, target);
        int right = findUpper(nums, target);
        if (left == nums.size() || nums[left] != target) {
            return {-1, -1};
        }
        // if (nums.size() == 1 && left == 0) {
        //     return {0,0};
        // }
        return {left, right -1};
    }
};