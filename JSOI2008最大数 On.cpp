#include<bits/stdc++.h>
using namespace std;
stack<int>s1;
stack<long long>s2;
int fa[200005];
long long a[200005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
int main()
{
	ios::sync_with_stdio(false);
	int m,num=0;
	long long t=0,d;
	cin>>m>>d;
	for(int i=1;i<=m;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		char tmp;
		cin>>tmp;
		if(tmp=='A')
		{
			++num;
			long long sum;
			cin>>sum;
			sum=(sum+t)%d;
			while((!s1.empty())&&sum>=s1.top())
			{
				fa[s2.top()]=num;
				s1.pop();
				s2.pop();
			}
			s1.push(sum);
			s2.push(num);
			a[num]=sum;
		}
		else
		{
			int len;
			cin>>len;
			t=a[getfa(num-len+1)];
			printf("%lld\n",t);
		}
	}
	return 0;
}
