// C++ implementation of insertion sort
//
// Author: Andres Langberg

// A utility function to print an array of size n 
#include <iostream>
#include <vector>
using namespace std;
void print_array(vector<int> arr, int n) 
{ 
   for (size_t i = 0; i < n; i++)
    {
       std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 
} 

/* Function to sort an array using insertion sort*/
void insertion_sort(vector<int> arr, int n) 
{ 
   int key;
   size_t j;
   for (size_t i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j + 1] = arr[j]; 
           j--; 
        
       } 
       arr[j + 1] = key;
       print_array(arr,n) ; 
   } 
}   
  
/* Driver program to test insertion sort */
int main() 
{ 
int n;
std::cin >> n;
vector<int> arr(n);

for(int i = 0;i < n;i++)
    std::cin >> arr[i] ;
insertion_sort(arr,n) ;
//print_it(n,arr);
return 0; 
} 
