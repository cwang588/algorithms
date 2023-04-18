#include<cstdio>
#include<algorithm>
using namespace std;
long long t[10005][15];
long long gg[15],s[4][4];
struct point
{
	long long zb[15],dis;
}p[10005];
bool cmp(point x,point y)
{
	return x.dis<y.dis;
}
long long d(int x,int y,int k)
{
	long long ans=0;
	for(int i=1;i<=k;++i)
		ans+=(p[x].zb[i]-p[y].zb[i])*(p[x].zb[i]-p[y].zb[i]);
	return ans;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{	
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=k;++j)
			{
				scanf("%lld",&p[i].zb[j]);
				t[i][j]=p[i].zb[j]*n;
				gg[j]+=p[i].zb[j];
			}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=k;++j)
				p[i].dis+=(gg[j]-t[i][j])*(gg[j]-t[i][j]);
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
				if(i!=j)
					s[i][j]=d(i,j,k);
		if(s[1][2]+s[1][3]<s[2][3])
		{
			printf("1\n");
			for(int i=1;i<=k;++i)
				printf("%lld ",p[1].zb[i]);
			return 0;
		}
		if(s[1][2]+s[2][3]<s[1][3])
		{
			printf("1\n");
			for(int i=1;i<=k;++i)
				printf("%lld ",p[2].zb[i]);
			return 0;
		}
		if(s[1][3]+s[2][3]<s[1][2])
		{
			printf("1\n");
			for(int i=1;i<=k;++i)
				printf("%lld ",p[3].zb[i]);
				return 0;
		}
		printf("0");
	}
	return 0;
}
