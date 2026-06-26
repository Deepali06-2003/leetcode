class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
            //temp = index ; arr = ele
        vector<int>temp = arr;

        sort(arr.begin(), arr.end());
        unordered_map<int, int>mp;

        vector<int>res(arr.size(), 0);

        int rank =1;
        for(int x : arr){
            if(mp.find(x) == mp.end())  mp[x] = rank++;
        }

        for(int i =0;i<temp.size();i++){
            res[i] = mp[temp[i]];
        }
        return res;
    }
};