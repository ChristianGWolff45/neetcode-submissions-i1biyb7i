class MyQueue {
public:
    stack<int> q;
    stack<int> temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        int size = q.size();
        while(!q.empty()){
            temp.push(q.top()); q.pop();
        }
        q.push(x);
        while(!temp.empty()){
            q.push(temp.top());
            temp.pop();
        }



    }
    
    int pop() {
        int top = q.top(); q.pop();
        return top;
    }
    
    int peek() {
        return q.top();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */