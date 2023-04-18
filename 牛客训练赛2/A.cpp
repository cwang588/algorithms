#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int x[105],y[105];
long long s[200005];

long long ss(int xx1,int yy1,int xx2,int yy2,int xx3,int yy3)
{
	return (long long)abs(xx1*yy2+xx2*yy3+xx3*yy1-xx1*yy3-xx2*yy1-xx3*yy2);
}
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(s,0,sizeof(s));
		int n,k,cnt=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=j+1;k<=n;++k)
					s[++cnt]=ss(x[i],y[i],x[j],y[j],x[k],y[k]);		
		sort(s+1,s+1+cnt,cmp);
		if(s[k]%2)
			printf("%lld.50\n",s[k]/2);
		else
			printf("%lld.00\n",s[k]/2);
	}
	return 0;
}
