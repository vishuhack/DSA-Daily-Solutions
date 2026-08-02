class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0];
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                candidate = nums[i];
                cnt = 1;
            }
            else if(candidate == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(candidate == nums[i]){
                cnt++;
            }
        }
        if(cnt > n/2) return candidate;
        return 0;
    }
};