
/*
 * @lc app=leetcode id=3363 lang=cpp
 *
 * [3363] Find the Maximum Number of Fruits Collected
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<vector<int>> t;
    int child1Collection(vector<vector<int>>& fruits){
        int count = 0;
        for(int i = 0;i<n;i++){
            count += fruits[i][i];
        }
        return count;
    }

    int child2Collection(int i,int j,vector<vector<int>> & fruits){

        if(i>=n || j <= 0 || j>= n){
            return 0;
        }

        if(i == n-1 && j == n-1){
            return 0;
        }

        if(i == j || i>j){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int bottomLeft = fruits[i][j] + child2Collection(i+1,j-1,fruits);
        int bottom = fruits[i][j] + child2Collection(i+1,j,fruits);
        int bottomRight = fruits[i][j] + child2Collection(i+1,j+1,fruits);

        return t[i][j] =  max({bottomLeft,bottom,bottomRight});
    }

    int child3Collection(int i,int j,vector<vector<int>> & fruits){
        
        if(i<=0 || i>= n || j>= n){
            return 0;
        }

        if(i == n-1 && j == n-1){
            return 0;
        }

        if(i == j || i<j){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }

        int upRight = fruits[i][j] + child3Collection(i - 1,j+1,fruits);
        int right = fruits[i][j] + child3Collection(i,j+1,fruits);
        int downRight = fruits[i][j] + child3Collection(i + 1,j+1,fruits);
        
        return t[i][j] =  max({upRight,right,downRight});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        t.resize(n,vector<int>(n,-1));
        int c1 = child1Collection(fruits);

        int c2 = child2Collection(0,n-1,fruits);

        int c3 = child3Collection(n-1,0,fruits);

        return c1 + c2 + c3;
    }
};
// @lc code=end

