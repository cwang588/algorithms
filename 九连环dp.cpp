#include<cstdio>
#include<cstdlib>

int n;
int d[1050];
int q[1050];
int book[1050];
int head=1,tail=0;
int main()
{
	q[++tail]=0;
	book[0]=true;
	while(head<=tail)
	{
		int now=q[head];
		head++;
		if(!book[now^1])
		{
			book[now^1]=true;
			q[++tail]=now^1;
			d[now^1]=d[now]+1;
		}
		for(int i=0;i<8;i++)
			if((now&(1<<i)))
			{
				if(!book[now^(1<<(i+1))])
				{
					book[now^(1<<(i+1))]=true;
					q[++tail]=now^(1<<(i+1));
					d[now^(1<<(i+1))]=d[now]+1;
				}
				break;
			}
	}
	int ans=0x1ff;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		ans^=(1<<(x-1));
	}
	printf("%d",d[ans]);
	return 0;
}

