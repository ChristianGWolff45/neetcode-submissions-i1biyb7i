class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int unique = 1;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[j-1]){
                nums[unique] = nums[j];
                unique++;
                
            }
        }


        return unique;
    }
};