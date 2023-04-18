#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int n=10005;
int m;
int num[10005*4],col[10005*4];
void push_col(int l,int r,int rt)
{
	int m=(l+r)>>1;
	col[rt<<1]=max(col[rt<<1],col[rt]);
	col[rt<<1|1]=max(col[rt<<1|1],col[rt]);
	col[rt]=0;
}
void modify(int l,int r,int rt,int nowl,int nowr,int h)
{
	if(l>=nowl&&r<=nowr)
	{
		col[rt]=max(col[rt],h);
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)modify(lson,nowl,nowr,h);
	if(m<nowr)modify(rson,nowl,nowr,h);
}
void work(int l,int r,int rt)
{
	if(l==r)
	{
		num[l]=col[rt];
		return;
	}
	int m=(l+r)>>1;
	push_col(l,r,rt);
	work(lson);
	work(rson);
}
int main()
{
	//freopen("test.txt","r",stdin);
	int x,y,h; 
	while(cin>>x>>h>>y)modify(1,n,1,x+1,y,h);
	work(1,n,1);
	int tot=0;
	for(int i=1;i<=10005;++i)
	{
		if(num[i]!=num[i-1])
		{
			++tot;
			printf("%d %d ",i-1,num[i]);
		}		
	}
	return 0;
}
