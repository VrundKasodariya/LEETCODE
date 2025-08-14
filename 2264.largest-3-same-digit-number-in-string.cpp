/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maxi = -1;
        string res =  "";
        for(int i =0;i<n;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                int t = stoi(num.substr(i,3));
                maxi = max(maxi,t);
            }
        }
        if(maxi == 0){
            res += "000";
        }
        else if(maxi > 0){
            res += to_string(maxi);
        }
        return res;
    }
};
// @lc code=end

