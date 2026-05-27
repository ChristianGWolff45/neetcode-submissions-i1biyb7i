class KthLargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto num : nums){
            if(pq.size() < k){
                pq.push(num);
            }else if(num > pq.top()){
                pq.push(num);
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        if(pq.size() < size){
            pq.push(val);
        }
        else if(val > pq.top()){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};
