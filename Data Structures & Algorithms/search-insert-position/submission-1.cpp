class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return 0;
        }
        int l = 0; int r = nums.size() - 1;
        int mid = 0;
        while(l <= r){
            mid = r + (l - r)/2;
            std::cout << mid << std::endl;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }else{
                return mid;
            }
        }
        return target > nums[mid] ? mid + 1 : mid;
    }
};