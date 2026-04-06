class Solution {
    public int maxArea(int[] heights) {
        int max = 0;
        int l = 0;
        int r = heights.length - 1;
        while(l < r){
            int area = area(r-l,heights[l], heights[r]);
            if(area > max){max = area;}
            if(heights[l] <= heights[r]){
                l++;
                continue;
            }
            if(heights[r] < heights[l]){
                r--;
                continue;
            }
        }
        return max;
    }
    public int area(int width, int height1, int height2){
        int height = height1 < height2 ? height1 : height2;
        return width * height;
    }
}
