class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;

        int MIN = to_string(low).size();
        int MAX = to_string(high).size();
        string s = "123456789";

        for(int l = MIN ; l<=MAX ; l++){
            for(int start = 0; start+l <=9 ; start++){
                string curr = s.substr(start , l);
                int x = stoi(curr);

                if(x>=low && x<=high) res.push_back(x);
            }
        }
        return res;
    }
};