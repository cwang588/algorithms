#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct code
{
	int l;
	string s;
}mima[105];
string ss;
bool cmp(code a,code b)
{
	return a.l<b.l;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		cin>>mima[i].s;
		mima[i].l=mima[i].s.size();
	}
	cin>>ss;
	sort(mima+1,mima+1+n,cmp);
	int num1=0,num2=0;
	for(int i=1;i<=n+1;++i)
	{
		if(!num1&&mima[i].l==ss.size())
			num1=i;
		if(mima[i-1].l==ss.size())
			num2=i;		
	}
	--num2;
	int fa1,fa2;
	fa1=num1/k;
	fa2=num2/k;
	if(num1%k==0)
		--fa1;
	if(num2%k==0)
		--fa2;
	printf("%d %d",num1+5*fa1,num2+5*fa2);
	return 0;
}
