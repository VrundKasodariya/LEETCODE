/*
 * @lc app=leetcode id=2438 lang=cpp
 *
 * [2438] Range Product Queries of Powers
 */

// @lc code=start
constexpr int MOD = 1e9 + 7;
using ll = long long;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bits;
        for(int i = 0; i < 32;i++){
            if(( 1 << i) & n) bits.push_back(1 << i);
        }
        vector<int> res;
        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            ll v = 1;
            for(int i = l; i <= r; i++){
                v *= bits[i];
                v %= MOD;
            }
            res.push_back(v);
        }
        return res;
    }
};
// @lc code=end

