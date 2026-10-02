class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0;
        int l = 0; int r = nums.size() -1;
        while(l < r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--; 
        }
        l=0;
        r = k%nums.size() -1;
        while(l < r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--; 
        }
        l=k%nums.size();
        r = nums.size() - 1;
        while(l < r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--; 
        }
    }
};