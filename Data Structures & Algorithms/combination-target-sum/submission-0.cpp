class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> response;
        vector<int> current;
        subset(response, nums, current, target, 0);

        return response;
    }

    void subset(vector<vector<int>>& response,vector<int>& nums, vector<int>& current, int target, int index){
        if(index == nums.size()){
            return;
        }
        subset(response, nums, current, target, index + 1);
        current.push_back(nums[index]);
        target-= nums[index];
        if(target < 0){
            current.pop_back();
            return;
        }
        if(target == 0){
            response.push_back(current);
            current.pop_back();
            return;
        }
        subset(response, nums, current, target, index);
        current.pop_back();

    }
};
