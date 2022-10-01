#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
   string str="hello";
   reverse(str.begin(),str.end());
   
   cout<<str;
}


//2nd method - Reverse string using stack

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string str;
    cin>>str;
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        s.push(ch);
}

    string ans="";
    while(!s.empty()){
        char ch= s.top();
        ans.push_back(ch);

        s.pop();
}
    cout<<ans;
    return 0;
}
