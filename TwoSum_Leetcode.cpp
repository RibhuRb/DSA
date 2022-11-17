/* Question:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists. */


//Solution in O(n) time complexity


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umapsum;  //unordered_map has constant(O(1)) time complexity for insertion and search.
        vector <int> result;
        int comp;
        for (unsigned i=0; i<nums.size(); i++)
        {
            comp=target-nums[i];
            if(umapsum.count(comp)){
                result.push_back(i);
                result.push_back(umapsum[comp]);
                return result;
            }
            umapsum[nums[i]]=i;
        }
        return result;
    }
};

int main()
{
    vector <int> nums;
    int target, vinput;
    cin>>target;
    while(cin>>vinput) nums.push_back(vinput);
    Solution obj;
    vector <int> output = obj.twoSum(nums,target);
    for(auto &it : output) cout<<it<<" ";
    return 0;
}