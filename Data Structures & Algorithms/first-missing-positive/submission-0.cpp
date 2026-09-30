class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> visited;
        int min = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > min){
                visited.insert(nums[i]);
            }if(nums[i] == min){
                while(visited.count(++min));
            }
        }
        return min;
    }
};