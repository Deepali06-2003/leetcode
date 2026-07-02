class Solution {
public:
int helper(vector<int>& nums, int capacity){
    int s =1;
    int curr_s=0;

    for(int i : nums){
        if((curr_s+i)> capacity){
            s++;
            curr_s = i;
        }
        else{
            curr_s = curr_s + i;
        }
    }return s;
}
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k > n) return -1;

        long long l = *max_element(nums.begin(), nums.end());
        long long h = accumulate(nums.begin(), nums.end(), 0);

        while(l<=h){
            long long m = (l+h)/2;

            int ans = helper(nums, m);

            if(ans > k) l = m+1;
            else h = m-1;
        }
        return l;
    }
};