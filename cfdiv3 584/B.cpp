#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
int sum[150005],a[150005],n;
int lowbit(int x)
{
	return x&(-x);
}
void add(int pos)
{
	while(pos<=n)
	{
		++sum[pos];
		pos+=lowbit(pos);
	}
}
long long query(int pos)
{
	long long re=0;
	while(pos)
	{
		re+=(long long)sum[pos];
		pos-=lowbit(pos);
	}
	return re;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		v.clear();
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			v.push_back(a[i]);
		}
		sort(v.begin(),v.end());
		int ans=0;
		for(int i=n;i>=1;--i)
		{
			int tep=getid(a[i]);
			if(query(tep-1))++ans;
			add(tep);
		}
		printf("%d\n",ans);
	}
	return 0;
}
