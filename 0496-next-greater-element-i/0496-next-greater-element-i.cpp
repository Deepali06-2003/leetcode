class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        vector<int>arr(n, -1);
        stack<int>st;

        for(int i =0;i<n;i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                arr[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[nums2[i]] = i;
        }

        vector<int>res;
        for(int i : nums1){
            int idx = mp[i];
            res.push_back(arr[idx]);
        }

        return res;
    }
};