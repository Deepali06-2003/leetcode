class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int ans = 0;
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int x = st.top();

                st.pop();

                int nxs = i;
                int pvs = (st.empty())?-1 : st.top();

                ans = max(ans , ((nxs-pvs-1)*heights[x]));
            }
            st.push(i);
        }
        while(!st.empty()){
                int x = st.top();

                st.pop();

                int nxs = n;
                int pvs = (st.empty())?-1 : st.top();

                ans = max(ans , ((nxs-pvs-1)*heights[x]));
            }

        return ans;

    }
};