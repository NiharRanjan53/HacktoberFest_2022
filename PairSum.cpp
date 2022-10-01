#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {

	int arr[]={1,2,3,4,5,6,7,8,9,15};
	int k=9;
	int n=10;
    unordered_set<int> s;
	for(int i=0;i<=n;i++)
	{
		int found = k-arr[i];
        if(s.find(found)!=s.end())
        {
            cout<<arr[i]<<","<<found<<endl;
        }
        s.insert(arr[i]);
	}
	return 0;
}