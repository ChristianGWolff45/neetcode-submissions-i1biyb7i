class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> response;
        vector<int> current;
        backtrack(response, current, nums, 0);
        return response;
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int index){
        if(index == nums.size()){
            res.push_back(cur);
            return;
        }
        int i = index;
        while(i < nums.size()){
            if(nums[i] != nums[index]){
                break;
            }
            i++;
        }
        backtrack(res, cur, nums, i);

        cur.push_back(nums[index]);
        backtrack(res, cur, nums, index+1);
        cur.pop_back();


    }
};
