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
            cars.emplace_back((double)(target - position[i])/speed[i], position[i]);
        }
        sort(cars.begin(), cars.end());
        double slowest = cars[cars.size() - 1].ETA;
        for(int i = cars.size() - 2; i >= 0; --i){
            if(cars[i].ETA <= slowest){
                fleets-=1;
            }
            else{
                slowest = cars[i].ETA;
            }
        }
        return fleets;
    }
};
