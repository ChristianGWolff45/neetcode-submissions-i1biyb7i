class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> visited;
        for(auto num : nums){
            if(visited.contains(num)){
                return num;
            }else{
                visited.insert(num);
            }
        }

        return -1;
    }
};
