/*
 * @lc app=leetcode id=3479 lang=cpp
 *
 * [3479] Fruits Into Baskets III
 */



// @lc code=start
class Solution {
public:
 void build(int i,int l, int r,vector<int>&baskets,vector<int>& segmentTree){
        
        if(l == r){
            segmentTree[i] = baskets[l];
            return;
        }

        int mid = (l+r)/2;
        build(2 * i + 1,l,mid,baskets,segmentTree);
        build(2 * i + 2,mid + 1,r,baskets,segmentTree);
        segmentTree[i] = max(segmentTree[2 * i + 1],segmentTree[2 * i + 2]);
    }
    bool query(int i,int l,int r,vector<int> & segmentTree,int fruit){
        if(segmentTree[i] < fruit) {
            return false;
        }
        if( l == r){
            segmentTree[i] = -1;
            return true;
        }
        int mid = l+(r-l)/2;
        bool placed = false;
        if(segmentTree[2 * i + 1] >= fruit){
            placed = query(2*i+1, l, mid, segmentTree, fruit);
        }
        else{
            placed = query(2*i+2, mid+1, r, segmentTree, fruit);
        }

        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);

        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();

        vector<int> segmentTree(4*n,-1);
        build(0,0,n-1,baskets,segmentTree);
        int unplaced = 0;
        for(int & fruit: fruits){
            if(!query(0,0,n-1,segmentTree,fruit)){
                unplaced++;
            }
        }
        return unplaced;
    }
};
// @lc code=end

