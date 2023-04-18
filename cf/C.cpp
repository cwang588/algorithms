#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct shu
{
	long long a;
	int id;
}s[200005];
long long ans[200005];
long long num=0;
bool cmp(shu x,shu y)
{
	return x.a<y.a;
}
int main()
{
	long long sum=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>s[i].a;
		sum+=(long long)s[i].a;
		s[i].id=i;
	}
	sort(s+1,s+1+n,cmp);
	if(s[n].a+s[n-1].a*2==sum)
		ans[++num]=s[n].id;
	sum-=s[n].a;
	for(int i=1;i<n;++i)
	{
		if(s[i].a+s[n].a==sum)
			ans[++num]=s[i].id;
	}
	cout<<num<<endl;
	for(int i=1;i<=num;++i)
		cout<<ans[i]<<' ';
	return 0;
}
