#include<cstdio>
#include<set>
using namespace std;
set<int>s[55];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j)
		{
			int t;
			scanf("%d",&t);
			s[i].insert(t);
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int s1=s[x].size(),s2=s[y].size();
		set<int>::iterator r;
		int ans=0;
		for(r=s[x].begin();r!=s[x].end();++r)
		{
			if(s[y].find(*r)!=s[y].end())
				++ans;
		}
		printf("%.2lf%%\n",(double)ans/(double)(s1+s2-ans)*100.0);
	}
	return 0;
}
