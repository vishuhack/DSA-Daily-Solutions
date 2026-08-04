class Solution {
public:
    int n;
    void solve(string& tiles, vector<bool>& used, string& curr, unordered_set<string>& result){
        result.insert(curr);

        for(int i = 0; i < n; i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            curr.push_back(tiles[i]);
            solve(tiles, used, curr, result);
            curr.pop_back();
            used[i] = false;
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<bool> used(n, false);
        unordered_set<string> result;
        string curr = "";
        solve(tiles, used, curr, result);
        return result.size()-1;
    }
};