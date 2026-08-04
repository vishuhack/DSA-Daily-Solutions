class Solution {
public:
    int maxCnt;
    int n;
    void solve(int idx, string s, int currCnt, unordered_set<string>& st)
    {
        if(currCnt + (n-idx) <= maxCnt) return;
        if(idx >= n){
            maxCnt = max(maxCnt, currCnt);
            return;
        }
        for(int j = idx; j < n; j++){
            string str = s.substr(idx, j-idx+1);
            if(st.find(str) == st.end()){
                st.insert(str);
                solve(j + 1, s, currCnt + 1, st);
                st.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        n = s.length();
        unordered_set<string> st;
        int currCnt = 0;
        solve(0, s, currCnt, st);
        return maxCnt;
    }
};