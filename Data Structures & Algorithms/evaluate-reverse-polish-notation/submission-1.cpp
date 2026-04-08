class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> a;
        int b;
        int i = 0;
        while(i < tokens.size()){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                b = a.top();
                a.pop();
                if(tokens[i] == "+"){
                    a.top() += b;
                }
                else if(tokens[i] == "-"){
                    a.top() -= b;
                }
                else if(tokens[i] == "*"){
                    a.top() *= b;
                }
                else if(tokens[i] == "/"){
                    a.top() = a.top() /b;
                }
            }else{
                a.push(stoi(tokens[i]));
            }
            ++i;
            
        }
        return a.top();
    }
};
