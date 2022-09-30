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
    //vector<int> r(input);
    struct Result res;
    
    for (int i = input - 1; i >= 0; i--) {
        int cnt = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (input2[j] > input2[i])
                cnt++;
        }
        res.output1[i] = cnt;
    }
    return res;
}



int main() {
    int n; cin >> n;
    int input2[n];
    for (int i = 0; i < n; i++)
        cin >> input2[i];

    struct Result res = placement(n, input2);
    
    for (int i = 0;i < n;i++) {
        cout << res.output1[i] << " ";
    }
    
    return 0;
}
