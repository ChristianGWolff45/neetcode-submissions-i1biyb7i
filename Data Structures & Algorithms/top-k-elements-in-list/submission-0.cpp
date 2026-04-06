class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 0) return {};
        if(n < 1) return {};


        unordered_map<int, int> freq;
        freq.reserve(n * 2);
        for(int x : nums) ++freq[x];

        vector<vector<int>> buckets(n+1);
        for(const auto& p : freq) {
            buckets[p.second].push_back(p.first);
        }
        int count = 0;
        vector<int> results;
        for(int i = n; i >= 1; i--){
            for(int num : buckets[i]){
                count++;
                results.push_back(num);
                if(count == k){
                    return results;
                }
            }
        }
        return results;
    }
};
