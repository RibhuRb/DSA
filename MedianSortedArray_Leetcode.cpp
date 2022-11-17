/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5. */

//Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert( nums1.end(), nums2.begin(), nums2.end() );
        sort(nums1.begin(), nums1.end());
        int s = nums1.size();
        if(s%2==1) return nums1.at((s-1)/2);
        else return (double(nums1.at(s/2) + nums1.at((s/2)-1)))/2;     
    }
};

int main(){
    vector<int> nums1;
    vector<int> nums2;
    int nums1size,nums2size,vinput;
    cin>>nums1size>>nums2size;  //Taking it as extra input as compare to leetcode question.
    while(nums1size--){
        cin>>vinput;
        nums1.push_back(vinput);
    }
    while(nums2size--){
        cin>>vinput;
        nums2.push_back(vinput);
    }
    Solution obj;
    double output = obj.findMedianSortedArrays(nums1,nums2);
    cout<<output;
}