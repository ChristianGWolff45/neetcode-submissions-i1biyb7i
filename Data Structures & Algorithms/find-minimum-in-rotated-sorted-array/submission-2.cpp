class Solution {
public:
    int findMin(vector<int> &nums) {
        int i =0, size = nums.size();
        while(nums[i] < nums[(i+1) % size]){i++;}
        return nums[(i + 1) % size];
    }
};
