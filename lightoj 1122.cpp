#include<bits/stdc++.h>
using namespace std;
int n,ar[100],p;
int cnt=0;
long long int dp[11][11];
long long int solve(int i,int value)
{
    long long int cnt=0;
    if(dp[i][value] != -1)
        return dp[i][value];
    if(i==n)
        return 1;

    for(int j=0;j<p;j++)
    {
        if(value==0 or (abs(value-ar[j])<=2))
        {
            cnt += solve(i+1,ar[j]);
        }
    }
    dp[i][value]=cnt;
    return dp[i][value];
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {

        cin>>p>>n;
        memset(dp,-1,sizeof(dp));
        for(int j=0;j<p;j++)
                cin>>ar[j];
        cout<<"Case "<<i<<": "<<solve(0,0)<<"\n";

    }
}
