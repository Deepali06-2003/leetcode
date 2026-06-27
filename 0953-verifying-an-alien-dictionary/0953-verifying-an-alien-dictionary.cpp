class Solution {
public:


bool helper(string a, string b , unordered_map<char , int>& mp){
    int i = 0, j = 0;
    while(i<a.size() && j<b.size()){
        int a_idx = mp[a[i]];
        int b_idx = mp[b[j]];

        if(a_idx < b_idx) return true;
        if(a_idx > b_idx) return false;
        i++; j++;
    }
    return a.size()<=b.size();
}
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char , int>mp;
        for(int i =0;i<order.size();i++){
            mp[order[i]] = i;
        }

        
        for(int i = 1;i<words.size() ;i++){
            if( !helper(words[i-1] , words[i] ,  mp)) return false;
        }
        return true;
    }
};