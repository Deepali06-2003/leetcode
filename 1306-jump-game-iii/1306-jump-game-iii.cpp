class Solution {
public:
int n ;
bool helper(vector<int>&arr , int start){

    if(start <0 || start >= n)return false;
    if(arr[start]==0)return true;
    if(arr[start] == -1)return false;
    int j = arr[start];
    arr[start] = -1;

    return helper(arr , start+j) || helper(arr , start-j);
}
    bool canReach(vector<int>& arr, int start) {
        
         n = arr.size();
        return helper(arr , start);
    }
};