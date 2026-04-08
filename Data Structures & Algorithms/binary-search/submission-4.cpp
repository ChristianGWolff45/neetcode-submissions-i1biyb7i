class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i;
        int left = 0, right = nums.size();
        do{
            i = (right + left) /2;
            if(nums[i] > target){
                right = i - 1;
            }else if(nums[i] < target){
                left = i + 1;
            }else{
                return i;
            }
        }while(i != (right + left) /2);
        return -1;
    }
};
