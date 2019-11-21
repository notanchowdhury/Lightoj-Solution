#include<bits/stdc++.h>
using namespace std;
double dp[110];
int gold[101];
int n;
double f(int u)
{
    //cout<<"s"<<endl;
    if(u>=n) return 0.0;
    if(dp[u]>-1)
        return dp[u];
    int total=min(6,n-u-1);
    double ret=0.0;
    if(total>0)
    {
        for(int i=1; i<=total; i++)
        {
            ret+=f(u+i);

        }
        ret /= (double)total;
    }

    dp[u]=gold[u]+ret;
   // cout<<u<<" "<<ret<<" "<<dp[u]<<endl;
    return dp[u];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;

    for(int kase=1; kase<=t; kase++)
    {
        //char ch;
        cin>>n;


        for(int j=0; j<n; j++)
            cin>>gold[j];
        memset(dp,-1.0,sizeof(dp));
        printf("Case %d: %.8f\n",kase,f(0));

    }

}

