/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
         vector<double> P(n+1,0.0);

        P[0] = 1.0;

        double currProbSum = (k == 0) ? 0 : 1;

        for(int i = 1;i<=n;i++){
            P[i] = currProbSum/maxPts;

            if(i < k){
                currProbSum += P[i];
            }
            if(i - maxPts >= 0 && i-maxPts < k)
            currProbSum -= P[i-maxPts];
        }

        return accumulate(P.begin() + k,P.end(),0.0);
    }
};
// @lc code=end

