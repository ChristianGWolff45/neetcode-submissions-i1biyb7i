class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product1 = 1;
        int product2 = 1;
        for(int num : nums){
            if(product1 == 0 && num == 0) product2 = 0;
            product1 = product1 * num;
            if(num != 0) product2 = product2 * num;
        }
        for(int i = 0;  i < nums.size(); i++){
            if(nums[i] == 0) nums[i] = product2;
            else nums[i] = product1 / nums[i];
        }
        return nums;
    }
};
