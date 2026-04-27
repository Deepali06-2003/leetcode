class Solution {
public:

void helper(int k, int n,vector<vector<int>>& res, vector<int>curr, int curr_s, int idx){
    if(curr_s == 0){
        if(curr.size() == k) res.push_back(curr);
        return;
    }

    for(int i = idx ;i<= 9;i++){
        if(curr_s < i) break;

        curr.push_back(i);
        helper(k , n , res , curr , curr_s-i, i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int>curr;

        helper(k , n , res , curr, n, 1);
        return res;
    }
};