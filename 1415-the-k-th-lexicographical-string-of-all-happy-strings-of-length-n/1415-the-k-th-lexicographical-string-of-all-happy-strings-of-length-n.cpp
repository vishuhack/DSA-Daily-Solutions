class Solution {
public:
    void solve(int n, vector<int>& used, vector<string>& result, string& curr){
        if(curr.length() == n){
            result.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c' ; ch++){
            if(curr.empty() || curr.back() != ch){
                curr.push_back(ch);
                solve(n, used, result, curr);
                curr.pop_back();

            }
        }
    }
    string getHappyString(int n, int k) {
        vector<int> used(3,-1);
        vector<string> result;
        string curr = "";
        solve(n, used, result, curr);
        if ( k > result.size()) return "";
        return result[k-1];
    }
};