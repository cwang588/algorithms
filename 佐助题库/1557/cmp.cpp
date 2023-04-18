#include<bits/stdc++.h>
using namespace std;
int a[35][35],n;
int mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool usd[35][35];
void bfs(int x,int y)
{
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	usd[x][y]=true;
	while(!q.empty())
	{
		int nowx=q.front().first,nowy=q.front().second;
		q.pop();
		for(int i=0;i<4;++i)
		{
			int tox=nowx+mov[i][0],toy=nowy+mov[i][1];
			if(tox<=0||tox>n||toy<=0||toy>n||usd[tox][toy]||a[tox][toy]==1)continue;
			usd[tox][toy]=true;
			q.push(make_pair(tox,toy));
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	for(int i=1;i<=n;++i)
		if(!usd[i][1])
			bfs(i,1);
	for(int i=1;i<=n;++i)
		if(!usd[1][i])
			bfs(1,i);
	for(int i=1;i<=n;++i)
		if(!usd[i][n])
			bfs(i,n);
	for(int i=1;i<=n;++i)
		if(!usd[n][i])
			bfs(n,i);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(a[i][j])cout<<"1 ";
			else
			{
				if(!usd[i][j])cout<<"2 ";
				else cout<<"0 ";
			}
		}
		cout<<"\n";
	}
	return 0;	
}

