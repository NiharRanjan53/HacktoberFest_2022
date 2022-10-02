#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int arr[]={1,2,3,4,5,6,7,8,9,15};
	int k=18;
	int n=10;
	sort(arr,arr+n);
	for(int i=0;i<=n-3;i++)
	{
		int p=i+1,q=n-1;
		int c= k-arr[i];
		while(p<q)
		{
			int res=arr[p]+arr[q];
			if(res==c)
			{
				cout<<arr[i]<<","<<arr[p]<<","<<arr[q]<<endl;
				q--;
                p++;
			}
			else if(c>res)
			{
				p++;
			}
			else{
				q--;				
			}
		}
	}
	return 0;
}
