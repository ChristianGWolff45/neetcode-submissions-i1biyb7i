class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> elements;
        for(int i = 0; i < nums.size(); i++){
            if(!elements.contains(nums[i])){
                elements[nums[i]] = 1;
            }else{
                elements[nums[i]]++;
            }
            if(elements[nums[i]] >= (nums.size()+1)/2){
                return nums[i];
            }
        }
        return -1;
    }
    
};