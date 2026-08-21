class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;  //value , next grater
        stack<int>st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[i]> st.top()){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            int x = nums1[i];
            if(mp.find(x) != mp.end()) nums1[i] = mp[x];
            else nums1[i]=-1;
        }
        return nums1;

    }
};