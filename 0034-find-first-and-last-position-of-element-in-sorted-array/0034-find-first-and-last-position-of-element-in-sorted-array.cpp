class Solution {
public:
    // First index where nums[index] >= target
    int lowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    // First index where nums[index] > target
    int upperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);

        // Target is not present
        if (lb == n || nums[lb] != target) {
            return {-1, -1};
        }

        return {lb, ub - 1};
    }
};