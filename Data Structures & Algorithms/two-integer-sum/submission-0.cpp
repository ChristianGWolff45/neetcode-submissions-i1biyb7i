class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> compliment;
        for(int i = 0; i < nums.size(); i++){
            if(compliment.count(target - nums[i])) return {compliment[target - nums[i]], i};
            compliment[nums[i]] = i;
        }
    }
};
