#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int Ne=115;
int N, K, dx, dy;   char chmp[4][Ne];   bool used[4][Ne];
struct node
{
    int x, y;
    node(int a=0, int b=0):x(a), y(b) {}
}u,v;
queue<node> qbfs;
bool bfs(int x, int y)
{
    while(!qbfs.empty())
	 qbfs.pop();
    qbfs.push(node(x, y));
    used[x][y]=true;
    while(!qbfs.empty())
    {
        u=qbfs.front();   qbfs.pop();
        if(u.y>=N) return true;
        ++u.y;
        if(chmp[u.x][u.y]=='.')
        {
            for(int i=-1; i<=1; i++)
            {
                v=node(u.x+i, u.y);
                if(v.x<1 || v.x>3) 
				continue;
                if(chmp[v.x][v.y]=='.'&&chmp[v.x][v.y+1]=='.'&& chmp[v.x][v.y+1+1]=='.' && !used[v.x][v.y+2])
                {
                    v.y=v.y+2;
                    used[v.x][v.y]=true;
                    qbfs.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>N>>K;
		memset(used, false, sizeof(used));
        for(int i=1; i<=3; i++)
        {
            scanf("%s", chmp[i]+1);
            if(chmp[i][1]=='s') 
			{ dx=i; dy=1; chmp[i][1]='.'; }
            chmp[i][N+1]=chmp[i][N+2]=chmp[i][N+3]='.';
        }
        bool ok=bfs(dx,dy);
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

