#include<bits/stdc++.h>
using namespace std;
struct qj
{
	int l,r;
	bool operator < (const qj &b)const
	{
		return r<b.l;
	} 
};
set<qj>s;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		char t;
		cin>>t;
		if(t=='A')
		{
			int l,r,cnt=0;
			cin>>l>>r;
			qj x;
			x.l=l;
			x.r=r;
			set<qj>::iterator it=s.find(x);
			while(it!=s.end())
			{
				++cnt;
				s.erase(it);
				it=s.find(x);
			}
			s.insert(x);
			printf("%d\n",cnt);
		} 
		else printf("%d\n",s.size());
	}
	return 0;
} 
