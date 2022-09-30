#include<iostream>
using namespace std;
void linearSearch(){

}
int recursiveLinearSearch(int arr[], int n, int key){
    if(n == 0){
        return -1;
    }

    if(arr[n-1] == key){
        return n-1;
    }

    else{
        return recursiveLinearSearch(arr, n-1, key);
    }
}
int main(){

    int arr[] = {5, 6, 7, 8, 3};
    cout << recursiveLinearSearch(arr, 5, 9);



    return 0;

}