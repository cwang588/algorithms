#include<bits/stdc++.h>
using namespace std;
struct flower
{
	long long val,price;
	bool operator < (const flower &f)const
	{
		return price<f.price;
	}
};
set<flower>s1;
set<long long>s2;
int main()
{
	int t;
	long long tot1=0,tot2=0;
	while(1)
	{
		cin>>t;
		if(t==1)
		{
			long long w,c;
			cin>>w>>c;
			if(s2.find(c)==s2.end())
			{
				flower tmp;
				tmp.val=w;
				tmp.price=c;
				s1.insert(tmp);
				s2.insert(c);
				tot1+=w;
				tot2+=c;
			}
		}
		else if(t==3)
		{
			if(!s1.size())
			{
				set<flower>::iterator it=s1.begin();
				flower tmp=*it;
				tot1-=tmp.val;
				tot2-=tmp.price;
				s2.erase(tmp.price);
				s1.erase(s1.begin());
			}
		}
		else if(t==2)
		{
			if(!s1.size())
			{
				set<flower>::iterator it=s1.end();
				--it;
				flower tmp=*it;
				tot1-=tmp.val;
				tot2-=tmp.price;
				s2.erase(tmp.price);
				s1.erase(s1.begin());
			}
		}
		else break;
	}
	printf("%lld %lld\n",tot1,tot2);
	return 0;
} 
