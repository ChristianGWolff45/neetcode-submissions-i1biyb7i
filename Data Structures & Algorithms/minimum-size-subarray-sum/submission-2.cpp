class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = nums.size() + 10;
        int l = 0, r = 0;
        int total = 0;
        while(r < nums.size()){
            if(total < target){
                total += nums[r];
                r++;
            }
            while(total >= target){
                if(r-l < min){
                    min = r-l;
                }
                total -= nums[l];
                l++;
            }
        }
        if(min == nums.size() + 10){
            return 0;
        }
        return min;
    }
};