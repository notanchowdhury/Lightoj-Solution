#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v[30001];

int vis[30005],ans[30005];
int prv[30005],prv2[30005];
int costfornodes[30001],costfornodes2[30001],costfornodes3[30001];
void bfs(int start)
{
    queue<int>q;
    vis[start]=1;
    costfornodes[start]=0;
    prv[start]=start;

    q.push(start);
    while(!q.empty())
    {
        int tp=q.front();
        q.pop();
        for(int i=0;i<v[tp].size();i++)
        {
            if(!vis[v[tp][i].first])
            {
                vis[v[tp][i].first]=1;
                q.push(v[tp][i].first);
                costfornodes[v[tp][i].first]=costfornodes[tp]+v[tp][i].second;
             //   prv2[v[tp][i].first]=v[tp][i].second;
             //   prv[v[tp][i].first]=tp;
              //  cout<<v[tp][i].first<< " "<< prv2[v[tp][i].first]<<" "<<prv[v[tp][i].first]<<endl;
             //   cout<<"____"<<costfornodes[v[tp][i].first]<<endl;
            }

        }
    }
}

void bfs2(int start)
{
    queue<int>q;
    vis[start]=1;
    costfornodes2[start]=0;
    prv[start]=start;

    q.push(start);
    while(!q.empty())
    {
        int tp=q.front();
        q.pop();
        for(int i=0;i<v[tp].size();i++)
        {
            if(!vis[v[tp][i].first])
            {
                vis[v[tp][i].first]=1;
                q.push(v[tp][i].first);
                costfornodes2[v[tp][i].first]=costfornodes2[tp]+v[tp][i].second;

            }

        }
    }
}

void bfs3(int start)
{
    queue<int>q;
    vis[start]=1;
    costfornodes3[start]=0;
    prv[start]=start;

    q.push(start);
    while(!q.empty())
    {
        int tp=q.front();
        q.pop();
        for(int i=0;i<v[tp].size();i++)
        {
            if(!vis[v[tp][i].first])
            {
                vis[v[tp][i].first]=1;
                q.push(v[tp][i].first);
                costfornodes3[v[tp][i].first]=costfornodes3[tp]+v[tp][i].second;

            }

        }
    }
}

int main()
{
  // freopen("1387.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tcase;
    cin>>tcase;
    for(int t=1; t<=tcase; t++)
    {
        int u,vv,w;
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>u>>vv>>w;
            v[u].push_back({vv,w} );
            v[vv].push_back({u,w} );
        }
//        for(int p=0;p<=n;p++)
//        vis[p]=0;
       memset(vis,0,sizeof(vis));

      //memset(costfornodes,0,sizeof(costfornodes));
     // memset(prv,0,sizeof(prv));  memset(prv2,0,sizeof(prv2));
        bfs(0);
        int ok,mx=-1;
        for(int i=0;i<n;i++)
        {
            if(costfornodes[i]>mx)
            {
                mx=costfornodes[i];
                ok=i;
            }
        }
       // cout<<ok<<" "<<mx<<endl;
//     for(int p=0;p<=n;p++)
//        vis[p]=0;
       memset(vis,0,sizeof(vis));

      //memset(costfornodes,0,sizeof(costfornodes));
      //memset(prv,0,sizeof(prv));  memset(prv2,0,sizeof(prv2));

      bfs2(ok);
      // for(int p=0;p<=n;p++)
       // vis[p]=0;
       memset(vis,0,sizeof(vis));
       mx=-1;
        for(int i=0;i<n;i++)
        {
            if(costfornodes2[i]>mx)
            {
                mx=costfornodes2[i];
                ok=i;
            }
        }
        bfs3(ok);
    for(int p=0;p<n;p++)
        ans[p]=max(costfornodes2[p],costfornodes3[p]);


    printf("Case %d:\n",t);

        for(int i=0;i<n;i++)
           printf("%d\n",ans[i]),v[i].clear();
//      for(int p=0;p<=n;p++)
//        vis[p]=0;
       memset(vis,0,sizeof(vis));


    }
}
