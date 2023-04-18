#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,value;
}e[100005];
int cnt;
bool cmp(edge x,edge y)
{
	return x.value<y.value;
}
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int fa[100005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	fa[x]=y;
}
int ans[505];
void work(int n)
{
	cnt=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			e[++cnt]={i,j,(i+1)*(j+1)/gcd(i+1,j+1)};
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(e+1,e+1+cnt,cmp);
	int tot=0,num=0;
	for(int i=1;i<=cnt;++i)
	{
		int r1=getfa(e[i].from),r2=getfa(e[i].to);
		if(r1!=r2)
		{
			tot+=e[i].value;
			Merge(r1,r2);
			++num; 
		}
		if(num==n-1)
		{
			printf("%d:%d\n",n,tot);
			ans[n]=tot;
			return;
		}
	}
}
int main()
{
	for(int i=2;i<=50;++i)
		work(i);
	//for(int i=3;i<=50;++i)printf("%d\n",ans[i]-ans[i-1]);
	return 0;
}
