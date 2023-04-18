#include<bits/stdc++.h>
using namespace std;
multiset<int>s;
struct meeting
{
	int l,r;
}m[100005];
bool cmp(meeting a,meeting b)
{
	return a.r==b.r?a.l>b.l:a.r>b.r;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&m[i].l,&m[i].r);
	sort(m+1,m+1+n,cmp);
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		auto it=s.lower_bound(m[i].r);
		if(it==s.end())
		{
			++cnt;
			s.insert(m[i].l);
		}
		else 
		{
			int tmp=*it;
			s.erase(tmp);
			s.insert(m[i].l);
		}
	}
	printf("%d\n",cnt);
	s.clear();
	return 0;
}
