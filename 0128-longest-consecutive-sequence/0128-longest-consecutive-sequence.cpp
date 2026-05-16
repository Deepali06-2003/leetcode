class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans = 0;

        unordered_set<int>st;
        for(int i : nums) st.insert(i);

        for(int i : st){
            if(st.find(i-1) == st.end()){
                int x = i;
                int c = 1;

                while(st.find(x+1) != st.end()){
                    c++;
                    x = x+1;
                    
                }
                ans = max(ans , c);
            }

        }

        return ans;
    }
};