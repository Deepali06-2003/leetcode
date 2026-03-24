class Solution {
public:

int helper(int n){
    int r =0;
    while(n!=0){
        r = r+ ( (n%10)*(n%10) );
        n = n/10;
    }
    return r;
}

    bool isHappy(int n) {
        
        unordered_set<int>st;

        while(n!=1){

            if(st.find(n) != st.end() )return false;
            st.insert(n);

            n = helper(n);
        }
        return true;
    }
};