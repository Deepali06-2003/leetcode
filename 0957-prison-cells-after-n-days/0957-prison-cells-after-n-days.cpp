class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        n = (n-1)%14+1;
        vector<int>res = cells;
        for(int j=0;j<n;j++){
            for(int i=0;i<cells.size();i++){
                if( ((i-1>=0) && cells[i-1]==0)  && ((i+1 < cells.size()) && cells[i+1]==0) ) res[i] = 1;
                else if( ((i-1>=0) && cells[i-1]==1)  && ((i+1 < cells.size()) && cells[i+1]==1) ) res[i] = 1;

                else res[i] =0;
            }
            cells = res;
}
        return res;
    }
};