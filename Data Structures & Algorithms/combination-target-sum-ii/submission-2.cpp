class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sets;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        combination(sets, subset, candidates, target, 0);
        return sets;
    }
    void combination(vector<vector<int>>& sets, vector<int>& subset, vector<int>& candidates, int target, int index) 
    {
        if(target == 0){
            sets.push_back(subset);
            return;
        }
        if(index >= candidates.size() || target < 0){
            return;
        }
        int i = 0;
        while(index + i < candidates.size() && candidates[index] == candidates[index + i]){
            i++;
        }
        combination(sets, subset, candidates, target, index + i);
        subset.push_back(candidates[index]);
        
        combination(sets, subset, candidates, target - candidates[index], index + 1);
        subset.pop_back();

    }
};
