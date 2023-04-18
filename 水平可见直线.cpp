#include<cstdio>
#include<algorithm>
using namespace std;
int zhan[50005];
int top,now;
struct line
{
	long long k,b;
	int id;
}l[50005],Ans[50005];
bool cmp1(line x,line y)
{
	if(x.k!=y.k)
		return x.k>y.k;
	return x.b>y.b;
}
bool cmp2(line x,line y)
{
	return x.id<y.id;
}
bool judge(int p,int q)
{
	long long k1,k2,k3,b1,b2,b3;
	k1=l[p].k;b1=l[p].b;
	k2=l[zhan[q-1]].k;b2=l[zhan[q-1]].b;
	k3=l[zhan[q]].k;b3=l[zhan[q]].b;
	long long ans=k3*(b1-b2)-b1*k2+b2*k1+b3*(k2-k1);
	if(ans>=0)
		return true;
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&l[i].k,&l[i].b);
		l[i].id=i;
	}
	sort(l+1,l+1+n,cmp1);
	zhan[++top]=1;
	int sec=2;
	while(l[sec].k==l[1].k&&sec<=n)
		++sec;
	if(sec>n)
		return !printf("%d ",l[1].id);
	zhan[++top]=sec;
	now=sec+1;
	while(now<=n)
	{
		if(l[now].k==l[zhan[top]].k)
		{
			++now;
			continue;
		}
		while(judge(now,zhan[top])&&top>=2)
			--top;
		zhan[++top]=now++;
	}
	for(int i=1;i<=top;++i)
		Ans[i]=l[zhan[i]];
	sort(Ans+1,Ans+1+top,cmp2);
	for(int i=1;i<=top;++i)
		printf("%d ",Ans[i].id);
	return 0;
}
