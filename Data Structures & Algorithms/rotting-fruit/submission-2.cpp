class Solution {
public:
    struct coord{
        int i;
        int j;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<coord> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            coord curr = q.front(); q.pop();
            int i = curr.i;
            int j = curr.j;
            if(curr.i > 0 && grid[i - 1][j] == 1){
                grid[i-1][j] = grid[i][j] + 1;
                q.push({i-1,j});
            }
            if(curr.i + 1 < grid.size() && grid[i + 1][j] == 1){
                grid[i+1][j] = grid[i][j] + 1;
                q.push({i+1,j});
            }
            if(curr.j > 0 && grid[i][j-1] == 1){
                grid[i][j-1] = grid[i][j] + 1;
                q.push({i,j-1});
            }
            if(curr.j + 1 < grid[i].size() && grid[i][j + 1] == 1){
                grid[i][j+1] = grid[i][j] + 1;
                q.push({i,j+1});
            }
        }
        int time = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                time = max(time, grid[i][j] - 2);
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;

    }
};
