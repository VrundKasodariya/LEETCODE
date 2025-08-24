/*
 * @lc app=leetcode id=3197 lang=cpp
 *
 * [3197] Find the Minimum Area to Cover All Ones II
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> rotateGrid(vector<vector<int>> & grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rotatedGrid(n, vector<int>(m));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                rotatedGrid[j][m-i-1] = grid[i][j];

            }
        }
        return rotatedGrid;
    }

    int  miniArea(int startRow,int endRow,int startCol,int endCol,vector<vector<int>> & grid){
        int m = grid.size();
        int n = grid[0].size();

        int minI = INT_MAX;
        int minJ = INT_MAX;
        int maxI = INT_MIN;
        int maxJ = INT_MIN;

        for(int i = startRow;i<endRow;i++){
            for(int j = startCol;j<endCol;j++){
                if(grid[i][j] == 1){
                    minI = min(minI,i);
                    minJ = min(minJ,j);
                    maxI = max(maxI,i);
                    maxJ = max(maxJ,j);
                }
            }
        }
        if(minI == INT_MAX) return 0;
        int height = maxI - minI + 1;
        int width = maxJ - minJ + 1;
        return height * width;

    }
    int utility(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        int result = INT_MAX;

        for(int rowSplit = 1;rowSplit < m; rowSplit++){
            for(int colSplit = 1;colSplit < n;colSplit++){
                int top = miniArea(0,rowSplit,0,n,grid);
                int bottomLeft = miniArea(rowSplit,m,0,colSplit,grid);
                int bottomRight = miniArea(rowSplit,m,colSplit,n,grid);

                result = min(result,top + bottomLeft + bottomRight);

                int topLeft = miniArea(0,rowSplit,0,colSplit,grid);
                int topRight = miniArea(0,rowSplit,colSplit,n,grid);
                int bottom = miniArea(rowSplit,m,0,n,grid);
                result = min(result,topLeft+topRight+bottom);

            }
        }
        for(int split1 = 1;split1 < m; split1++){
            for(int split2 = split1 + 1;split2 < m;split2++){
                int top = miniArea(0,split1,0,n,grid);
                int middle = miniArea(split1,split2,0,n,grid);
                int bottom = miniArea(split2,m,0,n,grid);

                result = min(result,top + middle + bottom);
            }
        }
        return result;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int result1 = utility(grid);
        vector<vector<int>> rotatedGrid = rotateGrid(grid);
        int result2 = utility(rotatedGrid);
        return min(result1,result2);
    }
};
// @lc code=end

