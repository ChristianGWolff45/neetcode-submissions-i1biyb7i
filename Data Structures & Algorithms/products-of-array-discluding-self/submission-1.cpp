class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preProduct = {1};
        vector<int> postProduct = {1};
        int product = 1;
        for(int num : nums){
            product *= num;
            preProduct.push_back(product);
        }
        product = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            product *= nums[i];
            postProduct.push_back(product);
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = preProduct[i] * postProduct[nums.size() - i - 1];
        }
        return nums;

    }
};
