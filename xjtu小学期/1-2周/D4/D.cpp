#include<bits/stdc++.h>
using namespace std;
bool mapx[2005][2005];
int vis[2002][2005][3];
int m,n,sx,sy,wayx[4]={0,-1,0,1},wayy[4]={-1,0,1,0},ans=0;
void dfs(int x,int y,int posx,int posy)
{
    if (vis[posx][posy][2] && (vis[posx][posy][0]!=x || vis[posx][posy][1]!=y))
    {
        ans=1;
        return;
    }
    if (vis[posx][posy][2] && vis[posx][posy][0]==x && vis[posx][posy][1]==y) return;
    {
		vis[posx][posy][0]=x;
		vis[posx][posy][1]=y;
		vis[posx][posy][2]=1;
	}
    int tox,toy;
    for (int w=0;w<=3;w++)
    {
        tox=(posx+wayx[w]+n)%n;
		toy=(posy+wayy[w]+m)%m;    
        if(mapx[tox][toy])
			dfs(x+wayx[w],y+wayy[w],tox,toy);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    char ch;
    cin>>n>>m;
    memset(mapx,false,sizeof(mapx));
	memset(vis,false,sizeof(vis));
    ans=0;
    for(int i=0;i<n;i++)
    {    
        for (int j=0;j<m;j++)
        {
            cin>>ch;
            if (ch=='.') mapx[i][j]=true;
            else if(ch=='S')
            {
                sx=i;
				sy=j;
                mapx[i][j]=true; 
            }
        }
    }
    dfs(sx,sy,sx,sy);
    if(ans)
		printf("Yes\n");
    else
		printf("No\n");
    return 0;
}
