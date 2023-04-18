#include<bits/stdc++.h>
using namespace std;
struct music
{
	int sum,id;
}a[400005];
bool cmp(music x,music y)
{
	return x.sum<y.sum;
}
int mpow(int a,int b)
{
	int re=1;
	for(int i=1;i<=b;++i)
		re*=a;
	return re;
}
int s[400005];
int main()
{
	int n,I;
	scanf("%d%d",&n,&I);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i].sum);
	if(I*8/n>29)
		return !printf("0");
	sort(a+1,a+1+n,cmp);
	int now=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i].sum!=a[i-1].sum)
			++now;
		a[i].id=now;
		++s[now];
	}
	for(int i=1;i<=n;++i)
		s[i]+=s[i-1];
	int tot=mpow(2,I*8/n);
	int ans=999999999;
	for(int i=1;i<=n;++i)
		ans=min(ans,n-s[min(n,i+tot-1)]+s[i-1]);
	printf("%d",ans);
	return 0;
}
