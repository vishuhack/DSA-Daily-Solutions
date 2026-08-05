class Solution {
public:
    int cnt;
    void solve(int n, vector<int>& used, vector<string>& result, string& curr, int k){
        if(curr.length() == n){
            cnt++;
            if(cnt == k)
                result.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c' ; ch++){
            if(curr.empty() || curr.back() != ch){
                curr.push_back(ch); // Do
                solve(n, used, result, curr, k); // Explore
                curr.pop_back(); //Undo

            }
        }
    }
    string getHappyString(int n, int k) {
        vector<int> used(3,-1);
        vector<string> result;
        string curr = "";
        solve(n, used, result, curr, k);
        if (result.empty()) return "";
        return result[0];
    }
};