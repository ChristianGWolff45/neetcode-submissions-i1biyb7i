class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size());
        stack<int> temps;
        
        for(int i = 0; i < temperatures.size(); i++){
            while(!temps.empty() && temperatures[i] > temperatures[temps.top()]){
                days[temps.top()] = i - temps.top();
                temps.pop();
            }
            temps.push(i);
        }
        return days;
    }
};
