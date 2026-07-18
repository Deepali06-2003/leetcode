class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>prefix(n , 0);
        vector<int>postfix(n , 0);

        prefix[0] = height[0];
        postfix[n-1] = height[n-1];

        for(int i=1;i<n;i++) prefix[i] = max(prefix[i-1], height[i]);
        for(int i=n-2;i>=0;i--) postfix[i] = max(postfix[i+1], height[i]);

        int ans=0;
        for(int i=0;i<n;i++){
            ans =  ans+ (min(prefix[i], postfix[i]) - height[i]);
        }
        return ans;

    }
};