class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
            //ele , freq
        map<int, int>mp;

        for(int i : arr1){
            mp[i]++;
        }

        vector<int>res;
        for(int i : arr2){
            if(mp.find(i) != mp.end()){
                while(mp[i]!=0){
                    res.push_back(i);
                    mp[i]--;
                }
                mp.erase(i);
            }
        }

        for(auto i : mp){
            while(i.second !=0){
                res.push_back(i.first);
                i.second--;
            }
        }

        return res;
    }
};