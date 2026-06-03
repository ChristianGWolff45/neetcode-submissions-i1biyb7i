class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stoneHeap;
        for(auto stone : stones){
            stoneHeap.push(stone);
        }
        while(stoneHeap.size() > 1){
            int x = stoneHeap.top(); stoneHeap.pop();
            int y = stoneHeap.top(); stoneHeap.pop();
            int z = x - y;
            if(z > 0){
                stoneHeap.push(z);
            }
        }
        return stoneHeap.empty() ? 0 : stoneHeap.top();
    }
};
