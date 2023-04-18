#include<cstdio>
#include<algorithm>
using namespace std;
struct kao
{
	int a,b;
}k[100005];
bool cmp(kao x,kao y)
{
	return x.b<y.b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&k[i].a);
	for(int i=1;i<=n;++i)
		scanf("%d",&k[i].b);
	sort(k+1,k+1+n,cmp);
	long long re=k[1].b;
	for(int i=1;i<=n;++i)
	{
		if(re<k[i].a)
			return !printf("NO");
		re-=k[i].a;
		re+=k[i+1].b-k[i].b-2;
	}
	printf("YES");
	return 0;
}
