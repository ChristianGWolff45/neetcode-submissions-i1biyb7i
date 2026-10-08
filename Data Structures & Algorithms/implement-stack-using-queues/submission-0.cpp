class MyStack {
private:
    queue<int> stk;
    queue<int> tempStack;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        while(stk.size() != 1){
            tempStack.push(stk.front());
            stk.pop();
        }
        int top = stk.front(); stk.pop();
        while(!tempStack.empty()){
            stk.push(tempStack.front());
            tempStack.pop();
        }
        return top;
    }
    
    int top() {
        while(stk.size() != 1){
            tempStack.push(stk.front());
            stk.pop();
        }
        int top = stk.front(); stk.pop();
        tempStack.push(top);
        while(!tempStack.empty()){
            stk.push(tempStack.front());
            tempStack.pop();
        }
        return top;
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */