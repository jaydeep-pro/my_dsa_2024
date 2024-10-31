class Solution {
    private:
    int h(int i,int j,  vector<vector<int>>&grid, vector<vector<int>>& dp){
        if(i < 0 || i >= grid.size() || j >= grid[0].size())
        return 0;
        int count = 0;

        if (dp[i][j] != -1)  
            return dp[i][j];

        if(j < grid[0].size() - 1 && grid[i][j + 1] > grid[i][j])
        count = max(count, h(i, j + 1, grid, dp) + 1);
        if(i < grid.size() - 1 && j < grid[0].size() - 1 && grid[i + 1][j + 1] > grid[i][j])
        count = max(count, h(i + 1, j + 1, grid, dp) + 1);
        if(i > 0 && j < grid[0].size() - 1 && grid[i - 1][j + 1] > grid[i][j])
        count = max(count, h(i - 1, j + 1, grid, dp) + 1);

        return dp[i][j] = count;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int maxi = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        for(int i = 0;i < grid.size();i++){
            maxi = max(maxi, h(i, 0, grid, dp));
        }

        return maxi;
    }
};