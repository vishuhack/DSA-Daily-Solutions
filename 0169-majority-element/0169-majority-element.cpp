class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // Stores the current majority candidate
        int candidate = nums[0];

        // Vote count for the current candidate
        int cnt = 0;

        // -------------------------------
        // 1st Pass : Boyer-Moore Voting
        // -------------------------------
        // Idea:
        // Different elements cancel each other's votes.
        // If count becomes 0, choose the current element as the new candidate.
        for (int i = 0; i < n; i++) {

            // No active candidate
            if (cnt == 0) {
                candidate = nums[i];
                cnt = 1;
            }

            // Same as candidate -> increase vote
            else if (candidate == nums[i]) {
                cnt++;
            }

            // Different element -> cancel one vote
            else {
                cnt--;
            }
        }

        // ----------------------------------------
        // 2nd Pass : Verify the candidate
        // ----------------------------------------
        // (LeetCode guarantees majority exists,
        // but verification is useful in general.)
        cnt = 0;

        for (int num : nums) {
            if (num == candidate)
                cnt++;
        }

        // Check if candidate occurs more than n/2 times
        if (cnt > n / 2)
            return candidate;

        return 0;
    }
};