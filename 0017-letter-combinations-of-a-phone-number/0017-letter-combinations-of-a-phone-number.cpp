class Solution {
public:
unordered_map<char , vector<char>>mp;

void helper(string& digits , vector<string>& res, string curr, int idx){
    if(idx == digits.size()){
        res.push_back(curr);
        return;
    }

    vector<char>temp = mp[digits[idx]];
    for(int i=0;i<temp.size();i++){
        curr.push_back(temp[i]);
        helper(digits , res, curr, idx+1);
        curr.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r' ,'s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};

        vector<string>res;
        string curr;

        helper(digits, res, curr, 0);
        return res;

    }
};




