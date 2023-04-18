#include<bits/stdc++.h>
using namespace std;
struct p
{
	int a,b;
	long long c;
}pp[100005],yi[100005],ling[100005];
int num1,num2,num;
char t1[100005],t2[100005];
bool cmp(p x,p y)
{
	return x.c<y.c;
}
long long tot=0;
long long calc(int Num)
{
	long long totnow=tot,re=0;
	int sum=0;
	for(int i=num1;i>=1;--i)
	{
		if(yi[i].b==0)
		{
			totnow-=yi[i].c;
			re+=totnow;
		}
		else
		{
			++sum;
			if(sum<=Num)
			{
				totnow-=yi[i].c;
				re+=totnow;
			}
		}
	}
	sum=0;
	for(int i=1;i<=num2;++i)
	{
		if(!ling[i].a)
		{
			totnow+=ling[i].c;
			re+=totnow;
		}
		else
		{
			++sum;
			if(sum>num-Num)
			{
				totnow+=ling[i].c;
				re+=totnow;
			}
		}
	}
	return re;
}
bool ch[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&pp[i].c);
	cin>>t1;
	for(int i=0;i<n;++i)
		pp[i+1].a=(int)(t1[i]-'0');
	cin>>t2;
	for(int i=0;i<n;++i)
		pp[i+1].b=(int)(t2[i]-'0');
	for(int i=1;i<=n;++i)
	{
		tot+=(long long)pp[i].a*pp[i].c;
		if(pp[i].a==1)
		{
			++num1;
			yi[num1].a=pp[i].a;
			yi[num1].b=pp[i].b;
			yi[num1].c=pp[i].c;
			if(pp[i].b==1)
			{
				++num2;
				ling[num2].a=pp[i].a;
				ling[num2].b=pp[i].b;
				ling[num2].c=pp[i].c;	
				++num;
			}
		}
		else
		{
			if(pp[i].b==1)
			{
				++num2;
				ling[num2].a=pp[i].a;
				ling[num2].b=pp[i].b;
				ling[num2].c=pp[i].c;		
		
			}
		}
	}
	sort(yi+1,yi+1+num1,cmp);
	sort(ling+1,ling+1+num2,cmp);
	long long ans=9223372036854775807;
	for(int i=0;i<=num;++i)
		ans=min(ans,calc(i));
	printf("%lld",ans);
	return 0;
}
