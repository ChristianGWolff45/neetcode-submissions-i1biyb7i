class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size(), w = matrix[0].size();
        int l = 0, r = h * w;
        int p, pval;
        do{
            p = (r + l )/2;
            pval = matrix[p/w][p%w];
            if(pval < target){
                l = p;
            }else if(pval > target){
                r = p;
            }else{
                return true;
            }

        }while(p != (r + l )/2);
        return false;
    }
};
