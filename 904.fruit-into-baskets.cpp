/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start

// Problem Summary:
// Here we are using  SLiding window + unordered_map 
// The Problems states an array of fruits where fruits[i] is the type of ith fruit.
// There are maximum 2 baskets provided, in which only 1 type o fruit can be added .
// Note that there is max size of the basket given.

// Imp = Once you encounter more than 2 fruits you stop
// your goal is to get the maximum number of fruits.

// NOTE: Now the question is : Find the lasrgest window(subarray) having atmost 2 unique fruits(numbers).

// Approach:
// You are using two pointers i and j which gives the current window.

// you have a variable named count to store the maximum number fruit 
// You are using unordered_map to store the frequency of the the fruits in the window.

// while j is less than n the loop will work 
// when encounter a fruit we increase its count in the map

// Because there can be a maximum of 2 types of fruits. The size of the map should not be more than 2

// if the size of the hasmap is more than 2 we decrease count of the fruit at position i because then we increase the i to the next position (shrinking the window).

// if the count of the fruit at ith position is zero that means there is no fruit of that type in the window. So we remove the fruit from the map

// we increase i

// we increase j

// return count

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0, j = 0;
        int count = 0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                count = max(count,j-i+1);
            }
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                     mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
        return count;
    }
};
// @lc code=end
