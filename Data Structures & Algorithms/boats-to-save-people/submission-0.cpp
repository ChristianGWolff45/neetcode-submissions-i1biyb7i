class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size() - 1;
        while(l < r){
            if(people[l] + people[r] > limit){
                boats++;
                r--;
            }else{
                boats++;
                l++;
                r--;
            }
        }
        if(l == r){
            boats++;
        }

        return boats;
    }
};