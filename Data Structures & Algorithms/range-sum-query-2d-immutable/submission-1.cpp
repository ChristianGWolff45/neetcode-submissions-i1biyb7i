class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        prefix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                int sum = matrix[i][j];
                for(int k = i; k > 0; k--){
                    sum+=matrix[k-1][j];
                }
                if(j > 0){
                    sum+=prefix[i][j-1];
                }
                prefix[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix[row2][col2];
        if(row1 > 0){
            sum -= prefix[row1 - 1][col2];
        }
        if(col1 > 0){
            sum -= prefix[row2][col1-1];
        }
        if(col1 > 0 && row1 > 0){
            sum += prefix[row1-1][col1-1];
        }
        return sum;
        
    }   
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */