#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
struct Heap
{
	int a[maxn];
	int cnt=0;
	void insert(int x)
	{
		a[++cnt]=x;
		int now=cnt;
		while(now>1&&a[now]<a[now>>1])
		{
			swap(a[now>>1],a[now]);
			now>>=1;
		}
	}
	int top()
	{
		return a[1];
	}
	void clear()
	{
		cnt=0;
	}
	void pop()
	{
		int now=1;
		a[1]=a[cnt--];
		while(now*2<=cnt)
		{
			int t=now<<1;
			if(t+1<=cnt&&a[t+1]<a[t])++t;
			if(a[now]<=a[t])break;
			swap(a[now],a[t]);
			now=t;
		}
	}
}h;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		h.insert(t);
	}
	while(n--)printf("%d ",h.top()),h.pop();
	printf("\n");
	return 0;
}
