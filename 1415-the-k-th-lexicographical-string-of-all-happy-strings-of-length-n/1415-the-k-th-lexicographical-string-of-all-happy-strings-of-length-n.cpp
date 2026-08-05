class Solution {
public:
    void solve(string s, int n, vector<int>& used, vector<string>& result, string& curr){
        if(curr.length() == n){
            result.push_back(curr);
            return;
        }

        for(int i = 0; i < 3; i++){
            if(curr.empty() || curr.back() != s[i]){
                curr.push_back(s[i]);
                solve(s, n, used, result, curr);
                curr.pop_back();

            }
        }
    }
    string getHappyString(int n, int k) {
        string s = "abc";
        vector<int> used(3,-1);
        vector<string> result;
        string curr = "";
        solve(s, n, used, result, curr);
        sort(result.begin(), result.end());
        if ( k > result.size()) return "";
        return result[k-1];
    }
};