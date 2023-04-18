#include<bits/stdc++.h>
#define N 100050
using namespace std;
struct node
{
	int l,r,num;
}T[N*400];
int root[N];
vector<int>v;
int a[N];
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
struct todo
{
	int tmp,l,r,k,x,y;
}t[N];
int n,m,num,cnt,n1,n2;
int t1[N],t2[N];
int lowbit(int x)
{
	return x&(-x);
}
void modify(int &now,int l,int r,int ind,int c)
{
	if(!now)now=++cnt;
	T[now].num+=c;
	if(l==r)return;
	int m=(l+r)>>1;
	if(m>=ind)modify(T[now].l,l,m,ind,c);
	else modify(T[now].r,m+1,r,ind,c); 
}
void change(int ind,int val)
{
	int now=a[ind];
	while(ind<=n)
	{
		modify(root[ind],1,num,now,val);
		ind+=lowbit(ind);
	}
}
int query(int l,int r,int k)
{
	if(l==r)return l;
	int sum=0,m=(l+r)>>1;
	for(int i=1;i<=n2;++i)
		sum+=T[T[t2[i]].l].num;
	for(int i=1;i<=n1;++i)
		sum-=T[T[t1[i]].l].num;
	if(sum>=k)
	{
		for(int i=1;i<=n1;++i)t1[i]=T[t1[i]].l;
		for(int i=1;i<=n2;++i)t2[i]=T[t2[i]].l;
		return query(l,m,k);
	} 
	else
	{
		for(int i=1;i<=n1;++i)t1[i]=T[t1[i]].r;
		for(int i=1;i<=n2;++i)t2[i]=T[t2[i]].r;
		return query(m+1,r,k-sum);
	}
}
int Kth(int l,int r,int k)
{
	n1=0,n2=0;
	for(int i=l-1;i;i-=lowbit(i))t1[++n1]=root[i];
	for(int i=r;i;i-=lowbit(i))t2[++n2]=root[i];
	return query(1,num,k);
}
int main()
{
	cin>>n>>m; 
	for(int i=1;i<=n;++i)cin>>a[i],v.push_back(a[i]);
	for(int i=1;i<=m;++i)
	{
		char tmp;
		cin>>tmp;
		if(tmp=='Q')
		{
			t[i].tmp=0;
			cin>>t[i].l>>t[i].r>>t[i].k;
		}
		else
		{
			t[i].tmp=1;
			cin>>t[i].x>>t[i].y;
			v.push_back(t[i].y);
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end()); 
	num=v.size();
	for(int i=1;i<=n;++i)
	{
		a[i]=getid(a[i]);
		change(i,1);
	}
	for(int i=1;i<=m;++i)
	{
		if(t[i].tmp)
		{
			change(t[i].x,-1);
			a[t[i].x]=getid(t[i].y);
			change(t[i].x,1);
		}
		else printf("%d\n",v[Kth(t[i].l,t[i].r,t[i].k)-1]);
	}
	return 0;
}
