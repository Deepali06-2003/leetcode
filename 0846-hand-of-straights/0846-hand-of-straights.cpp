class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();

        if(n%groupSize != 0)return false;

        map<int, int>mp;
        for(int i :hand) mp[i]++;

        while(!mp.empty()){
            int ele = mp.begin()->first;

            for(int i=0;i<groupSize;i++){

                if(mp[ele+i] == 0)  return false;           // if ele not found

                mp[ele+i]--;                                // reduce element freq;
                if(mp[ele+i] < 1) mp.erase(ele+i);          //if freq is 0 --> erase it
            }
        }return true;
    }
};