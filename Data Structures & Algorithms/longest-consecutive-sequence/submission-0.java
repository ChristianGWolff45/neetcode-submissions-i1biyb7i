class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> numbers = new HashSet<>();
        for(int num : nums){
            numbers.add(num);
        }
        int max = 0;
        for(int i = 0; i < nums.length; i++){
            int temp = 0;
            if(!numbers.contains(nums[i]-1)){
                do{
                    temp++;
                }while(numbers.contains(nums[i]+temp));
            }
            if(temp > max){
                max = temp;
            }
        }
        return max;
    }
}
