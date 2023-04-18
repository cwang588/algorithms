#include<bits/stdc++.h>
using namespace std;
int last[500005];
int st[500005];
multiset<int>s1,s2;//s1 所有数 s2 差值  
int ans1,ans2;
int jdz(int x)
{
	return x>0?x:-1*x;
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
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
	{
		last[i]=read();
		s1.insert(last[i]);
		st[i]=last[i];
	}
	ans1=ans2=214748364;
	s1.insert(214748364);
	s1.insert(-214748364);
	s2.insert(214748364);
	s2.insert(-214748364);
	for(int i=1;i<n;++i)
	{
		int t=last[i]-last[i+1];
		if(t<0)t*=-1;
		s2.insert(t);
	}
	multiset<int>::iterator it=s2.begin();
	//ans1=*it;
	multiset<int>::iterator itt=s1.begin();
	while(*itt<214748364)
	{
		int now=*itt;
		++itt;
		ans2=min(ans2,*itt-now);
	}
	for(int i=1;i<=m;++i)
	{
		string s;
		cin>>s;
		if(s=="INSERT")
		{
			int x,y;
			x=read();
			y=read();
			multiset<int>::iterator noww=s1.lower_bound(y);
			int nxt=*noww;
			--noww;
			int pre=*noww;
			ans2=min(ans2,nxt-y);
			ans2=min(ans2,y-pre);
			s1.insert(y);
			s2.insert(jdz(y-last[x]));
			if(x!=n)
			{
				multiset<int>::iterator tt=s2.find(jdz(last[x]-st[x+1]));
				s2.erase(tt);
				s2.insert(jdz(y-st[x+1]));
			}
			last[x]=y;
		}
		else if(s=="MIN_SORT_GAP")printf("%d\n",ans2);
		else
		{
			multiset<int>::iterator tt=s2.begin();
			++tt;
			printf("%d\n",*tt);
		}
	}
	return 0;
}
