class Solution {
public:

void helper(vector<vector<int>>& isConnected , vector<int>& visited, int n){
    visited[n]=1;

    queue<int>q;

    q.push(n);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int j = 0; j < isConnected.size(); j++){
            if(visited[j]==0 && isConnected[x][j]==1){
                visited[j]=1;
                q.push(j);
            }
        }
    }
}


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans=0;
        vector<int>visited(n, 0);

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                helper(isConnected, visited, i);
                ans++;
            }
        }

        return ans;
    }
};