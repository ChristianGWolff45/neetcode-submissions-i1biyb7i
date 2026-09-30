class Solution {
public:
    
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> elements;
        vector<int> majority;
        for(int i = 0; i < nums.size(); i++){
            if(!elements.contains(nums[i])){
                elements[nums[i]] = 1;
            }else{
                elements[nums[i]]++;
            }
            if(elements[nums[i]] == nums.size()/3 + 1){
                majority.push_back(nums[i]);
            }
        }
        return majority;
    }
};