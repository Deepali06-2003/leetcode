class Solution {
public:
int ans=0;
void merge(vector<int>& nums, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    vector<int> leftnums(n1), rightnums(n2);
    // Copy data to temporary vectors
    for (i = 0; i < n1; i++)
        leftnums[i] = nums[left + i];
    for (j = 0; j < n2; j++)
        rightnums[j] = nums[mid + 1 + j];

    // Merge the temporary vectors back into nums[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftnums[i] <= rightnums[j]) {
            nums[k] = leftnums[i];
            i++;
        } else {
            nums[k] = rightnums[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of leftnums[], if any
    while (i < n1) {
        nums[k] = leftnums[i];
        i++;
        k++;
    }
    // Copy the remaining elements of rightnums[], if any
    while (j < n2) {
        nums[k] = rightnums[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left..right]
void mergeSort(vector<int>& nums, int left, int right) {
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        //important partF
        CountPairs(nums, left ,mid, right);
        // Merge the sorted halves
        merge(nums, left, mid, right);
    }
}

void CountPairs(vector<int>& nums, int low , int mid, int high){
    int j = mid+1;
    for(int i=low;i<=mid ;i++){
        while (j <= high && nums[i] > 2LL * nums[j]) {
            j++;
        }
        ans = ans + (j-(mid+1));
    }
}
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
       mergeSort(nums, 0, n-1);
       return ans;
    }
};