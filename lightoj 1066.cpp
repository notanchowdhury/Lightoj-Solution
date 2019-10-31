#include<bits/stdc++.h>
using namespace std;
int X[5]= {1,0,-1,0};
int Y[5]= {0,1,0,-1};
struct Pair
{
    int x,y,time;
    Pair(int x,int y,int time)
    {
        this->x=x;
        this->y=y;
        this->time=time;
    }
    Pair() {}
};
char last;
int vis[18][19];
int indx=0,bgin,n;
Pair st[100];

char str[30][30];
void Push(Pair a)
{
    st[indx] = a;
    indx++;
}
Pair Front()
{

    return st[bgin];

}
void Pop()
{
    bgin++;
}

int bfs(Pair p,char des)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            vis[i][j]=0;
    if(des==last+1)
        return p.time;
    bgin=0;
    indx=0;
    Push(p);
    while(bgin<indx)
    {
        Pair frnt=Front();
        Pop();
        for(int i=0; i<4; i++)
        {
            int x=frnt.x+ X[i];
            int y=frnt.y+Y[i];
            if(x>=n || y>=n ||x<=-1 || y<=-1)
                continue;
            if(str[x][y]==des)
            {

                return bfs(Pair(x,y,frnt.time+1),des+1);
            }

            if((vis[x][y]==0 && str[x][y]=='.') || (vis[x][y]==0 && str[x][y]>='A' && str[x][y]<='Z' && str[x][y]<=des))
            {
                Push(Pair(x,y,frnt.time+1));
                vis[x][y]=1;
            }
        }
    }
    return -1;
}

int main()
{
   // freopen("1004.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;

    for(int i=1; i<=t; i++)
    {

        indx=0;
        bgin=0;
        cin>>n;

        last='A';
        Pair haha;
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                cin>>str[j][k];
                ///cout<<str[j][k];

                if(str[j][k]>='A' && str[j][k]<='Z')
                {
                    if(str[j][k]=='A')
                    {
                        haha.x=j;
                        haha.y=k;
                        haha.time=0;
                    }
                    else
                        last=max(last,str[j][k]);
                }
            }
          //  cout<<endl;
        }
        cout<<"Case "<<i<<": ";
        int ans=bfs(haha,'B');
        if(ans==-1)
            cout<<"Impossible"<<endl;
        else
            cout<<ans<<endl;



    }
}
