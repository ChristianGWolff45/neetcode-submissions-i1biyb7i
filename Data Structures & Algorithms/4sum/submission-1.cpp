class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> sums;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                unordered_set<int> visited;
                int l = j+1;
                int r = nums.size()-1;
                long long prevalue = nums[i] + nums[j];
                while(l < r){
                    if(target > prevalue + nums[l] + nums[r]){
                        l++;
                    }else if(target <  prevalue + nums[l] + nums[r]){
                        r--;
                    }else{
                        sums.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l+1]){
                            l++;
                        }
                        l++;
                    }
                }
                while(j + 1 < nums.size() && nums[j] == nums[j+1]){
                    j++;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i+1]){
                i++;
            }
        }
        return sums;
    }
};