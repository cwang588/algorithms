#include<cstdio>
#include<algorithm>
using namespace std;

struct Node
{
	int x,y,z;
	int id,flg;
};
Node e[50005],st[50005],st2[50005];
bool cmp(Node x,Node y)
{
	if(x.x!=y.x) return x.x<y.x;
	if(x.y!=y.y) return x.y<y.y;
	return x.z<y.z;
} 
bool cmp2(Node x,Node y)
{
	if(x.y!=y.y) return x.y<y.y;
	return x.z<y.z;
}
bool cmp3(Node x,Node y)
{
	return x.id<y.id;
}
int used[50005];
void solve(Node st[],int ln)
{
	if(ln==1) return;
	sort(st+1,st+ln+1,cmp2);
	int ln2=0;
	for(int i=1;i<=ln;i++)
	{
		int tag=st[i].y,lst=0;
		int j;
		for(j=i;j<=ln;j++)
		{
			if(st[j].y==tag&&st[lst].id)
			{
				printf("%d %d\n",st[lst].id,st[j].id);
				used[st[lst].id]=used[st[j].id]=1;
				lst=0;
			}
			else if(st[j].y==tag) lst=j;
			else
			{
				i=j-1;
				break;
			}
		}
		if(lst) st2[++ln2]=st[lst];
		if(j>ln) break;
	}
	for(int i=1;i<=ln2;i+=2)
	{
		if(i==ln2) return;
		used[st2[i].id]=used[st2[i+1].id]=1;
		printf("%d %d\n",st2[i].id,st2[i+1].id);
	}
}
int one()
{
	return 19260817;
}
int zero()
{
	return one()-one();
}
void work()
{
		int n,ln=0;
	scanf("%d",&n);
//	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z),e[i].id=i;
//		printf("%d %d %d\n",e[i].x,e[i].y,e[i].z);	
	}
	
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int tag=e[i].x,ln=0;
		int j;
		for(j=i;j<=n;j++)
		{
			if(e[j].x==tag)
				st[++ln]=e[j];
			else
			{
				i=j-1;
				break;
			}
		}
		solve(st,ln);
		if(j>n) break;
	}
	int lst=0;
	for(int i=1;i<=n;i++)
	{
		if(used[e[i].id]==0&&lst)
		{
			printf("%d %d\n",e[lst].id,e[i].id);
			lst=0;
		}
		else if(used[e[i].id]==0) lst=i;
		else continue;
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("in2.txt","w",stdout);
	work();
	return zero();
}

