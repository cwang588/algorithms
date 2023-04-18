#include<bits/stdc++.h>
using namespace std;
long long a[100005],t[100005];
long long tot;
void print()
{
	if(tot%2==0)cout<<tot/2<<"\n";
	else
	{
		if(tot>0)cout<<(tot+1)/2<<"\n";
		else cout<<-((abs(tot)-1)/2)<<"\n";
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	for(int i=1;i<=n;++i)t[i]=a[i]-a[i-1];
	tot=a[1];
	for(int i=2;i<=n;++i)tot+=max(t[i],0ll);
	print();
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		int l,r;
		long long x;
		scanf("%d%d%I64d",&l,&r,&x);
		if(l==1)tot+=x;
		else
		{
			if(t[l]>0)tot-=t[l];
			t[l]+=x;
			if(t[l]>0)tot+=t[l];
		}
		if(r==n);
		else 
		{
			if(t[r+1]>0)tot-=t[r+1];
			t[r+1]-=x;
			if(t[r+1]>0)tot+=t[r+1];
		}
		print();
	}
	return 0;
}
