#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct query
{
	int l,r,lw,rw,id,ans;
}q[100005];
int rr[100005];
int tong[100005];
bool cmpp(query a,query b)
{
	return a.id<b.id;
}
bool cmp(query a,query b)
{
	if(a.lw!=b.lw)
		return a.lw<b.lw;
	return a.rw<b.rw;
}
int main()
{
	//freopen("test.txt","r",stdin);
    char line[1000001];
    while(cin.getline(line,1000000)) 
	{
		memset(tong,0,sizeof(tong));
		memset(q,0,sizeof(q));
		memset(rr,0,sizeof(rr));
		int i=0,num=0;
		int n=0,m=0,r=0;
		while(line[i]!=' ')
		{
			n=n*10+line[i]-'0';
			++i;
		}
		int base=sqrt(n);
		++i;
		while(line[i]!=' ')
		{
			m=m*10+line[i]-'0';
			++i;
		}
		++i;
		while(line[i]!=';')
		{
			r=r*10+line[i]-'0';
			++i;
		}
		++i;
		while(line[i]!=';')
		{
			++num;
			while(line[i]!=' '&&line[i]!=';')
			{
				rr[num]=rr[num]*10+line[i]-'0';
				++i;
			}
			++i;
			if(num==n)
				break;
		}
		num=0;
		while(i<strlen(line))
		{
			int t=0;
			while(line[i]!=' '&&i<strlen(line))
			{
				t=t*10+line[i]-'0';
				++i;
			}
			++num;
			q[num].l=max(1,t-r);
			q[num].r=min(t+r,n);
			q[num].lw=q[num].l/base;
			q[num].rw=q[num].r/base;
			q[num].id=num;
			++i;
		}
		sort(q+1,q+m+1,cmp);
		int k=0;
		for(int j=q[1].l;j<=q[1].r;++j)
		{
			++tong[rr[j]];
			k=max(k,rr[j]);
		}
		q[1].ans=k;
		for(int o=2;o<=m;++o)
		{
			if(q[o].l<q[o-1].l)
			{
				for(int j=q[o].l;j<q[o-1].l;++j)
				{
					++tong[rr[j]];
					k=max(k,rr[j]);
				}
			}
			if(q[o].r>q[o-1].r)
			{
				for(int j=q[o-1].r+1;j<=q[o].r;++j)
				{
					++tong[rr[j]];
					k=max(k,rr[j]);
				}	
			}
			if(q[o].l>q[o-1].l)
			{
				for(int j=q[o-1].l;j<q[o].l;++j)
				{
					--tong[rr[j]];
					if(!tong[rr[j]]&&k==rr[j])
					{
						for(int w=rr[j];;--w)
							if(tong[w])
							{
								k=w;
								break;
							}
					}
				}
			}
			if(q[o].r<q[o-1].r)
			{
				for(int j=q[o].r+1;j<=q[o-1].r;++j)
				{
					--tong[rr[j]];
					if(!tong[rr[j]]&&k==rr[j])
					{
						for(int w=rr[j];;--w)
							if(tong[w])
							{
								k=w;
								break;
							}
					}
				}
			}
			q[o].ans=k;
		}
		sort(q+1,q+m+1,cmpp);
		for(int o=1;o<=m;++o)
			printf("%d ",q[o].ans);
		printf("\n");
    }
} 
