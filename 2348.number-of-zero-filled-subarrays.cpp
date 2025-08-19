/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 */

// @lc code=start
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long count = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] != 0){
                sum += (count*(count + 1))/2;
                count = 0;
            }
            else{
                count++;
            }
        }
        if(count != 0){
            sum += (count*(count + 1))/2;
        }
        return sum;
    }
};
// @lc code=end

