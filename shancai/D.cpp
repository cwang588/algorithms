#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
	int from,to,next;
}e[1001005];
int f[1001005],d[1001005];
bool usd[1001005];
struct Q
{
    int l,r,a[1001005];
    void push(int x)
	{
        this->a[++r] = x;
    }
    int front()
	{
        return a[l];
    }
    void pop()
	{
        l++;
    }
    int empty()
	{
        return l>r?1:0;
    }
}q;
int head[1001005];
int cnt;
int num;
int rd[1001005];
void init()
{
	for(int i=1;i<=num;++i)
	{
		q.push(d[i]);
		d[i]=0;
	}
	num=0;
}
int main()
{
	int n;
	scanf("%d",&n);
	int Max=0;
	for(int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Max=max(y,Max); 
		++cnt;
		++rd[y];
		e[cnt].from=x;
		e[cnt].to=y;
		e[cnt].next=head[x];
		head[x]=cnt;
		usd[x]=usd[y]=true;
	}
	for(int i=1;i<=Max;++i)
		if(usd[i])
			f[i]=i;
	for(int i=1;i<=Max;++i)
		if(!rd[i]&&usd[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].next)
		{
			f[e[i].to]=min(f[e[i].to],f[e[i].from]);
			--rd[e[i].to];
			if(!rd[e[i].to])
				d[++num]=e[i].to;
		}
	}
	while(num)
	{
		init();
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			for(int i=head[x];i;i=e[i].next)
			{
				f[e[i].to]=min(f[e[i].to],f[e[i].from]);
				--rd[e[i].to];
				if(!rd[e[i].to])
					d[++num]=e[i].to;
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=Max;++i)
		ans=max(ans,i-f[i]);
	printf("%d",ans);
	return 0;
}
