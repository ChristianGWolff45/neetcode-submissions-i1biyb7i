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
        if(index >= candidates.size()){
            return;
        }
        int i = 0;
        while(index + i < candidates.size() && candidates[index] == candidates[index + i]){
            i++;
        }
        combination(sets, subset, candidates, target, index + i);
        subset.push_back(candidates[index]);
        target -= candidates[index];
        if(target < 0){
            subset.pop_back();
            return;
        }
        if(target == 0){
            sets.push_back(subset);
            subset.pop_back();
            return;
        }
        combination(sets, subset, candidates, target, index + 1);
        subset.pop_back();

    }
};
