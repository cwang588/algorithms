#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int m;
const int N=131075;
int sum[N*8+5005],col1[N*8+5],col2[N*8+5];
bool usd[N+5005];
void push_col1(int l,int r,int rt)
{
	if(col1[rt])
	{
		col1[rt<<1]=col1[rt<<1|1]=1;
		col2[rt<<1]=col2[rt<<1|1]=0;
		col1[rt]=0;
	}
}
void push_col2(int l,int r,int rt)
{
	if(col2[rt])
	{
		++col2[rt<<1];
		col2[rt<<1]%=2;
		++col2[rt<<1|1];
		col2[rt<<1|1]%=2;
		col2[rt]=0;
	}
}
void modify1(int l,int r,int rt,int nowl,int nowr)
{
	if(nowl>nowr)return;
	if(l>=nowl&&r<=nowr)
	{
		col2[rt]=0;
		col1[rt]=1;
		return;
	}
	push_col1(l,r,rt);
	push_col2(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)modify1(lson,nowl,nowr);
	if(m<nowr)modify1(rson,nowl,nowr);
}
void modify2(int l,int r,int rt,int nowl,int nowr)
{
	if(nowl>nowr)return;
	if(l>=nowl&&r<=nowr)
	{
		push_col1(l,r,rt);
		++col2[rt];
		col2[rt]%=2;
		return;
	}
	push_col1(l,r,rt);
	push_col2(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)modify2(lson,nowl,nowr);
	if(m<nowr)modify2(rson,nowl,nowr);
}
void work1(int l,int r,int rt)
{
	if(l==r)
	{
		if(col1[rt])
		{
			col1[rt]=0;
			sum[rt]=1;
		}
		return;
	}
	push_col1(l,r,rt);
	int m=(l+r)>>1;
	work1(lson);
	work1(rson);
}
void work2(int l,int r,int rt)
{
	if(l==r)
	{
		if(col2[rt])
			++sum[rt];
		sum[rt]%=2;
		if(sum[rt])usd[l]=true;
		col2[rt]=0;
		return;
	}
	push_col2(l,r,rt);
	int m=(l+r)>>1;
	work2(lson);
	work2(rson);
}
int main()
{
	freopen("test.txt","r",stdin);
//	ios::sync_with_stdio(false);
	char t;
	while(cin>>t)
	{
		string s;
		cin>>s;
		int len=s.length();
		bool ll,rr;
		int l=0,r=0;
		if(s[0]=='[')ll=true;
		else ll=false;
		if(s[len-1]==']')rr=true;
		else rr=false;
		bool dh=false;
		for(int i=1;i<len-1;++i)
		{
			if(s[i]==',')
			{
				dh=true;
				continue;
			}
			if(!dh)l=l*10+(int)(s[i]-'0');
			else r=r*10+(int)(s[i]-'0');
		}
		l*=2;
		r*=2;
		if(!ll)++l;
		if(!rr)--r;
		if(t=='U')modify1(0,N-1,1,l,r);
		else if(t=='I')
		{
			modify2(0,N-1,1,0,N-1);
			modify1(0,N-1,1,0,l-1);
			modify1(0,N-1,1,r+1,N-1);			
			modify2(0,N-1,1,0,N-1);
		}
		else if(t=='D')
		{
			modify2(0,N-1,1,0,N-1);
			modify1(0,N-1,1,l,r);
			modify2(0,N-1,1,0,N-1);
		}
		else if(t=='C')
		{
			modify1(0,N-1,1,0,l-1);
			modify1(0,N-1,1,r+1,N-1);
			modify2(0,N-1,1,0,N-1);
		}
		else modify2(0,N-1,1,l,r);
	}
	work1(0,N-1,1);
	work2(0,N-1,1);
	int last=-1;
	bool ky=false;
	for(int i=0;i<=N;++i)
	{
		if(usd[i])
		{
			if(last==-1)
				last=i;
		}
		else
		{
			if(last>-1)
			{
				int l=last,r=i-1;
				if(l%2)printf("(%d",(l-1)/2);
				else printf("[%d",l/2);
				printf(",");
				if(r%2)printf("%d) ",(r+1)/2);
				else printf("%d] ",r/2);
				last=-1;
				ky=true;
			}
		}
	}
//	if(last!=-1)
//	{
//		int l=last,r=65535*2;
//		if(l%2)printf("(%d",(l-1)/2);
//		else printf("[%d",l/2);
//		printf(",");
//		if(r%2)printf("%d) ",(r+1)/2);
//		else printf("%d] ",r/2);
//		last=-1;
//		ky=true;
//	}
	if(!ky)printf("empty set\n");
	return 0;
}
