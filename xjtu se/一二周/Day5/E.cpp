#include<bits/stdc++.h>
using namespace std;
int a[300005],b[300005];
unordered_map<int,int>mm;
struct query
{
	int l,r,lw,rw,id;
	int ans;
}q[300005];
bool cmp(query x,query y)
{
	return (x.lw!=y.lw)?(x.lw<y.lw):(x.r<y.r);
}
bool cmpp(query x,query y)
{
	return x.id<y.id;
}
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
int main()
{
	freopen("xor1.in","r",stdin);
	freopen("xor1.out","w",stdout);
	int n,m;
	n=read();
	int base=sqrt(n);
	for(int i=1;i<=n;++i)a[i]=read(),b[i]=b[i-1]^a[i];
	m=read();
	for(int i=1;i<=m;++i)
	{
		q[i].l=read();
		q[i].r=read();
		q[i].lw=q[i].l/base;
		q[i].rw=q[i].r/base;
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	long long now=0;
	for(int i=1;i<=m;++i)
	{
		while(r<q[i].r)
		{
			++r;
			++mm[a[r]];
			if(mm[a[r]]==1)now^=a[r];
		}
		while(l>q[i].l)
		{
			--l;
			++mm[a[l]];
			if(mm[a[l]]==1)now^=a[l];
		}
		while(r>q[i].r)
		{
			--mm[a[r]];
			if(!mm[a[r]])now^=a[r];
			--r;
		}
		while(l<q[i].l)
		{
			--mm[a[l]];
			if(!mm[a[l]])now^=a[l];
			++l;
		}
		q[i].ans=now^b[q[i].r]^b[q[i].l-1];
	}
	sort(q+1,q+1+m,cmpp);
	for(int i=1;i<=m;++i)printf("%d\n",q[i].ans);
	return 0;
}
