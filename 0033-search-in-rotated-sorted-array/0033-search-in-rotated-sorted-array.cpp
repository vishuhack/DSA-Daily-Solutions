class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Check which half is sorted

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                // Check if target lies in the left half
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    // Search in the right half
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Check if target lies in the right half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    // Search in the left half
                    high = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }
};