/*Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?*/

//Solution

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int div,rem, temp=x;
        long long int rev=0;
        while(x>0){
            rem = x%10;
            rev = rev*10+rem;
            x=x/10;
        }
        if(rev==temp) return true;
        return false;
    }
};

int main()
{
    int x;
    cin>>x;
    Solution obj;
    bool b = obj.isPalindrome(x);
    if(b==1) cout<<"true";
    else cout<<"false";
    return 0;
}