/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
class Solution {
public:
    double epsilon = 0.1;
    bool solve(vector<double> & cards){
        if(cards.size() == 1){
            return abs(cards[0] - 24.0) < epsilon;
        }
        for(int i = 0;i<cards.size();i++){
            for(int j = 0;j<cards.size();j++){
                if( i == j) continue;
                vector<double> temp;
                for(int k = 0;k<cards.size();k++){
                    if(k != i && k != j){
                        temp.push_back(cards[k]);
                    }
                }
                double a = cards[i];
                double b = cards[j];

                vector<double> possibilities ={a+b,a-b,b-a,a*b};
                if(a>0){
                    possibilities.push_back(b/a);
                }
                if(b>0){
                    possibilities.push_back(a/b);
                }
                for(double val : possibilities){
                    temp.push_back(val);
                    if(solve(temp)) return true;
                    temp.pop_back();
                }

            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i = 0;i<cards.size();i++){
            nums.push_back(1.0 * cards[i]);
        }

        return solve(nums);
    }
};
// @lc code=end

