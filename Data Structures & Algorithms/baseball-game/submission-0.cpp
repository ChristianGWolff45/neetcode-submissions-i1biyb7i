class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        int points = 0;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "C"){
                record.pop();
            }
            else if(operations[i] == "D"){
                int calc = record.top() * 2;
                record.push(calc);
            }
            else if(operations[i] == "+"){
                int prev = record.top();
                record.pop();
                int calc = record.top() + prev;
                record.push(prev);
                record.push(calc);
            }else{
                record.push(stoi(operations[i]));
            }
        }
        while(!record.empty()){
            points += record.top(); record.pop();
        }
        return points;
    }
};