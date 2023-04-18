#include<bits/stdc++.h>
using namespace std;
vector<int>v[10050];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;++i)
	{
		//for(auto x=v[i].begin();x!=v[i].end();++x)
//		{
//			cout<<*x;
//			if(x+1!=v[i].end())cout<<' ';
//		}
		for(int j=0;j<v[i].size();++j)
		{
			cout<<v[i][j];
			if(j!=v[i].size()-1)cout<<' ';
		}
		cout<<"\n";
	}
	return 0;
}
