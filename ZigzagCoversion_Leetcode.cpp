/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000*/

//Solution

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if(numRows == 1 || numRows >= size) return s;
        int j,count,diff = numRows+(numRows-2);
        string res;
        for(int i=0;i<numRows;i++){
            j=i;
            count=0;
            while(j<size){
                res.push_back(s[j]);
                if(i==0 || i == numRows-1) j+=diff;
                else if (count%2==0) {
                    j+=(diff-2*i);
                    count++;
                }
                else {
                    j+=2*i;
                    count++;
                }
            }
        }
        return res;
    }
};

int main() {
    string s;
    int nR;
    cin>>s>>nR;
    Solution obj;
    cout<<obj.convert(s,nR);
}