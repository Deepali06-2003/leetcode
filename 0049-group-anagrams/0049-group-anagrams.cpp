class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;

        unordered_map<string, vector<string>>mp;
        for(string s : strs){
            string x = s;
            sort(x.begin(), x.end());

            mp[x].push_back(s);
        }

        for(auto i : mp){
            res.push_back(i.second);
        }
        return res;
    }
};