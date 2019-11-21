#include<bits/stdc++.h>
using namespace std;
char ar[25][25];
int vis[25][25],n,m;
struct qu
{
    int row,col,time;

};
qu q[403];
int frnt=-1,rear=0;
void push(int r,int c,int t)
{
    qu p;
    p.row=r;
    p.col=c;
    p.time=t;

    q[++frnt]=p;
}
void pop()
{
    rear++;
}
qu frnts()
{
    return q[rear];
}
bool empt()
{
    if(rear>frnt)
        return true;
    return false;
}
void bfs(int row,int col,int as)
{
    push(row,col,as);
    vis[row][col]=as;
    while(!empt())
    {
        qu tp=frnts();
        pop();
        row=tp.row;
        col=tp.col;
        int  asche=tp.time;
        if(row+1<m)
        {
            if(ar[row+1][col] !='#' && ar[row+1][col] !='m' && vis[row+1][col]==-1)
            {
                vis[row+1][col]=asche+1;
                push(row+1,col,asche+1);
            }
        }
        if(row-1>=0)
        {
            if(ar[row-1][col] !='#' && ar[row-1][col] !='m' && vis[row-1][col]==-1)
            {
                vis[row-1][col]=asche+1;
                push(row-1,col,asche+1);
            }
        }
        if(col+1<n)
        {
            if(ar[row][col+1] !='#' && ar[row][col+1] !='m' && vis[row][col+1]==-1)
            {
                vis[row][col+1]=asche+1;
                push(row,col+1,asche+1);
            }
        }
        if(col-1>=0)
        {
            if(ar[row][col-1] !='#' && ar[row][col-1] !='m' && vis[row][col-1]==-1)
            {
                vis[row][col-1]=asche+1;
                push(row,col-1,asche+1);
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;

    for(int kase=1; kase<=t; kase++)
    {
        //char ch;
       cin>>m>>n;


        qu blossom,bubbles,buttercup,home;
        for(int i=0; i<m; i++)
        {

            for(int j=0; j<n; j++)
            {
            cin>>ar[i][j];

                if(ar[i][j]=='a')
                {
                    blossom.row=i;
                    blossom.col=j;
                    blossom.time=0;
                }
                if(ar[i][j]=='b')
                {
                    bubbles.row=i;
                    bubbles.col=j;
                    bubbles.time=0;
                }
                if(ar[i][j]=='c')
                {
                    buttercup.row=i;
                    buttercup.col=j;
                    buttercup.time=0;
                }
                if(ar[i][j]=='h')
                {
                    home.row=i;
                    home.col=j;
                    //  buttercup.time=0;
                }
                vis[i][j]=-1;
            }
        }

        int ans=-1;
        bfs(blossom.row,blossom.col,blossom.time);
        int tmp=vis[home.row][home.col];
        ans=max(ans,tmp);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                vis[i][j]=-1;
                frnt=-1;rear=0;
            }
        }
        bfs(bubbles.row,bubbles.col,bubbles.time);
      tmp=vis[home.row][home.col];
        ans=max(ans,tmp);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                vis[i][j]=-1;
                frnt=-1;rear=0;
            }
        }
        bfs(buttercup.row,buttercup.col,buttercup.time);
      tmp=vis[home.row][home.col];
        ans=max(ans,tmp);
        printf("Case %d: %d\n",kase,ans);
    }

}
