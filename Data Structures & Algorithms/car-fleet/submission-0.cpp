class Solution {
struct car{
    double ETA;
    int position;
    car(double e, int p) : ETA(e), position(p) {}
    bool operator<(const car& other)const{
        return position < other.position;
    }
};
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = position.size();
        std::vector<car> cars;
        for(int i = 0; i < position.size(); ++i){
            car newCar = car((target - position[i])/speed[i], position[i]);
            cars.emplace_back((double)(target - position[i])/speed[i], position[i]);
        }
        sort(cars.begin(), cars.end());
        for(int i = 0; i < cars.size() - 1; ++i){
            for(int j = i + 1; j < cars.size(); ++j){
                if(cars[i].ETA <= cars[j].ETA){
                    fleets-=1;
                    break;
                }
            }
        }
        return fleets;
    }
};
