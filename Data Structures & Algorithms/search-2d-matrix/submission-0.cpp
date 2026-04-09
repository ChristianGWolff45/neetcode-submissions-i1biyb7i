class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size(), w = matrix[0].size();
        int l = 0, r = h * w;
        int p;
        do{
            p = (r + l )/2;
            if(matrix[p/w][p%w] < target){
                l = p;
            }else if(matrix[p/w][p%w] > target){
                r = p;
            }else{
                return true;
            }

        }while(p != (r + l )/2);
        return false;
    }
};
