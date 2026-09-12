class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size() , m = image[0].size();

        int old_c = image[sr][sc];
        if(image[sr][sc] == color) return image;

        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy={0, 0, 1, -1};

        queue<pair<int, int>>q;

        q.push({sr, sc});
        image[sr][sc]=color;

        while(!q.empty()){
             auto t = q.front();
             q.pop();

             for(auto x=0;x<4;x++){
                int i = dx[x] + t.first;
                int j = dy[x] + t.second;

                if(i>=0 && j>=0 && i<n && j<m && image[i][j]==old_c){
                    image[i][j] = color;
                    q.push({i, j});
                }
             }
        }

        return image;
    }
};