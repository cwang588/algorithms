#include<bits/stdc++.h>
using namespace std;
set<int>s;
bool usd[705][705];
int getid(int x,int y)
{
	return (x-1)*665+y;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int maxnum=0,maxtime=0,num=0;
		memset(usd,0,sizeof(usd));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				int nowx=i+330,nowy=j+330;
				char t;
				cin>>t;
				if(t=='#')
				{
					int now=getid(nowx,nowy);
					s.insert(now);
					usd[nowx][nowy]=true;
					++num;
				} 
			}
		maxnum=num;
		for(int i=1;i<=321;++i)
		{
			auto it=s.begin();
			while(it!=s.end())
			{
				int now=*it;
				
			}
		}
	}
	return 0;
}
