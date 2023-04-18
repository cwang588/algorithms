#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q1;
priority_queue <int,vector<int>,greater<int> > q2;
int main()
{
	int n,mid,s1=0,s2=0;
	scanf("%d",&n);
	scanf("%d",&mid);
	printf("%d\n",mid);
	for(int i=2;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t<mid)
		{
			++s1;
			q1.push(t);
		}
		else
		{
			++s2;
			q2.push(t);
		}
		if(s1-s2==2)
		{
			--s1;
			++s2;
			q2.push(mid);
			mid=q1.top();
			q1.pop();
		}
		if(s2-s1==2)
		{
			--s2;
			++s1;
			q1.push(mid);
			mid=q2.top();
			q2.pop();
		}
		if(i%2)
			printf("%d\n",mid);
	}
	return 0;
}
