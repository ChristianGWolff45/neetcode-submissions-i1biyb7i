class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        do{
            mid = (l + r)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[r] > nums[mid]){
                if(nums[r] >= target && nums[mid] < target){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }else {
                if(target >= nums[l] && target < nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }while(mid != (l+r)/2);
        return -1;
    }
};
