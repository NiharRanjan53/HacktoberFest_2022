#include<bits/stdc++.h>
using namespace std;
string solve(string s, unordered_set<string> list){

    for(int i = 0; i < s.size(); i++){
        int j = i;
        while(j < s.size() && s[j] != ' '){
            j++;
        }
        if(list.find(s.substr(i, j-i)) != list.end()){

            s[i] = toupper(s[i]);

        }

        i = j;

    }

    return s;

}
int main(){

    unordered_set<string>list;
    int n; cin >> n;
    for(int i = 0 ; i < n ;i++){
        string temp; cin >> temp;
        list.insert(temp);
    }

    string s;
    //cin >> s;
    getline(cin, s);

    

    cout << solve(s, list);
    //cout << s;

    return 0;
}