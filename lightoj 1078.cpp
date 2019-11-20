#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    long long int n,m,ans,num;
    for(int tcase=1;tcase<=t;tcase++)
    {
        scanf("%lld %lld",&n,&m);
        num=0;
        num=num*10+m;
        ans=1;
     //  cout<<(1%2)<<endl;
        while((num%n)!=0)
        {
            num=(num*10+m)%n;
            //cout<<num<<endl;
            ans++;
        }
        printf("Case %d: %lld\n",tcase,ans);
    }
}
