class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> sums = new ArrayList<>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length;i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = nums.length -1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                    continue;
                }
                if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                    continue;
                }
                if(nums[i] + nums[l] + nums[r] == 0){
                    sums.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    r--;
                    l++;
                }
            }
        }
        return sums;
    }
}
