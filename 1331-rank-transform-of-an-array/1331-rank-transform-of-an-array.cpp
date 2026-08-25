class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();

        vector<int>temp = arr;
        unordered_map<int, int>mp; //ele , rank

        sort(arr.begin(), arr.end());
        int rank =1;

        for(int x: arr){
            if(mp.find(x) == mp.end()) mp[x]=rank++;
        }

        for(int i=0;i<n;i++){
            temp[i] = mp[temp[i]];
        }

        return temp;
    }
};