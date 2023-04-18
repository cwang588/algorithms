#include<bits/stdc++.h>
using namespace std;
const unsigned long long Mod=19260817;
unsigned long long Hash[20005];
struct q
{
	int id;
	unsigned long long jzm;
	int ans;
}query[20005];
string t;
bool cmp(q x,q y)
{
	if(x.jzm!=y.jzm)
		return x.jzm>y.jzm;
	return x.id<y.id;
}
bool cmpp(q x,q y)
{
	return x.id<y.id;
}
int main()
{
	int n,q;
	cin>>n>>q;
	getchar();
	for(int i=1;i<=q;++i)
	{
		t.clear();
		getline(cin,t);
		int l=t.size();
		for(int j=0;j<l;++j)
			Hash[i]=Hash[i]*Mod+(unsigned long long)t[j];
	}
	for(int i=1;i<=n;++i)
	{
		query[i].id=i;
		t.clear();
		getline(cin,t);
		int l=t.size();
		if(t[l-1]=='.')
		{
			query[i].ans=4;
			continue;
		}
		for(int j=0;j<l;++j)
			query[i].jzm=query[i].jzm*Mod+(unsigned long long)t[j];
	}
	sort(query+1,query+1+n,cmp);
	int now=0;
	for(int i=1;i<=n;++i)
	{
		if(query[i].jzm!=query[i-1].jzm)
			now=1;
		else
			++now;
		bool stupid=false;
		for(int j=1;j<=q;++j)
		{
			if(query[i].jzm==Hash[j])
			{
				stupid=true;
				break;
			}
		}
		if(query[i].ans==4)
			continue;
		else;
		if(stupid)
			query[i].ans=1;
		else
		{
			if(now>5)
				query[i].ans=3;
			else
				query[i].ans=2;
		}
	}
	sort(query+1,query+1+n,cmpp);
	for(int i=1;i<=n;++i)
	{
		if(query[i].ans==4)
			printf("No Response.\n");
		else if(query[i].ans==1)
			printf("42.\n");
		else if(query[i].ans==2)
			printf("Read the problem statement carefully.\n");
		else
			printf("Juries are investigating. Thanks.\n");
	}
	return 0;
} 
