class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>st;
        for(int i:nums) st.insert(i);
        int ans=0;

        for(auto i : st){
            if(st.find(i-1) == st.end()){
                int x = i;
                int c=1;
                while(st.find(x+1) != st.end()){
                    x=x+1;
                    c++;
                }
                ans = max(ans, c);
            }
        }
        return ans;
    }
};