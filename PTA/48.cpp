#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int now,num,next;
}N[100005];
int main()
{
	int head,n;
	scanf("%d%d",&head,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&N[i].now,&N[i].num,&N[i].next);
	}
	return 0;
}
