/*
 * @lc app=leetcode id=3195 lang=cpp
 *
 * [3195] Find the Minimum Area to Cover All Ones I
 */

// @lc code=start
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minI = INT_MAX;
        int minJ = INT_MAX;
        int maxI = INT_MIN;
        int maxJ = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    minI = min(minI,i);
                    minJ = min(minJ,j);
                    maxI = max(maxI,i);
                    maxJ = max(maxJ,j);
                }
            }
        }
        int height = maxI - minI +1;
        int width = maxJ - minJ +1;
        return height * width;

    }
};
// @lc code=end

