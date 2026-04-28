class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int ans = 0;

        stack<int>st;
        for(int i =0;i<n;i++){
            while(!st.empty() && heights[i]< heights[st.top()]){

                int x = st.top();
                st.pop();

                int ns = i;
                int pr = (st.empty())? -1 : st.top();

                ans = max( ans , heights[x]*(ns-pr-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int x = st.top();
                st.pop();

                int ns = n;
                int pr = (st.empty())? -1 : st.top();

                ans = max( ans , heights[x]*(ns-pr-1));
        }

        return ans;
    }
};