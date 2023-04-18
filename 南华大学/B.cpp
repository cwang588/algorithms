#include<bits/stdc++.h>
using namespace std;
int father[100005];
string s[100005];
int fdj[100005];
int tong[100005];
int root[100005];
int find(int x)
{
    if(father[x]!=x)
        father[x]=find(father[x]);
    return father[x];
}
void unionn(int a,int b)
{
    father[b]=a;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        father[i]=i;
    for(int i=1;i<=m;++i)
    	cin>>fdj[i]>>s[i];
    for(int i=2;i<=m;++i)
	{
		if(s[i-1]==s[i])
		{
			int r1=find(fdj[i-1]),r2=find(fdj[i]);
			if(r1!=r2)
				unionn(r1,r2);
		}
	}
	for(int i=1;i<=n;++i)
	{
		root[i]=find(i);
		++tong[root[i]];
	}
	for(int i=1;i<=n;++i)
		printf("%d ",tong[root[i]]-1);
    return 0;
}
