class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSums;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }else if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                }else{
                    threeSums.push_back({nums[i], nums[l], nums[r]});
                    while(l + 1 < nums.size() && nums[l+1] == nums[l]){
                        l++;
                    }
                    l++;
                }
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]){
                i++;
            }
        }
        return threeSums;
    }
};
