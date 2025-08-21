/*
 * @lc app=leetcode id=1504 lang=cpp
 *
 * [1504] Count Submatrices With All Ones
 */

// @lc code=start
class Solution {
public:
    int oneDArray(vector<int>& arr){
        int count = 0;
        int total = 0;
        for(int &val : arr){
            if(val == 0){
                count = 0;
            }
            else{
                count++;
                total += count;
            }
        }
        return total;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        for(int startRow = 0;startRow<m;startRow++){
            vector<int> arr(n,1);
            for(int endRow = startRow;endRow<m;endRow++){
                for(int col = 0;col<n;col++){
                    arr[col] = arr[col] & mat[endRow][col];
                }
                result += oneDArray(arr);
            }
        }
        return result;
    }
};
// @lc code=end

