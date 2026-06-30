class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        unordered_set<int>st;
        for(int i=1;i<=n;i++)st.insert(i*i);
        
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                int x = (i*i)+(j*j);
                if(st.find(x)!= st.end())ans++;
            }
        }
        return ans;

    }
};