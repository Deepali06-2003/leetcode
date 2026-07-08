class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        auto myComp = [](int& a, int& b){
            string x = to_string(a);
            string y = to_string(b);

            if(x+y > y+x) return true;
            return false;
        };
        sort(nums.begin(), nums.end(), myComp);

        if(nums[0] == 0) return "0";

        string ans="";
        for(int i : nums){
            ans = ans+ to_string(i);
        }

        return ans;
    }
};