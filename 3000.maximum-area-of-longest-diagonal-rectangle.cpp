/*
 * @lc app=leetcode id=3000 lang=cpp
 *
 * [3000] Maximum Area of Longest Diagonal Rectangle
 */

// @lc code=start
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double diag = 0.0;
        int area = 0;
        for(vector<int> v:dimensions){
            int len = v[0];
            int width = v[1];
            double val = sqrt(len * len + width * width);
            if(val > diag){
                diag = val;
                area = len * width;
            }
            else if (val == diag){
                area = max(area,len * width);
            }
        }
        return area;
    }
};
// @lc code=end

