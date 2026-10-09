class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> right;
        vector<int> survivors;
        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] > 0){
                right.push(asteroids[i]);
            }else{
                bool destroyed = false;
                while(!right.empty()){
                    if(right.top() < abs(asteroids[i])){
                        right.pop();
                    }else if(right.top() == abs(asteroids[i])) {
                        right.pop();
                        destroyed = true;
                        break;
                    }else{
                        destroyed = true;
                        break;
                    }
                };
                if(!destroyed){
                    survivors.push_back(asteroids[i]);
                }
            }
        }
        int l = survivors.size();
        while(!right.empty()){
            survivors.push_back(right.top()); right.pop();
        }
        int r = survivors.size() - 1;
        while(l < r){
            int temp = survivors[r];
            survivors[r] = survivors[l];
            survivors[l] = temp;
            r--;
            l++;
        }
        return survivors;
    }
};