class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret(1 << nums.size());
        for(int i = 1; i < ret.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){
                    ret[i].push_back(nums[j]);
                }
            }
        }


        return ret;
    }
};
