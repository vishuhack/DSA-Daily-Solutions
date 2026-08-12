class Solution {
public:
    bool isBalance(vector<int>& freq) {
        bool okay = true;
        int common = 0;
        for (int i = 0; i < freq.size(); i++) {

            if(freq[i] == 0) continue;
            if(common == 0){
                common = freq[i];
            }else if(common != freq[i]){
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int maxL = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;
                if (isBalance(freq)) {
                    maxL = max(maxL, j - i + 1);
                }
            }
        }
        return maxL;
    }
};