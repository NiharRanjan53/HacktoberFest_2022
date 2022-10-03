// this can be considered as a variation of Bubble Sort.
#include<bits/stdc++.h>
using namespace std;

void oddEven(int arr[], int size)
{
    bool is_sorted = false; 
    while (!is_sorted)
    {
        is_sorted = true;
        for (int i=1; i<=size-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                is_sorted = false;
            }
        }
        for (int i=0; i<=size-2; i=i+2)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                is_sorted = false;
            }
        }
    }
    return;
}

void printer(int arr[], int size)
{
for (int i=0; i < size; i++)
    cout <<arr[i]<< " ";
cout << "\n";
}


int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    int arr[] = {4, 2, 87, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    oddEven(arr, n);
    printer(arr, n);
    return (0);
}
