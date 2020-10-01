class Solution {
public:
    int dp[1000][1000];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
       // vector<vector<int>> dp(row,vector<int> (col));
        dp[0][1] =1 ;
        //dp[1][0] = 1;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(obstacleGrid[i-1][j-1] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[row][col];
    }
};