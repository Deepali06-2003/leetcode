class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        int n = people.size();
       
       int l =0 , h = n-1;
       int c=0;
       while(l<=h){

            if( (people[l] + people[h]) <=limit ){
                c = c+1;
                l++;
                h--;
            } 
            else{
                c=c+1;
                h--;
            }

       }
       return c;
    }
};