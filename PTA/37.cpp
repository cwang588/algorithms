#include<cstdio>
#include<set>
using namespace std;
bool usd[200005];
struct lian
{
	int next,num,id;
}e[100005];
struct l
{
	int add,num;
}e1[100005],e2[100005];
int num1,num2;
int main()
{
	int head,n;
	scanf("%d%d",&head,&n);
	for(int i=1;i<=n;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[a].num=b;
		e[a].next=c;
	}
	for(int i=head;i!=-1;i=e[i].next)
	{
		if(!usd[e[i].num])
		{
			e[i].id=1;
			usd[e[i].num]=true;
		}
		else
			e[i].id=2;
	}
	for(int i=head;i!=-1;i=e[i].next)
	{
		if(e[i].id==1)
		{
			e1[++num1].add=i;
			e1[num1].num=e[i].num;
		}
		else
		{
			e2[++num2].add=i;
			e2[num2].num=e[i].num;
		}
	}
	for(int i=1;i<num1;++i)
		printf("%05d %d %05d\n",e1[i].add,e1[i].num,e1[i+1].add);
	printf("%05d %d -1\n",e1[num1].add,e1[num1].num); 
	for(int i=1;i<num2;++i)
		printf("%05d %d %05d\n",e2[i].add,e2[i].num,e2[i+1].add);
	printf("%05d %d -1\n",e2[num2].add,e2[num2].num); 
	return 0;
}
