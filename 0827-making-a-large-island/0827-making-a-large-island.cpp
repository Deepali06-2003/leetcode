class Disjoint{
    public:
    
    vector<int>parent, size;
    
    Disjoint(int n){
        parent.resize(n, 0);
        size.resize(n , 1);
        
        for(int i=0;i<n;i++) parent[i] = i;
    }
    
    int FindParent(int n){
        if(parent[n] == n) return n;
        
        return parent[n] = FindParent(parent[n]);
    }
    
    void UnionBySize(int u, int v){
        int pu = FindParent(u);
        int  pv = FindParent(v);
        
        if(pu == pv) return;
        else if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] = size[pu] + size[pv];
        }
        
        else{     //if size[pv] >= size[pu] -> then ultimate parent of pu is updated
            parent[pu] = pv;
            size[pv] = size[pv] + size[pu];
        }
    }
};



class Solution {
    private:
    bool isValid(int x, int y, int n){
        return (x>=0) && (x<n) && (y>=0) && (y<n);
    }
public:

    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        Disjoint ds(n*n);

        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){

                    vector<int>dx = {0, 0, 1, -1};
                    vector<int>dy={1, -1, 0, 0};
                    for(int x=0;x<4;x++){
                        int nx = i+ dx[x] ;
                        int ny = j + dy[x];

                        if(isValid(nx, ny, n) && grid[nx][ny]==1){
                            int u = (i*n)+ j;
                            int v = (nx*n) + ny;
                            ds.UnionBySize(u, v);
                        }
                    }
                }
            }
        }

        int ans = INT_MIN;

        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;

                vector<int>dx = {0, 0, 1, -1};
                vector<int>dy={1, -1, 0, 0};
                unordered_set<int>st;

                for(int x=0;x<4;x++){
                    int nx = i+ dx[x] ;
                    int ny = j + dy[x];

                    if(isValid(nx, ny, n) ){
                        if(grid[nx][ny]==1){
                            st.insert(ds.FindParent((n*nx) + ny));
                        }
                    }
                }

                //treverse st
                int sum=0;
                for(auto k : st){
                    sum = sum + ds.size[k];
                }
                ans = max(ans, sum+1);
        
            }
        }
        for(int cel =0; cel<n*n ; cel++){
            ans = max(ans, ds.size[ds.FindParent(cel)]);
        }
        return ans;
    }
};