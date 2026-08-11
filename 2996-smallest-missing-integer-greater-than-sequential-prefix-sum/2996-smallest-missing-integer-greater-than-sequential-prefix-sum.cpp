class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int it : nums){
            mp[it]++;
        }
        // sort(nums.begin(), nums.end());
        int sum = 0;
        int temp = 0;
        if(nums.size() == 1) return nums[0]+1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]-1 ){
                sum+= nums[i-1];
            }else{
                sum += nums[i-1];
                break;
            }
            if(nums[i-1] == nums[i]-1 && i == nums.size()-1)
                sum+= nums[i];
        }
        // sum += nums[temp];
        cout << sum;
        while(mp.find(sum)!=mp.end()){
            sum++;
        }
        return sum;
    }
};