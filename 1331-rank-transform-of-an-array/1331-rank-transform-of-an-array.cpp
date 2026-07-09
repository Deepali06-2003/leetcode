class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>res(arr.size(),0);
        if(arr.size()==0) return res;

        vector<int> temp = arr;

        sort(arr.begin(), arr.end());

        unordered_map<int, int>mp;
        int r =1;
        for(int i:arr){
            if(mp.find(i) == mp.end()){
                mp[i] = r++;
            }
        }

        for(int i=0;i<temp.size();i++){ 
            res[i] = mp[temp[i]];
        }

        return res;
    }
};