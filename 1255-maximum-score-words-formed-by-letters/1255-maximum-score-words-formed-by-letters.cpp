class Solution {
public:
    int n;
    int maxScore;
    void solve(int idx, int currScore, vector<string>& words, vector<int>& freq,
               vector<int>& score) {
        maxScore = max(currScore, maxScore);
        if (idx >= n) {
            return;
        }

        int tempScore = 0;
        int j = 0;
        vector<int> tempFreq = freq;
        while (j < words[idx].length()) {
            char ch = words[idx][j];
            tempFreq[ch - 'a']--;
            tempScore += score[ch - 'a'];

            if (tempFreq[ch - 'a'] < 0) {
                break;
            }
            j++;
        }
        if (j == words[idx].length()) {
            solve(idx + 1, currScore + tempScore, words, tempFreq, score);
        }
        solve(idx + 1, currScore, words, freq, score);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        vector<int> freq(26, 0);

        for (auto it : letters) {
            freq[it - 'a']++;
        }
        maxScore = INT_MIN;
        n = words.size();
        solve(0, 0, words, freq, score);
        return maxScore;
    }
};