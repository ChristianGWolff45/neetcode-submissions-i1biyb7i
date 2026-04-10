class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int bph = 0, l = 1, time;
        for(auto pile : piles){
            if(bph < pile){
                bph = pile;
            }
        }
        int r = bph;
        do{
            bph = ((l + r)/2);
            
            time = getTime(piles, bph);
            if(time > h){
                l = bph;
            }else{
                r = bph;
            }
        }while(bph != (l + r)/2);
        return r;
    }
    int getTime(vector<int>& piles, int rate){
        int time = 0;
        for(auto pile : piles){
            time += (pile + rate - 1)/rate;
        }
        return time;
    }
    
};
