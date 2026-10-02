class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax;
        vector<int> rmax;
        int l = 0;
        int r = 0;
        for(int i = 0; i < height.size(); i++){
            if(l < height[i]){
                l = height[i];
            }
            lmax.push_back(l);
        }
        rmax.reserve(height.size());
        for(int i = height.size() - 1; i >= 0; i--){
            if(r < height[i]){
                r = height[i];
            }

            rmax[i] = r;
        }
        vector<int> mins;
        for(int i = 0; i < lmax.size(); i++){
            mins.push_back(min(lmax[i], rmax[i]));
        }
        int total = 0;
        for(int i = 0; i < mins.size(); i++){
            total += max(mins[i] - height[i], 0);
        }

        return total;
    }
};
