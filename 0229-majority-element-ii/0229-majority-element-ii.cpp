class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        // At most two elements can appear more than n/3 times.
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;

        // Vote counts for both candidates.
        int count1 = 0;
        int count2 = 0;

        // First pass: Find the two possible majority candidates.
        for (int i = 0; i < n; i++) {

            // Select the current element as candidate1
            // only when candidate1 has no active votes
            // and the element is different from candidate2.
            if (count1 == 0 && candidate2 != nums[i]) {
                candidate1 = nums[i];
                count1 = 1;
            }

            // Select the current element as candidate2
            // only when candidate2 has no active votes
            // and the element is different from candidate1.
            else if (count2 == 0 && candidate1 != nums[i]) {
                candidate2 = nums[i];
                count2 = 1;
            }

            // Current element matches candidate1.
            else if (candidate1 == nums[i]) {
                count1++;
            }

            // Current element matches candidate2.
            else if (candidate2 == nums[i]) {
                count2++;
            }

            // Current element matches neither candidate,
            // so cancel one vote from both.
            else {
                count1--;
                count2--;
            }
        }

        // Second pass: Verify the actual frequencies
        // of both possible candidates.
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate1) {
                count1++;
            }

            if (nums[i] == candidate2) {
                count2++;
            }
        }

        vector<int> result;

        // Required frequency must be strictly greater than n/3.
        int frequencyLimit = n / 3;

        if (count1 > frequencyLimit) {
            result.push_back(candidate1);
        }

        if (count2 > frequencyLimit && candidate2 != candidate1) {
            result.push_back(candidate2);
        }

        return result;
    }
};