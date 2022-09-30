#include<bits/stdc++.h>
using namespace std;
int GetBuildingCount(int n, string s){
    set<char> row,col;
    int pos = 0;

    for(int i = 0;i < s.size(); i++){
        char ch = s[i];
        if(ch != '{' &&  ch != ',' && ch != '}'){
            if(pos == 0){
                row.insert(ch);
            }
            else{
                col.insert(ch);
            }
            pos = (pos+1)%2;

        }

    }
    return ((row.size() + col.size()) * 8 - n);
}
int main(){
    int n;  cin >> n;
    string s;  cin >> s;

    cout << GetBuildingCount(n, s);

    return 0;
}