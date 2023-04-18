#include<bits/stdc++.h>
#include<stack>
#include<queue> 
using namespace std;
stack<int>s;
priority_queue<int>q2;
priority_queue<int,vector<int>,greater<int> >q1;
int main()
{
	int n,num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		string cz;
		cin>>cz;
		if(cz=="Pop")
		{
			if(!num)
				printf("Invalid\n");
			else
			{
				int mid=q1.top(),now=s.top();
				s.pop();-
				printf("%d\n",now);
				if(now<=mid)
				{
					q1.pop();
					--num;
					if(num%2)
					{
						q1.push(q2.top());
						q2.pop();
					}
				}
			}
		}
		else if(cz=="Push")
		{
			int t;
			scanf("%d",&t);
			++num;
			s.push(t);
			if(q1.empty())
			{
				q1.push(t);
				continue;
			}
			int mid=q1.top();
			if(t>mid)
			{
				if(num%2)
					q1.push(t);
				else
				{
					q2.push(q1.top());
					q1.pop();
					q1.push(t);
				}
			}
			else
			{
				if(num%2)
					q1.push(t);
				else
				{
					q2.push(q1.top());
					q1.pop();
					q1.push(t);
				}
			}
		}
		else
		{
			if(!num)
				printf("Invalid\n");
			else
				printf("%d\n",q1.top());
		}
	}
	return 0;
}
