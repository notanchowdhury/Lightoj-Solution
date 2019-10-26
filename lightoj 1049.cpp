#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tcase;
    cin>>tcase;
    for(int i=1;i<=tcase;i++)
    {
        int n,a,b,c,ar[105][105],keep[105][3],vis[105];

        cin>>n;

         for(int j=1;j<=n;j++)
        {
            keep[j][0]=0;
            vis[j]=0;
            for(int k=1;k<=n;k++)
            {
                ar[j][k]=0;
            }
        }
        for(int j=0;j<n;j++)
        {
            cin>>a>>b>>c;
            ar[a][b]=0;
            ar[b][a]=c;
            keep[a][keep[a][0]+1]=b;
           // cout<<a<< " "<<keep[a][0]+1<<" "<<b<<endl;
            keep[a][0]+=1;

             keep[b][keep[b][0]+1]=a;
             //  cout<<b<< " "<<keep[b][0]+1<<" "<<a<<endl;
            keep[b][0]+=1;

        }
        int cnt=1,first=1,imcur,last,cur=1,cst=0,revcst=0;
      while(cnt<n)
      {
          vis[cur]=1;
          if(vis[keep[cur][1]]==0)
          {
              imcur=keep[cur][1];
              cnt++;
              cst+=ar[cur][imcur];
              vis[imcur]=1;
              cur=imcur;

          }
          else
          {
              imcur=keep[cur][2];
              cnt++;
              cst+=ar[cur][imcur];
              vis[imcur]=1;
              cur=imcur;

          }
      }
      cst+=ar[cur][1];
      cnt=1;
      for(int p=1;p<=n;p++)vis[p]=0;
      cur = 1;
       while(cnt<n)
      {
          vis[cur]=1;
          if(vis[keep[cur][2]]==0)
          {
              imcur=keep[cur][2];
              cnt++;
              revcst+=ar[cur][imcur];
              vis[imcur]=1;
              cur=imcur;

          }
          else
          {
              imcur=keep[cur][1];
              cnt++;
              revcst+=ar[cur][imcur];
              vis[imcur]=1;
              cur=imcur;

          }

      }
      revcst+=ar[cur][1];
      cout<<"Case "<<i<<": ";
      cout<<min(cst,revcst)<<endl;
    }
}
