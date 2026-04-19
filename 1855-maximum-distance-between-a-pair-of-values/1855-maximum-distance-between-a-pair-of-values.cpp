class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        

        int i = 0, j = 0; // initialize both pointers at the 0th index.

    while (i < nums1.size() && j < nums2.size()) {
        // If invalid:
        // move i right to restore a valid pair.
        if (nums1[i] > nums2[j])
            i++;

        // Move j right to maximize j - i.
        j++;
    }

    // j - i is the farthest gap reached so far;
    // subtract 1 since j is one step past it.
    return max(0, j - i - 1);
    }
};