class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size());
        for(int i = 0; i < temperatures.size(); ++i){
            for(int j = i; j< temperatures.size(); ++j){
                if(temperatures[j] > temperatures[i]){
                    days[i] = j-i;
                    break;
                }
            }
        }
        return days;
    }
};
