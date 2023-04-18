#include<bits/stdc++.h>
using namespace std;
set<int>s1,s2;
map<int,int>m;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		s2.insert(t);
		s1.insert(t);
		++m[t];
		int now=t;
		while(m[now]==2&&now>0)
		{
			m[now]=0;
			++m[now-1];
			s1.erase(now);
			if(now-1)
				s1.insert(now-1);
			--now;
		}
		if(s1.empty())
		{
			printf("preassigned\n");
			continue;
		}
		set<int>::iterator it=s1.begin();
		int tt=*it;
		printf("%d\n",*s2.lower_bound(tt));
	}
	return 0;
}
