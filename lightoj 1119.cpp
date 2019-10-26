#include<bits/stdc++.h>
using namespace std;
int ar[15][15];
int dp[(1<<15)+2],n;
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}
int check (int N,int pos)
{
    return N=(N &(1<<pos));
}

int Bitmask(int mask)
{
    if(mask==(1<<n)-1)
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    int mn=1<<28;
    int price,ret;

    for(int i=0; i<n; i++)
    {
      if(check(mask,i)==0)
      {
          price=ar[i][i];
          for(int j=0;j<n;j++)
          {
              if(i!=j && (check(mask,j))!=0)
              {
                  price+=ar[i][j];
              }
          }
            ret=price+Bitmask(Set(mask,i));
             mn=min(ret,mn);
      }
    }
    return dp[mask]=mn;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {

        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                cin>>ar[j][k];
            }
        }
        cout<<"Case "<<i<<": "<<Bitmask(0)<<"\n";
    }

}
