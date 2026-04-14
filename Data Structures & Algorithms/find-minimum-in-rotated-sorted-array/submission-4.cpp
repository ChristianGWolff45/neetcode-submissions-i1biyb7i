class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int mid;
        do{
            mid = (l+r)/2;
            if(nums[r] > nums[mid]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }while(mid != (l+r)/2);
        return nums[mid];
    }
};
