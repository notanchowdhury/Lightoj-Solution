#include<bits/stdc++.h>
using namespace std;
vector<pair <int,int> > vec[30001];
int vis[30001],dis[30001];
long long int bfs(int i)
{
    vis[i]=1;
    queue<int >q;
    q.push(i);
    while(!q.empty())
    {
        int frnt=q.front();
        q.pop();
        for(int j=0;j<vec[frnt].size();j++)
        {
            if(!vis[vec[frnt][j].first])
            {
                q.push(vec[frnt][j].first);
                vis[vec[frnt][j].first]=1;
                dis[vec[frnt][j].first]=dis[frnt]+vec[frnt][j].second;
               // cout<<dis[vec[frnt][j].first]<<endl;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int kase=1; kase<=t; kase++)
    {
        int n,u,v,w;
        cin>>n;
        long long int mx=0;
        //  for(int )
        memset(vis,0,sizeof(vis));
         memset(dis,0,sizeof(dis));
        for(int i=1; i<n; i++ )
        {
            cin>>u>>v>>w;
            vec[u].push_back({v,w});
            vec[v].push_back({u,w});
        }
        bfs(0);

       int max_size=0,runbfs=0;
       for(int i=0;i<n;i++)
       {
          // cout<<dis[i]<<"  +"<<endl;
           if(dis[i]>max_size)
           {
               max_size=dis[i];
               runbfs=i;
           }
       }
         memset(vis,0,sizeof(vis));
         memset(dis,0,sizeof(dis));
       //cout<<runbfs<<endl;
       bfs(runbfs);
       max_size=0,runbfs=0;
       for(int i=0;i<n;i++)
       {
          // cout<<dis[i]<<"  +"<<endl;
           if(dis[i]>max_size)
           {
               max_size=dis[i];
               //runbfs=i;
           }
       }

        cout<<"Case "<<kase<<": "<<max_size<<endl;
        for(int i=0; i<n; i++)
            vec[i].clear();
    }
}
