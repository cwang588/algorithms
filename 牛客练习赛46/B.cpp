#include<bits/stdc++.h>
using namespace std;
map<string,int>mm;
int fa[20005];
int getfa(int x)
{
	if(fa[x]==x)return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void unionn(int a,int b)
{
	fa[b]=a;
}
int main()
{
	int n,m; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		if(!mm[s])mm[s]=i;
	}
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int opt;
		scanf("%d",&opt);
		string a,b;
		cin>>a>>b;
		int r1=getfa(mm[a]),r2=getfa(mm[b]);
		if(opt==1)
			unionn(r1,r2);
		else
		{
			if(r1==r2)printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
