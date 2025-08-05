/*
 * @lc app=leetcode id=3477 lang=cpp
 *
 * [3477] Fruits Into Baskets II
 */

// Problem Statement: In the problme there are given 2 arrays : fruits and baskets.

// fruits[i] is the number of fruit of type i
// baskets[i] is the maximum quantity that , that position can hold

// From left to right the fruits has to be placed according to some rules:

// 1.Each fruit type should be placed in the leftmost available basket where the capacity of the basket is >= than the number of fruits 

// 2. Each basket can hold only 1 type of fruit

// 3. If a fruit cannot be placed in the basket then its unplaced fruit.

// Approach:


// We will make an array named placed and initialize the entire array with 0

// we will use nested for loop and for every fruit we will check whether the placed array is 0 and if the fruits[i] <= baskets[j]

// if thats the case we increase the count and initliase the placed[j] = 1 and break;
// We break; because we dont need to travel to the next element 


// atlast we have calculated the number of elements that are placed but we need to return the unplaced elements 

// So we return n-count

// @lc code=start
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> placed(n,0);
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(placed[j] == 0 && fruits[i]<=baskets[j]){
                    count++;
                    placed[j] = 1;
                    break;
                }
            }
        }
        return n-count;
    }
};
// @lc code=end

