#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<char[4]>s;
char a[1005][4];
struct dz
{
	char name[4];
	int time;
}d[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		char t[4];
		cin>>t;
		s.insert(t);
	}
	int m,tot=0;
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		cin>>d[i].name>>d[i].time;
		tot+=d[i].time;
	}
	int ans=0;
	for(int i=1;i<=m;++i)
		if(s.find(d[i].name)==s.end()&&d[i].time*n>tot)
		{
			++ans;
			for(int j=0;j<4;++j)
				a[ans][j]=d[i].name[j];
			for(int j=0;j<4;++j)
				cout<<a[ans][j];			
		}
	for(int i=1;i<=ans;++i)
		for(int j=0;j<4;++j)
			cout<<a[i][j];	
	if(!ans)
		return !printf("Bing Mei You\n");
	sort(a+1,a+1+ans);
	for(int i=1;i<=ans;++i)
	{
		for(int j=0;j<4;++j)
			cout<<a[i][j];
		printf("\n");
	}
	return 0;
}
