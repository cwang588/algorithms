#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int n,q,l,r;
struct node
{
	int x,y;
};
struct cmp
{
    bool operator() (node a,node b)
	{
        if(a.x!=b.x)
            return a.x<b.x;
        else
            return a.y<b.y;
    }
};
set<node,cmp>s;
set<node,cmp>::iterator it,it1,it2,it3;
void workit(node a1)
{
	if(it1==it2)
	{
		int l1=(*it3).x;
		int l2=(*it3).y;
		s.erase(it3);
		if(l1<l)
		{
			a1.x=l1;
			a1.y=l-1;
			s.insert(a1);
		}
		a1.x=l;
		a1.y=r;
		s.insert(a1);
		if(r<l2)
		{
			a1.x=r+1;
			a1.y=l2;
			s.insert(a1);
		}
	}
	else
	{
		int l1=(*it3).x;
		s.erase(it3);
		if(l>l1)
		{
			a1.x=l1;
			a1.y=l-1;
			s.insert(a1);
		}
		it=it1;
		while(it!=it2)
		{
			it3=it;it3++;
			s.erase(it);
			it=it3;
		}
		a1.x=l;
		a1.y=r;
		s.insert(a1);
		if((*it2).x-1>=r+1) 
		{
			a1.x=r+1;
			a1.y=(*it).x-1;
			s.insert(a1);
		}
	}		
}
int main()
{
	scanf("%d%d",&n,&q);
	node a1;
	a1.x=1;
	a1.y=n;
	s.insert(a1);
	a1.x=n+1;
	a1.y=n+1;
	s.insert(a1);
	for(int cnt=1;cnt<=q;++cnt)
	{
		scanf("%d%d",&l,&r);
		a1.x=l;
		a1.y=inf;
		it1=s.upper_bound(a1);
		a1.x=r;
		it2=s.upper_bound(a1);
		it3=it1;
		it3--;
		workit(a1);
		printf("%d\n",s.size()-1);
	} 
	return 0;
}

