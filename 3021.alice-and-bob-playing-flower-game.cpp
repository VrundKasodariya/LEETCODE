/*
 * @lc app=leetcode id=3021 lang=cpp
 *
 * [3021] Alice and Bob Playing Flower Game
 */

// @lc code=start
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd_n  = ceil(n / 2.0);
        long long even_n = floor(n / 2.0);
        long long odd_m  = ceil(m / 2.0);
        long long even_m = floor(m / 2.0);
        return (odd_m * even_n) + (even_m * odd_n);
    }
};
// @lc code=end

