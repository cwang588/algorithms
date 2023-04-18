#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100100
vector<int>ans[1],v[N];
int c[N],che=0;
int dfs(int s,int x)
{
	c[s]=x;//ans[x].push_back(s);
	for(auto p:v[s])
	{
		if(c[p]==x){
			return 1;
		}
		if(c[p]==-1){
			che=1;
//			x=(x+1)%2;
//			c[p]=x;
			if(dfs(p,!x)) return 1;
		}
	}
	if(che) ans[x].push_back(s);
	return 0;
}
int main()
{
	memset(c,-1,sizeof(c));
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(c[i]==-1){
			che=0;
			if(dfs(i,0))
			{
				printf("-1");
				return 0;
			}
		}
	}
	sort(ans[0].begin(),ans[0].end());
	sort(ans[1].begin(),ans[1].end());
	cout<<ans[0].size()<<endl;
	for(auto p:ans[0]) cout<<p<<" ";
	cout<<'\n'<<ans[1].size()<<endl;
	for(auto p:ans[1]) cout<<p<<" ";
	return 0;
}

