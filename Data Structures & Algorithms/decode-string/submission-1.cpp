class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, int>> stk;   // count // res location
        string res;
        int num = 0;
        for(char c : s){
            if(c >= '0' && c <= '9'){
                num *= 10;
                num += c - '0';
                
            }else if(c == '['){
                stk.push({num, res.size()});
                num = 0;
            }else if(c == ']'){
                int multi = stk.top().first;
                int loc = stk.top().second;
                stk.pop();
                string str = res.substr(loc);
                for(int i = 0; i < multi - 1; i++){
                    res += str;
                }
            }else{
                res.push_back(c);
            }
        }
        return res;
    }
};