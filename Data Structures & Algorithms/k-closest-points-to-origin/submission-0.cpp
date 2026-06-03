class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<
            pair<int, vector<int>>, 
            vector<pair<int, vector<int>>>, 
            greater<pair<int, vector<int>>>
        > minHeap;
        for(auto point : points){
            minHeap.push({distance(point), point});
        }
        for(int i = 0; i < k; i++){
            res.push_back(minHeap.top().second); minHeap.pop();
        }


        return res;

    }

    int distance(vector<int>& point){
        return ((point[0] * point[0]) + (point[1] * point[1]));
    }
};
