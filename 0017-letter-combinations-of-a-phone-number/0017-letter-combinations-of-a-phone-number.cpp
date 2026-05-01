class Solution {
public:
unordered_map<char , vector<char>>mp;

    void helper(string& digits , vector<string>& res, string curr, int s){
        if( s == digits.size()){
            res.push_back(curr);
            return;
        }

       
        vector<char> d = mp[digits[s]];
        for(auto i : d){
            curr.push_back(i);
            helper(digits, res, curr, s+1);
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
        if(digits.size() == 0)return res;

        helper(digits, res , curr , 0);
        return res;
    }
};




unordered_map<int , vector<char>>mp;

void helper(string digits,vector<string>& res , string curr, int start){

    if(start == digits.size()){
        res.push_back(curr);
        return;
    }

    int x = digits[start]-'0';
    vector<char>temp = mp[x];

    for(int i=0;i<temp.size();i++){
        curr = curr+ temp[i];
        helper(digits, res, curr, start+1);
        curr.pop_back();
    }
}

    vector<string> letterCombinations(string digits) {
        vector<string>res;
        string curr;

        if(digits.empty())return res;

        mp[2] = {'a','b','c'};
        mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r' ,'s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};

        helper(digits, res, curr, 0);
        return res;
    }