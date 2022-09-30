#include<stdio.h>
#include<string.h>
#include<iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
struct Result {
    Result() : output1() {};
    int output1[100];
};

Result placement(int input, int input2[]) {
    Result result ;
    for (int i = input - 1; i >= 0; i--) {
        int cnt = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (input2[j] > input2[i])
                cnt++;
        }
        result.output1[i] = cnt;
    }
    return result;
}



int main() {
    int n; cin >> n;
    int input2[n];
    for (int i = 0; i < n; i++)
        cin >> input2[i];

    Result res = placement(n, input2);
    
    for (int i = 0; i< n;i++) {
        cout << res.output1[i] << " ";
    }
    
    return 0;
}