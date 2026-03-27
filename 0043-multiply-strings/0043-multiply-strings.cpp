
   class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();

        if(num1 == "0" || num2 == "0") return "0";

        vector<int> res(n + m, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int d1 = num1[i] - '0';
                int d2 = num2[j] - '0';

                int s = res[i + j + 1] + (d1 * d2);

                res[i + j + 1] = s % 10;
                res[i + j] += s / 10;
            }
        }

        string ans = "";
        for(int x : res){
            if(!(ans.empty() && x == 0)){
                ans += (x + '0');
            }
        }

        return ans.empty() ? "0" : ans;
    }
};
