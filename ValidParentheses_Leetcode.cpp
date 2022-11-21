/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/

//Solution with Stack
//Leetcode 100% C++ time efficient solution.

#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> brac;
        unordered_map <char,char> pairs ( {{ ')','(' },{ '}','{' },{ ']','[' }} );
        while(!s.empty()){
            char lastch= s.back();
            
            if(pairs.count(lastch)) brac.push(pairs[lastch]);
            else if(brac.empty()) return false;
            else if(brac.top() == lastch) brac.pop();
            else return false;
            
            s.pop_back();
        }
        if(brac.empty()) return true;
        return false;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution obj;
    bool x = obj.isValid(s);
    if(x==1) cout<<"true";
    else cout<<"false";
    return 0;
}