/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
class Solution {
public:
    string sortedstring(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string t = sortedstring(n);
        unordered_set<string> st;
        for(int i = 0;i<=p;i++){
            string s = sortedstring(1<<i);
            st.insert(s);
        }
        return st.count(t);
    }
};
// @lc code=end

