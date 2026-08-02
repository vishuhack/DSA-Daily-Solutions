class Solution {
public:
    // Returns the first index where nums[index] >= target
    int findLowerBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        // If no valid index exists, return n
        int lowerBoundIndex = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                lowerBoundIndex = mid;

                // Search for an earlier valid index
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return lowerBoundIndex;
    }

    // Returns the first index where nums[index] > target
    int findUpperBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        // If no greater element exists, return n
        int upperBoundIndex = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                upperBoundIndex = mid;

                // Search for an earlier valid index
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return upperBoundIndex;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPosition = findLowerBound(nums, target);
        int upperBoundPosition = findUpperBound(nums, target);

        // Target is absent when:
        // 1. Lower bound is outside the array, or
        // 2. Lower bound does not contain the target
        if (firstPosition == nums.size() ||
            nums[firstPosition] != target) {
            return {-1, -1};
        }

        // Upper bound points to the first element greater than target
        int lastPosition = upperBoundPosition - 1;

        return {firstPosition, lastPosition};
    }
};