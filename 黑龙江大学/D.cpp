#include<cstdio>
#include<algorithm>
using namespace std;
int a[500005],c[500005];
const int N=1e5;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int num)
{
	while(x<=N)
	{
		c[x]+=num;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}
int main()
{
//	n=read();
//	m=read();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x+1,1);		
		add(y+1,-1);		
	}
	int ans=0;
	for(int i=1;i<=100000;++i)
		ans=max(ans,query(i+1));
	printf("%d",ans);
	return 0;
}
