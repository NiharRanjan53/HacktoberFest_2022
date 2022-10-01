#include <iostream>
#include <vector>
using namespace std;

int main() {

    int arr[] = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int highest_length = 0;
    for(int i=1;i<n-1;)
    {
        // trace peak element
        if(arr[i]>arr[i-1] and arr[i]>arr[i+1])
        {
            int count=1;
            int backward = i;

            // for backward 
            while(backward>1 and arr[backward]>arr[backward-1])
            {
                count++;
                backward--;
            }

            // for forward 
            while(i<(n-2) and arr[i]>arr[i+1])
            {
                i++;
                count++;
            }
             if(count>highest_length)
                {
                    highest_length=count;
                }
            
        }
        else
        {
            i++;
        }
       
        
    }

    cout<<highest_length;

	return 0;
}