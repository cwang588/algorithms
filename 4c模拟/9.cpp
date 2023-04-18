#include<bits/stdc++.h>
using namespace std;
struct biao
{
	int num,next;
}b[100005];
bool you[100005];
struct lian
{
	int num,now;
}l1[100005],l2[100005];
bool usd[1000005];
int main()
{
	int head,n;
	scanf("%d %d",&head,&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		scanf("%d%d",&b[t].num,&b[t].next);
	}
	int n1,n2;
	n1=n2=0;
	for(int i=head;i!=-1;i=b[i].next)
	{
		you[i]=true;
		if(!usd[abs(b[i].num)])
		{
			usd[abs(b[i].num)]=true;
			++n1;
			l1[n1].num=b[i].num;
			l1[n1].now=i;
		}
		else
		{
			++n2;
			l2[n2].num=b[i].num;
			l2[n2].now=i;	
		}
	}
	for(int i=1;i<n1;++i)
		printf("%05d %d %05d\n",l1[i].now,l1[i].num,l1[i+1].now);
	printf("%05d %d -1\n",l1[n1].now,l1[n1].num);
	for(int i=1;i<n2;++i)
		printf("%05d %d %05d\n",l2[i].now,l2[i].num,l2[i+1].now);
	printf("%05d %d -1\n",l2[n2].now,l2[n2].num);
	return 0;
}
