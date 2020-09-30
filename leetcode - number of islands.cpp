// leetcode - number of islands
// https://leetcode.com/problems/number-of-islands/

int points[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};

class Solution {
public:
    bool isValid(int i, int j, int m , int n) {
        return (i >= 0 and j >= 0 and i < m and j < n);
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        grid[i][j] = '0';

        for (int p = 0 ; p < 4 ; p++) {
            int x = i + points[p][0];
            int y = j + points[p][1];

            if (isValid(x, y, m, n) and grid[x][y] == '1')
                dfs(grid, x, y, m, n);
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.size() == 0)
            return 0;

        int ans = 0;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0 ; i < m ; i++)
            for (int j = 0 ; j < n ; j++)
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m , n);
                    ans++;
                }

        return ans;
    }
};