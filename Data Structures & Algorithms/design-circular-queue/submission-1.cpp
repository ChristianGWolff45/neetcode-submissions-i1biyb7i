class MyCircularQueue {
private:
    vector<int> q;
    int front = 0;
    int back = -1;

public:
    MyCircularQueue(int k) {
        q.resize(k);
    }
    
    bool enQueue(int value) {
        
        if(this->isFull()){
            return false;
        }
        back++;
        q[back%q.size()] = value;
        

        return true;
    }
    
    bool deQueue() {
        if(this->isEmpty()){
            return false;
        }
        front++;
        return true;
    }
    
    int Front() {
        if(this->isEmpty()){
            return -1;
        }
        return q[front%q.size()];
    }
    
    int Rear() {
        if(this->isEmpty()){
            return -1;
        }
        return q[back%q.size()];
    }
    
    bool isEmpty() {
        if(back < front){
            back = -1;
            front = 0;
        }
        return back < front;
    }
    
    bool isFull() {
        return back - front == q.size() - 1;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */