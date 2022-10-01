// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> left(n,0), right(n,0);
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    int result = 0;

    for(int i=1;i<n;i++)
    {
        left[i] = max(left[i-1],arr[i]);
        right[n-i-1] = max(right[n-i],arr[n-i-1]);
    }

    for(int i=0;i<n;i++)
    {
        result+=(min(left[i],right[i])-arr[i]);
    }
    cout<<result;

	return 0;
}
