#include<cstdio>
#include<algorithm>
using namespace std;
int k[50005],p[50005],x[50005],mm[50005];
bool usd[50005];
struct c
{
	int num,id;
}cha[50005];
bool cmp(c a,c b)
{
	return a.num>b.num;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&k[i],&p[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		int tot=0,M=-1;
		for(int j=1;j<=i;++j)
		{
			if(k[j]==x[i])
				tot+=p[j];
			M=max(M,p[j]);
		}
		mm[i]=max(tot,M);
		sum+=mm[i];
		cha[i].num=mm[i]-mm[i-1];
		cha[i].id=i;
	}
	cha[1].num=-9999999;
	sort(cha+1,cha+1+n,cmp);
	int t=0,now=1;
	while(t<m&&cha[now].num>0)
	{
		if(!usd[cha[now].id-1]&&!usd[cha[now].id+1])
		{	
			sum+=cha[now].num;
			++t;	
			usd[cha[now].id]=true;
		}
		++now;
	}
	printf("%d",sum); 
	return 0;
}
