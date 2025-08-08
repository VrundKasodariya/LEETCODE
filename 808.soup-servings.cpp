/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
class Solution {
public:
    vector<pair<int,int>> serves = {{100,0},{75,25},{50,50},{25,75}};
    vector<vector<double>> t;

    double solve(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        if (t[A][B] != -1.0) return t[A][B];

        double prob = 0.0;
        for (auto &p : serves) {
            int A_taken = p.first;
            int B_taken = p.second;
            prob += solve(max(0, A - A_taken), max(0, B - B_taken));
        }

        return t[A][B] = 0.25 * prob;
    }

    double soupServings(int n) {
        if (n >= 4800) return 1.0;  
   
        t.resize(n + 1, vector<double>(n + 1, -1.0));
        return solve(n, n);
    }
};

// @lc code=end

