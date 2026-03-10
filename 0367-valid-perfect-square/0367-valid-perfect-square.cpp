class Solution {
public:
    bool isPerfectSquare(int num) {
    int l = 0 , h = num;

    while(l<=h){
        int m = (l+h)/2;

        if((long long)m*m == num)return true;
        else if((long long)m*m > num)h = m-1;
        else l = m+1;
    }
    return false;
    }
};