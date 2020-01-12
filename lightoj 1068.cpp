#include<bits/stdc++.h>
#define ll  long long
using namespace std;


ll a,b,k,n;
ll dp[10][3][82][82];

template <typename T>

string to_string(T p)
{
    stringstream num;
    num << p;
    return num.str();
}


ll solve(string &s,ll idx, ll small,ll sumofdigit,ll ans)
{
    ll limit;
    if(idx>=s.size())
    {
        ll  sumDig=sumofdigit%k;
        ll   modans=ans%k;
        if(sumDig ==0 && modans ==0){
            return 1;
        }
        else return 0;
    }
    if(dp[idx][small][sumofdigit][ans]!=-1)
        return dp[idx][small][sumofdigit][ans];
    limit=9;
    ll sum=0;
    if(small)
    {
        limit=s[idx]-'0';
    }
    for(int i=0;i<=limit;i++)
    {
        ll pass=0;
        if(i<s[idx]-'0')
        {
            pass =0;
        }
        else
        {
            pass =small;
        }


        sum+=solve(s,idx+1,pass,((sumofdigit+i)%k),((ans*10)+i)%k);
    }
    dp[idx][small][sumofdigit][ans]=sum;
    return dp[idx][small][sumofdigit][ans];

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int tcase;
    cin>>tcase;
    for(int t=1;t<=tcase;t++)
    {
        cin>>a>>b>>k;

        string a1=to_string(a-1);
        string b1=to_string(b);
        cout<<"Case "<<t<<": ";
        if(k==1)
            cout<<(b-a+1)<<endl;
        else if(k>81)
        {
            cout<<0<<endl;
        }
        else
        {
              memset(dp,-1,sizeof(dp));
              ll p=solve(a1,0,1,0,0);
                memset(dp,-1,sizeof(dp));
              ll q=solve(b1,0,1,0,0);
              cout<<q-p<<endl;
        }

    }
}
