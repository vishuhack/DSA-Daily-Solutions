class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        // Stores the minimum element found so far
        int ans = INT_MAX;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                // The first element of a sorted half
                // is always its minimum element.
                ans = min(ans, nums[low]);

                // Search in the right half
                low = mid + 1;
            }

            // Right half is sorted
            else {

                // Mid is the smallest element
                // of the right sorted half.
                ans = min(ans, nums[mid]);

                // Search in the left half
                high = mid - 1;
            }
        }

        return ans;
    }
};