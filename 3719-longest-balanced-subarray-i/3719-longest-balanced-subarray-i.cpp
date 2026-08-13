class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // int maxL = 0;
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     int even = 0;
        //     int odd = 0;
        //     unordered_set<int> st;
        //     for (int j = i; j < n; j++) {
        //         if (st.find(nums[j]) == st.end()) {
        //             if (nums[j] % 2 == 0) {
        //                 even++;
        //             } else {
        //                 odd++;
        //             }
        //             st.insert(nums[j]);

        //         }
        //         if(even == odd){
        //             maxL = max(maxL, j-i+1);
        //         }
        //     }
        // }
        // return maxL;

        // Approach 2

        int maxL = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> even;
            unordered_set<int> odd;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    even.insert(nums[j]);
                } else {
                    odd.insert(nums[j]);
                }

                if (even.size() == odd.size()) {
                    maxL = max(maxL, j - i + 1);
                }
            }
        }
        return maxL;
    }
};