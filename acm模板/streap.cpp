#include<bits/stdc++.h>
using namespace std; 
typedef long long LL;
const int maxm = 2e6+26;
const int maxn = 1e5+15;
struct data{int l,r,v,size,fix,w;}tr[maxm];
int len,root[maxn];
void update(int k){tr[k].size=tr[tr[k].l].size+tr[tr[k].r].size+tr[k].w;}
void rturn(int &k){int t=tr[k].l;tr[k].l=tr[t].r;tr[t].r=k;tr[t].size=tr[k].size;update(k);k=t;}
void lturn(int &k){int t=tr[k].r;tr[k].r=tr[t].l;tr[t].l=k;tr[t].size=tr[k].size;update(k);k=t;}
void Insert(int &k,int x)                        //插入数x
{
    if(k==0){len++;k=len;tr[k].size=tr[k].w=1;tr[k].v=x;tr[k].fix=rand();return;}
    tr[k].size++;
    if(tr[k].v==x)tr[k].w++;
    else if(x>tr[k].v){Insert(tr[k].r,x);if(tr[tr[k].r].fix<tr[k].fix)lturn(k);}
    else {Insert(tr[k].l,x);if(tr[tr[k].l].fix<tr[k].fix)rturn(k);} 
} 
void Delete(int &k,int x)                        //删除数x
{
    if(k==0) return; 
    if(tr[k].v==x)
    {
        if(tr[k].w>1){tr[k].w--;tr[k].size--;return;}
        if(tr[k].l*tr[k].r==0)k=tr[k].l+tr[k].r;
        else if(tr[tr[k].l].fix<tr[tr[k].r].fix) rturn(k),Delete(k,x);
        else lturn(k),Delete(k,x);
    }
    else if(x>tr[k].v) tr[k].size--,Delete(tr[k].r,x);
    else tr[k].size--,Delete(tr[k].l,x);
}
/*
    查找x的排名
    返回 <= x 的数量,等于x的数有多个,只算一个
*/
int Findrank(int k,int x)                    
{
    if(k==0) return 0;
    if(tr[k].v==x) return tr[tr[k].l].size+1;
    else if(x>tr[k].v) return tr[tr[k].l].size+tr[k].w+Findrank(tr[k].r,x);
    else return Findrank(tr[k].l,x);
}
int Findkth(int k,int x)                        //查找排名为x的数
{
    if(k==0) return 0;
    if(x<=tr[tr[k].l].size) return Findkth(tr[k].l,x);
    else if(x>tr[tr[k].l].size+tr[k].w) return Findkth(tr[k].r,x-tr[tr[k].l].size-tr[k].w);
    else return tr[k].v;
}
int Findpre(int now,int x)
{
	int pre=-2147483647;
	while(now)
	{
		if(tr[now].v<x)
		{
			pre=tr[now].v;
			now=tr[now].r;
		}
		else now=tr[now].l;
	}
	return pre;
}
int Findnxt(int now,int x)
{
	int nxt=2147483647;
	while(now)
	{
		if(tr[now].v>x)
		{
			nxt=tr[now].v;
			now=tr[now].l;
		}
		else now=tr[now].r;
	}
	return nxt;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x;
			scanf("%d",&x);
			Insert(root[1],x);
		}
		else if(t==2)
		{
			int x;
			scanf("%d",&x);
			Delete(root[1],x);
		}	
		else if(t==3)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",Findrank(root[1],x));
		}
		else if(t==4)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",Findkth(root[1],x));
		}
		else if(t==5)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",Findpre(root[1],x));
		}
		else
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",Findnxt(root[1],x));
		}
	}
	return 0;
}
