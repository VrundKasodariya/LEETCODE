/*
 * @lc app=leetcode id=3446 lang=cpp
 *
 * [3446] Sort Matrix by Diagonals
 */

// @lc code=start
class Solution {
public:
void solve(int row,int col,vector<vector<int>> & grid, bool asc){
    int n = grid.size();

    int i = row;
    int j = col;
    vector<int> res;
    while(i<n && j<n){
        res.push_back(grid[i][j]);
        i++;
        j++;
    }
    if(asc){
        sort(res.begin(),res.end());
    }
    else{
        sort(res.rbegin(),res.rend());
    }
    i = row;
    j = col;
    for(int & val : res){
        grid[i][j] = val;
        i++;
        j++;
    }
}
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int row = 0;row<n;row++){
            solve(row,0,grid,false);
        }
        
        for(int col = 1;col<n;col++){
            solve(0,col,grid,true);
        }
        return grid;
    }
};
// @lc code=end

