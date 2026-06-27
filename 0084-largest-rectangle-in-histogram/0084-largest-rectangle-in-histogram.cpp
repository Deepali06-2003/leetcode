class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int ans = 0;

        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] < heights[st.top()] ){
                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = (st.empty())? -1 : st.top();

                ans = max(ans , (nse-pse-1)*heights[ele]);
            }
            st.push(i);
        }

        while(!st.empty()){
                int ele = st.top();
                st.pop();

                int nse = n;
                int pse = (st.empty())? -1 : st.top();

                ans = max(ans , (nse-pse-1)*heights[ele]);
        }
        return ans;
    }
};