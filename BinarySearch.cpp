// Self Implementation

#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    int BinarySearch(vector <int> &arr, int target, int start, int end) {
        int midIndex=(start+end)/2;
        if(start>end) return -1;
        int mid=arr[midIndex];
        if(mid==target) return midIndex;   
        else if(mid<target) return BinarySearch(arr, target, midIndex+1, end);
        else return BinarySearch(arr,target,start,midIndex-1);
    }
};

int main(){
    int size, target, vinput,i; 
    cin>>size>>target;
    vector <int> arr;
    i=size;
    while(i--){
        cin>>vinput;
        arr.push_back(vinput);
    }
    Solution obj;
    int output = obj.BinarySearch(arr,target,0,size-1);
    cout<<output;
    return 0;

}