class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int w = 0;
        int b = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                nums[r] = 0;
                r++;
            }else if(nums[i] == 1){
                w++;
            }else{
                b++;
            }
        }
        int i = r;
        while(i - r < w){
            nums[i] = 1;
            i++;
        }
        while(i - r - w < b){
            nums[i] = 2;
            i++;
        }
    }
};