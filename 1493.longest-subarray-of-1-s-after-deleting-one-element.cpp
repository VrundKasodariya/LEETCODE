/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int i = 0;
        int j = 0;
        int len = 0;

        while(j<n){
            if(nums[j] == 0){
                zeroCount++;
            }
            while(zeroCount > 1){
                if(nums[i] == 0) zeroCount--;
                i++;
            }
            len = max(len,j-i);
            j++;`
        }
        return len;
    }
};
// @lc code=end

