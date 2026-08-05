class Solution {
public:
    int orgColor;
    int m, n;
    void solve(vector<vector<int>>& image, int sr, int sc, int color){
        if(sr < 0 || sc < 0 || sr >= m || sc >= n || image[sr][sc] != orgColor){
            return;
        }
        if(image[sr][sc] == color){
            return;
        }

        
        if(image[sr][sc] == orgColor){
            image[sr][sc] = color;
        }else{
            return;
        }
        solve(image, sr, sc -1, color);
        solve(image, sr, sc +1, color);
        solve(image, sr-1, sc, color);
        solve(image, sr + 1, sc, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        orgColor = image[sr][sc];
        solve(image, sr, sc, color);
        return image;
    }
};