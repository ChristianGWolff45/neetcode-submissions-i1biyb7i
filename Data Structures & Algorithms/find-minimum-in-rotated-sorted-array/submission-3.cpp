class Solution {
public:
    int findMin(vector<int> &nums) {
        int l =0, r = nums.size() - 1, mid;
        do{
            mid = (l+r)/2;
            if(nums[r] > nums[l]){
                return nums[l];
            }else if(nums[r] > nums[mid]){
                r = mid;
            }else{
                l = mid;
            }

        }while(l < r -1);
        return nums[r];
    }
};
