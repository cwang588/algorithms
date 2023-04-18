#include<bits/stdc++.h>
using namespace std;
char s[55][55],ss[55][55];
int N,M,n,m;
bool judge(int x,int y)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int xx=
		}
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>N>>M;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				cin>>s[i][j];
		cin>>n>>m;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>ss[i][j];
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(judge(i,j))
					++ans;
	}
	return 0;
}
