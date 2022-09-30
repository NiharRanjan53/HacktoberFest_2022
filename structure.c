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

vector<int> placement(int input, int input2[]) {
    vector<int> r(input);
    for (int i = input - 1; i >= 0; i--) {
        int cnt = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (input2[j] > input2[i])
                cnt++;
        }
        r[i] = cnt;
    }
    return r;
}



int main() {
    int n; cin >> n;
    int input2[n];
    for (int i = 0; i < n; i++)
        cin >> input2[i];

    vector<int> v = placement(n, input2);
    
    for (auto it : v) {
        cout << it << " ";
    }
    
    return 0;
}
