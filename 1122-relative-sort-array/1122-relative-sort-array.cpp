class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int, int>mp;
        for(int i : arr1) mp[i]++;

        vector<int>res;
        for(int i : arr2){
            if( mp.find(i) != mp.end() ){
                for(int x = 0; x<mp[i]; x++){
                    res.push_back(i);
                }
            }
            mp.erase(i);
        }

        for(auto j : mp){
            for(int x = 0; x<j.second; x++){
                res.push_back(j.first);
            }
        }

        return res;
    }
};