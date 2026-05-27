class KthLargest {
public:
    int size;
    priority_queue<int> pq;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto num : nums){
            pq.push(num);
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        vector<int> temps;
        for(int i = 0; i < size -1; i++){
            temps.push_back(pq.top()); pq.pop();
        }
        int ret = pq.top();
        for(auto temp : temps){
            pq.push(temp);
        }
        return ret;
    }
};
