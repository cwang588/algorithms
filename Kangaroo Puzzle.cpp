#include<bits/stdc++.h>
using namespace std;
char a[22][22];
int n,m;
int Move[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
char doit[4]={'D','R','L','U'};
bool usd[25][25];
int cnt;
void dfs(int x,int y)
{
    usd[x][y]=true;
    for(int i=0;i<4;++i)
    {
        int xx=x+Move[i][0],yy=y+Move[i][1];
        if(xx>0&&yy>0&&xx<=n&&yy<=m&&!usd[xx][yy]&&a[xx][yy]=='1')
        {
            cout<<doit[i];
            ++cnt;
            if(cnt>=50000)exit(0);
            dfs(xx,yy);
            cout<<doit[3-i];
            ++cnt;
            if(cnt>=50000)exit(0);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(;;)
    {
        memset(usd,0,sizeof(usd));
        for(int i=1;i<=n;++i)
        {
            bool ky=false;
            for(int j=1;j<=m;++j)
                if(a[i][j]=='1')
                {
                    dfs(i,j);
                    ky=true;
                    break;
                }
            if(ky)break;
        }
        
    }
  //  system("pause");
    return 0;
}
