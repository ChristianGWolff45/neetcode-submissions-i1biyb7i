class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> coords;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0){
                    coords.push({i,j});
                }
            }
        }
        while(!coords.empty()){
            pair<int,int> coord = coords.front(); coords.pop();
            int dist = grid[coord.first][coord.second];
            if(coord.first > 0 && grid[coord.first - 1][coord.second] > dist + 1){
                grid[coord.first - 1][coord.second] = dist + 1;
                coords.push({coord.first -1, coord.second});
            }
            if(coord.first + 1 < grid.size() && grid[coord.first + 1][coord.second] > dist + 1){
                grid[coord.first + 1][coord.second] = dist + 1;
                coords.push({coord.first + 1, coord.second});
            }
            if(coord.second + 1 < grid[0].size() && grid[coord.first][coord.second + 1] > dist + 1){
                grid[coord.first][coord.second + 1] = dist + 1;
                coords.push({coord.first, coord.second + 1});
            }
            if(coord.second  > 0 && grid[coord.first][coord.second - 1] > dist + 1){
                grid[coord.first][coord.second - 1] = dist + 1;
                coords.push({coord.first, coord.second - 1});
            }
        }
    }
};
