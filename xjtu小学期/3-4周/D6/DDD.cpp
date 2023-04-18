#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> >s;
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	s.insert(make_pair(1,n));
	for(int i=1;i<=n;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		set<pair<int,int> >::iterator zuo=lower_bound(make_pair(l,l)),you=upper_bound(make_pair(r,r));
		pair<int,int>a=*zuo,b=*you;
		s.erase(zuo,you);
		if(l>a.first)
			s.insert(make_pair(a.first,l));
		if(l<a.second)
			s.insert(make_pair(l,a.second));
		if(r)
	}
	return 0;
}
