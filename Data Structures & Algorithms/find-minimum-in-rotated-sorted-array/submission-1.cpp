class Solution {
public:
    int findMin(vector<int> &nums) {
        int i =0;
        while(nums[i] < nums[(i+1) % nums.size()]){i++;}
        return nums[(i + 1) % nums.size()];
    }
};
