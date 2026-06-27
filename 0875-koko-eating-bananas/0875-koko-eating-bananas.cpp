class Solution {
public:

bool helper(vector<int>& piles, int h, int m){
    int ans=0;
    for(int i : piles) ans = ans + (ceil)((i*1.0)/m);
    return ans <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = *max_element(piles.begin(), piles.end());
       
        while(low<high){
            int m = (low+high)/2;

            if(helper(piles , h , m)) high = m;
            else low = m+1;
        }

        return low;
    }
};