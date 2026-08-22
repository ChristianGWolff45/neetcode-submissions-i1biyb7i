class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> response;
        vector<int> current;
        vector<bool> taken(nums.size(), false);
        backtrack(response, current, nums, taken);
        return response;
    }
    void backtrack(vector<vector<int>>& response, vector<int>& current, vector<int>& nums, vector<bool>& taken){
        if(current.size() == nums.size()){
            response.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(taken[i] == false){
                taken[i] = true;
                current.push_back(nums[i]);
                backtrack(response, current, nums, taken);
                current.pop_back();
                taken[i] = false;;
            }
        }
    }
};
