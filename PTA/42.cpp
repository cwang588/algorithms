#include<cstdio>
#include<algorithm>
using namespace std;
struct human
{
	int id,tot,num;
}h[10005];
bool cmp(human a,human b)
{
	if(a.tot!=b.tot)
		return a.tot>b.tot;
	if(a.num!=b.num)
		return a.num>b.num;
	return a.id<b.id;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		h[i].id=i;
		int num,sum=0;
		scanf("%d",&num);
		for(int j=1;j<=num;++j)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			sum+=b;
			h[a].tot+=b;
			++h[a].num;
		}
		h[i].tot-=sum;
	}
	sort(h+1,h+1+n,cmp);
	for(int i=1;i<=n;++i)
		printf("%d %.2lf\n",h[i].id,(double)(h[i].tot)/100.0);
	return 0;
}
