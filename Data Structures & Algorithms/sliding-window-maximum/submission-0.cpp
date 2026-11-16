class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deck;
        vector<int> max;
        max.resize(nums.size() - k + 1, 0);
        for(int i = 0; i < k; i++){
            while(!deck.empty() && deck.back() < nums[i]){
                deck.pop_back();
            }
            deck.push_back(nums[i]);
        }
        for(int i = k; i < nums.size(); i++){
            max[i-k] = deck.front();
            while(!deck.empty() && deck.back() < nums[i]){
                deck.pop_back();
            }
            deck.push_back(nums[i]);
            
            if(deck.front() == nums[i-k]){
                deck.pop_front();
            }
            
        }

        max[max.size()-1] = deck.front();

        return max;
    }
};
