class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Stores the current running sum of the subarray
        int currentSum = 0;

        // Stores the maximum subarray sum found so far
        int maximumSum = INT_MIN;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Extend the current subarray
            currentSum += nums[i];

            // Update the maximum sum if current subarray is better
            maximumSum = max(maximumSum, currentSum);

            // If the running sum becomes negative,
            // discard it and start a new subarray
            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maximumSum;
    }
};