#include<bits/stdc++.h>
using namespace std;
long long dp[100][100];
string s;
long long solve(int i,int j)
{
   // cout<<i<<" "<<j<<endl;
     if(i==j)
        return 1;
    if(i>j)
        return 0;
   //


    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==s[j])
    {
        return dp[i][j]=1+ solve(i+1,j)+solve(i,j-1);
    }
    else{
        return dp[i][j]= solve(i+1,j)+solve(i,j-1) -solve(i+1,j-1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
cin>>s;
int n=s.size()-1;
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",i,solve(0,n));
    }
}
