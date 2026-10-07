class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int count = 0;
        int currCount = 0;
        seen[0] = 1;
        for(auto num : nums){
            currCount += num;
            if(seen.contains(currCount - k)){
                count += seen[currCount-k];
            }
            if(seen.contains(currCount)){
                seen[currCount]++;
            }
            else{
                seen[currCount] = 1;
            }
            
        }
        return count;
    }
};