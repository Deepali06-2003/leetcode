class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        int size = n-k+1;
        priority_queue<int>pq;

        for(int i: nums){
            pq.push(i);

            if(pq.size() > size) pq.pop();
        }
        return pq.top();
    }
};