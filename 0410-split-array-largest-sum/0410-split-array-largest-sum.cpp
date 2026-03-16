class Solution {
public:
int helper(vector<int>& nums, long long m){
    int c = 1;
    long long s=0;

    for(int i =0;i<nums.size();i++){
        if((s+nums[i])<=m) s = s+nums[i];
        else{
            c=c+1;
            s=nums[i];
        }
    }
    return c;
}
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k>n)return -1;

        long long l = *max_element(nums.begin(), nums.end());
        long long h = accumulate(nums.begin(), nums.end(), 0);

        while(l<=h){
            long long m = (l+h)/2;

            int sum = helper(nums , m);
            if(sum <= k){
                
                h=m-1;
            }
            else l = m+1;
        }
        return l;
    }
};