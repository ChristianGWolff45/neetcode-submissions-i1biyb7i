class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = 0;
        int l = 0;
        for(int i = 0; i < weights.size(); i++){
            r += weights[i];
            l = max(l, weights[i]);
        }
        int minBoat = r;
        int boat = 0;
        while(l <= r){
            boat = r + (l - r)/2;
            bool shipable = isShipable(weights, days, boat);
            if(shipable){
                minBoat = boat;
                r = boat - 1;
            }else{
                l = boat + 1;
            }
        }
        return minBoat;

        
    }
private:
    bool isShipable(vector<int>& weights, int days, int boat){
        int time = 1;
        int curr = 0;

        for(int i = 0; i < weights.size(); i++){
            if(weights[i] + curr <= boat){
                curr += weights[i];
            }else{
                curr = weights[i];
                time++;
            }
        }
        
        return time <= days;

    }
};