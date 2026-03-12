class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>res;
        unordered_map<string , vector<string>> mp;

        for(string str : strs){
            string x = str;
            sort(x.begin(), x.end());

            mp[x].push_back(str);
        }

        for(auto j: mp){
            res.push_back(j.second);
        }
        return res;
    }
};