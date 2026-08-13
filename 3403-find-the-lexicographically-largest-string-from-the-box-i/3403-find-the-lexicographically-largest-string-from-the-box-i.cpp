class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        int maxHave = n - numFriends + 1;
        if(n==maxHave) return word;
        string res;
        int i = 0;
        while(i < n){
            string temp = word.substr(i, maxHave);
            res = max(res, temp);
            i++;
        }
        return res;
    }
};