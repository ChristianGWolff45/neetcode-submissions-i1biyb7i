class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = position.size();
        for(int i = 0; i < position.size(); ++i){
            for(int j = 0; j < position.size(); ++j){
                if(position[i] < position[j] && 1.0 *(target - position[i])/speed[i] <= 1.0 *(target - position[j])/speed[j]){
                    fleets-=1;
                    break;
                }
            }
        }
        return fleets;
    }
};
