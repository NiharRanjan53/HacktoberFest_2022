#include<bits/stdc++.h>
using namespace std;
int solve(int i, int j, int n, int m, vector<vector<int> > &dp)
{
    if (i == n && j == m)
    {
        return 0;
    }
    if (i > n || j > m)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = 1 + min(solve(i, j + i, n, m, dp), solve(i + j, j, n, m, dp));
}
int minSteps(int input1, int input2)
{
    vector<vector<int> > dp(input1 + 1, vector<int>(input2 + 1, -1));
    return solve(1, 1, input1, input2, dp);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int ans = minSteps(n, m);
    if (ans >= 1e9)
        cout << -1;
    else
        cout << ans;
    return 0;
}