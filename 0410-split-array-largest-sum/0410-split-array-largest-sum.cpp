class Solution {
public:
int helper(vector<int>& nums, int k, int m){
    int books =1, curr=0;

    for(int i=0;i<nums.size();i++){

        if((curr+nums[i])<=m){
            curr = curr+nums[i];
        }
        else{
            books++;
            curr = nums[i];
        }
    }
    return books;
}
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        

        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin() , nums.end(), 0);

        while(l<=h){
            int m = (l+h)/2;

            int ans = helper(nums, k , m);
            
            if(ans > k)l = m+1;
            else{ h = m-1;}
        }
        return l;
    }
};