#include<bits/stdc++.h>
using namespace std;
struct ice
{
	long long a,b,c;
}cream[200005];
bool cmp(ice x,ice y)
{
	return x.c<y.c;
}
int main()
{
	int n;
	long long ans=0,k,tot=0;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>cream[i].a>>cream[i].b>>cream[i].c;
		ans+=cream[i].a*cream[i].c;
		tot+=cream[i].a;
	}
	sort(cream+1,cream+1+n,cmp);
	if(tot>k)return !printf("-1\n"); 
	for(int i=1;i<=n;++i)
	{
		if(k-tot>cream[i].b-cream[i].a)
		{
			ans+=cream[i].c*(cream[i].b-cream[i].a);
			tot+=cream[i].b-cream[i].a;
		}
		else
		{
			ans+=cream[i].c*(k-tot);
			tot=k;
			break;
		}
	}
	if(tot<k)
		printf("-1\n");
	else
		printf("%lld\n",ans);
	return 0;
}
