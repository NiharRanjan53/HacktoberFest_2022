#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
       long long flag=1;
        long long y =x;
        if(y<0)
        {
            flag=-1;
            y*=-1;
        }

        long long c=0;
        while(y>0)
        {
            if(c*10 >INT_MAX)
            return 0;
            c*=10;
            c+=(y%10);
            y/=10;
        }
        return flag*c;
}
int main()
{
  int n;
  cin>>n;
  cout<<reverse(n);
  return 0;
}

