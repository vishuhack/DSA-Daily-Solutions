class Solution {
public:
    int cnt;
    string result = "";
    void solve(int n, vector<int>& used, string& curr, int k){
        if(curr.length() == n){
            cnt++;
            if(cnt == k)
                result = curr;
            return;
        }

        for(char ch = 'a'; ch <= 'c' ; ch++){
            if(curr.empty() || curr.back() != ch){
                curr.push_back(ch); // Do
                solve(n, used, curr, k); // Explore
                curr.pop_back(); //Undo

            }
        }
    }
    string getHappyString(int n, int k) {
        vector<int> used(3,-1);
        
        string curr = "";
        solve(n, used, curr, k);
        // if (result == NULL) return "";
        return result;
    }
};