class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int can1 = INT_MIN;
        int can2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && can2 != nums[i]) {
                cnt1 = 1;
                can1 = nums[i];
            } else if (cnt2 == 0 && can1 != nums[i]) {
                cnt2 = 1;
                can2 = nums[i];
            } else if (can1 == nums[i]) {
                cnt1++;
            } else if (can2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        int mini = (n / 3);
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (can1 == nums[i])
                cnt1++;
            if (can2 == nums[i])
                cnt2++;
        }
        if (cnt1 > mini) {
            res.push_back(can1);
        }
        if (cnt2 > mini && can2 != can1) {
            res.push_back(can2);
        }
        return res;
    }
};