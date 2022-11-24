/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1 */

//Fastest Solution

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;   // INT_MIN * -1 > INT_MAX. So, It will provide overflow in our (x=-x) code. 
        int rev=0, rem, flag=0;
        //Change X to positive so that overflow will only greater than INT_MAX.
        //Reverse Less than INT_MIN is not possible. 
        if(x<0) {     
            x=-x;
            flag=1;  //To check x is positive or negative.
        }
        //Reverse positive number
        while(x>0){
            rem=x%10;
            if(rev !=0 && INT_MAX/rev <10 ) return 0;    //Check Overflow of Integer
            rev=rev*10+rem;
            x=x/10;
        }
        if(flag==1) rev=-rev;   //if X is negative then rev should also be negative.
        return rev;
    }
};

int main() {
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.reverse(n);
}