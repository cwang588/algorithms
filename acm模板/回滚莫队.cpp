#include<bits/stdc++.h>
using namespace std;
inline int read() 
{
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}
vector<int>v;
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1};
struct query
{
	int l,r,lw,rw,id,ans;
}q[200005];
int a[200005];
bool cmp(query x,query y)
{
	if(x.lw!=y.lw)return x.lw<y.lw;
	return x.r<y.r;
}
int main()
{
	int n,m; 
	n=read();
	m=read();
	int base=sqrt(n);
	for(int i=1;i<=n;++i)a[i]=read(),v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i)a[i]=getid(a[i]);
	for(int i=1;i<=m;++i)
	{
		q[i].id=i;
		q[i].l=read();
		q[i].r=read();
		q[i].lw=q[i].l/base;
		q[i].rw=q[i].r/base;
	}
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=n;++i)
	{
		
	}
	return 0;
}
