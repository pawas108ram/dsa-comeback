// 198. House Robber
// Solved
// Medium
// Topics
// Companies
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400

//Question Link https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21

// Approach :

// Basic approach is to use dp there are two choices either i take the curr and then go to the ind+2 as i can only take from there without signalling the security system else i can skip the current ind and try to take from the ind+1


//Memo Code 

// class Solution {
// public:
//     int helper(vector<int>&nums,int ind,vector<int>&dp){
//         if(ind>=nums.size()){
//             return 0;

//         }
//         if(dp[ind]!=-1){
//             return dp[ind];
//         }
//         return dp[ind]=max(helper(nums,ind+1,dp),helper(nums,ind+2,dp)+nums[ind]);
//     }
//     int rob(vector<int>& nums) {
//        int n=nums.size();
//        vector<int>dp(n,-1);
//        return  helper(nums,0,dp);
//     }
// };

