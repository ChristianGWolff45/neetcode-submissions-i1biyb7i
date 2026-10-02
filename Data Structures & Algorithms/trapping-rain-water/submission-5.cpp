class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0; int r = 0;
        int total = 0;
        while(r < height.size()){
            int rindex = r;
            int rmax = 0;
            while(rmax < height[l] && r < height.size()){
                if(height[r] > rmax){
                    rmax = height[r];
                    rindex = r;
                }
                if(height[r] < height[l]){
                    r++;
                }
            }
            if(r == height.size()){
                r = rindex;
            }
            std::cout << l << ", " << r << std::endl;
            int lmax = height[l];
            while(l < r){
                total += max(min(lmax, rmax) - height[l], 0);
                l++;
            }
            r++;
        }
        return total;
    }
};
