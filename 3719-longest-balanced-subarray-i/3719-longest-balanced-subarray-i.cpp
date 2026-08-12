class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxL = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int even = 0;
            int odd = 0;
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                if (st.find(nums[j]) == st.end()) {
                    if (nums[j] % 2 == 0) {
                        even++;
                    } else {
                        odd++;
                    }
                    st.insert(nums[j]);
                    
                }
                if(even == odd){
                    maxL = max(maxL, j-i+1);
                }
            }
        }
        return maxL;
    }
};